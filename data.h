const String pagina =  R"====(
<!DOCTYPE html>
<html lang="es">
  <head>
    <meta charset="utf-8">
    <title>Identificador</title>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <style>
     body {
            background-image: linear-gradient(to top,#5a07f0, #d17bff);
            margin: 1%;
            padding: 9.5%;
            font-family: Impact, Haettenschweiler, 'Arial Narrow Bold', sans-serif;
            
            
        }
        input {
            color: white;
            font-weight: bold;
            margin-bottom: 20%;
            width: 100%;
        }
        p {
            color: black;
            font-weight: bold;
        }

        h1 {
            text-align: center;
            font-size: 24px;
            color: white;
            padding: 20px 0;
        }
        

        .container {
            color: white;
            width: 80%;
            height: inherit;
            display: flex;
            flex-wrap: wrap;
            justify-content: center;
            align-items: center;
            padding: 0%;
            margin: 12%;
            background-color: white;
            position: relative;
            border: 2px solid;
            border-radius: 20px;
            box-shadow: rgb(150,150,150) 5px 5px 20px;
        }

        .box {
            padding-left: 10px;
            text-align: center;
        }

        .box input {
                background-image: linear-gradient(to top,#186a3b,  #2ecc71);
                display: block;
                text-decoration: none;
                color: white;
                padding: 10px;
                border-radius: 15px;
                transition: background-color 0.3s;
                
        }
        .box input:active{
            background-image: linear-gradient(to top,#dc2f02,  #f48c06);
            
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
      <h1>interface IoT</h1>

      <div class="container">)====";

const String pagina1 =  R"====( <div class="box">
        <p>SALIDA #)====";
        
const String pagina2 =  R"====(</p>
        <input type="button" id="botonEncender" onclick="botonEncender)====";
const String pagina3 =  R"====(()" value="Encender">
        <input type="button" id="botonApagar"  onclick="botonApagar)====";
const String pagina4 =  R"====(()" value="Apagar">
        </div>)====";
const String pagina5 =  R"====(</div>
    <script>)====";
const String pagina6 =  R"====(function botonEncender)====";

const String pagina7 =  R"====((){
          consultaGET("on)====";
const String pagina8 =  R"====(");
      }
      function botonApagar)====";
const String pagina9 =  R"====((){
          consultaGET("off)====";
const String pagina10 =  R"====(");
      })====";
const String pagina11 =  R"====(function consultaGET(consulta){
          const Http = new XMLHttpRequest();
          console.log(`Consultando  ${consulta}`)
          Http.open("GET", consulta);
          Http.send();

          Http.onreadystatechange = (e) => {
          console.log(Http.status );
          console.log(Http.responseText);
          };
      }
        </script>
        </body>
        </html>)====";

const String pagina20 =  R"====(function botonEncender)====";
