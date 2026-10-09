#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011CCA8
// Address: 0x11cca8 - 0x11cea0
void sub_0011CCA8_0x11cca8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011CCA8_0x11cca8");
#endif

    switch (ctx->pc) {
        case 0x11ccd0u: goto label_11ccd0;
        case 0x11cd14u: goto label_11cd14;
        case 0x11cd24u: goto label_11cd24;
        case 0x11cd2cu: goto label_11cd2c;
        case 0x11cd40u: goto label_11cd40;
        case 0x11cd78u: goto label_11cd78;
        case 0x11cda4u: goto label_11cda4;
        case 0x11cde8u: goto label_11cde8;
        case 0x11cdf4u: goto label_11cdf4;
        case 0x11ce00u: goto label_11ce00;
        case 0x11ce70u: goto label_11ce70;
        case 0x11ce88u: goto label_11ce88;
        default: break;
    }

    ctx->pc = 0x11cca8u;

    // 0x11cca8: 0x27bdff80  addiu       $sp, $sp, -0x80
    ctx->pc = 0x11cca8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x11ccac: 0x3c020024  lui         $v0, 0x24
    ctx->pc = 0x11ccacu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
    // 0x11ccb0: 0xffb10060  sd          $s1, 0x60($sp)
    ctx->pc = 0x11ccb0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 17));
    // 0x11ccb4: 0xffb00050  sd          $s0, 0x50($sp)
    ctx->pc = 0x11ccb4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 16));
    // 0x11ccb8: 0xffbf0070  sd          $ra, 0x70($sp)
    ctx->pc = 0x11ccb8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 31));
    // 0x11ccbc: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x11ccbcu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ccc0: 0x82030000  lb          $v1, 0x0($s0)
    ctx->pc = 0x11ccc0u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x11ccc4: 0x1060000b  beqz        $v1, . + 4 + (0xB << 2)
    ctx->pc = 0x11CCC4u;
    {
        const bool branch_taken_0x11ccc4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x11CCC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11CCC4u;
            // 0x11ccc8: 0x24518ba0  addiu       $s1, $v0, -0x7460 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937504));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11ccc4) {
            ctx->pc = 0x11CCF4u;
            goto label_11ccf4;
        }
    }
    ctx->pc = 0x11CCCCu;
    // 0x11cccc: 0x2603fff5  addiu       $v1, $s0, -0xB
    ctx->pc = 0x11ccccu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967285));
label_11ccd0:
    // 0x11ccd0: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x11ccd0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x11ccd4: 0x80820000  lb          $v0, 0x0($a0)
    ctx->pc = 0x11ccd4u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x11ccd8: 0x0  nop
    ctx->pc = 0x11ccd8u;
    // NOP
    // 0x11ccdc: 0x0  nop
    ctx->pc = 0x11ccdcu;
    // NOP
    // 0x11cce0: 0x0  nop
    ctx->pc = 0x11cce0u;
    // NOP
    // 0x11cce4: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x11CCE4u;
    {
        const bool branch_taken_0x11cce4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x11cce4) {
            ctx->pc = 0x11CCD0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_11ccd0;
        }
    }
    ctx->pc = 0x11CCECu;
    // 0x11ccec: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x11CCECu;
    {
        const bool branch_taken_0x11ccec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11CCF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11CCECu;
            // 0x11ccf0: 0x831023  subu        $v0, $a0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11ccec) {
            ctx->pc = 0x11CCFCu;
            goto label_11ccfc;
        }
    }
    ctx->pc = 0x11CCF4u;
label_11ccf4:
    // 0x11ccf4: 0x2603fff5  addiu       $v1, $s0, -0xB
    ctx->pc = 0x11ccf4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967285));
    // 0x11ccf8: 0x831023  subu        $v0, $a0, $v1
    ctx->pc = 0x11ccf8u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
