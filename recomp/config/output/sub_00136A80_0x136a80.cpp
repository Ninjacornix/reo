#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00136A80
// Address: 0x136a80 - 0x136f98
void sub_00136A80_0x136a80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00136A80_0x136a80");
#endif

    switch (ctx->pc) {
        case 0x136ac8u: goto label_136ac8;
        case 0x136ae8u: goto label_136ae8;
        case 0x136af8u: goto label_136af8;
        case 0x136b30u: goto label_136b30;
        case 0x136b50u: goto label_136b50;
        case 0x136b60u: goto label_136b60;
        case 0x136bc0u: goto label_136bc0;
        case 0x136be4u: goto label_136be4;
        case 0x136bf8u: goto label_136bf8;
        case 0x136c20u: goto label_136c20;
        case 0x136c74u: goto label_136c74;
        case 0x136c94u: goto label_136c94;
        case 0x136cb4u: goto label_136cb4;
        case 0x136cc8u: goto label_136cc8;
        case 0x136ce0u: goto label_136ce0;
        case 0x136cf4u: goto label_136cf4;
        case 0x136d1cu: goto label_136d1c;
        case 0x136d90u: goto label_136d90;
        case 0x136db4u: goto label_136db4;
        case 0x136dc8u: goto label_136dc8;
        case 0x136df0u: goto label_136df0;
        case 0x136e58u: goto label_136e58;
        case 0x136e7cu: goto label_136e7c;
        case 0x136e90u: goto label_136e90;
        case 0x136ebcu: goto label_136ebc;
        case 0x136efcu: goto label_136efc;
        case 0x136f1cu: goto label_136f1c;
        case 0x136f30u: goto label_136f30;
        case 0x136f50u: goto label_136f50;
        case 0x136f60u: goto label_136f60;
        case 0x136f84u: goto label_136f84;
        default: break;
    }

    ctx->pc = 0x136a80u;

    // 0x136a80: 0x14800005  bnez        $a0, . + 4 + (0x5 << 2)
    ctx->pc = 0x136A80u;
    {
        const bool branch_taken_0x136a80 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x136A84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136A80u;
            // 0x136a84: 0x3c020022  lui         $v0, 0x22 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136a80) {
            ctx->pc = 0x136A98u;
            goto label_136a98;
        }
    }
    ctx->pc = 0x136A88u;
    // 0x136a88: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x136a88u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x136a8c: 0xac40bb7c  sw          $zero, -0x4484($v0)
    ctx->pc = 0x136a8cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4294949756), GPR_U32(ctx, 0));
    // 0x136a90: 0x3e00008  jr          $ra
    ctx->pc = 0x136A90u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x136A94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136A90u;
            // 0x136a94: 0xac60bb80  sw          $zero, -0x4480($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 4294949760), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x136A98u: goto label_136a98;
            case 0x136AC8u: goto label_136ac8;
            case 0x136AD0u: goto label_136ad0;
            case 0x136AE8u: goto label_136ae8;
            case 0x136AF0u: goto label_136af0;
            case 0x136AF8u: goto label_136af8;
            case 0x136AFCu: goto label_136afc;
            case 0x136B30u: goto label_136b30;
            case 0x136B38u: goto label_136b38;
            case 0x136B50u: goto label_136b50;
            case 0x136B58u: goto label_136b58;
            case 0x136B60u: goto label_136b60;
            case 0x136B64u: goto label_136b64;
            case 0x136BA0u: goto label_136ba0;
            case 0x136BB8u: goto label_136bb8;
            case 0x136BC0u: goto label_136bc0;
            case 0x136BDCu: goto label_136bdc;
            case 0x136BE4u: goto label_136be4;
            case 0x136BF0u: goto label_136bf0;
            case 0x136BF8u: goto label_136bf8;
            case 0x136C20u: goto label_136c20;
            case 0x136C74u: goto label_136c74;
            case 0x136C80u: goto label_136c80;
            case 0x136C94u: goto label_136c94;
            case 0x136CA0u: goto label_136ca0;
            case 0x136CB4u: goto label_136cb4;
            case 0x136CC0u: goto label_136cc0;
            case 0x136CC8u: goto label_136cc8;
            case 0x136CE0u: goto label_136ce0;
            case 0x136CE8u: goto label_136ce8;
            case 0x136CF4u: goto label_136cf4;
            case 0x136D1Cu: goto label_136d1c;
            case 0x136D28u: goto label_136d28;
            case 0x136D2Cu: goto label_136d2c;
            case 0x136D30u: goto label_136d30;
            case 0x136D70u: goto label_136d70;
            case 0x136D88u: goto label_136d88;
            case 0x136D90u: goto label_136d90;
            case 0x136DACu: goto label_136dac;
            case 0x136DB4u: goto label_136db4;
            case 0x136DC0u: goto label_136dc0;
            case 0x136DC8u: goto label_136dc8;
            case 0x136DF0u: goto label_136df0;
            case 0x136E38u: goto label_136e38;
            case 0x136E50u: goto label_136e50;
            case 0x136E58u: goto label_136e58;
            case 0x136E74u: goto label_136e74;
            case 0x136E7Cu: goto label_136e7c;
            case 0x136E88u: goto label_136e88;
            case 0x136E90u: goto label_136e90;
            case 0x136EBCu: goto label_136ebc;
            case 0x136EFCu: goto label_136efc;
            case 0x136F08u: goto label_136f08;
            case 0x136F1Cu: goto label_136f1c;
            case 0x136F28u: goto label_136f28;
            case 0x136F30u: goto label_136f30;
            case 0x136F50u: goto label_136f50;
            case 0x136F58u: goto label_136f58;
            case 0x136F60u: goto label_136f60;
            case 0x136F84u: goto label_136f84;
            case 0x136F88u: goto label_136f88;
            default: break;
        }
        return;
    }
    ctx->pc = 0x136A98u;
label_136a98:
    // 0x136a98: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x136a98u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x136a9c: 0xac44bb7c  sw          $a0, -0x4484($v0)
    ctx->pc = 0x136a9cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4294949756), GPR_U32(ctx, 4));
    // 0x136aa0: 0x3e00008  jr          $ra
    ctx->pc = 0x136AA0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x136AA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136AA0u;
            // 0x136aa4: 0xac65bb80  sw          $a1, -0x4480($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 4294949760), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x136A98u: goto label_136a98;
            case 0x136AC8u: goto label_136ac8;
            case 0x136AD0u: goto label_136ad0;
            case 0x136AE8u: goto label_136ae8;
            case 0x136AF0u: goto label_136af0;
            case 0x136AF8u: goto label_136af8;
            case 0x136AFCu: goto label_136afc;
            case 0x136B30u: goto label_136b30;
            case 0x136B38u: goto label_136b38;
            case 0x136B50u: goto label_136b50;
            case 0x136B58u: goto label_136b58;
            case 0x136B60u: goto label_136b60;
            case 0x136B64u: goto label_136b64;
            case 0x136BA0u: goto label_136ba0;
            case 0x136BB8u: goto label_136bb8;
            case 0x136BC0u: goto label_136bc0;
            case 0x136BDCu: goto label_136bdc;
            case 0x136BE4u: goto label_136be4;
            case 0x136BF0u: goto label_136bf0;
            case 0x136BF8u: goto label_136bf8;
            case 0x136C20u: goto label_136c20;
            case 0x136C74u: goto label_136c74;
            case 0x136C80u: goto label_136c80;
            case 0x136C94u: goto label_136c94;
            case 0x136CA0u: goto label_136ca0;
            case 0x136CB4u: goto label_136cb4;
            case 0x136CC0u: goto label_136cc0;
            case 0x136CC8u: goto label_136cc8;
            case 0x136CE0u: goto label_136ce0;
            case 0x136CE8u: goto label_136ce8;
            case 0x136CF4u: goto label_136cf4;
            case 0x136D1Cu: goto label_136d1c;
            case 0x136D28u: goto label_136d28;
            case 0x136D2Cu: goto label_136d2c;
            case 0x136D30u: goto label_136d30;
            case 0x136D70u: goto label_136d70;
            case 0x136D88u: goto label_136d88;
            case 0x136D90u: goto label_136d90;
            case 0x136DACu: goto label_136dac;
            case 0x136DB4u: goto label_136db4;
            case 0x136DC0u: goto label_136dc0;
            case 0x136DC8u: goto label_136dc8;
            case 0x136DF0u: goto label_136df0;
            case 0x136E38u: goto label_136e38;
            case 0x136E50u: goto label_136e50;
            case 0x136E58u: goto label_136e58;
            case 0x136E74u: goto label_136e74;
            case 0x136E7Cu: goto label_136e7c;
            case 0x136E88u: goto label_136e88;
            case 0x136E90u: goto label_136e90;
            case 0x136EBCu: goto label_136ebc;
            case 0x136EFCu: goto label_136efc;
            case 0x136F08u: goto label_136f08;
            case 0x136F1Cu: goto label_136f1c;
            case 0x136F28u: goto label_136f28;
            case 0x136F30u: goto label_136f30;
            case 0x136F50u: goto label_136f50;
            case 0x136F58u: goto label_136f58;
            case 0x136F60u: goto label_136f60;
            case 0x136F84u: goto label_136f84;
            case 0x136F88u: goto label_136f88;
            default: break;
        }
        return;
    }
    ctx->pc = 0x136AA8u;
    // 0x136aa8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x136aa8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x136aac: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x136aacu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x136ab0: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x136ab0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136ab4: 0x14800006  bnez        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x136AB4u;
    {
        const bool branch_taken_0x136ab4 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x136AB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136AB4u;
            // 0x136ab8: 0xffbf0008  sd          $ra, 0x8($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136ab4) {
            ctx->pc = 0x136AD0u;
            goto label_136ad0;
        }
    }
    ctx->pc = 0x136ABCu;
    // 0x136abc: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x136abcu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x136ac0: 0xc04d480  jal         func_135200
    ctx->pc = 0x136AC0u;
    SET_GPR_U32(ctx, 31, 0x136AC8u);
    ctx->pc = 0x136AC4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x136AC0u;
            // 0x136ac4: 0x2484c0c0  addiu       $a0, $a0, -0x3F40 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294951104));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136AC8u; }
        if (ctx->pc != 0x136AC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136AC8u; }
        if (ctx->pc != 0x136AC8u) { return; }
    }
    ctx->pc = 0x136AC8u;
label_136ac8:
    // 0x136ac8: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x136AC8u;
    {
        const bool branch_taken_0x136ac8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x136ACCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136AC8u;
            // 0x136acc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136ac8) {
            ctx->pc = 0x136AFCu;
            goto label_136afc;
        }
    }
    ctx->pc = 0x136AD0u;
