#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013CD38
// Address: 0x13cd38 - 0x13ced0
void sub_0013CD38_0x13cd38(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013CD38_0x13cd38");
#endif

    switch (ctx->pc) {
        case 0x13cd80u: goto label_13cd80;
        case 0x13cdacu: goto label_13cdac;
        case 0x13ce18u: goto label_13ce18;
        case 0x13ce28u: goto label_13ce28;
        default: break;
    }

    ctx->pc = 0x13cd38u;

    // 0x13cd38: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x13cd38u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x13cd3c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x13cd3cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x13cd40: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x13cd40u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13cd44: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x13cd44u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x13cd48: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x13cd48u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13cd4c: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x13cd4cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x13cd50: 0xe0a02d  daddu       $s4, $a3, $zero
    ctx->pc = 0x13cd50u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13cd54: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x13cd54u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x13cd58: 0x100a82d  daddu       $s5, $t0, $zero
    ctx->pc = 0x13cd58u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13cd5c: 0xffb60030  sd          $s6, 0x30($sp)
    ctx->pc = 0x13cd5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 22));
    // 0x13cd60: 0xc0b02d  daddu       $s6, $a2, $zero
    ctx->pc = 0x13cd60u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13cd64: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13cd64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13cd68: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x13cd68u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x13cd6c: 0x16200006  bnez        $s1, . + 4 + (0x6 << 2)
    ctx->pc = 0x13CD6Cu;
    {
        const bool branch_taken_0x13cd6c = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        ctx->pc = 0x13CD70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13CD6Cu;
            // 0x13cd70: 0xffbf0038  sd          $ra, 0x38($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13cd6c) {
            ctx->pc = 0x13CD88u;
            goto label_13cd88;
        }
    }
    ctx->pc = 0x13CD74u;
    // 0x13cd74: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13cd74u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13cd78: 0xc04f53e  jal         func_13D4F8
    ctx->pc = 0x13CD78u;
    SET_GPR_U32(ctx, 31, 0x13CD80u);
    ctx->pc = 0x13CD7Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13CD78u;
            // 0x13cd7c: 0x2484d368  addiu       $a0, $a0, -0x2C98 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294955880));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13D4F8u;
    if (runtime->hasFunction(0x13D4F8u)) {
        auto targetFn = runtime->lookupFunction(0x13D4F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13CD80u; }
        if (ctx->pc != 0x13CD80u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013D4F8_0x13d4f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13CD80u; }
        if (ctx->pc != 0x13CD80u) { return; }
    }
    ctx->pc = 0x13CD80u;
label_13cd80:
    // 0x13cd80: 0x10000049  b           . + 4 + (0x49 << 2)
    ctx->pc = 0x13CD80u;
    {
        const bool branch_taken_0x13cd80 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13CD84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13CD80u;
            // 0x13cd84: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13cd80) {
            ctx->pc = 0x13CEA8u;
            goto label_13cea8;
        }
    }
    ctx->pc = 0x13CD88u;
label_13cd88:
    // 0x13cd88: 0x8e230024  lw          $v1, 0x24($s1)
    ctx->pc = 0x13cd88u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 36)));
    // 0x13cd8c: 0x28630010  slti        $v1, $v1, 0x10
    ctx->pc = 0x13cd8cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x13cd90: 0x10600045  beqz        $v1, . + 4 + (0x45 << 2)
    ctx->pc = 0x13CD90u;
    {
        const bool branch_taken_0x13cd90 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x13CD94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13CD90u;
            // 0x13cd94: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13cd90) {
            ctx->pc = 0x13CEA8u;
            goto label_13cea8;
        }
    }
    ctx->pc = 0x13CD98u;
    // 0x13cd98: 0x56400007  bnel        $s2, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x13CD98u;
    {
        const bool branch_taken_0x13cd98 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 0));
        if (branch_taken_0x13cd98) {
            ctx->pc = 0x13CD9Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13CD98u;
            // 0x13cd9c: 0x8e23001c  lw          $v1, 0x1C($s1) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 28)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13CDB8u;
            goto label_13cdb8;
        }
    }
    ctx->pc = 0x13CDA0u;
    // 0x13cda0: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13cda0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13cda4: 0xc04f53e  jal         func_13D4F8
    ctx->pc = 0x13CDA4u;
    SET_GPR_U32(ctx, 31, 0x13CDACu);
    ctx->pc = 0x13CDA8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13CDA4u;
            // 0x13cda8: 0x2484d390  addiu       $a0, $a0, -0x2C70 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294955920));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13D4F8u;
    if (runtime->hasFunction(0x13D4F8u)) {
        auto targetFn = runtime->lookupFunction(0x13D4F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13CDACu; }
        if (ctx->pc != 0x13CDACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013D4F8_0x13d4f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13CDACu; }
        if (ctx->pc != 0x13CDACu) { return; }
    }
    ctx->pc = 0x13CDACu;
