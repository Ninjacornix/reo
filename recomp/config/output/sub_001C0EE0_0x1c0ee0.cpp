#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C0EE0
// Address: 0x1c0ee0 - 0x1c1048
void sub_001C0EE0_0x1c0ee0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C0EE0_0x1c0ee0");
#endif

    switch (ctx->pc) {
        case 0x1c0f20u: goto label_1c0f20;
        case 0x1c0f80u: goto label_1c0f80;
        case 0x1c0ff8u: goto label_1c0ff8;
        case 0x1c1038u: goto label_1c1038;
        default: break;
    }

    ctx->pc = 0x1c0ee0u;

    // 0x1c0ee0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1c0ee0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1c0ee4: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1c0ee4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1c0ee8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1c0ee8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1c0eec: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c0eecu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c0ef0: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x1c0ef0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1c0ef4: 0x1062003e  beq         $v1, $v0, . + 4 + (0x3E << 2)
    ctx->pc = 0x1C0EF4u;
    {
        const bool branch_taken_0x1c0ef4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1C0EF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0EF4u;
            // 0x1c0ef8: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0ef4) {
            ctx->pc = 0x1C0FF0u;
            goto label_1c0ff0;
        }
    }
    ctx->pc = 0x1C0EFCu;
    // 0x1c0efc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c0efcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c0f00: 0x1062001d  beq         $v1, $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x1C0F00u;
    {
        const bool branch_taken_0x1c0f00 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1c0f00) {
            ctx->pc = 0x1C0F78u;
            goto label_1c0f78;
        }
    }
    ctx->pc = 0x1C0F08u;
    // 0x1c0f08: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C0F08u;
    {
        const bool branch_taken_0x1c0f08 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c0f08) {
            ctx->pc = 0x1C0F18u;
            goto label_1c0f18;
        }
    }
    ctx->pc = 0x1C0F10u;
    // 0x1c0f10: 0x10000047  b           . + 4 + (0x47 << 2)
    ctx->pc = 0x1C0F10u;
    {
        const bool branch_taken_0x1c0f10 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C0F14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0F10u;
            // 0x1c0f14: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0f10) {
            ctx->pc = 0x1C1030u;
            goto label_1c1030;
        }
    }
    ctx->pc = 0x1C0F18u;
label_1c0f18:
    // 0x1c0f18: 0xc06fe10  jal         func_1BF840
    ctx->pc = 0x1C0F18u;
    SET_GPR_U32(ctx, 31, 0x1C0F20u);
    ctx->pc = 0x1BF840u;
    if (runtime->hasFunction(0x1BF840u)) {
        auto targetFn = runtime->lookupFunction(0x1BF840u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0F20u; }
        if (ctx->pc != 0x1C0F20u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BF840_0x1bf840(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0F20u; }
        if (ctx->pc != 0x1C0F20u) { return; }
    }
    ctx->pc = 0x1C0F20u;
label_1c0f20:
    // 0x1c0f20: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1c0f20u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1c0f24: 0x10430010  beq         $v0, $v1, . + 4 + (0x10 << 2)
    ctx->pc = 0x1C0F24u;
    {
        const bool branch_taken_0x1c0f24 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1C0F28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0F24u;
            // 0x1c0f28: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0f24) {
            ctx->pc = 0x1C0F68u;
            goto label_1c0f68;
        }
    }
    ctx->pc = 0x1C0F2Cu;
    // 0x1c0f2c: 0x1043000e  beq         $v0, $v1, . + 4 + (0xE << 2)
    ctx->pc = 0x1C0F2Cu;
    {
        const bool branch_taken_0x1c0f2c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c0f2c) {
            ctx->pc = 0x1C0F68u;
            goto label_1c0f68;
        }
    }
    ctx->pc = 0x1C0F34u;
    // 0x1c0f34: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1c0f34u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1c0f38: 0x10430008  beq         $v0, $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x1C0F38u;
    {
        const bool branch_taken_0x1c0f38 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c0f38) {
            ctx->pc = 0x1C0F5Cu;
            goto label_1c0f5c;
        }
    }
    ctx->pc = 0x1C0F40u;
    // 0x1c0f40: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C0F40u;
    {
        const bool branch_taken_0x1c0f40 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c0f40) {
            ctx->pc = 0x1C0F50u;
            goto label_1c0f50;
        }
    }
    ctx->pc = 0x1C0F48u;
    // 0x1c0f48: 0x10000038  b           . + 4 + (0x38 << 2)
    ctx->pc = 0x1C0F48u;
    {
        const bool branch_taken_0x1c0f48 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c0f48) {
            ctx->pc = 0x1C102Cu;
            goto label_1c102c;
        }
    }
    ctx->pc = 0x1C0F50u;
