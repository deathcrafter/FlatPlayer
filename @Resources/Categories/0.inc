[Variables]
Spotify0=[!WriteKeyValue Variables Player "Spotify" "#ROOTCONFIGPATH#FlatPlayer.ini"][!Refresh "#ROOTCONFIG#"]
Spotify1=[!ActivateConfig "FlatPlayer\Settings\SpicetifyInstaller"]

[MouseXRaw]
Measure=Plugin
Plugin=MouseXY
Dimension=X
MaxValue=#SCREENAREAWIDTH#
UpdateDivider=1

[MouseYRaw]
Measure=Plugin
Plugin=MouseXY
Dimension=Y
MaxValue=#SCREENAREAHEIGHT#
UpdateDivider=1
Group=Mouse
[MouseX]
Measure=Calc
Formula=(Clamp((MouseXRaw-#CURRENTCONFIGX#-[Strokes:X]),([Strokes:X]-200*[#Scale]),([Strokes:X]+[Strokes:W]+127.5*[#Scale])))
Group=Mouse
DynamicVariables=1
UpdateDivider=1
OnChangeAction=[!UpdateMeterGroup Main][!Redraw]

[MouseY]
Measure=Calc
Formula=(Clamp((MouseYRaw-#CURRENTCONFIGY#-[Strokes:Y]), ([Strokes:Y]-200*[#Scale]), ([Strokes:Y]+[Strokes:H]+207.5*[#Scale])))
Group=Mouse
DynamicVariables=1
UpdateDivider=1
OnChangeAction=[!UpdateMeterGroup Main][!Redraw]

[Strokes]
Meter=Shape
X=(65*[#Scale])
Y=(55*[#Scale])
Shape=Rectangle 0,0 ,(125*[#Scale]), (100*[#Scale]) | StrokeWidth (2*[#Scale]) | Fill Color FFFFFE00 | Stroke RadialGradient MyGradient
Shape2=Rectangle (130*[#Scale]),0 ,(125*[#Scale]), (100*[#Scale])
Shape3=Rectangle 0,(105*[#Scale]) ,(125*[#Scale]), (100*[#Scale])
Shape4=Rectangle (130*[#Scale]),(105*[#Scale]) ,(125*[#Scale]), (100*[#Scale])
Shape5=Rectangle 0,(210*[#Scale]) ,(125*[#Scale]), (100*[#Scale])
Shape6=Rectangle (130*[#Scale]),(210*[#Scale]) ,(125*[#Scale]), (100*[#Scale])
Shape7=Rectangle 0,(315*[#Scale]) ,(125*[#Scale]), (100*[#Scale])
Shape8=Rectangle (130*[#Scale]),(315*[#Scale]) ,(125*[#Scale]), (100*[#Scale])
Shape9=Combine Shape | Union Shape2 | Union Shape3 | Union Shape4 | Union Shape5 | Union Shape6 | Union Shape7 | Union Shape8
MyGradient= ([MouseX]-127.5*[#Scale]),([MouseY]-207.5*[#Scale]),0, 0,(100*[#Scale]),(100*[#Scale]) | 217,217,218,200;0.0 | 75,75,78,185;0.5 | 37, 37, 38,0;1.0
Group=Main
DynamicVariables=1

[ShapesStyle]
MyGradient= ([MouseXRaw]-#CURRENTCONFIGX#-[[#CURRENTSECTION]:X]-[[#CURRENTSECTION]:W]/2),(([MouseYRaw]-#CURRENTCONFIGY#-[[#CURRENTSECTION]:Y]-[[#CURRENTSECTION]:H]/2)),0, 0,(100*[#Scale]),(100*[#Scale]) | 87,87,88,170;0.0 | 75,75,78,185;0.5 | 67, 67, 68,200;1.0
MyColor = Fill Color 67, 67, 68,200
MouseOverAction=[!SetOption #CURRENTSECTION# MyColor "Fill RadialGradient MyGradient"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# MyColor "Fill Color 67, 67, 68,200"][!UpdateMeter #CURRENTSECTION#][!Redraw]
Group=Main
DynamicVariables=1

[AppNameStyle]
FontFace=Segoe UI Variable Display
FontSize=(9*[#Scale])
FontColor=FFFFFF
StringAlign=Left
AntiAlias=1

[Shape0]
Meter=Shape
X=(65*[#Scale])
Y=(55*[#Scale])
MeterStyle=ShapesStyle
Shape=Rectangle 0,0 ,(125*[#Scale]), (100*[#Scale]) | StrokeWidth 0 | Extend MyColor
LeftMouseUpAction=[!UpdateMeasure SpicetifyScript][!Delay 50][#Spotify[&SpicetifyScript]]

[SpotifyIcon]
Meter=Image
ImageName=#@#Images\spotify
H=(35*[#Scale])
X=([Shape0:W]/2-[[#CURRENTSECTION]:W]/2+1)r
Y=([Shape0:H]/2-[[#CURRENTSECTION]:H]/2)r
DynamicVariables=1
[SpotifyString]
Meter=String
X=([Shape0:X]+10*[#Scale])
Y=(12*[#Scale])R
Text=Spotify
MeterStyle=AppNameStyle
DynamicVariables-1

[Shape1]
Meter=Shape
X=(195*[#Scale])
Y=(55*[#Scale])
MeterStyle=ShapesStyle
Shape=Rectangle 0,0 ,(125*[#Scale]), (100*[#Scale]) | StrokeWidth 0 | Extend MyColor
LeftMouseUpAction=[!WriteKeyValue Variables Player "NowPlaying" "#ROOTCONFIGPATH#FlatPlayer.ini"][!WriteKeyValue MeasureState PlayerName "CAD" "#@#Players\NowPlaying.inc"][!Refresh "#ROOTCONFIG#"]

[FoobarIcon]
Meter=Image
ImageName=#@#Images\foobar2000
H=(35*[#Scale])
X=([Shape1:W]/2-[[#CURRENTSECTION]:W]/2)r
Y=([Shape1:H]/2-[[#CURRENTSECTION]:H]/2)r
DynamicVariables=1
[FoobarString]
Meter=String
X=([Shape1:X]+10*[#Scale])
Y=(12*[#Scale])R
Text=foobar2000
MeterStyle=AppNameStyle
DynamicVariables-1

[Shape2]
Meter=Shape
X=(65*[#Scale])
Y=(160*[#Scale])
MeterStyle=ShapesStyle
Shape=Rectangle 0,0,(125*[#Scale]), (100*[#Scale]) | StrokeWidth 0 | Extend MyColor
LeftMouseUpAction=[!WriteKeyValue Variables Player "NowPlaying" "#ROOTCONFIGPATH#FlatPlayer.ini"][!WriteKeyValue MeasureState PlayerName "iTunes" "#@#Players\NowPlaying.inc"][!Refresh "#ROOTCONFIG#"]

[iTunesIcon]
Meter=Image
ImageName=#@#Images\iTunes
H=(35*[#Scale])
X=([Shape2:W]/2-[[#CURRENTSECTION]:W]/2+1)r
Y=([Shape2:H]/2-[[#CURRENTSECTION]:H]/2)r
DynamicVariables=1
[iTunesString]
Meter=String
X=([Shape2:X]+10*[#Scale])
Y=(12*[#Scale])R
Text=iTunes
MeterStyle=AppNameStyle
DynamicVariables-1

[Shape3]
Meter=Shape
X=(195*[#Scale])
Y=(160*[#Scale])
MeterStyle=ShapesStyle
Shape=Rectangle 0,0 ,(125*[#Scale]), (100*[#Scale]) | StrokeWidth 0 | Extend MyColor
LeftMouseUpAction=[!WriteKeyValue Variables Player "NowPlaying" "#ROOTCONFIGPATH#FlatPlayer.ini"][!WriteKeyValue MeasureState PlayerName "CAD" "#@#Players\NowPlaying.inc"][!Refresh "#ROOTCONFIG#"]

[MusicBeeIcon]
Meter=Image
ImageName=#@#Images\musicbee
H=(35*[#Scale])
X=([Shape1:W]/2-[[#CURRENTSECTION]:W]/2)r
Y=([Shape1:H]/2-[[#CURRENTSECTION]:H]/2)r
DynamicVariables=1
[MusicBeeString]
Meter=String
X=([Shape3:X]+10*[#Scale])
Y=(12*[#Scale])R
Text=MusicBee
MeterStyle=AppNameStyle
DynamicVariables-1

[Shape4]
Meter=Shape
X=(65*[#Scale])
Y=(265*[#Scale])
MeterStyle=ShapesStyle
Shape=Rectangle 0,0 ,(125*[#Scale]), (100*[#Scale]) | StrokeWidth 0 | Extend MyColor
LeftMouseUpAction=[!WriteKeyValue Variables Player "NowPlaying" "#ROOTCONFIGPATH#FlatPlayer.ini"][!WriteKeyValue MeasureState PlayerName "Winamp" "#@#Players\NowPlaying.inc"][!Refresh "#ROOTCONFIG#"]

[WinampIcon]
Meter=Image
ImageName=#@#Images\winamp
H=(35*[#Scale])
X=([Shape2:W]/2-[[#CURRENTSECTION]:W]/2+1)r
Y=([Shape2:H]/2-[[#CURRENTSECTION]:H]/2)r
DynamicVariables=1
[WinampString]
Meter=String
X=([Shape4:X]+10*[#Scale])
Y=(12*[#Scale])R
Text=winamp
MeterStyle=AppNameStyle
DynamicVariables-1

[Shape5]
Meter=Shape
X=(195*[#Scale])
Y=(265*[#Scale])
MeterStyle=ShapesStyle
Shape=Rectangle 0,0 ,(125*[#Scale]), (100*[#Scale]) | StrokeWidth 0 | Extend MyColor
LeftMouseUpAction=[!WriteKeyValue Variables Player "NowPlaying" "#ROOTCONFIGPATH#FlatPlayer.ini"][!WriteKeyValue MeasureState PlayerName "AIMP" "#@#Players\NowPlaying.inc"][!Refresh "#ROOTCONFIG#"]

[AIMPIcon]
Meter=Image
ImageName=#@#Images\aimp
H=(37*[#Scale])
X=([Shape1:W]/2-[[#CURRENTSECTION]:W]/2)r
Y=([Shape1:H]/2-[[#CURRENTSECTION]:H]/2)r
DynamicVariables=1
[AIMPString]
Meter=String
X=([Shape5:X]+10*[#Scale])
Y=(11*[#Scale])R
Text=AIMP
MeterStyle=AppNameStyle
DynamicVariables-1

[Shape6]
Meter=Shape
X=(65*[#Scale])
Y=(370*[#Scale])
MeterStyle=ShapesStyle
Shape=Rectangle 0,0 ,(125*[#Scale]), (100*[#Scale]) | StrokeWidth 0 | Extend MyColor
LeftMouseUpAction=[!WriteKeyValue Variables Player "NowPlaying" "#ROOTCONFIGPATH#FlatPlayer.ini"][!WriteKeyValue MeasureState PlayerName "WMP" "#@#Players\NowPlaying.inc"][!Refresh "#ROOTCONFIG#"]

[WmpIcon]
Meter=Image
ImageName=#@#Images\wmp
H=(35*[#Scale])
X=([Shape2:W]/2-[[#CURRENTSECTION]:W]/2+1)r
Y=([Shape2:H]/2-[[#CURRENTSECTION]:H]/2)r
DynamicVariables=1
[WmpString]
Meter=String
X=([Shape6:X]+10*[#Scale])
W=([Shape6:W]-20)
Y=(12*[#Scale])R
ClipString=1
Text=Windows Media Player
MeterStyle=AppNameStyle
DynamicVariables-1

[Shape7]
Meter=Shape
X=(195*[#Scale])
Y=(370*[#Scale])
MeterStyle=ShapesStyle
Shape=Rectangle 0,0 ,(125*[#Scale]), (100*[#Scale]) | StrokeWidth 0 | Extend MyColor
LeftMouseUpAction=[!WriteKeyValue Variables Player "WebNowPlaying" "#ROOTCONFIGPATH#FlatPlayer.ini"][!Refresh "#ROOTCONFIG#"]

[WNPIcon]
Meter=Image
ImageName=#@#Images\wnp
H=(35*[#Scale])
X=([Shape1:W]/2-[[#CURRENTSECTION]:W]/2-1)r
Y=([Shape1:H]/2-[[#CURRENTSECTION]:H]/2)r
DynamicVariables=1
[WNPString]
Meter=String
X=([Shape7:X]+10*[#Scale])
Y=(12*[#Scale])R
Text=WebNowPlaying
MeterStyle=AppNameStyle
DynamicVariables-1