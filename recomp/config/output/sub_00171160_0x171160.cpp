#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00171160
// Address: 0x171160 - 0x171478
void sub_00171160_0x171160(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00171160_0x171160");
#endif

    switch (ctx->pc) {
        case 0x171190u: goto label_171190;
        case 0x17128cu: goto label_17128c;
        case 0x17129cu: goto label_17129c;
        case 0x1713a0u: goto label_1713a0;
        case 0x1713a8u: goto label_1713a8;
        case 0x1713d8u: goto label_1713d8;
        case 0x171428u: goto label_171428;
        case 0x171448u: goto label_171448;
        default: break;
    }

    ctx->pc = 0x171160u;

    // 0x171160: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x171160u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x171164: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x171164u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x171168: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x171168u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17116c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x17116cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x171170: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x171170u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x171174: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x171174u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x171178: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x171178u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x17117c: 0xffb60030  sd          $s6, 0x30($sp)
    ctx->pc = 0x17117cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 22));
    // 0x171180: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x171180u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x171184: 0xffbf0038  sd          $ra, 0x38($sp)
    ctx->pc = 0x171184u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x171188: 0xc045198  jal         func_114660
    ctx->pc = 0x171188u;
    SET_GPR_U32(ctx, 31, 0x171190u);
    ctx->pc = 0x17118Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x171188u;
            // 0x17118c: 0x8e040040  lw          $a0, 0x40($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 64)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114660u;
    if (runtime->hasFunction(0x114660u)) {
        auto targetFn = runtime->lookupFunction(0x114660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171190u; }
        if (ctx->pc != 0x171190u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114660_0x114660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171190u; }
        if (ctx->pc != 0x171190u) { return; }
    }
    ctx->pc = 0x171190u;
