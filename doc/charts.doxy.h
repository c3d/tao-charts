// *****************************************************************************
// charts.doxy.h                                                   Tao3D project
// *****************************************************************************
//
// File description:
//
//
//
//
//
//
//
//
// *****************************************************************************
// This software is licensed under the GNU General Public License v3
// (C) 2013, Baptiste Soulisse <baptiste.soulisse@taodyne.com>
// (C) 2013, Catherine Burvelle <catherine@taodyne.com>
// (C) 2013-2014, Christophe de Dinechin <christophe@taodyne.com>
// (C) 2013-2014, Jérôme Forissier <jerome@taodyne.com>
// *****************************************************************************
// This file is part of Tao3D
//
// Tao3D is free software: you can r redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Tao3D is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Tao3D, in a file named COPYING.
// If not, see <https://www.gnu.org/licenses/>.
// *****************************************************************************
/**
 * @~english
 * @taomoduledescription{Charts, Charts}
 * <tt>import Charts</tt> - 2D and 3D Charts.@n
 *
 * This module allows to add some 2D and 3D charts to your presentations, in particular:
 *    - @ref Areacharts
 *    - @ref Barcharts
 *    - @ref Linecharts
 *    - @ref Piecharts
 *
 * To use these differents charts, you may define up to four differents datasets, and
 * fill them with @ref chart_load_csv, @ref chart_load_tsv or @ref chart_push_data.
 * The style of these charts can change according to the slide theme used (see the
 * Slides module).
 *
 * @anchor RegExp <b>Regular expressions in resource names (<tt>re:</tt> syntax)</b>
 *
 * Several functions such as @ref chart_set_style can be apply to several charts simultaneously.
 * To specifiy several charts in a single @p name parameter, you use the <tt>re:</tt> prefix followed by a regular
 * expression. For instance, the following call would change style of all
 * charts having <tt>chart</tt> in their name:
@code
chart_set_style "re:chart"
@endcode
 * The functions that support the <tt>re:</tt> syntax are explicitely marked as
 * such in this documentation.
 *
 * @anchor Example <b>Example of some features</b>
 *
 * The code below (<a href="charts.ddd">charts.ddd</a>) presents some features
 * of this module.
 *
 * @include charts.ddd
 *
 * @endtaomoduledescription{Charts}
 *
 * @~french
 * @taomoduledescription{Charts, Diagrammes}
 * <tt>import Charts</tt> - Diagrammes 2D & 3D.@n
 *
 * Ce module permet d'ajouter facilement des diagrammes 2D et 3D dans vos présentations, parmis lesquels:
 *    - @ref Areacharts
 *    - @ref Barcharts
 *    - @ref Linecharts
 *    - @ref Piecharts
 *
 * Pour utiliser ces différents diagrammes, vous pouvez définir jusqu'à quatre différentes séries de
 * données, et les remplir grâce aux fonctions @ref chart_load_csv, @ref chart_load_tsv ou
 * @ref chart_push_data.
 * Le style de ces diagrammes peut changer suivant le choix du thème de diapositive (voir le module Slides).
 *
 * @anchor RegExp <b>Expressions régulières dans les noms (syntaxe <tt>re:</tt>)</b>
 *
 * Plusieurs fonctions, comme @ref chart_set_style par exemple, peuvent s'appliquer
 * à plusieurs diagrammes simultanément. Pour cela vous pouvez utiliser le
 * préfixe  <tt>re:</tt> suivi d'une expression régulière. Par exemple, l'appel
 * suivant change le style de tous les diagrammes dont le nom contient
 * <tt>diagramme</tt>.
@code
chart_set_style "re:diagramme"
@endcode
 * Les fonctions qui autorisent la syntaxe <tt>re:</tt> sont explicitement
 * signalées dans cette documentation.
 *
 * @anchor Exemple <b>Exemple de quelques fonctionnalités de ce module</b>
 * Le code ci-dessous (<a href="charts.ddd">charts.ddd</a>) présente quelques
 * fonctionnalités de ce module.
 *
 * @include charts.ddd
 *
 * @endtaomoduledescription{Charts}
 * @~
 * @{
 */


/**
 * @~english
 * A name that matches all currently loaded charts.
 * May be passed to any function that supports the @ref RegExp "re:" syntax.
 * @~french
 * Un nom qui désigne tous les diagrammes définis par le module. Peut être
 * utilisé dans n'importe quelle fonction qui accepte la syntaxe
 * @ref RegExp "re:".
 */
ALL_CHARTS = "re:";


/**
 * @~english
 * Draw current chart using all datasets.
 *
 * This function is a shortcut of @ref chart(X:real, Y:real, W:real, H:real)
 * with (X,Y) equal to (0,0) and (W,H) equal to (100%, 100%).
 *
 * @~french
 *
 * Affiche le diagramme courant à partir de toutes les séries de données.
 *
 * Cette fonction est un raccourci de @ref chart(X:real, Y:real, W:real, H:real)
 * avec (X, Y) égal à (0, 0) et (W, H) égal à (100%, 100%).
 *
 **/
chart();


/**
 * @~english
 * Draw current chart using a unique dataset.
 *
 * This function is a shortcut of @ref chart(X:real, Y:real, W:real, H:real, N:integer)
 * with (X,Y) equal to (0,0) and (W,H) equal to (100%, 100%).
 *
 * @~french
 *
 * Affiche le diagramme courant à partir d'une série de donnée unique.
 *
 * Cette fonction est un raccourci de @ref chart(X:real, Y:real, W:real, H:real, N:integer)
 * avec (X, Y) égal à (0, 0) et (W, H) égal à (100%, 100%).
 **/
chart(N:integer);



/**
 * @~english
 * Draw current chart using a range of datasets.
 *
 * This function is a shortcut of @ref chart(X:real, Y:real, W:real, H:real, First:integer, Last:integer)
 * with (X,Y) equal to (0,0) and (W,H) equal to (100%, 100%).
 *
 * This function is documented with this name due to limitations
 * in the documentation tool. The recommended notation to use this feature is
 * the following:
 *
 * @~french
 *
 * Affiche le diagramme courant à partir d'un intervalle de série de données.
 *
 * Cette fonction est un raccourci de @ref chart(X:real, Y:real, W:real, H:real, First:integer, Last:integer)
 * avec (X, Y) égal à (0, 0) et (W, H) égal à (100%, 100%).
 *
 * Cette fonction est documentée sous ce nom à cause de limitations de l'outil de génération de cette documentation.
 * La notation recommandée est la suivante :
 *
 * @~
@code
chart First..Last
@endcode
 *
 * @~english
 * For instance:
 *
 * @~french
 * Par exemple:
 *
 * @~
@code
chart 1..3
@endcode
 **/
chart(First:integer, Last:integer);


/**
 * @~english
 * Draw current chart using a list of datasets.
 *
 * This function is a shortcut of @ref chart(X:real, Y:real, W:real, H:real, L:list)
 * with (X,Y) equal to (0,0) and (W,H) equal to (100%, 100%).
 *
 * For instance:
 *
 * @~french
 *
 * Affiche un diagramme à partir d'une liste de série de données.
 *
 * Cette fonction est un raccourci de @ref chart(X:real, Y:real, W:real, H:real, L:list)
 * avec (X, Y) égal à (0, 0) et (W, H) égal à (100%, 100%).
 *
 * Par exemple:
 *
 * @~
@code
chart 2, 1, 3, etc.
@endcode
 **/
chart(L:list);


/**
 * @~english
 * Draw current chart using all datasets.
 *
 * This function draws current chart (@ref chart_current) with all datasets.\n
 * You may change the chart type, the chart style and/or format format with @ref chart_set_type,
 * @ref chart_set_type and @ref chart_set_format.\n
 * (@p W, @p H) represent the size of chart in percents, relative to the size
 * of the slide drawing zone (@ref picture) which may depend on the chosen
 * theme.\n
 * For instance, with the default theme, this size is equals to (1800, 750).
 *
 * @warning For pie chart, this function draws only the first dataset.
 *
 * @param X X-coordinate.
 * @param Y Y-coordinate.
 * @param W Chart width in percent.
 * @param H Chart height in percent.
 *
 * @~french
 *
 * Affiche le diagramme courant à partir de toutes les séries de données.
 *
 * Cette fonction affiche le diagramme courant (@ref chart_current)
 * à partir des différentes séries de données remplies.\n
 * Vous pouvez changer le type, style et le format du diagramme avec @ref chart_set_type,
 * @ref chart_set_style et @ref chart_set_format.\n
 * (@p W, @p H) représente la taille du diagramme en pourcentage.\n
 * La taille absolue du diagramme correspond à la taille de la zone de dessin d'une slide (@ref picture)
 * et dépend donc du thème choisi.\n
 * Par exemple, pour le thème par défaut, la taille d'un diagramme est (1800, 750).\n
 *
 * @warning Dans le cas du diagramme circulaire, cette fonction n'utilise que la première série de données.
 *
 * @param X Abscisse.
 * @param Y Ordonnée.
 * @param W Largeur en pourcentage.
 * @param H Hauteur en pourcentage.
 **/
