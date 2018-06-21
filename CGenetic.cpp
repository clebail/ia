#include <QtDebug>
#include <QEventLoop>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "commun.h"
#include "CGenetic.h"

CGenetic::CGenetic(CWCircuit *wCircuit) {
    QList<CMarker> mks1, mks2, mks3, mks4;

    mks1 << CMarker(QPoint(127, 429), &CMarker::depasseDroite);
    mks1 << CMarker(QPoint(146, 430), &CMarker::depasseDroite);
    mks1 << CMarker(QPoint(165, 430), &CMarker::depasseDroite);
    mks1 << CMarker(QPoint(184, 431), &CMarker::depasseDroite);
    mks1 << CMarker(QPoint(203, 432), &CMarker::depasseDroite);
    mks1 << CMarker(QPoint(222, 433), &CMarker::depasseDroite);
    mks1 << CMarker(QPoint(241, 434), &CMarker::depasseDroite);
    mks1 << CMarker(QPoint(260, 436), &CMarker::depasseDroite);
    mks1 << CMarker(QPoint(279, 437), &CMarker::depasseDroite);
    mks1 << CMarker(QPoint(298, 439), &CMarker::depasseDroite);
    mks1 << CMarker(QPoint(317, 441), &CMarker::depasseDroite);
    mks1 << CMarker(QPoint(336, 443), &CMarker::depasseDroite);
    mks1 << CMarker(QPoint(355, 445), &CMarker::depasseDroite);
    mks1 << CMarker(QPoint(374, 448), &CMarker::depasseDroite);
    mks1 << CMarker(QPoint(393, 452), &CMarker::depasseDroite);
    mks1 << CMarker(QPoint(412, 456), &CMarker::depasseDroite);
    mks1 << CMarker(QPoint(431, 459), &CMarker::depasseDroite);
    mks1 << CMarker(QPoint(449, 452), &CMarker::depasseDroite);
    mks1 << CMarker(QPoint(455, 432), &CMarker::depasseHaut);
    mks1 << CMarker(QPoint(454, 412), &CMarker::depasseHaut);
    mks1 << CMarker(QPoint(452, 392), &CMarker::depasseHaut);
    mks1 << CMarker(QPoint(447, 372), &CMarker::depasseHaut);
    mks1 << CMarker(QPoint(443, 352), &CMarker::depasseHaut);
    mks1 << CMarker(QPoint(437, 332), &CMarker::depasseHaut);
    mks1 << CMarker(QPoint(431, 312), &CMarker::depasseHaut);
    mks1 << CMarker(QPoint(426, 292), &CMarker::depasseHaut);
    mks1 << CMarker(QPoint(420, 272), &CMarker::depasseHaut);
    mks1 << CMarker(QPoint(414, 252), &CMarker::depasseHaut);
    mks1 << CMarker(QPoint(410, 232), &CMarker::depasseHaut);
    mks1 << CMarker(QPoint(409, 212), &CMarker::depasseHaut);
    mks1 << CMarker(QPoint(411, 192), &CMarker::depasseHaut);
    mks1 << CMarker(QPoint(420, 174), &CMarker::depasseHaut);
    mks1 << CMarker(QPoint(433, 158), &CMarker::depasseHaut);
    mks1 << CMarker(QPoint(446, 142), &CMarker::depasseHaut);
    mks1 << CMarker(QPoint(457, 125), &CMarker::depasseHaut);
    mks1 << CMarker(QPoint(463, 105), &CMarker::depasseHaut);
    mks1 << CMarker(QPoint(463, 85), &CMarker::depasseHaut);
    mks1 << CMarker(QPoint(458, 65), &CMarker::depasseHaut);
    mks1 << CMarker(QPoint(447, 47), &CMarker::depasseHaut);
    mks1 << CMarker(QPoint(429, 36), &CMarker::depasseGauche);
    mks1 << CMarker(QPoint(409, 31), &CMarker::depasseGauche);
    mks1 << CMarker(QPoint(389, 28), &CMarker::depasseGauche);
    mks1 << CMarker(QPoint(369, 26), &CMarker::depasseGauche);
    mks1 << CMarker(QPoint(349, 25), &CMarker::depasseGauche);
    mks1 << CMarker(QPoint(311, 24), &CMarker::depasseGauche);

    mks2 << CMarker(QPoint(338, 47), &CMarker::depasseGauche);
    mks2 << CMarker(QPoint(318, 48), &CMarker::depasseGauche);
    mks2 << CMarker(QPoint(298, 49), &CMarker::depasseGauche);
    mks2 << CMarker(QPoint(278, 49), &CMarker::depasseGauche);
    mks2 << CMarker(QPoint(258, 49), &CMarker::depasseGauche);
    mks2 << CMarker(QPoint(238, 48), &CMarker::depasseGauche);
    mks2 << CMarker(QPoint(218, 47), &CMarker::depasseGauche);
    mks2 << CMarker(QPoint(198, 46), &CMarker::depasseGauche);
    mks2 << CMarker(QPoint(178, 45), &CMarker::depasseGauche);
    mks2 << CMarker(QPoint(158, 44), &CMarker::depasseGauche);
    mks2 << CMarker(QPoint(138, 44), &CMarker::depasseGauche);
    mks2 << CMarker(QPoint(118, 44), &CMarker::depasseGauche);
    mks2 << CMarker(QPoint(98, 46), &CMarker::depasseGauche);
    mks2 << CMarker(QPoint(78, 51), &CMarker::depasseGauche);
    mks2 << CMarker(QPoint(60, 59), &CMarker::depasseGauche);
    mks2 << CMarker(QPoint(45, 72), &CMarker::depasseGauche);
    mks2 << CMarker(QPoint(34, 89), &CMarker::depasseBas);
    mks2 << CMarker(QPoint(29, 108), &CMarker::depasseBas);
    mks2 << CMarker(QPoint(35, 126), &CMarker::depasseBas);
    mks2 << CMarker(QPoint(43, 143), &CMarker::depasseBas);
    mks2 << CMarker(QPoint(47, 162), &CMarker::depasseBas);
    mks2 << CMarker(QPoint(44, 181), &CMarker::depasseBas);
    mks2 << CMarker(QPoint(41, 200), &CMarker::depasseBas);
    mks2 << CMarker(QPoint(41, 219), &CMarker::depasseBas);
    mks2 << CMarker(QPoint(45, 238), &CMarker::depasseBas);
    mks2 << CMarker(QPoint(52, 256), &CMarker::depasseBas);
    mks2 << CMarker(QPoint(60, 273), &CMarker::depasseBas);
    mks2 << CMarker(QPoint(66, 291), &CMarker::depasseBas);
    mks2 << CMarker(QPoint(69, 310), &CMarker::depasseBas);
    mks2 << CMarker(QPoint(64, 329), &CMarker::depasseBas);
    mks2 << CMarker(QPoint(55, 346), &CMarker::depasseBas);
    mks2 << CMarker(QPoint(45, 363), &CMarker::depasseBas);
    mks2 << CMarker(QPoint(39, 382), &CMarker::depasseBas);
    mks2 << CMarker(QPoint(40, 401), &CMarker::depasseBas);
    mks2 << CMarker(QPoint(50, 418), &CMarker::depasseBas);
    mks2 << CMarker(QPoint(64, 431), &CMarker::depasseDroite);
    mks2 << CMarker(QPoint(81, 441), &CMarker::depasseDroite);
    mks2 << CMarker(QPoint(99, 449), &CMarker::depasseDroite);
    mks2 << CMarker(QPoint(118, 453), &CMarker::depasseDroite);
    mks2 << CMarker(QPoint(137, 451), &CMarker::depasseDroite);
    mks2 << CMarker(QPoint(155, 443), &CMarker::depasseDroite);
    mks2 << CMarker(QPoint(172, 434), &CMarker::depasseDroite);
    mks2 << CMarker(QPoint(190, 427), &CMarker::depasseDroite);
    mks2 << CMarker(QPoint(209, 425), &CMarker::depasseDroite);
    mks2 << CMarker(QPoint(228, 426), &CMarker::depasseDroite);
    mks2 << CMarker(QPoint(247, 429), &CMarker::depasseDroite);
    mks2 << CMarker(QPoint(266, 432), &CMarker::depasseDroite);
    mks2 << CMarker(QPoint(285, 436), &CMarker::depasseDroite);
    mks2 << CMarker(QPoint(304, 439), &CMarker::depasseDroite);
    mks2 << CMarker(QPoint(323, 442), &CMarker::depasseDroite);
    mks2 << CMarker(QPoint(342, 444), &CMarker::depasseDroite);
    mks2 << CMarker(QPoint(361, 445), &CMarker::depasseDroite);
    mks2 << CMarker(QPoint(380, 444), &CMarker::depasseDroite);
    mks2 << CMarker(QPoint(399, 440), &CMarker::depasseDroite);
    mks2 << CMarker(QPoint(417, 431), &CMarker::depasseDroite);
    mks2 << CMarker(QPoint(433, 420), &CMarker::depasseDroite);
    mks2 << CMarker(QPoint(446, 405), &CMarker::depasseHaut);
    mks2 << CMarker(QPoint(452, 385), &CMarker::depasseHaut);
    mks2 << CMarker(QPoint(447, 365), &CMarker::depasseHaut);
    mks2 << CMarker(QPoint(438, 346), &CMarker::depasseHaut);
    mks2 << CMarker(QPoint(428, 328), &CMarker::depasseHaut);
    mks2 << CMarker(QPoint(417, 311), &CMarker::depasseHaut);
    mks2 << CMarker(QPoint(406, 294), &CMarker::depasseHaut);
    mks2 << CMarker(QPoint(395, 277), &CMarker::depasseHaut);
    mks2 << CMarker(QPoint(384, 260), &CMarker::depasseHaut);
    mks2 << CMarker(QPoint(373, 242), &CMarker::depasseHaut);
    mks2 << CMarker(QPoint(363, 224), &CMarker::depasseHaut);
    mks2 << CMarker(QPoint(353, 206), &CMarker::depasseHaut);
    mks2 << CMarker(QPoint(345, 187), &CMarker::depasseHaut);
    mks2 << CMarker(QPoint(342, 167), &CMarker::depasseHaut);
    mks2 << CMarker(QPoint(350, 148), &CMarker::depasseHaut);
    mks2 << CMarker(QPoint(366, 136), &CMarker::depasseDroite);
    mks2 << CMarker(QPoint(382, 125), &CMarker::depasseDroite);
    mks2 << CMarker(QPoint(399, 116), &CMarker::depasseDroite);
    mks2 << CMarker(QPoint(416, 107), &CMarker::depasseDroite);
    mks2 << CMarker(QPoint(433, 97), &CMarker::depasseDroite);
    mks2 << CMarker(QPoint(450, 86), &CMarker::depasseDroite);
    mks2 << CMarker(QPoint(464, 71), &CMarker::depasseHaut);
    mks2 << CMarker(QPoint(464, 51), &CMarker::depasseHaut);
    mks2 << CMarker(QPoint(447, 39), &CMarker::depasseGauche);
    mks2 << CMarker(QPoint(427, 37), &CMarker::depasseGauche);
    mks2 << CMarker(QPoint(407, 39), &CMarker::depasseGauche);
    mks2 << CMarker(QPoint(387, 41), &CMarker::depasseGauche);
    mks2 << CMarker(QPoint(358, 44), &CMarker::depasseGauche);

    mks3 << CMarker(QPoint(130, 132), &CMarker::depasseHaut);
    mks3 << CMarker(QPoint(131, 112), &CMarker::depasseHaut);
    mks3 << CMarker(QPoint(133, 92), &CMarker::depasseHaut);
    mks3 << CMarker(QPoint(133, 72), &CMarker::depasseHaut);
    mks3 << CMarker(QPoint(131, 52), &CMarker::depasseHaut);
    mks3 << CMarker(QPoint(122, 33), &CMarker::depasseHaut);
    mks3 << CMarker(QPoint(103, 24), &CMarker::depasseGauche);
    mks3 << CMarker(QPoint(83, 26), &CMarker::depasseGauche);
    mks3 << CMarker(QPoint(63, 31), &CMarker::depasseGauche);
    mks3 << CMarker(QPoint(50, 46), &CMarker::depasseBas);
    mks3 << CMarker(QPoint(47, 65), &CMarker::depasseBas);
    mks3 << CMarker(QPoint(46, 84), &CMarker::depasseBas);
    mks3 << CMarker(QPoint(46, 103), &CMarker::depasseBas);
    mks3 << CMarker(QPoint(45, 122), &CMarker::depasseBas);
    mks3 << CMarker(QPoint(46, 141), &CMarker::depasseBas);
    mks3 << CMarker(QPoint(46, 160), &CMarker::depasseBas);
    mks3 << CMarker(QPoint(48, 179), &CMarker::depasseBas);
    mks3 << CMarker(QPoint(50, 198), &CMarker::depasseBas);
    mks3 << CMarker(QPoint(51, 217), &CMarker::depasseBas);
    mks3 << CMarker(QPoint(47, 236), &CMarker::depasseBas);
    mks3 << CMarker(QPoint(40, 255), &CMarker::depasseBas);
    mks3 << CMarker(QPoint(33, 274), &CMarker::depasseBas);
    mks3 << CMarker(QPoint(29, 293), &CMarker::depasseBas);
    mks3 << CMarker(QPoint(29, 312), &CMarker::depasseBas);
    mks3 << CMarker(QPoint(33, 331), &CMarker::depasseBas);
    mks3 << CMarker(QPoint(40, 349), &CMarker::depasseBas);
    mks3 << CMarker(QPoint(47, 367), &CMarker::depasseBas);
    mks3 << CMarker(QPoint(55, 384), &CMarker::depasseBas);
    mks3 << CMarker(QPoint(64, 401), &CMarker::depasseBas);
    mks3 << CMarker(QPoint(75, 417), &CMarker::depasseBas);
    mks3 << CMarker(QPoint(86, 433), &CMarker::depasseBas);
    mks3 << CMarker(QPoint(101, 445), &CMarker::depasseDroite);
    mks3 << CMarker(QPoint(118, 455), &CMarker::depasseDroite);
    mks3 << CMarker(QPoint(136, 462), &CMarker::depasseDroite);
    mks3 << CMarker(QPoint(155, 465), &CMarker::depasseDroite);
    mks3 << CMarker(QPoint(174, 467), &CMarker::depasseDroite);
    mks3 << CMarker(QPoint(193, 466), &CMarker::depasseDroite);
    mks3 << CMarker(QPoint(212, 464), &CMarker::depasseDroite);
    mks3 << CMarker(QPoint(231, 461), &CMarker::depasseDroite);
    mks3 << CMarker(QPoint(250, 457), &CMarker::depasseDroite);
    mks3 << CMarker(QPoint(269, 451), &CMarker::depasseDroite);
    mks3 << CMarker(QPoint(286, 442), &CMarker::depasseDroite);
    mks3 << CMarker(QPoint(302, 431), &CMarker::depasseDroite);
    mks3 << CMarker(QPoint(321, 427), &CMarker::depasseDroite);
    mks3 << CMarker(QPoint(339, 434), &CMarker::depasseDroite);
    mks3 << CMarker(QPoint(357, 442), &CMarker::depasseDroite);
    mks3 << CMarker(QPoint(376, 448), &CMarker::depasseDroite);
    mks3 << CMarker(QPoint(395, 448), &CMarker::depasseDroite);
    mks3 << CMarker(QPoint(414, 441), &CMarker::depasseDroite);
    mks3 << CMarker(QPoint(430, 429), &CMarker::depasseDroite);
    mks3 << CMarker(QPoint(441, 412), &CMarker::depasseHaut);
    mks3 << CMarker(QPoint(448, 393), &CMarker::depasseHaut);
    mks3 << CMarker(QPoint(453, 373), &CMarker::depasseHaut);
    mks3 << CMarker(QPoint(460, 354), &CMarker::depasseHaut);
    mks3 << CMarker(QPoint(467, 335), &CMarker::depasseHaut);
    mks3 << CMarker(QPoint(467, 315), &CMarker::depasseHaut);
    mks3 << CMarker(QPoint(461, 295), &CMarker::depasseHaut);
    mks3 << CMarker(QPoint(451, 277), &CMarker::depasseHaut);
    mks3 << CMarker(QPoint(440, 260), &CMarker::depasseHaut);
    mks3 << CMarker(QPoint(430, 242), &CMarker::depasseHaut);
    mks3 << CMarker(QPoint(424, 222), &CMarker::depasseHaut);
    mks3 << CMarker(QPoint(422, 202), &CMarker::depasseHaut);
    mks3 << CMarker(QPoint(425, 182), &CMarker::depasseHaut);
    mks3 << CMarker(QPoint(431, 162), &CMarker::depasseHaut);
    mks3 << CMarker(QPoint(441, 145), &CMarker::depasseHaut);
    mks3 << CMarker(QPoint(452, 128), &CMarker::depasseHaut);
    mks3 << CMarker(QPoint(458, 109), &CMarker::depasseHaut);
    mks3 << CMarker(QPoint(457, 89), &CMarker::depasseHaut);
    mks3 << CMarker(QPoint(448, 71), &CMarker::depasseHaut);
    mks3 << CMarker(QPoint(433, 57), &CMarker::depasseGauche);
    mks3 << CMarker(QPoint(415, 47), &CMarker::depasseGauche);
    mks3 << CMarker(QPoint(395, 41), &CMarker::depasseGauche);
    mks3 << CMarker(QPoint(375, 37), &CMarker::depasseGauche);
    mks3 << CMarker(QPoint(355, 36), &CMarker::depasseGauche);
    mks3 << CMarker(QPoint(335, 35), &CMarker::depasseGauche);
    mks3 << CMarker(QPoint(315, 35), &CMarker::depasseGauche);
    mks3 << CMarker(QPoint(295, 36), &CMarker::depasseGauche);
    mks3 << CMarker(QPoint(275, 39), &CMarker::depasseGauche);
    mks3 << CMarker(QPoint(256, 45), &CMarker::depasseGauche);
    mks3 << CMarker(QPoint(239, 56), &CMarker::depasseGauche);
    mks3 << CMarker(QPoint(232, 75), &CMarker::depasseBas);
    mks3 << CMarker(QPoint(229, 94), &CMarker::depasseBas);
    mks3 << CMarker(QPoint(226, 113), &CMarker::depasseBas);
    mks3 << CMarker(QPoint(222, 132), &CMarker::depasseBas);
    mks3 << CMarker(QPoint(217, 151), &CMarker::depasseBas);
    mks3 << CMarker(QPoint(208, 169), &CMarker::depasseBas);
    mks3 << CMarker(QPoint(197, 185), &CMarker::depasseBas);
    mks3 << CMarker(QPoint(185, 201), &CMarker::depasseBas);
    mks3 << CMarker(QPoint(165, 202), &CMarker::depasseGauche);
    mks3 << CMarker(QPoint(146, 193), &CMarker::depasseGauche);
    mks3 << CMarker(QPoint(134, 176), &CMarker::depasseHaut);
    mks3 << CMarker(QPoint(130, 152), &CMarker::depasseHaut);

    mks4 << CMarker(QPoint(142, 449), &CMarker::depasseDroite);
    mks4 << CMarker(QPoint(161, 447), &CMarker::depasseDroite);
    mks4 << CMarker(QPoint(180, 446), &CMarker::depasseDroite);
    mks4 << CMarker(QPoint(199, 446), &CMarker::depasseDroite);
    mks4 << CMarker(QPoint(218, 449), &CMarker::depasseDroite);
    mks4 << CMarker(QPoint(237, 453), &CMarker::depasseDroite);
    mks4 << CMarker(QPoint(256, 458), &CMarker::depasseDroite);
    mks4 << CMarker(QPoint(275, 463), &CMarker::depasseDroite);
    mks4 << CMarker(QPoint(294, 467), &CMarker::depasseDroite);
    mks4 << CMarker(QPoint(313, 470), &CMarker::depasseDroite);
    mks4 << CMarker(QPoint(332, 470), &CMarker::depasseDroite);
    mks4 << CMarker(QPoint(351, 470), &CMarker::depasseDroite);
    mks4 << CMarker(QPoint(370, 468), &CMarker::depasseDroite);
    mks4 << CMarker(QPoint(389, 464), &CMarker::depasseDroite);
    mks4 << CMarker(QPoint(408, 458), &CMarker::depasseDroite);
    mks4 << CMarker(QPoint(426, 450), &CMarker::depasseDroite);
    mks4 << CMarker(QPoint(442, 439), &CMarker::depasseDroite);
    mks4 << CMarker(QPoint(454, 423), &CMarker::depasseHaut);
    mks4 << CMarker(QPoint(457, 403), &CMarker::depasseHaut);
    mks4 << CMarker(QPoint(454, 383), &CMarker::depasseHaut);
    mks4 << CMarker(QPoint(445, 364), &CMarker::depasseHaut);
    mks4 << CMarker(QPoint(434, 347), &CMarker::depasseHaut);
    mks4 << CMarker(QPoint(422, 330), &CMarker::depasseHaut);
    mks4 << CMarker(QPoint(408, 315), &CMarker::depasseHaut);
    mks4 << CMarker(QPoint(394, 299), &CMarker::depasseHaut);
    mks4 << CMarker(QPoint(379, 284), &CMarker::depasseGauche);
    mks4 << CMarker(QPoint(364, 269), &CMarker::depasseGauche);
    mks4 << CMarker(QPoint(349, 254), &CMarker::depasseGauche);
    mks4 << CMarker(QPoint(334, 239), &CMarker::depasseGauche);
    mks4 << CMarker(QPoint(319, 224), &CMarker::depasseGauche);
    mks4 << CMarker(QPoint(305, 209), &CMarker::depasseHaut);
    mks4 << CMarker(QPoint(293, 192), &CMarker::depasseHaut);
    mks4 << CMarker(QPoint(292, 172), &CMarker::depasseHaut);
    mks4 << CMarker(QPoint(310, 163), &CMarker::depasseDroite);
    mks4 << CMarker(QPoint(329, 158), &CMarker::depasseDroite);
    mks4 << CMarker(QPoint(348, 154), &CMarker::depasseDroite);
    mks4 << CMarker(QPoint(367, 150), &CMarker::depasseDroite);
    mks4 << CMarker(QPoint(386, 145), &CMarker::depasseDroite);
    mks4 << CMarker(QPoint(405, 138), &CMarker::depasseDroite);
    mks4 << CMarker(QPoint(423, 130), &CMarker::depasseDroite);
    mks4 << CMarker(QPoint(438, 117), &CMarker::depasseDroite);
    mks4 << CMarker(QPoint(448, 99), &CMarker::depasseHaut);
    mks4 << CMarker(QPoint(448, 79), &CMarker::depasseHaut);
    mks4 << CMarker(QPoint(437, 62), &CMarker::depasseHaut);
    mks4 << CMarker(QPoint(419, 51), &CMarker::depasseGauche);
    mks4 << CMarker(QPoint(399, 47), &CMarker::depasseGauche);
    mks4 << CMarker(QPoint(379, 46), &CMarker::depasseGauche);
    mks4 << CMarker(QPoint(359, 46), &CMarker::depasseGauche);
    mks4 << CMarker(QPoint(339, 47), &CMarker::depasseGauche);
    mks4 << CMarker(QPoint(319, 48), &CMarker::depasseGauche);
    mks4 << CMarker(QPoint(299, 49), &CMarker::depasseGauche);
    mks4 << CMarker(QPoint(279, 50), &CMarker::depasseGauche);
    mks4 << CMarker(QPoint(259, 50), &CMarker::depasseGauche);
    mks4 << CMarker(QPoint(239, 49), &CMarker::depasseGauche);
    mks4 << CMarker(QPoint(219, 49), &CMarker::depasseGauche);
    mks4 << CMarker(QPoint(199, 48), &CMarker::depasseGauche);
    mks4 << CMarker(QPoint(179, 48), &CMarker::depasseGauche);
    mks4 << CMarker(QPoint(159, 47), &CMarker::depasseGauche);
    mks4 << CMarker(QPoint(139, 47), &CMarker::depasseGauche);
    mks4 << CMarker(QPoint(119, 48), &CMarker::depasseGauche);
    mks4 << CMarker(QPoint(99, 50), &CMarker::depasseGauche);
    mks4 << CMarker(QPoint(80, 57), &CMarker::depasseGauche);
    mks4 << CMarker(QPoint(64, 69), &CMarker::depasseGauche);
    mks4 << CMarker(QPoint(55, 87), &CMarker::depasseBas);
    mks4 << CMarker(QPoint(53, 106), &CMarker::depasseBas);
    mks4 << CMarker(QPoint(58, 125), &CMarker::depasseBas);
    mks4 << CMarker(QPoint(68, 141), &CMarker::depasseBas);
    mks4 << CMarker(QPoint(87, 147), &CMarker::depasseDroite);
    mks4 << CMarker(QPoint(106, 142), &CMarker::depasseDroite);
    mks4 << CMarker(QPoint(125, 135), &CMarker::depasseDroite);
    mks4 << CMarker(QPoint(144, 129), &CMarker::depasseDroite);
    mks4 << CMarker(QPoint(163, 130), &CMarker::depasseDroite);
    mks4 << CMarker(QPoint(171, 147), &CMarker::depasseBas);
    mks4 << CMarker(QPoint(170, 166), &CMarker::depasseBas);
    mks4 << CMarker(QPoint(166, 185), &CMarker::depasseBas);
    mks4 << CMarker(QPoint(159, 203), &CMarker::depasseBas);
    mks4 << CMarker(QPoint(150, 221), &CMarker::depasseBas);
    mks4 << CMarker(QPoint(141, 238), &CMarker::depasseBas);
    mks4 << CMarker(QPoint(130, 255), &CMarker::depasseBas);
    mks4 << CMarker(QPoint(119, 272), &CMarker::depasseBas);
    mks4 << CMarker(QPoint(108, 289), &CMarker::depasseBas);
    mks4 << CMarker(QPoint(97, 305), &CMarker::depasseBas);
    mks4 << CMarker(QPoint(86, 322), &CMarker::depasseBas);
    mks4 << CMarker(QPoint(75, 339), &CMarker::depasseBas);
    mks4 << CMarker(QPoint(66, 356), &CMarker::depasseBas);
    mks4 << CMarker(QPoint(57, 374), &CMarker::depasseBas);
    mks4 << CMarker(QPoint(51, 393), &CMarker::depasseBas);
    mks4 << CMarker(QPoint(47, 412), &CMarker::depasseBas);
    mks4 << CMarker(QPoint(48, 431), &CMarker::depasseBas);
    mks4 << CMarker(QPoint(59, 447), &CMarker::depasseBas);
    mks4 << CMarker(QPoint(77, 454), &CMarker::depasseDroite);
    mks4 << CMarker(QPoint(96, 454), &CMarker::depasseDroite);
    mks4 << CMarker(QPoint(123, 452), &CMarker::depasseDroite);

    this->wCircuit = wCircuit;

    populationInited = false;

    circuits[0] = CCircuit(QPoint(311, 24), 0, ":/circuits/circuit1.png");
    circuits[1] = CCircuit(QPoint(358, 44), 0, ":/circuits/circuit2.png");
    circuits[2] = CCircuit(QPoint(130, 152), PI2, ":/circuits/circuit3.png");
    circuits[3] = CCircuit(QPoint(123, 452), PI, ":/circuits/circuit4.png");

    circuits[0].setMarkers(mks1);
    circuits[1].setMarkers(mks2);
    circuits[2].setMarkers(mks3);
    circuits[3].setMarkers(mks4);

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
        bool fini = y < 0 || y > 500 || circuits[currentCircuit].getImage().pixel(x, y) == 0xFF000000;
        
        while(!fini) {
            y += sens;

            fini = y < 0 || y > 500 || circuits[currentCircuit].getImage().pixel(x, y) == 0xFF000000;
        }
    } else {
        double a = tan(angle);
        double b = y - a * x;
        int sens = oppose.x() > p.x() ? -1 : 1;
        bool fini = x < 0 || x > 500 || y < 0 || y > 500 || circuits[currentCircuit].getImage().pixel(x, y) == 0xFF000000;
        
        while(!fini) {
            x += sens;
            y = a * x + b;

            fini = x < 0 || x > 500 || y < 0 || y > 500 || circuits[currentCircuit].getImage().pixel(x, y) == 0xFF000000;
        }
    }

    x = CCircuit::normCoordonnees(x);
    y = CCircuit::normCoordonnees(y);

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