label_136ad0:
    // 0x136ad0: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x136ad0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x136ad4: 0x8c420060  lw          $v0, 0x60($v0)
    ctx->pc = 0x136ad4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 96)));
    // 0x136ad8: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x136AD8u;
    {
        const bool branch_taken_0x136ad8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x136ad8) {
            ctx->pc = 0x136ADCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x136AD8u;
            // 0x136adc: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x136AF0u;
            goto label_136af0;
        }
    }
    ctx->pc = 0x136AE0u;
    // 0x136ae0: 0x40f809  jalr        $v0
    ctx->pc = 0x136AE0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x136AE8u);
        ctx->pc = 0x136AE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136AE0u;
            // 0x136ae4: 0x8c840004  lw          $a0, 0x4($a0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x136AE8u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x136A98u: goto label_136a98;
            case 0x136AC8u: goto label_136ac8;
            case 0x136AD0u: goto label_136ad0;
            case 0x136AE8u: goto label_136ae8;
            case 0x136AF0u: goto label_136af0;
            case 0x136AF8u: goto label_136af8;
            case 0x136AFCu: goto label_136afc;
            case 0x136B30u: goto label_136b30;
            case 0x136B38u: goto label_136b38;
            case 0x136B50u: goto label_136b50;
            case 0x136B58u: goto label_136b58;
            case 0x136B60u: goto label_136b60;
            case 0x136B64u: goto label_136b64;
            case 0x136BA0u: goto label_136ba0;
            case 0x136BB8u: goto label_136bb8;
            case 0x136BC0u: goto label_136bc0;
            case 0x136BDCu: goto label_136bdc;
            case 0x136BE4u: goto label_136be4;
            case 0x136BF0u: goto label_136bf0;
            case 0x136BF8u: goto label_136bf8;
            case 0x136C20u: goto label_136c20;
            case 0x136C74u: goto label_136c74;
            case 0x136C80u: goto label_136c80;
            case 0x136C94u: goto label_136c94;
            case 0x136CA0u: goto label_136ca0;
            case 0x136CB4u: goto label_136cb4;
            case 0x136CC0u: goto label_136cc0;
            case 0x136CC8u: goto label_136cc8;
            case 0x136CE0u: goto label_136ce0;
            case 0x136CE8u: goto label_136ce8;
            case 0x136CF4u: goto label_136cf4;
            case 0x136D1Cu: goto label_136d1c;
            case 0x136D28u: goto label_136d28;
            case 0x136D2Cu: goto label_136d2c;
            case 0x136D30u: goto label_136d30;
            case 0x136D70u: goto label_136d70;
            case 0x136D88u: goto label_136d88;
            case 0x136D90u: goto label_136d90;
            case 0x136DACu: goto label_136dac;
            case 0x136DB4u: goto label_136db4;
            case 0x136DC0u: goto label_136dc0;
            case 0x136DC8u: goto label_136dc8;
            case 0x136DF0u: goto label_136df0;
            case 0x136E38u: goto label_136e38;
            case 0x136E50u: goto label_136e50;
            case 0x136E58u: goto label_136e58;
            case 0x136E74u: goto label_136e74;
            case 0x136E7Cu: goto label_136e7c;
            case 0x136E88u: goto label_136e88;
            case 0x136E90u: goto label_136e90;
            case 0x136EBCu: goto label_136ebc;
            case 0x136EFCu: goto label_136efc;
            case 0x136F08u: goto label_136f08;
            case 0x136F1Cu: goto label_136f1c;
            case 0x136F28u: goto label_136f28;
            case 0x136F30u: goto label_136f30;
            case 0x136F50u: goto label_136f50;
            case 0x136F58u: goto label_136f58;
            case 0x136F60u: goto label_136f60;
            case 0x136F84u: goto label_136f84;
            case 0x136F88u: goto label_136f88;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x136AE8u; }
            if (ctx->pc != 0x136AE8u) { return; }
        }
        }
    }
    ctx->pc = 0x136AE8u;
label_136ae8:
    // 0x136ae8: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x136AE8u;
    {
        const bool branch_taken_0x136ae8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x136AECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136AE8u;
            // 0x136aec: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136ae8) {
            ctx->pc = 0x136AF8u;
            goto label_136af8;
        }
    }
    ctx->pc = 0x136AF0u;
label_136af0:
    // 0x136af0: 0xc04d480  jal         func_135200
    ctx->pc = 0x136AF0u;
    SET_GPR_U32(ctx, 31, 0x136AF8u);
    ctx->pc = 0x136AF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x136AF0u;
            // 0x136af4: 0x2484c0e0  addiu       $a0, $a0, -0x3F20 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294951136));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136AF8u; }
        if (ctx->pc != 0x136AF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136AF8u; }
        if (ctx->pc != 0x136AF8u) { return; }
    }
    ctx->pc = 0x136AF8u;
label_136af8:
    // 0x136af8: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x136af8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_136afc:
    // 0x136afc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x136afcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x136b00: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x136b00u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x136b04: 0x3e00008  jr          $ra
    ctx->pc = 0x136B04u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x136B08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136B04u;
            // 0x136b08: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x136A98u: goto label_136a98;
            case 0x136AC8u: goto label_136ac8;
            case 0x136AD0u: goto label_136ad0;
            case 0x136AE8u: goto label_136ae8;
            case 0x136AF0u: goto label_136af0;
            case 0x136AF8u: goto label_136af8;
            case 0x136AFCu: goto label_136afc;
            case 0x136B30u: goto label_136b30;
            case 0x136B38u: goto label_136b38;
            case 0x136B50u: goto label_136b50;
            case 0x136B58u: goto label_136b58;
            case 0x136B60u: goto label_136b60;
            case 0x136B64u: goto label_136b64;
            case 0x136BA0u: goto label_136ba0;
            case 0x136BB8u: goto label_136bb8;
            case 0x136BC0u: goto label_136bc0;
            case 0x136BDCu: goto label_136bdc;
            case 0x136BE4u: goto label_136be4;
            case 0x136BF0u: goto label_136bf0;
            case 0x136BF8u: goto label_136bf8;
            case 0x136C20u: goto label_136c20;
            case 0x136C74u: goto label_136c74;
            case 0x136C80u: goto label_136c80;
            case 0x136C94u: goto label_136c94;
            case 0x136CA0u: goto label_136ca0;
            case 0x136CB4u: goto label_136cb4;
            case 0x136CC0u: goto label_136cc0;
            case 0x136CC8u: goto label_136cc8;
            case 0x136CE0u: goto label_136ce0;
            case 0x136CE8u: goto label_136ce8;
            case 0x136CF4u: goto label_136cf4;
            case 0x136D1Cu: goto label_136d1c;
            case 0x136D28u: goto label_136d28;
            case 0x136D2Cu: goto label_136d2c;
            case 0x136D30u: goto label_136d30;
            case 0x136D70u: goto label_136d70;
            case 0x136D88u: goto label_136d88;
            case 0x136D90u: goto label_136d90;
            case 0x136DACu: goto label_136dac;
            case 0x136DB4u: goto label_136db4;
            case 0x136DC0u: goto label_136dc0;
            case 0x136DC8u: goto label_136dc8;
            case 0x136DF0u: goto label_136df0;
            case 0x136E38u: goto label_136e38;
            case 0x136E50u: goto label_136e50;
            case 0x136E58u: goto label_136e58;
            case 0x136E74u: goto label_136e74;
            case 0x136E7Cu: goto label_136e7c;
            case 0x136E88u: goto label_136e88;
            case 0x136E90u: goto label_136e90;
            case 0x136EBCu: goto label_136ebc;
            case 0x136EFCu: goto label_136efc;
            case 0x136F08u: goto label_136f08;
            case 0x136F1Cu: goto label_136f1c;
            case 0x136F28u: goto label_136f28;
            case 0x136F30u: goto label_136f30;
            case 0x136F50u: goto label_136f50;
            case 0x136F58u: goto label_136f58;
            case 0x136F60u: goto label_136f60;
            case 0x136F84u: goto label_136f84;
            case 0x136F88u: goto label_136f88;
            default: break;
        }
        return;
    }
    ctx->pc = 0x136B0Cu;
    // 0x136b0c: 0x0  nop
    ctx->pc = 0x136b0cu;
    // NOP
    // 0x136b10: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x136b10u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x136b14: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x136b14u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x136b18: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x136b18u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136b1c: 0x14800006  bnez        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x136B1Cu;
    {
        const bool branch_taken_0x136b1c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x136B20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136B1Cu;
            // 0x136b20: 0xffbf0008  sd          $ra, 0x8($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136b1c) {
            ctx->pc = 0x136B38u;
            goto label_136b38;
        }
    }
    ctx->pc = 0x136B24u;
    // 0x136b24: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x136b24u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x136b28: 0xc04d480  jal         func_135200
    ctx->pc = 0x136B28u;
    SET_GPR_U32(ctx, 31, 0x136B30u);
    ctx->pc = 0x136B2Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x136B28u;
            // 0x136b2c: 0x2484c100  addiu       $a0, $a0, -0x3F00 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294951168));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136B30u; }
        if (ctx->pc != 0x136B30u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136B30u; }
        if (ctx->pc != 0x136B30u) { return; }
    }
    ctx->pc = 0x136B30u;
label_136b30:
    // 0x136b30: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x136B30u;
    {
        const bool branch_taken_0x136b30 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x136B34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136B30u;
            // 0x136b34: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136b30) {
            ctx->pc = 0x136B64u;
            goto label_136b64;
        }
    }
    ctx->pc = 0x136B38u;
label_136b38:
    // 0x136b38: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x136b38u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x136b3c: 0x8c420064  lw          $v0, 0x64($v0)
    ctx->pc = 0x136b3cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 100)));
    // 0x136b40: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x136B40u;
    {
        const bool branch_taken_0x136b40 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x136b40) {
            ctx->pc = 0x136B44u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x136B40u;
            // 0x136b44: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x136B58u;
            goto label_136b58;
        }
    }
    ctx->pc = 0x136B48u;
    // 0x136b48: 0x40f809  jalr        $v0
    ctx->pc = 0x136B48u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x136B50u);
        ctx->pc = 0x136B4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136B48u;
            // 0x136b4c: 0x8c840004  lw          $a0, 0x4($a0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x136B50u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x136A98u: goto label_136a98;
            case 0x136AC8u: goto label_136ac8;
            case 0x136AD0u: goto label_136ad0;
            case 0x136AE8u: goto label_136ae8;
            case 0x136AF0u: goto label_136af0;
            case 0x136AF8u: goto label_136af8;
            case 0x136AFCu: goto label_136afc;
            case 0x136B30u: goto label_136b30;
            case 0x136B38u: goto label_136b38;
            case 0x136B50u: goto label_136b50;
            case 0x136B58u: goto label_136b58;
            case 0x136B60u: goto label_136b60;
            case 0x136B64u: goto label_136b64;
            case 0x136BA0u: goto label_136ba0;
            case 0x136BB8u: goto label_136bb8;
            case 0x136BC0u: goto label_136bc0;
            case 0x136BDCu: goto label_136bdc;
            case 0x136BE4u: goto label_136be4;
            case 0x136BF0u: goto label_136bf0;
            case 0x136BF8u: goto label_136bf8;
            case 0x136C20u: goto label_136c20;
            case 0x136C74u: goto label_136c74;
            case 0x136C80u: goto label_136c80;
            case 0x136C94u: goto label_136c94;
            case 0x136CA0u: goto label_136ca0;
            case 0x136CB4u: goto label_136cb4;
            case 0x136CC0u: goto label_136cc0;
            case 0x136CC8u: goto label_136cc8;
            case 0x136CE0u: goto label_136ce0;
            case 0x136CE8u: goto label_136ce8;
            case 0x136CF4u: goto label_136cf4;
            case 0x136D1Cu: goto label_136d1c;
            case 0x136D28u: goto label_136d28;
            case 0x136D2Cu: goto label_136d2c;
            case 0x136D30u: goto label_136d30;
            case 0x136D70u: goto label_136d70;
            case 0x136D88u: goto label_136d88;
            case 0x136D90u: goto label_136d90;
            case 0x136DACu: goto label_136dac;
            case 0x136DB4u: goto label_136db4;
            case 0x136DC0u: goto label_136dc0;
            case 0x136DC8u: goto label_136dc8;
            case 0x136DF0u: goto label_136df0;
            case 0x136E38u: goto label_136e38;
            case 0x136E50u: goto label_136e50;
            case 0x136E58u: goto label_136e58;
            case 0x136E74u: goto label_136e74;
            case 0x136E7Cu: goto label_136e7c;
            case 0x136E88u: goto label_136e88;
            case 0x136E90u: goto label_136e90;
            case 0x136EBCu: goto label_136ebc;
            case 0x136EFCu: goto label_136efc;
            case 0x136F08u: goto label_136f08;
            case 0x136F1Cu: goto label_136f1c;
            case 0x136F28u: goto label_136f28;
            case 0x136F30u: goto label_136f30;
            case 0x136F50u: goto label_136f50;
            case 0x136F58u: goto label_136f58;
            case 0x136F60u: goto label_136f60;
            case 0x136F84u: goto label_136f84;
            case 0x136F88u: goto label_136f88;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x136B50u; }
            if (ctx->pc != 0x136B50u) { return; }
        }
        }
    }
    ctx->pc = 0x136B50u;
