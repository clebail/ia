#include <QtDebug>
#include <QEventLoop>
#include <QTime>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "commun.h"
#include "CGenetic.h"
#include "circuit1.cpp"

CGenetic::CGenetic(CWCircuit *wCircuit, const CSetup &setup) {
    QList<CMarker> mks1, mks2, mks3, mks4;

    initCicuit1(mks1);

    mks2 << CMarker(QPoint(377, 42), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks2 << CMarker(QPoint(396, 39), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks2 << CMarker(QPoint(415, 37), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks2 << CMarker(QPoint(434, 37), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks2 << CMarker(QPoint(453, 40), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks2 << CMarker(QPoint(466, 54), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks2 << CMarker(QPoint(464, 73), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks2 << CMarker(QPoint(450, 88), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks2 << CMarker(QPoint(433, 98), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks2 << CMarker(QPoint(416, 108), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks2 << CMarker(QPoint(398, 118), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks2 << CMarker(QPoint(380, 128), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks2 << CMarker(QPoint(363, 138), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks2 << CMarker(QPoint(349, 152), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks2 << CMarker(QPoint(343, 171), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks2 << CMarker(QPoint(347, 190), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks2 << CMarker(QPoint(355, 208), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks2 << CMarker(QPoint(364, 225), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks2 << CMarker(QPoint(374, 241), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks2 << CMarker(QPoint(384, 257), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks2 << CMarker(QPoint(394, 273), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks2 << CMarker(QPoint(404, 289), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks2 << CMarker(QPoint(414, 305), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks2 << CMarker(QPoint(425, 321), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks2 << CMarker(QPoint(435, 338), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks2 << CMarker(QPoint(444, 355), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks2 << CMarker(QPoint(451, 373), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks2 << CMarker(QPoint(452, 392), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks2 << CMarker(QPoint(444, 410), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks2 << CMarker(QPoint(430, 424), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks2 << CMarker(QPoint(413, 434), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks2 << CMarker(QPoint(395, 442), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks2 << CMarker(QPoint(375, 446), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks2 << CMarker(QPoint(355, 446), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks2 << CMarker(QPoint(335, 444), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks2 << CMarker(QPoint(315, 442), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks2 << CMarker(QPoint(295, 438), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks2 << CMarker(QPoint(275, 435), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks2 << CMarker(QPoint(255, 431), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks2 << CMarker(QPoint(235, 428), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks2 << CMarker(QPoint(215, 426), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks2 << CMarker(QPoint(195, 427), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks2 << CMarker(QPoint(176, 433), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks2 << CMarker(QPoint(158, 442), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks2 << CMarker(QPoint(140, 451), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks2 << CMarker(QPoint(120, 454), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks2 << CMarker(QPoint(100, 450), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks2 << CMarker(QPoint(81, 442), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks2 << CMarker(QPoint(63, 432), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks2 << CMarker(QPoint(48, 418), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks2 << CMarker(QPoint(39, 400), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks2 << CMarker(QPoint(38, 380), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks2 << CMarker(QPoint(45, 361), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks2 << CMarker(QPoint(55, 344), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks2 << CMarker(QPoint(64, 326), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks2 << CMarker(QPoint(68, 306), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks2 << CMarker(QPoint(64, 286), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks2 << CMarker(QPoint(56, 267), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks2 << CMarker(QPoint(48, 248), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks2 << CMarker(QPoint(41, 228), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks2 << CMarker(QPoint(39, 208), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks2 << CMarker(QPoint(42, 188), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks2 << CMarker(QPoint(45, 168), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks2 << CMarker(QPoint(44, 148), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks2 << CMarker(QPoint(35, 129), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks2 << CMarker(QPoint(28, 110), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks2 << CMarker(QPoint(32, 90), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks2 << CMarker(QPoint(43, 73), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks2 << CMarker(QPoint(57, 59), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks2 << CMarker(QPoint(75, 51), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks2 << CMarker(QPoint(94, 46), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks2 << CMarker(QPoint(113, 44), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks2 << CMarker(QPoint(132, 43), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks2 << CMarker(QPoint(151, 44), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks2 << CMarker(QPoint(170, 44), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks2 << CMarker(QPoint(189, 45), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks2 << CMarker(QPoint(208, 46), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks2 << CMarker(QPoint(227, 47), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks2 << CMarker(QPoint(246, 48), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks2 << CMarker(QPoint(265, 48), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks2 << CMarker(QPoint(284, 48), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks2 << CMarker(QPoint(303, 48), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks2 << CMarker(QPoint(322, 47), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks2 << CMarker(QPoint(341, 45), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks2 << CMarker(QPoint(358, 44), &CMarker::depasseDroite, &CMarker::depasseGauche);

    mks3 << CMarker(QPoint(134, 171), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks3 << CMarker(QPoint(143, 188), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks3 << CMarker(QPoint(159, 199), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks3 << CMarker(QPoint(178, 203), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks3 << CMarker(QPoint(193, 189), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks3 << CMarker(QPoint(205, 173), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks3 << CMarker(QPoint(214, 155), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks3 << CMarker(QPoint(221, 136), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks3 << CMarker(QPoint(225, 116), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks3 << CMarker(QPoint(228, 96), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks3 << CMarker(QPoint(231, 76), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks3 << CMarker(QPoint(238, 57), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks3 << CMarker(QPoint(254, 45), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks3 << CMarker(QPoint(273, 39), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks3 << CMarker(QPoint(292, 36), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks3 << CMarker(QPoint(311, 34), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks3 << CMarker(QPoint(330, 34), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks3 << CMarker(QPoint(349, 35), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks3 << CMarker(QPoint(368, 36), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks3 << CMarker(QPoint(387, 39), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks3 << CMarker(QPoint(406, 43), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks3 << CMarker(QPoint(424, 50), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks3 << CMarker(QPoint(440, 61), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks3 << CMarker(QPoint(453, 76), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks3 << CMarker(QPoint(459, 94), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks3 << CMarker(QPoint(458, 113), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks3 << CMarker(QPoint(451, 132), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks3 << CMarker(QPoint(440, 149), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks3 << CMarker(QPoint(431, 166), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks3 << CMarker(QPoint(425, 185), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks3 << CMarker(QPoint(423, 204), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks3 << CMarker(QPoint(425, 223), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks3 << CMarker(QPoint(430, 242), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks3 << CMarker(QPoint(440, 259), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks3 << CMarker(QPoint(451, 275), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks3 << CMarker(QPoint(460, 292), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks3 << CMarker(QPoint(467, 310), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks3 << CMarker(QPoint(469, 329), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks3 << CMarker(QPoint(464, 348), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks3 << CMarker(QPoint(456, 366), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks3 << CMarker(QPoint(451, 385), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks3 << CMarker(QPoint(445, 404), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks3 << CMarker(QPoint(436, 422), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks3 << CMarker(QPoint(422, 437), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks3 << CMarker(QPoint(404, 447), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks3 << CMarker(QPoint(384, 450), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks3 << CMarker(QPoint(364, 445), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks3 << CMarker(QPoint(345, 437), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks3 << CMarker(QPoint(326, 429), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks3 << CMarker(QPoint(306, 430), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks3 << CMarker(QPoint(289, 441), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks3 << CMarker(QPoint(271, 451), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks3 << CMarker(QPoint(252, 457), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks3 << CMarker(QPoint(232, 462), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks3 << CMarker(QPoint(212, 465), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks3 << CMarker(QPoint(192, 467), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks3 << CMarker(QPoint(172, 467), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks3 << CMarker(QPoint(152, 466), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks3 << CMarker(QPoint(132, 462), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks3 << CMarker(QPoint(113, 454), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks3 << CMarker(QPoint(96, 443), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks3 << CMarker(QPoint(82, 428), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks3 << CMarker(QPoint(70, 411), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks3 << CMarker(QPoint(59, 393), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks3 << CMarker(QPoint(50, 375), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks3 << CMarker(QPoint(42, 356), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks3 << CMarker(QPoint(34, 337), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks3 << CMarker(QPoint(29, 317), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks3 << CMarker(QPoint(28, 297), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks3 << CMarker(QPoint(31, 277), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks3 << CMarker(QPoint(38, 258), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks3 << CMarker(QPoint(45, 239), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks3 << CMarker(QPoint(50, 219), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks3 << CMarker(QPoint(49, 199), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks3 << CMarker(QPoint(47, 179), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks3 << CMarker(QPoint(45, 159), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks3 << CMarker(QPoint(45, 139), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks3 << CMarker(QPoint(45, 119), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks3 << CMarker(QPoint(45, 99), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks3 << CMarker(QPoint(46, 79), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks3 << CMarker(QPoint(47, 59), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks3 << CMarker(QPoint(52, 39), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks3 << CMarker(QPoint(69, 28), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks3 << CMarker(QPoint(88, 24), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks3 << CMarker(QPoint(107, 24), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks3 << CMarker(QPoint(124, 34), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks3 << CMarker(QPoint(131, 52), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks3 << CMarker(QPoint(134, 71), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks3 << CMarker(QPoint(134, 90), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks3 << CMarker(QPoint(132, 109), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks3 << CMarker(QPoint(131, 128), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks3 << CMarker(QPoint(130, 152), &CMarker::depasseBas, &CMarker::depasseHaut);
	
	mks4 << CMarker(QPoint(142, 449), &CMarker::depasseDroite, &CMarker::depasseGauche);
	mks4 << CMarker(QPoint(161, 447), &CMarker::depasseDroite, &CMarker::depasseGauche);
	mks4 << CMarker(QPoint(180, 446), &CMarker::depasseDroite, &CMarker::depasseGauche);
	mks4 << CMarker(QPoint(199, 446), &CMarker::depasseDroite, &CMarker::depasseGauche);
	mks4 << CMarker(QPoint(218, 449), &CMarker::depasseDroite, &CMarker::depasseGauche);
	mks4 << CMarker(QPoint(237, 453), &CMarker::depasseDroite, &CMarker::depasseGauche);
	mks4 << CMarker(QPoint(256, 458), &CMarker::depasseDroite, &CMarker::depasseGauche);
	mks4 << CMarker(QPoint(275, 463), &CMarker::depasseDroite, &CMarker::depasseGauche);
	mks4 << CMarker(QPoint(294, 467), &CMarker::depasseDroite, &CMarker::depasseGauche);
	mks4 << CMarker(QPoint(313, 470), &CMarker::depasseDroite, &CMarker::depasseGauche);
	mks4 << CMarker(QPoint(332, 470), &CMarker::depasseDroite, &CMarker::depasseGauche);
	mks4 << CMarker(QPoint(351, 470), &CMarker::depasseDroite, &CMarker::depasseGauche);
	mks4 << CMarker(QPoint(370, 468), &CMarker::depasseDroite, &CMarker::depasseGauche);
	mks4 << CMarker(QPoint(389, 464), &CMarker::depasseDroite, &CMarker::depasseGauche);
	mks4 << CMarker(QPoint(408, 458), &CMarker::depasseDroite, &CMarker::depasseGauche);
	mks4 << CMarker(QPoint(426, 450), &CMarker::depasseDroite, &CMarker::depasseGauche);
	mks4 << CMarker(QPoint(442, 439), &CMarker::depasseDroite, &CMarker::depasseGauche);
	mks4 << CMarker(QPoint(454, 423), &CMarker::depasseHaut, &CMarker::depasseBas);
	mks4 << CMarker(QPoint(457, 403), &CMarker::depasseHaut, &CMarker::depasseBas);
	mks4 << CMarker(QPoint(454, 383), &CMarker::depasseHaut, &CMarker::depasseBas);
	mks4 << CMarker(QPoint(445, 364), &CMarker::depasseHaut, &CMarker::depasseBas);
	mks4 << CMarker(QPoint(434, 347), &CMarker::depasseHaut, &CMarker::depasseBas);
	mks4 << CMarker(QPoint(422, 330), &CMarker::depasseHaut, &CMarker::depasseBas);
	mks4 << CMarker(QPoint(408, 315), &CMarker::depasseHaut, &CMarker::depasseBas);
	mks4 << CMarker(QPoint(394, 299), &CMarker::depasseHaut, &CMarker::depasseBas);
	mks4 << CMarker(QPoint(379, 284), &CMarker::depasseGauche, &CMarker::depasseDroite);
	mks4 << CMarker(QPoint(364, 269), &CMarker::depasseGauche, &CMarker::depasseDroite);
	mks4 << CMarker(QPoint(349, 254), &CMarker::depasseGauche, &CMarker::depasseDroite);
	mks4 << CMarker(QPoint(334, 239), &CMarker::depasseGauche, &CMarker::depasseDroite);
	mks4 << CMarker(QPoint(319, 224), &CMarker::depasseGauche, &CMarker::depasseDroite);
	mks4 << CMarker(QPoint(305, 209), &CMarker::depasseHaut, &CMarker::depasseBas);
	mks4 << CMarker(QPoint(293, 192), &CMarker::depasseHaut, &CMarker::depasseBas);
	mks4 << CMarker(QPoint(292, 172), &CMarker::depasseHaut, &CMarker::depasseBas);
	mks4 << CMarker(QPoint(310, 163), &CMarker::depasseDroite, &CMarker::depasseGauche);
	mks4 << CMarker(QPoint(329, 158), &CMarker::depasseDroite, &CMarker::depasseGauche);
	mks4 << CMarker(QPoint(348, 154), &CMarker::depasseDroite, &CMarker::depasseGauche);
	mks4 << CMarker(QPoint(367, 150), &CMarker::depasseDroite, &CMarker::depasseGauche);
	mks4 << CMarker(QPoint(386, 145), &CMarker::depasseDroite, &CMarker::depasseGauche);
	mks4 << CMarker(QPoint(405, 138), &CMarker::depasseDroite, &CMarker::depasseGauche);
	mks4 << CMarker(QPoint(423, 130), &CMarker::depasseDroite, &CMarker::depasseGauche);
	mks4 << CMarker(QPoint(438, 117), &CMarker::depasseDroite, &CMarker::depasseGauche);
	mks4 << CMarker(QPoint(448, 99), &CMarker::depasseHaut, &CMarker::depasseBas);
	mks4 << CMarker(QPoint(448, 79), &CMarker::depasseHaut, &CMarker::depasseBas);
	mks4 << CMarker(QPoint(437, 62), &CMarker::depasseHaut, &CMarker::depasseBas);
	mks4 << CMarker(QPoint(419, 51), &CMarker::depasseGauche, &CMarker::depasseDroite);
	mks4 << CMarker(QPoint(399, 47), &CMarker::depasseGauche, &CMarker::depasseDroite);
	mks4 << CMarker(QPoint(379, 46), &CMarker::depasseGauche, &CMarker::depasseDroite);
	mks4 << CMarker(QPoint(359, 46), &CMarker::depasseGauche, &CMarker::depasseDroite);
	mks4 << CMarker(QPoint(339, 47), &CMarker::depasseGauche, &CMarker::depasseDroite);
	mks4 << CMarker(QPoint(319, 48), &CMarker::depasseGauche, &CMarker::depasseDroite);
	mks4 << CMarker(QPoint(299, 49), &CMarker::depasseGauche, &CMarker::depasseDroite);
	mks4 << CMarker(QPoint(279, 50), &CMarker::depasseGauche, &CMarker::depasseDroite);
	mks4 << CMarker(QPoint(259, 50), &CMarker::depasseGauche, &CMarker::depasseDroite);
	mks4 << CMarker(QPoint(239, 49), &CMarker::depasseGauche, &CMarker::depasseDroite);
	mks4 << CMarker(QPoint(219, 49), &CMarker::depasseGauche, &CMarker::depasseDroite);
	mks4 << CMarker(QPoint(199, 48), &CMarker::depasseGauche, &CMarker::depasseDroite);
	mks4 << CMarker(QPoint(179, 48), &CMarker::depasseGauche, &CMarker::depasseDroite);
	mks4 << CMarker(QPoint(159, 47), &CMarker::depasseGauche, &CMarker::depasseDroite);
	mks4 << CMarker(QPoint(139, 47), &CMarker::depasseGauche, &CMarker::depasseDroite);
	mks4 << CMarker(QPoint(119, 48), &CMarker::depasseGauche, &CMarker::depasseDroite);
	mks4 << CMarker(QPoint(99, 50), &CMarker::depasseGauche, &CMarker::depasseDroite);
	mks4 << CMarker(QPoint(80, 57), &CMarker::depasseGauche, &CMarker::depasseDroite);
	mks4 << CMarker(QPoint(64, 69), &CMarker::depasseGauche, &CMarker::depasseDroite);
	mks4 << CMarker(QPoint(55, 87), &CMarker::depasseBas, &CMarker::depasseHaut);
	mks4 << CMarker(QPoint(53, 106), &CMarker::depasseBas, &CMarker::depasseHaut);
	mks4 << CMarker(QPoint(58, 125), &CMarker::depasseBas, &CMarker::depasseHaut);
	mks4 << CMarker(QPoint(68, 141), &CMarker::depasseBas, &CMarker::depasseHaut);
	mks4 << CMarker(QPoint(87, 147), &CMarker::depasseDroite, &CMarker::depasseGauche);
	mks4 << CMarker(QPoint(106, 142), &CMarker::depasseDroite, &CMarker::depasseGauche);
	mks4 << CMarker(QPoint(125, 135), &CMarker::depasseDroite, &CMarker::depasseGauche);
	mks4 << CMarker(QPoint(144, 129), &CMarker::depasseDroite, &CMarker::depasseGauche);
	mks4 << CMarker(QPoint(163, 130), &CMarker::depasseDroite, &CMarker::depasseGauche);
	mks4 << CMarker(QPoint(171, 147), &CMarker::depasseBas, &CMarker::depasseHaut);
	mks4 << CMarker(QPoint(170, 166), &CMarker::depasseBas, &CMarker::depasseHaut);
	mks4 << CMarker(QPoint(166, 185), &CMarker::depasseBas, &CMarker::depasseHaut);
	mks4 << CMarker(QPoint(159, 203), &CMarker::depasseBas, &CMarker::depasseHaut);
	mks4 << CMarker(QPoint(150, 221), &CMarker::depasseBas, &CMarker::depasseHaut);
	mks4 << CMarker(QPoint(141, 238), &CMarker::depasseBas, &CMarker::depasseHaut);
	mks4 << CMarker(QPoint(130, 255), &CMarker::depasseBas, &CMarker::depasseHaut);
	mks4 << CMarker(QPoint(119, 272), &CMarker::depasseBas, &CMarker::depasseHaut);
	mks4 << CMarker(QPoint(108, 289), &CMarker::depasseBas, &CMarker::depasseHaut);
	mks4 << CMarker(QPoint(97, 305), &CMarker::depasseBas, &CMarker::depasseHaut);
	mks4 << CMarker(QPoint(86, 322), &CMarker::depasseBas, &CMarker::depasseHaut);
	mks4 << CMarker(QPoint(75, 339), &CMarker::depasseBas, &CMarker::depasseHaut);
	mks4 << CMarker(QPoint(66, 356), &CMarker::depasseBas, &CMarker::depasseHaut);
	mks4 << CMarker(QPoint(57, 374), &CMarker::depasseBas, &CMarker::depasseHaut);
	mks4 << CMarker(QPoint(51, 393), &CMarker::depasseBas, &CMarker::depasseHaut);
	mks4 << CMarker(QPoint(47, 412), &CMarker::depasseBas, &CMarker::depasseHaut);
	mks4 << CMarker(QPoint(48, 431), &CMarker::depasseBas, &CMarker::depasseHaut);
	mks4 << CMarker(QPoint(59, 447), &CMarker::depasseBas, &CMarker::depasseHaut);
	mks4 << CMarker(QPoint(77, 454), &CMarker::depasseDroite, &CMarker::depasseGauche);
	mks4 << CMarker(QPoint(96, 454), &CMarker::depasseDroite, &CMarker::depasseGauche);
	mks4 << CMarker(QPoint(123, 452), &CMarker::depasseDroite, &CMarker::depasseGauche);

    this->wCircuit = wCircuit;
    this->setup = setup;

    populationInited = false;

    circuits[0] = CCircuit(QPoint(311, 24), 0, ":/circuits/circuit1.png", QPoint(96, 220));
    circuits[1] = CCircuit(QPoint(358, 44), PI, ":/circuits/circuit2.png", QPoint(121, 286));
    circuits[2] = CCircuit(QPoint(130, 152), 3*PI2, ":/circuits/circuit3.png", QPoint(125, 354));
    circuits[3] = CCircuit(QPoint(123, 452), PI, ":/circuits/circuit4.png", QPoint(149, 382));

    circuits[0].setMarkers(mks1);
    circuits[1].setMarkers(mks2);
    circuits[2].setMarkers(mks3);
    circuits[3].setMarkers(mks4);
	
	currentCircuit = 0;

    connect(this->wCircuit, SIGNAL(drawVoitures(QPainter*)), this, SLOT(onWCircuitDrawVoitures(QPainter*)));
}

CGenetic::~CGenetic(void) {
}

void CGenetic::initPopulation(int from, int to) {
	int i;

    for(i=from;i<=to;i++) {
		population[i] = new CVoiture();
		population[i]->init();
	}

    populationInited = true;
}

void CGenetic::triPopulation(void) {
	int i, j;
	
	for(i=TAILLE_POPULATION-1;i>=1;i--) {
		for(j=0;j<=i-1;j++) {
			if(population[j+1]->getScore() > population[j]->getScore()) {
				CVoiture *tmp = population[j+1];
				
				population[j+1] = population[j];
				population[j] = tmp;
			}
		}
	}
}

void CGenetic::croisePopuplation(void) {
	int i, ir, max;
	
	i = 1;
	ir = TAILLE_POPULATION - 1;
	max = TAILLE_POPULATION / 2;
	
	while(i < max) {
        if(population[i-1]->getScore() > 0 && population[i]->getScore() > 0) {
            int seuilVitesse = (rand() % (NB_CAPTEUR - 1)) + 1;
            int seuilAngle = (rand() % (NB_CAPTEUR - 1)) + 1;

            croiseIndividus(i-1, i, ir, seuilVitesse, seuilAngle);
            croiseIndividus(i, i-1, ir-1, seuilVitesse, seuilAngle);

            i+=2;
            ir-=2;
        } else {
            initPopulation(i - (population[i-1]->getScore() <= 0 ? 1 : 0), max - 1);
            i = max;
        }
	}
}

void CGenetic::croiseIndividus(int i1, int i2, int ir, int seuilVitesse, int seuilAngle) {
    population[ir]->from(population[i1], population[i2], seuilVitesse, seuilAngle);
}

double CGenetic::calculDistance(QPoint p, QPoint oppose, double angle) {
    int x = p.x();
    int y = p.y();
    int dx, dy;
    
    if((angle > PI2 - 0.01 && angle < PI2 + 0.01) || (angle > 3 * PI2 - 0.01 && angle < 3 * PI2 + 0.01)) {
        int sens = oppose.y() > p.y() ? -1 : 1;
        bool fini = isDehors(QPoint(x, y));
        
        while(!fini) {
            y += sens;

            fini = isDehors(QPoint(x, y));
        }
    } else {
        double a = tan(angle);
        double b = y - a * x;
        int sens = oppose.x() > p.x() ? -1 : 1;
        bool fini = isDehors(QPoint(x, y));
        
        while(!fini) {
            x += sens;
            y = a * x + b;

            fini = isDehors(QPoint(x, y));
        }
    }
    
    circuits[currentCircuit].normCoordonnees(x, y);

    dx = abs(p.x() - x);
    dy = abs(p.y() - y);

    return sqrt(dx * dx + dy * dy);
}

void CGenetic::setCircuit(int numCircuit) {
    int i;

    currentCircuit = numCircuit;

    for(i=0;i<TAILLE_POPULATION;i++) {
        population[i]->setStartInfo(circuits[numCircuit].getDepart(), circuits[numCircuit].getAngle(), circuits[numCircuit].getMarkers());
        population[i]->setAlive(true);
    }

    emit circuitChange(&circuits[numCircuit]);
}

bool CGenetic::isDehors(const QPoint& p) {
	QImage img = circuits[currentCircuit].getImage();
	
	if(p.x() < 0 || p.y() < 0 || p.x() >= img.width() || p.y() >= img.height()) {
		return true;
	}
	
	return img.pixel(p) == 0xFF000000;
}

void CGenetic::run(void) {
    int i = 0;
	int nb = 0;
	
	srand(time(NULL));
		
	initPopulation();

    setCircuit(0);

    do {
        calculScores();
        triPopulation();
		
		qDebug() << "Meilleur score " << population[0]->getScore() << "Num tour " << nb;
		
        croisePopuplation();

        if(++nb == setup.getNbCircuit()) {
			currentCircuit = rand() % NB_CIRCUIT;//(currentCircuit + 1) % NB_CIRCUIT;
			nb=0;
		}
        setCircuit(currentCircuit);
    }while(++i < NOMBRE_GENERATION);
	
    emit calculOk(population[0]);
}

void CGenetic::drawPopulation(QPainter *painter) {
    if(populationInited) {
        int i;

        for(i=0;i<TAILLE_POPULATION;i++) {
            if(population[i]->isAlive()) {
                population[i]->draw(painter);
            }
        }
    }
}

void CGenetic::calculScores(void) {
    int i;
    int nbAlive = TAILLE_POPULATION;
    QTime time;
    int timeElapsed = 0;
    
    time.start();
    while(nbAlive != 0 && timeElapsed < MAX_TIME) {
        for(i=0;i<TAILLE_POPULATION;i++) {
            if(population[i]->isAlive()) {
                double angle = population[i]->getCurrentAngle();
                double inputs[NB_CAPTEUR];
                QPoint *posRoue = population[i]->getPosRoue();
                int nbDehors = 0;

                inputs[0] = calculDistance(posRoue[0], posRoue[2], angle);
                inputs[1] = calculDistance(posRoue[0], posRoue[1], angle + PI2);
                inputs[2] = calculDistance(posRoue[0], posRoue[3], angle + PI / 4);
                inputs[3] = calculDistance(posRoue[1], posRoue[3], angle);
                inputs[4] = calculDistance(posRoue[1], posRoue[0], angle + 3 * PI2);
                inputs[5] = calculDistance(posRoue[1], posRoue[2], angle + 7 * PI / 4);
                inputs[6] = calculDistance(posRoue[2], posRoue[3], angle + PI2);
                inputs[7] = calculDistance(posRoue[3], posRoue[2], angle + 3 * PI2);

                //inputs[8] = angle;
                //inputs[9] = population[i]->getCurrentVitesse();

                population[i]->setInputs(inputs);

                if(population[i]->move(timeElapsed)) {
					nbDehors += isDehors(posRoue[0]) ? 1 : 0;
					nbDehors += isDehors(posRoue[1]) ? 1 : 0;
					nbDehors += isDehors(posRoue[2]) ? 1 : 0;
					nbDehors += isDehors(posRoue[3]) ? 1 : 0;

					population[i]->setAlive(nbDehors < 2);
					nbAlive -= nbDehors < 2 ? 0 : 1;
				} else {
					nbAlive--;
				}
            }
        }

        emit repaintRequested();
        msleep(1000 / 24);

        timeElapsed = time.elapsed();
    }
}

void CGenetic::onWCircuitDrawVoitures(QPainter *painter) {
    drawPopulation(painter);
}
