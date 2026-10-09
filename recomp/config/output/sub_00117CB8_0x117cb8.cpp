#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00117CB8
// Address: 0x117cb8 - 0x117eb0
void sub_00117CB8_0x117cb8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00117CB8_0x117cb8");
#endif

    switch (ctx->pc) {
        case 0x117cfcu: goto label_117cfc;
        case 0x117d40u: goto label_117d40;
        case 0x117da8u: goto label_117da8;
        case 0x117dd8u: goto label_117dd8;
        case 0x117e00u: goto label_117e00;
        case 0x117e38u: goto label_117e38;
        case 0x117e70u: goto label_117e70;
        case 0x117e98u: goto label_117e98;
        default: break;
    }

    ctx->pc = 0x117cb8u;

    // 0x117cb8: 0x27bdff80  addiu       $sp, $sp, -0x80
    ctx->pc = 0x117cb8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x117cbc: 0xffb60060  sd          $s6, 0x60($sp)
    ctx->pc = 0x117cbcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 22));
    // 0x117cc0: 0xffb50050  sd          $s5, 0x50($sp)
    ctx->pc = 0x117cc0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 21));
    // 0x117cc4: 0x140b02d  daddu       $s6, $t2, $zero
    ctx->pc = 0x117cc4u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
    // 0x117cc8: 0xffb40040  sd          $s4, 0x40($sp)
    ctx->pc = 0x117cc8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 20));
    // 0x117ccc: 0x80a82d  daddu       $s5, $a0, $zero
    ctx->pc = 0x117cccu;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x117cd0: 0xffb30030  sd          $s3, 0x30($sp)
    ctx->pc = 0x117cd0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 19));
    // 0x117cd4: 0x120a02d  daddu       $s4, $t1, $zero
    ctx->pc = 0x117cd4u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x117cd8: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x117cd8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x117cdc: 0x100982d  daddu       $s3, $t0, $zero
    ctx->pc = 0x117cdcu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x117ce0: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x117ce0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x117ce4: 0xe0902d  daddu       $s2, $a3, $zero
    ctx->pc = 0x117ce4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x117ce8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x117ce8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x117cec: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x117cecu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x117cf0: 0xffbf0070  sd          $ra, 0x70($sp)
    ctx->pc = 0x117cf0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 31));
    // 0x117cf4: 0xc047598  jal         func_11D660
    ctx->pc = 0x117CF4u;
    SET_GPR_U32(ctx, 31, 0x117CFCu);
    ctx->pc = 0x117CF8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x117CF4u;
            // 0x117cf8: 0xa0802d  daddu       $s0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117CFCu; }
        if (ctx->pc != 0x117CFCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117CFCu; }
        if (ctx->pc != 0x117CFCu) { return; }
    }
    ctx->pc = 0x117CFCu;
