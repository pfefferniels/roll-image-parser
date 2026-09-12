//
// Programmer:    Craig Stuart Sapp <craig@ccrma.stanford.edu>
// Creation Date: Thu Dec  7 21:46:42 PST 2017
// Last Modified: Mon Mar 25 22:38:36 PDT 2019
// Filename:      RollOptions.cpp
// Web Address:
// Syntax:        C++
// vim:           ts=3:nowrap:ft=text
//
// Description:   Options for parsing images of piano rolls.
//

#include "RollOptions.h"

using namespace std;

namespace rip  {


//////////////////////////////
//
// RollOptions::RollOptions --
//

RollOptions::RollOptions(void) {
	reset();
}



//////////////////////////////
//
// RollOptions::~RollOptions --
//

RollOptions::~RollOptions() {
	// do nothing
}



//////////////////////////////
//
// RollOptions::reset -- Set to default parameters.
//

void RollOptions::reset(void) {
	m_minTrackerSpacingToPaperEdge = 0.50;
	m_maxHoleWidth                 = 1.50; // wide for rewind hole of duoart salesman
	m_aspectRatioThreshold         = 1.25;
	m_majorAxisThreshold           = 13.0;
	m_circularityThreshold         =  0.4;
	m_maxHoleCount                 = 100000;
	m_maxTearFill                  = 100000;
	m_attackLineSpacing            = 10;
	m_holeShiftCutoff              = 3.0;
};



//////////////////////////////
//
// RollOptions::getAspectRatioThreshold --
//

double RollOptions::getAspectRatioThreshold(void) {
	return m_aspectRatioThreshold;
}



//////////////////////////////
//
// RollOptions::getAspectRatioThreshold --
//

void RollOptions::setAspectRatioThreshold(double value) {
	m_aspectRatioThreshold = value;
}



//////////////////////////////
//
// RollOptions::getMaxHoleTrackerWidth --
//

double RollOptions::getMaxHoleTrackerWidth(void) {
	return m_maxHoleWidth;
}



//////////////////////////////
//
// RollOptions::setMaxHoleTrackerWidth --
//

void RollOptions::setMaxHoleTrackerWidth(double value) {
		m_maxHoleWidth = value;
}



//////////////////////////////
//
// RollOptions::getMinTrackerEdge --
//

double RollOptions::getMinTrackerEdge(void) {
	return m_minTrackerSpacingToPaperEdge;
}



//////////////////////////////
//
// RollOptions::setMinTrackerEdge --
//

void RollOptions::setMinTrackerEdge(double value) {
		m_minTrackerSpacingToPaperEdge = value;
}



//////////////////////////////
//
// RollOptions::getMinTrackerEdge --
//

double RollOptions::getMajorAxisCutoff(void) {
	return m_majorAxisThreshold;
}



//////////////////////////////
//
// RollOptions::setMinTrackerEdge --
//


void RollOptions::setMajorAxisCutoff(double value) {
	m_majorAxisThreshold = value;
}



//////////////////////////////
//
// RollOptions::getCircularityThreshold --
//

double RollOptions::getCircularityThreshold(void) {
	return m_circularityThreshold;
}



//////////////////////////////
//
// RollOptions::setCircularityThreshold --
//

void RollOptions::setCircularityThreshold(double value) {
	m_circularityThreshold = value;
}



//////////////////////////////
//
// RollOptions::getMaxHoleCount --
//

int RollOptions::getMaxHoleCount(void) {
	return m_maxHoleCount;
}



//////////////////////////////
//
// RollOptions::setMaxHoleCount --
//

void RollOptions::setMaxHoleCount(int value) {
	m_maxHoleCount = value;
}



//////////////////////////////
//
// RollOptions::getMaxTearFill --
//

int RollOptions::getMaxTearFill(void) {
	return m_maxTearFill;
}



//////////////////////////////
//
// RollOptions::setMaxTearFill --
//

void RollOptions::setMaxTearFill(int value) {
	m_maxTearFill = value;
}



//////////////////////////////
//
// RollOptions::getAttackLineSpacing --
//

int RollOptions::getAttackLineSpacing(void) {
	return m_attackLineSpacing;
}



//////////////////////////////
//
// RollOptions::setAttackLineSpacing --
//

void RollOptions::setAttackLineSpacing(int value) {
	m_attackLineSpacing = value;
}



//////////////////////////////
//
// RollOptions::getHoleShiftCutoff --
//

double RollOptions::getHoleShiftCutoff(void) {
	return m_holeShiftCutoff;
}



//////////////////////////////
//
// RollOptions::setHoleShiftCutoff --
//

void RollOptions::setHoleShiftCutoff(double value) {
	m_holeShiftCutoff = value;
}



//////////////////////////////
//
// RollOptions::getRollType -- Return the roll type being processed:
//   "" = unknown/unspecified
//   "welte-red"      = Welte Mignon T-100 red roll
//   "welte-green"    = Welte Mignon T-98 green roll
//   "welte-licensee" = Welte Mignon (Deluxe) Licensee
//   "ampico"         = AMPICO roll (variation not specified)
//   "ampico-a"       = AMPICO roll, earlier model
//   "ampico-b"       = AMPICO roll, later model
//   "duoart"         = Aeolean Duo-Art
//   "65-note"        = 64-note roll (6 holes/inch)
//   "88-note"        = 88-note roll standard (9 holes/inch)
//

std::string RollOptions::getRollType(void) {
	return m_rollType;
}



//////////////////////////////
//
// RollOptions::setRollTypeRedWelte -- Apply settings suitable for Red Welte (T-100) piano rolls.
//
// red Welte tracker holes:
//
//   10 expression on bass side:
//       1:  MF-Off                          MIDI Key 14
//       2:  MF-On                           MIDI Key 15
//       3:  Crescendo-Off                   MIDI Key 16
//       4:  Crescendo-On                    MIDI Key 17
//       5:  Forzando-Off                    MIDI Key 18
//       6:  Forzando-On                     MIDI Key 19
//       7:  Soft-Pedal-Off                  MIDI Key 20
//       8:  Soft-Pedal-On                   MIDI Key 21
//       9:  Motor-Off                       MIDI Key 22
//       10: Motor-On                        MIDI Key 23
//   Then 80 notes from C1 to G7 (MIDI notes 24 to 103)
//       11: C1                              MIDI Key 24
//       ...
//       53:  F#4                            MIDI Key 66
//    Treble register (note bass register has more notes):
//       54:  G4                             MIDI Key 67
//       ...
//       90:  G7                             MIDI Key 103
//   10 expression holes on the treble side:
//       91:  -10: Rewind                    MIDI Key 104
//       92:  -9:  Electric-Cutoff           MIDI Key 105
//       93:  -8:  Sustain-Pedal-On          MIDI Key 106
//       94:  -7:  Sustain-Pedal-Off         MIDI Key 107
//       95:  -6:  Forzando-On               MIDI Key 108
//       96:  -5:  Forzando-Off              MIDI Key 109
//       97:  -4:  Crescendo-On              MIDI Key 110
//       98:  -3:  Crescendo-Off             MIDI Key 111
//       99:  -2:  Mezzo-Forte-On            MIDI Key 112
//       100: -1:  Mezzo-Forte-Off           MIDI Key 113
//
//

void RollOptions::setRollTypeRedWelte(void) {
	m_rollType = "welte-red";
	m_minTrackerSpacingToPaperEdge = 1.6;
	m_rewindHole = 91;  // 91st hole from left (bass)
	m_rewindHoleMidi = 104;
	m_trackerHoles = 100;

	m_bass_midi = 14;   // first MIDI Note on bass side of paper
	m_treble_midi = 113; // first MIDI Note on treble side of paper

	m_bassExpressionTrackStartNumberLeft = 1;
	m_bassExpressionTrackStartMidi = 14;
	m_bassNotesTrackStartNumberLeft = 11;
	m_bassNotesTrackStartMidi = 24;
	m_trebleNotesTrackStartNumberLeft = 54;
	m_trebleNotesTrackStartMidi = 67;
	m_trebleExpressionTrackStartNumberLeft = 91;
	m_trebleExpressionTrackStartMidi = 104;

	hasExpressionMidiFileSetup();
}



//////////////////////////////
//
// RollOptions::setRollTypeGreenWelte -- Apply settings suitable for Green Welte (T-98) piano rolls.
//
// Sources: M. Welte & Soehne, Freiburg, Welte-Mignon Skala-Rolle 98
// (Gebrauchsanweisung, c. 1925), section 10, and the same firm's Technische
// Beschreibung, pp. 15-18, for the pedals and the rewind; Kirk Russell, "Red
// Welte, Green Welte & Welte Licensee Pianos", Mechanical Music Digest
// 2010.11.25.01, for the expression holes.  Peter Phillips's dissertation
// (https://ses.library.usyd.edu.au/bitstream/2123/16939/1/Piano%20Rolls.pdf)
// gives the compass and the paper speed but no hole-by-hole scale, and says
// nothing about a rewind hole.
//
// green Welte tracker holes:
//
//   5 expression holes on bass side:
//       1:  Bass Sforzando piano (& rewind) MIDI Key 16
//       2:  Bass Mezzoforte                 MIDI Key 17
//       3:  Sustain pedal                   MIDI Key 18
//       4:  Bass Crescendo                  MIDI Key 19
//       5:  Bass Sforzando forte            MIDI Key 20
//   Then 88 notes from C0 to C8 (MIDI notes 21 to 108) (but actually only 80 used)
//       6: A0                               MIDI Key 21
//       ...
//       51:  F#4                            MIDI Key 66
//    Treble register:
//       52:  G4                             MIDI Key 67
//       ...
//       93:  C8                             MIDI Key 108
//   5 expression holes on the treble side:
//       94:  -5:  Treble Sforzando forte    MIDI Key 109
//       95:  -4:  Treble Crescendo          MIDI Key 110
//       96:  -3:  Soft pedal                MIDI Key 111
//       97:  -2:  Treble Mezzoforte         MIDI Key 112
//       98:  -1:  Treble Sforzando piano    MIDI Key 113
//

// The paper is 11 1/4 inches wide and carries 98 tracks at 9 to the inch, which
// puts the outermost track (11.25 - 97/9) / 2 inches in from either edge, or
// 2.125 spacings.  Measurement on four scans agrees: Julian Dyer's roll 225
// gives 2.08 and 2.09 on the two sides, and three Stanford scans of two Condon
// rolls give per-side figures from 2.07 to 2.33.  Most of that spread is how the
// soft margin is split rather than the rolls -- one test roll scanned twice gives
// 2.07 and 2.28 -- and the rest is paper measuring 11.24 to 11.28 inches wide.
// analyzeMidiKeyMapping snaps to the nearest tracker position, so it needs this
// only to half a spacing, and every measurement is inside a quarter of one.  That
// tolerance matters here because the rewind cannot serve as a fallback check
// (see below).

void RollOptions::setRollTypeGreenWelte(void) {
	m_rollType = "welte-green";
	m_minTrackerSpacingToPaperEdge = 2.125;

	// Hole 1 rewinds the roll, by the same valve that plays Bass Forzando
	// piano: Welte's own booklet distinguishes the two by length alone, short
	// perforations for the expression and one very long one for the rewind, and
	// gives the bellows enough dead travel that a short one cannot trip it.
	// So there is no rewind hole in the sense assignMidiKeyNumbersToHoles wants
	// -- one that carries nothing until the end of the roll -- and setting the
	// MIDI key here would make that check align the tracker grid to hole 1's
	// first Forzando punch instead.  The T-98 also has no electric cutoff: the
	// machine stops on a notch in the take-up spool.
	m_rewindHole = 1;
	m_rewindHoleMidi = 0;
	m_trackerHoles = 98;

	m_bass_midi = 16;   // first MIDI Note on bass side of paper
	m_treble_midi = 113; // first MIDI Note on treble side of paper

	m_bassExpressionTrackStartNumberLeft = 1;
	m_bassExpressionTrackStartMidi = 16;
	m_bassNotesTrackStartNumberLeft = 6;
	m_bassNotesTrackStartMidi = 21;

	m_trebleNotesTrackStartNumberLeft = 52;
	m_trebleNotesTrackStartMidi = 67;

	m_trebleExpressionTrackStartNumberLeft = 94;
	m_trebleExpressionTrackStartMidi = 109;

	// m_tempo_additive_acceleration_per_foot keeps Stahnke's red-Welte 0.22 for
	// want of a green figure.  It should not simply carry over: the take-up
	// spool is the narrower of the two, about 1.9 against 2.7 inches, so each
	// wrap of paper changes its radius by more and the roll ought to speed up
	// faster over its length.
	hasExpressionMidiFileSetup();
}


//////////////////////////////
//
// RollOptions::setRollTypeLicensee -- Apply settings suitable for Welte-Mignon
// (Deluxe) Licensee piano rolls, the American re-cut of the T-100.
//
// Sources: Hagmann, Das Welte-Mignon-Klavier, p. 40 f., and Peter Phillips's
// dissertation p. 123 for the scale; Phillips, Table 4.3, for what separates
// the Licensee from the green Welte, which is the lock-and-cancel coding
// rather than the track count.  The layout is the one Stanford's midi2exp
// reads.
//
// The paper is 11 1/4 inches wide with 98 tracks at nine to the inch, so the
// geometry is the green Welte's and m_minTrackerSpacingToPaperEdge is the same
// (11.25 - 97/9) / 2 inches, or 2.125 spacings.  The coding is the red Welte's:
// the Licensee reads the same commands and lays them out the same way, minus
// the two motor tracks, so the note block and the treble valves sit two
// positions lower than on the T-100.
//
// Licensee tracker holes:
//
//   8 expression holes on the bass side:
//       1:  Mezzoforte-Off                 MIDI Key 16
//       2:  Mezzoforte-On                  MIDI Key 17
//       3:  Crescendo-Off                  MIDI Key 18
//       4:  Crescendo-On                   MIDI Key 19
//       5:  Forzando-Off                   MIDI Key 20
//       6:  Forzando-On                    MIDI Key 21
//       7:  Soft-Pedal-Off                 MIDI Key 22
//       8:  Soft-Pedal-On                  MIDI Key 23
//   Then 80 notes from C1 to G7 (MIDI notes 24 to 103):
//       9:  C1                             MIDI Key 24
//       ...
//       51: F#4                            MIDI Key 66
//    Treble register:
//       52: G4                             MIDI Key 67
//       ...
//       88: G7                             MIDI Key 103
//   10 expression holes on the treble side:
//       89: Rewind                         MIDI Key 104
//       90: Electric-Cutoff                MIDI Key 105
//       91: Sustain-Pedal-On               MIDI Key 106
//       92: Sustain-Pedal-Off              MIDI Key 107
//       93: Forzando-On                    MIDI Key 108
//       94: Forzando-Off                   MIDI Key 109
//       95: Crescendo-On                   MIDI Key 110
//       96: Crescendo-Off                  MIDI Key 111
//       97: Mezzoforte-On                  MIDI Key 112
//       98: Mezzoforte-Off                 MIDI Key 113
//
// Spencer Chase's scan of roll 225 (Schumann, Traeumerei, Gruenfeld) agrees
// valve by valve: the occupied tracks are 2-6 and 89, 91, 92, 95, 96, with
// Crescendo on/off matched at 87 and 86 punches, Forzando at 18 and 19,
// Sustain at 55 and 53, treble Crescendo at 83 and 85, and one 1.5 inch
// perforation on track 89, sixteen inches past the last note.
//
// Unlike the green Welte, the Licensee has a rewind track of its own, so
// assignMidiKeyNumbersToHoles can use it as the red Welte does.

void RollOptions::setRollTypeLicensee(void) {
	m_rollType = "welte-licensee";
	m_minTrackerSpacingToPaperEdge = 2.125;

	m_rewindHole = 89;  // 89th hole from left (bass)
	m_rewindHoleMidi = 104;
	m_trackerHoles = 98;

	m_bass_midi = 16;    // first MIDI Note on bass side of paper
	m_treble_midi = 113; // first MIDI Note on treble side of paper

	m_bassExpressionTrackStartNumberLeft = 1;
	m_bassExpressionTrackStartMidi = 16;
	m_bassNotesTrackStartNumberLeft = 9;
	m_bassNotesTrackStartMidi = 24;
	m_trebleNotesTrackStartNumberLeft = 52;
	m_trebleNotesTrackStartMidi = 67;
	m_trebleExpressionTrackStartNumberLeft = 89;
	m_trebleExpressionTrackStartMidi = 104;

	hasExpressionMidiFileSetup();
}



// Duo-Art register break at D#4/E4

// Ampico register break at E4/F4

//////////////////////////////
//
// RollOptions::setRollType65Note -- Apply settings suitable for 65-note piano rolls.
//   * Aeolian "universal"
//   * 11.125" width
//   * 6 holes to the inch
//   * 4.23 mm /hole
//   * First bass hole centered about 107 pixels @ 300 DPI from bass edge.
//   * First treble hole centered about 98 pixels @ 300 DPI from bass edge.
//   * Punch widths about 31 pixels at 300 DPI.
//   * Paper width 3406 @ 300 DPI = 11.35 inches
//   * about 50 pixels between tracker bar holes
//   * Lowest note A1 (MIDI note 33)
//   * Highest note C#7 (MIDI note 97)
//   * No sustain pedal
//
//

void RollOptions::setRollType65Note(void) {
	m_rollType = "65-note";
	m_bridgeFactor  = 1.25;
	m_minTrackerSpacingToPaperEdge = 2.0;
	m_rewindHole = 0;  // no rewind hole
	m_rewindHoleMidi = 0;
	m_trackerHoles = 65;

	m_bass_midi   = 33; // first MIDI note/expression on bass side of paper
	m_treble_midi = 97; // first MIDI note/expression on treble side of paper

	// no bass expression
	m_bassExpressionTrackStartNumberLeft = 0;
	m_bassExpressionTrackStartMidi = 0;
	m_bassNotesTrackStartNumberLeft = 0;
	m_bassNotesTrackStartMidi = 0;

	// no treble expression
	m_trebleNotesTrackStartNumberLeft = 0;
	m_trebleNotesTrackStartMidi = 0;
	m_trebleExpressionTrackStartNumberLeft = 0;
	m_trebleExpressionTrackStartMidi = 0;

	hasNoExpressionMidiFileSetup();
}



//////////////////////////////
//
// RollOptions::setRollType88Note -- Apply settings suitable for 88-note piano rolls.
//   * Introduced in 1900
//   * United States standardized to 88 note scale in 1909
//   * 9 holes/inch
//   * 100 positions with 6 mostly empty slots on each edge (for expression)
//   * Pedal is at position 4, which is MIDI note 18
//   * 88 notes are A0 (MIDI 21) at position 7 though C7 (MIDI 108) at position 94.
//   * The notes are evenly centered on the roll, with the middle of the 88 notes
//     occurring at the middle of the paper (E4 is last note on bass half of paper,
//     and F4 is first note on treble half of paper.
//
//   Position     MIDI    Meaning
//   ==============================
//       1        15      unused
//       2        16      unused, sometimes rewind hole
//       3        17      unused
//       4        18      sustain pedal
//       5        19      unused
//       6        20      unused
//       7        21      A0
//       ...
//       50       64      E4  Pretend Bass register
//       -------------------------
//       51       65      F4  Pretend Treble register
//       ...
//       94      108      C7
//       95      109      unused
//       96      110      unused
//       97      111      unused
//       98      112      unused
//       99      113      unused
//      100      114      unused
//

void RollOptions::setRollType88Note(void) {
	m_rollType = "88-note";
	m_bridgeFactor  = 0.85;
	m_minTrackerSpacingToPaperEdge = 1.6;
	m_rewindHole = 0;  // no rewind hole (but can be at position 2, MIDI 16)
	m_rewindHoleMidi = 0;
	m_trackerHoles = 100;

	// m_bass_midi == first MIDI note/expression on bass side of paper.
	// This is the first tracker bar position on the roll (left side,
	// or bass side).
	m_bass_midi   = 15;  

	// m_treble_midi == first MIDI note/expression on the treble side of the paper.
	// This is the last tracker bar position on the roll (right side, or
	// treble side).
	m_treble_midi = 114; // first MIDI note/expression on treble side of paper

	// bass expression (not really used except for pedal)
	m_bassExpressionTrackStartNumberLeft = 1;
	m_bassExpressionTrackStartMidi = 15;
	m_bassNotesTrackStartNumberLeft = 7;
	m_bassNotesTrackStartMidi = 21;

	// treble expression (not used)
	m_trebleNotesTrackStartNumberLeft = 51;
	m_trebleNotesTrackStartMidi = 65;
	m_trebleExpressionTrackStartNumberLeft = 95;
	m_trebleExpressionTrackStartMidi = 109;

	hasNoExpressionMidiFileSetup();
}



/////////////////////////////////
//
// RollOptions::getRewindHoleNumber(void) -- returns 0 if unknown.
//

int RollOptions::getRewindHoleBassNumber(void) {
	return m_rewindHole;
}



/////////////////////////////////
//
// RollOptions::getRewindHoleLeftIndex(void) -- returns 0 if unknown.
//

int RollOptions::getRewindHoleBassIndex(void) {
	return m_rewindHole - 1;
}



/////////////////////////////////
//
// RollOptions::getRewindHoleMidi(void) -- returns 0 if unknown; otherwise,
//     returns the MIDI note number of the rewind hole.
//

int RollOptions::getRewindHoleMidi(void) {
	return m_rewindHoleMidi;
}



/////////////////////////////////
//
// RollOptions::getBridgeFactor(void) -- Returns the ratio of width to length
//     distance which will force the merging of adjacent holes.
//

double RollOptions::getBridgeFactor(void) {
	return m_bridgeFactor;
}



//////////////////////////////
//
// RollOptions::getExpectedTrackerHoleCount -- Returns 0 if roll type is undefined.
//

int RollOptions::getExpectedTrackerHoleCount(void) {
	return m_trackerHoles;
}



//////////////////////////////
//
// RollOptions::setThreshold -- 
//

void RollOptions::setThreshold(int value) {
	m_threshold = value;
}



//////////////////////////////
//
// RollOptions::getThreshold -- 
//

int RollOptions::getThreshold(void) {
	return (ucharint)m_threshold;
}



//////////////////////////////
//
// RollOptions::hasNoExpressionMidiFileSetup -- The roll has no 
//   expression, so the output MIDI files will contain two
//   tracks: the 0th track is the tempo and metadata track with no
//   notes, and the 1st track contains all of the notes from the roll.
//

void RollOptions::hasNoExpressionMidiFileSetup(void) { 
	// MIDI file track assignments (offset from 0, with track 0 note having no notes):
	m_bass_track       = 1;
	m_treble_track     = 1;
	m_bass_exp_track   = 1;
	m_treble_exp_track = 1;

	// MIDI file channel assignments for each track, (offset from 0):
	m_bass_exp_ch      = 0;
	m_bass_ch          = 0;
	m_treble_ch        = 0;
	m_treble_exp_ch    = 0;
}



//////////////////////////////
//
// RollOptions::hasExpressionMidiFileSetup --  The roll has expression, so the output
//     MIDI files will contain two tracks: the 0th track is the tempo and metadata
//     track with no notes, the 1st track contains the bass notes, the 2nd track
//     contains the treble notes, the 3rd track contains the bass expression, and
//     the fourth track contains the treble expression.
//

void RollOptions::hasExpressionMidiFileSetup(void) {
	// MIDI file track assignments (offset from 0, with track 0 note having notes):
	m_bass_track       = 1;
	m_treble_track     = 2;
	m_bass_exp_track   = 3;
	m_treble_exp_track = 4;

	// MIDI file channel assignments for each track, (offset from 0):
	m_bass_exp_ch      = 0;
	m_bass_ch          = 1;
	m_treble_ch        = 2;
	m_treble_exp_ch    = 3;
}



} // end rip namespace