chart(X:real, Y:real, W:real, H:real);


/**
 * @~english
 * Draw current chart using an unique dataset.
 *
 * This function draws current chart (@ref chart_current) using dataset @p N.\n
 *
 * You may change the chart type, the chart style and/or format format with @ref chart_set_type,
 * @ref chart_set_type and @ref chart_set_format.\n
 * (@p W, @p H) represent the size of chart in percents, relative to the size
 * of the slide drawing zone (@ref picture) which may depend on the chosen
 * theme.\n
 * For instance, with the default theme, this size is equals to (1800, 750).
 *
 * @param X X-coordinate.
 * @param Y Y-coordinate.
 * @param W Chart width in percent.
 * @param H Chart height in percent.
 * @param N Index of the dataset (from 1 to 4).
 *
 * @~french
 *
 * Affiche le diagramme courant à partir d'une série de données unique.
 *
 * Cette fonction affiche le diagramme courant (@ref chart_current)
 * à partir de la série de données @p N.\n
 * Il existe quatre types de diagrammes
 * Vous pouvez changer le type, style et le format du diagramme avec @ref chart_set_type,
 * @ref chart_set_style et @ref chart_set_format.\n
 * (@p W, @p H) représente la taille du diagramme en pourcentage.\n
 * La taille absolue du diagramme correspond à la taille de la zone de dessin d'une slide (@ref picture)
 * et dépend donc du thème choisi.\n
 * Par exemple, pour le thème par défaut, la taille du diagramme est (1800, 750).\n
 *
 * @param X Abscisse.
 * @param Y Ordonnée.
 * @param W Largeur en pourcentage.
 * @param H Hauteur en pourcentage.
 * @param N Numéro de la série de données (de 1 à 4).
 *
 **/
chart(X:real, Y:real, W:real, H:real, N:integer);


/**
 * @~english
 * Draw a chart using a range of datasets.
 *
 * This function draws current chart (@ref chart_current) using
 * datasets from @p First to @p Last.\n
 * You may change the chart type, the chart style and/or format format
 * with @ref chart_set_type, @ref chart_set_type and @ref chart_set_format.\n
 * (@p W, @p H) represent the size of chart in percents, relative to the size
 * of the slide drawing zone (@ref picture) which may depend on the chosen
 * theme.\n
 * For instance, with the default theme, this size is equals to (1800, 750).
 *
 * This function is documented with this name due to limitations
 * in the documentation tool. The recommended notation to use this feature is
 * the following:
@code
 chart First..Last
@endcode
 *
 * For instance:
@code
// Show only datasets 2 to 4
chart 0, 0, 100%, 100%, 2..4
@endcode
 *
 * @warning For pie chart, this function draws only dataset @p First.
 *
 * @param X X-coordinate.
 * @param Y Y-coordinate.
 * @param W Chart width in percent.
 * @param H Chart height in percent.
 * @param First First dataset of chart.
 * @param Last Last dataset of chart.
 *
 * @~french
 *
 * Affiche le diagramme courant à partir d'un intervalle de série de données.
 *
 * Cette fonction affiche le diagramme courant (@ref chart_current)
 * à partir des données de la série @p First jusqu'à la série @p Last.
 *
 * Vous pouvez changer le type, style et le format du diagramme avec @ref chart_set_type,
 * @ref chart_set_style et @ref chart_set_format.\n
 * (@p W, @p H) représente la taille du diagramme en pourcentage.\n
 * La taille absolue du diagramme correspond à la taille de la zone de dessin d'une slide (@ref picture)
 * et dépend donc du thème choisi.\n
 * Par exemple, pour le thème par défaut, la taille d'un diagramme est (1800, 750).\n
 *
 * Cette fonction est documentée sous ce nom à cause de
 * limitations de l'outil de génération de cette documentation. La notation
 * recommandée est la suivante :
@code
 chart First..Last
@endcode
 *
 * Par exemple:
@code
// Affiche seulement les séries 2 à 4
chart 0, 0, 100%, 100%, 2..4
@endcode
 *
 * @warning Dans le cas du diagramme circulaire, cette fonction n'utilise que la série de données @p First.
 *
 * @param X Abscisse.
 * @param Y Ordonnée.
 * @param W Largeur en pourcentage.
 * @param H Hauteur en pourcentage.
 * @param First Première série du diagramme.
 * @param Last Dernière série du diagramme.
 *
 * @~
 **/
chart(X:real, Y:real, W:real, H:real, First:integer, Last:integer);


/**
 * @~english
 * Draw current chart using a list of datasets.
 *
 * This function draws current chart (@ref chart_current) using datasets given in
 * the list @p L.\n
 * You may change the chart type, the chart style and/or format format with @ref chart_set_type,
 * @ref chart_set_type and @ref chart_set_format.\n
 * (@p W, @p H) represent the size of chart in percents, relative to the size
 * of the slide drawing zone (@ref picture) which may depend on the chosen
 * theme.\n
 * For instance, with the default theme, this size is equals to (1800, 750).
 *
 * For instance:
@code
// Show only datasets 1, 3 and 4
chart 0, 0, 100%, 100%, 1, 3, 4
@endcode
 *
 * @warning For pie chart, this function draws only the first dataset in the list.
 *
 * @param X X-coordinate.
 * @param Y Y-coordinate.
 * @param W Chart width in percent.
 * @param H Chart height in percent.
 * @param L List of datasets.
 *
 * @~french
 *
 * Affiche le diagramme courant à partir d'une liste de séries de données.
 *
 * Cette fonction affiche le diagramme courant (@ref chart_current)
 * à partir des données des séries présentes dans la liste L.\n
 * Vous pouvez changer le type, style et le format du diagramme avec @ref chart_set_type,
 * @ref chart_set_style et @ref chart_set_format.\n
 * (@p W, @p H) représente la taille du diagramme en pourcentage.\n
 * La taille absolue du diagramme correspond à la taille de la zone de dessin d'une slide (@ref picture)
 * et dépend donc du thème choisi.\n
 * Par exemple, pour le thème par défaut, la taille d'un diagramme est (1800, 750).\n
 *
 * Exemple:
@code
// Affiche seulement les séries  1, 3 et 4
chart 0, 0, 100%, 100%, 1, 3, 4
@endcode
 *
 * @warning Dans le cas du diagramme circulaire, cette fonction n'utilise que la première série de données de la liste.
 *
 * @param X Abscisse.
 * @param Y Ordonnée.
 * @param W Largeur en pourcentage.
 * @param H Hauteur en pourcentage.
 * @param L Liste de séries de données.
 *
 * @~
 **/
chart(X:real, Y:real, W:real, H:real, L:list);


/**
 * @~english
 * Return the data count of a specific dataset.
 *
 * This function returns the size of dataset @p N
 * for current chart (@ref chart_current).
 *
 * @param S Index of the dataset (from 1 to 4).
 *
 * @~french
 *
 * Renvoie le nombre de données dans une série.
 *
 * Cette fonction renvoie le nombre de données que contient la série @p N
 * du diagramme courant (@ref chart_current).
 *
 * @param S Numéro de la série de données (de 1 à 4).
 *
 **/
chart_count(S:integer);


/**
 * @~english
 * Set a chart as current.
 *
 * This function sets the current chart (@ref chart_current) as current.\n
 * This function allows to change easily multiple settings of a same chart.
 * In this way, you can use this function to define multiple charts.
 * Example:
@code
chart_current "chart1"
chart_set_style "stacked"
chart_set_format "3D"
chart_push_data 1, 500
chart_push_data 2, 300
chart_current "chart2"
chart_set_format "2D"
@endcode
 *
 * @param Name Chart name.
 *
 * @~french
 * Utilise un diagramme comme pointeur courant.
 *
 * Cette fonction permet d'utiliser le diagramme courant (@ref chart_current) comme pointeur courant.\n
 * Cela permet ainsi de modifier facilement plusieurs champs d'un même diagramme.
 * De cette manière, il est possible de définir plusieurs diagrammes.
 * Exemple:
@code
chart_current "chart1"
chart_set_style "stacked"
chart_set_format "3D"
chart_push_data 1, 500
chart_push_data 2, 300
chart_current "chart2"
chart_set_format "2D"
@endcode
 *
 * @param Name Nom du diagramme.
 *
 */
