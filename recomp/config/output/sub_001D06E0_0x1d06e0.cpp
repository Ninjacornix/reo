#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D06E0
// Address: 0x1d06e0 - 0x1d16c0
void sub_001D06E0_0x1d06e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D06E0_0x1d06e0");
#endif

    switch (ctx->pc) {
        case 0x1d0754u: goto label_1d0754;
        case 0x1d0760u: goto label_1d0760;
        case 0x1d076cu: goto label_1d076c;
        case 0x1d0778u: goto label_1d0778;
        case 0x1d0784u: goto label_1d0784;
        case 0x1d0790u: goto label_1d0790;
        case 0x1d079cu: goto label_1d079c;
        case 0x1d07a8u: goto label_1d07a8;
        case 0x1d07c0u: goto label_1d07c0;
        case 0x1d07dcu: goto label_1d07dc;
        case 0x1d0840u: goto label_1d0840;
        case 0x1d0858u: goto label_1d0858;
        case 0x1d0860u: goto label_1d0860;
        case 0x1d089cu: goto label_1d089c;
        case 0x1d08e4u: goto label_1d08e4;
        case 0x1d08f8u: goto label_1d08f8;
        case 0x1d0998u: goto label_1d0998;
        case 0x1d09c8u: goto label_1d09c8;
        case 0x1d09d8u: goto label_1d09d8;
        case 0x1d09fcu: goto label_1d09fc;
        case 0x1d0a3cu: goto label_1d0a3c;
        case 0x1d0a4cu: goto label_1d0a4c;
        case 0x1d0abcu: goto label_1d0abc;
        case 0x1d0ad8u: goto label_1d0ad8;
        case 0x1d0aecu: goto label_1d0aec;
        case 0x1d0b20u: goto label_1d0b20;
        case 0x1d0b34u: goto label_1d0b34;
        case 0x1d0b8cu: goto label_1d0b8c;
        case 0x1d0b98u: goto label_1d0b98;
        case 0x1d0ba4u: goto label_1d0ba4;
        case 0x1d0bb0u: goto label_1d0bb0;
        case 0x1d0bbcu: goto label_1d0bbc;
        case 0x1d0bc8u: goto label_1d0bc8;
        case 0x1d0bd4u: goto label_1d0bd4;
        case 0x1d0be0u: goto label_1d0be0;
        case 0x1d0becu: goto label_1d0bec;
        case 0x1d0c00u: goto label_1d0c00;
        case 0x1d0c38u: goto label_1d0c38;
        case 0x1d0c50u: goto label_1d0c50;
        case 0x1d0c68u: goto label_1d0c68;
        case 0x1d0cc4u: goto label_1d0cc4;
        case 0x1d0cd0u: goto label_1d0cd0;
        case 0x1d0cdcu: goto label_1d0cdc;
        case 0x1d0ce8u: goto label_1d0ce8;
        case 0x1d0cf4u: goto label_1d0cf4;
        case 0x1d0d00u: goto label_1d0d00;
        case 0x1d0d0cu: goto label_1d0d0c;
        case 0x1d0d18u: goto label_1d0d18;
        case 0x1d0d38u: goto label_1d0d38;
        case 0x1d0d6cu: goto label_1d0d6c;
        case 0x1d0db4u: goto label_1d0db4;
        case 0x1d0df8u: goto label_1d0df8;
        case 0x1d0e0cu: goto label_1d0e0c;
        case 0x1d0e38u: goto label_1d0e38;
        case 0x1d0e44u: goto label_1d0e44;
        case 0x1d0e70u: goto label_1d0e70;
        case 0x1d0ea8u: goto label_1d0ea8;
        case 0x1d0efcu: goto label_1d0efc;
        case 0x1d0f04u: goto label_1d0f04;
        case 0x1d0f0cu: goto label_1d0f0c;
        case 0x1d0f38u: goto label_1d0f38;
        case 0x1d0f5cu: goto label_1d0f5c;
        case 0x1d0f78u: goto label_1d0f78;
        case 0x1d0f94u: goto label_1d0f94;
        case 0x1d0f9cu: goto label_1d0f9c;
        case 0x1d0fc4u: goto label_1d0fc4;
        case 0x1d0fe4u: goto label_1d0fe4;
        case 0x1d1004u: goto label_1d1004;
        case 0x1d1048u: goto label_1d1048;
        case 0x1d1054u: goto label_1d1054;
        case 0x1d1060u: goto label_1d1060;
        case 0x1d106cu: goto label_1d106c;
        case 0x1d1078u: goto label_1d1078;
        case 0x1d1084u: goto label_1d1084;
        case 0x1d1090u: goto label_1d1090;
        case 0x1d109cu: goto label_1d109c;
        case 0x1d10a8u: goto label_1d10a8;
        case 0x1d10b4u: goto label_1d10b4;
        case 0x1d10c8u: goto label_1d10c8;
        case 0x1d1100u: goto label_1d1100;
        case 0x1d1114u: goto label_1d1114;
        case 0x1d112cu: goto label_1d112c;
        case 0x1d1144u: goto label_1d1144;
        case 0x1d1190u: goto label_1d1190;
        case 0x1d11a8u: goto label_1d11a8;
        case 0x1d11d0u: goto label_1d11d0;
        case 0x1d11e8u: goto label_1d11e8;
        case 0x1d1200u: goto label_1d1200;
        case 0x1d123cu: goto label_1d123c;
        case 0x1d1248u: goto label_1d1248;
        case 0x1d1254u: goto label_1d1254;
        case 0x1d1260u: goto label_1d1260;
        case 0x1d126cu: goto label_1d126c;
        case 0x1d1278u: goto label_1d1278;
        case 0x1d1284u: goto label_1d1284;
        case 0x1d1290u: goto label_1d1290;
        case 0x1d129cu: goto label_1d129c;
        case 0x1d12a8u: goto label_1d12a8;
        case 0x1d12b8u: goto label_1d12b8;
        case 0x1d12d4u: goto label_1d12d4;
        case 0x1d12e8u: goto label_1d12e8;
        case 0x1d1308u: goto label_1d1308;
        case 0x1d1368u: goto label_1d1368;
        case 0x1d1388u: goto label_1d1388;
        case 0x1d139cu: goto label_1d139c;
        case 0x1d13b4u: goto label_1d13b4;
        case 0x1d141cu: goto label_1d141c;
        case 0x1d1428u: goto label_1d1428;
        case 0x1d1434u: goto label_1d1434;
        case 0x1d1440u: goto label_1d1440;
        case 0x1d144cu: goto label_1d144c;
        case 0x1d1458u: goto label_1d1458;
        case 0x1d1464u: goto label_1d1464;
        case 0x1d1470u: goto label_1d1470;
        case 0x1d147cu: goto label_1d147c;
        case 0x1d148cu: goto label_1d148c;
        case 0x1d14c4u: goto label_1d14c4;
        case 0x1d14dcu: goto label_1d14dc;
        case 0x1d1570u: goto label_1d1570;
        case 0x1d15acu: goto label_1d15ac;
        case 0x1d1604u: goto label_1d1604;
        case 0x1d160cu: goto label_1d160c;
        case 0x1d163cu: goto label_1d163c;
        default: break;
    }

    ctx->pc = 0x1d06e0u;

label_1d06e0:
    // 0x1d06e0: 0x308700ff  andi        $a3, $a0, 0xFF
    ctx->pc = 0x1d06e0u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x1d06e4: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1d06e4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1d06e8: 0x71980  sll         $v1, $a3, 6
    ctx->pc = 0x1d06e8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 7), 6));
    // 0x1d06ec: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1d06ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1d06f0: 0x30a400ff  andi        $a0, $a1, 0xFF
    ctx->pc = 0x1d06f0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x1d06f4: 0x673021  addu        $a2, $v1, $a3
    ctx->pc = 0x1d06f4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 7)));
    // 0x1d06f8: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1d06f8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1d06fc: 0x41880  sll         $v1, $a0, 2
    ctx->pc = 0x1d06fcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1d0700: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d0700u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d0704: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1d0704u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1d0708: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d0708u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d070c: 0x620c0  sll         $a0, $a2, 3
    ctx->pc = 0x1d070cu;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 6), 3));
    // 0x1d0710: 0x873021  addu        $a2, $a0, $a3
    ctx->pc = 0x1d0710u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 7)));
    // 0x1d0714: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x1d0714u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d0718: 0x3c05003f  lui         $a1, 0x3F
    ctx->pc = 0x1d0718u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)63 << 16));
    // 0x1d071c: 0x32080  sll         $a0, $v1, 2
    ctx->pc = 0x1d071cu;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1d0720: 0x3c030038  lui         $v1, 0x38
    ctx->pc = 0x1d0720u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)56 << 16));
    // 0x1d0724: 0x24a582f0  addiu       $a1, $a1, -0x7D10
    ctx->pc = 0x1d0724u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294935280));
    // 0x1d0728: 0x63080  sll         $a2, $a2, 2
    ctx->pc = 0x1d0728u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 2));
    // 0x1d072c: 0x246363d0  addiu       $v1, $v1, 0x63D0
    ctx->pc = 0x1d072cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 25552));
    // 0x1d0730: 0xa68821  addu        $s1, $a1, $a2
    ctx->pc = 0x1d0730u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 6)));
    // 0x1d0734: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1d0734u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1d0738: 0xa2200000  sb          $zero, 0x0($s1)
    ctx->pc = 0x1d0738u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1d073c: 0x8c63000c  lw          $v1, 0xC($v1)
    ctx->pc = 0x1d073cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 12)));
    // 0x1d0740: 0x10600026  beqz        $v1, . + 4 + (0x26 << 2)
    ctx->pc = 0x1D0740u;
    {
        const bool branch_taken_0x1d0740 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d0740) {
            ctx->pc = 0x1D07DCu;
            goto label_1d07dc;
        }
    }
    ctx->pc = 0x1D0748u;
    // 0x1d0748: 0x24040015  addiu       $a0, $zero, 0x15
    ctx->pc = 0x1d0748u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 21));
    // 0x1d074c: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D074Cu;
    SET_GPR_U32(ctx, 31, 0x1D0754u);
    ctx->pc = 0x1D0750u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D074Cu;
            // 0x1d0750: 0x24050002  addiu       $a1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0754u; }
        if (ctx->pc != 0x1D0754u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0754u; }
        if (ctx->pc != 0x1D0754u) { return; }
    }
    ctx->pc = 0x1D0754u;
label_1d0754:
    // 0x1d0754: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1d0754u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d0758: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D0758u;
    SET_GPR_U32(ctx, 31, 0x1D0760u);
    ctx->pc = 0x1D075Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0758u;
            // 0x1d075c: 0x24050800  addiu       $a1, $zero, 0x800 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2048));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0760u; }
        if (ctx->pc != 0x1D0760u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0760u; }
        if (ctx->pc != 0x1D0760u) { return; }
    }
    ctx->pc = 0x1D0760u;
label_1d0760:
    // 0x1d0760: 0x24040012  addiu       $a0, $zero, 0x12
    ctx->pc = 0x1d0760u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 18));
    // 0x1d0764: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D0764u;
    SET_GPR_U32(ctx, 31, 0x1D076Cu);
    ctx->pc = 0x1D0768u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0764u;
            // 0x1d0768: 0x34058000  ori         $a1, $zero, 0x8000 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D076Cu; }
        if (ctx->pc != 0x1D076Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D076Cu; }
        if (ctx->pc != 0x1D076Cu) { return; }
    }
    ctx->pc = 0x1D076Cu;
label_1d076c:
    // 0x1d076c: 0x24040062  addiu       $a0, $zero, 0x62
    ctx->pc = 0x1d076cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 98));
    // 0x1d0770: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D0770u;
    SET_GPR_U32(ctx, 31, 0x1D0778u);
    ctx->pc = 0x1D0774u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0770u;
            // 0x1d0774: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0778u; }
        if (ctx->pc != 0x1D0778u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0778u; }
        if (ctx->pc != 0x1D0778u) { return; }
    }
    ctx->pc = 0x1D0778u;
label_1d0778:
    // 0x1d0778: 0x2404000c  addiu       $a0, $zero, 0xC
    ctx->pc = 0x1d0778u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
    // 0x1d077c: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D077Cu;
    SET_GPR_U32(ctx, 31, 0x1D0784u);
    ctx->pc = 0x1D0780u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D077Cu;
            // 0x1d0780: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0784u; }
        if (ctx->pc != 0x1D0784u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0784u; }
        if (ctx->pc != 0x1D0784u) { return; }
    }
    ctx->pc = 0x1D0784u;
label_1d0784:
    // 0x1d0784: 0x24040066  addiu       $a0, $zero, 0x66
    ctx->pc = 0x1d0784u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1d0788: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D0788u;
    SET_GPR_U32(ctx, 31, 0x1D0790u);
    ctx->pc = 0x1D078Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0788u;
            // 0x1d078c: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0790u; }
        if (ctx->pc != 0x1D0790u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0790u; }
        if (ctx->pc != 0x1D0790u) { return; }
    }
    ctx->pc = 0x1D0790u;
label_1d0790:
    // 0x1d0790: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1d0790u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1d0794: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D0794u;
    SET_GPR_U32(ctx, 31, 0x1D079Cu);
    ctx->pc = 0x1D0798u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0794u;
            // 0x1d0798: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D079Cu; }
        if (ctx->pc != 0x1D079Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D079Cu; }
        if (ctx->pc != 0x1D079Cu) { return; }
    }
    ctx->pc = 0x1D079Cu;
label_1d079c:
    // 0x1d079c: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1d079cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d07a0: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D07A0u;
    SET_GPR_U32(ctx, 31, 0x1D07A8u);
    ctx->pc = 0x1D07A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D07A0u;
            // 0x1d07a4: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D07A8u; }
        if (ctx->pc != 0x1D07A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D07A8u; }
        if (ctx->pc != 0x1D07A8u) { return; }
    }
    ctx->pc = 0x1D07A8u;
label_1d07a8:
    // 0x1d07a8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1d07a8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d07ac: 0x24040020  addiu       $a0, $zero, 0x20
    ctx->pc = 0x1d07acu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x1d07b0: 0xa2220000  sb          $v0, 0x0($s1)
    ctx->pc = 0x1d07b0u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1d07b4: 0x24050003  addiu       $a1, $zero, 0x3
    ctx->pc = 0x1d07b4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1d07b8: 0xc06ca9c  jal         func_1B2A70
    ctx->pc = 0x1D07B8u;
    SET_GPR_U32(ctx, 31, 0x1D07C0u);
    ctx->pc = 0x1D07BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D07B8u;
            // 0x1d07bc: 0x26320004  addiu       $s2, $s1, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 17), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B2A70u;
    if (runtime->hasFunction(0x1B2A70u)) {
        auto targetFn = runtime->lookupFunction(0x1B2A70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D07C0u; }
        if (ctx->pc != 0x1D07C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B2A70_0x1b2a70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D07C0u; }
        if (ctx->pc != 0x1D07C0u) { return; }
    }
    ctx->pc = 0x1D07C0u;
label_1d07c0:
    // 0x1d07c0: 0xae420808  sw          $v0, 0x808($s2)
    ctx->pc = 0x1d07c0u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 2056), GPR_U32(ctx, 2));
    // 0x1d07c4: 0x320400ff  andi        $a0, $s0, 0xFF
    ctx->pc = 0x1d07c4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)255);
    // 0x1d07c8: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x1d07c8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d07cc: 0x2405ffff  addiu       $a1, $zero, -0x1
    ctx->pc = 0x1d07ccu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d07d0: 0x24070003  addiu       $a3, $zero, 0x3
    ctx->pc = 0x1d07d0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1d07d4: 0xc0738a8  jal         func_1CE2A0
    ctx->pc = 0x1D07D4u;
    SET_GPR_U32(ctx, 31, 0x1D07DCu);
    ctx->pc = 0x1D07D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D07D4u;
            // 0x1d07d8: 0xae400818  sw          $zero, 0x818($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 2072), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CE2A0u;
    if (runtime->hasFunction(0x1CE2A0u)) {
        auto targetFn = runtime->lookupFunction(0x1CE2A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D07DCu; }
        if (ctx->pc != 0x1D07DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CE2A0_0x1ce2a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D07DCu; }
        if (ctx->pc != 0x1D07DCu) { return; }
    }
    ctx->pc = 0x1D07DCu;
label_1d07dc:
    // 0x1d07dc: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1d07dcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1d07e0: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1d07e0u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d07e4: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d07e4u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d07e8: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d07e8u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d07ec: 0x3e00008  jr          $ra
    ctx->pc = 0x1D07ECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D07F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D07ECu;
            // 0x1d07f0: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D06E0u: goto label_1d06e0;
            case 0x1D0754u: goto label_1d0754;
            case 0x1D0760u: goto label_1d0760;
            case 0x1D076Cu: goto label_1d076c;
            case 0x1D0778u: goto label_1d0778;
            case 0x1D0784u: goto label_1d0784;
            case 0x1D0790u: goto label_1d0790;
            case 0x1D079Cu: goto label_1d079c;
            case 0x1D07A8u: goto label_1d07a8;
            case 0x1D07C0u: goto label_1d07c0;
            case 0x1D07DCu: goto label_1d07dc;
            case 0x1D0840u: goto label_1d0840;
            case 0x1D0848u: goto label_1d0848;
            case 0x1D0858u: goto label_1d0858;
            case 0x1D0860u: goto label_1d0860;
            case 0x1D0870u: goto label_1d0870;
            case 0x1D089Cu: goto label_1d089c;
            case 0x1D08C8u: goto label_1d08c8;
            case 0x1D08E4u: goto label_1d08e4;
            case 0x1D08F8u: goto label_1d08f8;
            case 0x1D0960u: goto label_1d0960;
            case 0x1D0964u: goto label_1d0964;
            case 0x1D0998u: goto label_1d0998;
            case 0x1D09A4u: goto label_1d09a4;
            case 0x1D09C8u: goto label_1d09c8;
            case 0x1D09D0u: goto label_1d09d0;
            case 0x1D09D8u: goto label_1d09d8;
            case 0x1D09FCu: goto label_1d09fc;
            case 0x1D0A3Cu: goto label_1d0a3c;
            case 0x1D0A4Cu: goto label_1d0a4c;
            case 0x1D0A50u: goto label_1d0a50;
            case 0x1D0ABCu: goto label_1d0abc;
            case 0x1D0AC4u: goto label_1d0ac4;
            case 0x1D0AD8u: goto label_1d0ad8;
            case 0x1D0AECu: goto label_1d0aec;
            case 0x1D0B20u: goto label_1d0b20;
            case 0x1D0B34u: goto label_1d0b34;
            case 0x1D0B40u: goto label_1d0b40;
            case 0x1D0B54u: goto label_1d0b54;
            case 0x1D0B8Cu: goto label_1d0b8c;
            case 0x1D0B98u: goto label_1d0b98;
            case 0x1D0BA4u: goto label_1d0ba4;
            case 0x1D0BB0u: goto label_1d0bb0;
            case 0x1D0BBCu: goto label_1d0bbc;
            case 0x1D0BC8u: goto label_1d0bc8;
            case 0x1D0BD4u: goto label_1d0bd4;
            case 0x1D0BE0u: goto label_1d0be0;
            case 0x1D0BECu: goto label_1d0bec;
            case 0x1D0C00u: goto label_1d0c00;
            case 0x1D0C38u: goto label_1d0c38;
            case 0x1D0C40u: goto label_1d0c40;
            case 0x1D0C50u: goto label_1d0c50;
            case 0x1D0C68u: goto label_1d0c68;
            case 0x1D0C6Cu: goto label_1d0c6c;
            case 0x1D0CC4u: goto label_1d0cc4;
            case 0x1D0CD0u: goto label_1d0cd0;
            case 0x1D0CDCu: goto label_1d0cdc;
            case 0x1D0CE8u: goto label_1d0ce8;
            case 0x1D0CF4u: goto label_1d0cf4;
            case 0x1D0D00u: goto label_1d0d00;
            case 0x1D0D0Cu: goto label_1d0d0c;
            case 0x1D0D18u: goto label_1d0d18;
            case 0x1D0D38u: goto label_1d0d38;
            case 0x1D0D6Cu: goto label_1d0d6c;
            case 0x1D0DB4u: goto label_1d0db4;
            case 0x1D0DF8u: goto label_1d0df8;
            case 0x1D0E0Cu: goto label_1d0e0c;
            case 0x1D0E14u: goto label_1d0e14;
            case 0x1D0E38u: goto label_1d0e38;
            case 0x1D0E44u: goto label_1d0e44;
            case 0x1D0E48u: goto label_1d0e48;
            case 0x1D0E70u: goto label_1d0e70;
            case 0x1D0EA8u: goto label_1d0ea8;
            case 0x1D0EFCu: goto label_1d0efc;
            case 0x1D0F04u: goto label_1d0f04;
            case 0x1D0F0Cu: goto label_1d0f0c;
            case 0x1D0F38u: goto label_1d0f38;
            case 0x1D0F40u: goto label_1d0f40;
            case 0x1D0F5Cu: goto label_1d0f5c;
            case 0x1D0F78u: goto label_1d0f78;
            case 0x1D0F94u: goto label_1d0f94;
            case 0x1D0F9Cu: goto label_1d0f9c;
            case 0x1D0FBCu: goto label_1d0fbc;
            case 0x1D0FC4u: goto label_1d0fc4;
            case 0x1D0FE4u: goto label_1d0fe4;
            case 0x1D1004u: goto label_1d1004;
            case 0x1D100Cu: goto label_1d100c;
            case 0x1D1048u: goto label_1d1048;
            case 0x1D1054u: goto label_1d1054;
            case 0x1D1060u: goto label_1d1060;
            case 0x1D106Cu: goto label_1d106c;
            case 0x1D1078u: goto label_1d1078;
            case 0x1D1084u: goto label_1d1084;
            case 0x1D1090u: goto label_1d1090;
            case 0x1D109Cu: goto label_1d109c;
            case 0x1D10A8u: goto label_1d10a8;
            case 0x1D10B4u: goto label_1d10b4;
            case 0x1D10C8u: goto label_1d10c8;
            case 0x1D1100u: goto label_1d1100;
            case 0x1D1108u: goto label_1d1108;
            case 0x1D1114u: goto label_1d1114;
            case 0x1D112Cu: goto label_1d112c;
            case 0x1D1144u: goto label_1d1144;
            case 0x1D1190u: goto label_1d1190;
            case 0x1D11A8u: goto label_1d11a8;
            case 0x1D11D0u: goto label_1d11d0;
            case 0x1D11D4u: goto label_1d11d4;
            case 0x1D11E8u: goto label_1d11e8;
            case 0x1D1200u: goto label_1d1200;
            case 0x1D120Cu: goto label_1d120c;
            case 0x1D123Cu: goto label_1d123c;
            case 0x1D1248u: goto label_1d1248;
            case 0x1D1254u: goto label_1d1254;
            case 0x1D1260u: goto label_1d1260;
            case 0x1D126Cu: goto label_1d126c;
            case 0x1D1278u: goto label_1d1278;
            case 0x1D1284u: goto label_1d1284;
            case 0x1D1290u: goto label_1d1290;
            case 0x1D129Cu: goto label_1d129c;
            case 0x1D12A8u: goto label_1d12a8;
            case 0x1D12B8u: goto label_1d12b8;
            case 0x1D12D4u: goto label_1d12d4;
            case 0x1D12E8u: goto label_1d12e8;
            case 0x1D1308u: goto label_1d1308;
            case 0x1D1368u: goto label_1d1368;
            case 0x1D1370u: goto label_1d1370;
            case 0x1D1388u: goto label_1d1388;
            case 0x1D139Cu: goto label_1d139c;
            case 0x1D13A0u: goto label_1d13a0;
            case 0x1D13B4u: goto label_1d13b4;
            case 0x1D141Cu: goto label_1d141c;
            case 0x1D1428u: goto label_1d1428;
            case 0x1D1434u: goto label_1d1434;
            case 0x1D1440u: goto label_1d1440;
            case 0x1D144Cu: goto label_1d144c;
            case 0x1D1458u: goto label_1d1458;
            case 0x1D1464u: goto label_1d1464;
            case 0x1D1470u: goto label_1d1470;
            case 0x1D147Cu: goto label_1d147c;
            case 0x1D148Cu: goto label_1d148c;
            case 0x1D14C4u: goto label_1d14c4;
            case 0x1D14CCu: goto label_1d14cc;
            case 0x1D14DCu: goto label_1d14dc;
            case 0x1D14E0u: goto label_1d14e0;
            case 0x1D1570u: goto label_1d1570;
            case 0x1D15ACu: goto label_1d15ac;
            case 0x1D15F4u: goto label_1d15f4;
            case 0x1D1604u: goto label_1d1604;
            case 0x1D160Cu: goto label_1d160c;
            case 0x1D163Cu: goto label_1d163c;
            case 0x1D1654u: goto label_1d1654;
            case 0x1D165Cu: goto label_1d165c;
            case 0x1D1670u: goto label_1d1670;
            case 0x1D1678u: goto label_1d1678;
            case 0x1D1688u: goto label_1d1688;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D07F4u;
    // 0x1d07f4: 0x0  nop
    ctx->pc = 0x1d07f4u;
    // NOP
    // 0x1d07f8: 0x0  nop
    ctx->pc = 0x1d07f8u;
    // NOP
    // 0x1d07fc: 0x0  nop
    ctx->pc = 0x1d07fcu;
    // NOP
    // 0x1d0800: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1d0800u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1d0804: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1d0804u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d0808: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x1d0808u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x1d080c: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1d080cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1d0810: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1d0810u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1d0814: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x1d0814u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d0818: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d0818u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d081c: 0xe0902d  daddu       $s2, $a3, $zero
    ctx->pc = 0x1d081cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d0820: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d0820u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d0824: 0x30d000ff  andi        $s0, $a2, 0xFF
    ctx->pc = 0x1d0824u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)255);
    // 0x1d0828: 0x16020007  bne         $s0, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1D0828u;
    {
        const bool branch_taken_0x1d0828 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 2));
        ctx->pc = 0x1D082Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0828u;
            // 0x1d082c: 0x80882d  daddu       $s1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d0828) {
            ctx->pc = 0x1D0848u;
            goto label_1d0848;
        }
    }
    ctx->pc = 0x1D0830u;
    // 0x1d0830: 0x322200ff  andi        $v0, $s1, 0xFF
    ctx->pc = 0x1d0830u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)255);
    // 0x1d0834: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x1d0834u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x1d0838: 0xc073470  jal         func_1CD1C0
    ctx->pc = 0x1D0838u;
    SET_GPR_U32(ctx, 31, 0x1D0840u);
    ctx->pc = 0x1D083Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0838u;
            // 0x1d083c: 0x24441600  addiu       $a0, $v0, 0x1600 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 5632));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CD1C0u;
    if (runtime->hasFunction(0x1CD1C0u)) {
        auto targetFn = runtime->lookupFunction(0x1CD1C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0840u; }
        if (ctx->pc != 0x1D0840u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CD1C0_0x1cd1c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0840u; }
        if (ctx->pc != 0x1D0840u) { return; }
    }
    ctx->pc = 0x1D0840u;
label_1d0840:
    // 0x1d0840: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1D0840u;
    {
        const bool branch_taken_0x1d0840 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d0840) {
            ctx->pc = 0x1D0858u;
            goto label_1d0858;
        }
    }
    ctx->pc = 0x1D0848u;
label_1d0848:
    // 0x1d0848: 0x322200ff  andi        $v0, $s1, 0xFF
    ctx->pc = 0x1d0848u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)255);
    // 0x1d084c: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x1d084cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x1d0850: 0xc073470  jal         func_1CD1C0
    ctx->pc = 0x1D0850u;
    SET_GPR_U32(ctx, 31, 0x1D0858u);
    ctx->pc = 0x1D0854u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0850u;
            // 0x1d0854: 0x24441400  addiu       $a0, $v0, 0x1400 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 5120));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CD1C0u;
    if (runtime->hasFunction(0x1CD1C0u)) {
        auto targetFn = runtime->lookupFunction(0x1CD1C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0858u; }
        if (ctx->pc != 0x1D0858u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CD1C0_0x1cd1c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0858u; }
        if (ctx->pc != 0x1D0858u) { return; }
    }
    ctx->pc = 0x1D0858u;
label_1d0858:
    // 0x1d0858: 0xc0740e8  jal         func_1D03A0
    ctx->pc = 0x1D0858u;
    SET_GPR_U32(ctx, 31, 0x1D0860u);
    ctx->pc = 0x1D03A0u;
    if (runtime->hasFunction(0x1D03A0u)) {
        auto targetFn = runtime->lookupFunction(0x1D03A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0860u; }
        if (ctx->pc != 0x1D0860u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D03A0_0x1d03a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0860u; }
        if (ctx->pc != 0x1D0860u) { return; }
    }
    ctx->pc = 0x1D0860u;
label_1d0860:
    // 0x1d0860: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1d0860u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d0864: 0x16020002  bne         $s0, $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1D0864u;
    {
        const bool branch_taken_0x1d0864 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 2));
        ctx->pc = 0x1D0868u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0864u;
            // 0x1d0868: 0x24050002  addiu       $a1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d0864) {
            ctx->pc = 0x1D0870u;
            goto label_1d0870;
        }
    }
    ctx->pc = 0x1D086Cu;
    // 0x1d086c: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x1d086cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
label_1d0870:
    // 0x1d0870: 0x326200ff  andi        $v0, $s3, 0xFF
    ctx->pc = 0x1d0870u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 19) & (uint64_t)(uint16_t)255);
    // 0x1d0874: 0x322400ff  andi        $a0, $s1, 0xFF
    ctx->pc = 0x1d0874u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)255);
    // 0x1d0878: 0x24031468  addiu       $v1, $zero, 0x1468
    ctx->pc = 0x1d0878u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 5224));
    // 0x1d087c: 0x21400  sll         $v0, $v0, 16
    ctx->pc = 0x1d087cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
    // 0x1d0880: 0x831818  mult        $v1, $a0, $v1
    ctx->pc = 0x1d0880u;
    { int64_t result = (int64_t)GPR_S32(ctx, 4) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x1d0884: 0xa22825  or          $a1, $a1, $v0
    ctx->pc = 0x1d0884u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 2));
    // 0x1d0888: 0x3c020042  lui         $v0, 0x42
    ctx->pc = 0x1d0888u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)66 << 16));
    // 0x1d088c: 0x24421ef0  addiu       $v0, $v0, 0x1EF0
    ctx->pc = 0x1d088cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 7920));
    // 0x1d0890: 0x24040020  addiu       $a0, $zero, 0x20
    ctx->pc = 0x1d0890u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x1d0894: 0xc06ca9c  jal         func_1B2A70
    ctx->pc = 0x1D0894u;
    SET_GPR_U32(ctx, 31, 0x1D089Cu);
    ctx->pc = 0x1D0898u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0894u;
            // 0x1d0898: 0x438821  addu        $s1, $v0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B2A70u;
    if (runtime->hasFunction(0x1B2A70u)) {
        auto targetFn = runtime->lookupFunction(0x1B2A70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D089Cu; }
        if (ctx->pc != 0x1D089Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B2A70_0x1b2a70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D089Cu; }
        if (ctx->pc != 0x1D089Cu) { return; }
    }
    ctx->pc = 0x1D089Cu;
