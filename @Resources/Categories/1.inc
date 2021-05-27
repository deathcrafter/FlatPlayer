[Installer]
IfEqualValue=1
IfEqualAction=[!ActivateConfig "#CURRENTCONFIG#\SpicetifyInstaller"]


[Variables]
@includeSpiceVars=#@#Spicetify\Variables.inc
ThemesH=0
CSchemesH=0
Theme0=[!CommandMeasure MeasureOpener "Stop 2"][!CommandMeasure MeasureOpener "Execute 1"][!SetVariable nT 1]
Theme1=[!CommandMeasure MeasureOpener "Stop 1"][!CommandMeasure MeasureOpener "Execute 2"][!SetVariable nT 0]
nT=0
Scheme0=[!CommandMeasure MeasureOpener "Stop 4"][!CommandMeasure MeasureOpener "Execute 3"][!SetVariable nC 1]
Scheme1=[!CommandMeasure MeasureOpener "Stop 3"][!CommandMeasure MeasureOpener "Execute 4"][!SetVariable nC 0]
nC=0
UTHEME=[!UpdateMeter ThemesContainer][!UpdateMeasure MeasureOpener][!Redraw]
USCHEME=[!UpdateMeter CSchemesContainer][!UpdateMeasure MeasureOpener][!Redraw]

