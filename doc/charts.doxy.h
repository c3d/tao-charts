/**
 * @~english
 * @taomoduledescription{Charts, Charts}
 * <tt>import Charts</tt> - 2D and 3D Charts.@n
 *
 * This module allows to add some 2D and 3d charts in your presentations, in particular:
 *    - Area charts
 *    - Bar charts
 *    - Line charts
 *    - Pie charts
 *
 * To use these differents charts, you can define four differents datasets at the most, and
 * fill them with @ref chart_load_csv, @ref chart_load_tsv or @ref chart_push_data.
 * The style of these charts can changed according to the slide theme used (see Slides module).
 *
 * The code below presents some features containing in this module.
 *
 * @include charts.ddd
 *
 * @endtaomoduledescription{Charts}
 *
 * @~french
 * @taomoduledescription{Charts, Diagrammes}
 * <tt>import Charts</tt> - Diagrammes 2D & 3D.@n
 *
 * Ce module permet d'ajouter facile des diagrammes 2D et 3D dans vos présentations, parmis lesquels:
 *   - Diagrammes circulaires
 *   - Diagrammes à barres
 *   - Diagrammes linéaires
 *   - Diagrammes de zones
 *
 * Pour utiliser ces différents diagrammes, vous pouvez définir jusqu'à quatre différentes séries de
 * données, et les remplir grâce aux fonctions @ref chart_load_csv, @ref chart_load_tsv ou
 * @ref chart_push_data.
 * Le style de ces diagrammes peut changer suivant le choix du thème de diapositive (voir le module Slides).
 *
 * Le code ci-dessous présente quelques fonctionnalités de ce module.
 *
 * @include charts.ddd
 *
 * @endtaomoduledescription{Charts}
 * @~
 * @{
 */

/**
 * @~english
 * Draw a chart with a unique dataset.
 *
 * This function draw a chart with dataset @p N.\n
 * There is four types of chart:
 *    - "area" for area charts
 *    - "bar" for bar charts
 *    - "line" for line charts
 *    - "pie" for Pie charts
 *
 * You can change chart style and format with @ref chart_style
 * and @ref chart_format.\n
 * (@p W, @p H) represent the size of chart in percent.\n
 * The absolute size of chart corresponds to the size of the slide drawing zone (@ref picture)
 * and, by this way, depends also of the chosen theme.\n
 * For instance, with default theme, this size is equal to (1800, 750).
 *
 * @param N Index of the dataset (from 1 to 4).
 * @param Type Chart type.
 * @param X X-coordinate.
 * @param Y Y-coordinate.
 * @param W Chart with in percent.
 * @param H Chart height in percent.
 *
 * @~french
 *
 * Affiche un diagramme avec une série de données unique.
 *
 * Cette fonction affiche un diagramme à partir de la série de données @p N.\n
 * Il existe quatre types de diagramme:
 *    - "area" pour les diagrammes de zones
 *    - "bar" pour les diagrammes à barres (ou batons)
 *    - "line" pour les diagrammes linéaires
 *    - "pie" pour les diagrammes circulaires
 *
 * Vous pouvez change le style et le format du diagramme avec @ref chart_style
 * et @ref chart_format.\n
 * (@p W, @p H) représente la taille du diagramme en pourcentage.\n
 * La taille absolue du diagramme correspond à la taille de la zone de dessin d'une slide (@ref picture)
 * et dépend donc du thème choisi.\n
 * Par exemple, pour le thème par défaut, la taille du diagramme est (1800, 750).\n
 *
 * @param N Numéro de la série de données (de 1 à 4).
 * @param Type Type du diagramme.
 * @param X Abscisse.
 * @param Y Ordonnée.
 * @param W Largeur en pourcentage.
 * @param H Hauteur en pourcentage.
 *
 **/
chart(N:integer, Type:text, X:real, Y:real, W:real, H:real);


/**
 * @~english
 * Draw a chart with filled datasets.
 *
 * This function draw a chart with all filled datasets.\n
 * There is four types of chart:
 *    - "area" for area charts
 *    - "bar" for bar charts
 *    - "line" for line charts
 *    - "pie" for Pie charts
 *
 * You can change chart style and format with @ref chart_style
 * and @ref chart_format.\n
 * (@p W, @p H) represent the size of chart in percent.\n
 * The absolute size of chart corresponds to the size of the slide drawing zone (@ref picture)
 * and, by this way, depends also of the chosen theme.\n
 * For instance, with default theme, this size is equal to (1800, 750).
 *
 * @warning For pie chart, this function draw only the first dataset.
 *
 * @param Type Chart type.
 * @param X X-coordinate.
 * @param Y Y-coordinate.
 * @param W Chart with in percent.
 * @param H Chart height in percent.
 *
 * @~french
 *
 * Affiche un diagramme à partir des séries de données remplies.
 *
 * Cette fonction affiche un diagramme à partir des différentes séries de données remplies.\n
 * Il existe quatre types de diagramme:
 *    - "area" pour les diagrammes de zones
 *    - "bar" pour les diagrammes à barres (ou batons)
 *    - "line" pour les diagrammes linéaires
 *    - "pie" pour les diagrammes circulaires
 *
 * Vous pouvez change le style et le format du diagramme avec @ref chart_style
 * et @ref chart_format.\n
 * (@p W, @p H) représente la taille du diagramme en pourcentage.\n
 * La taille absolue du diagramme correspond à la taille de la zone de dessin d'une slide (@ref picture)
 * et dépend donc du thème choisi.\n
 * Par exemple, pour le thème par défaut, la taille d'un diagramme est (1800, 750).\n
 *
 * @warning Dans le cas du diagramme circulaire, cette fonction n'utilise que la première série de données.
 *
 * @param Type Type du diagramme.
 * @param X Abscisse.
 * @param Y Ordonnée.
 * @param W Largeur en pourcentage.
 * @param H Hauteur en pourcentage.
 *
 **/
