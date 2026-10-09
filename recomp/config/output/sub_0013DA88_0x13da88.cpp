#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013DA88
// Address: 0x13da88 - 0x13db44
void sub_0013DA88_0x13da88(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013DA88_0x13da88");
#endif

    ctx->pc = 0x13da88u;

    // 0x13da88: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13da88u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13da8c: 0x80502d  daddu       $t2, $a0, $zero
    ctx->pc = 0x13da8cu;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13da90: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x13da90u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x13da94: 0x5410008  bgez        $t2, . + 4 + (0x8 << 2)
    ctx->pc = 0x13DA94u;
    {
        const bool branch_taken_0x13da94 = (GPR_S64(ctx, 10) >= 0);
        ctx->pc = 0x13DA98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13DA94u;
            // 0x13da98: 0xa0582d  daddu       $t3, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13da94) {
            ctx->pc = 0x13DAB8u;
            goto label_13dab8;
        }
    }
    ctx->pc = 0x13DA9Cu;
    // 0x13da9c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13da9cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13daa0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13daa0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13daa4: 0x140282d  daddu       $a1, $t2, $zero
    ctx->pc = 0x13daa4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13daa8: 0x2484d4e0  addiu       $a0, $a0, -0x2B20
    ctx->pc = 0x13daa8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294956256));
    // 0x13daac: 0x8045a12  j           func_116848
    ctx->pc = 0x13DAACu;
    ctx->pc = 0x13DAB0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13DAACu;
            // 0x13dab0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00116848_0x116848(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13DAB4u;
    // 0x13dab4: 0x0  nop
    ctx->pc = 0x13dab4u;
    // NOP
label_13dab8:
    // 0x13dab8: 0x5610007  bgez        $t3, . + 4 + (0x7 << 2)
    ctx->pc = 0x13DAB8u;
    {
        const bool branch_taken_0x13dab8 = (GPR_S64(ctx, 11) >= 0);
        ctx->pc = 0x13DABCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13DAB8u;
            // 0x13dabc: 0xa1040  sll         $v0, $t2, 1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 10), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13dab8) {
            ctx->pc = 0x13DAD8u;
            goto label_13dad8;
        }
    }
    ctx->pc = 0x13DAC0u;
    // 0x13dac0: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13dac0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13dac4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13dac4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13dac8: 0x2484d510  addiu       $a0, $a0, -0x2AF0
    ctx->pc = 0x13dac8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294956304));
    // 0x13dacc: 0x8045a12  j           func_116848
    ctx->pc = 0x13DACCu;
    ctx->pc = 0x13DAD0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13DACCu;
            // 0x13dad0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00116848_0x116848(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13DAD4u;
    // 0x13dad4: 0x0  nop
    ctx->pc = 0x13dad4u;
    // NOP
label_13dad8:
    // 0x13dad8: 0x4b4821  addu        $t1, $v0, $t3
    ctx->pc = 0x13dad8u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 11)));
    // 0x13dadc: 0x91980  sll         $v1, $t1, 6
    ctx->pc = 0x13dadcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 9), 6));
    // 0x13dae0: 0x29220021  slti        $v0, $t1, 0x21
    ctx->pc = 0x13dae0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 9) < (int64_t)(int32_t)33) ? 1 : 0);
    // 0x13dae4: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x13DAE4u;
    {
        const bool branch_taken_0x13dae4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x13DAE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13DAE4u;
            // 0x13dae8: 0x691821  addu        $v1, $v1, $t1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 9)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13dae4) {
            ctx->pc = 0x13DB08u;
            goto label_13db08;
        }
    }
    ctx->pc = 0x13DAECu;
    // 0x13daec: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13daecu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13daf0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13daf0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13daf4: 0x24050020  addiu       $a1, $zero, 0x20
    ctx->pc = 0x13daf4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x13daf8: 0x2484d540  addiu       $a0, $a0, -0x2AC0
    ctx->pc = 0x13daf8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294956352));
    // 0x13dafc: 0x8045a12  j           func_116848
    ctx->pc = 0x13DAFCu;
    ctx->pc = 0x13DB00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13DAFCu;
            // 0x13db00: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00116848_0x116848(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13DB04u;
    // 0x13db04: 0x0  nop
    ctx->pc = 0x13db04u;
    // NOP
label_13db08:
    // 0x13db08: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13db08u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13db0c: 0x33a00  sll         $a3, $v1, 8
    ctx->pc = 0x13db0cu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
    // 0x13db10: 0x3c080022  lui         $t0, 0x22
    ctx->pc = 0x13db10u;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)34 << 16));
    // 0x13db14: 0x3c040022  lui         $a0, 0x22
    ctx->pc = 0x13db14u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)34 << 16));
    // 0x13db18: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x13db18u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x13db1c: 0x3c050022  lui         $a1, 0x22
    ctx->pc = 0x13db1cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)34 << 16));
    // 0x13db20: 0x3c060022  lui         $a2, 0x22
    ctx->pc = 0x13db20u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)34 << 16));
    // 0x13db24: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x13db24u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x13db28: 0xac6a1460  sw          $t2, 0x1460($v1)
    ctx->pc = 0x13db28u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 5216), GPR_U32(ctx, 10));
    // 0x13db2c: 0xac8b1464  sw          $t3, 0x1464($a0)
    ctx->pc = 0x13db2cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 5220), GPR_U32(ctx, 11));
    // 0x13db30: 0xaca7143c  sw          $a3, 0x143C($a1)
    ctx->pc = 0x13db30u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 5180), GPR_U32(ctx, 7));
    // 0x13db34: 0xacc21440  sw          $v0, 0x1440($a2)
    ctx->pc = 0x13db34u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 5184), GPR_U32(ctx, 2));
    // 0x13db38: 0xad091438  sw          $t1, 0x1438($t0)
    ctx->pc = 0x13db38u;
    WRITE32(ADD32(GPR_U32(ctx, 8), 5176), GPR_U32(ctx, 9));
    // 0x13db3c: 0x3e00008  jr          $ra
    ctx->pc = 0x13DB3Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13DB40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13DB3Cu;
            // 0x13db40: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13DAB8u: goto label_13dab8;
            case 0x13DAD8u: goto label_13dad8;
            case 0x13DB08u: goto label_13db08;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13DB44u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