label_136b50:
    // 0x136b50: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x136B50u;
    {
        const bool branch_taken_0x136b50 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x136B54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136B50u;
            // 0x136b54: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136b50) {
            ctx->pc = 0x136B60u;
            goto label_136b60;
        }
    }
    ctx->pc = 0x136B58u;
label_136b58:
    // 0x136b58: 0xc04d480  jal         func_135200
    ctx->pc = 0x136B58u;
    SET_GPR_U32(ctx, 31, 0x136B60u);
    ctx->pc = 0x136B5Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x136B58u;
            // 0x136b5c: 0x2484c120  addiu       $a0, $a0, -0x3EE0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294951200));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136B60u; }
        if (ctx->pc != 0x136B60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136B60u; }
        if (ctx->pc != 0x136B60u) { return; }
    }
    ctx->pc = 0x136B60u;
label_136b60:
    // 0x136b60: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x136b60u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_136b64:
    // 0x136b64: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x136b64u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x136b68: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x136b68u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x136b6c: 0x3e00008  jr          $ra
    ctx->pc = 0x136B6Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x136B70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136B6Cu;
            // 0x136b70: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x136A98u: goto label_136a98;
            case 0x136AC8u: goto label_136ac8;
            case 0x136AD0u: goto label_136ad0;
            case 0x136AE8u: goto label_136ae8;
            case 0x136AF0u: goto label_136af0;
            case 0x136AF8u: goto label_136af8;
            case 0x136AFCu: goto label_136afc;
            case 0x136B30u: goto label_136b30;
            case 0x136B38u: goto label_136b38;
            case 0x136B50u: goto label_136b50;
            case 0x136B58u: goto label_136b58;
            case 0x136B60u: goto label_136b60;
            case 0x136B64u: goto label_136b64;
            case 0x136BA0u: goto label_136ba0;
            case 0x136BB8u: goto label_136bb8;
            case 0x136BC0u: goto label_136bc0;
            case 0x136BDCu: goto label_136bdc;
            case 0x136BE4u: goto label_136be4;
            case 0x136BF0u: goto label_136bf0;
            case 0x136BF8u: goto label_136bf8;
            case 0x136C20u: goto label_136c20;
            case 0x136C74u: goto label_136c74;
            case 0x136C80u: goto label_136c80;
            case 0x136C94u: goto label_136c94;
            case 0x136CA0u: goto label_136ca0;
            case 0x136CB4u: goto label_136cb4;
            case 0x136CC0u: goto label_136cc0;
            case 0x136CC8u: goto label_136cc8;
            case 0x136CE0u: goto label_136ce0;
            case 0x136CE8u: goto label_136ce8;
            case 0x136CF4u: goto label_136cf4;
            case 0x136D1Cu: goto label_136d1c;
            case 0x136D28u: goto label_136d28;
            case 0x136D2Cu: goto label_136d2c;
            case 0x136D30u: goto label_136d30;
            case 0x136D70u: goto label_136d70;
            case 0x136D88u: goto label_136d88;
            case 0x136D90u: goto label_136d90;
            case 0x136DACu: goto label_136dac;
            case 0x136DB4u: goto label_136db4;
            case 0x136DC0u: goto label_136dc0;
            case 0x136DC8u: goto label_136dc8;
            case 0x136DF0u: goto label_136df0;
            case 0x136E38u: goto label_136e38;
            case 0x136E50u: goto label_136e50;
            case 0x136E58u: goto label_136e58;
            case 0x136E74u: goto label_136e74;
            case 0x136E7Cu: goto label_136e7c;
            case 0x136E88u: goto label_136e88;
            case 0x136E90u: goto label_136e90;
            case 0x136EBCu: goto label_136ebc;
            case 0x136EFCu: goto label_136efc;
            case 0x136F08u: goto label_136f08;
            case 0x136F1Cu: goto label_136f1c;
            case 0x136F28u: goto label_136f28;
            case 0x136F30u: goto label_136f30;
            case 0x136F50u: goto label_136f50;
            case 0x136F58u: goto label_136f58;
            case 0x136F60u: goto label_136f60;
            case 0x136F84u: goto label_136f84;
            case 0x136F88u: goto label_136f88;
            default: break;
        }
        return;
    }
    ctx->pc = 0x136B74u;
    // 0x136b74: 0x0  nop
    ctx->pc = 0x136b74u;
    // NOP
    // 0x136b78: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x136b78u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x136b7c: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x136b7cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x136b80: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x136b80u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136b84: 0xffb10028  sd          $s1, 0x28($sp)
    ctx->pc = 0x136b84u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 17));
    // 0x136b88: 0x14800005  bnez        $a0, . + 4 + (0x5 << 2)
    ctx->pc = 0x136B88u;
    {
        const bool branch_taken_0x136b88 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x136B8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136B88u;
            // 0x136b8c: 0xffbf0030  sd          $ra, 0x30($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136b88) {
            ctx->pc = 0x136BA0u;
            goto label_136ba0;
        }
    }
    ctx->pc = 0x136B90u;
    // 0x136b90: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x136b90u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x136b94: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x136B94u;
    {
        const bool branch_taken_0x136b94 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x136B98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136B94u;
            // 0x136b98: 0x2484c140  addiu       $a0, $a0, -0x3EC0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294951232));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136b94) {
            ctx->pc = 0x136BDCu;
            goto label_136bdc;
        }
    }
    ctx->pc = 0x136B9Cu;
    // 0x136b9c: 0x0  nop
    ctx->pc = 0x136b9cu;
    // NOP
label_136ba0:
    // 0x136ba0: 0x16000005  bnez        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x136BA0u;
    {
        const bool branch_taken_0x136ba0 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x136ba0) {
            ctx->pc = 0x136BB8u;
            goto label_136bb8;
        }
    }
    ctx->pc = 0x136BA8u;
    // 0x136ba8: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x136ba8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x136bac: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x136BACu;
    {
        const bool branch_taken_0x136bac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x136BB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136BACu;
            // 0x136bb0: 0x2484c168  addiu       $a0, $a0, -0x3E98 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294951272));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136bac) {
            ctx->pc = 0x136BDCu;
            goto label_136bdc;
        }
    }
    ctx->pc = 0x136BB4u;
    // 0x136bb4: 0x0  nop
    ctx->pc = 0x136bb4u;
    // NOP
label_136bb8:
    // 0x136bb8: 0xc04d558  jal         func_135560
    ctx->pc = 0x136BB8u;
    SET_GPR_U32(ctx, 31, 0x136BC0u);
    ctx->pc = 0x135560u;
    if (runtime->hasFunction(0x135560u)) {
        auto targetFn = runtime->lookupFunction(0x135560u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136BC0u; }
        if (ctx->pc != 0x136BC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135560_0x135560(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136BC0u; }
        if (ctx->pc != 0x136BC0u) { return; }
    }
    ctx->pc = 0x136BC0u;
label_136bc0:
    // 0x136bc0: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x136bc0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136bc4: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x136bc4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136bc8: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x136bc8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136bcc: 0x16200008  bnez        $s1, . + 4 + (0x8 << 2)
    ctx->pc = 0x136BCCu;
    {
        const bool branch_taken_0x136bcc = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        ctx->pc = 0x136BD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136BCCu;
            // 0x136bd0: 0x24060014  addiu       $a2, $zero, 0x14 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136bcc) {
            ctx->pc = 0x136BF0u;
            goto label_136bf0;
        }
    }
    ctx->pc = 0x136BD4u;
    // 0x136bd4: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x136bd4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x136bd8: 0x2484c198  addiu       $a0, $a0, -0x3E68
    ctx->pc = 0x136bd8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294951320));
label_136bdc:
    // 0x136bdc: 0xc04d480  jal         func_135200
    ctx->pc = 0x136BDCu;
    SET_GPR_U32(ctx, 31, 0x136BE4u);
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136BE4u; }
        if (ctx->pc != 0x136BE4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136BE4u; }
        if (ctx->pc != 0x136BE4u) { return; }
    }
    ctx->pc = 0x136BE4u;
label_136be4:
    // 0x136be4: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x136BE4u;
    {
        const bool branch_taken_0x136be4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x136BE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136BE4u;
            // 0x136be8: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136be4) {
            ctx->pc = 0x136C20u;
            goto label_136c20;
        }
    }
    ctx->pc = 0x136BECu;
    // 0x136bec: 0x0  nop
    ctx->pc = 0x136becu;
    // NOP
label_136bf0:
    // 0x136bf0: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x136BF0u;
    SET_GPR_U32(ctx, 31, 0x136BF8u);
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136BF8u; }
        if (ctx->pc != 0x136BF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136BF8u; }
        if (ctx->pc != 0x136BF8u) { return; }
    }
    ctx->pc = 0x136BF8u;
label_136bf8:
    // 0x136bf8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x136bf8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x136bfc: 0xafb00000  sw          $s0, 0x0($sp)
    ctx->pc = 0x136bfcu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 16));
    // 0x136c00: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x136c00u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136c04: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x136c04u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x136c08: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x136c08u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136c0c: 0x8e230060  lw          $v1, 0x60($s1)
    ctx->pc = 0x136c0cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 96)));
    // 0x136c10: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x136C10u;
    {
        const bool branch_taken_0x136c10 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x136C14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136C10u;
            // 0x136c14: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136c10) {
            ctx->pc = 0x136C20u;
            goto label_136c20;
        }
    }
    ctx->pc = 0x136C18u;
    // 0x136c18: 0x60f809  jalr        $v1
    ctx->pc = 0x136C18u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x136C20u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x136C20u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x136A98u: goto label_136a98;
            case 0x136AC8u: goto label_136ac8;
            case 0x136AD0u: goto label_136ad0;
            case 0x136AE8u: goto label_136ae8;
            case 0x136AF0u: goto label_136af0;
            case 0x136AF8u: goto label_136af8;
            case 0x136AFCu: goto label_136afc;
            case 0x136B30u: goto label_136b30;
            case 0x136B38u: goto label_136b38;
            case 0x136B50u: goto label_136b50;
            case 0x136B58u: goto label_136b58;
            case 0x136B60u: goto label_136b60;
            case 0x136B64u: goto label_136b64;
            case 0x136BA0u: goto label_136ba0;
            case 0x136BB8u: goto label_136bb8;
            case 0x136BC0u: goto label_136bc0;
            case 0x136BDCu: goto label_136bdc;
            case 0x136BE4u: goto label_136be4;
            case 0x136BF0u: goto label_136bf0;
            case 0x136BF8u: goto label_136bf8;
            case 0x136C20u: goto label_136c20;
            case 0x136C74u: goto label_136c74;
            case 0x136C80u: goto label_136c80;
            case 0x136C94u: goto label_136c94;
            case 0x136CA0u: goto label_136ca0;
            case 0x136CB4u: goto label_136cb4;
            case 0x136CC0u: goto label_136cc0;
            case 0x136CC8u: goto label_136cc8;
            case 0x136CE0u: goto label_136ce0;
            case 0x136CE8u: goto label_136ce8;
            case 0x136CF4u: goto label_136cf4;
            case 0x136D1Cu: goto label_136d1c;
            case 0x136D28u: goto label_136d28;
            case 0x136D2Cu: goto label_136d2c;
            case 0x136D30u: goto label_136d30;
            case 0x136D70u: goto label_136d70;
            case 0x136D88u: goto label_136d88;
            case 0x136D90u: goto label_136d90;
            case 0x136DACu: goto label_136dac;
            case 0x136DB4u: goto label_136db4;
            case 0x136DC0u: goto label_136dc0;
            case 0x136DC8u: goto label_136dc8;
            case 0x136DF0u: goto label_136df0;
            case 0x136E38u: goto label_136e38;
            case 0x136E50u: goto label_136e50;
            case 0x136E58u: goto label_136e58;
            case 0x136E74u: goto label_136e74;
            case 0x136E7Cu: goto label_136e7c;
            case 0x136E88u: goto label_136e88;
            case 0x136E90u: goto label_136e90;
            case 0x136EBCu: goto label_136ebc;
            case 0x136EFCu: goto label_136efc;
            case 0x136F08u: goto label_136f08;
            case 0x136F1Cu: goto label_136f1c;
            case 0x136F28u: goto label_136f28;
            case 0x136F30u: goto label_136f30;
            case 0x136F50u: goto label_136f50;
            case 0x136F58u: goto label_136f58;
            case 0x136F60u: goto label_136f60;
            case 0x136F84u: goto label_136f84;
            case 0x136F88u: goto label_136f88;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x136C20u; }
            if (ctx->pc != 0x136C20u) { return; }
        }
        }
    }
    ctx->pc = 0x136C20u;