label_1c0f50:
    // 0x1c0f50: 0x2402ff01  addiu       $v0, $zero, -0xFF
    ctx->pc = 0x1c0f50u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967041));
    // 0x1c0f54: 0x10000035  b           . + 4 + (0x35 << 2)
    ctx->pc = 0x1C0F54u;
    {
        const bool branch_taken_0x1c0f54 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C0F58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0F54u;
            // 0x1c0f58: 0xae020024  sw          $v0, 0x24($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0f54) {
            ctx->pc = 0x1C102Cu;
            goto label_1c102c;
        }
    }
    ctx->pc = 0x1C0F5Cu;
label_1c0f5c:
    // 0x1c0f5c: 0x2402ff02  addiu       $v0, $zero, -0xFE
    ctx->pc = 0x1c0f5cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967042));
    // 0x1c0f60: 0x10000032  b           . + 4 + (0x32 << 2)
    ctx->pc = 0x1C0F60u;
    {
        const bool branch_taken_0x1c0f60 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C0F64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0F60u;
            // 0x1c0f64: 0xae020024  sw          $v0, 0x24($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0f60) {
            ctx->pc = 0x1C102Cu;
            goto label_1c102c;
        }
    }
    ctx->pc = 0x1C0F68u;
label_1c0f68:
    // 0x1c0f68: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x1c0f68u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1c0f6c: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1c0f6cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1c0f70: 0x1000002e  b           . + 4 + (0x2E << 2)
    ctx->pc = 0x1C0F70u;
    {
        const bool branch_taken_0x1c0f70 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C0F74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0F70u;
            // 0x1c0f74: 0xae020000  sw          $v0, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0f70) {
            ctx->pc = 0x1C102Cu;
            goto label_1c102c;
        }
    }
    ctx->pc = 0x1C0F78u;
label_1c0f78:
    // 0x1c0f78: 0xc06fe94  jal         func_1BFA50
    ctx->pc = 0x1C0F78u;
    SET_GPR_U32(ctx, 31, 0x1C0F80u);
    ctx->pc = 0x1BFA50u;
    if (runtime->hasFunction(0x1BFA50u)) {
        auto targetFn = runtime->lookupFunction(0x1BFA50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0F80u; }
        if (ctx->pc != 0x1C0F80u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BFA50_0x1bfa50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0F80u; }
        if (ctx->pc != 0x1C0F80u) { return; }
    }
    ctx->pc = 0x1C0F80u;