chart_current(Name:text);


/**
 * @~english
 * Get a specific data of a dataset.
 *
 * Get a specific data situed at the position @p I into dataset @p N
 * of current chart (@ref chart_current).\n
 * The first data is situated at position I=0.\n
 * Example:
@code
// Add 50 to dataset 1
chart_push_data 1, 50
text text (chart_data(1, 0))
@endcode
 *
 * @param N Index of dataset (from 1 to 4).
 * @param I Position of data into dataset.
 *
 * @~french
 * Renvoie une valeur contenue dans une série de données.
 *
 * Renvoie la valeur située à la position @p I dans la série de données @p N.\n
 * La première valeur est située à la position I=0.\n
 * Exemple:
@code
// Ajoute 50 à la série 1 du diagramme
chart_push_data 1, 50
text text (chart_data(1, 0))
@endcode
 *
 * @param N Numéro de la série de données (de 1 à 4).
 * @param I Position de la donnée dans la série.
 *
 */
chart_data(N:integer, I:integer);


/**
 * @~english
 * Return value of a property for a specific data.
 *
 * This function return the value of property @p P for a specific data
 * situed at the position @p I into dataset @p N.\n
 * This value is setted with @ref chart_data_set_property.\n
 * The first value is situated at the position I=0.
 *
 * @param N Index of dataset (from 1 to 4).
 * @param I Position of data into dataset.
 * @param P Property to get.
 *
 * @~french
 * Renvoie la valeur d'un attribut d'une donnée particulière.
 *
 * Cette fonction renvoie la valeur de l'attribut @p P pour une valeur située à la position @p I
 * dans la série de données @p N du diagramme courant (@ref chart_current).\n
 * Cette valeur est modifiée par la fonction @ref chart_data_set_property.\n
 * La première valeur est située à la position I=0.
 *
 * @param N Numéro de la série de données (de 1 à 4).
 * @param I Position de la donnée dans la série.
 * @param P Attribut à récupérer.
 *
 */
chart_data_property(N:integer, I:integer, P:text);


/**
 * @~english
 * Get ratio a specific data of a dataset.
 *
 * Get ratio of a specific data situed at the position @p I into dataset @p N
 * of current chart (@ref chart_current).\n
 * The first ratio is situated at the position I=0.
 *
 * @param N Index of dataset (from 1 to 4).
 * @param I Position of data into dataset.
 *
 * @~french
 * Renvoie le ratio d'une valeur contenue dans une série de données.
 *
 * Renvoie le ratio d'une valeur située à la position @p I dans la
 * série de données @p N du diagramme courant (@ref chart_current).\n
 * La première valeur est située à la position I=0.
 *
 * @param N Numéro de la série de données (de 1 à 4).
 * @param I Position de la donnée dans la série.
 *
 */
chart_data_ratio(N:integer, I:integer);


/**
 * @~english
 * Set a property on a specific data of a dataset.
 *
 * This function change a property on a specific data
 * situed at the position @p I into dataset @p N of current chart (@ref chart_current).\n
 * These properties allow to manage in more depth, the behavior of charts.\n
 * The first value is situated at the position I=0.\n
 * For instance, To explode the first slice of a pie chart from 100 pixels, you can use
 * the predefined property "exploded_slice".\n
@code
chart_data_set_property "mychart", 1, 0, "exploded_slice", 100
@endcode
 *
 * @param N Index of dataset (from 1 to 4).
 * @param I Position of data into dataset.
 * @param P Property to change.
 * @param V New value of property.
 *
 *
 * @~french
 * Modifie la valeur d'un attribut d'une donnée particulière.
 *
 * Cette fonction modifie l'attribut @p P d'une valeur située à la position @p I
 * dans la série de données @p N du diagramme courant (@ref chart_current).\n
 * Ces attributs sont particulièrement utiles pour gérer de manière approndie le comportement
 * des différents diagrammes.\n
 * La première valeur est située à la position I=0.\n
 * Par exemple, pour éclater la premier tranche d'un diagramme circulaire de 100 pixels,
 * vous pouvez utiliser l'attribut prédéfinit "exploded_slice" de la façon suivante:
@code
chart_data_set_property "mychart", 1, 0, "exploded_slice", 100
@endcode
 *
 * @param N Numéro de la série de données (de 1 à 4).
 * @param I Position de la donnée dans la série.
 * @param P Attribut à modifier.
 * @param V Nouvelle valeur de l'attribut.
 *
 */
chart_data_set_property(N:integer, I:integer, P:text, V:real);


/**
 * @~english
 * Return the number of a dataset situated at a position.
 *
 * This function returns the dataset situated at position @p N in the list
 * to draw.
 *
 * @param N Dataset index.
 *
 * @~french
 *
 * Renvoie le numéro d'une série de donnée.
 *
 * Cette fonction renvoie le numéro de la série de données situé à la position
 * @p N dans la liste à dessiner.
 *
 * @param N Index de la série de donnée.
 *
 **/
chart_dataset(N:integer);


/**
 * @~english
 * Return the number of used datasets in a chart.
 *
 * This function returns the count of datasets used in the current chart (@ref chart_current).\n
 *
 * @~french
 *
 * Renvoie le nombre de séries de données utilisées dans un diagramme.
 *
 * Cette fonction renvoie le nombre de séries de données utilisées dans le diagramme
 * courant (@ref chart_current).\n
 *
 **/
chart_datasets_count();


/**
 * @~english
 * Drop completly one or multiple charts.
 *
 * This command drops all charts named @p Name.\n
 * Unlike @p chart_reset, this function deletes completly charts.
 * The @ref RegExp "re:" syntax is supported as chart name.\n
 *
 * @param Name Chart name.
 *
 * @~french
 * Garde un diagramme actif.
 *
 * Cette commande permet de supprimer complètement les diagrammes nommés @p Name.\n
 * A l'inverse de @p chart_reset, cette fonction permet de supprimer complètement un diagramme.
 * La syntaxe @ref RegExp "re:" est supportée comme nom de diagramme.
 *
 * @param Name Nom du diagramme
 *
 * @~
 */
chart_drop(Name:text);


/**
 * @~english
 * Return the index of the first dataset used in a chart.
 *
 * This function returns the index of the first dataset drawn in
 * the current chart (@ref chart_current).\n
 * This function is a shortcut to @ref chart_dataset(N:integer) with
 * N=0.
 *
 * @~french
 * Renvoie le numéro de la première série utilisée dans un diagramme.
 *
 * Cette fonction permet de renvoyer le numéro de la première série utilisée
 * dans le diagramme courant (@ref chart_current).\n
 * Cette fonction est un raccourci à la fonction @ref chart_dataset(N:integer)
 * avec N=0.
 *
 * @~
 */
chart_first();


/**
 * @~english
 * Return the format of current chart.
 *
 * This function returns the format of the current chart (@ref chart_current).\n
 * You can modify its value by using @ref chart_set_format.
 *
 * @~french
 * Renvoie le format du diagramme courant.
 *
 * Cette fonction permet de renvoyer le format du diagramme courant.\n
 * Il est possible de modifier le format grâce à la fonction @ref chart_set_format.
 *
 * @~
 */
chart_format();


/**
 * @~english
 * Return the index of the last dataset used in a chart.
 *
 * This function returns the index of the last dataset drawn in
 * the current chart (@ref chart_current).\n
 * It is a shortcut to @ref chart_dataset(N:integer) with N=(@ref chart_datasets_count() - 1).
 *
 * @~french
 * Renvoie le numéro de la dernière série utilisée dans un diagramme.
 *
 * Cette fonction permet de renvoyer le numéro de la dernière série utilisée
 * dans le diagramme courant (@ref chart_current).\n
 * Cette fonction est un raccourci à la fonction @ref chart_dataset(N:integer)
 * avec N=(@ref chart_datasets_count() - 1).
 *
 * @~
 */
chart_last();


