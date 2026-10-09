#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00122E10
// Address: 0x122e10 - 0x122fa0
void sub_00122E10_0x122e10(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00122E10_0x122e10");
#endif

    switch (ctx->pc) {
        case 0x122e64u: goto label_122e64;
        case 0x122eb4u: goto label_122eb4;
        case 0x122ee0u: goto label_122ee0;
        default: break;
    }

    ctx->pc = 0x122e10u;

    // 0x122e10: 0x3e00008  jr          $ra
    ctx->pc = 0x122E10u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x122E14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122E10u;
            // 0x122e14: 0xac850020  sw          $a1, 0x20($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 32), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x122E64u: goto label_122e64;
            case 0x122E84u: goto label_122e84;
            case 0x122EB4u: goto label_122eb4;
            case 0x122EE0u: goto label_122ee0;
            case 0x122F98u: goto label_122f98;
            default: break;
        }
        return;
    }
    ctx->pc = 0x122E18u;
    // 0x122e18: 0x3e00008  jr          $ra
    ctx->pc = 0x122E18u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x122E1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122E18u;
            // 0x122e1c: 0x8c820020  lw          $v0, 0x20($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 32)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x122E64u: goto label_122e64;
            case 0x122E84u: goto label_122e84;
            case 0x122EB4u: goto label_122eb4;
            case 0x122EE0u: goto label_122ee0;
            case 0x122F98u: goto label_122f98;
            default: break;
        }
        return;
    }
    ctx->pc = 0x122E20u;
    // 0x122e20: 0x3e00008  jr          $ra
    ctx->pc = 0x122E20u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x122E24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122E20u;
            // 0x122e24: 0xe48c0024  swc1        $f12, 0x24($a0) (Delay Slot)
        { float f = ctx->f[12]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 36), bits); }
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x122E64u: goto label_122e64;
            case 0x122E84u: goto label_122e84;
            case 0x122EB4u: goto label_122eb4;
            case 0x122EE0u: goto label_122ee0;
            case 0x122F98u: goto label_122f98;
            default: break;
        }
        return;
    }
    ctx->pc = 0x122E28u;
    // 0x122e28: 0x3e00008  jr          $ra
    ctx->pc = 0x122E28u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x122E2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122E28u;
            // 0x122e2c: 0xc4800024  lwc1        $f0, 0x24($a0) (Delay Slot)
        { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x122E64u: goto label_122e64;
            case 0x122E84u: goto label_122e84;
            case 0x122EB4u: goto label_122eb4;
            case 0x122EE0u: goto label_122ee0;
            case 0x122F98u: goto label_122f98;
            default: break;
        }
        return;
    }
    ctx->pc = 0x122E30u;
    // 0x122e30: 0x3e00008  jr          $ra
    ctx->pc = 0x122E30u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x122E34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122E30u;
            // 0x122e34: 0xe48c0028  swc1        $f12, 0x28($a0) (Delay Slot)
        { float f = ctx->f[12]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 40), bits); }
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x122E64u: goto label_122e64;
            case 0x122E84u: goto label_122e84;
            case 0x122EB4u: goto label_122eb4;
            case 0x122EE0u: goto label_122ee0;
            case 0x122F98u: goto label_122f98;
            default: break;
        }
        return;
    }
    ctx->pc = 0x122E38u;
    // 0x122e38: 0x3e00008  jr          $ra
    ctx->pc = 0x122E38u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x122E3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122E38u;
            // 0x122e3c: 0xc4800028  lwc1        $f0, 0x28($a0) (Delay Slot)
        { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 40)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x122E64u: goto label_122e64;
            case 0x122E84u: goto label_122e84;
            case 0x122EB4u: goto label_122eb4;
            case 0x122EE0u: goto label_122ee0;
            case 0x122F98u: goto label_122f98;
            default: break;
        }
        return;
    }
    ctx->pc = 0x122E40u;
    // 0x122e40: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x122e40u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x122e44: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x122e44u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x122e48: 0x8c8200bc  lw          $v0, 0xBC($a0)
    ctx->pc = 0x122e48u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 188)));
    // 0x122e4c: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x122E4Cu;
    {
        const bool branch_taken_0x122e4c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x122E50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122E4Cu;
            // 0x122e50: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x122e4c) {
            ctx->pc = 0x122E64u;
            goto label_122e64;
        }
    }
    ctx->pc = 0x122E54u;
    // 0x122e54: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x122e54u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x122e58: 0x8c43b718  lw          $v1, -0x48E8($v0)
    ctx->pc = 0x122e58u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294948632)));
    // 0x122e5c: 0x60f809  jalr        $v1
    ctx->pc = 0x122E5Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x122E64u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x122E64u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x122E64u: goto label_122e64;
            case 0x122E84u: goto label_122e84;
            case 0x122EB4u: goto label_122eb4;
            case 0x122EE0u: goto label_122ee0;
            case 0x122F98u: goto label_122f98;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x122E64u; }
            if (ctx->pc != 0x122E64u) { return; }
        }
        }
    }
    ctx->pc = 0x122E64u;
