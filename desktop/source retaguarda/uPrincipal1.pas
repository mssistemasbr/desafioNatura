unit uPrincipal1;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, ExtCtrls, pngimage, ComCtrls, jpeg;

type
  TfrmPrincipal = class(TForm)
    imgFundo: TImage;
    Panel1: TPanel;
    imgCompra: TImage;
    StatusBar1: TStatusBar;
    Timer1: TTimer;
    imgSair: TImage;
    Bevel1: TBevel;
    procedure imgCompraClick(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure Timer1Timer(Sender: TObject);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure imgSairClick(Sender: TObject);
    procedure FormDestroy(Sender: TObject);
  private
  public
    { Public declarations }
  end;

var
  frmPrincipal: TfrmPrincipal;

implementation

uses
  uCompra;

{$R *.dfm}

procedure TfrmPrincipal.imgCompraClick(Sender: TObject);
begin
  if (frmCompra = Nil) then
  begin
    try
      Application.CreateForm(TfrmCompra, frmCompra);
      frmCompra.ShowModal;
    except
      on e: exception do
      begin
        ShowMessage('Não foi possível abrir o formulário de compras.'+#13+#10+'Erro:'+E.Message);
      end;
    end;
  end;
end;

procedure TfrmPrincipal.FormCreate(Sender: TObject);
begin
  StatusBar1.Panels[0].Text := ' Versão 1.0 ';
  StatusBar1.Panels[1].Text := ' Cliente: Natura ';

  Timer1.Enabled := True;

  //Self.ClientHeight := 600;
  //Self.ClientWidth  := 800;
end;

procedure TfrmPrincipal.Timer1Timer(Sender: TObject);
begin
  StatusBar1.Panels[2].Text := ' Data: '+FormatDateTime('dd/mm/yyyy', Date);
  StatusBar1.Panels[3].Text := ' Hora: '+FormatDateTime('hh:mm:ss', Time);
end;

procedure TfrmPrincipal.FormClose(Sender: TObject;
  var Action: TCloseAction);
begin
  Action:= caFree;
end;

procedure TfrmPrincipal.imgSairClick(Sender: TObject);
begin
  Close;
end;

procedure TfrmPrincipal.FormDestroy(Sender: TObject);
begin
  frmPrincipal := Nil;
end;

end.