label_1d089c:
    // 0x1d089c: 0xae220808  sw          $v0, 0x808($s1)
    ctx->pc = 0x1d089cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 2056), GPR_U32(ctx, 2));
    // 0x1d08a0: 0x26220820  addiu       $v0, $s1, 0x820
    ctx->pc = 0x1d08a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), 2080));
    // 0x1d08a4: 0xae220000  sw          $v0, 0x0($s1)
    ctx->pc = 0x1d08a4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
    // 0x1d08a8: 0x26220a20  addiu       $v0, $s1, 0xA20
    ctx->pc = 0x1d08a8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), 2592));
    // 0x1d08ac: 0xae220004  sw          $v0, 0x4($s1)
    ctx->pc = 0x1d08acu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 2));
    // 0x1d08b0: 0x26220c20  addiu       $v0, $s1, 0xC20
    ctx->pc = 0x1d08b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), 3104));
    // 0x1d08b4: 0xae220818  sw          $v0, 0x818($s1)
    ctx->pc = 0x1d08b4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 2072), GPR_U32(ctx, 2));
    // 0x1d08b8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1d08b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d08bc: 0x12020002  beq         $s0, $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1D08BCu;
    {
        const bool branch_taken_0x1d08bc = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        ctx->pc = 0x1D08C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D08BCu;
            // 0x1d08c0: 0x326500ff  andi        $a1, $s3, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 19) & (uint64_t)(uint16_t)255);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d08bc) {
            ctx->pc = 0x1D08C8u;
            goto label_1d08c8;
        }
    }
    ctx->pc = 0x1D08C4u;
    // 0x1d08c4: 0x641200ff  daddiu      $s2, $zero, 0xFF
    ctx->pc = 0x1d08c4u;
    SET_GPR_S64(ctx, 18, (int64_t)GPR_S64(ctx, 0) + (int64_t)(int32_t)255);
label_1d08c8:
    // 0x1d08c8: 0x124e3c  dsll32      $t1, $s2, 24
    ctx->pc = 0x1d08c8u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 18) << (32 + 24));
    // 0x1d08cc: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1d08ccu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d08d0: 0x94e3f  dsra32      $t1, $t1, 24
    ctx->pc = 0x1d08d0u;
    SET_GPR_S64(ctx, 9, GPR_S64(ctx, 9) >> (32 + 24));
    // 0x1d08d4: 0xa0302d  daddu       $a2, $a1, $zero
    ctx->pc = 0x1d08d4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d08d8: 0x24070003  addiu       $a3, $zero, 0x3
    ctx->pc = 0x1d08d8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1d08dc: 0xc073cc0  jal         func_1CF300
    ctx->pc = 0x1D08DCu;
    SET_GPR_U32(ctx, 31, 0x1D08E4u);
    ctx->pc = 0x1D08E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D08DCu;
            // 0x1d08e0: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CF300u;
    if (runtime->hasFunction(0x1CF300u)) {
        auto targetFn = runtime->lookupFunction(0x1CF300u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D08E4u; }
        if (ctx->pc != 0x1D08E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CF300_0x1cf300(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D08E4u; }
        if (ctx->pc != 0x1D08E4u) { return; }
    }
    ctx->pc = 0x1D08E4u;
label_1d08e4:
    // 0x1d08e4: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1d08e4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d08e8: 0x16030003  bne         $s0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D08E8u;
    {
        const bool branch_taken_0x1d08e8 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 3));
        ctx->pc = 0x1D08ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D08E8u;
            // 0x1d08ec: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d08e8) {
            ctx->pc = 0x1D08F8u;
            goto label_1d08f8;
        }
    }
    ctx->pc = 0x1D08F0u;
    // 0x1d08f0: 0xc0741b8  jal         func_1D06E0
    ctx->pc = 0x1D08F0u;
    SET_GPR_U32(ctx, 31, 0x1D08F8u);
    ctx->pc = 0x1D08F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D08F0u;
            // 0x1d08f4: 0x260282d  daddu       $a1, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D06E0u;
    goto label_1d06e0;
    ctx->pc = 0x1D08F8u;
label_1d08f8:
    // 0x1d08f8: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x1d08f8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1d08fc: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1d08fcu;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1d0900: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1d0900u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d0904: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d0904u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d0908: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d0908u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d090c: 0x3e00008  jr          $ra
    ctx->pc = 0x1D090Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D0910u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D090Cu;
            // 0x1d0910: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D06E0u: goto label_1d06e0;
            case 0x1D0754u: goto label_1d0754;
            case 0x1D0760u: goto label_1d0760;
            case 0x1D076Cu: goto label_1d076c;
            case 0x1D0778u: goto label_1d0778;
            case 0x1D0784u: goto label_1d0784;
            case 0x1D0790u: goto label_1d0790;
            case 0x1D079Cu: goto label_1d079c;
            case 0x1D07A8u: goto label_1d07a8;
            case 0x1D07C0u: goto label_1d07c0;
            case 0x1D07DCu: goto label_1d07dc;
            case 0x1D0840u: goto label_1d0840;
            case 0x1D0848u: goto label_1d0848;
            case 0x1D0858u: goto label_1d0858;
            case 0x1D0860u: goto label_1d0860;
            case 0x1D0870u: goto label_1d0870;
            case 0x1D089Cu: goto label_1d089c;
            case 0x1D08C8u: goto label_1d08c8;
            case 0x1D08E4u: goto label_1d08e4;
            case 0x1D08F8u: goto label_1d08f8;
            case 0x1D0960u: goto label_1d0960;
            case 0x1D0964u: goto label_1d0964;
            case 0x1D0998u: goto label_1d0998;
            case 0x1D09A4u: goto label_1d09a4;
            case 0x1D09C8u: goto label_1d09c8;
            case 0x1D09D0u: goto label_1d09d0;
            case 0x1D09D8u: goto label_1d09d8;
            case 0x1D09FCu: goto label_1d09fc;
            case 0x1D0A3Cu: goto label_1d0a3c;
            case 0x1D0A4Cu: goto label_1d0a4c;
            case 0x1D0A50u: goto label_1d0a50;
            case 0x1D0ABCu: goto label_1d0abc;
            case 0x1D0AC4u: goto label_1d0ac4;
            case 0x1D0AD8u: goto label_1d0ad8;
            case 0x1D0AECu: goto label_1d0aec;
            case 0x1D0B20u: goto label_1d0b20;
            case 0x1D0B34u: goto label_1d0b34;
            case 0x1D0B40u: goto label_1d0b40;
            case 0x1D0B54u: goto label_1d0b54;
            case 0x1D0B8Cu: goto label_1d0b8c;
            case 0x1D0B98u: goto label_1d0b98;
            case 0x1D0BA4u: goto label_1d0ba4;
            case 0x1D0BB0u: goto label_1d0bb0;
            case 0x1D0BBCu: goto label_1d0bbc;
            case 0x1D0BC8u: goto label_1d0bc8;
            case 0x1D0BD4u: goto label_1d0bd4;
            case 0x1D0BE0u: goto label_1d0be0;
            case 0x1D0BECu: goto label_1d0bec;
            case 0x1D0C00u: goto label_1d0c00;
            case 0x1D0C38u: goto label_1d0c38;
            case 0x1D0C40u: goto label_1d0c40;
            case 0x1D0C50u: goto label_1d0c50;
            case 0x1D0C68u: goto label_1d0c68;
            case 0x1D0C6Cu: goto label_1d0c6c;
            case 0x1D0CC4u: goto label_1d0cc4;
            case 0x1D0CD0u: goto label_1d0cd0;
            case 0x1D0CDCu: goto label_1d0cdc;
            case 0x1D0CE8u: goto label_1d0ce8;
            case 0x1D0CF4u: goto label_1d0cf4;
            case 0x1D0D00u: goto label_1d0d00;
            case 0x1D0D0Cu: goto label_1d0d0c;
            case 0x1D0D18u: goto label_1d0d18;
            case 0x1D0D38u: goto label_1d0d38;
            case 0x1D0D6Cu: goto label_1d0d6c;
            case 0x1D0DB4u: goto label_1d0db4;
            case 0x1D0DF8u: goto label_1d0df8;
            case 0x1D0E0Cu: goto label_1d0e0c;
            case 0x1D0E14u: goto label_1d0e14;
            case 0x1D0E38u: goto label_1d0e38;
            case 0x1D0E44u: goto label_1d0e44;
            case 0x1D0E48u: goto label_1d0e48;
            case 0x1D0E70u: goto label_1d0e70;
            case 0x1D0EA8u: goto label_1d0ea8;
            case 0x1D0EFCu: goto label_1d0efc;
            case 0x1D0F04u: goto label_1d0f04;
            case 0x1D0F0Cu: goto label_1d0f0c;
            case 0x1D0F38u: goto label_1d0f38;
            case 0x1D0F40u: goto label_1d0f40;
            case 0x1D0F5Cu: goto label_1d0f5c;
            case 0x1D0F78u: goto label_1d0f78;
            case 0x1D0F94u: goto label_1d0f94;
            case 0x1D0F9Cu: goto label_1d0f9c;
            case 0x1D0FBCu: goto label_1d0fbc;
            case 0x1D0FC4u: goto label_1d0fc4;
            case 0x1D0FE4u: goto label_1d0fe4;
            case 0x1D1004u: goto label_1d1004;
            case 0x1D100Cu: goto label_1d100c;
            case 0x1D1048u: goto label_1d1048;
            case 0x1D1054u: goto label_1d1054;
            case 0x1D1060u: goto label_1d1060;
            case 0x1D106Cu: goto label_1d106c;
            case 0x1D1078u: goto label_1d1078;
            case 0x1D1084u: goto label_1d1084;
            case 0x1D1090u: goto label_1d1090;
            case 0x1D109Cu: goto label_1d109c;
            case 0x1D10A8u: goto label_1d10a8;
            case 0x1D10B4u: goto label_1d10b4;
            case 0x1D10C8u: goto label_1d10c8;
            case 0x1D1100u: goto label_1d1100;
            case 0x1D1108u: goto label_1d1108;
            case 0x1D1114u: goto label_1d1114;
            case 0x1D112Cu: goto label_1d112c;
            case 0x1D1144u: goto label_1d1144;
            case 0x1D1190u: goto label_1d1190;
            case 0x1D11A8u: goto label_1d11a8;
            case 0x1D11D0u: goto label_1d11d0;
            case 0x1D11D4u: goto label_1d11d4;
            case 0x1D11E8u: goto label_1d11e8;
            case 0x1D1200u: goto label_1d1200;
            case 0x1D120Cu: goto label_1d120c;
            case 0x1D123Cu: goto label_1d123c;
            case 0x1D1248u: goto label_1d1248;
            case 0x1D1254u: goto label_1d1254;
            case 0x1D1260u: goto label_1d1260;
            case 0x1D126Cu: goto label_1d126c;
            case 0x1D1278u: goto label_1d1278;
            case 0x1D1284u: goto label_1d1284;
            case 0x1D1290u: goto label_1d1290;
            case 0x1D129Cu: goto label_1d129c;
            case 0x1D12A8u: goto label_1d12a8;
            case 0x1D12B8u: goto label_1d12b8;
            case 0x1D12D4u: goto label_1d12d4;
            case 0x1D12E8u: goto label_1d12e8;
            case 0x1D1308u: goto label_1d1308;
            case 0x1D1368u: goto label_1d1368;
            case 0x1D1370u: goto label_1d1370;
            case 0x1D1388u: goto label_1d1388;
            case 0x1D139Cu: goto label_1d139c;
            case 0x1D13A0u: goto label_1d13a0;
            case 0x1D13B4u: goto label_1d13b4;
            case 0x1D141Cu: goto label_1d141c;
            case 0x1D1428u: goto label_1d1428;
            case 0x1D1434u: goto label_1d1434;
            case 0x1D1440u: goto label_1d1440;
            case 0x1D144Cu: goto label_1d144c;
            case 0x1D1458u: goto label_1d1458;
            case 0x1D1464u: goto label_1d1464;
            case 0x1D1470u: goto label_1d1470;
            case 0x1D147Cu: goto label_1d147c;
            case 0x1D148Cu: goto label_1d148c;
            case 0x1D14C4u: goto label_1d14c4;
            case 0x1D14CCu: goto label_1d14cc;
            case 0x1D14DCu: goto label_1d14dc;
            case 0x1D14E0u: goto label_1d14e0;
            case 0x1D1570u: goto label_1d1570;
            case 0x1D15ACu: goto label_1d15ac;
            case 0x1D15F4u: goto label_1d15f4;
            case 0x1D1604u: goto label_1d1604;
            case 0x1D160Cu: goto label_1d160c;
            case 0x1D163Cu: goto label_1d163c;
            case 0x1D1654u: goto label_1d1654;
            case 0x1D165Cu: goto label_1d165c;
            case 0x1D1670u: goto label_1d1670;
            case 0x1D1678u: goto label_1d1678;
            case 0x1D1688u: goto label_1d1688;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D0914u;
    // 0x1d0914: 0x0  nop
    ctx->pc = 0x1d0914u;
    // NOP
    // 0x1d0918: 0x0  nop
    ctx->pc = 0x1d0918u;
    // NOP
    // 0x1d091c: 0x0  nop
    ctx->pc = 0x1d091cu;
    // NOP
    // 0x1d0920: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1d0920u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1d0924: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d0924u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d0928: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x1d0928u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x1d092c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1d092cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d0930: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1d0930u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1d0934: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1d0934u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1d0938: 0xe0982d  daddu       $s3, $a3, $zero
    ctx->pc = 0x1d0938u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d093c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d093cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d0940: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d0940u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d0944: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x1d0944u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d0948: 0x84234200  lh          $v1, 0x4200($at)
    ctx->pc = 0x1d0948u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 1), 16896)));
    // 0x1d094c: 0x10620004  beq         $v1, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1D094Cu;
    {
        const bool branch_taken_0x1d094c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1D0950u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D094Cu;
            // 0x1d0950: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d094c) {
            ctx->pc = 0x1D0960u;
            goto label_1d0960;
        }
    }
    ctx->pc = 0x1D0954u;
    // 0x1d0954: 0x11000003  beqz        $t0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D0954u;
    {
        const bool branch_taken_0x1d0954 = (GPR_U64(ctx, 8) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D0958u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0954u;
            // 0x1d0958: 0x308300ff  andi        $v1, $a0, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d0954) {
            ctx->pc = 0x1D0964u;
            goto label_1d0964;
        }
    }
    ctx->pc = 0x1D095Cu;
    // 0x1d095c: 0x3c108000  lui         $s0, 0x8000
    ctx->pc = 0x1d095cu;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)32768 << 16));
label_1d0960:
    // 0x1d0960: 0x308300ff  andi        $v1, $a0, 0xFF
    ctx->pc = 0x1d0960u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
label_1d0964:
    // 0x1d0964: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1d0964u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d0968: 0x1062000e  beq         $v1, $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x1D0968u;
    {
        const bool branch_taken_0x1d0968 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1D096Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0968u;
            // 0x1d096c: 0x30c200ff  andi        $v0, $a2, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)255);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d0968) {
            ctx->pc = 0x1D09A4u;
            goto label_1d09a4;
        }
    }
    ctx->pc = 0x1D0970u;
    // 0x1d0970: 0x30c200ff  andi        $v0, $a2, 0xFF
    ctx->pc = 0x1d0970u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)255);
    // 0x1d0974: 0x3c030038  lui         $v1, 0x38
    ctx->pc = 0x1d0974u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)56 << 16));
    // 0x1d0978: 0x220c0  sll         $a0, $v0, 3
    ctx->pc = 0x1d0978u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x1d097c: 0x24637e90  addiu       $v1, $v1, 0x7E90
    ctx->pc = 0x1d097cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 32400));
    // 0x1d0980: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1d0980u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1d0984: 0x322200ff  andi        $v0, $s1, 0xFF
    ctx->pc = 0x1d0984u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)255);
    // 0x1d0988: 0x8c720000  lw          $s2, 0x0($v1)
    ctx->pc = 0x1d0988u;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1d098c: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1d098cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1d0990: 0xc073470  jal         func_1CD1C0
    ctx->pc = 0x1D0990u;
    SET_GPR_U32(ctx, 31, 0x1D0998u);
    ctx->pc = 0x1D0994u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0990u;
            // 0x1d0994: 0x24441200  addiu       $a0, $v0, 0x1200 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 4608));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CD1C0u;
    if (runtime->hasFunction(0x1CD1C0u)) {
        auto targetFn = runtime->lookupFunction(0x1CD1C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0998u; }
        if (ctx->pc != 0x1D0998u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CD1C0_0x1cd1c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0998u; }
        if (ctx->pc != 0x1D0998u) { return; }
    }
    ctx->pc = 0x1D0998u;
label_1d0998:
    // 0x1d0998: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1D0998u;
    {
        const bool branch_taken_0x1d0998 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d0998) {
            ctx->pc = 0x1D09D0u;
            goto label_1d09d0;
        }
    }
    ctx->pc = 0x1D09A0u;
    // 0x1d09a0: 0x30c200ff  andi        $v0, $a2, 0xFF
    ctx->pc = 0x1d09a0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)255);
label_1d09a4:
    // 0x1d09a4: 0x3c030039  lui         $v1, 0x39
    ctx->pc = 0x1d09a4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)57 << 16));
    // 0x1d09a8: 0x220c0  sll         $a0, $v0, 3
    ctx->pc = 0x1d09a8u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x1d09ac: 0x246387f0  addiu       $v1, $v1, -0x7810
    ctx->pc = 0x1d09acu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294936560));
    // 0x1d09b0: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1d09b0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1d09b4: 0x322200ff  andi        $v0, $s1, 0xFF
    ctx->pc = 0x1d09b4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)255);
    // 0x1d09b8: 0x8c720000  lw          $s2, 0x0($v1)
    ctx->pc = 0x1d09b8u;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1d09bc: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1d09bcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1d09c0: 0xc073470  jal         func_1CD1C0
    ctx->pc = 0x1D09C0u;
    SET_GPR_U32(ctx, 31, 0x1D09C8u);
    ctx->pc = 0x1D09C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D09C0u;
            // 0x1d09c4: 0x24441300  addiu       $a0, $v0, 0x1300 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 4864));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CD1C0u;
    if (runtime->hasFunction(0x1CD1C0u)) {
        auto targetFn = runtime->lookupFunction(0x1CD1C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D09C8u; }
        if (ctx->pc != 0x1D09C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CD1C0_0x1cd1c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D09C8u; }
        if (ctx->pc != 0x1D09C8u) { return; }
    }
    ctx->pc = 0x1D09C8u;
label_1d09c8:
    // 0x1d09c8: 0x3c022000  lui         $v0, 0x2000
    ctx->pc = 0x1d09c8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)8192 << 16));
    // 0x1d09cc: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x1d09ccu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
label_1d09d0:
    // 0x1d09d0: 0xc0740e8  jal         func_1D03A0
    ctx->pc = 0x1D09D0u;
    SET_GPR_U32(ctx, 31, 0x1D09D8u);
    ctx->pc = 0x1D03A0u;
    if (runtime->hasFunction(0x1D03A0u)) {
        auto targetFn = runtime->lookupFunction(0x1D03A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D09D8u; }
        if (ctx->pc != 0x1D09D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D03A0_0x1d03a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D09D8u; }
        if (ctx->pc != 0x1D09D8u) { return; }
    }
    ctx->pc = 0x1D09D8u;
label_1d09d8:
    // 0x1d09d8: 0x322300ff  andi        $v1, $s1, 0xFF
    ctx->pc = 0x1d09d8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)255);
    // 0x1d09dc: 0x24021468  addiu       $v0, $zero, 0x1468
    ctx->pc = 0x1d09dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5224));
    // 0x1d09e0: 0x621818  mult        $v1, $v1, $v0
    ctx->pc = 0x1d09e0u;
    { int64_t result = (int64_t)GPR_S32(ctx, 3) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x1d09e4: 0x24040020  addiu       $a0, $zero, 0x20
    ctx->pc = 0x1d09e4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x1d09e8: 0x24050009  addiu       $a1, $zero, 0x9
    ctx->pc = 0x1d09e8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x1d09ec: 0x3c020046  lui         $v0, 0x46
    ctx->pc = 0x1d09ecu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)70 << 16));
    // 0x1d09f0: 0x24429120  addiu       $v0, $v0, -0x6EE0
    ctx->pc = 0x1d09f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294938912));
    // 0x1d09f4: 0xc06ca9c  jal         func_1B2A70
    ctx->pc = 0x1D09F4u;
    SET_GPR_U32(ctx, 31, 0x1D09FCu);
    ctx->pc = 0x1D09F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D09F4u;
            // 0x1d09f8: 0x438821  addu        $s1, $v0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B2A70u;
    if (runtime->hasFunction(0x1B2A70u)) {
        auto targetFn = runtime->lookupFunction(0x1B2A70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D09FCu; }
        if (ctx->pc != 0x1D09FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B2A70_0x1b2a70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D09FCu; }
        if (ctx->pc != 0x1D09FCu) { return; }
    }
    ctx->pc = 0x1D09FCu;
label_1d09fc:
    // 0x1d09fc: 0x326300ff  andi        $v1, $s3, 0xFF
    ctx->pc = 0x1d09fcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 19) & (uint64_t)(uint16_t)255);
    // 0x1d0a00: 0xae220808  sw          $v0, 0x808($s1)
    ctx->pc = 0x1d0a00u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 2056), GPR_U32(ctx, 2));
    // 0x1d0a04: 0x31900  sll         $v1, $v1, 4
    ctx->pc = 0x1d0a04u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x1d0a08: 0x36070002  ori         $a3, $s0, 0x2
    ctx->pc = 0x1d0a08u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 16) | (uint64_t)(uint16_t)2);
    // 0x1d0a0c: 0x2431021  addu        $v0, $s2, $v1
    ctx->pc = 0x1d0a0cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 3)));
    // 0x1d0a10: 0x26230820  addiu       $v1, $s1, 0x820
    ctx->pc = 0x1d0a10u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), 2080));
    // 0x1d0a14: 0xae230000  sw          $v1, 0x0($s1)
    ctx->pc = 0x1d0a14u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
    // 0x1d0a18: 0x26230a20  addiu       $v1, $s1, 0xA20
    ctx->pc = 0x1d0a18u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), 2592));
    // 0x1d0a1c: 0xae230004  sw          $v1, 0x4($s1)
    ctx->pc = 0x1d0a1cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 3));
    // 0x1d0a20: 0x26230c20  addiu       $v1, $s1, 0xC20
    ctx->pc = 0x1d0a20u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), 3104));
    // 0x1d0a24: 0xae230818  sw          $v1, 0x818($s1)
    ctx->pc = 0x1d0a24u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 2072), GPR_U32(ctx, 3));
    // 0x1d0a28: 0x90450000  lbu         $a1, 0x0($v0)
    ctx->pc = 0x1d0a28u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1d0a2c: 0x90460001  lbu         $a2, 0x1($v0)
    ctx->pc = 0x1d0a2cu;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 1)));
    // 0x1d0a30: 0x90480004  lbu         $t0, 0x4($v0)
    ctx->pc = 0x1d0a30u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1d0a34: 0xc073c24  jal         func_1CF090
    ctx->pc = 0x1D0A34u;
    SET_GPR_U32(ctx, 31, 0x1D0A3Cu);
    ctx->pc = 0x1D0A38u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0A34u;
            // 0x1d0a38: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CF090u;
    if (runtime->hasFunction(0x1CF090u)) {
        auto targetFn = runtime->lookupFunction(0x1CF090u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0A3Cu; }
        if (ctx->pc != 0x1D0A3Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CF090_0x1cf090(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0A3Cu; }
        if (ctx->pc != 0x1D0A3Cu) { return; }
    }
    ctx->pc = 0x1D0A3Cu;
label_1d0a3c:
    // 0x1d0a3c: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1D0A3Cu;
    {
        const bool branch_taken_0x1d0a3c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d0a3c) {
            ctx->pc = 0x1D0A50u;
            goto label_1d0a50;
        }
    }
    ctx->pc = 0x1D0A44u;
    // 0x1d0a44: 0xc06cae4  jal         func_1B2B90
    ctx->pc = 0x1D0A44u;
    SET_GPR_U32(ctx, 31, 0x1D0A4Cu);
    ctx->pc = 0x1D0A48u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0A44u;
            // 0x1d0a48: 0x8e240808  lw          $a0, 0x808($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 2056)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B2B90u;
    if (runtime->hasFunction(0x1B2B90u)) {
        auto targetFn = runtime->lookupFunction(0x1B2B90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0A4Cu; }
        if (ctx->pc != 0x1D0A4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B2B90_0x1b2b90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0A4Cu; }
        if (ctx->pc != 0x1D0A4Cu) { return; }
    }
    ctx->pc = 0x1D0A4Cu;
label_1d0a4c:
    // 0x1d0a4c: 0xae200808  sw          $zero, 0x808($s1)
    ctx->pc = 0x1d0a4cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 2056), GPR_U32(ctx, 0));
label_1d0a50:
    // 0x1d0a50: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x1d0a50u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1d0a54: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1d0a54u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1d0a58: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1d0a58u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d0a5c: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d0a5cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d0a60: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d0a60u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d0a64: 0x3e00008  jr          $ra
    ctx->pc = 0x1D0A64u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D0A68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0A64u;
            // 0x1d0a68: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D06E0u: goto label_1d06e0;
            case 0x1D0754u: goto label_1d0754;
            case 0x1D0760u: goto label_1d0760;
            case 0x1D076Cu: goto label_1d076c;
            case 0x1D0778u: goto label_1d0778;
            case 0x1D0784u: goto label_1d0784;
            case 0x1D0790u: goto label_1d0790;
            case 0x1D079Cu: goto label_1d079c;
            case 0x1D07A8u: goto label_1d07a8;
            case 0x1D07C0u: goto label_1d07c0;
            case 0x1D07DCu: goto label_1d07dc;
            case 0x1D0840u: goto label_1d0840;
            case 0x1D0848u: goto label_1d0848;
            case 0x1D0858u: goto label_1d0858;
            case 0x1D0860u: goto label_1d0860;
            case 0x1D0870u: goto label_1d0870;
            case 0x1D089Cu: goto label_1d089c;
            case 0x1D08C8u: goto label_1d08c8;
            case 0x1D08E4u: goto label_1d08e4;
            case 0x1D08F8u: goto label_1d08f8;
            case 0x1D0960u: goto label_1d0960;
            case 0x1D0964u: goto label_1d0964;
            case 0x1D0998u: goto label_1d0998;
            case 0x1D09A4u: goto label_1d09a4;
            case 0x1D09C8u: goto label_1d09c8;
            case 0x1D09D0u: goto label_1d09d0;
            case 0x1D09D8u: goto label_1d09d8;
            case 0x1D09FCu: goto label_1d09fc;
            case 0x1D0A3Cu: goto label_1d0a3c;
            case 0x1D0A4Cu: goto label_1d0a4c;
            case 0x1D0A50u: goto label_1d0a50;
            case 0x1D0ABCu: goto label_1d0abc;
            case 0x1D0AC4u: goto label_1d0ac4;
            case 0x1D0AD8u: goto label_1d0ad8;
            case 0x1D0AECu: goto label_1d0aec;
            case 0x1D0B20u: goto label_1d0b20;
            case 0x1D0B34u: goto label_1d0b34;
            case 0x1D0B40u: goto label_1d0b40;
            case 0x1D0B54u: goto label_1d0b54;
            case 0x1D0B8Cu: goto label_1d0b8c;
            case 0x1D0B98u: goto label_1d0b98;
            case 0x1D0BA4u: goto label_1d0ba4;
            case 0x1D0BB0u: goto label_1d0bb0;
            case 0x1D0BBCu: goto label_1d0bbc;
            case 0x1D0BC8u: goto label_1d0bc8;
            case 0x1D0BD4u: goto label_1d0bd4;
            case 0x1D0BE0u: goto label_1d0be0;
            case 0x1D0BECu: goto label_1d0bec;
            case 0x1D0C00u: goto label_1d0c00;
            case 0x1D0C38u: goto label_1d0c38;
            case 0x1D0C40u: goto label_1d0c40;
            case 0x1D0C50u: goto label_1d0c50;
            case 0x1D0C68u: goto label_1d0c68;
            case 0x1D0C6Cu: goto label_1d0c6c;
            case 0x1D0CC4u: goto label_1d0cc4;
            case 0x1D0CD0u: goto label_1d0cd0;
            case 0x1D0CDCu: goto label_1d0cdc;
            case 0x1D0CE8u: goto label_1d0ce8;
            case 0x1D0CF4u: goto label_1d0cf4;
            case 0x1D0D00u: goto label_1d0d00;
            case 0x1D0D0Cu: goto label_1d0d0c;
            case 0x1D0D18u: goto label_1d0d18;
            case 0x1D0D38u: goto label_1d0d38;
            case 0x1D0D6Cu: goto label_1d0d6c;
            case 0x1D0DB4u: goto label_1d0db4;
            case 0x1D0DF8u: goto label_1d0df8;
            case 0x1D0E0Cu: goto label_1d0e0c;
            case 0x1D0E14u: goto label_1d0e14;
            case 0x1D0E38u: goto label_1d0e38;
            case 0x1D0E44u: goto label_1d0e44;
            case 0x1D0E48u: goto label_1d0e48;
            case 0x1D0E70u: goto label_1d0e70;
            case 0x1D0EA8u: goto label_1d0ea8;
            case 0x1D0EFCu: goto label_1d0efc;
            case 0x1D0F04u: goto label_1d0f04;
            case 0x1D0F0Cu: goto label_1d0f0c;
            case 0x1D0F38u: goto label_1d0f38;
            case 0x1D0F40u: goto label_1d0f40;
            case 0x1D0F5Cu: goto label_1d0f5c;
            case 0x1D0F78u: goto label_1d0f78;
            case 0x1D0F94u: goto label_1d0f94;
            case 0x1D0F9Cu: goto label_1d0f9c;
            case 0x1D0FBCu: goto label_1d0fbc;
            case 0x1D0FC4u: goto label_1d0fc4;
            case 0x1D0FE4u: goto label_1d0fe4;
            case 0x1D1004u: goto label_1d1004;
            case 0x1D100Cu: goto label_1d100c;
            case 0x1D1048u: goto label_1d1048;
            case 0x1D1054u: goto label_1d1054;
            case 0x1D1060u: goto label_1d1060;
            case 0x1D106Cu: goto label_1d106c;
            case 0x1D1078u: goto label_1d1078;
            case 0x1D1084u: goto label_1d1084;
            case 0x1D1090u: goto label_1d1090;
            case 0x1D109Cu: goto label_1d109c;
            case 0x1D10A8u: goto label_1d10a8;
            case 0x1D10B4u: goto label_1d10b4;
            case 0x1D10C8u: goto label_1d10c8;
            case 0x1D1100u: goto label_1d1100;
            case 0x1D1108u: goto label_1d1108;
            case 0x1D1114u: goto label_1d1114;
            case 0x1D112Cu: goto label_1d112c;
            case 0x1D1144u: goto label_1d1144;
            case 0x1D1190u: goto label_1d1190;
            case 0x1D11A8u: goto label_1d11a8;
            case 0x1D11D0u: goto label_1d11d0;
            case 0x1D11D4u: goto label_1d11d4;
            case 0x1D11E8u: goto label_1d11e8;
            case 0x1D1200u: goto label_1d1200;
            case 0x1D120Cu: goto label_1d120c;
            case 0x1D123Cu: goto label_1d123c;
            case 0x1D1248u: goto label_1d1248;
            case 0x1D1254u: goto label_1d1254;
            case 0x1D1260u: goto label_1d1260;
            case 0x1D126Cu: goto label_1d126c;
            case 0x1D1278u: goto label_1d1278;
            case 0x1D1284u: goto label_1d1284;
            case 0x1D1290u: goto label_1d1290;
            case 0x1D129Cu: goto label_1d129c;
            case 0x1D12A8u: goto label_1d12a8;
            case 0x1D12B8u: goto label_1d12b8;
            case 0x1D12D4u: goto label_1d12d4;
            case 0x1D12E8u: goto label_1d12e8;
            case 0x1D1308u: goto label_1d1308;
            case 0x1D1368u: goto label_1d1368;
            case 0x1D1370u: goto label_1d1370;
            case 0x1D1388u: goto label_1d1388;
            case 0x1D139Cu: goto label_1d139c;
            case 0x1D13A0u: goto label_1d13a0;
            case 0x1D13B4u: goto label_1d13b4;
            case 0x1D141Cu: goto label_1d141c;
            case 0x1D1428u: goto label_1d1428;
            case 0x1D1434u: goto label_1d1434;
            case 0x1D1440u: goto label_1d1440;
            case 0x1D144Cu: goto label_1d144c;
            case 0x1D1458u: goto label_1d1458;
            case 0x1D1464u: goto label_1d1464;
            case 0x1D1470u: goto label_1d1470;
            case 0x1D147Cu: goto label_1d147c;
            case 0x1D148Cu: goto label_1d148c;
            case 0x1D14C4u: goto label_1d14c4;
            case 0x1D14CCu: goto label_1d14cc;
            case 0x1D14DCu: goto label_1d14dc;
            case 0x1D14E0u: goto label_1d14e0;
            case 0x1D1570u: goto label_1d1570;
            case 0x1D15ACu: goto label_1d15ac;
            case 0x1D15F4u: goto label_1d15f4;
            case 0x1D1604u: goto label_1d1604;
            case 0x1D160Cu: goto label_1d160c;
            case 0x1D163Cu: goto label_1d163c;
            case 0x1D1654u: goto label_1d1654;
            case 0x1D165Cu: goto label_1d165c;
            case 0x1D1670u: goto label_1d1670;
            case 0x1D1678u: goto label_1d1678;
            case 0x1D1688u: goto label_1d1688;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D0A6Cu;
    // 0x1d0a6c: 0x0  nop
    ctx->pc = 0x1d0a6cu;
    // NOP
    // 0x1d0a70: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1d0a70u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1d0a74: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d0a74u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d0a78: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x1d0a78u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x1d0a7c: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1d0a7cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1d0a80: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1d0a80u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1d0a84: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x1d0a84u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d0a88: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d0a88u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d0a8c: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x1d0a8cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d0a90: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d0a90u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d0a94: 0x802243d7  lb          $v0, 0x43D7($at)
    ctx->pc = 0x1d0a94u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 17367)));
    // 0x1d0a98: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1D0A98u;
    {
        const bool branch_taken_0x1d0a98 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D0A9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0A98u;
            // 0x1d0a9c: 0xc0882d  daddu       $s1, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d0a98) {
            ctx->pc = 0x1D0AC4u;
            goto label_1d0ac4;
        }
    }
    ctx->pc = 0x1D0AA0u;
    // 0x1d0aa0: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d0aa0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d0aa4: 0x902443da  lbu         $a0, 0x43DA($at)
    ctx->pc = 0x1d0aa4u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17370)));
    // 0x1d0aa8: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d0aa8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d0aac: 0x902543dc  lbu         $a1, 0x43DC($at)
    ctx->pc = 0x1d0aacu;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17372)));
    // 0x1d0ab0: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d0ab0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d0ab4: 0xc06a930  jal         func_1AA4C0
    ctx->pc = 0x1D0AB4u;
    SET_GPR_U32(ctx, 31, 0x1D0ABCu);
    ctx->pc = 0x1D0AB8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0AB4u;
            // 0x1d0ab8: 0x902643de  lbu         $a2, 0x43DE($at) (Delay Slot)
        SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17374)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AA4C0u;
    if (runtime->hasFunction(0x1AA4C0u)) {
        auto targetFn = runtime->lookupFunction(0x1AA4C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0ABCu; }
        if (ctx->pc != 0x1D0ABCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AA4C0_0x1aa4c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0ABCu; }
        if (ctx->pc != 0x1D0ABCu) { return; }
    }
    ctx->pc = 0x1D0ABCu;