label_171190:
    // 0x171190: 0x8e040038  lw          $a0, 0x38($s0)
    ctx->pc = 0x171190u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 56)));
    // 0x171194: 0x8e09001c  lw          $t1, 0x1C($s0)
    ctx->pc = 0x171194u;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x171198: 0x41202  srl         $v0, $a0, 8
    ctx->pc = 0x171198u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 4), 8));
    // 0x17119c: 0x41c02  srl         $v1, $a0, 16
    ctx->pc = 0x17119cu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 4), 16));
    // 0x1711a0: 0x3042000f  andi        $v0, $v0, 0xF
    ctx->pc = 0x1711a0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)15);
    // 0x1711a4: 0x30630003  andi        $v1, $v1, 0x3
    ctx->pc = 0x1711a4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)3);
    // 0x1711a8: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x1711a8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1711ac: 0x8e070000  lw          $a3, 0x0($s0)
    ctx->pc = 0x1711acu;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1711b0: 0x31100  sll         $v0, $v1, 4
    ctx->pc = 0x1711b0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x1711b4: 0x8e050024  lw          $a1, 0x24($s0)
    ctx->pc = 0x1711b4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
    // 0x1711b8: 0x1229023  subu        $s2, $t1, $v0
    ctx->pc = 0x1711b8u;
    SET_GPR_S32(ctx, 18, (int32_t)SUB32(GPR_U32(ctx, 9), GPR_U32(ctx, 2)));
    // 0x1711bc: 0x8e0a0028  lw          $t2, 0x28($s0)
    ctx->pc = 0x1711bcu;
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 40)));
    // 0x1711c0: 0x247102b  sltu        $v0, $s2, $a3
    ctx->pc = 0x1711c0u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 18) < (uint64_t)GPR_U64(ctx, 7)) ? 1 : 0);
    // 0x1711c4: 0xa3a821  addu        $s5, $a1, $v1
    ctx->pc = 0x1711c4u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
    // 0x1711c8: 0x3096007f  andi        $s6, $a0, 0x7F
    ctx->pc = 0x1711c8u;
    SET_GPR_U64(ctx, 22, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)127);
    // 0x1711cc: 0x8e140020  lw          $s4, 0x20($s0)
    ctx->pc = 0x1711ccu;
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x1711d0: 0x1040002b  beqz        $v0, . + 4 + (0x2B << 2)
    ctx->pc = 0x1711D0u;
    {
        const bool branch_taken_0x1711d0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1711D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1711D0u;
            // 0x1711d4: 0x35530100  ori         $s3, $t2, 0x100 (Delay Slot)
        SET_GPR_U64(ctx, 19, GPR_U64(ctx, 10) | (uint64_t)(uint16_t)256);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1711d0) {
            ctx->pc = 0x171280u;
            goto label_171280;
        }
    }
    ctx->pc = 0x1711D8u;
    // 0x1711d8: 0x8e060008  lw          $a2, 0x8($s0)
    ctx->pc = 0x1711d8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x1711dc: 0x3c020fff  lui         $v0, 0xFFF
    ctx->pc = 0x1711dcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4095 << 16));
    // 0x1711e0: 0x8e030004  lw          $v1, 0x4($s0)
    ctx->pc = 0x1711e0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1711e4: 0xf22023  subu        $a0, $a3, $s2
    ctx->pc = 0x1711e4u;
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 7), GPR_U32(ctx, 18)));
    // 0x1711e8: 0x642c0  sll         $t0, $a2, 11
    ctx->pc = 0x1711e8u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 6), 11));
    // 0x1711ec: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x1711ecu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x1711f0: 0x62a024  and         $s4, $v1, $v0
    ctx->pc = 0x1711f0u;
    SET_GPR_U64(ctx, 20, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1711f4: 0x4a902  srl         $s5, $a0, 4
    ctx->pc = 0x1711f4u;
    SET_GPR_S32(ctx, 21, (int32_t)SRL32(GPR_U32(ctx, 4), 4));
    // 0x1711f8: 0x11270004  beq         $t1, $a3, . + 4 + (0x4 << 2)
    ctx->pc = 0x1711F8u;
    {
        const bool branch_taken_0x1711f8 = (GPR_U64(ctx, 9) == GPR_U64(ctx, 7));
        ctx->pc = 0x1711FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1711F8u;
            // 0x1711fc: 0x2489021  addu        $s2, $s2, $t0 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 8)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1711f8) {
            ctx->pc = 0x17120Cu;
            goto label_17120c;
        }
    }
    ctx->pc = 0x171200u;
    // 0x171200: 0xe81021  addu        $v0, $a3, $t0
    ctx->pc = 0x171200u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x171204: 0x15220002  bne         $t1, $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x171204u;
    {
        const bool branch_taken_0x171204 = (GPR_U64(ctx, 9) != GPR_U64(ctx, 2));
        ctx->pc = 0x171208u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x171204u;
            // 0x171208: 0x24040003  addiu       $a0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x171204) {
            ctx->pc = 0x171210u;
            goto label_171210;
        }
    }
    ctx->pc = 0x17120Cu;
label_17120c:
    // 0x17120c: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x17120cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_171210:
    // 0x171210: 0x8e03000c  lw          $v1, 0xC($s0)
    ctx->pc = 0x171210u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x171214: 0x3c020fff  lui         $v0, 0xFFF
    ctx->pc = 0x171214u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4095 << 16));
    // 0x171218: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x171218u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x17121c: 0x42700  sll         $a0, $a0, 28
    ctx->pc = 0x17121cu;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 28));
    // 0x171220: 0xc31823  subu        $v1, $a2, $v1
    ctx->pc = 0x171220u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x171224: 0x1421024  and         $v0, $t2, $v0
    ctx->pc = 0x171224u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 10) & GPR_U64(ctx, 2));
    // 0x171228: 0x66001a  div         $zero, $v1, $a2
    ctx->pc = 0x171228u;
    { int32_t divisor = GPR_S32(ctx, 6);    int32_t dividend = GPR_S32(ctx, 3);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x17122c: 0x441025  or          $v0, $v0, $a0
    ctx->pc = 0x17122cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 4));
    // 0x171230: 0x34530100  ori         $s3, $v0, 0x100
    ctx->pc = 0x171230u;
    SET_GPR_U64(ctx, 19, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)256);
    // 0x171234: 0x50c00001  beql        $a2, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x171234u;
    {
        const bool branch_taken_0x171234 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        if (branch_taken_0x171234) {
            ctx->pc = 0x171238u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x171234u;
            // 0x171238: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x17123Cu;
            goto label_17123c;
        }
    }
    ctx->pc = 0x17123Cu;
