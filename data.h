const String responseHTML =  R"====(<!DOCTYPE html>
<!DOCTYPE html>
<html lang="es">
  <head>
    <meta charset="utf-8">
    <title></title>
  </head>
  <body>
    <header></header>
    <main></main>
    <!DOCTYPE html>

    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Identificador</title>
    <style>
        body {
            background-image: linear-gradient(to top,#5a07f0, #d17bff);
            margin: 1%;
            padding: 9.5%;
            font-family: Impact, Haettenschweiler, 'Arial Narrow Bold', sans-serif;
            
            
        }
        a {
            color: white;
            font-weight: bold;
            margin-bottom: 20%;
        }
        p {
            color: black;
            font-weight: bold;
            margin: 0.5%;
            pading:0%;
        }

        h1 {
            text-align: center;
            font-size: 24px;
            color: white;
            padding: 4%;
            margin:0%;
            
        }

        .container {
            color: white;
            width: 90%;
            height: inherit;
            display: flex;
            flex-wrap: wrap;
            justify-content: center;
            align-items: center;
            padding: 0%;
            margin-left: 7%;
            background-color: white;
            position: relative;
            border: 0px solid;
            border-radius: 20px;
            box-shadow: rgb(150,150,150) 5px 5px 20px;
        }

        .box {
            padding: 5%;
            text-align: center;
        }

        .box a {
                background-image: linear-gradient(to top,#186a3b,  #2ecc71);
                display: block;
                text-decoration: none;
                color: white;
                padding: 10%;
                border-radius: 15px;
                transition: background-color 0.3s;
                
        }

        .box a:hover {
            background-color: #e3bf0e;
        }

        .box a:active{
            background-color: red;
        }

        @media (min-width: 768px) {
            .container {
                max-width: 600px;
            }
        }

        @media (min-width: 992px) {
            .container {
                max-width: 800px;
            }
        }

        @media (min-width: 1200px) {
            .container {
                max-width: 1000px;
            }
        }

    </style>
</head>
<body>

<h1>Internet de las cosas</h1>

<div class="container">
 
    
    <!-- Repite los demás bloques de filas de la tabla siguiendo el mismo formato -->

    )====";
    const String responseHTML1 =  R"====(<div class="box">
        <p>SALIDA )====";
     const String responseHTML2  = R"====(</p>
        <a href="/on)====";
     const String responseHTML3  = R"====(">ON</a>
        <a href="/off)====";
     const String responseHTML4  = R"====(">OFF</a>&nbsp
    </div>)====";  
  const String responseHTML5 =  R"====(  </div>    </body>  </html>
     )====";