label_1c0f80:
    // 0x1c0f80: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1c0f80u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1c0f84: 0x10430016  beq         $v0, $v1, . + 4 + (0x16 << 2)
    ctx->pc = 0x1C0F84u;
    {
        const bool branch_taken_0x1c0f84 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1C0F88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0F84u;
            // 0x1c0f88: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0f84) {
            ctx->pc = 0x1C0FE0u;
            goto label_1c0fe0;
        }
    }
    ctx->pc = 0x1C0F8Cu;
    // 0x1c0f8c: 0x10430010  beq         $v0, $v1, . + 4 + (0x10 << 2)
    ctx->pc = 0x1C0F8Cu;
    {
        const bool branch_taken_0x1c0f8c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c0f8c) {
            ctx->pc = 0x1C0FD0u;
            goto label_1c0fd0;
        }
    }
    ctx->pc = 0x1C0F94u;
    // 0x1c0f94: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1c0f94u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c0f98: 0x10430009  beq         $v0, $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x1C0F98u;
    {
        const bool branch_taken_0x1c0f98 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c0f98) {
            ctx->pc = 0x1C0FC0u;
            goto label_1c0fc0;
        }
    }
    ctx->pc = 0x1C0FA0u;
    // 0x1c0fa0: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C0FA0u;
    {
        const bool branch_taken_0x1c0fa0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c0fa0) {
            ctx->pc = 0x1C0FB0u;
            goto label_1c0fb0;
        }
    }
    ctx->pc = 0x1C0FA8u;
    // 0x1c0fa8: 0x10000020  b           . + 4 + (0x20 << 2)
    ctx->pc = 0x1C0FA8u;
    {
        const bool branch_taken_0x1c0fa8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c0fa8) {
            ctx->pc = 0x1C102Cu;
            goto label_1c102c;
        }
    }
    ctx->pc = 0x1C0FB0u;
label_1c0fb0:
    // 0x1c0fb0: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x1c0fb0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1c0fb4: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1c0fb4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1c0fb8: 0x1000001c  b           . + 4 + (0x1C << 2)
    ctx->pc = 0x1C0FB8u;
    {
        const bool branch_taken_0x1c0fb8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C0FBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0FB8u;
            // 0x1c0fbc: 0xae020000  sw          $v0, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0fb8) {
            ctx->pc = 0x1C102Cu;
            goto label_1c102c;
        }
    }
    ctx->pc = 0x1C0FC0u;
label_1c0fc0:
    // 0x1c0fc0: 0xae000000  sw          $zero, 0x0($s0)
    ctx->pc = 0x1c0fc0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    // 0x1c0fc4: 0x2402ff03  addiu       $v0, $zero, -0xFD
    ctx->pc = 0x1c0fc4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967043));
    // 0x1c0fc8: 0x10000018  b           . + 4 + (0x18 << 2)
    ctx->pc = 0x1C0FC8u;
    {
        const bool branch_taken_0x1c0fc8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C0FCCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0FC8u;
            // 0x1c0fcc: 0xae020024  sw          $v0, 0x24($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0fc8) {
            ctx->pc = 0x1C102Cu;
            goto label_1c102c;
        }
    }
    ctx->pc = 0x1C0FD0u;
label_1c0fd0:
    // 0x1c0fd0: 0xae000000  sw          $zero, 0x0($s0)
    ctx->pc = 0x1c0fd0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    // 0x1c0fd4: 0x2402ff01  addiu       $v0, $zero, -0xFF
    ctx->pc = 0x1c0fd4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967041));
    // 0x1c0fd8: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x1C0FD8u;
    {
        const bool branch_taken_0x1c0fd8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C0FDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0FD8u;
            // 0x1c0fdc: 0xae020024  sw          $v0, 0x24($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0fd8) {
            ctx->pc = 0x1C102Cu;
            goto label_1c102c;
        }
    }
    ctx->pc = 0x1C0FE0u;
label_1c0fe0:
    // 0x1c0fe0: 0xae000000  sw          $zero, 0x0($s0)
    ctx->pc = 0x1c0fe0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    // 0x1c0fe4: 0x2402ff00  addiu       $v0, $zero, -0x100
    ctx->pc = 0x1c0fe4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967040));
    // 0x1c0fe8: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x1C0FE8u;
    {
        const bool branch_taken_0x1c0fe8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C0FECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0FE8u;
            // 0x1c0fec: 0xae020024  sw          $v0, 0x24($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0fe8) {
            ctx->pc = 0x1C102Cu;
            goto label_1c102c;
        }
    }
    ctx->pc = 0x1C0FF0u;
label_1c0ff0:
    // 0x1c0ff0: 0xc070034  jal         func_1C00D0
    ctx->pc = 0x1C0FF0u;
    SET_GPR_U32(ctx, 31, 0x1C0FF8u);
    ctx->pc = 0x1C00D0u;
    if (runtime->hasFunction(0x1C00D0u)) {
        auto targetFn = runtime->lookupFunction(0x1C00D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0FF8u; }
        if (ctx->pc != 0x1C0FF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C00D0_0x1c00d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0FF8u; }
        if (ctx->pc != 0x1C0FF8u) { return; }
    }
    ctx->pc = 0x1C0FF8u;