label_17123c:
    // 0x17123c: 0x2810  mfhi        $a1
    ctx->pc = 0x17123cu;
    SET_GPR_U64(ctx, 5, ctx->hi);
    // 0x171240: 0x4a20009  bltzl       $a1, . + 4 + (0x9 << 2)
    ctx->pc = 0x171240u;
    {
        const bool branch_taken_0x171240 = (GPR_S64(ctx, 5) < 0);
        if (branch_taken_0x171240) {
            ctx->pc = 0x171244u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x171240u;
            // 0x171244: 0x8e030010  lw          $v1, 0x10($s0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x171268u;
            goto label_171268;
        }
    }
    ctx->pc = 0x171248u;
    // 0x171248: 0x50c00001  beql        $a2, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x171248u;
    {
        const bool branch_taken_0x171248 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        if (branch_taken_0x171248) {
            ctx->pc = 0x17124Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x171248u;
            // 0x17124c: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x171250u;
            goto label_171250;
        }
    }
    ctx->pc = 0x171250u;
label_171250:
    // 0x171250: 0x8e030010  lw          $v1, 0x10($s0)
    ctx->pc = 0x171250u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x171254: 0xa3102a  slt         $v0, $a1, $v1
    ctx->pc = 0x171254u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x171258: 0x54400043  bnel        $v0, $zero, . + 4 + (0x43 << 2)
    ctx->pc = 0x171258u;
    {
        const bool branch_taken_0x171258 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x171258) {
            ctx->pc = 0x17125Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x171258u;
            // 0x17125c: 0x8e03002c  lw          $v1, 0x2C($s0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 44)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x171368u;
            goto label_171368;
        }
    }
    ctx->pc = 0x171260u;
    // 0x171260: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x171260u;
    {
        const bool branch_taken_0x171260 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x171264u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x171260u;
            // 0x171264: 0x24c2ffff  addiu       $v0, $a2, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x171260) {
            ctx->pc = 0x17126Cu;
            goto label_17126c;
        }
    }
    ctx->pc = 0x171268u;
label_171268:
    // 0x171268: 0x24c2ffff  addiu       $v0, $a2, -0x1
    ctx->pc = 0x171268u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
label_17126c:
    // 0x17126c: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x17126cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x171270: 0xae02000c  sw          $v0, 0xC($s0)
    ctx->pc = 0x171270u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 2));
    // 0x171274: 0x1000003b  b           . + 4 + (0x3B << 2)
    ctx->pc = 0x171274u;
    {
        const bool branch_taken_0x171274 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x171278u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x171274u;
            // 0x171278: 0xae030010  sw          $v1, 0x10($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x171274) {
            ctx->pc = 0x171364u;
            goto label_171364;
        }
    }
    ctx->pc = 0x17127Cu;
    // 0x17127c: 0x0  nop
    ctx->pc = 0x17127cu;
    // NOP
label_171280:
    // 0x171280: 0x120282d  daddu       $a1, $t1, $zero
    ctx->pc = 0x171280u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x171284: 0xc05c268  jal         func_1709A0
    ctx->pc = 0x171284u;
    SET_GPR_U32(ctx, 31, 0x17128Cu);
    ctx->pc = 0x171288u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x171284u;
            // 0x171288: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1709A0u;
    if (runtime->hasFunction(0x1709A0u)) {
        auto targetFn = runtime->lookupFunction(0x1709A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17128Cu; }
        if (ctx->pc != 0x17128Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001709A0_0x1709a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17128Cu; }
        if (ctx->pc != 0x17128Cu) { return; }
    }
    ctx->pc = 0x17128Cu;