label_136c20:
    // 0x136c20: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x136c20u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x136c24: 0xdfb10028  ld          $s1, 0x28($sp)
    ctx->pc = 0x136c24u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x136c28: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x136c28u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x136c2c: 0x3e00008  jr          $ra
    ctx->pc = 0x136C2Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x136C30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136C2Cu;
            // 0x136c30: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x136A98u: goto label_136a98;
            case 0x136AC8u: goto label_136ac8;
            case 0x136AD0u: goto label_136ad0;
            case 0x136AE8u: goto label_136ae8;
            case 0x136AF0u: goto label_136af0;
            case 0x136AF8u: goto label_136af8;
            case 0x136AFCu: goto label_136afc;
            case 0x136B30u: goto label_136b30;
            case 0x136B38u: goto label_136b38;
            case 0x136B50u: goto label_136b50;
            case 0x136B58u: goto label_136b58;
            case 0x136B60u: goto label_136b60;
            case 0x136B64u: goto label_136b64;
            case 0x136BA0u: goto label_136ba0;
            case 0x136BB8u: goto label_136bb8;
            case 0x136BC0u: goto label_136bc0;
            case 0x136BDCu: goto label_136bdc;
            case 0x136BE4u: goto label_136be4;
            case 0x136BF0u: goto label_136bf0;
            case 0x136BF8u: goto label_136bf8;
            case 0x136C20u: goto label_136c20;
            case 0x136C74u: goto label_136c74;
            case 0x136C80u: goto label_136c80;
            case 0x136C94u: goto label_136c94;
            case 0x136CA0u: goto label_136ca0;
            case 0x136CB4u: goto label_136cb4;
            case 0x136CC0u: goto label_136cc0;
            case 0x136CC8u: goto label_136cc8;
            case 0x136CE0u: goto label_136ce0;
            case 0x136CE8u: goto label_136ce8;
            case 0x136CF4u: goto label_136cf4;
            case 0x136D1Cu: goto label_136d1c;
            case 0x136D28u: goto label_136d28;
            case 0x136D2Cu: goto label_136d2c;
            case 0x136D30u: goto label_136d30;
            case 0x136D70u: goto label_136d70;
            case 0x136D88u: goto label_136d88;
            case 0x136D90u: goto label_136d90;
            case 0x136DACu: goto label_136dac;
            case 0x136DB4u: goto label_136db4;
            case 0x136DC0u: goto label_136dc0;
            case 0x136DC8u: goto label_136dc8;
            case 0x136DF0u: goto label_136df0;
            case 0x136E38u: goto label_136e38;
            case 0x136E50u: goto label_136e50;
            case 0x136E58u: goto label_136e58;
            case 0x136E74u: goto label_136e74;
            case 0x136E7Cu: goto label_136e7c;
            case 0x136E88u: goto label_136e88;
            case 0x136E90u: goto label_136e90;
            case 0x136EBCu: goto label_136ebc;
            case 0x136EFCu: goto label_136efc;
            case 0x136F08u: goto label_136f08;
            case 0x136F1Cu: goto label_136f1c;
            case 0x136F28u: goto label_136f28;
            case 0x136F30u: goto label_136f30;
            case 0x136F50u: goto label_136f50;
            case 0x136F58u: goto label_136f58;
            case 0x136F60u: goto label_136f60;
            case 0x136F84u: goto label_136f84;
            case 0x136F88u: goto label_136f88;
            default: break;
        }
        return;
    }
    ctx->pc = 0x136C34u;
    // 0x136c34: 0x0  nop
    ctx->pc = 0x136c34u;
    // NOP
    // 0x136c38: 0x3e00008  jr          $ra
    ctx->pc = 0x136C38u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x136C3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136C38u;
            // 0x136c3c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x136A98u: goto label_136a98;
            case 0x136AC8u: goto label_136ac8;
            case 0x136AD0u: goto label_136ad0;
            case 0x136AE8u: goto label_136ae8;
            case 0x136AF0u: goto label_136af0;
            case 0x136AF8u: goto label_136af8;
            case 0x136AFCu: goto label_136afc;
            case 0x136B30u: goto label_136b30;
            case 0x136B38u: goto label_136b38;
            case 0x136B50u: goto label_136b50;
            case 0x136B58u: goto label_136b58;
            case 0x136B60u: goto label_136b60;
            case 0x136B64u: goto label_136b64;
            case 0x136BA0u: goto label_136ba0;
            case 0x136BB8u: goto label_136bb8;
            case 0x136BC0u: goto label_136bc0;
            case 0x136BDCu: goto label_136bdc;
            case 0x136BE4u: goto label_136be4;
            case 0x136BF0u: goto label_136bf0;
            case 0x136BF8u: goto label_136bf8;
            case 0x136C20u: goto label_136c20;
            case 0x136C74u: goto label_136c74;
            case 0x136C80u: goto label_136c80;
            case 0x136C94u: goto label_136c94;
            case 0x136CA0u: goto label_136ca0;
            case 0x136CB4u: goto label_136cb4;
            case 0x136CC0u: goto label_136cc0;
            case 0x136CC8u: goto label_136cc8;
            case 0x136CE0u: goto label_136ce0;
            case 0x136CE8u: goto label_136ce8;
            case 0x136CF4u: goto label_136cf4;
            case 0x136D1Cu: goto label_136d1c;
            case 0x136D28u: goto label_136d28;
            case 0x136D2Cu: goto label_136d2c;
            case 0x136D30u: goto label_136d30;
            case 0x136D70u: goto label_136d70;
            case 0x136D88u: goto label_136d88;
            case 0x136D90u: goto label_136d90;
            case 0x136DACu: goto label_136dac;
            case 0x136DB4u: goto label_136db4;
            case 0x136DC0u: goto label_136dc0;
            case 0x136DC8u: goto label_136dc8;
            case 0x136DF0u: goto label_136df0;
            case 0x136E38u: goto label_136e38;
            case 0x136E50u: goto label_136e50;
            case 0x136E58u: goto label_136e58;
            case 0x136E74u: goto label_136e74;
            case 0x136E7Cu: goto label_136e7c;
            case 0x136E88u: goto label_136e88;
            case 0x136E90u: goto label_136e90;
            case 0x136EBCu: goto label_136ebc;
            case 0x136EFCu: goto label_136efc;
            case 0x136F08u: goto label_136f08;
            case 0x136F1Cu: goto label_136f1c;
            case 0x136F28u: goto label_136f28;
            case 0x136F30u: goto label_136f30;
            case 0x136F50u: goto label_136f50;
            case 0x136F58u: goto label_136f58;
            case 0x136F60u: goto label_136f60;
            case 0x136F84u: goto label_136f84;
            case 0x136F88u: goto label_136f88;
            default: break;
        }
        return;
    }
    ctx->pc = 0x136C40u;
    // 0x136c40: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x136c40u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x136c44: 0xffb10028  sd          $s1, 0x28($sp)
    ctx->pc = 0x136c44u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 17));
    // 0x136c48: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x136c48u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136c4c: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x136c4cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x136c50: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x136c50u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136c54: 0xffb30038  sd          $s3, 0x38($sp)
    ctx->pc = 0x136c54u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 19));
    // 0x136c58: 0xe0982d  daddu       $s3, $a3, $zero
    ctx->pc = 0x136c58u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136c5c: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x136c5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x136c60: 0x14800007  bnez        $a0, . + 4 + (0x7 << 2)
    ctx->pc = 0x136C60u;
    {
        const bool branch_taken_0x136c60 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x136C64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136C60u;
            // 0x136c64: 0xffbf0040  sd          $ra, 0x40($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136c60) {
            ctx->pc = 0x136C80u;
            goto label_136c80;
        }
    }
    ctx->pc = 0x136C68u;
    // 0x136c68: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x136c68u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x136c6c: 0xc04d480  jal         func_135200
    ctx->pc = 0x136C6Cu;
    SET_GPR_U32(ctx, 31, 0x136C74u);
    ctx->pc = 0x136C70u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x136C6Cu;
            // 0x136c70: 0x2484c1c0  addiu       $a0, $a0, -0x3E40 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294951360));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136C74u; }
        if (ctx->pc != 0x136C74u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136C74u; }
        if (ctx->pc != 0x136C74u) { return; }
    }
    ctx->pc = 0x136C74u;
label_136c74:
    // 0x136c74: 0x1000002d  b           . + 4 + (0x2D << 2)
    ctx->pc = 0x136C74u;
    {
        const bool branch_taken_0x136c74 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x136C78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136C74u;
            // 0x136c78: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136c74) {
            ctx->pc = 0x136D2Cu;
            goto label_136d2c;
        }
    }
    ctx->pc = 0x136C7Cu;
    // 0x136c7c: 0x0  nop
    ctx->pc = 0x136c7cu;
    // NOP
label_136c80:
    // 0x136c80: 0x16400007  bnez        $s2, . + 4 + (0x7 << 2)
    ctx->pc = 0x136C80u;
    {
        const bool branch_taken_0x136c80 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 0));
        if (branch_taken_0x136c80) {
            ctx->pc = 0x136CA0u;
            goto label_136ca0;
        }
    }
    ctx->pc = 0x136C88u;
    // 0x136c88: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x136c88u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x136c8c: 0xc04d480  jal         func_135200
    ctx->pc = 0x136C8Cu;
    SET_GPR_U32(ctx, 31, 0x136C94u);
    ctx->pc = 0x136C90u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x136C8Cu;
            // 0x136c90: 0x2484c1e8  addiu       $a0, $a0, -0x3E18 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294951400));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136C94u; }
        if (ctx->pc != 0x136C94u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136C94u; }
        if (ctx->pc != 0x136C94u) { return; }
    }
    ctx->pc = 0x136C94u;
label_136c94:
    // 0x136c94: 0x10000025  b           . + 4 + (0x25 << 2)
    ctx->pc = 0x136C94u;
    {
        const bool branch_taken_0x136c94 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x136C98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136C94u;
            // 0x136c98: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136c94) {
            ctx->pc = 0x136D2Cu;
            goto label_136d2c;
        }
    }
    ctx->pc = 0x136C9Cu;
    // 0x136c9c: 0x0  nop
    ctx->pc = 0x136c9cu;
    // NOP
label_136ca0:
    // 0x136ca0: 0x16200007  bnez        $s1, . + 4 + (0x7 << 2)
    ctx->pc = 0x136CA0u;
    {
        const bool branch_taken_0x136ca0 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        if (branch_taken_0x136ca0) {
            ctx->pc = 0x136CC0u;
            goto label_136cc0;
        }
    }
    ctx->pc = 0x136CA8u;
    // 0x136ca8: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x136ca8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x136cac: 0xc04d480  jal         func_135200
    ctx->pc = 0x136CACu;
    SET_GPR_U32(ctx, 31, 0x136CB4u);
    ctx->pc = 0x136CB0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x136CACu;
            // 0x136cb0: 0x2484c210  addiu       $a0, $a0, -0x3DF0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294951440));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136CB4u; }
        if (ctx->pc != 0x136CB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136CB4u; }
        if (ctx->pc != 0x136CB4u) { return; }
    }
    ctx->pc = 0x136CB4u;
label_136cb4:
    // 0x136cb4: 0x1000001d  b           . + 4 + (0x1D << 2)
    ctx->pc = 0x136CB4u;
    {
        const bool branch_taken_0x136cb4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x136CB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136CB4u;
            // 0x136cb8: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136cb4) {
            ctx->pc = 0x136D2Cu;
            goto label_136d2c;
        }
    }
    ctx->pc = 0x136CBCu;
    // 0x136cbc: 0x0  nop
    ctx->pc = 0x136cbcu;
    // NOP