label_11ccfc:
    // 0x11ccfc: 0x2c420051  sltiu       $v0, $v0, 0x51
    ctx->pc = 0x11ccfcu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)81) ? 1 : 0);
    // 0x11cd00: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x11CD00u;
    {
        const bool branch_taken_0x11cd00 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x11CD04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11CD00u;
            // 0x11cd04: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11cd00) {
            ctx->pc = 0x11CD1Cu;
            goto label_11cd1c;
        }
    }
    ctx->pc = 0x11CD08u;
    // 0x11cd08: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x11cd08u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11cd0c: 0xc045a12  jal         func_116848
    ctx->pc = 0x11CD0Cu;
    SET_GPR_U32(ctx, 31, 0x11CD14u);
    ctx->pc = 0x11CD10u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11CD0Cu;
            // 0x11cd10: 0x24848bb0  addiu       $a0, $a0, -0x7450 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294937520));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CD14u; }
        if (ctx->pc != 0x11CD14u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CD14u; }
        if (ctx->pc != 0x11CD14u) { return; }
    }
    ctx->pc = 0x11CD14u;
label_11cd14:
    // 0x11cd14: 0x10000023  b           . + 4 + (0x23 << 2)
    ctx->pc = 0x11CD14u;
    {
        const bool branch_taken_0x11cd14 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11CD18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11CD14u;
            // 0x11cd18: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11cd14) {
            ctx->pc = 0x11CDA4u;
            goto label_11cda4;
        }
    }
    ctx->pc = 0x11CD1Cu;
label_11cd1c:
    // 0x11cd1c: 0xc045c20  jal         func_117080
    ctx->pc = 0x11CD1Cu;
    SET_GPR_U32(ctx, 31, 0x11CD24u);
    ctx->pc = 0x11CD20u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11CD1Cu;
            // 0x11cd20: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x117080u;
    if (runtime->hasFunction(0x117080u)) {
        auto targetFn = runtime->lookupFunction(0x117080u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CD24u; }
        if (ctx->pc != 0x11CD24u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00117080_0x117080(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CD24u; }
        if (ctx->pc != 0x11CD24u) { return; }
    }
    ctx->pc = 0x11CD24u;
label_11cd24:
    // 0x11cd24: 0xc045c88  jal         func_117220
    ctx->pc = 0x11CD24u;
    SET_GPR_U32(ctx, 31, 0x11CD2Cu);
    ctx->pc = 0x117220u;
    if (runtime->hasFunction(0x117220u)) {
        auto targetFn = runtime->lookupFunction(0x117220u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CD2Cu; }
        if (ctx->pc != 0x11CD2Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00117220_0x117220(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CD2Cu; }
        if (ctx->pc != 0x11CD2Cu) { return; }
    }
    ctx->pc = 0x11CD2Cu;
label_11cd2c:
    // 0x11cd2c: 0x82220000  lb          $v0, 0x0($s1)
    ctx->pc = 0x11cd2cu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x11cd30: 0x3a0182d  daddu       $v1, $sp, $zero
    ctx->pc = 0x11cd30u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11cd34: 0x1040000b  beqz        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x11CD34u;
    {
        const bool branch_taken_0x11cd34 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x11CD38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11CD34u;
            // 0x11cd38: 0x92240000  lbu         $a0, 0x0($s1) (Delay Slot)
        SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11cd34) {
            ctx->pc = 0x11CD64u;
            goto label_11cd64;
        }
    }
    ctx->pc = 0x11CD3Cu;
    // 0x11cd3c: 0x92050000  lbu         $a1, 0x0($s0)
    ctx->pc = 0x11cd3cu;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
label_11cd40:
    // 0x11cd40: 0xa0640000  sb          $a0, 0x0($v1)
    ctx->pc = 0x11cd40u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x11cd44: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x11cd44u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x11cd48: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x11cd48u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x11cd4c: 0x92240000  lbu         $a0, 0x0($s1)
    ctx->pc = 0x11cd4cu;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x11cd50: 0x82220000  lb          $v0, 0x0($s1)
    ctx->pc = 0x11cd50u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x11cd54: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x11CD54u;
    {
        const bool branch_taken_0x11cd54 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x11cd54) {
            ctx->pc = 0x11CD40u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_11cd40;
        }
    }
    ctx->pc = 0x11CD5Cu;
    // 0x11cd5c: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x11CD5Cu;
    {
        const bool branch_taken_0x11cd5c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11CD60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11CD5Cu;
            // 0x11cd60: 0xa0202d  daddu       $a0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11cd5c) {
            ctx->pc = 0x11CD6Cu;
            goto label_11cd6c;
        }
    }
    ctx->pc = 0x11CD64u;
