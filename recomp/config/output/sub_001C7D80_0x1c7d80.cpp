#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C7D80
// Address: 0x1c7d80 - 0x1c7df0
void sub_001C7D80_0x1c7d80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C7D80_0x1c7d80");
#endif

    switch (ctx->pc) {
        case 0x1c7db4u: goto label_1c7db4;
        case 0x1c7dccu: goto label_1c7dcc;
        default: break;
    }

    ctx->pc = 0x1c7d80u;

    // 0x1c7d80: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1c7d80u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1c7d84: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1c7d84u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1c7d88: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1c7d88u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1c7d8c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c7d8cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c7d90: 0x1ca00002  bgtz        $a1, . + 4 + (0x2 << 2)
    ctx->pc = 0x1C7D90u;
    {
        const bool branch_taken_0x1c7d90 = (GPR_S64(ctx, 5) > 0);
        ctx->pc = 0x1C7D94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7D90u;
            // 0x1c7d94: 0x80882d  daddu       $s1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c7d90) {
            ctx->pc = 0x1C7D9Cu;
            goto label_1c7d9c;
        }
    }
    ctx->pc = 0x1C7D98u;
    // 0x1c7d98: 0x8e250004  lw          $a1, 0x4($s1)
    ctx->pc = 0x1c7d98u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
label_1c7d9c:
    // 0x1c7d9c: 0x8e22000c  lw          $v0, 0xC($s1)
    ctx->pc = 0x1c7d9cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
    // 0x1c7da0: 0x458023  subu        $s0, $v0, $a1
    ctx->pc = 0x1c7da0u;
    SET_GPR_S32(ctx, 16, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x1c7da4: 0x1e000005  bgtz        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1C7DA4u;
    {
        const bool branch_taken_0x1c7da4 = (GPR_S64(ctx, 16) > 0);
        ctx->pc = 0x1C7DA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7DA4u;
            // 0x1c7da8: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c7da4) {
            ctx->pc = 0x1C7DBCu;
            goto label_1c7dbc;
        }
    }
    ctx->pc = 0x1C7DACu;
    // 0x1c7dac: 0xc071f40  jal         func_1C7D00
    ctx->pc = 0x1C7DACu;
    SET_GPR_U32(ctx, 31, 0x1C7DB4u);
    ctx->pc = 0x1C7D00u;
    if (runtime->hasFunction(0x1C7D00u)) {
        auto targetFn = runtime->lookupFunction(0x1C7D00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C7DB4u; }
        if (ctx->pc != 0x1C7DB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7D00_0x1c7d00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C7DB4u; }
        if (ctx->pc != 0x1C7DB4u) { return; }
    }
    ctx->pc = 0x1C7DB4u;
label_1c7db4:
    // 0x1c7db4: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1C7DB4u;
    {
        const bool branch_taken_0x1c7db4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C7DB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7DB4u;
            // 0x1c7db8: 0xdfbf0020  ld          $ra, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c7db4) {
            ctx->pc = 0x1C7DD8u;
            goto label_1c7dd8;
        }
    }
    ctx->pc = 0x1C7DBCu;
label_1c7dbc:
    // 0x1c7dbc: 0x8e240008  lw          $a0, 0x8($s1)
    ctx->pc = 0x1c7dbcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x1c7dc0: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x1c7dc0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c7dc4: 0xc041ed8  jal         func_107B60
    ctx->pc = 0x1C7DC4u;
    SET_GPR_U32(ctx, 31, 0x1C7DCCu);
    ctx->pc = 0x1C7DC8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7DC4u;
            // 0x1c7dc8: 0x852821  addu        $a1, $a0, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107B60u;
    if (runtime->hasFunction(0x107B60u)) {
        auto targetFn = runtime->lookupFunction(0x107B60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C7DCCu; }
        if (ctx->pc != 0x1C7DCCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107B60_0x107b60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C7DCCu; }
        if (ctx->pc != 0x1C7DCCu) { return; }
    }
    ctx->pc = 0x1C7DCCu;
label_1c7dcc:
    // 0x1c7dcc: 0xae30000c  sw          $s0, 0xC($s1)
    ctx->pc = 0x1c7dccu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 12), GPR_U32(ctx, 16));
    // 0x1c7dd0: 0xae200004  sw          $zero, 0x4($s1)
    ctx->pc = 0x1c7dd0u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 0));
    // 0x1c7dd4: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1c7dd4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_1c7dd8:
    // 0x1c7dd8: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1c7dd8u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c7ddc: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c7ddcu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c7de0: 0x3e00008  jr          $ra
    ctx->pc = 0x1C7DE0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C7DE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7DE0u;
            // 0x1c7de4: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C7D9Cu: goto label_1c7d9c;
            case 0x1C7DB4u: goto label_1c7db4;
            case 0x1C7DBCu: goto label_1c7dbc;
            case 0x1C7DCCu: goto label_1c7dcc;
            case 0x1C7DD8u: goto label_1c7dd8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C7DE8u;
    // 0x1c7de8: 0x0  nop
    ctx->pc = 0x1c7de8u;
    // NOP
    // 0x1c7dec: 0x0  nop
    ctx->pc = 0x1c7decu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