label_1d0abc:
    // 0x1d0abc: 0x10000025  b           . + 4 + (0x25 << 2)
    ctx->pc = 0x1D0ABCu;
    {
        const bool branch_taken_0x1d0abc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D0AC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0ABCu;
            // 0x1d0ac0: 0xdfbf0040  ld          $ra, 0x40($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d0abc) {
            ctx->pc = 0x1D0B54u;
            goto label_1d0b54;
        }
    }
    ctx->pc = 0x1D0AC4u;
label_1d0ac4:
    // 0x1d0ac4: 0x3c010057  lui         $at, 0x57
    ctx->pc = 0x1d0ac4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)87 << 16));
    // 0x1d0ac8: 0x902297b8  lbu         $v0, -0x6848($at)
    ctx->pc = 0x1d0ac8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294940600)));
    // 0x1d0acc: 0x211c0  sll         $v0, $v0, 7
    ctx->pc = 0x1d0accu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 7));
    // 0x1d0ad0: 0xc073470  jal         func_1CD1C0
    ctx->pc = 0x1D0AD0u;
    SET_GPR_U32(ctx, 31, 0x1D0AD8u);
    ctx->pc = 0x1D0AD4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0AD0u;
            // 0x1d0ad4: 0x24441800  addiu       $a0, $v0, 0x1800 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 6144));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CD1C0u;
    if (runtime->hasFunction(0x1CD1C0u)) {
        auto targetFn = runtime->lookupFunction(0x1CD1C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0AD8u; }
        if (ctx->pc != 0x1D0AD8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CD1C0_0x1cd1c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0AD8u; }
        if (ctx->pc != 0x1D0AD8u) { return; }
    }
    ctx->pc = 0x1D0AD8u;
label_1d0ad8:
    // 0x1d0ad8: 0x3c10004a  lui         $s0, 0x4A
    ctx->pc = 0x1d0ad8u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)74 << 16));
    // 0x1d0adc: 0x24040080  addiu       $a0, $zero, 0x80
    ctx->pc = 0x1d0adcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
    // 0x1d0ae0: 0x24050006  addiu       $a1, $zero, 0x6
    ctx->pc = 0x1d0ae0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x1d0ae4: 0xc06ca9c  jal         func_1B2A70
    ctx->pc = 0x1D0AE4u;
    SET_GPR_U32(ctx, 31, 0x1D0AECu);
    ctx->pc = 0x1D0AE8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0AE4u;
            // 0x1d0ae8: 0x2610ef50  addiu       $s0, $s0, -0x10B0 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294963024));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B2A70u;
    if (runtime->hasFunction(0x1B2A70u)) {
        auto targetFn = runtime->lookupFunction(0x1B2A70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0AECu; }
        if (ctx->pc != 0x1D0AECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B2A70_0x1b2a70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0AECu; }
        if (ctx->pc != 0x1D0AECu) { return; }
    }
    ctx->pc = 0x1D0AECu;
label_1d0aec:
    // 0x1d0aec: 0x326400ff  andi        $a0, $s3, 0xFF
    ctx->pc = 0x1d0aecu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 19) & (uint64_t)(uint16_t)255);
    // 0x1d0af0: 0x324300ff  andi        $v1, $s2, 0xFF
    ctx->pc = 0x1d0af0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 18) & (uint64_t)(uint16_t)255);
    // 0x1d0af4: 0x42400  sll         $a0, $a0, 16
    ctx->pc = 0x1d0af4u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 16));
    // 0x1d0af8: 0x31a00  sll         $v1, $v1, 8
    ctx->pc = 0x1d0af8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
    // 0x1d0afc: 0x832025  or          $a0, $a0, $v1
    ctx->pc = 0x1d0afcu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x1d0b00: 0xae020808  sw          $v0, 0x808($s0)
    ctx->pc = 0x1d0b00u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 2056), GPR_U32(ctx, 2));
    // 0x1d0b04: 0x322300ff  andi        $v1, $s1, 0xFF
    ctx->pc = 0x1d0b04u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)255);
    // 0x1d0b08: 0x2405ffff  addiu       $a1, $zero, -0x1
    ctx->pc = 0x1d0b08u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d0b0c: 0x642025  or          $a0, $v1, $a0
    ctx->pc = 0x1d0b0cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x1d0b10: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x1d0b10u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d0b14: 0x24070002  addiu       $a3, $zero, 0x2
    ctx->pc = 0x1d0b14u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1d0b18: 0xc073844  jal         func_1CE110
    ctx->pc = 0x1D0B18u;
    SET_GPR_U32(ctx, 31, 0x1D0B20u);
    ctx->pc = 0x1D0B1Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0B18u;
            // 0x1d0b1c: 0xae000818  sw          $zero, 0x818($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 2072), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CE110u;
    if (runtime->hasFunction(0x1CE110u)) {
        auto targetFn = runtime->lookupFunction(0x1CE110u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0B20u; }
        if (ctx->pc != 0x1D0B20u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CE110_0x1ce110(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0B20u; }
        if (ctx->pc != 0x1D0B20u) { return; }
    }
    ctx->pc = 0x1D0B20u;
label_1d0b20:
    // 0x1d0b20: 0x3c04004a  lui         $a0, 0x4A
    ctx->pc = 0x1d0b20u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)74 << 16));
    // 0x1d0b24: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1d0b24u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d0b28: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1d0b28u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d0b2c: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1D0B2Cu;
    {
        const bool branch_taken_0x1d0b2c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D0B30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0B2Cu;
            // 0x1d0b30: 0x2484eef0  addiu       $a0, $a0, -0x1110 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294962928));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d0b2c) {
            ctx->pc = 0x1D0B40u;
            goto label_1d0b40;
        }
    }
    ctx->pc = 0x1D0B34u;
label_1d0b34:
    // 0x1d0b34: 0x861821  addu        $v1, $a0, $a2
    ctx->pc = 0x1d0b34u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 6)));
    // 0x1d0b38: 0xa06508a0  sb          $a1, 0x8A0($v1)
    ctx->pc = 0x1d0b38u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 2208), (uint8_t)GPR_U32(ctx, 5));
    // 0x1d0b3c: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x1d0b3cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
label_1d0b40:
    // 0x1d0b40: 0x96030812  lhu         $v1, 0x812($s0)
    ctx->pc = 0x1d0b40u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 2066)));
    // 0x1d0b44: 0xc3182a  slt         $v1, $a2, $v1
    ctx->pc = 0x1d0b44u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 6) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1d0b48: 0x1460fffa  bnez        $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1D0B48u;
    {
        const bool branch_taken_0x1d0b48 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d0b48) {
            ctx->pc = 0x1D0B34u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d0b34;
        }
    }
    ctx->pc = 0x1D0B50u;
    // 0x1d0b50: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x1d0b50u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
label_1d0b54:
    // 0x1d0b54: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1d0b54u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1d0b58: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1d0b58u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d0b5c: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d0b5cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d0b60: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d0b60u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d0b64: 0x3e00008  jr          $ra
    ctx->pc = 0x1D0B64u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D0B68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0B64u;
            // 0x1d0b68: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D06E0u: goto label_1d06e0;
            case 0x1D0754u: goto label_1d0754;
            case 0x1D0760u: goto label_1d0760;
            case 0x1D076Cu: goto label_1d076c;
            case 0x1D0778u: goto label_1d0778;
            case 0x1D0784u: goto label_1d0784;
            case 0x1D0790u: goto label_1d0790;
            case 0x1D079Cu: goto label_1d079c;
            case 0x1D07A8u: goto label_1d07a8;
            case 0x1D07C0u: goto label_1d07c0;
            case 0x1D07DCu: goto label_1d07dc;
            case 0x1D0840u: goto label_1d0840;
            case 0x1D0848u: goto label_1d0848;
            case 0x1D0858u: goto label_1d0858;
            case 0x1D0860u: goto label_1d0860;
            case 0x1D0870u: goto label_1d0870;
            case 0x1D089Cu: goto label_1d089c;
            case 0x1D08C8u: goto label_1d08c8;
            case 0x1D08E4u: goto label_1d08e4;
            case 0x1D08F8u: goto label_1d08f8;
            case 0x1D0960u: goto label_1d0960;
            case 0x1D0964u: goto label_1d0964;
            case 0x1D0998u: goto label_1d0998;
            case 0x1D09A4u: goto label_1d09a4;
            case 0x1D09C8u: goto label_1d09c8;
            case 0x1D09D0u: goto label_1d09d0;
            case 0x1D09D8u: goto label_1d09d8;
            case 0x1D09FCu: goto label_1d09fc;
            case 0x1D0A3Cu: goto label_1d0a3c;
            case 0x1D0A4Cu: goto label_1d0a4c;
            case 0x1D0A50u: goto label_1d0a50;
            case 0x1D0ABCu: goto label_1d0abc;
            case 0x1D0AC4u: goto label_1d0ac4;
            case 0x1D0AD8u: goto label_1d0ad8;
            case 0x1D0AECu: goto label_1d0aec;
            case 0x1D0B20u: goto label_1d0b20;
            case 0x1D0B34u: goto label_1d0b34;
            case 0x1D0B40u: goto label_1d0b40;
            case 0x1D0B54u: goto label_1d0b54;
            case 0x1D0B8Cu: goto label_1d0b8c;
            case 0x1D0B98u: goto label_1d0b98;
            case 0x1D0BA4u: goto label_1d0ba4;
            case 0x1D0BB0u: goto label_1d0bb0;
            case 0x1D0BBCu: goto label_1d0bbc;
            case 0x1D0BC8u: goto label_1d0bc8;
            case 0x1D0BD4u: goto label_1d0bd4;
            case 0x1D0BE0u: goto label_1d0be0;
            case 0x1D0BECu: goto label_1d0bec;
            case 0x1D0C00u: goto label_1d0c00;
            case 0x1D0C38u: goto label_1d0c38;
            case 0x1D0C40u: goto label_1d0c40;
            case 0x1D0C50u: goto label_1d0c50;
            case 0x1D0C68u: goto label_1d0c68;
            case 0x1D0C6Cu: goto label_1d0c6c;
            case 0x1D0CC4u: goto label_1d0cc4;
            case 0x1D0CD0u: goto label_1d0cd0;
            case 0x1D0CDCu: goto label_1d0cdc;
            case 0x1D0CE8u: goto label_1d0ce8;
            case 0x1D0CF4u: goto label_1d0cf4;
            case 0x1D0D00u: goto label_1d0d00;
            case 0x1D0D0Cu: goto label_1d0d0c;
            case 0x1D0D18u: goto label_1d0d18;
            case 0x1D0D38u: goto label_1d0d38;
            case 0x1D0D6Cu: goto label_1d0d6c;
            case 0x1D0DB4u: goto label_1d0db4;
            case 0x1D0DF8u: goto label_1d0df8;
            case 0x1D0E0Cu: goto label_1d0e0c;
            case 0x1D0E14u: goto label_1d0e14;
            case 0x1D0E38u: goto label_1d0e38;
            case 0x1D0E44u: goto label_1d0e44;
            case 0x1D0E48u: goto label_1d0e48;
            case 0x1D0E70u: goto label_1d0e70;
            case 0x1D0EA8u: goto label_1d0ea8;
            case 0x1D0EFCu: goto label_1d0efc;
            case 0x1D0F04u: goto label_1d0f04;
            case 0x1D0F0Cu: goto label_1d0f0c;
            case 0x1D0F38u: goto label_1d0f38;
            case 0x1D0F40u: goto label_1d0f40;
            case 0x1D0F5Cu: goto label_1d0f5c;
            case 0x1D0F78u: goto label_1d0f78;
            case 0x1D0F94u: goto label_1d0f94;
            case 0x1D0F9Cu: goto label_1d0f9c;
            case 0x1D0FBCu: goto label_1d0fbc;
            case 0x1D0FC4u: goto label_1d0fc4;
            case 0x1D0FE4u: goto label_1d0fe4;
            case 0x1D1004u: goto label_1d1004;
            case 0x1D100Cu: goto label_1d100c;
            case 0x1D1048u: goto label_1d1048;
            case 0x1D1054u: goto label_1d1054;
            case 0x1D1060u: goto label_1d1060;
            case 0x1D106Cu: goto label_1d106c;
            case 0x1D1078u: goto label_1d1078;
            case 0x1D1084u: goto label_1d1084;
            case 0x1D1090u: goto label_1d1090;
            case 0x1D109Cu: goto label_1d109c;
            case 0x1D10A8u: goto label_1d10a8;
            case 0x1D10B4u: goto label_1d10b4;
            case 0x1D10C8u: goto label_1d10c8;
            case 0x1D1100u: goto label_1d1100;
            case 0x1D1108u: goto label_1d1108;
            case 0x1D1114u: goto label_1d1114;
            case 0x1D112Cu: goto label_1d112c;
            case 0x1D1144u: goto label_1d1144;
            case 0x1D1190u: goto label_1d1190;
            case 0x1D11A8u: goto label_1d11a8;
            case 0x1D11D0u: goto label_1d11d0;
            case 0x1D11D4u: goto label_1d11d4;
            case 0x1D11E8u: goto label_1d11e8;
            case 0x1D1200u: goto label_1d1200;
            case 0x1D120Cu: goto label_1d120c;
            case 0x1D123Cu: goto label_1d123c;
            case 0x1D1248u: goto label_1d1248;
            case 0x1D1254u: goto label_1d1254;
            case 0x1D1260u: goto label_1d1260;
            case 0x1D126Cu: goto label_1d126c;
            case 0x1D1278u: goto label_1d1278;
            case 0x1D1284u: goto label_1d1284;
            case 0x1D1290u: goto label_1d1290;
            case 0x1D129Cu: goto label_1d129c;
            case 0x1D12A8u: goto label_1d12a8;
            case 0x1D12B8u: goto label_1d12b8;
            case 0x1D12D4u: goto label_1d12d4;
            case 0x1D12E8u: goto label_1d12e8;
            case 0x1D1308u: goto label_1d1308;
            case 0x1D1368u: goto label_1d1368;
            case 0x1D1370u: goto label_1d1370;
            case 0x1D1388u: goto label_1d1388;
            case 0x1D139Cu: goto label_1d139c;
            case 0x1D13A0u: goto label_1d13a0;
            case 0x1D13B4u: goto label_1d13b4;
            case 0x1D141Cu: goto label_1d141c;
            case 0x1D1428u: goto label_1d1428;
            case 0x1D1434u: goto label_1d1434;
            case 0x1D1440u: goto label_1d1440;
            case 0x1D144Cu: goto label_1d144c;
            case 0x1D1458u: goto label_1d1458;
            case 0x1D1464u: goto label_1d1464;
            case 0x1D1470u: goto label_1d1470;
            case 0x1D147Cu: goto label_1d147c;
            case 0x1D148Cu: goto label_1d148c;
            case 0x1D14C4u: goto label_1d14c4;
            case 0x1D14CCu: goto label_1d14cc;
            case 0x1D14DCu: goto label_1d14dc;
            case 0x1D14E0u: goto label_1d14e0;
            case 0x1D1570u: goto label_1d1570;
            case 0x1D15ACu: goto label_1d15ac;
            case 0x1D15F4u: goto label_1d15f4;
            case 0x1D1604u: goto label_1d1604;
            case 0x1D160Cu: goto label_1d160c;
            case 0x1D163Cu: goto label_1d163c;
            case 0x1D1654u: goto label_1d1654;
            case 0x1D165Cu: goto label_1d165c;
            case 0x1D1670u: goto label_1d1670;
            case 0x1D1678u: goto label_1d1678;
            case 0x1D1688u: goto label_1d1688;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D0B6Cu;
    // 0x1d0b6c: 0x0  nop
    ctx->pc = 0x1d0b6cu;
    // NOP
    // 0x1d0b70: 0x27bdfed0  addiu       $sp, $sp, -0x130
    ctx->pc = 0x1d0b70u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966992));
    // 0x1d0b74: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1d0b74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1d0b78: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d0b78u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d0b7c: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1d0b7cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d0b80: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d0b80u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d0b84: 0xc073470  jal         func_1CD1C0
    ctx->pc = 0x1D0B84u;
    SET_GPR_U32(ctx, 31, 0x1D0B8Cu);
    ctx->pc = 0x1D0B88u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0B84u;
            // 0x1d0b88: 0x24042a00  addiu       $a0, $zero, 0x2A00 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 10752));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CD1C0u;
    if (runtime->hasFunction(0x1CD1C0u)) {
        auto targetFn = runtime->lookupFunction(0x1CD1C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0B8Cu; }
        if (ctx->pc != 0x1D0B8Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CD1C0_0x1cd1c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0B8Cu; }
        if (ctx->pc != 0x1D0B8Cu) { return; }
    }
    ctx->pc = 0x1D0B8Cu;
label_1d0b8c:
    // 0x1d0b8c: 0x24040015  addiu       $a0, $zero, 0x15
    ctx->pc = 0x1d0b8cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 21));
    // 0x1d0b90: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D0B90u;
    SET_GPR_U32(ctx, 31, 0x1D0B98u);
    ctx->pc = 0x1D0B94u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0B90u;
            // 0x1d0b94: 0x24050002  addiu       $a1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0B98u; }
        if (ctx->pc != 0x1D0B98u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0B98u; }
        if (ctx->pc != 0x1D0B98u) { return; }
    }
    ctx->pc = 0x1D0B98u;
label_1d0b98:
    // 0x1d0b98: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1d0b98u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d0b9c: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D0B9Cu;
    SET_GPR_U32(ctx, 31, 0x1D0BA4u);
    ctx->pc = 0x1D0BA0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0B9Cu;
            // 0x1d0ba0: 0x24050800  addiu       $a1, $zero, 0x800 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2048));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0BA4u; }
        if (ctx->pc != 0x1D0BA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0BA4u; }
        if (ctx->pc != 0x1D0BA4u) { return; }
    }
    ctx->pc = 0x1D0BA4u;
label_1d0ba4:
    // 0x1d0ba4: 0x24040012  addiu       $a0, $zero, 0x12
    ctx->pc = 0x1d0ba4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 18));
    // 0x1d0ba8: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D0BA8u;
    SET_GPR_U32(ctx, 31, 0x1D0BB0u);
    ctx->pc = 0x1D0BACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0BA8u;
            // 0x1d0bac: 0x34058000  ori         $a1, $zero, 0x8000 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0BB0u; }
        if (ctx->pc != 0x1D0BB0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0BB0u; }
        if (ctx->pc != 0x1D0BB0u) { return; }
    }
    ctx->pc = 0x1D0BB0u;
label_1d0bb0:
    // 0x1d0bb0: 0x2404000c  addiu       $a0, $zero, 0xC
    ctx->pc = 0x1d0bb0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
    // 0x1d0bb4: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D0BB4u;
    SET_GPR_U32(ctx, 31, 0x1D0BBCu);
    ctx->pc = 0x1D0BB8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0BB4u;
            // 0x1d0bb8: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0BBCu; }
        if (ctx->pc != 0x1D0BBCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0BBCu; }
        if (ctx->pc != 0x1D0BBCu) { return; }
    }
    ctx->pc = 0x1D0BBCu;
label_1d0bbc:
    // 0x1d0bbc: 0x24040066  addiu       $a0, $zero, 0x66
    ctx->pc = 0x1d0bbcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1d0bc0: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D0BC0u;
    SET_GPR_U32(ctx, 31, 0x1D0BC8u);
    ctx->pc = 0x1D0BC4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0BC0u;
            // 0x1d0bc4: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0BC8u; }
        if (ctx->pc != 0x1D0BC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0BC8u; }
        if (ctx->pc != 0x1D0BC8u) { return; }
    }
    ctx->pc = 0x1D0BC8u;
label_1d0bc8:
    // 0x1d0bc8: 0x24040062  addiu       $a0, $zero, 0x62
    ctx->pc = 0x1d0bc8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 98));
    // 0x1d0bcc: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D0BCCu;
    SET_GPR_U32(ctx, 31, 0x1D0BD4u);
    ctx->pc = 0x1D0BD0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0BCCu;
            // 0x1d0bd0: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0BD4u; }
        if (ctx->pc != 0x1D0BD4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0BD4u; }
        if (ctx->pc != 0x1D0BD4u) { return; }
    }
    ctx->pc = 0x1D0BD4u;
label_1d0bd4:
    // 0x1d0bd4: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1d0bd4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d0bd8: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D0BD8u;
    SET_GPR_U32(ctx, 31, 0x1D0BE0u);
    ctx->pc = 0x1D0BDCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0BD8u;
            // 0x1d0bdc: 0x24050020  addiu       $a1, $zero, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0BE0u; }
        if (ctx->pc != 0x1D0BE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0BE0u; }
        if (ctx->pc != 0x1D0BE0u) { return; }
    }
    ctx->pc = 0x1D0BE0u;
label_1d0be0:
    // 0x1d0be0: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1d0be0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1d0be4: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D0BE4u;
    SET_GPR_U32(ctx, 31, 0x1D0BECu);
    ctx->pc = 0x1D0BE8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0BE4u;
            // 0x1d0be8: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0BECu; }
        if (ctx->pc != 0x1D0BECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0BECu; }
        if (ctx->pc != 0x1D0BECu) { return; }
    }
    ctx->pc = 0x1D0BECu;
label_1d0bec:
    // 0x1d0bec: 0x3c10003d  lui         $s0, 0x3D
    ctx->pc = 0x1d0becu;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)61 << 16));
    // 0x1d0bf0: 0x24040240  addiu       $a0, $zero, 0x240
    ctx->pc = 0x1d0bf0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 576));
    // 0x1d0bf4: 0x24050008  addiu       $a1, $zero, 0x8
    ctx->pc = 0x1d0bf4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1d0bf8: 0xc06ca9c  jal         func_1B2A70
    ctx->pc = 0x1D0BF8u;
    SET_GPR_U32(ctx, 31, 0x1D0C00u);
    ctx->pc = 0x1D0BFCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0BF8u;
            // 0x1d0bfc: 0x26109230  addiu       $s0, $s0, -0x6DD0 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294939184));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B2A70u;
    if (runtime->hasFunction(0x1B2A70u)) {
        auto targetFn = runtime->lookupFunction(0x1B2A70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0C00u; }
        if (ctx->pc != 0x1D0C00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B2A70_0x1b2a70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0C00u; }
        if (ctx->pc != 0x1D0C00u) { return; }
    }
    ctx->pc = 0x1D0C00u;
label_1d0c00:
    // 0x1d0c00: 0x3c01003d  lui         $at, 0x3D
    ctx->pc = 0x1d0c00u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)61 << 16));
    // 0x1d0c04: 0xac229a38  sw          $v0, -0x65C8($at)
    ctx->pc = 0x1d0c04u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294941240), GPR_U32(ctx, 2));
    // 0x1d0c08: 0x3c01003d  lui         $at, 0x3D
    ctx->pc = 0x1d0c08u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)61 << 16));
    // 0x1d0c0c: 0xac209a48  sw          $zero, -0x65B8($at)
    ctx->pc = 0x1d0c0cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294941256), GPR_U32(ctx, 0));
    // 0x1d0c10: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d0c10u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d0c14: 0x802243d7  lb          $v0, 0x43D7($at)
    ctx->pc = 0x1d0c14u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 17367)));
    // 0x1d0c18: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1D0C18u;
    {
        const bool branch_taken_0x1d0c18 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D0C1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0C18u;
            // 0x1d0c1c: 0x3c050025  lui         $a1, 0x25 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d0c18) {
            ctx->pc = 0x1D0C40u;
            goto label_1d0c40;
        }
    }
    ctx->pc = 0x1D0C20u;
    // 0x1d0c20: 0x322200ff  andi        $v0, $s1, 0xFF
    ctx->pc = 0x1d0c20u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)255);
    // 0x1d0c24: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x1d0c24u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d0c28: 0x22400  sll         $a0, $v0, 16
    ctx->pc = 0x1d0c28u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
    // 0x1d0c2c: 0x2405ffff  addiu       $a1, $zero, -0x1
    ctx->pc = 0x1d0c2cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d0c30: 0xc073844  jal         func_1CE110
    ctx->pc = 0x1D0C30u;
    SET_GPR_U32(ctx, 31, 0x1D0C38u);
    ctx->pc = 0x1D0C34u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0C30u;
            // 0x1d0c34: 0x24070003  addiu       $a3, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CE110u;
    if (runtime->hasFunction(0x1CE110u)) {
        auto targetFn = runtime->lookupFunction(0x1CE110u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0C38u; }
        if (ctx->pc != 0x1D0C38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CE110_0x1ce110(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0C38u; }
        if (ctx->pc != 0x1D0C38u) { return; }
    }
    ctx->pc = 0x1D0C38u;
label_1d0c38:
    // 0x1d0c38: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x1D0C38u;
    {
        const bool branch_taken_0x1d0c38 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D0C3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0C38u;
            // 0x1d0c3c: 0xdfbf0020  ld          $ra, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d0c38) {
            ctx->pc = 0x1D0C6Cu;
            goto label_1d0c6c;
        }
    }
    ctx->pc = 0x1D0C40u;
label_1d0c40:
    // 0x1d0c40: 0x322600ff  andi        $a2, $s1, 0xFF
    ctx->pc = 0x1d0c40u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)255);
    // 0x1d0c44: 0x27a40030  addiu       $a0, $sp, 0x30
    ctx->pc = 0x1d0c44u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1d0c48: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D0C48u;
    SET_GPR_U32(ctx, 31, 0x1D0C50u);
    ctx->pc = 0x1D0C4Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0C48u;
            // 0x1d0c4c: 0x24a56248  addiu       $a1, $a1, 0x6248 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 25160));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0C50u; }
        if (ctx->pc != 0x1D0C50u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0C50u; }
        if (ctx->pc != 0x1D0C50u) { return; }
    }
    ctx->pc = 0x1D0C50u;