void CGenetic::run(void) {
    int i = 0;
	
	srand(time(NULL));
		
	initPopulation();

    setCircuit(0);

    do {
        calculScores();
        triPopulation();
        croisePopuplation();

        setCircuit((currentCircuit + 1) % NB_CIRCUIT);
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
    int nbIter = 0;
    
    while(nbAlive != 0 && nbIter < 400) {
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

                population[i]->setInputs(inputs);

                population[i]->move();

                nbDehors += circuits[currentCircuit].getImage().pixel(posRoue[0]) == 0xFF000000 ? 1 : 0;
                nbDehors += circuits[currentCircuit].getImage().pixel(posRoue[1]) == 0xFF000000 ? 1 : 0;
                nbDehors += circuits[currentCircuit].getImage().pixel(posRoue[2]) == 0xFF000000 ? 1 : 0;
                nbDehors += circuits[currentCircuit].getImage().pixel(posRoue[3]) == 0xFF000000 ? 1 : 0;

                population[i]->setAlive(nbDehors < 2);
                nbAlive -= nbDehors < 2 ? 0 : 1;
            }
        }

        emit repaintRequested();
        msleep(1000 / 24);

        nbIter++;
    }
}

void CGenetic::onWCircuitDrawVoitures(QPainter *painter) {
    drawPopulation(painter);
}