label_17128c:
    // 0x17128c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17128cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x171290: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x171290u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x171294: 0xc05c268  jal         func_1709A0
    ctx->pc = 0x171294u;
    SET_GPR_U32(ctx, 31, 0x17129Cu);
    ctx->pc = 0x171298u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x171294u;
            // 0x171298: 0x40882d  daddu       $s1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1709A0u;
    if (runtime->hasFunction(0x1709A0u)) {
        auto targetFn = runtime->lookupFunction(0x1709A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17129Cu; }
        if (ctx->pc != 0x17129Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001709A0_0x1709a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17129Cu; }
        if (ctx->pc != 0x17129Cu) { return; }
    }
    ctx->pc = 0x17129Cu;
label_17129c:
    // 0x17129c: 0x40702d  daddu       $t6, $v0, $zero
    ctx->pc = 0x17129cu;
    SET_GPR_U64(ctx, 14, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1712a0: 0x122e0030  beq         $s1, $t6, . + 4 + (0x30 << 2)
    ctx->pc = 0x1712A0u;
    {
        const bool branch_taken_0x1712a0 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 14));
        ctx->pc = 0x1712A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1712A0u;
            // 0x1712a4: 0x3c090fff  lui         $t1, 0xFFF (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)((uint32_t)4095 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1712a0) {
            ctx->pc = 0x171364u;
            goto label_171364;
        }
    }
    ctx->pc = 0x1712A8u;
    // 0x1712a8: 0x8e0c0008  lw          $t4, 0x8($s0)
    ctx->pc = 0x1712a8u;
    SET_GPR_S32(ctx, 12, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x1712ac: 0x8e080000  lw          $t0, 0x0($s0)
    ctx->pc = 0x1712acu;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1712b0: 0x240b0003  addiu       $t3, $zero, 0x3
    ctx->pc = 0x1712b0u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1712b4: 0x8e02001c  lw          $v0, 0x1C($s0)
    ctx->pc = 0x1712b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x1712b8: 0xc1ac0  sll         $v1, $t4, 11
    ctx->pc = 0x1712b8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 12), 11));
    // 0x1712bc: 0x50600001  beql        $v1, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x1712BCu;
    {
        const bool branch_taken_0x1712bc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1712bc) {
            ctx->pc = 0x1712C0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1712BCu;
            // 0x1712c0: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x1712C4u;
            goto label_1712c4;
        }
    }
    ctx->pc = 0x1712C4u;