label_1d0c50:
    // 0x1d0c50: 0x3c020001  lui         $v0, 0x1
    ctx->pc = 0x1d0c50u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)1 << 16));
    // 0x1d0c54: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1d0c54u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d0c58: 0x27a40030  addiu       $a0, $sp, 0x30
    ctx->pc = 0x1d0c58u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1d0c5c: 0x24062a00  addiu       $a2, $zero, 0x2A00
    ctx->pc = 0x1d0c5cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 10752));
    // 0x1d0c60: 0xc06aab4  jal         func_1AAAD0
    ctx->pc = 0x1D0C60u;
    SET_GPR_U32(ctx, 31, 0x1D0C68u);
    ctx->pc = 0x1D0C64u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0C60u;
            // 0x1d0c64: 0x34470003  ori         $a3, $v0, 0x3 (Delay Slot)
        SET_GPR_U64(ctx, 7, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)3);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AAAD0u;
    if (runtime->hasFunction(0x1AAAD0u)) {
        auto targetFn = runtime->lookupFunction(0x1AAAD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0C68u; }
        if (ctx->pc != 0x1D0C68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AAAD0_0x1aaad0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0C68u; }
        if (ctx->pc != 0x1D0C68u) { return; }
    }
    ctx->pc = 0x1D0C68u;
label_1d0c68:
    // 0x1d0c68: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1d0c68u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_1d0c6c:
    // 0x1d0c6c: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d0c6cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d0c70: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d0c70u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d0c74: 0x3e00008  jr          $ra
    ctx->pc = 0x1D0C74u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D0C78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0C74u;
            // 0x1d0c78: 0x27bd0130  addiu       $sp, $sp, 0x130 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 304));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D06E0u: goto label_1d06e0;
            case 0x1D0754u: goto label_1d0754;
            case 0x1D0760u: goto label_1d0760;
            case 0x1D076Cu: goto label_1d076c;
            case 0x1D0778u: goto label_1d0778;
            case 0x1D0784u: goto label_1d0784;
            case 0x1D0790u: goto label_1d0790;
            case 0x1D079Cu: goto label_1d079c;
            case 0x1D07A8u: goto label_1d07a8;
            case 0x1D07C0u: goto label_1d07c0;
            case 0x1D07DCu: goto label_1d07dc;
            case 0x1D0840u: goto label_1d0840;
            case 0x1D0848u: goto label_1d0848;
            case 0x1D0858u: goto label_1d0858;
            case 0x1D0860u: goto label_1d0860;
            case 0x1D0870u: goto label_1d0870;
            case 0x1D089Cu: goto label_1d089c;
            case 0x1D08C8u: goto label_1d08c8;
            case 0x1D08E4u: goto label_1d08e4;
            case 0x1D08F8u: goto label_1d08f8;
            case 0x1D0960u: goto label_1d0960;
            case 0x1D0964u: goto label_1d0964;
            case 0x1D0998u: goto label_1d0998;
            case 0x1D09A4u: goto label_1d09a4;
            case 0x1D09C8u: goto label_1d09c8;
            case 0x1D09D0u: goto label_1d09d0;
            case 0x1D09D8u: goto label_1d09d8;
            case 0x1D09FCu: goto label_1d09fc;
            case 0x1D0A3Cu: goto label_1d0a3c;
            case 0x1D0A4Cu: goto label_1d0a4c;
            case 0x1D0A50u: goto label_1d0a50;
            case 0x1D0ABCu: goto label_1d0abc;
            case 0x1D0AC4u: goto label_1d0ac4;
            case 0x1D0AD8u: goto label_1d0ad8;
            case 0x1D0AECu: goto label_1d0aec;
            case 0x1D0B20u: goto label_1d0b20;
            case 0x1D0B34u: goto label_1d0b34;
            case 0x1D0B40u: goto label_1d0b40;
            case 0x1D0B54u: goto label_1d0b54;
            case 0x1D0B8Cu: goto label_1d0b8c;
            case 0x1D0B98u: goto label_1d0b98;
            case 0x1D0BA4u: goto label_1d0ba4;
            case 0x1D0BB0u: goto label_1d0bb0;
            case 0x1D0BBCu: goto label_1d0bbc;
            case 0x1D0BC8u: goto label_1d0bc8;
            case 0x1D0BD4u: goto label_1d0bd4;
            case 0x1D0BE0u: goto label_1d0be0;
            case 0x1D0BECu: goto label_1d0bec;
            case 0x1D0C00u: goto label_1d0c00;
            case 0x1D0C38u: goto label_1d0c38;
            case 0x1D0C40u: goto label_1d0c40;
            case 0x1D0C50u: goto label_1d0c50;
            case 0x1D0C68u: goto label_1d0c68;
            case 0x1D0C6Cu: goto label_1d0c6c;
            case 0x1D0CC4u: goto label_1d0cc4;
            case 0x1D0CD0u: goto label_1d0cd0;
            case 0x1D0CDCu: goto label_1d0cdc;
            case 0x1D0CE8u: goto label_1d0ce8;
            case 0x1D0CF4u: goto label_1d0cf4;
            case 0x1D0D00u: goto label_1d0d00;
            case 0x1D0D0Cu: goto label_1d0d0c;
            case 0x1D0D18u: goto label_1d0d18;
            case 0x1D0D38u: goto label_1d0d38;
            case 0x1D0D6Cu: goto label_1d0d6c;
            case 0x1D0DB4u: goto label_1d0db4;
            case 0x1D0DF8u: goto label_1d0df8;
            case 0x1D0E0Cu: goto label_1d0e0c;
            case 0x1D0E14u: goto label_1d0e14;
            case 0x1D0E38u: goto label_1d0e38;
            case 0x1D0E44u: goto label_1d0e44;
            case 0x1D0E48u: goto label_1d0e48;
            case 0x1D0E70u: goto label_1d0e70;
            case 0x1D0EA8u: goto label_1d0ea8;
            case 0x1D0EFCu: goto label_1d0efc;
            case 0x1D0F04u: goto label_1d0f04;
            case 0x1D0F0Cu: goto label_1d0f0c;
            case 0x1D0F38u: goto label_1d0f38;
            case 0x1D0F40u: goto label_1d0f40;
            case 0x1D0F5Cu: goto label_1d0f5c;
            case 0x1D0F78u: goto label_1d0f78;
            case 0x1D0F94u: goto label_1d0f94;
            case 0x1D0F9Cu: goto label_1d0f9c;
            case 0x1D0FBCu: goto label_1d0fbc;
            case 0x1D0FC4u: goto label_1d0fc4;
            case 0x1D0FE4u: goto label_1d0fe4;
            case 0x1D1004u: goto label_1d1004;
            case 0x1D100Cu: goto label_1d100c;
            case 0x1D1048u: goto label_1d1048;
            case 0x1D1054u: goto label_1d1054;
            case 0x1D1060u: goto label_1d1060;
            case 0x1D106Cu: goto label_1d106c;
            case 0x1D1078u: goto label_1d1078;
            case 0x1D1084u: goto label_1d1084;
            case 0x1D1090u: goto label_1d1090;
            case 0x1D109Cu: goto label_1d109c;
            case 0x1D10A8u: goto label_1d10a8;
            case 0x1D10B4u: goto label_1d10b4;
            case 0x1D10C8u: goto label_1d10c8;
            case 0x1D1100u: goto label_1d1100;
            case 0x1D1108u: goto label_1d1108;
            case 0x1D1114u: goto label_1d1114;
            case 0x1D112Cu: goto label_1d112c;
            case 0x1D1144u: goto label_1d1144;
            case 0x1D1190u: goto label_1d1190;
            case 0x1D11A8u: goto label_1d11a8;
            case 0x1D11D0u: goto label_1d11d0;
            case 0x1D11D4u: goto label_1d11d4;
            case 0x1D11E8u: goto label_1d11e8;
            case 0x1D1200u: goto label_1d1200;
            case 0x1D120Cu: goto label_1d120c;
            case 0x1D123Cu: goto label_1d123c;
            case 0x1D1248u: goto label_1d1248;
            case 0x1D1254u: goto label_1d1254;
            case 0x1D1260u: goto label_1d1260;
            case 0x1D126Cu: goto label_1d126c;
            case 0x1D1278u: goto label_1d1278;
            case 0x1D1284u: goto label_1d1284;
            case 0x1D1290u: goto label_1d1290;
            case 0x1D129Cu: goto label_1d129c;
            case 0x1D12A8u: goto label_1d12a8;
            case 0x1D12B8u: goto label_1d12b8;
            case 0x1D12D4u: goto label_1d12d4;
            case 0x1D12E8u: goto label_1d12e8;
            case 0x1D1308u: goto label_1d1308;
            case 0x1D1368u: goto label_1d1368;
            case 0x1D1370u: goto label_1d1370;
            case 0x1D1388u: goto label_1d1388;
            case 0x1D139Cu: goto label_1d139c;
            case 0x1D13A0u: goto label_1d13a0;
            case 0x1D13B4u: goto label_1d13b4;
            case 0x1D141Cu: goto label_1d141c;
            case 0x1D1428u: goto label_1d1428;
            case 0x1D1434u: goto label_1d1434;
            case 0x1D1440u: goto label_1d1440;
            case 0x1D144Cu: goto label_1d144c;
            case 0x1D1458u: goto label_1d1458;
            case 0x1D1464u: goto label_1d1464;
            case 0x1D1470u: goto label_1d1470;
            case 0x1D147Cu: goto label_1d147c;
            case 0x1D148Cu: goto label_1d148c;
            case 0x1D14C4u: goto label_1d14c4;
            case 0x1D14CCu: goto label_1d14cc;
            case 0x1D14DCu: goto label_1d14dc;
            case 0x1D14E0u: goto label_1d14e0;
            case 0x1D1570u: goto label_1d1570;
            case 0x1D15ACu: goto label_1d15ac;
            case 0x1D15F4u: goto label_1d15f4;
            case 0x1D1604u: goto label_1d1604;
            case 0x1D160Cu: goto label_1d160c;
            case 0x1D163Cu: goto label_1d163c;
            case 0x1D1654u: goto label_1d1654;
            case 0x1D165Cu: goto label_1d165c;
            case 0x1D1670u: goto label_1d1670;
            case 0x1D1678u: goto label_1d1678;
            case 0x1D1688u: goto label_1d1688;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D0C7Cu;
    // 0x1d0c7c: 0x0  nop
    ctx->pc = 0x1d0c7cu;
    // NOP
    // 0x1d0c80: 0x27bdfe90  addiu       $sp, $sp, -0x170
    ctx->pc = 0x1d0c80u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966928));
    // 0x1d0c84: 0x3c010057  lui         $at, 0x57
    ctx->pc = 0x1d0c84u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)87 << 16));
    // 0x1d0c88: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x1d0c88u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x1d0c8c: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1d0c8cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1d0c90: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1d0c90u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1d0c94: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1d0c94u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1d0c98: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x1d0c98u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d0c9c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d0c9cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d0ca0: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x1d0ca0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d0ca4: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d0ca4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d0ca8: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x1d0ca8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d0cac: 0x902397b8  lbu         $v1, -0x6848($at)
    ctx->pc = 0x1d0cacu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294940600)));
    // 0x1d0cb0: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x1d0cb0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1d0cb4: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1d0cb4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1d0cb8: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x1d0cb8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x1d0cbc: 0xc073470  jal         func_1CD1C0
    ctx->pc = 0x1D0CBCu;
    SET_GPR_U32(ctx, 31, 0x1D0CC4u);
    ctx->pc = 0x1D0CC0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0CBCu;
            // 0x1d0cc0: 0x24442100  addiu       $a0, $v0, 0x2100 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 8448));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CD1C0u;
    if (runtime->hasFunction(0x1CD1C0u)) {
        auto targetFn = runtime->lookupFunction(0x1CD1C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0CC4u; }
        if (ctx->pc != 0x1D0CC4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CD1C0_0x1cd1c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0CC4u; }
        if (ctx->pc != 0x1D0CC4u) { return; }
    }
    ctx->pc = 0x1D0CC4u;
label_1d0cc4:
    // 0x1d0cc4: 0x24040015  addiu       $a0, $zero, 0x15
    ctx->pc = 0x1d0cc4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 21));
    // 0x1d0cc8: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D0CC8u;
    SET_GPR_U32(ctx, 31, 0x1D0CD0u);
    ctx->pc = 0x1D0CCCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0CC8u;
            // 0x1d0ccc: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0CD0u; }
        if (ctx->pc != 0x1D0CD0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0CD0u; }
        if (ctx->pc != 0x1D0CD0u) { return; }
    }
    ctx->pc = 0x1D0CD0u;
label_1d0cd0:
    // 0x1d0cd0: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1d0cd0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d0cd4: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D0CD4u;
    SET_GPR_U32(ctx, 31, 0x1D0CDCu);
    ctx->pc = 0x1D0CD8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0CD4u;
            // 0x1d0cd8: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0CDCu; }
        if (ctx->pc != 0x1D0CDCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0CDCu; }
        if (ctx->pc != 0x1D0CDCu) { return; }
    }
    ctx->pc = 0x1D0CDCu;
label_1d0cdc:
    // 0x1d0cdc: 0x24040012  addiu       $a0, $zero, 0x12
    ctx->pc = 0x1d0cdcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 18));
    // 0x1d0ce0: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D0CE0u;
    SET_GPR_U32(ctx, 31, 0x1D0CE8u);
    ctx->pc = 0x1D0CE4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0CE0u;
            // 0x1d0ce4: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0CE8u; }
        if (ctx->pc != 0x1D0CE8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0CE8u; }
        if (ctx->pc != 0x1D0CE8u) { return; }
    }
    ctx->pc = 0x1D0CE8u;
label_1d0ce8:
    // 0x1d0ce8: 0x24040062  addiu       $a0, $zero, 0x62
    ctx->pc = 0x1d0ce8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 98));
    // 0x1d0cec: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D0CECu;
    SET_GPR_U32(ctx, 31, 0x1D0CF4u);
    ctx->pc = 0x1D0CF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0CECu;
            // 0x1d0cf0: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0CF4u; }
        if (ctx->pc != 0x1D0CF4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0CF4u; }
        if (ctx->pc != 0x1D0CF4u) { return; }
    }
    ctx->pc = 0x1D0CF4u;
label_1d0cf4:
    // 0x1d0cf4: 0x2404000c  addiu       $a0, $zero, 0xC
    ctx->pc = 0x1d0cf4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
    // 0x1d0cf8: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D0CF8u;
    SET_GPR_U32(ctx, 31, 0x1D0D00u);
    ctx->pc = 0x1D0CFCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0CF8u;
            // 0x1d0cfc: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0D00u; }
        if (ctx->pc != 0x1D0D00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0D00u; }
        if (ctx->pc != 0x1D0D00u) { return; }
    }
    ctx->pc = 0x1D0D00u;
label_1d0d00:
    // 0x1d0d00: 0x24040066  addiu       $a0, $zero, 0x66
    ctx->pc = 0x1d0d00u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1d0d04: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D0D04u;
    SET_GPR_U32(ctx, 31, 0x1D0D0Cu);
    ctx->pc = 0x1D0D08u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0D04u;
            // 0x1d0d08: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0D0Cu; }
        if (ctx->pc != 0x1D0D0Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0D0Cu; }
        if (ctx->pc != 0x1D0D0Cu) { return; }
    }
    ctx->pc = 0x1D0D0Cu;
label_1d0d0c:
    // 0x1d0d0c: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1d0d0cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1d0d10: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D0D10u;
    SET_GPR_U32(ctx, 31, 0x1D0D18u);
    ctx->pc = 0x1D0D14u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0D10u;
            // 0x1d0d14: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0D18u; }
        if (ctx->pc != 0x1D0D18u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0D18u; }
        if (ctx->pc != 0x1D0D18u) { return; }
    }
    ctx->pc = 0x1D0D18u;
label_1d0d18:
    // 0x1d0d18: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d0d18u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d0d1c: 0x3c10003c  lui         $s0, 0x3C
    ctx->pc = 0x1d0d1cu;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)60 << 16));
    // 0x1d0d20: 0x802243d7  lb          $v0, 0x43D7($at)
    ctx->pc = 0x1d0d20u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 17367)));
    // 0x1d0d24: 0x14400011  bnez        $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x1D0D24u;
    {
        const bool branch_taken_0x1d0d24 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D0D28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0D24u;
            // 0x1d0d28: 0x2610d5d4  addiu       $s0, $s0, -0x2A2C (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294956500));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d0d24) {
            ctx->pc = 0x1D0D6Cu;
            goto label_1d0d6c;
        }
    }
    ctx->pc = 0x1D0D2Cu;
    // 0x1d0d2c: 0x24040400  addiu       $a0, $zero, 0x400
    ctx->pc = 0x1d0d2cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
    // 0x1d0d30: 0xc06ca9c  jal         func_1B2A70
    ctx->pc = 0x1D0D30u;
    SET_GPR_U32(ctx, 31, 0x1D0D38u);
    ctx->pc = 0x1D0D34u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0D30u;
            // 0x1d0d34: 0x24050007  addiu       $a1, $zero, 0x7 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B2A70u;
    if (runtime->hasFunction(0x1B2A70u)) {
        auto targetFn = runtime->lookupFunction(0x1B2A70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0D38u; }
        if (ctx->pc != 0x1D0D38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B2A70_0x1b2a70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0D38u; }
        if (ctx->pc != 0x1D0D38u) { return; }
    }
    ctx->pc = 0x1D0D38u;
label_1d0d38:
    // 0x1d0d38: 0xae020808  sw          $v0, 0x808($s0)
    ctx->pc = 0x1d0d38u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 2056), GPR_U32(ctx, 2));
    // 0x1d0d3c: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x1d0d3cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d0d40: 0x326200ff  andi        $v0, $s3, 0xFF
    ctx->pc = 0x1d0d40u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 19) & (uint64_t)(uint16_t)255);
    // 0x1d0d44: 0x2405ffff  addiu       $a1, $zero, -0x1
    ctx->pc = 0x1d0d44u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d0d48: 0x22400  sll         $a0, $v0, 16
    ctx->pc = 0x1d0d48u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
    // 0x1d0d4c: 0x24070002  addiu       $a3, $zero, 0x2
    ctx->pc = 0x1d0d4cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1d0d50: 0x324200ff  andi        $v0, $s2, 0xFF
    ctx->pc = 0x1d0d50u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 18) & (uint64_t)(uint16_t)255);
    // 0x1d0d54: 0xae000818  sw          $zero, 0x818($s0)
    ctx->pc = 0x1d0d54u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 2072), GPR_U32(ctx, 0));
    // 0x1d0d58: 0x21a00  sll         $v1, $v0, 8
    ctx->pc = 0x1d0d58u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1d0d5c: 0x322200ff  andi        $v0, $s1, 0xFF
    ctx->pc = 0x1d0d5cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)255);
    // 0x1d0d60: 0x831825  or          $v1, $a0, $v1
    ctx->pc = 0x1d0d60u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x1d0d64: 0xc073844  jal         func_1CE110
    ctx->pc = 0x1D0D64u;
    SET_GPR_U32(ctx, 31, 0x1D0D6Cu);
    ctx->pc = 0x1D0D68u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0D64u;
            // 0x1d0d68: 0x432025  or          $a0, $v0, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CE110u;
    if (runtime->hasFunction(0x1CE110u)) {
        auto targetFn = runtime->lookupFunction(0x1CE110u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0D6Cu; }
        if (ctx->pc != 0x1D0D6Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CE110_0x1ce110(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0D6Cu; }
        if (ctx->pc != 0x1D0D6Cu) { return; }
    }
    ctx->pc = 0x1D0D6Cu;
label_1d0d6c:
    // 0x1d0d6c: 0x3c03003c  lui         $v1, 0x3C
    ctx->pc = 0x1d0d6cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)60 << 16));
    // 0x1d0d70: 0x3c140039  lui         $s4, 0x39
    ctx->pc = 0x1d0d70u;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)57 << 16));
    // 0x1d0d74: 0x2463d5d4  addiu       $v1, $v1, -0x2A2C
    ctx->pc = 0x1d0d74u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294956500));
    // 0x1d0d78: 0x3c010039  lui         $at, 0x39
    ctx->pc = 0x1d0d78u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)57 << 16));
    // 0x1d0d7c: 0xac2326b4  sw          $v1, 0x26B4($at)
    ctx->pc = 0x1d0d7cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 9908), GPR_U32(ctx, 3));
    // 0x1d0d80: 0x2694269c  addiu       $s4, $s4, 0x269C
    ctx->pc = 0x1d0d80u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 9884));
    // 0x1d0d84: 0xae830018  sw          $v1, 0x18($s4)
    ctx->pc = 0x1d0d84u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 24), GPR_U32(ctx, 3));
    // 0x1d0d88: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d0d88u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d0d8c: 0x8c23440c  lw          $v1, 0x440C($at)
    ctx->pc = 0x1d0d8cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1d0d90: 0x3c020020  lui         $v0, 0x20
    ctx->pc = 0x1d0d90u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32 << 16));
    // 0x1d0d94: 0x27a40060  addiu       $a0, $sp, 0x60
    ctx->pc = 0x1d0d94u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
    // 0x1d0d98: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1d0d98u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d0d9c: 0x24060100  addiu       $a2, $zero, 0x100
    ctx->pc = 0x1d0d9cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 256));
    // 0x1d0da0: 0xae800020  sw          $zero, 0x20($s4)
    ctx->pc = 0x1d0da0u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 32), GPR_U32(ctx, 0));
    // 0x1d0da4: 0x629821  addu        $s3, $v1, $v0
    ctx->pc = 0x1d0da4u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1d0da8: 0xae800024  sw          $zero, 0x24($s4)
    ctx->pc = 0x1d0da8u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 36), GPR_U32(ctx, 0));
    // 0x1d0dac: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1D0DACu;
    SET_GPR_U32(ctx, 31, 0x1D0DB4u);
    ctx->pc = 0x1D0DB0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0DACu;
            // 0x1d0db0: 0xae800028  sw          $zero, 0x28($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 40), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0DB4u; }
        if (ctx->pc != 0x1D0DB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0DB4u; }
        if (ctx->pc != 0x1D0DB4u) { return; }
    }
    ctx->pc = 0x1D0DB4u;
label_1d0db4:
    // 0x1d0db4: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d0db4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d0db8: 0x802243d7  lb          $v0, 0x43D7($at)
    ctx->pc = 0x1d0db8u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 17367)));
    // 0x1d0dbc: 0x14400015  bnez        $v0, . + 4 + (0x15 << 2)
    ctx->pc = 0x1D0DBCu;
    {
        const bool branch_taken_0x1d0dbc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D0DC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0DBCu;
            // 0x1d0dc0: 0x3c010032  lui         $at, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d0dbc) {
            ctx->pc = 0x1D0E14u;
            goto label_1d0e14;
        }
    }
    ctx->pc = 0x1D0DC4u;
    // 0x1d0dc4: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d0dc4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d0dc8: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1d0dc8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1d0dcc: 0x942743da  lhu         $a3, 0x43DA($at)
    ctx->pc = 0x1d0dccu;
    SET_GPR_U32(ctx, 7, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17370)));
    // 0x1d0dd0: 0x27a40060  addiu       $a0, $sp, 0x60
    ctx->pc = 0x1d0dd0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
    // 0x1d0dd4: 0x24a56260  addiu       $a1, $a1, 0x6260
    ctx->pc = 0x1d0dd4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 25184));
    // 0x1d0dd8: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d0dd8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d0ddc: 0x942943dc  lhu         $t1, 0x43DC($at)
    ctx->pc = 0x1d0ddcu;
    SET_GPR_U32(ctx, 9, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17372)));
    // 0x1d0de0: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d0de0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d0de4: 0x942a43de  lhu         $t2, 0x43DE($at)
    ctx->pc = 0x1d0de4u;
    SET_GPR_U32(ctx, 10, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17374)));
    // 0x1d0de8: 0x3c010039  lui         $at, 0x39
    ctx->pc = 0x1d0de8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)57 << 16));
    // 0x1d0dec: 0x8c268b58  lw          $a2, -0x74A8($at)
    ctx->pc = 0x1d0decu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294937432)));
    // 0x1d0df0: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D0DF0u;
    SET_GPR_U32(ctx, 31, 0x1D0DF8u);
    ctx->pc = 0x1D0DF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0DF0u;
            // 0x1d0df4: 0xe0402d  daddu       $t0, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0DF8u; }
        if (ctx->pc != 0x1D0DF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0DF8u; }
        if (ctx->pc != 0x1D0DF8u) { return; }
    }
    ctx->pc = 0x1D0DF8u;
label_1d0df8:
    // 0x1d0df8: 0x27a40060  addiu       $a0, $sp, 0x60
    ctx->pc = 0x1d0df8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
    // 0x1d0dfc: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x1d0dfcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d0e00: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x1d0e00u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d0e04: 0xc07323c  jal         func_1CC8F0
    ctx->pc = 0x1D0E04u;
    SET_GPR_U32(ctx, 31, 0x1D0E0Cu);
    ctx->pc = 0x1D0E08u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0E04u;
            // 0x1d0e08: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CC8F0u;
    if (runtime->hasFunction(0x1CC8F0u)) {
        auto targetFn = runtime->lookupFunction(0x1CC8F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0E0Cu; }
        if (ctx->pc != 0x1D0E0Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0E0Cu; }
        if (ctx->pc != 0x1D0E0Cu) { return; }
    }
    ctx->pc = 0x1D0E0Cu;
label_1d0e0c:
    // 0x1d0e0c: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x1D0E0Cu;
    {
        const bool branch_taken_0x1d0e0c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D0E10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0E0Cu;
            // 0x1d0e10: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d0e0c) {
            ctx->pc = 0x1D0E48u;
            goto label_1d0e48;
        }
    }
    ctx->pc = 0x1D0E14u;
label_1d0e14:
    // 0x1d0e14: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1d0e14u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1d0e18: 0x942643da  lhu         $a2, 0x43DA($at)
    ctx->pc = 0x1d0e18u;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17370)));
    // 0x1d0e1c: 0x27a40060  addiu       $a0, $sp, 0x60
    ctx->pc = 0x1d0e1cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
    // 0x1d0e20: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d0e20u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d0e24: 0x942743dc  lhu         $a3, 0x43DC($at)
    ctx->pc = 0x1d0e24u;
    SET_GPR_U32(ctx, 7, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17372)));
    // 0x1d0e28: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d0e28u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d0e2c: 0x942843de  lhu         $t0, 0x43DE($at)
    ctx->pc = 0x1d0e2cu;
    SET_GPR_U32(ctx, 8, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17374)));
    // 0x1d0e30: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D0E30u;
    SET_GPR_U32(ctx, 31, 0x1D0E38u);
    ctx->pc = 0x1D0E34u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0E30u;
            // 0x1d0e34: 0x24a56280  addiu       $a1, $a1, 0x6280 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 25216));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0E38u; }
        if (ctx->pc != 0x1D0E38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0E38u; }
        if (ctx->pc != 0x1D0E38u) { return; }
    }
    ctx->pc = 0x1D0E38u;
label_1d0e38:
    // 0x1d0e38: 0x27a40060  addiu       $a0, $sp, 0x60
    ctx->pc = 0x1d0e38u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
    // 0x1d0e3c: 0xc06a8f8  jal         func_1AA3E0
    ctx->pc = 0x1D0E3Cu;
    SET_GPR_U32(ctx, 31, 0x1D0E44u);
    ctx->pc = 0x1D0E40u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0E3Cu;
            // 0x1d0e40: 0x260282d  daddu       $a1, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AA3E0u;
    if (runtime->hasFunction(0x1AA3E0u)) {
        auto targetFn = runtime->lookupFunction(0x1AA3E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0E44u; }
        if (ctx->pc != 0x1D0E44u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AA3E0_0x1aa3e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0E44u; }
        if (ctx->pc != 0x1D0E44u) { return; }
    }
    ctx->pc = 0x1D0E44u;
label_1d0e44:
    // 0x1d0e44: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1d0e44u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_1d0e48:
    // 0x1d0e48: 0x12000070  beqz        $s0, . + 4 + (0x70 << 2)
    ctx->pc = 0x1D0E48u;
    {
        const bool branch_taken_0x1d0e48 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d0e48) {
            ctx->pc = 0x1D100Cu;
            goto label_1d100c;
        }
    }
    ctx->pc = 0x1D0E50u;
    // 0x1d0e50: 0x8e720000  lw          $s2, 0x0($s3)
    ctx->pc = 0x1d0e50u;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1d0e54: 0x3c040039  lui         $a0, 0x39
    ctx->pc = 0x1d0e54u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)57 << 16));
    // 0x1d0e58: 0x24842630  addiu       $a0, $a0, 0x2630
    ctx->pc = 0x1d0e58u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 9776));
    // 0x1d0e5c: 0x26730004  addiu       $s3, $s3, 0x4
    ctx->pc = 0x1d0e5cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4));
    // 0x1d0e60: 0x1288c0  sll         $s1, $s2, 3
    ctx->pc = 0x1d0e60u;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 18), 3));
    // 0x1d0e64: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x1d0e64u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d0e68: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1D0E68u;
    SET_GPR_U32(ctx, 31, 0x1D0E70u);
    ctx->pc = 0x1D0E6Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0E68u;
            // 0x1d0e6c: 0x220302d  daddu       $a2, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0E70u; }
        if (ctx->pc != 0x1D0E70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0E70u; }
        if (ctx->pc != 0x1D0E70u) { return; }
    }
    ctx->pc = 0x1D0E70u;
label_1d0e70:
    // 0x1d0e70: 0x2402fffc  addiu       $v0, $zero, -0x4
    ctx->pc = 0x1d0e70u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967292));
    // 0x1d0e74: 0x3c040039  lui         $a0, 0x39
    ctx->pc = 0x1d0e74u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)57 << 16));
    // 0x1d0e78: 0x2221024  and         $v0, $s1, $v0
    ctx->pc = 0x1d0e78u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & GPR_U64(ctx, 2));
    // 0x1d0e7c: 0x24842010  addiu       $a0, $a0, 0x2010
    ctx->pc = 0x1d0e7cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 8208));
    // 0x1d0e80: 0x2629821  addu        $s3, $s3, $v0
    ctx->pc = 0x1d0e80u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 2)));
    // 0x1d0e84: 0x8e620000  lw          $v0, 0x0($s3)
    ctx->pc = 0x1d0e84u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1d0e88: 0xae820028  sw          $v0, 0x28($s4)
    ctx->pc = 0x1d0e88u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 40), GPR_U32(ctx, 2));
    // 0x1d0e8c: 0x26730004  addiu       $s3, $s3, 0x4
    ctx->pc = 0x1d0e8cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4));
    // 0x1d0e90: 0x8e830028  lw          $v1, 0x28($s4)
    ctx->pc = 0x1d0e90u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 40)));
    // 0x1d0e94: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x1d0e94u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d0e98: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x1d0e98u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1d0e9c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1d0e9cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1d0ea0: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1D0EA0u;
    SET_GPR_U32(ctx, 31, 0x1D0EA8u);
    ctx->pc = 0x1D0EA4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0EA0u;
            // 0x1d0ea4: 0x23080  sll         $a2, $v0, 2 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0EA8u; }
        if (ctx->pc != 0x1D0EA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0EA8u; }
        if (ctx->pc != 0x1D0EA8u) { return; }
    }
    ctx->pc = 0x1D0EA8u;