label_122e64:
    // 0x122e64: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x122e64u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x122e68: 0x3e00008  jr          $ra
    ctx->pc = 0x122E68u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x122E6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122E68u;
            // 0x122e6c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x122E64u: goto label_122e64;
            case 0x122E84u: goto label_122e84;
            case 0x122EB4u: goto label_122eb4;
            case 0x122EE0u: goto label_122ee0;
            case 0x122F98u: goto label_122f98;
            default: break;
        }
        return;
    }
    ctx->pc = 0x122E70u;
    // 0x122e70: 0x24020600  addiu       $v0, $zero, 0x600
    ctx->pc = 0x122e70u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1536));
    // 0x122e74: 0xac8500c0  sw          $a1, 0xC0($a0)
    ctx->pc = 0x122e74u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 192), GPR_U32(ctx, 5));
    // 0x122e78: 0xa2001a  div         $zero, $a1, $v0
    ctx->pc = 0x122e78u;
    { int32_t divisor = GPR_S32(ctx, 2);    int32_t dividend = GPR_S32(ctx, 5);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x122e7c: 0x50400001  beql        $v0, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x122E7Cu;
    {
        const bool branch_taken_0x122e7c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x122e7c) {
            ctx->pc = 0x122E80u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x122E7Cu;
            // 0x122e80: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x122E84u;
            goto label_122e84;
        }
    }
    ctx->pc = 0x122E84u;
label_122e84:
    // 0x122e84: 0x1812  mflo        $v1
    ctx->pc = 0x122e84u;
    SET_GPR_U64(ctx, 3, ctx->lo);
    // 0x122e88: 0x3e00008  jr          $ra
    ctx->pc = 0x122E88u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x122E8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122E88u;
            // 0x122e8c: 0xac8300c4  sw          $v1, 0xC4($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 196), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x122E64u: goto label_122e64;
            case 0x122E84u: goto label_122e84;
            case 0x122EB4u: goto label_122eb4;
            case 0x122EE0u: goto label_122ee0;
            case 0x122F98u: goto label_122f98;
            default: break;
        }
        return;
    }
    ctx->pc = 0x122E90u;
    // 0x122e90: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x122e90u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x122e94: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x122e94u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x122e98: 0x8c8200bc  lw          $v0, 0xBC($a0)
    ctx->pc = 0x122e98u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 188)));
    // 0x122e9c: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x122E9Cu;
    {
        const bool branch_taken_0x122e9c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x122EA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122E9Cu;
            // 0x122ea0: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x122e9c) {
            ctx->pc = 0x122EB4u;
            goto label_122eb4;
        }
    }
    ctx->pc = 0x122EA4u;
    // 0x122ea4: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x122ea4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x122ea8: 0x8c43b71c  lw          $v1, -0x48E4($v0)
    ctx->pc = 0x122ea8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294948636)));
    // 0x122eac: 0x60f809  jalr        $v1
    ctx->pc = 0x122EACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x122EB4u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x122EB4u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x122E64u: goto label_122e64;
            case 0x122E84u: goto label_122e84;
            case 0x122EB4u: goto label_122eb4;
            case 0x122EE0u: goto label_122ee0;
            case 0x122F98u: goto label_122f98;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x122EB4u; }
            if (ctx->pc != 0x122EB4u) { return; }
        }
        }
    }
    ctx->pc = 0x122EB4u;
