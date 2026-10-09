#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00124158
// Address: 0x124158 - 0x1242d8
void sub_00124158_0x124158(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00124158_0x124158");
#endif

    switch (ctx->pc) {
        case 0x12418cu: goto label_12418c;
        case 0x1241acu: goto label_1241ac;
        case 0x124208u: goto label_124208;
        case 0x124258u: goto label_124258;
        case 0x1242b8u: goto label_1242b8;
        default: break;
    }

    ctx->pc = 0x124158u;

    // 0x124158: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x124158u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x12415c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x12415cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x124160: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x124160u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x124164: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x124164u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x124168: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x124168u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x12416c: 0x26110048  addiu       $s1, $s0, 0x48
    ctx->pc = 0x12416cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 16), 72));
    // 0x124170: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x124170u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x124174: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x124174u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x124178: 0x8e030004  lw          $v1, 0x4($s0)
    ctx->pc = 0x124178u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x12417c: 0x14620046  bne         $v1, $v0, . + 4 + (0x46 << 2)
    ctx->pc = 0x12417Cu;
    {
        const bool branch_taken_0x12417c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x124180u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12417Cu;
            // 0x124180: 0x8e320000  lw          $s2, 0x0($s1) (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12417c) {
            ctx->pc = 0x124298u;
            goto label_124298;
        }
    }
    ctx->pc = 0x124184u;
    // 0x124184: 0xc04d3e6  jal         func_134F98
    ctx->pc = 0x124184u;
    SET_GPR_U32(ctx, 31, 0x12418Cu);
    ctx->pc = 0x124188u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x124184u;
            // 0x124188: 0x8e040008  lw          $a0, 0x8($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x134F98u;
    if (runtime->hasFunction(0x134F98u)) {
        auto targetFn = runtime->lookupFunction(0x134F98u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12418Cu; }
        if (ctx->pc != 0x12418Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00134F98_0x134f98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12418Cu; }
        if (ctx->pc != 0x12418Cu) { return; }
    }
    ctx->pc = 0x12418Cu;
label_12418c:
    // 0x12418c: 0x54400042  bnel        $v0, $zero, . + 4 + (0x42 << 2)
    ctx->pc = 0x12418Cu;
    {
        const bool branch_taken_0x12418c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x12418c) {
            ctx->pc = 0x124190u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12418Cu;
            // 0x124190: 0x8e030004  lw          $v1, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x124298u;
            goto label_124298;
        }
    }
    ctx->pc = 0x124194u;
    // 0x124194: 0x8e04007c  lw          $a0, 0x7C($s0)
    ctx->pc = 0x124194u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 124)));
    // 0x124198: 0x26050068  addiu       $a1, $s0, 0x68
    ctx->pc = 0x124198u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 104));
    // 0x12419c: 0x8e020078  lw          $v0, 0x78($s0)
    ctx->pc = 0x12419cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 120)));
    // 0x1241a0: 0x2606006c  addiu       $a2, $s0, 0x6C
    ctx->pc = 0x1241a0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), 108));
    // 0x1241a4: 0x40f809  jalr        $v0
    ctx->pc = 0x1241A4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1241ACu);
        ctx->pc = 0x1241A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1241A4u;
            // 0x1241a8: 0x26070070  addiu       $a3, $s0, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), 112));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1241ACu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12418Cu: goto label_12418c;
            case 0x1241ACu: goto label_1241ac;
            case 0x124208u: goto label_124208;
            case 0x124248u: goto label_124248;
            case 0x124258u: goto label_124258;
            case 0x12427Cu: goto label_12427c;
            case 0x124298u: goto label_124298;
            case 0x1242B8u: goto label_1242b8;
            case 0x1242C4u: goto label_1242c4;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1241ACu; }
            if (ctx->pc != 0x1241ACu) { return; }
        }
        }
    }
    ctx->pc = 0x1241ACu;
