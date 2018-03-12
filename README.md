# jack-keyboard

![Screenshot of jack-keyboard](jack_keyboard.png)

## What is it?

jack-keyboard is a virtual MIDI keyboard - a program that allows you to
send JACK MIDI events (play ;-) using your PC keyboard.  It's  somewhat
similar  to  vkeybd,  except it uses JACK MIDI instead of ALSA, and the
keyboard mapping is much better - it uses the same layout  as  trackers
(like Impulse Tracker) did, so you have two and half octaves under your
fingers.

## How to compile it?

If you're using FreeBSD, install from ports - audio/jack-keyboard.

Otherwise, you need JACK with MIDI support, gtk+ 2.6 or higher,
make(1), gcc and all the standard headers.  Untar the file, type
'make install' and that's it.  If there is any problem, drop me
an email (trasz@FreeBSD.org) and I will help you.  Really.

## How to use it?

You need JACK with MIDI support and some softsynth that accepts
JACK MIDI as input.  Ghostess, http://home.jps.net/~musound/,
is a good choice.  Of course you will also need some DSSI plugin
that will make the actual sound.  WhySynth is nice.

When you have all of these installed: first, run jackd.  Then run
ghostess with a plugin of choice.  Then run jack-keyboard.  Press
'z' key.  You should hear sound.

## Keyboard

Keyboard mapping is the same as in Impulse Tracker.  This is your
QWERTY keyboard:

       +----+----+    +----+----+----+    +----+----+
       | 2  | 3  |    | 5  | 6  | 7  |    | 9  | 0  |
    +----+----+----+----+----+----+----+----+----+----+
    | q  | w  | e  | r  | t  | y  | u  | i  | o  | p  |
    +----+----+----+----+----+----+----+----+----+----+
           | s  | d  |    | g  | h  | j  |
        +----+----+----+----+----+----+----+
        | z  | x  | c  | v  | b  | n  | m  |
        +----+----+----+----+----+----+----+

And this is MIDI mapping.

       +----+----+    +----+----+----+    +----+----+
       |C#5 |D#5 |    |F#5 |G#5 |A#5 |    |C#6 |D#6 |
    +----+----+----+----+----+----+----+----+----+----+
    | C5 | D5 | E5 | F5 | G5 | A5 | B5 | C6 | D6 | E6 |
    +----+----+----+----+----+----+----+----+----+----+
           |C#4 |D#4 |    |F#4 |G#4 |A#4 |
        +----+----+----+----+----+----+----+
        | C4 | D4 | E4 | F4 | G4 | A4 | B4 |
        +----+----+----+----+----+----+----+

Spacebar  is  a sustain key.  Holding it when pressing or releasing key
will make that key sustained, i.e. Note Off MIDI event  won't  be  sent
after  releasing  the  key.  To release (stop) all the sustained notes,
press and release spacebar.

Holding Shift when pressing note will  make  it  louder  (it  increases
velocity).   Holding  Ctrl  will  do  the opposite.  You can change the
default velocity by moving the Velocity slider.   You  can  change  the
"high"  and  "low"  velocity  values by moving the slider while holding
Shift or Ctrl keys.

Pressing "-" and "+" keys on numeric keypad  changes  the  octave  your
keyboard  is mapped to.  Pressing "*" and "/" on numeric keypad changes
MIDI program (instrument).  Pressing Insert or Delete keys will connect
jack-keyboard  to  the  next/previous  MIDI  input  port (it will cycle
between running instances of ghostess, for example).  Home and End keys
change  the  MIDI  channel.  Page Up and Page Down keys switch the MIDI
bank.

Esc works as a panic key - when you press it, all sound stops.

## Setting channel/bank/program number directly

To switch directly to a channel, bank or program, enter its  number  on
the numeric keypad (it won't be shown in any way) and press Home or End
(to change channel), Page Up or Page Down (to change bank)  or  "/"  or
"*" (to change program).  For example, to change to program number 123,
type, on the numeric keypad, "123/", without quotes.

## Titlebar

When -G xor -T is given, some informational messages in the  title  bar
appear.  They  are  supposed  to  be  self  explanatory.   If  you  see
"bank/program change not sent", it means that the bank/program  numbers
as  seen  in  the  title  bar were not sent.  In other words, synth the
jack-keyboard is connected to may use different values.   This  happens
at  startup  and  after  switching  between synths (using Insert/Delete
keys).  To send bank/program change at startup, use -b and  -p  parame-
ters.   To  automatically send bank/program change after reconnect, use
the -u option.

## Pianola mode

In addition to the MIDI output  port,  jack-keyboard  also  opens  MIDI
input  (listening)  port.   MIDI  events  going  into this port will be
passed to the output port unmodified, except for channel number,  which
will be set to the one jack-keyboard is configured to use.  Note On and
Note Off MIDI events will cause visible effect (pressing and releasing)
on  keys, just like if they were being pressed using keyboard or mouse.

jack-keyboard will never connect to it's own MIDI input port.  It  will
also  refuse to connect to any other client whose name begins in "jack-
keyboard", unless the "-k" option is given.  It is,  however,  possible
to  connect  these ports manually, using jack_connect or qjackctl; this
may create feedback loop.

## License 

JACK Keyboard is distributed under the BSD license, two clause.

## Contact 

If you have any questions, comments, suggestions, patches or anything,
let us know:
* Edward Tomasz Napierala <trasz@FreeBSD.org> (initial version)
* Hans Petter Selasky <hselasky@FreeBSD.org> (further development, gtk3)
* Markus Schmidt <schmidt@boomshop.net> (further development, UX/UI)
