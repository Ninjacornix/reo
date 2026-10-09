#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00145C40
// Address: 0x145c40 - 0x145d60
void sub_00145C40_0x145c40(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00145C40_0x145c40");
#endif

    switch (ctx->pc) {
        case 0x145c88u: goto label_145c88;
        case 0x145c98u: goto label_145c98;
        case 0x145ca4u: goto label_145ca4;
        case 0x145ce8u: goto label_145ce8;
        case 0x145cf8u: goto label_145cf8;
        case 0x145d08u: goto label_145d08;
        case 0x145d20u: goto label_145d20;
        default: break;
    }

    ctx->pc = 0x145c40u;

    // 0x145c40: 0x27bdff60  addiu       $sp, $sp, -0xA0
    ctx->pc = 0x145c40u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967136));
    // 0x145c44: 0xffb60080  sd          $s6, 0x80($sp)
    ctx->pc = 0x145c44u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 22));
    // 0x145c48: 0xffb50070  sd          $s5, 0x70($sp)
    ctx->pc = 0x145c48u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 21));
    // 0x145c4c: 0x24160005  addiu       $s6, $zero, 0x5
    ctx->pc = 0x145c4cu;
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x145c50: 0xffb40060  sd          $s4, 0x60($sp)
    ctx->pc = 0x145c50u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 20));
    // 0x145c54: 0x241501b3  addiu       $s5, $zero, 0x1B3
    ctx->pc = 0x145c54u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 0), 435));
    // 0x145c58: 0xffb30050  sd          $s3, 0x50($sp)
    ctx->pc = 0x145c58u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 19));
    // 0x145c5c: 0x24140100  addiu       $s4, $zero, 0x100
    ctx->pc = 0x145c5cu;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), 256));
    // 0x145c60: 0xffb20040  sd          $s2, 0x40($sp)
    ctx->pc = 0x145c60u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 18));
    // 0x145c64: 0x241301b7  addiu       $s3, $zero, 0x1B7
    ctx->pc = 0x145c64u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 439));
    // 0x145c68: 0xffb10030  sd          $s1, 0x30($sp)
    ctx->pc = 0x145c68u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 17));
    // 0x145c6c: 0x241201b8  addiu       $s2, $zero, 0x1B8
    ctx->pc = 0x145c6cu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 440));
    // 0x145c70: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x145c70u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x145c74: 0x2411ffff  addiu       $s1, $zero, -0x1
    ctx->pc = 0x145c74u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x145c78: 0xffbf0090  sd          $ra, 0x90($sp)
    ctx->pc = 0x145c78u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 31));
    // 0x145c7c: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x145c7cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x145c80: 0x8e0210a0  lw          $v0, 0x10A0($s0)
    ctx->pc = 0x145c80u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4256)));
    // 0x145c84: 0x0  nop
    ctx->pc = 0x145c84u;
    // NOP
label_145c88:
    // 0x145c88: 0x1440002a  bnez        $v0, . + 4 + (0x2A << 2)
    ctx->pc = 0x145C88u;
    {
        const bool branch_taken_0x145c88 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x145C8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x145C88u;
            // 0x145c8c: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x145c88) {
            ctx->pc = 0x145D34u;
            goto label_145d34;
        }
    }
    ctx->pc = 0x145C90u;
    // 0x145c90: 0xc0516d6  jal         func_145B58
    ctx->pc = 0x145C90u;
    SET_GPR_U32(ctx, 31, 0x145C98u);
    ctx->pc = 0x145C94u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x145C90u;
            // 0x145c94: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x145B58u;
    if (runtime->hasFunction(0x145B58u)) {
        auto targetFn = runtime->lookupFunction(0x145B58u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145C98u; }
        if (ctx->pc != 0x145C98u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00145B58_0x145b58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145C98u; }
        if (ctx->pc != 0x145C98u) { return; }
    }
    ctx->pc = 0x145C98u;
label_145c98:
    // 0x145c98: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x145c98u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x145c9c: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x145C9Cu;
    SET_GPR_U32(ctx, 31, 0x145CA4u);
    ctx->pc = 0x145CA0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x145C9Cu;
            // 0x145ca0: 0x24050020  addiu       $a1, $zero, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145CA4u; }
        if (ctx->pc != 0x145CA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145CA4u; }
        if (ctx->pc != 0x145CA4u) { return; }
    }
    ctx->pc = 0x145CA4u;