label_11cd64:
    // 0x11cd64: 0x92050000  lbu         $a1, 0x0($s0)
    ctx->pc = 0x11cd64u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x11cd68: 0xa0202d  daddu       $a0, $a1, $zero
    ctx->pc = 0x11cd68u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
label_11cd6c:
    // 0x11cd6c: 0x5080000a  beql        $a0, $zero, . + 4 + (0xA << 2)
    ctx->pc = 0x11CD6Cu;
    {
        const bool branch_taken_0x11cd6c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x11cd6c) {
            ctx->pc = 0x11CD70u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11CD6Cu;
            // 0x11cd70: 0xa0600000  sb          $zero, 0x0($v1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11CD98u;
            goto label_11cd98;
        }
    }
    ctx->pc = 0x11CD74u;
    // 0x11cd74: 0x0  nop
    ctx->pc = 0x11cd74u;
    // NOP
label_11cd78:
    // 0x11cd78: 0xa0640000  sb          $a0, 0x0($v1)
    ctx->pc = 0x11cd78u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x11cd7c: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x11cd7cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x11cd80: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x11cd80u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x11cd84: 0x82020000  lb          $v0, 0x0($s0)
    ctx->pc = 0x11cd84u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x11cd88: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x11cd88u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11cd8c: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x11CD8Cu;
    {
        const bool branch_taken_0x11cd8c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x11cd8c) {
            ctx->pc = 0x11CD78u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_11cd78;
        }
    }
    ctx->pc = 0x11CD94u;
    // 0x11cd94: 0xa0600000  sb          $zero, 0x0($v1)
    ctx->pc = 0x11cd94u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 0));
label_11cd98:
    // 0x11cd98: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x11cd98u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11cd9c: 0xc0472b6  jal         func_11CAD8
    ctx->pc = 0x11CD9Cu;
    SET_GPR_U32(ctx, 31, 0x11CDA4u);
    ctx->pc = 0x11CDA0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11CD9Cu;
            // 0x11cda0: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11CAD8u;
    if (runtime->hasFunction(0x11CAD8u)) {
        auto targetFn = runtime->lookupFunction(0x11CAD8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CDA4u; }
        if (ctx->pc != 0x11CDA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011CAD8_0x11cad8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CDA4u; }
        if (ctx->pc != 0x11CDA4u) { return; }
    }
    ctx->pc = 0x11CDA4u;
