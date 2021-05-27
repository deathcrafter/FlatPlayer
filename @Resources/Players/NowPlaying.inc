[MeasureState]
Measure=NowPlaying
PlayerName=Winamp
PlayerType=State
OnChangeAction=[!UpdateMeterGroup Player][!Redraw]
UpdateDivider=5

[MeasureTrack]
Measure=NowPlaying
PlayerName=[MeasureState]
PlayerType=Title
RegExpSubstitute=1
Substitute="":"N\A", "^(.+)\s\(.+$":"\1"

[MeasureArtist]
Measure=NowPlaying
PlayerName=[MeasureState]
PlayerType=Artist
RegExpSubstitute=1
Substitute="":"N\A", "^(.+)\,.+$":"\1"

[MeasureProgress]
Measure=NowPlaying
PlayerName=[MeasureState]
PlayerType=Progress
