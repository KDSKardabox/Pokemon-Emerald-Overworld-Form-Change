.text
.thumb

.include "defines/asm_defines.s"
.include "defines/xse_commands.s"

keldeo_main:
	lock
	faceplayer
	msgbox ask_string MSG_YESNO
	compare 0x800D 0x1
	if 0x1 _goto poke_selection
	msgbox none_chosen_string MSG_NORMAL
	release
	end
	
poke_selection:
	msgbox what_pokemon_teach_string MSG_NORMAL
	special 0xA2
	waitstate
	lock
	faceplayer
	compare 0x8004 0xFF
	if 0x1 _goto none_chosen
	callasm check_if_slot_keldeo+1
	compare 0x800D 0x1
	if 0x1 _goto continue_teach
	msgbox incorrect_pokemon MSG_NORMAL
	release
	end
	
none_chosen:
	lock
	msgbox none_chosen_string MSG_NORMAL
	release
	end
	
continue_teach:
	callasm check_free_move+1
	compare 0x8005 0x1
	if 0x1 _goto teach_move_free_slot
	goto replace_move
	end
	
teach_move_free_slot:
	callasm teach_secret_sword+1
	sound 0xC6
	msgbox one_two_string MSG_KEEPOPEN
	waitmsg
	closeonkeypress
	sound 0x5B
	msgbox tada_string MSG_KEEPOPEN
	waitmsg
	closeonkeypress
	fanfare 0x173
	msgbox move_replaced_string MSG_KEEPOPEN
	waitfanfare
	pause 0x10
	msgbox keldeo_changing_string MSG_NORMAL
	fanfare 0x185
	lock
	msgbox form_change_string MSG_KEEPOPEN
	waitfanfare
	release
	end
	
replace_move:
	msgbox choose_move_delete_string MSG_NORMAL
	fadescreen 0x1
	special 0xDF
	waitstate
	compare 0x8005 0x4
	if 0x1 _goto none_chosen
	special 0xE0
	callasm teach_secret_sword+1
	sound 0xC6
	msgbox one_two_string MSG_KEEPOPEN
	waitmsg
	closeonkeypress
	sound 0x5B
	msgbox tada_string MSG_KEEPOPEN
	waitmsg
	closeonkeypress
	fanfare 0x173
	msgbox move_replaced_string MSG_KEEPOPEN
	waitfanfare
	pause 0x10
	msgbox keldeo_changing_string MSG_NORMAL
	fanfare 0x185
	lock
	msgbox form_change_string MSG_KEEPOPEN
	waitfanfare
	release
	end
	
ask_string:
.byte I_, t_, Apos, s_, Space, m_, y_, Space, s_, o_, l_, e_, m_, n_, Space, d_, u_, t_, y_, Space, t_, o_, Space, t_, e_, a_, c_, h_, Space, a_, Space, m_, o_, v_, e_, JumpLine, t_, o_, Space, M_, y_, t_, h_, i_, c_, a_, l_, Space, P_, o_, k_, 0x1B, m_, o_, n_, Dot, Para, A_, l_, t_, h_, o_, u_, g_, h_, Space, I_, Apos, m_, Space, o_, n_, Space, v_, a_, c_, a_, t_, i_, o_, n_, Comma, Space, I_, Space, c_, o_, u_, l_, d_, JumpLine, t_, e_, a_, c_, h_, Space, a_, Space, m_, o_, v_, e_, Space, t_, o_, Space, y_, o_, u_, r_, Space, K_, e_, l_, d_, e_, o_, Dot, Para, W_, h_, a_, t_, Space, d_, o_, Space, y_, o_, u_, Space, s_, a_, y_, Interro, Termin
	
none_chosen_string:
.byte N_, o_, Interro, Space, O_, k_, a_, y_, Dot, JumpLine, I_, Apos, m_, Space, a_, l_, w_, a_, y_, s_, Space, h_, e_, r_, e_, Space, i_, f_, Space, y_, o_, u_, Space, n_, e_, e_, d_, Space, m_, e_, Dot, Termin

what_pokemon_teach_string:
.byte C_, h_, o_, o_, s_, e_, Space, a_, Space, P_, o_, k_, 0x1B, m_, o_, n_, Space, f_, o_, r_, Space, m_, e_, Space, t_, o_, Space, t_, e_, a_, c_, h_, Space, a_, JumpLine, m_, o_, v_, e_, Space, t_, o_, Dot, Termin

incorrect_pokemon:
.byte I_, Apos, m_, Space, s_, o_, r_, r_, y_, Comma, Space, b_, u_, t_, Space, t_, h_, a_, t_, Apos, s_, Space, n_, o_, t_, Space, a_, Space, K_, e_, l_, d_, e_, o_, Dot, Termin

choose_move_delete_string:
.byte P_, l_, e_, a_, s_, e_, Space, c_, h_, o_, o_, s_, e_, Space, a_, Space, m_, o_, v_, e_, Space, t_, h_, a_, t_, Space, w_, i_, l_, l_, Space, b_, e_, JumpLine, r_, e_, p_, l_, a_, c_, e_, d_, Space, w_, i_, t_, h_, Space, S_, e_, c_, r_, e_, t_, Space, S_, w_, o_, r_, d_, Dot, Termin

one_two_string:
.byte 0xA2, Comma, Space, 0xA3, Comma, Space, a_, n_, d_, 0xB0, Space, 0xB0, Space, 0xB0, Termin

tada_string:
.byte T_, a_, Dash, d_, a_, Exclam, Termin

move_replaced_string:
.byte K_, e_, l_, d_, e_, o_, Space, l_, e_, a_, r_, n_, t_, Space, S_, e_, c_, r_, e_, t_, Space, S_, w_, o_, r_, d_, Exclam, Termin

keldeo_changing_string:
.byte W_, h_, a_, t_, Interro, Space, K_, e_, l_, d_, e_, o_, Space, i_, s_, 0xB0, Termin

form_change_string:
.byte K_, e_, l_, d_, e_, o_, Space, h_, a_, s_, Space, r_, e_, s_, o_, l_, v_, e_, d_, Space, t_, o_, Space, b_, a_, t_, t_, l_, e_, Space, a_, n_, d_, JumpLine, h_, a_, s_, Space, c_, h_, a_, n_, g_, e_, d_, Space, i_, n_, t_, o_, Space, R_, e_, s_, o_, l_, u_, t_, e_, Space, F_, o_, r_, m_, Exclam, Termin