/**
 * @~english
 * Return a legend of a charts.
 *
 * This function returns the legend @p N of current chart (@ref chart_current).
 * You can set a legend with @ref chart_set_legend.
 *
 * @param N Legend index.
 *
 * @~french
 * Renvoie une légende d'un diagramme.
 *
 * Cette fonction renvoie la légende @p N du diagramme courant (@ref chart_current).
 * Il est possible de modifier une légende avec @ref chart_set_legend.
 *
 * @param N Numéro de la légende.
 *
 */
chart_legend(N:integer);


/**
 * @~english
 * Load datasets directly from a csv file.
 *
 * Use datasets of a csv file @p T for chart named @p Name.\n
 * Load only the first four columns of the csv file.
 * The @ref RegExp "re:" syntax is supported as chart name.
 *
 * @param Name Chart name.
 * @param F filename of csv file.
 *
 * @note You can also use this function without giving the chart @p Name thanks to @ref chart_current.
@code
chart_current "mychart"
chart_load_csv "data.csv"
@endcode
 *
 * @~french
 * Charge des séries de données à partir d'un fichier csv.
 *
 * Charge des séries de données à partir du fichier csv @p F dans le diagramme
 * nommé @p Name.\n
 * Cette fonction ne charge que les quatres premiers colonnes du fichier csv.
 * La syntaxe @ref RegExp "re:" est supportée comme nom de diagramme.
 *
 * @param Name Nom du diagramme.
 * @param F Nom du fichier csv.
 *
 * @note Vous pouvez aussi utiliser cette fonction sans indiquer le paramètre @p Name grâce à @ref chart_current.
@code
chart_current "mychart"
chart_load_csv "data.csv"
@endcode
 */
chart_load_csv(Name:text, F:text);


/**
 * @~english
 * Load datasets directly from a tsv file.
 *
 * Use datasets of a tsv file @p T for chart named @p Name.\n
 * Load only the first four columns of the tsv file.
 * The @ref RegExp "re:" syntax is supported as chart name.
 *
 * @param Name Chart name.
 * @param F filename of tsv file.
 *
 * @note You can also use this function without giving the chart @p Name thanks to @ref chart_current.
@code
chart_current "mychart"
chart_load_tsv "data.tsv"
@endcode
 *
 * @~french
 * Charge des séries de données à partir d'un fichier tsv.
 *
 * Charge des séries de données à partir du fichier tsv @p F dans le diagramme
 * nommé @p Name.\n
 * Cette fonction ne charge que les quatres premiers colonnes du fichier tsv.
 * La syntaxe @ref RegExp "re:" est supportée comme nom de diagramme.
 *
 * @param Name Nom du diagramme.
 * @param F Nom du fichier tsv.
 *
 * @note Vous pouvez aussi utiliser cette fonction sans indiquer le paramètre @p Name grâce à @ref chart_current.
@code
chart_current "mychart"
chart_load_tsv "data.tsv"
@endcode
 */
chart_load_tsv(Name:text, F:text);


/**
 * @~english
 * Return the maximum data count between datasets of a chart.
 *
 * This function returns the maximum data count between datasets of current chart (@ref chart_current).\n
 * For instance, if dataset 1 has 4 data and and dataset 2 has 2 data, then
 * this function will return 4.
 *
 * @~french
 *
 * Renvoie le nombre maximum de éléments parmis les séries de données d'un diagramme.
 *
 * Cette fonction renvoie le nombre maximum de éléments parmis les séries de
 * données du diagramme courant (@ref chart_current).\n
 * Par exemple, si la série de données 1 contient 4 éléments et la série de données 2
 * seulement 2, alors cette fonction renverra la valeur 4.
 *
 **/
chart_max_count();


/**
 * @~english
 * Keep only one chart.
 *
 * This command drops all charts but the selected one.\n
 * It is similar to calling @ref chart_drop for all currently charts.
 * except the one named @p Name.\n
 * Unlike @p chart_reset, this function deletes completly charts.
 * The @ref RegExp "re:" syntax is supported as chart name.\n
 *
 * @param Name Chart name.
 *
 * @~french
 * Garde un diagramme actif.
 *
 * Cette commande permet de supprimer complètement les diagrammes courants, excepté
 * celui nommé @p Name.\n
 * Elle a un effet équivalent à appeler @ref chart_drop pour tous les
 * diagrammes actifs sauf @p Name.
 * La syntaxe @ref RegExp "re:" est supportée comme nom de diagramme.
 *
 * @param Name Nom du diagramme
 *
 * @~
 */
chart_only(Name:text);


/**
 * @~english
 * Push a data into a dataset of a chart.
 *
 * Push data @p D at the end of the dataset @p N of the chart
 * name @p Name.\n
 * The @ref RegExp "re:" syntax is supported as chart name.\n
 * Example:
@code
chart_push_data "mychart", 1, 25 // Add 25 to first dataset
chart_push_data "mychart", 1, 40 // Add 40 to first dataset
chart_push_data "mychart", 2, 40 // Add 40 to second dataset
@endcode
 *
 * @param Name Chart name.
 * @param N Index of the dataset (from 1 to 4).
 * @param D Data to push.
 *
 * @note You can also use this function without giving the chart @p Name thanks to @ref chart_current.
@code
chart_current "mychart"
chart_push_data 1, 25
chart_push_data 1, 40
chart_push_data 2, 40
@endcode
 *
 * @~french
 * Ajoute une valeur à une série de donnée d'un diagramme.
 *
 * Ajoute la valeur @p D à la série de donnée @p N du diagramme
 * nommé @p Name.\n
 * La syntaxe @ref RegExp "re:" est supportée comme nom de diagramme.\n
 * Exemple:
@code
chart_push_data "mychart", 1, 25 // Ajoute 25 à la série 1
chart_push_data "mychart", 1, 40 // Ajoute 40 à la série 1
chart_push_data "mychart", 2, 40 // Ajoute 40 à la série 2
@endcode
 *
 * @param Name Nom du diagramme.
 * @param N Numéro de la série de donnée (de 1 à 4).
 * @param D Donnée à ajouter.
 *
 * @note Vous pouvez aussi utiliser cette fonction sans indiquer le paramètre @p Name grâce à @ref chart_current.
@code
chart_current "mychart"
chart_push_data 1, 25
chart_push_data 1, 40
chart_push_data 2, 40
@endcode
 *
 */
chart_push_data(Name:text, N:integer, D:real);


/**
 * @~english
 * Reset one or multiple charts.
 *
 * This function reset charts named @p Name.\n
 * The @ref RegExp "re:" syntax is supported as chart name.\n
 * Example:
@code
// Reset all charts
chart_reset ALL_CHARTS
@endcode
 *
 * @param Name Chart name.
 *
 * @note You can also use this function without giving the chart @p Name thanks to @ref chart_current.
@code
chart_current "mychart"
chart_reset
@endcode
 *
 * @~french
 *
 * Réinitialise un ou plusieurs diagrammes.
 *
 * Cette fonction remet à zéro les diagrammes nommés @p Name.\n
 * La syntaxe @ref RegExp "re:" est supportée comme nom de diagramme.\n
 * Exemple:
@code
// Réinitialise tous les diagrammes
chart_reset ALL_CHARTS
@endcode
 *
 * @param Name Nom du diagramme.
 *
 * @note Vous pouvez aussi utiliser cette fonction sans indiquer le paramètre @p Name grâce à @ref chart_current.
@code
chart_current "mychart"
chart_reset
@endcode
 * @~

 **/
chart_reset(Name:text);


/**
 * @~english
 * Change the format of one or multiple charts.
 *
 * This function allows to change the format of charts named @p Name.\n
 * The @ref RegExp "re:" syntax is supported as chart name.\n
 * There are two possible formats:
 *    - "2D" to display 2D charts
 *    - "3D" to display 3D charts
 *
@code
chart_set_format "mychart", "3D"
@endcode
 *
 * @param Name   Chart name.
 * @param Format Chart format. Default is "2D".
 *
 * @note You can also use this function without giving the chart @p Name thanks to @ref chart_current.
@code
chart_current "mychart"
chart_set_format "3D" // Change format of chart named "mychart"
@endcode
 *
 * @~french
 * Change le format d'un ou plusieurs diagrammes.
 *
 * Cette fonction permet de change le format d'un ou plusieurs diagrammes.\n
 * La syntaxe @ref RegExp "re:" est supportée comme nom de diagramme.\n
 *
 * Il existe deux valeurs possibles:
 *    - "2D" pour afficher des diagrammes en 2D
 *    - "3D" pour afficher des diagrammes en 3D
 *
@code
// Change le format du diagramme nommé "mychart"
chart_set_format "mychart", "3D"
@endcode
 *
 * @param Name   Nom du diagramme.
 * @param Format Format du diagramme. La valeur par défaut est "2D".
 *
 * @note Vous pouvez aussi utiliser cette fonction sans indiquer le paramètre @p Name grâce à @ref chart_current.
@code
chart_current "mychart"
chart_set_format "3D"
@endcode
 *
 */