label_1d0ea8:
    // 0x1d0ea8: 0x8e850028  lw          $a1, 0x28($s4)
    ctx->pc = 0x1d0ea8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 40)));
    // 0x1d0eac: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d0eacu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d0eb0: 0x2403fffc  addiu       $v1, $zero, -0x4
    ctx->pc = 0x1d0eb0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967292));
    // 0x1d0eb4: 0x84224200  lh          $v0, 0x4200($at)
    ctx->pc = 0x1d0eb4u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 1), 16896)));
    // 0x1d0eb8: 0x52040  sll         $a0, $a1, 1
    ctx->pc = 0x1d0eb8u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
    // 0x1d0ebc: 0x852021  addu        $a0, $a0, $a1
    ctx->pc = 0x1d0ebcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
    // 0x1d0ec0: 0x42080  sll         $a0, $a0, 2
    ctx->pc = 0x1d0ec0u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1d0ec4: 0x831824  and         $v1, $a0, $v1
    ctx->pc = 0x1d0ec4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) & GPR_U64(ctx, 3));
    // 0x1d0ec8: 0x2639821  addu        $s3, $s3, $v1
    ctx->pc = 0x1d0ec8u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 3)));
    // 0x1d0ecc: 0x8e710000  lw          $s1, 0x0($s3)
    ctx->pc = 0x1d0eccu;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1d0ed0: 0x1040003c  beqz        $v0, . + 4 + (0x3C << 2)
    ctx->pc = 0x1D0ED0u;
    {
        const bool branch_taken_0x1d0ed0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D0ED4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0ED0u;
            // 0x1d0ed4: 0x26730004  addiu       $s3, $s3, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d0ed0) {
            ctx->pc = 0x1D0FC4u;
            goto label_1d0fc4;
        }
    }
    ctx->pc = 0x1D0ED8u;
    // 0x1d0ed8: 0x2a210021  slti        $at, $s1, 0x21
    ctx->pc = 0x1d0ed8u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)33) ? 1 : 0);
    // 0x1d0edc: 0x1020002f  beqz        $at, . + 4 + (0x2F << 2)
    ctx->pc = 0x1D0EDCu;
    {
        const bool branch_taken_0x1d0edc = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d0edc) {
            ctx->pc = 0x1D0F9Cu;
            goto label_1d0f9c;
        }
    }
    ctx->pc = 0x1D0EE4u;
    // 0x1d0ee4: 0x34018001  ori         $at, $zero, 0x8001
    ctx->pc = 0x1d0ee4u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32769);
    // 0x1d0ee8: 0x201082b  sltu        $at, $s0, $at
    ctx->pc = 0x1d0ee8u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)GPR_U64(ctx, 1)) ? 1 : 0);
    // 0x1d0eec: 0x14200033  bnez        $at, . + 4 + (0x33 << 2)
    ctx->pc = 0x1D0EECu;
    {
        const bool branch_taken_0x1d0eec = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D0EF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0EECu;
            // 0x1d0ef0: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d0eec) {
            ctx->pc = 0x1D0FBCu;
            goto label_1d0fbc;
        }
    }
    ctx->pc = 0x1D0EF4u;
    // 0x1d0ef4: 0x10000029  b           . + 4 + (0x29 << 2)
    ctx->pc = 0x1D0EF4u;
    {
        const bool branch_taken_0x1d0ef4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d0ef4) {
            ctx->pc = 0x1D0F9Cu;
            goto label_1d0f9c;
        }
    }
    ctx->pc = 0x1D0EFCu;
label_1d0efc:
    // 0x1d0efc: 0xc06c1bc  jal         func_1B06F0
    ctx->pc = 0x1D0EFCu;
    SET_GPR_U32(ctx, 31, 0x1D0F04u);
    ctx->pc = 0x1B06F0u;
    if (runtime->hasFunction(0x1B06F0u)) {
        auto targetFn = runtime->lookupFunction(0x1B06F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0F04u; }
        if (ctx->pc != 0x1D0F04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B06F0_0x1b06f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0F04u; }
        if (ctx->pc != 0x1D0F04u) { return; }
    }
    ctx->pc = 0x1D0F04u;
label_1d0f04:
    // 0x1d0f04: 0xc06bda8  jal         func_1AF6A0
    ctx->pc = 0x1D0F04u;
    SET_GPR_U32(ctx, 31, 0x1D0F0Cu);
    ctx->pc = 0x1D0F08u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0F04u;
            // 0x1d0f08: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF6A0u;
    if (runtime->hasFunction(0x1AF6A0u)) {
        auto targetFn = runtime->lookupFunction(0x1AF6A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0F0Cu; }
        if (ctx->pc != 0x1D0F0Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF6A0_0x1af6a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0F0Cu; }
        if (ctx->pc != 0x1D0F0Cu) { return; }
    }
    ctx->pc = 0x1D0F0Cu;
label_1d0f0c:
    // 0x1d0f0c: 0x2a210021  slti        $at, $s1, 0x21
    ctx->pc = 0x1d0f0cu;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)33) ? 1 : 0);
    // 0x1d0f10: 0x1420000b  bnez        $at, . + 4 + (0xB << 2)
    ctx->pc = 0x1D0F10u;
    {
        const bool branch_taken_0x1d0f10 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D0F14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0F10u;
            // 0x1d0f14: 0x3c080025  lui         $t0, 0x25 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)37 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d0f10) {
            ctx->pc = 0x1D0F40u;
            goto label_1d0f40;
        }
    }
    ctx->pc = 0x1D0F18u;
    // 0x1d0f18: 0x3c080025  lui         $t0, 0x25
    ctx->pc = 0x1d0f18u;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)37 << 16));
    // 0x1d0f1c: 0x2404000d  addiu       $a0, $zero, 0xD
    ctx->pc = 0x1d0f1cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 13));
    // 0x1d0f20: 0x2405000a  addiu       $a1, $zero, 0xA
    ctx->pc = 0x1d0f20u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x1d0f24: 0x24060002  addiu       $a2, $zero, 0x2
    ctx->pc = 0x1d0f24u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1d0f28: 0x2407ffff  addiu       $a3, $zero, -0x1
    ctx->pc = 0x1d0f28u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d0f2c: 0x250862a0  addiu       $t0, $t0, 0x62A0
    ctx->pc = 0x1d0f2cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 25248));
    // 0x1d0f30: 0xc06cda0  jal         func_1B3680
    ctx->pc = 0x1D0F30u;
    SET_GPR_U32(ctx, 31, 0x1D0F38u);
    ctx->pc = 0x1D0F34u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0F30u;
            // 0x1d0f34: 0x220482d  daddu       $t1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B3680u;
    if (runtime->hasFunction(0x1B3680u)) {
        auto targetFn = runtime->lookupFunction(0x1B3680u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0F38u; }
        if (ctx->pc != 0x1D0F38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B3680_0x1b3680(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0F38u; }
        if (ctx->pc != 0x1D0F38u) { return; }
    }
    ctx->pc = 0x1D0F38u;
label_1d0f38:
    // 0x1d0f38: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1D0F38u;
    {
        const bool branch_taken_0x1d0f38 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d0f38) {
            ctx->pc = 0x1D0F5Cu;
            goto label_1d0f5c;
        }
    }
    ctx->pc = 0x1D0F40u;
label_1d0f40:
    // 0x1d0f40: 0x2404000d  addiu       $a0, $zero, 0xD
    ctx->pc = 0x1d0f40u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 13));
    // 0x1d0f44: 0x2405000a  addiu       $a1, $zero, 0xA
    ctx->pc = 0x1d0f44u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x1d0f48: 0x24060002  addiu       $a2, $zero, 0x2
    ctx->pc = 0x1d0f48u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1d0f4c: 0x2407ffff  addiu       $a3, $zero, -0x1
    ctx->pc = 0x1d0f4cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d0f50: 0x250862c0  addiu       $t0, $t0, 0x62C0
    ctx->pc = 0x1d0f50u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 25280));
    // 0x1d0f54: 0xc06cda0  jal         func_1B3680
    ctx->pc = 0x1D0F54u;
    SET_GPR_U32(ctx, 31, 0x1D0F5Cu);
    ctx->pc = 0x1D0F58u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0F54u;
            // 0x1d0f58: 0x200482d  daddu       $t1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B3680u;
    if (runtime->hasFunction(0x1B3680u)) {
        auto targetFn = runtime->lookupFunction(0x1B3680u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0F5Cu; }
        if (ctx->pc != 0x1D0F5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B3680_0x1b3680(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0F5Cu; }
        if (ctx->pc != 0x1D0F5Cu) { return; }
    }
    ctx->pc = 0x1D0F5Cu;
label_1d0f5c:
    // 0x1d0f5c: 0x3c080025  lui         $t0, 0x25
    ctx->pc = 0x1d0f5cu;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)37 << 16));
    // 0x1d0f60: 0x2404000d  addiu       $a0, $zero, 0xD
    ctx->pc = 0x1d0f60u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 13));
    // 0x1d0f64: 0x2405000b  addiu       $a1, $zero, 0xB
    ctx->pc = 0x1d0f64u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 11));
    // 0x1d0f68: 0x24060002  addiu       $a2, $zero, 0x2
    ctx->pc = 0x1d0f68u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1d0f6c: 0x2407ffff  addiu       $a3, $zero, -0x1
    ctx->pc = 0x1d0f6cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d0f70: 0xc06cda0  jal         func_1B3680
    ctx->pc = 0x1D0F70u;
    SET_GPR_U32(ctx, 31, 0x1D0F78u);
    ctx->pc = 0x1D0F74u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0F70u;
            // 0x1d0f74: 0x250862e0  addiu       $t0, $t0, 0x62E0 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 25312));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B3680u;
    if (runtime->hasFunction(0x1B3680u)) {
        auto targetFn = runtime->lookupFunction(0x1B3680u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0F78u; }
        if (ctx->pc != 0x1D0F78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B3680_0x1b3680(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0F78u; }
        if (ctx->pc != 0x1D0F78u) { return; }
    }
    ctx->pc = 0x1D0F78u;
label_1d0f78:
    // 0x1d0f78: 0x2404000d  addiu       $a0, $zero, 0xD
    ctx->pc = 0x1d0f78u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 13));
    // 0x1d0f7c: 0x3c080025  lui         $t0, 0x25
    ctx->pc = 0x1d0f7cu;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)37 << 16));
    // 0x1d0f80: 0x24060002  addiu       $a2, $zero, 0x2
    ctx->pc = 0x1d0f80u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1d0f84: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x1d0f84u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d0f88: 0x2407ffff  addiu       $a3, $zero, -0x1
    ctx->pc = 0x1d0f88u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d0f8c: 0xc06cda0  jal         func_1B3680
    ctx->pc = 0x1D0F8Cu;
    SET_GPR_U32(ctx, 31, 0x1D0F94u);
    ctx->pc = 0x1D0F90u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0F8Cu;
            // 0x1d0f90: 0x250862f0  addiu       $t0, $t0, 0x62F0 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 25328));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B3680u;
    if (runtime->hasFunction(0x1B3680u)) {
        auto targetFn = runtime->lookupFunction(0x1B3680u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0F94u; }
        if (ctx->pc != 0x1D0F94u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B3680_0x1b3680(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0F94u; }
        if (ctx->pc != 0x1D0F94u) { return; }
    }
    ctx->pc = 0x1D0F94u;
label_1d0f94:
    // 0x1d0f94: 0xc06eabc  jal         func_1BAAF0
    ctx->pc = 0x1D0F94u;
    SET_GPR_U32(ctx, 31, 0x1D0F9Cu);
    ctx->pc = 0x1D0F98u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0F94u;
            // 0x1d0f98: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1BAAF0u;
    if (runtime->hasFunction(0x1BAAF0u)) {
        auto targetFn = runtime->lookupFunction(0x1BAAF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0F9Cu; }
        if (ctx->pc != 0x1D0F9Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BAAF0_0x1baaf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0F9Cu; }
        if (ctx->pc != 0x1D0F9Cu) { return; }
    }
    ctx->pc = 0x1D0F9Cu;
label_1d0f9c:
    // 0x1d0f9c: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d0f9cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d0fa0: 0x8c224300  lw          $v0, 0x4300($at)
    ctx->pc = 0x1d0fa0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17152)));
    // 0x1d0fa4: 0x30428000  andi        $v0, $v0, 0x8000
    ctx->pc = 0x1d0fa4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)32768);
    // 0x1d0fa8: 0x2102b  sltu        $v0, $zero, $v0
    ctx->pc = 0x1d0fa8u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x1d0fac: 0x38420001  xori        $v0, $v0, 0x1
    ctx->pc = 0x1d0facu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)1);
    // 0x1d0fb0: 0x1440ffd2  bnez        $v0, . + 4 + (-0x2E << 2)
    ctx->pc = 0x1D0FB0u;
    {
        const bool branch_taken_0x1d0fb0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d0fb0) {
            ctx->pc = 0x1D0EFCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d0efc;
        }
    }
    ctx->pc = 0x1D0FB8u;
    // 0x1d0fb8: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1d0fb8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1d0fbc:
    // 0x1d0fbc: 0xc06bda8  jal         func_1AF6A0
    ctx->pc = 0x1D0FBCu;
    SET_GPR_U32(ctx, 31, 0x1D0FC4u);
    ctx->pc = 0x1AF6A0u;
    if (runtime->hasFunction(0x1AF6A0u)) {
        auto targetFn = runtime->lookupFunction(0x1AF6A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0FC4u; }
        if (ctx->pc != 0x1D0FC4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF6A0_0x1af6a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0FC4u; }
        if (ctx->pc != 0x1D0FC4u) { return; }
    }
    ctx->pc = 0x1D0FC4u;
label_1d0fc4:
    // 0x1d0fc4: 0x111040  sll         $v0, $s1, 1
    ctx->pc = 0x1d0fc4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 17), 1));
    // 0x1d0fc8: 0x3c040039  lui         $a0, 0x39
    ctx->pc = 0x1d0fc8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)57 << 16));
    // 0x1d0fcc: 0x511021  addu        $v0, $v0, $s1
    ctx->pc = 0x1d0fccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
    // 0x1d0fd0: 0x24842030  addiu       $a0, $a0, 0x2030
    ctx->pc = 0x1d0fd0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 8240));
    // 0x1d0fd4: 0x28100  sll         $s0, $v0, 4
    ctx->pc = 0x1d0fd4u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x1d0fd8: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x1d0fd8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d0fdc: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1D0FDCu;
    SET_GPR_U32(ctx, 31, 0x1D0FE4u);
    ctx->pc = 0x1D0FE0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0FDCu;
            // 0x1d0fe0: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0FE4u; }
        if (ctx->pc != 0x1D0FE4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0FE4u; }
        if (ctx->pc != 0x1D0FE4u) { return; }
    }
    ctx->pc = 0x1D0FE4u;
label_1d0fe4:
    // 0x1d0fe4: 0x2402fffc  addiu       $v0, $zero, -0x4
    ctx->pc = 0x1d0fe4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967292));
    // 0x1d0fe8: 0x3c06003b  lui         $a2, 0x3B
    ctx->pc = 0x1d0fe8u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)59 << 16));
    // 0x1d0fec: 0x2021024  and         $v0, $s0, $v0
    ctx->pc = 0x1d0fecu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & GPR_U64(ctx, 2));
    // 0x1d0ff0: 0x280282d  daddu       $a1, $s4, $zero
    ctx->pc = 0x1d0ff0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d0ff4: 0x2629821  addu        $s3, $s3, $v0
    ctx->pc = 0x1d0ff4u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 2)));
    // 0x1d0ff8: 0x24c6a6d0  addiu       $a2, $a2, -0x5930
    ctx->pc = 0x1d0ff8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294944464));
    // 0x1d0ffc: 0xc163fb0  jal         func_58FEC0
    ctx->pc = 0x1D0FFCu;
    SET_GPR_U32(ctx, 31, 0x1D1004u);
    ctx->pc = 0x1D1000u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0FFCu;
            // 0x1d1000: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x58FEC0u;
    {
        auto targetFn = runtime->lookupFunction(0x58FEC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1004u; }
        if (ctx->pc != 0x1D1004u) { return; }
    }
    ctx->pc = 0x1D1004u;
label_1d1004:
    // 0x1d1004: 0xae920020  sw          $s2, 0x20($s4)
    ctx->pc = 0x1d1004u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 32), GPR_U32(ctx, 18));
    // 0x1d1008: 0xae910024  sw          $s1, 0x24($s4)
    ctx->pc = 0x1d1008u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 36), GPR_U32(ctx, 17));
label_1d100c:
    // 0x1d100c: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x1d100cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1d1010: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1d1010u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1d1014: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1d1014u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1d1018: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1d1018u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d101c: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d101cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d1020: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d1020u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d1024: 0x3e00008  jr          $ra
    ctx->pc = 0x1D1024u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D1028u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1024u;
            // 0x1d1028: 0x27bd0170  addiu       $sp, $sp, 0x170 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 368));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D06E0u: goto label_1d06e0;
            case 0x1D0754u: goto label_1d0754;
            case 0x1D0760u: goto label_1d0760;
            case 0x1D076Cu: goto label_1d076c;
            case 0x1D0778u: goto label_1d0778;
            case 0x1D0784u: goto label_1d0784;
            case 0x1D0790u: goto label_1d0790;
            case 0x1D079Cu: goto label_1d079c;
            case 0x1D07A8u: goto label_1d07a8;
            case 0x1D07C0u: goto label_1d07c0;
            case 0x1D07DCu: goto label_1d07dc;
            case 0x1D0840u: goto label_1d0840;
            case 0x1D0848u: goto label_1d0848;
            case 0x1D0858u: goto label_1d0858;
            case 0x1D0860u: goto label_1d0860;
            case 0x1D0870u: goto label_1d0870;
            case 0x1D089Cu: goto label_1d089c;
            case 0x1D08C8u: goto label_1d08c8;
            case 0x1D08E4u: goto label_1d08e4;
            case 0x1D08F8u: goto label_1d08f8;
            case 0x1D0960u: goto label_1d0960;
            case 0x1D0964u: goto label_1d0964;
            case 0x1D0998u: goto label_1d0998;
            case 0x1D09A4u: goto label_1d09a4;
            case 0x1D09C8u: goto label_1d09c8;
            case 0x1D09D0u: goto label_1d09d0;
            case 0x1D09D8u: goto label_1d09d8;
            case 0x1D09FCu: goto label_1d09fc;
            case 0x1D0A3Cu: goto label_1d0a3c;
            case 0x1D0A4Cu: goto label_1d0a4c;
            case 0x1D0A50u: goto label_1d0a50;
            case 0x1D0ABCu: goto label_1d0abc;
            case 0x1D0AC4u: goto label_1d0ac4;
            case 0x1D0AD8u: goto label_1d0ad8;
            case 0x1D0AECu: goto label_1d0aec;
            case 0x1D0B20u: goto label_1d0b20;
            case 0x1D0B34u: goto label_1d0b34;
            case 0x1D0B40u: goto label_1d0b40;
            case 0x1D0B54u: goto label_1d0b54;
            case 0x1D0B8Cu: goto label_1d0b8c;
            case 0x1D0B98u: goto label_1d0b98;
            case 0x1D0BA4u: goto label_1d0ba4;
            case 0x1D0BB0u: goto label_1d0bb0;
            case 0x1D0BBCu: goto label_1d0bbc;
            case 0x1D0BC8u: goto label_1d0bc8;
            case 0x1D0BD4u: goto label_1d0bd4;
            case 0x1D0BE0u: goto label_1d0be0;
            case 0x1D0BECu: goto label_1d0bec;
            case 0x1D0C00u: goto label_1d0c00;
            case 0x1D0C38u: goto label_1d0c38;
            case 0x1D0C40u: goto label_1d0c40;
            case 0x1D0C50u: goto label_1d0c50;
            case 0x1D0C68u: goto label_1d0c68;
            case 0x1D0C6Cu: goto label_1d0c6c;
            case 0x1D0CC4u: goto label_1d0cc4;
            case 0x1D0CD0u: goto label_1d0cd0;
            case 0x1D0CDCu: goto label_1d0cdc;
            case 0x1D0CE8u: goto label_1d0ce8;
            case 0x1D0CF4u: goto label_1d0cf4;
            case 0x1D0D00u: goto label_1d0d00;
            case 0x1D0D0Cu: goto label_1d0d0c;
            case 0x1D0D18u: goto label_1d0d18;
            case 0x1D0D38u: goto label_1d0d38;
            case 0x1D0D6Cu: goto label_1d0d6c;
            case 0x1D0DB4u: goto label_1d0db4;
            case 0x1D0DF8u: goto label_1d0df8;
            case 0x1D0E0Cu: goto label_1d0e0c;
            case 0x1D0E14u: goto label_1d0e14;
            case 0x1D0E38u: goto label_1d0e38;
            case 0x1D0E44u: goto label_1d0e44;
            case 0x1D0E48u: goto label_1d0e48;
            case 0x1D0E70u: goto label_1d0e70;
            case 0x1D0EA8u: goto label_1d0ea8;
            case 0x1D0EFCu: goto label_1d0efc;
            case 0x1D0F04u: goto label_1d0f04;
            case 0x1D0F0Cu: goto label_1d0f0c;
            case 0x1D0F38u: goto label_1d0f38;
            case 0x1D0F40u: goto label_1d0f40;
            case 0x1D0F5Cu: goto label_1d0f5c;
            case 0x1D0F78u: goto label_1d0f78;
            case 0x1D0F94u: goto label_1d0f94;
            case 0x1D0F9Cu: goto label_1d0f9c;
            case 0x1D0FBCu: goto label_1d0fbc;
            case 0x1D0FC4u: goto label_1d0fc4;
            case 0x1D0FE4u: goto label_1d0fe4;
            case 0x1D1004u: goto label_1d1004;
            case 0x1D100Cu: goto label_1d100c;
            case 0x1D1048u: goto label_1d1048;
            case 0x1D1054u: goto label_1d1054;
            case 0x1D1060u: goto label_1d1060;
            case 0x1D106Cu: goto label_1d106c;
            case 0x1D1078u: goto label_1d1078;
            case 0x1D1084u: goto label_1d1084;
            case 0x1D1090u: goto label_1d1090;
            case 0x1D109Cu: goto label_1d109c;
            case 0x1D10A8u: goto label_1d10a8;
            case 0x1D10B4u: goto label_1d10b4;
            case 0x1D10C8u: goto label_1d10c8;
            case 0x1D1100u: goto label_1d1100;
            case 0x1D1108u: goto label_1d1108;
            case 0x1D1114u: goto label_1d1114;
            case 0x1D112Cu: goto label_1d112c;
            case 0x1D1144u: goto label_1d1144;
            case 0x1D1190u: goto label_1d1190;
            case 0x1D11A8u: goto label_1d11a8;
            case 0x1D11D0u: goto label_1d11d0;
            case 0x1D11D4u: goto label_1d11d4;
            case 0x1D11E8u: goto label_1d11e8;
            case 0x1D1200u: goto label_1d1200;
            case 0x1D120Cu: goto label_1d120c;
            case 0x1D123Cu: goto label_1d123c;
            case 0x1D1248u: goto label_1d1248;
            case 0x1D1254u: goto label_1d1254;
            case 0x1D1260u: goto label_1d1260;
            case 0x1D126Cu: goto label_1d126c;
            case 0x1D1278u: goto label_1d1278;
            case 0x1D1284u: goto label_1d1284;
            case 0x1D1290u: goto label_1d1290;
            case 0x1D129Cu: goto label_1d129c;
            case 0x1D12A8u: goto label_1d12a8;
            case 0x1D12B8u: goto label_1d12b8;
            case 0x1D12D4u: goto label_1d12d4;
            case 0x1D12E8u: goto label_1d12e8;
            case 0x1D1308u: goto label_1d1308;
            case 0x1D1368u: goto label_1d1368;
            case 0x1D1370u: goto label_1d1370;
            case 0x1D1388u: goto label_1d1388;
            case 0x1D139Cu: goto label_1d139c;
            case 0x1D13A0u: goto label_1d13a0;
            case 0x1D13B4u: goto label_1d13b4;
            case 0x1D141Cu: goto label_1d141c;
            case 0x1D1428u: goto label_1d1428;
            case 0x1D1434u: goto label_1d1434;
            case 0x1D1440u: goto label_1d1440;
            case 0x1D144Cu: goto label_1d144c;
            case 0x1D1458u: goto label_1d1458;
            case 0x1D1464u: goto label_1d1464;
            case 0x1D1470u: goto label_1d1470;
            case 0x1D147Cu: goto label_1d147c;
            case 0x1D148Cu: goto label_1d148c;
            case 0x1D14C4u: goto label_1d14c4;
            case 0x1D14CCu: goto label_1d14cc;
            case 0x1D14DCu: goto label_1d14dc;
            case 0x1D14E0u: goto label_1d14e0;
            case 0x1D1570u: goto label_1d1570;
            case 0x1D15ACu: goto label_1d15ac;
            case 0x1D15F4u: goto label_1d15f4;
            case 0x1D1604u: goto label_1d1604;
            case 0x1D160Cu: goto label_1d160c;
            case 0x1D163Cu: goto label_1d163c;
            case 0x1D1654u: goto label_1d1654;
            case 0x1D165Cu: goto label_1d165c;
            case 0x1D1670u: goto label_1d1670;
            case 0x1D1678u: goto label_1d1678;
            case 0x1D1688u: goto label_1d1688;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D102Cu;
    // 0x1d102c: 0x0  nop
    ctx->pc = 0x1d102cu;
    // NOP
    // 0x1d1030: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1d1030u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1d1034: 0x24042000  addiu       $a0, $zero, 0x2000
    ctx->pc = 0x1d1034u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 8192));
    // 0x1d1038: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1d1038u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1d103c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d103cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d1040: 0xc073470  jal         func_1CD1C0
    ctx->pc = 0x1D1040u;
    SET_GPR_U32(ctx, 31, 0x1D1048u);
    ctx->pc = 0x1D1044u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1040u;
            // 0x1d1044: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CD1C0u;
    if (runtime->hasFunction(0x1CD1C0u)) {
        auto targetFn = runtime->lookupFunction(0x1CD1C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1048u; }
        if (ctx->pc != 0x1D1048u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CD1C0_0x1cd1c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1048u; }
        if (ctx->pc != 0x1D1048u) { return; }
    }
    ctx->pc = 0x1D1048u;
label_1d1048:
    // 0x1d1048: 0x24040015  addiu       $a0, $zero, 0x15
    ctx->pc = 0x1d1048u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 21));
    // 0x1d104c: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D104Cu;
    SET_GPR_U32(ctx, 31, 0x1D1054u);
    ctx->pc = 0x1D1050u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D104Cu;
            // 0x1d1050: 0x24050002  addiu       $a1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1054u; }
        if (ctx->pc != 0x1D1054u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1054u; }
        if (ctx->pc != 0x1D1054u) { return; }
    }
    ctx->pc = 0x1D1054u;
label_1d1054:
    // 0x1d1054: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1d1054u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d1058: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D1058u;
    SET_GPR_U32(ctx, 31, 0x1D1060u);
    ctx->pc = 0x1D105Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1058u;
            // 0x1d105c: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1060u; }
        if (ctx->pc != 0x1D1060u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1060u; }
        if (ctx->pc != 0x1D1060u) { return; }
    }
    ctx->pc = 0x1D1060u;
label_1d1060:
    // 0x1d1060: 0x24040012  addiu       $a0, $zero, 0x12
    ctx->pc = 0x1d1060u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 18));
    // 0x1d1064: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D1064u;
    SET_GPR_U32(ctx, 31, 0x1D106Cu);
    ctx->pc = 0x1D1068u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1064u;
            // 0x1d1068: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D106Cu; }
        if (ctx->pc != 0x1D106Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D106Cu; }
        if (ctx->pc != 0x1D106Cu) { return; }
    }
    ctx->pc = 0x1D106Cu;
label_1d106c:
    // 0x1d106c: 0x24040062  addiu       $a0, $zero, 0x62
    ctx->pc = 0x1d106cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 98));
    // 0x1d1070: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D1070u;
    SET_GPR_U32(ctx, 31, 0x1D1078u);
    ctx->pc = 0x1D1074u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1070u;
            // 0x1d1074: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1078u; }
        if (ctx->pc != 0x1D1078u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1078u; }
        if (ctx->pc != 0x1D1078u) { return; }
    }
    ctx->pc = 0x1D1078u;
label_1d1078:
    // 0x1d1078: 0x2404000c  addiu       $a0, $zero, 0xC
    ctx->pc = 0x1d1078u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
    // 0x1d107c: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D107Cu;
    SET_GPR_U32(ctx, 31, 0x1D1084u);
    ctx->pc = 0x1D1080u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D107Cu;
            // 0x1d1080: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1084u; }
        if (ctx->pc != 0x1D1084u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1084u; }
        if (ctx->pc != 0x1D1084u) { return; }
    }
    ctx->pc = 0x1D1084u;
label_1d1084:
    // 0x1d1084: 0x24040066  addiu       $a0, $zero, 0x66
    ctx->pc = 0x1d1084u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1d1088: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D1088u;
    SET_GPR_U32(ctx, 31, 0x1D1090u);
    ctx->pc = 0x1D108Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1088u;
            // 0x1d108c: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1090u; }
        if (ctx->pc != 0x1D1090u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1090u; }
        if (ctx->pc != 0x1D1090u) { return; }
    }
    ctx->pc = 0x1D1090u;
label_1d1090:
    // 0x1d1090: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1d1090u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1d1094: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D1094u;
    SET_GPR_U32(ctx, 31, 0x1D109Cu);
    ctx->pc = 0x1D1098u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1094u;
            // 0x1d1098: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D109Cu; }
        if (ctx->pc != 0x1D109Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D109Cu; }
        if (ctx->pc != 0x1D109Cu) { return; }
    }
    ctx->pc = 0x1D109Cu;