label_1712c4:
    // 0x1712c4: 0x8e04000c  lw          $a0, 0xC($s0)
    ctx->pc = 0x1712c4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x1712c8: 0x481023  subu        $v0, $v0, $t0
    ctx->pc = 0x1712c8u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x1712cc: 0x8e0d0010  lw          $t5, 0x10($s0)
    ctx->pc = 0x1712ccu;
    SET_GPR_S32(ctx, 13, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x1712d0: 0x43001b  divu        $zero, $v0, $v1
    ctx->pc = 0x1712d0u;
    { uint32_t divisor = GPR_U32(ctx, 3); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 2) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 2) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,2); } }
    // 0x1712d4: 0x111ac0  sll         $v1, $s1, 11
    ctx->pc = 0x1712d4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 17), 11));
    // 0x1712d8: 0x8d1021  addu        $v0, $a0, $t5
    ctx->pc = 0x1712d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 13)));
    // 0x1712dc: 0x1cc2821  addu        $a1, $t6, $t4
    ctx->pc = 0x1712dcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 14), GPR_U32(ctx, 12)));
    // 0x1712e0: 0xa42823  subu        $a1, $a1, $a0
    ctx->pc = 0x1712e0u;
    SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 4)));
    // 0x1712e4: 0x1031821  addu        $v1, $t0, $v1
    ctx->pc = 0x1712e4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 3)));
    // 0x1712e8: 0x8e040028  lw          $a0, 0x28($s0)
    ctx->pc = 0x1712e8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 40)));
    // 0x1712ec: 0x8e0a0004  lw          $t2, 0x4($s0)
    ctx->pc = 0x1712ecu;
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1712f0: 0x3529ffff  ori         $t1, $t1, 0xFFFF
    ctx->pc = 0x1712f0u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) | (uint64_t)(uint16_t)65535);
    // 0x1712f4: 0x892024  and         $a0, $a0, $t1
    ctx->pc = 0x1712f4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & GPR_U64(ctx, 9));
    // 0x1712f8: 0x721823  subu        $v1, $v1, $s2
    ctx->pc = 0x1712f8u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 18)));
    // 0x1712fc: 0x3a902  srl         $s5, $v1, 4
    ctx->pc = 0x1712fcu;
    SET_GPR_S32(ctx, 21, (int32_t)SRL32(GPR_U32(ctx, 3), 4));
    // 0x171300: 0x3010  mfhi        $a2
    ctx->pc = 0x171300u;
    SET_GPR_U64(ctx, 6, ctx->hi);
    // 0x171304: 0x4c001a  div         $zero, $v0, $t4
    ctx->pc = 0x171304u;
    { int32_t divisor = GPR_S32(ctx, 12);    int32_t dividend = GPR_S32(ctx, 2);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x171308: 0x1063021  addu        $a2, $t0, $a2
    ctx->pc = 0x171308u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 6)));
    // 0x17130c: 0x111100  sll         $v0, $s1, 4
    ctx->pc = 0x17130cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 17), 4));
    // 0x171310: 0x4a1021  addu        $v0, $v0, $t2
    ctx->pc = 0x171310u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 10)));
    // 0x171314: 0x49a024  and         $s4, $v0, $t1
    ctx->pc = 0x171314u;
    SET_GPR_U64(ctx, 20, GPR_U64(ctx, 2) & GPR_U64(ctx, 9));
    // 0x171318: 0x3810  mfhi        $a3
    ctx->pc = 0x171318u;
    SET_GPR_U64(ctx, 7, ctx->hi);
    // 0x17131c: 0xac001a  div         $zero, $a1, $t4
    ctx->pc = 0x17131cu;
    { int32_t divisor = GPR_S32(ctx, 12);    int32_t dividend = GPR_S32(ctx, 5);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x171320: 0x73ac0  sll         $a3, $a3, 11
    ctx->pc = 0x171320u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 11));
    // 0x171324: 0x1074021  addu        $t0, $t0, $a3
    ctx->pc = 0x171324u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 7)));
    // 0x171328: 0xc83026  xor         $a2, $a2, $t0
    ctx->pc = 0x171328u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) ^ GPR_U64(ctx, 8));
    // 0x17132c: 0x6580a  movz        $t3, $zero, $a2
    ctx->pc = 0x17132cu;
    if (GPR_U64(ctx, 6) == 0) SET_GPR_VEC(ctx, 11, GPR_VEC(ctx, 0));
    // 0x171330: 0xb5f00  sll         $t3, $t3, 28
    ctx->pc = 0x171330u;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 28));
    // 0x171334: 0x8b2025  or          $a0, $a0, $t3
    ctx->pc = 0x171334u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 11));
    // 0x171338: 0x1010  mfhi        $v0
    ctx->pc = 0x171338u;
    SET_GPR_U64(ctx, 2, ctx->hi);
    // 0x17133c: 0x4400006  bltz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x17133Cu;
    {
        const bool branch_taken_0x17133c = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x171340u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17133Cu;
            // 0x171340: 0x34930100  ori         $s3, $a0, 0x100 (Delay Slot)
        SET_GPR_U64(ctx, 19, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)256);
        ctx->in_delay_slot = false;
        if (branch_taken_0x17133c) {
            ctx->pc = 0x171358u;
            goto label_171358;
        }
    }
    ctx->pc = 0x171344u;
    // 0x171344: 0x4d102a  slt         $v0, $v0, $t5
    ctx->pc = 0x171344u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 13)) ? 1 : 0);
    // 0x171348: 0x51800001  beql        $t4, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x171348u;
    {
        const bool branch_taken_0x171348 = (GPR_U64(ctx, 12) == GPR_U64(ctx, 0));
        if (branch_taken_0x171348) {
            ctx->pc = 0x17134Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x171348u;
            // 0x17134c: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x171350u;
            goto label_171350;
        }
    }
    ctx->pc = 0x171350u;
