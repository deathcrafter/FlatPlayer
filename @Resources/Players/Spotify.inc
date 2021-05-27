[MeasureState]
Measure=Plugin
Plugin=WebNowPlaying
Player=Spotify
PlayerType=State
OnChangeAction=[!UpdateMeterGroup Player][!Redraw]
UpdateDivider=5

[MeasureTrack]
Measure=NowPlaying
PlayerName=Spotify
PlayerType=Title
RegExpSubstitute=1
Substitute="^(.+)\s+?\(.+$":"\1"

[MeasureArtist]
Measure=NowPlaying
PlayerName=Spotify
PlayerType=Artist
Substitute="":"N\A"

[MeasureProgress]
Measure=Plugin
Plugin=WebNowPlaying
Player=Spotify
PlayerType=Progress