chart(Type:text, X:real, Y:real, W:real, H:real);

/**
 * @~english
 * Return the data count of a specific dataset.
 *
 * This function returns the data count of dataset @p N.
 *
 * @param S Index of the dataset (from 1 to 4).
 *
 * @~french
 *
 * Renvoie le nombre de données dans une série.
 *
 * Cette fonction renvoie le nombre de données que contient la série @p N.
 *
 * @param S Numéro de la série de données (de 1 à 4).
 *
 **/
chart_count(N:integer);


/**
 * @~english
 * Return the number of filled datasets.
 *
 * This function returns the number of filled datasets.\n
 * The maximum value is 4.
 *
 * @~french
 *
 * Renvoie le nombre de séries de données non vides.
 *
 * Cette fonction renvoie le nombre de séries de données non vides.\n
 * La valeur maximale est 4.
 **/
chart_datasets_count();


/**
 * @~english
 * Get a specific data into a dataset.
 *
 * Get a specific data situed at the position @p I into dataset @p N.\n
 *
 * @param N Index of dataset (from 1 to 4).
 * @param I Position of data into dataset.
 *
 * @~french
 * Renvoie une valeur contenue dans une série de données.
 *
 * Renvoie la valeur situé la position @p I dans la série de données @p N.\n
 *
 * @param N Numéro de la série de données (de 1 à 4).
 * @param I Position de la donnée dans la série.
 *
 * @~
@code
chart_push_data 1, 50

// Display 50
text text (chart_data(1, 0))
@endcode
 */
chart_data(N:integer, I:integer);


/**
 * @~english
 *  Add an entry to current legend.
 *
 *  This function allow to add an entry @p T to the current legend defined
 *  with @p chart_legend.
 *
 *  @param T Legend entry.
 *
 * @~french
 * Ajoute une entrée à la légende courante.
 *
 * Cette fonction ajoute une entrée @p à la légende courante définit avec
 * @p chart_entry
 *
 * @param T Entrée de la légende.
 *
 * @~
@code
chart_legend
    chart_entry "First entry"
    chart_entry "Second entry"
    chart_entry "Thrid entry"
@endcode
 */
chart_entry(T:text);


/**
 * @~english
 * Change the format of charts.
 *
 * This function allows to change the chart format.\n
 * There are two possible formats:
 *    - "2D" to display 2D charts
 *    - "3D" to display 3D charts
 *
 * @param Format Chart format. Default is "2D".
 *
 * @~french
 * Change le format des diagrammes.
 *
 * Cette fonction permet de change le format d'un diagramme.\n
 * Il existe deux valeurs possibles:
 *    - "2D" pour afficher des diagrammes en 2D
 *    - "3D" pour afficher des diagrammes en 3D
 *
 * @param Format Format du diagramme. La valeur par défaut est "2D".
 *
 * @~
@code
chart_format "3D"
@endcode
 */
chart_format(T:text);


/**
 * @~english
 *  Show a legend for charts.
 *
 *  This function creates a container to show a legend to a chart.
 *  To add entry to this legend, you have to used @ref chart_entry
 *
 *  @param Body Specifies the contents of the legend.
 *
 * @~french
 * Affiche la légende du diagramme.
 *
 * Cette fonction ajoute une légende à un diagramme.
 * En général une légende est constitué d'une ou plusieurs entrées.
 * Celles-ci peuvent être définit grâce à la fonction @ref chart_entry
 *
 * @param Body Spécify le contenu de la légende.
 *
 * @~
@code
chart_legend
    chart_entry "First entry"
    chart_entry "Second entry"
    chart_entry "Thrid entry"
@endcode
 */
chart_legend(Body);


/**
 * @~english
 *  Load datasets directly from a csv file.
 *
 *  Use datasets of a csv file @p T.\n
 *  Load only the first four columns of the csv file.
 *
 *  @param F filename of csv file
 *
 * @~french
 * Charge des séries de données à partir d'un fichier csv.
 *
 * Charge des séries de données à partir du fichier csv @p F.\n
 * Cette fonction ne charge que les quatres premiers colonnes du fichier csv.
 *
 * @param F Nom du fichier csv
 */
chart_load_csv(F:text);