label_1d109c:
    // 0x1d109c: 0x24040012  addiu       $a0, $zero, 0x12
    ctx->pc = 0x1d109cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 18));
    // 0x1d10a0: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D10A0u;
    SET_GPR_U32(ctx, 31, 0x1D10A8u);
    ctx->pc = 0x1D10A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D10A0u;
            // 0x1d10a4: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D10A8u; }
        if (ctx->pc != 0x1D10A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D10A8u; }
        if (ctx->pc != 0x1D10A8u) { return; }
    }
    ctx->pc = 0x1D10A8u;
label_1d10a8:
    // 0x1d10a8: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1d10a8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d10ac: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D10ACu;
    SET_GPR_U32(ctx, 31, 0x1D10B4u);
    ctx->pc = 0x1D10B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D10ACu;
            // 0x1d10b0: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D10B4u; }
        if (ctx->pc != 0x1D10B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D10B4u; }
        if (ctx->pc != 0x1D10B4u) { return; }
    }
    ctx->pc = 0x1D10B4u;
label_1d10b4:
    // 0x1d10b4: 0x3c10003c  lui         $s0, 0x3C
    ctx->pc = 0x1d10b4u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)60 << 16));
    // 0x1d10b8: 0x24040400  addiu       $a0, $zero, 0x400
    ctx->pc = 0x1d10b8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
    // 0x1d10bc: 0x24050004  addiu       $a1, $zero, 0x4
    ctx->pc = 0x1d10bcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1d10c0: 0xc06ca9c  jal         func_1B2A70
    ctx->pc = 0x1D10C0u;
    SET_GPR_U32(ctx, 31, 0x1D10C8u);
    ctx->pc = 0x1D10C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D10C0u;
            // 0x1d10c4: 0x261085b0  addiu       $s0, $s0, -0x7A50 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294935984));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B2A70u;
    if (runtime->hasFunction(0x1B2A70u)) {
        auto targetFn = runtime->lookupFunction(0x1B2A70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D10C8u; }
        if (ctx->pc != 0x1D10C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B2A70_0x1b2a70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D10C8u; }
        if (ctx->pc != 0x1D10C8u) { return; }
    }
    ctx->pc = 0x1D10C8u;
label_1d10c8:
    // 0x1d10c8: 0x3c01003c  lui         $at, 0x3C
    ctx->pc = 0x1d10c8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)60 << 16));
    // 0x1d10cc: 0xac228db8  sw          $v0, -0x7248($at)
    ctx->pc = 0x1d10ccu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294938040), GPR_U32(ctx, 2));
    // 0x1d10d0: 0x3c01003c  lui         $at, 0x3C
    ctx->pc = 0x1d10d0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)60 << 16));
    // 0x1d10d4: 0xac208dc8  sw          $zero, -0x7238($at)
    ctx->pc = 0x1d10d4u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294938056), GPR_U32(ctx, 0));
    // 0x1d10d8: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d10d8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d10dc: 0x802243d7  lb          $v0, 0x43D7($at)
    ctx->pc = 0x1d10dcu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 17367)));
    // 0x1d10e0: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1D10E0u;
    {
        const bool branch_taken_0x1d10e0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D10E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D10E0u;
            // 0x1d10e4: 0x27a40030  addiu       $a0, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d10e0) {
            ctx->pc = 0x1D1108u;
            goto label_1d1108;
        }
    }
    ctx->pc = 0x1D10E8u;
    // 0x1d10e8: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d10e8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d10ec: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x1d10ecu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d10f0: 0x942443da  lhu         $a0, 0x43DA($at)
    ctx->pc = 0x1d10f0u;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17370)));
    // 0x1d10f4: 0x2405ffff  addiu       $a1, $zero, -0x1
    ctx->pc = 0x1d10f4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d10f8: 0xc073844  jal         func_1CE110
    ctx->pc = 0x1D10F8u;
    SET_GPR_U32(ctx, 31, 0x1D1100u);
    ctx->pc = 0x1D10FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D10F8u;
            // 0x1d10fc: 0x24070002  addiu       $a3, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CE110u;
    if (runtime->hasFunction(0x1CE110u)) {
        auto targetFn = runtime->lookupFunction(0x1CE110u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1100u; }
        if (ctx->pc != 0x1D1100u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CE110_0x1ce110(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1100u; }
        if (ctx->pc != 0x1D1100u) { return; }
    }
    ctx->pc = 0x1D1100u;
label_1d1100:
    // 0x1d1100: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x1D1100u;
    {
        const bool branch_taken_0x1d1100 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d1100) {
            ctx->pc = 0x1D1144u;
            goto label_1d1144;
        }
    }
    ctx->pc = 0x1D1108u;
label_1d1108:
    // 0x1d1108: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1d1108u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d110c: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1D110Cu;
    SET_GPR_U32(ctx, 31, 0x1D1114u);
    ctx->pc = 0x1D1110u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D110Cu;
            // 0x1d1110: 0x24060020  addiu       $a2, $zero, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1114u; }
        if (ctx->pc != 0x1D1114u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1114u; }
        if (ctx->pc != 0x1D1114u) { return; }
    }
    ctx->pc = 0x1D1114u;
label_1d1114:
    // 0x1d1114: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d1114u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d1118: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1d1118u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1d111c: 0x942643da  lhu         $a2, 0x43DA($at)
    ctx->pc = 0x1d111cu;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17370)));
    // 0x1d1120: 0x27a40030  addiu       $a0, $sp, 0x30
    ctx->pc = 0x1d1120u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1d1124: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D1124u;
    SET_GPR_U32(ctx, 31, 0x1D112Cu);
    ctx->pc = 0x1D1128u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1124u;
            // 0x1d1128: 0x24a56300  addiu       $a1, $a1, 0x6300 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 25344));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D112Cu; }
        if (ctx->pc != 0x1D112Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D112Cu; }
        if (ctx->pc != 0x1D112Cu) { return; }
    }
    ctx->pc = 0x1D112Cu;
label_1d112c:
    // 0x1d112c: 0x3c020001  lui         $v0, 0x1
    ctx->pc = 0x1d112cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)1 << 16));
    // 0x1d1130: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1d1130u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1134: 0x27a40030  addiu       $a0, $sp, 0x30
    ctx->pc = 0x1d1134u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1d1138: 0x24062000  addiu       $a2, $zero, 0x2000
    ctx->pc = 0x1d1138u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 8192));
    // 0x1d113c: 0xc06aab4  jal         func_1AAAD0
    ctx->pc = 0x1D113Cu;
    SET_GPR_U32(ctx, 31, 0x1D1144u);
    ctx->pc = 0x1D1140u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D113Cu;
            // 0x1d1140: 0x34470002  ori         $a3, $v0, 0x2 (Delay Slot)
        SET_GPR_U64(ctx, 7, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)2);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AAAD0u;
    if (runtime->hasFunction(0x1AAAD0u)) {
        auto targetFn = runtime->lookupFunction(0x1AAAD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1144u; }
        if (ctx->pc != 0x1D1144u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AAAD0_0x1aaad0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1144u; }
        if (ctx->pc != 0x1D1144u) { return; }
    }
    ctx->pc = 0x1D1144u;
label_1d1144:
    // 0x1d1144: 0x3c010039  lui         $at, 0x39
    ctx->pc = 0x1d1144u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)57 << 16));
    // 0x1d1148: 0x3c02003c  lui         $v0, 0x3C
    ctx->pc = 0x1d1148u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)60 << 16));
    // 0x1d114c: 0xac202690  sw          $zero, 0x2690($at)
    ctx->pc = 0x1d114cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 9872), GPR_U32(ctx, 0));
    // 0x1d1150: 0x3c100039  lui         $s0, 0x39
    ctx->pc = 0x1d1150u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)57 << 16));
    // 0x1d1154: 0x3c010039  lui         $at, 0x39
    ctx->pc = 0x1d1154u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)57 << 16));
    // 0x1d1158: 0x244285b0  addiu       $v0, $v0, -0x7A50
    ctx->pc = 0x1d1158u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294935984));
    // 0x1d115c: 0xac202694  sw          $zero, 0x2694($at)
    ctx->pc = 0x1d115cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 9876), GPR_U32(ctx, 0));
    // 0x1d1160: 0x27a40030  addiu       $a0, $sp, 0x30
    ctx->pc = 0x1d1160u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1d1164: 0x3c010039  lui         $at, 0x39
    ctx->pc = 0x1d1164u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)57 << 16));
    // 0x1d1168: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1d1168u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d116c: 0xac222688  sw          $v0, 0x2688($at)
    ctx->pc = 0x1d116cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 9864), GPR_U32(ctx, 2));
    // 0x1d1170: 0x24060020  addiu       $a2, $zero, 0x20
    ctx->pc = 0x1d1170u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x1d1174: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d1174u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d1178: 0x3c02002f  lui         $v0, 0x2F
    ctx->pc = 0x1d1178u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)47 << 16));
    // 0x1d117c: 0x8c23440c  lw          $v1, 0x440C($at)
    ctx->pc = 0x1d117cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1d1180: 0x3442f000  ori         $v0, $v0, 0xF000
    ctx->pc = 0x1d1180u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)61440);
    // 0x1d1184: 0x26102670  addiu       $s0, $s0, 0x2670
    ctx->pc = 0x1d1184u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 9840));
    // 0x1d1188: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1D1188u;
    SET_GPR_U32(ctx, 31, 0x1D1190u);
    ctx->pc = 0x1D118Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1188u;
            // 0x1d118c: 0x628821  addu        $s1, $v1, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1190u; }
        if (ctx->pc != 0x1D1190u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1190u; }
        if (ctx->pc != 0x1D1190u) { return; }
    }
    ctx->pc = 0x1D1190u;
label_1d1190:
    // 0x1d1190: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d1190u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d1194: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1d1194u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1d1198: 0x942643da  lhu         $a2, 0x43DA($at)
    ctx->pc = 0x1d1198u;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17370)));
    // 0x1d119c: 0x27a40030  addiu       $a0, $sp, 0x30
    ctx->pc = 0x1d119cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1d11a0: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D11A0u;
    SET_GPR_U32(ctx, 31, 0x1D11A8u);
    ctx->pc = 0x1D11A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D11A0u;
            // 0x1d11a4: 0x24a56310  addiu       $a1, $a1, 0x6310 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 25360));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D11A8u; }
        if (ctx->pc != 0x1D11A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D11A8u; }
        if (ctx->pc != 0x1D11A8u) { return; }
    }
    ctx->pc = 0x1D11A8u;
label_1d11a8:
    // 0x1d11a8: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d11a8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d11ac: 0x802243d7  lb          $v0, 0x43D7($at)
    ctx->pc = 0x1d11acu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 17367)));
    // 0x1d11b0: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1D11B0u;
    {
        const bool branch_taken_0x1d11b0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D11B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D11B0u;
            // 0x1d11b4: 0x3c020001  lui         $v0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)1 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d11b0) {
            ctx->pc = 0x1D11D4u;
            goto label_1d11d4;
        }
    }
    ctx->pc = 0x1D11B8u;
    // 0x1d11b8: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d11b8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d11bc: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1d11bcu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1d11c0: 0x942643da  lhu         $a2, 0x43DA($at)
    ctx->pc = 0x1d11c0u;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17370)));
    // 0x1d11c4: 0x27a40030  addiu       $a0, $sp, 0x30
    ctx->pc = 0x1d11c4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1d11c8: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D11C8u;
    SET_GPR_U32(ctx, 31, 0x1D11D0u);
    ctx->pc = 0x1D11CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D11C8u;
            // 0x1d11cc: 0x24a56330  addiu       $a1, $a1, 0x6330 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 25392));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D11D0u; }
        if (ctx->pc != 0x1D11D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D11D0u; }
        if (ctx->pc != 0x1D11D0u) { return; }
    }
    ctx->pc = 0x1D11D0u;
label_1d11d0:
    // 0x1d11d0: 0x3c020001  lui         $v0, 0x1
    ctx->pc = 0x1d11d0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)1 << 16));
label_1d11d4:
    // 0x1d11d4: 0x27a40030  addiu       $a0, $sp, 0x30
    ctx->pc = 0x1d11d4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1d11d8: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1d11d8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d11dc: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1d11dcu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d11e0: 0xc07323c  jal         func_1CC8F0
    ctx->pc = 0x1D11E0u;
    SET_GPR_U32(ctx, 31, 0x1D11E8u);
    ctx->pc = 0x1D11E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D11E0u;
            // 0x1d11e4: 0x34460001  ori         $a2, $v0, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)1);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CC8F0u;
    if (runtime->hasFunction(0x1CC8F0u)) {
        auto targetFn = runtime->lookupFunction(0x1CC8F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D11E8u; }
        if (ctx->pc != 0x1D11E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D11E8u; }
        if (ctx->pc != 0x1D11E8u) { return; }
    }
    ctx->pc = 0x1D11E8u;
label_1d11e8:
    // 0x1d11e8: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x1d11e8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d11ec: 0x10c00007  beqz        $a2, . + 4 + (0x7 << 2)
    ctx->pc = 0x1D11ECu;
    {
        const bool branch_taken_0x1d11ec = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D11F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D11ECu;
            // 0x1d11f0: 0x3c040039  lui         $a0, 0x39 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)57 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d11ec) {
            ctx->pc = 0x1D120Cu;
            goto label_1d120c;
        }
    }
    ctx->pc = 0x1D11F4u;
    // 0x1d11f4: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1d11f4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d11f8: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1D11F8u;
    SET_GPR_U32(ctx, 31, 0x1D1200u);
    ctx->pc = 0x1D11FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D11F8u;
            // 0x1d11fc: 0x248426d0  addiu       $a0, $a0, 0x26D0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 9936));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1200u; }
        if (ctx->pc != 0x1D1200u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1200u; }
        if (ctx->pc != 0x1D1200u) { return; }
    }
    ctx->pc = 0x1D1200u;
label_1d1200:
    // 0x1d1200: 0x3c030039  lui         $v1, 0x39
    ctx->pc = 0x1d1200u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)57 << 16));
    // 0x1d1204: 0x24632ad0  addiu       $v1, $v1, 0x2AD0
    ctx->pc = 0x1d1204u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 10960));
    // 0x1d1208: 0xae03001c  sw          $v1, 0x1C($s0)
    ctx->pc = 0x1d1208u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 28), GPR_U32(ctx, 3));
label_1d120c:
    // 0x1d120c: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1d120cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d1210: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d1210u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d1214: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d1214u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d1218: 0x3e00008  jr          $ra
    ctx->pc = 0x1D1218u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D121Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1218u;
            // 0x1d121c: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D06E0u: goto label_1d06e0;
            case 0x1D0754u: goto label_1d0754;
            case 0x1D0760u: goto label_1d0760;
            case 0x1D076Cu: goto label_1d076c;
            case 0x1D0778u: goto label_1d0778;
            case 0x1D0784u: goto label_1d0784;
            case 0x1D0790u: goto label_1d0790;
            case 0x1D079Cu: goto label_1d079c;
            case 0x1D07A8u: goto label_1d07a8;
            case 0x1D07C0u: goto label_1d07c0;
            case 0x1D07DCu: goto label_1d07dc;
            case 0x1D0840u: goto label_1d0840;
            case 0x1D0848u: goto label_1d0848;
            case 0x1D0858u: goto label_1d0858;
            case 0x1D0860u: goto label_1d0860;
            case 0x1D0870u: goto label_1d0870;
            case 0x1D089Cu: goto label_1d089c;
            case 0x1D08C8u: goto label_1d08c8;
            case 0x1D08E4u: goto label_1d08e4;
            case 0x1D08F8u: goto label_1d08f8;
            case 0x1D0960u: goto label_1d0960;
            case 0x1D0964u: goto label_1d0964;
            case 0x1D0998u: goto label_1d0998;
            case 0x1D09A4u: goto label_1d09a4;
            case 0x1D09C8u: goto label_1d09c8;
            case 0x1D09D0u: goto label_1d09d0;
            case 0x1D09D8u: goto label_1d09d8;
            case 0x1D09FCu: goto label_1d09fc;
            case 0x1D0A3Cu: goto label_1d0a3c;
            case 0x1D0A4Cu: goto label_1d0a4c;
            case 0x1D0A50u: goto label_1d0a50;
            case 0x1D0ABCu: goto label_1d0abc;
            case 0x1D0AC4u: goto label_1d0ac4;
            case 0x1D0AD8u: goto label_1d0ad8;
            case 0x1D0AECu: goto label_1d0aec;
            case 0x1D0B20u: goto label_1d0b20;
            case 0x1D0B34u: goto label_1d0b34;
            case 0x1D0B40u: goto label_1d0b40;
            case 0x1D0B54u: goto label_1d0b54;
            case 0x1D0B8Cu: goto label_1d0b8c;
            case 0x1D0B98u: goto label_1d0b98;
            case 0x1D0BA4u: goto label_1d0ba4;
            case 0x1D0BB0u: goto label_1d0bb0;
            case 0x1D0BBCu: goto label_1d0bbc;
            case 0x1D0BC8u: goto label_1d0bc8;
            case 0x1D0BD4u: goto label_1d0bd4;
            case 0x1D0BE0u: goto label_1d0be0;
            case 0x1D0BECu: goto label_1d0bec;
            case 0x1D0C00u: goto label_1d0c00;
            case 0x1D0C38u: goto label_1d0c38;
            case 0x1D0C40u: goto label_1d0c40;
            case 0x1D0C50u: goto label_1d0c50;
            case 0x1D0C68u: goto label_1d0c68;
            case 0x1D0C6Cu: goto label_1d0c6c;
            case 0x1D0CC4u: goto label_1d0cc4;
            case 0x1D0CD0u: goto label_1d0cd0;
            case 0x1D0CDCu: goto label_1d0cdc;
            case 0x1D0CE8u: goto label_1d0ce8;
            case 0x1D0CF4u: goto label_1d0cf4;
            case 0x1D0D00u: goto label_1d0d00;
            case 0x1D0D0Cu: goto label_1d0d0c;
            case 0x1D0D18u: goto label_1d0d18;
            case 0x1D0D38u: goto label_1d0d38;
            case 0x1D0D6Cu: goto label_1d0d6c;
            case 0x1D0DB4u: goto label_1d0db4;
            case 0x1D0DF8u: goto label_1d0df8;
            case 0x1D0E0Cu: goto label_1d0e0c;
            case 0x1D0E14u: goto label_1d0e14;
            case 0x1D0E38u: goto label_1d0e38;
            case 0x1D0E44u: goto label_1d0e44;
            case 0x1D0E48u: goto label_1d0e48;
            case 0x1D0E70u: goto label_1d0e70;
            case 0x1D0EA8u: goto label_1d0ea8;
            case 0x1D0EFCu: goto label_1d0efc;
            case 0x1D0F04u: goto label_1d0f04;
            case 0x1D0F0Cu: goto label_1d0f0c;
            case 0x1D0F38u: goto label_1d0f38;
            case 0x1D0F40u: goto label_1d0f40;
            case 0x1D0F5Cu: goto label_1d0f5c;
            case 0x1D0F78u: goto label_1d0f78;
            case 0x1D0F94u: goto label_1d0f94;
            case 0x1D0F9Cu: goto label_1d0f9c;
            case 0x1D0FBCu: goto label_1d0fbc;
            case 0x1D0FC4u: goto label_1d0fc4;
            case 0x1D0FE4u: goto label_1d0fe4;
            case 0x1D1004u: goto label_1d1004;
            case 0x1D100Cu: goto label_1d100c;
            case 0x1D1048u: goto label_1d1048;
            case 0x1D1054u: goto label_1d1054;
            case 0x1D1060u: goto label_1d1060;
            case 0x1D106Cu: goto label_1d106c;
            case 0x1D1078u: goto label_1d1078;
            case 0x1D1084u: goto label_1d1084;
            case 0x1D1090u: goto label_1d1090;
            case 0x1D109Cu: goto label_1d109c;
            case 0x1D10A8u: goto label_1d10a8;
            case 0x1D10B4u: goto label_1d10b4;
            case 0x1D10C8u: goto label_1d10c8;
            case 0x1D1100u: goto label_1d1100;
            case 0x1D1108u: goto label_1d1108;
            case 0x1D1114u: goto label_1d1114;
            case 0x1D112Cu: goto label_1d112c;
            case 0x1D1144u: goto label_1d1144;
            case 0x1D1190u: goto label_1d1190;
            case 0x1D11A8u: goto label_1d11a8;
            case 0x1D11D0u: goto label_1d11d0;
            case 0x1D11D4u: goto label_1d11d4;
            case 0x1D11E8u: goto label_1d11e8;
            case 0x1D1200u: goto label_1d1200;
            case 0x1D120Cu: goto label_1d120c;
            case 0x1D123Cu: goto label_1d123c;
            case 0x1D1248u: goto label_1d1248;
            case 0x1D1254u: goto label_1d1254;
            case 0x1D1260u: goto label_1d1260;
            case 0x1D126Cu: goto label_1d126c;
            case 0x1D1278u: goto label_1d1278;
            case 0x1D1284u: goto label_1d1284;
            case 0x1D1290u: goto label_1d1290;
            case 0x1D129Cu: goto label_1d129c;
            case 0x1D12A8u: goto label_1d12a8;
            case 0x1D12B8u: goto label_1d12b8;
            case 0x1D12D4u: goto label_1d12d4;
            case 0x1D12E8u: goto label_1d12e8;
            case 0x1D1308u: goto label_1d1308;
            case 0x1D1368u: goto label_1d1368;
            case 0x1D1370u: goto label_1d1370;
            case 0x1D1388u: goto label_1d1388;
            case 0x1D139Cu: goto label_1d139c;
            case 0x1D13A0u: goto label_1d13a0;
            case 0x1D13B4u: goto label_1d13b4;
            case 0x1D141Cu: goto label_1d141c;
            case 0x1D1428u: goto label_1d1428;
            case 0x1D1434u: goto label_1d1434;
            case 0x1D1440u: goto label_1d1440;
            case 0x1D144Cu: goto label_1d144c;
            case 0x1D1458u: goto label_1d1458;
            case 0x1D1464u: goto label_1d1464;
            case 0x1D1470u: goto label_1d1470;
            case 0x1D147Cu: goto label_1d147c;
            case 0x1D148Cu: goto label_1d148c;
            case 0x1D14C4u: goto label_1d14c4;
            case 0x1D14CCu: goto label_1d14cc;
            case 0x1D14DCu: goto label_1d14dc;
            case 0x1D14E0u: goto label_1d14e0;
            case 0x1D1570u: goto label_1d1570;
            case 0x1D15ACu: goto label_1d15ac;
            case 0x1D15F4u: goto label_1d15f4;
            case 0x1D1604u: goto label_1d1604;
            case 0x1D160Cu: goto label_1d160c;
            case 0x1D163Cu: goto label_1d163c;
            case 0x1D1654u: goto label_1d1654;
            case 0x1D165Cu: goto label_1d165c;
            case 0x1D1670u: goto label_1d1670;
            case 0x1D1678u: goto label_1d1678;
            case 0x1D1688u: goto label_1d1688;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D1220u;
    // 0x1d1220: 0x27bdff80  addiu       $sp, $sp, -0x80
    ctx->pc = 0x1d1220u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x1d1224: 0x24042400  addiu       $a0, $zero, 0x2400
    ctx->pc = 0x1d1224u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 9216));
    // 0x1d1228: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1d1228u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1d122c: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1d122cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1d1230: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d1230u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d1234: 0xc073470  jal         func_1CD1C0
    ctx->pc = 0x1D1234u;
    SET_GPR_U32(ctx, 31, 0x1D123Cu);
    ctx->pc = 0x1D1238u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1234u;
            // 0x1d1238: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CD1C0u;
    if (runtime->hasFunction(0x1CD1C0u)) {
        auto targetFn = runtime->lookupFunction(0x1CD1C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D123Cu; }
        if (ctx->pc != 0x1D123Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CD1C0_0x1cd1c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D123Cu; }
        if (ctx->pc != 0x1D123Cu) { return; }
    }
    ctx->pc = 0x1D123Cu;
label_1d123c:
    // 0x1d123c: 0x24040015  addiu       $a0, $zero, 0x15
    ctx->pc = 0x1d123cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 21));
    // 0x1d1240: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D1240u;
    SET_GPR_U32(ctx, 31, 0x1D1248u);
    ctx->pc = 0x1D1244u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1240u;
            // 0x1d1244: 0x24050002  addiu       $a1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1248u; }
        if (ctx->pc != 0x1D1248u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1248u; }
        if (ctx->pc != 0x1D1248u) { return; }
    }
    ctx->pc = 0x1D1248u;
label_1d1248:
    // 0x1d1248: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1d1248u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d124c: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D124Cu;
    SET_GPR_U32(ctx, 31, 0x1D1254u);
    ctx->pc = 0x1D1250u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D124Cu;
            // 0x1d1250: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1254u; }
        if (ctx->pc != 0x1D1254u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1254u; }
        if (ctx->pc != 0x1D1254u) { return; }
    }
    ctx->pc = 0x1D1254u;
label_1d1254:
    // 0x1d1254: 0x24040012  addiu       $a0, $zero, 0x12
    ctx->pc = 0x1d1254u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 18));
    // 0x1d1258: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D1258u;
    SET_GPR_U32(ctx, 31, 0x1D1260u);
    ctx->pc = 0x1D125Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1258u;
            // 0x1d125c: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1260u; }
        if (ctx->pc != 0x1D1260u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1260u; }
        if (ctx->pc != 0x1D1260u) { return; }
    }
    ctx->pc = 0x1D1260u;
label_1d1260:
    // 0x1d1260: 0x24040062  addiu       $a0, $zero, 0x62
    ctx->pc = 0x1d1260u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 98));
    // 0x1d1264: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D1264u;
    SET_GPR_U32(ctx, 31, 0x1D126Cu);
    ctx->pc = 0x1D1268u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1264u;
            // 0x1d1268: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D126Cu; }
        if (ctx->pc != 0x1D126Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D126Cu; }
        if (ctx->pc != 0x1D126Cu) { return; }
    }
    ctx->pc = 0x1D126Cu;
label_1d126c:
    // 0x1d126c: 0x2404000c  addiu       $a0, $zero, 0xC
    ctx->pc = 0x1d126cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
    // 0x1d1270: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D1270u;
    SET_GPR_U32(ctx, 31, 0x1D1278u);
    ctx->pc = 0x1D1274u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1270u;
            // 0x1d1274: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1278u; }
        if (ctx->pc != 0x1D1278u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1278u; }
        if (ctx->pc != 0x1D1278u) { return; }
    }
    ctx->pc = 0x1D1278u;
label_1d1278:
    // 0x1d1278: 0x24040066  addiu       $a0, $zero, 0x66
    ctx->pc = 0x1d1278u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1d127c: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D127Cu;
    SET_GPR_U32(ctx, 31, 0x1D1284u);
    ctx->pc = 0x1D1280u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D127Cu;
            // 0x1d1280: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1284u; }
        if (ctx->pc != 0x1D1284u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1284u; }
        if (ctx->pc != 0x1D1284u) { return; }
    }
    ctx->pc = 0x1D1284u;
label_1d1284:
    // 0x1d1284: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1d1284u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1d1288: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D1288u;
    SET_GPR_U32(ctx, 31, 0x1D1290u);
    ctx->pc = 0x1D128Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1288u;
            // 0x1d128c: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1290u; }
        if (ctx->pc != 0x1D1290u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1290u; }
        if (ctx->pc != 0x1D1290u) { return; }
    }
    ctx->pc = 0x1D1290u;
label_1d1290:
    // 0x1d1290: 0x24040012  addiu       $a0, $zero, 0x12
    ctx->pc = 0x1d1290u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 18));
    // 0x1d1294: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D1294u;
    SET_GPR_U32(ctx, 31, 0x1D129Cu);
    ctx->pc = 0x1D1298u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1294u;
            // 0x1d1298: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D129Cu; }
        if (ctx->pc != 0x1D129Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D129Cu; }
        if (ctx->pc != 0x1D129Cu) { return; }
    }
    ctx->pc = 0x1D129Cu;
label_1d129c:
    // 0x1d129c: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1d129cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d12a0: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D12A0u;
    SET_GPR_U32(ctx, 31, 0x1D12A8u);
    ctx->pc = 0x1D12A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D12A0u;
            // 0x1d12a4: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D12A8u; }
        if (ctx->pc != 0x1D12A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D12A8u; }
        if (ctx->pc != 0x1D12A8u) { return; }
    }
    ctx->pc = 0x1D12A8u;
label_1d12a8:
    // 0x1d12a8: 0x27a40060  addiu       $a0, $sp, 0x60
    ctx->pc = 0x1d12a8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
    // 0x1d12ac: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1d12acu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d12b0: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1D12B0u;
    SET_GPR_U32(ctx, 31, 0x1D12B8u);
    ctx->pc = 0x1D12B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D12B0u;
            // 0x1d12b4: 0x24060020  addiu       $a2, $zero, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D12B8u; }
        if (ctx->pc != 0x1D12B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D12B8u; }
        if (ctx->pc != 0x1D12B8u) { return; }
    }
    ctx->pc = 0x1D12B8u;
label_1d12b8:
    // 0x1d12b8: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d12b8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d12bc: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1d12bcu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1d12c0: 0x943043da  lhu         $s0, 0x43DA($at)
    ctx->pc = 0x1d12c0u;
    SET_GPR_U32(ctx, 16, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17370)));
    // 0x1d12c4: 0x27a40060  addiu       $a0, $sp, 0x60
    ctx->pc = 0x1d12c4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
    // 0x1d12c8: 0x24a56340  addiu       $a1, $a1, 0x6340
    ctx->pc = 0x1d12c8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 25408));
    // 0x1d12cc: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D12CCu;
    SET_GPR_U32(ctx, 31, 0x1D12D4u);
    ctx->pc = 0x1D12D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D12CCu;
            // 0x1d12d0: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D12D4u; }
        if (ctx->pc != 0x1D12D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D12D4u; }
        if (ctx->pc != 0x1D12D4u) { return; }
    }
    ctx->pc = 0x1D12D4u;
label_1d12d4:
    // 0x1d12d4: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1d12d4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1d12d8: 0x27a40040  addiu       $a0, $sp, 0x40
    ctx->pc = 0x1d12d8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x1d12dc: 0x24a56350  addiu       $a1, $a1, 0x6350
    ctx->pc = 0x1d12dcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 25424));
    // 0x1d12e0: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D12E0u;
    SET_GPR_U32(ctx, 31, 0x1D12E8u);
    ctx->pc = 0x1D12E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D12E0u;
            // 0x1d12e4: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D12E8u; }
        if (ctx->pc != 0x1D12E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D12E8u; }
        if (ctx->pc != 0x1D12E8u) { return; }
    }
    ctx->pc = 0x1D12E8u;