label_11cda4:
    // 0x11cda4: 0xdfbf0070  ld          $ra, 0x70($sp)
    ctx->pc = 0x11cda4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x11cda8: 0xdfb10060  ld          $s1, 0x60($sp)
    ctx->pc = 0x11cda8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x11cdac: 0xdfb00050  ld          $s0, 0x50($sp)
    ctx->pc = 0x11cdacu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x11cdb0: 0x3e00008  jr          $ra
    ctx->pc = 0x11CDB0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11CDB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11CDB0u;
            // 0x11cdb4: 0x27bd0080  addiu       $sp, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11CCD0u: goto label_11ccd0;
            case 0x11CCF4u: goto label_11ccf4;
            case 0x11CCFCu: goto label_11ccfc;
            case 0x11CD14u: goto label_11cd14;
            case 0x11CD1Cu: goto label_11cd1c;
            case 0x11CD24u: goto label_11cd24;
            case 0x11CD2Cu: goto label_11cd2c;
            case 0x11CD40u: goto label_11cd40;
            case 0x11CD64u: goto label_11cd64;
            case 0x11CD6Cu: goto label_11cd6c;
            case 0x11CD78u: goto label_11cd78;
            case 0x11CD98u: goto label_11cd98;
            case 0x11CDA4u: goto label_11cda4;
            case 0x11CDE8u: goto label_11cde8;
            case 0x11CDF4u: goto label_11cdf4;
            case 0x11CE00u: goto label_11ce00;
            case 0x11CE40u: goto label_11ce40;
            case 0x11CE70u: goto label_11ce70;
            case 0x11CE78u: goto label_11ce78;
            case 0x11CE88u: goto label_11ce88;
            case 0x11CE8Cu: goto label_11ce8c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11CDB8u;
    // 0x11cdb8: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x11cdb8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x11cdbc: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x11cdbcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x11cdc0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x11cdc0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x11cdc4: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x11cdc4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x11cdc8: 0x3c100012  lui         $s0, 0x12
    ctx->pc = 0x11cdc8u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)18 << 16));
    // 0x11cdcc: 0x2610d300  addiu       $s0, $s0, -0x2D00
    ctx->pc = 0x11cdccu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294955776));
    // 0x11cdd0: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x11cdd0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11cdd4: 0xac51a138  sw          $s1, -0x5EC8($v0)
    ctx->pc = 0x11cdd4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4294943032), GPR_U32(ctx, 17));
    // 0x11cdd8: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x11cdd8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11cddc: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x11cddcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x11cde0: 0xc0450b4  jal         func_1142D0
    ctx->pc = 0x11CDE0u;
    SET_GPR_U32(ctx, 31, 0x11CDE8u);
    ctx->pc = 0x11CDE4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11CDE0u;
            // 0x11cde4: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1142D0u;
    if (runtime->hasFunction(0x1142D0u)) {
        auto targetFn = runtime->lookupFunction(0x1142D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CDE8u; }
        if (ctx->pc != 0x11CDE8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001142D0_0x1142d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CDE8u; }
        if (ctx->pc != 0x11CDE8u) { return; }
    }
    ctx->pc = 0x11CDE8u;
label_11cde8:
    // 0x11cde8: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x11cde8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11cdec: 0xc0450b4  jal         func_1142D0
    ctx->pc = 0x11CDECu;
    SET_GPR_U32(ctx, 31, 0x11CDF4u);
    ctx->pc = 0x11CDF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11CDECu;
            // 0x11cdf0: 0x24040002  addiu       $a0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1142D0u;
    if (runtime->hasFunction(0x1142D0u)) {
        auto targetFn = runtime->lookupFunction(0x1142D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CDF4u; }
        if (ctx->pc != 0x11CDF4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001142D0_0x1142d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CDF4u; }
        if (ctx->pc != 0x11CDF4u) { return; }
    }
    ctx->pc = 0x11CDF4u;
label_11cdf4:
    // 0x11cdf4: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x11cdf4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11cdf8: 0xc0450b4  jal         func_1142D0
    ctx->pc = 0x11CDF8u;
    SET_GPR_U32(ctx, 31, 0x11CE00u);
    ctx->pc = 0x11CDFCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11CDF8u;
            // 0x11cdfc: 0x24040003  addiu       $a0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1142D0u;
    if (runtime->hasFunction(0x1142D0u)) {
        auto targetFn = runtime->lookupFunction(0x1142D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CE00u; }
        if (ctx->pc != 0x11CE00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001142D0_0x1142d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CE00u; }
        if (ctx->pc != 0x11CE00u) { return; }
    }
    ctx->pc = 0x11CE00u;