label_122eb4:
    // 0x122eb4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x122eb4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x122eb8: 0x3e00008  jr          $ra
    ctx->pc = 0x122EB8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x122EBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122EB8u;
            // 0x122ebc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x122E64u: goto label_122e64;
            case 0x122E84u: goto label_122e84;
            case 0x122EB4u: goto label_122eb4;
            case 0x122EE0u: goto label_122ee0;
            case 0x122F98u: goto label_122f98;
            default: break;
        }
        return;
    }
    ctx->pc = 0x122EC0u;
    // 0x122ec0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x122ec0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x122ec4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x122ec4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x122ec8: 0x8c8200bc  lw          $v0, 0xBC($a0)
    ctx->pc = 0x122ec8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 188)));
    // 0x122ecc: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x122ECCu;
    {
        const bool branch_taken_0x122ecc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x122ED0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122ECCu;
            // 0x122ed0: 0x3c020021  lui         $v0, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x122ecc) {
            ctx->pc = 0x122EE0u;
            goto label_122ee0;
        }
    }
    ctx->pc = 0x122ED4u;
    // 0x122ed4: 0x8c43b720  lw          $v1, -0x48E0($v0)
    ctx->pc = 0x122ed4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294948640)));
    // 0x122ed8: 0x60f809  jalr        $v1
    ctx->pc = 0x122ED8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x122EE0u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x122EE0u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x122E64u: goto label_122e64;
            case 0x122E84u: goto label_122e84;
            case 0x122EB4u: goto label_122eb4;
            case 0x122EE0u: goto label_122ee0;
            case 0x122F98u: goto label_122f98;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x122EE0u; }
            if (ctx->pc != 0x122EE0u) { return; }
        }
        }
    }
    ctx->pc = 0x122EE0u;