label_1d12e8:
    // 0x1d12e8: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d12e8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d12ec: 0x3c02002f  lui         $v0, 0x2F
    ctx->pc = 0x1d12ecu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)47 << 16));
    // 0x1d12f0: 0x8c23440c  lw          $v1, 0x440C($at)
    ctx->pc = 0x1d12f0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1d12f4: 0x3442f000  ori         $v0, $v0, 0xF000
    ctx->pc = 0x1d12f4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)61440);
    // 0x1d12f8: 0x24040200  addiu       $a0, $zero, 0x200
    ctx->pc = 0x1d12f8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 512));
    // 0x1d12fc: 0x2405000a  addiu       $a1, $zero, 0xA
    ctx->pc = 0x1d12fcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x1d1300: 0xc06ca9c  jal         func_1B2A70
    ctx->pc = 0x1D1300u;
    SET_GPR_U32(ctx, 31, 0x1D1308u);
    ctx->pc = 0x1D1304u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1300u;
            // 0x1d1304: 0x628821  addu        $s1, $v1, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B2A70u;
    if (runtime->hasFunction(0x1B2A70u)) {
        auto targetFn = runtime->lookupFunction(0x1B2A70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1308u; }
        if (ctx->pc != 0x1D1308u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B2A70_0x1b2a70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1308u; }
        if (ctx->pc != 0x1D1308u) { return; }
    }
    ctx->pc = 0x1D1308u;
label_1d1308:
    // 0x1d1308: 0xae220808  sw          $v0, 0x808($s1)
    ctx->pc = 0x1d1308u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 2056), GPR_U32(ctx, 2));
    // 0x1d130c: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d130cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d1310: 0xae200818  sw          $zero, 0x818($s1)
    ctx->pc = 0x1d1310u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 2072), GPR_U32(ctx, 0));
    // 0x1d1314: 0x3c020030  lui         $v0, 0x30
    ctx->pc = 0x1d1314u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)48 << 16));
    // 0x1d1318: 0x8c24440c  lw          $a0, 0x440C($at)
    ctx->pc = 0x1d1318u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1d131c: 0x34431000  ori         $v1, $v0, 0x1000
    ctx->pc = 0x1d131cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)4096);
    // 0x1d1320: 0x34421100  ori         $v0, $v0, 0x1100
    ctx->pc = 0x1d1320u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)4352);
    // 0x1d1324: 0x839021  addu        $s2, $a0, $v1
    ctx->pc = 0x1d1324u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x1d1328: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d1328u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d132c: 0xae510018  sw          $s1, 0x18($s2)
    ctx->pc = 0x1d132cu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 24), GPR_U32(ctx, 17));
    // 0x1d1330: 0xae400020  sw          $zero, 0x20($s2)
    ctx->pc = 0x1d1330u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 32), GPR_U32(ctx, 0));
    // 0x1d1334: 0xae400024  sw          $zero, 0x24($s2)
    ctx->pc = 0x1d1334u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 36), GPR_U32(ctx, 0));
    // 0x1d1338: 0x8c23440c  lw          $v1, 0x440C($at)
    ctx->pc = 0x1d1338u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1d133c: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1d133cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1d1340: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d1340u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d1344: 0xae42001c  sw          $v0, 0x1C($s2)
    ctx->pc = 0x1d1344u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 28), GPR_U32(ctx, 2));
    // 0x1d1348: 0x802243d7  lb          $v0, 0x43D7($at)
    ctx->pc = 0x1d1348u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 17367)));
    // 0x1d134c: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1D134Cu;
    {
        const bool branch_taken_0x1d134c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D1350u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D134Cu;
            // 0x1d1350: 0x3c010032  lui         $at, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d134c) {
            ctx->pc = 0x1D1370u;
            goto label_1d1370;
        }
    }
    ctx->pc = 0x1D1354u;
    // 0x1d1354: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x1d1354u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1358: 0x942443da  lhu         $a0, 0x43DA($at)
    ctx->pc = 0x1d1358u;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17370)));
    // 0x1d135c: 0x2405ffff  addiu       $a1, $zero, -0x1
    ctx->pc = 0x1d135cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d1360: 0xc073844  jal         func_1CE110
    ctx->pc = 0x1D1360u;
    SET_GPR_U32(ctx, 31, 0x1D1368u);
    ctx->pc = 0x1D1364u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1360u;
            // 0x1d1364: 0x24070002  addiu       $a3, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CE110u;
    if (runtime->hasFunction(0x1CE110u)) {
        auto targetFn = runtime->lookupFunction(0x1CE110u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1368u; }
        if (ctx->pc != 0x1D1368u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CE110_0x1ce110(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1368u; }
        if (ctx->pc != 0x1D1368u) { return; }
    }
    ctx->pc = 0x1D1368u;
label_1d1368:
    // 0x1d1368: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1D1368u;
    {
        const bool branch_taken_0x1d1368 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D136Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1368u;
            // 0x1d136c: 0x8e45001c  lw          $a1, 0x1C($s2) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 28)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d1368) {
            ctx->pc = 0x1D13A0u;
            goto label_1d13a0;
        }
    }
    ctx->pc = 0x1D1370u;
label_1d1370:
    // 0x1d1370: 0x3c020001  lui         $v0, 0x1
    ctx->pc = 0x1d1370u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)1 << 16));
    // 0x1d1374: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1d1374u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1378: 0x27a40060  addiu       $a0, $sp, 0x60
    ctx->pc = 0x1d1378u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
    // 0x1d137c: 0x24062400  addiu       $a2, $zero, 0x2400
    ctx->pc = 0x1d137cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 9216));
    // 0x1d1380: 0xc06aab4  jal         func_1AAAD0
    ctx->pc = 0x1D1380u;
    SET_GPR_U32(ctx, 31, 0x1D1388u);
    ctx->pc = 0x1D1384u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1380u;
            // 0x1d1384: 0x34470002  ori         $a3, $v0, 0x2 (Delay Slot)
        SET_GPR_U64(ctx, 7, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)2);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AAAD0u;
    if (runtime->hasFunction(0x1AAAD0u)) {
        auto targetFn = runtime->lookupFunction(0x1AAAD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1388u; }
        if (ctx->pc != 0x1D1388u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AAAD0_0x1aaad0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1388u; }
        if (ctx->pc != 0x1D1388u) { return; }
    }
    ctx->pc = 0x1D1388u;
label_1d1388:
    // 0x1d1388: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1d1388u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1d138c: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x1d138cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1390: 0x27a40040  addiu       $a0, $sp, 0x40
    ctx->pc = 0x1d1390u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x1d1394: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D1394u;
    SET_GPR_U32(ctx, 31, 0x1D139Cu);
    ctx->pc = 0x1D1398u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1394u;
            // 0x1d1398: 0x24a56370  addiu       $a1, $a1, 0x6370 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 25456));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D139Cu; }
        if (ctx->pc != 0x1D139Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D139Cu; }
        if (ctx->pc != 0x1D139Cu) { return; }
    }
    ctx->pc = 0x1D139Cu;
label_1d139c:
    // 0x1d139c: 0x8e45001c  lw          $a1, 0x1C($s2)
    ctx->pc = 0x1d139cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 28)));
label_1d13a0:
    // 0x1d13a0: 0x3c020001  lui         $v0, 0x1
    ctx->pc = 0x1d13a0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)1 << 16));
    // 0x1d13a4: 0x27a40040  addiu       $a0, $sp, 0x40
    ctx->pc = 0x1d13a4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x1d13a8: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1d13a8u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d13ac: 0xc07323c  jal         func_1CC8F0
    ctx->pc = 0x1D13ACu;
    SET_GPR_U32(ctx, 31, 0x1D13B4u);
    ctx->pc = 0x1D13B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D13ACu;
            // 0x1d13b0: 0x34460001  ori         $a2, $v0, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)1);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CC8F0u;
    if (runtime->hasFunction(0x1CC8F0u)) {
        auto targetFn = runtime->lookupFunction(0x1CC8F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D13B4u; }
        if (ctx->pc != 0x1D13B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D13B4u; }
        if (ctx->pc != 0x1D13B4u) { return; }
    }
    ctx->pc = 0x1D13B4u;
label_1d13b4:
    // 0x1d13b4: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d13b4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d13b8: 0x3c030030  lui         $v1, 0x30
    ctx->pc = 0x1d13b8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)48 << 16));
    // 0x1d13bc: 0x8c24440c  lw          $a0, 0x440C($at)
    ctx->pc = 0x1d13bcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1d13c0: 0x34631500  ori         $v1, $v1, 0x1500
    ctx->pc = 0x1d13c0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)5376);
    // 0x1d13c4: 0x831821  addu        $v1, $a0, $v1
    ctx->pc = 0x1d13c4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x1d13c8: 0xae43001c  sw          $v1, 0x1C($s2)
    ctx->pc = 0x1d13c8u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 28), GPR_U32(ctx, 3));
    // 0x1d13cc: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1d13ccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1d13d0: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1d13d0u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d13d4: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d13d4u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d13d8: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d13d8u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d13dc: 0x3e00008  jr          $ra
    ctx->pc = 0x1D13DCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D13E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D13DCu;
            // 0x1d13e0: 0x27bd0080  addiu       $sp, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D06E0u: goto label_1d06e0;
            case 0x1D0754u: goto label_1d0754;
            case 0x1D0760u: goto label_1d0760;
            case 0x1D076Cu: goto label_1d076c;
            case 0x1D0778u: goto label_1d0778;
            case 0x1D0784u: goto label_1d0784;
            case 0x1D0790u: goto label_1d0790;
            case 0x1D079Cu: goto label_1d079c;
            case 0x1D07A8u: goto label_1d07a8;
            case 0x1D07C0u: goto label_1d07c0;
            case 0x1D07DCu: goto label_1d07dc;
            case 0x1D0840u: goto label_1d0840;
            case 0x1D0848u: goto label_1d0848;
            case 0x1D0858u: goto label_1d0858;
            case 0x1D0860u: goto label_1d0860;
            case 0x1D0870u: goto label_1d0870;
            case 0x1D089Cu: goto label_1d089c;
            case 0x1D08C8u: goto label_1d08c8;
            case 0x1D08E4u: goto label_1d08e4;
            case 0x1D08F8u: goto label_1d08f8;
            case 0x1D0960u: goto label_1d0960;
            case 0x1D0964u: goto label_1d0964;
            case 0x1D0998u: goto label_1d0998;
            case 0x1D09A4u: goto label_1d09a4;
            case 0x1D09C8u: goto label_1d09c8;
            case 0x1D09D0u: goto label_1d09d0;
            case 0x1D09D8u: goto label_1d09d8;
            case 0x1D09FCu: goto label_1d09fc;
            case 0x1D0A3Cu: goto label_1d0a3c;
            case 0x1D0A4Cu: goto label_1d0a4c;
            case 0x1D0A50u: goto label_1d0a50;
            case 0x1D0ABCu: goto label_1d0abc;
            case 0x1D0AC4u: goto label_1d0ac4;
            case 0x1D0AD8u: goto label_1d0ad8;
            case 0x1D0AECu: goto label_1d0aec;
            case 0x1D0B20u: goto label_1d0b20;
            case 0x1D0B34u: goto label_1d0b34;
            case 0x1D0B40u: goto label_1d0b40;
            case 0x1D0B54u: goto label_1d0b54;
            case 0x1D0B8Cu: goto label_1d0b8c;
            case 0x1D0B98u: goto label_1d0b98;
            case 0x1D0BA4u: goto label_1d0ba4;
            case 0x1D0BB0u: goto label_1d0bb0;
            case 0x1D0BBCu: goto label_1d0bbc;
            case 0x1D0BC8u: goto label_1d0bc8;
            case 0x1D0BD4u: goto label_1d0bd4;
            case 0x1D0BE0u: goto label_1d0be0;
            case 0x1D0BECu: goto label_1d0bec;
            case 0x1D0C00u: goto label_1d0c00;
            case 0x1D0C38u: goto label_1d0c38;
            case 0x1D0C40u: goto label_1d0c40;
            case 0x1D0C50u: goto label_1d0c50;
            case 0x1D0C68u: goto label_1d0c68;
            case 0x1D0C6Cu: goto label_1d0c6c;
            case 0x1D0CC4u: goto label_1d0cc4;
            case 0x1D0CD0u: goto label_1d0cd0;
            case 0x1D0CDCu: goto label_1d0cdc;
            case 0x1D0CE8u: goto label_1d0ce8;
            case 0x1D0CF4u: goto label_1d0cf4;
            case 0x1D0D00u: goto label_1d0d00;
            case 0x1D0D0Cu: goto label_1d0d0c;
            case 0x1D0D18u: goto label_1d0d18;
            case 0x1D0D38u: goto label_1d0d38;
            case 0x1D0D6Cu: goto label_1d0d6c;
            case 0x1D0DB4u: goto label_1d0db4;
            case 0x1D0DF8u: goto label_1d0df8;
            case 0x1D0E0Cu: goto label_1d0e0c;
            case 0x1D0E14u: goto label_1d0e14;
            case 0x1D0E38u: goto label_1d0e38;
            case 0x1D0E44u: goto label_1d0e44;
            case 0x1D0E48u: goto label_1d0e48;
            case 0x1D0E70u: goto label_1d0e70;
            case 0x1D0EA8u: goto label_1d0ea8;
            case 0x1D0EFCu: goto label_1d0efc;
            case 0x1D0F04u: goto label_1d0f04;
            case 0x1D0F0Cu: goto label_1d0f0c;
            case 0x1D0F38u: goto label_1d0f38;
            case 0x1D0F40u: goto label_1d0f40;
            case 0x1D0F5Cu: goto label_1d0f5c;
            case 0x1D0F78u: goto label_1d0f78;
            case 0x1D0F94u: goto label_1d0f94;
            case 0x1D0F9Cu: goto label_1d0f9c;
            case 0x1D0FBCu: goto label_1d0fbc;
            case 0x1D0FC4u: goto label_1d0fc4;
            case 0x1D0FE4u: goto label_1d0fe4;
            case 0x1D1004u: goto label_1d1004;
            case 0x1D100Cu: goto label_1d100c;
            case 0x1D1048u: goto label_1d1048;
            case 0x1D1054u: goto label_1d1054;
            case 0x1D1060u: goto label_1d1060;
            case 0x1D106Cu: goto label_1d106c;
            case 0x1D1078u: goto label_1d1078;
            case 0x1D1084u: goto label_1d1084;
            case 0x1D1090u: goto label_1d1090;
            case 0x1D109Cu: goto label_1d109c;
            case 0x1D10A8u: goto label_1d10a8;
            case 0x1D10B4u: goto label_1d10b4;
            case 0x1D10C8u: goto label_1d10c8;
            case 0x1D1100u: goto label_1d1100;
            case 0x1D1108u: goto label_1d1108;
            case 0x1D1114u: goto label_1d1114;
            case 0x1D112Cu: goto label_1d112c;
            case 0x1D1144u: goto label_1d1144;
            case 0x1D1190u: goto label_1d1190;
            case 0x1D11A8u: goto label_1d11a8;
            case 0x1D11D0u: goto label_1d11d0;
            case 0x1D11D4u: goto label_1d11d4;
            case 0x1D11E8u: goto label_1d11e8;
            case 0x1D1200u: goto label_1d1200;
            case 0x1D120Cu: goto label_1d120c;
            case 0x1D123Cu: goto label_1d123c;
            case 0x1D1248u: goto label_1d1248;
            case 0x1D1254u: goto label_1d1254;
            case 0x1D1260u: goto label_1d1260;
            case 0x1D126Cu: goto label_1d126c;
            case 0x1D1278u: goto label_1d1278;
            case 0x1D1284u: goto label_1d1284;
            case 0x1D1290u: goto label_1d1290;
            case 0x1D129Cu: goto label_1d129c;
            case 0x1D12A8u: goto label_1d12a8;
            case 0x1D12B8u: goto label_1d12b8;
            case 0x1D12D4u: goto label_1d12d4;
            case 0x1D12E8u: goto label_1d12e8;
            case 0x1D1308u: goto label_1d1308;
            case 0x1D1368u: goto label_1d1368;
            case 0x1D1370u: goto label_1d1370;
            case 0x1D1388u: goto label_1d1388;
            case 0x1D139Cu: goto label_1d139c;
            case 0x1D13A0u: goto label_1d13a0;
            case 0x1D13B4u: goto label_1d13b4;
            case 0x1D141Cu: goto label_1d141c;
            case 0x1D1428u: goto label_1d1428;
            case 0x1D1434u: goto label_1d1434;
            case 0x1D1440u: goto label_1d1440;
            case 0x1D144Cu: goto label_1d144c;
            case 0x1D1458u: goto label_1d1458;
            case 0x1D1464u: goto label_1d1464;
            case 0x1D1470u: goto label_1d1470;
            case 0x1D147Cu: goto label_1d147c;
            case 0x1D148Cu: goto label_1d148c;
            case 0x1D14C4u: goto label_1d14c4;
            case 0x1D14CCu: goto label_1d14cc;
            case 0x1D14DCu: goto label_1d14dc;
            case 0x1D14E0u: goto label_1d14e0;
            case 0x1D1570u: goto label_1d1570;
            case 0x1D15ACu: goto label_1d15ac;
            case 0x1D15F4u: goto label_1d15f4;
            case 0x1D1604u: goto label_1d1604;
            case 0x1D160Cu: goto label_1d160c;
            case 0x1D163Cu: goto label_1d163c;
            case 0x1D1654u: goto label_1d1654;
            case 0x1D165Cu: goto label_1d165c;
            case 0x1D1670u: goto label_1d1670;
            case 0x1D1678u: goto label_1d1678;
            case 0x1D1688u: goto label_1d1688;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D13E4u;
    // 0x1d13e4: 0x0  nop
    ctx->pc = 0x1d13e4u;
    // NOP
    // 0x1d13e8: 0x0  nop
    ctx->pc = 0x1d13e8u;
    // NOP
    // 0x1d13ec: 0x0  nop
    ctx->pc = 0x1d13ecu;
    // NOP
    // 0x1d13f0: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1d13f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1d13f4: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x1d13f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x1d13f8: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1d13f8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1d13fc: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1d13fcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1d1400: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x1d1400u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1404: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d1404u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d1408: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d1408u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d140c: 0x30b000ff  andi        $s0, $a1, 0xFF
    ctx->pc = 0x1d140cu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x1d1410: 0x1010c0  sll         $v0, $s0, 3
    ctx->pc = 0x1d1410u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 3));
    // 0x1d1414: 0xc073470  jal         func_1CD1C0
    ctx->pc = 0x1D1414u;
    SET_GPR_U32(ctx, 31, 0x1D141Cu);
    ctx->pc = 0x1D1418u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1414u;
            // 0x1d1418: 0x24443000  addiu       $a0, $v0, 0x3000 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 12288));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CD1C0u;
    if (runtime->hasFunction(0x1CD1C0u)) {
        auto targetFn = runtime->lookupFunction(0x1CD1C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D141Cu; }
        if (ctx->pc != 0x1D141Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CD1C0_0x1cd1c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D141Cu; }
        if (ctx->pc != 0x1D141Cu) { return; }
    }
    ctx->pc = 0x1D141Cu;
label_1d141c:
    // 0x1d141c: 0x24040015  addiu       $a0, $zero, 0x15
    ctx->pc = 0x1d141cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 21));
    // 0x1d1420: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D1420u;
    SET_GPR_U32(ctx, 31, 0x1D1428u);
    ctx->pc = 0x1D1424u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1420u;
            // 0x1d1424: 0x24050002  addiu       $a1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1428u; }
        if (ctx->pc != 0x1D1428u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1428u; }
        if (ctx->pc != 0x1D1428u) { return; }
    }
    ctx->pc = 0x1D1428u;
label_1d1428:
    // 0x1d1428: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1d1428u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d142c: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D142Cu;
    SET_GPR_U32(ctx, 31, 0x1D1434u);
    ctx->pc = 0x1D1430u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D142Cu;
            // 0x1d1430: 0x24050800  addiu       $a1, $zero, 0x800 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2048));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1434u; }
        if (ctx->pc != 0x1D1434u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1434u; }
        if (ctx->pc != 0x1D1434u) { return; }
    }
    ctx->pc = 0x1D1434u;
label_1d1434:
    // 0x1d1434: 0x24040012  addiu       $a0, $zero, 0x12
    ctx->pc = 0x1d1434u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 18));
    // 0x1d1438: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D1438u;
    SET_GPR_U32(ctx, 31, 0x1D1440u);
    ctx->pc = 0x1D143Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1438u;
            // 0x1d143c: 0x34058000  ori         $a1, $zero, 0x8000 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1440u; }
        if (ctx->pc != 0x1D1440u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1440u; }
        if (ctx->pc != 0x1D1440u) { return; }
    }
    ctx->pc = 0x1D1440u;
label_1d1440:
    // 0x1d1440: 0x24040062  addiu       $a0, $zero, 0x62
    ctx->pc = 0x1d1440u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 98));
    // 0x1d1444: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D1444u;
    SET_GPR_U32(ctx, 31, 0x1D144Cu);
    ctx->pc = 0x1D1448u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1444u;
            // 0x1d1448: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D144Cu; }
        if (ctx->pc != 0x1D144Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D144Cu; }
        if (ctx->pc != 0x1D144Cu) { return; }
    }
    ctx->pc = 0x1D144Cu;
label_1d144c:
    // 0x1d144c: 0x2404000c  addiu       $a0, $zero, 0xC
    ctx->pc = 0x1d144cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
    // 0x1d1450: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D1450u;
    SET_GPR_U32(ctx, 31, 0x1D1458u);
    ctx->pc = 0x1D1454u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1450u;
            // 0x1d1454: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1458u; }
        if (ctx->pc != 0x1D1458u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1458u; }
        if (ctx->pc != 0x1D1458u) { return; }
    }
    ctx->pc = 0x1D1458u;
label_1d1458:
    // 0x1d1458: 0x24040066  addiu       $a0, $zero, 0x66
    ctx->pc = 0x1d1458u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1d145c: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D145Cu;
    SET_GPR_U32(ctx, 31, 0x1D1464u);
    ctx->pc = 0x1D1460u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D145Cu;
            // 0x1d1460: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1464u; }
        if (ctx->pc != 0x1D1464u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1464u; }
        if (ctx->pc != 0x1D1464u) { return; }
    }
    ctx->pc = 0x1D1464u;
label_1d1464:
    // 0x1d1464: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1d1464u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1d1468: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D1468u;
    SET_GPR_U32(ctx, 31, 0x1D1470u);
    ctx->pc = 0x1D146Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1468u;
            // 0x1d146c: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1470u; }
        if (ctx->pc != 0x1D1470u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1470u; }
        if (ctx->pc != 0x1D1470u) { return; }
    }
    ctx->pc = 0x1D1470u;
label_1d1470:
    // 0x1d1470: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1d1470u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1474: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D1474u;
    SET_GPR_U32(ctx, 31, 0x1D147Cu);
    ctx->pc = 0x1D1478u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1474u;
            // 0x1d1478: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D147Cu; }
        if (ctx->pc != 0x1D147Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D147Cu; }
        if (ctx->pc != 0x1D147Cu) { return; }
    }
    ctx->pc = 0x1D147Cu;
label_1d147c:
    // 0x1d147c: 0x24040008  addiu       $a0, $zero, 0x8
    ctx->pc = 0x1d147cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1d1480: 0x2405000b  addiu       $a1, $zero, 0xB
    ctx->pc = 0x1d1480u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 11));
    // 0x1d1484: 0xc06ca9c  jal         func_1B2A70
    ctx->pc = 0x1D1484u;
    SET_GPR_U32(ctx, 31, 0x1D148Cu);
    ctx->pc = 0x1D1488u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1484u;
            // 0x1d1488: 0x26710070  addiu       $s1, $s3, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 19), 112));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B2A70u;
    if (runtime->hasFunction(0x1B2A70u)) {
        auto targetFn = runtime->lookupFunction(0x1B2A70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D148Cu; }
        if (ctx->pc != 0x1D148Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B2A70_0x1b2a70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D148Cu; }
        if (ctx->pc != 0x1D148Cu) { return; }
    }
    ctx->pc = 0x1D148Cu;
label_1d148c:
    // 0x1d148c: 0xae220808  sw          $v0, 0x808($s1)
    ctx->pc = 0x1d148cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 2056), GPR_U32(ctx, 2));
    // 0x1d1490: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d1490u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d1494: 0x26620890  addiu       $v0, $s3, 0x890
    ctx->pc = 0x1d1494u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 19), 2192));
    // 0x1d1498: 0xae220000  sw          $v0, 0x0($s1)
    ctx->pc = 0x1d1498u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
    // 0x1d149c: 0x26620910  addiu       $v0, $s3, 0x910
    ctx->pc = 0x1d149cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 19), 2320));
    // 0x1d14a0: 0xae220818  sw          $v0, 0x818($s1)
    ctx->pc = 0x1d14a0u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 2072), GPR_U32(ctx, 2));
    // 0x1d14a4: 0x802243d7  lb          $v0, 0x43D7($at)
    ctx->pc = 0x1d14a4u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 17367)));
    // 0x1d14a8: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1D14A8u;
    {
        const bool branch_taken_0x1d14a8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D14ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D14A8u;
            // 0x1d14ac: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d14a8) {
            ctx->pc = 0x1D14CCu;
            goto label_1d14cc;
        }
    }
    ctx->pc = 0x1D14B0u;
    // 0x1d14b0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1d14b0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d14b4: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x1d14b4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d14b8: 0x2405ffff  addiu       $a1, $zero, -0x1
    ctx->pc = 0x1d14b8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d14bc: 0xc073844  jal         func_1CE110
    ctx->pc = 0x1D14BCu;
    SET_GPR_U32(ctx, 31, 0x1D14C4u);
    ctx->pc = 0x1D14C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D14BCu;
            // 0x1d14c0: 0x24070003  addiu       $a3, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CE110u;
    if (runtime->hasFunction(0x1CE110u)) {
        auto targetFn = runtime->lookupFunction(0x1CE110u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D14C4u; }
        if (ctx->pc != 0x1D14C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CE110_0x1ce110(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D14C4u; }
        if (ctx->pc != 0x1D14C4u) { return; }
    }
    ctx->pc = 0x1D14C4u;
label_1d14c4:
    // 0x1d14c4: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1D14C4u;
    {
        const bool branch_taken_0x1d14c4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D14C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D14C4u;
            // 0x1d14c8: 0xdfbf0040  ld          $ra, 0x40($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d14c4) {
            ctx->pc = 0x1D14E0u;
            goto label_1d14e0;
        }
    }
    ctx->pc = 0x1D14CCu;
label_1d14cc:
    // 0x1d14cc: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x1d14ccu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d14d0: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1d14d0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d14d4: 0xc06aab4  jal         func_1AAAD0
    ctx->pc = 0x1D14D4u;
    SET_GPR_U32(ctx, 31, 0x1D14DCu);
    ctx->pc = 0x1D14D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D14D4u;
            // 0x1d14d8: 0x24070003  addiu       $a3, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AAAD0u;
    if (runtime->hasFunction(0x1AAAD0u)) {
        auto targetFn = runtime->lookupFunction(0x1AAAD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D14DCu; }
        if (ctx->pc != 0x1D14DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AAAD0_0x1aaad0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D14DCu; }
        if (ctx->pc != 0x1D14DCu) { return; }
    }
    ctx->pc = 0x1D14DCu;
label_1d14dc:
    // 0x1d14dc: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x1d14dcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
