object frmCompra: TfrmCompra
  Left = 428
  Top = 174
  Width = 806
  Height = 514
  Caption = 'Compras'
  Color = clWhite
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object Bevel1: TBevel
    Left = 8
    Top = 335
    Width = 769
    Height = 16
    ParentShowHint = False
    Shape = bsTopLine
    ShowHint = True
  end
  object DBGrid1: TDBGrid
    Left = 16
    Top = 8
    Width = 521
    Height = 185
    DataSource = DataSource1
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = 'Id'
        Title.Caption = '# Id'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Arial'
        Title.Font.Style = []
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Produto'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Arial'
        Title.Font.Style = []
        Width = 264
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Valor'
        Title.Alignment = taRightJustify
        Title.Caption = 'R$ Pre'#231'o'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Arial'
        Title.Font.Style = []
        Width = 112
        Visible = True
      end>
  end
  object btnAtualiza: TBitBtn
    Left = 16
    Top = 200
    Width = 521
    Height = 41
    Cursor = crHandPoint
    Caption = 'Atualizar'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    OnClick = btnAtualizaClick
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 448
    Width = 798
    Height = 29
    Panels = <
      item
        Width = 100
      end
      item
        Width = 50
      end>
  end
  object GroupBox1: TGroupBox
    Left = 544
    Top = 56
    Width = 233
    Height = 113
    Color = clWhite
    ParentColor = False
    TabOrder = 3
    object lblTotalPagar: TLabel
      Left = 2
      Top = 66
      Width = 229
      Height = 45
      Align = alBottom
      Alignment = taCenter
      BiDiMode = bdLeftToRight
      Caption = 'R$ 100,00'
      Color = clWhite
      Font.Charset = ANSI_CHARSET
      Font.Color = clRed
      Font.Height = -40
      Font.Name = 'Arial'
      Font.Style = []
      ParentBiDiMode = False
      ParentColor = False
      ParentFont = False
      Layout = tlCenter
    end
    object Label1: TLabel
      Left = 2
      Top = 15
      Width = 229
      Height = 23
      Align = alTop
      Alignment = taCenter
      BiDiMode = bdLeftToRight
      Caption = 'TOTAL A PAGAR'
      Color = clWhite
      Font.Charset = ANSI_CHARSET
      Font.Color = clBlue
      Font.Height = -20
      Font.Name = 'Arial'
      Font.Style = []
      ParentBiDiMode = False
      ParentColor = False
      ParentFont = False
      Layout = tlCenter
    end
  end
  object btnFinaliza: TBitBtn
    Left = 16
    Top = 256
    Width = 753
    Height = 57
    Cursor = crHandPoint
    Caption = 'Finalizar Compra'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -23
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    OnClick = btnFinalizaClick
  end
  object btnVoltar: TBitBtn
    Left = 16
    Top = 360
    Width = 753
    Height = 57
    Cursor = crHandPoint
    Caption = 'Voltar'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -23
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
    OnClick = btnVoltarClick
  end
  object zConexao: TZConnection
    ControlsCodePage = cGET_ACP
    AutoEncodeStrings = False
    HostName = 'com.br'
    Port = 3306
    Database = 'natura'
    User = 'usernat'
    Password = '*****'
    Protocol = 'mysql'
    Left = 224
    Top = 80
  end
  object ClientDataSet1: TClientDataSet
    Aggregates = <>
    Params = <>
    Left = 432
    Top = 96
    object ClientDataSet1Id: TIntegerField
      FieldName = 'Id'
    end
    object ClientDataSet1Produto: TStringField
      FieldName = 'Produto'
      Size = 80
    end
    object ClientDataSet1Valor: TFloatField
      FieldName = 'Valor'
      DisplayFormat = '###,###,##0.00'
    end
  end
  object ZQuery1: TZQuery
    Connection = zConexao
    Params = <>
    Left = 256
    Top = 80
  end
  object DataSource1: TDataSource
    DataSet = ClientDataSet1
    Left = 416
    Top = 112
  end
end