label_136cc0:
    // 0x136cc0: 0xc04d558  jal         func_135560
    ctx->pc = 0x136CC0u;
    SET_GPR_U32(ctx, 31, 0x136CC8u);
    ctx->pc = 0x135560u;
    if (runtime->hasFunction(0x135560u)) {
        auto targetFn = runtime->lookupFunction(0x135560u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136CC8u; }
        if (ctx->pc != 0x136CC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135560_0x135560(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136CC8u; }
        if (ctx->pc != 0x136CC8u) { return; }
    }
    ctx->pc = 0x136CC8u;
label_136cc8:
    // 0x136cc8: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x136cc8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136ccc: 0x56000006  bnel        $s0, $zero, . + 4 + (0x6 << 2)
    ctx->pc = 0x136CCCu;
    {
        const bool branch_taken_0x136ccc = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x136ccc) {
            ctx->pc = 0x136CD0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x136CCCu;
            // 0x136cd0: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x136CE8u;
            goto label_136ce8;
        }
    }
    ctx->pc = 0x136CD4u;
    // 0x136cd4: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x136cd4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x136cd8: 0xc04d480  jal         func_135200
    ctx->pc = 0x136CD8u;
    SET_GPR_U32(ctx, 31, 0x136CE0u);
    ctx->pc = 0x136CDCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x136CD8u;
            // 0x136cdc: 0x2484c238  addiu       $a0, $a0, -0x3DC8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294951480));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136CE0u; }
        if (ctx->pc != 0x136CE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136CE0u; }
        if (ctx->pc != 0x136CE0u) { return; }
    }
    ctx->pc = 0x136CE0u;
label_136ce0:
    // 0x136ce0: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x136CE0u;
    {
        const bool branch_taken_0x136ce0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x136CE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136CE0u;
            // 0x136ce4: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136ce0) {
            ctx->pc = 0x136D2Cu;
            goto label_136d2c;
        }
    }
    ctx->pc = 0x136CE8u;
label_136ce8:
    // 0x136ce8: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x136ce8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136cec: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x136CECu;
    SET_GPR_U32(ctx, 31, 0x136CF4u);
    ctx->pc = 0x136CF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x136CECu;
            // 0x136cf0: 0x24060014  addiu       $a2, $zero, 0x14 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136CF4u; }
        if (ctx->pc != 0x136CF4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136CF4u; }
        if (ctx->pc != 0x136CF4u) { return; }
    }
    ctx->pc = 0x136CF4u;
label_136cf4:
    // 0x136cf4: 0xafb10000  sw          $s1, 0x0($sp)
    ctx->pc = 0x136cf4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 17));
    // 0x136cf8: 0xafb20004  sw          $s2, 0x4($sp)
    ctx->pc = 0x136cf8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 18));
    // 0x136cfc: 0xafb30008  sw          $s3, 0x8($sp)
    ctx->pc = 0x136cfcu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 19));
    // 0x136d00: 0x8e020060  lw          $v0, 0x60($s0)
    ctx->pc = 0x136d00u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 96)));
    // 0x136d04: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x136D04u;
    {
        const bool branch_taken_0x136d04 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x136D08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136D04u;
            // 0x136d08: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136d04) {
            ctx->pc = 0x136D28u;
            goto label_136d28;
        }
    }
    ctx->pc = 0x136D0Cu;
    // 0x136d0c: 0x24050002  addiu       $a1, $zero, 0x2
    ctx->pc = 0x136d0cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x136d10: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x136d10u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136d14: 0x40f809  jalr        $v0
    ctx->pc = 0x136D14u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x136D1Cu);
        ctx->pc = 0x136D18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136D14u;
            // 0x136d18: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x136D1Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x136A98u: goto label_136a98;
            case 0x136AC8u: goto label_136ac8;
            case 0x136AD0u: goto label_136ad0;
            case 0x136AE8u: goto label_136ae8;
            case 0x136AF0u: goto label_136af0;
            case 0x136AF8u: goto label_136af8;
            case 0x136AFCu: goto label_136afc;
            case 0x136B30u: goto label_136b30;
            case 0x136B38u: goto label_136b38;
            case 0x136B50u: goto label_136b50;
            case 0x136B58u: goto label_136b58;
            case 0x136B60u: goto label_136b60;
            case 0x136B64u: goto label_136b64;
            case 0x136BA0u: goto label_136ba0;
            case 0x136BB8u: goto label_136bb8;
            case 0x136BC0u: goto label_136bc0;
            case 0x136BDCu: goto label_136bdc;
            case 0x136BE4u: goto label_136be4;
            case 0x136BF0u: goto label_136bf0;
            case 0x136BF8u: goto label_136bf8;
            case 0x136C20u: goto label_136c20;
            case 0x136C74u: goto label_136c74;
            case 0x136C80u: goto label_136c80;
            case 0x136C94u: goto label_136c94;
            case 0x136CA0u: goto label_136ca0;
            case 0x136CB4u: goto label_136cb4;
            case 0x136CC0u: goto label_136cc0;
            case 0x136CC8u: goto label_136cc8;
            case 0x136CE0u: goto label_136ce0;
            case 0x136CE8u: goto label_136ce8;
            case 0x136CF4u: goto label_136cf4;
            case 0x136D1Cu: goto label_136d1c;
            case 0x136D28u: goto label_136d28;
            case 0x136D2Cu: goto label_136d2c;
            case 0x136D30u: goto label_136d30;
            case 0x136D70u: goto label_136d70;
            case 0x136D88u: goto label_136d88;
            case 0x136D90u: goto label_136d90;
            case 0x136DACu: goto label_136dac;
            case 0x136DB4u: goto label_136db4;
            case 0x136DC0u: goto label_136dc0;
            case 0x136DC8u: goto label_136dc8;
            case 0x136DF0u: goto label_136df0;
            case 0x136E38u: goto label_136e38;
            case 0x136E50u: goto label_136e50;
            case 0x136E58u: goto label_136e58;
            case 0x136E74u: goto label_136e74;
            case 0x136E7Cu: goto label_136e7c;
            case 0x136E88u: goto label_136e88;
            case 0x136E90u: goto label_136e90;
            case 0x136EBCu: goto label_136ebc;
            case 0x136EFCu: goto label_136efc;
            case 0x136F08u: goto label_136f08;
            case 0x136F1Cu: goto label_136f1c;
            case 0x136F28u: goto label_136f28;
            case 0x136F30u: goto label_136f30;
            case 0x136F50u: goto label_136f50;
            case 0x136F58u: goto label_136f58;
            case 0x136F60u: goto label_136f60;
            case 0x136F84u: goto label_136f84;
            case 0x136F88u: goto label_136f88;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x136D1Cu; }
            if (ctx->pc != 0x136D1Cu) { return; }
        }
        }
    }
    ctx->pc = 0x136D1Cu;
label_136d1c:
    // 0x136d1c: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x136D1Cu;
    {
        const bool branch_taken_0x136d1c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x136D20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136D1Cu;
            // 0x136d20: 0xdfb00020  ld          $s0, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136d1c) {
            ctx->pc = 0x136D30u;
            goto label_136d30;
        }
    }
    ctx->pc = 0x136D24u;
    // 0x136d24: 0x0  nop
    ctx->pc = 0x136d24u;
    // NOP
label_136d28:
    // 0x136d28: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x136d28u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_136d2c:
    // 0x136d2c: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x136d2cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_136d30:
    // 0x136d30: 0xdfb10028  ld          $s1, 0x28($sp)
    ctx->pc = 0x136d30u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x136d34: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x136d34u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x136d38: 0xdfb30038  ld          $s3, 0x38($sp)
    ctx->pc = 0x136d38u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x136d3c: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x136d3cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x136d40: 0x3e00008  jr          $ra
    ctx->pc = 0x136D40u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x136D44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136D40u;
            // 0x136d44: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x136A98u: goto label_136a98;
            case 0x136AC8u: goto label_136ac8;
            case 0x136AD0u: goto label_136ad0;
            case 0x136AE8u: goto label_136ae8;
            case 0x136AF0u: goto label_136af0;
            case 0x136AF8u: goto label_136af8;
            case 0x136AFCu: goto label_136afc;
            case 0x136B30u: goto label_136b30;
            case 0x136B38u: goto label_136b38;
            case 0x136B50u: goto label_136b50;
            case 0x136B58u: goto label_136b58;
            case 0x136B60u: goto label_136b60;
            case 0x136B64u: goto label_136b64;
            case 0x136BA0u: goto label_136ba0;
            case 0x136BB8u: goto label_136bb8;
            case 0x136BC0u: goto label_136bc0;
            case 0x136BDCu: goto label_136bdc;
            case 0x136BE4u: goto label_136be4;
            case 0x136BF0u: goto label_136bf0;
            case 0x136BF8u: goto label_136bf8;
            case 0x136C20u: goto label_136c20;
            case 0x136C74u: goto label_136c74;
            case 0x136C80u: goto label_136c80;
            case 0x136C94u: goto label_136c94;
            case 0x136CA0u: goto label_136ca0;
            case 0x136CB4u: goto label_136cb4;
            case 0x136CC0u: goto label_136cc0;
            case 0x136CC8u: goto label_136cc8;
            case 0x136CE0u: goto label_136ce0;
            case 0x136CE8u: goto label_136ce8;
            case 0x136CF4u: goto label_136cf4;
            case 0x136D1Cu: goto label_136d1c;
            case 0x136D28u: goto label_136d28;
            case 0x136D2Cu: goto label_136d2c;
            case 0x136D30u: goto label_136d30;
            case 0x136D70u: goto label_136d70;
            case 0x136D88u: goto label_136d88;
            case 0x136D90u: goto label_136d90;
            case 0x136DACu: goto label_136dac;
            case 0x136DB4u: goto label_136db4;
            case 0x136DC0u: goto label_136dc0;
            case 0x136DC8u: goto label_136dc8;
            case 0x136DF0u: goto label_136df0;
            case 0x136E38u: goto label_136e38;
            case 0x136E50u: goto label_136e50;
            case 0x136E58u: goto label_136e58;
            case 0x136E74u: goto label_136e74;
            case 0x136E7Cu: goto label_136e7c;
            case 0x136E88u: goto label_136e88;
            case 0x136E90u: goto label_136e90;
            case 0x136EBCu: goto label_136ebc;
            case 0x136EFCu: goto label_136efc;
            case 0x136F08u: goto label_136f08;
            case 0x136F1Cu: goto label_136f1c;
            case 0x136F28u: goto label_136f28;
            case 0x136F30u: goto label_136f30;
            case 0x136F50u: goto label_136f50;
            case 0x136F58u: goto label_136f58;
            case 0x136F60u: goto label_136f60;
            case 0x136F84u: goto label_136f84;
            case 0x136F88u: goto label_136f88;
            default: break;
        }
        return;
    }
    ctx->pc = 0x136D48u;
    // 0x136d48: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x136d48u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x136d4c: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x136d4cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x136d50: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x136d50u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136d54: 0xffb10028  sd          $s1, 0x28($sp)
    ctx->pc = 0x136d54u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 17));
    // 0x136d58: 0x14800005  bnez        $a0, . + 4 + (0x5 << 2)
    ctx->pc = 0x136D58u;
    {
        const bool branch_taken_0x136d58 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x136D5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136D58u;
            // 0x136d5c: 0xffbf0030  sd          $ra, 0x30($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136d58) {
            ctx->pc = 0x136D70u;
            goto label_136d70;
        }
    }
    ctx->pc = 0x136D60u;
    // 0x136d60: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x136d60u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x136d64: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x136D64u;
    {
        const bool branch_taken_0x136d64 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x136D68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136D64u;
            // 0x136d68: 0x2484c260  addiu       $a0, $a0, -0x3DA0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294951520));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136d64) {
            ctx->pc = 0x136DACu;
            goto label_136dac;
        }
    }
    ctx->pc = 0x136D6Cu;
    // 0x136d6c: 0x0  nop
    ctx->pc = 0x136d6cu;
    // NOP
