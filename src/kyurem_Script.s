.text
.thumb
.align 2

.include "defines/asm_defines.s"
.include "defines/xse_commands.s"

.global kyurem_script

kyurem_script:
lock
special 0xA2
waitstate
callasm check_and_fuse_kyurem+1
compare 0x800D 0x1
if 0x1 _goto successfull
compare 0x800D 0x2
if 0x1 _goto no_kyurem_in_party
compare 0x800D 0x3
if 0x1 _goto fusion_already_happened
compare 0x800D 0x4
if 0x1 _goto revert_success
compare 0x800D 0x5
if 0x1 _goto already_6_poke
msgbox not_effective_string MSG_KEEPOPEN
closeonkeypress
release
end
	
successfull:
	bufferpartypokemon 0x1 0x8004
	msgbox successful_string MSG_KEEPOPEN
	closeonkeypress
	release
	end

no_kyurem_in_party:
	msgbox no_kyurem_in_party_string MSG_KEEPOPEN
	closeonkeypress
	release
	end

fusion_already_happened:
	msgbox fusion_already_string MSG_KEEPOPEN
	closeonkeypress
	release
	end

revert_success:
	msgbox successful_string MSG_KEEPOPEN
	closeonkeypress
	release
	end

already_6_poke:
	msgbox revert_not_possible_string MSG_KEEPOPEN
	closeonkeypress
	release
	end

not_effective_string:
.byte I_, t_, Space, w_, o_, n_, t_, Space, h_, a_, v_, e_, Space, a_, n_, y_, Space, e_, f_, f_, e_, c_, t_, Exclam, Termin

successful_string:
.byte 0xFD, 0x3, Space, c_, h_, a_, n_, g_, e_, d_, Space, f_, o_, r_, m_, Exclam, Termin

no_kyurem_in_party_string:
.byte T_, h_, e_, r_, e_, Space, i_, s_, Space, n_, o_, Space, K_, y_, u_, r_, e_, m_, Space, i_, n_, Space, t_, h_, e_, Space, p_, a_, r_, t_, y_, Exclam, Termin

fusion_already_string:
.byte M_, u_, l_, t_, i_, p_, l_, e_, Space, f_, u_, s_, i_, o_, n_, s_, Space, a_, r_, e_, Space, n_, o_, t_, Space, a_, l_, l_, o_, w_, e_, d_, Exclam, Termin

revert_not_possible_string:
.byte T_, h_, e_, r_, e_, Space, i_, s_, Space, n_, o_, Space, e_, n_, o_, u_, g_, h_, Space, s_, p_, a_, c_, e_, Space, i_, n_, Space, t_, h_, e_, Space, p_, a_, r_, t_, y_
.byte Exclam, Termin