label_145ca4:
    // 0x145ca4: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x145ca4u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x145ca8: 0x1075000d  beq         $v1, $s5, . + 4 + (0xD << 2)
    ctx->pc = 0x145CA8u;
    {
        const bool branch_taken_0x145ca8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 21));
        ctx->pc = 0x145CACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x145CA8u;
            // 0x145cac: 0x2c6201b4  sltiu       $v0, $v1, 0x1B4 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)436) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x145ca8) {
            ctx->pc = 0x145CE0u;
            goto label_145ce0;
        }
    }
    ctx->pc = 0x145CB0u;
    // 0x145cb0: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x145CB0u;
    {
        const bool branch_taken_0x145cb0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x145cb0) {
            ctx->pc = 0x145CC8u;
            goto label_145cc8;
        }
    }
    ctx->pc = 0x145CB8u;
    // 0x145cb8: 0x10740011  beq         $v1, $s4, . + 4 + (0x11 << 2)
    ctx->pc = 0x145CB8u;
    {
        const bool branch_taken_0x145cb8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 20));
        if (branch_taken_0x145cb8) {
            ctx->pc = 0x145D00u;
            goto label_145d00;
        }
    }
    ctx->pc = 0x145CC0u;
    // 0x145cc0: 0x1000fff1  b           . + 4 + (-0xF << 2)
    ctx->pc = 0x145CC0u;
    {
        const bool branch_taken_0x145cc0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x145CC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x145CC0u;
            // 0x145cc4: 0x8e0210a0  lw          $v0, 0x10A0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4256)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x145cc0) {
            ctx->pc = 0x145C88u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_145c88;
        }
    }
    ctx->pc = 0x145CC8u;
label_145cc8:
    // 0x145cc8: 0x1073001a  beq         $v1, $s3, . + 4 + (0x1A << 2)
    ctx->pc = 0x145CC8u;
    {
        const bool branch_taken_0x145cc8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 19));
        ctx->pc = 0x145CCCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x145CC8u;
            // 0x145ccc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x145cc8) {
            ctx->pc = 0x145D34u;
            goto label_145d34;
        }
    }
    ctx->pc = 0x145CD0u;
    // 0x145cd0: 0x10720007  beq         $v1, $s2, . + 4 + (0x7 << 2)
    ctx->pc = 0x145CD0u;
    {
        const bool branch_taken_0x145cd0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 18));
        if (branch_taken_0x145cd0) {
            ctx->pc = 0x145CF0u;
            goto label_145cf0;
        }
    }
    ctx->pc = 0x145CD8u;
    // 0x145cd8: 0x1000ffeb  b           . + 4 + (-0x15 << 2)
    ctx->pc = 0x145CD8u;
    {
        const bool branch_taken_0x145cd8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x145CDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x145CD8u;
            // 0x145cdc: 0x8e0210a0  lw          $v0, 0x10A0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4256)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x145cd8) {
            ctx->pc = 0x145C88u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_145c88;
        }
    }
    ctx->pc = 0x145CE0u;
label_145ce0:
    // 0x145ce0: 0xc05227a  jal         func_1489E8
    ctx->pc = 0x145CE0u;
    SET_GPR_U32(ctx, 31, 0x145CE8u);
    ctx->pc = 0x145CE4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x145CE0u;
            // 0x145ce4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1489E8u;
    if (runtime->hasFunction(0x1489E8u)) {
        auto targetFn = runtime->lookupFunction(0x1489E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145CE8u; }
        if (ctx->pc != 0x145CE8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001489E8_0x1489e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145CE8u; }
        if (ctx->pc != 0x145CE8u) { return; }
    }
    ctx->pc = 0x145CE8u;
label_145ce8:
    // 0x145ce8: 0x1000ffe7  b           . + 4 + (-0x19 << 2)
    ctx->pc = 0x145CE8u;
    {
        const bool branch_taken_0x145ce8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x145CECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x145CE8u;
            // 0x145cec: 0x8e0210a0  lw          $v0, 0x10A0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4256)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x145ce8) {
            ctx->pc = 0x145C88u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_145c88;
        }
    }
    ctx->pc = 0x145CF0u;
label_145cf0:
    // 0x145cf0: 0xc051880  jal         func_146200
    ctx->pc = 0x145CF0u;
    SET_GPR_U32(ctx, 31, 0x145CF8u);
    ctx->pc = 0x145CF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x145CF0u;
            // 0x145cf4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x146200u;
    if (runtime->hasFunction(0x146200u)) {
        auto targetFn = runtime->lookupFunction(0x146200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145CF8u; }
        if (ctx->pc != 0x145CF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00146200_0x146200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145CF8u; }
        if (ctx->pc != 0x145CF8u) { return; }
    }
    ctx->pc = 0x145CF8u;
