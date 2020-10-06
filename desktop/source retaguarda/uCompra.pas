unit uCompra;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, ZAbstractRODataset, ZAbstractDataset, ZDataset, DB, DBClient,
  ZAbstractConnection, ZConnection, Grids, DBGrids, StdCtrls, Buttons,
  ComCtrls, ExtCtrls;

type
  TfrmCompra = class(TForm)
    DBGrid1: TDBGrid;
    zConexao: TZConnection;
    ClientDataSet1: TClientDataSet;
    ClientDataSet1Id: TIntegerField;
    ClientDataSet1Produto: TStringField;
    ClientDataSet1Valor: TFloatField;
    ZQuery1: TZQuery;
    DataSource1: TDataSource;
    btnAtualiza: TBitBtn;
    StatusBar1: TStatusBar;
    GroupBox1: TGroupBox;
    btnFinaliza: TBitBtn;
    lblTotalPagar: TLabel;
    Label1: TLabel;
    btnVoltar: TBitBtn;
    Bevel1: TBevel;
    procedure btnAtualizaClick(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure btnFinalizaClick(Sender: TObject);
    procedure btnVoltarClick(Sender: TObject);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure FormDestroy(Sender: TObject);
  private
    iCont : Integer;
    dTotal: Double;

    procedure CheckCompra();
    procedure AddProduto(sProduto: String; dValor: Double);
    procedure Totalizadores();
    procedure Inicializa();
  public
  end;

var
  frmCompra: TfrmCompra;

implementation

{$R *.dfm}

procedure TfrmCompra.AddProduto(sProduto: String; dValor: Double);
begin
  if not ClientDataSet1.Active then
  begin
    ClientDataSet1.CreateDataSet;
    ClientDataSet1.EmptyDataSet;
  end;


  ClientDataSet1.Append;
  ClientDataSet1.FieldByName('Id').AsInteger      := iCont;
  ClientDataSet1.FieldByName('Produto').AsString  := sProduto;
  ClientDataSet1.FieldByName('Valor').AsFloat     := dValor;
  ClientDataSet1.Post;

  dTotal:= dTotal+dValor;
  Inc(iCont);
end;

procedure TfrmCompra.CheckCompra;
var
  dPreco1, dPreco2, dPreco3, dPreco4, dPreco5: Double;
  sProduto1, sProduto2, sProduto3, sProduto4, sProduto5: String;
begin
  dPreco1:= 10;
  dPreco2:= 12;
  dPreco3:= 15;
  dPreco4:= 22;
  dPreco5:= 34;
  
  iCont  := 1;
  dTotal := 0;

  sProduto1:= 'Hidradante para Maõs - Ekos';
  sProduto2:= 'Sabonete Líquido - Ekos';
  sProduto3:= 'Hidradante Corporal - Ekos';
  sProduto4:= 'Óleo Trifásico - Ekos';
  sProduto5:= 'Sabonete - Ekos';

  try
    Screen.Cursor := crSQLWait;
    try
      ClientDataSet1.Close;
      ZQuery1.Close;

      ZQuery1.SQL.Text := 'select * from posicoes';
      ZQuery1.Open;

      ZQuery1.First;
      While not ZQuery1.Eof do
      begin

        if ZQuery1.FieldByName('container_01').AsString = '0' then
          AddProduto(sProduto1, dPreco1)
        else if ZQuery1.FieldByName('container_02').AsString = '0' then
          AddProduto(sProduto2, dPreco2)
        else if ZQuery1.FieldByName('container_03').AsString = '0' then
          AddProduto(sProduto3, dPreco3)
        else if ZQuery1.FieldByName('container_04').AsString = '0' then
          AddProduto(sProduto4, dPreco4)
        else if ZQuery1.FieldByName('container_05').AsString = '0' then
          AddProduto(sProduto5, dPreco5);

      ZQuery1.Next;
      end;
      Totalizadores();
    except
      on e: exception do
      begin
        ShowMessage('Não foi possível incluir o produto de compra.'+#13+#10+'Erro:'+E.Message);
      end;
    end;

  finally
    Screen.Cursor := crDefault;
  end;
end;

procedure TfrmCompra.btnAtualizaClick(Sender: TObject);
begin
  CheckCompra();
end;

procedure TfrmCompra.Totalizadores;
begin
  StatusBar1.Panels[0].Text := ' Qtde: '+IntToStr(iCont-1);
  StatusBar1.Panels[1].Text := ' Total R$: '+FormatFloat('###,###,##0.00', dTotal);
  lblTotalPagar.Caption     := ' R$: '+FormatFloat('###,###,##0.00', dTotal);
end;

procedure TfrmCompra.FormCreate(Sender: TObject);
var
  sPathDLL: String;
begin
  sPathDLL := ExtractFilePath(Application.ExeName)+'LIBMYSQL51.DLL';

  zConexao.LibraryLocation := sPathDLL;
  zConexao.Connect;
  Inicializa();

  btnAtualiza.Click;
end;

procedure TfrmCompra.btnFinalizaClick(Sender: TObject);
begin
  ShowMessage('Compra Finalizada com Sucesso.');
  Inicializa();
end;

procedure TfrmCompra.Inicializa;
begin
  StatusBar1.Panels[0].Text := ' Qtde: '+IntToStr(0);
  StatusBar1.Panels[1].Text := ' Total R$: '+FormatFloat('###,###,##0.00', 0);
  lblTotalPagar.Caption     := ' R$: '+FormatFloat('###,###,##0.00', 0);

  if ZQuery1.Active then
    ZQuery1.Close;
  if ClientDataSet1.Active then
    ClientDataSet1.Close;
end;

procedure TfrmCompra.btnVoltarClick(Sender: TObject);
begin
  Close;
end;

procedure TfrmCompra.FormClose(Sender: TObject; var Action: TCloseAction);
begin

  zConexao.Disconnect;

  Action:= caFree;
end;

procedure TfrmCompra.FormDestroy(Sender: TObject);
begin
  frmCompra:= Nil;
end;

end.
