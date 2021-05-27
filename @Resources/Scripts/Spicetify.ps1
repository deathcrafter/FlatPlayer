function Update {
    $oldPreference = $ErrorActionPreference

    $ErrorActionPreference = 'stop'
  
    try {if(spicetify -v){0}}
  
    Catch {1}
  
    Finally {$ErrorActionPreference=$oldPreference}
}
function Install {
    
    $RmAPI.Log("Installing spicetify-cli...")
    
    Invoke-WebRequest -UseBasicParsing "https://raw.githubusercontent.com/khanhas/spicetify-cli/master/install.ps1" | Invoke-Expression
    
    $RmAPI.Log("Configuring webnowplaying.js...")
    
    spicetify config extensions webnowplaying.js

    $RmAPI.Log("Spicing up Spotify...")

    spicetify backup apply -n

    MakeThemes

    MakeColorSchemes -currentTheme 'SpicetifyDefault'
    
    $RmAPI.Log("Restarting Spotify...")
    
    RestartSpotify
    
    $RmAPI.Log("Spotify is spiced up!")
    
    $RmAPI.Bang("!Refresh `"FlatPlayer\Settings`"")

    $RmAPI.Bang("!DeactivateConfig")
}
function MakeThemes {
   
    $filePath=$RmAPI.VariableStr('@') + 'Spicetify\'
    $k=1
    $a=@"
"@
    $b=(Get-ChildItem -Path "$(${HOME} + "\spicetify-cli\Themes")" -Exclude "SpicetifyDefault").Name
    $b | ForEach-Object {
        if ($_ -notlike ""){
        $a+=@"

[$_]
Meter=String
Text=$_
MeterStyle=PopTextStyle
Container=ThemesContainer
LeftMouseUpAction=[!SetVariable ActiveTheme "$_"][!WriteKeyValue Variables ActiveTheme "$_" "#@#Spicetify\Variables.inc"][!CommandMeasure SpicetifyScript UpdateTheme]
"@
        $k=$k+1
        }
    }
    $a | Out-File -FilePath $($filePath+"Themes.inc")
    $RmAPI.Bang("!WriteKeyValue Variables NumberOfThemes $k `"$($RmAPI.VariableStr('@') + 'Spicetify\Variables.inc')`"")
}

function MakeColorSchemes {
    param(
        [Parameter(Mandatory=$true)]
        $currentTheme
    )
    $filePath=$RmAPI.VariableStr('@') + 'Spicetify\'
    $k=1
    $c=@()
    $b=Select-String -Path $(${HOME} + "\spicetify-cli\Themes\" + $currentTheme + "\color.ini") -Pattern "^\[.+\]$" -Exclude "[base]"
    $b | ForEach-Object {
        $_ -match "(?<=\[)(.*?)(?=\])"
        $c+=$matches[1]
    }
    $a=@"
"@
    $c | ForEach-Object {
        if ($_ -notlike "Base"){
        $a+=@"

[$_]
Meter=String
Text=$_
MeterStyle=PopTextStyle
Container=CSchemesContainer
LeftMouseUpAction=[!SetVariable ActiveColorScheme "$_"][!WriteKeyValue Variables ActiveColorScheme "$_" "#@#Spicetify\Variables.inc"][!CommandMeasure SpicetifyScript UpdateColorScheme]
"@
        $k+=1
        }
    }
    $a | Out-File -FilePath $($filePath + "ColorSchemes.inc")
    $RmAPI.Bang("!WriteKeyValue Variables NumberOfColorSchemes $k `"$($RmAPI.VariableStr('@') + 'Spicetify\Variables.inc')`"")
}

function UpdateColorScheme {
    $colorScheme=$RmAPI.VariableStr('ActiveColorScheme')
    spicetify config color_scheme $colorScheme
    spicetify apply -q -n
    RestartSpotify
    $RmAPI.Bang('[!Refresh]')
}
function UpdateTheme {
    $theme=$RmAPI.VariableStr('ActiveTheme')
    spicetify config current_theme $theme
    spicetify apply -q -n
    MakeColorSchemes -currentTheme $theme
    RestartSpotify
    $RmAPI.Bang('[!Refresh]')
}

function InstallTheme {
    $filePath=$RmAPI.VariableStr("ToInstall")
    $fileName=$RmAPI.VariableStr("ThemeName")
    if ((Get-ChildItem -Path $filePath).Name -contains "user.css" -and "color.ini") {
        Copy-Item -Path "$filePath" -Destination "${HOME}\spicetify-cli\Themes\$fileName\" -Force
        MakeThemes
        $RmAPI.Bang('!Refresh')
    }else{
        $RmAPI.Bang("[!ShowMeter IncorrectFile][!Delay 2000][!HideMeter IncorrectFile]")
    }
}

function RestartSpotify {
    $spotify = Get-Process Spotify -ErrorAction SilentlyContinue
    if ($spotify) {
        $spotify | Stop-Process -Force
    }
    Start-Sleep -Milliseconds 1000
    Start-Process -FilePath $($env:APPDATA + '\Spotify\spotify.exe')
}

function Test-SpicetifyExists{

  $oldPreference = $ErrorActionPreference

  $ErrorActionPreference = 'stop'

  try {if(spicetify -v){0}}

  Catch {1}

  Finally {$ErrorActionPreference=$oldPreference}

}

function CheckSpicetifyUpdate {
    $oldPreference = $ErrorActionPreference

    $ErrorActionPreference = 'stop'
  
    try {
        if(spicetify -v){
  
    
            try{
                $latest_release_uri ="https://api.github.com/repos/khanhas/spicetify-cli/releases/latest"
                $latest_release_json = Invoke-WebRequest -Uri $latest_release_uri -UseBasicParsing   
                $version = ($latest_release_json | ConvertFrom-Json).tag_name -replace "v", ""
                $v=spicetify -v
                if ($v -ne $version) {
                    $RmAPI.Bang('!HideMeter CheckUpdates')
                    $RmAPI.Bang('!ShowMeterGroup Updater')
                }else{
                    $RmAPI.Log('Latest version of spicetify-cli is installed!')
                }
            }
            catch{
                $RmAPI.Log('Unable to fetch info for now!')
            }
        }
    }
    catch {
        $RmAPI.Bang('!ActivateConfig FlatPlayer\Settings\SpicetifyInstaller')
    }
  
    Finally {$ErrorActionPreference=$oldPreference}
}