/**
 * @~english
 *  Load datasets directly from a tsv file.
 *
 *  Use datasets of a tsv file @p T.\n
 *  Load only the first four columns of the tsv file.
 *
 *  @param F filename of a tsv file
 *
 * @~french
 * Charge des séries de données à partir d'un fichier tsv.
 *
 * Charge des séries de données à partir du fichier tsv @p F.\n
 * Cette fonction ne charge que les quatres premières colonnes du fichier csv.
 *
 * @param F Nom du fichier tsv
 */
chart_load_tsv(F:text);


/**
 * @~english
 * Return the maximum data count between datasets.
 *
 * This function returns the maximum data count between datasets.\n
 * For instance, if dataset 1 has 4 data and and dataset 2 has 2 data, then
 * this function will return 4.
 *
 * @~french
 *
 * Renvoie le nombre maximum de éléments parmis les séries de données.
 *
 * Cette fonction renvoie le nombre maximum de éléments parmis les séries de données.\n
 * Par exemple, si la série de données 1 contient 4 éléments et la série de données 2 seulement 2,
 * alors cette fonction renverra la valeur 4.
 *
 **/
chart_max_count();


/**
 * @~english
 * Push a data into a dataset.
 *
 * Push data @p D at the end of the dataset @p N.
 *
 * @param N Index of the dataset (from 1 to 4).
 * @param D Data to push.
 *
 * @~french
 * Ajoute une valeur à une série de donnée.
 *
 * Ajoute la valeur @p D à la série de donnée @p N.
 *
 * @param N Numéro de la série de donnée (de 1 à 4).
 * @param D Donnée à ajouter.
 *
 * @~
@code
chart_push_data 1, 25 // Add 25 to first dataset
chart_push_data 1, 40 // Add 40 to first dataset
chart_push_data 2, 40 // Add 40 to second dataset
@endcode
 */
chart_push_data(N:integer, D:real);


/**
 * @~english
 * Reset all datasets.
 *
 * This function reset all datasets.\n
 *
 * @~french
 *
 * Réinitialise les différentes séries de données.
 *
 * Cette fonction remet à zéro les différentes séries de données.\n
 *
 * @~
@code
chart_push_data 2, 50
chart_push_data 2, 21
chart_push_data 2, 26

chart_reset
chart_count 2 // Return 0
@endcode
 **/
chart_reset();

/**
 * @~english
 * Compute sum of a dataset.
 *
 * This function computes sum of dataset @p N.\n
 *
 * @param N Index of dataset (from 1 to 4).
 *
 * @~french
 *
 * Calcule la somme d'une série de données.
 *
 * Cette fonction calcule la somme de la série de données @p N.\n
 *
 * @param N Numéro de la série de données (de 1 à 4).
 *
 * @~
@code
chart_reset
chart_push_data 2, 50
chart_push_data 2, 21
chart_push_data 2, 26

chart_sum 2 // Return 97
@endcode
 **/
chart_sum(N:integer);


/**
 * @~english
 * Return title of charts.
 *
 * This functions returns the title of charts.\n
 * To set this title, you can use @ref chart_title(T:text).
 *
 * @~french
 *
 * Renvoie le titre des diagrammes.
 *
 * Cette fonction renvoie le titre des différents diagrammes.\n
 * Pour changer cette valeur, il est possible d'utiliser la fonction @ref chart_title(T:text).
 *
 **/
chart_title();


/**
 * @~english
 * Define title of charts.
 *
 * This functions allows to set the title @p T to charts.\n
 * To get this title, you can use @ref chart_title().
 *
 * @param T Title of charts.
 *
 * @~french
 *
 * Définit le titre des diagrammes.
 *
 * Cette fonction permet d'appliquer le titre @p T aux différents diagrammes.\n
 * Pour récupérer cette valeur, il est possible d'utiliser la fonction @ref chart_title().
 *
 * @param T Titre des diagrammes.
 **/
chart_title(T:text);



/**
 * @~english
 * Change the style of charts.
 *
 * This function allows to change the style format.\n
 * Possible values are varying according to the chart type:
 *   - @ref Areacharts : "", "stacked"
 *   - @ref Barcharts : "", "vertical", "vertical_stacked", "horizontal", "horizontal_stacked"
 *   - @ref Linecharts : "", "point", "line", "line&point"
 *   - @ref Piecharts :  "", "exploded"
 *
 * @param Style Chart style. Default is "".
 *
 * @~french
 * Change le type des diagrammes.
 *
 * Cette fonction permet de change le type d'un diagramme.\n
 * Les valeurs possibles dépendent du type du diagramme :
 *   - @ref Areacharts : "", "stacked"
 *   - @ref Barcharts : "", "vertical", "vertical_stacked", "horizontal", "horizontal_stacked"
 *   - @ref Linecharts : "", "point", "line", "line&point"
 *   - @ref Piecharts :  "", "exploded"
 *
 * @param Style Style du diagramme. La valeur par défaut est "".
 *
 * @~
 */
chart_style(Style:text);


/**
 * @~english
 * Return label of X-axis.
 *
 * This functions returns the label of X-axis.\n
 * To set this label, you can use @ref chart_xlabel(T:text).
 *
 * @~french
 *
 * Renvoie le nom de l'axe X.
 *
 * Cette fonction renvoie le nom de l'axe X.\n
 * Pour changer cette valeur, il est possible d'utiliser la fonction @ref chart_xlabel(T:text).
 *
 **/
