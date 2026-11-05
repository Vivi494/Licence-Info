<?php
session_start();
$fond=$_POST["fond"] ?? "white";
$texte=$_POST["texte"] ?? "black";

if($fond!="white"){
    $_SESSION["CouleurFond"]=$fond;
}
if($texte!="black"){
    $_SESSION["CouleurPolice"]=$texte;
}
?>

<!DOCTYPE html>
<html>

<head>
    <meta charset="UTF-8" />
    <title>TP PHP - Personnalisation avec sessions</title>
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
            background-color: <?= $_SESSION["CouleurFond"] ?? "white" ?>;
            color: <?= $_SESSION["CouleurPolice"] ?? "black" ?>;
        }
    </style>
</head>

<body>
    <form method="post" action="sessions.php">
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

    <p>Contenu de la page principale <br />
        <a href="sessions-B.php">Lien vers la page B qui aura ces couleurs</a>
    </p>
</body>
</html>