chart_set_format(Name:text, T:text);


/**
 * @~english
 * Change a legend of one or multiple charts.
 *
 * This function sets @p T as legend @p N of charts named @p Name.
 * The @ref RegExp "re:" syntax is supported as chart name.
 *
 * @param Name Chart name.
 * @param N Legend index.
 * @param T Legend to set.
 *
 * @note You can also use this function without giving the chart @p Name thanks to @ref chart_current.
@code
chart_current "mychart"
chart_legend 1, "mylegend"
@endcode
 *
 * @~french
 * Renvoie une légende d'un ou plusieurs diagrammes.
 *
 * Cette fonction applique @p T comme légende numéro @p N des diagrammes nommés @p Name.
 * La syntaxe @ref RegExp "re:" est supportée comme nom de diagramme.
 *
 * @param Name Nom du diagramme.
 * @param N Numéro de la légende.
 * @param T Légende à appliquer.
 *
 * @note Vous pouvez aussi utiliser cette fonction sans indiquer le paramètre @p Name grâce à @ref chart_current.
@code
chart_current "mychart"
chart_legend 1, "mylegend"
@endcode
 *
 */
chart_set_legend(Name:text, N:integer, T:text);


/**
 * @~english
 * Change the style of one or multiple charts.
 *
 * This function allows to change the style of one or multiple charts named @p Name.\n
 * The @ref RegExp "re:" syntax is supported as chart name.
 * Possible values are varying according to the chart type:
 *   - @ref Areacharts : "", "stacked"
 *   - @ref Barcharts : "", "vertical", "vertical_stacked", "horizontal", "horizontal_stacked"
 *   - @ref Linecharts : "", "point", "line", "line&point"
 *   - @ref Piecharts :  ""
 *
 * @param Name Chart name.
 * @param Style Chart style. Default is "".
 *
 * @note You can also use this function without giving the chart @p Name thanks to @ref chart_current.
@code
chart_current "mychart"
chart_set_style "stacked"
text chart_style
@endcode
 *
 * @~french
 * Change le style d'un ou plusieurs diagrammes.
 *
 * Cette fonction permet de changer le style d'un ou plusieurs diagramme.\n
 * La syntaxe @ref RegExp "re:" est supportée comme nom de diagramme.
 * Les valeurs possibles dépendent du type du diagramme :
 *   - @ref Areacharts : "", "stacked"
 *   - @ref Barcharts : "", "vertical", "vertical_stacked", "horizontal", "horizontal_stacked"
 *   - @ref Linecharts : "", "point", "line", "line&point"
 *   - @ref Piecharts :  ""
 *
 * @param Name Nom du diagramme.
 * @param Style Style du diagramme. La valeur par défaut est "".
 *
 * @note Vous pouvez aussi utiliser cette fonction sans indiquer le paramètre @p Name grâce à @ref chart_current.
@code
chart_current "mychart"
chart_set_style "stacked"
text chart_style
@endcode
 *
 * @~
 */
chart_set_style(Name:text, Style:text);


/**
 * @~english
 * Set title of a chart.
 *
 * This functions sets @p Title as title of chart @p Name.\n
 * The @ref RegExp "re:" syntax is supported as chart name.
 *
 * @param Name Chart name.
 * @param Title Chart title
 *
 * @note You can also use this function without giving the chart @p Name thanks to @ref chart_current.
@code
chart_current "mychart"
chart_set_title "mytitle"
text chart_title
@endcode
 *
 * @~french
 *
 * Modifie le titre d'un diagramme.
 *
 * Cette fonction applique @p Title comme titre du diagramme courant (@ref chart_current).\n
 * La syntaxe @ref RegExp "re:" est supportée comme nom de diagramme.
 *
 * @param Name Nom du diagramme.
 * @param Title Titre du diagramme
 *
 * @note Vous pouvez aussi utiliser cette fonction sans indiquer le paramètre @p Name grâce à @ref chart_current.
@code
chart_current "mychart"
chart_set_title "mytitle"
text chart_title
@endcode
 *
 **/
chart_set_title(Name:text, Title:text);


/**
 * @~english
 * Change the type of one or multiple charts.
 *
 * This function allows to change the type of one or multiple charts named @p Name.\n
 * The @ref RegExp "re:" syntax is supported as chart name.
 * There are four types of charts:
 *  - @ref Areacharts "@c area"
 *  - @ref Barcharts "@c bar"
 *  - @ref Linecharts "@c line"
 *  - @ref Piecharts "@c pie"
 *
 *
 * @param Name Chart name.
 * @param Type Chart type. Default is "bar".
 *
 * @note You can also use this function without giving the chart @p Name thanks to @ref chart_current.
@code
chart_current "mychart"
chart_set_type "bar"
text chart_type
@endcode
 *
 * @~french
 * Change le type d'un ou plusieurs diagrammes.
 *
 * Cette fonction permet de changer le type d'un ou plusieurs diagramme.\n
 * La syntaxe @ref RegExp "re:" est supportée comme nom de diagramme.
 * Il existe quatre types de diagrammes:
 *  - @c area : @ref Areacharts
 *  - @c bar : @ref Barcharts
 *  - @c line : @ref Linecharts
 *  - @c pie : @ref Piecharts
 *
 * @param Name Nom du diagramme.
 * @param Type Type du diagramme. La valeur par défaut est "bar".
 *
 * @note Vous pouvez aussi utiliser cette fonction sans indiquer le paramètre @p Name grâce à @ref chart_current.
@code
chart_current "mychart"
chart_set_type "bar"
text chart_type
@endcode
 *
 * @~
 */
chart_set_type(Name:text, Type:text);


/**
 * @~english
 * Set label of X-axis of one or multiple charts.
 *
 * This functions allows to change the X-axis label of one or multiple charts
 * named @p Name.\n
 * The @ref RegExp "re:" syntax is supported as chart name.
 *
 * @param Name Chart name.
 * @param Label X-axis label.
 *
 * @note You can also use this function without giving the chart @p Name thanks to @ref chart_current.
@code
chart_current "mychart"
chart_set_xlabel "x-axis"
text chart_xlabel
@endcode
 *
 * @~french
 *
 * Change le nom de l'axe X d'un ou plusieurs diagrammes.
 *
 * Cette fonction change le nom de l'axe X d'un ou plusieurs diagrammes nommés @p Name.\n
 * La syntaxe @ref RegExp "re:" est supportée comme nom de diagramme.
 *
 * @param Name Nom du diagramme.
 * @param Label Nom de l'axe X.
 *
 * @note Vous pouvez aussi utiliser cette fonction sans indiquer le paramètre @p Name grâce à @ref chart_current.
@code
chart_current "mychart"
chart_set_xlabel "x-axis"
text chart_xlabel
@endcode
 *
 **/
chart_set_xlabel(Name:text, Label:text);


/**
 * @~english
 * Set ticks number of X-axis of one or multiple charts.
 *
 * This functions allows to set @p N ticks on X-axis for one or multiple charts
 * named @p Name.\n
 * The @ref RegExp "re:" syntax is supported as chart name.
 *
 * @param Name Chart name.
 * @param Ticks Ticks number.
 *
 * @note You can also use this function without giving the chart @p Name thanks to @ref chart_current.
@code
chart_current "mychart"
chart_set_xticks 5
text chart_xticks
@endcode
 *
 * @~french
 *
 * Définit le nombre d'intervalles de l'axe X d'un ou plusieurs diagrammes.
 *
 * Cette fonction change le nombre d'intervalles de l'axe X
 * d'un ou plusieurs diagrammes nommés @p Name.\n
 * La syntaxe @ref RegExp "re:" est supportée comme nom de diagramme.
 *
 * @param Name Nom du diagramme.
 * @param Ticks Nombre d'intervalles.
 *
 * @note Vous pouvez aussi utiliser cette fonction sans indiquer le paramètre @p Name grâce à @ref chart_current.
@code
chart_current "mychart"
chart_set_xticks 5
text chart_xticks
@endcode
 *
 **/