label_171350:
    // 0x171350: 0x54400005  bnel        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x171350u;
    {
        const bool branch_taken_0x171350 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x171350) {
            ctx->pc = 0x171354u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x171350u;
            // 0x171354: 0x8e03002c  lw          $v1, 0x2C($s0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 44)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x171368u;
            goto label_171368;
        }
    }
    ctx->pc = 0x171358u;
label_171358:
    // 0x171358: 0x25a20001  addiu       $v0, $t5, 0x1
    ctx->pc = 0x171358u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 13), 1));
    // 0x17135c: 0xae0e000c  sw          $t6, 0xC($s0)
    ctx->pc = 0x17135cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 14));
    // 0x171360: 0xae020010  sw          $v0, 0x10($s0)
    ctx->pc = 0x171360u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 2));
label_171364:
    // 0x171364: 0x8e03002c  lw          $v1, 0x2C($s0)
    ctx->pc = 0x171364u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 44)));
label_171368:
    // 0x171368: 0x5060000e  beql        $v1, $zero, . + 4 + (0xE << 2)
    ctx->pc = 0x171368u;
    {
        const bool branch_taken_0x171368 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x171368) {
            ctx->pc = 0x17136Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x171368u;
            // 0x17136c: 0x3c031000  lui         $v1, 0x1000 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1713A4u;
            goto label_1713a4;
        }
    }
    ctx->pc = 0x171370u;
    // 0x171370: 0x8e020030  lw          $v0, 0x30($s0)
    ctx->pc = 0x171370u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 48)));
    // 0x171374: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x171374u;
    {
        const bool branch_taken_0x171374 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x171378u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x171374u;
            // 0x171378: 0x3c021000  lui         $v0, 0x1000 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x171374) {
            ctx->pc = 0x1713A0u;
            goto label_1713a0;
        }
    }
    ctx->pc = 0x17137Cu;
    // 0x17137c: 0x3c041000  lui         $a0, 0x1000
    ctx->pc = 0x17137cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)4096 << 16));
    // 0x171380: 0x3442b010  ori         $v0, $v0, 0xB010
    ctx->pc = 0x171380u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)45072);
    // 0x171384: 0x3484b020  ori         $a0, $a0, 0xB020
    ctx->pc = 0x171384u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)45088);
    // 0x171388: 0xac430000  sw          $v1, 0x0($v0)
    ctx->pc = 0x171388u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3)); // MMIO: 0x10000000
    // 0x17138c: 0x8e030030  lw          $v1, 0x30($s0)
    ctx->pc = 0x17138cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 48)));
    // 0x171390: 0xac830000  sw          $v1, 0x0($a0)
    ctx->pc = 0x171390u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 3)); // MMIO: 0x10000000
    // 0x171394: 0x8e040034  lw          $a0, 0x34($s0)
    ctx->pc = 0x171394u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 52)));
    // 0x171398: 0xc05c27c  jal         func_1709F0
    ctx->pc = 0x171398u;
    SET_GPR_U32(ctx, 31, 0x1713A0u);
    ctx->pc = 0x17139Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x171398u;
            // 0x17139c: 0x34840100  ori         $a0, $a0, 0x100 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)256);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1709F0u;
    if (runtime->hasFunction(0x1709F0u)) {
        auto targetFn = runtime->lookupFunction(0x1709F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1713A0u; }
        if (ctx->pc != 0x1713A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001709F0_0x1709f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1713A0u; }
        if (ctx->pc != 0x1713A0u) { return; }
    }
    ctx->pc = 0x1713A0u;
