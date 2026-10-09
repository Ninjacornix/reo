#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C7E30
// Address: 0x1c7e30 - 0x1c7ed0
void sub_001C7E30_0x1c7e30(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C7E30_0x1c7e30");
#endif

    switch (ctx->pc) {
        case 0x1c7ea4u: goto label_1c7ea4;
        default: break;
    }

    ctx->pc = 0x1c7e30u;

    // 0x1c7e30: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1c7e30u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1c7e34: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c7e34u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c7e38: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1c7e38u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1c7e3c: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1c7e3cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1c7e40: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c7e40u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c7e44: 0x8c28d158  lw          $t0, -0x2EA8($at)
    ctx->pc = 0x1c7e44u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294955352)));
    // 0x1c7e48: 0x8d080008  lw          $t0, 0x8($t0)
    ctx->pc = 0x1c7e48u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 8)));
    // 0x1c7e4c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c7e4cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c7e50: 0xa4880000  sh          $t0, 0x0($a0)
    ctx->pc = 0x1c7e50u;
    WRITE16(ADD32(GPR_U32(ctx, 4), 0), (uint16_t)GPR_U32(ctx, 8));
    // 0x1c7e54: 0x8c24d158  lw          $a0, -0x2EA8($at)
    ctx->pc = 0x1c7e54u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294955352)));
    // 0x1c7e58: 0x8c84000c  lw          $a0, 0xC($a0)
    ctx->pc = 0x1c7e58u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x1c7e5c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c7e5cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c7e60: 0xa4a40000  sh          $a0, 0x0($a1)
    ctx->pc = 0x1c7e60u;
    WRITE16(ADD32(GPR_U32(ctx, 5), 0), (uint16_t)GPR_U32(ctx, 4));
    // 0x1c7e64: 0x84242640  lh          $a0, 0x2640($at)
    ctx->pc = 0x1c7e64u;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 1), 9792)));
    // 0x1c7e68: 0x30840001  andi        $a0, $a0, 0x1
    ctx->pc = 0x1c7e68u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)1);
    // 0x1c7e6c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c7e6cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c7e70: 0xa4c40000  sh          $a0, 0x0($a2)
    ctx->pc = 0x1c7e70u;
    WRITE16(ADD32(GPR_U32(ctx, 6), 0), (uint16_t)GPR_U32(ctx, 4));
    // 0x1c7e74: 0xa4e00000  sh          $zero, 0x0($a3)
    ctx->pc = 0x1c7e74u;
    WRITE16(ADD32(GPR_U32(ctx, 7), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1c7e78: 0x8c24d158  lw          $a0, -0x2EA8($at)
    ctx->pc = 0x1c7e78u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294955352)));
    // 0x1c7e7c: 0x8c840000  lw          $a0, 0x0($a0)
    ctx->pc = 0x1c7e7cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1c7e80: 0x10830006  beq         $a0, $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x1C7E80u;
    {
        const bool branch_taken_0x1c7e80 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x1C7E84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7E80u;
            // 0x1c7e84: 0xe0802d  daddu       $s0, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c7e80) {
            ctx->pc = 0x1C7E9Cu;
            goto label_1c7e9c;
        }
    }
    ctx->pc = 0x1C7E88u;
    // 0x1c7e88: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1c7e88u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1c7e8c: 0x10830003  beq         $a0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C7E8Cu;
    {
        const bool branch_taken_0x1c7e8c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c7e8c) {
            ctx->pc = 0x1C7E9Cu;
            goto label_1c7e9c;
        }
    }
    ctx->pc = 0x1C7E94u;
    // 0x1c7e94: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x1C7E94u;
    {
        const bool branch_taken_0x1c7e94 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C7E98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7E94u;
            // 0x1c7e98: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c7e94) {
            ctx->pc = 0x1C7EC4u;
            goto label_1c7ec4;
        }
    }
    ctx->pc = 0x1C7E9Cu;
label_1c7e9c:
    // 0x1c7e9c: 0xc075c14  jal         func_1D7050
    ctx->pc = 0x1C7E9Cu;
    SET_GPR_U32(ctx, 31, 0x1C7EA4u);
    ctx->pc = 0x1C7EA0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7E9Cu;
            // 0x1c7ea0: 0x27a40020  addiu       $a0, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7050u;
    if (runtime->hasFunction(0x1D7050u)) {
        auto targetFn = runtime->lookupFunction(0x1D7050u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C7EA4u; }
        if (ctx->pc != 0x1C7EA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7050_0x1d7050(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C7EA4u; }
        if (ctx->pc != 0x1C7EA4u) { return; }
    }
    ctx->pc = 0x1C7EA4u;
label_1c7ea4:
    // 0x1c7ea4: 0x8fa40028  lw          $a0, 0x28($sp)
    ctx->pc = 0x1c7ea4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1c7ea8: 0x24030064  addiu       $v1, $zero, 0x64
    ctx->pc = 0x1c7ea8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1c7eac: 0x83001a  div         $zero, $a0, $v1
    ctx->pc = 0x1c7eacu;
    { int32_t divisor = GPR_S32(ctx, 3);    int32_t dividend = GPR_S32(ctx, 4);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x1c7eb0: 0x0  nop
    ctx->pc = 0x1c7eb0u;
    // NOP
    // 0x1c7eb4: 0x0  nop
    ctx->pc = 0x1c7eb4u;
    // NOP
    // 0x1c7eb8: 0x1812  mflo        $v1
    ctx->pc = 0x1c7eb8u;
    SET_GPR_U64(ctx, 3, ctx->lo);
    // 0x1c7ebc: 0xa6030000  sh          $v1, 0x0($s0)
    ctx->pc = 0x1c7ebcu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 3));
    // 0x1c7ec0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1c7ec0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1c7ec4:
    // 0x1c7ec4: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c7ec4u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c7ec8: 0x3e00008  jr          $ra
    ctx->pc = 0x1C7EC8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C7ECCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7EC8u;
            // 0x1c7ecc: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C7E9Cu: goto label_1c7e9c;
            case 0x1C7EA4u: goto label_1c7ea4;
            case 0x1C7EC4u: goto label_1c7ec4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C7ED0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