[MeasureOpener]
Measure=Plugin
Plugin=ActionTimer
ActionList1 = Repeat OpenTheme, 5, 24
;(Ceil(Min(([#NumberofThemes]*24+6)*[#Scale],150*[#Scale]))/10)
ActionList2 = Repeat CloseTheme, 5, 24
;(Ceil(Min(([#NumberofThemes]*24+6)*[#Scale],150*[#Scale]))/10)
ActionList3 = Repeat OpenScheme, 5, 24
;(Ceil(Min(([#NumberofColorSchemes]*24+6)*[#Scale],150*[#Scale]))/10)
ActionList4 = Repeat CloseScheme, 5, 24
;(Ceil(Min(([#NumberofColorSchemes]*24+6)*[#Scale],150*[#Scale]))/10)
OpenTheme=[!SetVariable ThemesH "(Clamp([#ThemesH]+10, 0,Min(([#NumberofThemes]*24+5)*[#Scale],149*[#Scale])))"]#UTHEME#
CloseTheme=[!SetVariable ThemesH "(Clamp([#ThemesH]-10, 0,Min(([#NumberofThemes]*24+5)*[#Scale],149*[#Scale])))"]#UTHEME#
OpenScheme=[!SetVariable CSchemesH "(Clamp([#CSchemesH]+10, 0, Min(([#NumberofColorSchemes]*24+5)*[#Scale],149*[#Scale])))"]#USCHEME#
CloseScheme=[!SetVariable CSchemesH "(Clamp([#CSchemesH]-10, 0, Min(([#NumberofColorSchemes]*24+5)*[#Scale],149*[#Scale])))"]#USCHEME#
IgnoreWarnings=0
DynamicVariables=1

[SpiceTitle]
Meter=String
X=(55*[#Scale])
Y=(35*[#Scale])
Text=spicetify-cli
FontFace=Segoe UI Variable Display
FontSize=(15*[#Scale])
FontWeight=600
FontColor=FFFFFF
AntiAlias=1
LeftMouseUpAction=[!Log "[FirstCSchemePanel:Y]"]
DynamicVariables=1
[Themes]
Meter=String
X=(55*[#Scale])
Y=(20*[#Scale])R
Text=Themes
FontFace=Segoe UI Variable Display
FontSize=(13*[#Scale])
SolidColor=0,0,0,1
FontColor=FFFFFF
AntiAlias=1
RightMouseUpAction=[!CommandMeasure SpicetifyScript MakeThemes][!Delay 100][!Refresh]
DynamicVariables=1

[Drag&DropParent]
Measure=Plugin
Plugin=Drag&Drop
[ThemeDrag&Drop]
Measure=Plugin
Plugin=Drag&Drop
Parent=Drag&DropParent
Bounds=ThemesBox
Action=Path
Silent=1
OnDropAction=[!SetVariable ToInstall $File$][!SetVariable ThemeName $Name$][!CommandMeasure SpicetifyScript InstallTheme]

[ThemesBox]
Meter=Shape
X=(55*[#Scale])
Y=(15*[#Scale])R
Shape=Rectangle (1*[#Scale]),0,(250*[#Scale]),(30*[#Scale]) | Fill Color 0,0,0 | StrokeWidth (2*[#Scale]) | Extend MyStroke
MyStroke= Stroke Color 217,217,218,100
MouseOverAction=[!SetOption #CURRENTSECTION# MyStroke "Stroke Color 217,217,218,200"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# MyStroke "Stroke Color 217,217,218,100"][!UpdateMeter #CURRENTSECTION#][!Redraw]
LeftMouseUpAction=[#Theme[#nT]]
DynamicVariables=1

[ActiveTheme]
Meter=String
X=(10*[#Scale])r
Y=(15*[#Scale])r
Text=[#ActiveTheme]
FontFace=Segoe UI Variable Text
FontSize=(10*[#Scale])
StringAlign=LeftCenter
FontColor=FFFFFF
AntiAlias=1
DynamicVariables=1

[ColorScheme]
Meter=String
X=(55*[#Scale])
Y=(15*[#Scale])R
Text=Color Scheme
FontFace=Segoe UI Variable Display
FontSize=(13*[#Scale])
FontColor=FFFFFF
AntiAlias=1
DynamicVariables=1

[Color_SchemesBox]
Meter=Shape
X=(55*[#Scale])
Y=(15*[#Scale])R
Shape=Rectangle (1*[#Scale]),0,(250*[#Scale]),(30*[#Scale]) | Fill Color 0,0,0 | StrokeWidth (2*[#Scale]) | Extend MyStroke
MyStroke= Stroke Color 217,217,218,100
MouseOverAction=[!SetOption #CURRENTSECTION# MyStroke "Stroke Color 217,217,218,200"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# MyStroke "Stroke Color 217,217,218,100"][!UpdateMeter #CURRENTSECTION#][!Redraw]
LeftMouseUpAction=[#Scheme[#nC]]
DynamicVariables=1

[ActiveColorScheme]
Meter=String
Text=[#ActiveColorScheme]
MeterStyle=ActiveTheme
DynamicVariables=1

[PopTextStyle]
X=r
Y=R
W=(237*[#Scale])
FontFace=Segoe UI Variable Text
FontSize=(10*[#Scale])
Padding=(10*[#Scale]),(3*[#Scale]),0,(3*[#Scale])
SolidColor=0,0,0,1
FontColor=FFFFFF
AntiAlias=1
ClipString=1
DynamicVariables=1
Group=Themes | CSchemes
MouseOverAction=[!SetOption #CURRENTSECTION# SolidColor "30,30,30,150"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# SolidColor "0,0,0,1"][!UpdateMeter #CURRENTSECTION#][!Redraw]

[FirstItem]
H=0
W=0
X=0
SolidColor=0,0,0,0
DynamicVariables=1

[LastITem]
H=0
W=0
Y=3R
X=0
SolidColor=0,0,0,0

[ThemesContainer]
Meter=Shape
X=(55*[#Scale])
Y=([ThemesBox:Y]+35*[#Scale])
Shape=Rectangle 0,0,(252*[#Scale]),[#ThemesH] | Fill Color 0,0,0 | StrokeWidth 0 | Extend MyStroke
MyStroke= Stroke Color 217,217,218,255
DynamicVariables=1

[ThemesBG]
Meter=Shape
X=0
Y=0
Shape=Rectangle (1*[#Scale]),1,(250*[#Scale]),(Clamp((([#NumberofThemes]*24+3)*[#Scale]), 27*[#Scale], 147*[#Scale])) | Fill Color 0,0,0 | StrokeWidth (2*[#Scale]) | Extend MyStroke
MyStroke= Stroke Color 217,217,218,100
Container=ThemesContainer
MouseScrollDownAction=[!EnableMeasure ScrollDownThemePanel][!UpdateMeasure ScrollDownThemePanel]
MouseScrollUpAction=[!EnableMeasure ScrollUpThemePanel][!UpdateMeasure ScrollUpThemePanel]

[FirstThemePanel]
Meter=String
Text=First
FontColor=0,0,0,0
MeterStyle=FirstItem
Container=ThemesContainer
Group=Themes
Y=[#s_ScrollThemePanel]

[SpicetifyDefault]
Meter=String
X=(2*[#Scale])r
Y=(2*[#Scale])r
Text=SpicetifyDefault
MeterStyle=PopTextStyle
Container=ThemesContainer
LeftMouseUpAction=[!SetVariable ActiveTheme "SpicetifyDefault"][!WriteKeyValue Variables ActiveTheme "SpicetifyDefault" "#@#Spicetify\Variables.inc"][!CommandMeasure SpicetifyScript UpdateTheme]

@includeThemes=#@#Spicetify\Themes.inc

[LastThemePanel]
Meter=String
Text=Last
FontColor=255,0,0,0
MeterStyle=LastItem
Container=ThemesContainer

[ScrollDownThemePanel]
Measure=Calc
Formula=(Clamp(([#s_ScrollThemePanel] - [#s_ScrollSpeed]),(6-[#NumberofColorSchemes])*24*[#Scale], 0))
IfCondition=([#NumberofThemes] > 6)
IfTrueAction=[!SetVariable "s_ScrollThemePanel" "[&ScrollDownThemePanel]"][!DisableMeasure "ScrollDownThemePanel"][!UpdateMeterGroup Themes][!Redraw]
IfFalseAction=[!DisableMeasure "ScrollDownThemePanel"]
IfConditionMode=1
Disabled=1
DynamicVariables=1

[ScrollUpThemePanel]
Measure=Calc
Formula=(Clamp(([#s_ScrollThemePanel] + [#s_ScrollSpeed]),(6-[#NumberofColorSchemes])*24*[#Scale], 0))
IfCondition=([#s_ScrollThemePanel] < 0)
IfTrueAction=[!SetVariable "s_ScrollThemePanel" "[&ScrollUpThemePanel]"][!DisableMeasure "ScrollUpThemePanel"][!UpdateMeterGroup Themes][!Redraw]
IfFalseAction=[!DisableMeasure "ScrollUpThemePanel"]
IfConditionMode=1
Disabled=1
DynamicVariables=1

[CSchemesContainer]
Meter=Shape
X=(55*[#Scale])
Y=([Color_SchemesBox:Y]+35*[#Scale])
Shape=Rectangle 0,0,(252*[#Scale]),[#CSchemesH] | Fill Color 0,0,0 | StrokeWidth 0 | Extend MyStroke
MyStroke= Stroke Color 217,217,218,255
DynamicVariables=1

[CSchemesBG]
Meter=Shape
X=0
Y=0
Shape=Rectangle (1*[#Scale]),(1*[#Scale]),(250*[#Scale]),(Clamp((([#NumberofColorSchemes]*24+3)*[#Scale]), 27*[#Scale], 147*[#Scale])) | Fill Color 0,0,0 | StrokeWidth (2*[#Scale]) | Extend MyStroke
MyStroke= Stroke Color 217,217,218,100
Container=CSchemesContainer
DynamicVariables=1
MouseScrollDownAction=[!EnableMeasure ScrollDownCSchemePanel][!UpdateMeasure ScrollDownCSchemePanel]
MouseScrollUpAction=[!EnableMeasure ScrollUpCSchemePanel][!UpdateMeasure ScrollUpCSchemePanel]

[FirstCSchemePanel]
Meter=String
Text=First
FontColor=0,0,0,0
MeterStyle=FirstItem
Container=CSchemesContainer
Group=CSchemes
Y=[#s_ScrollCSchemePanel]

[base]
Meter=String
X=(2*[#Scale])r
Y=(2*[#Scale])r
Text=base
MeterStyle=PopTextStyle
LeftMouseUpAction=[!SetVariable ActiveColorScheme "base"][!WriteKeyValue Variables ActiveColorScheme "base" "#@#Spicetify\Variables.inc"][!CommandMeasure SpicetifyScript UpdateColorScheme]
Container=CSchemesContainer

@includeCSchemes=#@#Spicetify\ColorSchemes.inc

[LastCSchemePanel]
Meter=String
Text=Last
FontColor=255,0,0,0
MeterStyle=LastItem
Container=CSchemesContainer

[ScrollDownCSchemePanel]
Measure=Calc
Formula=(Clamp(([#s_ScrollCSchemePanel] - [#s_ScrollSpeed]),(6-[#NumberofColorSchemes])*24*[#Scale], 0))
IfCondition=([#NumberofColorSchemes] > 6)
IfTrueAction=[!SetVariable "s_ScrollCSchemePanel" "[&ScrollDownCSchemePanel]"][!DisableMeasure "ScrollDownCSchemePanel"][!UpdateMeterGroup CSchemes][!Redraw]
IfFalseAction=[!DisableMeasure "ScrollDownCSchemePanel"]
IfConditionMode=1
Disabled=1
DynamicVariables=1

[ScrollUpCSchemePanel]
Measure=Calc
Formula=(Clamp(([#s_ScrollCSchemePanel] + [#s_ScrollSpeed]),(6-[#NumberofColorSchemes])*24*[#Scale], 0))
IfCondition=([#s_ScrollCSchemePanel] < 0)
IfTrueAction=[!SetVariable "s_ScrollCSchemePanel" "[&ScrollUpCSchemePanel]"][!DisableMeasure "ScrollUpCSchemePanel"][!UpdateMeterGroup CSchemes][!Redraw]
IfFalseAction=[!DisableMeasure "ScrollUpCSchemePanel"]
IfConditionMode=1
Disabled=1
DynamicVariables=1

[IncorrectFile]
Meter=String
X=(55*[#Scale])
Y=(300*[#Scale])
Text=Folder incorrect!#CRLF#Please drop a valid folder.
FontFace=Segoe UI Variable Display
FontSize=(13*[#Scale])
FontColor=FFFFFF
Hidden=1
AntiAlias=1

[InstallerTextStyle]
FontFace=Segoe UI Variable Text
FontSize=(10*[#Scale])
Padding=(5*[#Scale]),(5*[#Scale]),(5*[#Scale]),(5*[#Scale])
SolidColor=30,30,30,150
FontColor=FFFFFF
AntiAlias=1
ClipString=1
DynamicVariables=1
Hidden=1
MouseOverAction=[!SetOption #CURRENTSECTION# SolidColor "60,60,60,150"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# SolidColor "30,30,30,150"][!UpdateMeter #CURRENTSECTION#][!Redraw]


[CheckUpdates]
Meter=String
X=(0*[#Scale])r
Y=(450*[#Scale])
W=(110*[#Scale])
Text=Check for Updates
Hidden=0
LeftMouseUpAction=[!CommandMeasure SpicetifyScript CheckSpicetifyUpdate]
MeterStyle=InstallerTextStyle

[UpdateNotif]
Meter=String
X=(55*[#Scale])
Y=(435*[#Scale])
W=285
ClipString=2
StringAlign=LeftBottom
Text=Update available!
FontFace=Segoe UI Variable Display
FontSize=(10*[#Scale])
FontColor=00FF00
Hidden=1
Group=Updater
AntiAlias=1

[UpdaterButton]
Meter=String
X=(0*[#Scale])r
Y=(450*[#Scale])
W=(45*[#Scale])
Text=Update
LeftMouseUpAction=[!About][!Delay 600][!CommandMeasure SpicetifyScript Install]
MeterStyle=InstallerTextStyle
Group=Updater

[UpdaterText]
Meter=String
X=(5*[#Scale])R
Y=(10*[#Scale])r
W=(200*[#Scale])
Text=*Rainmeter skins will stay unresponisive for a long time.Please wait patiently until Spotify restarts.
SolidColor=0,0,0,1
Padding=(10*[#Scale]),(5*[#Scale]),(5*[#Scale]),(5*[#Scale])
MouseOverAction=[]
MouseLeaveAction=[]
MouseActionCursor=0
FontColor=FF0000
FontSize=9
ClipString=2
StringAlign=LeftCenter
MeterStyle=InstallerTextStyle
Group=Updater