label_11ce00:
    // 0x11ce00: 0x220102d  daddu       $v0, $s1, $zero
    ctx->pc = 0x11ce00u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ce04: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x11ce04u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11ce08: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x11ce08u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11ce0c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x11ce0cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11ce10: 0x3e00008  jr          $ra
    ctx->pc = 0x11CE10u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11CE14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11CE10u;
            // 0x11ce14: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11CCD0u: goto label_11ccd0;
            case 0x11CCF4u: goto label_11ccf4;
            case 0x11CCFCu: goto label_11ccfc;
            case 0x11CD14u: goto label_11cd14;
            case 0x11CD1Cu: goto label_11cd1c;
            case 0x11CD24u: goto label_11cd24;
            case 0x11CD2Cu: goto label_11cd2c;
            case 0x11CD40u: goto label_11cd40;
            case 0x11CD64u: goto label_11cd64;
            case 0x11CD6Cu: goto label_11cd6c;
            case 0x11CD78u: goto label_11cd78;
            case 0x11CD98u: goto label_11cd98;
            case 0x11CDA4u: goto label_11cda4;
            case 0x11CDE8u: goto label_11cde8;
            case 0x11CDF4u: goto label_11cdf4;
            case 0x11CE00u: goto label_11ce00;
            case 0x11CE40u: goto label_11ce40;
            case 0x11CE70u: goto label_11ce70;
            case 0x11CE78u: goto label_11ce78;
            case 0x11CE88u: goto label_11ce88;
            case 0x11CE8Cu: goto label_11ce8c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11CE18u;
    // 0x11ce18: 0x80302d  daddu       $a2, $a0, $zero
    ctx->pc = 0x11ce18u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ce1c: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x11ce1cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x11ce20: 0x24c4ffff  addiu       $a0, $a2, -0x1
    ctx->pc = 0x11ce20u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x11ce24: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x11ce24u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x11ce28: 0x2c82000d  sltiu       $v0, $a0, 0xD
    ctx->pc = 0x11ce28u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)(int64_t)(int32_t)13) ? 1 : 0);
    // 0x11ce2c: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x11CE2Cu;
    {
        const bool branch_taken_0x11ce2c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x11CE30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11CE2Cu;
            // 0x11ce30: 0xffb00000  sd          $s0, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11ce2c) {
            ctx->pc = 0x11CE40u;
            goto label_11ce40;
        }
    }
    ctx->pc = 0x11CE34u;
    // 0x11ce34: 0x3c02ffff  lui         $v0, 0xFFFF
    ctx->pc = 0x11ce34u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65535 << 16));
    // 0x11ce38: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x11CE38u;
    {
        const bool branch_taken_0x11ce38 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11CE3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11CE38u;
            // 0x11ce3c: 0x3442ffff  ori         $v0, $v0, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x11ce38) {
            ctx->pc = 0x11CE8Cu;
            goto label_11ce8c;
        }
    }
    ctx->pc = 0x11CE40u;
label_11ce40:
    // 0x11ce40: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x11ce40u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x11ce44: 0x61880  sll         $v1, $a2, 2
    ctx->pc = 0x11ce44u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 6), 2));
    // 0x11ce48: 0x2442a140  addiu       $v0, $v0, -0x5EC0
    ctx->pc = 0x11ce48u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294943040));
    // 0x11ce4c: 0x2c840003  sltiu       $a0, $a0, 0x3
    ctx->pc = 0x11ce4cu;
    SET_GPR_U64(ctx, 4, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)(int64_t)(int32_t)3) ? 1 : 0);
    // 0x11ce50: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x11ce50u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x11ce54: 0x8c700000  lw          $s0, 0x0($v1)
    ctx->pc = 0x11ce54u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x11ce58: 0x10800007  beqz        $a0, . + 4 + (0x7 << 2)
    ctx->pc = 0x11CE58u;
    {
        const bool branch_taken_0x11ce58 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x11CE5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11CE58u;
            // 0x11ce5c: 0xac650000  sw          $a1, 0x0($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11ce58) {
            ctx->pc = 0x11CE78u;
            goto label_11ce78;
        }
    }
    ctx->pc = 0x11CE60u;
    // 0x11ce60: 0x3c050012  lui         $a1, 0x12
    ctx->pc = 0x11ce60u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)18 << 16));
    // 0x11ce64: 0xc0202d  daddu       $a0, $a2, $zero
    ctx->pc = 0x11ce64u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ce68: 0xc0450b4  jal         func_1142D0
    ctx->pc = 0x11CE68u;
    SET_GPR_U32(ctx, 31, 0x11CE70u);
    ctx->pc = 0x11CE6Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11CE68u;
            // 0x11ce6c: 0x24a5d540  addiu       $a1, $a1, -0x2AC0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294956352));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1142D0u;
    if (runtime->hasFunction(0x1142D0u)) {
        auto targetFn = runtime->lookupFunction(0x1142D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CE70u; }
        if (ctx->pc != 0x11CE70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001142D0_0x1142d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CE70u; }
        if (ctx->pc != 0x11CE70u) { return; }
    }
    ctx->pc = 0x11CE70u;