chart_xlabel();


/**
 * @~english
 * Define X-axis label.
 *
 * This functions allows to set the value @p T as X-axis label.\n
 * To get this value, you can use @ref chart_xlabel().
 *
 * @param T X-axis label.
 *
 * @~french
 *
 * Définit le nom de l'axe X.
 *
 * Cette fonction permet de changer le nom de l'axe X.\n
 * Pour récupérer cette valeur, il est possible d'utiliser la fonction @ref chart_xlabel().
 *
 * @param T Nom de l'axe X.
 **/
chart_xlabel(T:text);


/**
* @~english
* Return ticks number of X-axis.
*
* This functions return ticks number of X-axis.\n
* You can set this value with @ref chart_xticks(N:integer).
*
* @~french
*
* Renvoie le nombre d'intervalles sur l'axe X.
*
* Renvoie le nombre d'intervalle sur l'axe X.\n
* Il est possible de modifier cette valeur grâce à la fonction @ref chart_xticks(N:integer).
*
**/
chart_xticks();


/**
* @~english
* Set ticks number of X-axis.
*
* This functions set @p N ticks on X-axis.\n
* You can get this value with @ref chart_xticks().
*
* @param N Ticks number
*
* @~french
*
* Définit le nombre d'intervalles sur l'axe X.
*
* Change le nombre d'intervalle sur l'axe X.\n
* Il est possible de récupérer cette valeur grâce à la fonction @ref chart_xticks().
*
* @param N Nombre d'intervalles sur l'axe X.
*
**/
chart_xticks(N:integer);


/**
 * @~english
 * Return label of a tick located on the X-axis.
 *
 * This functions returns the label of tick @p N located on the X-axis.\n
 * To set a such label, you can use @ref chart_xticks_labels(L:list).
 *
 * @~french
 *
 * Renvoie le nom d'un intervalle particulier de l'axe X.
 *
 * Renvoie le nom de l'intervalle @p N situé sur l'axe X.\n
 * Pour changer cette valeur, il est possible d'utiliser la fonction @ref chart_xticks_labels(L:list).
 *
 * @param N Numéro de l'intervalle.
 *
 **/
chart_xticks_label(N:integer);


/**
* @~english
* Set ticks labels of X-axis.
*
* This functions use list @p L as ticks labels of X-axis.\n
* You can get a specific label with @ref chart_xticks_label(N:integer).
*
* @param L List of ticks labels
*
* @~french
*
* Définit les noms des intervalles de l'axe X.
*
* Change les noms des intervalles de l'axe X par la liste L.\n
* Il est possible de récupérer un de ces noms grâce à la fonction @ref chart_xticks_label(N:integer).
*
* @param L Liste contenant le nom des intervalles.
*
* @~
@code
// Set "First", "Second", "Third" as ticks labels
chart_xticks_labels { "First", "Second", "Third" }
@endcode
**/
chart_xticks_labels(L:list);


/**
 * @~english
 * Return label of Y-axis.
 *
 * This functions returns the label of Y-axis.\n
 * To set this label, you can use @ref chart_ylabel(T:text).
 *
 * @~french
 *
 * Renvoie le nom de l'axe Y.
 *
 * Cette fonction renvoie le nom de l'axe Y.\n
 * Pour changer cette valeur, il est possible d'utiliser la fonction @ref chart_ylabel(T:text).
 *
 **/
chart_ylabel();


/**
 * @~english
 * Define Y-axis label.
 *
 * This functions allows to set the value @p T as Y-axis label.\n
 * To get this value, you can use @ref chart_ylabel().
 *
 * @param T Y-axis label.
 *
 * @~french
 *
 * Définit le nom de l'axe Y.
 *
 * Cette fonction permet de changer le nom de l'axe Y.\n
 * Pour récupérer cette valeur, il est possible d'utiliser la fonction @ref chart_ylabel().
 *
 * @param T Nom de l'axe Y.
 **/
chart_ylabel(T:text);


/**
* @~english
* Return ticks number of Y-axis.
*
* This functions return ticks number of Y-axis.\n
* You can set this value with @ref chart_yticks(N:integer).
*
* @~french
*
* Renvoie le nombre d'intervalles sur l'axe Y.
*
* Renvoie le nombre d'intervalle sur l'axe Y.\n
* Il est possible de modifier cette valeur grâce à la fonction @ref chart_yticks(N:integer).
*
**/
chart_yticks();


/**
* @~english
* Set ticks number of Y-axis.
*
* This functions set @p N ticks on Y-axis.\n
* You can get this value with @ref chart_yticks().
*
* @param N Ticks number
*
* @~french
*
* Définit le nombre d'intervalles sur l'axe Y.
*
* Change le nombre d'intervalle sur l'axe Y.\n
* Il est possible de récupérer cette valeur grâce à la fonction @ref chart_yticks().
*
* @param N Nombre d'intervalles sur l'axe Y.
*
**/
chart_yticks(N:integer);


