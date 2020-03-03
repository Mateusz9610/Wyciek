object Form1: TForm1
  Left = 186
  Top = 127
  Width = 615
  Height = 549
  HorzScrollBar.Visible = False
  VertScrollBar.Visible = False
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnCreate = FormCreate
  OnKeyDown = FormKeyDown
  OnKeyUp = FormKeyUp
  PixelsPerInch = 96
  TextHeight = 13
  object tlo: TShape
    Left = 0
    Top = 0
    Width = 599
    Height = 510
    Brush.Color = clScrollBar
    ParentShowHint = False
    Pen.Color = clGray
    ShowHint = False
  end
  object IloscGwiazd: TLabel
    Left = 552
    Top = 32
    Width = 3
    Height = 13
  end
  object MediaPlayer1: TMediaPlayer
    Left = 544
    Top = 0
    Width = 29
    Height = 30
    Enabled = False
    VisibleButtons = []
    AutoEnable = False
    Shareable = True
    ParentShowHint = False
    ShowHint = True
    TabOrder = 0
  end
  object TimerOtoczenie: TTimer
    Interval = 50
    OnTimer = TimerOtoczenieTimer
    Left = 16
    Top = 16
  end
  object Lewo: TTimer
    Enabled = False
    Interval = 10
    OnTimer = LewoTimer
    Left = 16
    Top = 48
  end
  object Prawo: TTimer
    Enabled = False
    Interval = 10
    OnTimer = PrawoTimer
    Left = 40
    Top = 48
  end
  object Gora: TTimer
    Enabled = False
    Interval = 10
    OnTimer = GoraTimer
    Left = 64
    Top = 48
  end
  object Dol: TTimer
    Enabled = False
    Interval = 10
    OnTimer = DolTimer
    Left = 88
    Top = 48
  end
  object TimerPrzeszkoda: TTimer
    Interval = 2000
    OnTimer = TimerPrzeszkodaTimer
    Left = 16
    Top = 80
  end
  object TimerGwiazda: TTimer
    Interval = 2500
    OnTimer = TimerGwiazdaTimer
    Left = 48
    Top = 80
  end
end