chart_set_xticks(Name:text, N:integer);


/**
 * @~english
 * Set label of a tick located on the X-axis.
 *
 * This functions changes the label of tick @p N located on the X-axis for
 * one or multiple charts named @p Name.\n
 * The @ref RegExp "re:" syntax is supported as chart name.
 *
 * @param Name Chart name.
 * @param N Tick index.
 * @param L Tick Label.
 *
 * @note You can also use this function without giving the chart @p Name thanks to @ref chart_current.
@code
chart_current "mychart"
chart_set_xticks_label 1, "First tick"
text (chart_xticks_label 1)
@endcode
 *
 * @~french
 *
 * Modifie le nom d'un intervalle de l'axe X.
 *
 * Modifie le nom de l'intervalle @p N situé sur l'axe X d'un ou plusieurs diagrammes
 * nommés @p Name.\n
 * La syntaxe @ref RegExp "re:" est supportée comme nom de diagramme.
 *
 * @param Name Nom du diagramme.
 * @param N Numéro de l'intervalle.
 * @param L Nom de l'intervalle.
 *
 * @note Vous pouvez aussi utiliser cette fonction sans indiquer le paramètre @p Name grâce à @ref chart_current.
@code
chart_current "mychart"
chart_set_xticks_label 1, "Premier intervalle"
text (chart_xticks_label 1)
@endcode
 *
 **/
chart_set_xticks_label(Name:text, N:integer, L:text);


/**
 * @~english
 * Set labels of ticks located on the X-axis.
 *
 * This functions changes labels of ticks located on the X-axis for
 * one or multiple charts named @p Name.\n
 * The @ref RegExp "re:" syntax is supported as chart name.
 *
 * @note You can also use this function without giving the chart @p Name thanks to @ref chart_current.
@code
// Set "First", "Second", "Third" as ticks labels
chart_current "mychart"
chart_set_xticks_labels { "First", "Second", "Third" }
@endcode
 *
 * @param Name Chart name
 * @param L List of ticks labels
 *
 * @~french
 *
 * Modifie le nom des intervalles de l'axe X.
 *
 * Modifie le nom des intervalles situés sur l'axe X d'un ou plusieurs diagrammes
 * nommés @p Name.\n
 * La syntaxe @ref RegExp "re:" est supportée comme nom de diagramme.
 *
 * @note Vous pouvez aussi utiliser cette fonction sans indiquer le paramètre @p Name grâce à @ref chart_current.
@code
// Utilise "Premier", "Second", "Troisième" comme noms d'intervalles
chart_current "mychart"
chart_set_xticks_labels { "Premier", "Second", "Troisième" }
@endcode
 *
 * @param Name Nom du diagramme.
 * @param L Liste contenant le nom des intervalles.
 *
 **/
chart_set_xticks_labels(Name:text, L:list);


/**
 * @~english
 * Set label of Y-axis of one or multiple charts.
 *
 * This functions allows to change the Y-axis label of one or multiple charts
 * named @p Name.\n
 * The @ref RegExp "re:" syntax is supported as chart name.
 *
 * @param Name Chart name.
 * @param Label Y-axis label.
 *
 * @note You can also use this function without giving the chart @p Name thanks to @ref chart_current.
@code
chart_current "mychart"
chart_set_ylabel "x-axis"
text chart_ylabel
@endcode
 *
 * @~french
 *
 * Change le nom de l'axe Y d'un ou plusieurs diagrammes.
 *
 * Cette fonction change le nom de l'axe Y d'un ou plusieurs diagrammes nommés @p Name.\n
 * La syntaxe @ref RegExp "re:" est supportée comme nom de diagramme.
 *
 * @param Name Nom du diagramme.
 * @param Label Nom de l'axe Y.
 *
 * @note Vous pouvez aussi utiliser cette fonction sans indiquer le paramètre @p Name grâce à @ref chart_current.
@code
chart_current "mychart"
chart_set_ylabel "y-axis"
text chart_ylabel
@endcode
 *
 **/
chart_set_ylabel(Name:text, Label:text);


/**
 * @~english
 * Set ticks number of Y-axis of one or multiple charts.
 *
 * This functions allows to set @p N ticks on Y-axis for one or multiple charts
 * named @p Name.\n
 * The @ref RegExp "re:" syntax is supported as chart name.
 *
 * @param Name Chart name.
 * @param Ticks Ticks number.
 *
 * @note You can also use this function without giving the chart @p Name thanks to @ref chart_current.
@code
chart_current "mychart"
chart_set_yticks 5
text chart_yticks
@endcode
 *
 * @~french
 *
 * Définit le nombre d'intervalles de l'axe Y d'un ou plusieurs diagrammes.
 *
 * Cette fonction change le nombre d'intervalles de l'axe Y
 * d'un ou plusieurs diagrammes nommés @p Name.\n
 * La syntaxe @ref RegExp "re:" est supportée comme nom de diagramme.
 *
 * @param Name Nom du diagramme.
 * @param Ticks Nombre d'intervalles.
 *
 * @note Vous pouvez aussi utiliser cette fonction sans indiquer le paramètre @p Name grâce à @ref chart_current.
@code
chart_current "mychart"
chart_set_yticks 5
text chart_yticks
@endcode
 *
 **/
chart_set_yticks(Name:text, N:integer);


/**
 * @~english
 * Set label of a tick located on the Y-axis.
 *
 * This functions changes the label of tick @p N located on the Y-axis for
 * one or multiple charts named @p Name.\n
 * The @ref RegExp "re:" syntax is supported as chart name.
 *
 * @param Name Chart name.
 * @param N Tick index.
 * @param T Tick Label.
 *
 * @note You can also use this function without giving the chart @p Name thanks to @ref chart_current.
@code
chart_current "mychart"
chart_set_yticks_label 1, "First tick"
text (chart_yticks_label 1)
@endcode
 *
 * @~french
 *
 * Modifie le nom d'un intervalle de l'axe Y.
 *
 * Modifie le nom de l'intervalle @p N situé sur l'axe Y d'un ou plusieurs diagrammes
 * nommés @p Name.\n
 * La syntaxe @ref RegExp "re:" est supportée comme nom de diagramme.
 *
 * @param Name Nom du diagramme.
 * @param N Numéro de l'intervalle.
 * @param T Nom de l'intervalle.
 *
 * @note Vous pouvez aussi utiliser cette fonction sans indiquer le paramètre @p Name grâce à @ref chart_current.
@code
chart_current "mychart"
chart_set_yticks_label 1, "Premier intervalle"
text (chart_yticks_label 1)
@endcode
 *
 **/
chart_set_yticks_label(Name:text, N:integer, T:text);


/**
 * @~english
 * Set labels of ticks located on the Y-axis.
 *
 * This functions changes labels of ticks located on the Y-axis for
 * one or multiple charts named @p Name.\n
 * The @ref RegExp "re:" syntax is supported as chart name.
 * Example:
@code
// Set "First", "Second", "Third" as ticks labels
chart_set_yticks_labels { "First", "Second", "Third" }
@endcode
 *
 * @param Name Chart name
 * @param L List of ticks labels
 *
 * @~french
 *
 * Modifie le nom des intervalles de l'axe Y.
 *
 * Modifie le nom des intervalles situés sur l'axe Y d'un ou plusieurs diagrammes
 * nommés @p Name.\n
 * La syntaxe @ref RegExp "re:" est supportée comme nom de diagramme.
 * Exemple:
@code
// Utilise "Premier", "Second", "Troisième" comme noms d'intervalles
chart_set_yticks_labels { "Premier", "Second", "Troisième" }
@endcode
 *
 * @param Name Nom du diagramme.
 * @param L Liste contenant le nom des intervalles.
 *
 **/
chart_set_yticks_labels(Name:text, L:list);


/**
 * @~english
 * Return the style of a chart.
 *
 * This function returns the style of current chart (@ref chart_current).\n
 * Possible returned values are varying according to the chart type:
 *   - @ref Areacharts : "", "stacked"
 *   - @ref Barcharts : "", "vertical", "vertical_stacked", "horizontal", "horizontal_stacked"
 *   - @ref Linecharts : "", "point", "line", "line&point"
 *   - @ref Piecharts :  ""
 * You can modify this value with @ref chart_set_style.
 *
 * @~french
 * Renvoie le type d'un diagramme
 *
 * Cette fonction renvoie le type du diagramme courant (@ref chart_current).\n
 * Les valeurs possibles renvoyés dépendent du type du diagramme :
 *   - @ref Areacharts : "", "stacked"
 *   - @ref Barcharts : "", "vertical", "vertical_stacked", "horizontal", "horizontal_stacked"
 *   - @ref Linecharts : "", "point", "line", "line&point"
 *   - @ref Piecharts :  ""
 * Vous pouvez modifier cette valeur grâce à @ref chart_set_style.
 *
 * @~
 */