/**
 * @~english
 * Return label of a tick located on the Y-axis.
 *
 * This functions returns the label of tick @p N located on the Y-axis.\n
 * To set a such label, you can use @ref chart_yticks_labels(L:list).
 *
 * @~french
 *
 * Renvoie le nom d'un intervalle particulier de l'axe Y.
 *
 * Renvoie le nom de l'intervalle @p N situé sur l'axe Y.\n
 * Pour changer cette valeur, il est possible d'utiliser la fonction @ref chart_yticks_labels(L:list).
 *
 * @param N Numéro de l'intervalle.
 *
 **/
chart_yticks_label(N:integer);


/**
* @~english
* Set ticks labels of Y-axis.
*
* This functions use list @p L as ticks labels of Y-axis.\n
* You can get a specific label with @ref chart_yticks_label(N:integer).
*
* @param L List of ticks labels
*
* @~french
*
* Définit les noms des intervalles de l'axe Y.
*
* Change les noms des intervalles de l'axe Y par la liste L.\n
* Il est possible de récupérer un de ces noms grâce à la fonction @ref chart_yticks_label(N:integer).
*
* @param L Liste contenant le nom des intervalles.
*
* @~
@code
// Set "First", "Second", "Third" as ticks labels
chart_yticks_label { "First", "Second", "Third" }
@endcode
**/
chart_yticks_labels(L:list);


/**
 * @~english
 * \defgroup Areacharts Area charts
 * This page show all area styles with some examples and screenshots
 * using the default theme.
 * First, for all these charts, we need to initialize our datasets:
@code
import Charts

material_ambient 1.0, 1.0, 1.0, 1.0
material_diffuse 1.0, 1.0, 1.0, 1.0

// Init datasets with a loop
chart_reset
for i in 1..6 loop
    chart_push_data 1, 200
    chart_push_data 1, 250
    chart_push_data 1, 350
    chart_push_data 2, 165
    chart_push_data 2, 85
    chart_push_data 2, 188
@endcode
 *
 *
 * \section area1 Regular
 *
 * \subsection two 2D
 *
@code
chart_style ""
chart_format "2D"
chart "area", 0, 0, 1.0, 1.0
@endcode
 *
 * @image html "area_regular_2d.png" "Example of 2D regular area chart"
 *
 *
 * \subsection third 3D
@code
rotatey -15
light 0
chart_style ""
chart_format "3D"
chart "area", 0, 0, 1.0, 1.0
@endcode
 *
 * @image html "area_regular_3d.png" "Example of 3D regular area chart"
 *
 *
 * \section area2 Stacked
 *
 * \subsection two 2D
 *
@code
chart_style "stacked"
chart_format "2D"
chart "area", 0, 0, 1.0, 1.0
@endcode
 *
 * @image html "area_stacked_2d.png" "Example of 2D stacked area chart"
 *
 *
 * \subsection third 3D
@code
rotatey -15
light 0
chart_style "stacked"
chart_format "3D"
chart "area", 0, 0, 1.0, 1.0
@endcode
 *
 * @image html "area_stacked_3d.png" "Example of 3D stacked area chart"
 *
 *
 * @~french
 * \defgroup Areacharts Diagrammes de zones
 * Cette page montre les différents types de diagrammes de zones grâce à des exemples
 * et des captures d'écrans.
 * Le thème par défaut est utilisé pour tous les cas présentés ci-dessous.\n
 * Avant tout, il est nécessaire d'initialiser nos séries de données en y ajoutant quelques valeurs:
@code
import Charts

material_ambient 1.0, 1.0, 1.0, 1.0
material_diffuse 1.0, 1.0, 1.0, 1.0

// Initialisation de deux séries de données
// à l'aide d'une boucle
chart_reset
for i in 1..6 loop
    chart_push_data 1, 200
    chart_push_data 1, 250
    chart_push_data 1, 350
    chart_push_data 2, 165
    chart_push_data 2, 85
    chart_push_data 2, 188
@endcode
 *
 *
 * \section area1 Classique
 *
 * \subsection two 2D
 *
@code
chart_style ""
chart_format "2D"
chart "area", 0, 0, 1.0, 1.0
@endcode
 *
 * @image html "area_regular_2d.png" "Exemple de diagramme de zones 2D classique"
 *
 *
 * \subsection third 3D
@code
rotatey -15
light 0
chart_style ""
chart_format "3D"
chart "area", 0, 0, 1.0, 1.0
@endcode
 *
 * @image html "area_regular_3d.png" "Exemple de diagramme de zones 3D classique"
 *
 *
 * \section area2 Empilé
 *
 * \subsection two 2D
 *
@code
chart_style "stacked"
chart_format "2D"
chart "area", 0, 0, 1.0, 1.0
@endcode
 *
 * @image html "area_stacked_2d.png" "Exemple de diagramme de zones empilées en 2D "
 *
 *
 * \subsection third 3D
@code
rotatey -15
light 0
chart_style "stacked"
chart_format "3D"
chart "area", 0, 0, 1.0, 1.0
@endcode
 *
 * @image html "area_stacked_3d.png" "Exemple de diagramme de zones empilées 3D"
 *
 */