label_145cf8:
    // 0x145cf8: 0x1000ffe3  b           . + 4 + (-0x1D << 2)
    ctx->pc = 0x145CF8u;
    {
        const bool branch_taken_0x145cf8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x145CFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x145CF8u;
            // 0x145cfc: 0x8e0210a0  lw          $v0, 0x10A0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4256)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x145cf8) {
            ctx->pc = 0x145C88u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_145c88;
        }
    }
    ctx->pc = 0x145D00u;
label_145d00:
    // 0x145d00: 0xc051758  jal         func_145D60
    ctx->pc = 0x145D00u;
    SET_GPR_U32(ctx, 31, 0x145D08u);
    ctx->pc = 0x145D04u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x145D00u;
            // 0x145d04: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x145D60u;
    if (runtime->hasFunction(0x145D60u)) {
        auto targetFn = runtime->lookupFunction(0x145D60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145D08u; }
        if (ctx->pc != 0x145D08u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00145D60_0x145d60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145D08u; }
        if (ctx->pc != 0x145D08u) { return; }
    }
    ctx->pc = 0x145D08u;
label_145d08:
    // 0x145d08: 0x8e040870  lw          $a0, 0x870($s0)
    ctx->pc = 0x145d08u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 2160)));
    // 0x145d0c: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x145d0cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x145d10: 0xafb60000  sw          $s6, 0x0($sp)
    ctx->pc = 0x145d10u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 22));
    // 0x145d14: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x145d14u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x145d18: 0xc051fda  jal         func_147F68
    ctx->pc = 0x145D18u;
    SET_GPR_U32(ctx, 31, 0x145D20u);
    ctx->pc = 0x145D1Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x145D18u;
            // 0x145d1c: 0xffb10008  sd          $s1, 0x8($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
        ctx->in_delay_slot = false;
    ctx->pc = 0x147F68u;
    if (runtime->hasFunction(0x147F68u)) {
        auto targetFn = runtime->lookupFunction(0x147F68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145D20u; }
        if (ctx->pc != 0x145D20u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00147F68_0x147f68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145D20u; }
        if (ctx->pc != 0x145D20u) { return; }
    }
    ctx->pc = 0x145D20u;
label_145d20:
    // 0x145d20: 0xdfa20010  ld          $v0, 0x10($sp)
    ctx->pc = 0x145d20u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x145d24: 0xdfa30008  ld          $v1, 0x8($sp)
    ctx->pc = 0x145d24u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x145d28: 0xfe020848  sd          $v0, 0x848($s0)
    ctx->pc = 0x145d28u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 2120), GPR_U64(ctx, 2));
    // 0x145d2c: 0xfe030840  sd          $v1, 0x840($s0)
    ctx->pc = 0x145d2cu;
    WRITE64(ADD32(GPR_U32(ctx, 16), 2112), GPR_U64(ctx, 3));
    // 0x145d30: 0x8e020168  lw          $v0, 0x168($s0)
    ctx->pc = 0x145d30u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 360)));
label_145d34:
    // 0x145d34: 0xdfbf0090  ld          $ra, 0x90($sp)
    ctx->pc = 0x145d34u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x145d38: 0xdfb60080  ld          $s6, 0x80($sp)
    ctx->pc = 0x145d38u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x145d3c: 0xdfb50070  ld          $s5, 0x70($sp)
    ctx->pc = 0x145d3cu;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x145d40: 0xdfb40060  ld          $s4, 0x60($sp)
    ctx->pc = 0x145d40u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x145d44: 0xdfb30050  ld          $s3, 0x50($sp)
    ctx->pc = 0x145d44u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x145d48: 0xdfb20040  ld          $s2, 0x40($sp)
    ctx->pc = 0x145d48u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x145d4c: 0xdfb10030  ld          $s1, 0x30($sp)
    ctx->pc = 0x145d4cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x145d50: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x145d50u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x145d54: 0x3e00008  jr          $ra
    ctx->pc = 0x145D54u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x145D58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x145D54u;
            // 0x145d58: 0x27bd00a0  addiu       $sp, $sp, 0xA0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x145C88u: goto label_145c88;
            case 0x145C98u: goto label_145c98;
            case 0x145CA4u: goto label_145ca4;
            case 0x145CC8u: goto label_145cc8;
            case 0x145CE0u: goto label_145ce0;
            case 0x145CE8u: goto label_145ce8;
            case 0x145CF0u: goto label_145cf0;
            case 0x145CF8u: goto label_145cf8;
            case 0x145D00u: goto label_145d00;
            case 0x145D08u: goto label_145d08;
            case 0x145D20u: goto label_145d20;
            case 0x145D34u: goto label_145d34;
            default: break;
        }
        return;
    }
    ctx->pc = 0x145D5Cu;
    // 0x145d5c: 0x0  nop
    ctx->pc = 0x145d5cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