label_117cfc:
    // 0x117cfc: 0xaea0003c  sw          $zero, 0x3C($s5)
    ctx->pc = 0x117cfcu;
    WRITE32(ADD32(GPR_U32(ctx, 21), 60), GPR_U32(ctx, 0));
    // 0x117d00: 0xaea00038  sw          $zero, 0x38($s5)
    ctx->pc = 0x117d00u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 56), GPR_U32(ctx, 0));
    // 0x117d04: 0xaeb00000  sw          $s0, 0x0($s5)
    ctx->pc = 0x117d04u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 0), GPR_U32(ctx, 16));
    // 0x117d08: 0x8ec20008  lw          $v0, 0x8($s6)
    ctx->pc = 0x117d08u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 22), 8)));
    // 0x117d0c: 0xaeb10004  sw          $s1, 0x4($s5)
    ctx->pc = 0x117d0cu;
    WRITE32(ADD32(GPR_U32(ctx, 21), 4), GPR_U32(ctx, 17));
    // 0x117d10: 0xaeb20008  sw          $s2, 0x8($s5)
    ctx->pc = 0x117d10u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 8), GPR_U32(ctx, 18));
    // 0x117d14: 0xaeb30010  sw          $s3, 0x10($s5)
    ctx->pc = 0x117d14u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 16), GPR_U32(ctx, 19));
    // 0x117d18: 0xaeb40014  sw          $s4, 0x14($s5)
    ctx->pc = 0x117d18u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 20), GPR_U32(ctx, 20));
    // 0x117d1c: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x117D1Cu;
    {
        const bool branch_taken_0x117d1c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x117D20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x117D1Cu;
            // 0x117d20: 0xaeb60040  sw          $s6, 0x40($s5) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 21), 64), GPR_U32(ctx, 22));
        ctx->in_delay_slot = false;
        if (branch_taken_0x117d1c) {
            ctx->pc = 0x117D2Cu;
            goto label_117d2c;
        }
    }
    ctx->pc = 0x117D24u;
    // 0x117d24: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x117D24u;
    {
        const bool branch_taken_0x117d24 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x117D28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x117D24u;
            // 0x117d28: 0xaed50008  sw          $s5, 0x8($s6) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 22), 8), GPR_U32(ctx, 21));
        ctx->in_delay_slot = false;
        if (branch_taken_0x117d24) {
            ctx->pc = 0x117D60u;
            goto label_117d60;
        }
    }
    ctx->pc = 0x117D2Cu;
label_117d2c:
    // 0x117d2c: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x117d2cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x117d30: 0x8c830038  lw          $v1, 0x38($a0)
    ctx->pc = 0x117d30u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 56)));
    // 0x117d34: 0x5060000a  beql        $v1, $zero, . + 4 + (0xA << 2)
    ctx->pc = 0x117D34u;
    {
        const bool branch_taken_0x117d34 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x117d34) {
            ctx->pc = 0x117D38u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x117D34u;
            // 0x117d38: 0xac950038  sw          $s5, 0x38($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 56), GPR_U32(ctx, 21));
        ctx->in_delay_slot = false;
            ctx->pc = 0x117D60u;
            goto label_117d60;
        }
    }
    ctx->pc = 0x117D3Cu;
    // 0x117d3c: 0x0  nop
    ctx->pc = 0x117d3cu;
    // NOP
label_117d40:
    // 0x117d40: 0x60202d  daddu       $a0, $v1, $zero
    ctx->pc = 0x117d40u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x117d44: 0x8c820038  lw          $v0, 0x38($a0)
    ctx->pc = 0x117d44u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 56)));
    // 0x117d48: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x117d48u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x117d4c: 0x0  nop
    ctx->pc = 0x117d4cu;
    // NOP
    // 0x117d50: 0x0  nop
    ctx->pc = 0x117d50u;
    // NOP
    // 0x117d54: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x117D54u;
    {
        const bool branch_taken_0x117d54 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x117d54) {
            ctx->pc = 0x117D40u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_117d40;
        }
    }
    ctx->pc = 0x117D5Cu;
    // 0x117d5c: 0xac950038  sw          $s5, 0x38($a0)
    ctx->pc = 0x117d5cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 56), GPR_U32(ctx, 21));
label_117d60:
    // 0x117d60: 0xdfbf0070  ld          $ra, 0x70($sp)
    ctx->pc = 0x117d60u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x117d64: 0xdfb60060  ld          $s6, 0x60($sp)
    ctx->pc = 0x117d64u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x117d68: 0xdfb50050  ld          $s5, 0x50($sp)
    ctx->pc = 0x117d68u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x117d6c: 0xdfb40040  ld          $s4, 0x40($sp)
    ctx->pc = 0x117d6cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x117d70: 0xdfb30030  ld          $s3, 0x30($sp)
    ctx->pc = 0x117d70u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x117d74: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x117d74u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x117d78: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x117d78u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x117d7c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x117d7cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x117d80: 0x80475ae  j           func_11D6B8
    ctx->pc = 0x117D80u;
    ctx->pc = 0x117D84u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x117D80u;
            // 0x117d84: 0x27bd0080  addiu       $sp, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x117D88u;
    // 0x117d88: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x117d88u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x117d8c: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x117d8cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x117d90: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x117d90u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x117d94: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x117d94u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x117d98: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x117d98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x117d9c: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x117d9cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x117da0: 0xc047598  jal         func_11D660
    ctx->pc = 0x117DA0u;
    SET_GPR_U32(ctx, 31, 0x117DA8u);
    ctx->pc = 0x117DA4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x117DA0u;
            // 0x117da4: 0x80882d  daddu       $s1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117DA8u; }
        if (ctx->pc != 0x117DA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117DA8u; }
        if (ctx->pc != 0x117DA8u) { return; }
    }
    ctx->pc = 0x117DA8u;