/**
 * @~english
 * \defgroup Barcharts Bar charts
 * This page show all bar styles with some examples and screenshots
 * using the default theme.
 * First, for all these charts, we need to initialize our datasets:
@code
import Charts

material_ambient 1.0, 1.0, 1.0, 1.0
material_diffuse 1.0, 1.0, 1.0, 1.0

// Init datasets with a loop
chart_reset
for i in 1..6 loop
    chart_push_data 1, 200
    chart_push_data 1, 250
    chart_push_data 1, 350
    chart_push_data 2, 165
    chart_push_data 2, 85
    chart_push_data 2, 188
@endcode
 *
 *
 * \section bar1 Vertical
 *
 * \subsection two 2D
 *
@code
chart_style ""
chart_format "2D"
chart "bar", 0, 0, 1.0, 1.0
@endcode
 *
 * @image html "bar_vertical_2d.png" "Example of 2D vertical bar chart"
 *
 *
 * \subsection third 3D
@code
rotatey -15
light 0
chart_style ""
chart_format "3D"
chart "bar", 0, 0, 1.0, 1.0
@endcode
 *
 * @image html "bar_vertical_3d.png" "Example of 3D vertical bar chart"
 *
 *
 * \section bar2 Vertical Stacked
 *
 * \subsection two 2D
 *
@code
chart_style "vertical_stacked"
chart_format "2D"
chart "bar", 0, 0, 1.0, 1.0
@endcode
 *
 * @image html "bar_vertical_stacked_2d.png" "Example of 2D vertical stacked bar chart"
 *
 *
 * \subsection third 3D
@code
rotatey -15
light 0
chart_style "vertical_stacked"
chart_format "3D"
chart "bar", 0, 0, 1.0, 1.0
@endcode
 *
 *  @image html "bar_vertical_stacked_3d.png" "Example of 3D vertical stacked bar chart"
 *
 * \section bar3 Horizontal
 *
 * \subsection two 2D
 *
@code
chart_style "horizontal"
chart_format "2D"
chart "bar", 0, 0, 1.0, 1.0
@endcode
 *
 * @image html "bar_horizontal_2d.png" "Example of 2D horizontal bar chart"
 *
 *
 * \subsection third 3D
@code
rotatey -15
light 0
chart_style "horizontal"
chart_format "3D"
chart "bar", 0, 0, 1.0, 1.0
@endcode
 *
 * @image html "bar_horizontal_3d.png" "Example of 3D horizontal bar chart"
 *
 *
 * \section bar4 Horizontal Stacked
 *
 * \subsection two 2D
 *
@code
chart_style "horizontal_stacked"
chart_format "2D"
chart "bar", 0, 0, 1.0, 1.0
@endcode
 *
 * @image html "bar_horizontal_stacked_2d.png" "Example of 2D horizontal stacked bar chart"
 *
 *
 * \subsection third 3D
@code
rotatey -15
light 0
chart_style "horizontal_stacked"
chart_format "3D"
chart "bar", 0, 0, 1.0, 1.0
@endcode
 *
 * @image html "bar_horizontal_stacked_3d.png" "Example of 3D horizontal stacked bar chart"
 *
 *
 * @~french
 * \defgroup Barcharts Diagrammes à barres
 * Cette page montre les différents types de diagrammes à barres grâce à des exemples
 * et des captures d'écrans.
 * Le thème par défaut est utilisé pour tous les cas présentés ci-dessous.\n
 * Avant tout, il est nécessaire d'initialiser nos séries de données en y ajoutant quelques valeurs:
@code
import Charts

material_ambient 1.0, 1.0, 1.0, 1.0
material_diffuse 1.0, 1.0, 1.0, 1.0

// Initialisation de deux séries de données
// à l'aide d'une boucle
chart_reset
for i in 1..6 loop
    chart_push_data 1, 200
    chart_push_data 1, 250
    chart_push_data 1, 350
    chart_push_data 2, 165
    chart_push_data 2, 85
    chart_push_data 2, 188
@endcode
 *
 *
 * \section bar1 Vertical
 *
 * \subsection two 2D
 *
@code
chart_style ""
chart_format "2D"
chart "bar", 0, 0, 1.0, 1.0
@endcode
 *
 * @image html "bar_vertical_2d.png" "Exemple de diagrammes à barres verticales en 2D"
 *
 *
 * \subsection third 3D
@code
rotatey -15
light 0
chart_style ""
chart_format "3D"
chart "bar", 0, 0, 1.0, 1.0
@endcode
 *
 * @image html "bar_vertical_3d.png" "Exemple de diagrammes à barres verticales en 3D"
 *
 *
 * \section bar2 Vertical Empilé
 *
 * \subsection two 2D
 *
@code
chart_style "vertical_stacked"
chart_format "2D"
chart "bar", 0, 0, 1.0, 1.0
@endcode
 *
 * @image html "bar_vertical_stacked_2d.png" "Exemple de diagrammes à barres verticales empilées en 2D"
 *
 *
 * \subsection third 3D
@code
rotatey -15
light 0
chart_style "vertical_stacked"
chart_format "3D"
chart "bar", 0, 0, 1.0, 1.0
@endcode
 *
 *  @image html "bar_vertical_stacked_3d.png" "Exemple de diagrammes à barres verticales empilées en 3D"
 *
 * \section bar3 Horizontal
 *
 * \subsection two 2D
 *
@code
chart_style "horizontal"
chart_format "2D"
chart "bar", 0, 0, 1.0, 1.0
@endcode
 *
 * @image html "bar_horizontal_2d.png" "Exemple de diagrammes à barres horizontales en 2D"
 *
 *
 * \subsection third 3D
@code
rotatey -15
light 0
chart_style "horizontal"
chart_format "3D"
chart "bar", 0, 0, 1.0, 1.0
@endcode
 *
 * @image html "bar_horizontal_3d.png" "Exemple de diagrammes à barres horizontales en 3D"
 *
 *
 * \section bar4 Horizontal Empilé
 *
 * \subsection two 2D
 *
@code
chart_style "horizontal_stacked"
chart_format "2D"
chart "bar", 0, 0, 1.0, 1.0
@endcode
 *
 * @image html "bar_horizontal_stacked_2d.png" "Exemple de diagrammes à barres horizontales empilées en 2D"
 *
 *
 * \subsection third 3D
@code
rotatey -15
light 0
chart_style "horizontal_stacked"
chart_format "3D"
chart "bar", 0, 0, 1.0, 1.0
@endcode
 *
 * @image html "bar_horizontal_stacked_3d.png" "Exemple de diagrammes à barres horizontales empilées en 3D"
 */