label_13cdac:
    // 0x13cdac: 0x1000003e  b           . + 4 + (0x3E << 2)
    ctx->pc = 0x13CDACu;
    {
        const bool branch_taken_0x13cdac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13CDB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13CDACu;
            // 0x13cdb0: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13cdac) {
            ctx->pc = 0x13CEA8u;
            goto label_13cea8;
        }
    }
    ctx->pc = 0x13CDB4u;
    // 0x13cdb4: 0x0  nop
    ctx->pc = 0x13cdb4u;
    // NOP
label_13cdb8:
    // 0x13cdb8: 0x3c087fff  lui         $t0, 0x7FFF
    ctx->pc = 0x13cdb8u;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)32767 << 16));
    // 0x13cdbc: 0x3508ffff  ori         $t0, $t0, 0xFFFF
    ctx->pc = 0x13cdbcu;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | (uint64_t)(uint16_t)65535);
    // 0x13cdc0: 0x982d  daddu       $s3, $zero, $zero
    ctx->pc = 0x13cdc0u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13cdc4: 0x2466000f  addiu       $a2, $v1, 0xF
    ctx->pc = 0x13cdc4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 3), 15));
    // 0x13cdc8: 0x2467001e  addiu       $a3, $v1, 0x1E
    ctx->pc = 0x13cdc8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 3), 30));
    // 0x13cdcc: 0x28c50000  slti        $a1, $a2, 0x0
    ctx->pc = 0x13cdccu;
    SET_GPR_U64(ctx, 5, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x13cdd0: 0xc0102d  daddu       $v0, $a2, $zero
    ctx->pc = 0x13cdd0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13cdd4: 0xe5100b  movn        $v0, $a3, $a1
    ctx->pc = 0x13cdd4u;
    if (GPR_U64(ctx, 5) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 7));
    // 0x13cdd8: 0x31940  sll         $v1, $v1, 5
    ctx->pc = 0x13cdd8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 5));
    // 0x13cddc: 0x21103  sra         $v0, $v0, 4
    ctx->pc = 0x13cddcu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 4));
    // 0x13cde0: 0x2231821  addu        $v1, $s1, $v1
    ctx->pc = 0x13cde0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 3)));
    // 0x13cde4: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x13cde4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x13cde8: 0x24700038  addiu       $s0, $v1, 0x38
    ctx->pc = 0x13cde8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 3), 56));
    // 0x13cdec: 0xc21023  subu        $v0, $a2, $v0
    ctx->pc = 0x13cdecu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
    // 0x13cdf0: 0xae120004  sw          $s2, 0x4($s0)
    ctx->pc = 0x13cdf0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 18));
    // 0x13cdf4: 0x21140  sll         $v0, $v0, 5
    ctx->pc = 0x13cdf4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x13cdf8: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x13cdf8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13cdfc: 0x511021  addu        $v0, $v0, $s1
    ctx->pc = 0x13cdfcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
    // 0x13ce00: 0x8c430038  lw          $v1, 0x38($v0)
    ctx->pc = 0x13ce00u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 56)));
    // 0x13ce04: 0x684026  xor         $t0, $v1, $t0
    ctx->pc = 0x13ce04u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 8));
    // 0x13ce08: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x13ce08u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x13ce0c: 0x68980b  movn        $s3, $v1, $t0
    ctx->pc = 0x13ce0cu;
    if (GPR_U64(ctx, 8) != 0) SET_GPR_VEC(ctx, 19, GPR_VEC(ctx, 3));
    // 0x13ce10: 0xc042c56  jal         func_10B158
    ctx->pc = 0x13CE10u;
    SET_GPR_U32(ctx, 31, 0x13CE18u);
    ctx->pc = 0x13CE14u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13CE10u;
            // 0x13ce14: 0xae130000  sw          $s3, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 19));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13CE18u; }
        if (ctx->pc != 0x13CE18u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13CE18u; }
        if (ctx->pc != 0x13CE18u) { return; }
    }
    ctx->pc = 0x13CE18u;
label_13ce18:
    // 0x13ce18: 0xae000008  sw          $zero, 0x8($s0)
    ctx->pc = 0x13ce18u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 0));
    // 0x13ce1c: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x13ce1cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13ce20: 0x10c00009  beqz        $a2, . + 4 + (0x9 << 2)
    ctx->pc = 0x13CE20u;
    {
        const bool branch_taken_0x13ce20 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        ctx->pc = 0x13CE24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13CE20u;
            // 0x13ce24: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13ce20) {
            ctx->pc = 0x13CE48u;
            goto label_13ce48;
        }
    }
    ctx->pc = 0x13CE28u;
