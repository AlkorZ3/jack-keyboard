/*-
 * Copyright (c) 2007, 2008 Edward Tomasz Napierała <trasz@FreeBSD.org>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *	notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *	notice, this list of conditions and the following disclaimer in the
 *	documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#ifndef __PIANO_KEYBOARD_H__
#define __PIANO_KEYBOARD_H__

#include <glib.h>
#include <gtk/gtkdrawingarea.h>

G_BEGIN_DECLS

#define TYPE_PIANO_KEYBOARD			(piano_keyboard_get_type ())
#define PIANO_KEYBOARD(obj)			(G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_PIANO_KEYBOARD, PianoKeyboard))
#define PIANO_KEYBOARD_CLASS(klass)		(G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_PIANO_KEYBOARD, PianoKeyboardClass))
#define IS_PIANO_KEYBOARD(obj)			(G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_PIANO_KEYBOARD))
#define IS_PIANO_KEYBOARD_CLASS(klass)		(G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_PIANO_KEYBOARD))
#define PIANO_KEYBOARD_GET_CLASS(obj)		(G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_PIANO_KEYBOARD, PianoKeyboardClass))

typedef struct	_PianoKeyboard			PianoKeyboard;
typedef struct	_PianoKeyboardClass		PianoKeyboardClass;

/* A note about note numbers:

 0   = C-1     (midi minmum)
 21  = A0      (piano minimum)
 60  = C4      (middle C)
 108 = C7      (piano maximum)
 127 = G9      (midi maximum)
*/
#define NNOTES			128
#define PIANO_MIN_NOTE		21
#define PIANO_MAX_NOTE		108

#define OCTAVE_MIN	-1
#define OCTAVE_MAX	7

struct Note {
	int			pressed;		/* 1 if key is in pressed down state. */
	int			sustained;		/* 1 if note is sustained. */
	int			x;			/* Distance between the left edge of the key
							 * and the left edge of the widget, in pixels. */
	int			w;			/* Width of the key, in pixels. */
	int			h;			/* Height of the key, in pixels. */
	int			white;			/* 1 if key is white; 0 otherwise. */
	int			velocity;
};

struct _PianoKeyboard
{
	GtkDrawingArea		da;
	int			maybe_stop_sustained_notes;
	int			sustain_new_notes;
	int			enable_keyboard_cue;
	int			octave;
	int			widget_margin;
	int			note_being_pressed_using_mouse;
	int			min_note;
	int			max_note;
	int			current_velocity;
	volatile struct Note 	notes[NNOTES];
	/* Table used to translate from PC keyboard character to MIDI note number. */
	GArray			*key_bindings;
};

struct _PianoKeyboardClass
{
	GtkDrawingAreaClass	parent_class;
};

typedef struct {
	double r;
	double g;
	double b;
} rgb;

typedef struct {
	double h;
	double s;
	double v;
} hsv;

GType		piano_keyboard_get_type		(void) G_GNUC_CONST;
GtkWidget*	piano_keyboard_new		(void);
void		piano_keyboard_sustain_press	(PianoKeyboard *pk);
void		piano_keyboard_sustain_release	(PianoKeyboard *pk);
void		piano_keyboard_set_note_on	(PianoKeyboard *pk, int note, int vel);
void		piano_keyboard_set_note_off	(PianoKeyboard *pk, int note);
void		piano_keyboard_set_keyboard_cue	(PianoKeyboard *pk, int enabled);
void		piano_keyboard_set_octave (PianoKeyboard *pk, int octave);
gboolean	piano_keyboard_set_keyboard_layout (PianoKeyboard *pk, const char *layout);
void		piano_keyboard_enable_all_midi_notes(PianoKeyboard* pk);
void		piano_keyboard_draw_white_key (GtkWidget *widget, int x, int y, int w, int h, int pressed, int val);
void		piano_keyboard_draw_black_key (GtkWidget *widget, int x, int y, int w, int h, int pressed, int val);
void		piano_keyboard_draw_pressed (cairo_t *c, int x, int y, int w, int h, int val);
void		piano_keyboard_draw_key_shadow (cairo_t *c, int x, int y, int w, int h);
rgb			hsv2rgb(hsv HSV);

G_END_DECLS

#endif /* __PIANO_KEYBOARD_H__ */