label_117da8:
    // 0x117da8: 0x8e500008  lw          $s0, 0x8($s2)
    ctx->pc = 0x117da8u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 8)));
    // 0x117dac: 0x16110004  bne         $s0, $s1, . + 4 + (0x4 << 2)
    ctx->pc = 0x117DACu;
    {
        const bool branch_taken_0x117dac = (GPR_U64(ctx, 16) != GPR_U64(ctx, 17));
        if (branch_taken_0x117dac) {
            ctx->pc = 0x117DC0u;
            goto label_117dc0;
        }
    }
    ctx->pc = 0x117DB4u;
    // 0x117db4: 0x8e020038  lw          $v0, 0x38($s0)
    ctx->pc = 0x117db4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 56)));
    // 0x117db8: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x117DB8u;
    {
        const bool branch_taken_0x117db8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x117DBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x117DB8u;
            // 0x117dbc: 0xae420008  sw          $v0, 0x8($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 8), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x117db8) {
            ctx->pc = 0x117DF8u;
            goto label_117df8;
        }
    }
    ctx->pc = 0x117DC0u;
label_117dc0:
    // 0x117dc0: 0x1200000d  beqz        $s0, . + 4 + (0xD << 2)
    ctx->pc = 0x117DC0u;
    {
        const bool branch_taken_0x117dc0 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        if (branch_taken_0x117dc0) {
            ctx->pc = 0x117DF8u;
            goto label_117df8;
        }
    }
    ctx->pc = 0x117DC8u;
    // 0x117dc8: 0x8e030038  lw          $v1, 0x38($s0)
    ctx->pc = 0x117dc8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 56)));
    // 0x117dcc: 0x50710009  beql        $v1, $s1, . + 4 + (0x9 << 2)
    ctx->pc = 0x117DCCu;
    {
        const bool branch_taken_0x117dcc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 17));
        if (branch_taken_0x117dcc) {
            ctx->pc = 0x117DD0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x117DCCu;
            // 0x117dd0: 0x8e220038  lw          $v0, 0x38($s1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 56)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x117DF4u;
            goto label_117df4;
        }
    }
    ctx->pc = 0x117DD4u;
    // 0x117dd4: 0x0  nop
    ctx->pc = 0x117dd4u;
    // NOP
label_117dd8:
    // 0x117dd8: 0x60802d  daddu       $s0, $v1, $zero
    ctx->pc = 0x117dd8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x117ddc: 0x12000006  beqz        $s0, . + 4 + (0x6 << 2)
    ctx->pc = 0x117DDCu;
    {
        const bool branch_taken_0x117ddc = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        if (branch_taken_0x117ddc) {
            ctx->pc = 0x117DF8u;
            goto label_117df8;
        }
    }
    ctx->pc = 0x117DE4u;
    // 0x117de4: 0x8e020038  lw          $v0, 0x38($s0)
    ctx->pc = 0x117de4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 56)));
    // 0x117de8: 0x1451fffb  bne         $v0, $s1, . + 4 + (-0x5 << 2)
    ctx->pc = 0x117DE8u;
    {
        const bool branch_taken_0x117de8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 17));
        ctx->pc = 0x117DECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x117DE8u;
            // 0x117dec: 0x40182d  daddu       $v1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x117de8) {
            ctx->pc = 0x117DD8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_117dd8;
        }
    }
    ctx->pc = 0x117DF0u;
    // 0x117df0: 0x8e220038  lw          $v0, 0x38($s1)
    ctx->pc = 0x117df0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 56)));