label_1713a0:
    // 0x1713a0: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x1713a0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
label_1713a4:
    // 0x1713a4: 0x34632010  ori         $v1, $v1, 0x2010
    ctx->pc = 0x1713a4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)8208);
label_1713a8:
    // 0x1713a8: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x1713a8u;
    SET_GPR_S32(ctx, 2, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0))); // MMIO: 0x10000000
    // 0x1713ac: 0x0  nop
    ctx->pc = 0x1713acu;
    // NOP
    // 0x1713b0: 0x0  nop
    ctx->pc = 0x1713b0u;
    // NOP
    // 0x1713b4: 0x0  nop
    ctx->pc = 0x1713b4u;
    // NOP
    // 0x1713b8: 0x0  nop
    ctx->pc = 0x1713b8u;
    // NOP
    // 0x1713bc: 0x440fffa  bltz        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1713BCu;
    {
        const bool branch_taken_0x1713bc = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x1713C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1713BCu;
            // 0x1713c0: 0x3c021000  lui         $v0, 0x1000 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1713bc) {
            ctx->pc = 0x1713A8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1713a8;
        }
    }
    ctx->pc = 0x1713C4u;
    // 0x1713c4: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x1713c4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x1713c8: 0x34422000  ori         $v0, $v0, 0x2000
    ctx->pc = 0x1713c8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)8192);
    // 0x1713cc: 0x34632010  ori         $v1, $v1, 0x2010
    ctx->pc = 0x1713ccu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)8208);
    // 0x1713d0: 0xac560000  sw          $s6, 0x0($v0)
    ctx->pc = 0x1713d0u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 22)); // MMIO: 0x10000000
    // 0x1713d4: 0x0  nop
    ctx->pc = 0x1713d4u;
    // NOP
label_1713d8:
    // 0x1713d8: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x1713d8u;
    SET_GPR_S32(ctx, 2, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0))); // MMIO: 0x10000000
    // 0x1713dc: 0x0  nop
    ctx->pc = 0x1713dcu;
    // NOP
    // 0x1713e0: 0x0  nop
    ctx->pc = 0x1713e0u;
    // NOP
    // 0x1713e4: 0x0  nop
    ctx->pc = 0x1713e4u;
    // NOP
    // 0x1713e8: 0x0  nop
    ctx->pc = 0x1713e8u;
    // NOP
    // 0x1713ec: 0x440fffa  bltz        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1713ECu;
    {
        const bool branch_taken_0x1713ec = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x1713F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1713ECu;
            // 0x1713f0: 0x3c021000  lui         $v0, 0x1000 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1713ec) {
            ctx->pc = 0x1713D8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1713d8;
        }
    }
    ctx->pc = 0x1713F4u;
    // 0x1713f4: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x1713f4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x1713f8: 0x3c041000  lui         $a0, 0x1000
    ctx->pc = 0x1713f8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)4096 << 16));
    // 0x1713fc: 0x3442b410  ori         $v0, $v0, 0xB410
    ctx->pc = 0x1713fcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)46096);
    // 0x171400: 0x3463b430  ori         $v1, $v1, 0xB430
    ctx->pc = 0x171400u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)46128);
    // 0x171404: 0x3484b420  ori         $a0, $a0, 0xB420
    ctx->pc = 0x171404u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)46112);
    // 0x171408: 0xac520000  sw          $s2, 0x0($v0)
    ctx->pc = 0x171408u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 18));
    // 0x17140c: 0xac740000  sw          $s4, 0x0($v1)
    ctx->pc = 0x17140cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 20));
    // 0x171410: 0xac950000  sw          $s5, 0x0($a0)
    ctx->pc = 0x171410u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 21));
    // 0x171414: 0x8e020010  lw          $v0, 0x10($s0)
    ctx->pc = 0x171414u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x171418: 0x50400004  beql        $v0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x171418u;
    {
        const bool branch_taken_0x171418 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x171418) {
            ctx->pc = 0x17141Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x171418u;
            // 0x17141c: 0x8e02003c  lw          $v0, 0x3C($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 60)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x17142Cu;
            goto label_17142c;
        }
    }
    ctx->pc = 0x171420u;
    // 0x171420: 0xc05c296  jal         func_170A58
    ctx->pc = 0x171420u;
    SET_GPR_U32(ctx, 31, 0x171428u);
    ctx->pc = 0x171424u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x171420u;
            // 0x171424: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x170A58u;
    if (runtime->hasFunction(0x170A58u)) {
        auto targetFn = runtime->lookupFunction(0x170A58u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171428u; }
        if (ctx->pc != 0x171428u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00170A58_0x170a58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171428u; }
        if (ctx->pc != 0x171428u) { return; }
    }
    ctx->pc = 0x171428u;