label_136d70:
    // 0x136d70: 0x16000005  bnez        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x136D70u;
    {
        const bool branch_taken_0x136d70 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x136d70) {
            ctx->pc = 0x136D88u;
            goto label_136d88;
        }
    }
    ctx->pc = 0x136D78u;
    // 0x136d78: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x136d78u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x136d7c: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x136D7Cu;
    {
        const bool branch_taken_0x136d7c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x136D80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136D7Cu;
            // 0x136d80: 0x2484c288  addiu       $a0, $a0, -0x3D78 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294951560));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136d7c) {
            ctx->pc = 0x136DACu;
            goto label_136dac;
        }
    }
    ctx->pc = 0x136D84u;
    // 0x136d84: 0x0  nop
    ctx->pc = 0x136d84u;
    // NOP
label_136d88:
    // 0x136d88: 0xc04d558  jal         func_135560
    ctx->pc = 0x136D88u;
    SET_GPR_U32(ctx, 31, 0x136D90u);
    ctx->pc = 0x135560u;
    if (runtime->hasFunction(0x135560u)) {
        auto targetFn = runtime->lookupFunction(0x135560u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136D90u; }
        if (ctx->pc != 0x136D90u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135560_0x135560(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136D90u; }
        if (ctx->pc != 0x136D90u) { return; }
    }
    ctx->pc = 0x136D90u;
label_136d90:
    // 0x136d90: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x136d90u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136d94: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x136d94u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136d98: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x136d98u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136d9c: 0x16200008  bnez        $s1, . + 4 + (0x8 << 2)
    ctx->pc = 0x136D9Cu;
    {
        const bool branch_taken_0x136d9c = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        ctx->pc = 0x136DA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136D9Cu;
            // 0x136da0: 0x24060014  addiu       $a2, $zero, 0x14 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136d9c) {
            ctx->pc = 0x136DC0u;
            goto label_136dc0;
        }
    }
    ctx->pc = 0x136DA4u;
    // 0x136da4: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x136da4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x136da8: 0x2484c2b0  addiu       $a0, $a0, -0x3D50
    ctx->pc = 0x136da8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294951600));
label_136dac:
    // 0x136dac: 0xc04d480  jal         func_135200
    ctx->pc = 0x136DACu;
    SET_GPR_U32(ctx, 31, 0x136DB4u);
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136DB4u; }
        if (ctx->pc != 0x136DB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136DB4u; }
        if (ctx->pc != 0x136DB4u) { return; }
    }
    ctx->pc = 0x136DB4u;
label_136db4:
    // 0x136db4: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x136DB4u;
    {
        const bool branch_taken_0x136db4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x136DB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136DB4u;
            // 0x136db8: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136db4) {
            ctx->pc = 0x136DF0u;
            goto label_136df0;
        }
    }
    ctx->pc = 0x136DBCu;
    // 0x136dbc: 0x0  nop
    ctx->pc = 0x136dbcu;
    // NOP
label_136dc0:
    // 0x136dc0: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x136DC0u;
    SET_GPR_U32(ctx, 31, 0x136DC8u);
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136DC8u; }
        if (ctx->pc != 0x136DC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136DC8u; }
        if (ctx->pc != 0x136DC8u) { return; }
    }
    ctx->pc = 0x136DC8u;
label_136dc8:
    // 0x136dc8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x136dc8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x136dcc: 0xafb00004  sw          $s0, 0x4($sp)
    ctx->pc = 0x136dccu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 16));
    // 0x136dd0: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x136dd0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136dd4: 0x24050003  addiu       $a1, $zero, 0x3
    ctx->pc = 0x136dd4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x136dd8: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x136dd8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136ddc: 0x8e230060  lw          $v1, 0x60($s1)
    ctx->pc = 0x136ddcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 96)));
    // 0x136de0: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x136DE0u;
    {
        const bool branch_taken_0x136de0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x136DE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136DE0u;
            // 0x136de4: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136de0) {
            ctx->pc = 0x136DF0u;
            goto label_136df0;
        }
    }
    ctx->pc = 0x136DE8u;
    // 0x136de8: 0x60f809  jalr        $v1
    ctx->pc = 0x136DE8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x136DF0u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x136DF0u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x136A98u: goto label_136a98;
            case 0x136AC8u: goto label_136ac8;
            case 0x136AD0u: goto label_136ad0;
            case 0x136AE8u: goto label_136ae8;
            case 0x136AF0u: goto label_136af0;
            case 0x136AF8u: goto label_136af8;
            case 0x136AFCu: goto label_136afc;
            case 0x136B30u: goto label_136b30;
            case 0x136B38u: goto label_136b38;
            case 0x136B50u: goto label_136b50;
            case 0x136B58u: goto label_136b58;
            case 0x136B60u: goto label_136b60;
            case 0x136B64u: goto label_136b64;
            case 0x136BA0u: goto label_136ba0;
            case 0x136BB8u: goto label_136bb8;
            case 0x136BC0u: goto label_136bc0;
            case 0x136BDCu: goto label_136bdc;
            case 0x136BE4u: goto label_136be4;
            case 0x136BF0u: goto label_136bf0;
            case 0x136BF8u: goto label_136bf8;
            case 0x136C20u: goto label_136c20;
            case 0x136C74u: goto label_136c74;
            case 0x136C80u: goto label_136c80;
            case 0x136C94u: goto label_136c94;
            case 0x136CA0u: goto label_136ca0;
            case 0x136CB4u: goto label_136cb4;
            case 0x136CC0u: goto label_136cc0;
            case 0x136CC8u: goto label_136cc8;
            case 0x136CE0u: goto label_136ce0;
            case 0x136CE8u: goto label_136ce8;
            case 0x136CF4u: goto label_136cf4;
            case 0x136D1Cu: goto label_136d1c;
            case 0x136D28u: goto label_136d28;
            case 0x136D2Cu: goto label_136d2c;
            case 0x136D30u: goto label_136d30;
            case 0x136D70u: goto label_136d70;
            case 0x136D88u: goto label_136d88;
            case 0x136D90u: goto label_136d90;
            case 0x136DACu: goto label_136dac;
            case 0x136DB4u: goto label_136db4;
            case 0x136DC0u: goto label_136dc0;
            case 0x136DC8u: goto label_136dc8;
            case 0x136DF0u: goto label_136df0;
            case 0x136E38u: goto label_136e38;
            case 0x136E50u: goto label_136e50;
            case 0x136E58u: goto label_136e58;
            case 0x136E74u: goto label_136e74;
            case 0x136E7Cu: goto label_136e7c;
            case 0x136E88u: goto label_136e88;
            case 0x136E90u: goto label_136e90;
            case 0x136EBCu: goto label_136ebc;
            case 0x136EFCu: goto label_136efc;
            case 0x136F08u: goto label_136f08;
            case 0x136F1Cu: goto label_136f1c;
            case 0x136F28u: goto label_136f28;
            case 0x136F30u: goto label_136f30;
            case 0x136F50u: goto label_136f50;
            case 0x136F58u: goto label_136f58;
            case 0x136F60u: goto label_136f60;
            case 0x136F84u: goto label_136f84;
            case 0x136F88u: goto label_136f88;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x136DF0u; }
            if (ctx->pc != 0x136DF0u) { return; }
        }
        }
    }
    ctx->pc = 0x136DF0u;
label_136df0:
    // 0x136df0: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x136df0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x136df4: 0xdfb10028  ld          $s1, 0x28($sp)
    ctx->pc = 0x136df4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x136df8: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x136df8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x136dfc: 0x3e00008  jr          $ra
    ctx->pc = 0x136DFCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x136E00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136DFCu;
            // 0x136e00: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x136A98u: goto label_136a98;
            case 0x136AC8u: goto label_136ac8;
            case 0x136AD0u: goto label_136ad0;
            case 0x136AE8u: goto label_136ae8;
            case 0x136AF0u: goto label_136af0;
            case 0x136AF8u: goto label_136af8;
            case 0x136AFCu: goto label_136afc;
            case 0x136B30u: goto label_136b30;
            case 0x136B38u: goto label_136b38;
            case 0x136B50u: goto label_136b50;
            case 0x136B58u: goto label_136b58;
            case 0x136B60u: goto label_136b60;
            case 0x136B64u: goto label_136b64;
            case 0x136BA0u: goto label_136ba0;
            case 0x136BB8u: goto label_136bb8;
            case 0x136BC0u: goto label_136bc0;
            case 0x136BDCu: goto label_136bdc;
            case 0x136BE4u: goto label_136be4;
            case 0x136BF0u: goto label_136bf0;
            case 0x136BF8u: goto label_136bf8;
            case 0x136C20u: goto label_136c20;
            case 0x136C74u: goto label_136c74;
            case 0x136C80u: goto label_136c80;
            case 0x136C94u: goto label_136c94;
            case 0x136CA0u: goto label_136ca0;
            case 0x136CB4u: goto label_136cb4;
            case 0x136CC0u: goto label_136cc0;
            case 0x136CC8u: goto label_136cc8;
            case 0x136CE0u: goto label_136ce0;
            case 0x136CE8u: goto label_136ce8;
            case 0x136CF4u: goto label_136cf4;
            case 0x136D1Cu: goto label_136d1c;
            case 0x136D28u: goto label_136d28;
            case 0x136D2Cu: goto label_136d2c;
            case 0x136D30u: goto label_136d30;
            case 0x136D70u: goto label_136d70;
            case 0x136D88u: goto label_136d88;
            case 0x136D90u: goto label_136d90;
            case 0x136DACu: goto label_136dac;
            case 0x136DB4u: goto label_136db4;
            case 0x136DC0u: goto label_136dc0;
            case 0x136DC8u: goto label_136dc8;
            case 0x136DF0u: goto label_136df0;
            case 0x136E38u: goto label_136e38;
            case 0x136E50u: goto label_136e50;
            case 0x136E58u: goto label_136e58;
            case 0x136E74u: goto label_136e74;
            case 0x136E7Cu: goto label_136e7c;
            case 0x136E88u: goto label_136e88;
            case 0x136E90u: goto label_136e90;
            case 0x136EBCu: goto label_136ebc;
            case 0x136EFCu: goto label_136efc;
            case 0x136F08u: goto label_136f08;
            case 0x136F1Cu: goto label_136f1c;
            case 0x136F28u: goto label_136f28;
            case 0x136F30u: goto label_136f30;
            case 0x136F50u: goto label_136f50;
            case 0x136F58u: goto label_136f58;
            case 0x136F60u: goto label_136f60;
            case 0x136F84u: goto label_136f84;
            case 0x136F88u: goto label_136f88;
            default: break;
        }
        return;
    }
    ctx->pc = 0x136E04u;
    // 0x136e04: 0x0  nop
    ctx->pc = 0x136e04u;
    // NOP
    // 0x136e08: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x136e08u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x136e0c: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x136e0cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x136e10: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x136e10u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136e14: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x136e14u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x136e18: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x136e18u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136e1c: 0xffb10028  sd          $s1, 0x28($sp)
    ctx->pc = 0x136e1cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 17));
    // 0x136e20: 0x14800005  bnez        $a0, . + 4 + (0x5 << 2)
    ctx->pc = 0x136E20u;
    {
        const bool branch_taken_0x136e20 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x136E24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136E20u;
            // 0x136e24: 0xffbf0038  sd          $ra, 0x38($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136e20) {
            ctx->pc = 0x136E38u;
            goto label_136e38;
        }
    }
    ctx->pc = 0x136E28u;
    // 0x136e28: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x136e28u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x136e2c: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x136E2Cu;
    {
        const bool branch_taken_0x136e2c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x136E30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136E2Cu;
            // 0x136e30: 0x2484c2d8  addiu       $a0, $a0, -0x3D28 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294951640));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136e2c) {
            ctx->pc = 0x136E74u;
            goto label_136e74;
        }
    }
    ctx->pc = 0x136E34u;
    // 0x136e34: 0x0  nop
    ctx->pc = 0x136e34u;
    // NOP