label_117df4:
    // 0x117df4: 0xae020038  sw          $v0, 0x38($s0)
    ctx->pc = 0x117df4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 56), GPR_U32(ctx, 2));
label_117df8:
    // 0x117df8: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x117DF8u;
    SET_GPR_U32(ctx, 31, 0x117E00u);
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117E00u; }
        if (ctx->pc != 0x117E00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117E00u; }
        if (ctx->pc != 0x117E00u) { return; }
    }
    ctx->pc = 0x117E00u;
label_117e00:
    // 0x117e00: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x117e00u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x117e04: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x117e04u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x117e08: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x117e08u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x117e0c: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x117e0cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x117e10: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x117e10u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x117e14: 0x3e00008  jr          $ra
    ctx->pc = 0x117E14u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x117E18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x117E14u;
            // 0x117e18: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x117CFCu: goto label_117cfc;
            case 0x117D2Cu: goto label_117d2c;
            case 0x117D40u: goto label_117d40;
            case 0x117D60u: goto label_117d60;
            case 0x117DA8u: goto label_117da8;
            case 0x117DC0u: goto label_117dc0;
            case 0x117DD8u: goto label_117dd8;
            case 0x117DF4u: goto label_117df4;
            case 0x117DF8u: goto label_117df8;
            case 0x117E00u: goto label_117e00;
            case 0x117E38u: goto label_117e38;
            case 0x117E58u: goto label_117e58;
            case 0x117E70u: goto label_117e70;
            case 0x117E8Cu: goto label_117e8c;
            case 0x117E90u: goto label_117e90;
            case 0x117E98u: goto label_117e98;
            default: break;
        }
        return;
    }
    ctx->pc = 0x117E1Cu;
    // 0x117e1c: 0x0  nop
    ctx->pc = 0x117e1cu;
    // NOP
    // 0x117e20: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x117e20u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x117e24: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x117e24u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x117e28: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x117e28u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x117e2c: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x117e2cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x117e30: 0xc047598  jal         func_11D660
    ctx->pc = 0x117E30u;
    SET_GPR_U32(ctx, 31, 0x117E38u);
    ctx->pc = 0x117E34u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x117E30u;
            // 0x117e34: 0x80882d  daddu       $s1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117E38u; }
        if (ctx->pc != 0x117E38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117E38u; }
        if (ctx->pc != 0x117E38u) { return; }
    }
    ctx->pc = 0x117E38u;
label_117e38:
    // 0x117e38: 0x3c030026  lui         $v1, 0x26
    ctx->pc = 0x117e38u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)38 << 16));
    // 0x117e3c: 0x2463c9c0  addiu       $v1, $v1, -0x3640
    ctx->pc = 0x117e3cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294953408));
    // 0x117e40: 0x8c700028  lw          $s0, 0x28($v1)
    ctx->pc = 0x117e40u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 40)));
    // 0x117e44: 0x16110004  bne         $s0, $s1, . + 4 + (0x4 << 2)
    ctx->pc = 0x117E44u;
    {
        const bool branch_taken_0x117e44 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 17));
        if (branch_taken_0x117e44) {
            ctx->pc = 0x117E58u;
            goto label_117e58;
        }
    }
    ctx->pc = 0x117E4Cu;
    // 0x117e4c: 0x8e020014  lw          $v0, 0x14($s0)
    ctx->pc = 0x117e4cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x117e50: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x117E50u;
    {
        const bool branch_taken_0x117e50 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x117E54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x117E50u;
            // 0x117e54: 0xac620028  sw          $v0, 0x28($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 40), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x117e50) {
            ctx->pc = 0x117E90u;
            goto label_117e90;
        }
    }
    ctx->pc = 0x117E58u;