chart_style();


/**
 * @~english
 * Compute sum of a dataset.
 *
 * This function computes sum of dataset @p N of current chart.\n
 * Example:
@code
chart_reset "mychart"
chart_push_data "mychart", 2, 50
chart_push_data "mychart", 2, 21
chart_push_data "mychart", 2, 26

chart_sum 2 // Return 97
@endcode
 *
 * @param N Index of dataset (from 1 to 4).
 *
 * @~french
 *
 * Calcule la somme d'une série de données d'un diagramme.
 *
 * Cette fonction calcule la somme de la série de données @p N
 * du diagramme courant (@ref chart_current).\n
 * Exemple:
@code
chart_reset "mychart"
chart_push_data "mychart", 2, 50
chart_push_data "mychart", 2, 21
chart_push_data "mychart", 2, 26

chart_sum "mychart", 2 // Renvoie 97
@endcode
 *
 * @param N Numéro de la série de données (de 1 à 4).
 *
 * @~

 **/
chart_sum(N:integer);


/**
 * @~english
 * Return title of a chart.
 *
 * This functions returns the title of current chart (@ref chart_current).\n
 * To set this title, you can use @ref chart_set_title.
 *
 * @~french
 *
 * Renvoie le titre d'un diagramme.
 *
 * Cette fonction renvoie le titre du diagramme courant (@ref chart_current).\n
 * Pour changer cette valeur, il est possible d'utiliser la fonction @ref chart_set_title.
 *
 **/
chart_title();


/**
 * @~english
 * Return the type of current chart.
 *
 * This function returns the type of current chart (@ref chart_current).\n
 * You can modify this value with @ref chart_set_type.
 *
 * @~french
 * Renvoie le type d'un diagramme
 *
 * Cette fonction renvoie le type du diagramme courant (@ref chart_current).\n
 * Vous pouvez modifier cette valeur grâce à @ref chart_set_type.
 *
 * @~
 */
chart_type();


/**
 * @~english
 * Return label of X-axis.
 *
 * This functions returns the label of X-axis of current chart (@ref chart_current).\n
 * To change this value, you can use @ref chart_set_xlabel.
 *
 * @~french
 *
 * Renvoie le nom de l'axe X d'un diagramme.
 *
 * Cette fonction renvoie le nom de l'axe X du diagramme courant (@ref chart_current).\n
 * Pour changer cette valeur, il est possible d'utiliser la fonction @ref chart_set_xlabel.
 *
 **/
chart_xlabel();


/**
 * @~english
 * Return ticks number of X-axis.
 *
 * This functions return ticks number of X-axis of current chart (@ref chart_current).\n
 * To change this value, you can use @ref chart_set_xticks.
 *
 * @~french
 *
 * Renvoie le nombre d'intervalles sur l'axe X d'un diagramme.
 *
 * Cette fonction renvoie le nombre d'intervalles de l'axe X du diagramme courant (@ref chart_current).\n
 * Pour changer cette valeur, il est possible d'utiliser la fonction @ref chart_set_xticks.
 *
 **/
chart_xticks();


/**
 * @~english
 * Return label of a tick located on the X-axis.
 *
 * This functions returns the label of tick @p N located on the X-axis for
 * current chart (@ref chart_current).\n
 * To set a such label, you can use @ref chart_set_xticks_label.
 *
 * @param N Tick index.
 *
 * @~french
 *
 * Renvoie le nom d'un intervalle de l'axe X.
 *
 * Renvoie le nom de l'intervalle @p N situé sur l'axe X.\n
 * Pour changer cette valeur, il est possible d'utiliser la
 * fonction @ref chart_set_xticks_label.
 *
 * @param N Numéro de l'intervalle.
 *
 **/
chart_xticks_label(N:integer);


/**
 * @~english
 * Return label of Y-axis.
 *
 * This functions returns the label of Y-axis of current chart (@ref chart_current).\n
 * To change this value, you can use @ref chart_set_ylabel.
 *
 * @~french
 *
 * Renvoie le nom de l'axe Y d'un diagramme.
 *
 * Cette fonction renvoie le nom de l'axe Y du diagramme courant (@ref chart_current).\n
 * Pour changer cette valeur, il est possible d'utiliser la fonction @ref chart_set_ylabel.
 *
 **/
chart_ylabel();


/**
 * @~english
 * Return ticks number of Y-axis.
 *
 * This functions return ticks number of Y-axis of current chart (@ref chart_current).\n
 * To change this value, you can use @ref chart_set_yticks.
 *
 * @~french
 *
 * Renvoie le nombre d'intervalles sur l'axe Y d'un diagramme.
 *
 * Cette fonction renvoie le nombre d'intervalles de l'axe Y du diagramme courant (@ref chart_current).\n
 * Pour changer cette valeur, il est possible d'utiliser la fonction @ref chart_set_yticks.
 *
 **/
chart_yticks();


/**
 * @~english
 * Return label of a tick located on the Y-axis.
 *
 * This functions returns the label of tick @p N located on the Y-axis for
 * current chart (@ref chart_current).\n
 * To set a such label, you can use @ref chart_set_yticks_label.
 *
 * @param Name Chart name.
 * @param N Tick index.
 *
 * @~french
 *
 * Renvoie le nom d'un intervalle de l'axe Y.
 *
 * Renvoie le nom de l'intervalle @p N situé sur l'axe Y.\n
 * Pour changer cette valeur, il est possible d'utiliser la
 * fonction @ref chart_set_yticks_label.
 *
 * @param N Numéro de l'intervalle.
 *
 **/
chart_yticks_label(N:integer);



/**
 * @~english
 * \defgroup Areacharts Area charts
 * This page shows all styles of area charts with some examples and screenshots
 * using the default theme.
 * First, for all these charts, we need to initialize our datasets:
@code
import Charts

material_ambient 1.0, 1.0, 1.0, 1.0
material_diffuse 1.0, 1.0, 1.0, 1.0

// Init datasets with a loop
chart_current "My chart"
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
chart_set_type "area"
chart_set_style ""
chart_set_format "2D"
chart 1, 2
@endcode
 *
 * @image html "area_regular_2d.png" "Example of 2D regular area chart"
 *
 *
 * \subsection third 3D
@code
rotatey -15
chart_set_type "area"
chart_set_style ""
chart_set_format "3D"
chart 1, 2
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
chart_set_type "area"
chart_set_style "stacked"
chart_set_format "2D"
chart 1, 2
@endcode
 *
 * @image html "area_stacked_2d.png" "Example of 2D stacked area chart"
 *
 *
 * \subsection third 3D
@code
rotatey -15
chart_set_type "area"
chart_set_style "stacked"
chart_set_format "3D"
chart 1, 2
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

// Init datasets with a loop
chart_current "My chart"
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
chart_set_type "area"
chart_set_style ""
chart_set_format "2D"
chart 1, 2
@endcode
 *
 * @image html "area_regular_2d.png" "Exemple de diagramme de zones 2D classique"
 *
 *
 * \subsection third 3D
@code
rotatey -15
chart_set_type "area"
chart_set_style ""
chart_set_format "3D"
chart 1, 2
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
chart_set_type "area"
chart_set_style "stacked"
chart_set_format "2D"
chart 1, 2
@endcode
 *
 * @image html "area_stacked_2d.png" "Exemple de diagramme de zones empilées en 2D "
 *
 *
 * \subsection third 3D
@code
rotatey -15
chart_set_type "area"
chart_set_style "stacked"
chart_set_format "3D"
chart 1, 2
@endcode
 *
 * @image html "area_stacked_3d.png" "Exemple de diagramme de zones empilées 3D"
 *
 */


