program Retaguarda;

uses
  Forms,
  uPrincipal1 in 'uPrincipal1.pas' {frmPrincipal},
  uCompra in 'uCompra.pas' {frmCompra};

{$R *.res}

begin
  Application.Initialize;
  Application.Title := 'Compra Natura';
  Application.CreateForm(TfrmPrincipal, frmPrincipal);
  Application.Run;
end.