label_117e58:
    // 0x117e58: 0x1200000d  beqz        $s0, . + 4 + (0xD << 2)
    ctx->pc = 0x117E58u;
    {
        const bool branch_taken_0x117e58 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        if (branch_taken_0x117e58) {
            ctx->pc = 0x117E90u;
            goto label_117e90;
        }
    }
    ctx->pc = 0x117E60u;
    // 0x117e60: 0x8e030014  lw          $v1, 0x14($s0)
    ctx->pc = 0x117e60u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x117e64: 0x50710009  beql        $v1, $s1, . + 4 + (0x9 << 2)
    ctx->pc = 0x117E64u;
    {
        const bool branch_taken_0x117e64 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 17));
        if (branch_taken_0x117e64) {
            ctx->pc = 0x117E68u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x117E64u;
            // 0x117e68: 0x8e220014  lw          $v0, 0x14($s1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x117E8Cu;
            goto label_117e8c;
        }
    }
    ctx->pc = 0x117E6Cu;
    // 0x117e6c: 0x0  nop
    ctx->pc = 0x117e6cu;
    // NOP
label_117e70:
    // 0x117e70: 0x60802d  daddu       $s0, $v1, $zero
    ctx->pc = 0x117e70u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x117e74: 0x12000006  beqz        $s0, . + 4 + (0x6 << 2)
    ctx->pc = 0x117E74u;
    {
        const bool branch_taken_0x117e74 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        if (branch_taken_0x117e74) {
            ctx->pc = 0x117E90u;
            goto label_117e90;
        }
    }
    ctx->pc = 0x117E7Cu;
    // 0x117e7c: 0x8e020014  lw          $v0, 0x14($s0)
    ctx->pc = 0x117e7cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x117e80: 0x1451fffb  bne         $v0, $s1, . + 4 + (-0x5 << 2)
    ctx->pc = 0x117E80u;
    {
        const bool branch_taken_0x117e80 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 17));
        ctx->pc = 0x117E84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x117E80u;
            // 0x117e84: 0x40182d  daddu       $v1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x117e80) {
            ctx->pc = 0x117E70u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_117e70;
        }
    }
    ctx->pc = 0x117E88u;
    // 0x117e88: 0x8e220014  lw          $v0, 0x14($s1)
    ctx->pc = 0x117e88u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
label_117e8c:
    // 0x117e8c: 0xae020014  sw          $v0, 0x14($s0)
    ctx->pc = 0x117e8cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 2));
label_117e90:
    // 0x117e90: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x117E90u;
    SET_GPR_U32(ctx, 31, 0x117E98u);
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117E98u; }
        if (ctx->pc != 0x117E98u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117E98u; }
        if (ctx->pc != 0x117E98u) { return; }
    }
    ctx->pc = 0x117E98u;
label_117e98:
    // 0x117e98: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x117e98u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x117e9c: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x117e9cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x117ea0: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x117ea0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x117ea4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x117ea4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x117ea8: 0x3e00008  jr          $ra
    ctx->pc = 0x117EA8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x117EACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x117EA8u;
            // 0x117eac: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x117CFCu: goto label_117cfc;
            case 0x117D2Cu: goto label_117d2c;
            case 0x117D40u: goto label_117d40;
            case 0x117D60u: goto label_117d60;
            case 0x117DA8u: goto label_117da8;
            case 0x117DC0u: goto label_117dc0;
            case 0x117DD8u: goto label_117dd8;
            case 0x117DF4u: goto label_117df4;
            case 0x117DF8u: goto label_117df8;
            case 0x117E00u: goto label_117e00;
            case 0x117E38u: goto label_117e38;
            case 0x117E58u: goto label_117e58;
            case 0x117E70u: goto label_117e70;
            case 0x117E8Cu: goto label_117e8c;
            case 0x117E90u: goto label_117e90;
            case 0x117E98u: goto label_117e98;
            default: break;
        }
        return;
    }
    ctx->pc = 0x117EB0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