label_13ce28:
    // 0x13ce28: 0x2451021  addu        $v0, $s2, $a1
    ctx->pc = 0x13ce28u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 5)));
    // 0x13ce2c: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x13ce2cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x13ce30: 0x90430000  lbu         $v1, 0x0($v0)
    ctx->pc = 0x13ce30u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x13ce34: 0xa6202b  sltu        $a0, $a1, $a2
    ctx->pc = 0x13ce34u;
    SET_GPR_U64(ctx, 4, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)GPR_U64(ctx, 6)) ? 1 : 0);
    // 0x13ce38: 0x8e020008  lw          $v0, 0x8($s0)
    ctx->pc = 0x13ce38u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x13ce3c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x13ce3cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x13ce40: 0x1480fff9  bnez        $a0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x13CE40u;
    {
        const bool branch_taken_0x13ce40 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x13CE44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13CE40u;
            // 0x13ce44: 0xae020008  sw          $v0, 0x8($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13ce40) {
            ctx->pc = 0x13CE28u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_13ce28;
        }
    }
    ctx->pc = 0x13CE48u;
label_13ce48:
    // 0x13ce48: 0xae140010  sw          $s4, 0x10($s0)
    ctx->pc = 0x13ce48u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 20));
    // 0x13ce4c: 0x24080001  addiu       $t0, $zero, 0x1
    ctx->pc = 0x13ce4cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x13ce50: 0xae150014  sw          $s5, 0x14($s0)
    ctx->pc = 0x13ce50u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 21));
    // 0x13ce54: 0xae00001c  sw          $zero, 0x1C($s0)
    ctx->pc = 0x13ce54u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 28), GPR_U32(ctx, 0));
    // 0x13ce58: 0xae000018  sw          $zero, 0x18($s0)
    ctx->pc = 0x13ce58u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 24), GPR_U32(ctx, 0));
    // 0x13ce5c: 0xae16000c  sw          $s6, 0xC($s0)
    ctx->pc = 0x13ce5cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 22));
    // 0x13ce60: 0x8e23001c  lw          $v1, 0x1C($s1)
    ctx->pc = 0x13ce60u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 28)));
    // 0x13ce64: 0x8e260024  lw          $a2, 0x24($s1)
    ctx->pc = 0x13ce64u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 36)));
    // 0x13ce68: 0x24640001  addiu       $a0, $v1, 0x1
    ctx->pc = 0x13ce68u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x13ce6c: 0x24630010  addiu       $v1, $v1, 0x10
    ctx->pc = 0x13ce6cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 16));
    // 0x13ce70: 0x28850000  slti        $a1, $a0, 0x0
    ctx->pc = 0x13ce70u;
    SET_GPR_U64(ctx, 5, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x13ce74: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x13ce74u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13ce78: 0x65100b  movn        $v0, $v1, $a1
    ctx->pc = 0x13ce78u;
    if (GPR_U64(ctx, 5) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 3));
    // 0x13ce7c: 0x82270001  lb          $a3, 0x1($s1)
    ctx->pc = 0x13ce7cu;
    SET_GPR_S32(ctx, 7, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 1)));
    // 0x13ce80: 0x21103  sra         $v0, $v0, 4
    ctx->pc = 0x13ce80u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 4));
    // 0x13ce84: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x13ce84u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x13ce88: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x13ce88u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x13ce8c: 0xae260024  sw          $a2, 0x24($s1)
    ctx->pc = 0x13ce8cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 36), GPR_U32(ctx, 6));
    // 0x13ce90: 0x822023  subu        $a0, $a0, $v0
    ctx->pc = 0x13ce90u;
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x13ce94: 0x14e80003  bne         $a3, $t0, . + 4 + (0x3 << 2)
    ctx->pc = 0x13CE94u;
    {
        const bool branch_taken_0x13ce94 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 8));
        ctx->pc = 0x13CE98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13CE94u;
            // 0x13ce98: 0xae24001c  sw          $a0, 0x1C($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 28), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13ce94) {
            ctx->pc = 0x13CEA4u;
            goto label_13cea4;
        }
    }
    ctx->pc = 0x13CE9Cu;
    // 0x13ce9c: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x13ce9cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x13cea0: 0xa2220001  sb          $v0, 0x1($s1)
    ctx->pc = 0x13cea0u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 1), (uint8_t)GPR_U32(ctx, 2));
label_13cea4:
    // 0x13cea4: 0x260102d  daddu       $v0, $s3, $zero
    ctx->pc = 0x13cea4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
label_13cea8:
    // 0x13cea8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13cea8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13ceac: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13ceacu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13ceb0: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x13ceb0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13ceb4: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x13ceb4u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13ceb8: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x13ceb8u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x13cebc: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x13cebcu;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x13cec0: 0xdfb60030  ld          $s6, 0x30($sp)
    ctx->pc = 0x13cec0u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x13cec4: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x13cec4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x13cec8: 0x3e00008  jr          $ra
    ctx->pc = 0x13CEC8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13CECCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13CEC8u;
            // 0x13cecc: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13CD80u: goto label_13cd80;
            case 0x13CD88u: goto label_13cd88;
            case 0x13CDACu: goto label_13cdac;
            case 0x13CDB8u: goto label_13cdb8;
            case 0x13CE18u: goto label_13ce18;
            case 0x13CE28u: goto label_13ce28;
            case 0x13CE48u: goto label_13ce48;
            case 0x13CEA4u: goto label_13cea4;
            case 0x13CEA8u: goto label_13cea8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13CED0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
