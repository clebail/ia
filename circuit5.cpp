#include <QList>
#include "CMarker.h"

void initCircuit5(QList<CMarker>& mks) {
    mks << CMarker(QPoint(611, 403), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(591, 405), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(571, 406), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(551, 408), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(531, 410), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(511, 411), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(491, 411), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(471, 408), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(452, 399), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(438, 384), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks << CMarker(QPoint(429, 365), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks << CMarker(QPoint(428, 345), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks << CMarker(QPoint(434, 326), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks << CMarker(QPoint(447, 310), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks << CMarker(QPoint(463, 298), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(479, 287), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(494, 274), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(504, 256), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks << CMarker(QPoint(505, 236), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks << CMarker(QPoint(496, 218), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks << CMarker(QPoint(480, 204), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(464, 190), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(454, 172), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks << CMarker(QPoint(451, 152), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks << CMarker(QPoint(457, 133), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks << CMarker(QPoint(471, 118), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks << CMarker(QPoint(488, 109), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(507, 105), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(526, 109), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(544, 117), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(560, 127), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(574, 140), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(587, 155), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks << CMarker(QPoint(597, 171), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks << CMarker(QPoint(606, 188), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks << CMarker(QPoint(615, 205), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks << CMarker(QPoint(623, 222), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks << CMarker(QPoint(633, 238), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks << CMarker(QPoint(646, 252), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks << CMarker(QPoint(661, 264), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(680, 270), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(699, 269), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(716, 258), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(729, 242), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks << CMarker(QPoint(739, 224), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks << CMarker(QPoint(746, 205), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks << CMarker(QPoint(752, 185), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks << CMarker(QPoint(756, 165), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks << CMarker(QPoint(758, 145), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks << CMarker(QPoint(759, 125), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks << CMarker(QPoint(757, 105), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks << CMarker(QPoint(753, 85), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks << CMarker(QPoint(745, 66), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks << CMarker(QPoint(731, 51), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks << CMarker(QPoint(713, 40), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(693, 34), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(673, 30), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(653, 28), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(633, 26), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(613, 26), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(593, 27), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(573, 27), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(553, 29), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(533, 30), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(513, 31), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(493, 32), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(473, 34), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(453, 34), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(433, 35), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(413, 36), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(393, 36), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(373, 36), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(353, 36), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(333, 36), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(313, 36), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(293, 36), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(273, 36), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(253, 36), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(233, 37), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(213, 37), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(193, 38), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(173, 39), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(153, 41), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(133, 44), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(113, 50), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(95, 59), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(80, 73), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(68, 89), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks << CMarker(QPoint(60, 107), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks << CMarker(QPoint(56, 126), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks << CMarker(QPoint(56, 145), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks << CMarker(QPoint(61, 164), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks << CMarker(QPoint(70, 181), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks << CMarker(QPoint(83, 195), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks << CMarker(QPoint(99, 205), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(117, 212), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(136, 215), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(155, 217), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(174, 219), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(193, 220), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(212, 221), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(231, 222), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(250, 223), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(269, 225), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(288, 228), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(307, 233), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(324, 242), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(337, 256), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks << CMarker(QPoint(346, 273), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks << CMarker(QPoint(352, 291), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks << CMarker(QPoint(356, 310), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks << CMarker(QPoint(358, 329), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks << CMarker(QPoint(356, 348), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks << CMarker(QPoint(349, 367), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks << CMarker(QPoint(335, 381), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(318, 392), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(301, 402), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(282, 409), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(262, 413), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(242, 415), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(222, 417), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(202, 418), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(182, 418), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(162, 419), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(142, 421), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(122, 423), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(102, 427), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(83, 433), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(66, 443), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(51, 456), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(40, 472), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks << CMarker(QPoint(34, 491), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks << CMarker(QPoint(35, 510), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks << CMarker(QPoint(42, 528), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks << CMarker(QPoint(53, 544), &CMarker::depasseBas, &CMarker::depasseHaut);
    mks << CMarker(QPoint(68, 556), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(87, 561), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(106, 562), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(125, 560), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(144, 556), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(163, 552), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(182, 548), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(201, 543), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(220, 538), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(239, 533), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(258, 528), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(277, 523), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(296, 518), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(315, 513), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(334, 509), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(353, 506), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(372, 504), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(391, 503), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(410, 504), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(429, 507), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(448, 513), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(466, 520), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(484, 528), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(502, 536), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(520, 544), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(538, 551), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(557, 556), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(576, 560), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(595, 562), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(614, 564), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(633, 565), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(652, 565), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(671, 564), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(690, 562), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(709, 558), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(727, 549), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(741, 535), &CMarker::depasseDroite, &CMarker::depasseGauche);
    mks << CMarker(QPoint(751, 517), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks << CMarker(QPoint(757, 497), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks << CMarker(QPoint(757, 477), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks << CMarker(QPoint(751, 457), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks << CMarker(QPoint(737, 441), &CMarker::depasseHaut, &CMarker::depasseBas);
    mks << CMarker(QPoint(720, 429), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(702, 419), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(683, 411), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(663, 406), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(643, 403), &CMarker::depasseGauche, &CMarker::depasseDroite);
    mks << CMarker(QPoint(631, 402), &CMarker::depasseGauche, &CMarker::depasseDroite);
}