label_1c0ff8:
    // 0x1c0ff8: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1c0ff8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c0ffc: 0x10430008  beq         $v0, $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x1C0FFCu;
    {
        const bool branch_taken_0x1c0ffc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c0ffc) {
            ctx->pc = 0x1C1020u;
            goto label_1c1020;
        }
    }
    ctx->pc = 0x1C1004u;
    // 0x1c1004: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C1004u;
    {
        const bool branch_taken_0x1c1004 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c1004) {
            ctx->pc = 0x1C1014u;
            goto label_1c1014;
        }
    }
    ctx->pc = 0x1C100Cu;
    // 0x1c100c: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1C100Cu;
    {
        const bool branch_taken_0x1c100c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c100c) {
            ctx->pc = 0x1C102Cu;
            goto label_1c102c;
        }
    }
    ctx->pc = 0x1C1014u;
label_1c1014:
    // 0x1c1014: 0xae000000  sw          $zero, 0x0($s0)
    ctx->pc = 0x1c1014u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    // 0x1c1018: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1C1018u;
    {
        const bool branch_taken_0x1c1018 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C101Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1018u;
            // 0x1c101c: 0xae000024  sw          $zero, 0x24($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1018) {
            ctx->pc = 0x1C102Cu;
            goto label_1c102c;
        }
    }
    ctx->pc = 0x1C1020u;
label_1c1020:
    // 0x1c1020: 0xae000000  sw          $zero, 0x0($s0)
    ctx->pc = 0x1c1020u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    // 0x1c1024: 0x2402ff00  addiu       $v0, $zero, -0x100
    ctx->pc = 0x1c1024u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967040));
    // 0x1c1028: 0xae020024  sw          $v0, 0x24($s0)
    ctx->pc = 0x1c1028u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 2));
label_1c102c:
    // 0x1c102c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1c102cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_1c1030:
    // 0x1c1030: 0xc070108  jal         func_1C0420
    ctx->pc = 0x1C1030u;
    SET_GPR_U32(ctx, 31, 0x1C1038u);
    ctx->pc = 0x1C0420u;
    if (runtime->hasFunction(0x1C0420u)) {
        auto targetFn = runtime->lookupFunction(0x1C0420u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1038u; }
        if (ctx->pc != 0x1C1038u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C0420_0x1c0420(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1038u; }
        if (ctx->pc != 0x1C1038u) { return; }
    }
    ctx->pc = 0x1C1038u;
label_1c1038:
    // 0x1c1038: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1c1038u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c103c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c103cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c1040: 0x3e00008  jr          $ra
    ctx->pc = 0x1C1040u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C1044u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1040u;
            // 0x1c1044: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C0F18u: goto label_1c0f18;
            case 0x1C0F20u: goto label_1c0f20;
            case 0x1C0F50u: goto label_1c0f50;
            case 0x1C0F5Cu: goto label_1c0f5c;
            case 0x1C0F68u: goto label_1c0f68;
            case 0x1C0F78u: goto label_1c0f78;
            case 0x1C0F80u: goto label_1c0f80;
            case 0x1C0FB0u: goto label_1c0fb0;
            case 0x1C0FC0u: goto label_1c0fc0;
            case 0x1C0FD0u: goto label_1c0fd0;
            case 0x1C0FE0u: goto label_1c0fe0;
            case 0x1C0FF0u: goto label_1c0ff0;
            case 0x1C0FF8u: goto label_1c0ff8;
            case 0x1C1014u: goto label_1c1014;
            case 0x1C1020u: goto label_1c1020;
            case 0x1C102Cu: goto label_1c102c;
            case 0x1C1030u: goto label_1c1030;
            case 0x1C1038u: goto label_1c1038;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C1048u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