label_11ce70:
    // 0x11ce70: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x11CE70u;
    {
        const bool branch_taken_0x11ce70 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11CE74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11CE70u;
            // 0x11ce74: 0x200102d  daddu       $v0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11ce70) {
            ctx->pc = 0x11CE8Cu;
            goto label_11ce8c;
        }
    }
    ctx->pc = 0x11CE78u;
label_11ce78:
    // 0x11ce78: 0x3c050012  lui         $a1, 0x12
    ctx->pc = 0x11ce78u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)18 << 16));
    // 0x11ce7c: 0xc0202d  daddu       $a0, $a2, $zero
    ctx->pc = 0x11ce7cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ce80: 0xc0450b8  jal         func_1142E0
    ctx->pc = 0x11CE80u;
    SET_GPR_U32(ctx, 31, 0x11CE88u);
    ctx->pc = 0x11CE84u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11CE80u;
            // 0x11ce84: 0x24a5d540  addiu       $a1, $a1, -0x2AC0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294956352));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1142E0u;
    if (runtime->hasFunction(0x1142E0u)) {
        auto targetFn = runtime->lookupFunction(0x1142E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CE88u; }
        if (ctx->pc != 0x11CE88u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001142E0_0x1142e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CE88u; }
        if (ctx->pc != 0x11CE88u) { return; }
    }
    ctx->pc = 0x11CE88u;
label_11ce88:
    // 0x11ce88: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x11ce88u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_11ce8c:
    // 0x11ce8c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x11ce8cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11ce90: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x11ce90u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11ce94: 0x3e00008  jr          $ra
    ctx->pc = 0x11CE94u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11CE98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11CE94u;
            // 0x11ce98: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11CCD0u: goto label_11ccd0;
            case 0x11CCF4u: goto label_11ccf4;
            case 0x11CCFCu: goto label_11ccfc;
            case 0x11CD14u: goto label_11cd14;
            case 0x11CD1Cu: goto label_11cd1c;
            case 0x11CD24u: goto label_11cd24;
            case 0x11CD2Cu: goto label_11cd2c;
            case 0x11CD40u: goto label_11cd40;
            case 0x11CD64u: goto label_11cd64;
            case 0x11CD6Cu: goto label_11cd6c;
            case 0x11CD78u: goto label_11cd78;
            case 0x11CD98u: goto label_11cd98;
            case 0x11CDA4u: goto label_11cda4;
            case 0x11CDE8u: goto label_11cde8;
            case 0x11CDF4u: goto label_11cdf4;
            case 0x11CE00u: goto label_11ce00;
            case 0x11CE40u: goto label_11ce40;
            case 0x11CE70u: goto label_11ce70;
            case 0x11CE78u: goto label_11ce78;
            case 0x11CE88u: goto label_11ce88;
            case 0x11CE8Cu: goto label_11ce8c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11CE9Cu;
    // 0x11ce9c: 0x0  nop
    ctx->pc = 0x11ce9cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
