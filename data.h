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
            background-color: lightslategray; 
            background-image: linear-gradient(to bottom,#3746ee,#b6a2ff);
            margin: 1%;
            padding: 5%;
            font-family: Arial, sans-serif;
        }

        h1 {
            text-align: center;
            font-size: 24px;
            color: #33285e;
            padding: 20px 0;
        }

        .container {
            display: flex;
            flex-wrap: wrap;
            justify-content: center;
            align-items: center;
            padding: 20px;
        }

        .box {
            padding: 10px;
            text-align: center;
        }

        .box a {
            display: block;
            margin-bottom: 10px;
            text-decoration: none;
            background-color: #4CAF50;
            color: white;
            padding: 10px;
            border-radius: 5px;
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

<h1>Mi programa serio esp32</h1>

<div class="container">
 
    
    <!-- Repite los demás bloques de filas de la tabla siguiendo el mismo formato -->

    )====";
    const String responseHTML1 =  R"====(  <div class="box">
        <p>SALIDA # )====";
     const String responseHTML2  = R"====(     </p>
        <a href="/on  )====";
     const String responseHTML3  = R"====(     ">ON</a>
        <a href="/off  )====";
     const String responseHTML4  = R"====(     ">OFF</a>
    </div>  )====";  
  const String responseHTML5 =  R"====(  </div>    </body>  </html>
     )====";
