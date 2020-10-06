<?php 
	
	// WebService - Natura - Versão 1.0
	// 01/10/2020 às 07h45
	
    $vcontainer_01  = $_GET['vcontainer_01'];
	$vcontainer_02  = $_GET['vcontainer_02'];
    $vcontainer_03  = $_GET['vcontainer_03'];
	$vcontainer_04  = $_GET['vcontainer_04'];
	$vcontainer_05  = $_GET['vcontainer_05'];
	$vstatusbotao   = $_GET['vstatusbotao'];

	date_default_timezone_set('America/Sao_Paulo');
	$data= date('Y-m-d');
	$hora= date('H:i:s');	
	
	$servername = "localhost";
	$username = "usernat";
	$password = "*******";
	$dbname = "natura";

	// Create connection
	$conn = mysqli_connect($servername, $username, $password, $dbname);
	// Check connection
	if (!$conn) {
		die("Connection failed: " . mysqli_connect_error());
	}
		
		//////////////////////////////////////////////////////////////////////////
		// Quando apertou o botão...
		//////////////////////////////////////////////////////////////////////////
		if ($vstatusbotao==0)
		{
		  // se entrou aqui é porque o botão foi apertado.
		  
		  //////////////////////////////////////////////////////////////////////////
		  // CONTAINER 01...
		  //////////////////////////////////////////////////////////////////////////
		  if ($vcontainer_01 == 0)
		  {
		    // se entrou aqui é porque comprou o produto do container 1
			$sql_compra_01 = " update posicoes set container_01 = 0 ";
		    if (mysqli_query($conn, $sql_compra_01))
		    {
		      echo $xMsg = $xMsg . " [buy container 01 - [OK] ] ";
		    }  
		    else
		    {
		      echo $xMsg = $xMsg . " [buy container 01 - [ERRO] ] ";
		    }
			
		  }
		  else
		  {
		    // se entrou aqui é porque fez reposicao
			$sql_compra_01 = " update posicoes set container_01 = 1 ";
		    if (mysqli_query($conn, $sql_compra_01))
		    {
		      echo $xMsg = $xMsg . " [reposicao container 01 - [OK] ] ";
		    }  
		    else
		    {
		      echo $xMsg = $xMsg . " [reposicao container 01 - [ERRO] ] ";
		    }
		  
		  }
		  
		  
		  //////////////////////////////////////////////////////////////////////////
		  // CONTAINER 02...
		  //////////////////////////////////////////////////////////////////////////
		  if ($vcontainer_02 == 0)
		  {
		    // se entrou aqui é porque comprou o produto do container 2
			$sql_compra_02 = " update posicoes set container_02 = 0 ";
		    if (mysqli_query($conn, $sql_compra_02))
		    {
		      echo $xMsg = $xMsg . " [buy container 02 - [OK] ] ";
		    }  
		    else
		    {
		      echo $xMsg = $xMsg . " [buy container 02 - [ERRO] ] ";
		    }
			
		  }
		  else
		  {
		    // se entrou aqui é porque fez reposicao
			$sql_compra_02 = " update posicoes set container_02 = 1 ";
		    if (mysqli_query($conn, $sql_compra_02))
		    {
		      echo $xMsg = $xMsg . " [reposicao container 02 - [OK] ] ";
		    }  
		    else
		    {
		      echo $xMsg = $xMsg . " [reposicao container 02 - [ERRO] ] ";
		    }
		  
		  }
		  
		  
		  //////////////////////////////////////////////////////////////////////////
		  // CONTAINER 03...
		  //////////////////////////////////////////////////////////////////////////
		  if ($vcontainer_03 == 0)
		  {
		    // se entrou aqui é porque comprou o produto do container 3
			$sql_compra_03 = " update posicoes set container_03 = 0 "; 
		    if (mysqli_query($conn, $sql_compra_03))
		    {
		      echo $xMsg = $xMsg . " [buy container 03 - [OK] ] ";
		    }  
		    else
		    {
		      echo $xMsg = $xMsg . " [buy container 03 - [ERRO] ] ";
		    }
			
		  }
		  else
		  {
		  
			$sql_compra_03 = " update posicoes set container_03 = 1 "; 
		    if (mysqli_query($conn, $sql_compra_03))
		    {
		      echo $xMsg = $xMsg . " [reposicao container 03 - [OK] ] ";
		    }  
		    else
		    {
		      echo $xMsg = $xMsg . " [reposicao container 03 - [ERRO] ] ";
		    }
		  
		  }
		  
		  
		  //////////////////////////////////////////////////////////////////////////
		  // CONTAINER 04...
		  //////////////////////////////////////////////////////////////////////////
		  if ($vcontainer_04 == 0)
		  {
		    // se entrou aqui é porque comprou o produto do container 3
			$sql_compra_04 = " update posicoes set container_04 = 0 "; 
		    if (mysqli_query($conn, $sql_compra_04))
		    {
		      echo $xMsg = $xMsg . " [buy container 04 - [OK] ] ";
		    }  
		    else
		    {
		      echo $xMsg = $xMsg . " [buy container 04 - [ERRO] ] ";
		    }
			
		  } 
		  else
		  {
			$sql_compra_04 = " update posicoes set container_04 = 1 "; 
		    if (mysqli_query($conn, $sql_compra_04))
		    {
		      echo $xMsg = $xMsg . " [reposicao container 04 - [OK] ] ";
		    }  
		    else
		    {
		      echo $xMsg = $xMsg . " [reposicao container 04 - [ERRO] ] ";
		    }
		  }
		  
		  //////////////////////////////////////////////////////////////////////////
		  // CONTAINER 04...
		  //////////////////////////////////////////////////////////////////////////
		  if ($vcontainer_05 == 0)
		  {
		    // se entrou aqui é porque comprou o produto do container 5
			$sql_compra_05 = " update posicoes set container_05 = 0 "; 
		    if (mysqli_query($conn, $sql_compra_05))
		    {
		      echo $xMsg = $xMsg . " [buy container 05 - [OK] ] ";
		    }  
		    else
		    {
		      echo $xMsg = $xMsg . " [buy container 05 - [ERRO] ] ";
		    }
			
		  } 
		  else
		  {
			$sql_compra_05 = " update posicoes set container_05 = 1 "; 
		    if (mysqli_query($conn, $sql_compra_05))
		    {
		      echo $xMsg = $xMsg . " [reposicao container 05 - [OK] ] ";
		    }  
		    else
		    {
		      echo $xMsg = $xMsg . " [reposicao container 05 - [ERRO] ] ";
		    }
		  }
		  
		}
		mysqli_close($conn);
			
	
?>