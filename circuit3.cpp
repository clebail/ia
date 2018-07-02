#include <QList>
#include "CMarker.h"

void initCicuit3(QList<CMarker>& mks) {
	mks << CMarker(QPoint(632, 373), &CMarker::depasseGauche, &CMarker::depasseDroite);
	mks << CMarker(QPoint(612, 376), &CMarker::depasseGauche, &CMarker::depasseDroite);
	mks << CMarker(QPoint(592, 379), &CMarker::depasseGauche, &CMarker::depasseDroite);
	mks << CMarker(QPoint(572, 383), &CMarker::depasseGauche, &CMarker::depasseDroite);
	mks << CMarker(QPoint(552, 387), &CMarker::depasseGauche, &CMarker::depasseDroite);
	mks << CMarker(QPoint(532, 391), &CMarker::depasseGauche, &CMarker::depasseDroite);
	mks << CMarker(QPoint(512, 395), &CMarker::depasseGauche, &CMarker::depasseDroite);
	mks << CMarker(QPoint(492, 397), &CMarker::depasseGauche, &CMarker::depasseDroite);
	mks << CMarker(QPoint(472, 398), &CMarker::depasseGauche, &CMarker::depasseDroite);
	mks << CMarker(QPoint(452, 397), &CMarker::depasseGauche, &CMarker::depasseDroite);
	mks << CMarker(QPoint(432, 392), &CMarker::depasseGauche, &CMarker::depasseDroite);
	mks << CMarker(QPoint(414, 383), &CMarker::depasseGauche, &CMarker::depasseDroite);
	mks << CMarker(QPoint(399, 369), &CMarker::depasseGauche, &CMarker::depasseDroite);
	mks << CMarker(QPoint(387, 352), &CMarker::depasseHaut, &CMarker::depasseBas);
	mks << CMarker(QPoint(378, 333), &CMarker::depasseHaut, &CMarker::depasseBas);
	mks << CMarker(QPoint(371, 314), &CMarker::depasseHaut, &CMarker::depasseBas);
	mks << CMarker(QPoint(364, 295), &CMarker::depasseHaut, &CMarker::depasseBas);
	mks << CMarker(QPoint(353, 277), &CMarker::depasseHaut, &CMarker::depasseBas);
	mks << CMarker(QPoint(341, 260), &CMarker::depasseHaut, &CMarker::depasseBas);
	mks << CMarker(QPoint(329, 243), &CMarker::depasseHaut, &CMarker::depasseBas);
	mks << CMarker(QPoint(324, 223), &CMarker::depasseHaut, &CMarker::depasseBas);
	mks << CMarker(QPoint(327, 203), &CMarker::depasseHaut, &CMarker::depasseBas);
	mks << CMarker(QPoint(335, 184), &CMarker::depasseHaut, &CMarker::depasseBas);
	mks << CMarker(QPoint(345, 166), &CMarker::depasseHaut, &CMarker::depasseBas);
	mks << CMarker(QPoint(354, 148), &CMarker::depasseHaut, &CMarker::depasseBas);
	mks << CMarker(QPoint(362, 129), &CMarker::depasseHaut, &CMarker::depasseBas);
	mks << CMarker(QPoint(366, 109), &CMarker::depasseHaut, &CMarker::depasseBas);
	mks << CMarker(QPoint(360, 89), &CMarker::depasseHaut, &CMarker::depasseBas);
	mks << CMarker(QPoint(344, 75), &CMarker::depasseGauche, &CMarker::depasseDroite);
	mks << CMarker(QPoint(324, 72), &CMarker::depasseGauche, &CMarker::depasseDroite);
	mks << CMarker(QPoint(304, 75), &CMarker::depasseGauche, &CMarker::depasseDroite);
	mks << CMarker(QPoint(285, 82), &CMarker::depasseGauche, &CMarker::depasseDroite);
	mks << CMarker(QPoint(267, 90), &CMarker::depasseGauche, &CMarker::depasseDroite);
	mks << CMarker(QPoint(249, 98), &CMarker::depasseGauche, &CMarker::depasseDroite);
	mks << CMarker(QPoint(230, 104), &CMarker::depasseGauche, &CMarker::depasseDroite);
	mks << CMarker(QPoint(210, 106), &CMarker::depasseGauche, &CMarker::depasseDroite);
	mks << CMarker(QPoint(192, 97), &CMarker::depasseGauche, &CMarker::depasseDroite);
	mks << CMarker(QPoint(178, 82), &CMarker::depasseHaut, &CMarker::depasseBas);
	mks << CMarker(QPoint(167, 65), &CMarker::depasseHaut, &CMarker::depasseBas);
	mks << CMarker(QPoint(155, 48), &CMarker::depasseHaut, &CMarker::depasseBas);
	mks << CMarker(QPoint(138, 37), &CMarker::depasseGauche, &CMarker::depasseDroite);
	mks << CMarker(QPoint(118, 32), &CMarker::depasseGauche, &CMarker::depasseDroite);
	mks << CMarker(QPoint(98, 33), &CMarker::depasseGauche, &CMarker::depasseDroite);
	mks << CMarker(QPoint(78, 39), &CMarker::depasseGauche, &CMarker::depasseDroite);
	mks << CMarker(QPoint(65, 54), &CMarker::depasseBas, &CMarker::depasseHaut);
	mks << CMarker(QPoint(61, 73), &CMarker::depasseBas, &CMarker::depasseHaut);
	mks << CMarker(QPoint(65, 92), &CMarker::depasseBas, &CMarker::depasseHaut);
	mks << CMarker(QPoint(72, 110), &CMarker::depasseBas, &CMarker::depasseHaut);
	mks << CMarker(QPoint(77, 129), &CMarker::depasseBas, &CMarker::depasseHaut);
	mks << CMarker(QPoint(76, 148), &CMarker::depasseBas, &CMarker::depasseHaut);
	mks << CMarker(QPoint(72, 167), &CMarker::depasseBas, &CMarker::depasseHaut);
	mks << CMarker(QPoint(68, 186), &CMarker::depasseBas, &CMarker::depasseHaut);
	mks << CMarker(QPoint(65, 205), &CMarker::depasseBas, &CMarker::depasseHaut);
	mks << CMarker(QPoint(67, 224), &CMarker::depasseBas, &CMarker::depasseHaut);
	mks << CMarker(QPoint(72, 243), &CMarker::depasseBas, &CMarker::depasseHaut);
	mks << CMarker(QPoint(80, 260), &CMarker::depasseBas, &CMarker::depasseHaut);
	mks << CMarker(QPoint(88, 277), &CMarker::depasseBas, &CMarker::depasseHaut);
	mks << CMarker(QPoint(96, 294), &CMarker::depasseBas, &CMarker::depasseHaut);
	mks << CMarker(QPoint(102, 312), &CMarker::depasseBas, &CMarker::depasseHaut);
	mks << CMarker(QPoint(102, 331), &CMarker::depasseBas, &CMarker::depasseHaut);
	mks << CMarker(QPoint(97, 350), &CMarker::depasseBas, &CMarker::depasseHaut);
	mks << CMarker(QPoint(88, 368), &CMarker::depasseBas, &CMarker::depasseHaut);
	mks << CMarker(QPoint(77, 385), &CMarker::depasseBas, &CMarker::depasseHaut);
	mks << CMarker(QPoint(67, 402), &CMarker::depasseBas, &CMarker::depasseHaut);
	mks << CMarker(QPoint(57, 419), &CMarker::depasseBas, &CMarker::depasseHaut);
	mks << CMarker(QPoint(48, 436), &CMarker::depasseBas, &CMarker::depasseHaut);
	mks << CMarker(QPoint(40, 454), &CMarker::depasseBas, &CMarker::depasseHaut);
	mks << CMarker(QPoint(34, 473), &CMarker::depasseBas, &CMarker::depasseHaut);
	mks << CMarker(QPoint(30, 492), &CMarker::depasseBas, &CMarker::depasseHaut);
	mks << CMarker(QPoint(30, 511), &CMarker::depasseBas, &CMarker::depasseHaut);
	mks << CMarker(QPoint(35, 530), &CMarker::depasseBas, &CMarker::depasseHaut);
	mks << CMarker(QPoint(46, 546), &CMarker::depasseBas, &CMarker::depasseHaut);
	mks << CMarker(QPoint(63, 555), &CMarker::depasseDroite, &CMarker::depasseGauche);
	mks << CMarker(QPoint(82, 558), &CMarker::depasseDroite, &CMarker::depasseGauche);
	mks << CMarker(QPoint(101, 558), &CMarker::depasseDroite, &CMarker::depasseGauche);
	mks << CMarker(QPoint(120, 555), &CMarker::depasseDroite, &CMarker::depasseGauche);
	mks << CMarker(QPoint(139, 551), &CMarker::depasseDroite, &CMarker::depasseGauche);
	mks << CMarker(QPoint(158, 546), &CMarker::depasseDroite, &CMarker::depasseGauche);
	mks << CMarker(QPoint(177, 541), &CMarker::depasseDroite, &CMarker::depasseGauche);
	mks << CMarker(QPoint(196, 537), &CMarker::depasseDroite, &CMarker::depasseGauche);
	mks << CMarker(QPoint(215, 534), &CMarker::depasseDroite, &CMarker::depasseGauche);
	mks << CMarker(QPoint(234, 532), &CMarker::depasseDroite, &CMarker::depasseGauche);
	mks << CMarker(QPoint(253, 531), &CMarker::depasseDroite, &CMarker::depasseGauche);
	mks << CMarker(QPoint(272, 533), &CMarker::depasseDroite, &CMarker::depasseGauche);
	mks << CMarker(QPoint(291, 537), &CMarker::depasseDroite, &CMarker::depasseGauche);
	mks << CMarker(QPoint(310, 543), &CMarker::depasseDroite, &CMarker::depasseGauche);
	mks << CMarker(QPoint(329, 548), &CMarker::depasseDroite, &CMarker::depasseGauche);
	mks << CMarker(QPoint(348, 552), &CMarker::depasseDroite, &CMarker::depasseGauche);
	mks << CMarker(QPoint(367, 554), &CMarker::depasseDroite, &CMarker::depasseGauche);
	mks << CMarker(QPoint(386, 552), &CMarker::depasseDroite, &CMarker::depasseGauche);
	mks << CMarker(QPoint(405, 549), &CMarker::depasseDroite, &CMarker::depasseGauche);
	mks << CMarker(QPoint(424, 544), &CMarker::depasseDroite, &CMarker::depasseGauche);
	mks << CMarker(QPoint(443, 539), &CMarker::depasseDroite, &CMarker::depasseGauche);
	mks << CMarker(QPoint(462, 535), &CMarker::depasseDroite, &CMarker::depasseGauche);
	mks << CMarker(QPoint(481, 532), &CMarker::depasseDroite, &CMarker::depasseGauche);
	mks << CMarker(QPoint(500, 532), &CMarker::depasseDroite, &CMarker::depasseGauche);
	mks << CMarker(QPoint(519, 535), &CMarker::depasseDroite, &CMarker::depasseGauche);
	mks << CMarker(QPoint(538, 540), &CMarker::depasseDroite, &CMarker::depasseGauche);
	mks << CMarker(QPoint(557, 546), &CMarker::depasseDroite, &CMarker::depasseGauche);
	mks << CMarker(QPoint(576, 552), &CMarker::depasseDroite, &CMarker::depasseGauche);
	mks << CMarker(QPoint(595, 557), &CMarker::depasseDroite, &CMarker::depasseGauche);
	mks << CMarker(QPoint(614, 560), &CMarker::depasseDroite, &CMarker::depasseGauche);
	mks << CMarker(QPoint(633, 560), &CMarker::depasseDroite, &CMarker::depasseGauche);
	mks << CMarker(QPoint(652, 558), &CMarker::depasseDroite, &CMarker::depasseGauche);
	mks << CMarker(QPoint(671, 553), &CMarker::depasseDroite, &CMarker::depasseGauche);
	mks << CMarker(QPoint(690, 546), &CMarker::depasseDroite, &CMarker::depasseGauche);
	mks << CMarker(QPoint(708, 538), &CMarker::depasseDroite, &CMarker::depasseGauche);
	mks << CMarker(QPoint(724, 527), &CMarker::depasseDroite, &CMarker::depasseGauche);
	mks << CMarker(QPoint(740, 515), &CMarker::depasseDroite, &CMarker::depasseGauche);
	mks << CMarker(QPoint(754, 500), &CMarker::depasseHaut, &CMarker::depasseBas);
	mks << CMarker(QPoint(761, 481), &CMarker::depasseHaut, &CMarker::depasseBas);
	mks << CMarker(QPoint(757, 461), &CMarker::depasseHaut, &CMarker::depasseBas);
	mks << CMarker(QPoint(749, 442), &CMarker::depasseHaut, &CMarker::depasseBas);
	mks << CMarker(QPoint(740, 424), &CMarker::depasseHaut, &CMarker::depasseBas);
	mks << CMarker(QPoint(728, 407), &CMarker::depasseHaut, &CMarker::depasseBas);
	mks << CMarker(QPoint(713, 392), &CMarker::depasseGauche, &CMarker::depasseDroite);
	mks << CMarker(QPoint(695, 381), &CMarker::depasseGauche, &CMarker::depasseDroite);
	mks << CMarker(QPoint(675, 374), &CMarker::depasseGauche, &CMarker::depasseDroite);
	mks << CMarker(QPoint(652, 372), &CMarker::depasseGauche, &CMarker::depasseDroite);
}