label_1d14e0:
    // 0x1d14e0: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1d14e0u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1d14e4: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1d14e4u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d14e8: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d14e8u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d14ec: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d14ecu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d14f0: 0x3e00008  jr          $ra
    ctx->pc = 0x1D14F0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D14F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D14F0u;
            // 0x1d14f4: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D06E0u: goto label_1d06e0;
            case 0x1D0754u: goto label_1d0754;
            case 0x1D0760u: goto label_1d0760;
            case 0x1D076Cu: goto label_1d076c;
            case 0x1D0778u: goto label_1d0778;
            case 0x1D0784u: goto label_1d0784;
            case 0x1D0790u: goto label_1d0790;
            case 0x1D079Cu: goto label_1d079c;
            case 0x1D07A8u: goto label_1d07a8;
            case 0x1D07C0u: goto label_1d07c0;
            case 0x1D07DCu: goto label_1d07dc;
            case 0x1D0840u: goto label_1d0840;
            case 0x1D0848u: goto label_1d0848;
            case 0x1D0858u: goto label_1d0858;
            case 0x1D0860u: goto label_1d0860;
            case 0x1D0870u: goto label_1d0870;
            case 0x1D089Cu: goto label_1d089c;
            case 0x1D08C8u: goto label_1d08c8;
            case 0x1D08E4u: goto label_1d08e4;
            case 0x1D08F8u: goto label_1d08f8;
            case 0x1D0960u: goto label_1d0960;
            case 0x1D0964u: goto label_1d0964;
            case 0x1D0998u: goto label_1d0998;
            case 0x1D09A4u: goto label_1d09a4;
            case 0x1D09C8u: goto label_1d09c8;
            case 0x1D09D0u: goto label_1d09d0;
            case 0x1D09D8u: goto label_1d09d8;
            case 0x1D09FCu: goto label_1d09fc;
            case 0x1D0A3Cu: goto label_1d0a3c;
            case 0x1D0A4Cu: goto label_1d0a4c;
            case 0x1D0A50u: goto label_1d0a50;
            case 0x1D0ABCu: goto label_1d0abc;
            case 0x1D0AC4u: goto label_1d0ac4;
            case 0x1D0AD8u: goto label_1d0ad8;
            case 0x1D0AECu: goto label_1d0aec;
            case 0x1D0B20u: goto label_1d0b20;
            case 0x1D0B34u: goto label_1d0b34;
            case 0x1D0B40u: goto label_1d0b40;
            case 0x1D0B54u: goto label_1d0b54;
            case 0x1D0B8Cu: goto label_1d0b8c;
            case 0x1D0B98u: goto label_1d0b98;
            case 0x1D0BA4u: goto label_1d0ba4;
            case 0x1D0BB0u: goto label_1d0bb0;
            case 0x1D0BBCu: goto label_1d0bbc;
            case 0x1D0BC8u: goto label_1d0bc8;
            case 0x1D0BD4u: goto label_1d0bd4;
            case 0x1D0BE0u: goto label_1d0be0;
            case 0x1D0BECu: goto label_1d0bec;
            case 0x1D0C00u: goto label_1d0c00;
            case 0x1D0C38u: goto label_1d0c38;
            case 0x1D0C40u: goto label_1d0c40;
            case 0x1D0C50u: goto label_1d0c50;
            case 0x1D0C68u: goto label_1d0c68;
            case 0x1D0C6Cu: goto label_1d0c6c;
            case 0x1D0CC4u: goto label_1d0cc4;
            case 0x1D0CD0u: goto label_1d0cd0;
            case 0x1D0CDCu: goto label_1d0cdc;
            case 0x1D0CE8u: goto label_1d0ce8;
            case 0x1D0CF4u: goto label_1d0cf4;
            case 0x1D0D00u: goto label_1d0d00;
            case 0x1D0D0Cu: goto label_1d0d0c;
            case 0x1D0D18u: goto label_1d0d18;
            case 0x1D0D38u: goto label_1d0d38;
            case 0x1D0D6Cu: goto label_1d0d6c;
            case 0x1D0DB4u: goto label_1d0db4;
            case 0x1D0DF8u: goto label_1d0df8;
            case 0x1D0E0Cu: goto label_1d0e0c;
            case 0x1D0E14u: goto label_1d0e14;
            case 0x1D0E38u: goto label_1d0e38;
            case 0x1D0E44u: goto label_1d0e44;
            case 0x1D0E48u: goto label_1d0e48;
            case 0x1D0E70u: goto label_1d0e70;
            case 0x1D0EA8u: goto label_1d0ea8;
            case 0x1D0EFCu: goto label_1d0efc;
            case 0x1D0F04u: goto label_1d0f04;
            case 0x1D0F0Cu: goto label_1d0f0c;
            case 0x1D0F38u: goto label_1d0f38;
            case 0x1D0F40u: goto label_1d0f40;
            case 0x1D0F5Cu: goto label_1d0f5c;
            case 0x1D0F78u: goto label_1d0f78;
            case 0x1D0F94u: goto label_1d0f94;
            case 0x1D0F9Cu: goto label_1d0f9c;
            case 0x1D0FBCu: goto label_1d0fbc;
            case 0x1D0FC4u: goto label_1d0fc4;
            case 0x1D0FE4u: goto label_1d0fe4;
            case 0x1D1004u: goto label_1d1004;
            case 0x1D100Cu: goto label_1d100c;
            case 0x1D1048u: goto label_1d1048;
            case 0x1D1054u: goto label_1d1054;
            case 0x1D1060u: goto label_1d1060;
            case 0x1D106Cu: goto label_1d106c;
            case 0x1D1078u: goto label_1d1078;
            case 0x1D1084u: goto label_1d1084;
            case 0x1D1090u: goto label_1d1090;
            case 0x1D109Cu: goto label_1d109c;
            case 0x1D10A8u: goto label_1d10a8;
            case 0x1D10B4u: goto label_1d10b4;
            case 0x1D10C8u: goto label_1d10c8;
            case 0x1D1100u: goto label_1d1100;
            case 0x1D1108u: goto label_1d1108;
            case 0x1D1114u: goto label_1d1114;
            case 0x1D112Cu: goto label_1d112c;
            case 0x1D1144u: goto label_1d1144;
            case 0x1D1190u: goto label_1d1190;
            case 0x1D11A8u: goto label_1d11a8;
            case 0x1D11D0u: goto label_1d11d0;
            case 0x1D11D4u: goto label_1d11d4;
            case 0x1D11E8u: goto label_1d11e8;
            case 0x1D1200u: goto label_1d1200;
            case 0x1D120Cu: goto label_1d120c;
            case 0x1D123Cu: goto label_1d123c;
            case 0x1D1248u: goto label_1d1248;
            case 0x1D1254u: goto label_1d1254;
            case 0x1D1260u: goto label_1d1260;
            case 0x1D126Cu: goto label_1d126c;
            case 0x1D1278u: goto label_1d1278;
            case 0x1D1284u: goto label_1d1284;
            case 0x1D1290u: goto label_1d1290;
            case 0x1D129Cu: goto label_1d129c;
            case 0x1D12A8u: goto label_1d12a8;
            case 0x1D12B8u: goto label_1d12b8;
            case 0x1D12D4u: goto label_1d12d4;
            case 0x1D12E8u: goto label_1d12e8;
            case 0x1D1308u: goto label_1d1308;
            case 0x1D1368u: goto label_1d1368;
            case 0x1D1370u: goto label_1d1370;
            case 0x1D1388u: goto label_1d1388;
            case 0x1D139Cu: goto label_1d139c;
            case 0x1D13A0u: goto label_1d13a0;
            case 0x1D13B4u: goto label_1d13b4;
            case 0x1D141Cu: goto label_1d141c;
            case 0x1D1428u: goto label_1d1428;
            case 0x1D1434u: goto label_1d1434;
            case 0x1D1440u: goto label_1d1440;
            case 0x1D144Cu: goto label_1d144c;
            case 0x1D1458u: goto label_1d1458;
            case 0x1D1464u: goto label_1d1464;
            case 0x1D1470u: goto label_1d1470;
            case 0x1D147Cu: goto label_1d147c;
            case 0x1D148Cu: goto label_1d148c;
            case 0x1D14C4u: goto label_1d14c4;
            case 0x1D14CCu: goto label_1d14cc;
            case 0x1D14DCu: goto label_1d14dc;
            case 0x1D14E0u: goto label_1d14e0;
            case 0x1D1570u: goto label_1d1570;
            case 0x1D15ACu: goto label_1d15ac;
            case 0x1D15F4u: goto label_1d15f4;
            case 0x1D1604u: goto label_1d1604;
            case 0x1D160Cu: goto label_1d160c;
            case 0x1D163Cu: goto label_1d163c;
            case 0x1D1654u: goto label_1d1654;
            case 0x1D165Cu: goto label_1d165c;
            case 0x1D1670u: goto label_1d1670;
            case 0x1D1678u: goto label_1d1678;
            case 0x1D1688u: goto label_1d1688;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D14F8u;
    // 0x1d14f8: 0x0  nop
    ctx->pc = 0x1d14f8u;
    // NOP
    // 0x1d14fc: 0x0  nop
    ctx->pc = 0x1d14fcu;
    // NOP
    // 0x1d1500: 0x27bdfee0  addiu       $sp, $sp, -0x120
    ctx->pc = 0x1d1500u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967008));
    // 0x1d1504: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d1504u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d1508: 0xffbf0090  sd          $ra, 0x90($sp)
    ctx->pc = 0x1d1508u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 31));
    // 0x1d150c: 0x7fbe0080  sq          $fp, 0x80($sp)
    ctx->pc = 0x1d150cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 128), GPR_VEC(ctx, 30));
    // 0x1d1510: 0x7fb70070  sq          $s7, 0x70($sp)
    ctx->pc = 0x1d1510u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 112), GPR_VEC(ctx, 23));
    // 0x1d1514: 0x7fb60060  sq          $s6, 0x60($sp)
    ctx->pc = 0x1d1514u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 96), GPR_VEC(ctx, 22));
    // 0x1d1518: 0x120b82d  daddu       $s7, $t1, $zero
    ctx->pc = 0x1d1518u;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d151c: 0x7fb50050  sq          $s5, 0x50($sp)
    ctx->pc = 0x1d151cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 21));
    // 0x1d1520: 0xa0b02d  daddu       $s6, $a1, $zero
    ctx->pc = 0x1d1520u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1524: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1d1524u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1d1528: 0x2405ffc0  addiu       $a1, $zero, -0x40
    ctx->pc = 0x1d1528u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967232));
    // 0x1d152c: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1d152cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1d1530: 0xa02d  daddu       $s4, $zero, $zero
    ctx->pc = 0x1d1530u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1534: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1d1534u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1d1538: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d1538u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d153c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d153cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d1540: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1d1540u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1544: 0xafa600fc  sw          $a2, 0xFC($sp)
    ctx->pc = 0x1d1544u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 252), GPR_U32(ctx, 6));
    // 0x1d1548: 0xe0802d  daddu       $s0, $a3, $zero
    ctx->pc = 0x1d1548u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d154c: 0x8ce30004  lw          $v1, 0x4($a3)
    ctx->pc = 0x1d154cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 4)));
    // 0x1d1550: 0x8c26440c  lw          $a2, 0x440C($at)
    ctx->pc = 0x1d1550u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1d1554: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1d1554u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1d1558: 0xafa300d0  sw          $v1, 0xD0($sp)
    ctx->pc = 0x1d1558u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 208), GPR_U32(ctx, 3));
    // 0x1d155c: 0xc81821  addu        $v1, $a2, $t0
    ctx->pc = 0x1d155cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x1d1560: 0x2463003f  addiu       $v1, $v1, 0x3F
    ctx->pc = 0x1d1560u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 63));
    // 0x1d1564: 0x651824  and         $v1, $v1, $a1
    ctx->pc = 0x1d1564u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 5));
    // 0x1d1568: 0x10000043  b           . + 4 + (0x43 << 2)
    ctx->pc = 0x1D1568u;
    {
        const bool branch_taken_0x1d1568 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D156Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1568u;
            // 0x1d156c: 0xafa300c0  sw          $v1, 0xC0($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 192), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d1568) {
            ctx->pc = 0x1D1678u;
            goto label_1d1678;
        }
    }
    ctx->pc = 0x1D1570u;
label_1d1570:
    // 0x1d1570: 0x8fa300d0  lw          $v1, 0xD0($sp)
    ctx->pc = 0x1d1570u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 208)));
    // 0x1d1574: 0x203082b  sltu        $at, $s0, $v1
    ctx->pc = 0x1d1574u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x1d1578: 0x10200043  beqz        $at, . + 4 + (0x43 << 2)
    ctx->pc = 0x1D1578u;
    {
        const bool branch_taken_0x1d1578 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d1578) {
            ctx->pc = 0x1D1688u;
            goto label_1d1688;
        }
    }
    ctx->pc = 0x1D1580u;
    // 0x1d1580: 0x8e1e0000  lw          $fp, 0x0($s0)
    ctx->pc = 0x1d1580u;
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1d1584: 0x13c0003a  beqz        $fp, . + 4 + (0x3A << 2)
    ctx->pc = 0x1D1584u;
    {
        const bool branch_taken_0x1d1584 = (GPR_U64(ctx, 30) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D1588u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1584u;
            // 0x1d1588: 0x26830001  addiu       $v1, $s4, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 20), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d1584) {
            ctx->pc = 0x1D1670u;
            goto label_1d1670;
        }
    }
    ctx->pc = 0x1D158Cu;
    // 0x1d158c: 0x8fa300fc  lw          $v1, 0xFC($sp)
    ctx->pc = 0x1d158cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 252)));
    // 0x1d1590: 0x982d  daddu       $s3, $zero, $zero
    ctx->pc = 0x1d1590u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1594: 0x831818  mult        $v1, $a0, $v1
    ctx->pc = 0x1d1594u;
    { int64_t result = (int64_t)GPR_S32(ctx, 4) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x1d1598: 0xafa300b0  sw          $v1, 0xB0($sp)
    ctx->pc = 0x1d1598u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 176), GPR_U32(ctx, 3));
    // 0x1d159c: 0x8e030004  lw          $v1, 0x4($s0)
    ctx->pc = 0x1d159cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1d15a0: 0x711821  addu        $v1, $v1, $s1
    ctx->pc = 0x1d15a0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 17)));
    // 0x1d15a4: 0x1000002d  b           . + 4 + (0x2D << 2)
    ctx->pc = 0x1D15A4u;
    {
        const bool branch_taken_0x1d15a4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D15A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D15A4u;
            // 0x1d15a8: 0xafa300e0  sw          $v1, 0xE0($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 224), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d15a4) {
            ctx->pc = 0x1D165Cu;
            goto label_1d165c;
        }
    }
    ctx->pc = 0x1D15ACu;
label_1d15ac:
    // 0x1d15ac: 0x2404ffff  addiu       $a0, $zero, -0x1
    ctx->pc = 0x1d15acu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d15b0: 0x32880  sll         $a1, $v1, 2
    ctx->pc = 0x1d15b0u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1d15b4: 0x8fa300e0  lw          $v1, 0xE0($sp)
    ctx->pc = 0x1d15b4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 224)));
    // 0x1d15b8: 0x651821  addu        $v1, $v1, $a1
    ctx->pc = 0x1d15b8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x1d15bc: 0x8c630000  lw          $v1, 0x0($v1)
    ctx->pc = 0x1d15bcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1d15c0: 0x10640024  beq         $v1, $a0, . + 4 + (0x24 << 2)
    ctx->pc = 0x1D15C0u;
    {
        const bool branch_taken_0x1d15c0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        ctx->pc = 0x1D15C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D15C0u;
            // 0x1d15c4: 0x223a821  addu        $s5, $s1, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d15c0) {
            ctx->pc = 0x1D1654u;
            goto label_1d1654;
        }
    }
    ctx->pc = 0x1D15C8u;
    // 0x1d15c8: 0x8ea30000  lw          $v1, 0x0($s5)
    ctx->pc = 0x1d15c8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 0)));
    // 0x1d15cc: 0x14640009  bne         $v1, $a0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1D15CCu;
    {
        const bool branch_taken_0x1d15cc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 4));
        if (branch_taken_0x1d15cc) {
            ctx->pc = 0x1D15F4u;
            goto label_1d15f4;
        }
    }
    ctx->pc = 0x1D15D4u;
    // 0x1d15d4: 0x8fa300b0  lw          $v1, 0xB0($sp)
    ctx->pc = 0x1d15d4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 176)));
    // 0x1d15d8: 0x8ea40004  lw          $a0, 0x4($s5)
    ctx->pc = 0x1d15d8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 4)));
    // 0x1d15dc: 0x2431821  addu        $v1, $s2, $v1
    ctx->pc = 0x1d15dcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 3)));
    // 0x1d15e0: 0x2e31821  addu        $v1, $s7, $v1
    ctx->pc = 0x1d15e0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 23), GPR_U32(ctx, 3)));
    // 0x1d15e4: 0x31840  sll         $v1, $v1, 1
    ctx->pc = 0x1d15e4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1d15e8: 0x2c31821  addu        $v1, $s6, $v1
    ctx->pc = 0x1d15e8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 3)));
    // 0x1d15ec: 0x10000019  b           . + 4 + (0x19 << 2)
    ctx->pc = 0x1D15ECu;
    {
        const bool branch_taken_0x1d15ec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D15F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D15ECu;
            // 0x1d15f0: 0xa4640004  sh          $a0, 0x4($v1) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 3), 4), (uint16_t)GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d15ec) {
            ctx->pc = 0x1D1654u;
            goto label_1d1654;
        }
    }
    ctx->pc = 0x1D15F4u;
label_1d15f4:
    // 0x1d15f4: 0x8fa500c0  lw          $a1, 0xC0($sp)
    ctx->pc = 0x1d15f4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 192)));
    // 0x1d15f8: 0x27a40100  addiu       $a0, $sp, 0x100
    ctx->pc = 0x1d15f8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 256));
    // 0x1d15fc: 0xc074d54  jal         func_1D3550
    ctx->pc = 0x1D15FCu;
    SET_GPR_U32(ctx, 31, 0x1D1604u);
    ctx->pc = 0x1D1600u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D15FCu;
            // 0x1d1600: 0x2a0302d  daddu       $a2, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D3550u;
    if (runtime->hasFunction(0x1D3550u)) {
        auto targetFn = runtime->lookupFunction(0x1D3550u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1604u; }
        if (ctx->pc != 0x1D1604u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D3550_0x1d3550(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1604u; }
        if (ctx->pc != 0x1D1604u) { return; }
    }
    ctx->pc = 0x1D1604u;
label_1d1604:
    // 0x1d1604: 0xc064940  jal         func_192500
    ctx->pc = 0x1D1604u;
    SET_GPR_U32(ctx, 31, 0x1D160Cu);
    ctx->pc = 0x1D1608u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1604u;
            // 0x1d1608: 0x27a40100  addiu       $a0, $sp, 0x100 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 256));
        ctx->in_delay_slot = false;
    ctx->pc = 0x192500u;
    if (runtime->hasFunction(0x192500u)) {
        auto targetFn = runtime->lookupFunction(0x192500u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D160Cu; }
        if (ctx->pc != 0x1D160Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00192500_0x192500(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D160Cu; }
        if (ctx->pc != 0x1D160Cu) { return; }
    }
    ctx->pc = 0x1D160Cu;
label_1d160c:
    // 0x1d160c: 0x8fa300b0  lw          $v1, 0xB0($sp)
    ctx->pc = 0x1d160cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 176)));
    // 0x1d1610: 0x2431821  addu        $v1, $s2, $v1
    ctx->pc = 0x1d1610u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 3)));
    // 0x1d1614: 0x2e31821  addu        $v1, $s7, $v1
    ctx->pc = 0x1d1614u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 23), GPR_U32(ctx, 3)));
    // 0x1d1618: 0x31840  sll         $v1, $v1, 1
    ctx->pc = 0x1d1618u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1d161c: 0x2c32021  addu        $a0, $s6, $v1
    ctx->pc = 0x1d161cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 3)));
    // 0x1d1620: 0x24830004  addiu       $v1, $a0, 0x4
    ctx->pc = 0x1d1620u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1d1624: 0xafa300a0  sw          $v1, 0xA0($sp)
    ctx->pc = 0x1d1624u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 160), GPR_U32(ctx, 3));
    // 0x1d1628: 0x94830004  lhu         $v1, 0x4($a0)
    ctx->pc = 0x1d1628u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1d162c: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D162Cu;
    {
        const bool branch_taken_0x1d162c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D1630u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D162Cu;
            // 0x1d1630: 0x3052ffff  andi        $s2, $v0, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 18, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d162c) {
            ctx->pc = 0x1D163Cu;
            goto label_1d163c;
        }
    }
    ctx->pc = 0x1D1634u;
    // 0x1d1634: 0xc064968  jal         func_1925A0
    ctx->pc = 0x1D1634u;
    SET_GPR_U32(ctx, 31, 0x1D163Cu);
    ctx->pc = 0x1D1638u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1634u;
            // 0x1d1638: 0x3064ffff  andi        $a0, $v1, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1925A0u;
    if (runtime->hasFunction(0x1925A0u)) {
        auto targetFn = runtime->lookupFunction(0x1925A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D163Cu; }
        if (ctx->pc != 0x1D163Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001925A0_0x1925a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D163Cu; }
        if (ctx->pc != 0x1D163Cu) { return; }
    }
    ctx->pc = 0x1D163Cu;
label_1d163c:
    // 0x1d163c: 0x8fa300a0  lw          $v1, 0xA0($sp)
    ctx->pc = 0x1d163cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x1d1640: 0x2404ffff  addiu       $a0, $zero, -0x1
    ctx->pc = 0x1d1640u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d1644: 0xa4720000  sh          $s2, 0x0($v1)
    ctx->pc = 0x1d1644u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 0), (uint16_t)GPR_U32(ctx, 18));
    // 0x1d1648: 0x3243ffff  andi        $v1, $s2, 0xFFFF
    ctx->pc = 0x1d1648u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 18) & (uint64_t)(uint16_t)65535);
    // 0x1d164c: 0xaea40000  sw          $a0, 0x0($s5)
    ctx->pc = 0x1d164cu;
    WRITE32(ADD32(GPR_U32(ctx, 21), 0), GPR_U32(ctx, 4));
    // 0x1d1650: 0xaea30004  sw          $v1, 0x4($s5)
    ctx->pc = 0x1d1650u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 4), GPR_U32(ctx, 3));
label_1d1654:
    // 0x1d1654: 0x26630001  addiu       $v1, $s3, 0x1
    ctx->pc = 0x1d1654u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
    // 0x1d1658: 0x3073ffff  andi        $s3, $v1, 0xFFFF
    ctx->pc = 0x1d1658u;
    SET_GPR_U64(ctx, 19, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)65535);
label_1d165c:
    // 0x1d165c: 0x3272ffff  andi        $s2, $s3, 0xFFFF
    ctx->pc = 0x1d165cu;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 19) & (uint64_t)(uint16_t)65535);
    // 0x1d1660: 0x25e182b  sltu        $v1, $s2, $fp
    ctx->pc = 0x1d1660u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 18) < (uint64_t)GPR_U64(ctx, 30)) ? 1 : 0);
    // 0x1d1664: 0x1460ffd1  bnez        $v1, . + 4 + (-0x2F << 2)
    ctx->pc = 0x1D1664u;
    {
        const bool branch_taken_0x1d1664 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D1668u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1664u;
            // 0x1d1668: 0x3263ffff  andi        $v1, $s3, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 19) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d1664) {
            ctx->pc = 0x1D15ACu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d15ac;
        }
    }
    ctx->pc = 0x1D166Cu;
    // 0x1d166c: 0x26830001  addiu       $v1, $s4, 0x1
    ctx->pc = 0x1d166cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 20), 1));
label_1d1670:
    // 0x1d1670: 0x26100008  addiu       $s0, $s0, 0x8
    ctx->pc = 0x1d1670u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 8));
    // 0x1d1674: 0x3074ffff  andi        $s4, $v1, 0xFFFF
    ctx->pc = 0x1d1674u;
    SET_GPR_U64(ctx, 20, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)65535);
label_1d1678:
    // 0x1d1678: 0x3284ffff  andi        $a0, $s4, 0xFFFF
    ctx->pc = 0x1d1678u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 20) & (uint64_t)(uint16_t)65535);
    // 0x1d167c: 0x28830008  slti        $v1, $a0, 0x8
    ctx->pc = 0x1d167cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0x1d1680: 0x1460ffbb  bnez        $v1, . + 4 + (-0x45 << 2)
    ctx->pc = 0x1D1680u;
    {
        const bool branch_taken_0x1d1680 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d1680) {
            ctx->pc = 0x1D1570u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d1570;
        }
    }
    ctx->pc = 0x1D1688u;
label_1d1688:
    // 0x1d1688: 0xdfbf0090  ld          $ra, 0x90($sp)
    ctx->pc = 0x1d1688u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x1d168c: 0x7bbe0080  lq          $fp, 0x80($sp)
    ctx->pc = 0x1d168cu;
    SET_GPR_VEC(ctx, 30, READ128(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x1d1690: 0x7bb70070  lq          $s7, 0x70($sp)
    ctx->pc = 0x1d1690u;
    SET_GPR_VEC(ctx, 23, READ128(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x1d1694: 0x7bb60060  lq          $s6, 0x60($sp)
    ctx->pc = 0x1d1694u;
    SET_GPR_VEC(ctx, 22, READ128(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1d1698: 0x7bb50050  lq          $s5, 0x50($sp)
    ctx->pc = 0x1d1698u;
    SET_GPR_VEC(ctx, 21, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1d169c: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1d169cu;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1d16a0: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1d16a0u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1d16a4: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1d16a4u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d16a8: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d16a8u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d16ac: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d16acu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d16b0: 0x3e00008  jr          $ra
    ctx->pc = 0x1D16B0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D16B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D16B0u;
            // 0x1d16b4: 0x27bd0120  addiu       $sp, $sp, 0x120 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 288));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D06E0u: goto label_1d06e0;
            case 0x1D0754u: goto label_1d0754;
            case 0x1D0760u: goto label_1d0760;
            case 0x1D076Cu: goto label_1d076c;
            case 0x1D0778u: goto label_1d0778;
            case 0x1D0784u: goto label_1d0784;
            case 0x1D0790u: goto label_1d0790;
            case 0x1D079Cu: goto label_1d079c;
            case 0x1D07A8u: goto label_1d07a8;
            case 0x1D07C0u: goto label_1d07c0;
            case 0x1D07DCu: goto label_1d07dc;
            case 0x1D0840u: goto label_1d0840;
            case 0x1D0848u: goto label_1d0848;
            case 0x1D0858u: goto label_1d0858;
            case 0x1D0860u: goto label_1d0860;
            case 0x1D0870u: goto label_1d0870;
            case 0x1D089Cu: goto label_1d089c;
            case 0x1D08C8u: goto label_1d08c8;
            case 0x1D08E4u: goto label_1d08e4;
            case 0x1D08F8u: goto label_1d08f8;
            case 0x1D0960u: goto label_1d0960;
            case 0x1D0964u: goto label_1d0964;
            case 0x1D0998u: goto label_1d0998;
            case 0x1D09A4u: goto label_1d09a4;
            case 0x1D09C8u: goto label_1d09c8;
            case 0x1D09D0u: goto label_1d09d0;
            case 0x1D09D8u: goto label_1d09d8;
            case 0x1D09FCu: goto label_1d09fc;
            case 0x1D0A3Cu: goto label_1d0a3c;
            case 0x1D0A4Cu: goto label_1d0a4c;
            case 0x1D0A50u: goto label_1d0a50;
            case 0x1D0ABCu: goto label_1d0abc;
            case 0x1D0AC4u: goto label_1d0ac4;
            case 0x1D0AD8u: goto label_1d0ad8;
            case 0x1D0AECu: goto label_1d0aec;
            case 0x1D0B20u: goto label_1d0b20;
            case 0x1D0B34u: goto label_1d0b34;
            case 0x1D0B40u: goto label_1d0b40;
            case 0x1D0B54u: goto label_1d0b54;
            case 0x1D0B8Cu: goto label_1d0b8c;
            case 0x1D0B98u: goto label_1d0b98;
            case 0x1D0BA4u: goto label_1d0ba4;
            case 0x1D0BB0u: goto label_1d0bb0;
            case 0x1D0BBCu: goto label_1d0bbc;
            case 0x1D0BC8u: goto label_1d0bc8;
            case 0x1D0BD4u: goto label_1d0bd4;
            case 0x1D0BE0u: goto label_1d0be0;
            case 0x1D0BECu: goto label_1d0bec;
            case 0x1D0C00u: goto label_1d0c00;
            case 0x1D0C38u: goto label_1d0c38;
            case 0x1D0C40u: goto label_1d0c40;
            case 0x1D0C50u: goto label_1d0c50;
            case 0x1D0C68u: goto label_1d0c68;
            case 0x1D0C6Cu: goto label_1d0c6c;
            case 0x1D0CC4u: goto label_1d0cc4;
            case 0x1D0CD0u: goto label_1d0cd0;
            case 0x1D0CDCu: goto label_1d0cdc;
            case 0x1D0CE8u: goto label_1d0ce8;
            case 0x1D0CF4u: goto label_1d0cf4;
            case 0x1D0D00u: goto label_1d0d00;
            case 0x1D0D0Cu: goto label_1d0d0c;
            case 0x1D0D18u: goto label_1d0d18;
            case 0x1D0D38u: goto label_1d0d38;
            case 0x1D0D6Cu: goto label_1d0d6c;
            case 0x1D0DB4u: goto label_1d0db4;
            case 0x1D0DF8u: goto label_1d0df8;
            case 0x1D0E0Cu: goto label_1d0e0c;
            case 0x1D0E14u: goto label_1d0e14;
            case 0x1D0E38u: goto label_1d0e38;
            case 0x1D0E44u: goto label_1d0e44;
            case 0x1D0E48u: goto label_1d0e48;
            case 0x1D0E70u: goto label_1d0e70;
            case 0x1D0EA8u: goto label_1d0ea8;
            case 0x1D0EFCu: goto label_1d0efc;
            case 0x1D0F04u: goto label_1d0f04;
            case 0x1D0F0Cu: goto label_1d0f0c;
            case 0x1D0F38u: goto label_1d0f38;
            case 0x1D0F40u: goto label_1d0f40;
            case 0x1D0F5Cu: goto label_1d0f5c;
            case 0x1D0F78u: goto label_1d0f78;
            case 0x1D0F94u: goto label_1d0f94;
            case 0x1D0F9Cu: goto label_1d0f9c;
            case 0x1D0FBCu: goto label_1d0fbc;
            case 0x1D0FC4u: goto label_1d0fc4;
            case 0x1D0FE4u: goto label_1d0fe4;
            case 0x1D1004u: goto label_1d1004;
            case 0x1D100Cu: goto label_1d100c;
            case 0x1D1048u: goto label_1d1048;
            case 0x1D1054u: goto label_1d1054;
            case 0x1D1060u: goto label_1d1060;
            case 0x1D106Cu: goto label_1d106c;
            case 0x1D1078u: goto label_1d1078;
            case 0x1D1084u: goto label_1d1084;
            case 0x1D1090u: goto label_1d1090;
            case 0x1D109Cu: goto label_1d109c;
            case 0x1D10A8u: goto label_1d10a8;
            case 0x1D10B4u: goto label_1d10b4;
            case 0x1D10C8u: goto label_1d10c8;
            case 0x1D1100u: goto label_1d1100;
            case 0x1D1108u: goto label_1d1108;
            case 0x1D1114u: goto label_1d1114;
            case 0x1D112Cu: goto label_1d112c;
            case 0x1D1144u: goto label_1d1144;
            case 0x1D1190u: goto label_1d1190;
            case 0x1D11A8u: goto label_1d11a8;
            case 0x1D11D0u: goto label_1d11d0;
            case 0x1D11D4u: goto label_1d11d4;
            case 0x1D11E8u: goto label_1d11e8;
            case 0x1D1200u: goto label_1d1200;
            case 0x1D120Cu: goto label_1d120c;
            case 0x1D123Cu: goto label_1d123c;
            case 0x1D1248u: goto label_1d1248;
            case 0x1D1254u: goto label_1d1254;
            case 0x1D1260u: goto label_1d1260;
            case 0x1D126Cu: goto label_1d126c;
            case 0x1D1278u: goto label_1d1278;
            case 0x1D1284u: goto label_1d1284;
            case 0x1D1290u: goto label_1d1290;
            case 0x1D129Cu: goto label_1d129c;
            case 0x1D12A8u: goto label_1d12a8;
            case 0x1D12B8u: goto label_1d12b8;
            case 0x1D12D4u: goto label_1d12d4;
            case 0x1D12E8u: goto label_1d12e8;
            case 0x1D1308u: goto label_1d1308;
            case 0x1D1368u: goto label_1d1368;
            case 0x1D1370u: goto label_1d1370;
            case 0x1D1388u: goto label_1d1388;
            case 0x1D139Cu: goto label_1d139c;
            case 0x1D13A0u: goto label_1d13a0;
            case 0x1D13B4u: goto label_1d13b4;
            case 0x1D141Cu: goto label_1d141c;
            case 0x1D1428u: goto label_1d1428;
            case 0x1D1434u: goto label_1d1434;
            case 0x1D1440u: goto label_1d1440;
            case 0x1D144Cu: goto label_1d144c;
            case 0x1D1458u: goto label_1d1458;
            case 0x1D1464u: goto label_1d1464;
            case 0x1D1470u: goto label_1d1470;
            case 0x1D147Cu: goto label_1d147c;
            case 0x1D148Cu: goto label_1d148c;
            case 0x1D14C4u: goto label_1d14c4;
            case 0x1D14CCu: goto label_1d14cc;
            case 0x1D14DCu: goto label_1d14dc;
            case 0x1D14E0u: goto label_1d14e0;
            case 0x1D1570u: goto label_1d1570;
            case 0x1D15ACu: goto label_1d15ac;
            case 0x1D15F4u: goto label_1d15f4;
            case 0x1D1604u: goto label_1d1604;
            case 0x1D160Cu: goto label_1d160c;
            case 0x1D163Cu: goto label_1d163c;
            case 0x1D1654u: goto label_1d1654;
            case 0x1D165Cu: goto label_1d165c;
            case 0x1D1670u: goto label_1d1670;
            case 0x1D1678u: goto label_1d1678;
            case 0x1D1688u: goto label_1d1688;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D16B8u;
    // 0x1d16b8: 0x0  nop
    ctx->pc = 0x1d16b8u;
    // NOP
    // 0x1d16bc: 0x0  nop
    ctx->pc = 0x1d16bcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
