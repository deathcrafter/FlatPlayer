[MeasureState]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=State
OnChangeAction=[!UpdateMeterGroup Player][!Redraw]
UpdateDivider=5

[MeasureTrack]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Title
RegExpSubstitute=1
Substitute="":"N\A", "^(.+)\s\(.+$":"\1"

[MeasureArtist]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Artist
Substitute="":"N\A"

[MeasureProgress]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Progress