label_1241ac:
    // 0x1241ac: 0x8e240018  lw          $a0, 0x18($s1)
    ctx->pc = 0x1241acu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 24)));
    // 0x1241b0: 0x8e290020  lw          $t1, 0x20($s1)
    ctx->pc = 0x1241b0u;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 32)));
    // 0x1241b4: 0x24060002  addiu       $a2, $zero, 0x2
    ctx->pc = 0x1241b4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1241b8: 0x8e230024  lw          $v1, 0x24($s1)
    ctx->pc = 0x1241b8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 36)));
    // 0x1241bc: 0x894023  subu        $t0, $a0, $t1
    ctx->pc = 0x1241bcu;
    SET_GPR_S32(ctx, 8, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 9)));
    // 0x1241c0: 0x8204000e  lb          $a0, 0xE($s0)
    ctx->pc = 0x1241c0u;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
    // 0x1241c4: 0x68102a  slt         $v0, $v1, $t0
    ctx->pc = 0x1241c4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 8)) ? 1 : 0);
    // 0x1241c8: 0x8e250004  lw          $a1, 0x4($s1)
    ctx->pc = 0x1241c8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x1241cc: 0x62400b  movn        $t0, $v1, $v0
    ctx->pc = 0x1241ccu;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 8, GPR_VEC(ctx, 3));
    // 0x1241d0: 0x91840  sll         $v1, $t1, 1
    ctx->pc = 0x1241d0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 9), 1));
    // 0x1241d4: 0x8e2b0014  lw          $t3, 0x14($s1)
    ctx->pc = 0x1241d4u;
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x1241d8: 0xa8102a  slt         $v0, $a1, $t0
    ctx->pc = 0x1241d8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 8)) ? 1 : 0);
    // 0x1241dc: 0xa2400b  movn        $t0, $a1, $v0
    ctx->pc = 0x1241dcu;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 8, GPR_VEC(ctx, 5));
    // 0x1241e0: 0x1635021  addu        $t2, $t3, $v1
    ctx->pc = 0x1241e0u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 11), GPR_U32(ctx, 3)));
    // 0x1241e4: 0x14860018  bne         $a0, $a2, . + 4 + (0x18 << 2)
    ctx->pc = 0x1241E4u;
    {
        const bool branch_taken_0x1241e4 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 6));
        ctx->pc = 0x1241E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1241E4u;
            // 0x1241e8: 0x9203000e  lbu         $v1, 0xE($s0) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1241e4) {
            ctx->pc = 0x124248u;
            goto label_124248;
        }
    }
    ctx->pc = 0x1241ECu;
    // 0x1241ec: 0x8e22001c  lw          $v0, 0x1C($s1)
    ctx->pc = 0x1241ecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 28)));
    // 0x1241f0: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1241f0u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1241f4: 0x491021  addu        $v0, $v0, $t1
    ctx->pc = 0x1241f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 9)));
    // 0x1241f8: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x1241f8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1241fc: 0x1900001f  blez        $t0, . + 4 + (0x1F << 2)
    ctx->pc = 0x1241FCu;
    {
        const bool branch_taken_0x1241fc = (GPR_S64(ctx, 8) <= 0);
        ctx->pc = 0x124200u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1241FCu;
            // 0x124200: 0x1624821  addu        $t1, $t3, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 11), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1241fc) {
            ctx->pc = 0x12427Cu;
            goto label_12427c;
        }
    }
    ctx->pc = 0x124204u;
    // 0x124204: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x124204u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
label_124208:
    // 0x124208: 0x90c20000  lbu         $v0, 0x0($a2)
    ctx->pc = 0x124208u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x12420c: 0x71840  sll         $v1, $a3, 1
    ctx->pc = 0x12420cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 7), 1));
    // 0x124210: 0x6a2021  addu        $a0, $v1, $t2
    ctx->pc = 0x124210u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 10)));
    // 0x124214: 0x691821  addu        $v1, $v1, $t1
    ctx->pc = 0x124214u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 9)));
    // 0x124218: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x124218u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x12421c: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x12421cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x124220: 0xa4820000  sh          $v0, 0x0($a0)
    ctx->pc = 0x124220u;
    WRITE16(ADD32(GPR_U32(ctx, 4), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x124224: 0xe8282a  slt         $a1, $a3, $t0
    ctx->pc = 0x124224u;
    SET_GPR_U64(ctx, 5, ((int64_t)GPR_S64(ctx, 7) < (int64_t)GPR_S64(ctx, 8)) ? 1 : 0);
    // 0x124228: 0x90c20001  lbu         $v0, 0x1($a2)
    ctx->pc = 0x124228u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 1)));
    // 0x12422c: 0x24c60002  addiu       $a2, $a2, 0x2
    ctx->pc = 0x12422cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 2));
    // 0x124230: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x124230u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x124234: 0x14a0fff4  bnez        $a1, . + 4 + (-0xC << 2)
    ctx->pc = 0x124234u;
    {
        const bool branch_taken_0x124234 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x124238u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124234u;
            // 0x124238: 0xa4620000  sh          $v0, 0x0($v1) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 3), 0), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x124234) {
            ctx->pc = 0x124208u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_124208;
        }
    }
    ctx->pc = 0x12423Cu;
    // 0x12423c: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x12423Cu;
    {
        const bool branch_taken_0x12423c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x124240u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12423Cu;
            // 0x124240: 0x9203000e  lbu         $v1, 0xE($s0) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12423c) {
            ctx->pc = 0x12427Cu;
            goto label_12427c;
        }
    }
    ctx->pc = 0x124244u;
    // 0x124244: 0x0  nop
    ctx->pc = 0x124244u;
    // NOP
label_124248:
    // 0x124248: 0x1900000c  blez        $t0, . + 4 + (0xC << 2)
    ctx->pc = 0x124248u;
    {
        const bool branch_taken_0x124248 = (GPR_S64(ctx, 8) <= 0);
        ctx->pc = 0x12424Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124248u;
            // 0x12424c: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x124248) {
            ctx->pc = 0x12427Cu;
            goto label_12427c;
        }
    }
    ctx->pc = 0x124250u;
    // 0x124250: 0x140282d  daddu       $a1, $t2, $zero
    ctx->pc = 0x124250u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
    // 0x124254: 0x0  nop
    ctx->pc = 0x124254u;
    // NOP