label_136e38:
    // 0x136e38: 0x16000005  bnez        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x136E38u;
    {
        const bool branch_taken_0x136e38 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x136e38) {
            ctx->pc = 0x136E50u;
            goto label_136e50;
        }
    }
    ctx->pc = 0x136E40u;
    // 0x136e40: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x136e40u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x136e44: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x136E44u;
    {
        const bool branch_taken_0x136e44 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x136E48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136E44u;
            // 0x136e48: 0x2484c308  addiu       $a0, $a0, -0x3CF8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294951688));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136e44) {
            ctx->pc = 0x136E74u;
            goto label_136e74;
        }
    }
    ctx->pc = 0x136E4Cu;
    // 0x136e4c: 0x0  nop
    ctx->pc = 0x136e4cu;
    // NOP
label_136e50:
    // 0x136e50: 0xc04d558  jal         func_135560
    ctx->pc = 0x136E50u;
    SET_GPR_U32(ctx, 31, 0x136E58u);
    ctx->pc = 0x135560u;
    if (runtime->hasFunction(0x135560u)) {
        auto targetFn = runtime->lookupFunction(0x135560u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136E58u; }
        if (ctx->pc != 0x136E58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135560_0x135560(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136E58u; }
        if (ctx->pc != 0x136E58u) { return; }
    }
    ctx->pc = 0x136E58u;
label_136e58:
    // 0x136e58: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x136e58u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136e5c: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x136e5cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136e60: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x136e60u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136e64: 0x16200008  bnez        $s1, . + 4 + (0x8 << 2)
    ctx->pc = 0x136E64u;
    {
        const bool branch_taken_0x136e64 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        ctx->pc = 0x136E68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136E64u;
            // 0x136e68: 0x24060014  addiu       $a2, $zero, 0x14 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136e64) {
            ctx->pc = 0x136E88u;
            goto label_136e88;
        }
    }
    ctx->pc = 0x136E6Cu;
    // 0x136e6c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x136e6cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x136e70: 0x2484c338  addiu       $a0, $a0, -0x3CC8
    ctx->pc = 0x136e70u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294951736));
label_136e74:
    // 0x136e74: 0xc04d480  jal         func_135200
    ctx->pc = 0x136E74u;
    SET_GPR_U32(ctx, 31, 0x136E7Cu);
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136E7Cu; }
        if (ctx->pc != 0x136E7Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136E7Cu; }
        if (ctx->pc != 0x136E7Cu) { return; }
    }
    ctx->pc = 0x136E7Cu;
label_136e7c:
    // 0x136e7c: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x136E7Cu;
    {
        const bool branch_taken_0x136e7c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x136E80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136E7Cu;
            // 0x136e80: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136e7c) {
            ctx->pc = 0x136EBCu;
            goto label_136ebc;
        }
    }
    ctx->pc = 0x136E84u;
    // 0x136e84: 0x0  nop
    ctx->pc = 0x136e84u;
    // NOP
label_136e88:
    // 0x136e88: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x136E88u;
    SET_GPR_U32(ctx, 31, 0x136E90u);
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136E90u; }
        if (ctx->pc != 0x136E90u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136E90u; }
        if (ctx->pc != 0x136E90u) { return; }
    }
    ctx->pc = 0x136E90u;
label_136e90:
    // 0x136e90: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x136e90u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x136e94: 0xafb00004  sw          $s0, 0x4($sp)
    ctx->pc = 0x136e94u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 16));
    // 0x136e98: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x136e98u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136e9c: 0xafb20008  sw          $s2, 0x8($sp)
    ctx->pc = 0x136e9cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 18));
    // 0x136ea0: 0x24050005  addiu       $a1, $zero, 0x5
    ctx->pc = 0x136ea0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x136ea4: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x136ea4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136ea8: 0x8e230060  lw          $v1, 0x60($s1)
    ctx->pc = 0x136ea8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 96)));
    // 0x136eac: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x136EACu;
    {
        const bool branch_taken_0x136eac = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x136EB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136EACu;
            // 0x136eb0: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136eac) {
            ctx->pc = 0x136EBCu;
            goto label_136ebc;
        }
    }
    ctx->pc = 0x136EB4u;
    // 0x136eb4: 0x60f809  jalr        $v1
    ctx->pc = 0x136EB4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x136EBCu);
        if (jumpTarget == 0u) {
            ctx->pc = 0x136EBCu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x136A98u: goto label_136a98;
            case 0x136AC8u: goto label_136ac8;
            case 0x136AD0u: goto label_136ad0;
            case 0x136AE8u: goto label_136ae8;
            case 0x136AF0u: goto label_136af0;
            case 0x136AF8u: goto label_136af8;
            case 0x136AFCu: goto label_136afc;
            case 0x136B30u: goto label_136b30;
            case 0x136B38u: goto label_136b38;
            case 0x136B50u: goto label_136b50;
            case 0x136B58u: goto label_136b58;
            case 0x136B60u: goto label_136b60;
            case 0x136B64u: goto label_136b64;
            case 0x136BA0u: goto label_136ba0;
            case 0x136BB8u: goto label_136bb8;
            case 0x136BC0u: goto label_136bc0;
            case 0x136BDCu: goto label_136bdc;
            case 0x136BE4u: goto label_136be4;
            case 0x136BF0u: goto label_136bf0;
            case 0x136BF8u: goto label_136bf8;
            case 0x136C20u: goto label_136c20;
            case 0x136C74u: goto label_136c74;
            case 0x136C80u: goto label_136c80;
            case 0x136C94u: goto label_136c94;
            case 0x136CA0u: goto label_136ca0;
            case 0x136CB4u: goto label_136cb4;
            case 0x136CC0u: goto label_136cc0;
            case 0x136CC8u: goto label_136cc8;
            case 0x136CE0u: goto label_136ce0;
            case 0x136CE8u: goto label_136ce8;
            case 0x136CF4u: goto label_136cf4;
            case 0x136D1Cu: goto label_136d1c;
            case 0x136D28u: goto label_136d28;
            case 0x136D2Cu: goto label_136d2c;
            case 0x136D30u: goto label_136d30;
            case 0x136D70u: goto label_136d70;
            case 0x136D88u: goto label_136d88;
            case 0x136D90u: goto label_136d90;
            case 0x136DACu: goto label_136dac;
            case 0x136DB4u: goto label_136db4;
            case 0x136DC0u: goto label_136dc0;
            case 0x136DC8u: goto label_136dc8;
            case 0x136DF0u: goto label_136df0;
            case 0x136E38u: goto label_136e38;
            case 0x136E50u: goto label_136e50;
            case 0x136E58u: goto label_136e58;
            case 0x136E74u: goto label_136e74;
            case 0x136E7Cu: goto label_136e7c;
            case 0x136E88u: goto label_136e88;
            case 0x136E90u: goto label_136e90;
            case 0x136EBCu: goto label_136ebc;
            case 0x136EFCu: goto label_136efc;
            case 0x136F08u: goto label_136f08;
            case 0x136F1Cu: goto label_136f1c;
            case 0x136F28u: goto label_136f28;
            case 0x136F30u: goto label_136f30;
            case 0x136F50u: goto label_136f50;
            case 0x136F58u: goto label_136f58;
            case 0x136F60u: goto label_136f60;
            case 0x136F84u: goto label_136f84;
            case 0x136F88u: goto label_136f88;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x136EBCu; }
            if (ctx->pc != 0x136EBCu) { return; }
        }
        }
    }
    ctx->pc = 0x136EBCu;
label_136ebc:
    // 0x136ebc: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x136ebcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x136ec0: 0xdfb10028  ld          $s1, 0x28($sp)
    ctx->pc = 0x136ec0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x136ec4: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x136ec4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x136ec8: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x136ec8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x136ecc: 0x3e00008  jr          $ra
    ctx->pc = 0x136ECCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x136ED0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136ECCu;
            // 0x136ed0: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x136A98u: goto label_136a98;
            case 0x136AC8u: goto label_136ac8;
            case 0x136AD0u: goto label_136ad0;
            case 0x136AE8u: goto label_136ae8;
            case 0x136AF0u: goto label_136af0;
            case 0x136AF8u: goto label_136af8;
            case 0x136AFCu: goto label_136afc;
            case 0x136B30u: goto label_136b30;
            case 0x136B38u: goto label_136b38;
            case 0x136B50u: goto label_136b50;
            case 0x136B58u: goto label_136b58;
            case 0x136B60u: goto label_136b60;
            case 0x136B64u: goto label_136b64;
            case 0x136BA0u: goto label_136ba0;
            case 0x136BB8u: goto label_136bb8;
            case 0x136BC0u: goto label_136bc0;
            case 0x136BDCu: goto label_136bdc;
            case 0x136BE4u: goto label_136be4;
            case 0x136BF0u: goto label_136bf0;
            case 0x136BF8u: goto label_136bf8;
            case 0x136C20u: goto label_136c20;
            case 0x136C74u: goto label_136c74;
            case 0x136C80u: goto label_136c80;
            case 0x136C94u: goto label_136c94;
            case 0x136CA0u: goto label_136ca0;
            case 0x136CB4u: goto label_136cb4;
            case 0x136CC0u: goto label_136cc0;
            case 0x136CC8u: goto label_136cc8;
            case 0x136CE0u: goto label_136ce0;
            case 0x136CE8u: goto label_136ce8;
            case 0x136CF4u: goto label_136cf4;
            case 0x136D1Cu: goto label_136d1c;
            case 0x136D28u: goto label_136d28;
            case 0x136D2Cu: goto label_136d2c;
            case 0x136D30u: goto label_136d30;
            case 0x136D70u: goto label_136d70;
            case 0x136D88u: goto label_136d88;
            case 0x136D90u: goto label_136d90;
            case 0x136DACu: goto label_136dac;
            case 0x136DB4u: goto label_136db4;
            case 0x136DC0u: goto label_136dc0;
            case 0x136DC8u: goto label_136dc8;
            case 0x136DF0u: goto label_136df0;
            case 0x136E38u: goto label_136e38;
            case 0x136E50u: goto label_136e50;
            case 0x136E58u: goto label_136e58;
            case 0x136E74u: goto label_136e74;
            case 0x136E7Cu: goto label_136e7c;
            case 0x136E88u: goto label_136e88;
            case 0x136E90u: goto label_136e90;
            case 0x136EBCu: goto label_136ebc;
            case 0x136EFCu: goto label_136efc;
            case 0x136F08u: goto label_136f08;
            case 0x136F1Cu: goto label_136f1c;
            case 0x136F28u: goto label_136f28;
            case 0x136F30u: goto label_136f30;
            case 0x136F50u: goto label_136f50;
            case 0x136F58u: goto label_136f58;
            case 0x136F60u: goto label_136f60;
            case 0x136F84u: goto label_136f84;
            case 0x136F88u: goto label_136f88;
            default: break;
        }
        return;
    }
    ctx->pc = 0x136ED4u;
    // 0x136ed4: 0x0  nop
    ctx->pc = 0x136ed4u;
    // NOP
    // 0x136ed8: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x136ed8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x136edc: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x136edcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x136ee0: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x136ee0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136ee4: 0xffb10028  sd          $s1, 0x28($sp)
    ctx->pc = 0x136ee4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 17));
    // 0x136ee8: 0x14800007  bnez        $a0, . + 4 + (0x7 << 2)
    ctx->pc = 0x136EE8u;
    {
        const bool branch_taken_0x136ee8 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x136EECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136EE8u;
            // 0x136eec: 0xffbf0030  sd          $ra, 0x30($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136ee8) {
            ctx->pc = 0x136F08u;
            goto label_136f08;
        }
    }
    ctx->pc = 0x136EF0u;
    // 0x136ef0: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x136ef0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x136ef4: 0xc04d480  jal         func_135200
    ctx->pc = 0x136EF4u;
    SET_GPR_U32(ctx, 31, 0x136EFCu);
    ctx->pc = 0x136EF8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x136EF4u;
            // 0x136ef8: 0x2484c360  addiu       $a0, $a0, -0x3CA0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294951776));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136EFCu; }
        if (ctx->pc != 0x136EFCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136EFCu; }
        if (ctx->pc != 0x136EFCu) { return; }
    }
    ctx->pc = 0x136EFCu;