/**
 * @~english
 * \defgroup Barcharts Bar charts
 * This page shows all styles of bar charts with some examples and screenshots
 * using the default theme.
 * First, for all these charts, we need to initialize our datasets:
@code
import Charts

material_ambient 1.0, 1.0, 1.0, 1.0
material_diffuse 1.0, 1.0, 1.0, 1.0

// Init datasets with a loop
chart_current "My chart"
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
chart_set_type "bar"
chart_set_style ""
chart_set_format "2D"
chart 1, 2
@endcode
 *
 * @image html "bar_vertical_2d.png" "Example of 2D vertical bar chart"
 *
 *
 * \subsection third 3D
@code
rotatey -15
light 0
chart_set_type "bar"
chart_set_style ""
chart_set_format "3D"
chart 1, 2
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
chart_set_type "bar"
chart_set_style "vertical_stacked"
chart_set_format "2D"
chart 1, 2
@endcode
 *
 * @image html "bar_vertical_stacked_2d.png" "Example of 2D vertical stacked bar chart"
 *
 *
 * \subsection third 3D
@code
rotatey -15
light 0
chart_set_type "bar"
chart_set_style "vertical_stacked"
chart_set_format "3D"
chart 1, 2
@endcode
 *
 *  @image html "bar_vertical_stacked_3d.png" "Example of 3D vertical stacked bar chart"
 *
 * \section bar3 Horizontal
 *
 * \subsection two 2D
 *
@code
chart_set_type "bar"
chart_set_style "horizontal"
chart_set_format "2D"
chart 1, 2
@endcode
 *
 * @image html "bar_horizontal_2d.png" "Example of 2D horizontal bar chart"
 *
 *
 * \subsection third 3D
@code
rotatey -15
light 0
chart_set_type "bar"
chart_set_style "horizontal"
chart_set_format "3D"
chart 1, 2
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
chart_set_type "bar"
chart_set_style "horizontal_stacked"
chart_set_format "2D"
chart 1, 2
@endcode
 *
 * @image html "bar_horizontal_stacked_2d.png" "Example of 2D horizontal stacked bar chart"
 *
 *
 * \subsection third 3D
@code
rotatey -15
light 0
chart_set_type "bar"
chart_set_style "horizontal_stacked"
chart_set_format "3D"
chart 1, 2
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

// Init datasets with a loop
chart_current "My chart"
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
chart_set_type "bar"
chart_set_style ""
chart_set_format "2D"
chart 1, 2
@endcode
 *
 * @image html "bar_vertical_2d.png" "Exemple de diagrammes à barres verticales en 2D"
 *
 *
 * \subsection third 3D
@code
rotatey -15
light 0
chart_set_type "bar"
chart_set_style ""
chart_set_format "3D"
chart 1, 2
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
chart_set_type "bar"
chart_set_style "vertical_stacked"
chart_set_format "2D"
chart 1, 2
@endcode
 *
 * @image html "bar_vertical_stacked_2d.png" "Exemple de diagrammes à barres verticales empilées en 2D"
 *
 *
 * \subsection third 3D
@code
rotatey -15
light 0
chart_set_type "bar"
chart_set_style "vertical_stacked"
chart_set_format "3D"
chart 1, 2
@endcode
 *
 *  @image html "bar_vertical_stacked_3d.png" "Exemple de diagrammes à barres verticales empilées en 3D"
 *
 * \section bar3 Horizontal
 *
 * \subsection two 2D
 *
@code
chart_set_type "bar"
chart_set_style "horizontal"
chart_set_format "2D"
chart 1, 2
@endcode
 *
 * @image html "bar_horizontal_2d.png" "Exemple de diagrammes à barres horizontales en 2D"
 *
 *
 * \subsection third 3D
@code
rotatey -15
light 0
chart_set_type "bar"
chart_set_style "horizontal"
chart_set_format "3D"
chart 1, 2
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
chart_set_type "bar"
chart_set_style "horizontal_stacked"
chart_set_format "2D"
chart 1, 2
@endcode
 *
 * @image html "bar_horizontal_stacked_2d.png" "Exemple de diagrammes à barres horizontales empilées en 2D"
 *
 *
 * \subsection third 3D
@code
rotatey -15
light 0
chart_set_type "bar"
chart_set_style "horizontal_stacked"
chart_set_format "3D"
chart 1, 2
@endcode
 *
 * @image html "bar_horizontal_stacked_3d.png" "Exemple de diagrammes à barres horizontales empilées en 3D"
 */


/**
 * @~english
 * \defgroup Linecharts Line charts
 * This page shows all line styles with some examples and screenshots
 * using the default theme.
 * First, for all these charts, we need to initialize our datasets:
@code
import Charts

material_ambient 1.0, 1.0, 1.0, 1.0
material_diffuse 1.0, 1.0, 1.0, 1.0

// Init datasets with a loop
chart_current "My chart"
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
chart_set_type "line"
chart_set_style ""
chart_set_format "2D"
chart 1, 2
@endcode
 *
 * @image html "line_and_point_2d.png" "Example of 2D line and point chart"
 *
 *
 * \subsection third 3D
@code
rotatey -15
light 0
chart_set_type "line"
chart_set_style ""
chart_set_format "3D"
chart 1, 2
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
chart_set_type "line"
chart_set_style "line"
chart_set_format "2D"
chart 1, 2
@endcode
 *
 * @image html "line_2d.png" "Example of 2D line chart"
 *
 *
 * \subsection third 3D
@code
rotatey -15
light 0
chart_set_type "line"
chart_set_style "line"
chart_set_format "3D"
chart 1, 2
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
chart_set_type "line"
chart_set_style "point"
chart_set_format "2D"
chart 1, 2
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
chart_set_type "line"
chart_set_style "point"
chart_set_format "3D"
chart 1, 2
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

// Init datasets with a loop
chart_current "My chart"
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
chart_set_type "line"
chart_set_style ""
chart_set_format "2D"
chart 1, 2
@endcode
 *
 * @image html "line_and_point_2d.png" "Exemple de diagramme linéaire 2D avec lignes et points"
 *
 *
 * \subsection third 3D
@code
rotatey -15
light 0
chart_set_type "line"
chart_set_style ""
chart_set_format "3D"
chart 1, 2
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
chart_set_type "line"
chart_set_style "line"
chart_set_format "2D"
chart 1, 2
@endcode
 *
 * @image html "line_2d.png" "Exemple de diagramme linéaire 2D avec lignes seulement"
 *
 *
 * \subsection third 3D
@code
rotatey -15
light 0
chart_set_type "line"
chart_set_style "line"
chart_set_format "3D"
chart 1, 2
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
chart_set_type "line"
chart_set_style "point"
chart_set_format "2D"
chart 1, 2
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
chart_set_type "line"
chart_set_style "point"
chart_set_format "3D"
chart 1, 2
@endcode
 *
 * Ce style a le même résultat en 2D et en 3D dans le thème par défaut.
 *
 */


/**
 * @~english
 * \defgroup Piecharts Pie charts
 * This page shows all pie styles with some examples and screenshots
 * using the default theme.
 * First, for all these charts, we need to initialize our datasets:
@code
import Charts

material_ambient 1.0, 1.0, 1.0, 1.0
material_diffuse 1.0, 1.0, 1.0, 1.0

// Init datasets with a loop
chart_current "My chart"
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
 * You can use @ref chart_data_set_property with "exploded_slice" as property to explode
 * a specific slice of the pie chart.
 *
 * \subsection two 2D
 *
@code
chart_set_type "pie"
chart_set_style ""
chart_set_format "2D"
chart 1, 2
@endcode
 *
 * @image html "pie_regular_2d.png" "Example of 2D regular pie chart"
 *
 *
 * \subsection third 3D
@code
light 0
chart_set_type "pie"
chart_set_style ""
chart_set_format "3D"
chart 1, 2
@endcode
 *
 * @image html "pie_regular_3d.png" "Example of 3D regular pie chart"
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

// Init datasets with a loop
chart_current "My chart"
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
 * Vous pouvez éclater une part spécifique du diagramme circulaire en changeant la valeur
 * de l'attribut "exploded_slice" grâce à @ref chart_data_set_property.
 *
 * \subsection two 2D
 *
@code
chart_set_type "pie"
chart_set_style ""
chart_set_format "2D"
chart 1, 2
@endcode
 *
 * @image html "pie_regular_2d.png" "Exemple de diagramme circulaire classique 2D"
 *
 *
 * \subsection third 3D
@code
light 0
chart_set_type "pie"
chart_set_style ""
chart_set_format "3D"
chart 1, 2
@endcode
 *
 * @image html "pie_regular_3d.png" "Exemple de diagramme circulaire classique 3D"
 *
 */


/**
 * @}
 */