/**
 * @~english
 * \defgroup Linecharts Line charts
 * This page show all line styles with some examples and screenshots
 * using the default theme.
 * First, for all these charts, we need to initialize our datasets:
@code
import Charts

material_ambient 1.0, 1.0, 1.0, 1.0
material_diffuse 1.0, 1.0, 1.0, 1.0

// Init datasets with a loop
chart_reset
for i in 1..6 loop
    chart_push_data 1, 200
    chart_push_data 1, 250
    chart_push_data 1, 350
    chart_push_data 2, 165
    chart_push_data 2, 85
    chart_push_data 2, 188
@endcode
 *
 *
 * \section line1 Line & Point
 *
 * \subsection two 2D
 *
@code
chart_style ""
chart_format "2D"
chart "line", 0, 0, 1.0, 1.0
@endcode
 *
 * @image html "line_and_point_2d.png" "Example of 2D line and point chart"
 *
 *
 * \subsection third 3D
@code
rotatey -15
light 0
chart_style ""
chart_format "3D"
chart "area", 0, 0, 1.0, 1.0
@endcode
 *
 * @image html "line_and_point_3d.png" "Example of 3D line and point chart"
 *
 *
 * \section line2 Line
 *
 * \subsection two 2D
 *
@code
chart_style "line"
chart_format "2D"
chart "line", 0, 0, 1.0, 1.0
@endcode
 *
 * @image html "line_2d.png" "Example of 2D line chart"
 *
 *
 * \subsection third 3D
@code
rotatey -15
light 0
chart_style "line"
chart_format "3D"
chart "line", 0, 0, 1.0, 1.0
@endcode
 *
 * @image html "line_3d.png" "Example of 3D line chart"
 *
 *
 * \section line3 Point
 *
 * \subsection two 2D
 *
@code
chart_style "point"
chart_format "2D"
chart "line", 0, 0, 1.0, 1.0
@endcode
 *
 * @image html "point.png" "Example of 2D point chart"
 *
 *
 * \subsection third 3D
 *
 @code
rotatey -15
light 0
chart_style "point"
chart_format "3D"
chart "line", 0, 0, 1.0, 1.0
@endcode
 *
 * This style has the same rendering in 2D and in 3D.
 *
 * @~french
 * \defgroup Linecharts Diagrammes linéaires
 * Cette page montre les différents types de diagrammes linéaires grâce à des exemples
 * et des captures d'écrans.
 * Le thème par défaut est utilisé pour tous les cas présentés ci-dessous.\n
 * Avant tout, il est nécessaire d'initialiser nos séries de données en y ajoutant quelques valeurs:
@code
import Charts

material_ambient 1.0, 1.0, 1.0, 1.0
material_diffuse 1.0, 1.0, 1.0, 1.0

// Initialisation de deux séries de données
// à l'aide d'une boucle
chart_reset
for i in 1..6 loop
    chart_push_data 1, 200
    chart_push_data 1, 250
    chart_push_data 1, 350
    chart_push_data 2, 165
    chart_push_data 2, 85
    chart_push_data 2, 188
@endcode
 *
 *
 * \section line1 Lignes & Points
 *
 * \subsection two 2D
 *
@code
chart_style ""
chart_format "2D"
chart "line", 0, 0, 1.0, 1.0
@endcode
 *
 * @image html "line_and_point_2d.png" "Exemple de diagramme linéaire 2D avec lignes et points"
 *
 *
 * \subsection third 3D
@code
rotatey -15
light 0
chart_style ""
chart_format "3D"
chart "area", 0, 0, 1.0, 1.0
@endcode
 *
 * @image html "line_and_point_3d.png" "Exemple de diagramme linéaire 3D avec lignes et points"
 *
 *
 * \section line2 Lignes
 *
 * \subsection two 2D
 *
@code
chart_style "line"
chart_format "2D"
chart "line", 0, 0, 1.0, 1.0
@endcode
 *
 * @image html "line_2d.png" "Exemple de diagramme linéaire 2D avec lignes seulement"
 *
 *
 * \subsection third 3D
@code
rotatey -15
light 0
chart_style "line"
chart_format "3D"
chart "line", 0, 0, 1.0, 1.0
@endcode
 *
 * @image html "line_3d.png" "Exemple de diagramme linéaire 3D avec lignes seulement"
 *
 *
 * \section line3 Points
 *
 * \subsection two 2D
 *
@code
chart_style "point"
chart_format "2D"
chart "line", 0, 0, 1.0, 1.0
@endcode
 *
 * @image html "point.png" "Exemple de diagramme linéaire 2D avec points seulement"
 *
 *
 * \subsection third 3D
 *
 @code
rotatey -15
light 0
chart_style "point"
chart_format "3D"
chart "line", 0, 0, 1.0, 1.0
@endcode
 *
 * Ce style a le même résultat en 2D et en 3D dans le thème par défaut.
 *
 */