label_136efc:
    // 0x136efc: 0x10000022  b           . + 4 + (0x22 << 2)
    ctx->pc = 0x136EFCu;
    {
        const bool branch_taken_0x136efc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x136F00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136EFCu;
            // 0x136f00: 0xdfb00020  ld          $s0, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136efc) {
            ctx->pc = 0x136F88u;
            goto label_136f88;
        }
    }
    ctx->pc = 0x136F04u;
    // 0x136f04: 0x0  nop
    ctx->pc = 0x136f04u;
    // NOP
label_136f08:
    // 0x136f08: 0x16000007  bnez        $s0, . + 4 + (0x7 << 2)
    ctx->pc = 0x136F08u;
    {
        const bool branch_taken_0x136f08 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x136f08) {
            ctx->pc = 0x136F28u;
            goto label_136f28;
        }
    }
    ctx->pc = 0x136F10u;
    // 0x136f10: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x136f10u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x136f14: 0xc04d480  jal         func_135200
    ctx->pc = 0x136F14u;
    SET_GPR_U32(ctx, 31, 0x136F1Cu);
    ctx->pc = 0x136F18u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x136F14u;
            // 0x136f18: 0x2484c388  addiu       $a0, $a0, -0x3C78 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294951816));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136F1Cu; }
        if (ctx->pc != 0x136F1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136F1Cu; }
        if (ctx->pc != 0x136F1Cu) { return; }
    }
    ctx->pc = 0x136F1Cu;
label_136f1c:
    // 0x136f1c: 0x1000001a  b           . + 4 + (0x1A << 2)
    ctx->pc = 0x136F1Cu;
    {
        const bool branch_taken_0x136f1c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x136F20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136F1Cu;
            // 0x136f20: 0xdfb00020  ld          $s0, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136f1c) {
            ctx->pc = 0x136F88u;
            goto label_136f88;
        }
    }
    ctx->pc = 0x136F24u;
    // 0x136f24: 0x0  nop
    ctx->pc = 0x136f24u;
    // NOP
label_136f28:
    // 0x136f28: 0xc04d558  jal         func_135560
    ctx->pc = 0x136F28u;
    SET_GPR_U32(ctx, 31, 0x136F30u);
    ctx->pc = 0x135560u;
    if (runtime->hasFunction(0x135560u)) {
        auto targetFn = runtime->lookupFunction(0x135560u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136F30u; }
        if (ctx->pc != 0x136F30u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135560_0x135560(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136F30u; }
        if (ctx->pc != 0x136F30u) { return; }
    }
    ctx->pc = 0x136F30u;
label_136f30:
    // 0x136f30: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x136f30u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136f34: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x136f34u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136f38: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x136f38u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136f3c: 0x16200006  bnez        $s1, . + 4 + (0x6 << 2)
    ctx->pc = 0x136F3Cu;
    {
        const bool branch_taken_0x136f3c = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        ctx->pc = 0x136F40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136F3Cu;
            // 0x136f40: 0x24060014  addiu       $a2, $zero, 0x14 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136f3c) {
            ctx->pc = 0x136F58u;
            goto label_136f58;
        }
    }
    ctx->pc = 0x136F44u;
    // 0x136f44: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x136f44u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x136f48: 0xc04d480  jal         func_135200
    ctx->pc = 0x136F48u;
    SET_GPR_U32(ctx, 31, 0x136F50u);
    ctx->pc = 0x136F4Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x136F48u;
            // 0x136f4c: 0x2484c3b0  addiu       $a0, $a0, -0x3C50 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294951856));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136F50u; }
        if (ctx->pc != 0x136F50u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136F50u; }
        if (ctx->pc != 0x136F50u) { return; }
    }
    ctx->pc = 0x136F50u;
label_136f50:
    // 0x136f50: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x136F50u;
    {
        const bool branch_taken_0x136f50 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x136F54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136F50u;
            // 0x136f54: 0xdfb00020  ld          $s0, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136f50) {
            ctx->pc = 0x136F88u;
            goto label_136f88;
        }
    }
    ctx->pc = 0x136F58u;
label_136f58:
    // 0x136f58: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x136F58u;
    SET_GPR_U32(ctx, 31, 0x136F60u);
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136F60u; }
        if (ctx->pc != 0x136F60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136F60u; }
        if (ctx->pc != 0x136F60u) { return; }
    }
    ctx->pc = 0x136F60u;
label_136f60:
    // 0x136f60: 0x24050006  addiu       $a1, $zero, 0x6
    ctx->pc = 0x136f60u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x136f64: 0xafb00004  sw          $s0, 0x4($sp)
    ctx->pc = 0x136f64u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 16));
    // 0x136f68: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x136f68u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136f6c: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x136f6cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136f70: 0x8e220060  lw          $v0, 0x60($s1)
    ctx->pc = 0x136f70u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 96)));
    // 0x136f74: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x136F74u;
    {
        const bool branch_taken_0x136f74 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x136F78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136F74u;
            // 0x136f78: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136f74) {
            ctx->pc = 0x136F84u;
            goto label_136f84;
        }
    }
    ctx->pc = 0x136F7Cu;
    // 0x136f7c: 0x40f809  jalr        $v0
    ctx->pc = 0x136F7Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x136F84u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x136F84u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x136A98u: goto label_136a98;
            case 0x136AC8u: goto label_136ac8;
            case 0x136AD0u: goto label_136ad0;
            case 0x136AE8u: goto label_136ae8;
            case 0x136AF0u: goto label_136af0;
            case 0x136AF8u: goto label_136af8;
            case 0x136AFCu: goto label_136afc;
            case 0x136B30u: goto label_136b30;
            case 0x136B38u: goto label_136b38;
            case 0x136B50u: goto label_136b50;
            case 0x136B58u: goto label_136b58;
            case 0x136B60u: goto label_136b60;
            case 0x136B64u: goto label_136b64;
            case 0x136BA0u: goto label_136ba0;
            case 0x136BB8u: goto label_136bb8;
            case 0x136BC0u: goto label_136bc0;
            case 0x136BDCu: goto label_136bdc;
            case 0x136BE4u: goto label_136be4;
            case 0x136BF0u: goto label_136bf0;
            case 0x136BF8u: goto label_136bf8;
            case 0x136C20u: goto label_136c20;
            case 0x136C74u: goto label_136c74;
            case 0x136C80u: goto label_136c80;
            case 0x136C94u: goto label_136c94;
            case 0x136CA0u: goto label_136ca0;
            case 0x136CB4u: goto label_136cb4;
            case 0x136CC0u: goto label_136cc0;
            case 0x136CC8u: goto label_136cc8;
            case 0x136CE0u: goto label_136ce0;
            case 0x136CE8u: goto label_136ce8;
            case 0x136CF4u: goto label_136cf4;
            case 0x136D1Cu: goto label_136d1c;
            case 0x136D28u: goto label_136d28;
            case 0x136D2Cu: goto label_136d2c;
            case 0x136D30u: goto label_136d30;
            case 0x136D70u: goto label_136d70;
            case 0x136D88u: goto label_136d88;
            case 0x136D90u: goto label_136d90;
            case 0x136DACu: goto label_136dac;
            case 0x136DB4u: goto label_136db4;
            case 0x136DC0u: goto label_136dc0;
            case 0x136DC8u: goto label_136dc8;
            case 0x136DF0u: goto label_136df0;
            case 0x136E38u: goto label_136e38;
            case 0x136E50u: goto label_136e50;
            case 0x136E58u: goto label_136e58;
            case 0x136E74u: goto label_136e74;
            case 0x136E7Cu: goto label_136e7c;
            case 0x136E88u: goto label_136e88;
            case 0x136E90u: goto label_136e90;
            case 0x136EBCu: goto label_136ebc;
            case 0x136EFCu: goto label_136efc;
            case 0x136F08u: goto label_136f08;
            case 0x136F1Cu: goto label_136f1c;
            case 0x136F28u: goto label_136f28;
            case 0x136F30u: goto label_136f30;
            case 0x136F50u: goto label_136f50;
            case 0x136F58u: goto label_136f58;
            case 0x136F60u: goto label_136f60;
            case 0x136F84u: goto label_136f84;
            case 0x136F88u: goto label_136f88;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x136F84u; }
            if (ctx->pc != 0x136F84u) { return; }
        }
        }
    }
    ctx->pc = 0x136F84u;
label_136f84:
    // 0x136f84: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x136f84u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_136f88:
    // 0x136f88: 0xdfb10028  ld          $s1, 0x28($sp)
    ctx->pc = 0x136f88u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x136f8c: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x136f8cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x136f90: 0x3e00008  jr          $ra
    ctx->pc = 0x136F90u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x136F94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136F90u;
            // 0x136f94: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x136A98u: goto label_136a98;
            case 0x136AC8u: goto label_136ac8;
            case 0x136AD0u: goto label_136ad0;
            case 0x136AE8u: goto label_136ae8;
            case 0x136AF0u: goto label_136af0;
            case 0x136AF8u: goto label_136af8;
            case 0x136AFCu: goto label_136afc;
            case 0x136B30u: goto label_136b30;
            case 0x136B38u: goto label_136b38;
            case 0x136B50u: goto label_136b50;
            case 0x136B58u: goto label_136b58;
            case 0x136B60u: goto label_136b60;
            case 0x136B64u: goto label_136b64;
            case 0x136BA0u: goto label_136ba0;
            case 0x136BB8u: goto label_136bb8;
            case 0x136BC0u: goto label_136bc0;
            case 0x136BDCu: goto label_136bdc;
            case 0x136BE4u: goto label_136be4;
            case 0x136BF0u: goto label_136bf0;
            case 0x136BF8u: goto label_136bf8;
            case 0x136C20u: goto label_136c20;
            case 0x136C74u: goto label_136c74;
            case 0x136C80u: goto label_136c80;
            case 0x136C94u: goto label_136c94;
            case 0x136CA0u: goto label_136ca0;
            case 0x136CB4u: goto label_136cb4;
            case 0x136CC0u: goto label_136cc0;
            case 0x136CC8u: goto label_136cc8;
            case 0x136CE0u: goto label_136ce0;
            case 0x136CE8u: goto label_136ce8;
            case 0x136CF4u: goto label_136cf4;
            case 0x136D1Cu: goto label_136d1c;
            case 0x136D28u: goto label_136d28;
            case 0x136D2Cu: goto label_136d2c;
            case 0x136D30u: goto label_136d30;
            case 0x136D70u: goto label_136d70;
            case 0x136D88u: goto label_136d88;
            case 0x136D90u: goto label_136d90;
            case 0x136DACu: goto label_136dac;
            case 0x136DB4u: goto label_136db4;
            case 0x136DC0u: goto label_136dc0;
            case 0x136DC8u: goto label_136dc8;
            case 0x136DF0u: goto label_136df0;
            case 0x136E38u: goto label_136e38;
            case 0x136E50u: goto label_136e50;
            case 0x136E58u: goto label_136e58;
            case 0x136E74u: goto label_136e74;
            case 0x136E7Cu: goto label_136e7c;
            case 0x136E88u: goto label_136e88;
            case 0x136E90u: goto label_136e90;
            case 0x136EBCu: goto label_136ebc;
            case 0x136EFCu: goto label_136efc;
            case 0x136F08u: goto label_136f08;
            case 0x136F1Cu: goto label_136f1c;
            case 0x136F28u: goto label_136f28;
            case 0x136F30u: goto label_136f30;
            case 0x136F50u: goto label_136f50;
            case 0x136F58u: goto label_136f58;
            case 0x136F60u: goto label_136f60;
            case 0x136F84u: goto label_136f84;
            case 0x136F88u: goto label_136f88;
            default: break;
        }
        return;
    }
    ctx->pc = 0x136F98u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
