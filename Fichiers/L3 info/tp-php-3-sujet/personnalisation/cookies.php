<?php

$ck1=$_COOKIE["CouleurFond"] ?? "white";
$ck2=$_COOKIE["CouleurPolice"] ?? "black";

if(isset($_POST["fond"])){
    setcookie("CouleurFond" , $_POST["fond"] , time()+10);
}
if(isset($_POST["texte"])){
    setcookie("CouleurPolice" , $_POST["texte"] , time()+10);
}
?>

<!DOCTYPE html>
<html>

<head>
    <meta charset="UTF-8" />
    <title>TP PHP - Personnalisation avec cookies</title>
    <style type="text/css">
        /* A COMPLETER */
        legend {
            font-weight: bold;
            font-family: cursive;
        }

        label {
            font-weight: bold;
            font-style: italic;
        }

        body {
            background-color: <?= $ck1 ?>;
            color: <?= $ck2 ?>;
        }
    </style>
</head>

<body>
    <form method="post" action="cookies.php">
        <fieldset>
            <legend>Choisissez vos couleurs (mot clé ou code)</legend>
            <label>Couleur de fond
                <input type="text" name="fond" />
            </label><br /><br />
            <label>Couleur de texte
                <input type="text" name="texte" />
            </label><br />
            <input type="submit" value="Envoyer" />&nbsp;&nbsp;
            <input type="reset" value="Effacer" />
        </fieldset>
    </form>
</body>

</html>