label_122ee0:
    // 0x122ee0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x122ee0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x122ee4: 0x3e00008  jr          $ra
    ctx->pc = 0x122EE4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x122EE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122EE4u;
            // 0x122ee8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x122E64u: goto label_122e64;
            case 0x122E84u: goto label_122e84;
            case 0x122EB4u: goto label_122eb4;
            case 0x122EE0u: goto label_122ee0;
            case 0x122F98u: goto label_122f98;
            default: break;
        }
        return;
    }
    ctx->pc = 0x122EECu;
    // 0x122eec: 0x0  nop
    ctx->pc = 0x122eecu;
    // NOP
    // 0x122ef0: 0x80702d  daddu       $t6, $a0, $zero
    ctx->pc = 0x122ef0u;
    SET_GPR_U64(ctx, 14, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x122ef4: 0x8dc300bc  lw          $v1, 0xBC($t6)
    ctx->pc = 0x122ef4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 14), 188)));
    // 0x122ef8: 0x10600027  beqz        $v1, . + 4 + (0x27 << 2)
    ctx->pc = 0x122EF8u;
    {
        const bool branch_taken_0x122ef8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x122EFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122EF8u;
            // 0x122efc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x122ef8) {
            ctx->pc = 0x122F98u;
            goto label_122f98;
        }
    }
    ctx->pc = 0x122F00u;
    // 0x122f00: 0x3c037fff  lui         $v1, 0x7FFF
    ctx->pc = 0x122f00u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32767 << 16));
    // 0x122f04: 0x8dcc003c  lw          $t4, 0x3C($t6)
    ctx->pc = 0x122f04u;
    SET_GPR_S32(ctx, 12, (int32_t)READ32(ADD32(GPR_U32(ctx, 14), 60)));
    // 0x122f08: 0x8dcd0040  lw          $t5, 0x40($t6)
    ctx->pc = 0x122f08u;
    SET_GPR_S32(ctx, 13, (int32_t)READ32(ADD32(GPR_U32(ctx, 14), 64)));
    // 0x122f0c: 0x240a0001  addiu       $t2, $zero, 0x1
    ctx->pc = 0x122f0cu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x122f10: 0x8dcb0044  lw          $t3, 0x44($t6)
    ctx->pc = 0x122f10u;
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 14), 68)));
    // 0x122f14: 0x24090600  addiu       $t1, $zero, 0x600
    ctx->pc = 0x122f14u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 1536));
    // 0x122f18: 0x24040010  addiu       $a0, $zero, 0x10
    ctx->pc = 0x122f18u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x122f1c: 0x3463ffff  ori         $v1, $v1, 0xFFFF
    ctx->pc = 0x122f1cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)65535);
    // 0x122f20: 0x2405007f  addiu       $a1, $zero, 0x7F
    ctx->pc = 0x122f20u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 127));
    // 0x122f24: 0x2406000f  addiu       $a2, $zero, 0xF
    ctx->pc = 0x122f24u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
    // 0x122f28: 0x24070001  addiu       $a3, $zero, 0x1
    ctx->pc = 0x122f28u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x122f2c: 0x2408007f  addiu       $t0, $zero, 0x7F
    ctx->pc = 0x122f2cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 127));
    // 0x122f30: 0x3402bb80  ori         $v0, $zero, 0xBB80
    ctx->pc = 0x122f30u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)48000);
    // 0x122f34: 0xa1ca000e  sb          $t2, 0xE($t6)
    ctx->pc = 0x122f34u;
    WRITE8(ADD32(GPR_U32(ctx, 14), 14), (uint8_t)GPR_U32(ctx, 10));
    // 0x122f38: 0xa1c4000d  sb          $a0, 0xD($t6)
    ctx->pc = 0x122f38u;
    WRITE8(ADD32(GPR_U32(ctx, 14), 13), (uint8_t)GPR_U32(ctx, 4));
    // 0x122f3c: 0xadc30018  sw          $v1, 0x18($t6)
    ctx->pc = 0x122f3cu;
    WRITE32(ADD32(GPR_U32(ctx, 14), 24), GPR_U32(ctx, 3));
    // 0x122f40: 0xa1c5000f  sb          $a1, 0xF($t6)
    ctx->pc = 0x122f40u;
    WRITE8(ADD32(GPR_U32(ctx, 14), 15), (uint8_t)GPR_U32(ctx, 5));
    // 0x122f44: 0xa5c60098  sh          $a2, 0x98($t6)
    ctx->pc = 0x122f44u;
    WRITE16(ADD32(GPR_U32(ctx, 14), 152), (uint16_t)GPR_U32(ctx, 6));
    // 0x122f48: 0xadc70050  sw          $a3, 0x50($t6)
    ctx->pc = 0x122f48u;
    WRITE32(ADD32(GPR_U32(ctx, 14), 80), GPR_U32(ctx, 7));
    // 0x122f4c: 0xadc80054  sw          $t0, 0x54($t6)
    ctx->pc = 0x122f4cu;
    WRITE32(ADD32(GPR_U32(ctx, 14), 84), GPR_U32(ctx, 8));
    // 0x122f50: 0xadc90058  sw          $t1, 0x58($t6)
    ctx->pc = 0x122f50u;
    WRITE32(ADD32(GPR_U32(ctx, 14), 88), GPR_U32(ctx, 9));
    // 0x122f54: 0xadcc005c  sw          $t4, 0x5C($t6)
    ctx->pc = 0x122f54u;
    WRITE32(ADD32(GPR_U32(ctx, 14), 92), GPR_U32(ctx, 12));
    // 0x122f58: 0xadcd0060  sw          $t5, 0x60($t6)
    ctx->pc = 0x122f58u;
    WRITE32(ADD32(GPR_U32(ctx, 14), 96), GPR_U32(ctx, 13));
    // 0x122f5c: 0xadcb0064  sw          $t3, 0x64($t6)
    ctx->pc = 0x122f5cu;
    WRITE32(ADD32(GPR_U32(ctx, 14), 100), GPR_U32(ctx, 11));
    // 0x122f60: 0xadc00088  sw          $zero, 0x88($t6)
    ctx->pc = 0x122f60u;
    WRITE32(ADD32(GPR_U32(ctx, 14), 136), GPR_U32(ctx, 0));
    // 0x122f64: 0xa5ca0002  sh          $t2, 0x2($t6)
    ctx->pc = 0x122f64u;
    WRITE16(ADD32(GPR_U32(ctx, 14), 2), (uint16_t)GPR_U32(ctx, 10));
    // 0x122f68: 0xadc90010  sw          $t1, 0x10($t6)
    ctx->pc = 0x122f68u;
    WRITE32(ADD32(GPR_U32(ctx, 14), 16), GPR_U32(ctx, 9));
    // 0x122f6c: 0xadc0008c  sw          $zero, 0x8C($t6)
    ctx->pc = 0x122f6cu;
    WRITE32(ADD32(GPR_U32(ctx, 14), 140), GPR_U32(ctx, 0));
    // 0x122f70: 0xa5c0001c  sh          $zero, 0x1C($t6)
    ctx->pc = 0x122f70u;
    WRITE16(ADD32(GPR_U32(ctx, 14), 28), (uint16_t)GPR_U32(ctx, 0));
    // 0x122f74: 0xa5c00024  sh          $zero, 0x24($t6)
    ctx->pc = 0x122f74u;
    WRITE16(ADD32(GPR_U32(ctx, 14), 36), (uint16_t)GPR_U32(ctx, 0));
    // 0x122f78: 0xa5c00026  sh          $zero, 0x26($t6)
    ctx->pc = 0x122f78u;
    WRITE16(ADD32(GPR_U32(ctx, 14), 38), (uint16_t)GPR_U32(ctx, 0));
    // 0x122f7c: 0xadc00020  sw          $zero, 0x20($t6)
    ctx->pc = 0x122f7cu;
    WRITE32(ADD32(GPR_U32(ctx, 14), 32), GPR_U32(ctx, 0));
    // 0x122f80: 0xadc00028  sw          $zero, 0x28($t6)
    ctx->pc = 0x122f80u;
    WRITE32(ADD32(GPR_U32(ctx, 14), 40), GPR_U32(ctx, 0));
    // 0x122f84: 0xadc0002c  sw          $zero, 0x2C($t6)
    ctx->pc = 0x122f84u;
    WRITE32(ADD32(GPR_U32(ctx, 14), 44), GPR_U32(ctx, 0));
    // 0x122f88: 0xadc00030  sw          $zero, 0x30($t6)
    ctx->pc = 0x122f88u;
    WRITE32(ADD32(GPR_U32(ctx, 14), 48), GPR_U32(ctx, 0));
    // 0x122f8c: 0xadc00034  sw          $zero, 0x34($t6)
    ctx->pc = 0x122f8cu;
    WRITE32(ADD32(GPR_U32(ctx, 14), 52), GPR_U32(ctx, 0));
    // 0x122f90: 0xadc20014  sw          $v0, 0x14($t6)
    ctx->pc = 0x122f90u;
    WRITE32(ADD32(GPR_U32(ctx, 14), 20), GPR_U32(ctx, 2));
    // 0x122f94: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x122f94u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_122f98:
    // 0x122f98: 0x3e00008  jr          $ra
    ctx->pc = 0x122F98u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x122E64u: goto label_122e64;
            case 0x122E84u: goto label_122e84;
            case 0x122EB4u: goto label_122eb4;
            case 0x122EE0u: goto label_122ee0;
            case 0x122F98u: goto label_122f98;
            default: break;
        }
        return;
    }
    ctx->pc = 0x122FA0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
