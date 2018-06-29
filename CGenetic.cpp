#include <QtDebug>
#include <QEventLoop>
#include <QTime>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "commun.h"
#include "CGenetic.h"

CGenetic::CGenetic(CWCircuit *wCircuit) {
    QList<CMarker> mks1, mks2, mks3, mks4;

    mks1 << CMarker(QPoint(330, 23), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks1 << CMarker(QPoint(349, 24), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks1 << CMarker(QPoint(368, 25), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks1 << CMarker(QPoint(387, 27), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks1 << CMarker(QPoint(406, 29), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks1 << CMarker(QPoint(425, 33), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks1 << CMarker(QPoint(442, 41), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks1 << CMarker(QPoint(455, 55), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks1 << CMarker(QPoint(462, 73), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks1 << CMarker(QPoint(464, 92), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks1 << CMarker(QPoint(463, 111), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks1 << CMarker(QPoint(456, 130), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks1 << CMarker(QPoint(445, 146), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks1 << CMarker(QPoint(432, 161), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks1 << CMarker(QPoint(419, 176), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks1 << CMarker(QPoint(412, 194), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks1 << CMarker(QPoint(409, 213), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks1 << CMarker(QPoint(411, 232), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks1 << CMarker(QPoint(415, 251), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks1 << CMarker(QPoint(420, 270), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks1 << CMarker(QPoint(426, 289), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks1 << CMarker(QPoint(431, 308), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks1 << CMarker(QPoint(437, 327), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks1 << CMarker(QPoint(442, 346), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks1 << CMarker(QPoint(447, 365), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks1 << CMarker(QPoint(451, 384), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks1 << CMarker(QPoint(454, 403), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks1 << CMarker(QPoint(456, 422), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks1 << CMarker(QPoint(455, 441), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks1 << CMarker(QPoint(444, 457), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks1 << CMarker(QPoint(424, 459), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks1 << CMarker(QPoint(404, 456), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks1 << CMarker(QPoint(384, 451), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks1 << CMarker(QPoint(364, 448), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks1 << CMarker(QPoint(344, 445), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks1 << CMarker(QPoint(324, 442), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks1 << CMarker(QPoint(304, 440), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks1 << CMarker(QPoint(284, 438), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks1 << CMarker(QPoint(264, 437), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks1 << CMarker(QPoint(244, 435), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks1 << CMarker(QPoint(224, 434), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks1 << CMarker(QPoint(204, 433), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks1 << CMarker(QPoint(184, 432), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks1 << CMarker(QPoint(164, 431), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks1 << CMarker(QPoint(144, 430), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks1 << CMarker(QPoint(124, 430), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks1 << CMarker(QPoint(104, 429), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks1 << CMarker(QPoint(84, 428), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks1 << CMarker(QPoint(64, 423), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks1 << CMarker(QPoint(47, 412), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks1 << CMarker(QPoint(36, 395), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks1 << CMarker(QPoint(30, 375), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks1 << CMarker(QPoint(28, 355), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks1 << CMarker(QPoint(32, 335), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks1 << CMarker(QPoint(37, 315), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks1 << CMarker(QPoint(40, 295), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks1 << CMarker(QPoint(40, 275), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks1 << CMarker(QPoint(37, 255), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks1 << CMarker(QPoint(34, 235), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks1 << CMarker(QPoint(32, 215), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks1 << CMarker(QPoint(31, 195), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks1 << CMarker(QPoint(33, 175), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks1 << CMarker(QPoint(35, 155), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks1 << CMarker(QPoint(36, 135), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks1 << CMarker(QPoint(35, 115), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks1 << CMarker(QPoint(38, 95), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks1 << CMarker(QPoint(47, 77), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks1 << CMarker(QPoint(60, 61), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks1 << CMarker(QPoint(76, 49), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks1 << CMarker(QPoint(94, 41), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks1 << CMarker(QPoint(113, 36), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks1 << CMarker(QPoint(132, 34), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks1 << CMarker(QPoint(151, 34), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks1 << CMarker(QPoint(170, 33), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks1 << CMarker(QPoint(189, 32), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks1 << CMarker(QPoint(208, 30), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks1 << CMarker(QPoint(227, 28), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks1 << CMarker(QPoint(246, 27), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks1 << CMarker(QPoint(265, 25), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks1 << CMarker(QPoint(284, 24), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks1 << CMarker(QPoint(311, 24), &CMarker::depasseDroite, &CMarker::depasseGauche);

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

    mks4 << CMarker(QPoint(103, 454), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks4 << CMarker(QPoint(83, 455), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks4 << CMarker(QPoint(63, 451), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks4 << CMarker(QPoint(49, 436), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks4 << CMarker(QPoint(46, 416), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks4 << CMarker(QPoint(49, 396), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks4 << CMarker(QPoint(55, 377), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks4 << CMarker(QPoint(63, 359), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks4 << CMarker(QPoint(73, 341), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks4 << CMarker(QPoint(84, 324), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks4 << CMarker(QPoint(95, 307), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks4 << CMarker(QPoint(106, 290), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks4 << CMarker(QPoint(117, 273), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks4 << CMarker(QPoint(129, 257), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks4 << CMarker(QPoint(139, 239), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks4 << CMarker(QPoint(149, 221), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks4 << CMarker(QPoint(158, 203), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks4 << CMarker(QPoint(165, 184), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks4 << CMarker(QPoint(170, 164), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks4 << CMarker(QPoint(170, 144), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks4 << CMarker(QPoint(155, 129), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks4 << CMarker(QPoint(135, 133), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks4 << CMarker(QPoint(116, 140), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks4 << CMarker(QPoint(97, 146), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks4 << CMarker(QPoint(77, 148), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks4 << CMarker(QPoint(61, 134), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks4 << CMarker(QPoint(54, 115), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks4 << CMarker(QPoint(53, 95), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks4 << CMarker(QPoint(59, 75), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks4 << CMarker(QPoint(72, 60), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks4 << CMarker(QPoint(90, 52), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks4 << CMarker(QPoint(109, 48), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks4 << CMarker(QPoint(128, 46), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks4 << CMarker(QPoint(147, 46), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks4 << CMarker(QPoint(166, 46), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks4 << CMarker(QPoint(185, 47), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks4 << CMarker(QPoint(204, 48), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks4 << CMarker(QPoint(223, 48), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks4 << CMarker(QPoint(242, 49), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks4 << CMarker(QPoint(261, 49), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks4 << CMarker(QPoint(280, 49), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks4 << CMarker(QPoint(299, 48), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks4 << CMarker(QPoint(318, 47), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks4 << CMarker(QPoint(337, 46), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks4 << CMarker(QPoint(356, 45), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks4 << CMarker(QPoint(375, 45), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks4 << CMarker(QPoint(394, 46), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks4 << CMarker(QPoint(413, 49), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks4 << CMarker(QPoint(431, 56), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks4 << CMarker(QPoint(445, 70), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks4 << CMarker(QPoint(450, 89), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks4 << CMarker(QPoint(445, 108), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks4 << CMarker(QPoint(433, 124), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks4 << CMarker(QPoint(416, 134), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks4 << CMarker(QPoint(398, 142), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks4 << CMarker(QPoint(379, 148), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks4 << CMarker(QPoint(359, 153), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks4 << CMarker(QPoint(339, 157), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks4 << CMarker(QPoint(319, 162), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks4 << CMarker(QPoint(300, 168), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks4 << CMarker(QPoint(291, 186), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks4 << CMarker(QPoint(301, 202), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks4 << CMarker(QPoint(314, 217), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks4 << CMarker(QPoint(327, 231), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks4 << CMarker(QPoint(341, 245), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks4 << CMarker(QPoint(355, 258), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks4 << CMarker(QPoint(369, 272), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks4 << CMarker(QPoint(383, 286), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks4 << CMarker(QPoint(396, 300), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks4 << CMarker(QPoint(409, 314), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks4 << CMarker(QPoint(422, 329), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks4 << CMarker(QPoint(434, 344), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks4 << CMarker(QPoint(444, 360), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks4 << CMarker(QPoint(452, 377), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks4 << CMarker(QPoint(458, 395), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks4 << CMarker(QPoint(457, 414), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks4 << CMarker(QPoint(449, 432), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks4 << CMarker(QPoint(435, 446), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks4 << CMarker(QPoint(417, 456), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks4 << CMarker(QPoint(398, 462), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks4 << CMarker(QPoint(378, 467), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks4 << CMarker(QPoint(358, 470), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks4 << CMarker(QPoint(338, 471), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks4 << CMarker(QPoint(318, 471), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks4 << CMarker(QPoint(298, 469), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks4 << CMarker(QPoint(278, 465), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks4 << CMarker(QPoint(258, 460), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks4 << CMarker(QPoint(238, 454), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks4 << CMarker(QPoint(218, 450), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks4 << CMarker(QPoint(198, 447), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks4 << CMarker(QPoint(178, 447), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks4 << CMarker(QPoint(158, 448), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks4 << CMarker(QPoint(138, 450), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks4 << CMarker(QPoint(123, 452), &CMarker::depasseGauche, &CMarker::depasseDroite);

    this->wCircuit = wCircuit;

    populationInited = false;

    circuits[0] = CCircuit(QPoint(311, 24), PI, ":/circuits/circuit1.png");
    circuits[1] = CCircuit(QPoint(358, 44), PI, ":/circuits/circuit2.png");
    circuits[2] = CCircuit(QPoint(130, 152), 3*PI2, ":/circuits/circuit3.png");
    circuits[3] = CCircuit(QPoint(123, 452), 0, ":/circuits/circuit4.png");

    circuits[0].setMarkers(mks1);
    circuits[1].setMarkers(mks2);
    circuits[2].setMarkers(mks3);
    circuits[3].setMarkers(mks4);
	
	currentCircuit = 0;

    connect(this->wCircuit, SIGNAL(drawVoitures(QPainter*)), this, SLOT(onWCircuitDrawVoitures(QPainter*)));
}

CGenetic::~CGenetic(void) {
}

void CGenetic::initPopulation(void) {
	int i;

    for(i=0;i<TAILLE_POPULATION;i++) {
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
        int seuilVitesse = (rand() % (NB_CAPTEUR - 1)) + 1;
        int seuilAngle = (rand() % (NB_CAPTEUR - 1)) + 1;
		
        croiseIndividus(i-1, i, ir, seuilVitesse, seuilAngle);
        croiseIndividus(i, i-1, ir-1, seuilVitesse, seuilAngle);
		
        i+=2;
		ir-=2;
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
		
		qDebug() << "Meilleur score " << population[0]->getScore();
		
        croisePopuplation();

		if(++nb == 10) {
			currentCircuit = (currentCircuit + 1) % NB_CIRCUIT;
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
                double inputs[NB_CAPTEUR+2];
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

                inputs[8] = angle;
                inputs[9] = population[i]->getCurrentVitesse();

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