label_171428:
    // 0x171428: 0x8e02003c  lw          $v0, 0x3C($s0)
    ctx->pc = 0x171428u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 60)));
label_17142c:
    // 0x17142c: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x17142cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x171430: 0x34632010  ori         $v1, $v1, 0x2010
    ctx->pc = 0x171430u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)8208);
    // 0x171434: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x171434u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x171438: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x171438u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2)); // MMIO: 0x10000000
    // 0x17143c: 0xae040044  sw          $a0, 0x44($s0)
    ctx->pc = 0x17143cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 68), GPR_U32(ctx, 4));
    // 0x171440: 0xc045190  jal         func_114640
    ctx->pc = 0x171440u;
    SET_GPR_U32(ctx, 31, 0x171448u);
    ctx->pc = 0x171444u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x171440u;
            // 0x171444: 0x8e040040  lw          $a0, 0x40($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 64)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114640u;
    if (runtime->hasFunction(0x114640u)) {
        auto targetFn = runtime->lookupFunction(0x114640u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171448u; }
        if (ctx->pc != 0x171448u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114640_0x114640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171448u; }
        if (ctx->pc != 0x171448u) { return; }
    }
    ctx->pc = 0x171448u;
label_171448:
    // 0x171448: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x171448u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17144c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17144cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x171450: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x171450u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x171454: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x171454u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x171458: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x171458u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17145c: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x17145cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x171460: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x171460u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x171464: 0xdfb60030  ld          $s6, 0x30($sp)
    ctx->pc = 0x171464u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x171468: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x171468u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x17146c: 0x3e00008  jr          $ra
    ctx->pc = 0x17146Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x171470u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17146Cu;
            // 0x171470: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x171190u: goto label_171190;
            case 0x17120Cu: goto label_17120c;
            case 0x171210u: goto label_171210;
            case 0x17123Cu: goto label_17123c;
            case 0x171250u: goto label_171250;
            case 0x171268u: goto label_171268;
            case 0x17126Cu: goto label_17126c;
            case 0x171280u: goto label_171280;
            case 0x17128Cu: goto label_17128c;
            case 0x17129Cu: goto label_17129c;
            case 0x1712C4u: goto label_1712c4;
            case 0x171350u: goto label_171350;
            case 0x171358u: goto label_171358;
            case 0x171364u: goto label_171364;
            case 0x171368u: goto label_171368;
            case 0x1713A0u: goto label_1713a0;
            case 0x1713A4u: goto label_1713a4;
            case 0x1713A8u: goto label_1713a8;
            case 0x1713D8u: goto label_1713d8;
            case 0x171428u: goto label_171428;
            case 0x17142Cu: goto label_17142c;
            case 0x171448u: goto label_171448;
            default: break;
        }
        return;
    }
    ctx->pc = 0x171474u;
    // 0x171474: 0x0  nop
    ctx->pc = 0x171474u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
