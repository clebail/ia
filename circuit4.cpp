#include <QList>
#include "CMarker.h"

void initCicuit4(QList<CMarker>& mks) {
    mks << CMarker(QPoint(142, 449), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(161, 447), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(180, 446), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(199, 446), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(218, 449), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(237, 453), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(256, 458), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(275, 463), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(294, 467), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(313, 470), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(332, 470), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(351, 470), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(370, 468), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(389, 464), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(408, 458), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(426, 450), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(442, 439), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(454, 423), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks << CMarker(QPoint(457, 403), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks << CMarker(QPoint(454, 383), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks << CMarker(QPoint(445, 364), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks << CMarker(QPoint(434, 347), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks << CMarker(QPoint(422, 330), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks << CMarker(QPoint(408, 315), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks << CMarker(QPoint(394, 299), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks << CMarker(QPoint(379, 284), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(364, 269), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(349, 254), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(334, 239), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(319, 224), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(305, 209), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks << CMarker(QPoint(293, 192), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks << CMarker(QPoint(292, 172), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks << CMarker(QPoint(310, 163), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(329, 158), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(348, 154), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(367, 150), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(386, 145), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(405, 138), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(423, 130), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(438, 117), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(448, 99), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks << CMarker(QPoint(448, 79), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks << CMarker(QPoint(437, 62), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks << CMarker(QPoint(419, 51), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(399, 47), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(379, 46), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(359, 46), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(339, 47), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(319, 48), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(299, 49), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(279, 50), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(259, 50), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(239, 49), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(219, 49), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(199, 48), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(179, 48), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(159, 47), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(139, 47), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(119, 48), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(99, 50), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(80, 57), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(64, 69), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(55, 87), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks << CMarker(QPoint(53, 106), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks << CMarker(QPoint(58, 125), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks << CMarker(QPoint(68, 141), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks << CMarker(QPoint(87, 147), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(106, 142), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(125, 135), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(144, 129), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(163, 130), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(171, 147), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks << CMarker(QPoint(170, 166), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks << CMarker(QPoint(166, 185), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks << CMarker(QPoint(159, 203), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks << CMarker(QPoint(150, 221), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks << CMarker(QPoint(141, 238), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks << CMarker(QPoint(130, 255), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks << CMarker(QPoint(119, 272), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks << CMarker(QPoint(108, 289), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks << CMarker(QPoint(97, 305), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks << CMarker(QPoint(86, 322), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks << CMarker(QPoint(75, 339), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks << CMarker(QPoint(66, 356), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks << CMarker(QPoint(57, 374), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks << CMarker(QPoint(51, 393), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks << CMarker(QPoint(47, 412), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks << CMarker(QPoint(48, 431), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks << CMarker(QPoint(59, 447), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks << CMarker(QPoint(77, 454), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(96, 454), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(123, 452), &CMarker::depasseDroite, &CMarker::depasseGauche);
}