label_124258:
    // 0x124258: 0x2471021  addu        $v0, $s2, $a3
    ctx->pc = 0x124258u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 7)));
    // 0x12425c: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x12425cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x124260: 0x90430000  lbu         $v1, 0x0($v0)
    ctx->pc = 0x124260u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x124264: 0xe8202a  slt         $a0, $a3, $t0
    ctx->pc = 0x124264u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 7) < (int64_t)GPR_S64(ctx, 8)) ? 1 : 0);
    // 0x124268: 0x31a00  sll         $v1, $v1, 8
    ctx->pc = 0x124268u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
    // 0x12426c: 0xa4a30000  sh          $v1, 0x0($a1)
    ctx->pc = 0x12426cu;
    WRITE16(ADD32(GPR_U32(ctx, 5), 0), (uint16_t)GPR_U32(ctx, 3));
    // 0x124270: 0x1480fff9  bnez        $a0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x124270u;
    {
        const bool branch_taken_0x124270 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x124274u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124270u;
            // 0x124274: 0x24a50002  addiu       $a1, $a1, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x124270) {
            ctx->pc = 0x124258u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_124258;
        }
    }
    ctx->pc = 0x124278u;
    // 0x124278: 0x9203000e  lbu         $v1, 0xE($s0)
    ctx->pc = 0x124278u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
label_12427c:
    // 0x12427c: 0x31600  sll         $v0, $v1, 24
    ctx->pc = 0x12427cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 24));
    // 0x124280: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x124280u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x124284: 0x21603  sra         $v0, $v0, 24
    ctx->pc = 0x124284u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 24));
    // 0x124288: 0xae030004  sw          $v1, 0x4($s0)
    ctx->pc = 0x124288u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 3));
    // 0x12428c: 0x1021018  mult        $v0, $t0, $v0
    ctx->pc = 0x12428cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 8) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x124290: 0xae080090  sw          $t0, 0x90($s0)
    ctx->pc = 0x124290u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 144), GPR_U32(ctx, 8));
    // 0x124294: 0xae020094  sw          $v0, 0x94($s0)
    ctx->pc = 0x124294u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 148), GPR_U32(ctx, 2));
label_124298:
    // 0x124298: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x124298u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x12429c: 0x54620009  bnel        $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x12429Cu;
    {
        const bool branch_taken_0x12429c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x12429c) {
            ctx->pc = 0x1242A0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12429Cu;
            // 0x1242a0: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1242C4u;
            goto label_1242c4;
        }
    }
    ctx->pc = 0x1242A4u;
    // 0x1242a4: 0x8e030080  lw          $v1, 0x80($s0)
    ctx->pc = 0x1242a4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 128)));
    // 0x1242a8: 0x8e040084  lw          $a0, 0x84($s0)
    ctx->pc = 0x1242a8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 132)));
    // 0x1242ac: 0x8e050094  lw          $a1, 0x94($s0)
    ctx->pc = 0x1242acu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 148)));
    // 0x1242b0: 0x60f809  jalr        $v1
    ctx->pc = 0x1242B0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x1242B8u);
        ctx->pc = 0x1242B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1242B0u;
            // 0x1242b4: 0x8e060090  lw          $a2, 0x90($s0) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 144)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1242B8u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12418Cu: goto label_12418c;
            case 0x1241ACu: goto label_1241ac;
            case 0x124208u: goto label_124208;
            case 0x124248u: goto label_124248;
            case 0x124258u: goto label_124258;
            case 0x12427Cu: goto label_12427c;
            case 0x124298u: goto label_124298;
            case 0x1242B8u: goto label_1242b8;
            case 0x1242C4u: goto label_1242c4;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1242B8u; }
            if (ctx->pc != 0x1242B8u) { return; }
        }
        }
    }
    ctx->pc = 0x1242B8u;
label_1242b8:
    // 0x1242b8: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1242b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1242bc: 0xae020004  sw          $v0, 0x4($s0)
    ctx->pc = 0x1242bcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
    // 0x1242c0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1242c0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1242c4:
    // 0x1242c4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1242c4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1242c8: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1242c8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1242cc: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1242ccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1242d0: 0x3e00008  jr          $ra
    ctx->pc = 0x1242D0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1242D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1242D0u;
            // 0x1242d4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12418Cu: goto label_12418c;
            case 0x1241ACu: goto label_1241ac;
            case 0x124208u: goto label_124208;
            case 0x124248u: goto label_124248;
            case 0x124258u: goto label_124258;
            case 0x12427Cu: goto label_12427c;
            case 0x124298u: goto label_124298;
            case 0x1242B8u: goto label_1242b8;
            case 0x1242C4u: goto label_1242c4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1242D8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