/**
 * @~english
 * \defgroup Piecharts Pie charts
 * This page show all pie styles with some examples and screenshots
 * using the default theme.
 * First, for all these charts, we need to initialize our datasets:
@code
import Charts

material_ambient 1.0, 1.0, 1.0, 1.0
material_diffuse 1.0, 1.0, 1.0, 1.0

// Init datasets with a loop
chart_reset
for i in 1..6 loop
    chart_push_data 1, 200
    chart_push_data 1, 250
    chart_push_data 1, 350
    chart_push_data 2, 165
    chart_push_data 2, 85
    chart_push_data 2, 188
@endcode
 *
 *
 * \section pie1 Regular
 *
 * \subsection two 2D
 *
@code
chart_style ""
chart_format "2D"
chart "pie", 0, 0, 1.0, 1.0
@endcode
 *
 * @image html "pie_regular_2d.png" "Example of 2D regular pie chart"
 *
 *
 * \subsection third 3D
@code
rotatey -15
light 0
chart_style ""
chart_format "3D"
chart "pie", 0, 0, 1.0, 1.0
@endcode
 *
 * @image html "pie_regular_3d.png" "Example of 3D regular pie chart"
 *
 *
 * \section pie2 Exploded
 *
 * \subsection two 2D
 *
@code
chart_style "exploded"
chart_format "2D"
chart "pie", 0, 0, 1.0, 1.0
@endcode
 *
 * @image html "pie_exploded_2d.png" "Example of 2D exploded pie chart"
 *
 *
 * \subsection third 3D
@code
rotatey -15
light 0
chart_style "exploded"
chart_format "3D"
chart "pie", 0, 0, 1.0, 1.0
@endcode
 *
 * @image html "pie_exploded_3d.png" "Example of 3D exploded pie chart"
 *
 * @~french
 * \defgroup Piecharts Diagrammes circulaires
 * Cette page montre les différents types de diagrammes circulaires grâce à des exemples
 * et des captures d'écrans.
 * Le thème par défaut est utilisé pour tous les cas présentés ci-dessous.\n
 * Avant tout, il est nécessaire d'initialiser nos séries de données en y ajoutant quelques valeurs:
@code
import Charts

material_ambient 1.0, 1.0, 1.0, 1.0
material_diffuse 1.0, 1.0, 1.0, 1.0

// Initialisation de deux séries de données
// à l'aide d'une boucle
chart_reset
for i in 1..6 loop
    chart_push_data 1, 200
    chart_push_data 1, 250
    chart_push_data 1, 350
    chart_push_data 2, 165
    chart_push_data 2, 85
    chart_push_data 2, 188
@endcode
 *
 *
 * \section pie1 Classique
 *
 * \subsection two 2D
 *
@code
chart_style ""
chart_format "2D"
chart "pie", 0, 0, 1.0, 1.0
@endcode
 *
 * @image html "pie_regular_2d.png" "Exemple de diagramme circulaire classique 2D"
 *
 *
 * \subsection third 3D
@code
rotatey -15
light 0
chart_style ""
chart_format "3D"
chart "pie", 0, 0, 1.0, 1.0
@endcode
 *
 * @image html "pie_regular_3d.png" "Exemple de diagramme circulaire classique 3D"
 *
 *
 * \section pie2 Eclaté
 *
 * \subsection two 2D
 *
@code
chart_style "exploded"
chart_format "2D"
chart "pie", 0, 0, 1.0, 1.0
@endcode
 *
 * @image html "pie_exploded_2d.png" "Exemple de diagramme circulaire éclaté 2D"
 *
 *
 * \subsection third 3D
@code
rotatey -15
light 0
chart_style "exploded"
chart_format "3D"
chart "pie", 0, 0, 1.0, 1.0
@endcode
 *
 * @image html "pie_exploded_3d.png" "Exemple de diagramme circulaire éclaté 3D"
 *
 */






/**
 * @}
 */
