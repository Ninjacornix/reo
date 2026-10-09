#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E1B3C
// Address: 0x1e1b3c - 0x1e5008
void sub_001E1B3C_0x1e1b3c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E1B3C_0x1e1b3c");
#endif

    switch (ctx->pc) {
        case 0x1e1b60u: goto label_1e1b60;
        case 0x1e1bc8u: goto label_1e1bc8;
        case 0x1e1d14u: goto label_1e1d14;
        case 0x1e1de0u: goto label_1e1de0;
        case 0x1e1e14u: goto label_1e1e14;
        case 0x1e1e38u: goto label_1e1e38;
        case 0x1e1e5cu: goto label_1e1e5c;
        case 0x1e1e84u: goto label_1e1e84;
        case 0x1e1eb4u: goto label_1e1eb4;
        case 0x1e1facu: goto label_1e1fac;
        case 0x1e1fe0u: goto label_1e1fe0;
        case 0x1e2004u: goto label_1e2004;
        case 0x1e202cu: goto label_1e202c;
        case 0x1e2064u: goto label_1e2064;
        case 0x1e2088u: goto label_1e2088;
        case 0x1e20a0u: goto label_1e20a0;
        case 0x1e20d4u: goto label_1e20d4;
        case 0x1e210cu: goto label_1e210c;
        case 0x1e21f4u: goto label_1e21f4;
        case 0x1e2228u: goto label_1e2228;
        case 0x1e224cu: goto label_1e224c;
        case 0x1e22d4u: goto label_1e22d4;
        case 0x1e2304u: goto label_1e2304;
        case 0x1e2404u: goto label_1e2404;
        case 0x1e2438u: goto label_1e2438;
        case 0x1e245cu: goto label_1e245c;
        case 0x1e2480u: goto label_1e2480;
        case 0x1e24f8u: goto label_1e24f8;
        case 0x1e25d0u: goto label_1e25d0;
        case 0x1e2600u: goto label_1e2600;
        case 0x1e26e8u: goto label_1e26e8;
        case 0x1e271cu: goto label_1e271c;
        case 0x1e2740u: goto label_1e2740;
        case 0x1e27c8u: goto label_1e27c8;
        case 0x1e27f8u: goto label_1e27f8;
        case 0x1e28e0u: goto label_1e28e0;
        case 0x1e2914u: goto label_1e2914;
        case 0x1e2938u: goto label_1e2938;
        case 0x1e29c0u: goto label_1e29c0;
        case 0x1e29f0u: goto label_1e29f0;
        case 0x1e2adcu: goto label_1e2adc;
        case 0x1e2b10u: goto label_1e2b10;
        case 0x1e2b34u: goto label_1e2b34;
        case 0x1e2b54u: goto label_1e2b54;
        case 0x1e2b90u: goto label_1e2b90;
        case 0x1e2bc0u: goto label_1e2bc0;
        case 0x1e2bf8u: goto label_1e2bf8;
        case 0x1e2ce8u: goto label_1e2ce8;
        case 0x1e2d1cu: goto label_1e2d1c;
        case 0x1e2d40u: goto label_1e2d40;
        case 0x1e2e10u: goto label_1e2e10;
        case 0x1e2e48u: goto label_1e2e48;
        case 0x1e2e78u: goto label_1e2e78;
        case 0x1e2f5cu: goto label_1e2f5c;
        case 0x1e2fa8u: goto label_1e2fa8;
        case 0x1e2fd8u: goto label_1e2fd8;
        case 0x1e30bcu: goto label_1e30bc;
        case 0x1e3108u: goto label_1e3108;
        case 0x1e3138u: goto label_1e3138;
        case 0x1e3238u: goto label_1e3238;
        case 0x1e3278u: goto label_1e3278;
        case 0x1e329cu: goto label_1e329c;
        case 0x1e3318u: goto label_1e3318;
        case 0x1e33c4u: goto label_1e33c4;
        case 0x1e33f4u: goto label_1e33f4;
        case 0x1e34e0u: goto label_1e34e0;
        case 0x1e3514u: goto label_1e3514;
        case 0x1e3538u: goto label_1e3538;
        case 0x1e360cu: goto label_1e360c;
        case 0x1e363cu: goto label_1e363c;
        case 0x1e3728u: goto label_1e3728;
        case 0x1e375cu: goto label_1e375c;
        case 0x1e3780u: goto label_1e3780;
        case 0x1e3854u: goto label_1e3854;
        case 0x1e3884u: goto label_1e3884;
        case 0x1e396cu: goto label_1e396c;
        case 0x1e39a0u: goto label_1e39a0;
        case 0x1e39c4u: goto label_1e39c4;
        case 0x1e3a44u: goto label_1e3a44;
        case 0x1e3a74u: goto label_1e3a74;
        case 0x1e3b40u: goto label_1e3b40;
        case 0x1e3b84u: goto label_1e3b84;
        case 0x1e3bb4u: goto label_1e3bb4;
        case 0x1e3c80u: goto label_1e3c80;
        case 0x1e3cc4u: goto label_1e3cc4;
        case 0x1e3cfcu: goto label_1e3cfc;
        case 0x1e3dccu: goto label_1e3dcc;
        case 0x1e3e00u: goto label_1e3e00;
        case 0x1e3e24u: goto label_1e3e24;
        case 0x1e3ea4u: goto label_1e3ea4;
        case 0x1e3ed4u: goto label_1e3ed4;
        case 0x1e3fa4u: goto label_1e3fa4;
        case 0x1e3fd8u: goto label_1e3fd8;
        case 0x1e3ffcu: goto label_1e3ffc;
        case 0x1e407cu: goto label_1e407c;
        case 0x1e40acu: goto label_1e40ac;
        case 0x1e417cu: goto label_1e417c;
        case 0x1e41b0u: goto label_1e41b0;
        case 0x1e41d4u: goto label_1e41d4;
        case 0x1e4254u: goto label_1e4254;
        case 0x1e4284u: goto label_1e4284;
        case 0x1e4358u: goto label_1e4358;
        case 0x1e4394u: goto label_1e4394;
        case 0x1e43b8u: goto label_1e43b8;
        case 0x1e43e4u: goto label_1e43e4;
        case 0x1e4414u: goto label_1e4414;
        case 0x1e4444u: goto label_1e4444;
        case 0x1e452cu: goto label_1e452c;
        case 0x1e4560u: goto label_1e4560;
        case 0x1e4584u: goto label_1e4584;
        case 0x1e460cu: goto label_1e460c;
        case 0x1e463cu: goto label_1e463c;
        case 0x1e472cu: goto label_1e472c;
        case 0x1e4764u: goto label_1e4764;
        case 0x1e4788u: goto label_1e4788;
        case 0x1e47b0u: goto label_1e47b0;
        case 0x1e47e0u: goto label_1e47e0;
        case 0x1e4918u: goto label_1e4918;
        case 0x1e4974u: goto label_1e4974;
        case 0x1e4998u: goto label_1e4998;
        case 0x1e4a08u: goto label_1e4a08;
        case 0x1e4ac0u: goto label_1e4ac0;
        case 0x1e4b00u: goto label_1e4b00;
        case 0x1e4c10u: goto label_1e4c10;
        case 0x1e4c64u: goto label_1e4c64;
        case 0x1e4c88u: goto label_1e4c88;
        case 0x1e4d08u: goto label_1e4d08;
        case 0x1e4df8u: goto label_1e4df8;
        case 0x1e4e3cu: goto label_1e4e3c;
        case 0x1e4f28u: goto label_1e4f28;
        case 0x1e4f60u: goto label_1e4f60;
        case 0x1e4f84u: goto label_1e4f84;
        case 0x1e4facu: goto label_1e4fac;
        case 0x1e4fd0u: goto label_1e4fd0;
        default: break;
    }

    ctx->pc = 0x1e1b3cu;

label_1e1b3c:
    // 0x1e1b3c: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1e1b3cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1e1b40: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1e1b40u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1e1b44: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1e1b44u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1e1b48: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e1b48u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e1b4c: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e1b4cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e1b50: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1e1b50u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e1b54: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1e1b54u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e1b58: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E1B58u;
    SET_GPR_U32(ctx, 31, 0x1E1B60u);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E1B60u; }
        if (ctx->pc != 0x1E1B60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E1B60u; }
        if (ctx->pc != 0x1E1B60u) { return; }
    }
    ctx->pc = 0x1E1B60u;
label_1e1b60:
    // 0x1e1b60: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1e1b60u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
    // 0x1e1b64: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e1b64u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e1b68: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E1B68u;
    {
        const bool branch_taken_0x1e1b68 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e1b68) {
            ctx->pc = 0x1E1B84u;
            goto label_1e1b84;
        }
    }
    ctx->pc = 0x1E1B70u;
    // 0x1e1b70: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e1b70u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e1b74: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e1b74u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e1b78: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e1b78u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e1b7c: 0x1000001a  b           . + 4 + (0x1A << 2)
    ctx->pc = 0x1E1B7Cu;
    {
        const bool branch_taken_0x1e1b7c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e1b7c) {
            ctx->pc = 0x1E1BE8u;
            goto label_1e1be8;
        }
    }
    ctx->pc = 0x1E1B84u;
label_1e1b84:
    // 0x1e1b84: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e1b84u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e1b88: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e1b88u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e1b8c: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E1B8Cu;
    {
        const bool branch_taken_0x1e1b8c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e1b8c) {
            ctx->pc = 0x1E1BA8u;
            goto label_1e1ba8;
        }
    }
    ctx->pc = 0x1E1B94u;
    // 0x1e1b94: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e1b94u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e1b98: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e1b98u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e1b9c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e1b9cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e1ba0: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x1E1BA0u;
    {
        const bool branch_taken_0x1e1ba0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e1ba0) {
            ctx->pc = 0x1E1BE8u;
            goto label_1e1be8;
        }
    }
    ctx->pc = 0x1E1BA8u;
label_1e1ba8:
    // 0x1e1ba8: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1e1ba8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e1bac: 0x8fc50004  lw          $a1, 0x4($fp)
    ctx->pc = 0x1e1bacu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e1bb0: 0x3406b000  ori         $a2, $zero, 0xB000
    ctx->pc = 0x1e1bb0u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)45056);
    // 0x1e1bb4: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1e1bb4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e1bb8: 0x24080002  addiu       $t0, $zero, 0x2
    ctx->pc = 0x1e1bb8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1e1bbc: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1e1bbcu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e1bc0: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E1BC0u;
    SET_GPR_U32(ctx, 31, 0x1E1BC8u);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E1BC8u; }
        if (ctx->pc != 0x1E1BC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E1BC8u; }
        if (ctx->pc != 0x1E1BC8u) { return; }
    }
    ctx->pc = 0x1E1BC8u;
label_1e1bc8:
    // 0x1e1bc8: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E1BC8u;
    {
        const bool branch_taken_0x1e1bc8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e1bc8) {
            ctx->pc = 0x1E1BE4u;
            goto label_1e1be4;
        }
    }
    ctx->pc = 0x1E1BD0u;
    // 0x1e1bd0: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e1bd0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e1bd4: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e1bd4u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e1bd8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e1bd8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e1bdc: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1E1BDCu;
    {
        const bool branch_taken_0x1e1bdc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e1bdc) {
            ctx->pc = 0x1E1BE8u;
            goto label_1e1be8;
        }
    }
    ctx->pc = 0x1E1BE4u;
label_1e1be4:
    // 0x1e1be4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1e1be4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1e1be8:
    // 0x1e1be8: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e1be8u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e1bec: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1e1becu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1e1bf0: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1e1bf0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1e1bf4: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1e1bf4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1e1bf8: 0x3e00008  jr          $ra
    ctx->pc = 0x1E1BF8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E1B3Cu: goto label_1e1b3c;
            case 0x1E1B60u: goto label_1e1b60;
            case 0x1E1B84u: goto label_1e1b84;
            case 0x1E1BA8u: goto label_1e1ba8;
            case 0x1E1BC8u: goto label_1e1bc8;
            case 0x1E1BE4u: goto label_1e1be4;
            case 0x1E1BE8u: goto label_1e1be8;
            case 0x1E1C44u: goto label_1e1c44;
            case 0x1E1C58u: goto label_1e1c58;
            case 0x1E1C7Cu: goto label_1e1c7c;
            case 0x1E1CD8u: goto label_1e1cd8;
            case 0x1E1CECu: goto label_1e1cec;
            case 0x1E1D14u: goto label_1e1d14;
            case 0x1E1D7Cu: goto label_1e1d7c;
            case 0x1E1D90u: goto label_1e1d90;
            case 0x1E1DD0u: goto label_1e1dd0;
            case 0x1E1DE0u: goto label_1e1de0;
            case 0x1E1E04u: goto label_1e1e04;
            case 0x1E1E14u: goto label_1e1e14;
            case 0x1E1E38u: goto label_1e1e38;
            case 0x1E1E4Cu: goto label_1e1e4c;
            case 0x1E1E5Cu: goto label_1e1e5c;
            case 0x1E1E84u: goto label_1e1e84;
            case 0x1E1EA0u: goto label_1e1ea0;
            case 0x1E1EB4u: goto label_1e1eb4;
            case 0x1E1ED0u: goto label_1e1ed0;
            case 0x1E1F48u: goto label_1e1f48;
            case 0x1E1F5Cu: goto label_1e1f5c;
            case 0x1E1F9Cu: goto label_1e1f9c;
            case 0x1E1FACu: goto label_1e1fac;
            case 0x1E1FD0u: goto label_1e1fd0;
            case 0x1E1FE0u: goto label_1e1fe0;
            case 0x1E2004u: goto label_1e2004;
            case 0x1E2018u: goto label_1e2018;
            case 0x1E202Cu: goto label_1e202c;
            case 0x1E2064u: goto label_1e2064;
            case 0x1E206Cu: goto label_1e206c;
            case 0x1E2088u: goto label_1e2088;
            case 0x1E20A0u: goto label_1e20a0;
            case 0x1E20D4u: goto label_1e20d4;
            case 0x1E20F8u: goto label_1e20f8;
            case 0x1E210Cu: goto label_1e210c;
            case 0x1E2128u: goto label_1e2128;
            case 0x1E2190u: goto label_1e2190;
            case 0x1E21A4u: goto label_1e21a4;
            case 0x1E21E4u: goto label_1e21e4;
            case 0x1E21F4u: goto label_1e21f4;
            case 0x1E2218u: goto label_1e2218;
            case 0x1E2228u: goto label_1e2228;
            case 0x1E224Cu: goto label_1e224c;
            case 0x1E2260u: goto label_1e2260;
            case 0x1E22D4u: goto label_1e22d4;
            case 0x1E22F0u: goto label_1e22f0;
            case 0x1E2304u: goto label_1e2304;
            case 0x1E2320u: goto label_1e2320;
            case 0x1E23A0u: goto label_1e23a0;
            case 0x1E23B4u: goto label_1e23b4;
            case 0x1E23F4u: goto label_1e23f4;
            case 0x1E2404u: goto label_1e2404;
            case 0x1E2428u: goto label_1e2428;
            case 0x1E2438u: goto label_1e2438;
            case 0x1E245Cu: goto label_1e245c;
            case 0x1E2470u: goto label_1e2470;
            case 0x1E2480u: goto label_1e2480;
            case 0x1E24F8u: goto label_1e24f8;
            case 0x1E2500u: goto label_1e2500;
            case 0x1E2508u: goto label_1e2508;
            case 0x1E25D0u: goto label_1e25d0;
            case 0x1E25ECu: goto label_1e25ec;
            case 0x1E2600u: goto label_1e2600;
            case 0x1E261Cu: goto label_1e261c;
            case 0x1E2684u: goto label_1e2684;
            case 0x1E2698u: goto label_1e2698;
            case 0x1E26D8u: goto label_1e26d8;
            case 0x1E26E8u: goto label_1e26e8;
            case 0x1E270Cu: goto label_1e270c;
            case 0x1E271Cu: goto label_1e271c;
            case 0x1E2740u: goto label_1e2740;
            case 0x1E2754u: goto label_1e2754;
            case 0x1E27C8u: goto label_1e27c8;
            case 0x1E27E4u: goto label_1e27e4;
            case 0x1E27F8u: goto label_1e27f8;
            case 0x1E2814u: goto label_1e2814;
            case 0x1E287Cu: goto label_1e287c;
            case 0x1E2890u: goto label_1e2890;
            case 0x1E28D0u: goto label_1e28d0;
            case 0x1E28E0u: goto label_1e28e0;
            case 0x1E2904u: goto label_1e2904;
            case 0x1E2914u: goto label_1e2914;
            case 0x1E2938u: goto label_1e2938;
            case 0x1E294Cu: goto label_1e294c;
            case 0x1E29C0u: goto label_1e29c0;
            case 0x1E29DCu: goto label_1e29dc;
            case 0x1E29F0u: goto label_1e29f0;
            case 0x1E2A0Cu: goto label_1e2a0c;
            case 0x1E2A78u: goto label_1e2a78;
            case 0x1E2A8Cu: goto label_1e2a8c;
            case 0x1E2ACCu: goto label_1e2acc;
            case 0x1E2ADCu: goto label_1e2adc;
            case 0x1E2B00u: goto label_1e2b00;
            case 0x1E2B10u: goto label_1e2b10;
            case 0x1E2B34u: goto label_1e2b34;
            case 0x1E2B48u: goto label_1e2b48;
            case 0x1E2B54u: goto label_1e2b54;
            case 0x1E2B90u: goto label_1e2b90;
            case 0x1E2B98u: goto label_1e2b98;
            case 0x1E2BC0u: goto label_1e2bc0;
            case 0x1E2BE4u: goto label_1e2be4;
            case 0x1E2BF8u: goto label_1e2bf8;
            case 0x1E2C14u: goto label_1e2c14;
            case 0x1E2C84u: goto label_1e2c84;
            case 0x1E2C98u: goto label_1e2c98;
            case 0x1E2CD8u: goto label_1e2cd8;
            case 0x1E2CE8u: goto label_1e2ce8;
            case 0x1E2D0Cu: goto label_1e2d0c;
            case 0x1E2D1Cu: goto label_1e2d1c;
            case 0x1E2D40u: goto label_1e2d40;
            case 0x1E2D54u: goto label_1e2d54;
            case 0x1E2E10u: goto label_1e2e10;
            case 0x1E2E18u: goto label_1e2e18;
            case 0x1E2E20u: goto label_1e2e20;
            case 0x1E2E48u: goto label_1e2e48;
            case 0x1E2E64u: goto label_1e2e64;
            case 0x1E2E78u: goto label_1e2e78;
            case 0x1E2E94u: goto label_1e2e94;
            case 0x1E2EF8u: goto label_1e2ef8;
            case 0x1E2F0Cu: goto label_1e2f0c;
            case 0x1E2F4Cu: goto label_1e2f4c;
            case 0x1E2F5Cu: goto label_1e2f5c;
            case 0x1E2F80u: goto label_1e2f80;
            case 0x1E2FA8u: goto label_1e2fa8;
            case 0x1E2FC4u: goto label_1e2fc4;
            case 0x1E2FD8u: goto label_1e2fd8;
            case 0x1E2FF4u: goto label_1e2ff4;
            case 0x1E3058u: goto label_1e3058;
            case 0x1E306Cu: goto label_1e306c;
            case 0x1E30ACu: goto label_1e30ac;
            case 0x1E30BCu: goto label_1e30bc;
            case 0x1E30E0u: goto label_1e30e0;
            case 0x1E3108u: goto label_1e3108;
            case 0x1E3124u: goto label_1e3124;
            case 0x1E3138u: goto label_1e3138;
            case 0x1E3154u: goto label_1e3154;
            case 0x1E31CCu: goto label_1e31cc;
            case 0x1E31E0u: goto label_1e31e0;
            case 0x1E3220u: goto label_1e3220;
            case 0x1E3238u: goto label_1e3238;
            case 0x1E325Cu: goto label_1e325c;
            case 0x1E3278u: goto label_1e3278;
            case 0x1E329Cu: goto label_1e329c;
            case 0x1E32B0u: goto label_1e32b0;
            case 0x1E3318u: goto label_1e3318;
            case 0x1E3388u: goto label_1e3388;
            case 0x1E33C4u: goto label_1e33c4;
            case 0x1E33E0u: goto label_1e33e0;
            case 0x1E33F4u: goto label_1e33f4;
            case 0x1E3410u: goto label_1e3410;
            case 0x1E347Cu: goto label_1e347c;
            case 0x1E3490u: goto label_1e3490;
            case 0x1E34D0u: goto label_1e34d0;
            case 0x1E34E0u: goto label_1e34e0;
            case 0x1E3504u: goto label_1e3504;
            case 0x1E3514u: goto label_1e3514;
            case 0x1E3538u: goto label_1e3538;
            case 0x1E354Cu: goto label_1e354c;
            case 0x1E360Cu: goto label_1e360c;
            case 0x1E3628u: goto label_1e3628;
            case 0x1E363Cu: goto label_1e363c;
            case 0x1E3658u: goto label_1e3658;
            case 0x1E36C4u: goto label_1e36c4;
            case 0x1E36D8u: goto label_1e36d8;
            case 0x1E3718u: goto label_1e3718;
            case 0x1E3728u: goto label_1e3728;
            case 0x1E374Cu: goto label_1e374c;
            case 0x1E375Cu: goto label_1e375c;
            case 0x1E3780u: goto label_1e3780;
            case 0x1E3794u: goto label_1e3794;
            case 0x1E3854u: goto label_1e3854;
            case 0x1E3870u: goto label_1e3870;
            case 0x1E3884u: goto label_1e3884;
            case 0x1E38A0u: goto label_1e38a0;
            case 0x1E3908u: goto label_1e3908;
            case 0x1E391Cu: goto label_1e391c;
            case 0x1E395Cu: goto label_1e395c;
            case 0x1E396Cu: goto label_1e396c;
            case 0x1E3990u: goto label_1e3990;
            case 0x1E39A0u: goto label_1e39a0;
            case 0x1E39C4u: goto label_1e39c4;
            case 0x1E39D8u: goto label_1e39d8;
            case 0x1E3A44u: goto label_1e3a44;
            case 0x1E3A60u: goto label_1e3a60;
            case 0x1E3A74u: goto label_1e3a74;
            case 0x1E3A78u: goto label_1e3a78;
            case 0x1E3ADCu: goto label_1e3adc;
            case 0x1E3AF0u: goto label_1e3af0;
            case 0x1E3B30u: goto label_1e3b30;
            case 0x1E3B40u: goto label_1e3b40;
            case 0x1E3B64u: goto label_1e3b64;
            case 0x1E3B84u: goto label_1e3b84;
            case 0x1E3BA0u: goto label_1e3ba0;
            case 0x1E3BB4u: goto label_1e3bb4;
            case 0x1E3BB8u: goto label_1e3bb8;
            case 0x1E3C1Cu: goto label_1e3c1c;
            case 0x1E3C30u: goto label_1e3c30;
            case 0x1E3C70u: goto label_1e3c70;
            case 0x1E3C80u: goto label_1e3c80;
            case 0x1E3CA4u: goto label_1e3ca4;
            case 0x1E3CC4u: goto label_1e3cc4;
            case 0x1E3CE8u: goto label_1e3ce8;
            case 0x1E3CFCu: goto label_1e3cfc;
            case 0x1E3D00u: goto label_1e3d00;
            case 0x1E3D68u: goto label_1e3d68;
            case 0x1E3D7Cu: goto label_1e3d7c;
            case 0x1E3DBCu: goto label_1e3dbc;
            case 0x1E3DCCu: goto label_1e3dcc;
            case 0x1E3DF0u: goto label_1e3df0;
            case 0x1E3E00u: goto label_1e3e00;
            case 0x1E3E24u: goto label_1e3e24;
            case 0x1E3E38u: goto label_1e3e38;
            case 0x1E3EA4u: goto label_1e3ea4;
            case 0x1E3EC0u: goto label_1e3ec0;
            case 0x1E3ED4u: goto label_1e3ed4;
            case 0x1E3ED8u: goto label_1e3ed8;
            case 0x1E3F40u: goto label_1e3f40;
            case 0x1E3F54u: goto label_1e3f54;
            case 0x1E3F94u: goto label_1e3f94;
            case 0x1E3FA4u: goto label_1e3fa4;
            case 0x1E3FC8u: goto label_1e3fc8;
            case 0x1E3FD8u: goto label_1e3fd8;
            case 0x1E3FFCu: goto label_1e3ffc;
            case 0x1E4010u: goto label_1e4010;
            case 0x1E407Cu: goto label_1e407c;
            case 0x1E4098u: goto label_1e4098;
            case 0x1E40ACu: goto label_1e40ac;
            case 0x1E40B0u: goto label_1e40b0;
            case 0x1E4118u: goto label_1e4118;
            case 0x1E412Cu: goto label_1e412c;
            case 0x1E416Cu: goto label_1e416c;
            case 0x1E417Cu: goto label_1e417c;
            case 0x1E41A0u: goto label_1e41a0;
            case 0x1E41B0u: goto label_1e41b0;
            case 0x1E41D4u: goto label_1e41d4;
            case 0x1E41E8u: goto label_1e41e8;
            case 0x1E4254u: goto label_1e4254;
            case 0x1E4270u: goto label_1e4270;
            case 0x1E4284u: goto label_1e4284;
            case 0x1E4288u: goto label_1e4288;
            case 0x1E42F0u: goto label_1e42f0;
            case 0x1E4304u: goto label_1e4304;
            case 0x1E4344u: goto label_1e4344;
            case 0x1E4358u: goto label_1e4358;
            case 0x1E437Cu: goto label_1e437c;
            case 0x1E4394u: goto label_1e4394;
            case 0x1E43B8u: goto label_1e43b8;
            case 0x1E43CCu: goto label_1e43cc;
            case 0x1E43E4u: goto label_1e43e4;
            case 0x1E4414u: goto label_1e4414;
            case 0x1E4430u: goto label_1e4430;
            case 0x1E4444u: goto label_1e4444;
            case 0x1E4460u: goto label_1e4460;
            case 0x1E44C8u: goto label_1e44c8;
            case 0x1E44DCu: goto label_1e44dc;
            case 0x1E451Cu: goto label_1e451c;
            case 0x1E452Cu: goto label_1e452c;
            case 0x1E4550u: goto label_1e4550;
            case 0x1E4560u: goto label_1e4560;
            case 0x1E4584u: goto label_1e4584;
            case 0x1E4598u: goto label_1e4598;
            case 0x1E460Cu: goto label_1e460c;
            case 0x1E4628u: goto label_1e4628;
            case 0x1E463Cu: goto label_1e463c;
            case 0x1E4658u: goto label_1e4658;
            case 0x1E46C8u: goto label_1e46c8;
            case 0x1E46DCu: goto label_1e46dc;
            case 0x1E471Cu: goto label_1e471c;
            case 0x1E472Cu: goto label_1e472c;
            case 0x1E4750u: goto label_1e4750;
            case 0x1E4764u: goto label_1e4764;
            case 0x1E4788u: goto label_1e4788;
            case 0x1E479Cu: goto label_1e479c;
            case 0x1E47B0u: goto label_1e47b0;
            case 0x1E47E0u: goto label_1e47e0;
            case 0x1E47FCu: goto label_1e47fc;
            case 0x1E4800u: goto label_1e4800;
            case 0x1E48A0u: goto label_1e48a0;
            case 0x1E48B4u: goto label_1e48b4;
            case 0x1E48F4u: goto label_1e48f4;
            case 0x1E4918u: goto label_1e4918;
            case 0x1E493Cu: goto label_1e493c;
            case 0x1E4974u: goto label_1e4974;
            case 0x1E4998u: goto label_1e4998;
            case 0x1E49ACu: goto label_1e49ac;
            case 0x1E4A08u: goto label_1e4a08;
            case 0x1E4A24u: goto label_1e4a24;
            case 0x1E4AACu: goto label_1e4aac;
            case 0x1E4AC0u: goto label_1e4ac0;
            case 0x1E4B00u: goto label_1e4b00;
            case 0x1E4B1Cu: goto label_1e4b1c;
            case 0x1E4B20u: goto label_1e4b20;
            case 0x1E4B94u: goto label_1e4b94;
            case 0x1E4BA8u: goto label_1e4ba8;
            case 0x1E4BE8u: goto label_1e4be8;
            case 0x1E4C10u: goto label_1e4c10;
            case 0x1E4C34u: goto label_1e4c34;
            case 0x1E4C64u: goto label_1e4c64;
            case 0x1E4C88u: goto label_1e4c88;
            case 0x1E4C9Cu: goto label_1e4c9c;
            case 0x1E4D08u: goto label_1e4d08;
            case 0x1E4D28u: goto label_1e4d28;
            case 0x1E4DE4u: goto label_1e4de4;
            case 0x1E4DF8u: goto label_1e4df8;
            case 0x1E4E3Cu: goto label_1e4e3c;
            case 0x1E4E58u: goto label_1e4e58;
            case 0x1E4E5Cu: goto label_1e4e5c;
            case 0x1E4EC4u: goto label_1e4ec4;
            case 0x1E4ED8u: goto label_1e4ed8;
            case 0x1E4F18u: goto label_1e4f18;
            case 0x1E4F28u: goto label_1e4f28;
            case 0x1E4F4Cu: goto label_1e4f4c;
            case 0x1E4F60u: goto label_1e4f60;
            case 0x1E4F84u: goto label_1e4f84;
            case 0x1E4F98u: goto label_1e4f98;
            case 0x1E4FACu: goto label_1e4fac;
            case 0x1E4FD0u: goto label_1e4fd0;
            case 0x1E4FECu: goto label_1e4fec;
            case 0x1E4FF0u: goto label_1e4ff0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E1C00u;
    // 0x1e1c00: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1e1c00u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1e1c04: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1e1c04u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1e1c08: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e1c08u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e1c0c: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e1c0cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e1c10: 0xafc00004  sw          $zero, 0x4($fp)
    ctx->pc = 0x1e1c10u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 0));
    // 0x1e1c14: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e1c14u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e1c18: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e1c18u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e1c1c: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E1C1Cu;
    {
        const bool branch_taken_0x1e1c1c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e1c1c) {
            ctx->pc = 0x1E1C44u;
            goto label_1e1c44;
        }
    }
    ctx->pc = 0x1E1C24u;
    // 0x1e1c24: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e1c24u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e1c28: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e1c28u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e1c2c: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e1c2cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e1c30: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e1c30u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e1c34: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e1c34u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e1c38: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e1c38u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e1c3c: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E1C3Cu;
    {
        const bool branch_taken_0x1e1c3c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e1c3c) {
            ctx->pc = 0x1E1C58u;
            goto label_1e1c58;
        }
    }
    ctx->pc = 0x1E1C44u;
label_1e1c44:
    // 0x1e1c44: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e1c44u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e1c48: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e1c48u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e1c4c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e1c4cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e1c50: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1E1C50u;
    {
        const bool branch_taken_0x1e1c50 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e1c50) {
            ctx->pc = 0x1E1C7Cu;
            goto label_1e1c7c;
        }
    }
    ctx->pc = 0x1E1C58u;
label_1e1c58:
    // 0x1e1c58: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e1c58u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e1c5c: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e1c5cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e1c60: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e1c60u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e1c64: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e1c64u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e1c68: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e1c68u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e1c6c: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e1c6cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e1c70: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1e1c70u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
    // 0x1e1c74: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e1c74u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e1c78: 0x8c420508  lw          $v0, 0x508($v0)
    ctx->pc = 0x1e1c78u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1288)));
label_1e1c7c:
    // 0x1e1c7c: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e1c7cu;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e1c80: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1e1c80u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1e1c84: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1e1c84u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1e1c88: 0x3e00008  jr          $ra
    ctx->pc = 0x1E1C88u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E1B3Cu: goto label_1e1b3c;
            case 0x1E1B60u: goto label_1e1b60;
            case 0x1E1B84u: goto label_1e1b84;
            case 0x1E1BA8u: goto label_1e1ba8;
            case 0x1E1BC8u: goto label_1e1bc8;
            case 0x1E1BE4u: goto label_1e1be4;
            case 0x1E1BE8u: goto label_1e1be8;
            case 0x1E1C44u: goto label_1e1c44;
            case 0x1E1C58u: goto label_1e1c58;
            case 0x1E1C7Cu: goto label_1e1c7c;
            case 0x1E1CD8u: goto label_1e1cd8;
            case 0x1E1CECu: goto label_1e1cec;
            case 0x1E1D14u: goto label_1e1d14;
            case 0x1E1D7Cu: goto label_1e1d7c;
            case 0x1E1D90u: goto label_1e1d90;
            case 0x1E1DD0u: goto label_1e1dd0;
            case 0x1E1DE0u: goto label_1e1de0;
            case 0x1E1E04u: goto label_1e1e04;
            case 0x1E1E14u: goto label_1e1e14;
            case 0x1E1E38u: goto label_1e1e38;
            case 0x1E1E4Cu: goto label_1e1e4c;
            case 0x1E1E5Cu: goto label_1e1e5c;
            case 0x1E1E84u: goto label_1e1e84;
            case 0x1E1EA0u: goto label_1e1ea0;
            case 0x1E1EB4u: goto label_1e1eb4;
            case 0x1E1ED0u: goto label_1e1ed0;
            case 0x1E1F48u: goto label_1e1f48;
            case 0x1E1F5Cu: goto label_1e1f5c;
            case 0x1E1F9Cu: goto label_1e1f9c;
            case 0x1E1FACu: goto label_1e1fac;
            case 0x1E1FD0u: goto label_1e1fd0;
            case 0x1E1FE0u: goto label_1e1fe0;
            case 0x1E2004u: goto label_1e2004;
            case 0x1E2018u: goto label_1e2018;
            case 0x1E202Cu: goto label_1e202c;
            case 0x1E2064u: goto label_1e2064;
            case 0x1E206Cu: goto label_1e206c;
            case 0x1E2088u: goto label_1e2088;
            case 0x1E20A0u: goto label_1e20a0;
            case 0x1E20D4u: goto label_1e20d4;
            case 0x1E20F8u: goto label_1e20f8;
            case 0x1E210Cu: goto label_1e210c;
            case 0x1E2128u: goto label_1e2128;
            case 0x1E2190u: goto label_1e2190;
            case 0x1E21A4u: goto label_1e21a4;
            case 0x1E21E4u: goto label_1e21e4;
            case 0x1E21F4u: goto label_1e21f4;
            case 0x1E2218u: goto label_1e2218;
            case 0x1E2228u: goto label_1e2228;
            case 0x1E224Cu: goto label_1e224c;
            case 0x1E2260u: goto label_1e2260;
            case 0x1E22D4u: goto label_1e22d4;
            case 0x1E22F0u: goto label_1e22f0;
            case 0x1E2304u: goto label_1e2304;
            case 0x1E2320u: goto label_1e2320;
            case 0x1E23A0u: goto label_1e23a0;
            case 0x1E23B4u: goto label_1e23b4;
            case 0x1E23F4u: goto label_1e23f4;
            case 0x1E2404u: goto label_1e2404;
            case 0x1E2428u: goto label_1e2428;
            case 0x1E2438u: goto label_1e2438;
            case 0x1E245Cu: goto label_1e245c;
            case 0x1E2470u: goto label_1e2470;
            case 0x1E2480u: goto label_1e2480;
            case 0x1E24F8u: goto label_1e24f8;
            case 0x1E2500u: goto label_1e2500;
            case 0x1E2508u: goto label_1e2508;
            case 0x1E25D0u: goto label_1e25d0;
            case 0x1E25ECu: goto label_1e25ec;
            case 0x1E2600u: goto label_1e2600;
            case 0x1E261Cu: goto label_1e261c;
            case 0x1E2684u: goto label_1e2684;
            case 0x1E2698u: goto label_1e2698;
            case 0x1E26D8u: goto label_1e26d8;
            case 0x1E26E8u: goto label_1e26e8;
            case 0x1E270Cu: goto label_1e270c;
            case 0x1E271Cu: goto label_1e271c;
            case 0x1E2740u: goto label_1e2740;
            case 0x1E2754u: goto label_1e2754;
            case 0x1E27C8u: goto label_1e27c8;
            case 0x1E27E4u: goto label_1e27e4;
            case 0x1E27F8u: goto label_1e27f8;
            case 0x1E2814u: goto label_1e2814;
            case 0x1E287Cu: goto label_1e287c;
            case 0x1E2890u: goto label_1e2890;
            case 0x1E28D0u: goto label_1e28d0;
            case 0x1E28E0u: goto label_1e28e0;
            case 0x1E2904u: goto label_1e2904;
            case 0x1E2914u: goto label_1e2914;
            case 0x1E2938u: goto label_1e2938;
            case 0x1E294Cu: goto label_1e294c;
            case 0x1E29C0u: goto label_1e29c0;
            case 0x1E29DCu: goto label_1e29dc;
            case 0x1E29F0u: goto label_1e29f0;
            case 0x1E2A0Cu: goto label_1e2a0c;
            case 0x1E2A78u: goto label_1e2a78;
            case 0x1E2A8Cu: goto label_1e2a8c;
            case 0x1E2ACCu: goto label_1e2acc;
            case 0x1E2ADCu: goto label_1e2adc;
            case 0x1E2B00u: goto label_1e2b00;
            case 0x1E2B10u: goto label_1e2b10;
            case 0x1E2B34u: goto label_1e2b34;
            case 0x1E2B48u: goto label_1e2b48;
            case 0x1E2B54u: goto label_1e2b54;
            case 0x1E2B90u: goto label_1e2b90;
            case 0x1E2B98u: goto label_1e2b98;
            case 0x1E2BC0u: goto label_1e2bc0;
            case 0x1E2BE4u: goto label_1e2be4;
            case 0x1E2BF8u: goto label_1e2bf8;
            case 0x1E2C14u: goto label_1e2c14;
            case 0x1E2C84u: goto label_1e2c84;
            case 0x1E2C98u: goto label_1e2c98;
            case 0x1E2CD8u: goto label_1e2cd8;
            case 0x1E2CE8u: goto label_1e2ce8;
            case 0x1E2D0Cu: goto label_1e2d0c;
            case 0x1E2D1Cu: goto label_1e2d1c;
            case 0x1E2D40u: goto label_1e2d40;
            case 0x1E2D54u: goto label_1e2d54;
            case 0x1E2E10u: goto label_1e2e10;
            case 0x1E2E18u: goto label_1e2e18;
            case 0x1E2E20u: goto label_1e2e20;
            case 0x1E2E48u: goto label_1e2e48;
            case 0x1E2E64u: goto label_1e2e64;
            case 0x1E2E78u: goto label_1e2e78;
            case 0x1E2E94u: goto label_1e2e94;
            case 0x1E2EF8u: goto label_1e2ef8;
            case 0x1E2F0Cu: goto label_1e2f0c;
            case 0x1E2F4Cu: goto label_1e2f4c;
            case 0x1E2F5Cu: goto label_1e2f5c;
            case 0x1E2F80u: goto label_1e2f80;
            case 0x1E2FA8u: goto label_1e2fa8;
            case 0x1E2FC4u: goto label_1e2fc4;
            case 0x1E2FD8u: goto label_1e2fd8;
            case 0x1E2FF4u: goto label_1e2ff4;
            case 0x1E3058u: goto label_1e3058;
            case 0x1E306Cu: goto label_1e306c;
            case 0x1E30ACu: goto label_1e30ac;
            case 0x1E30BCu: goto label_1e30bc;
            case 0x1E30E0u: goto label_1e30e0;
            case 0x1E3108u: goto label_1e3108;
            case 0x1E3124u: goto label_1e3124;
            case 0x1E3138u: goto label_1e3138;
            case 0x1E3154u: goto label_1e3154;
            case 0x1E31CCu: goto label_1e31cc;
            case 0x1E31E0u: goto label_1e31e0;
            case 0x1E3220u: goto label_1e3220;
            case 0x1E3238u: goto label_1e3238;
            case 0x1E325Cu: goto label_1e325c;
            case 0x1E3278u: goto label_1e3278;
            case 0x1E329Cu: goto label_1e329c;
            case 0x1E32B0u: goto label_1e32b0;
            case 0x1E3318u: goto label_1e3318;
            case 0x1E3388u: goto label_1e3388;
            case 0x1E33C4u: goto label_1e33c4;
            case 0x1E33E0u: goto label_1e33e0;
            case 0x1E33F4u: goto label_1e33f4;
            case 0x1E3410u: goto label_1e3410;
            case 0x1E347Cu: goto label_1e347c;
            case 0x1E3490u: goto label_1e3490;
            case 0x1E34D0u: goto label_1e34d0;
            case 0x1E34E0u: goto label_1e34e0;
            case 0x1E3504u: goto label_1e3504;
            case 0x1E3514u: goto label_1e3514;
            case 0x1E3538u: goto label_1e3538;
            case 0x1E354Cu: goto label_1e354c;
            case 0x1E360Cu: goto label_1e360c;
            case 0x1E3628u: goto label_1e3628;
            case 0x1E363Cu: goto label_1e363c;
            case 0x1E3658u: goto label_1e3658;
            case 0x1E36C4u: goto label_1e36c4;
            case 0x1E36D8u: goto label_1e36d8;
            case 0x1E3718u: goto label_1e3718;
            case 0x1E3728u: goto label_1e3728;
            case 0x1E374Cu: goto label_1e374c;
            case 0x1E375Cu: goto label_1e375c;
            case 0x1E3780u: goto label_1e3780;
            case 0x1E3794u: goto label_1e3794;
            case 0x1E3854u: goto label_1e3854;
            case 0x1E3870u: goto label_1e3870;
            case 0x1E3884u: goto label_1e3884;
            case 0x1E38A0u: goto label_1e38a0;
            case 0x1E3908u: goto label_1e3908;
            case 0x1E391Cu: goto label_1e391c;
            case 0x1E395Cu: goto label_1e395c;
            case 0x1E396Cu: goto label_1e396c;
            case 0x1E3990u: goto label_1e3990;
            case 0x1E39A0u: goto label_1e39a0;
            case 0x1E39C4u: goto label_1e39c4;
            case 0x1E39D8u: goto label_1e39d8;
            case 0x1E3A44u: goto label_1e3a44;
            case 0x1E3A60u: goto label_1e3a60;
            case 0x1E3A74u: goto label_1e3a74;
            case 0x1E3A78u: goto label_1e3a78;
            case 0x1E3ADCu: goto label_1e3adc;
            case 0x1E3AF0u: goto label_1e3af0;
            case 0x1E3B30u: goto label_1e3b30;
            case 0x1E3B40u: goto label_1e3b40;
            case 0x1E3B64u: goto label_1e3b64;
            case 0x1E3B84u: goto label_1e3b84;
            case 0x1E3BA0u: goto label_1e3ba0;
            case 0x1E3BB4u: goto label_1e3bb4;
            case 0x1E3BB8u: goto label_1e3bb8;
            case 0x1E3C1Cu: goto label_1e3c1c;
            case 0x1E3C30u: goto label_1e3c30;
            case 0x1E3C70u: goto label_1e3c70;
            case 0x1E3C80u: goto label_1e3c80;
            case 0x1E3CA4u: goto label_1e3ca4;
            case 0x1E3CC4u: goto label_1e3cc4;
            case 0x1E3CE8u: goto label_1e3ce8;
            case 0x1E3CFCu: goto label_1e3cfc;
            case 0x1E3D00u: goto label_1e3d00;
            case 0x1E3D68u: goto label_1e3d68;
            case 0x1E3D7Cu: goto label_1e3d7c;
            case 0x1E3DBCu: goto label_1e3dbc;
            case 0x1E3DCCu: goto label_1e3dcc;
            case 0x1E3DF0u: goto label_1e3df0;
            case 0x1E3E00u: goto label_1e3e00;
            case 0x1E3E24u: goto label_1e3e24;
            case 0x1E3E38u: goto label_1e3e38;
            case 0x1E3EA4u: goto label_1e3ea4;
            case 0x1E3EC0u: goto label_1e3ec0;
            case 0x1E3ED4u: goto label_1e3ed4;
            case 0x1E3ED8u: goto label_1e3ed8;
            case 0x1E3F40u: goto label_1e3f40;
            case 0x1E3F54u: goto label_1e3f54;
            case 0x1E3F94u: goto label_1e3f94;
            case 0x1E3FA4u: goto label_1e3fa4;
            case 0x1E3FC8u: goto label_1e3fc8;
            case 0x1E3FD8u: goto label_1e3fd8;
            case 0x1E3FFCu: goto label_1e3ffc;
            case 0x1E4010u: goto label_1e4010;
            case 0x1E407Cu: goto label_1e407c;
            case 0x1E4098u: goto label_1e4098;
            case 0x1E40ACu: goto label_1e40ac;
            case 0x1E40B0u: goto label_1e40b0;
            case 0x1E4118u: goto label_1e4118;
            case 0x1E412Cu: goto label_1e412c;
            case 0x1E416Cu: goto label_1e416c;
            case 0x1E417Cu: goto label_1e417c;
            case 0x1E41A0u: goto label_1e41a0;
            case 0x1E41B0u: goto label_1e41b0;
            case 0x1E41D4u: goto label_1e41d4;
            case 0x1E41E8u: goto label_1e41e8;
            case 0x1E4254u: goto label_1e4254;
            case 0x1E4270u: goto label_1e4270;
            case 0x1E4284u: goto label_1e4284;
            case 0x1E4288u: goto label_1e4288;
            case 0x1E42F0u: goto label_1e42f0;
            case 0x1E4304u: goto label_1e4304;
            case 0x1E4344u: goto label_1e4344;
            case 0x1E4358u: goto label_1e4358;
            case 0x1E437Cu: goto label_1e437c;
            case 0x1E4394u: goto label_1e4394;
            case 0x1E43B8u: goto label_1e43b8;
            case 0x1E43CCu: goto label_1e43cc;
            case 0x1E43E4u: goto label_1e43e4;
            case 0x1E4414u: goto label_1e4414;
            case 0x1E4430u: goto label_1e4430;
            case 0x1E4444u: goto label_1e4444;
            case 0x1E4460u: goto label_1e4460;
            case 0x1E44C8u: goto label_1e44c8;
            case 0x1E44DCu: goto label_1e44dc;
            case 0x1E451Cu: goto label_1e451c;
            case 0x1E452Cu: goto label_1e452c;
            case 0x1E4550u: goto label_1e4550;
            case 0x1E4560u: goto label_1e4560;
            case 0x1E4584u: goto label_1e4584;
            case 0x1E4598u: goto label_1e4598;
            case 0x1E460Cu: goto label_1e460c;
            case 0x1E4628u: goto label_1e4628;
            case 0x1E463Cu: goto label_1e463c;
            case 0x1E4658u: goto label_1e4658;
            case 0x1E46C8u: goto label_1e46c8;
            case 0x1E46DCu: goto label_1e46dc;
            case 0x1E471Cu: goto label_1e471c;
            case 0x1E472Cu: goto label_1e472c;
            case 0x1E4750u: goto label_1e4750;
            case 0x1E4764u: goto label_1e4764;
            case 0x1E4788u: goto label_1e4788;
            case 0x1E479Cu: goto label_1e479c;
            case 0x1E47B0u: goto label_1e47b0;
            case 0x1E47E0u: goto label_1e47e0;
            case 0x1E47FCu: goto label_1e47fc;
            case 0x1E4800u: goto label_1e4800;
            case 0x1E48A0u: goto label_1e48a0;
            case 0x1E48B4u: goto label_1e48b4;
            case 0x1E48F4u: goto label_1e48f4;
            case 0x1E4918u: goto label_1e4918;
            case 0x1E493Cu: goto label_1e493c;
            case 0x1E4974u: goto label_1e4974;
            case 0x1E4998u: goto label_1e4998;
            case 0x1E49ACu: goto label_1e49ac;
            case 0x1E4A08u: goto label_1e4a08;
            case 0x1E4A24u: goto label_1e4a24;
            case 0x1E4AACu: goto label_1e4aac;
            case 0x1E4AC0u: goto label_1e4ac0;
            case 0x1E4B00u: goto label_1e4b00;
            case 0x1E4B1Cu: goto label_1e4b1c;
            case 0x1E4B20u: goto label_1e4b20;
            case 0x1E4B94u: goto label_1e4b94;
            case 0x1E4BA8u: goto label_1e4ba8;
            case 0x1E4BE8u: goto label_1e4be8;
            case 0x1E4C10u: goto label_1e4c10;
            case 0x1E4C34u: goto label_1e4c34;
            case 0x1E4C64u: goto label_1e4c64;
            case 0x1E4C88u: goto label_1e4c88;
            case 0x1E4C9Cu: goto label_1e4c9c;
            case 0x1E4D08u: goto label_1e4d08;
            case 0x1E4D28u: goto label_1e4d28;
            case 0x1E4DE4u: goto label_1e4de4;
            case 0x1E4DF8u: goto label_1e4df8;
            case 0x1E4E3Cu: goto label_1e4e3c;
            case 0x1E4E58u: goto label_1e4e58;
            case 0x1E4E5Cu: goto label_1e4e5c;
            case 0x1E4EC4u: goto label_1e4ec4;
            case 0x1E4ED8u: goto label_1e4ed8;
            case 0x1E4F18u: goto label_1e4f18;
            case 0x1E4F28u: goto label_1e4f28;
            case 0x1E4F4Cu: goto label_1e4f4c;
            case 0x1E4F60u: goto label_1e4f60;
            case 0x1E4F84u: goto label_1e4f84;
            case 0x1E4F98u: goto label_1e4f98;
            case 0x1E4FACu: goto label_1e4fac;
            case 0x1E4FD0u: goto label_1e4fd0;
            case 0x1E4FECu: goto label_1e4fec;
            case 0x1E4FF0u: goto label_1e4ff0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E1C90u;
    // 0x1e1c90: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1e1c90u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1e1c94: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1e1c94u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1e1c98: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1e1c98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1e1c9c: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e1c9cu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e1ca0: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e1ca0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e1ca4: 0xafc00004  sw          $zero, 0x4($fp)
    ctx->pc = 0x1e1ca4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 0));
    // 0x1e1ca8: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e1ca8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e1cac: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e1cacu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e1cb0: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E1CB0u;
    {
        const bool branch_taken_0x1e1cb0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e1cb0) {
            ctx->pc = 0x1E1CD8u;
            goto label_1e1cd8;
        }
    }
    ctx->pc = 0x1E1CB8u;
    // 0x1e1cb8: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e1cb8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e1cbc: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e1cbcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e1cc0: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e1cc0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e1cc4: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e1cc4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e1cc8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e1cc8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e1ccc: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e1cccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e1cd0: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E1CD0u;
    {
        const bool branch_taken_0x1e1cd0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e1cd0) {
            ctx->pc = 0x1E1CECu;
            goto label_1e1cec;
        }
    }
    ctx->pc = 0x1E1CD8u;
label_1e1cd8:
    // 0x1e1cd8: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e1cd8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e1cdc: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e1cdcu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e1ce0: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e1ce0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e1ce4: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x1E1CE4u;
    {
        const bool branch_taken_0x1e1ce4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e1ce4) {
            ctx->pc = 0x1E1D14u;
            goto label_1e1d14;
        }
    }
    ctx->pc = 0x1E1CECu;
label_1e1cec:
    // 0x1e1cec: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e1cecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e1cf0: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e1cf0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e1cf4: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e1cf4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e1cf8: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e1cf8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e1cfc: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e1cfcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e1d00: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e1d00u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e1d04: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1e1d04u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
    // 0x1e1d08: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1e1d08u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e1d0c: 0xc0786cf  jal         func_1E1B3C
    ctx->pc = 0x1E1D0Cu;
    SET_GPR_U32(ctx, 31, 0x1E1D14u);
    ctx->pc = 0x1E1B3Cu;
    goto label_1e1b3c;
    ctx->pc = 0x1E1D14u;
label_1e1d14:
    // 0x1e1d14: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e1d14u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e1d18: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1e1d18u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1e1d1c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1e1d1cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1e1d20: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1e1d20u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1e1d24: 0x3e00008  jr          $ra
    ctx->pc = 0x1E1D24u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E1B3Cu: goto label_1e1b3c;
            case 0x1E1B60u: goto label_1e1b60;
            case 0x1E1B84u: goto label_1e1b84;
            case 0x1E1BA8u: goto label_1e1ba8;
            case 0x1E1BC8u: goto label_1e1bc8;
            case 0x1E1BE4u: goto label_1e1be4;
            case 0x1E1BE8u: goto label_1e1be8;
            case 0x1E1C44u: goto label_1e1c44;
            case 0x1E1C58u: goto label_1e1c58;
            case 0x1E1C7Cu: goto label_1e1c7c;
            case 0x1E1CD8u: goto label_1e1cd8;
            case 0x1E1CECu: goto label_1e1cec;
            case 0x1E1D14u: goto label_1e1d14;
            case 0x1E1D7Cu: goto label_1e1d7c;
            case 0x1E1D90u: goto label_1e1d90;
            case 0x1E1DD0u: goto label_1e1dd0;
            case 0x1E1DE0u: goto label_1e1de0;
            case 0x1E1E04u: goto label_1e1e04;
            case 0x1E1E14u: goto label_1e1e14;
            case 0x1E1E38u: goto label_1e1e38;
            case 0x1E1E4Cu: goto label_1e1e4c;
            case 0x1E1E5Cu: goto label_1e1e5c;
            case 0x1E1E84u: goto label_1e1e84;
            case 0x1E1EA0u: goto label_1e1ea0;
            case 0x1E1EB4u: goto label_1e1eb4;
            case 0x1E1ED0u: goto label_1e1ed0;
            case 0x1E1F48u: goto label_1e1f48;
            case 0x1E1F5Cu: goto label_1e1f5c;
            case 0x1E1F9Cu: goto label_1e1f9c;
            case 0x1E1FACu: goto label_1e1fac;
            case 0x1E1FD0u: goto label_1e1fd0;
            case 0x1E1FE0u: goto label_1e1fe0;
            case 0x1E2004u: goto label_1e2004;
            case 0x1E2018u: goto label_1e2018;
            case 0x1E202Cu: goto label_1e202c;
            case 0x1E2064u: goto label_1e2064;
            case 0x1E206Cu: goto label_1e206c;
            case 0x1E2088u: goto label_1e2088;
            case 0x1E20A0u: goto label_1e20a0;
            case 0x1E20D4u: goto label_1e20d4;
            case 0x1E20F8u: goto label_1e20f8;
            case 0x1E210Cu: goto label_1e210c;
            case 0x1E2128u: goto label_1e2128;
            case 0x1E2190u: goto label_1e2190;
            case 0x1E21A4u: goto label_1e21a4;
            case 0x1E21E4u: goto label_1e21e4;
            case 0x1E21F4u: goto label_1e21f4;
            case 0x1E2218u: goto label_1e2218;
            case 0x1E2228u: goto label_1e2228;
            case 0x1E224Cu: goto label_1e224c;
            case 0x1E2260u: goto label_1e2260;
            case 0x1E22D4u: goto label_1e22d4;
            case 0x1E22F0u: goto label_1e22f0;
            case 0x1E2304u: goto label_1e2304;
            case 0x1E2320u: goto label_1e2320;
            case 0x1E23A0u: goto label_1e23a0;
            case 0x1E23B4u: goto label_1e23b4;
            case 0x1E23F4u: goto label_1e23f4;
            case 0x1E2404u: goto label_1e2404;
            case 0x1E2428u: goto label_1e2428;
            case 0x1E2438u: goto label_1e2438;
            case 0x1E245Cu: goto label_1e245c;
            case 0x1E2470u: goto label_1e2470;
            case 0x1E2480u: goto label_1e2480;
            case 0x1E24F8u: goto label_1e24f8;
            case 0x1E2500u: goto label_1e2500;
            case 0x1E2508u: goto label_1e2508;
            case 0x1E25D0u: goto label_1e25d0;
            case 0x1E25ECu: goto label_1e25ec;
            case 0x1E2600u: goto label_1e2600;
            case 0x1E261Cu: goto label_1e261c;
            case 0x1E2684u: goto label_1e2684;
            case 0x1E2698u: goto label_1e2698;
            case 0x1E26D8u: goto label_1e26d8;
            case 0x1E26E8u: goto label_1e26e8;
            case 0x1E270Cu: goto label_1e270c;
            case 0x1E271Cu: goto label_1e271c;
            case 0x1E2740u: goto label_1e2740;
            case 0x1E2754u: goto label_1e2754;
            case 0x1E27C8u: goto label_1e27c8;
            case 0x1E27E4u: goto label_1e27e4;
            case 0x1E27F8u: goto label_1e27f8;
            case 0x1E2814u: goto label_1e2814;
            case 0x1E287Cu: goto label_1e287c;
            case 0x1E2890u: goto label_1e2890;
            case 0x1E28D0u: goto label_1e28d0;
            case 0x1E28E0u: goto label_1e28e0;
            case 0x1E2904u: goto label_1e2904;
            case 0x1E2914u: goto label_1e2914;
            case 0x1E2938u: goto label_1e2938;
            case 0x1E294Cu: goto label_1e294c;
            case 0x1E29C0u: goto label_1e29c0;
            case 0x1E29DCu: goto label_1e29dc;
            case 0x1E29F0u: goto label_1e29f0;
            case 0x1E2A0Cu: goto label_1e2a0c;
            case 0x1E2A78u: goto label_1e2a78;
            case 0x1E2A8Cu: goto label_1e2a8c;
            case 0x1E2ACCu: goto label_1e2acc;
            case 0x1E2ADCu: goto label_1e2adc;
            case 0x1E2B00u: goto label_1e2b00;
            case 0x1E2B10u: goto label_1e2b10;
            case 0x1E2B34u: goto label_1e2b34;
            case 0x1E2B48u: goto label_1e2b48;
            case 0x1E2B54u: goto label_1e2b54;
            case 0x1E2B90u: goto label_1e2b90;
            case 0x1E2B98u: goto label_1e2b98;
            case 0x1E2BC0u: goto label_1e2bc0;
            case 0x1E2BE4u: goto label_1e2be4;
            case 0x1E2BF8u: goto label_1e2bf8;
            case 0x1E2C14u: goto label_1e2c14;
            case 0x1E2C84u: goto label_1e2c84;
            case 0x1E2C98u: goto label_1e2c98;
            case 0x1E2CD8u: goto label_1e2cd8;
            case 0x1E2CE8u: goto label_1e2ce8;
            case 0x1E2D0Cu: goto label_1e2d0c;
            case 0x1E2D1Cu: goto label_1e2d1c;
            case 0x1E2D40u: goto label_1e2d40;
            case 0x1E2D54u: goto label_1e2d54;
            case 0x1E2E10u: goto label_1e2e10;
            case 0x1E2E18u: goto label_1e2e18;
            case 0x1E2E20u: goto label_1e2e20;
            case 0x1E2E48u: goto label_1e2e48;
            case 0x1E2E64u: goto label_1e2e64;
            case 0x1E2E78u: goto label_1e2e78;
            case 0x1E2E94u: goto label_1e2e94;
            case 0x1E2EF8u: goto label_1e2ef8;
            case 0x1E2F0Cu: goto label_1e2f0c;
            case 0x1E2F4Cu: goto label_1e2f4c;
            case 0x1E2F5Cu: goto label_1e2f5c;
            case 0x1E2F80u: goto label_1e2f80;
            case 0x1E2FA8u: goto label_1e2fa8;
            case 0x1E2FC4u: goto label_1e2fc4;
            case 0x1E2FD8u: goto label_1e2fd8;
            case 0x1E2FF4u: goto label_1e2ff4;
            case 0x1E3058u: goto label_1e3058;
            case 0x1E306Cu: goto label_1e306c;
            case 0x1E30ACu: goto label_1e30ac;
            case 0x1E30BCu: goto label_1e30bc;
            case 0x1E30E0u: goto label_1e30e0;
            case 0x1E3108u: goto label_1e3108;
            case 0x1E3124u: goto label_1e3124;
            case 0x1E3138u: goto label_1e3138;
            case 0x1E3154u: goto label_1e3154;
            case 0x1E31CCu: goto label_1e31cc;
            case 0x1E31E0u: goto label_1e31e0;
            case 0x1E3220u: goto label_1e3220;
            case 0x1E3238u: goto label_1e3238;
            case 0x1E325Cu: goto label_1e325c;
            case 0x1E3278u: goto label_1e3278;
            case 0x1E329Cu: goto label_1e329c;
            case 0x1E32B0u: goto label_1e32b0;
            case 0x1E3318u: goto label_1e3318;
            case 0x1E3388u: goto label_1e3388;
            case 0x1E33C4u: goto label_1e33c4;
            case 0x1E33E0u: goto label_1e33e0;
            case 0x1E33F4u: goto label_1e33f4;
            case 0x1E3410u: goto label_1e3410;
            case 0x1E347Cu: goto label_1e347c;
            case 0x1E3490u: goto label_1e3490;
            case 0x1E34D0u: goto label_1e34d0;
            case 0x1E34E0u: goto label_1e34e0;
            case 0x1E3504u: goto label_1e3504;
            case 0x1E3514u: goto label_1e3514;
            case 0x1E3538u: goto label_1e3538;
            case 0x1E354Cu: goto label_1e354c;
            case 0x1E360Cu: goto label_1e360c;
            case 0x1E3628u: goto label_1e3628;
            case 0x1E363Cu: goto label_1e363c;
            case 0x1E3658u: goto label_1e3658;
            case 0x1E36C4u: goto label_1e36c4;
            case 0x1E36D8u: goto label_1e36d8;
            case 0x1E3718u: goto label_1e3718;
            case 0x1E3728u: goto label_1e3728;
            case 0x1E374Cu: goto label_1e374c;
            case 0x1E375Cu: goto label_1e375c;
            case 0x1E3780u: goto label_1e3780;
            case 0x1E3794u: goto label_1e3794;
            case 0x1E3854u: goto label_1e3854;
            case 0x1E3870u: goto label_1e3870;
            case 0x1E3884u: goto label_1e3884;
            case 0x1E38A0u: goto label_1e38a0;
            case 0x1E3908u: goto label_1e3908;
            case 0x1E391Cu: goto label_1e391c;
            case 0x1E395Cu: goto label_1e395c;
            case 0x1E396Cu: goto label_1e396c;
            case 0x1E3990u: goto label_1e3990;
            case 0x1E39A0u: goto label_1e39a0;
            case 0x1E39C4u: goto label_1e39c4;
            case 0x1E39D8u: goto label_1e39d8;
            case 0x1E3A44u: goto label_1e3a44;
            case 0x1E3A60u: goto label_1e3a60;
            case 0x1E3A74u: goto label_1e3a74;
            case 0x1E3A78u: goto label_1e3a78;
            case 0x1E3ADCu: goto label_1e3adc;
            case 0x1E3AF0u: goto label_1e3af0;
            case 0x1E3B30u: goto label_1e3b30;
            case 0x1E3B40u: goto label_1e3b40;
            case 0x1E3B64u: goto label_1e3b64;
            case 0x1E3B84u: goto label_1e3b84;
            case 0x1E3BA0u: goto label_1e3ba0;
            case 0x1E3BB4u: goto label_1e3bb4;
            case 0x1E3BB8u: goto label_1e3bb8;
            case 0x1E3C1Cu: goto label_1e3c1c;
            case 0x1E3C30u: goto label_1e3c30;
            case 0x1E3C70u: goto label_1e3c70;
            case 0x1E3C80u: goto label_1e3c80;
            case 0x1E3CA4u: goto label_1e3ca4;
            case 0x1E3CC4u: goto label_1e3cc4;
            case 0x1E3CE8u: goto label_1e3ce8;
            case 0x1E3CFCu: goto label_1e3cfc;
            case 0x1E3D00u: goto label_1e3d00;
            case 0x1E3D68u: goto label_1e3d68;
            case 0x1E3D7Cu: goto label_1e3d7c;
            case 0x1E3DBCu: goto label_1e3dbc;
            case 0x1E3DCCu: goto label_1e3dcc;
            case 0x1E3DF0u: goto label_1e3df0;
            case 0x1E3E00u: goto label_1e3e00;
            case 0x1E3E24u: goto label_1e3e24;
            case 0x1E3E38u: goto label_1e3e38;
            case 0x1E3EA4u: goto label_1e3ea4;
            case 0x1E3EC0u: goto label_1e3ec0;
            case 0x1E3ED4u: goto label_1e3ed4;
            case 0x1E3ED8u: goto label_1e3ed8;
            case 0x1E3F40u: goto label_1e3f40;
            case 0x1E3F54u: goto label_1e3f54;
            case 0x1E3F94u: goto label_1e3f94;
            case 0x1E3FA4u: goto label_1e3fa4;
            case 0x1E3FC8u: goto label_1e3fc8;
            case 0x1E3FD8u: goto label_1e3fd8;
            case 0x1E3FFCu: goto label_1e3ffc;
            case 0x1E4010u: goto label_1e4010;
            case 0x1E407Cu: goto label_1e407c;
            case 0x1E4098u: goto label_1e4098;
            case 0x1E40ACu: goto label_1e40ac;
            case 0x1E40B0u: goto label_1e40b0;
            case 0x1E4118u: goto label_1e4118;
            case 0x1E412Cu: goto label_1e412c;
            case 0x1E416Cu: goto label_1e416c;
            case 0x1E417Cu: goto label_1e417c;
            case 0x1E41A0u: goto label_1e41a0;
            case 0x1E41B0u: goto label_1e41b0;
            case 0x1E41D4u: goto label_1e41d4;
            case 0x1E41E8u: goto label_1e41e8;
            case 0x1E4254u: goto label_1e4254;
            case 0x1E4270u: goto label_1e4270;
            case 0x1E4284u: goto label_1e4284;
            case 0x1E4288u: goto label_1e4288;
            case 0x1E42F0u: goto label_1e42f0;
            case 0x1E4304u: goto label_1e4304;
            case 0x1E4344u: goto label_1e4344;
            case 0x1E4358u: goto label_1e4358;
            case 0x1E437Cu: goto label_1e437c;
            case 0x1E4394u: goto label_1e4394;
            case 0x1E43B8u: goto label_1e43b8;
            case 0x1E43CCu: goto label_1e43cc;
            case 0x1E43E4u: goto label_1e43e4;
            case 0x1E4414u: goto label_1e4414;
            case 0x1E4430u: goto label_1e4430;
            case 0x1E4444u: goto label_1e4444;
            case 0x1E4460u: goto label_1e4460;
            case 0x1E44C8u: goto label_1e44c8;
            case 0x1E44DCu: goto label_1e44dc;
            case 0x1E451Cu: goto label_1e451c;
            case 0x1E452Cu: goto label_1e452c;
            case 0x1E4550u: goto label_1e4550;
            case 0x1E4560u: goto label_1e4560;
            case 0x1E4584u: goto label_1e4584;
            case 0x1E4598u: goto label_1e4598;
            case 0x1E460Cu: goto label_1e460c;
            case 0x1E4628u: goto label_1e4628;
            case 0x1E463Cu: goto label_1e463c;
            case 0x1E4658u: goto label_1e4658;
            case 0x1E46C8u: goto label_1e46c8;
            case 0x1E46DCu: goto label_1e46dc;
            case 0x1E471Cu: goto label_1e471c;
            case 0x1E472Cu: goto label_1e472c;
            case 0x1E4750u: goto label_1e4750;
            case 0x1E4764u: goto label_1e4764;
            case 0x1E4788u: goto label_1e4788;
            case 0x1E479Cu: goto label_1e479c;
            case 0x1E47B0u: goto label_1e47b0;
            case 0x1E47E0u: goto label_1e47e0;
            case 0x1E47FCu: goto label_1e47fc;
            case 0x1E4800u: goto label_1e4800;
            case 0x1E48A0u: goto label_1e48a0;
            case 0x1E48B4u: goto label_1e48b4;
            case 0x1E48F4u: goto label_1e48f4;
            case 0x1E4918u: goto label_1e4918;
            case 0x1E493Cu: goto label_1e493c;
            case 0x1E4974u: goto label_1e4974;
            case 0x1E4998u: goto label_1e4998;
            case 0x1E49ACu: goto label_1e49ac;
            case 0x1E4A08u: goto label_1e4a08;
            case 0x1E4A24u: goto label_1e4a24;
            case 0x1E4AACu: goto label_1e4aac;
            case 0x1E4AC0u: goto label_1e4ac0;
            case 0x1E4B00u: goto label_1e4b00;
            case 0x1E4B1Cu: goto label_1e4b1c;
            case 0x1E4B20u: goto label_1e4b20;
            case 0x1E4B94u: goto label_1e4b94;
            case 0x1E4BA8u: goto label_1e4ba8;
            case 0x1E4BE8u: goto label_1e4be8;
            case 0x1E4C10u: goto label_1e4c10;
            case 0x1E4C34u: goto label_1e4c34;
            case 0x1E4C64u: goto label_1e4c64;
            case 0x1E4C88u: goto label_1e4c88;
            case 0x1E4C9Cu: goto label_1e4c9c;
            case 0x1E4D08u: goto label_1e4d08;
            case 0x1E4D28u: goto label_1e4d28;
            case 0x1E4DE4u: goto label_1e4de4;
            case 0x1E4DF8u: goto label_1e4df8;
            case 0x1E4E3Cu: goto label_1e4e3c;
            case 0x1E4E58u: goto label_1e4e58;
            case 0x1E4E5Cu: goto label_1e4e5c;
            case 0x1E4EC4u: goto label_1e4ec4;
            case 0x1E4ED8u: goto label_1e4ed8;
            case 0x1E4F18u: goto label_1e4f18;
            case 0x1E4F28u: goto label_1e4f28;
            case 0x1E4F4Cu: goto label_1e4f4c;
            case 0x1E4F60u: goto label_1e4f60;
            case 0x1E4F84u: goto label_1e4f84;
            case 0x1E4F98u: goto label_1e4f98;
            case 0x1E4FACu: goto label_1e4fac;
            case 0x1E4FD0u: goto label_1e4fd0;
            case 0x1E4FECu: goto label_1e4fec;
            case 0x1E4FF0u: goto label_1e4ff0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E1D2Cu;
    // 0x1e1d2c: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1e1d2cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1e1d30: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1e1d30u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1e1d34: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1e1d34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1e1d38: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e1d38u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e1d3c: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e1d3cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e1d40: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e1d40u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e1d44: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e1d44u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e1d48: 0xafc00014  sw          $zero, 0x14($fp)
    ctx->pc = 0x1e1d48u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 0));
    // 0x1e1d4c: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e1d4cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e1d50: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e1d50u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e1d54: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E1D54u;
    {
        const bool branch_taken_0x1e1d54 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e1d54) {
            ctx->pc = 0x1E1D7Cu;
            goto label_1e1d7c;
        }
    }
    ctx->pc = 0x1E1D5Cu;
    // 0x1e1d5c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e1d5cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e1d60: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e1d60u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e1d64: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e1d64u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e1d68: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e1d68u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e1d6c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e1d6cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e1d70: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e1d70u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e1d74: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E1D74u;
    {
        const bool branch_taken_0x1e1d74 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e1d74) {
            ctx->pc = 0x1E1D90u;
            goto label_1e1d90;
        }
    }
    ctx->pc = 0x1E1D7Cu;
label_1e1d7c:
    // 0x1e1d7c: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e1d7cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e1d80: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e1d80u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e1d84: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e1d84u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e1d88: 0x10000051  b           . + 4 + (0x51 << 2)
    ctx->pc = 0x1E1D88u;
    {
        const bool branch_taken_0x1e1d88 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e1d88) {
            ctx->pc = 0x1E1ED0u;
            goto label_1e1ed0;
        }
    }
    ctx->pc = 0x1E1D90u;
label_1e1d90:
    // 0x1e1d90: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e1d90u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e1d94: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e1d94u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e1d98: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e1d98u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e1d9c: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e1d9cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e1da0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e1da0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e1da4: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e1da4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e1da8: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1e1da8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1e1dac: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e1dacu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e1db0: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e1db0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e1db4: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E1DB4u;
    {
        const bool branch_taken_0x1e1db4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e1db4) {
            ctx->pc = 0x1E1DD0u;
            goto label_1e1dd0;
        }
    }
    ctx->pc = 0x1E1DBCu;
    // 0x1e1dbc: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e1dbcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e1dc0: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e1dc0u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e1dc4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e1dc4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e1dc8: 0x10000041  b           . + 4 + (0x41 << 2)
    ctx->pc = 0x1E1DC8u;
    {
        const bool branch_taken_0x1e1dc8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e1dc8) {
            ctx->pc = 0x1E1ED0u;
            goto label_1e1ed0;
        }
    }
    ctx->pc = 0x1E1DD0u;
label_1e1dd0:
    // 0x1e1dd0: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e1dd0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e1dd4: 0x24050010  addiu       $a1, $zero, 0x10
    ctx->pc = 0x1e1dd4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1e1dd8: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E1DD8u;
    SET_GPR_U32(ctx, 31, 0x1E1DE0u);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E1DE0u; }
        if (ctx->pc != 0x1E1DE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E1DE0u; }
        if (ctx->pc != 0x1E1DE0u) { return; }
    }
    ctx->pc = 0x1E1DE0u;
label_1e1de0:
    // 0x1e1de0: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1e1de0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1e1de4: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e1de4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e1de8: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E1DE8u;
    {
        const bool branch_taken_0x1e1de8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e1de8) {
            ctx->pc = 0x1E1E04u;
            goto label_1e1e04;
        }
    }
    ctx->pc = 0x1E1DF0u;
    // 0x1e1df0: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e1df0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e1df4: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e1df4u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e1df8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e1df8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e1dfc: 0x10000034  b           . + 4 + (0x34 << 2)
    ctx->pc = 0x1E1DFCu;
    {
        const bool branch_taken_0x1e1dfc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e1dfc) {
            ctx->pc = 0x1E1ED0u;
            goto label_1e1ed0;
        }
    }
    ctx->pc = 0x1E1E04u;
label_1e1e04:
    // 0x1e1e04: 0x8fc40010  lw          $a0, 0x10($fp)
    ctx->pc = 0x1e1e04u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e1e08: 0x24050010  addiu       $a1, $zero, 0x10
    ctx->pc = 0x1e1e08u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1e1e0c: 0xc07cc3c  jal         func_1F30F0
    ctx->pc = 0x1E1E0Cu;
    SET_GPR_U32(ctx, 31, 0x1E1E14u);
    ctx->pc = 0x1F30F0u;
    if (runtime->hasFunction(0x1F30F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F30F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E1E14u; }
        if (ctx->pc != 0x1E1E14u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F30F0_0x1f30f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E1E14u; }
        if (ctx->pc != 0x1E1E14u) { return; }
    }
    ctx->pc = 0x1E1E14u;
label_1e1e14:
    // 0x1e1e14: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1e1e14u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1e1e18: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e1e18u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e1e1c: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1E1E1Cu;
    {
        const bool branch_taken_0x1e1e1c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e1e1c) {
            ctx->pc = 0x1E1E4Cu;
            goto label_1e1e4c;
        }
    }
    ctx->pc = 0x1E1E24u;
    // 0x1e1e24: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e1e24u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e1e28: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1e1e28u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1e1e2c: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e1e2cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e1e30: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1E1E30u;
    SET_GPR_U32(ctx, 31, 0x1E1E38u);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E1E38u; }
        if (ctx->pc != 0x1E1E38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E1E38u; }
        if (ctx->pc != 0x1E1E38u) { return; }
    }
    ctx->pc = 0x1E1E38u;
label_1e1e38:
    // 0x1e1e38: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e1e38u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e1e3c: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e1e3cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e1e40: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e1e40u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e1e44: 0x10000022  b           . + 4 + (0x22 << 2)
    ctx->pc = 0x1E1E44u;
    {
        const bool branch_taken_0x1e1e44 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e1e44) {
            ctx->pc = 0x1E1ED0u;
            goto label_1e1ed0;
        }
    }
    ctx->pc = 0x1E1E4Cu;
label_1e1e4c:
    // 0x1e1e4c: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1e1e4cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e1e50: 0x8fc50004  lw          $a1, 0x4($fp)
    ctx->pc = 0x1e1e50u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e1e54: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1E1E54u;
    SET_GPR_U32(ctx, 31, 0x1E1E5Cu);
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E1E5Cu; }
        if (ctx->pc != 0x1E1E5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E1E5Cu; }
        if (ctx->pc != 0x1E1E5Cu) { return; }
    }
    ctx->pc = 0x1E1E5Cu;
label_1e1e5c:
    // 0x1e1e5c: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e1e5cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e1e60: 0x90420614  lbu         $v0, 0x614($v0)
    ctx->pc = 0x1e1e60u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 1556)));
    // 0x1e1e64: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e1e64u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e1e68: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e1e68u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e1e6c: 0x3406b000  ori         $a2, $zero, 0xB000
    ctx->pc = 0x1e1e6cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)45056);
    // 0x1e1e70: 0x24070010  addiu       $a3, $zero, 0x10
    ctx->pc = 0x1e1e70u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1e1e74: 0x24080003  addiu       $t0, $zero, 0x3
    ctx->pc = 0x1e1e74u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1e1e78: 0x40482d  daddu       $t1, $v0, $zero
    ctx->pc = 0x1e1e78u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e1e7c: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E1E7Cu;
    SET_GPR_U32(ctx, 31, 0x1E1E84u);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E1E84u; }
        if (ctx->pc != 0x1E1E84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E1E84u; }
        if (ctx->pc != 0x1E1E84u) { return; }
    }
    ctx->pc = 0x1E1E84u;
label_1e1e84:
    // 0x1e1e84: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E1E84u;
    {
        const bool branch_taken_0x1e1e84 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e1e84) {
            ctx->pc = 0x1E1EA0u;
            goto label_1e1ea0;
        }
    }
    ctx->pc = 0x1E1E8Cu;
    // 0x1e1e8c: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e1e8cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e1e90: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e1e90u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e1e94: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e1e94u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e1e98: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1E1E98u;
    {
        const bool branch_taken_0x1e1e98 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e1e98) {
            ctx->pc = 0x1E1ED0u;
            goto label_1e1ed0;
        }
    }
    ctx->pc = 0x1E1EA0u;
label_1e1ea0:
    // 0x1e1ea0: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1e1ea0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e1ea4: 0x2405001d  addiu       $a1, $zero, 0x1D
    ctx->pc = 0x1e1ea4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 29));
    // 0x1e1ea8: 0x8fc60008  lw          $a2, 0x8($fp)
    ctx->pc = 0x1e1ea8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e1eac: 0xc076ad5  jal         func_1DAB54
    ctx->pc = 0x1E1EACu;
    SET_GPR_U32(ctx, 31, 0x1E1EB4u);
    ctx->pc = 0x1DAB54u;
    if (runtime->hasFunction(0x1DAB54u)) {
        auto targetFn = runtime->lookupFunction(0x1DAB54u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E1EB4u; }
        if (ctx->pc != 0x1E1EB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DAB54_0x1dab54(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E1EB4u; }
        if (ctx->pc != 0x1E1EB4u) { return; }
    }
    ctx->pc = 0x1E1EB4u;
label_1e1eb4:
    // 0x1e1eb4: 0x8fc30014  lw          $v1, 0x14($fp)
    ctx->pc = 0x1e1eb4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e1eb8: 0x90640614  lbu         $a0, 0x614($v1)
    ctx->pc = 0x1e1eb8u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 1556)));
    // 0x1e1ebc: 0x24820001  addiu       $v0, $a0, 0x1
    ctx->pc = 0x1e1ebcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1e1ec0: 0xa0620614  sb          $v0, 0x614($v1)
    ctx->pc = 0x1e1ec0u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 1556), (uint8_t)GPR_U32(ctx, 2));
    // 0x1e1ec4: 0x308200ff  andi        $v0, $a0, 0xFF
    ctx->pc = 0x1e1ec4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x1e1ec8: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1e1ec8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1e1ecc: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e1eccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
label_1e1ed0:
    // 0x1e1ed0: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e1ed0u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e1ed4: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1e1ed4u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1e1ed8: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1e1ed8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1e1edc: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1e1edcu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1e1ee0: 0x3e00008  jr          $ra
    ctx->pc = 0x1E1EE0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E1B3Cu: goto label_1e1b3c;
            case 0x1E1B60u: goto label_1e1b60;
            case 0x1E1B84u: goto label_1e1b84;
            case 0x1E1BA8u: goto label_1e1ba8;
            case 0x1E1BC8u: goto label_1e1bc8;
            case 0x1E1BE4u: goto label_1e1be4;
            case 0x1E1BE8u: goto label_1e1be8;
            case 0x1E1C44u: goto label_1e1c44;
            case 0x1E1C58u: goto label_1e1c58;
            case 0x1E1C7Cu: goto label_1e1c7c;
            case 0x1E1CD8u: goto label_1e1cd8;
            case 0x1E1CECu: goto label_1e1cec;
            case 0x1E1D14u: goto label_1e1d14;
            case 0x1E1D7Cu: goto label_1e1d7c;
            case 0x1E1D90u: goto label_1e1d90;
            case 0x1E1DD0u: goto label_1e1dd0;
            case 0x1E1DE0u: goto label_1e1de0;
            case 0x1E1E04u: goto label_1e1e04;
            case 0x1E1E14u: goto label_1e1e14;
            case 0x1E1E38u: goto label_1e1e38;
            case 0x1E1E4Cu: goto label_1e1e4c;
            case 0x1E1E5Cu: goto label_1e1e5c;
            case 0x1E1E84u: goto label_1e1e84;
            case 0x1E1EA0u: goto label_1e1ea0;
            case 0x1E1EB4u: goto label_1e1eb4;
            case 0x1E1ED0u: goto label_1e1ed0;
            case 0x1E1F48u: goto label_1e1f48;
            case 0x1E1F5Cu: goto label_1e1f5c;
            case 0x1E1F9Cu: goto label_1e1f9c;
            case 0x1E1FACu: goto label_1e1fac;
            case 0x1E1FD0u: goto label_1e1fd0;
            case 0x1E1FE0u: goto label_1e1fe0;
            case 0x1E2004u: goto label_1e2004;
            case 0x1E2018u: goto label_1e2018;
            case 0x1E202Cu: goto label_1e202c;
            case 0x1E2064u: goto label_1e2064;
            case 0x1E206Cu: goto label_1e206c;
            case 0x1E2088u: goto label_1e2088;
            case 0x1E20A0u: goto label_1e20a0;
            case 0x1E20D4u: goto label_1e20d4;
            case 0x1E20F8u: goto label_1e20f8;
            case 0x1E210Cu: goto label_1e210c;
            case 0x1E2128u: goto label_1e2128;
            case 0x1E2190u: goto label_1e2190;
            case 0x1E21A4u: goto label_1e21a4;
            case 0x1E21E4u: goto label_1e21e4;
            case 0x1E21F4u: goto label_1e21f4;
            case 0x1E2218u: goto label_1e2218;
            case 0x1E2228u: goto label_1e2228;
            case 0x1E224Cu: goto label_1e224c;
            case 0x1E2260u: goto label_1e2260;
            case 0x1E22D4u: goto label_1e22d4;
            case 0x1E22F0u: goto label_1e22f0;
            case 0x1E2304u: goto label_1e2304;
            case 0x1E2320u: goto label_1e2320;
            case 0x1E23A0u: goto label_1e23a0;
            case 0x1E23B4u: goto label_1e23b4;
            case 0x1E23F4u: goto label_1e23f4;
            case 0x1E2404u: goto label_1e2404;
            case 0x1E2428u: goto label_1e2428;
            case 0x1E2438u: goto label_1e2438;
            case 0x1E245Cu: goto label_1e245c;
            case 0x1E2470u: goto label_1e2470;
            case 0x1E2480u: goto label_1e2480;
            case 0x1E24F8u: goto label_1e24f8;
            case 0x1E2500u: goto label_1e2500;
            case 0x1E2508u: goto label_1e2508;
            case 0x1E25D0u: goto label_1e25d0;
            case 0x1E25ECu: goto label_1e25ec;
            case 0x1E2600u: goto label_1e2600;
            case 0x1E261Cu: goto label_1e261c;
            case 0x1E2684u: goto label_1e2684;
            case 0x1E2698u: goto label_1e2698;
            case 0x1E26D8u: goto label_1e26d8;
            case 0x1E26E8u: goto label_1e26e8;
            case 0x1E270Cu: goto label_1e270c;
            case 0x1E271Cu: goto label_1e271c;
            case 0x1E2740u: goto label_1e2740;
            case 0x1E2754u: goto label_1e2754;
            case 0x1E27C8u: goto label_1e27c8;
            case 0x1E27E4u: goto label_1e27e4;
            case 0x1E27F8u: goto label_1e27f8;
            case 0x1E2814u: goto label_1e2814;
            case 0x1E287Cu: goto label_1e287c;
            case 0x1E2890u: goto label_1e2890;
            case 0x1E28D0u: goto label_1e28d0;
            case 0x1E28E0u: goto label_1e28e0;
            case 0x1E2904u: goto label_1e2904;
            case 0x1E2914u: goto label_1e2914;
            case 0x1E2938u: goto label_1e2938;
            case 0x1E294Cu: goto label_1e294c;
            case 0x1E29C0u: goto label_1e29c0;
            case 0x1E29DCu: goto label_1e29dc;
            case 0x1E29F0u: goto label_1e29f0;
            case 0x1E2A0Cu: goto label_1e2a0c;
            case 0x1E2A78u: goto label_1e2a78;
            case 0x1E2A8Cu: goto label_1e2a8c;
            case 0x1E2ACCu: goto label_1e2acc;
            case 0x1E2ADCu: goto label_1e2adc;
            case 0x1E2B00u: goto label_1e2b00;
            case 0x1E2B10u: goto label_1e2b10;
            case 0x1E2B34u: goto label_1e2b34;
            case 0x1E2B48u: goto label_1e2b48;
            case 0x1E2B54u: goto label_1e2b54;
            case 0x1E2B90u: goto label_1e2b90;
            case 0x1E2B98u: goto label_1e2b98;
            case 0x1E2BC0u: goto label_1e2bc0;
            case 0x1E2BE4u: goto label_1e2be4;
            case 0x1E2BF8u: goto label_1e2bf8;
            case 0x1E2C14u: goto label_1e2c14;
            case 0x1E2C84u: goto label_1e2c84;
            case 0x1E2C98u: goto label_1e2c98;
            case 0x1E2CD8u: goto label_1e2cd8;
            case 0x1E2CE8u: goto label_1e2ce8;
            case 0x1E2D0Cu: goto label_1e2d0c;
            case 0x1E2D1Cu: goto label_1e2d1c;
            case 0x1E2D40u: goto label_1e2d40;
            case 0x1E2D54u: goto label_1e2d54;
            case 0x1E2E10u: goto label_1e2e10;
            case 0x1E2E18u: goto label_1e2e18;
            case 0x1E2E20u: goto label_1e2e20;
            case 0x1E2E48u: goto label_1e2e48;
            case 0x1E2E64u: goto label_1e2e64;
            case 0x1E2E78u: goto label_1e2e78;
            case 0x1E2E94u: goto label_1e2e94;
            case 0x1E2EF8u: goto label_1e2ef8;
            case 0x1E2F0Cu: goto label_1e2f0c;
            case 0x1E2F4Cu: goto label_1e2f4c;
            case 0x1E2F5Cu: goto label_1e2f5c;
            case 0x1E2F80u: goto label_1e2f80;
            case 0x1E2FA8u: goto label_1e2fa8;
            case 0x1E2FC4u: goto label_1e2fc4;
            case 0x1E2FD8u: goto label_1e2fd8;
            case 0x1E2FF4u: goto label_1e2ff4;
            case 0x1E3058u: goto label_1e3058;
            case 0x1E306Cu: goto label_1e306c;
            case 0x1E30ACu: goto label_1e30ac;
            case 0x1E30BCu: goto label_1e30bc;
            case 0x1E30E0u: goto label_1e30e0;
            case 0x1E3108u: goto label_1e3108;
            case 0x1E3124u: goto label_1e3124;
            case 0x1E3138u: goto label_1e3138;
            case 0x1E3154u: goto label_1e3154;
            case 0x1E31CCu: goto label_1e31cc;
            case 0x1E31E0u: goto label_1e31e0;
            case 0x1E3220u: goto label_1e3220;
            case 0x1E3238u: goto label_1e3238;
            case 0x1E325Cu: goto label_1e325c;
            case 0x1E3278u: goto label_1e3278;
            case 0x1E329Cu: goto label_1e329c;
            case 0x1E32B0u: goto label_1e32b0;
            case 0x1E3318u: goto label_1e3318;
            case 0x1E3388u: goto label_1e3388;
            case 0x1E33C4u: goto label_1e33c4;
            case 0x1E33E0u: goto label_1e33e0;
            case 0x1E33F4u: goto label_1e33f4;
            case 0x1E3410u: goto label_1e3410;
            case 0x1E347Cu: goto label_1e347c;
            case 0x1E3490u: goto label_1e3490;
            case 0x1E34D0u: goto label_1e34d0;
            case 0x1E34E0u: goto label_1e34e0;
            case 0x1E3504u: goto label_1e3504;
            case 0x1E3514u: goto label_1e3514;
            case 0x1E3538u: goto label_1e3538;
            case 0x1E354Cu: goto label_1e354c;
            case 0x1E360Cu: goto label_1e360c;
            case 0x1E3628u: goto label_1e3628;
            case 0x1E363Cu: goto label_1e363c;
            case 0x1E3658u: goto label_1e3658;
            case 0x1E36C4u: goto label_1e36c4;
            case 0x1E36D8u: goto label_1e36d8;
            case 0x1E3718u: goto label_1e3718;
            case 0x1E3728u: goto label_1e3728;
            case 0x1E374Cu: goto label_1e374c;
            case 0x1E375Cu: goto label_1e375c;
            case 0x1E3780u: goto label_1e3780;
            case 0x1E3794u: goto label_1e3794;
            case 0x1E3854u: goto label_1e3854;
            case 0x1E3870u: goto label_1e3870;
            case 0x1E3884u: goto label_1e3884;
            case 0x1E38A0u: goto label_1e38a0;
            case 0x1E3908u: goto label_1e3908;
            case 0x1E391Cu: goto label_1e391c;
            case 0x1E395Cu: goto label_1e395c;
            case 0x1E396Cu: goto label_1e396c;
            case 0x1E3990u: goto label_1e3990;
            case 0x1E39A0u: goto label_1e39a0;
            case 0x1E39C4u: goto label_1e39c4;
            case 0x1E39D8u: goto label_1e39d8;
            case 0x1E3A44u: goto label_1e3a44;
            case 0x1E3A60u: goto label_1e3a60;
            case 0x1E3A74u: goto label_1e3a74;
            case 0x1E3A78u: goto label_1e3a78;
            case 0x1E3ADCu: goto label_1e3adc;
            case 0x1E3AF0u: goto label_1e3af0;
            case 0x1E3B30u: goto label_1e3b30;
            case 0x1E3B40u: goto label_1e3b40;
            case 0x1E3B64u: goto label_1e3b64;
            case 0x1E3B84u: goto label_1e3b84;
            case 0x1E3BA0u: goto label_1e3ba0;
            case 0x1E3BB4u: goto label_1e3bb4;
            case 0x1E3BB8u: goto label_1e3bb8;
            case 0x1E3C1Cu: goto label_1e3c1c;
            case 0x1E3C30u: goto label_1e3c30;
            case 0x1E3C70u: goto label_1e3c70;
            case 0x1E3C80u: goto label_1e3c80;
            case 0x1E3CA4u: goto label_1e3ca4;
            case 0x1E3CC4u: goto label_1e3cc4;
            case 0x1E3CE8u: goto label_1e3ce8;
            case 0x1E3CFCu: goto label_1e3cfc;
            case 0x1E3D00u: goto label_1e3d00;
            case 0x1E3D68u: goto label_1e3d68;
            case 0x1E3D7Cu: goto label_1e3d7c;
            case 0x1E3DBCu: goto label_1e3dbc;
            case 0x1E3DCCu: goto label_1e3dcc;
            case 0x1E3DF0u: goto label_1e3df0;
            case 0x1E3E00u: goto label_1e3e00;
            case 0x1E3E24u: goto label_1e3e24;
            case 0x1E3E38u: goto label_1e3e38;
            case 0x1E3EA4u: goto label_1e3ea4;
            case 0x1E3EC0u: goto label_1e3ec0;
            case 0x1E3ED4u: goto label_1e3ed4;
            case 0x1E3ED8u: goto label_1e3ed8;
            case 0x1E3F40u: goto label_1e3f40;
            case 0x1E3F54u: goto label_1e3f54;
            case 0x1E3F94u: goto label_1e3f94;
            case 0x1E3FA4u: goto label_1e3fa4;
            case 0x1E3FC8u: goto label_1e3fc8;
            case 0x1E3FD8u: goto label_1e3fd8;
            case 0x1E3FFCu: goto label_1e3ffc;
            case 0x1E4010u: goto label_1e4010;
            case 0x1E407Cu: goto label_1e407c;
            case 0x1E4098u: goto label_1e4098;
            case 0x1E40ACu: goto label_1e40ac;
            case 0x1E40B0u: goto label_1e40b0;
            case 0x1E4118u: goto label_1e4118;
            case 0x1E412Cu: goto label_1e412c;
            case 0x1E416Cu: goto label_1e416c;
            case 0x1E417Cu: goto label_1e417c;
            case 0x1E41A0u: goto label_1e41a0;
            case 0x1E41B0u: goto label_1e41b0;
            case 0x1E41D4u: goto label_1e41d4;
            case 0x1E41E8u: goto label_1e41e8;
            case 0x1E4254u: goto label_1e4254;
            case 0x1E4270u: goto label_1e4270;
            case 0x1E4284u: goto label_1e4284;
            case 0x1E4288u: goto label_1e4288;
            case 0x1E42F0u: goto label_1e42f0;
            case 0x1E4304u: goto label_1e4304;
            case 0x1E4344u: goto label_1e4344;
            case 0x1E4358u: goto label_1e4358;
            case 0x1E437Cu: goto label_1e437c;
            case 0x1E4394u: goto label_1e4394;
            case 0x1E43B8u: goto label_1e43b8;
            case 0x1E43CCu: goto label_1e43cc;
            case 0x1E43E4u: goto label_1e43e4;
            case 0x1E4414u: goto label_1e4414;
            case 0x1E4430u: goto label_1e4430;
            case 0x1E4444u: goto label_1e4444;
            case 0x1E4460u: goto label_1e4460;
            case 0x1E44C8u: goto label_1e44c8;
            case 0x1E44DCu: goto label_1e44dc;
            case 0x1E451Cu: goto label_1e451c;
            case 0x1E452Cu: goto label_1e452c;
            case 0x1E4550u: goto label_1e4550;
            case 0x1E4560u: goto label_1e4560;
            case 0x1E4584u: goto label_1e4584;
            case 0x1E4598u: goto label_1e4598;
            case 0x1E460Cu: goto label_1e460c;
            case 0x1E4628u: goto label_1e4628;
            case 0x1E463Cu: goto label_1e463c;
            case 0x1E4658u: goto label_1e4658;
            case 0x1E46C8u: goto label_1e46c8;
            case 0x1E46DCu: goto label_1e46dc;
            case 0x1E471Cu: goto label_1e471c;
            case 0x1E472Cu: goto label_1e472c;
            case 0x1E4750u: goto label_1e4750;
            case 0x1E4764u: goto label_1e4764;
            case 0x1E4788u: goto label_1e4788;
            case 0x1E479Cu: goto label_1e479c;
            case 0x1E47B0u: goto label_1e47b0;
            case 0x1E47E0u: goto label_1e47e0;
            case 0x1E47FCu: goto label_1e47fc;
            case 0x1E4800u: goto label_1e4800;
            case 0x1E48A0u: goto label_1e48a0;
            case 0x1E48B4u: goto label_1e48b4;
            case 0x1E48F4u: goto label_1e48f4;
            case 0x1E4918u: goto label_1e4918;
            case 0x1E493Cu: goto label_1e493c;
            case 0x1E4974u: goto label_1e4974;
            case 0x1E4998u: goto label_1e4998;
            case 0x1E49ACu: goto label_1e49ac;
            case 0x1E4A08u: goto label_1e4a08;
            case 0x1E4A24u: goto label_1e4a24;
            case 0x1E4AACu: goto label_1e4aac;
            case 0x1E4AC0u: goto label_1e4ac0;
            case 0x1E4B00u: goto label_1e4b00;
            case 0x1E4B1Cu: goto label_1e4b1c;
            case 0x1E4B20u: goto label_1e4b20;
            case 0x1E4B94u: goto label_1e4b94;
            case 0x1E4BA8u: goto label_1e4ba8;
            case 0x1E4BE8u: goto label_1e4be8;
            case 0x1E4C10u: goto label_1e4c10;
            case 0x1E4C34u: goto label_1e4c34;
            case 0x1E4C64u: goto label_1e4c64;
            case 0x1E4C88u: goto label_1e4c88;
            case 0x1E4C9Cu: goto label_1e4c9c;
            case 0x1E4D08u: goto label_1e4d08;
            case 0x1E4D28u: goto label_1e4d28;
            case 0x1E4DE4u: goto label_1e4de4;
            case 0x1E4DF8u: goto label_1e4df8;
            case 0x1E4E3Cu: goto label_1e4e3c;
            case 0x1E4E58u: goto label_1e4e58;
            case 0x1E4E5Cu: goto label_1e4e5c;
            case 0x1E4EC4u: goto label_1e4ec4;
            case 0x1E4ED8u: goto label_1e4ed8;
            case 0x1E4F18u: goto label_1e4f18;
            case 0x1E4F28u: goto label_1e4f28;
            case 0x1E4F4Cu: goto label_1e4f4c;
            case 0x1E4F60u: goto label_1e4f60;
            case 0x1E4F84u: goto label_1e4f84;
            case 0x1E4F98u: goto label_1e4f98;
            case 0x1E4FACu: goto label_1e4fac;
            case 0x1E4FD0u: goto label_1e4fd0;
            case 0x1E4FECu: goto label_1e4fec;
            case 0x1E4FF0u: goto label_1e4ff0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E1EE8u;
    // 0x1e1ee8: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1e1ee8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1e1eec: 0xffbe0030  sd          $fp, 0x30($sp)
    ctx->pc = 0x1e1eecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 30));
    // 0x1e1ef0: 0xffbf0038  sd          $ra, 0x38($sp)
    ctx->pc = 0x1e1ef0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x1e1ef4: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e1ef4u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e1ef8: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e1ef8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e1efc: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e1efcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e1f00: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e1f00u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e1f04: 0xe0102d  daddu       $v0, $a3, $zero
    ctx->pc = 0x1e1f04u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e1f08: 0xafc80010  sw          $t0, 0x10($fp)
    ctx->pc = 0x1e1f08u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 8));
    // 0x1e1f0c: 0xafc90014  sw          $t1, 0x14($fp)
    ctx->pc = 0x1e1f0cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 9));
    // 0x1e1f10: 0xa7c2000c  sh          $v0, 0xC($fp)
    ctx->pc = 0x1e1f10u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 12), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e1f14: 0xafc00020  sw          $zero, 0x20($fp)
    ctx->pc = 0x1e1f14u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 0));
    // 0x1e1f18: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e1f18u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e1f1c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e1f1cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e1f20: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E1F20u;
    {
        const bool branch_taken_0x1e1f20 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e1f20) {
            ctx->pc = 0x1E1F48u;
            goto label_1e1f48;
        }
    }
    ctx->pc = 0x1E1F28u;
    // 0x1e1f28: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e1f28u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e1f2c: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e1f2cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e1f30: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e1f30u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e1f34: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e1f34u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e1f38: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e1f38u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e1f3c: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e1f3cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e1f40: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E1F40u;
    {
        const bool branch_taken_0x1e1f40 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e1f40) {
            ctx->pc = 0x1E1F5Cu;
            goto label_1e1f5c;
        }
    }
    ctx->pc = 0x1E1F48u;
label_1e1f48:
    // 0x1e1f48: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e1f48u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e1f4c: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e1f4cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e1f50: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e1f50u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e1f54: 0x10000074  b           . + 4 + (0x74 << 2)
    ctx->pc = 0x1E1F54u;
    {
        const bool branch_taken_0x1e1f54 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e1f54) {
            ctx->pc = 0x1E2128u;
            goto label_1e2128;
        }
    }
    ctx->pc = 0x1E1F5Cu;
label_1e1f5c:
    // 0x1e1f5c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e1f5cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e1f60: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e1f60u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e1f64: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e1f64u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e1f68: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e1f68u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e1f6c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e1f6cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e1f70: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e1f70u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e1f74: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1e1f74u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1e1f78: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e1f78u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e1f7c: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e1f7cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e1f80: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E1F80u;
    {
        const bool branch_taken_0x1e1f80 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e1f80) {
            ctx->pc = 0x1E1F9Cu;
            goto label_1e1f9c;
        }
    }
    ctx->pc = 0x1E1F88u;
    // 0x1e1f88: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e1f88u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e1f8c: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e1f8cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e1f90: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e1f90u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e1f94: 0x10000064  b           . + 4 + (0x64 << 2)
    ctx->pc = 0x1E1F94u;
    {
        const bool branch_taken_0x1e1f94 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e1f94) {
            ctx->pc = 0x1E2128u;
            goto label_1e2128;
        }
    }
    ctx->pc = 0x1E1F9Cu;
label_1e1f9c:
    // 0x1e1f9c: 0x8fc40020  lw          $a0, 0x20($fp)
    ctx->pc = 0x1e1f9cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e1fa0: 0x24050028  addiu       $a1, $zero, 0x28
    ctx->pc = 0x1e1fa0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 40));
    // 0x1e1fa4: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E1FA4u;
    SET_GPR_U32(ctx, 31, 0x1E1FACu);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E1FACu; }
        if (ctx->pc != 0x1E1FACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E1FACu; }
        if (ctx->pc != 0x1E1FACu) { return; }
    }
    ctx->pc = 0x1E1FACu;
label_1e1fac:
    // 0x1e1fac: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1e1facu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1e1fb0: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1e1fb0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e1fb4: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E1FB4u;
    {
        const bool branch_taken_0x1e1fb4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e1fb4) {
            ctx->pc = 0x1E1FD0u;
            goto label_1e1fd0;
        }
    }
    ctx->pc = 0x1E1FBCu;
    // 0x1e1fbc: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e1fbcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e1fc0: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e1fc0u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e1fc4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e1fc4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e1fc8: 0x10000057  b           . + 4 + (0x57 << 2)
    ctx->pc = 0x1E1FC8u;
    {
        const bool branch_taken_0x1e1fc8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e1fc8) {
            ctx->pc = 0x1E2128u;
            goto label_1e2128;
        }
    }
    ctx->pc = 0x1E1FD0u;
label_1e1fd0:
    // 0x1e1fd0: 0x8fc4001c  lw          $a0, 0x1C($fp)
    ctx->pc = 0x1e1fd0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e1fd4: 0x24050028  addiu       $a1, $zero, 0x28
    ctx->pc = 0x1e1fd4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 40));
    // 0x1e1fd8: 0xc07cc3c  jal         func_1F30F0
    ctx->pc = 0x1E1FD8u;
    SET_GPR_U32(ctx, 31, 0x1E1FE0u);
    ctx->pc = 0x1F30F0u;
    if (runtime->hasFunction(0x1F30F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F30F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E1FE0u; }
        if (ctx->pc != 0x1E1FE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F30F0_0x1f30f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E1FE0u; }
        if (ctx->pc != 0x1E1FE0u) { return; }
    }
    ctx->pc = 0x1E1FE0u;
label_1e1fe0:
    // 0x1e1fe0: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1e1fe0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1e1fe4: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e1fe4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e1fe8: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1E1FE8u;
    {
        const bool branch_taken_0x1e1fe8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e1fe8) {
            ctx->pc = 0x1E2018u;
            goto label_1e2018;
        }
    }
    ctx->pc = 0x1E1FF0u;
    // 0x1e1ff0: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e1ff0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e1ff4: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1e1ff4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1e1ff8: 0x8fc5001c  lw          $a1, 0x1C($fp)
    ctx->pc = 0x1e1ff8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e1ffc: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1E1FFCu;
    SET_GPR_U32(ctx, 31, 0x1E2004u);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2004u; }
        if (ctx->pc != 0x1E2004u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2004u; }
        if (ctx->pc != 0x1E2004u) { return; }
    }
    ctx->pc = 0x1E2004u;
label_1e2004:
    // 0x1e2004: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e2004u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e2008: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e2008u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e200c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e200cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e2010: 0x10000045  b           . + 4 + (0x45 << 2)
    ctx->pc = 0x1E2010u;
    {
        const bool branch_taken_0x1e2010 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e2010) {
            ctx->pc = 0x1E2128u;
            goto label_1e2128;
        }
    }
    ctx->pc = 0x1E2018u;
label_1e2018:
    // 0x1e2018: 0x8fc40018  lw          $a0, 0x18($fp)
    ctx->pc = 0x1e2018u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e201c: 0x8fc50004  lw          $a1, 0x4($fp)
    ctx->pc = 0x1e201cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e2020: 0x24060010  addiu       $a2, $zero, 0x10
    ctx->pc = 0x1e2020u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1e2024: 0xc042d7e  jal         func_10B5F8
    ctx->pc = 0x1E2024u;
    SET_GPR_U32(ctx, 31, 0x1E202Cu);
    ctx->pc = 0x10B5F8u;
    if (runtime->hasFunction(0x10B5F8u)) {
        auto targetFn = runtime->lookupFunction(0x10B5F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E202Cu; }
        if (ctx->pc != 0x1E202Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B5F8_0x10b5f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E202Cu; }
        if (ctx->pc != 0x1E202Cu) { return; }
    }
    ctx->pc = 0x1E202Cu;
label_1e202c:
    // 0x1e202c: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e202cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e2030: 0xa040000f  sb          $zero, 0xF($v0)
    ctx->pc = 0x1e2030u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 15), (uint8_t)GPR_U32(ctx, 0));
    // 0x1e2034: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e2034u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e2038: 0xa0400010  sb          $zero, 0x10($v0)
    ctx->pc = 0x1e2038u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 16), (uint8_t)GPR_U32(ctx, 0));
    // 0x1e203c: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1e203cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e2040: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1E2040u;
    {
        const bool branch_taken_0x1e2040 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e2040) {
            ctx->pc = 0x1E206Cu;
            goto label_1e206c;
        }
    }
    ctx->pc = 0x1E2048u;
    // 0x1e2048: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e2048u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e204c: 0x24420010  addiu       $v0, $v0, 0x10
    ctx->pc = 0x1e204cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 16));
    // 0x1e2050: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1e2050u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e2054: 0x8fc50008  lw          $a1, 0x8($fp)
    ctx->pc = 0x1e2054u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e2058: 0x24060010  addiu       $a2, $zero, 0x10
    ctx->pc = 0x1e2058u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1e205c: 0xc042d7e  jal         func_10B5F8
    ctx->pc = 0x1E205Cu;
    SET_GPR_U32(ctx, 31, 0x1E2064u);
    ctx->pc = 0x10B5F8u;
    if (runtime->hasFunction(0x10B5F8u)) {
        auto targetFn = runtime->lookupFunction(0x10B5F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2064u; }
        if (ctx->pc != 0x1E2064u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B5F8_0x10b5f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2064u; }
        if (ctx->pc != 0x1E2064u) { return; }
    }
    ctx->pc = 0x1E2064u;
label_1e2064:
    // 0x1e2064: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e2064u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e2068: 0xa040001f  sb          $zero, 0x1F($v0)
    ctx->pc = 0x1e2068u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 31), (uint8_t)GPR_U32(ctx, 0));
label_1e206c:
    // 0x1e206c: 0x8fc30018  lw          $v1, 0x18($fp)
    ctx->pc = 0x1e206cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e2070: 0x97c2000c  lhu         $v0, 0xC($fp)
    ctx->pc = 0x1e2070u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e2074: 0xac620020  sw          $v0, 0x20($v1)
    ctx->pc = 0x1e2074u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 32), GPR_U32(ctx, 2));
    // 0x1e2078: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e2078u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e207c: 0x8c440020  lw          $a0, 0x20($v0)
    ctx->pc = 0x1e207cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 32)));
    // 0x1e2080: 0xc07a04d  jal         func_1E8134
    ctx->pc = 0x1E2080u;
    SET_GPR_U32(ctx, 31, 0x1E2088u);
    ctx->pc = 0x1E8134u;
    if (runtime->hasFunction(0x1E8134u)) {
        auto targetFn = runtime->lookupFunction(0x1E8134u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2088u; }
        if (ctx->pc != 0x1E2088u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E8134_0x1e8134(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2088u; }
        if (ctx->pc != 0x1E2088u) { return; }
    }
    ctx->pc = 0x1E2088u;
label_1e2088:
    // 0x1e2088: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e2088u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e208c: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e208cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e2090: 0xac430020  sw          $v1, 0x20($v0)
    ctx->pc = 0x1e2090u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 32), GPR_U32(ctx, 3));
    // 0x1e2094: 0x8fc40010  lw          $a0, 0x10($fp)
    ctx->pc = 0x1e2094u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e2098: 0xc07a04d  jal         func_1E8134
    ctx->pc = 0x1E2098u;
    SET_GPR_U32(ctx, 31, 0x1E20A0u);
    ctx->pc = 0x1E8134u;
    if (runtime->hasFunction(0x1E8134u)) {
        auto targetFn = runtime->lookupFunction(0x1E8134u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E20A0u; }
        if (ctx->pc != 0x1E20A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E8134_0x1e8134(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E20A0u; }
        if (ctx->pc != 0x1E20A0u) { return; }
    }
    ctx->pc = 0x1E20A0u;
label_1e20a0:
    // 0x1e20a0: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e20a0u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e20a4: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e20a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e20a8: 0xac430024  sw          $v1, 0x24($v0)
    ctx->pc = 0x1e20a8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 36), GPR_U32(ctx, 3));
    // 0x1e20ac: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e20acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e20b0: 0x90420614  lbu         $v0, 0x614($v0)
    ctx->pc = 0x1e20b0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 1556)));
    // 0x1e20b4: 0x8fc40020  lw          $a0, 0x20($fp)
    ctx->pc = 0x1e20b4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e20b8: 0x8fc5001c  lw          $a1, 0x1C($fp)
    ctx->pc = 0x1e20b8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e20bc: 0x3406b000  ori         $a2, $zero, 0xB000
    ctx->pc = 0x1e20bcu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)45056);
    // 0x1e20c0: 0x24070028  addiu       $a3, $zero, 0x28
    ctx->pc = 0x1e20c0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 40));
    // 0x1e20c4: 0x24080046  addiu       $t0, $zero, 0x46
    ctx->pc = 0x1e20c4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 70));
    // 0x1e20c8: 0x40482d  daddu       $t1, $v0, $zero
    ctx->pc = 0x1e20c8u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e20cc: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E20CCu;
    SET_GPR_U32(ctx, 31, 0x1E20D4u);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E20D4u; }
        if (ctx->pc != 0x1E20D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E20D4u; }
        if (ctx->pc != 0x1E20D4u) { return; }
    }
    ctx->pc = 0x1E20D4u;
label_1e20d4:
    // 0x1e20d4: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1e20d4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1e20d8: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1e20d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1e20dc: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E20DCu;
    {
        const bool branch_taken_0x1e20dc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e20dc) {
            ctx->pc = 0x1E20F8u;
            goto label_1e20f8;
        }
    }
    ctx->pc = 0x1E20E4u;
    // 0x1e20e4: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e20e4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e20e8: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e20e8u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e20ec: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e20ecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e20f0: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1E20F0u;
    {
        const bool branch_taken_0x1e20f0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e20f0) {
            ctx->pc = 0x1E2128u;
            goto label_1e2128;
        }
    }
    ctx->pc = 0x1E20F8u;
label_1e20f8:
    // 0x1e20f8: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1e20f8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e20fc: 0x2405002f  addiu       $a1, $zero, 0x2F
    ctx->pc = 0x1e20fcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 47));
    // 0x1e2100: 0x8fc60014  lw          $a2, 0x14($fp)
    ctx->pc = 0x1e2100u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e2104: 0xc076ad5  jal         func_1DAB54
    ctx->pc = 0x1E2104u;
    SET_GPR_U32(ctx, 31, 0x1E210Cu);
    ctx->pc = 0x1DAB54u;
    if (runtime->hasFunction(0x1DAB54u)) {
        auto targetFn = runtime->lookupFunction(0x1DAB54u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E210Cu; }
        if (ctx->pc != 0x1E210Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DAB54_0x1dab54(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E210Cu; }
        if (ctx->pc != 0x1E210Cu) { return; }
    }
    ctx->pc = 0x1E210Cu;
label_1e210c:
    // 0x1e210c: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1e210cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e2110: 0x90640614  lbu         $a0, 0x614($v1)
    ctx->pc = 0x1e2110u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 1556)));
    // 0x1e2114: 0x24820001  addiu       $v0, $a0, 0x1
    ctx->pc = 0x1e2114u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1e2118: 0xa0620614  sb          $v0, 0x614($v1)
    ctx->pc = 0x1e2118u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 1556), (uint8_t)GPR_U32(ctx, 2));
    // 0x1e211c: 0x308200ff  andi        $v0, $a0, 0xFF
    ctx->pc = 0x1e211cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x1e2120: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1e2120u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1e2124: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1e2124u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
label_1e2128:
    // 0x1e2128: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e2128u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e212c: 0xdfbe0030  ld          $fp, 0x30($sp)
    ctx->pc = 0x1e212cu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1e2130: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x1e2130u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x1e2134: 0x27bd0040  addiu       $sp, $sp, 0x40
    ctx->pc = 0x1e2134u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x1e2138: 0x3e00008  jr          $ra
    ctx->pc = 0x1E2138u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E1B3Cu: goto label_1e1b3c;
            case 0x1E1B60u: goto label_1e1b60;
            case 0x1E1B84u: goto label_1e1b84;
            case 0x1E1BA8u: goto label_1e1ba8;
            case 0x1E1BC8u: goto label_1e1bc8;
            case 0x1E1BE4u: goto label_1e1be4;
            case 0x1E1BE8u: goto label_1e1be8;
            case 0x1E1C44u: goto label_1e1c44;
            case 0x1E1C58u: goto label_1e1c58;
            case 0x1E1C7Cu: goto label_1e1c7c;
            case 0x1E1CD8u: goto label_1e1cd8;
            case 0x1E1CECu: goto label_1e1cec;
            case 0x1E1D14u: goto label_1e1d14;
            case 0x1E1D7Cu: goto label_1e1d7c;
            case 0x1E1D90u: goto label_1e1d90;
            case 0x1E1DD0u: goto label_1e1dd0;
            case 0x1E1DE0u: goto label_1e1de0;
            case 0x1E1E04u: goto label_1e1e04;
            case 0x1E1E14u: goto label_1e1e14;
            case 0x1E1E38u: goto label_1e1e38;
            case 0x1E1E4Cu: goto label_1e1e4c;
            case 0x1E1E5Cu: goto label_1e1e5c;
            case 0x1E1E84u: goto label_1e1e84;
            case 0x1E1EA0u: goto label_1e1ea0;
            case 0x1E1EB4u: goto label_1e1eb4;
            case 0x1E1ED0u: goto label_1e1ed0;
            case 0x1E1F48u: goto label_1e1f48;
            case 0x1E1F5Cu: goto label_1e1f5c;
            case 0x1E1F9Cu: goto label_1e1f9c;
            case 0x1E1FACu: goto label_1e1fac;
            case 0x1E1FD0u: goto label_1e1fd0;
            case 0x1E1FE0u: goto label_1e1fe0;
            case 0x1E2004u: goto label_1e2004;
            case 0x1E2018u: goto label_1e2018;
            case 0x1E202Cu: goto label_1e202c;
            case 0x1E2064u: goto label_1e2064;
            case 0x1E206Cu: goto label_1e206c;
            case 0x1E2088u: goto label_1e2088;
            case 0x1E20A0u: goto label_1e20a0;
            case 0x1E20D4u: goto label_1e20d4;
            case 0x1E20F8u: goto label_1e20f8;
            case 0x1E210Cu: goto label_1e210c;
            case 0x1E2128u: goto label_1e2128;
            case 0x1E2190u: goto label_1e2190;
            case 0x1E21A4u: goto label_1e21a4;
            case 0x1E21E4u: goto label_1e21e4;
            case 0x1E21F4u: goto label_1e21f4;
            case 0x1E2218u: goto label_1e2218;
            case 0x1E2228u: goto label_1e2228;
            case 0x1E224Cu: goto label_1e224c;
            case 0x1E2260u: goto label_1e2260;
            case 0x1E22D4u: goto label_1e22d4;
            case 0x1E22F0u: goto label_1e22f0;
            case 0x1E2304u: goto label_1e2304;
            case 0x1E2320u: goto label_1e2320;
            case 0x1E23A0u: goto label_1e23a0;
            case 0x1E23B4u: goto label_1e23b4;
            case 0x1E23F4u: goto label_1e23f4;
            case 0x1E2404u: goto label_1e2404;
            case 0x1E2428u: goto label_1e2428;
            case 0x1E2438u: goto label_1e2438;
            case 0x1E245Cu: goto label_1e245c;
            case 0x1E2470u: goto label_1e2470;
            case 0x1E2480u: goto label_1e2480;
            case 0x1E24F8u: goto label_1e24f8;
            case 0x1E2500u: goto label_1e2500;
            case 0x1E2508u: goto label_1e2508;
            case 0x1E25D0u: goto label_1e25d0;
            case 0x1E25ECu: goto label_1e25ec;
            case 0x1E2600u: goto label_1e2600;
            case 0x1E261Cu: goto label_1e261c;
            case 0x1E2684u: goto label_1e2684;
            case 0x1E2698u: goto label_1e2698;
            case 0x1E26D8u: goto label_1e26d8;
            case 0x1E26E8u: goto label_1e26e8;
            case 0x1E270Cu: goto label_1e270c;
            case 0x1E271Cu: goto label_1e271c;
            case 0x1E2740u: goto label_1e2740;
            case 0x1E2754u: goto label_1e2754;
            case 0x1E27C8u: goto label_1e27c8;
            case 0x1E27E4u: goto label_1e27e4;
            case 0x1E27F8u: goto label_1e27f8;
            case 0x1E2814u: goto label_1e2814;
            case 0x1E287Cu: goto label_1e287c;
            case 0x1E2890u: goto label_1e2890;
            case 0x1E28D0u: goto label_1e28d0;
            case 0x1E28E0u: goto label_1e28e0;
            case 0x1E2904u: goto label_1e2904;
            case 0x1E2914u: goto label_1e2914;
            case 0x1E2938u: goto label_1e2938;
            case 0x1E294Cu: goto label_1e294c;
            case 0x1E29C0u: goto label_1e29c0;
            case 0x1E29DCu: goto label_1e29dc;
            case 0x1E29F0u: goto label_1e29f0;
            case 0x1E2A0Cu: goto label_1e2a0c;
            case 0x1E2A78u: goto label_1e2a78;
            case 0x1E2A8Cu: goto label_1e2a8c;
            case 0x1E2ACCu: goto label_1e2acc;
            case 0x1E2ADCu: goto label_1e2adc;
            case 0x1E2B00u: goto label_1e2b00;
            case 0x1E2B10u: goto label_1e2b10;
            case 0x1E2B34u: goto label_1e2b34;
            case 0x1E2B48u: goto label_1e2b48;
            case 0x1E2B54u: goto label_1e2b54;
            case 0x1E2B90u: goto label_1e2b90;
            case 0x1E2B98u: goto label_1e2b98;
            case 0x1E2BC0u: goto label_1e2bc0;
            case 0x1E2BE4u: goto label_1e2be4;
            case 0x1E2BF8u: goto label_1e2bf8;
            case 0x1E2C14u: goto label_1e2c14;
            case 0x1E2C84u: goto label_1e2c84;
            case 0x1E2C98u: goto label_1e2c98;
            case 0x1E2CD8u: goto label_1e2cd8;
            case 0x1E2CE8u: goto label_1e2ce8;
            case 0x1E2D0Cu: goto label_1e2d0c;
            case 0x1E2D1Cu: goto label_1e2d1c;
            case 0x1E2D40u: goto label_1e2d40;
            case 0x1E2D54u: goto label_1e2d54;
            case 0x1E2E10u: goto label_1e2e10;
            case 0x1E2E18u: goto label_1e2e18;
            case 0x1E2E20u: goto label_1e2e20;
            case 0x1E2E48u: goto label_1e2e48;
            case 0x1E2E64u: goto label_1e2e64;
            case 0x1E2E78u: goto label_1e2e78;
            case 0x1E2E94u: goto label_1e2e94;
            case 0x1E2EF8u: goto label_1e2ef8;
            case 0x1E2F0Cu: goto label_1e2f0c;
            case 0x1E2F4Cu: goto label_1e2f4c;
            case 0x1E2F5Cu: goto label_1e2f5c;
            case 0x1E2F80u: goto label_1e2f80;
            case 0x1E2FA8u: goto label_1e2fa8;
            case 0x1E2FC4u: goto label_1e2fc4;
            case 0x1E2FD8u: goto label_1e2fd8;
            case 0x1E2FF4u: goto label_1e2ff4;
            case 0x1E3058u: goto label_1e3058;
            case 0x1E306Cu: goto label_1e306c;
            case 0x1E30ACu: goto label_1e30ac;
            case 0x1E30BCu: goto label_1e30bc;
            case 0x1E30E0u: goto label_1e30e0;
            case 0x1E3108u: goto label_1e3108;
            case 0x1E3124u: goto label_1e3124;
            case 0x1E3138u: goto label_1e3138;
            case 0x1E3154u: goto label_1e3154;
            case 0x1E31CCu: goto label_1e31cc;
            case 0x1E31E0u: goto label_1e31e0;
            case 0x1E3220u: goto label_1e3220;
            case 0x1E3238u: goto label_1e3238;
            case 0x1E325Cu: goto label_1e325c;
            case 0x1E3278u: goto label_1e3278;
            case 0x1E329Cu: goto label_1e329c;
            case 0x1E32B0u: goto label_1e32b0;
            case 0x1E3318u: goto label_1e3318;
            case 0x1E3388u: goto label_1e3388;
            case 0x1E33C4u: goto label_1e33c4;
            case 0x1E33E0u: goto label_1e33e0;
            case 0x1E33F4u: goto label_1e33f4;
            case 0x1E3410u: goto label_1e3410;
            case 0x1E347Cu: goto label_1e347c;
            case 0x1E3490u: goto label_1e3490;
            case 0x1E34D0u: goto label_1e34d0;
            case 0x1E34E0u: goto label_1e34e0;
            case 0x1E3504u: goto label_1e3504;
            case 0x1E3514u: goto label_1e3514;
            case 0x1E3538u: goto label_1e3538;
            case 0x1E354Cu: goto label_1e354c;
            case 0x1E360Cu: goto label_1e360c;
            case 0x1E3628u: goto label_1e3628;
            case 0x1E363Cu: goto label_1e363c;
            case 0x1E3658u: goto label_1e3658;
            case 0x1E36C4u: goto label_1e36c4;
            case 0x1E36D8u: goto label_1e36d8;
            case 0x1E3718u: goto label_1e3718;
            case 0x1E3728u: goto label_1e3728;
            case 0x1E374Cu: goto label_1e374c;
            case 0x1E375Cu: goto label_1e375c;
            case 0x1E3780u: goto label_1e3780;
            case 0x1E3794u: goto label_1e3794;
            case 0x1E3854u: goto label_1e3854;
            case 0x1E3870u: goto label_1e3870;
            case 0x1E3884u: goto label_1e3884;
            case 0x1E38A0u: goto label_1e38a0;
            case 0x1E3908u: goto label_1e3908;
            case 0x1E391Cu: goto label_1e391c;
            case 0x1E395Cu: goto label_1e395c;
            case 0x1E396Cu: goto label_1e396c;
            case 0x1E3990u: goto label_1e3990;
            case 0x1E39A0u: goto label_1e39a0;
            case 0x1E39C4u: goto label_1e39c4;
            case 0x1E39D8u: goto label_1e39d8;
            case 0x1E3A44u: goto label_1e3a44;
            case 0x1E3A60u: goto label_1e3a60;
            case 0x1E3A74u: goto label_1e3a74;
            case 0x1E3A78u: goto label_1e3a78;
            case 0x1E3ADCu: goto label_1e3adc;
            case 0x1E3AF0u: goto label_1e3af0;
            case 0x1E3B30u: goto label_1e3b30;
            case 0x1E3B40u: goto label_1e3b40;
            case 0x1E3B64u: goto label_1e3b64;
            case 0x1E3B84u: goto label_1e3b84;
            case 0x1E3BA0u: goto label_1e3ba0;
            case 0x1E3BB4u: goto label_1e3bb4;
            case 0x1E3BB8u: goto label_1e3bb8;
            case 0x1E3C1Cu: goto label_1e3c1c;
            case 0x1E3C30u: goto label_1e3c30;
            case 0x1E3C70u: goto label_1e3c70;
            case 0x1E3C80u: goto label_1e3c80;
            case 0x1E3CA4u: goto label_1e3ca4;
            case 0x1E3CC4u: goto label_1e3cc4;
            case 0x1E3CE8u: goto label_1e3ce8;
            case 0x1E3CFCu: goto label_1e3cfc;
            case 0x1E3D00u: goto label_1e3d00;
            case 0x1E3D68u: goto label_1e3d68;
            case 0x1E3D7Cu: goto label_1e3d7c;
            case 0x1E3DBCu: goto label_1e3dbc;
            case 0x1E3DCCu: goto label_1e3dcc;
            case 0x1E3DF0u: goto label_1e3df0;
            case 0x1E3E00u: goto label_1e3e00;
            case 0x1E3E24u: goto label_1e3e24;
            case 0x1E3E38u: goto label_1e3e38;
            case 0x1E3EA4u: goto label_1e3ea4;
            case 0x1E3EC0u: goto label_1e3ec0;
            case 0x1E3ED4u: goto label_1e3ed4;
            case 0x1E3ED8u: goto label_1e3ed8;
            case 0x1E3F40u: goto label_1e3f40;
            case 0x1E3F54u: goto label_1e3f54;
            case 0x1E3F94u: goto label_1e3f94;
            case 0x1E3FA4u: goto label_1e3fa4;
            case 0x1E3FC8u: goto label_1e3fc8;
            case 0x1E3FD8u: goto label_1e3fd8;
            case 0x1E3FFCu: goto label_1e3ffc;
            case 0x1E4010u: goto label_1e4010;
            case 0x1E407Cu: goto label_1e407c;
            case 0x1E4098u: goto label_1e4098;
            case 0x1E40ACu: goto label_1e40ac;
            case 0x1E40B0u: goto label_1e40b0;
            case 0x1E4118u: goto label_1e4118;
            case 0x1E412Cu: goto label_1e412c;
            case 0x1E416Cu: goto label_1e416c;
            case 0x1E417Cu: goto label_1e417c;
            case 0x1E41A0u: goto label_1e41a0;
            case 0x1E41B0u: goto label_1e41b0;
            case 0x1E41D4u: goto label_1e41d4;
            case 0x1E41E8u: goto label_1e41e8;
            case 0x1E4254u: goto label_1e4254;
            case 0x1E4270u: goto label_1e4270;
            case 0x1E4284u: goto label_1e4284;
            case 0x1E4288u: goto label_1e4288;
            case 0x1E42F0u: goto label_1e42f0;
            case 0x1E4304u: goto label_1e4304;
            case 0x1E4344u: goto label_1e4344;
            case 0x1E4358u: goto label_1e4358;
            case 0x1E437Cu: goto label_1e437c;
            case 0x1E4394u: goto label_1e4394;
            case 0x1E43B8u: goto label_1e43b8;
            case 0x1E43CCu: goto label_1e43cc;
            case 0x1E43E4u: goto label_1e43e4;
            case 0x1E4414u: goto label_1e4414;
            case 0x1E4430u: goto label_1e4430;
            case 0x1E4444u: goto label_1e4444;
            case 0x1E4460u: goto label_1e4460;
            case 0x1E44C8u: goto label_1e44c8;
            case 0x1E44DCu: goto label_1e44dc;
            case 0x1E451Cu: goto label_1e451c;
            case 0x1E452Cu: goto label_1e452c;
            case 0x1E4550u: goto label_1e4550;
            case 0x1E4560u: goto label_1e4560;
            case 0x1E4584u: goto label_1e4584;
            case 0x1E4598u: goto label_1e4598;
            case 0x1E460Cu: goto label_1e460c;
            case 0x1E4628u: goto label_1e4628;
            case 0x1E463Cu: goto label_1e463c;
            case 0x1E4658u: goto label_1e4658;
            case 0x1E46C8u: goto label_1e46c8;
            case 0x1E46DCu: goto label_1e46dc;
            case 0x1E471Cu: goto label_1e471c;
            case 0x1E472Cu: goto label_1e472c;
            case 0x1E4750u: goto label_1e4750;
            case 0x1E4764u: goto label_1e4764;
            case 0x1E4788u: goto label_1e4788;
            case 0x1E479Cu: goto label_1e479c;
            case 0x1E47B0u: goto label_1e47b0;
            case 0x1E47E0u: goto label_1e47e0;
            case 0x1E47FCu: goto label_1e47fc;
            case 0x1E4800u: goto label_1e4800;
            case 0x1E48A0u: goto label_1e48a0;
            case 0x1E48B4u: goto label_1e48b4;
            case 0x1E48F4u: goto label_1e48f4;
            case 0x1E4918u: goto label_1e4918;
            case 0x1E493Cu: goto label_1e493c;
            case 0x1E4974u: goto label_1e4974;
            case 0x1E4998u: goto label_1e4998;
            case 0x1E49ACu: goto label_1e49ac;
            case 0x1E4A08u: goto label_1e4a08;
            case 0x1E4A24u: goto label_1e4a24;
            case 0x1E4AACu: goto label_1e4aac;
            case 0x1E4AC0u: goto label_1e4ac0;
            case 0x1E4B00u: goto label_1e4b00;
            case 0x1E4B1Cu: goto label_1e4b1c;
            case 0x1E4B20u: goto label_1e4b20;
            case 0x1E4B94u: goto label_1e4b94;
            case 0x1E4BA8u: goto label_1e4ba8;
            case 0x1E4BE8u: goto label_1e4be8;
            case 0x1E4C10u: goto label_1e4c10;
            case 0x1E4C34u: goto label_1e4c34;
            case 0x1E4C64u: goto label_1e4c64;
            case 0x1E4C88u: goto label_1e4c88;
            case 0x1E4C9Cu: goto label_1e4c9c;
            case 0x1E4D08u: goto label_1e4d08;
            case 0x1E4D28u: goto label_1e4d28;
            case 0x1E4DE4u: goto label_1e4de4;
            case 0x1E4DF8u: goto label_1e4df8;
            case 0x1E4E3Cu: goto label_1e4e3c;
            case 0x1E4E58u: goto label_1e4e58;
            case 0x1E4E5Cu: goto label_1e4e5c;
            case 0x1E4EC4u: goto label_1e4ec4;
            case 0x1E4ED8u: goto label_1e4ed8;
            case 0x1E4F18u: goto label_1e4f18;
            case 0x1E4F28u: goto label_1e4f28;
            case 0x1E4F4Cu: goto label_1e4f4c;
            case 0x1E4F60u: goto label_1e4f60;
            case 0x1E4F84u: goto label_1e4f84;
            case 0x1E4F98u: goto label_1e4f98;
            case 0x1E4FACu: goto label_1e4fac;
            case 0x1E4FD0u: goto label_1e4fd0;
            case 0x1E4FECu: goto label_1e4fec;
            case 0x1E4FF0u: goto label_1e4ff0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E2140u;
    // 0x1e2140: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1e2140u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1e2144: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1e2144u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1e2148: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1e2148u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1e214c: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e214cu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e2150: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e2150u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e2154: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e2154u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e2158: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e2158u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e215c: 0xafc00014  sw          $zero, 0x14($fp)
    ctx->pc = 0x1e215cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 0));
    // 0x1e2160: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e2160u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e2164: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e2164u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e2168: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E2168u;
    {
        const bool branch_taken_0x1e2168 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e2168) {
            ctx->pc = 0x1E2190u;
            goto label_1e2190;
        }
    }
    ctx->pc = 0x1E2170u;
    // 0x1e2170: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e2170u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e2174: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e2174u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e2178: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e2178u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e217c: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e217cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e2180: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e2180u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e2184: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e2184u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e2188: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E2188u;
    {
        const bool branch_taken_0x1e2188 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e2188) {
            ctx->pc = 0x1E21A4u;
            goto label_1e21a4;
        }
    }
    ctx->pc = 0x1E2190u;
label_1e2190:
    // 0x1e2190: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e2190u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e2194: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e2194u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e2198: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e2198u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e219c: 0x10000060  b           . + 4 + (0x60 << 2)
    ctx->pc = 0x1E219Cu;
    {
        const bool branch_taken_0x1e219c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e219c) {
            ctx->pc = 0x1E2320u;
            goto label_1e2320;
        }
    }
    ctx->pc = 0x1E21A4u;
label_1e21a4:
    // 0x1e21a4: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e21a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e21a8: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e21a8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e21ac: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e21acu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e21b0: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e21b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e21b4: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e21b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e21b8: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e21b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e21bc: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1e21bcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1e21c0: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e21c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e21c4: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e21c4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e21c8: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E21C8u;
    {
        const bool branch_taken_0x1e21c8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e21c8) {
            ctx->pc = 0x1E21E4u;
            goto label_1e21e4;
        }
    }
    ctx->pc = 0x1E21D0u;
    // 0x1e21d0: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e21d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e21d4: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e21d4u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e21d8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e21d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e21dc: 0x10000050  b           . + 4 + (0x50 << 2)
    ctx->pc = 0x1E21DCu;
    {
        const bool branch_taken_0x1e21dc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e21dc) {
            ctx->pc = 0x1E2320u;
            goto label_1e2320;
        }
    }
    ctx->pc = 0x1E21E4u;
label_1e21e4:
    // 0x1e21e4: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e21e4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e21e8: 0x24050004  addiu       $a1, $zero, 0x4
    ctx->pc = 0x1e21e8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1e21ec: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E21ECu;
    SET_GPR_U32(ctx, 31, 0x1E21F4u);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E21F4u; }
        if (ctx->pc != 0x1E21F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E21F4u; }
        if (ctx->pc != 0x1E21F4u) { return; }
    }
    ctx->pc = 0x1E21F4u;
label_1e21f4:
    // 0x1e21f4: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1e21f4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1e21f8: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e21f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e21fc: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E21FCu;
    {
        const bool branch_taken_0x1e21fc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e21fc) {
            ctx->pc = 0x1E2218u;
            goto label_1e2218;
        }
    }
    ctx->pc = 0x1E2204u;
    // 0x1e2204: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e2204u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e2208: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e2208u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e220c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e220cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e2210: 0x10000043  b           . + 4 + (0x43 << 2)
    ctx->pc = 0x1E2210u;
    {
        const bool branch_taken_0x1e2210 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e2210) {
            ctx->pc = 0x1E2320u;
            goto label_1e2320;
        }
    }
    ctx->pc = 0x1E2218u;
label_1e2218:
    // 0x1e2218: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1e2218u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e221c: 0x24050004  addiu       $a1, $zero, 0x4
    ctx->pc = 0x1e221cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1e2220: 0xc07cc3c  jal         func_1F30F0
    ctx->pc = 0x1E2220u;
    SET_GPR_U32(ctx, 31, 0x1E2228u);
    ctx->pc = 0x1F30F0u;
    if (runtime->hasFunction(0x1F30F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F30F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2228u; }
        if (ctx->pc != 0x1E2228u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F30F0_0x1f30f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2228u; }
        if (ctx->pc != 0x1E2228u) { return; }
    }
    ctx->pc = 0x1E2228u;
label_1e2228:
    // 0x1e2228: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1e2228u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1e222c: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e222cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e2230: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1E2230u;
    {
        const bool branch_taken_0x1e2230 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e2230) {
            ctx->pc = 0x1E2260u;
            goto label_1e2260;
        }
    }
    ctx->pc = 0x1E2238u;
    // 0x1e2238: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e2238u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e223c: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1e223cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1e2240: 0x8fc5000c  lw          $a1, 0xC($fp)
    ctx->pc = 0x1e2240u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e2244: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1E2244u;
    SET_GPR_U32(ctx, 31, 0x1E224Cu);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E224Cu; }
        if (ctx->pc != 0x1E224Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E224Cu; }
        if (ctx->pc != 0x1E224Cu) { return; }
    }
    ctx->pc = 0x1E224Cu;
label_1e224c:
    // 0x1e224c: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e224cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e2250: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e2250u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e2254: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e2254u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e2258: 0x10000031  b           . + 4 + (0x31 << 2)
    ctx->pc = 0x1E2258u;
    {
        const bool branch_taken_0x1e2258 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e2258) {
            ctx->pc = 0x1E2320u;
            goto label_1e2320;
        }
    }
    ctx->pc = 0x1E2260u;
label_1e2260:
    // 0x1e2260: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e2260u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e2264: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e2264u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e2268: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1e2268u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1e226c: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1e226cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1e2270: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e2270u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e2274: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1e2274u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1e2278: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1e2278u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1e227c: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1e227cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e2280: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1e2280u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e2284: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1e2284u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1e2288: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e2288u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e228c: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1e228cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1e2290: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1e2290u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e2294: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1e2294u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e2298: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1e2298u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1e229c: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e229cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e22a0: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1e22a0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1e22a4: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1e22a4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e22a8: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x1e22a8u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x1e22ac: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e22acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e22b0: 0x90420615  lbu         $v0, 0x615($v0)
    ctx->pc = 0x1e22b0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 1557)));
    // 0x1e22b4: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e22b4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e22b8: 0x8fc5000c  lw          $a1, 0xC($fp)
    ctx->pc = 0x1e22b8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e22bc: 0x3406b000  ori         $a2, $zero, 0xB000
    ctx->pc = 0x1e22bcu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)45056);
    // 0x1e22c0: 0x24070004  addiu       $a3, $zero, 0x4
    ctx->pc = 0x1e22c0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1e22c4: 0x24080005  addiu       $t0, $zero, 0x5
    ctx->pc = 0x1e22c4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1e22c8: 0x40482d  daddu       $t1, $v0, $zero
    ctx->pc = 0x1e22c8u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e22cc: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E22CCu;
    SET_GPR_U32(ctx, 31, 0x1E22D4u);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E22D4u; }
        if (ctx->pc != 0x1E22D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E22D4u; }
        if (ctx->pc != 0x1E22D4u) { return; }
    }
    ctx->pc = 0x1E22D4u;
label_1e22d4:
    // 0x1e22d4: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E22D4u;
    {
        const bool branch_taken_0x1e22d4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e22d4) {
            ctx->pc = 0x1E22F0u;
            goto label_1e22f0;
        }
    }
    ctx->pc = 0x1E22DCu;
    // 0x1e22dc: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e22dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e22e0: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e22e0u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e22e4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e22e4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e22e8: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1E22E8u;
    {
        const bool branch_taken_0x1e22e8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e22e8) {
            ctx->pc = 0x1E2320u;
            goto label_1e2320;
        }
    }
    ctx->pc = 0x1E22F0u;
label_1e22f0:
    // 0x1e22f0: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1e22f0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e22f4: 0x2405001e  addiu       $a1, $zero, 0x1E
    ctx->pc = 0x1e22f4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 30));
    // 0x1e22f8: 0x8fc60008  lw          $a2, 0x8($fp)
    ctx->pc = 0x1e22f8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e22fc: 0xc076ad5  jal         func_1DAB54
    ctx->pc = 0x1E22FCu;
    SET_GPR_U32(ctx, 31, 0x1E2304u);
    ctx->pc = 0x1DAB54u;
    if (runtime->hasFunction(0x1DAB54u)) {
        auto targetFn = runtime->lookupFunction(0x1DAB54u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2304u; }
        if (ctx->pc != 0x1E2304u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DAB54_0x1dab54(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2304u; }
        if (ctx->pc != 0x1E2304u) { return; }
    }
    ctx->pc = 0x1E2304u;
label_1e2304:
    // 0x1e2304: 0x8fc30014  lw          $v1, 0x14($fp)
    ctx->pc = 0x1e2304u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e2308: 0x90640615  lbu         $a0, 0x615($v1)
    ctx->pc = 0x1e2308u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 1557)));
    // 0x1e230c: 0x24820001  addiu       $v0, $a0, 0x1
    ctx->pc = 0x1e230cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1e2310: 0xa0620615  sb          $v0, 0x615($v1)
    ctx->pc = 0x1e2310u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 1557), (uint8_t)GPR_U32(ctx, 2));
    // 0x1e2314: 0x308200ff  andi        $v0, $a0, 0xFF
    ctx->pc = 0x1e2314u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x1e2318: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1e2318u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1e231c: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e231cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
label_1e2320:
    // 0x1e2320: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e2320u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e2324: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1e2324u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1e2328: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1e2328u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1e232c: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1e232cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1e2330: 0x3e00008  jr          $ra
    ctx->pc = 0x1E2330u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E1B3Cu: goto label_1e1b3c;
            case 0x1E1B60u: goto label_1e1b60;
            case 0x1E1B84u: goto label_1e1b84;
            case 0x1E1BA8u: goto label_1e1ba8;
            case 0x1E1BC8u: goto label_1e1bc8;
            case 0x1E1BE4u: goto label_1e1be4;
            case 0x1E1BE8u: goto label_1e1be8;
            case 0x1E1C44u: goto label_1e1c44;
            case 0x1E1C58u: goto label_1e1c58;
            case 0x1E1C7Cu: goto label_1e1c7c;
            case 0x1E1CD8u: goto label_1e1cd8;
            case 0x1E1CECu: goto label_1e1cec;
            case 0x1E1D14u: goto label_1e1d14;
            case 0x1E1D7Cu: goto label_1e1d7c;
            case 0x1E1D90u: goto label_1e1d90;
            case 0x1E1DD0u: goto label_1e1dd0;
            case 0x1E1DE0u: goto label_1e1de0;
            case 0x1E1E04u: goto label_1e1e04;
            case 0x1E1E14u: goto label_1e1e14;
            case 0x1E1E38u: goto label_1e1e38;
            case 0x1E1E4Cu: goto label_1e1e4c;
            case 0x1E1E5Cu: goto label_1e1e5c;
            case 0x1E1E84u: goto label_1e1e84;
            case 0x1E1EA0u: goto label_1e1ea0;
            case 0x1E1EB4u: goto label_1e1eb4;
            case 0x1E1ED0u: goto label_1e1ed0;
            case 0x1E1F48u: goto label_1e1f48;
            case 0x1E1F5Cu: goto label_1e1f5c;
            case 0x1E1F9Cu: goto label_1e1f9c;
            case 0x1E1FACu: goto label_1e1fac;
            case 0x1E1FD0u: goto label_1e1fd0;
            case 0x1E1FE0u: goto label_1e1fe0;
            case 0x1E2004u: goto label_1e2004;
            case 0x1E2018u: goto label_1e2018;
            case 0x1E202Cu: goto label_1e202c;
            case 0x1E2064u: goto label_1e2064;
            case 0x1E206Cu: goto label_1e206c;
            case 0x1E2088u: goto label_1e2088;
            case 0x1E20A0u: goto label_1e20a0;
            case 0x1E20D4u: goto label_1e20d4;
            case 0x1E20F8u: goto label_1e20f8;
            case 0x1E210Cu: goto label_1e210c;
            case 0x1E2128u: goto label_1e2128;
            case 0x1E2190u: goto label_1e2190;
            case 0x1E21A4u: goto label_1e21a4;
            case 0x1E21E4u: goto label_1e21e4;
            case 0x1E21F4u: goto label_1e21f4;
            case 0x1E2218u: goto label_1e2218;
            case 0x1E2228u: goto label_1e2228;
            case 0x1E224Cu: goto label_1e224c;
            case 0x1E2260u: goto label_1e2260;
            case 0x1E22D4u: goto label_1e22d4;
            case 0x1E22F0u: goto label_1e22f0;
            case 0x1E2304u: goto label_1e2304;
            case 0x1E2320u: goto label_1e2320;
            case 0x1E23A0u: goto label_1e23a0;
            case 0x1E23B4u: goto label_1e23b4;
            case 0x1E23F4u: goto label_1e23f4;
            case 0x1E2404u: goto label_1e2404;
            case 0x1E2428u: goto label_1e2428;
            case 0x1E2438u: goto label_1e2438;
            case 0x1E245Cu: goto label_1e245c;
            case 0x1E2470u: goto label_1e2470;
            case 0x1E2480u: goto label_1e2480;
            case 0x1E24F8u: goto label_1e24f8;
            case 0x1E2500u: goto label_1e2500;
            case 0x1E2508u: goto label_1e2508;
            case 0x1E25D0u: goto label_1e25d0;
            case 0x1E25ECu: goto label_1e25ec;
            case 0x1E2600u: goto label_1e2600;
            case 0x1E261Cu: goto label_1e261c;
            case 0x1E2684u: goto label_1e2684;
            case 0x1E2698u: goto label_1e2698;
            case 0x1E26D8u: goto label_1e26d8;
            case 0x1E26E8u: goto label_1e26e8;
            case 0x1E270Cu: goto label_1e270c;
            case 0x1E271Cu: goto label_1e271c;
            case 0x1E2740u: goto label_1e2740;
            case 0x1E2754u: goto label_1e2754;
            case 0x1E27C8u: goto label_1e27c8;
            case 0x1E27E4u: goto label_1e27e4;
            case 0x1E27F8u: goto label_1e27f8;
            case 0x1E2814u: goto label_1e2814;
            case 0x1E287Cu: goto label_1e287c;
            case 0x1E2890u: goto label_1e2890;
            case 0x1E28D0u: goto label_1e28d0;
            case 0x1E28E0u: goto label_1e28e0;
            case 0x1E2904u: goto label_1e2904;
            case 0x1E2914u: goto label_1e2914;
            case 0x1E2938u: goto label_1e2938;
            case 0x1E294Cu: goto label_1e294c;
            case 0x1E29C0u: goto label_1e29c0;
            case 0x1E29DCu: goto label_1e29dc;
            case 0x1E29F0u: goto label_1e29f0;
            case 0x1E2A0Cu: goto label_1e2a0c;
            case 0x1E2A78u: goto label_1e2a78;
            case 0x1E2A8Cu: goto label_1e2a8c;
            case 0x1E2ACCu: goto label_1e2acc;
            case 0x1E2ADCu: goto label_1e2adc;
            case 0x1E2B00u: goto label_1e2b00;
            case 0x1E2B10u: goto label_1e2b10;
            case 0x1E2B34u: goto label_1e2b34;
            case 0x1E2B48u: goto label_1e2b48;
            case 0x1E2B54u: goto label_1e2b54;
            case 0x1E2B90u: goto label_1e2b90;
            case 0x1E2B98u: goto label_1e2b98;
            case 0x1E2BC0u: goto label_1e2bc0;
            case 0x1E2BE4u: goto label_1e2be4;
            case 0x1E2BF8u: goto label_1e2bf8;
            case 0x1E2C14u: goto label_1e2c14;
            case 0x1E2C84u: goto label_1e2c84;
            case 0x1E2C98u: goto label_1e2c98;
            case 0x1E2CD8u: goto label_1e2cd8;
            case 0x1E2CE8u: goto label_1e2ce8;
            case 0x1E2D0Cu: goto label_1e2d0c;
            case 0x1E2D1Cu: goto label_1e2d1c;
            case 0x1E2D40u: goto label_1e2d40;
            case 0x1E2D54u: goto label_1e2d54;
            case 0x1E2E10u: goto label_1e2e10;
            case 0x1E2E18u: goto label_1e2e18;
            case 0x1E2E20u: goto label_1e2e20;
            case 0x1E2E48u: goto label_1e2e48;
            case 0x1E2E64u: goto label_1e2e64;
            case 0x1E2E78u: goto label_1e2e78;
            case 0x1E2E94u: goto label_1e2e94;
            case 0x1E2EF8u: goto label_1e2ef8;
            case 0x1E2F0Cu: goto label_1e2f0c;
            case 0x1E2F4Cu: goto label_1e2f4c;
            case 0x1E2F5Cu: goto label_1e2f5c;
            case 0x1E2F80u: goto label_1e2f80;
            case 0x1E2FA8u: goto label_1e2fa8;
            case 0x1E2FC4u: goto label_1e2fc4;
            case 0x1E2FD8u: goto label_1e2fd8;
            case 0x1E2FF4u: goto label_1e2ff4;
            case 0x1E3058u: goto label_1e3058;
            case 0x1E306Cu: goto label_1e306c;
            case 0x1E30ACu: goto label_1e30ac;
            case 0x1E30BCu: goto label_1e30bc;
            case 0x1E30E0u: goto label_1e30e0;
            case 0x1E3108u: goto label_1e3108;
            case 0x1E3124u: goto label_1e3124;
            case 0x1E3138u: goto label_1e3138;
            case 0x1E3154u: goto label_1e3154;
            case 0x1E31CCu: goto label_1e31cc;
            case 0x1E31E0u: goto label_1e31e0;
            case 0x1E3220u: goto label_1e3220;
            case 0x1E3238u: goto label_1e3238;
            case 0x1E325Cu: goto label_1e325c;
            case 0x1E3278u: goto label_1e3278;
            case 0x1E329Cu: goto label_1e329c;
            case 0x1E32B0u: goto label_1e32b0;
            case 0x1E3318u: goto label_1e3318;
            case 0x1E3388u: goto label_1e3388;
            case 0x1E33C4u: goto label_1e33c4;
            case 0x1E33E0u: goto label_1e33e0;
            case 0x1E33F4u: goto label_1e33f4;
            case 0x1E3410u: goto label_1e3410;
            case 0x1E347Cu: goto label_1e347c;
            case 0x1E3490u: goto label_1e3490;
            case 0x1E34D0u: goto label_1e34d0;
            case 0x1E34E0u: goto label_1e34e0;
            case 0x1E3504u: goto label_1e3504;
            case 0x1E3514u: goto label_1e3514;
            case 0x1E3538u: goto label_1e3538;
            case 0x1E354Cu: goto label_1e354c;
            case 0x1E360Cu: goto label_1e360c;
            case 0x1E3628u: goto label_1e3628;
            case 0x1E363Cu: goto label_1e363c;
            case 0x1E3658u: goto label_1e3658;
            case 0x1E36C4u: goto label_1e36c4;
            case 0x1E36D8u: goto label_1e36d8;
            case 0x1E3718u: goto label_1e3718;
            case 0x1E3728u: goto label_1e3728;
            case 0x1E374Cu: goto label_1e374c;
            case 0x1E375Cu: goto label_1e375c;
            case 0x1E3780u: goto label_1e3780;
            case 0x1E3794u: goto label_1e3794;
            case 0x1E3854u: goto label_1e3854;
            case 0x1E3870u: goto label_1e3870;
            case 0x1E3884u: goto label_1e3884;
            case 0x1E38A0u: goto label_1e38a0;
            case 0x1E3908u: goto label_1e3908;
            case 0x1E391Cu: goto label_1e391c;
            case 0x1E395Cu: goto label_1e395c;
            case 0x1E396Cu: goto label_1e396c;
            case 0x1E3990u: goto label_1e3990;
            case 0x1E39A0u: goto label_1e39a0;
            case 0x1E39C4u: goto label_1e39c4;
            case 0x1E39D8u: goto label_1e39d8;
            case 0x1E3A44u: goto label_1e3a44;
            case 0x1E3A60u: goto label_1e3a60;
            case 0x1E3A74u: goto label_1e3a74;
            case 0x1E3A78u: goto label_1e3a78;
            case 0x1E3ADCu: goto label_1e3adc;
            case 0x1E3AF0u: goto label_1e3af0;
            case 0x1E3B30u: goto label_1e3b30;
            case 0x1E3B40u: goto label_1e3b40;
            case 0x1E3B64u: goto label_1e3b64;
            case 0x1E3B84u: goto label_1e3b84;
            case 0x1E3BA0u: goto label_1e3ba0;
            case 0x1E3BB4u: goto label_1e3bb4;
            case 0x1E3BB8u: goto label_1e3bb8;
            case 0x1E3C1Cu: goto label_1e3c1c;
            case 0x1E3C30u: goto label_1e3c30;
            case 0x1E3C70u: goto label_1e3c70;
            case 0x1E3C80u: goto label_1e3c80;
            case 0x1E3CA4u: goto label_1e3ca4;
            case 0x1E3CC4u: goto label_1e3cc4;
            case 0x1E3CE8u: goto label_1e3ce8;
            case 0x1E3CFCu: goto label_1e3cfc;
            case 0x1E3D00u: goto label_1e3d00;
            case 0x1E3D68u: goto label_1e3d68;
            case 0x1E3D7Cu: goto label_1e3d7c;
            case 0x1E3DBCu: goto label_1e3dbc;
            case 0x1E3DCCu: goto label_1e3dcc;
            case 0x1E3DF0u: goto label_1e3df0;
            case 0x1E3E00u: goto label_1e3e00;
            case 0x1E3E24u: goto label_1e3e24;
            case 0x1E3E38u: goto label_1e3e38;
            case 0x1E3EA4u: goto label_1e3ea4;
            case 0x1E3EC0u: goto label_1e3ec0;
            case 0x1E3ED4u: goto label_1e3ed4;
            case 0x1E3ED8u: goto label_1e3ed8;
            case 0x1E3F40u: goto label_1e3f40;
            case 0x1E3F54u: goto label_1e3f54;
            case 0x1E3F94u: goto label_1e3f94;
            case 0x1E3FA4u: goto label_1e3fa4;
            case 0x1E3FC8u: goto label_1e3fc8;
            case 0x1E3FD8u: goto label_1e3fd8;
            case 0x1E3FFCu: goto label_1e3ffc;
            case 0x1E4010u: goto label_1e4010;
            case 0x1E407Cu: goto label_1e407c;
            case 0x1E4098u: goto label_1e4098;
            case 0x1E40ACu: goto label_1e40ac;
            case 0x1E40B0u: goto label_1e40b0;
            case 0x1E4118u: goto label_1e4118;
            case 0x1E412Cu: goto label_1e412c;
            case 0x1E416Cu: goto label_1e416c;
            case 0x1E417Cu: goto label_1e417c;
            case 0x1E41A0u: goto label_1e41a0;
            case 0x1E41B0u: goto label_1e41b0;
            case 0x1E41D4u: goto label_1e41d4;
            case 0x1E41E8u: goto label_1e41e8;
            case 0x1E4254u: goto label_1e4254;
            case 0x1E4270u: goto label_1e4270;
            case 0x1E4284u: goto label_1e4284;
            case 0x1E4288u: goto label_1e4288;
            case 0x1E42F0u: goto label_1e42f0;
            case 0x1E4304u: goto label_1e4304;
            case 0x1E4344u: goto label_1e4344;
            case 0x1E4358u: goto label_1e4358;
            case 0x1E437Cu: goto label_1e437c;
            case 0x1E4394u: goto label_1e4394;
            case 0x1E43B8u: goto label_1e43b8;
            case 0x1E43CCu: goto label_1e43cc;
            case 0x1E43E4u: goto label_1e43e4;
            case 0x1E4414u: goto label_1e4414;
            case 0x1E4430u: goto label_1e4430;
            case 0x1E4444u: goto label_1e4444;
            case 0x1E4460u: goto label_1e4460;
            case 0x1E44C8u: goto label_1e44c8;
            case 0x1E44DCu: goto label_1e44dc;
            case 0x1E451Cu: goto label_1e451c;
            case 0x1E452Cu: goto label_1e452c;
            case 0x1E4550u: goto label_1e4550;
            case 0x1E4560u: goto label_1e4560;
            case 0x1E4584u: goto label_1e4584;
            case 0x1E4598u: goto label_1e4598;
            case 0x1E460Cu: goto label_1e460c;
            case 0x1E4628u: goto label_1e4628;
            case 0x1E463Cu: goto label_1e463c;
            case 0x1E4658u: goto label_1e4658;
            case 0x1E46C8u: goto label_1e46c8;
            case 0x1E46DCu: goto label_1e46dc;
            case 0x1E471Cu: goto label_1e471c;
            case 0x1E472Cu: goto label_1e472c;
            case 0x1E4750u: goto label_1e4750;
            case 0x1E4764u: goto label_1e4764;
            case 0x1E4788u: goto label_1e4788;
            case 0x1E479Cu: goto label_1e479c;
            case 0x1E47B0u: goto label_1e47b0;
            case 0x1E47E0u: goto label_1e47e0;
            case 0x1E47FCu: goto label_1e47fc;
            case 0x1E4800u: goto label_1e4800;
            case 0x1E48A0u: goto label_1e48a0;
            case 0x1E48B4u: goto label_1e48b4;
            case 0x1E48F4u: goto label_1e48f4;
            case 0x1E4918u: goto label_1e4918;
            case 0x1E493Cu: goto label_1e493c;
            case 0x1E4974u: goto label_1e4974;
            case 0x1E4998u: goto label_1e4998;
            case 0x1E49ACu: goto label_1e49ac;
            case 0x1E4A08u: goto label_1e4a08;
            case 0x1E4A24u: goto label_1e4a24;
            case 0x1E4AACu: goto label_1e4aac;
            case 0x1E4AC0u: goto label_1e4ac0;
            case 0x1E4B00u: goto label_1e4b00;
            case 0x1E4B1Cu: goto label_1e4b1c;
            case 0x1E4B20u: goto label_1e4b20;
            case 0x1E4B94u: goto label_1e4b94;
            case 0x1E4BA8u: goto label_1e4ba8;
            case 0x1E4BE8u: goto label_1e4be8;
            case 0x1E4C10u: goto label_1e4c10;
            case 0x1E4C34u: goto label_1e4c34;
            case 0x1E4C64u: goto label_1e4c64;
            case 0x1E4C88u: goto label_1e4c88;
            case 0x1E4C9Cu: goto label_1e4c9c;
            case 0x1E4D08u: goto label_1e4d08;
            case 0x1E4D28u: goto label_1e4d28;
            case 0x1E4DE4u: goto label_1e4de4;
            case 0x1E4DF8u: goto label_1e4df8;
            case 0x1E4E3Cu: goto label_1e4e3c;
            case 0x1E4E58u: goto label_1e4e58;
            case 0x1E4E5Cu: goto label_1e4e5c;
            case 0x1E4EC4u: goto label_1e4ec4;
            case 0x1E4ED8u: goto label_1e4ed8;
            case 0x1E4F18u: goto label_1e4f18;
            case 0x1E4F28u: goto label_1e4f28;
            case 0x1E4F4Cu: goto label_1e4f4c;
            case 0x1E4F60u: goto label_1e4f60;
            case 0x1E4F84u: goto label_1e4f84;
            case 0x1E4F98u: goto label_1e4f98;
            case 0x1E4FACu: goto label_1e4fac;
            case 0x1E4FD0u: goto label_1e4fd0;
            case 0x1E4FECu: goto label_1e4fec;
            case 0x1E4FF0u: goto label_1e4ff0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E2338u;
    // 0x1e2338: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1e2338u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1e233c: 0xffbe0030  sd          $fp, 0x30($sp)
    ctx->pc = 0x1e233cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 30));
    // 0x1e2340: 0xffbf0038  sd          $ra, 0x38($sp)
    ctx->pc = 0x1e2340u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x1e2344: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e2344u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e2348: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e2348u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e234c: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e234cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e2350: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e2350u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e2354: 0xe0102d  daddu       $v0, $a3, $zero
    ctx->pc = 0x1e2354u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e2358: 0x100182d  daddu       $v1, $t0, $zero
    ctx->pc = 0x1e2358u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e235c: 0xafc90010  sw          $t1, 0x10($fp)
    ctx->pc = 0x1e235cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 9));
    // 0x1e2360: 0xafca0014  sw          $t2, 0x14($fp)
    ctx->pc = 0x1e2360u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 10));
    // 0x1e2364: 0xa7c2000c  sh          $v0, 0xC($fp)
    ctx->pc = 0x1e2364u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 12), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e2368: 0xa7c3000e  sh          $v1, 0xE($fp)
    ctx->pc = 0x1e2368u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 14), (uint16_t)GPR_U32(ctx, 3));
    // 0x1e236c: 0xafc00020  sw          $zero, 0x20($fp)
    ctx->pc = 0x1e236cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 0));
    // 0x1e2370: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e2370u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e2374: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e2374u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e2378: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E2378u;
    {
        const bool branch_taken_0x1e2378 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e2378) {
            ctx->pc = 0x1E23A0u;
            goto label_1e23a0;
        }
    }
    ctx->pc = 0x1E2380u;
    // 0x1e2380: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e2380u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e2384: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e2384u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e2388: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e2388u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e238c: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e238cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e2390: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e2390u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e2394: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e2394u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e2398: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E2398u;
    {
        const bool branch_taken_0x1e2398 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e2398) {
            ctx->pc = 0x1E23B4u;
            goto label_1e23b4;
        }
    }
    ctx->pc = 0x1E23A0u;
label_1e23a0:
    // 0x1e23a0: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e23a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e23a4: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e23a4u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e23a8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e23a8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e23ac: 0x1000009b  b           . + 4 + (0x9B << 2)
    ctx->pc = 0x1E23ACu;
    {
        const bool branch_taken_0x1e23ac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e23ac) {
            ctx->pc = 0x1E261Cu;
            goto label_1e261c;
        }
    }
    ctx->pc = 0x1E23B4u;
label_1e23b4:
    // 0x1e23b4: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e23b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e23b8: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e23b8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e23bc: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e23bcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e23c0: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e23c0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e23c4: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e23c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e23c8: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e23c8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e23cc: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1e23ccu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1e23d0: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e23d0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e23d4: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e23d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e23d8: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E23D8u;
    {
        const bool branch_taken_0x1e23d8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e23d8) {
            ctx->pc = 0x1E23F4u;
            goto label_1e23f4;
        }
    }
    ctx->pc = 0x1E23E0u;
    // 0x1e23e0: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e23e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e23e4: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e23e4u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e23e8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e23e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e23ec: 0x1000008b  b           . + 4 + (0x8B << 2)
    ctx->pc = 0x1E23ECu;
    {
        const bool branch_taken_0x1e23ec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e23ec) {
            ctx->pc = 0x1E261Cu;
            goto label_1e261c;
        }
    }
    ctx->pc = 0x1E23F4u;
label_1e23f4:
    // 0x1e23f4: 0x8fc40020  lw          $a0, 0x20($fp)
    ctx->pc = 0x1e23f4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e23f8: 0x2405002c  addiu       $a1, $zero, 0x2C
    ctx->pc = 0x1e23f8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 44));
    // 0x1e23fc: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E23FCu;
    SET_GPR_U32(ctx, 31, 0x1E2404u);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2404u; }
        if (ctx->pc != 0x1E2404u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2404u; }
        if (ctx->pc != 0x1E2404u) { return; }
    }
    ctx->pc = 0x1E2404u;
label_1e2404:
    // 0x1e2404: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1e2404u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1e2408: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1e2408u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e240c: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E240Cu;
    {
        const bool branch_taken_0x1e240c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e240c) {
            ctx->pc = 0x1E2428u;
            goto label_1e2428;
        }
    }
    ctx->pc = 0x1E2414u;
    // 0x1e2414: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e2414u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e2418: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e2418u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e241c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e241cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e2420: 0x1000007e  b           . + 4 + (0x7E << 2)
    ctx->pc = 0x1E2420u;
    {
        const bool branch_taken_0x1e2420 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e2420) {
            ctx->pc = 0x1E261Cu;
            goto label_1e261c;
        }
    }
    ctx->pc = 0x1E2428u;
label_1e2428:
    // 0x1e2428: 0x8fc4001c  lw          $a0, 0x1C($fp)
    ctx->pc = 0x1e2428u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e242c: 0x2405002c  addiu       $a1, $zero, 0x2C
    ctx->pc = 0x1e242cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 44));
    // 0x1e2430: 0xc07cc3c  jal         func_1F30F0
    ctx->pc = 0x1E2430u;
    SET_GPR_U32(ctx, 31, 0x1E2438u);
    ctx->pc = 0x1F30F0u;
    if (runtime->hasFunction(0x1F30F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F30F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2438u; }
        if (ctx->pc != 0x1E2438u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F30F0_0x1f30f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2438u; }
        if (ctx->pc != 0x1E2438u) { return; }
    }
    ctx->pc = 0x1E2438u;
label_1e2438:
    // 0x1e2438: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1e2438u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1e243c: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e243cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e2440: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1E2440u;
    {
        const bool branch_taken_0x1e2440 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e2440) {
            ctx->pc = 0x1E2470u;
            goto label_1e2470;
        }
    }
    ctx->pc = 0x1E2448u;
    // 0x1e2448: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e2448u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e244c: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1e244cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1e2450: 0x8fc5001c  lw          $a1, 0x1C($fp)
    ctx->pc = 0x1e2450u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e2454: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1E2454u;
    SET_GPR_U32(ctx, 31, 0x1E245Cu);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E245Cu; }
        if (ctx->pc != 0x1E245Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E245Cu; }
        if (ctx->pc != 0x1E245Cu) { return; }
    }
    ctx->pc = 0x1E245Cu;
label_1e245c:
    // 0x1e245c: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e245cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e2460: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e2460u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e2464: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e2464u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e2468: 0x1000006c  b           . + 4 + (0x6C << 2)
    ctx->pc = 0x1E2468u;
    {
        const bool branch_taken_0x1e2468 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e2468) {
            ctx->pc = 0x1E261Cu;
            goto label_1e261c;
        }
    }
    ctx->pc = 0x1E2470u;
label_1e2470:
    // 0x1e2470: 0x8fc40018  lw          $a0, 0x18($fp)
    ctx->pc = 0x1e2470u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e2474: 0x8fc50004  lw          $a1, 0x4($fp)
    ctx->pc = 0x1e2474u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e2478: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1E2478u;
    SET_GPR_U32(ctx, 31, 0x1E2480u);
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2480u; }
        if (ctx->pc != 0x1E2480u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2480u; }
        if (ctx->pc != 0x1E2480u) { return; }
    }
    ctx->pc = 0x1E2480u;
label_1e2480:
    // 0x1e2480: 0x8fc50018  lw          $a1, 0x18($fp)
    ctx->pc = 0x1e2480u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e2484: 0x97c2000c  lhu         $v0, 0xC($fp)
    ctx->pc = 0x1e2484u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e2488: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1e2488u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1e248c: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1e248cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1e2490: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1e2490u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1e2494: 0x97c2000c  lhu         $v0, 0xC($fp)
    ctx->pc = 0x1e2494u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e2498: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1e2498u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1e249c: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1e249cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1e24a0: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1e24a0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1e24a4: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1e24a4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e24a8: 0x97c3000c  lhu         $v1, 0xC($fp)
    ctx->pc = 0x1e24a8u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e24ac: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1e24acu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1e24b0: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e24b0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e24b4: 0x21203  sra         $v0, $v0, 8
    ctx->pc = 0x1e24b4u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 8));
    // 0x1e24b8: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1e24b8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e24bc: 0x97c3000c  lhu         $v1, 0xC($fp)
    ctx->pc = 0x1e24bcu;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e24c0: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1e24c0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1e24c4: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e24c4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e24c8: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1e24c8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1e24cc: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1e24ccu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e24d0: 0xaca20010  sw          $v0, 0x10($a1)
    ctx->pc = 0x1e24d0u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 16), GPR_U32(ctx, 2));
    // 0x1e24d4: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1e24d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e24d8: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E24D8u;
    {
        const bool branch_taken_0x1e24d8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e24d8) {
            ctx->pc = 0x1E2500u;
            goto label_1e2500;
        }
    }
    ctx->pc = 0x1E24E0u;
    // 0x1e24e0: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e24e0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e24e4: 0x24420014  addiu       $v0, $v0, 0x14
    ctx->pc = 0x1e24e4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 20));
    // 0x1e24e8: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1e24e8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e24ec: 0x8fc50008  lw          $a1, 0x8($fp)
    ctx->pc = 0x1e24ecu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e24f0: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1E24F0u;
    SET_GPR_U32(ctx, 31, 0x1E24F8u);
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E24F8u; }
        if (ctx->pc != 0x1E24F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E24F8u; }
        if (ctx->pc != 0x1E24F8u) { return; }
    }
    ctx->pc = 0x1E24F8u;
label_1e24f8:
    // 0x1e24f8: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1E24F8u;
    {
        const bool branch_taken_0x1e24f8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e24f8) {
            ctx->pc = 0x1E2508u;
            goto label_1e2508;
        }
    }
    ctx->pc = 0x1E2500u;
label_1e2500:
    // 0x1e2500: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e2500u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e2504: 0xa0400014  sb          $zero, 0x14($v0)
    ctx->pc = 0x1e2504u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 20), (uint8_t)GPR_U32(ctx, 0));
label_1e2508:
    // 0x1e2508: 0x8fc50018  lw          $a1, 0x18($fp)
    ctx->pc = 0x1e2508u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e250c: 0x97c2000e  lhu         $v0, 0xE($fp)
    ctx->pc = 0x1e250cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 14)));
    // 0x1e2510: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1e2510u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1e2514: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1e2514u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1e2518: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1e2518u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1e251c: 0x97c2000e  lhu         $v0, 0xE($fp)
    ctx->pc = 0x1e251cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 14)));
    // 0x1e2520: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1e2520u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1e2524: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1e2524u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1e2528: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1e2528u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1e252c: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1e252cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e2530: 0x97c3000e  lhu         $v1, 0xE($fp)
    ctx->pc = 0x1e2530u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 14)));
    // 0x1e2534: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1e2534u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1e2538: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e2538u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e253c: 0x21203  sra         $v0, $v0, 8
    ctx->pc = 0x1e253cu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 8));
    // 0x1e2540: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1e2540u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e2544: 0x97c3000e  lhu         $v1, 0xE($fp)
    ctx->pc = 0x1e2544u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 14)));
    // 0x1e2548: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1e2548u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1e254c: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e254cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e2550: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1e2550u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1e2554: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1e2554u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e2558: 0xaca20024  sw          $v0, 0x24($a1)
    ctx->pc = 0x1e2558u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 36), GPR_U32(ctx, 2));
    // 0x1e255c: 0x8fc50018  lw          $a1, 0x18($fp)
    ctx->pc = 0x1e255cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e2560: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e2560u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e2564: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1e2564u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1e2568: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1e2568u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1e256c: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e256cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e2570: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1e2570u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1e2574: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1e2574u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1e2578: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1e2578u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e257c: 0x8fc30010  lw          $v1, 0x10($fp)
    ctx->pc = 0x1e257cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e2580: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1e2580u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1e2584: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e2584u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e2588: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1e2588u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1e258c: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1e258cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e2590: 0x8fc30010  lw          $v1, 0x10($fp)
    ctx->pc = 0x1e2590u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e2594: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1e2594u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1e2598: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e2598u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e259c: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1e259cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1e25a0: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1e25a0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e25a4: 0xaca20028  sw          $v0, 0x28($a1)
    ctx->pc = 0x1e25a4u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 40), GPR_U32(ctx, 2));
    // 0x1e25a8: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e25a8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e25ac: 0x90420616  lbu         $v0, 0x616($v0)
    ctx->pc = 0x1e25acu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 1558)));
    // 0x1e25b0: 0x8fc40020  lw          $a0, 0x20($fp)
    ctx->pc = 0x1e25b0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e25b4: 0x8fc5001c  lw          $a1, 0x1C($fp)
    ctx->pc = 0x1e25b4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e25b8: 0x3406b000  ori         $a2, $zero, 0xB000
    ctx->pc = 0x1e25b8u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)45056);
    // 0x1e25bc: 0x2407002c  addiu       $a3, $zero, 0x2C
    ctx->pc = 0x1e25bcu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 44));
    // 0x1e25c0: 0x24080004  addiu       $t0, $zero, 0x4
    ctx->pc = 0x1e25c0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1e25c4: 0x40482d  daddu       $t1, $v0, $zero
    ctx->pc = 0x1e25c4u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e25c8: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E25C8u;
    SET_GPR_U32(ctx, 31, 0x1E25D0u);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E25D0u; }
        if (ctx->pc != 0x1E25D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E25D0u; }
        if (ctx->pc != 0x1E25D0u) { return; }
    }
    ctx->pc = 0x1E25D0u;
label_1e25d0:
    // 0x1e25d0: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E25D0u;
    {
        const bool branch_taken_0x1e25d0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e25d0) {
            ctx->pc = 0x1E25ECu;
            goto label_1e25ec;
        }
    }
    ctx->pc = 0x1E25D8u;
    // 0x1e25d8: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e25d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e25dc: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e25dcu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e25e0: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e25e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e25e4: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1E25E4u;
    {
        const bool branch_taken_0x1e25e4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e25e4) {
            ctx->pc = 0x1E261Cu;
            goto label_1e261c;
        }
    }
    ctx->pc = 0x1E25ECu;
label_1e25ec:
    // 0x1e25ec: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1e25ecu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e25f0: 0x2405001f  addiu       $a1, $zero, 0x1F
    ctx->pc = 0x1e25f0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 31));
    // 0x1e25f4: 0x8fc60014  lw          $a2, 0x14($fp)
    ctx->pc = 0x1e25f4u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e25f8: 0xc076ad5  jal         func_1DAB54
    ctx->pc = 0x1E25F8u;
    SET_GPR_U32(ctx, 31, 0x1E2600u);
    ctx->pc = 0x1DAB54u;
    if (runtime->hasFunction(0x1DAB54u)) {
        auto targetFn = runtime->lookupFunction(0x1DAB54u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2600u; }
        if (ctx->pc != 0x1E2600u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DAB54_0x1dab54(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2600u; }
        if (ctx->pc != 0x1E2600u) { return; }
    }
    ctx->pc = 0x1E2600u;
label_1e2600:
    // 0x1e2600: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1e2600u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e2604: 0x90640616  lbu         $a0, 0x616($v1)
    ctx->pc = 0x1e2604u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 1558)));
    // 0x1e2608: 0x24820001  addiu       $v0, $a0, 0x1
    ctx->pc = 0x1e2608u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1e260c: 0xa0620616  sb          $v0, 0x616($v1)
    ctx->pc = 0x1e260cu;
    WRITE8(ADD32(GPR_U32(ctx, 3), 1558), (uint8_t)GPR_U32(ctx, 2));
    // 0x1e2610: 0x308200ff  andi        $v0, $a0, 0xFF
    ctx->pc = 0x1e2610u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x1e2614: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1e2614u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1e2618: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1e2618u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
label_1e261c:
    // 0x1e261c: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e261cu;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e2620: 0xdfbe0030  ld          $fp, 0x30($sp)
    ctx->pc = 0x1e2620u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1e2624: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x1e2624u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x1e2628: 0x27bd0040  addiu       $sp, $sp, 0x40
    ctx->pc = 0x1e2628u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x1e262c: 0x3e00008  jr          $ra
    ctx->pc = 0x1E262Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E1B3Cu: goto label_1e1b3c;
            case 0x1E1B60u: goto label_1e1b60;
            case 0x1E1B84u: goto label_1e1b84;
            case 0x1E1BA8u: goto label_1e1ba8;
            case 0x1E1BC8u: goto label_1e1bc8;
            case 0x1E1BE4u: goto label_1e1be4;
            case 0x1E1BE8u: goto label_1e1be8;
            case 0x1E1C44u: goto label_1e1c44;
            case 0x1E1C58u: goto label_1e1c58;
            case 0x1E1C7Cu: goto label_1e1c7c;
            case 0x1E1CD8u: goto label_1e1cd8;
            case 0x1E1CECu: goto label_1e1cec;
            case 0x1E1D14u: goto label_1e1d14;
            case 0x1E1D7Cu: goto label_1e1d7c;
            case 0x1E1D90u: goto label_1e1d90;
            case 0x1E1DD0u: goto label_1e1dd0;
            case 0x1E1DE0u: goto label_1e1de0;
            case 0x1E1E04u: goto label_1e1e04;
            case 0x1E1E14u: goto label_1e1e14;
            case 0x1E1E38u: goto label_1e1e38;
            case 0x1E1E4Cu: goto label_1e1e4c;
            case 0x1E1E5Cu: goto label_1e1e5c;
            case 0x1E1E84u: goto label_1e1e84;
            case 0x1E1EA0u: goto label_1e1ea0;
            case 0x1E1EB4u: goto label_1e1eb4;
            case 0x1E1ED0u: goto label_1e1ed0;
            case 0x1E1F48u: goto label_1e1f48;
            case 0x1E1F5Cu: goto label_1e1f5c;
            case 0x1E1F9Cu: goto label_1e1f9c;
            case 0x1E1FACu: goto label_1e1fac;
            case 0x1E1FD0u: goto label_1e1fd0;
            case 0x1E1FE0u: goto label_1e1fe0;
            case 0x1E2004u: goto label_1e2004;
            case 0x1E2018u: goto label_1e2018;
            case 0x1E202Cu: goto label_1e202c;
            case 0x1E2064u: goto label_1e2064;
            case 0x1E206Cu: goto label_1e206c;
            case 0x1E2088u: goto label_1e2088;
            case 0x1E20A0u: goto label_1e20a0;
            case 0x1E20D4u: goto label_1e20d4;
            case 0x1E20F8u: goto label_1e20f8;
            case 0x1E210Cu: goto label_1e210c;
            case 0x1E2128u: goto label_1e2128;
            case 0x1E2190u: goto label_1e2190;
            case 0x1E21A4u: goto label_1e21a4;
            case 0x1E21E4u: goto label_1e21e4;
            case 0x1E21F4u: goto label_1e21f4;
            case 0x1E2218u: goto label_1e2218;
            case 0x1E2228u: goto label_1e2228;
            case 0x1E224Cu: goto label_1e224c;
            case 0x1E2260u: goto label_1e2260;
            case 0x1E22D4u: goto label_1e22d4;
            case 0x1E22F0u: goto label_1e22f0;
            case 0x1E2304u: goto label_1e2304;
            case 0x1E2320u: goto label_1e2320;
            case 0x1E23A0u: goto label_1e23a0;
            case 0x1E23B4u: goto label_1e23b4;
            case 0x1E23F4u: goto label_1e23f4;
            case 0x1E2404u: goto label_1e2404;
            case 0x1E2428u: goto label_1e2428;
            case 0x1E2438u: goto label_1e2438;
            case 0x1E245Cu: goto label_1e245c;
            case 0x1E2470u: goto label_1e2470;
            case 0x1E2480u: goto label_1e2480;
            case 0x1E24F8u: goto label_1e24f8;
            case 0x1E2500u: goto label_1e2500;
            case 0x1E2508u: goto label_1e2508;
            case 0x1E25D0u: goto label_1e25d0;
            case 0x1E25ECu: goto label_1e25ec;
            case 0x1E2600u: goto label_1e2600;
            case 0x1E261Cu: goto label_1e261c;
            case 0x1E2684u: goto label_1e2684;
            case 0x1E2698u: goto label_1e2698;
            case 0x1E26D8u: goto label_1e26d8;
            case 0x1E26E8u: goto label_1e26e8;
            case 0x1E270Cu: goto label_1e270c;
            case 0x1E271Cu: goto label_1e271c;
            case 0x1E2740u: goto label_1e2740;
            case 0x1E2754u: goto label_1e2754;
            case 0x1E27C8u: goto label_1e27c8;
            case 0x1E27E4u: goto label_1e27e4;
            case 0x1E27F8u: goto label_1e27f8;
            case 0x1E2814u: goto label_1e2814;
            case 0x1E287Cu: goto label_1e287c;
            case 0x1E2890u: goto label_1e2890;
            case 0x1E28D0u: goto label_1e28d0;
            case 0x1E28E0u: goto label_1e28e0;
            case 0x1E2904u: goto label_1e2904;
            case 0x1E2914u: goto label_1e2914;
            case 0x1E2938u: goto label_1e2938;
            case 0x1E294Cu: goto label_1e294c;
            case 0x1E29C0u: goto label_1e29c0;
            case 0x1E29DCu: goto label_1e29dc;
            case 0x1E29F0u: goto label_1e29f0;
            case 0x1E2A0Cu: goto label_1e2a0c;
            case 0x1E2A78u: goto label_1e2a78;
            case 0x1E2A8Cu: goto label_1e2a8c;
            case 0x1E2ACCu: goto label_1e2acc;
            case 0x1E2ADCu: goto label_1e2adc;
            case 0x1E2B00u: goto label_1e2b00;
            case 0x1E2B10u: goto label_1e2b10;
            case 0x1E2B34u: goto label_1e2b34;
            case 0x1E2B48u: goto label_1e2b48;
            case 0x1E2B54u: goto label_1e2b54;
            case 0x1E2B90u: goto label_1e2b90;
            case 0x1E2B98u: goto label_1e2b98;
            case 0x1E2BC0u: goto label_1e2bc0;
            case 0x1E2BE4u: goto label_1e2be4;
            case 0x1E2BF8u: goto label_1e2bf8;
            case 0x1E2C14u: goto label_1e2c14;
            case 0x1E2C84u: goto label_1e2c84;
            case 0x1E2C98u: goto label_1e2c98;
            case 0x1E2CD8u: goto label_1e2cd8;
            case 0x1E2CE8u: goto label_1e2ce8;
            case 0x1E2D0Cu: goto label_1e2d0c;
            case 0x1E2D1Cu: goto label_1e2d1c;
            case 0x1E2D40u: goto label_1e2d40;
            case 0x1E2D54u: goto label_1e2d54;
            case 0x1E2E10u: goto label_1e2e10;
            case 0x1E2E18u: goto label_1e2e18;
            case 0x1E2E20u: goto label_1e2e20;
            case 0x1E2E48u: goto label_1e2e48;
            case 0x1E2E64u: goto label_1e2e64;
            case 0x1E2E78u: goto label_1e2e78;
            case 0x1E2E94u: goto label_1e2e94;
            case 0x1E2EF8u: goto label_1e2ef8;
            case 0x1E2F0Cu: goto label_1e2f0c;
            case 0x1E2F4Cu: goto label_1e2f4c;
            case 0x1E2F5Cu: goto label_1e2f5c;
            case 0x1E2F80u: goto label_1e2f80;
            case 0x1E2FA8u: goto label_1e2fa8;
            case 0x1E2FC4u: goto label_1e2fc4;
            case 0x1E2FD8u: goto label_1e2fd8;
            case 0x1E2FF4u: goto label_1e2ff4;
            case 0x1E3058u: goto label_1e3058;
            case 0x1E306Cu: goto label_1e306c;
            case 0x1E30ACu: goto label_1e30ac;
            case 0x1E30BCu: goto label_1e30bc;
            case 0x1E30E0u: goto label_1e30e0;
            case 0x1E3108u: goto label_1e3108;
            case 0x1E3124u: goto label_1e3124;
            case 0x1E3138u: goto label_1e3138;
            case 0x1E3154u: goto label_1e3154;
            case 0x1E31CCu: goto label_1e31cc;
            case 0x1E31E0u: goto label_1e31e0;
            case 0x1E3220u: goto label_1e3220;
            case 0x1E3238u: goto label_1e3238;
            case 0x1E325Cu: goto label_1e325c;
            case 0x1E3278u: goto label_1e3278;
            case 0x1E329Cu: goto label_1e329c;
            case 0x1E32B0u: goto label_1e32b0;
            case 0x1E3318u: goto label_1e3318;
            case 0x1E3388u: goto label_1e3388;
            case 0x1E33C4u: goto label_1e33c4;
            case 0x1E33E0u: goto label_1e33e0;
            case 0x1E33F4u: goto label_1e33f4;
            case 0x1E3410u: goto label_1e3410;
            case 0x1E347Cu: goto label_1e347c;
            case 0x1E3490u: goto label_1e3490;
            case 0x1E34D0u: goto label_1e34d0;
            case 0x1E34E0u: goto label_1e34e0;
            case 0x1E3504u: goto label_1e3504;
            case 0x1E3514u: goto label_1e3514;
            case 0x1E3538u: goto label_1e3538;
            case 0x1E354Cu: goto label_1e354c;
            case 0x1E360Cu: goto label_1e360c;
            case 0x1E3628u: goto label_1e3628;
            case 0x1E363Cu: goto label_1e363c;
            case 0x1E3658u: goto label_1e3658;
            case 0x1E36C4u: goto label_1e36c4;
            case 0x1E36D8u: goto label_1e36d8;
            case 0x1E3718u: goto label_1e3718;
            case 0x1E3728u: goto label_1e3728;
            case 0x1E374Cu: goto label_1e374c;
            case 0x1E375Cu: goto label_1e375c;
            case 0x1E3780u: goto label_1e3780;
            case 0x1E3794u: goto label_1e3794;
            case 0x1E3854u: goto label_1e3854;
            case 0x1E3870u: goto label_1e3870;
            case 0x1E3884u: goto label_1e3884;
            case 0x1E38A0u: goto label_1e38a0;
            case 0x1E3908u: goto label_1e3908;
            case 0x1E391Cu: goto label_1e391c;
            case 0x1E395Cu: goto label_1e395c;
            case 0x1E396Cu: goto label_1e396c;
            case 0x1E3990u: goto label_1e3990;
            case 0x1E39A0u: goto label_1e39a0;
            case 0x1E39C4u: goto label_1e39c4;
            case 0x1E39D8u: goto label_1e39d8;
            case 0x1E3A44u: goto label_1e3a44;
            case 0x1E3A60u: goto label_1e3a60;
            case 0x1E3A74u: goto label_1e3a74;
            case 0x1E3A78u: goto label_1e3a78;
            case 0x1E3ADCu: goto label_1e3adc;
            case 0x1E3AF0u: goto label_1e3af0;
            case 0x1E3B30u: goto label_1e3b30;
            case 0x1E3B40u: goto label_1e3b40;
            case 0x1E3B64u: goto label_1e3b64;
            case 0x1E3B84u: goto label_1e3b84;
            case 0x1E3BA0u: goto label_1e3ba0;
            case 0x1E3BB4u: goto label_1e3bb4;
            case 0x1E3BB8u: goto label_1e3bb8;
            case 0x1E3C1Cu: goto label_1e3c1c;
            case 0x1E3C30u: goto label_1e3c30;
            case 0x1E3C70u: goto label_1e3c70;
            case 0x1E3C80u: goto label_1e3c80;
            case 0x1E3CA4u: goto label_1e3ca4;
            case 0x1E3CC4u: goto label_1e3cc4;
            case 0x1E3CE8u: goto label_1e3ce8;
            case 0x1E3CFCu: goto label_1e3cfc;
            case 0x1E3D00u: goto label_1e3d00;
            case 0x1E3D68u: goto label_1e3d68;
            case 0x1E3D7Cu: goto label_1e3d7c;
            case 0x1E3DBCu: goto label_1e3dbc;
            case 0x1E3DCCu: goto label_1e3dcc;
            case 0x1E3DF0u: goto label_1e3df0;
            case 0x1E3E00u: goto label_1e3e00;
            case 0x1E3E24u: goto label_1e3e24;
            case 0x1E3E38u: goto label_1e3e38;
            case 0x1E3EA4u: goto label_1e3ea4;
            case 0x1E3EC0u: goto label_1e3ec0;
            case 0x1E3ED4u: goto label_1e3ed4;
            case 0x1E3ED8u: goto label_1e3ed8;
            case 0x1E3F40u: goto label_1e3f40;
            case 0x1E3F54u: goto label_1e3f54;
            case 0x1E3F94u: goto label_1e3f94;
            case 0x1E3FA4u: goto label_1e3fa4;
            case 0x1E3FC8u: goto label_1e3fc8;
            case 0x1E3FD8u: goto label_1e3fd8;
            case 0x1E3FFCu: goto label_1e3ffc;
            case 0x1E4010u: goto label_1e4010;
            case 0x1E407Cu: goto label_1e407c;
            case 0x1E4098u: goto label_1e4098;
            case 0x1E40ACu: goto label_1e40ac;
            case 0x1E40B0u: goto label_1e40b0;
            case 0x1E4118u: goto label_1e4118;
            case 0x1E412Cu: goto label_1e412c;
            case 0x1E416Cu: goto label_1e416c;
            case 0x1E417Cu: goto label_1e417c;
            case 0x1E41A0u: goto label_1e41a0;
            case 0x1E41B0u: goto label_1e41b0;
            case 0x1E41D4u: goto label_1e41d4;
            case 0x1E41E8u: goto label_1e41e8;
            case 0x1E4254u: goto label_1e4254;
            case 0x1E4270u: goto label_1e4270;
            case 0x1E4284u: goto label_1e4284;
            case 0x1E4288u: goto label_1e4288;
            case 0x1E42F0u: goto label_1e42f0;
            case 0x1E4304u: goto label_1e4304;
            case 0x1E4344u: goto label_1e4344;
            case 0x1E4358u: goto label_1e4358;
            case 0x1E437Cu: goto label_1e437c;
            case 0x1E4394u: goto label_1e4394;
            case 0x1E43B8u: goto label_1e43b8;
            case 0x1E43CCu: goto label_1e43cc;
            case 0x1E43E4u: goto label_1e43e4;
            case 0x1E4414u: goto label_1e4414;
            case 0x1E4430u: goto label_1e4430;
            case 0x1E4444u: goto label_1e4444;
            case 0x1E4460u: goto label_1e4460;
            case 0x1E44C8u: goto label_1e44c8;
            case 0x1E44DCu: goto label_1e44dc;
            case 0x1E451Cu: goto label_1e451c;
            case 0x1E452Cu: goto label_1e452c;
            case 0x1E4550u: goto label_1e4550;
            case 0x1E4560u: goto label_1e4560;
            case 0x1E4584u: goto label_1e4584;
            case 0x1E4598u: goto label_1e4598;
            case 0x1E460Cu: goto label_1e460c;
            case 0x1E4628u: goto label_1e4628;
            case 0x1E463Cu: goto label_1e463c;
            case 0x1E4658u: goto label_1e4658;
            case 0x1E46C8u: goto label_1e46c8;
            case 0x1E46DCu: goto label_1e46dc;
            case 0x1E471Cu: goto label_1e471c;
            case 0x1E472Cu: goto label_1e472c;
            case 0x1E4750u: goto label_1e4750;
            case 0x1E4764u: goto label_1e4764;
            case 0x1E4788u: goto label_1e4788;
            case 0x1E479Cu: goto label_1e479c;
            case 0x1E47B0u: goto label_1e47b0;
            case 0x1E47E0u: goto label_1e47e0;
            case 0x1E47FCu: goto label_1e47fc;
            case 0x1E4800u: goto label_1e4800;
            case 0x1E48A0u: goto label_1e48a0;
            case 0x1E48B4u: goto label_1e48b4;
            case 0x1E48F4u: goto label_1e48f4;
            case 0x1E4918u: goto label_1e4918;
            case 0x1E493Cu: goto label_1e493c;
            case 0x1E4974u: goto label_1e4974;
            case 0x1E4998u: goto label_1e4998;
            case 0x1E49ACu: goto label_1e49ac;
            case 0x1E4A08u: goto label_1e4a08;
            case 0x1E4A24u: goto label_1e4a24;
            case 0x1E4AACu: goto label_1e4aac;
            case 0x1E4AC0u: goto label_1e4ac0;
            case 0x1E4B00u: goto label_1e4b00;
            case 0x1E4B1Cu: goto label_1e4b1c;
            case 0x1E4B20u: goto label_1e4b20;
            case 0x1E4B94u: goto label_1e4b94;
            case 0x1E4BA8u: goto label_1e4ba8;
            case 0x1E4BE8u: goto label_1e4be8;
            case 0x1E4C10u: goto label_1e4c10;
            case 0x1E4C34u: goto label_1e4c34;
            case 0x1E4C64u: goto label_1e4c64;
            case 0x1E4C88u: goto label_1e4c88;
            case 0x1E4C9Cu: goto label_1e4c9c;
            case 0x1E4D08u: goto label_1e4d08;
            case 0x1E4D28u: goto label_1e4d28;
            case 0x1E4DE4u: goto label_1e4de4;
            case 0x1E4DF8u: goto label_1e4df8;
            case 0x1E4E3Cu: goto label_1e4e3c;
            case 0x1E4E58u: goto label_1e4e58;
            case 0x1E4E5Cu: goto label_1e4e5c;
            case 0x1E4EC4u: goto label_1e4ec4;
            case 0x1E4ED8u: goto label_1e4ed8;
            case 0x1E4F18u: goto label_1e4f18;
            case 0x1E4F28u: goto label_1e4f28;
            case 0x1E4F4Cu: goto label_1e4f4c;
            case 0x1E4F60u: goto label_1e4f60;
            case 0x1E4F84u: goto label_1e4f84;
            case 0x1E4F98u: goto label_1e4f98;
            case 0x1E4FACu: goto label_1e4fac;
            case 0x1E4FD0u: goto label_1e4fd0;
            case 0x1E4FECu: goto label_1e4fec;
            case 0x1E4FF0u: goto label_1e4ff0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E2634u;
    // 0x1e2634: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1e2634u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1e2638: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1e2638u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1e263c: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1e263cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1e2640: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e2640u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e2644: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e2644u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e2648: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e2648u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e264c: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e264cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e2650: 0xafc00018  sw          $zero, 0x18($fp)
    ctx->pc = 0x1e2650u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 0));
    // 0x1e2654: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e2654u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e2658: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e2658u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e265c: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E265Cu;
    {
        const bool branch_taken_0x1e265c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e265c) {
            ctx->pc = 0x1E2684u;
            goto label_1e2684;
        }
    }
    ctx->pc = 0x1E2664u;
    // 0x1e2664: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e2664u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e2668: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e2668u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e266c: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e266cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e2670: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e2670u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e2674: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e2674u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e2678: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e2678u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e267c: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E267Cu;
    {
        const bool branch_taken_0x1e267c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e267c) {
            ctx->pc = 0x1E2698u;
            goto label_1e2698;
        }
    }
    ctx->pc = 0x1E2684u;
label_1e2684:
    // 0x1e2684: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e2684u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e2688: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e2688u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e268c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e268cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e2690: 0x10000060  b           . + 4 + (0x60 << 2)
    ctx->pc = 0x1E2690u;
    {
        const bool branch_taken_0x1e2690 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e2690) {
            ctx->pc = 0x1E2814u;
            goto label_1e2814;
        }
    }
    ctx->pc = 0x1E2698u;
label_1e2698:
    // 0x1e2698: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e2698u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e269c: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e269cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e26a0: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e26a0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e26a4: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e26a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e26a8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e26a8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e26ac: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e26acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e26b0: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1e26b0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1e26b4: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e26b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e26b8: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e26b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e26bc: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E26BCu;
    {
        const bool branch_taken_0x1e26bc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e26bc) {
            ctx->pc = 0x1E26D8u;
            goto label_1e26d8;
        }
    }
    ctx->pc = 0x1E26C4u;
    // 0x1e26c4: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e26c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e26c8: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e26c8u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e26cc: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e26ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e26d0: 0x10000050  b           . + 4 + (0x50 << 2)
    ctx->pc = 0x1E26D0u;
    {
        const bool branch_taken_0x1e26d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e26d0) {
            ctx->pc = 0x1E2814u;
            goto label_1e2814;
        }
    }
    ctx->pc = 0x1E26D8u;
label_1e26d8:
    // 0x1e26d8: 0x8fc40018  lw          $a0, 0x18($fp)
    ctx->pc = 0x1e26d8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e26dc: 0x24050004  addiu       $a1, $zero, 0x4
    ctx->pc = 0x1e26dcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1e26e0: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E26E0u;
    SET_GPR_U32(ctx, 31, 0x1E26E8u);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E26E8u; }
        if (ctx->pc != 0x1E26E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E26E8u; }
        if (ctx->pc != 0x1E26E8u) { return; }
    }
    ctx->pc = 0x1E26E8u;
label_1e26e8:
    // 0x1e26e8: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1e26e8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1e26ec: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e26ecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e26f0: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E26F0u;
    {
        const bool branch_taken_0x1e26f0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e26f0) {
            ctx->pc = 0x1E270Cu;
            goto label_1e270c;
        }
    }
    ctx->pc = 0x1E26F8u;
    // 0x1e26f8: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e26f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e26fc: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e26fcu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e2700: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e2700u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e2704: 0x10000043  b           . + 4 + (0x43 << 2)
    ctx->pc = 0x1E2704u;
    {
        const bool branch_taken_0x1e2704 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e2704) {
            ctx->pc = 0x1E2814u;
            goto label_1e2814;
        }
    }
    ctx->pc = 0x1E270Cu;
label_1e270c:
    // 0x1e270c: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1e270cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e2710: 0x24050004  addiu       $a1, $zero, 0x4
    ctx->pc = 0x1e2710u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1e2714: 0xc07cc3c  jal         func_1F30F0
    ctx->pc = 0x1E2714u;
    SET_GPR_U32(ctx, 31, 0x1E271Cu);
    ctx->pc = 0x1F30F0u;
    if (runtime->hasFunction(0x1F30F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F30F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E271Cu; }
        if (ctx->pc != 0x1E271Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F30F0_0x1f30f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E271Cu; }
        if (ctx->pc != 0x1E271Cu) { return; }
    }
    ctx->pc = 0x1E271Cu;
label_1e271c:
    // 0x1e271c: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1e271cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1e2720: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e2720u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e2724: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1E2724u;
    {
        const bool branch_taken_0x1e2724 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e2724) {
            ctx->pc = 0x1E2754u;
            goto label_1e2754;
        }
    }
    ctx->pc = 0x1E272Cu;
    // 0x1e272c: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e272cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e2730: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1e2730u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1e2734: 0x8fc5000c  lw          $a1, 0xC($fp)
    ctx->pc = 0x1e2734u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e2738: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1E2738u;
    SET_GPR_U32(ctx, 31, 0x1E2740u);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2740u; }
        if (ctx->pc != 0x1E2740u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2740u; }
        if (ctx->pc != 0x1E2740u) { return; }
    }
    ctx->pc = 0x1E2740u;
label_1e2740:
    // 0x1e2740: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e2740u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e2744: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e2744u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e2748: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e2748u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e274c: 0x10000031  b           . + 4 + (0x31 << 2)
    ctx->pc = 0x1E274Cu;
    {
        const bool branch_taken_0x1e274c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e274c) {
            ctx->pc = 0x1E2814u;
            goto label_1e2814;
        }
    }
    ctx->pc = 0x1E2754u;
label_1e2754:
    // 0x1e2754: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e2754u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e2758: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e2758u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e275c: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1e275cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1e2760: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1e2760u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1e2764: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e2764u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e2768: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1e2768u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1e276c: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1e276cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1e2770: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1e2770u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e2774: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1e2774u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e2778: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1e2778u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1e277c: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e277cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e2780: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1e2780u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1e2784: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1e2784u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e2788: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1e2788u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e278c: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1e278cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1e2790: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e2790u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e2794: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1e2794u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1e2798: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1e2798u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e279c: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x1e279cu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x1e27a0: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e27a0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e27a4: 0x90420617  lbu         $v0, 0x617($v0)
    ctx->pc = 0x1e27a4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 1559)));
    // 0x1e27a8: 0x8fc40018  lw          $a0, 0x18($fp)
    ctx->pc = 0x1e27a8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e27ac: 0x8fc5000c  lw          $a1, 0xC($fp)
    ctx->pc = 0x1e27acu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e27b0: 0x3406a000  ori         $a2, $zero, 0xA000
    ctx->pc = 0x1e27b0u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)40960);
    // 0x1e27b4: 0x24070004  addiu       $a3, $zero, 0x4
    ctx->pc = 0x1e27b4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1e27b8: 0x24080005  addiu       $t0, $zero, 0x5
    ctx->pc = 0x1e27b8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1e27bc: 0x40482d  daddu       $t1, $v0, $zero
    ctx->pc = 0x1e27bcu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e27c0: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E27C0u;
    SET_GPR_U32(ctx, 31, 0x1E27C8u);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E27C8u; }
        if (ctx->pc != 0x1E27C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E27C8u; }
        if (ctx->pc != 0x1E27C8u) { return; }
    }
    ctx->pc = 0x1E27C8u;
label_1e27c8:
    // 0x1e27c8: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E27C8u;
    {
        const bool branch_taken_0x1e27c8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e27c8) {
            ctx->pc = 0x1E27E4u;
            goto label_1e27e4;
        }
    }
    ctx->pc = 0x1E27D0u;
    // 0x1e27d0: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e27d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e27d4: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e27d4u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e27d8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e27d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e27dc: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1E27DCu;
    {
        const bool branch_taken_0x1e27dc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e27dc) {
            ctx->pc = 0x1E2814u;
            goto label_1e2814;
        }
    }
    ctx->pc = 0x1E27E4u;
label_1e27e4:
    // 0x1e27e4: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1e27e4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e27e8: 0x24050020  addiu       $a1, $zero, 0x20
    ctx->pc = 0x1e27e8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x1e27ec: 0x8fc60008  lw          $a2, 0x8($fp)
    ctx->pc = 0x1e27ecu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e27f0: 0xc076ad5  jal         func_1DAB54
    ctx->pc = 0x1E27F0u;
    SET_GPR_U32(ctx, 31, 0x1E27F8u);
    ctx->pc = 0x1DAB54u;
    if (runtime->hasFunction(0x1DAB54u)) {
        auto targetFn = runtime->lookupFunction(0x1DAB54u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E27F8u; }
        if (ctx->pc != 0x1E27F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DAB54_0x1dab54(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E27F8u; }
        if (ctx->pc != 0x1E27F8u) { return; }
    }
    ctx->pc = 0x1E27F8u;
label_1e27f8:
    // 0x1e27f8: 0x8fc30018  lw          $v1, 0x18($fp)
    ctx->pc = 0x1e27f8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e27fc: 0x90640617  lbu         $a0, 0x617($v1)
    ctx->pc = 0x1e27fcu;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 1559)));
    // 0x1e2800: 0x24820001  addiu       $v0, $a0, 0x1
    ctx->pc = 0x1e2800u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1e2804: 0xa0620617  sb          $v0, 0x617($v1)
    ctx->pc = 0x1e2804u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 1559), (uint8_t)GPR_U32(ctx, 2));
    // 0x1e2808: 0x308200ff  andi        $v0, $a0, 0xFF
    ctx->pc = 0x1e2808u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x1e280c: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1e280cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1e2810: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e2810u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
label_1e2814:
    // 0x1e2814: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e2814u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e2818: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1e2818u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1e281c: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1e281cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1e2820: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1e2820u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1e2824: 0x3e00008  jr          $ra
    ctx->pc = 0x1E2824u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E1B3Cu: goto label_1e1b3c;
            case 0x1E1B60u: goto label_1e1b60;
            case 0x1E1B84u: goto label_1e1b84;
            case 0x1E1BA8u: goto label_1e1ba8;
            case 0x1E1BC8u: goto label_1e1bc8;
            case 0x1E1BE4u: goto label_1e1be4;
            case 0x1E1BE8u: goto label_1e1be8;
            case 0x1E1C44u: goto label_1e1c44;
            case 0x1E1C58u: goto label_1e1c58;
            case 0x1E1C7Cu: goto label_1e1c7c;
            case 0x1E1CD8u: goto label_1e1cd8;
            case 0x1E1CECu: goto label_1e1cec;
            case 0x1E1D14u: goto label_1e1d14;
            case 0x1E1D7Cu: goto label_1e1d7c;
            case 0x1E1D90u: goto label_1e1d90;
            case 0x1E1DD0u: goto label_1e1dd0;
            case 0x1E1DE0u: goto label_1e1de0;
            case 0x1E1E04u: goto label_1e1e04;
            case 0x1E1E14u: goto label_1e1e14;
            case 0x1E1E38u: goto label_1e1e38;
            case 0x1E1E4Cu: goto label_1e1e4c;
            case 0x1E1E5Cu: goto label_1e1e5c;
            case 0x1E1E84u: goto label_1e1e84;
            case 0x1E1EA0u: goto label_1e1ea0;
            case 0x1E1EB4u: goto label_1e1eb4;
            case 0x1E1ED0u: goto label_1e1ed0;
            case 0x1E1F48u: goto label_1e1f48;
            case 0x1E1F5Cu: goto label_1e1f5c;
            case 0x1E1F9Cu: goto label_1e1f9c;
            case 0x1E1FACu: goto label_1e1fac;
            case 0x1E1FD0u: goto label_1e1fd0;
            case 0x1E1FE0u: goto label_1e1fe0;
            case 0x1E2004u: goto label_1e2004;
            case 0x1E2018u: goto label_1e2018;
            case 0x1E202Cu: goto label_1e202c;
            case 0x1E2064u: goto label_1e2064;
            case 0x1E206Cu: goto label_1e206c;
            case 0x1E2088u: goto label_1e2088;
            case 0x1E20A0u: goto label_1e20a0;
            case 0x1E20D4u: goto label_1e20d4;
            case 0x1E20F8u: goto label_1e20f8;
            case 0x1E210Cu: goto label_1e210c;
            case 0x1E2128u: goto label_1e2128;
            case 0x1E2190u: goto label_1e2190;
            case 0x1E21A4u: goto label_1e21a4;
            case 0x1E21E4u: goto label_1e21e4;
            case 0x1E21F4u: goto label_1e21f4;
            case 0x1E2218u: goto label_1e2218;
            case 0x1E2228u: goto label_1e2228;
            case 0x1E224Cu: goto label_1e224c;
            case 0x1E2260u: goto label_1e2260;
            case 0x1E22D4u: goto label_1e22d4;
            case 0x1E22F0u: goto label_1e22f0;
            case 0x1E2304u: goto label_1e2304;
            case 0x1E2320u: goto label_1e2320;
            case 0x1E23A0u: goto label_1e23a0;
            case 0x1E23B4u: goto label_1e23b4;
            case 0x1E23F4u: goto label_1e23f4;
            case 0x1E2404u: goto label_1e2404;
            case 0x1E2428u: goto label_1e2428;
            case 0x1E2438u: goto label_1e2438;
            case 0x1E245Cu: goto label_1e245c;
            case 0x1E2470u: goto label_1e2470;
            case 0x1E2480u: goto label_1e2480;
            case 0x1E24F8u: goto label_1e24f8;
            case 0x1E2500u: goto label_1e2500;
            case 0x1E2508u: goto label_1e2508;
            case 0x1E25D0u: goto label_1e25d0;
            case 0x1E25ECu: goto label_1e25ec;
            case 0x1E2600u: goto label_1e2600;
            case 0x1E261Cu: goto label_1e261c;
            case 0x1E2684u: goto label_1e2684;
            case 0x1E2698u: goto label_1e2698;
            case 0x1E26D8u: goto label_1e26d8;
            case 0x1E26E8u: goto label_1e26e8;
            case 0x1E270Cu: goto label_1e270c;
            case 0x1E271Cu: goto label_1e271c;
            case 0x1E2740u: goto label_1e2740;
            case 0x1E2754u: goto label_1e2754;
            case 0x1E27C8u: goto label_1e27c8;
            case 0x1E27E4u: goto label_1e27e4;
            case 0x1E27F8u: goto label_1e27f8;
            case 0x1E2814u: goto label_1e2814;
            case 0x1E287Cu: goto label_1e287c;
            case 0x1E2890u: goto label_1e2890;
            case 0x1E28D0u: goto label_1e28d0;
            case 0x1E28E0u: goto label_1e28e0;
            case 0x1E2904u: goto label_1e2904;
            case 0x1E2914u: goto label_1e2914;
            case 0x1E2938u: goto label_1e2938;
            case 0x1E294Cu: goto label_1e294c;
            case 0x1E29C0u: goto label_1e29c0;
            case 0x1E29DCu: goto label_1e29dc;
            case 0x1E29F0u: goto label_1e29f0;
            case 0x1E2A0Cu: goto label_1e2a0c;
            case 0x1E2A78u: goto label_1e2a78;
            case 0x1E2A8Cu: goto label_1e2a8c;
            case 0x1E2ACCu: goto label_1e2acc;
            case 0x1E2ADCu: goto label_1e2adc;
            case 0x1E2B00u: goto label_1e2b00;
            case 0x1E2B10u: goto label_1e2b10;
            case 0x1E2B34u: goto label_1e2b34;
            case 0x1E2B48u: goto label_1e2b48;
            case 0x1E2B54u: goto label_1e2b54;
            case 0x1E2B90u: goto label_1e2b90;
            case 0x1E2B98u: goto label_1e2b98;
            case 0x1E2BC0u: goto label_1e2bc0;
            case 0x1E2BE4u: goto label_1e2be4;
            case 0x1E2BF8u: goto label_1e2bf8;
            case 0x1E2C14u: goto label_1e2c14;
            case 0x1E2C84u: goto label_1e2c84;
            case 0x1E2C98u: goto label_1e2c98;
            case 0x1E2CD8u: goto label_1e2cd8;
            case 0x1E2CE8u: goto label_1e2ce8;
            case 0x1E2D0Cu: goto label_1e2d0c;
            case 0x1E2D1Cu: goto label_1e2d1c;
            case 0x1E2D40u: goto label_1e2d40;
            case 0x1E2D54u: goto label_1e2d54;
            case 0x1E2E10u: goto label_1e2e10;
            case 0x1E2E18u: goto label_1e2e18;
            case 0x1E2E20u: goto label_1e2e20;
            case 0x1E2E48u: goto label_1e2e48;
            case 0x1E2E64u: goto label_1e2e64;
            case 0x1E2E78u: goto label_1e2e78;
            case 0x1E2E94u: goto label_1e2e94;
            case 0x1E2EF8u: goto label_1e2ef8;
            case 0x1E2F0Cu: goto label_1e2f0c;
            case 0x1E2F4Cu: goto label_1e2f4c;
            case 0x1E2F5Cu: goto label_1e2f5c;
            case 0x1E2F80u: goto label_1e2f80;
            case 0x1E2FA8u: goto label_1e2fa8;
            case 0x1E2FC4u: goto label_1e2fc4;
            case 0x1E2FD8u: goto label_1e2fd8;
            case 0x1E2FF4u: goto label_1e2ff4;
            case 0x1E3058u: goto label_1e3058;
            case 0x1E306Cu: goto label_1e306c;
            case 0x1E30ACu: goto label_1e30ac;
            case 0x1E30BCu: goto label_1e30bc;
            case 0x1E30E0u: goto label_1e30e0;
            case 0x1E3108u: goto label_1e3108;
            case 0x1E3124u: goto label_1e3124;
            case 0x1E3138u: goto label_1e3138;
            case 0x1E3154u: goto label_1e3154;
            case 0x1E31CCu: goto label_1e31cc;
            case 0x1E31E0u: goto label_1e31e0;
            case 0x1E3220u: goto label_1e3220;
            case 0x1E3238u: goto label_1e3238;
            case 0x1E325Cu: goto label_1e325c;
            case 0x1E3278u: goto label_1e3278;
            case 0x1E329Cu: goto label_1e329c;
            case 0x1E32B0u: goto label_1e32b0;
            case 0x1E3318u: goto label_1e3318;
            case 0x1E3388u: goto label_1e3388;
            case 0x1E33C4u: goto label_1e33c4;
            case 0x1E33E0u: goto label_1e33e0;
            case 0x1E33F4u: goto label_1e33f4;
            case 0x1E3410u: goto label_1e3410;
            case 0x1E347Cu: goto label_1e347c;
            case 0x1E3490u: goto label_1e3490;
            case 0x1E34D0u: goto label_1e34d0;
            case 0x1E34E0u: goto label_1e34e0;
            case 0x1E3504u: goto label_1e3504;
            case 0x1E3514u: goto label_1e3514;
            case 0x1E3538u: goto label_1e3538;
            case 0x1E354Cu: goto label_1e354c;
            case 0x1E360Cu: goto label_1e360c;
            case 0x1E3628u: goto label_1e3628;
            case 0x1E363Cu: goto label_1e363c;
            case 0x1E3658u: goto label_1e3658;
            case 0x1E36C4u: goto label_1e36c4;
            case 0x1E36D8u: goto label_1e36d8;
            case 0x1E3718u: goto label_1e3718;
            case 0x1E3728u: goto label_1e3728;
            case 0x1E374Cu: goto label_1e374c;
            case 0x1E375Cu: goto label_1e375c;
            case 0x1E3780u: goto label_1e3780;
            case 0x1E3794u: goto label_1e3794;
            case 0x1E3854u: goto label_1e3854;
            case 0x1E3870u: goto label_1e3870;
            case 0x1E3884u: goto label_1e3884;
            case 0x1E38A0u: goto label_1e38a0;
            case 0x1E3908u: goto label_1e3908;
            case 0x1E391Cu: goto label_1e391c;
            case 0x1E395Cu: goto label_1e395c;
            case 0x1E396Cu: goto label_1e396c;
            case 0x1E3990u: goto label_1e3990;
            case 0x1E39A0u: goto label_1e39a0;
            case 0x1E39C4u: goto label_1e39c4;
            case 0x1E39D8u: goto label_1e39d8;
            case 0x1E3A44u: goto label_1e3a44;
            case 0x1E3A60u: goto label_1e3a60;
            case 0x1E3A74u: goto label_1e3a74;
            case 0x1E3A78u: goto label_1e3a78;
            case 0x1E3ADCu: goto label_1e3adc;
            case 0x1E3AF0u: goto label_1e3af0;
            case 0x1E3B30u: goto label_1e3b30;
            case 0x1E3B40u: goto label_1e3b40;
            case 0x1E3B64u: goto label_1e3b64;
            case 0x1E3B84u: goto label_1e3b84;
            case 0x1E3BA0u: goto label_1e3ba0;
            case 0x1E3BB4u: goto label_1e3bb4;
            case 0x1E3BB8u: goto label_1e3bb8;
            case 0x1E3C1Cu: goto label_1e3c1c;
            case 0x1E3C30u: goto label_1e3c30;
            case 0x1E3C70u: goto label_1e3c70;
            case 0x1E3C80u: goto label_1e3c80;
            case 0x1E3CA4u: goto label_1e3ca4;
            case 0x1E3CC4u: goto label_1e3cc4;
            case 0x1E3CE8u: goto label_1e3ce8;
            case 0x1E3CFCu: goto label_1e3cfc;
            case 0x1E3D00u: goto label_1e3d00;
            case 0x1E3D68u: goto label_1e3d68;
            case 0x1E3D7Cu: goto label_1e3d7c;
            case 0x1E3DBCu: goto label_1e3dbc;
            case 0x1E3DCCu: goto label_1e3dcc;
            case 0x1E3DF0u: goto label_1e3df0;
            case 0x1E3E00u: goto label_1e3e00;
            case 0x1E3E24u: goto label_1e3e24;
            case 0x1E3E38u: goto label_1e3e38;
            case 0x1E3EA4u: goto label_1e3ea4;
            case 0x1E3EC0u: goto label_1e3ec0;
            case 0x1E3ED4u: goto label_1e3ed4;
            case 0x1E3ED8u: goto label_1e3ed8;
            case 0x1E3F40u: goto label_1e3f40;
            case 0x1E3F54u: goto label_1e3f54;
            case 0x1E3F94u: goto label_1e3f94;
            case 0x1E3FA4u: goto label_1e3fa4;
            case 0x1E3FC8u: goto label_1e3fc8;
            case 0x1E3FD8u: goto label_1e3fd8;
            case 0x1E3FFCu: goto label_1e3ffc;
            case 0x1E4010u: goto label_1e4010;
            case 0x1E407Cu: goto label_1e407c;
            case 0x1E4098u: goto label_1e4098;
            case 0x1E40ACu: goto label_1e40ac;
            case 0x1E40B0u: goto label_1e40b0;
            case 0x1E4118u: goto label_1e4118;
            case 0x1E412Cu: goto label_1e412c;
            case 0x1E416Cu: goto label_1e416c;
            case 0x1E417Cu: goto label_1e417c;
            case 0x1E41A0u: goto label_1e41a0;
            case 0x1E41B0u: goto label_1e41b0;
            case 0x1E41D4u: goto label_1e41d4;
            case 0x1E41E8u: goto label_1e41e8;
            case 0x1E4254u: goto label_1e4254;
            case 0x1E4270u: goto label_1e4270;
            case 0x1E4284u: goto label_1e4284;
            case 0x1E4288u: goto label_1e4288;
            case 0x1E42F0u: goto label_1e42f0;
            case 0x1E4304u: goto label_1e4304;
            case 0x1E4344u: goto label_1e4344;
            case 0x1E4358u: goto label_1e4358;
            case 0x1E437Cu: goto label_1e437c;
            case 0x1E4394u: goto label_1e4394;
            case 0x1E43B8u: goto label_1e43b8;
            case 0x1E43CCu: goto label_1e43cc;
            case 0x1E43E4u: goto label_1e43e4;
            case 0x1E4414u: goto label_1e4414;
            case 0x1E4430u: goto label_1e4430;
            case 0x1E4444u: goto label_1e4444;
            case 0x1E4460u: goto label_1e4460;
            case 0x1E44C8u: goto label_1e44c8;
            case 0x1E44DCu: goto label_1e44dc;
            case 0x1E451Cu: goto label_1e451c;
            case 0x1E452Cu: goto label_1e452c;
            case 0x1E4550u: goto label_1e4550;
            case 0x1E4560u: goto label_1e4560;
            case 0x1E4584u: goto label_1e4584;
            case 0x1E4598u: goto label_1e4598;
            case 0x1E460Cu: goto label_1e460c;
            case 0x1E4628u: goto label_1e4628;
            case 0x1E463Cu: goto label_1e463c;
            case 0x1E4658u: goto label_1e4658;
            case 0x1E46C8u: goto label_1e46c8;
            case 0x1E46DCu: goto label_1e46dc;
            case 0x1E471Cu: goto label_1e471c;
            case 0x1E472Cu: goto label_1e472c;
            case 0x1E4750u: goto label_1e4750;
            case 0x1E4764u: goto label_1e4764;
            case 0x1E4788u: goto label_1e4788;
            case 0x1E479Cu: goto label_1e479c;
            case 0x1E47B0u: goto label_1e47b0;
            case 0x1E47E0u: goto label_1e47e0;
            case 0x1E47FCu: goto label_1e47fc;
            case 0x1E4800u: goto label_1e4800;
            case 0x1E48A0u: goto label_1e48a0;
            case 0x1E48B4u: goto label_1e48b4;
            case 0x1E48F4u: goto label_1e48f4;
            case 0x1E4918u: goto label_1e4918;
            case 0x1E493Cu: goto label_1e493c;
            case 0x1E4974u: goto label_1e4974;
            case 0x1E4998u: goto label_1e4998;
            case 0x1E49ACu: goto label_1e49ac;
            case 0x1E4A08u: goto label_1e4a08;
            case 0x1E4A24u: goto label_1e4a24;
            case 0x1E4AACu: goto label_1e4aac;
            case 0x1E4AC0u: goto label_1e4ac0;
            case 0x1E4B00u: goto label_1e4b00;
            case 0x1E4B1Cu: goto label_1e4b1c;
            case 0x1E4B20u: goto label_1e4b20;
            case 0x1E4B94u: goto label_1e4b94;
            case 0x1E4BA8u: goto label_1e4ba8;
            case 0x1E4BE8u: goto label_1e4be8;
            case 0x1E4C10u: goto label_1e4c10;
            case 0x1E4C34u: goto label_1e4c34;
            case 0x1E4C64u: goto label_1e4c64;
            case 0x1E4C88u: goto label_1e4c88;
            case 0x1E4C9Cu: goto label_1e4c9c;
            case 0x1E4D08u: goto label_1e4d08;
            case 0x1E4D28u: goto label_1e4d28;
            case 0x1E4DE4u: goto label_1e4de4;
            case 0x1E4DF8u: goto label_1e4df8;
            case 0x1E4E3Cu: goto label_1e4e3c;
            case 0x1E4E58u: goto label_1e4e58;
            case 0x1E4E5Cu: goto label_1e4e5c;
            case 0x1E4EC4u: goto label_1e4ec4;
            case 0x1E4ED8u: goto label_1e4ed8;
            case 0x1E4F18u: goto label_1e4f18;
            case 0x1E4F28u: goto label_1e4f28;
            case 0x1E4F4Cu: goto label_1e4f4c;
            case 0x1E4F60u: goto label_1e4f60;
            case 0x1E4F84u: goto label_1e4f84;
            case 0x1E4F98u: goto label_1e4f98;
            case 0x1E4FACu: goto label_1e4fac;
            case 0x1E4FD0u: goto label_1e4fd0;
            case 0x1E4FECu: goto label_1e4fec;
            case 0x1E4FF0u: goto label_1e4ff0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E282Cu;
    // 0x1e282c: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1e282cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1e2830: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1e2830u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1e2834: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1e2834u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1e2838: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e2838u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e283c: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e283cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e2840: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e2840u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e2844: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e2844u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e2848: 0xafc00014  sw          $zero, 0x14($fp)
    ctx->pc = 0x1e2848u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 0));
    // 0x1e284c: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e284cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e2850: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e2850u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e2854: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E2854u;
    {
        const bool branch_taken_0x1e2854 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e2854) {
            ctx->pc = 0x1E287Cu;
            goto label_1e287c;
        }
    }
    ctx->pc = 0x1E285Cu;
    // 0x1e285c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e285cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e2860: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e2860u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e2864: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e2864u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e2868: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e2868u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e286c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e286cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e2870: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e2870u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e2874: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E2874u;
    {
        const bool branch_taken_0x1e2874 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e2874) {
            ctx->pc = 0x1E2890u;
            goto label_1e2890;
        }
    }
    ctx->pc = 0x1E287Cu;
label_1e287c:
    // 0x1e287c: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e287cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e2880: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e2880u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e2884: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e2884u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e2888: 0x10000060  b           . + 4 + (0x60 << 2)
    ctx->pc = 0x1E2888u;
    {
        const bool branch_taken_0x1e2888 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e2888) {
            ctx->pc = 0x1E2A0Cu;
            goto label_1e2a0c;
        }
    }
    ctx->pc = 0x1E2890u;
label_1e2890:
    // 0x1e2890: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e2890u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e2894: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e2894u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e2898: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e2898u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e289c: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e289cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e28a0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e28a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e28a4: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e28a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e28a8: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1e28a8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1e28ac: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e28acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e28b0: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e28b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e28b4: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E28B4u;
    {
        const bool branch_taken_0x1e28b4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e28b4) {
            ctx->pc = 0x1E28D0u;
            goto label_1e28d0;
        }
    }
    ctx->pc = 0x1E28BCu;
    // 0x1e28bc: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e28bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e28c0: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e28c0u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e28c4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e28c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e28c8: 0x10000050  b           . + 4 + (0x50 << 2)
    ctx->pc = 0x1E28C8u;
    {
        const bool branch_taken_0x1e28c8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e28c8) {
            ctx->pc = 0x1E2A0Cu;
            goto label_1e2a0c;
        }
    }
    ctx->pc = 0x1E28D0u;
label_1e28d0:
    // 0x1e28d0: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e28d0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e28d4: 0x24050004  addiu       $a1, $zero, 0x4
    ctx->pc = 0x1e28d4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1e28d8: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E28D8u;
    SET_GPR_U32(ctx, 31, 0x1E28E0u);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E28E0u; }
        if (ctx->pc != 0x1E28E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E28E0u; }
        if (ctx->pc != 0x1E28E0u) { return; }
    }
    ctx->pc = 0x1E28E0u;
label_1e28e0:
    // 0x1e28e0: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1e28e0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1e28e4: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e28e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e28e8: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E28E8u;
    {
        const bool branch_taken_0x1e28e8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e28e8) {
            ctx->pc = 0x1E2904u;
            goto label_1e2904;
        }
    }
    ctx->pc = 0x1E28F0u;
    // 0x1e28f0: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e28f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e28f4: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e28f4u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e28f8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e28f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e28fc: 0x10000043  b           . + 4 + (0x43 << 2)
    ctx->pc = 0x1E28FCu;
    {
        const bool branch_taken_0x1e28fc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e28fc) {
            ctx->pc = 0x1E2A0Cu;
            goto label_1e2a0c;
        }
    }
    ctx->pc = 0x1E2904u;
label_1e2904:
    // 0x1e2904: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1e2904u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e2908: 0x24050004  addiu       $a1, $zero, 0x4
    ctx->pc = 0x1e2908u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1e290c: 0xc07cc3c  jal         func_1F30F0
    ctx->pc = 0x1E290Cu;
    SET_GPR_U32(ctx, 31, 0x1E2914u);
    ctx->pc = 0x1F30F0u;
    if (runtime->hasFunction(0x1F30F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F30F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2914u; }
        if (ctx->pc != 0x1E2914u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F30F0_0x1f30f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2914u; }
        if (ctx->pc != 0x1E2914u) { return; }
    }
    ctx->pc = 0x1E2914u;
label_1e2914:
    // 0x1e2914: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1e2914u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1e2918: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e2918u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e291c: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1E291Cu;
    {
        const bool branch_taken_0x1e291c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e291c) {
            ctx->pc = 0x1E294Cu;
            goto label_1e294c;
        }
    }
    ctx->pc = 0x1E2924u;
    // 0x1e2924: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e2924u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e2928: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1e2928u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1e292c: 0x8fc5000c  lw          $a1, 0xC($fp)
    ctx->pc = 0x1e292cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e2930: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1E2930u;
    SET_GPR_U32(ctx, 31, 0x1E2938u);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2938u; }
        if (ctx->pc != 0x1E2938u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2938u; }
        if (ctx->pc != 0x1E2938u) { return; }
    }
    ctx->pc = 0x1E2938u;
label_1e2938:
    // 0x1e2938: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e2938u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e293c: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e293cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e2940: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e2940u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e2944: 0x10000031  b           . + 4 + (0x31 << 2)
    ctx->pc = 0x1E2944u;
    {
        const bool branch_taken_0x1e2944 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e2944) {
            ctx->pc = 0x1E2A0Cu;
            goto label_1e2a0c;
        }
    }
    ctx->pc = 0x1E294Cu;
label_1e294c:
    // 0x1e294c: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e294cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e2950: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e2950u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e2954: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1e2954u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1e2958: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1e2958u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1e295c: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e295cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e2960: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1e2960u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1e2964: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1e2964u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1e2968: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1e2968u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e296c: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1e296cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e2970: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1e2970u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1e2974: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e2974u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e2978: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1e2978u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1e297c: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1e297cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e2980: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1e2980u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e2984: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1e2984u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1e2988: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e2988u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e298c: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1e298cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1e2990: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1e2990u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e2994: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x1e2994u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x1e2998: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e2998u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e299c: 0x90420618  lbu         $v0, 0x618($v0)
    ctx->pc = 0x1e299cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 1560)));
    // 0x1e29a0: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e29a0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e29a4: 0x8fc5000c  lw          $a1, 0xC($fp)
    ctx->pc = 0x1e29a4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e29a8: 0x3406b000  ori         $a2, $zero, 0xB000
    ctx->pc = 0x1e29a8u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)45056);
    // 0x1e29ac: 0x24070004  addiu       $a3, $zero, 0x4
    ctx->pc = 0x1e29acu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1e29b0: 0x24080006  addiu       $t0, $zero, 0x6
    ctx->pc = 0x1e29b0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x1e29b4: 0x40482d  daddu       $t1, $v0, $zero
    ctx->pc = 0x1e29b4u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e29b8: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E29B8u;
    SET_GPR_U32(ctx, 31, 0x1E29C0u);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E29C0u; }
        if (ctx->pc != 0x1E29C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E29C0u; }
        if (ctx->pc != 0x1E29C0u) { return; }
    }
    ctx->pc = 0x1E29C0u;
label_1e29c0:
    // 0x1e29c0: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E29C0u;
    {
        const bool branch_taken_0x1e29c0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e29c0) {
            ctx->pc = 0x1E29DCu;
            goto label_1e29dc;
        }
    }
    ctx->pc = 0x1E29C8u;
    // 0x1e29c8: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e29c8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e29cc: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e29ccu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e29d0: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e29d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e29d4: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1E29D4u;
    {
        const bool branch_taken_0x1e29d4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e29d4) {
            ctx->pc = 0x1E2A0Cu;
            goto label_1e2a0c;
        }
    }
    ctx->pc = 0x1E29DCu;
label_1e29dc:
    // 0x1e29dc: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1e29dcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e29e0: 0x24050021  addiu       $a1, $zero, 0x21
    ctx->pc = 0x1e29e0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 33));
    // 0x1e29e4: 0x8fc60008  lw          $a2, 0x8($fp)
    ctx->pc = 0x1e29e4u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e29e8: 0xc076ad5  jal         func_1DAB54
    ctx->pc = 0x1E29E8u;
    SET_GPR_U32(ctx, 31, 0x1E29F0u);
    ctx->pc = 0x1DAB54u;
    if (runtime->hasFunction(0x1DAB54u)) {
        auto targetFn = runtime->lookupFunction(0x1DAB54u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E29F0u; }
        if (ctx->pc != 0x1E29F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DAB54_0x1dab54(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E29F0u; }
        if (ctx->pc != 0x1E29F0u) { return; }
    }
    ctx->pc = 0x1E29F0u;
label_1e29f0:
    // 0x1e29f0: 0x8fc30014  lw          $v1, 0x14($fp)
    ctx->pc = 0x1e29f0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e29f4: 0x90640618  lbu         $a0, 0x618($v1)
    ctx->pc = 0x1e29f4u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 1560)));
    // 0x1e29f8: 0x24820001  addiu       $v0, $a0, 0x1
    ctx->pc = 0x1e29f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1e29fc: 0xa0620618  sb          $v0, 0x618($v1)
    ctx->pc = 0x1e29fcu;
    WRITE8(ADD32(GPR_U32(ctx, 3), 1560), (uint8_t)GPR_U32(ctx, 2));
    // 0x1e2a00: 0x308200ff  andi        $v0, $a0, 0xFF
    ctx->pc = 0x1e2a00u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x1e2a04: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1e2a04u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1e2a08: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e2a08u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
label_1e2a0c:
    // 0x1e2a0c: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e2a0cu;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e2a10: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1e2a10u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1e2a14: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1e2a14u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1e2a18: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1e2a18u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1e2a1c: 0x3e00008  jr          $ra
    ctx->pc = 0x1E2A1Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E1B3Cu: goto label_1e1b3c;
            case 0x1E1B60u: goto label_1e1b60;
            case 0x1E1B84u: goto label_1e1b84;
            case 0x1E1BA8u: goto label_1e1ba8;
            case 0x1E1BC8u: goto label_1e1bc8;
            case 0x1E1BE4u: goto label_1e1be4;
            case 0x1E1BE8u: goto label_1e1be8;
            case 0x1E1C44u: goto label_1e1c44;
            case 0x1E1C58u: goto label_1e1c58;
            case 0x1E1C7Cu: goto label_1e1c7c;
            case 0x1E1CD8u: goto label_1e1cd8;
            case 0x1E1CECu: goto label_1e1cec;
            case 0x1E1D14u: goto label_1e1d14;
            case 0x1E1D7Cu: goto label_1e1d7c;
            case 0x1E1D90u: goto label_1e1d90;
            case 0x1E1DD0u: goto label_1e1dd0;
            case 0x1E1DE0u: goto label_1e1de0;
            case 0x1E1E04u: goto label_1e1e04;
            case 0x1E1E14u: goto label_1e1e14;
            case 0x1E1E38u: goto label_1e1e38;
            case 0x1E1E4Cu: goto label_1e1e4c;
            case 0x1E1E5Cu: goto label_1e1e5c;
            case 0x1E1E84u: goto label_1e1e84;
            case 0x1E1EA0u: goto label_1e1ea0;
            case 0x1E1EB4u: goto label_1e1eb4;
            case 0x1E1ED0u: goto label_1e1ed0;
            case 0x1E1F48u: goto label_1e1f48;
            case 0x1E1F5Cu: goto label_1e1f5c;
            case 0x1E1F9Cu: goto label_1e1f9c;
            case 0x1E1FACu: goto label_1e1fac;
            case 0x1E1FD0u: goto label_1e1fd0;
            case 0x1E1FE0u: goto label_1e1fe0;
            case 0x1E2004u: goto label_1e2004;
            case 0x1E2018u: goto label_1e2018;
            case 0x1E202Cu: goto label_1e202c;
            case 0x1E2064u: goto label_1e2064;
            case 0x1E206Cu: goto label_1e206c;
            case 0x1E2088u: goto label_1e2088;
            case 0x1E20A0u: goto label_1e20a0;
            case 0x1E20D4u: goto label_1e20d4;
            case 0x1E20F8u: goto label_1e20f8;
            case 0x1E210Cu: goto label_1e210c;
            case 0x1E2128u: goto label_1e2128;
            case 0x1E2190u: goto label_1e2190;
            case 0x1E21A4u: goto label_1e21a4;
            case 0x1E21E4u: goto label_1e21e4;
            case 0x1E21F4u: goto label_1e21f4;
            case 0x1E2218u: goto label_1e2218;
            case 0x1E2228u: goto label_1e2228;
            case 0x1E224Cu: goto label_1e224c;
            case 0x1E2260u: goto label_1e2260;
            case 0x1E22D4u: goto label_1e22d4;
            case 0x1E22F0u: goto label_1e22f0;
            case 0x1E2304u: goto label_1e2304;
            case 0x1E2320u: goto label_1e2320;
            case 0x1E23A0u: goto label_1e23a0;
            case 0x1E23B4u: goto label_1e23b4;
            case 0x1E23F4u: goto label_1e23f4;
            case 0x1E2404u: goto label_1e2404;
            case 0x1E2428u: goto label_1e2428;
            case 0x1E2438u: goto label_1e2438;
            case 0x1E245Cu: goto label_1e245c;
            case 0x1E2470u: goto label_1e2470;
            case 0x1E2480u: goto label_1e2480;
            case 0x1E24F8u: goto label_1e24f8;
            case 0x1E2500u: goto label_1e2500;
            case 0x1E2508u: goto label_1e2508;
            case 0x1E25D0u: goto label_1e25d0;
            case 0x1E25ECu: goto label_1e25ec;
            case 0x1E2600u: goto label_1e2600;
            case 0x1E261Cu: goto label_1e261c;
            case 0x1E2684u: goto label_1e2684;
            case 0x1E2698u: goto label_1e2698;
            case 0x1E26D8u: goto label_1e26d8;
            case 0x1E26E8u: goto label_1e26e8;
            case 0x1E270Cu: goto label_1e270c;
            case 0x1E271Cu: goto label_1e271c;
            case 0x1E2740u: goto label_1e2740;
            case 0x1E2754u: goto label_1e2754;
            case 0x1E27C8u: goto label_1e27c8;
            case 0x1E27E4u: goto label_1e27e4;
            case 0x1E27F8u: goto label_1e27f8;
            case 0x1E2814u: goto label_1e2814;
            case 0x1E287Cu: goto label_1e287c;
            case 0x1E2890u: goto label_1e2890;
            case 0x1E28D0u: goto label_1e28d0;
            case 0x1E28E0u: goto label_1e28e0;
            case 0x1E2904u: goto label_1e2904;
            case 0x1E2914u: goto label_1e2914;
            case 0x1E2938u: goto label_1e2938;
            case 0x1E294Cu: goto label_1e294c;
            case 0x1E29C0u: goto label_1e29c0;
            case 0x1E29DCu: goto label_1e29dc;
            case 0x1E29F0u: goto label_1e29f0;
            case 0x1E2A0Cu: goto label_1e2a0c;
            case 0x1E2A78u: goto label_1e2a78;
            case 0x1E2A8Cu: goto label_1e2a8c;
            case 0x1E2ACCu: goto label_1e2acc;
            case 0x1E2ADCu: goto label_1e2adc;
            case 0x1E2B00u: goto label_1e2b00;
            case 0x1E2B10u: goto label_1e2b10;
            case 0x1E2B34u: goto label_1e2b34;
            case 0x1E2B48u: goto label_1e2b48;
            case 0x1E2B54u: goto label_1e2b54;
            case 0x1E2B90u: goto label_1e2b90;
            case 0x1E2B98u: goto label_1e2b98;
            case 0x1E2BC0u: goto label_1e2bc0;
            case 0x1E2BE4u: goto label_1e2be4;
            case 0x1E2BF8u: goto label_1e2bf8;
            case 0x1E2C14u: goto label_1e2c14;
            case 0x1E2C84u: goto label_1e2c84;
            case 0x1E2C98u: goto label_1e2c98;
            case 0x1E2CD8u: goto label_1e2cd8;
            case 0x1E2CE8u: goto label_1e2ce8;
            case 0x1E2D0Cu: goto label_1e2d0c;
            case 0x1E2D1Cu: goto label_1e2d1c;
            case 0x1E2D40u: goto label_1e2d40;
            case 0x1E2D54u: goto label_1e2d54;
            case 0x1E2E10u: goto label_1e2e10;
            case 0x1E2E18u: goto label_1e2e18;
            case 0x1E2E20u: goto label_1e2e20;
            case 0x1E2E48u: goto label_1e2e48;
            case 0x1E2E64u: goto label_1e2e64;
            case 0x1E2E78u: goto label_1e2e78;
            case 0x1E2E94u: goto label_1e2e94;
            case 0x1E2EF8u: goto label_1e2ef8;
            case 0x1E2F0Cu: goto label_1e2f0c;
            case 0x1E2F4Cu: goto label_1e2f4c;
            case 0x1E2F5Cu: goto label_1e2f5c;
            case 0x1E2F80u: goto label_1e2f80;
            case 0x1E2FA8u: goto label_1e2fa8;
            case 0x1E2FC4u: goto label_1e2fc4;
            case 0x1E2FD8u: goto label_1e2fd8;
            case 0x1E2FF4u: goto label_1e2ff4;
            case 0x1E3058u: goto label_1e3058;
            case 0x1E306Cu: goto label_1e306c;
            case 0x1E30ACu: goto label_1e30ac;
            case 0x1E30BCu: goto label_1e30bc;
            case 0x1E30E0u: goto label_1e30e0;
            case 0x1E3108u: goto label_1e3108;
            case 0x1E3124u: goto label_1e3124;
            case 0x1E3138u: goto label_1e3138;
            case 0x1E3154u: goto label_1e3154;
            case 0x1E31CCu: goto label_1e31cc;
            case 0x1E31E0u: goto label_1e31e0;
            case 0x1E3220u: goto label_1e3220;
            case 0x1E3238u: goto label_1e3238;
            case 0x1E325Cu: goto label_1e325c;
            case 0x1E3278u: goto label_1e3278;
            case 0x1E329Cu: goto label_1e329c;
            case 0x1E32B0u: goto label_1e32b0;
            case 0x1E3318u: goto label_1e3318;
            case 0x1E3388u: goto label_1e3388;
            case 0x1E33C4u: goto label_1e33c4;
            case 0x1E33E0u: goto label_1e33e0;
            case 0x1E33F4u: goto label_1e33f4;
            case 0x1E3410u: goto label_1e3410;
            case 0x1E347Cu: goto label_1e347c;
            case 0x1E3490u: goto label_1e3490;
            case 0x1E34D0u: goto label_1e34d0;
            case 0x1E34E0u: goto label_1e34e0;
            case 0x1E3504u: goto label_1e3504;
            case 0x1E3514u: goto label_1e3514;
            case 0x1E3538u: goto label_1e3538;
            case 0x1E354Cu: goto label_1e354c;
            case 0x1E360Cu: goto label_1e360c;
            case 0x1E3628u: goto label_1e3628;
            case 0x1E363Cu: goto label_1e363c;
            case 0x1E3658u: goto label_1e3658;
            case 0x1E36C4u: goto label_1e36c4;
            case 0x1E36D8u: goto label_1e36d8;
            case 0x1E3718u: goto label_1e3718;
            case 0x1E3728u: goto label_1e3728;
            case 0x1E374Cu: goto label_1e374c;
            case 0x1E375Cu: goto label_1e375c;
            case 0x1E3780u: goto label_1e3780;
            case 0x1E3794u: goto label_1e3794;
            case 0x1E3854u: goto label_1e3854;
            case 0x1E3870u: goto label_1e3870;
            case 0x1E3884u: goto label_1e3884;
            case 0x1E38A0u: goto label_1e38a0;
            case 0x1E3908u: goto label_1e3908;
            case 0x1E391Cu: goto label_1e391c;
            case 0x1E395Cu: goto label_1e395c;
            case 0x1E396Cu: goto label_1e396c;
            case 0x1E3990u: goto label_1e3990;
            case 0x1E39A0u: goto label_1e39a0;
            case 0x1E39C4u: goto label_1e39c4;
            case 0x1E39D8u: goto label_1e39d8;
            case 0x1E3A44u: goto label_1e3a44;
            case 0x1E3A60u: goto label_1e3a60;
            case 0x1E3A74u: goto label_1e3a74;
            case 0x1E3A78u: goto label_1e3a78;
            case 0x1E3ADCu: goto label_1e3adc;
            case 0x1E3AF0u: goto label_1e3af0;
            case 0x1E3B30u: goto label_1e3b30;
            case 0x1E3B40u: goto label_1e3b40;
            case 0x1E3B64u: goto label_1e3b64;
            case 0x1E3B84u: goto label_1e3b84;
            case 0x1E3BA0u: goto label_1e3ba0;
            case 0x1E3BB4u: goto label_1e3bb4;
            case 0x1E3BB8u: goto label_1e3bb8;
            case 0x1E3C1Cu: goto label_1e3c1c;
            case 0x1E3C30u: goto label_1e3c30;
            case 0x1E3C70u: goto label_1e3c70;
            case 0x1E3C80u: goto label_1e3c80;
            case 0x1E3CA4u: goto label_1e3ca4;
            case 0x1E3CC4u: goto label_1e3cc4;
            case 0x1E3CE8u: goto label_1e3ce8;
            case 0x1E3CFCu: goto label_1e3cfc;
            case 0x1E3D00u: goto label_1e3d00;
            case 0x1E3D68u: goto label_1e3d68;
            case 0x1E3D7Cu: goto label_1e3d7c;
            case 0x1E3DBCu: goto label_1e3dbc;
            case 0x1E3DCCu: goto label_1e3dcc;
            case 0x1E3DF0u: goto label_1e3df0;
            case 0x1E3E00u: goto label_1e3e00;
            case 0x1E3E24u: goto label_1e3e24;
            case 0x1E3E38u: goto label_1e3e38;
            case 0x1E3EA4u: goto label_1e3ea4;
            case 0x1E3EC0u: goto label_1e3ec0;
            case 0x1E3ED4u: goto label_1e3ed4;
            case 0x1E3ED8u: goto label_1e3ed8;
            case 0x1E3F40u: goto label_1e3f40;
            case 0x1E3F54u: goto label_1e3f54;
            case 0x1E3F94u: goto label_1e3f94;
            case 0x1E3FA4u: goto label_1e3fa4;
            case 0x1E3FC8u: goto label_1e3fc8;
            case 0x1E3FD8u: goto label_1e3fd8;
            case 0x1E3FFCu: goto label_1e3ffc;
            case 0x1E4010u: goto label_1e4010;
            case 0x1E407Cu: goto label_1e407c;
            case 0x1E4098u: goto label_1e4098;
            case 0x1E40ACu: goto label_1e40ac;
            case 0x1E40B0u: goto label_1e40b0;
            case 0x1E4118u: goto label_1e4118;
            case 0x1E412Cu: goto label_1e412c;
            case 0x1E416Cu: goto label_1e416c;
            case 0x1E417Cu: goto label_1e417c;
            case 0x1E41A0u: goto label_1e41a0;
            case 0x1E41B0u: goto label_1e41b0;
            case 0x1E41D4u: goto label_1e41d4;
            case 0x1E41E8u: goto label_1e41e8;
            case 0x1E4254u: goto label_1e4254;
            case 0x1E4270u: goto label_1e4270;
            case 0x1E4284u: goto label_1e4284;
            case 0x1E4288u: goto label_1e4288;
            case 0x1E42F0u: goto label_1e42f0;
            case 0x1E4304u: goto label_1e4304;
            case 0x1E4344u: goto label_1e4344;
            case 0x1E4358u: goto label_1e4358;
            case 0x1E437Cu: goto label_1e437c;
            case 0x1E4394u: goto label_1e4394;
            case 0x1E43B8u: goto label_1e43b8;
            case 0x1E43CCu: goto label_1e43cc;
            case 0x1E43E4u: goto label_1e43e4;
            case 0x1E4414u: goto label_1e4414;
            case 0x1E4430u: goto label_1e4430;
            case 0x1E4444u: goto label_1e4444;
            case 0x1E4460u: goto label_1e4460;
            case 0x1E44C8u: goto label_1e44c8;
            case 0x1E44DCu: goto label_1e44dc;
            case 0x1E451Cu: goto label_1e451c;
            case 0x1E452Cu: goto label_1e452c;
            case 0x1E4550u: goto label_1e4550;
            case 0x1E4560u: goto label_1e4560;
            case 0x1E4584u: goto label_1e4584;
            case 0x1E4598u: goto label_1e4598;
            case 0x1E460Cu: goto label_1e460c;
            case 0x1E4628u: goto label_1e4628;
            case 0x1E463Cu: goto label_1e463c;
            case 0x1E4658u: goto label_1e4658;
            case 0x1E46C8u: goto label_1e46c8;
            case 0x1E46DCu: goto label_1e46dc;
            case 0x1E471Cu: goto label_1e471c;
            case 0x1E472Cu: goto label_1e472c;
            case 0x1E4750u: goto label_1e4750;
            case 0x1E4764u: goto label_1e4764;
            case 0x1E4788u: goto label_1e4788;
            case 0x1E479Cu: goto label_1e479c;
            case 0x1E47B0u: goto label_1e47b0;
            case 0x1E47E0u: goto label_1e47e0;
            case 0x1E47FCu: goto label_1e47fc;
            case 0x1E4800u: goto label_1e4800;
            case 0x1E48A0u: goto label_1e48a0;
            case 0x1E48B4u: goto label_1e48b4;
            case 0x1E48F4u: goto label_1e48f4;
            case 0x1E4918u: goto label_1e4918;
            case 0x1E493Cu: goto label_1e493c;
            case 0x1E4974u: goto label_1e4974;
            case 0x1E4998u: goto label_1e4998;
            case 0x1E49ACu: goto label_1e49ac;
            case 0x1E4A08u: goto label_1e4a08;
            case 0x1E4A24u: goto label_1e4a24;
            case 0x1E4AACu: goto label_1e4aac;
            case 0x1E4AC0u: goto label_1e4ac0;
            case 0x1E4B00u: goto label_1e4b00;
            case 0x1E4B1Cu: goto label_1e4b1c;
            case 0x1E4B20u: goto label_1e4b20;
            case 0x1E4B94u: goto label_1e4b94;
            case 0x1E4BA8u: goto label_1e4ba8;
            case 0x1E4BE8u: goto label_1e4be8;
            case 0x1E4C10u: goto label_1e4c10;
            case 0x1E4C34u: goto label_1e4c34;
            case 0x1E4C64u: goto label_1e4c64;
            case 0x1E4C88u: goto label_1e4c88;
            case 0x1E4C9Cu: goto label_1e4c9c;
            case 0x1E4D08u: goto label_1e4d08;
            case 0x1E4D28u: goto label_1e4d28;
            case 0x1E4DE4u: goto label_1e4de4;
            case 0x1E4DF8u: goto label_1e4df8;
            case 0x1E4E3Cu: goto label_1e4e3c;
            case 0x1E4E58u: goto label_1e4e58;
            case 0x1E4E5Cu: goto label_1e4e5c;
            case 0x1E4EC4u: goto label_1e4ec4;
            case 0x1E4ED8u: goto label_1e4ed8;
            case 0x1E4F18u: goto label_1e4f18;
            case 0x1E4F28u: goto label_1e4f28;
            case 0x1E4F4Cu: goto label_1e4f4c;
            case 0x1E4F60u: goto label_1e4f60;
            case 0x1E4F84u: goto label_1e4f84;
            case 0x1E4F98u: goto label_1e4f98;
            case 0x1E4FACu: goto label_1e4fac;
            case 0x1E4FD0u: goto label_1e4fd0;
            case 0x1E4FECu: goto label_1e4fec;
            case 0x1E4FF0u: goto label_1e4ff0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E2A24u;
    // 0x1e2a24: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1e2a24u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1e2a28: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1e2a28u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1e2a2c: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1e2a2cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1e2a30: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e2a30u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e2a34: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e2a34u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e2a38: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e2a38u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e2a3c: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e2a3cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e2a40: 0xafc7000c  sw          $a3, 0xC($fp)
    ctx->pc = 0x1e2a40u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 7));
    // 0x1e2a44: 0xafc00018  sw          $zero, 0x18($fp)
    ctx->pc = 0x1e2a44u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 0));
    // 0x1e2a48: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e2a48u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e2a4c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e2a4cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e2a50: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E2A50u;
    {
        const bool branch_taken_0x1e2a50 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e2a50) {
            ctx->pc = 0x1E2A78u;
            goto label_1e2a78;
        }
    }
    ctx->pc = 0x1E2A58u;
    // 0x1e2a58: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e2a58u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e2a5c: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e2a5cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e2a60: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e2a60u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e2a64: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e2a64u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e2a68: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e2a68u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e2a6c: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e2a6cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e2a70: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E2A70u;
    {
        const bool branch_taken_0x1e2a70 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e2a70) {
            ctx->pc = 0x1E2A8Cu;
            goto label_1e2a8c;
        }
    }
    ctx->pc = 0x1E2A78u;
label_1e2a78:
    // 0x1e2a78: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e2a78u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e2a7c: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e2a7cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e2a80: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e2a80u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e2a84: 0x10000063  b           . + 4 + (0x63 << 2)
    ctx->pc = 0x1E2A84u;
    {
        const bool branch_taken_0x1e2a84 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e2a84) {
            ctx->pc = 0x1E2C14u;
            goto label_1e2c14;
        }
    }
    ctx->pc = 0x1E2A8Cu;
label_1e2a8c:
    // 0x1e2a8c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e2a8cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e2a90: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e2a90u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e2a94: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e2a94u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e2a98: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e2a98u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e2a9c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e2a9cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e2aa0: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e2aa0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e2aa4: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1e2aa4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1e2aa8: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e2aa8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e2aac: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e2aacu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e2ab0: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E2AB0u;
    {
        const bool branch_taken_0x1e2ab0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e2ab0) {
            ctx->pc = 0x1E2ACCu;
            goto label_1e2acc;
        }
    }
    ctx->pc = 0x1E2AB8u;
    // 0x1e2ab8: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e2ab8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e2abc: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e2abcu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e2ac0: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e2ac0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e2ac4: 0x10000053  b           . + 4 + (0x53 << 2)
    ctx->pc = 0x1E2AC4u;
    {
        const bool branch_taken_0x1e2ac4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e2ac4) {
            ctx->pc = 0x1E2C14u;
            goto label_1e2c14;
        }
    }
    ctx->pc = 0x1E2ACCu;
label_1e2acc:
    // 0x1e2acc: 0x8fc40018  lw          $a0, 0x18($fp)
    ctx->pc = 0x1e2accu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e2ad0: 0x24050014  addiu       $a1, $zero, 0x14
    ctx->pc = 0x1e2ad0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
    // 0x1e2ad4: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E2AD4u;
    SET_GPR_U32(ctx, 31, 0x1E2ADCu);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2ADCu; }
        if (ctx->pc != 0x1E2ADCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2ADCu; }
        if (ctx->pc != 0x1E2ADCu) { return; }
    }
    ctx->pc = 0x1E2ADCu;
label_1e2adc:
    // 0x1e2adc: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1e2adcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1e2ae0: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e2ae0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e2ae4: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E2AE4u;
    {
        const bool branch_taken_0x1e2ae4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e2ae4) {
            ctx->pc = 0x1E2B00u;
            goto label_1e2b00;
        }
    }
    ctx->pc = 0x1E2AECu;
    // 0x1e2aec: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e2aecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e2af0: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e2af0u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e2af4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e2af4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e2af8: 0x10000046  b           . + 4 + (0x46 << 2)
    ctx->pc = 0x1E2AF8u;
    {
        const bool branch_taken_0x1e2af8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e2af8) {
            ctx->pc = 0x1E2C14u;
            goto label_1e2c14;
        }
    }
    ctx->pc = 0x1E2B00u;
label_1e2b00:
    // 0x1e2b00: 0x8fc40010  lw          $a0, 0x10($fp)
    ctx->pc = 0x1e2b00u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e2b04: 0x24050014  addiu       $a1, $zero, 0x14
    ctx->pc = 0x1e2b04u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
    // 0x1e2b08: 0xc07cc3c  jal         func_1F30F0
    ctx->pc = 0x1E2B08u;
    SET_GPR_U32(ctx, 31, 0x1E2B10u);
    ctx->pc = 0x1F30F0u;
    if (runtime->hasFunction(0x1F30F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F30F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2B10u; }
        if (ctx->pc != 0x1E2B10u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F30F0_0x1f30f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2B10u; }
        if (ctx->pc != 0x1E2B10u) { return; }
    }
    ctx->pc = 0x1E2B10u;
label_1e2b10:
    // 0x1e2b10: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1e2b10u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1e2b14: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e2b14u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e2b18: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1E2B18u;
    {
        const bool branch_taken_0x1e2b18 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e2b18) {
            ctx->pc = 0x1E2B48u;
            goto label_1e2b48;
        }
    }
    ctx->pc = 0x1E2B20u;
    // 0x1e2b20: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e2b20u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e2b24: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1e2b24u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1e2b28: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e2b28u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e2b2c: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1E2B2Cu;
    SET_GPR_U32(ctx, 31, 0x1E2B34u);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2B34u; }
        if (ctx->pc != 0x1E2B34u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2B34u; }
        if (ctx->pc != 0x1E2B34u) { return; }
    }
    ctx->pc = 0x1E2B34u;
label_1e2b34:
    // 0x1e2b34: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e2b34u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e2b38: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e2b38u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e2b3c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e2b3cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e2b40: 0x10000034  b           . + 4 + (0x34 << 2)
    ctx->pc = 0x1E2B40u;
    {
        const bool branch_taken_0x1e2b40 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e2b40) {
            ctx->pc = 0x1E2C14u;
            goto label_1e2c14;
        }
    }
    ctx->pc = 0x1E2B48u;
label_1e2b48:
    // 0x1e2b48: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1e2b48u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e2b4c: 0xc07a04d  jal         func_1E8134
    ctx->pc = 0x1E2B4Cu;
    SET_GPR_U32(ctx, 31, 0x1E2B54u);
    ctx->pc = 0x1E8134u;
    if (runtime->hasFunction(0x1E8134u)) {
        auto targetFn = runtime->lookupFunction(0x1E8134u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2B54u; }
        if (ctx->pc != 0x1E2B54u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E8134_0x1e8134(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2B54u; }
        if (ctx->pc != 0x1E2B54u) { return; }
    }
    ctx->pc = 0x1E2B54u;
label_1e2b54:
    // 0x1e2b54: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e2b54u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e2b58: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e2b58u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e2b5c: 0xac430000  sw          $v1, 0x0($v0)
    ctx->pc = 0x1e2b5cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x1e2b60: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e2b60u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e2b64: 0xa0400004  sb          $zero, 0x4($v0)
    ctx->pc = 0x1e2b64u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 4), (uint8_t)GPR_U32(ctx, 0));
    // 0x1e2b68: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1e2b68u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e2b6c: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1E2B6Cu;
    {
        const bool branch_taken_0x1e2b6c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e2b6c) {
            ctx->pc = 0x1E2B98u;
            goto label_1e2b98;
        }
    }
    ctx->pc = 0x1E2B74u;
    // 0x1e2b74: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e2b74u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e2b78: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1e2b78u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1e2b7c: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1e2b7cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e2b80: 0x8fc50008  lw          $a1, 0x8($fp)
    ctx->pc = 0x1e2b80u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e2b84: 0x24060010  addiu       $a2, $zero, 0x10
    ctx->pc = 0x1e2b84u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1e2b88: 0xc042d7e  jal         func_10B5F8
    ctx->pc = 0x1E2B88u;
    SET_GPR_U32(ctx, 31, 0x1E2B90u);
    ctx->pc = 0x10B5F8u;
    if (runtime->hasFunction(0x10B5F8u)) {
        auto targetFn = runtime->lookupFunction(0x10B5F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2B90u; }
        if (ctx->pc != 0x1E2B90u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B5F8_0x10b5f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2B90u; }
        if (ctx->pc != 0x1E2B90u) { return; }
    }
    ctx->pc = 0x1E2B90u;
label_1e2b90:
    // 0x1e2b90: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e2b90u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e2b94: 0xa0400013  sb          $zero, 0x13($v0)
    ctx->pc = 0x1e2b94u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 19), (uint8_t)GPR_U32(ctx, 0));
label_1e2b98:
    // 0x1e2b98: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e2b98u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e2b9c: 0x90420618  lbu         $v0, 0x618($v0)
    ctx->pc = 0x1e2b9cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 1560)));
    // 0x1e2ba0: 0x8fc40018  lw          $a0, 0x18($fp)
    ctx->pc = 0x1e2ba0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e2ba4: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e2ba4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e2ba8: 0x3406b000  ori         $a2, $zero, 0xB000
    ctx->pc = 0x1e2ba8u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)45056);
    // 0x1e2bac: 0x24070014  addiu       $a3, $zero, 0x14
    ctx->pc = 0x1e2bacu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
    // 0x1e2bb0: 0x24080006  addiu       $t0, $zero, 0x6
    ctx->pc = 0x1e2bb0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x1e2bb4: 0x40482d  daddu       $t1, $v0, $zero
    ctx->pc = 0x1e2bb4u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e2bb8: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E2BB8u;
    SET_GPR_U32(ctx, 31, 0x1E2BC0u);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2BC0u; }
        if (ctx->pc != 0x1E2BC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2BC0u; }
        if (ctx->pc != 0x1E2BC0u) { return; }
    }
    ctx->pc = 0x1E2BC0u;
label_1e2bc0:
    // 0x1e2bc0: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1e2bc0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1e2bc4: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1e2bc4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e2bc8: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E2BC8u;
    {
        const bool branch_taken_0x1e2bc8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e2bc8) {
            ctx->pc = 0x1E2BE4u;
            goto label_1e2be4;
        }
    }
    ctx->pc = 0x1E2BD0u;
    // 0x1e2bd0: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e2bd0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e2bd4: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e2bd4u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e2bd8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e2bd8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e2bdc: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1E2BDCu;
    {
        const bool branch_taken_0x1e2bdc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e2bdc) {
            ctx->pc = 0x1E2C14u;
            goto label_1e2c14;
        }
    }
    ctx->pc = 0x1E2BE4u;
label_1e2be4:
    // 0x1e2be4: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1e2be4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e2be8: 0x24050021  addiu       $a1, $zero, 0x21
    ctx->pc = 0x1e2be8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 33));
    // 0x1e2bec: 0x8fc6000c  lw          $a2, 0xC($fp)
    ctx->pc = 0x1e2becu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e2bf0: 0xc076ad5  jal         func_1DAB54
    ctx->pc = 0x1E2BF0u;
    SET_GPR_U32(ctx, 31, 0x1E2BF8u);
    ctx->pc = 0x1DAB54u;
    if (runtime->hasFunction(0x1DAB54u)) {
        auto targetFn = runtime->lookupFunction(0x1DAB54u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2BF8u; }
        if (ctx->pc != 0x1E2BF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DAB54_0x1dab54(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2BF8u; }
        if (ctx->pc != 0x1E2BF8u) { return; }
    }
    ctx->pc = 0x1E2BF8u;
label_1e2bf8:
    // 0x1e2bf8: 0x8fc30018  lw          $v1, 0x18($fp)
    ctx->pc = 0x1e2bf8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e2bfc: 0x90640618  lbu         $a0, 0x618($v1)
    ctx->pc = 0x1e2bfcu;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 1560)));
    // 0x1e2c00: 0x24820001  addiu       $v0, $a0, 0x1
    ctx->pc = 0x1e2c00u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1e2c04: 0xa0620618  sb          $v0, 0x618($v1)
    ctx->pc = 0x1e2c04u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 1560), (uint8_t)GPR_U32(ctx, 2));
    // 0x1e2c08: 0x308200ff  andi        $v0, $a0, 0xFF
    ctx->pc = 0x1e2c08u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x1e2c0c: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1e2c0cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1e2c10: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1e2c10u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
label_1e2c14:
    // 0x1e2c14: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e2c14u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e2c18: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1e2c18u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1e2c1c: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1e2c1cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1e2c20: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1e2c20u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1e2c24: 0x3e00008  jr          $ra
    ctx->pc = 0x1E2C24u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E1B3Cu: goto label_1e1b3c;
            case 0x1E1B60u: goto label_1e1b60;
            case 0x1E1B84u: goto label_1e1b84;
            case 0x1E1BA8u: goto label_1e1ba8;
            case 0x1E1BC8u: goto label_1e1bc8;
            case 0x1E1BE4u: goto label_1e1be4;
            case 0x1E1BE8u: goto label_1e1be8;
            case 0x1E1C44u: goto label_1e1c44;
            case 0x1E1C58u: goto label_1e1c58;
            case 0x1E1C7Cu: goto label_1e1c7c;
            case 0x1E1CD8u: goto label_1e1cd8;
            case 0x1E1CECu: goto label_1e1cec;
            case 0x1E1D14u: goto label_1e1d14;
            case 0x1E1D7Cu: goto label_1e1d7c;
            case 0x1E1D90u: goto label_1e1d90;
            case 0x1E1DD0u: goto label_1e1dd0;
            case 0x1E1DE0u: goto label_1e1de0;
            case 0x1E1E04u: goto label_1e1e04;
            case 0x1E1E14u: goto label_1e1e14;
            case 0x1E1E38u: goto label_1e1e38;
            case 0x1E1E4Cu: goto label_1e1e4c;
            case 0x1E1E5Cu: goto label_1e1e5c;
            case 0x1E1E84u: goto label_1e1e84;
            case 0x1E1EA0u: goto label_1e1ea0;
            case 0x1E1EB4u: goto label_1e1eb4;
            case 0x1E1ED0u: goto label_1e1ed0;
            case 0x1E1F48u: goto label_1e1f48;
            case 0x1E1F5Cu: goto label_1e1f5c;
            case 0x1E1F9Cu: goto label_1e1f9c;
            case 0x1E1FACu: goto label_1e1fac;
            case 0x1E1FD0u: goto label_1e1fd0;
            case 0x1E1FE0u: goto label_1e1fe0;
            case 0x1E2004u: goto label_1e2004;
            case 0x1E2018u: goto label_1e2018;
            case 0x1E202Cu: goto label_1e202c;
            case 0x1E2064u: goto label_1e2064;
            case 0x1E206Cu: goto label_1e206c;
            case 0x1E2088u: goto label_1e2088;
            case 0x1E20A0u: goto label_1e20a0;
            case 0x1E20D4u: goto label_1e20d4;
            case 0x1E20F8u: goto label_1e20f8;
            case 0x1E210Cu: goto label_1e210c;
            case 0x1E2128u: goto label_1e2128;
            case 0x1E2190u: goto label_1e2190;
            case 0x1E21A4u: goto label_1e21a4;
            case 0x1E21E4u: goto label_1e21e4;
            case 0x1E21F4u: goto label_1e21f4;
            case 0x1E2218u: goto label_1e2218;
            case 0x1E2228u: goto label_1e2228;
            case 0x1E224Cu: goto label_1e224c;
            case 0x1E2260u: goto label_1e2260;
            case 0x1E22D4u: goto label_1e22d4;
            case 0x1E22F0u: goto label_1e22f0;
            case 0x1E2304u: goto label_1e2304;
            case 0x1E2320u: goto label_1e2320;
            case 0x1E23A0u: goto label_1e23a0;
            case 0x1E23B4u: goto label_1e23b4;
            case 0x1E23F4u: goto label_1e23f4;
            case 0x1E2404u: goto label_1e2404;
            case 0x1E2428u: goto label_1e2428;
            case 0x1E2438u: goto label_1e2438;
            case 0x1E245Cu: goto label_1e245c;
            case 0x1E2470u: goto label_1e2470;
            case 0x1E2480u: goto label_1e2480;
            case 0x1E24F8u: goto label_1e24f8;
            case 0x1E2500u: goto label_1e2500;
            case 0x1E2508u: goto label_1e2508;
            case 0x1E25D0u: goto label_1e25d0;
            case 0x1E25ECu: goto label_1e25ec;
            case 0x1E2600u: goto label_1e2600;
            case 0x1E261Cu: goto label_1e261c;
            case 0x1E2684u: goto label_1e2684;
            case 0x1E2698u: goto label_1e2698;
            case 0x1E26D8u: goto label_1e26d8;
            case 0x1E26E8u: goto label_1e26e8;
            case 0x1E270Cu: goto label_1e270c;
            case 0x1E271Cu: goto label_1e271c;
            case 0x1E2740u: goto label_1e2740;
            case 0x1E2754u: goto label_1e2754;
            case 0x1E27C8u: goto label_1e27c8;
            case 0x1E27E4u: goto label_1e27e4;
            case 0x1E27F8u: goto label_1e27f8;
            case 0x1E2814u: goto label_1e2814;
            case 0x1E287Cu: goto label_1e287c;
            case 0x1E2890u: goto label_1e2890;
            case 0x1E28D0u: goto label_1e28d0;
            case 0x1E28E0u: goto label_1e28e0;
            case 0x1E2904u: goto label_1e2904;
            case 0x1E2914u: goto label_1e2914;
            case 0x1E2938u: goto label_1e2938;
            case 0x1E294Cu: goto label_1e294c;
            case 0x1E29C0u: goto label_1e29c0;
            case 0x1E29DCu: goto label_1e29dc;
            case 0x1E29F0u: goto label_1e29f0;
            case 0x1E2A0Cu: goto label_1e2a0c;
            case 0x1E2A78u: goto label_1e2a78;
            case 0x1E2A8Cu: goto label_1e2a8c;
            case 0x1E2ACCu: goto label_1e2acc;
            case 0x1E2ADCu: goto label_1e2adc;
            case 0x1E2B00u: goto label_1e2b00;
            case 0x1E2B10u: goto label_1e2b10;
            case 0x1E2B34u: goto label_1e2b34;
            case 0x1E2B48u: goto label_1e2b48;
            case 0x1E2B54u: goto label_1e2b54;
            case 0x1E2B90u: goto label_1e2b90;
            case 0x1E2B98u: goto label_1e2b98;
            case 0x1E2BC0u: goto label_1e2bc0;
            case 0x1E2BE4u: goto label_1e2be4;
            case 0x1E2BF8u: goto label_1e2bf8;
            case 0x1E2C14u: goto label_1e2c14;
            case 0x1E2C84u: goto label_1e2c84;
            case 0x1E2C98u: goto label_1e2c98;
            case 0x1E2CD8u: goto label_1e2cd8;
            case 0x1E2CE8u: goto label_1e2ce8;
            case 0x1E2D0Cu: goto label_1e2d0c;
            case 0x1E2D1Cu: goto label_1e2d1c;
            case 0x1E2D40u: goto label_1e2d40;
            case 0x1E2D54u: goto label_1e2d54;
            case 0x1E2E10u: goto label_1e2e10;
            case 0x1E2E18u: goto label_1e2e18;
            case 0x1E2E20u: goto label_1e2e20;
            case 0x1E2E48u: goto label_1e2e48;
            case 0x1E2E64u: goto label_1e2e64;
            case 0x1E2E78u: goto label_1e2e78;
            case 0x1E2E94u: goto label_1e2e94;
            case 0x1E2EF8u: goto label_1e2ef8;
            case 0x1E2F0Cu: goto label_1e2f0c;
            case 0x1E2F4Cu: goto label_1e2f4c;
            case 0x1E2F5Cu: goto label_1e2f5c;
            case 0x1E2F80u: goto label_1e2f80;
            case 0x1E2FA8u: goto label_1e2fa8;
            case 0x1E2FC4u: goto label_1e2fc4;
            case 0x1E2FD8u: goto label_1e2fd8;
            case 0x1E2FF4u: goto label_1e2ff4;
            case 0x1E3058u: goto label_1e3058;
            case 0x1E306Cu: goto label_1e306c;
            case 0x1E30ACu: goto label_1e30ac;
            case 0x1E30BCu: goto label_1e30bc;
            case 0x1E30E0u: goto label_1e30e0;
            case 0x1E3108u: goto label_1e3108;
            case 0x1E3124u: goto label_1e3124;
            case 0x1E3138u: goto label_1e3138;
            case 0x1E3154u: goto label_1e3154;
            case 0x1E31CCu: goto label_1e31cc;
            case 0x1E31E0u: goto label_1e31e0;
            case 0x1E3220u: goto label_1e3220;
            case 0x1E3238u: goto label_1e3238;
            case 0x1E325Cu: goto label_1e325c;
            case 0x1E3278u: goto label_1e3278;
            case 0x1E329Cu: goto label_1e329c;
            case 0x1E32B0u: goto label_1e32b0;
            case 0x1E3318u: goto label_1e3318;
            case 0x1E3388u: goto label_1e3388;
            case 0x1E33C4u: goto label_1e33c4;
            case 0x1E33E0u: goto label_1e33e0;
            case 0x1E33F4u: goto label_1e33f4;
            case 0x1E3410u: goto label_1e3410;
            case 0x1E347Cu: goto label_1e347c;
            case 0x1E3490u: goto label_1e3490;
            case 0x1E34D0u: goto label_1e34d0;
            case 0x1E34E0u: goto label_1e34e0;
            case 0x1E3504u: goto label_1e3504;
            case 0x1E3514u: goto label_1e3514;
            case 0x1E3538u: goto label_1e3538;
            case 0x1E354Cu: goto label_1e354c;
            case 0x1E360Cu: goto label_1e360c;
            case 0x1E3628u: goto label_1e3628;
            case 0x1E363Cu: goto label_1e363c;
            case 0x1E3658u: goto label_1e3658;
            case 0x1E36C4u: goto label_1e36c4;
            case 0x1E36D8u: goto label_1e36d8;
            case 0x1E3718u: goto label_1e3718;
            case 0x1E3728u: goto label_1e3728;
            case 0x1E374Cu: goto label_1e374c;
            case 0x1E375Cu: goto label_1e375c;
            case 0x1E3780u: goto label_1e3780;
            case 0x1E3794u: goto label_1e3794;
            case 0x1E3854u: goto label_1e3854;
            case 0x1E3870u: goto label_1e3870;
            case 0x1E3884u: goto label_1e3884;
            case 0x1E38A0u: goto label_1e38a0;
            case 0x1E3908u: goto label_1e3908;
            case 0x1E391Cu: goto label_1e391c;
            case 0x1E395Cu: goto label_1e395c;
            case 0x1E396Cu: goto label_1e396c;
            case 0x1E3990u: goto label_1e3990;
            case 0x1E39A0u: goto label_1e39a0;
            case 0x1E39C4u: goto label_1e39c4;
            case 0x1E39D8u: goto label_1e39d8;
            case 0x1E3A44u: goto label_1e3a44;
            case 0x1E3A60u: goto label_1e3a60;
            case 0x1E3A74u: goto label_1e3a74;
            case 0x1E3A78u: goto label_1e3a78;
            case 0x1E3ADCu: goto label_1e3adc;
            case 0x1E3AF0u: goto label_1e3af0;
            case 0x1E3B30u: goto label_1e3b30;
            case 0x1E3B40u: goto label_1e3b40;
            case 0x1E3B64u: goto label_1e3b64;
            case 0x1E3B84u: goto label_1e3b84;
            case 0x1E3BA0u: goto label_1e3ba0;
            case 0x1E3BB4u: goto label_1e3bb4;
            case 0x1E3BB8u: goto label_1e3bb8;
            case 0x1E3C1Cu: goto label_1e3c1c;
            case 0x1E3C30u: goto label_1e3c30;
            case 0x1E3C70u: goto label_1e3c70;
            case 0x1E3C80u: goto label_1e3c80;
            case 0x1E3CA4u: goto label_1e3ca4;
            case 0x1E3CC4u: goto label_1e3cc4;
            case 0x1E3CE8u: goto label_1e3ce8;
            case 0x1E3CFCu: goto label_1e3cfc;
            case 0x1E3D00u: goto label_1e3d00;
            case 0x1E3D68u: goto label_1e3d68;
            case 0x1E3D7Cu: goto label_1e3d7c;
            case 0x1E3DBCu: goto label_1e3dbc;
            case 0x1E3DCCu: goto label_1e3dcc;
            case 0x1E3DF0u: goto label_1e3df0;
            case 0x1E3E00u: goto label_1e3e00;
            case 0x1E3E24u: goto label_1e3e24;
            case 0x1E3E38u: goto label_1e3e38;
            case 0x1E3EA4u: goto label_1e3ea4;
            case 0x1E3EC0u: goto label_1e3ec0;
            case 0x1E3ED4u: goto label_1e3ed4;
            case 0x1E3ED8u: goto label_1e3ed8;
            case 0x1E3F40u: goto label_1e3f40;
            case 0x1E3F54u: goto label_1e3f54;
            case 0x1E3F94u: goto label_1e3f94;
            case 0x1E3FA4u: goto label_1e3fa4;
            case 0x1E3FC8u: goto label_1e3fc8;
            case 0x1E3FD8u: goto label_1e3fd8;
            case 0x1E3FFCu: goto label_1e3ffc;
            case 0x1E4010u: goto label_1e4010;
            case 0x1E407Cu: goto label_1e407c;
            case 0x1E4098u: goto label_1e4098;
            case 0x1E40ACu: goto label_1e40ac;
            case 0x1E40B0u: goto label_1e40b0;
            case 0x1E4118u: goto label_1e4118;
            case 0x1E412Cu: goto label_1e412c;
            case 0x1E416Cu: goto label_1e416c;
            case 0x1E417Cu: goto label_1e417c;
            case 0x1E41A0u: goto label_1e41a0;
            case 0x1E41B0u: goto label_1e41b0;
            case 0x1E41D4u: goto label_1e41d4;
            case 0x1E41E8u: goto label_1e41e8;
            case 0x1E4254u: goto label_1e4254;
            case 0x1E4270u: goto label_1e4270;
            case 0x1E4284u: goto label_1e4284;
            case 0x1E4288u: goto label_1e4288;
            case 0x1E42F0u: goto label_1e42f0;
            case 0x1E4304u: goto label_1e4304;
            case 0x1E4344u: goto label_1e4344;
            case 0x1E4358u: goto label_1e4358;
            case 0x1E437Cu: goto label_1e437c;
            case 0x1E4394u: goto label_1e4394;
            case 0x1E43B8u: goto label_1e43b8;
            case 0x1E43CCu: goto label_1e43cc;
            case 0x1E43E4u: goto label_1e43e4;
            case 0x1E4414u: goto label_1e4414;
            case 0x1E4430u: goto label_1e4430;
            case 0x1E4444u: goto label_1e4444;
            case 0x1E4460u: goto label_1e4460;
            case 0x1E44C8u: goto label_1e44c8;
            case 0x1E44DCu: goto label_1e44dc;
            case 0x1E451Cu: goto label_1e451c;
            case 0x1E452Cu: goto label_1e452c;
            case 0x1E4550u: goto label_1e4550;
            case 0x1E4560u: goto label_1e4560;
            case 0x1E4584u: goto label_1e4584;
            case 0x1E4598u: goto label_1e4598;
            case 0x1E460Cu: goto label_1e460c;
            case 0x1E4628u: goto label_1e4628;
            case 0x1E463Cu: goto label_1e463c;
            case 0x1E4658u: goto label_1e4658;
            case 0x1E46C8u: goto label_1e46c8;
            case 0x1E46DCu: goto label_1e46dc;
            case 0x1E471Cu: goto label_1e471c;
            case 0x1E472Cu: goto label_1e472c;
            case 0x1E4750u: goto label_1e4750;
            case 0x1E4764u: goto label_1e4764;
            case 0x1E4788u: goto label_1e4788;
            case 0x1E479Cu: goto label_1e479c;
            case 0x1E47B0u: goto label_1e47b0;
            case 0x1E47E0u: goto label_1e47e0;
            case 0x1E47FCu: goto label_1e47fc;
            case 0x1E4800u: goto label_1e4800;
            case 0x1E48A0u: goto label_1e48a0;
            case 0x1E48B4u: goto label_1e48b4;
            case 0x1E48F4u: goto label_1e48f4;
            case 0x1E4918u: goto label_1e4918;
            case 0x1E493Cu: goto label_1e493c;
            case 0x1E4974u: goto label_1e4974;
            case 0x1E4998u: goto label_1e4998;
            case 0x1E49ACu: goto label_1e49ac;
            case 0x1E4A08u: goto label_1e4a08;
            case 0x1E4A24u: goto label_1e4a24;
            case 0x1E4AACu: goto label_1e4aac;
            case 0x1E4AC0u: goto label_1e4ac0;
            case 0x1E4B00u: goto label_1e4b00;
            case 0x1E4B1Cu: goto label_1e4b1c;
            case 0x1E4B20u: goto label_1e4b20;
            case 0x1E4B94u: goto label_1e4b94;
            case 0x1E4BA8u: goto label_1e4ba8;
            case 0x1E4BE8u: goto label_1e4be8;
            case 0x1E4C10u: goto label_1e4c10;
            case 0x1E4C34u: goto label_1e4c34;
            case 0x1E4C64u: goto label_1e4c64;
            case 0x1E4C88u: goto label_1e4c88;
            case 0x1E4C9Cu: goto label_1e4c9c;
            case 0x1E4D08u: goto label_1e4d08;
            case 0x1E4D28u: goto label_1e4d28;
            case 0x1E4DE4u: goto label_1e4de4;
            case 0x1E4DF8u: goto label_1e4df8;
            case 0x1E4E3Cu: goto label_1e4e3c;
            case 0x1E4E58u: goto label_1e4e58;
            case 0x1E4E5Cu: goto label_1e4e5c;
            case 0x1E4EC4u: goto label_1e4ec4;
            case 0x1E4ED8u: goto label_1e4ed8;
            case 0x1E4F18u: goto label_1e4f18;
            case 0x1E4F28u: goto label_1e4f28;
            case 0x1E4F4Cu: goto label_1e4f4c;
            case 0x1E4F60u: goto label_1e4f60;
            case 0x1E4F84u: goto label_1e4f84;
            case 0x1E4F98u: goto label_1e4f98;
            case 0x1E4FACu: goto label_1e4fac;
            case 0x1E4FD0u: goto label_1e4fd0;
            case 0x1E4FECu: goto label_1e4fec;
            case 0x1E4FF0u: goto label_1e4ff0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E2C2Cu;
    // 0x1e2c2c: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1e2c2cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1e2c30: 0xffbe0030  sd          $fp, 0x30($sp)
    ctx->pc = 0x1e2c30u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 30));
    // 0x1e2c34: 0xffbf0038  sd          $ra, 0x38($sp)
    ctx->pc = 0x1e2c34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x1e2c38: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e2c38u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e2c3c: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e2c3cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e2c40: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e2c40u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e2c44: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e2c44u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e2c48: 0xafc7000c  sw          $a3, 0xC($fp)
    ctx->pc = 0x1e2c48u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 7));
    // 0x1e2c4c: 0xafc80010  sw          $t0, 0x10($fp)
    ctx->pc = 0x1e2c4cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 8));
    // 0x1e2c50: 0xafc0001c  sw          $zero, 0x1C($fp)
    ctx->pc = 0x1e2c50u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 0));
    // 0x1e2c54: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e2c54u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e2c58: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e2c58u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e2c5c: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E2C5Cu;
    {
        const bool branch_taken_0x1e2c5c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e2c5c) {
            ctx->pc = 0x1E2C84u;
            goto label_1e2c84;
        }
    }
    ctx->pc = 0x1E2C64u;
    // 0x1e2c64: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e2c64u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e2c68: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e2c68u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e2c6c: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e2c6cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e2c70: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e2c70u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e2c74: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e2c74u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e2c78: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e2c78u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e2c7c: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E2C7Cu;
    {
        const bool branch_taken_0x1e2c7c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e2c7c) {
            ctx->pc = 0x1E2C98u;
            goto label_1e2c98;
        }
    }
    ctx->pc = 0x1E2C84u;
label_1e2c84:
    // 0x1e2c84: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e2c84u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e2c88: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e2c88u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e2c8c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e2c8cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e2c90: 0x10000080  b           . + 4 + (0x80 << 2)
    ctx->pc = 0x1E2C90u;
    {
        const bool branch_taken_0x1e2c90 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e2c90) {
            ctx->pc = 0x1E2E94u;
            goto label_1e2e94;
        }
    }
    ctx->pc = 0x1E2C98u;
label_1e2c98:
    // 0x1e2c98: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e2c98u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e2c9c: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e2c9cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e2ca0: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e2ca0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e2ca4: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e2ca4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e2ca8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e2ca8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e2cac: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e2cacu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e2cb0: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1e2cb0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1e2cb4: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1e2cb4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e2cb8: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e2cb8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e2cbc: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E2CBCu;
    {
        const bool branch_taken_0x1e2cbc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e2cbc) {
            ctx->pc = 0x1E2CD8u;
            goto label_1e2cd8;
        }
    }
    ctx->pc = 0x1E2CC4u;
    // 0x1e2cc4: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e2cc4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e2cc8: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e2cc8u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e2ccc: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e2cccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e2cd0: 0x10000070  b           . + 4 + (0x70 << 2)
    ctx->pc = 0x1E2CD0u;
    {
        const bool branch_taken_0x1e2cd0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e2cd0) {
            ctx->pc = 0x1E2E94u;
            goto label_1e2e94;
        }
    }
    ctx->pc = 0x1E2CD8u;
label_1e2cd8:
    // 0x1e2cd8: 0x8fc4001c  lw          $a0, 0x1C($fp)
    ctx->pc = 0x1e2cd8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e2cdc: 0x24050018  addiu       $a1, $zero, 0x18
    ctx->pc = 0x1e2cdcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 24));
    // 0x1e2ce0: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E2CE0u;
    SET_GPR_U32(ctx, 31, 0x1E2CE8u);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2CE8u; }
        if (ctx->pc != 0x1E2CE8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2CE8u; }
        if (ctx->pc != 0x1E2CE8u) { return; }
    }
    ctx->pc = 0x1E2CE8u;
label_1e2ce8:
    // 0x1e2ce8: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1e2ce8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1e2cec: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e2cecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e2cf0: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E2CF0u;
    {
        const bool branch_taken_0x1e2cf0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e2cf0) {
            ctx->pc = 0x1E2D0Cu;
            goto label_1e2d0c;
        }
    }
    ctx->pc = 0x1E2CF8u;
    // 0x1e2cf8: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e2cf8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e2cfc: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e2cfcu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e2d00: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e2d00u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e2d04: 0x10000063  b           . + 4 + (0x63 << 2)
    ctx->pc = 0x1E2D04u;
    {
        const bool branch_taken_0x1e2d04 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e2d04) {
            ctx->pc = 0x1E2E94u;
            goto label_1e2e94;
        }
    }
    ctx->pc = 0x1E2D0Cu;
label_1e2d0c:
    // 0x1e2d0c: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e2d0cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e2d10: 0x24050018  addiu       $a1, $zero, 0x18
    ctx->pc = 0x1e2d10u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 24));
    // 0x1e2d14: 0xc07cc3c  jal         func_1F30F0
    ctx->pc = 0x1E2D14u;
    SET_GPR_U32(ctx, 31, 0x1E2D1Cu);
    ctx->pc = 0x1F30F0u;
    if (runtime->hasFunction(0x1F30F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F30F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2D1Cu; }
        if (ctx->pc != 0x1E2D1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F30F0_0x1f30f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2D1Cu; }
        if (ctx->pc != 0x1E2D1Cu) { return; }
    }
    ctx->pc = 0x1E2D1Cu;
label_1e2d1c:
    // 0x1e2d1c: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1e2d1cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1e2d20: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e2d20u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e2d24: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1E2D24u;
    {
        const bool branch_taken_0x1e2d24 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e2d24) {
            ctx->pc = 0x1E2D54u;
            goto label_1e2d54;
        }
    }
    ctx->pc = 0x1E2D2Cu;
    // 0x1e2d2c: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1e2d2cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e2d30: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1e2d30u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1e2d34: 0x8fc50014  lw          $a1, 0x14($fp)
    ctx->pc = 0x1e2d34u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e2d38: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1E2D38u;
    SET_GPR_U32(ctx, 31, 0x1E2D40u);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2D40u; }
        if (ctx->pc != 0x1E2D40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2D40u; }
        if (ctx->pc != 0x1E2D40u) { return; }
    }
    ctx->pc = 0x1E2D40u;
label_1e2d40:
    // 0x1e2d40: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e2d40u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e2d44: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e2d44u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e2d48: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e2d48u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e2d4c: 0x10000051  b           . + 4 + (0x51 << 2)
    ctx->pc = 0x1E2D4Cu;
    {
        const bool branch_taken_0x1e2d4c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e2d4c) {
            ctx->pc = 0x1E2E94u;
            goto label_1e2e94;
        }
    }
    ctx->pc = 0x1E2D54u;
label_1e2d54:
    // 0x1e2d54: 0x8fc50018  lw          $a1, 0x18($fp)
    ctx->pc = 0x1e2d54u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e2d58: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e2d58u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e2d5c: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1e2d5cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1e2d60: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1e2d60u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1e2d64: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e2d64u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e2d68: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1e2d68u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1e2d6c: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1e2d6cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1e2d70: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1e2d70u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e2d74: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1e2d74u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e2d78: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1e2d78u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1e2d7c: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e2d7cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e2d80: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1e2d80u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1e2d84: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1e2d84u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e2d88: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1e2d88u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e2d8c: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1e2d8cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1e2d90: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e2d90u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e2d94: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1e2d94u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1e2d98: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1e2d98u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e2d9c: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x1e2d9cu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x1e2da0: 0x8fc50018  lw          $a1, 0x18($fp)
    ctx->pc = 0x1e2da0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e2da4: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e2da4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e2da8: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1e2da8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1e2dac: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1e2dacu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1e2db0: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e2db0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e2db4: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1e2db4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1e2db8: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1e2db8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1e2dbc: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1e2dbcu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e2dc0: 0x8fc3000c  lw          $v1, 0xC($fp)
    ctx->pc = 0x1e2dc0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e2dc4: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1e2dc4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1e2dc8: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e2dc8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e2dcc: 0x21203  sra         $v0, $v0, 8
    ctx->pc = 0x1e2dccu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 8));
    // 0x1e2dd0: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1e2dd0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e2dd4: 0x8fc3000c  lw          $v1, 0xC($fp)
    ctx->pc = 0x1e2dd4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e2dd8: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1e2dd8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1e2ddc: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e2ddcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e2de0: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1e2de0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1e2de4: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1e2de4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e2de8: 0xaca20004  sw          $v0, 0x4($a1)
    ctx->pc = 0x1e2de8u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 4), GPR_U32(ctx, 2));
    // 0x1e2dec: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1e2decu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e2df0: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E2DF0u;
    {
        const bool branch_taken_0x1e2df0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e2df0) {
            ctx->pc = 0x1E2E18u;
            goto label_1e2e18;
        }
    }
    ctx->pc = 0x1E2DF8u;
    // 0x1e2df8: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e2df8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e2dfc: 0x24420008  addiu       $v0, $v0, 0x8
    ctx->pc = 0x1e2dfcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x1e2e00: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1e2e00u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e2e04: 0x8fc50008  lw          $a1, 0x8($fp)
    ctx->pc = 0x1e2e04u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e2e08: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1E2E08u;
    SET_GPR_U32(ctx, 31, 0x1E2E10u);
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2E10u; }
        if (ctx->pc != 0x1E2E10u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2E10u; }
        if (ctx->pc != 0x1E2E10u) { return; }
    }
    ctx->pc = 0x1E2E10u;
label_1e2e10:
    // 0x1e2e10: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1E2E10u;
    {
        const bool branch_taken_0x1e2e10 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e2e10) {
            ctx->pc = 0x1E2E20u;
            goto label_1e2e20;
        }
    }
    ctx->pc = 0x1E2E18u;
label_1e2e18:
    // 0x1e2e18: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e2e18u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e2e1c: 0xa0400008  sb          $zero, 0x8($v0)
    ctx->pc = 0x1e2e1cu;
    WRITE8(ADD32(GPR_U32(ctx, 2), 8), (uint8_t)GPR_U32(ctx, 0));
label_1e2e20:
    // 0x1e2e20: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1e2e20u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e2e24: 0x90420619  lbu         $v0, 0x619($v0)
    ctx->pc = 0x1e2e24u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 1561)));
    // 0x1e2e28: 0x8fc4001c  lw          $a0, 0x1C($fp)
    ctx->pc = 0x1e2e28u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e2e2c: 0x8fc50014  lw          $a1, 0x14($fp)
    ctx->pc = 0x1e2e2cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e2e30: 0x3406a000  ori         $a2, $zero, 0xA000
    ctx->pc = 0x1e2e30u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)40960);
    // 0x1e2e34: 0x24070018  addiu       $a3, $zero, 0x18
    ctx->pc = 0x1e2e34u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 24));
    // 0x1e2e38: 0x24080006  addiu       $t0, $zero, 0x6
    ctx->pc = 0x1e2e38u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x1e2e3c: 0x40482d  daddu       $t1, $v0, $zero
    ctx->pc = 0x1e2e3cu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e2e40: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E2E40u;
    SET_GPR_U32(ctx, 31, 0x1E2E48u);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2E48u; }
        if (ctx->pc != 0x1E2E48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2E48u; }
        if (ctx->pc != 0x1E2E48u) { return; }
    }
    ctx->pc = 0x1E2E48u;
label_1e2e48:
    // 0x1e2e48: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E2E48u;
    {
        const bool branch_taken_0x1e2e48 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e2e48) {
            ctx->pc = 0x1E2E64u;
            goto label_1e2e64;
        }
    }
    ctx->pc = 0x1E2E50u;
    // 0x1e2e50: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e2e50u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e2e54: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e2e54u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e2e58: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e2e58u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e2e5c: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1E2E5Cu;
    {
        const bool branch_taken_0x1e2e5c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e2e5c) {
            ctx->pc = 0x1E2E94u;
            goto label_1e2e94;
        }
    }
    ctx->pc = 0x1E2E64u;
label_1e2e64:
    // 0x1e2e64: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1e2e64u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e2e68: 0x24050022  addiu       $a1, $zero, 0x22
    ctx->pc = 0x1e2e68u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 34));
    // 0x1e2e6c: 0x8fc60010  lw          $a2, 0x10($fp)
    ctx->pc = 0x1e2e6cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e2e70: 0xc076ad5  jal         func_1DAB54
    ctx->pc = 0x1E2E70u;
    SET_GPR_U32(ctx, 31, 0x1E2E78u);
    ctx->pc = 0x1DAB54u;
    if (runtime->hasFunction(0x1DAB54u)) {
        auto targetFn = runtime->lookupFunction(0x1DAB54u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2E78u; }
        if (ctx->pc != 0x1E2E78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DAB54_0x1dab54(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2E78u; }
        if (ctx->pc != 0x1E2E78u) { return; }
    }
    ctx->pc = 0x1E2E78u;
label_1e2e78:
    // 0x1e2e78: 0x8fc3001c  lw          $v1, 0x1C($fp)
    ctx->pc = 0x1e2e78u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e2e7c: 0x90640619  lbu         $a0, 0x619($v1)
    ctx->pc = 0x1e2e7cu;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 1561)));
    // 0x1e2e80: 0x24820001  addiu       $v0, $a0, 0x1
    ctx->pc = 0x1e2e80u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1e2e84: 0xa0620619  sb          $v0, 0x619($v1)
    ctx->pc = 0x1e2e84u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 1561), (uint8_t)GPR_U32(ctx, 2));
    // 0x1e2e88: 0x308200ff  andi        $v0, $a0, 0xFF
    ctx->pc = 0x1e2e88u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x1e2e8c: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1e2e8cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1e2e90: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e2e90u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
label_1e2e94:
    // 0x1e2e94: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e2e94u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e2e98: 0xdfbe0030  ld          $fp, 0x30($sp)
    ctx->pc = 0x1e2e98u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1e2e9c: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x1e2e9cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x1e2ea0: 0x27bd0040  addiu       $sp, $sp, 0x40
    ctx->pc = 0x1e2ea0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x1e2ea4: 0x3e00008  jr          $ra
    ctx->pc = 0x1E2EA4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E1B3Cu: goto label_1e1b3c;
            case 0x1E1B60u: goto label_1e1b60;
            case 0x1E1B84u: goto label_1e1b84;
            case 0x1E1BA8u: goto label_1e1ba8;
            case 0x1E1BC8u: goto label_1e1bc8;
            case 0x1E1BE4u: goto label_1e1be4;
            case 0x1E1BE8u: goto label_1e1be8;
            case 0x1E1C44u: goto label_1e1c44;
            case 0x1E1C58u: goto label_1e1c58;
            case 0x1E1C7Cu: goto label_1e1c7c;
            case 0x1E1CD8u: goto label_1e1cd8;
            case 0x1E1CECu: goto label_1e1cec;
            case 0x1E1D14u: goto label_1e1d14;
            case 0x1E1D7Cu: goto label_1e1d7c;
            case 0x1E1D90u: goto label_1e1d90;
            case 0x1E1DD0u: goto label_1e1dd0;
            case 0x1E1DE0u: goto label_1e1de0;
            case 0x1E1E04u: goto label_1e1e04;
            case 0x1E1E14u: goto label_1e1e14;
            case 0x1E1E38u: goto label_1e1e38;
            case 0x1E1E4Cu: goto label_1e1e4c;
            case 0x1E1E5Cu: goto label_1e1e5c;
            case 0x1E1E84u: goto label_1e1e84;
            case 0x1E1EA0u: goto label_1e1ea0;
            case 0x1E1EB4u: goto label_1e1eb4;
            case 0x1E1ED0u: goto label_1e1ed0;
            case 0x1E1F48u: goto label_1e1f48;
            case 0x1E1F5Cu: goto label_1e1f5c;
            case 0x1E1F9Cu: goto label_1e1f9c;
            case 0x1E1FACu: goto label_1e1fac;
            case 0x1E1FD0u: goto label_1e1fd0;
            case 0x1E1FE0u: goto label_1e1fe0;
            case 0x1E2004u: goto label_1e2004;
            case 0x1E2018u: goto label_1e2018;
            case 0x1E202Cu: goto label_1e202c;
            case 0x1E2064u: goto label_1e2064;
            case 0x1E206Cu: goto label_1e206c;
            case 0x1E2088u: goto label_1e2088;
            case 0x1E20A0u: goto label_1e20a0;
            case 0x1E20D4u: goto label_1e20d4;
            case 0x1E20F8u: goto label_1e20f8;
            case 0x1E210Cu: goto label_1e210c;
            case 0x1E2128u: goto label_1e2128;
            case 0x1E2190u: goto label_1e2190;
            case 0x1E21A4u: goto label_1e21a4;
            case 0x1E21E4u: goto label_1e21e4;
            case 0x1E21F4u: goto label_1e21f4;
            case 0x1E2218u: goto label_1e2218;
            case 0x1E2228u: goto label_1e2228;
            case 0x1E224Cu: goto label_1e224c;
            case 0x1E2260u: goto label_1e2260;
            case 0x1E22D4u: goto label_1e22d4;
            case 0x1E22F0u: goto label_1e22f0;
            case 0x1E2304u: goto label_1e2304;
            case 0x1E2320u: goto label_1e2320;
            case 0x1E23A0u: goto label_1e23a0;
            case 0x1E23B4u: goto label_1e23b4;
            case 0x1E23F4u: goto label_1e23f4;
            case 0x1E2404u: goto label_1e2404;
            case 0x1E2428u: goto label_1e2428;
            case 0x1E2438u: goto label_1e2438;
            case 0x1E245Cu: goto label_1e245c;
            case 0x1E2470u: goto label_1e2470;
            case 0x1E2480u: goto label_1e2480;
            case 0x1E24F8u: goto label_1e24f8;
            case 0x1E2500u: goto label_1e2500;
            case 0x1E2508u: goto label_1e2508;
            case 0x1E25D0u: goto label_1e25d0;
            case 0x1E25ECu: goto label_1e25ec;
            case 0x1E2600u: goto label_1e2600;
            case 0x1E261Cu: goto label_1e261c;
            case 0x1E2684u: goto label_1e2684;
            case 0x1E2698u: goto label_1e2698;
            case 0x1E26D8u: goto label_1e26d8;
            case 0x1E26E8u: goto label_1e26e8;
            case 0x1E270Cu: goto label_1e270c;
            case 0x1E271Cu: goto label_1e271c;
            case 0x1E2740u: goto label_1e2740;
            case 0x1E2754u: goto label_1e2754;
            case 0x1E27C8u: goto label_1e27c8;
            case 0x1E27E4u: goto label_1e27e4;
            case 0x1E27F8u: goto label_1e27f8;
            case 0x1E2814u: goto label_1e2814;
            case 0x1E287Cu: goto label_1e287c;
            case 0x1E2890u: goto label_1e2890;
            case 0x1E28D0u: goto label_1e28d0;
            case 0x1E28E0u: goto label_1e28e0;
            case 0x1E2904u: goto label_1e2904;
            case 0x1E2914u: goto label_1e2914;
            case 0x1E2938u: goto label_1e2938;
            case 0x1E294Cu: goto label_1e294c;
            case 0x1E29C0u: goto label_1e29c0;
            case 0x1E29DCu: goto label_1e29dc;
            case 0x1E29F0u: goto label_1e29f0;
            case 0x1E2A0Cu: goto label_1e2a0c;
            case 0x1E2A78u: goto label_1e2a78;
            case 0x1E2A8Cu: goto label_1e2a8c;
            case 0x1E2ACCu: goto label_1e2acc;
            case 0x1E2ADCu: goto label_1e2adc;
            case 0x1E2B00u: goto label_1e2b00;
            case 0x1E2B10u: goto label_1e2b10;
            case 0x1E2B34u: goto label_1e2b34;
            case 0x1E2B48u: goto label_1e2b48;
            case 0x1E2B54u: goto label_1e2b54;
            case 0x1E2B90u: goto label_1e2b90;
            case 0x1E2B98u: goto label_1e2b98;
            case 0x1E2BC0u: goto label_1e2bc0;
            case 0x1E2BE4u: goto label_1e2be4;
            case 0x1E2BF8u: goto label_1e2bf8;
            case 0x1E2C14u: goto label_1e2c14;
            case 0x1E2C84u: goto label_1e2c84;
            case 0x1E2C98u: goto label_1e2c98;
            case 0x1E2CD8u: goto label_1e2cd8;
            case 0x1E2CE8u: goto label_1e2ce8;
            case 0x1E2D0Cu: goto label_1e2d0c;
            case 0x1E2D1Cu: goto label_1e2d1c;
            case 0x1E2D40u: goto label_1e2d40;
            case 0x1E2D54u: goto label_1e2d54;
            case 0x1E2E10u: goto label_1e2e10;
            case 0x1E2E18u: goto label_1e2e18;
            case 0x1E2E20u: goto label_1e2e20;
            case 0x1E2E48u: goto label_1e2e48;
            case 0x1E2E64u: goto label_1e2e64;
            case 0x1E2E78u: goto label_1e2e78;
            case 0x1E2E94u: goto label_1e2e94;
            case 0x1E2EF8u: goto label_1e2ef8;
            case 0x1E2F0Cu: goto label_1e2f0c;
            case 0x1E2F4Cu: goto label_1e2f4c;
            case 0x1E2F5Cu: goto label_1e2f5c;
            case 0x1E2F80u: goto label_1e2f80;
            case 0x1E2FA8u: goto label_1e2fa8;
            case 0x1E2FC4u: goto label_1e2fc4;
            case 0x1E2FD8u: goto label_1e2fd8;
            case 0x1E2FF4u: goto label_1e2ff4;
            case 0x1E3058u: goto label_1e3058;
            case 0x1E306Cu: goto label_1e306c;
            case 0x1E30ACu: goto label_1e30ac;
            case 0x1E30BCu: goto label_1e30bc;
            case 0x1E30E0u: goto label_1e30e0;
            case 0x1E3108u: goto label_1e3108;
            case 0x1E3124u: goto label_1e3124;
            case 0x1E3138u: goto label_1e3138;
            case 0x1E3154u: goto label_1e3154;
            case 0x1E31CCu: goto label_1e31cc;
            case 0x1E31E0u: goto label_1e31e0;
            case 0x1E3220u: goto label_1e3220;
            case 0x1E3238u: goto label_1e3238;
            case 0x1E325Cu: goto label_1e325c;
            case 0x1E3278u: goto label_1e3278;
            case 0x1E329Cu: goto label_1e329c;
            case 0x1E32B0u: goto label_1e32b0;
            case 0x1E3318u: goto label_1e3318;
            case 0x1E3388u: goto label_1e3388;
            case 0x1E33C4u: goto label_1e33c4;
            case 0x1E33E0u: goto label_1e33e0;
            case 0x1E33F4u: goto label_1e33f4;
            case 0x1E3410u: goto label_1e3410;
            case 0x1E347Cu: goto label_1e347c;
            case 0x1E3490u: goto label_1e3490;
            case 0x1E34D0u: goto label_1e34d0;
            case 0x1E34E0u: goto label_1e34e0;
            case 0x1E3504u: goto label_1e3504;
            case 0x1E3514u: goto label_1e3514;
            case 0x1E3538u: goto label_1e3538;
            case 0x1E354Cu: goto label_1e354c;
            case 0x1E360Cu: goto label_1e360c;
            case 0x1E3628u: goto label_1e3628;
            case 0x1E363Cu: goto label_1e363c;
            case 0x1E3658u: goto label_1e3658;
            case 0x1E36C4u: goto label_1e36c4;
            case 0x1E36D8u: goto label_1e36d8;
            case 0x1E3718u: goto label_1e3718;
            case 0x1E3728u: goto label_1e3728;
            case 0x1E374Cu: goto label_1e374c;
            case 0x1E375Cu: goto label_1e375c;
            case 0x1E3780u: goto label_1e3780;
            case 0x1E3794u: goto label_1e3794;
            case 0x1E3854u: goto label_1e3854;
            case 0x1E3870u: goto label_1e3870;
            case 0x1E3884u: goto label_1e3884;
            case 0x1E38A0u: goto label_1e38a0;
            case 0x1E3908u: goto label_1e3908;
            case 0x1E391Cu: goto label_1e391c;
            case 0x1E395Cu: goto label_1e395c;
            case 0x1E396Cu: goto label_1e396c;
            case 0x1E3990u: goto label_1e3990;
            case 0x1E39A0u: goto label_1e39a0;
            case 0x1E39C4u: goto label_1e39c4;
            case 0x1E39D8u: goto label_1e39d8;
            case 0x1E3A44u: goto label_1e3a44;
            case 0x1E3A60u: goto label_1e3a60;
            case 0x1E3A74u: goto label_1e3a74;
            case 0x1E3A78u: goto label_1e3a78;
            case 0x1E3ADCu: goto label_1e3adc;
            case 0x1E3AF0u: goto label_1e3af0;
            case 0x1E3B30u: goto label_1e3b30;
            case 0x1E3B40u: goto label_1e3b40;
            case 0x1E3B64u: goto label_1e3b64;
            case 0x1E3B84u: goto label_1e3b84;
            case 0x1E3BA0u: goto label_1e3ba0;
            case 0x1E3BB4u: goto label_1e3bb4;
            case 0x1E3BB8u: goto label_1e3bb8;
            case 0x1E3C1Cu: goto label_1e3c1c;
            case 0x1E3C30u: goto label_1e3c30;
            case 0x1E3C70u: goto label_1e3c70;
            case 0x1E3C80u: goto label_1e3c80;
            case 0x1E3CA4u: goto label_1e3ca4;
            case 0x1E3CC4u: goto label_1e3cc4;
            case 0x1E3CE8u: goto label_1e3ce8;
            case 0x1E3CFCu: goto label_1e3cfc;
            case 0x1E3D00u: goto label_1e3d00;
            case 0x1E3D68u: goto label_1e3d68;
            case 0x1E3D7Cu: goto label_1e3d7c;
            case 0x1E3DBCu: goto label_1e3dbc;
            case 0x1E3DCCu: goto label_1e3dcc;
            case 0x1E3DF0u: goto label_1e3df0;
            case 0x1E3E00u: goto label_1e3e00;
            case 0x1E3E24u: goto label_1e3e24;
            case 0x1E3E38u: goto label_1e3e38;
            case 0x1E3EA4u: goto label_1e3ea4;
            case 0x1E3EC0u: goto label_1e3ec0;
            case 0x1E3ED4u: goto label_1e3ed4;
            case 0x1E3ED8u: goto label_1e3ed8;
            case 0x1E3F40u: goto label_1e3f40;
            case 0x1E3F54u: goto label_1e3f54;
            case 0x1E3F94u: goto label_1e3f94;
            case 0x1E3FA4u: goto label_1e3fa4;
            case 0x1E3FC8u: goto label_1e3fc8;
            case 0x1E3FD8u: goto label_1e3fd8;
            case 0x1E3FFCu: goto label_1e3ffc;
            case 0x1E4010u: goto label_1e4010;
            case 0x1E407Cu: goto label_1e407c;
            case 0x1E4098u: goto label_1e4098;
            case 0x1E40ACu: goto label_1e40ac;
            case 0x1E40B0u: goto label_1e40b0;
            case 0x1E4118u: goto label_1e4118;
            case 0x1E412Cu: goto label_1e412c;
            case 0x1E416Cu: goto label_1e416c;
            case 0x1E417Cu: goto label_1e417c;
            case 0x1E41A0u: goto label_1e41a0;
            case 0x1E41B0u: goto label_1e41b0;
            case 0x1E41D4u: goto label_1e41d4;
            case 0x1E41E8u: goto label_1e41e8;
            case 0x1E4254u: goto label_1e4254;
            case 0x1E4270u: goto label_1e4270;
            case 0x1E4284u: goto label_1e4284;
            case 0x1E4288u: goto label_1e4288;
            case 0x1E42F0u: goto label_1e42f0;
            case 0x1E4304u: goto label_1e4304;
            case 0x1E4344u: goto label_1e4344;
            case 0x1E4358u: goto label_1e4358;
            case 0x1E437Cu: goto label_1e437c;
            case 0x1E4394u: goto label_1e4394;
            case 0x1E43B8u: goto label_1e43b8;
            case 0x1E43CCu: goto label_1e43cc;
            case 0x1E43E4u: goto label_1e43e4;
            case 0x1E4414u: goto label_1e4414;
            case 0x1E4430u: goto label_1e4430;
            case 0x1E4444u: goto label_1e4444;
            case 0x1E4460u: goto label_1e4460;
            case 0x1E44C8u: goto label_1e44c8;
            case 0x1E44DCu: goto label_1e44dc;
            case 0x1E451Cu: goto label_1e451c;
            case 0x1E452Cu: goto label_1e452c;
            case 0x1E4550u: goto label_1e4550;
            case 0x1E4560u: goto label_1e4560;
            case 0x1E4584u: goto label_1e4584;
            case 0x1E4598u: goto label_1e4598;
            case 0x1E460Cu: goto label_1e460c;
            case 0x1E4628u: goto label_1e4628;
            case 0x1E463Cu: goto label_1e463c;
            case 0x1E4658u: goto label_1e4658;
            case 0x1E46C8u: goto label_1e46c8;
            case 0x1E46DCu: goto label_1e46dc;
            case 0x1E471Cu: goto label_1e471c;
            case 0x1E472Cu: goto label_1e472c;
            case 0x1E4750u: goto label_1e4750;
            case 0x1E4764u: goto label_1e4764;
            case 0x1E4788u: goto label_1e4788;
            case 0x1E479Cu: goto label_1e479c;
            case 0x1E47B0u: goto label_1e47b0;
            case 0x1E47E0u: goto label_1e47e0;
            case 0x1E47FCu: goto label_1e47fc;
            case 0x1E4800u: goto label_1e4800;
            case 0x1E48A0u: goto label_1e48a0;
            case 0x1E48B4u: goto label_1e48b4;
            case 0x1E48F4u: goto label_1e48f4;
            case 0x1E4918u: goto label_1e4918;
            case 0x1E493Cu: goto label_1e493c;
            case 0x1E4974u: goto label_1e4974;
            case 0x1E4998u: goto label_1e4998;
            case 0x1E49ACu: goto label_1e49ac;
            case 0x1E4A08u: goto label_1e4a08;
            case 0x1E4A24u: goto label_1e4a24;
            case 0x1E4AACu: goto label_1e4aac;
            case 0x1E4AC0u: goto label_1e4ac0;
            case 0x1E4B00u: goto label_1e4b00;
            case 0x1E4B1Cu: goto label_1e4b1c;
            case 0x1E4B20u: goto label_1e4b20;
            case 0x1E4B94u: goto label_1e4b94;
            case 0x1E4BA8u: goto label_1e4ba8;
            case 0x1E4BE8u: goto label_1e4be8;
            case 0x1E4C10u: goto label_1e4c10;
            case 0x1E4C34u: goto label_1e4c34;
            case 0x1E4C64u: goto label_1e4c64;
            case 0x1E4C88u: goto label_1e4c88;
            case 0x1E4C9Cu: goto label_1e4c9c;
            case 0x1E4D08u: goto label_1e4d08;
            case 0x1E4D28u: goto label_1e4d28;
            case 0x1E4DE4u: goto label_1e4de4;
            case 0x1E4DF8u: goto label_1e4df8;
            case 0x1E4E3Cu: goto label_1e4e3c;
            case 0x1E4E58u: goto label_1e4e58;
            case 0x1E4E5Cu: goto label_1e4e5c;
            case 0x1E4EC4u: goto label_1e4ec4;
            case 0x1E4ED8u: goto label_1e4ed8;
            case 0x1E4F18u: goto label_1e4f18;
            case 0x1E4F28u: goto label_1e4f28;
            case 0x1E4F4Cu: goto label_1e4f4c;
            case 0x1E4F60u: goto label_1e4f60;
            case 0x1E4F84u: goto label_1e4f84;
            case 0x1E4F98u: goto label_1e4f98;
            case 0x1E4FACu: goto label_1e4fac;
            case 0x1E4FD0u: goto label_1e4fd0;
            case 0x1E4FECu: goto label_1e4fec;
            case 0x1E4FF0u: goto label_1e4ff0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E2EACu;
    // 0x1e2eac: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1e2eacu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1e2eb0: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1e2eb0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1e2eb4: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1e2eb4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1e2eb8: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e2eb8u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e2ebc: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e2ebcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e2ec0: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e2ec0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e2ec4: 0xafc0000c  sw          $zero, 0xC($fp)
    ctx->pc = 0x1e2ec4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 0));
    // 0x1e2ec8: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e2ec8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e2ecc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e2eccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e2ed0: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E2ED0u;
    {
        const bool branch_taken_0x1e2ed0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e2ed0) {
            ctx->pc = 0x1E2EF8u;
            goto label_1e2ef8;
        }
    }
    ctx->pc = 0x1E2ED8u;
    // 0x1e2ed8: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e2ed8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e2edc: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e2edcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e2ee0: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e2ee0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e2ee4: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e2ee4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e2ee8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e2ee8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e2eec: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e2eecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e2ef0: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E2EF0u;
    {
        const bool branch_taken_0x1e2ef0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e2ef0) {
            ctx->pc = 0x1E2F0Cu;
            goto label_1e2f0c;
        }
    }
    ctx->pc = 0x1E2EF8u;
label_1e2ef8:
    // 0x1e2ef8: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e2ef8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e2efc: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e2efcu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e2f00: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e2f00u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e2f04: 0x1000003b  b           . + 4 + (0x3B << 2)
    ctx->pc = 0x1E2F04u;
    {
        const bool branch_taken_0x1e2f04 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e2f04) {
            ctx->pc = 0x1E2FF4u;
            goto label_1e2ff4;
        }
    }
    ctx->pc = 0x1E2F0Cu;
label_1e2f0c:
    // 0x1e2f0c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e2f0cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e2f10: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e2f10u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e2f14: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e2f14u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e2f18: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e2f18u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e2f1c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e2f1cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e2f20: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e2f20u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e2f24: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1e2f24u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1e2f28: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e2f28u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e2f2c: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e2f2cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e2f30: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E2F30u;
    {
        const bool branch_taken_0x1e2f30 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e2f30) {
            ctx->pc = 0x1E2F4Cu;
            goto label_1e2f4c;
        }
    }
    ctx->pc = 0x1E2F38u;
    // 0x1e2f38: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e2f38u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e2f3c: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e2f3cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e2f40: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e2f40u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e2f44: 0x1000002b  b           . + 4 + (0x2B << 2)
    ctx->pc = 0x1E2F44u;
    {
        const bool branch_taken_0x1e2f44 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e2f44) {
            ctx->pc = 0x1E2FF4u;
            goto label_1e2ff4;
        }
    }
    ctx->pc = 0x1E2F4Cu;
label_1e2f4c:
    // 0x1e2f4c: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1e2f4cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e2f50: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1e2f50u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e2f54: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E2F54u;
    SET_GPR_U32(ctx, 31, 0x1E2F5Cu);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2F5Cu; }
        if (ctx->pc != 0x1E2F5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2F5Cu; }
        if (ctx->pc != 0x1E2F5Cu) { return; }
    }
    ctx->pc = 0x1E2F5Cu;
label_1e2f5c:
    // 0x1e2f5c: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1e2f5cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1e2f60: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1e2f60u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e2f64: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E2F64u;
    {
        const bool branch_taken_0x1e2f64 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e2f64) {
            ctx->pc = 0x1E2F80u;
            goto label_1e2f80;
        }
    }
    ctx->pc = 0x1E2F6Cu;
    // 0x1e2f6c: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e2f6cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e2f70: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e2f70u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e2f74: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e2f74u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e2f78: 0x1000001e  b           . + 4 + (0x1E << 2)
    ctx->pc = 0x1E2F78u;
    {
        const bool branch_taken_0x1e2f78 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e2f78) {
            ctx->pc = 0x1E2FF4u;
            goto label_1e2ff4;
        }
    }
    ctx->pc = 0x1E2F80u;
label_1e2f80:
    // 0x1e2f80: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e2f80u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e2f84: 0x9042061a  lbu         $v0, 0x61A($v0)
    ctx->pc = 0x1e2f84u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 1562)));
    // 0x1e2f88: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1e2f88u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e2f8c: 0x8fc50008  lw          $a1, 0x8($fp)
    ctx->pc = 0x1e2f8cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e2f90: 0x3406b000  ori         $a2, $zero, 0xB000
    ctx->pc = 0x1e2f90u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)45056);
    // 0x1e2f94: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1e2f94u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e2f98: 0x24080007  addiu       $t0, $zero, 0x7
    ctx->pc = 0x1e2f98u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1e2f9c: 0x40482d  daddu       $t1, $v0, $zero
    ctx->pc = 0x1e2f9cu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e2fa0: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E2FA0u;
    SET_GPR_U32(ctx, 31, 0x1E2FA8u);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2FA8u; }
        if (ctx->pc != 0x1E2FA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2FA8u; }
        if (ctx->pc != 0x1E2FA8u) { return; }
    }
    ctx->pc = 0x1E2FA8u;
label_1e2fa8:
    // 0x1e2fa8: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E2FA8u;
    {
        const bool branch_taken_0x1e2fa8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e2fa8) {
            ctx->pc = 0x1E2FC4u;
            goto label_1e2fc4;
        }
    }
    ctx->pc = 0x1E2FB0u;
    // 0x1e2fb0: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e2fb0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e2fb4: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e2fb4u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e2fb8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e2fb8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e2fbc: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1E2FBCu;
    {
        const bool branch_taken_0x1e2fbc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e2fbc) {
            ctx->pc = 0x1E2FF4u;
            goto label_1e2ff4;
        }
    }
    ctx->pc = 0x1E2FC4u;
label_1e2fc4:
    // 0x1e2fc4: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1e2fc4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e2fc8: 0x24050023  addiu       $a1, $zero, 0x23
    ctx->pc = 0x1e2fc8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 35));
    // 0x1e2fcc: 0x8fc60004  lw          $a2, 0x4($fp)
    ctx->pc = 0x1e2fccu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e2fd0: 0xc076ad5  jal         func_1DAB54
    ctx->pc = 0x1E2FD0u;
    SET_GPR_U32(ctx, 31, 0x1E2FD8u);
    ctx->pc = 0x1DAB54u;
    if (runtime->hasFunction(0x1DAB54u)) {
        auto targetFn = runtime->lookupFunction(0x1DAB54u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2FD8u; }
        if (ctx->pc != 0x1E2FD8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DAB54_0x1dab54(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2FD8u; }
        if (ctx->pc != 0x1E2FD8u) { return; }
    }
    ctx->pc = 0x1E2FD8u;
label_1e2fd8:
    // 0x1e2fd8: 0x8fc3000c  lw          $v1, 0xC($fp)
    ctx->pc = 0x1e2fd8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e2fdc: 0x9064061a  lbu         $a0, 0x61A($v1)
    ctx->pc = 0x1e2fdcu;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 1562)));
    // 0x1e2fe0: 0x24820001  addiu       $v0, $a0, 0x1
    ctx->pc = 0x1e2fe0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1e2fe4: 0xa062061a  sb          $v0, 0x61A($v1)
    ctx->pc = 0x1e2fe4u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 1562), (uint8_t)GPR_U32(ctx, 2));
    // 0x1e2fe8: 0x308200ff  andi        $v0, $a0, 0xFF
    ctx->pc = 0x1e2fe8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x1e2fec: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1e2fecu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1e2ff0: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e2ff0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
label_1e2ff4:
    // 0x1e2ff4: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e2ff4u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e2ff8: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1e2ff8u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1e2ffc: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1e2ffcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1e3000: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1e3000u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1e3004: 0x3e00008  jr          $ra
    ctx->pc = 0x1E3004u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E1B3Cu: goto label_1e1b3c;
            case 0x1E1B60u: goto label_1e1b60;
            case 0x1E1B84u: goto label_1e1b84;
            case 0x1E1BA8u: goto label_1e1ba8;
            case 0x1E1BC8u: goto label_1e1bc8;
            case 0x1E1BE4u: goto label_1e1be4;
            case 0x1E1BE8u: goto label_1e1be8;
            case 0x1E1C44u: goto label_1e1c44;
            case 0x1E1C58u: goto label_1e1c58;
            case 0x1E1C7Cu: goto label_1e1c7c;
            case 0x1E1CD8u: goto label_1e1cd8;
            case 0x1E1CECu: goto label_1e1cec;
            case 0x1E1D14u: goto label_1e1d14;
            case 0x1E1D7Cu: goto label_1e1d7c;
            case 0x1E1D90u: goto label_1e1d90;
            case 0x1E1DD0u: goto label_1e1dd0;
            case 0x1E1DE0u: goto label_1e1de0;
            case 0x1E1E04u: goto label_1e1e04;
            case 0x1E1E14u: goto label_1e1e14;
            case 0x1E1E38u: goto label_1e1e38;
            case 0x1E1E4Cu: goto label_1e1e4c;
            case 0x1E1E5Cu: goto label_1e1e5c;
            case 0x1E1E84u: goto label_1e1e84;
            case 0x1E1EA0u: goto label_1e1ea0;
            case 0x1E1EB4u: goto label_1e1eb4;
            case 0x1E1ED0u: goto label_1e1ed0;
            case 0x1E1F48u: goto label_1e1f48;
            case 0x1E1F5Cu: goto label_1e1f5c;
            case 0x1E1F9Cu: goto label_1e1f9c;
            case 0x1E1FACu: goto label_1e1fac;
            case 0x1E1FD0u: goto label_1e1fd0;
            case 0x1E1FE0u: goto label_1e1fe0;
            case 0x1E2004u: goto label_1e2004;
            case 0x1E2018u: goto label_1e2018;
            case 0x1E202Cu: goto label_1e202c;
            case 0x1E2064u: goto label_1e2064;
            case 0x1E206Cu: goto label_1e206c;
            case 0x1E2088u: goto label_1e2088;
            case 0x1E20A0u: goto label_1e20a0;
            case 0x1E20D4u: goto label_1e20d4;
            case 0x1E20F8u: goto label_1e20f8;
            case 0x1E210Cu: goto label_1e210c;
            case 0x1E2128u: goto label_1e2128;
            case 0x1E2190u: goto label_1e2190;
            case 0x1E21A4u: goto label_1e21a4;
            case 0x1E21E4u: goto label_1e21e4;
            case 0x1E21F4u: goto label_1e21f4;
            case 0x1E2218u: goto label_1e2218;
            case 0x1E2228u: goto label_1e2228;
            case 0x1E224Cu: goto label_1e224c;
            case 0x1E2260u: goto label_1e2260;
            case 0x1E22D4u: goto label_1e22d4;
            case 0x1E22F0u: goto label_1e22f0;
            case 0x1E2304u: goto label_1e2304;
            case 0x1E2320u: goto label_1e2320;
            case 0x1E23A0u: goto label_1e23a0;
            case 0x1E23B4u: goto label_1e23b4;
            case 0x1E23F4u: goto label_1e23f4;
            case 0x1E2404u: goto label_1e2404;
            case 0x1E2428u: goto label_1e2428;
            case 0x1E2438u: goto label_1e2438;
            case 0x1E245Cu: goto label_1e245c;
            case 0x1E2470u: goto label_1e2470;
            case 0x1E2480u: goto label_1e2480;
            case 0x1E24F8u: goto label_1e24f8;
            case 0x1E2500u: goto label_1e2500;
            case 0x1E2508u: goto label_1e2508;
            case 0x1E25D0u: goto label_1e25d0;
            case 0x1E25ECu: goto label_1e25ec;
            case 0x1E2600u: goto label_1e2600;
            case 0x1E261Cu: goto label_1e261c;
            case 0x1E2684u: goto label_1e2684;
            case 0x1E2698u: goto label_1e2698;
            case 0x1E26D8u: goto label_1e26d8;
            case 0x1E26E8u: goto label_1e26e8;
            case 0x1E270Cu: goto label_1e270c;
            case 0x1E271Cu: goto label_1e271c;
            case 0x1E2740u: goto label_1e2740;
            case 0x1E2754u: goto label_1e2754;
            case 0x1E27C8u: goto label_1e27c8;
            case 0x1E27E4u: goto label_1e27e4;
            case 0x1E27F8u: goto label_1e27f8;
            case 0x1E2814u: goto label_1e2814;
            case 0x1E287Cu: goto label_1e287c;
            case 0x1E2890u: goto label_1e2890;
            case 0x1E28D0u: goto label_1e28d0;
            case 0x1E28E0u: goto label_1e28e0;
            case 0x1E2904u: goto label_1e2904;
            case 0x1E2914u: goto label_1e2914;
            case 0x1E2938u: goto label_1e2938;
            case 0x1E294Cu: goto label_1e294c;
            case 0x1E29C0u: goto label_1e29c0;
            case 0x1E29DCu: goto label_1e29dc;
            case 0x1E29F0u: goto label_1e29f0;
            case 0x1E2A0Cu: goto label_1e2a0c;
            case 0x1E2A78u: goto label_1e2a78;
            case 0x1E2A8Cu: goto label_1e2a8c;
            case 0x1E2ACCu: goto label_1e2acc;
            case 0x1E2ADCu: goto label_1e2adc;
            case 0x1E2B00u: goto label_1e2b00;
            case 0x1E2B10u: goto label_1e2b10;
            case 0x1E2B34u: goto label_1e2b34;
            case 0x1E2B48u: goto label_1e2b48;
            case 0x1E2B54u: goto label_1e2b54;
            case 0x1E2B90u: goto label_1e2b90;
            case 0x1E2B98u: goto label_1e2b98;
            case 0x1E2BC0u: goto label_1e2bc0;
            case 0x1E2BE4u: goto label_1e2be4;
            case 0x1E2BF8u: goto label_1e2bf8;
            case 0x1E2C14u: goto label_1e2c14;
            case 0x1E2C84u: goto label_1e2c84;
            case 0x1E2C98u: goto label_1e2c98;
            case 0x1E2CD8u: goto label_1e2cd8;
            case 0x1E2CE8u: goto label_1e2ce8;
            case 0x1E2D0Cu: goto label_1e2d0c;
            case 0x1E2D1Cu: goto label_1e2d1c;
            case 0x1E2D40u: goto label_1e2d40;
            case 0x1E2D54u: goto label_1e2d54;
            case 0x1E2E10u: goto label_1e2e10;
            case 0x1E2E18u: goto label_1e2e18;
            case 0x1E2E20u: goto label_1e2e20;
            case 0x1E2E48u: goto label_1e2e48;
            case 0x1E2E64u: goto label_1e2e64;
            case 0x1E2E78u: goto label_1e2e78;
            case 0x1E2E94u: goto label_1e2e94;
            case 0x1E2EF8u: goto label_1e2ef8;
            case 0x1E2F0Cu: goto label_1e2f0c;
            case 0x1E2F4Cu: goto label_1e2f4c;
            case 0x1E2F5Cu: goto label_1e2f5c;
            case 0x1E2F80u: goto label_1e2f80;
            case 0x1E2FA8u: goto label_1e2fa8;
            case 0x1E2FC4u: goto label_1e2fc4;
            case 0x1E2FD8u: goto label_1e2fd8;
            case 0x1E2FF4u: goto label_1e2ff4;
            case 0x1E3058u: goto label_1e3058;
            case 0x1E306Cu: goto label_1e306c;
            case 0x1E30ACu: goto label_1e30ac;
            case 0x1E30BCu: goto label_1e30bc;
            case 0x1E30E0u: goto label_1e30e0;
            case 0x1E3108u: goto label_1e3108;
            case 0x1E3124u: goto label_1e3124;
            case 0x1E3138u: goto label_1e3138;
            case 0x1E3154u: goto label_1e3154;
            case 0x1E31CCu: goto label_1e31cc;
            case 0x1E31E0u: goto label_1e31e0;
            case 0x1E3220u: goto label_1e3220;
            case 0x1E3238u: goto label_1e3238;
            case 0x1E325Cu: goto label_1e325c;
            case 0x1E3278u: goto label_1e3278;
            case 0x1E329Cu: goto label_1e329c;
            case 0x1E32B0u: goto label_1e32b0;
            case 0x1E3318u: goto label_1e3318;
            case 0x1E3388u: goto label_1e3388;
            case 0x1E33C4u: goto label_1e33c4;
            case 0x1E33E0u: goto label_1e33e0;
            case 0x1E33F4u: goto label_1e33f4;
            case 0x1E3410u: goto label_1e3410;
            case 0x1E347Cu: goto label_1e347c;
            case 0x1E3490u: goto label_1e3490;
            case 0x1E34D0u: goto label_1e34d0;
            case 0x1E34E0u: goto label_1e34e0;
            case 0x1E3504u: goto label_1e3504;
            case 0x1E3514u: goto label_1e3514;
            case 0x1E3538u: goto label_1e3538;
            case 0x1E354Cu: goto label_1e354c;
            case 0x1E360Cu: goto label_1e360c;
            case 0x1E3628u: goto label_1e3628;
            case 0x1E363Cu: goto label_1e363c;
            case 0x1E3658u: goto label_1e3658;
            case 0x1E36C4u: goto label_1e36c4;
            case 0x1E36D8u: goto label_1e36d8;
            case 0x1E3718u: goto label_1e3718;
            case 0x1E3728u: goto label_1e3728;
            case 0x1E374Cu: goto label_1e374c;
            case 0x1E375Cu: goto label_1e375c;
            case 0x1E3780u: goto label_1e3780;
            case 0x1E3794u: goto label_1e3794;
            case 0x1E3854u: goto label_1e3854;
            case 0x1E3870u: goto label_1e3870;
            case 0x1E3884u: goto label_1e3884;
            case 0x1E38A0u: goto label_1e38a0;
            case 0x1E3908u: goto label_1e3908;
            case 0x1E391Cu: goto label_1e391c;
            case 0x1E395Cu: goto label_1e395c;
            case 0x1E396Cu: goto label_1e396c;
            case 0x1E3990u: goto label_1e3990;
            case 0x1E39A0u: goto label_1e39a0;
            case 0x1E39C4u: goto label_1e39c4;
            case 0x1E39D8u: goto label_1e39d8;
            case 0x1E3A44u: goto label_1e3a44;
            case 0x1E3A60u: goto label_1e3a60;
            case 0x1E3A74u: goto label_1e3a74;
            case 0x1E3A78u: goto label_1e3a78;
            case 0x1E3ADCu: goto label_1e3adc;
            case 0x1E3AF0u: goto label_1e3af0;
            case 0x1E3B30u: goto label_1e3b30;
            case 0x1E3B40u: goto label_1e3b40;
            case 0x1E3B64u: goto label_1e3b64;
            case 0x1E3B84u: goto label_1e3b84;
            case 0x1E3BA0u: goto label_1e3ba0;
            case 0x1E3BB4u: goto label_1e3bb4;
            case 0x1E3BB8u: goto label_1e3bb8;
            case 0x1E3C1Cu: goto label_1e3c1c;
            case 0x1E3C30u: goto label_1e3c30;
            case 0x1E3C70u: goto label_1e3c70;
            case 0x1E3C80u: goto label_1e3c80;
            case 0x1E3CA4u: goto label_1e3ca4;
            case 0x1E3CC4u: goto label_1e3cc4;
            case 0x1E3CE8u: goto label_1e3ce8;
            case 0x1E3CFCu: goto label_1e3cfc;
            case 0x1E3D00u: goto label_1e3d00;
            case 0x1E3D68u: goto label_1e3d68;
            case 0x1E3D7Cu: goto label_1e3d7c;
            case 0x1E3DBCu: goto label_1e3dbc;
            case 0x1E3DCCu: goto label_1e3dcc;
            case 0x1E3DF0u: goto label_1e3df0;
            case 0x1E3E00u: goto label_1e3e00;
            case 0x1E3E24u: goto label_1e3e24;
            case 0x1E3E38u: goto label_1e3e38;
            case 0x1E3EA4u: goto label_1e3ea4;
            case 0x1E3EC0u: goto label_1e3ec0;
            case 0x1E3ED4u: goto label_1e3ed4;
            case 0x1E3ED8u: goto label_1e3ed8;
            case 0x1E3F40u: goto label_1e3f40;
            case 0x1E3F54u: goto label_1e3f54;
            case 0x1E3F94u: goto label_1e3f94;
            case 0x1E3FA4u: goto label_1e3fa4;
            case 0x1E3FC8u: goto label_1e3fc8;
            case 0x1E3FD8u: goto label_1e3fd8;
            case 0x1E3FFCu: goto label_1e3ffc;
            case 0x1E4010u: goto label_1e4010;
            case 0x1E407Cu: goto label_1e407c;
            case 0x1E4098u: goto label_1e4098;
            case 0x1E40ACu: goto label_1e40ac;
            case 0x1E40B0u: goto label_1e40b0;
            case 0x1E4118u: goto label_1e4118;
            case 0x1E412Cu: goto label_1e412c;
            case 0x1E416Cu: goto label_1e416c;
            case 0x1E417Cu: goto label_1e417c;
            case 0x1E41A0u: goto label_1e41a0;
            case 0x1E41B0u: goto label_1e41b0;
            case 0x1E41D4u: goto label_1e41d4;
            case 0x1E41E8u: goto label_1e41e8;
            case 0x1E4254u: goto label_1e4254;
            case 0x1E4270u: goto label_1e4270;
            case 0x1E4284u: goto label_1e4284;
            case 0x1E4288u: goto label_1e4288;
            case 0x1E42F0u: goto label_1e42f0;
            case 0x1E4304u: goto label_1e4304;
            case 0x1E4344u: goto label_1e4344;
            case 0x1E4358u: goto label_1e4358;
            case 0x1E437Cu: goto label_1e437c;
            case 0x1E4394u: goto label_1e4394;
            case 0x1E43B8u: goto label_1e43b8;
            case 0x1E43CCu: goto label_1e43cc;
            case 0x1E43E4u: goto label_1e43e4;
            case 0x1E4414u: goto label_1e4414;
            case 0x1E4430u: goto label_1e4430;
            case 0x1E4444u: goto label_1e4444;
            case 0x1E4460u: goto label_1e4460;
            case 0x1E44C8u: goto label_1e44c8;
            case 0x1E44DCu: goto label_1e44dc;
            case 0x1E451Cu: goto label_1e451c;
            case 0x1E452Cu: goto label_1e452c;
            case 0x1E4550u: goto label_1e4550;
            case 0x1E4560u: goto label_1e4560;
            case 0x1E4584u: goto label_1e4584;
            case 0x1E4598u: goto label_1e4598;
            case 0x1E460Cu: goto label_1e460c;
            case 0x1E4628u: goto label_1e4628;
            case 0x1E463Cu: goto label_1e463c;
            case 0x1E4658u: goto label_1e4658;
            case 0x1E46C8u: goto label_1e46c8;
            case 0x1E46DCu: goto label_1e46dc;
            case 0x1E471Cu: goto label_1e471c;
            case 0x1E472Cu: goto label_1e472c;
            case 0x1E4750u: goto label_1e4750;
            case 0x1E4764u: goto label_1e4764;
            case 0x1E4788u: goto label_1e4788;
            case 0x1E479Cu: goto label_1e479c;
            case 0x1E47B0u: goto label_1e47b0;
            case 0x1E47E0u: goto label_1e47e0;
            case 0x1E47FCu: goto label_1e47fc;
            case 0x1E4800u: goto label_1e4800;
            case 0x1E48A0u: goto label_1e48a0;
            case 0x1E48B4u: goto label_1e48b4;
            case 0x1E48F4u: goto label_1e48f4;
            case 0x1E4918u: goto label_1e4918;
            case 0x1E493Cu: goto label_1e493c;
            case 0x1E4974u: goto label_1e4974;
            case 0x1E4998u: goto label_1e4998;
            case 0x1E49ACu: goto label_1e49ac;
            case 0x1E4A08u: goto label_1e4a08;
            case 0x1E4A24u: goto label_1e4a24;
            case 0x1E4AACu: goto label_1e4aac;
            case 0x1E4AC0u: goto label_1e4ac0;
            case 0x1E4B00u: goto label_1e4b00;
            case 0x1E4B1Cu: goto label_1e4b1c;
            case 0x1E4B20u: goto label_1e4b20;
            case 0x1E4B94u: goto label_1e4b94;
            case 0x1E4BA8u: goto label_1e4ba8;
            case 0x1E4BE8u: goto label_1e4be8;
            case 0x1E4C10u: goto label_1e4c10;
            case 0x1E4C34u: goto label_1e4c34;
            case 0x1E4C64u: goto label_1e4c64;
            case 0x1E4C88u: goto label_1e4c88;
            case 0x1E4C9Cu: goto label_1e4c9c;
            case 0x1E4D08u: goto label_1e4d08;
            case 0x1E4D28u: goto label_1e4d28;
            case 0x1E4DE4u: goto label_1e4de4;
            case 0x1E4DF8u: goto label_1e4df8;
            case 0x1E4E3Cu: goto label_1e4e3c;
            case 0x1E4E58u: goto label_1e4e58;
            case 0x1E4E5Cu: goto label_1e4e5c;
            case 0x1E4EC4u: goto label_1e4ec4;
            case 0x1E4ED8u: goto label_1e4ed8;
            case 0x1E4F18u: goto label_1e4f18;
            case 0x1E4F28u: goto label_1e4f28;
            case 0x1E4F4Cu: goto label_1e4f4c;
            case 0x1E4F60u: goto label_1e4f60;
            case 0x1E4F84u: goto label_1e4f84;
            case 0x1E4F98u: goto label_1e4f98;
            case 0x1E4FACu: goto label_1e4fac;
            case 0x1E4FD0u: goto label_1e4fd0;
            case 0x1E4FECu: goto label_1e4fec;
            case 0x1E4FF0u: goto label_1e4ff0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E300Cu;
    // 0x1e300c: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1e300cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1e3010: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1e3010u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1e3014: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1e3014u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1e3018: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e3018u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e301c: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e301cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e3020: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e3020u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e3024: 0xafc0000c  sw          $zero, 0xC($fp)
    ctx->pc = 0x1e3024u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 0));
    // 0x1e3028: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e3028u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e302c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e302cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e3030: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E3030u;
    {
        const bool branch_taken_0x1e3030 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e3030) {
            ctx->pc = 0x1E3058u;
            goto label_1e3058;
        }
    }
    ctx->pc = 0x1E3038u;
    // 0x1e3038: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e3038u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e303c: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e303cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e3040: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e3040u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e3044: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e3044u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e3048: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e3048u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e304c: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e304cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e3050: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E3050u;
    {
        const bool branch_taken_0x1e3050 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e3050) {
            ctx->pc = 0x1E306Cu;
            goto label_1e306c;
        }
    }
    ctx->pc = 0x1E3058u;
label_1e3058:
    // 0x1e3058: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e3058u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e305c: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e305cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e3060: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e3060u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e3064: 0x1000003b  b           . + 4 + (0x3B << 2)
    ctx->pc = 0x1E3064u;
    {
        const bool branch_taken_0x1e3064 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3064) {
            ctx->pc = 0x1E3154u;
            goto label_1e3154;
        }
    }
    ctx->pc = 0x1E306Cu;
label_1e306c:
    // 0x1e306c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e306cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e3070: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e3070u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e3074: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e3074u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e3078: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e3078u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e307c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e307cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e3080: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e3080u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e3084: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1e3084u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1e3088: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e3088u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e308c: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e308cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e3090: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E3090u;
    {
        const bool branch_taken_0x1e3090 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3090) {
            ctx->pc = 0x1E30ACu;
            goto label_1e30ac;
        }
    }
    ctx->pc = 0x1E3098u;
    // 0x1e3098: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e3098u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e309c: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e309cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e30a0: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e30a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e30a4: 0x1000002b  b           . + 4 + (0x2B << 2)
    ctx->pc = 0x1E30A4u;
    {
        const bool branch_taken_0x1e30a4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e30a4) {
            ctx->pc = 0x1E3154u;
            goto label_1e3154;
        }
    }
    ctx->pc = 0x1E30ACu;
label_1e30ac:
    // 0x1e30ac: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1e30acu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e30b0: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1e30b0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e30b4: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E30B4u;
    SET_GPR_U32(ctx, 31, 0x1E30BCu);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E30BCu; }
        if (ctx->pc != 0x1E30BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E30BCu; }
        if (ctx->pc != 0x1E30BCu) { return; }
    }
    ctx->pc = 0x1E30BCu;
label_1e30bc:
    // 0x1e30bc: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1e30bcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1e30c0: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1e30c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e30c4: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E30C4u;
    {
        const bool branch_taken_0x1e30c4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e30c4) {
            ctx->pc = 0x1E30E0u;
            goto label_1e30e0;
        }
    }
    ctx->pc = 0x1E30CCu;
    // 0x1e30cc: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e30ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e30d0: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e30d0u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e30d4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e30d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e30d8: 0x1000001e  b           . + 4 + (0x1E << 2)
    ctx->pc = 0x1E30D8u;
    {
        const bool branch_taken_0x1e30d8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e30d8) {
            ctx->pc = 0x1E3154u;
            goto label_1e3154;
        }
    }
    ctx->pc = 0x1E30E0u;
label_1e30e0:
    // 0x1e30e0: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e30e0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e30e4: 0x9042061b  lbu         $v0, 0x61B($v0)
    ctx->pc = 0x1e30e4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 1563)));
    // 0x1e30e8: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1e30e8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e30ec: 0x8fc50008  lw          $a1, 0x8($fp)
    ctx->pc = 0x1e30ecu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e30f0: 0x3406a000  ori         $a2, $zero, 0xA000
    ctx->pc = 0x1e30f0u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)40960);
    // 0x1e30f4: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1e30f4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e30f8: 0x24080007  addiu       $t0, $zero, 0x7
    ctx->pc = 0x1e30f8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1e30fc: 0x40482d  daddu       $t1, $v0, $zero
    ctx->pc = 0x1e30fcu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e3100: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E3100u;
    SET_GPR_U32(ctx, 31, 0x1E3108u);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3108u; }
        if (ctx->pc != 0x1E3108u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3108u; }
        if (ctx->pc != 0x1E3108u) { return; }
    }
    ctx->pc = 0x1E3108u;
label_1e3108:
    // 0x1e3108: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E3108u;
    {
        const bool branch_taken_0x1e3108 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3108) {
            ctx->pc = 0x1E3124u;
            goto label_1e3124;
        }
    }
    ctx->pc = 0x1E3110u;
    // 0x1e3110: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e3110u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e3114: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e3114u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e3118: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e3118u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e311c: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1E311Cu;
    {
        const bool branch_taken_0x1e311c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e311c) {
            ctx->pc = 0x1E3154u;
            goto label_1e3154;
        }
    }
    ctx->pc = 0x1E3124u;
label_1e3124:
    // 0x1e3124: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1e3124u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e3128: 0x24050024  addiu       $a1, $zero, 0x24
    ctx->pc = 0x1e3128u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 36));
    // 0x1e312c: 0x8fc60004  lw          $a2, 0x4($fp)
    ctx->pc = 0x1e312cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e3130: 0xc076ad5  jal         func_1DAB54
    ctx->pc = 0x1E3130u;
    SET_GPR_U32(ctx, 31, 0x1E3138u);
    ctx->pc = 0x1DAB54u;
    if (runtime->hasFunction(0x1DAB54u)) {
        auto targetFn = runtime->lookupFunction(0x1DAB54u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3138u; }
        if (ctx->pc != 0x1E3138u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DAB54_0x1dab54(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3138u; }
        if (ctx->pc != 0x1E3138u) { return; }
    }
    ctx->pc = 0x1E3138u;
label_1e3138:
    // 0x1e3138: 0x8fc3000c  lw          $v1, 0xC($fp)
    ctx->pc = 0x1e3138u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e313c: 0x9064061b  lbu         $a0, 0x61B($v1)
    ctx->pc = 0x1e313cu;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 1563)));
    // 0x1e3140: 0x24820001  addiu       $v0, $a0, 0x1
    ctx->pc = 0x1e3140u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1e3144: 0xa062061b  sb          $v0, 0x61B($v1)
    ctx->pc = 0x1e3144u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 1563), (uint8_t)GPR_U32(ctx, 2));
    // 0x1e3148: 0x308200ff  andi        $v0, $a0, 0xFF
    ctx->pc = 0x1e3148u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x1e314c: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1e314cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1e3150: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e3150u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
label_1e3154:
    // 0x1e3154: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e3154u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e3158: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1e3158u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1e315c: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1e315cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1e3160: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1e3160u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1e3164: 0x3e00008  jr          $ra
    ctx->pc = 0x1E3164u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E1B3Cu: goto label_1e1b3c;
            case 0x1E1B60u: goto label_1e1b60;
            case 0x1E1B84u: goto label_1e1b84;
            case 0x1E1BA8u: goto label_1e1ba8;
            case 0x1E1BC8u: goto label_1e1bc8;
            case 0x1E1BE4u: goto label_1e1be4;
            case 0x1E1BE8u: goto label_1e1be8;
            case 0x1E1C44u: goto label_1e1c44;
            case 0x1E1C58u: goto label_1e1c58;
            case 0x1E1C7Cu: goto label_1e1c7c;
            case 0x1E1CD8u: goto label_1e1cd8;
            case 0x1E1CECu: goto label_1e1cec;
            case 0x1E1D14u: goto label_1e1d14;
            case 0x1E1D7Cu: goto label_1e1d7c;
            case 0x1E1D90u: goto label_1e1d90;
            case 0x1E1DD0u: goto label_1e1dd0;
            case 0x1E1DE0u: goto label_1e1de0;
            case 0x1E1E04u: goto label_1e1e04;
            case 0x1E1E14u: goto label_1e1e14;
            case 0x1E1E38u: goto label_1e1e38;
            case 0x1E1E4Cu: goto label_1e1e4c;
            case 0x1E1E5Cu: goto label_1e1e5c;
            case 0x1E1E84u: goto label_1e1e84;
            case 0x1E1EA0u: goto label_1e1ea0;
            case 0x1E1EB4u: goto label_1e1eb4;
            case 0x1E1ED0u: goto label_1e1ed0;
            case 0x1E1F48u: goto label_1e1f48;
            case 0x1E1F5Cu: goto label_1e1f5c;
            case 0x1E1F9Cu: goto label_1e1f9c;
            case 0x1E1FACu: goto label_1e1fac;
            case 0x1E1FD0u: goto label_1e1fd0;
            case 0x1E1FE0u: goto label_1e1fe0;
            case 0x1E2004u: goto label_1e2004;
            case 0x1E2018u: goto label_1e2018;
            case 0x1E202Cu: goto label_1e202c;
            case 0x1E2064u: goto label_1e2064;
            case 0x1E206Cu: goto label_1e206c;
            case 0x1E2088u: goto label_1e2088;
            case 0x1E20A0u: goto label_1e20a0;
            case 0x1E20D4u: goto label_1e20d4;
            case 0x1E20F8u: goto label_1e20f8;
            case 0x1E210Cu: goto label_1e210c;
            case 0x1E2128u: goto label_1e2128;
            case 0x1E2190u: goto label_1e2190;
            case 0x1E21A4u: goto label_1e21a4;
            case 0x1E21E4u: goto label_1e21e4;
            case 0x1E21F4u: goto label_1e21f4;
            case 0x1E2218u: goto label_1e2218;
            case 0x1E2228u: goto label_1e2228;
            case 0x1E224Cu: goto label_1e224c;
            case 0x1E2260u: goto label_1e2260;
            case 0x1E22D4u: goto label_1e22d4;
            case 0x1E22F0u: goto label_1e22f0;
            case 0x1E2304u: goto label_1e2304;
            case 0x1E2320u: goto label_1e2320;
            case 0x1E23A0u: goto label_1e23a0;
            case 0x1E23B4u: goto label_1e23b4;
            case 0x1E23F4u: goto label_1e23f4;
            case 0x1E2404u: goto label_1e2404;
            case 0x1E2428u: goto label_1e2428;
            case 0x1E2438u: goto label_1e2438;
            case 0x1E245Cu: goto label_1e245c;
            case 0x1E2470u: goto label_1e2470;
            case 0x1E2480u: goto label_1e2480;
            case 0x1E24F8u: goto label_1e24f8;
            case 0x1E2500u: goto label_1e2500;
            case 0x1E2508u: goto label_1e2508;
            case 0x1E25D0u: goto label_1e25d0;
            case 0x1E25ECu: goto label_1e25ec;
            case 0x1E2600u: goto label_1e2600;
            case 0x1E261Cu: goto label_1e261c;
            case 0x1E2684u: goto label_1e2684;
            case 0x1E2698u: goto label_1e2698;
            case 0x1E26D8u: goto label_1e26d8;
            case 0x1E26E8u: goto label_1e26e8;
            case 0x1E270Cu: goto label_1e270c;
            case 0x1E271Cu: goto label_1e271c;
            case 0x1E2740u: goto label_1e2740;
            case 0x1E2754u: goto label_1e2754;
            case 0x1E27C8u: goto label_1e27c8;
            case 0x1E27E4u: goto label_1e27e4;
            case 0x1E27F8u: goto label_1e27f8;
            case 0x1E2814u: goto label_1e2814;
            case 0x1E287Cu: goto label_1e287c;
            case 0x1E2890u: goto label_1e2890;
            case 0x1E28D0u: goto label_1e28d0;
            case 0x1E28E0u: goto label_1e28e0;
            case 0x1E2904u: goto label_1e2904;
            case 0x1E2914u: goto label_1e2914;
            case 0x1E2938u: goto label_1e2938;
            case 0x1E294Cu: goto label_1e294c;
            case 0x1E29C0u: goto label_1e29c0;
            case 0x1E29DCu: goto label_1e29dc;
            case 0x1E29F0u: goto label_1e29f0;
            case 0x1E2A0Cu: goto label_1e2a0c;
            case 0x1E2A78u: goto label_1e2a78;
            case 0x1E2A8Cu: goto label_1e2a8c;
            case 0x1E2ACCu: goto label_1e2acc;
            case 0x1E2ADCu: goto label_1e2adc;
            case 0x1E2B00u: goto label_1e2b00;
            case 0x1E2B10u: goto label_1e2b10;
            case 0x1E2B34u: goto label_1e2b34;
            case 0x1E2B48u: goto label_1e2b48;
            case 0x1E2B54u: goto label_1e2b54;
            case 0x1E2B90u: goto label_1e2b90;
            case 0x1E2B98u: goto label_1e2b98;
            case 0x1E2BC0u: goto label_1e2bc0;
            case 0x1E2BE4u: goto label_1e2be4;
            case 0x1E2BF8u: goto label_1e2bf8;
            case 0x1E2C14u: goto label_1e2c14;
            case 0x1E2C84u: goto label_1e2c84;
            case 0x1E2C98u: goto label_1e2c98;
            case 0x1E2CD8u: goto label_1e2cd8;
            case 0x1E2CE8u: goto label_1e2ce8;
            case 0x1E2D0Cu: goto label_1e2d0c;
            case 0x1E2D1Cu: goto label_1e2d1c;
            case 0x1E2D40u: goto label_1e2d40;
            case 0x1E2D54u: goto label_1e2d54;
            case 0x1E2E10u: goto label_1e2e10;
            case 0x1E2E18u: goto label_1e2e18;
            case 0x1E2E20u: goto label_1e2e20;
            case 0x1E2E48u: goto label_1e2e48;
            case 0x1E2E64u: goto label_1e2e64;
            case 0x1E2E78u: goto label_1e2e78;
            case 0x1E2E94u: goto label_1e2e94;
            case 0x1E2EF8u: goto label_1e2ef8;
            case 0x1E2F0Cu: goto label_1e2f0c;
            case 0x1E2F4Cu: goto label_1e2f4c;
            case 0x1E2F5Cu: goto label_1e2f5c;
            case 0x1E2F80u: goto label_1e2f80;
            case 0x1E2FA8u: goto label_1e2fa8;
            case 0x1E2FC4u: goto label_1e2fc4;
            case 0x1E2FD8u: goto label_1e2fd8;
            case 0x1E2FF4u: goto label_1e2ff4;
            case 0x1E3058u: goto label_1e3058;
            case 0x1E306Cu: goto label_1e306c;
            case 0x1E30ACu: goto label_1e30ac;
            case 0x1E30BCu: goto label_1e30bc;
            case 0x1E30E0u: goto label_1e30e0;
            case 0x1E3108u: goto label_1e3108;
            case 0x1E3124u: goto label_1e3124;
            case 0x1E3138u: goto label_1e3138;
            case 0x1E3154u: goto label_1e3154;
            case 0x1E31CCu: goto label_1e31cc;
            case 0x1E31E0u: goto label_1e31e0;
            case 0x1E3220u: goto label_1e3220;
            case 0x1E3238u: goto label_1e3238;
            case 0x1E325Cu: goto label_1e325c;
            case 0x1E3278u: goto label_1e3278;
            case 0x1E329Cu: goto label_1e329c;
            case 0x1E32B0u: goto label_1e32b0;
            case 0x1E3318u: goto label_1e3318;
            case 0x1E3388u: goto label_1e3388;
            case 0x1E33C4u: goto label_1e33c4;
            case 0x1E33E0u: goto label_1e33e0;
            case 0x1E33F4u: goto label_1e33f4;
            case 0x1E3410u: goto label_1e3410;
            case 0x1E347Cu: goto label_1e347c;
            case 0x1E3490u: goto label_1e3490;
            case 0x1E34D0u: goto label_1e34d0;
            case 0x1E34E0u: goto label_1e34e0;
            case 0x1E3504u: goto label_1e3504;
            case 0x1E3514u: goto label_1e3514;
            case 0x1E3538u: goto label_1e3538;
            case 0x1E354Cu: goto label_1e354c;
            case 0x1E360Cu: goto label_1e360c;
            case 0x1E3628u: goto label_1e3628;
            case 0x1E363Cu: goto label_1e363c;
            case 0x1E3658u: goto label_1e3658;
            case 0x1E36C4u: goto label_1e36c4;
            case 0x1E36D8u: goto label_1e36d8;
            case 0x1E3718u: goto label_1e3718;
            case 0x1E3728u: goto label_1e3728;
            case 0x1E374Cu: goto label_1e374c;
            case 0x1E375Cu: goto label_1e375c;
            case 0x1E3780u: goto label_1e3780;
            case 0x1E3794u: goto label_1e3794;
            case 0x1E3854u: goto label_1e3854;
            case 0x1E3870u: goto label_1e3870;
            case 0x1E3884u: goto label_1e3884;
            case 0x1E38A0u: goto label_1e38a0;
            case 0x1E3908u: goto label_1e3908;
            case 0x1E391Cu: goto label_1e391c;
            case 0x1E395Cu: goto label_1e395c;
            case 0x1E396Cu: goto label_1e396c;
            case 0x1E3990u: goto label_1e3990;
            case 0x1E39A0u: goto label_1e39a0;
            case 0x1E39C4u: goto label_1e39c4;
            case 0x1E39D8u: goto label_1e39d8;
            case 0x1E3A44u: goto label_1e3a44;
            case 0x1E3A60u: goto label_1e3a60;
            case 0x1E3A74u: goto label_1e3a74;
            case 0x1E3A78u: goto label_1e3a78;
            case 0x1E3ADCu: goto label_1e3adc;
            case 0x1E3AF0u: goto label_1e3af0;
            case 0x1E3B30u: goto label_1e3b30;
            case 0x1E3B40u: goto label_1e3b40;
            case 0x1E3B64u: goto label_1e3b64;
            case 0x1E3B84u: goto label_1e3b84;
            case 0x1E3BA0u: goto label_1e3ba0;
            case 0x1E3BB4u: goto label_1e3bb4;
            case 0x1E3BB8u: goto label_1e3bb8;
            case 0x1E3C1Cu: goto label_1e3c1c;
            case 0x1E3C30u: goto label_1e3c30;
            case 0x1E3C70u: goto label_1e3c70;
            case 0x1E3C80u: goto label_1e3c80;
            case 0x1E3CA4u: goto label_1e3ca4;
            case 0x1E3CC4u: goto label_1e3cc4;
            case 0x1E3CE8u: goto label_1e3ce8;
            case 0x1E3CFCu: goto label_1e3cfc;
            case 0x1E3D00u: goto label_1e3d00;
            case 0x1E3D68u: goto label_1e3d68;
            case 0x1E3D7Cu: goto label_1e3d7c;
            case 0x1E3DBCu: goto label_1e3dbc;
            case 0x1E3DCCu: goto label_1e3dcc;
            case 0x1E3DF0u: goto label_1e3df0;
            case 0x1E3E00u: goto label_1e3e00;
            case 0x1E3E24u: goto label_1e3e24;
            case 0x1E3E38u: goto label_1e3e38;
            case 0x1E3EA4u: goto label_1e3ea4;
            case 0x1E3EC0u: goto label_1e3ec0;
            case 0x1E3ED4u: goto label_1e3ed4;
            case 0x1E3ED8u: goto label_1e3ed8;
            case 0x1E3F40u: goto label_1e3f40;
            case 0x1E3F54u: goto label_1e3f54;
            case 0x1E3F94u: goto label_1e3f94;
            case 0x1E3FA4u: goto label_1e3fa4;
            case 0x1E3FC8u: goto label_1e3fc8;
            case 0x1E3FD8u: goto label_1e3fd8;
            case 0x1E3FFCu: goto label_1e3ffc;
            case 0x1E4010u: goto label_1e4010;
            case 0x1E407Cu: goto label_1e407c;
            case 0x1E4098u: goto label_1e4098;
            case 0x1E40ACu: goto label_1e40ac;
            case 0x1E40B0u: goto label_1e40b0;
            case 0x1E4118u: goto label_1e4118;
            case 0x1E412Cu: goto label_1e412c;
            case 0x1E416Cu: goto label_1e416c;
            case 0x1E417Cu: goto label_1e417c;
            case 0x1E41A0u: goto label_1e41a0;
            case 0x1E41B0u: goto label_1e41b0;
            case 0x1E41D4u: goto label_1e41d4;
            case 0x1E41E8u: goto label_1e41e8;
            case 0x1E4254u: goto label_1e4254;
            case 0x1E4270u: goto label_1e4270;
            case 0x1E4284u: goto label_1e4284;
            case 0x1E4288u: goto label_1e4288;
            case 0x1E42F0u: goto label_1e42f0;
            case 0x1E4304u: goto label_1e4304;
            case 0x1E4344u: goto label_1e4344;
            case 0x1E4358u: goto label_1e4358;
            case 0x1E437Cu: goto label_1e437c;
            case 0x1E4394u: goto label_1e4394;
            case 0x1E43B8u: goto label_1e43b8;
            case 0x1E43CCu: goto label_1e43cc;
            case 0x1E43E4u: goto label_1e43e4;
            case 0x1E4414u: goto label_1e4414;
            case 0x1E4430u: goto label_1e4430;
            case 0x1E4444u: goto label_1e4444;
            case 0x1E4460u: goto label_1e4460;
            case 0x1E44C8u: goto label_1e44c8;
            case 0x1E44DCu: goto label_1e44dc;
            case 0x1E451Cu: goto label_1e451c;
            case 0x1E452Cu: goto label_1e452c;
            case 0x1E4550u: goto label_1e4550;
            case 0x1E4560u: goto label_1e4560;
            case 0x1E4584u: goto label_1e4584;
            case 0x1E4598u: goto label_1e4598;
            case 0x1E460Cu: goto label_1e460c;
            case 0x1E4628u: goto label_1e4628;
            case 0x1E463Cu: goto label_1e463c;
            case 0x1E4658u: goto label_1e4658;
            case 0x1E46C8u: goto label_1e46c8;
            case 0x1E46DCu: goto label_1e46dc;
            case 0x1E471Cu: goto label_1e471c;
            case 0x1E472Cu: goto label_1e472c;
            case 0x1E4750u: goto label_1e4750;
            case 0x1E4764u: goto label_1e4764;
            case 0x1E4788u: goto label_1e4788;
            case 0x1E479Cu: goto label_1e479c;
            case 0x1E47B0u: goto label_1e47b0;
            case 0x1E47E0u: goto label_1e47e0;
            case 0x1E47FCu: goto label_1e47fc;
            case 0x1E4800u: goto label_1e4800;
            case 0x1E48A0u: goto label_1e48a0;
            case 0x1E48B4u: goto label_1e48b4;
            case 0x1E48F4u: goto label_1e48f4;
            case 0x1E4918u: goto label_1e4918;
            case 0x1E493Cu: goto label_1e493c;
            case 0x1E4974u: goto label_1e4974;
            case 0x1E4998u: goto label_1e4998;
            case 0x1E49ACu: goto label_1e49ac;
            case 0x1E4A08u: goto label_1e4a08;
            case 0x1E4A24u: goto label_1e4a24;
            case 0x1E4AACu: goto label_1e4aac;
            case 0x1E4AC0u: goto label_1e4ac0;
            case 0x1E4B00u: goto label_1e4b00;
            case 0x1E4B1Cu: goto label_1e4b1c;
            case 0x1E4B20u: goto label_1e4b20;
            case 0x1E4B94u: goto label_1e4b94;
            case 0x1E4BA8u: goto label_1e4ba8;
            case 0x1E4BE8u: goto label_1e4be8;
            case 0x1E4C10u: goto label_1e4c10;
            case 0x1E4C34u: goto label_1e4c34;
            case 0x1E4C64u: goto label_1e4c64;
            case 0x1E4C88u: goto label_1e4c88;
            case 0x1E4C9Cu: goto label_1e4c9c;
            case 0x1E4D08u: goto label_1e4d08;
            case 0x1E4D28u: goto label_1e4d28;
            case 0x1E4DE4u: goto label_1e4de4;
            case 0x1E4DF8u: goto label_1e4df8;
            case 0x1E4E3Cu: goto label_1e4e3c;
            case 0x1E4E58u: goto label_1e4e58;
            case 0x1E4E5Cu: goto label_1e4e5c;
            case 0x1E4EC4u: goto label_1e4ec4;
            case 0x1E4ED8u: goto label_1e4ed8;
            case 0x1E4F18u: goto label_1e4f18;
            case 0x1E4F28u: goto label_1e4f28;
            case 0x1E4F4Cu: goto label_1e4f4c;
            case 0x1E4F60u: goto label_1e4f60;
            case 0x1E4F84u: goto label_1e4f84;
            case 0x1E4F98u: goto label_1e4f98;
            case 0x1E4FACu: goto label_1e4fac;
            case 0x1E4FD0u: goto label_1e4fd0;
            case 0x1E4FECu: goto label_1e4fec;
            case 0x1E4FF0u: goto label_1e4ff0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E316Cu;
    // 0x1e316c: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1e316cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1e3170: 0xffbe0030  sd          $fp, 0x30($sp)
    ctx->pc = 0x1e3170u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 30));
    // 0x1e3174: 0xffbf0038  sd          $ra, 0x38($sp)
    ctx->pc = 0x1e3174u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x1e3178: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e3178u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e317c: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e317cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e3180: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e3180u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e3184: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e3184u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e3188: 0xafc7000c  sw          $a3, 0xC($fp)
    ctx->pc = 0x1e3188u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 7));
    // 0x1e318c: 0x100102d  daddu       $v0, $t0, $zero
    ctx->pc = 0x1e318cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e3190: 0xafc90014  sw          $t1, 0x14($fp)
    ctx->pc = 0x1e3190u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 9));
    // 0x1e3194: 0xa7c20010  sh          $v0, 0x10($fp)
    ctx->pc = 0x1e3194u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 16), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e3198: 0xafc0001c  sw          $zero, 0x1C($fp)
    ctx->pc = 0x1e3198u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 0));
    // 0x1e319c: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e319cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e31a0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e31a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e31a4: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E31A4u;
    {
        const bool branch_taken_0x1e31a4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e31a4) {
            ctx->pc = 0x1E31CCu;
            goto label_1e31cc;
        }
    }
    ctx->pc = 0x1E31ACu;
    // 0x1e31ac: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e31acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e31b0: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e31b0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e31b4: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e31b4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e31b8: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e31b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e31bc: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e31bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e31c0: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e31c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e31c4: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E31C4u;
    {
        const bool branch_taken_0x1e31c4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e31c4) {
            ctx->pc = 0x1E31E0u;
            goto label_1e31e0;
        }
    }
    ctx->pc = 0x1E31CCu;
label_1e31cc:
    // 0x1e31cc: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e31ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e31d0: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e31d0u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e31d4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e31d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e31d8: 0x1000008d  b           . + 4 + (0x8D << 2)
    ctx->pc = 0x1E31D8u;
    {
        const bool branch_taken_0x1e31d8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e31d8) {
            ctx->pc = 0x1E3410u;
            goto label_1e3410;
        }
    }
    ctx->pc = 0x1E31E0u;
label_1e31e0:
    // 0x1e31e0: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e31e0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e31e4: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e31e4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e31e8: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e31e8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e31ec: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e31ecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e31f0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e31f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e31f4: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e31f4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e31f8: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1e31f8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1e31fc: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1e31fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e3200: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e3200u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e3204: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E3204u;
    {
        const bool branch_taken_0x1e3204 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3204) {
            ctx->pc = 0x1E3220u;
            goto label_1e3220;
        }
    }
    ctx->pc = 0x1E320Cu;
    // 0x1e320c: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e320cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e3210: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e3210u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e3214: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e3214u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e3218: 0x1000007d  b           . + 4 + (0x7D << 2)
    ctx->pc = 0x1E3218u;
    {
        const bool branch_taken_0x1e3218 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3218) {
            ctx->pc = 0x1E3410u;
            goto label_1e3410;
        }
    }
    ctx->pc = 0x1E3220u;
label_1e3220:
    // 0x1e3220: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e3220u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e3224: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1e3224u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1e3228: 0x8fc4001c  lw          $a0, 0x1C($fp)
    ctx->pc = 0x1e3228u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e322c: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1e322cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e3230: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E3230u;
    SET_GPR_U32(ctx, 31, 0x1E3238u);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3238u; }
        if (ctx->pc != 0x1E3238u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3238u; }
        if (ctx->pc != 0x1E3238u) { return; }
    }
    ctx->pc = 0x1E3238u;
label_1e3238:
    // 0x1e3238: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1e3238u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1e323c: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e323cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e3240: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E3240u;
    {
        const bool branch_taken_0x1e3240 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e3240) {
            ctx->pc = 0x1E325Cu;
            goto label_1e325c;
        }
    }
    ctx->pc = 0x1E3248u;
    // 0x1e3248: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e3248u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e324c: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e324cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e3250: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e3250u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e3254: 0x1000006e  b           . + 4 + (0x6E << 2)
    ctx->pc = 0x1E3254u;
    {
        const bool branch_taken_0x1e3254 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3254) {
            ctx->pc = 0x1E3410u;
            goto label_1e3410;
        }
    }
    ctx->pc = 0x1E325Cu;
label_1e325c:
    // 0x1e325c: 0x97c2000c  lhu         $v0, 0xC($fp)
    ctx->pc = 0x1e325cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e3260: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1e3260u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1e3264: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1e3264u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1e3268: 0x8fc40018  lw          $a0, 0x18($fp)
    ctx->pc = 0x1e3268u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e326c: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1e326cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e3270: 0xc07cc3c  jal         func_1F30F0
    ctx->pc = 0x1E3270u;
    SET_GPR_U32(ctx, 31, 0x1E3278u);
    ctx->pc = 0x1F30F0u;
    if (runtime->hasFunction(0x1F30F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F30F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3278u; }
        if (ctx->pc != 0x1E3278u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F30F0_0x1f30f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3278u; }
        if (ctx->pc != 0x1E3278u) { return; }
    }
    ctx->pc = 0x1E3278u;
label_1e3278:
    // 0x1e3278: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1e3278u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1e327c: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e327cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e3280: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1E3280u;
    {
        const bool branch_taken_0x1e3280 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e3280) {
            ctx->pc = 0x1E32B0u;
            goto label_1e32b0;
        }
    }
    ctx->pc = 0x1E3288u;
    // 0x1e3288: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1e3288u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e328c: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1e328cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1e3290: 0x8fc50018  lw          $a1, 0x18($fp)
    ctx->pc = 0x1e3290u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e3294: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1E3294u;
    SET_GPR_U32(ctx, 31, 0x1E329Cu);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E329Cu; }
        if (ctx->pc != 0x1E329Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E329Cu; }
        if (ctx->pc != 0x1E329Cu) { return; }
    }
    ctx->pc = 0x1E329Cu;
label_1e329c:
    // 0x1e329c: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e329cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e32a0: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e32a0u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e32a4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e32a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e32a8: 0x10000059  b           . + 4 + (0x59 << 2)
    ctx->pc = 0x1E32A8u;
    {
        const bool branch_taken_0x1e32a8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e32a8) {
            ctx->pc = 0x1E3410u;
            goto label_1e3410;
        }
    }
    ctx->pc = 0x1E32B0u;
label_1e32b0:
    // 0x1e32b0: 0x8fc50020  lw          $a1, 0x20($fp)
    ctx->pc = 0x1e32b0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e32b4: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e32b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e32b8: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1e32b8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1e32bc: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1e32bcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1e32c0: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e32c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e32c4: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1e32c4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1e32c8: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1e32c8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1e32cc: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1e32ccu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e32d0: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1e32d0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e32d4: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1e32d4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1e32d8: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e32d8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e32dc: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1e32dcu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1e32e0: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1e32e0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e32e4: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1e32e4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e32e8: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1e32e8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1e32ec: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e32ecu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e32f0: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1e32f0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1e32f4: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1e32f4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e32f8: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x1e32f8u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x1e32fc: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e32fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e3300: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1e3300u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1e3304: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1e3304u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e3308: 0x8fc50008  lw          $a1, 0x8($fp)
    ctx->pc = 0x1e3308u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e330c: 0x8fc6000c  lw          $a2, 0xC($fp)
    ctx->pc = 0x1e330cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e3310: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1E3310u;
    SET_GPR_U32(ctx, 31, 0x1E3318u);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3318u; }
        if (ctx->pc != 0x1E3318u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3318u; }
        if (ctx->pc != 0x1E3318u) { return; }
    }
    ctx->pc = 0x1E3318u;
label_1e3318:
    // 0x1e3318: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1e3318u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e331c: 0x3c024e41  lui         $v0, 0x4E41
    ctx->pc = 0x1e331cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)20033 << 16));
    // 0x1e3320: 0x34424d45  ori         $v0, $v0, 0x4D45
    ctx->pc = 0x1e3320u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)19781);
    // 0x1e3324: 0x10620018  beq         $v1, $v0, . + 4 + (0x18 << 2)
    ctx->pc = 0x1E3324u;
    {
        const bool branch_taken_0x1e3324 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1e3324) {
            ctx->pc = 0x1E3388u;
            goto label_1e3388;
        }
    }
    ctx->pc = 0x1E332Cu;
    // 0x1e332c: 0x8fc50020  lw          $a1, 0x20($fp)
    ctx->pc = 0x1e332cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e3330: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e3330u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e3334: 0x8c420004  lw          $v0, 0x4($v0)
    ctx->pc = 0x1e3334u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1e3338: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1e3338u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1e333c: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1e333cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1e3340: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e3340u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e3344: 0x8c420004  lw          $v0, 0x4($v0)
    ctx->pc = 0x1e3344u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1e3348: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1e3348u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1e334c: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1e334cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1e3350: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1e3350u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e3354: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e3354u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e3358: 0x8c430004  lw          $v1, 0x4($v0)
    ctx->pc = 0x1e3358u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1e335c: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1e335cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1e3360: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e3360u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e3364: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1e3364u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1e3368: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1e3368u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e336c: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e336cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e3370: 0x8c430004  lw          $v1, 0x4($v0)
    ctx->pc = 0x1e3370u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1e3374: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1e3374u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1e3378: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e3378u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e337c: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1e337cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1e3380: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1e3380u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e3384: 0xaca20004  sw          $v0, 0x4($a1)
    ctx->pc = 0x1e3384u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 4), GPR_U32(ctx, 2));
label_1e3388:
    // 0x1e3388: 0x97c20010  lhu         $v0, 0x10($fp)
    ctx->pc = 0x1e3388u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e338c: 0x3442a000  ori         $v0, $v0, 0xA000
    ctx->pc = 0x1e338cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)40960);
    // 0x1e3390: 0x3046ffff  andi        $a2, $v0, 0xFFFF
    ctx->pc = 0x1e3390u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1e3394: 0x97c2000c  lhu         $v0, 0xC($fp)
    ctx->pc = 0x1e3394u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e3398: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1e3398u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1e339c: 0x3043ffff  andi        $v1, $v0, 0xFFFF
    ctx->pc = 0x1e339cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1e33a0: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1e33a0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e33a4: 0x9042061c  lbu         $v0, 0x61C($v0)
    ctx->pc = 0x1e33a4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 1564)));
    // 0x1e33a8: 0x8fc4001c  lw          $a0, 0x1C($fp)
    ctx->pc = 0x1e33a8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e33ac: 0x8fc50018  lw          $a1, 0x18($fp)
    ctx->pc = 0x1e33acu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e33b0: 0x60382d  daddu       $a3, $v1, $zero
    ctx->pc = 0x1e33b0u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e33b4: 0x24080008  addiu       $t0, $zero, 0x8
    ctx->pc = 0x1e33b4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1e33b8: 0x40482d  daddu       $t1, $v0, $zero
    ctx->pc = 0x1e33b8u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e33bc: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E33BCu;
    SET_GPR_U32(ctx, 31, 0x1E33C4u);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E33C4u; }
        if (ctx->pc != 0x1E33C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E33C4u; }
        if (ctx->pc != 0x1E33C4u) { return; }
    }
    ctx->pc = 0x1E33C4u;
label_1e33c4:
    // 0x1e33c4: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E33C4u;
    {
        const bool branch_taken_0x1e33c4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e33c4) {
            ctx->pc = 0x1E33E0u;
            goto label_1e33e0;
        }
    }
    ctx->pc = 0x1E33CCu;
    // 0x1e33cc: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e33ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e33d0: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e33d0u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e33d4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e33d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e33d8: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1E33D8u;
    {
        const bool branch_taken_0x1e33d8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e33d8) {
            ctx->pc = 0x1E3410u;
            goto label_1e3410;
        }
    }
    ctx->pc = 0x1E33E0u;
label_1e33e0:
    // 0x1e33e0: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1e33e0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e33e4: 0x24050025  addiu       $a1, $zero, 0x25
    ctx->pc = 0x1e33e4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 37));
    // 0x1e33e8: 0x8fc60014  lw          $a2, 0x14($fp)
    ctx->pc = 0x1e33e8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e33ec: 0xc076ad5  jal         func_1DAB54
    ctx->pc = 0x1E33ECu;
    SET_GPR_U32(ctx, 31, 0x1E33F4u);
    ctx->pc = 0x1DAB54u;
    if (runtime->hasFunction(0x1DAB54u)) {
        auto targetFn = runtime->lookupFunction(0x1DAB54u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E33F4u; }
        if (ctx->pc != 0x1E33F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DAB54_0x1dab54(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E33F4u; }
        if (ctx->pc != 0x1E33F4u) { return; }
    }
    ctx->pc = 0x1E33F4u;
label_1e33f4:
    // 0x1e33f4: 0x8fc3001c  lw          $v1, 0x1C($fp)
    ctx->pc = 0x1e33f4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e33f8: 0x9064061c  lbu         $a0, 0x61C($v1)
    ctx->pc = 0x1e33f8u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 1564)));
    // 0x1e33fc: 0x24820001  addiu       $v0, $a0, 0x1
    ctx->pc = 0x1e33fcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1e3400: 0xa062061c  sb          $v0, 0x61C($v1)
    ctx->pc = 0x1e3400u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 1564), (uint8_t)GPR_U32(ctx, 2));
    // 0x1e3404: 0x308200ff  andi        $v0, $a0, 0xFF
    ctx->pc = 0x1e3404u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x1e3408: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1e3408u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1e340c: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1e340cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
label_1e3410:
    // 0x1e3410: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e3410u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e3414: 0xdfbe0030  ld          $fp, 0x30($sp)
    ctx->pc = 0x1e3414u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1e3418: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x1e3418u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x1e341c: 0x27bd0040  addiu       $sp, $sp, 0x40
    ctx->pc = 0x1e341cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x1e3420: 0x3e00008  jr          $ra
    ctx->pc = 0x1E3420u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E1B3Cu: goto label_1e1b3c;
            case 0x1E1B60u: goto label_1e1b60;
            case 0x1E1B84u: goto label_1e1b84;
            case 0x1E1BA8u: goto label_1e1ba8;
            case 0x1E1BC8u: goto label_1e1bc8;
            case 0x1E1BE4u: goto label_1e1be4;
            case 0x1E1BE8u: goto label_1e1be8;
            case 0x1E1C44u: goto label_1e1c44;
            case 0x1E1C58u: goto label_1e1c58;
            case 0x1E1C7Cu: goto label_1e1c7c;
            case 0x1E1CD8u: goto label_1e1cd8;
            case 0x1E1CECu: goto label_1e1cec;
            case 0x1E1D14u: goto label_1e1d14;
            case 0x1E1D7Cu: goto label_1e1d7c;
            case 0x1E1D90u: goto label_1e1d90;
            case 0x1E1DD0u: goto label_1e1dd0;
            case 0x1E1DE0u: goto label_1e1de0;
            case 0x1E1E04u: goto label_1e1e04;
            case 0x1E1E14u: goto label_1e1e14;
            case 0x1E1E38u: goto label_1e1e38;
            case 0x1E1E4Cu: goto label_1e1e4c;
            case 0x1E1E5Cu: goto label_1e1e5c;
            case 0x1E1E84u: goto label_1e1e84;
            case 0x1E1EA0u: goto label_1e1ea0;
            case 0x1E1EB4u: goto label_1e1eb4;
            case 0x1E1ED0u: goto label_1e1ed0;
            case 0x1E1F48u: goto label_1e1f48;
            case 0x1E1F5Cu: goto label_1e1f5c;
            case 0x1E1F9Cu: goto label_1e1f9c;
            case 0x1E1FACu: goto label_1e1fac;
            case 0x1E1FD0u: goto label_1e1fd0;
            case 0x1E1FE0u: goto label_1e1fe0;
            case 0x1E2004u: goto label_1e2004;
            case 0x1E2018u: goto label_1e2018;
            case 0x1E202Cu: goto label_1e202c;
            case 0x1E2064u: goto label_1e2064;
            case 0x1E206Cu: goto label_1e206c;
            case 0x1E2088u: goto label_1e2088;
            case 0x1E20A0u: goto label_1e20a0;
            case 0x1E20D4u: goto label_1e20d4;
            case 0x1E20F8u: goto label_1e20f8;
            case 0x1E210Cu: goto label_1e210c;
            case 0x1E2128u: goto label_1e2128;
            case 0x1E2190u: goto label_1e2190;
            case 0x1E21A4u: goto label_1e21a4;
            case 0x1E21E4u: goto label_1e21e4;
            case 0x1E21F4u: goto label_1e21f4;
            case 0x1E2218u: goto label_1e2218;
            case 0x1E2228u: goto label_1e2228;
            case 0x1E224Cu: goto label_1e224c;
            case 0x1E2260u: goto label_1e2260;
            case 0x1E22D4u: goto label_1e22d4;
            case 0x1E22F0u: goto label_1e22f0;
            case 0x1E2304u: goto label_1e2304;
            case 0x1E2320u: goto label_1e2320;
            case 0x1E23A0u: goto label_1e23a0;
            case 0x1E23B4u: goto label_1e23b4;
            case 0x1E23F4u: goto label_1e23f4;
            case 0x1E2404u: goto label_1e2404;
            case 0x1E2428u: goto label_1e2428;
            case 0x1E2438u: goto label_1e2438;
            case 0x1E245Cu: goto label_1e245c;
            case 0x1E2470u: goto label_1e2470;
            case 0x1E2480u: goto label_1e2480;
            case 0x1E24F8u: goto label_1e24f8;
            case 0x1E2500u: goto label_1e2500;
            case 0x1E2508u: goto label_1e2508;
            case 0x1E25D0u: goto label_1e25d0;
            case 0x1E25ECu: goto label_1e25ec;
            case 0x1E2600u: goto label_1e2600;
            case 0x1E261Cu: goto label_1e261c;
            case 0x1E2684u: goto label_1e2684;
            case 0x1E2698u: goto label_1e2698;
            case 0x1E26D8u: goto label_1e26d8;
            case 0x1E26E8u: goto label_1e26e8;
            case 0x1E270Cu: goto label_1e270c;
            case 0x1E271Cu: goto label_1e271c;
            case 0x1E2740u: goto label_1e2740;
            case 0x1E2754u: goto label_1e2754;
            case 0x1E27C8u: goto label_1e27c8;
            case 0x1E27E4u: goto label_1e27e4;
            case 0x1E27F8u: goto label_1e27f8;
            case 0x1E2814u: goto label_1e2814;
            case 0x1E287Cu: goto label_1e287c;
            case 0x1E2890u: goto label_1e2890;
            case 0x1E28D0u: goto label_1e28d0;
            case 0x1E28E0u: goto label_1e28e0;
            case 0x1E2904u: goto label_1e2904;
            case 0x1E2914u: goto label_1e2914;
            case 0x1E2938u: goto label_1e2938;
            case 0x1E294Cu: goto label_1e294c;
            case 0x1E29C0u: goto label_1e29c0;
            case 0x1E29DCu: goto label_1e29dc;
            case 0x1E29F0u: goto label_1e29f0;
            case 0x1E2A0Cu: goto label_1e2a0c;
            case 0x1E2A78u: goto label_1e2a78;
            case 0x1E2A8Cu: goto label_1e2a8c;
            case 0x1E2ACCu: goto label_1e2acc;
            case 0x1E2ADCu: goto label_1e2adc;
            case 0x1E2B00u: goto label_1e2b00;
            case 0x1E2B10u: goto label_1e2b10;
            case 0x1E2B34u: goto label_1e2b34;
            case 0x1E2B48u: goto label_1e2b48;
            case 0x1E2B54u: goto label_1e2b54;
            case 0x1E2B90u: goto label_1e2b90;
            case 0x1E2B98u: goto label_1e2b98;
            case 0x1E2BC0u: goto label_1e2bc0;
            case 0x1E2BE4u: goto label_1e2be4;
            case 0x1E2BF8u: goto label_1e2bf8;
            case 0x1E2C14u: goto label_1e2c14;
            case 0x1E2C84u: goto label_1e2c84;
            case 0x1E2C98u: goto label_1e2c98;
            case 0x1E2CD8u: goto label_1e2cd8;
            case 0x1E2CE8u: goto label_1e2ce8;
            case 0x1E2D0Cu: goto label_1e2d0c;
            case 0x1E2D1Cu: goto label_1e2d1c;
            case 0x1E2D40u: goto label_1e2d40;
            case 0x1E2D54u: goto label_1e2d54;
            case 0x1E2E10u: goto label_1e2e10;
            case 0x1E2E18u: goto label_1e2e18;
            case 0x1E2E20u: goto label_1e2e20;
            case 0x1E2E48u: goto label_1e2e48;
            case 0x1E2E64u: goto label_1e2e64;
            case 0x1E2E78u: goto label_1e2e78;
            case 0x1E2E94u: goto label_1e2e94;
            case 0x1E2EF8u: goto label_1e2ef8;
            case 0x1E2F0Cu: goto label_1e2f0c;
            case 0x1E2F4Cu: goto label_1e2f4c;
            case 0x1E2F5Cu: goto label_1e2f5c;
            case 0x1E2F80u: goto label_1e2f80;
            case 0x1E2FA8u: goto label_1e2fa8;
            case 0x1E2FC4u: goto label_1e2fc4;
            case 0x1E2FD8u: goto label_1e2fd8;
            case 0x1E2FF4u: goto label_1e2ff4;
            case 0x1E3058u: goto label_1e3058;
            case 0x1E306Cu: goto label_1e306c;
            case 0x1E30ACu: goto label_1e30ac;
            case 0x1E30BCu: goto label_1e30bc;
            case 0x1E30E0u: goto label_1e30e0;
            case 0x1E3108u: goto label_1e3108;
            case 0x1E3124u: goto label_1e3124;
            case 0x1E3138u: goto label_1e3138;
            case 0x1E3154u: goto label_1e3154;
            case 0x1E31CCu: goto label_1e31cc;
            case 0x1E31E0u: goto label_1e31e0;
            case 0x1E3220u: goto label_1e3220;
            case 0x1E3238u: goto label_1e3238;
            case 0x1E325Cu: goto label_1e325c;
            case 0x1E3278u: goto label_1e3278;
            case 0x1E329Cu: goto label_1e329c;
            case 0x1E32B0u: goto label_1e32b0;
            case 0x1E3318u: goto label_1e3318;
            case 0x1E3388u: goto label_1e3388;
            case 0x1E33C4u: goto label_1e33c4;
            case 0x1E33E0u: goto label_1e33e0;
            case 0x1E33F4u: goto label_1e33f4;
            case 0x1E3410u: goto label_1e3410;
            case 0x1E347Cu: goto label_1e347c;
            case 0x1E3490u: goto label_1e3490;
            case 0x1E34D0u: goto label_1e34d0;
            case 0x1E34E0u: goto label_1e34e0;
            case 0x1E3504u: goto label_1e3504;
            case 0x1E3514u: goto label_1e3514;
            case 0x1E3538u: goto label_1e3538;
            case 0x1E354Cu: goto label_1e354c;
            case 0x1E360Cu: goto label_1e360c;
            case 0x1E3628u: goto label_1e3628;
            case 0x1E363Cu: goto label_1e363c;
            case 0x1E3658u: goto label_1e3658;
            case 0x1E36C4u: goto label_1e36c4;
            case 0x1E36D8u: goto label_1e36d8;
            case 0x1E3718u: goto label_1e3718;
            case 0x1E3728u: goto label_1e3728;
            case 0x1E374Cu: goto label_1e374c;
            case 0x1E375Cu: goto label_1e375c;
            case 0x1E3780u: goto label_1e3780;
            case 0x1E3794u: goto label_1e3794;
            case 0x1E3854u: goto label_1e3854;
            case 0x1E3870u: goto label_1e3870;
            case 0x1E3884u: goto label_1e3884;
            case 0x1E38A0u: goto label_1e38a0;
            case 0x1E3908u: goto label_1e3908;
            case 0x1E391Cu: goto label_1e391c;
            case 0x1E395Cu: goto label_1e395c;
            case 0x1E396Cu: goto label_1e396c;
            case 0x1E3990u: goto label_1e3990;
            case 0x1E39A0u: goto label_1e39a0;
            case 0x1E39C4u: goto label_1e39c4;
            case 0x1E39D8u: goto label_1e39d8;
            case 0x1E3A44u: goto label_1e3a44;
            case 0x1E3A60u: goto label_1e3a60;
            case 0x1E3A74u: goto label_1e3a74;
            case 0x1E3A78u: goto label_1e3a78;
            case 0x1E3ADCu: goto label_1e3adc;
            case 0x1E3AF0u: goto label_1e3af0;
            case 0x1E3B30u: goto label_1e3b30;
            case 0x1E3B40u: goto label_1e3b40;
            case 0x1E3B64u: goto label_1e3b64;
            case 0x1E3B84u: goto label_1e3b84;
            case 0x1E3BA0u: goto label_1e3ba0;
            case 0x1E3BB4u: goto label_1e3bb4;
            case 0x1E3BB8u: goto label_1e3bb8;
            case 0x1E3C1Cu: goto label_1e3c1c;
            case 0x1E3C30u: goto label_1e3c30;
            case 0x1E3C70u: goto label_1e3c70;
            case 0x1E3C80u: goto label_1e3c80;
            case 0x1E3CA4u: goto label_1e3ca4;
            case 0x1E3CC4u: goto label_1e3cc4;
            case 0x1E3CE8u: goto label_1e3ce8;
            case 0x1E3CFCu: goto label_1e3cfc;
            case 0x1E3D00u: goto label_1e3d00;
            case 0x1E3D68u: goto label_1e3d68;
            case 0x1E3D7Cu: goto label_1e3d7c;
            case 0x1E3DBCu: goto label_1e3dbc;
            case 0x1E3DCCu: goto label_1e3dcc;
            case 0x1E3DF0u: goto label_1e3df0;
            case 0x1E3E00u: goto label_1e3e00;
            case 0x1E3E24u: goto label_1e3e24;
            case 0x1E3E38u: goto label_1e3e38;
            case 0x1E3EA4u: goto label_1e3ea4;
            case 0x1E3EC0u: goto label_1e3ec0;
            case 0x1E3ED4u: goto label_1e3ed4;
            case 0x1E3ED8u: goto label_1e3ed8;
            case 0x1E3F40u: goto label_1e3f40;
            case 0x1E3F54u: goto label_1e3f54;
            case 0x1E3F94u: goto label_1e3f94;
            case 0x1E3FA4u: goto label_1e3fa4;
            case 0x1E3FC8u: goto label_1e3fc8;
            case 0x1E3FD8u: goto label_1e3fd8;
            case 0x1E3FFCu: goto label_1e3ffc;
            case 0x1E4010u: goto label_1e4010;
            case 0x1E407Cu: goto label_1e407c;
            case 0x1E4098u: goto label_1e4098;
            case 0x1E40ACu: goto label_1e40ac;
            case 0x1E40B0u: goto label_1e40b0;
            case 0x1E4118u: goto label_1e4118;
            case 0x1E412Cu: goto label_1e412c;
            case 0x1E416Cu: goto label_1e416c;
            case 0x1E417Cu: goto label_1e417c;
            case 0x1E41A0u: goto label_1e41a0;
            case 0x1E41B0u: goto label_1e41b0;
            case 0x1E41D4u: goto label_1e41d4;
            case 0x1E41E8u: goto label_1e41e8;
            case 0x1E4254u: goto label_1e4254;
            case 0x1E4270u: goto label_1e4270;
            case 0x1E4284u: goto label_1e4284;
            case 0x1E4288u: goto label_1e4288;
            case 0x1E42F0u: goto label_1e42f0;
            case 0x1E4304u: goto label_1e4304;
            case 0x1E4344u: goto label_1e4344;
            case 0x1E4358u: goto label_1e4358;
            case 0x1E437Cu: goto label_1e437c;
            case 0x1E4394u: goto label_1e4394;
            case 0x1E43B8u: goto label_1e43b8;
            case 0x1E43CCu: goto label_1e43cc;
            case 0x1E43E4u: goto label_1e43e4;
            case 0x1E4414u: goto label_1e4414;
            case 0x1E4430u: goto label_1e4430;
            case 0x1E4444u: goto label_1e4444;
            case 0x1E4460u: goto label_1e4460;
            case 0x1E44C8u: goto label_1e44c8;
            case 0x1E44DCu: goto label_1e44dc;
            case 0x1E451Cu: goto label_1e451c;
            case 0x1E452Cu: goto label_1e452c;
            case 0x1E4550u: goto label_1e4550;
            case 0x1E4560u: goto label_1e4560;
            case 0x1E4584u: goto label_1e4584;
            case 0x1E4598u: goto label_1e4598;
            case 0x1E460Cu: goto label_1e460c;
            case 0x1E4628u: goto label_1e4628;
            case 0x1E463Cu: goto label_1e463c;
            case 0x1E4658u: goto label_1e4658;
            case 0x1E46C8u: goto label_1e46c8;
            case 0x1E46DCu: goto label_1e46dc;
            case 0x1E471Cu: goto label_1e471c;
            case 0x1E472Cu: goto label_1e472c;
            case 0x1E4750u: goto label_1e4750;
            case 0x1E4764u: goto label_1e4764;
            case 0x1E4788u: goto label_1e4788;
            case 0x1E479Cu: goto label_1e479c;
            case 0x1E47B0u: goto label_1e47b0;
            case 0x1E47E0u: goto label_1e47e0;
            case 0x1E47FCu: goto label_1e47fc;
            case 0x1E4800u: goto label_1e4800;
            case 0x1E48A0u: goto label_1e48a0;
            case 0x1E48B4u: goto label_1e48b4;
            case 0x1E48F4u: goto label_1e48f4;
            case 0x1E4918u: goto label_1e4918;
            case 0x1E493Cu: goto label_1e493c;
            case 0x1E4974u: goto label_1e4974;
            case 0x1E4998u: goto label_1e4998;
            case 0x1E49ACu: goto label_1e49ac;
            case 0x1E4A08u: goto label_1e4a08;
            case 0x1E4A24u: goto label_1e4a24;
            case 0x1E4AACu: goto label_1e4aac;
            case 0x1E4AC0u: goto label_1e4ac0;
            case 0x1E4B00u: goto label_1e4b00;
            case 0x1E4B1Cu: goto label_1e4b1c;
            case 0x1E4B20u: goto label_1e4b20;
            case 0x1E4B94u: goto label_1e4b94;
            case 0x1E4BA8u: goto label_1e4ba8;
            case 0x1E4BE8u: goto label_1e4be8;
            case 0x1E4C10u: goto label_1e4c10;
            case 0x1E4C34u: goto label_1e4c34;
            case 0x1E4C64u: goto label_1e4c64;
            case 0x1E4C88u: goto label_1e4c88;
            case 0x1E4C9Cu: goto label_1e4c9c;
            case 0x1E4D08u: goto label_1e4d08;
            case 0x1E4D28u: goto label_1e4d28;
            case 0x1E4DE4u: goto label_1e4de4;
            case 0x1E4DF8u: goto label_1e4df8;
            case 0x1E4E3Cu: goto label_1e4e3c;
            case 0x1E4E58u: goto label_1e4e58;
            case 0x1E4E5Cu: goto label_1e4e5c;
            case 0x1E4EC4u: goto label_1e4ec4;
            case 0x1E4ED8u: goto label_1e4ed8;
            case 0x1E4F18u: goto label_1e4f18;
            case 0x1E4F28u: goto label_1e4f28;
            case 0x1E4F4Cu: goto label_1e4f4c;
            case 0x1E4F60u: goto label_1e4f60;
            case 0x1E4F84u: goto label_1e4f84;
            case 0x1E4F98u: goto label_1e4f98;
            case 0x1E4FACu: goto label_1e4fac;
            case 0x1E4FD0u: goto label_1e4fd0;
            case 0x1E4FECu: goto label_1e4fec;
            case 0x1E4FF0u: goto label_1e4ff0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E3428u;
    // 0x1e3428: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1e3428u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1e342c: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1e342cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1e3430: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1e3430u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1e3434: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e3434u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e3438: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e3438u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e343c: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e343cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e3440: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e3440u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e3444: 0xafc7000c  sw          $a3, 0xC($fp)
    ctx->pc = 0x1e3444u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 7));
    // 0x1e3448: 0xafc00014  sw          $zero, 0x14($fp)
    ctx->pc = 0x1e3448u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 0));
    // 0x1e344c: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e344cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e3450: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e3450u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e3454: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E3454u;
    {
        const bool branch_taken_0x1e3454 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e3454) {
            ctx->pc = 0x1E347Cu;
            goto label_1e347c;
        }
    }
    ctx->pc = 0x1E345Cu;
    // 0x1e345c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e345cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e3460: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e3460u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e3464: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e3464u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e3468: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e3468u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e346c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e346cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e3470: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e3470u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e3474: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E3474u;
    {
        const bool branch_taken_0x1e3474 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e3474) {
            ctx->pc = 0x1E3490u;
            goto label_1e3490;
        }
    }
    ctx->pc = 0x1E347Cu;
label_1e347c:
    // 0x1e347c: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e347cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e3480: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e3480u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e3484: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e3484u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e3488: 0x10000073  b           . + 4 + (0x73 << 2)
    ctx->pc = 0x1E3488u;
    {
        const bool branch_taken_0x1e3488 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3488) {
            ctx->pc = 0x1E3658u;
            goto label_1e3658;
        }
    }
    ctx->pc = 0x1E3490u;
label_1e3490:
    // 0x1e3490: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e3490u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e3494: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e3494u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e3498: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e3498u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e349c: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e349cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e34a0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e34a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e34a4: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e34a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e34a8: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1e34a8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1e34ac: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e34acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e34b0: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e34b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e34b4: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E34B4u;
    {
        const bool branch_taken_0x1e34b4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e34b4) {
            ctx->pc = 0x1E34D0u;
            goto label_1e34d0;
        }
    }
    ctx->pc = 0x1E34BCu;
    // 0x1e34bc: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e34bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e34c0: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e34c0u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e34c4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e34c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e34c8: 0x10000063  b           . + 4 + (0x63 << 2)
    ctx->pc = 0x1E34C8u;
    {
        const bool branch_taken_0x1e34c8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e34c8) {
            ctx->pc = 0x1E3658u;
            goto label_1e3658;
        }
    }
    ctx->pc = 0x1E34D0u;
label_1e34d0:
    // 0x1e34d0: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e34d0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e34d4: 0x24050008  addiu       $a1, $zero, 0x8
    ctx->pc = 0x1e34d4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1e34d8: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E34D8u;
    SET_GPR_U32(ctx, 31, 0x1E34E0u);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E34E0u; }
        if (ctx->pc != 0x1E34E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E34E0u; }
        if (ctx->pc != 0x1E34E0u) { return; }
    }
    ctx->pc = 0x1E34E0u;
label_1e34e0:
    // 0x1e34e0: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1e34e0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1e34e4: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e34e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e34e8: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E34E8u;
    {
        const bool branch_taken_0x1e34e8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e34e8) {
            ctx->pc = 0x1E3504u;
            goto label_1e3504;
        }
    }
    ctx->pc = 0x1E34F0u;
    // 0x1e34f0: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e34f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e34f4: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e34f4u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e34f8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e34f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e34fc: 0x10000056  b           . + 4 + (0x56 << 2)
    ctx->pc = 0x1E34FCu;
    {
        const bool branch_taken_0x1e34fc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e34fc) {
            ctx->pc = 0x1E3658u;
            goto label_1e3658;
        }
    }
    ctx->pc = 0x1E3504u;
label_1e3504:
    // 0x1e3504: 0x8fc40010  lw          $a0, 0x10($fp)
    ctx->pc = 0x1e3504u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e3508: 0x24050008  addiu       $a1, $zero, 0x8
    ctx->pc = 0x1e3508u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1e350c: 0xc07cc3c  jal         func_1F30F0
    ctx->pc = 0x1E350Cu;
    SET_GPR_U32(ctx, 31, 0x1E3514u);
    ctx->pc = 0x1F30F0u;
    if (runtime->hasFunction(0x1F30F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F30F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3514u; }
        if (ctx->pc != 0x1E3514u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F30F0_0x1f30f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3514u; }
        if (ctx->pc != 0x1E3514u) { return; }
    }
    ctx->pc = 0x1E3514u;
label_1e3514:
    // 0x1e3514: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1e3514u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1e3518: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e3518u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e351c: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1E351Cu;
    {
        const bool branch_taken_0x1e351c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e351c) {
            ctx->pc = 0x1E354Cu;
            goto label_1e354c;
        }
    }
    ctx->pc = 0x1E3524u;
    // 0x1e3524: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e3524u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e3528: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1e3528u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1e352c: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e352cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e3530: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1E3530u;
    SET_GPR_U32(ctx, 31, 0x1E3538u);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3538u; }
        if (ctx->pc != 0x1E3538u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3538u; }
        if (ctx->pc != 0x1E3538u) { return; }
    }
    ctx->pc = 0x1E3538u;
label_1e3538:
    // 0x1e3538: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e3538u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e353c: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e353cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e3540: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e3540u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e3544: 0x10000044  b           . + 4 + (0x44 << 2)
    ctx->pc = 0x1E3544u;
    {
        const bool branch_taken_0x1e3544 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3544) {
            ctx->pc = 0x1E3658u;
            goto label_1e3658;
        }
    }
    ctx->pc = 0x1E354Cu;
label_1e354c:
    // 0x1e354c: 0x8fc50018  lw          $a1, 0x18($fp)
    ctx->pc = 0x1e354cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e3550: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e3550u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e3554: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1e3554u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1e3558: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1e3558u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1e355c: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e355cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e3560: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1e3560u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1e3564: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1e3564u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1e3568: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1e3568u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e356c: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1e356cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e3570: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1e3570u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1e3574: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e3574u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e3578: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1e3578u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1e357c: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1e357cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e3580: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1e3580u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e3584: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1e3584u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1e3588: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e3588u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e358c: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1e358cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1e3590: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1e3590u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e3594: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x1e3594u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x1e3598: 0x8fc50018  lw          $a1, 0x18($fp)
    ctx->pc = 0x1e3598u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e359c: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1e359cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e35a0: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1e35a0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1e35a4: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1e35a4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1e35a8: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1e35a8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e35ac: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1e35acu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1e35b0: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1e35b0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1e35b4: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1e35b4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e35b8: 0x8fc30008  lw          $v1, 0x8($fp)
    ctx->pc = 0x1e35b8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e35bc: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1e35bcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1e35c0: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e35c0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e35c4: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1e35c4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1e35c8: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1e35c8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e35cc: 0x8fc30008  lw          $v1, 0x8($fp)
    ctx->pc = 0x1e35ccu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e35d0: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1e35d0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1e35d4: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e35d4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e35d8: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1e35d8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1e35dc: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1e35dcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e35e0: 0xaca20004  sw          $v0, 0x4($a1)
    ctx->pc = 0x1e35e0u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 4), GPR_U32(ctx, 2));
    // 0x1e35e4: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e35e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e35e8: 0x9042061d  lbu         $v0, 0x61D($v0)
    ctx->pc = 0x1e35e8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 1565)));
    // 0x1e35ec: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e35ecu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e35f0: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e35f0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e35f4: 0x3406a000  ori         $a2, $zero, 0xA000
    ctx->pc = 0x1e35f4u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)40960);
    // 0x1e35f8: 0x24070008  addiu       $a3, $zero, 0x8
    ctx->pc = 0x1e35f8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1e35fc: 0x24080009  addiu       $t0, $zero, 0x9
    ctx->pc = 0x1e35fcu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x1e3600: 0x40482d  daddu       $t1, $v0, $zero
    ctx->pc = 0x1e3600u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e3604: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E3604u;
    SET_GPR_U32(ctx, 31, 0x1E360Cu);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E360Cu; }
        if (ctx->pc != 0x1E360Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E360Cu; }
        if (ctx->pc != 0x1E360Cu) { return; }
    }
    ctx->pc = 0x1E360Cu;
label_1e360c:
    // 0x1e360c: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E360Cu;
    {
        const bool branch_taken_0x1e360c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e360c) {
            ctx->pc = 0x1E3628u;
            goto label_1e3628;
        }
    }
    ctx->pc = 0x1E3614u;
    // 0x1e3614: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e3614u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e3618: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e3618u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e361c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e361cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e3620: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1E3620u;
    {
        const bool branch_taken_0x1e3620 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3620) {
            ctx->pc = 0x1E3658u;
            goto label_1e3658;
        }
    }
    ctx->pc = 0x1E3628u;
label_1e3628:
    // 0x1e3628: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1e3628u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e362c: 0x24050016  addiu       $a1, $zero, 0x16
    ctx->pc = 0x1e362cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 22));
    // 0x1e3630: 0x8fc6000c  lw          $a2, 0xC($fp)
    ctx->pc = 0x1e3630u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e3634: 0xc076ad5  jal         func_1DAB54
    ctx->pc = 0x1E3634u;
    SET_GPR_U32(ctx, 31, 0x1E363Cu);
    ctx->pc = 0x1DAB54u;
    if (runtime->hasFunction(0x1DAB54u)) {
        auto targetFn = runtime->lookupFunction(0x1DAB54u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E363Cu; }
        if (ctx->pc != 0x1E363Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DAB54_0x1dab54(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E363Cu; }
        if (ctx->pc != 0x1E363Cu) { return; }
    }
    ctx->pc = 0x1E363Cu;
label_1e363c:
    // 0x1e363c: 0x8fc30014  lw          $v1, 0x14($fp)
    ctx->pc = 0x1e363cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e3640: 0x9064061d  lbu         $a0, 0x61D($v1)
    ctx->pc = 0x1e3640u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 1565)));
    // 0x1e3644: 0x24820001  addiu       $v0, $a0, 0x1
    ctx->pc = 0x1e3644u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1e3648: 0xa062061d  sb          $v0, 0x61D($v1)
    ctx->pc = 0x1e3648u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 1565), (uint8_t)GPR_U32(ctx, 2));
    // 0x1e364c: 0x308200ff  andi        $v0, $a0, 0xFF
    ctx->pc = 0x1e364cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x1e3650: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1e3650u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1e3654: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1e3654u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
label_1e3658:
    // 0x1e3658: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e3658u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e365c: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1e365cu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1e3660: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1e3660u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1e3664: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1e3664u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1e3668: 0x3e00008  jr          $ra
    ctx->pc = 0x1E3668u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E1B3Cu: goto label_1e1b3c;
            case 0x1E1B60u: goto label_1e1b60;
            case 0x1E1B84u: goto label_1e1b84;
            case 0x1E1BA8u: goto label_1e1ba8;
            case 0x1E1BC8u: goto label_1e1bc8;
            case 0x1E1BE4u: goto label_1e1be4;
            case 0x1E1BE8u: goto label_1e1be8;
            case 0x1E1C44u: goto label_1e1c44;
            case 0x1E1C58u: goto label_1e1c58;
            case 0x1E1C7Cu: goto label_1e1c7c;
            case 0x1E1CD8u: goto label_1e1cd8;
            case 0x1E1CECu: goto label_1e1cec;
            case 0x1E1D14u: goto label_1e1d14;
            case 0x1E1D7Cu: goto label_1e1d7c;
            case 0x1E1D90u: goto label_1e1d90;
            case 0x1E1DD0u: goto label_1e1dd0;
            case 0x1E1DE0u: goto label_1e1de0;
            case 0x1E1E04u: goto label_1e1e04;
            case 0x1E1E14u: goto label_1e1e14;
            case 0x1E1E38u: goto label_1e1e38;
            case 0x1E1E4Cu: goto label_1e1e4c;
            case 0x1E1E5Cu: goto label_1e1e5c;
            case 0x1E1E84u: goto label_1e1e84;
            case 0x1E1EA0u: goto label_1e1ea0;
            case 0x1E1EB4u: goto label_1e1eb4;
            case 0x1E1ED0u: goto label_1e1ed0;
            case 0x1E1F48u: goto label_1e1f48;
            case 0x1E1F5Cu: goto label_1e1f5c;
            case 0x1E1F9Cu: goto label_1e1f9c;
            case 0x1E1FACu: goto label_1e1fac;
            case 0x1E1FD0u: goto label_1e1fd0;
            case 0x1E1FE0u: goto label_1e1fe0;
            case 0x1E2004u: goto label_1e2004;
            case 0x1E2018u: goto label_1e2018;
            case 0x1E202Cu: goto label_1e202c;
            case 0x1E2064u: goto label_1e2064;
            case 0x1E206Cu: goto label_1e206c;
            case 0x1E2088u: goto label_1e2088;
            case 0x1E20A0u: goto label_1e20a0;
            case 0x1E20D4u: goto label_1e20d4;
            case 0x1E20F8u: goto label_1e20f8;
            case 0x1E210Cu: goto label_1e210c;
            case 0x1E2128u: goto label_1e2128;
            case 0x1E2190u: goto label_1e2190;
            case 0x1E21A4u: goto label_1e21a4;
            case 0x1E21E4u: goto label_1e21e4;
            case 0x1E21F4u: goto label_1e21f4;
            case 0x1E2218u: goto label_1e2218;
            case 0x1E2228u: goto label_1e2228;
            case 0x1E224Cu: goto label_1e224c;
            case 0x1E2260u: goto label_1e2260;
            case 0x1E22D4u: goto label_1e22d4;
            case 0x1E22F0u: goto label_1e22f0;
            case 0x1E2304u: goto label_1e2304;
            case 0x1E2320u: goto label_1e2320;
            case 0x1E23A0u: goto label_1e23a0;
            case 0x1E23B4u: goto label_1e23b4;
            case 0x1E23F4u: goto label_1e23f4;
            case 0x1E2404u: goto label_1e2404;
            case 0x1E2428u: goto label_1e2428;
            case 0x1E2438u: goto label_1e2438;
            case 0x1E245Cu: goto label_1e245c;
            case 0x1E2470u: goto label_1e2470;
            case 0x1E2480u: goto label_1e2480;
            case 0x1E24F8u: goto label_1e24f8;
            case 0x1E2500u: goto label_1e2500;
            case 0x1E2508u: goto label_1e2508;
            case 0x1E25D0u: goto label_1e25d0;
            case 0x1E25ECu: goto label_1e25ec;
            case 0x1E2600u: goto label_1e2600;
            case 0x1E261Cu: goto label_1e261c;
            case 0x1E2684u: goto label_1e2684;
            case 0x1E2698u: goto label_1e2698;
            case 0x1E26D8u: goto label_1e26d8;
            case 0x1E26E8u: goto label_1e26e8;
            case 0x1E270Cu: goto label_1e270c;
            case 0x1E271Cu: goto label_1e271c;
            case 0x1E2740u: goto label_1e2740;
            case 0x1E2754u: goto label_1e2754;
            case 0x1E27C8u: goto label_1e27c8;
            case 0x1E27E4u: goto label_1e27e4;
            case 0x1E27F8u: goto label_1e27f8;
            case 0x1E2814u: goto label_1e2814;
            case 0x1E287Cu: goto label_1e287c;
            case 0x1E2890u: goto label_1e2890;
            case 0x1E28D0u: goto label_1e28d0;
            case 0x1E28E0u: goto label_1e28e0;
            case 0x1E2904u: goto label_1e2904;
            case 0x1E2914u: goto label_1e2914;
            case 0x1E2938u: goto label_1e2938;
            case 0x1E294Cu: goto label_1e294c;
            case 0x1E29C0u: goto label_1e29c0;
            case 0x1E29DCu: goto label_1e29dc;
            case 0x1E29F0u: goto label_1e29f0;
            case 0x1E2A0Cu: goto label_1e2a0c;
            case 0x1E2A78u: goto label_1e2a78;
            case 0x1E2A8Cu: goto label_1e2a8c;
            case 0x1E2ACCu: goto label_1e2acc;
            case 0x1E2ADCu: goto label_1e2adc;
            case 0x1E2B00u: goto label_1e2b00;
            case 0x1E2B10u: goto label_1e2b10;
            case 0x1E2B34u: goto label_1e2b34;
            case 0x1E2B48u: goto label_1e2b48;
            case 0x1E2B54u: goto label_1e2b54;
            case 0x1E2B90u: goto label_1e2b90;
            case 0x1E2B98u: goto label_1e2b98;
            case 0x1E2BC0u: goto label_1e2bc0;
            case 0x1E2BE4u: goto label_1e2be4;
            case 0x1E2BF8u: goto label_1e2bf8;
            case 0x1E2C14u: goto label_1e2c14;
            case 0x1E2C84u: goto label_1e2c84;
            case 0x1E2C98u: goto label_1e2c98;
            case 0x1E2CD8u: goto label_1e2cd8;
            case 0x1E2CE8u: goto label_1e2ce8;
            case 0x1E2D0Cu: goto label_1e2d0c;
            case 0x1E2D1Cu: goto label_1e2d1c;
            case 0x1E2D40u: goto label_1e2d40;
            case 0x1E2D54u: goto label_1e2d54;
            case 0x1E2E10u: goto label_1e2e10;
            case 0x1E2E18u: goto label_1e2e18;
            case 0x1E2E20u: goto label_1e2e20;
            case 0x1E2E48u: goto label_1e2e48;
            case 0x1E2E64u: goto label_1e2e64;
            case 0x1E2E78u: goto label_1e2e78;
            case 0x1E2E94u: goto label_1e2e94;
            case 0x1E2EF8u: goto label_1e2ef8;
            case 0x1E2F0Cu: goto label_1e2f0c;
            case 0x1E2F4Cu: goto label_1e2f4c;
            case 0x1E2F5Cu: goto label_1e2f5c;
            case 0x1E2F80u: goto label_1e2f80;
            case 0x1E2FA8u: goto label_1e2fa8;
            case 0x1E2FC4u: goto label_1e2fc4;
            case 0x1E2FD8u: goto label_1e2fd8;
            case 0x1E2FF4u: goto label_1e2ff4;
            case 0x1E3058u: goto label_1e3058;
            case 0x1E306Cu: goto label_1e306c;
            case 0x1E30ACu: goto label_1e30ac;
            case 0x1E30BCu: goto label_1e30bc;
            case 0x1E30E0u: goto label_1e30e0;
            case 0x1E3108u: goto label_1e3108;
            case 0x1E3124u: goto label_1e3124;
            case 0x1E3138u: goto label_1e3138;
            case 0x1E3154u: goto label_1e3154;
            case 0x1E31CCu: goto label_1e31cc;
            case 0x1E31E0u: goto label_1e31e0;
            case 0x1E3220u: goto label_1e3220;
            case 0x1E3238u: goto label_1e3238;
            case 0x1E325Cu: goto label_1e325c;
            case 0x1E3278u: goto label_1e3278;
            case 0x1E329Cu: goto label_1e329c;
            case 0x1E32B0u: goto label_1e32b0;
            case 0x1E3318u: goto label_1e3318;
            case 0x1E3388u: goto label_1e3388;
            case 0x1E33C4u: goto label_1e33c4;
            case 0x1E33E0u: goto label_1e33e0;
            case 0x1E33F4u: goto label_1e33f4;
            case 0x1E3410u: goto label_1e3410;
            case 0x1E347Cu: goto label_1e347c;
            case 0x1E3490u: goto label_1e3490;
            case 0x1E34D0u: goto label_1e34d0;
            case 0x1E34E0u: goto label_1e34e0;
            case 0x1E3504u: goto label_1e3504;
            case 0x1E3514u: goto label_1e3514;
            case 0x1E3538u: goto label_1e3538;
            case 0x1E354Cu: goto label_1e354c;
            case 0x1E360Cu: goto label_1e360c;
            case 0x1E3628u: goto label_1e3628;
            case 0x1E363Cu: goto label_1e363c;
            case 0x1E3658u: goto label_1e3658;
            case 0x1E36C4u: goto label_1e36c4;
            case 0x1E36D8u: goto label_1e36d8;
            case 0x1E3718u: goto label_1e3718;
            case 0x1E3728u: goto label_1e3728;
            case 0x1E374Cu: goto label_1e374c;
            case 0x1E375Cu: goto label_1e375c;
            case 0x1E3780u: goto label_1e3780;
            case 0x1E3794u: goto label_1e3794;
            case 0x1E3854u: goto label_1e3854;
            case 0x1E3870u: goto label_1e3870;
            case 0x1E3884u: goto label_1e3884;
            case 0x1E38A0u: goto label_1e38a0;
            case 0x1E3908u: goto label_1e3908;
            case 0x1E391Cu: goto label_1e391c;
            case 0x1E395Cu: goto label_1e395c;
            case 0x1E396Cu: goto label_1e396c;
            case 0x1E3990u: goto label_1e3990;
            case 0x1E39A0u: goto label_1e39a0;
            case 0x1E39C4u: goto label_1e39c4;
            case 0x1E39D8u: goto label_1e39d8;
            case 0x1E3A44u: goto label_1e3a44;
            case 0x1E3A60u: goto label_1e3a60;
            case 0x1E3A74u: goto label_1e3a74;
            case 0x1E3A78u: goto label_1e3a78;
            case 0x1E3ADCu: goto label_1e3adc;
            case 0x1E3AF0u: goto label_1e3af0;
            case 0x1E3B30u: goto label_1e3b30;
            case 0x1E3B40u: goto label_1e3b40;
            case 0x1E3B64u: goto label_1e3b64;
            case 0x1E3B84u: goto label_1e3b84;
            case 0x1E3BA0u: goto label_1e3ba0;
            case 0x1E3BB4u: goto label_1e3bb4;
            case 0x1E3BB8u: goto label_1e3bb8;
            case 0x1E3C1Cu: goto label_1e3c1c;
            case 0x1E3C30u: goto label_1e3c30;
            case 0x1E3C70u: goto label_1e3c70;
            case 0x1E3C80u: goto label_1e3c80;
            case 0x1E3CA4u: goto label_1e3ca4;
            case 0x1E3CC4u: goto label_1e3cc4;
            case 0x1E3CE8u: goto label_1e3ce8;
            case 0x1E3CFCu: goto label_1e3cfc;
            case 0x1E3D00u: goto label_1e3d00;
            case 0x1E3D68u: goto label_1e3d68;
            case 0x1E3D7Cu: goto label_1e3d7c;
            case 0x1E3DBCu: goto label_1e3dbc;
            case 0x1E3DCCu: goto label_1e3dcc;
            case 0x1E3DF0u: goto label_1e3df0;
            case 0x1E3E00u: goto label_1e3e00;
            case 0x1E3E24u: goto label_1e3e24;
            case 0x1E3E38u: goto label_1e3e38;
            case 0x1E3EA4u: goto label_1e3ea4;
            case 0x1E3EC0u: goto label_1e3ec0;
            case 0x1E3ED4u: goto label_1e3ed4;
            case 0x1E3ED8u: goto label_1e3ed8;
            case 0x1E3F40u: goto label_1e3f40;
            case 0x1E3F54u: goto label_1e3f54;
            case 0x1E3F94u: goto label_1e3f94;
            case 0x1E3FA4u: goto label_1e3fa4;
            case 0x1E3FC8u: goto label_1e3fc8;
            case 0x1E3FD8u: goto label_1e3fd8;
            case 0x1E3FFCu: goto label_1e3ffc;
            case 0x1E4010u: goto label_1e4010;
            case 0x1E407Cu: goto label_1e407c;
            case 0x1E4098u: goto label_1e4098;
            case 0x1E40ACu: goto label_1e40ac;
            case 0x1E40B0u: goto label_1e40b0;
            case 0x1E4118u: goto label_1e4118;
            case 0x1E412Cu: goto label_1e412c;
            case 0x1E416Cu: goto label_1e416c;
            case 0x1E417Cu: goto label_1e417c;
            case 0x1E41A0u: goto label_1e41a0;
            case 0x1E41B0u: goto label_1e41b0;
            case 0x1E41D4u: goto label_1e41d4;
            case 0x1E41E8u: goto label_1e41e8;
            case 0x1E4254u: goto label_1e4254;
            case 0x1E4270u: goto label_1e4270;
            case 0x1E4284u: goto label_1e4284;
            case 0x1E4288u: goto label_1e4288;
            case 0x1E42F0u: goto label_1e42f0;
            case 0x1E4304u: goto label_1e4304;
            case 0x1E4344u: goto label_1e4344;
            case 0x1E4358u: goto label_1e4358;
            case 0x1E437Cu: goto label_1e437c;
            case 0x1E4394u: goto label_1e4394;
            case 0x1E43B8u: goto label_1e43b8;
            case 0x1E43CCu: goto label_1e43cc;
            case 0x1E43E4u: goto label_1e43e4;
            case 0x1E4414u: goto label_1e4414;
            case 0x1E4430u: goto label_1e4430;
            case 0x1E4444u: goto label_1e4444;
            case 0x1E4460u: goto label_1e4460;
            case 0x1E44C8u: goto label_1e44c8;
            case 0x1E44DCu: goto label_1e44dc;
            case 0x1E451Cu: goto label_1e451c;
            case 0x1E452Cu: goto label_1e452c;
            case 0x1E4550u: goto label_1e4550;
            case 0x1E4560u: goto label_1e4560;
            case 0x1E4584u: goto label_1e4584;
            case 0x1E4598u: goto label_1e4598;
            case 0x1E460Cu: goto label_1e460c;
            case 0x1E4628u: goto label_1e4628;
            case 0x1E463Cu: goto label_1e463c;
            case 0x1E4658u: goto label_1e4658;
            case 0x1E46C8u: goto label_1e46c8;
            case 0x1E46DCu: goto label_1e46dc;
            case 0x1E471Cu: goto label_1e471c;
            case 0x1E472Cu: goto label_1e472c;
            case 0x1E4750u: goto label_1e4750;
            case 0x1E4764u: goto label_1e4764;
            case 0x1E4788u: goto label_1e4788;
            case 0x1E479Cu: goto label_1e479c;
            case 0x1E47B0u: goto label_1e47b0;
            case 0x1E47E0u: goto label_1e47e0;
            case 0x1E47FCu: goto label_1e47fc;
            case 0x1E4800u: goto label_1e4800;
            case 0x1E48A0u: goto label_1e48a0;
            case 0x1E48B4u: goto label_1e48b4;
            case 0x1E48F4u: goto label_1e48f4;
            case 0x1E4918u: goto label_1e4918;
            case 0x1E493Cu: goto label_1e493c;
            case 0x1E4974u: goto label_1e4974;
            case 0x1E4998u: goto label_1e4998;
            case 0x1E49ACu: goto label_1e49ac;
            case 0x1E4A08u: goto label_1e4a08;
            case 0x1E4A24u: goto label_1e4a24;
            case 0x1E4AACu: goto label_1e4aac;
            case 0x1E4AC0u: goto label_1e4ac0;
            case 0x1E4B00u: goto label_1e4b00;
            case 0x1E4B1Cu: goto label_1e4b1c;
            case 0x1E4B20u: goto label_1e4b20;
            case 0x1E4B94u: goto label_1e4b94;
            case 0x1E4BA8u: goto label_1e4ba8;
            case 0x1E4BE8u: goto label_1e4be8;
            case 0x1E4C10u: goto label_1e4c10;
            case 0x1E4C34u: goto label_1e4c34;
            case 0x1E4C64u: goto label_1e4c64;
            case 0x1E4C88u: goto label_1e4c88;
            case 0x1E4C9Cu: goto label_1e4c9c;
            case 0x1E4D08u: goto label_1e4d08;
            case 0x1E4D28u: goto label_1e4d28;
            case 0x1E4DE4u: goto label_1e4de4;
            case 0x1E4DF8u: goto label_1e4df8;
            case 0x1E4E3Cu: goto label_1e4e3c;
            case 0x1E4E58u: goto label_1e4e58;
            case 0x1E4E5Cu: goto label_1e4e5c;
            case 0x1E4EC4u: goto label_1e4ec4;
            case 0x1E4ED8u: goto label_1e4ed8;
            case 0x1E4F18u: goto label_1e4f18;
            case 0x1E4F28u: goto label_1e4f28;
            case 0x1E4F4Cu: goto label_1e4f4c;
            case 0x1E4F60u: goto label_1e4f60;
            case 0x1E4F84u: goto label_1e4f84;
            case 0x1E4F98u: goto label_1e4f98;
            case 0x1E4FACu: goto label_1e4fac;
            case 0x1E4FD0u: goto label_1e4fd0;
            case 0x1E4FECu: goto label_1e4fec;
            case 0x1E4FF0u: goto label_1e4ff0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E3670u;
    // 0x1e3670: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1e3670u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1e3674: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1e3674u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1e3678: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1e3678u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1e367c: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e367cu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e3680: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e3680u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e3684: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e3684u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e3688: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e3688u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e368c: 0xafc7000c  sw          $a3, 0xC($fp)
    ctx->pc = 0x1e368cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 7));
    // 0x1e3690: 0xafc00014  sw          $zero, 0x14($fp)
    ctx->pc = 0x1e3690u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 0));
    // 0x1e3694: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e3694u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e3698: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e3698u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e369c: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E369Cu;
    {
        const bool branch_taken_0x1e369c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e369c) {
            ctx->pc = 0x1E36C4u;
            goto label_1e36c4;
        }
    }
    ctx->pc = 0x1E36A4u;
    // 0x1e36a4: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e36a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e36a8: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e36a8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e36ac: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e36acu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e36b0: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e36b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e36b4: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e36b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e36b8: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e36b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e36bc: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E36BCu;
    {
        const bool branch_taken_0x1e36bc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e36bc) {
            ctx->pc = 0x1E36D8u;
            goto label_1e36d8;
        }
    }
    ctx->pc = 0x1E36C4u;
label_1e36c4:
    // 0x1e36c4: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e36c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e36c8: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e36c8u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e36cc: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e36ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e36d0: 0x10000073  b           . + 4 + (0x73 << 2)
    ctx->pc = 0x1E36D0u;
    {
        const bool branch_taken_0x1e36d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e36d0) {
            ctx->pc = 0x1E38A0u;
            goto label_1e38a0;
        }
    }
    ctx->pc = 0x1E36D8u;
label_1e36d8:
    // 0x1e36d8: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e36d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e36dc: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e36dcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e36e0: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e36e0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e36e4: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e36e4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e36e8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e36e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e36ec: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e36ecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e36f0: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1e36f0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1e36f4: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e36f4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e36f8: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e36f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e36fc: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E36FCu;
    {
        const bool branch_taken_0x1e36fc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e36fc) {
            ctx->pc = 0x1E3718u;
            goto label_1e3718;
        }
    }
    ctx->pc = 0x1E3704u;
    // 0x1e3704: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e3704u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e3708: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e3708u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e370c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e370cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e3710: 0x10000063  b           . + 4 + (0x63 << 2)
    ctx->pc = 0x1E3710u;
    {
        const bool branch_taken_0x1e3710 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3710) {
            ctx->pc = 0x1E38A0u;
            goto label_1e38a0;
        }
    }
    ctx->pc = 0x1E3718u;
label_1e3718:
    // 0x1e3718: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e3718u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e371c: 0x24050008  addiu       $a1, $zero, 0x8
    ctx->pc = 0x1e371cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1e3720: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E3720u;
    SET_GPR_U32(ctx, 31, 0x1E3728u);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3728u; }
        if (ctx->pc != 0x1E3728u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3728u; }
        if (ctx->pc != 0x1E3728u) { return; }
    }
    ctx->pc = 0x1E3728u;
label_1e3728:
    // 0x1e3728: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1e3728u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1e372c: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e372cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e3730: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E3730u;
    {
        const bool branch_taken_0x1e3730 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e3730) {
            ctx->pc = 0x1E374Cu;
            goto label_1e374c;
        }
    }
    ctx->pc = 0x1E3738u;
    // 0x1e3738: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e3738u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e373c: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e373cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e3740: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e3740u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e3744: 0x10000056  b           . + 4 + (0x56 << 2)
    ctx->pc = 0x1E3744u;
    {
        const bool branch_taken_0x1e3744 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3744) {
            ctx->pc = 0x1E38A0u;
            goto label_1e38a0;
        }
    }
    ctx->pc = 0x1E374Cu;
label_1e374c:
    // 0x1e374c: 0x8fc40010  lw          $a0, 0x10($fp)
    ctx->pc = 0x1e374cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e3750: 0x24050008  addiu       $a1, $zero, 0x8
    ctx->pc = 0x1e3750u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1e3754: 0xc07cc3c  jal         func_1F30F0
    ctx->pc = 0x1E3754u;
    SET_GPR_U32(ctx, 31, 0x1E375Cu);
    ctx->pc = 0x1F30F0u;
    if (runtime->hasFunction(0x1F30F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F30F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E375Cu; }
        if (ctx->pc != 0x1E375Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F30F0_0x1f30f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E375Cu; }
        if (ctx->pc != 0x1E375Cu) { return; }
    }
    ctx->pc = 0x1E375Cu;
label_1e375c:
    // 0x1e375c: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1e375cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1e3760: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e3760u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e3764: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1E3764u;
    {
        const bool branch_taken_0x1e3764 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e3764) {
            ctx->pc = 0x1E3794u;
            goto label_1e3794;
        }
    }
    ctx->pc = 0x1E376Cu;
    // 0x1e376c: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e376cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e3770: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1e3770u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1e3774: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e3774u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e3778: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1E3778u;
    SET_GPR_U32(ctx, 31, 0x1E3780u);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3780u; }
        if (ctx->pc != 0x1E3780u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3780u; }
        if (ctx->pc != 0x1E3780u) { return; }
    }
    ctx->pc = 0x1E3780u;
label_1e3780:
    // 0x1e3780: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e3780u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e3784: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e3784u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e3788: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e3788u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e378c: 0x10000044  b           . + 4 + (0x44 << 2)
    ctx->pc = 0x1E378Cu;
    {
        const bool branch_taken_0x1e378c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e378c) {
            ctx->pc = 0x1E38A0u;
            goto label_1e38a0;
        }
    }
    ctx->pc = 0x1E3794u;
label_1e3794:
    // 0x1e3794: 0x8fc50018  lw          $a1, 0x18($fp)
    ctx->pc = 0x1e3794u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e3798: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e3798u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e379c: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1e379cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1e37a0: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1e37a0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1e37a4: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e37a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e37a8: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1e37a8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1e37ac: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1e37acu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1e37b0: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1e37b0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e37b4: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1e37b4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e37b8: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1e37b8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1e37bc: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e37bcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e37c0: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1e37c0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1e37c4: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1e37c4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e37c8: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1e37c8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e37cc: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1e37ccu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1e37d0: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e37d0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e37d4: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1e37d4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1e37d8: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1e37d8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e37dc: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x1e37dcu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x1e37e0: 0x8fc50018  lw          $a1, 0x18($fp)
    ctx->pc = 0x1e37e0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e37e4: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1e37e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e37e8: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1e37e8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1e37ec: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1e37ecu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1e37f0: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1e37f0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e37f4: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1e37f4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1e37f8: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1e37f8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1e37fc: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1e37fcu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e3800: 0x8fc30008  lw          $v1, 0x8($fp)
    ctx->pc = 0x1e3800u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e3804: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1e3804u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1e3808: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e3808u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e380c: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1e380cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1e3810: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1e3810u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e3814: 0x8fc30008  lw          $v1, 0x8($fp)
    ctx->pc = 0x1e3814u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e3818: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1e3818u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1e381c: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e381cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e3820: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1e3820u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1e3824: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1e3824u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e3828: 0xaca20004  sw          $v0, 0x4($a1)
    ctx->pc = 0x1e3828u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 4), GPR_U32(ctx, 2));
    // 0x1e382c: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e382cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e3830: 0x9042061e  lbu         $v0, 0x61E($v0)
    ctx->pc = 0x1e3830u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 1566)));
    // 0x1e3834: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e3834u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e3838: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e3838u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e383c: 0x3406b000  ori         $a2, $zero, 0xB000
    ctx->pc = 0x1e383cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)45056);
    // 0x1e3840: 0x24070008  addiu       $a3, $zero, 0x8
    ctx->pc = 0x1e3840u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1e3844: 0x24080009  addiu       $t0, $zero, 0x9
    ctx->pc = 0x1e3844u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x1e3848: 0x40482d  daddu       $t1, $v0, $zero
    ctx->pc = 0x1e3848u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e384c: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E384Cu;
    SET_GPR_U32(ctx, 31, 0x1E3854u);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3854u; }
        if (ctx->pc != 0x1E3854u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3854u; }
        if (ctx->pc != 0x1E3854u) { return; }
    }
    ctx->pc = 0x1E3854u;
label_1e3854:
    // 0x1e3854: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E3854u;
    {
        const bool branch_taken_0x1e3854 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3854) {
            ctx->pc = 0x1E3870u;
            goto label_1e3870;
        }
    }
    ctx->pc = 0x1E385Cu;
    // 0x1e385c: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e385cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e3860: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e3860u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e3864: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e3864u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e3868: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1E3868u;
    {
        const bool branch_taken_0x1e3868 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3868) {
            ctx->pc = 0x1E38A0u;
            goto label_1e38a0;
        }
    }
    ctx->pc = 0x1E3870u;
label_1e3870:
    // 0x1e3870: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1e3870u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e3874: 0x24050017  addiu       $a1, $zero, 0x17
    ctx->pc = 0x1e3874u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 23));
    // 0x1e3878: 0x8fc6000c  lw          $a2, 0xC($fp)
    ctx->pc = 0x1e3878u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e387c: 0xc076ad5  jal         func_1DAB54
    ctx->pc = 0x1E387Cu;
    SET_GPR_U32(ctx, 31, 0x1E3884u);
    ctx->pc = 0x1DAB54u;
    if (runtime->hasFunction(0x1DAB54u)) {
        auto targetFn = runtime->lookupFunction(0x1DAB54u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3884u; }
        if (ctx->pc != 0x1E3884u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DAB54_0x1dab54(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3884u; }
        if (ctx->pc != 0x1E3884u) { return; }
    }
    ctx->pc = 0x1E3884u;
label_1e3884:
    // 0x1e3884: 0x8fc30014  lw          $v1, 0x14($fp)
    ctx->pc = 0x1e3884u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e3888: 0x9064061e  lbu         $a0, 0x61E($v1)
    ctx->pc = 0x1e3888u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 1566)));
    // 0x1e388c: 0x24820001  addiu       $v0, $a0, 0x1
    ctx->pc = 0x1e388cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1e3890: 0xa062061e  sb          $v0, 0x61E($v1)
    ctx->pc = 0x1e3890u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 1566), (uint8_t)GPR_U32(ctx, 2));
    // 0x1e3894: 0x308200ff  andi        $v0, $a0, 0xFF
    ctx->pc = 0x1e3894u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x1e3898: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1e3898u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1e389c: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1e389cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
label_1e38a0:
    // 0x1e38a0: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e38a0u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e38a4: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1e38a4u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1e38a8: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1e38a8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1e38ac: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1e38acu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1e38b0: 0x3e00008  jr          $ra
    ctx->pc = 0x1E38B0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E1B3Cu: goto label_1e1b3c;
            case 0x1E1B60u: goto label_1e1b60;
            case 0x1E1B84u: goto label_1e1b84;
            case 0x1E1BA8u: goto label_1e1ba8;
            case 0x1E1BC8u: goto label_1e1bc8;
            case 0x1E1BE4u: goto label_1e1be4;
            case 0x1E1BE8u: goto label_1e1be8;
            case 0x1E1C44u: goto label_1e1c44;
            case 0x1E1C58u: goto label_1e1c58;
            case 0x1E1C7Cu: goto label_1e1c7c;
            case 0x1E1CD8u: goto label_1e1cd8;
            case 0x1E1CECu: goto label_1e1cec;
            case 0x1E1D14u: goto label_1e1d14;
            case 0x1E1D7Cu: goto label_1e1d7c;
            case 0x1E1D90u: goto label_1e1d90;
            case 0x1E1DD0u: goto label_1e1dd0;
            case 0x1E1DE0u: goto label_1e1de0;
            case 0x1E1E04u: goto label_1e1e04;
            case 0x1E1E14u: goto label_1e1e14;
            case 0x1E1E38u: goto label_1e1e38;
            case 0x1E1E4Cu: goto label_1e1e4c;
            case 0x1E1E5Cu: goto label_1e1e5c;
            case 0x1E1E84u: goto label_1e1e84;
            case 0x1E1EA0u: goto label_1e1ea0;
            case 0x1E1EB4u: goto label_1e1eb4;
            case 0x1E1ED0u: goto label_1e1ed0;
            case 0x1E1F48u: goto label_1e1f48;
            case 0x1E1F5Cu: goto label_1e1f5c;
            case 0x1E1F9Cu: goto label_1e1f9c;
            case 0x1E1FACu: goto label_1e1fac;
            case 0x1E1FD0u: goto label_1e1fd0;
            case 0x1E1FE0u: goto label_1e1fe0;
            case 0x1E2004u: goto label_1e2004;
            case 0x1E2018u: goto label_1e2018;
            case 0x1E202Cu: goto label_1e202c;
            case 0x1E2064u: goto label_1e2064;
            case 0x1E206Cu: goto label_1e206c;
            case 0x1E2088u: goto label_1e2088;
            case 0x1E20A0u: goto label_1e20a0;
            case 0x1E20D4u: goto label_1e20d4;
            case 0x1E20F8u: goto label_1e20f8;
            case 0x1E210Cu: goto label_1e210c;
            case 0x1E2128u: goto label_1e2128;
            case 0x1E2190u: goto label_1e2190;
            case 0x1E21A4u: goto label_1e21a4;
            case 0x1E21E4u: goto label_1e21e4;
            case 0x1E21F4u: goto label_1e21f4;
            case 0x1E2218u: goto label_1e2218;
            case 0x1E2228u: goto label_1e2228;
            case 0x1E224Cu: goto label_1e224c;
            case 0x1E2260u: goto label_1e2260;
            case 0x1E22D4u: goto label_1e22d4;
            case 0x1E22F0u: goto label_1e22f0;
            case 0x1E2304u: goto label_1e2304;
            case 0x1E2320u: goto label_1e2320;
            case 0x1E23A0u: goto label_1e23a0;
            case 0x1E23B4u: goto label_1e23b4;
            case 0x1E23F4u: goto label_1e23f4;
            case 0x1E2404u: goto label_1e2404;
            case 0x1E2428u: goto label_1e2428;
            case 0x1E2438u: goto label_1e2438;
            case 0x1E245Cu: goto label_1e245c;
            case 0x1E2470u: goto label_1e2470;
            case 0x1E2480u: goto label_1e2480;
            case 0x1E24F8u: goto label_1e24f8;
            case 0x1E2500u: goto label_1e2500;
            case 0x1E2508u: goto label_1e2508;
            case 0x1E25D0u: goto label_1e25d0;
            case 0x1E25ECu: goto label_1e25ec;
            case 0x1E2600u: goto label_1e2600;
            case 0x1E261Cu: goto label_1e261c;
            case 0x1E2684u: goto label_1e2684;
            case 0x1E2698u: goto label_1e2698;
            case 0x1E26D8u: goto label_1e26d8;
            case 0x1E26E8u: goto label_1e26e8;
            case 0x1E270Cu: goto label_1e270c;
            case 0x1E271Cu: goto label_1e271c;
            case 0x1E2740u: goto label_1e2740;
            case 0x1E2754u: goto label_1e2754;
            case 0x1E27C8u: goto label_1e27c8;
            case 0x1E27E4u: goto label_1e27e4;
            case 0x1E27F8u: goto label_1e27f8;
            case 0x1E2814u: goto label_1e2814;
            case 0x1E287Cu: goto label_1e287c;
            case 0x1E2890u: goto label_1e2890;
            case 0x1E28D0u: goto label_1e28d0;
            case 0x1E28E0u: goto label_1e28e0;
            case 0x1E2904u: goto label_1e2904;
            case 0x1E2914u: goto label_1e2914;
            case 0x1E2938u: goto label_1e2938;
            case 0x1E294Cu: goto label_1e294c;
            case 0x1E29C0u: goto label_1e29c0;
            case 0x1E29DCu: goto label_1e29dc;
            case 0x1E29F0u: goto label_1e29f0;
            case 0x1E2A0Cu: goto label_1e2a0c;
            case 0x1E2A78u: goto label_1e2a78;
            case 0x1E2A8Cu: goto label_1e2a8c;
            case 0x1E2ACCu: goto label_1e2acc;
            case 0x1E2ADCu: goto label_1e2adc;
            case 0x1E2B00u: goto label_1e2b00;
            case 0x1E2B10u: goto label_1e2b10;
            case 0x1E2B34u: goto label_1e2b34;
            case 0x1E2B48u: goto label_1e2b48;
            case 0x1E2B54u: goto label_1e2b54;
            case 0x1E2B90u: goto label_1e2b90;
            case 0x1E2B98u: goto label_1e2b98;
            case 0x1E2BC0u: goto label_1e2bc0;
            case 0x1E2BE4u: goto label_1e2be4;
            case 0x1E2BF8u: goto label_1e2bf8;
            case 0x1E2C14u: goto label_1e2c14;
            case 0x1E2C84u: goto label_1e2c84;
            case 0x1E2C98u: goto label_1e2c98;
            case 0x1E2CD8u: goto label_1e2cd8;
            case 0x1E2CE8u: goto label_1e2ce8;
            case 0x1E2D0Cu: goto label_1e2d0c;
            case 0x1E2D1Cu: goto label_1e2d1c;
            case 0x1E2D40u: goto label_1e2d40;
            case 0x1E2D54u: goto label_1e2d54;
            case 0x1E2E10u: goto label_1e2e10;
            case 0x1E2E18u: goto label_1e2e18;
            case 0x1E2E20u: goto label_1e2e20;
            case 0x1E2E48u: goto label_1e2e48;
            case 0x1E2E64u: goto label_1e2e64;
            case 0x1E2E78u: goto label_1e2e78;
            case 0x1E2E94u: goto label_1e2e94;
            case 0x1E2EF8u: goto label_1e2ef8;
            case 0x1E2F0Cu: goto label_1e2f0c;
            case 0x1E2F4Cu: goto label_1e2f4c;
            case 0x1E2F5Cu: goto label_1e2f5c;
            case 0x1E2F80u: goto label_1e2f80;
            case 0x1E2FA8u: goto label_1e2fa8;
            case 0x1E2FC4u: goto label_1e2fc4;
            case 0x1E2FD8u: goto label_1e2fd8;
            case 0x1E2FF4u: goto label_1e2ff4;
            case 0x1E3058u: goto label_1e3058;
            case 0x1E306Cu: goto label_1e306c;
            case 0x1E30ACu: goto label_1e30ac;
            case 0x1E30BCu: goto label_1e30bc;
            case 0x1E30E0u: goto label_1e30e0;
            case 0x1E3108u: goto label_1e3108;
            case 0x1E3124u: goto label_1e3124;
            case 0x1E3138u: goto label_1e3138;
            case 0x1E3154u: goto label_1e3154;
            case 0x1E31CCu: goto label_1e31cc;
            case 0x1E31E0u: goto label_1e31e0;
            case 0x1E3220u: goto label_1e3220;
            case 0x1E3238u: goto label_1e3238;
            case 0x1E325Cu: goto label_1e325c;
            case 0x1E3278u: goto label_1e3278;
            case 0x1E329Cu: goto label_1e329c;
            case 0x1E32B0u: goto label_1e32b0;
            case 0x1E3318u: goto label_1e3318;
            case 0x1E3388u: goto label_1e3388;
            case 0x1E33C4u: goto label_1e33c4;
            case 0x1E33E0u: goto label_1e33e0;
            case 0x1E33F4u: goto label_1e33f4;
            case 0x1E3410u: goto label_1e3410;
            case 0x1E347Cu: goto label_1e347c;
            case 0x1E3490u: goto label_1e3490;
            case 0x1E34D0u: goto label_1e34d0;
            case 0x1E34E0u: goto label_1e34e0;
            case 0x1E3504u: goto label_1e3504;
            case 0x1E3514u: goto label_1e3514;
            case 0x1E3538u: goto label_1e3538;
            case 0x1E354Cu: goto label_1e354c;
            case 0x1E360Cu: goto label_1e360c;
            case 0x1E3628u: goto label_1e3628;
            case 0x1E363Cu: goto label_1e363c;
            case 0x1E3658u: goto label_1e3658;
            case 0x1E36C4u: goto label_1e36c4;
            case 0x1E36D8u: goto label_1e36d8;
            case 0x1E3718u: goto label_1e3718;
            case 0x1E3728u: goto label_1e3728;
            case 0x1E374Cu: goto label_1e374c;
            case 0x1E375Cu: goto label_1e375c;
            case 0x1E3780u: goto label_1e3780;
            case 0x1E3794u: goto label_1e3794;
            case 0x1E3854u: goto label_1e3854;
            case 0x1E3870u: goto label_1e3870;
            case 0x1E3884u: goto label_1e3884;
            case 0x1E38A0u: goto label_1e38a0;
            case 0x1E3908u: goto label_1e3908;
            case 0x1E391Cu: goto label_1e391c;
            case 0x1E395Cu: goto label_1e395c;
            case 0x1E396Cu: goto label_1e396c;
            case 0x1E3990u: goto label_1e3990;
            case 0x1E39A0u: goto label_1e39a0;
            case 0x1E39C4u: goto label_1e39c4;
            case 0x1E39D8u: goto label_1e39d8;
            case 0x1E3A44u: goto label_1e3a44;
            case 0x1E3A60u: goto label_1e3a60;
            case 0x1E3A74u: goto label_1e3a74;
            case 0x1E3A78u: goto label_1e3a78;
            case 0x1E3ADCu: goto label_1e3adc;
            case 0x1E3AF0u: goto label_1e3af0;
            case 0x1E3B30u: goto label_1e3b30;
            case 0x1E3B40u: goto label_1e3b40;
            case 0x1E3B64u: goto label_1e3b64;
            case 0x1E3B84u: goto label_1e3b84;
            case 0x1E3BA0u: goto label_1e3ba0;
            case 0x1E3BB4u: goto label_1e3bb4;
            case 0x1E3BB8u: goto label_1e3bb8;
            case 0x1E3C1Cu: goto label_1e3c1c;
            case 0x1E3C30u: goto label_1e3c30;
            case 0x1E3C70u: goto label_1e3c70;
            case 0x1E3C80u: goto label_1e3c80;
            case 0x1E3CA4u: goto label_1e3ca4;
            case 0x1E3CC4u: goto label_1e3cc4;
            case 0x1E3CE8u: goto label_1e3ce8;
            case 0x1E3CFCu: goto label_1e3cfc;
            case 0x1E3D00u: goto label_1e3d00;
            case 0x1E3D68u: goto label_1e3d68;
            case 0x1E3D7Cu: goto label_1e3d7c;
            case 0x1E3DBCu: goto label_1e3dbc;
            case 0x1E3DCCu: goto label_1e3dcc;
            case 0x1E3DF0u: goto label_1e3df0;
            case 0x1E3E00u: goto label_1e3e00;
            case 0x1E3E24u: goto label_1e3e24;
            case 0x1E3E38u: goto label_1e3e38;
            case 0x1E3EA4u: goto label_1e3ea4;
            case 0x1E3EC0u: goto label_1e3ec0;
            case 0x1E3ED4u: goto label_1e3ed4;
            case 0x1E3ED8u: goto label_1e3ed8;
            case 0x1E3F40u: goto label_1e3f40;
            case 0x1E3F54u: goto label_1e3f54;
            case 0x1E3F94u: goto label_1e3f94;
            case 0x1E3FA4u: goto label_1e3fa4;
            case 0x1E3FC8u: goto label_1e3fc8;
            case 0x1E3FD8u: goto label_1e3fd8;
            case 0x1E3FFCu: goto label_1e3ffc;
            case 0x1E4010u: goto label_1e4010;
            case 0x1E407Cu: goto label_1e407c;
            case 0x1E4098u: goto label_1e4098;
            case 0x1E40ACu: goto label_1e40ac;
            case 0x1E40B0u: goto label_1e40b0;
            case 0x1E4118u: goto label_1e4118;
            case 0x1E412Cu: goto label_1e412c;
            case 0x1E416Cu: goto label_1e416c;
            case 0x1E417Cu: goto label_1e417c;
            case 0x1E41A0u: goto label_1e41a0;
            case 0x1E41B0u: goto label_1e41b0;
            case 0x1E41D4u: goto label_1e41d4;
            case 0x1E41E8u: goto label_1e41e8;
            case 0x1E4254u: goto label_1e4254;
            case 0x1E4270u: goto label_1e4270;
            case 0x1E4284u: goto label_1e4284;
            case 0x1E4288u: goto label_1e4288;
            case 0x1E42F0u: goto label_1e42f0;
            case 0x1E4304u: goto label_1e4304;
            case 0x1E4344u: goto label_1e4344;
            case 0x1E4358u: goto label_1e4358;
            case 0x1E437Cu: goto label_1e437c;
            case 0x1E4394u: goto label_1e4394;
            case 0x1E43B8u: goto label_1e43b8;
            case 0x1E43CCu: goto label_1e43cc;
            case 0x1E43E4u: goto label_1e43e4;
            case 0x1E4414u: goto label_1e4414;
            case 0x1E4430u: goto label_1e4430;
            case 0x1E4444u: goto label_1e4444;
            case 0x1E4460u: goto label_1e4460;
            case 0x1E44C8u: goto label_1e44c8;
            case 0x1E44DCu: goto label_1e44dc;
            case 0x1E451Cu: goto label_1e451c;
            case 0x1E452Cu: goto label_1e452c;
            case 0x1E4550u: goto label_1e4550;
            case 0x1E4560u: goto label_1e4560;
            case 0x1E4584u: goto label_1e4584;
            case 0x1E4598u: goto label_1e4598;
            case 0x1E460Cu: goto label_1e460c;
            case 0x1E4628u: goto label_1e4628;
            case 0x1E463Cu: goto label_1e463c;
            case 0x1E4658u: goto label_1e4658;
            case 0x1E46C8u: goto label_1e46c8;
            case 0x1E46DCu: goto label_1e46dc;
            case 0x1E471Cu: goto label_1e471c;
            case 0x1E472Cu: goto label_1e472c;
            case 0x1E4750u: goto label_1e4750;
            case 0x1E4764u: goto label_1e4764;
            case 0x1E4788u: goto label_1e4788;
            case 0x1E479Cu: goto label_1e479c;
            case 0x1E47B0u: goto label_1e47b0;
            case 0x1E47E0u: goto label_1e47e0;
            case 0x1E47FCu: goto label_1e47fc;
            case 0x1E4800u: goto label_1e4800;
            case 0x1E48A0u: goto label_1e48a0;
            case 0x1E48B4u: goto label_1e48b4;
            case 0x1E48F4u: goto label_1e48f4;
            case 0x1E4918u: goto label_1e4918;
            case 0x1E493Cu: goto label_1e493c;
            case 0x1E4974u: goto label_1e4974;
            case 0x1E4998u: goto label_1e4998;
            case 0x1E49ACu: goto label_1e49ac;
            case 0x1E4A08u: goto label_1e4a08;
            case 0x1E4A24u: goto label_1e4a24;
            case 0x1E4AACu: goto label_1e4aac;
            case 0x1E4AC0u: goto label_1e4ac0;
            case 0x1E4B00u: goto label_1e4b00;
            case 0x1E4B1Cu: goto label_1e4b1c;
            case 0x1E4B20u: goto label_1e4b20;
            case 0x1E4B94u: goto label_1e4b94;
            case 0x1E4BA8u: goto label_1e4ba8;
            case 0x1E4BE8u: goto label_1e4be8;
            case 0x1E4C10u: goto label_1e4c10;
            case 0x1E4C34u: goto label_1e4c34;
            case 0x1E4C64u: goto label_1e4c64;
            case 0x1E4C88u: goto label_1e4c88;
            case 0x1E4C9Cu: goto label_1e4c9c;
            case 0x1E4D08u: goto label_1e4d08;
            case 0x1E4D28u: goto label_1e4d28;
            case 0x1E4DE4u: goto label_1e4de4;
            case 0x1E4DF8u: goto label_1e4df8;
            case 0x1E4E3Cu: goto label_1e4e3c;
            case 0x1E4E58u: goto label_1e4e58;
            case 0x1E4E5Cu: goto label_1e4e5c;
            case 0x1E4EC4u: goto label_1e4ec4;
            case 0x1E4ED8u: goto label_1e4ed8;
            case 0x1E4F18u: goto label_1e4f18;
            case 0x1E4F28u: goto label_1e4f28;
            case 0x1E4F4Cu: goto label_1e4f4c;
            case 0x1E4F60u: goto label_1e4f60;
            case 0x1E4F84u: goto label_1e4f84;
            case 0x1E4F98u: goto label_1e4f98;
            case 0x1E4FACu: goto label_1e4fac;
            case 0x1E4FD0u: goto label_1e4fd0;
            case 0x1E4FECu: goto label_1e4fec;
            case 0x1E4FF0u: goto label_1e4ff0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E38B8u;
    // 0x1e38b8: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1e38b8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1e38bc: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1e38bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1e38c0: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1e38c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1e38c4: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e38c4u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e38c8: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e38c8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e38cc: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e38ccu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e38d0: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e38d0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e38d4: 0xafc00010  sw          $zero, 0x10($fp)
    ctx->pc = 0x1e38d4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 0));
    // 0x1e38d8: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e38d8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e38dc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e38dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e38e0: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E38E0u;
    {
        const bool branch_taken_0x1e38e0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e38e0) {
            ctx->pc = 0x1E3908u;
            goto label_1e3908;
        }
    }
    ctx->pc = 0x1E38E8u;
    // 0x1e38e8: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e38e8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e38ec: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e38ecu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e38f0: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e38f0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e38f4: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e38f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e38f8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e38f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e38fc: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e38fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e3900: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E3900u;
    {
        const bool branch_taken_0x1e3900 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e3900) {
            ctx->pc = 0x1E391Cu;
            goto label_1e391c;
        }
    }
    ctx->pc = 0x1E3908u;
label_1e3908:
    // 0x1e3908: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e3908u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e390c: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e390cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e3910: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e3910u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e3914: 0x10000058  b           . + 4 + (0x58 << 2)
    ctx->pc = 0x1E3914u;
    {
        const bool branch_taken_0x1e3914 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3914) {
            ctx->pc = 0x1E3A78u;
            goto label_1e3a78;
        }
    }
    ctx->pc = 0x1E391Cu;
label_1e391c:
    // 0x1e391c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e391cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e3920: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e3920u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e3924: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e3924u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e3928: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e3928u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e392c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e392cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e3930: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e3930u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e3934: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1e3934u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1e3938: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e3938u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e393c: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e393cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e3940: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E3940u;
    {
        const bool branch_taken_0x1e3940 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3940) {
            ctx->pc = 0x1E395Cu;
            goto label_1e395c;
        }
    }
    ctx->pc = 0x1E3948u;
    // 0x1e3948: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e3948u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e394c: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e394cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e3950: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e3950u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e3954: 0x10000048  b           . + 4 + (0x48 << 2)
    ctx->pc = 0x1E3954u;
    {
        const bool branch_taken_0x1e3954 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3954) {
            ctx->pc = 0x1E3A78u;
            goto label_1e3a78;
        }
    }
    ctx->pc = 0x1E395Cu;
label_1e395c:
    // 0x1e395c: 0x8fc40010  lw          $a0, 0x10($fp)
    ctx->pc = 0x1e395cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e3960: 0x24050004  addiu       $a1, $zero, 0x4
    ctx->pc = 0x1e3960u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1e3964: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E3964u;
    SET_GPR_U32(ctx, 31, 0x1E396Cu);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E396Cu; }
        if (ctx->pc != 0x1E396Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E396Cu; }
        if (ctx->pc != 0x1E396Cu) { return; }
    }
    ctx->pc = 0x1E396Cu;
label_1e396c:
    // 0x1e396c: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1e396cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1e3970: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e3970u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e3974: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E3974u;
    {
        const bool branch_taken_0x1e3974 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e3974) {
            ctx->pc = 0x1E3990u;
            goto label_1e3990;
        }
    }
    ctx->pc = 0x1E397Cu;
    // 0x1e397c: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e397cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e3980: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e3980u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e3984: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e3984u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e3988: 0x1000003b  b           . + 4 + (0x3B << 2)
    ctx->pc = 0x1E3988u;
    {
        const bool branch_taken_0x1e3988 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3988) {
            ctx->pc = 0x1E3A78u;
            goto label_1e3a78;
        }
    }
    ctx->pc = 0x1E3990u;
label_1e3990:
    // 0x1e3990: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1e3990u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e3994: 0x24050004  addiu       $a1, $zero, 0x4
    ctx->pc = 0x1e3994u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1e3998: 0xc07cc3c  jal         func_1F30F0
    ctx->pc = 0x1E3998u;
    SET_GPR_U32(ctx, 31, 0x1E39A0u);
    ctx->pc = 0x1F30F0u;
    if (runtime->hasFunction(0x1F30F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F30F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E39A0u; }
        if (ctx->pc != 0x1E39A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F30F0_0x1f30f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E39A0u; }
        if (ctx->pc != 0x1E39A0u) { return; }
    }
    ctx->pc = 0x1E39A0u;
label_1e39a0:
    // 0x1e39a0: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1e39a0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1e39a4: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e39a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e39a8: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1E39A8u;
    {
        const bool branch_taken_0x1e39a8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e39a8) {
            ctx->pc = 0x1E39D8u;
            goto label_1e39d8;
        }
    }
    ctx->pc = 0x1E39B0u;
    // 0x1e39b0: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e39b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e39b4: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1e39b4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1e39b8: 0x8fc5000c  lw          $a1, 0xC($fp)
    ctx->pc = 0x1e39b8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e39bc: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1E39BCu;
    SET_GPR_U32(ctx, 31, 0x1E39C4u);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E39C4u; }
        if (ctx->pc != 0x1E39C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E39C4u; }
        if (ctx->pc != 0x1E39C4u) { return; }
    }
    ctx->pc = 0x1E39C4u;
label_1e39c4:
    // 0x1e39c4: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e39c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e39c8: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e39c8u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e39cc: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e39ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e39d0: 0x10000029  b           . + 4 + (0x29 << 2)
    ctx->pc = 0x1E39D0u;
    {
        const bool branch_taken_0x1e39d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e39d0) {
            ctx->pc = 0x1E3A78u;
            goto label_1e3a78;
        }
    }
    ctx->pc = 0x1E39D8u;
label_1e39d8:
    // 0x1e39d8: 0x8fc50014  lw          $a1, 0x14($fp)
    ctx->pc = 0x1e39d8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e39dc: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e39dcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e39e0: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1e39e0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1e39e4: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1e39e4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1e39e8: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e39e8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e39ec: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1e39ecu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1e39f0: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1e39f0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1e39f4: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1e39f4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e39f8: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1e39f8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e39fc: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1e39fcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1e3a00: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e3a00u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e3a04: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1e3a04u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1e3a08: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1e3a08u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e3a0c: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1e3a0cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e3a10: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1e3a10u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1e3a14: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e3a14u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e3a18: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1e3a18u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1e3a1c: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1e3a1cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e3a20: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x1e3a20u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x1e3a24: 0x8fc40010  lw          $a0, 0x10($fp)
    ctx->pc = 0x1e3a24u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e3a28: 0x8fc5000c  lw          $a1, 0xC($fp)
    ctx->pc = 0x1e3a28u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e3a2c: 0x3406b000  ori         $a2, $zero, 0xB000
    ctx->pc = 0x1e3a2cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)45056);
    // 0x1e3a30: 0x24070004  addiu       $a3, $zero, 0x4
    ctx->pc = 0x1e3a30u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1e3a34: 0x2408000b  addiu       $t0, $zero, 0xB
    ctx->pc = 0x1e3a34u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 11));
    // 0x1e3a38: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1e3a38u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e3a3c: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E3A3Cu;
    SET_GPR_U32(ctx, 31, 0x1E3A44u);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3A44u; }
        if (ctx->pc != 0x1E3A44u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3A44u; }
        if (ctx->pc != 0x1E3A44u) { return; }
    }
    ctx->pc = 0x1E3A44u;
label_1e3a44:
    // 0x1e3a44: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E3A44u;
    {
        const bool branch_taken_0x1e3a44 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3a44) {
            ctx->pc = 0x1E3A60u;
            goto label_1e3a60;
        }
    }
    ctx->pc = 0x1E3A4Cu;
    // 0x1e3a4c: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e3a4cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e3a50: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e3a50u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e3a54: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e3a54u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e3a58: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1E3A58u;
    {
        const bool branch_taken_0x1e3a58 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3a58) {
            ctx->pc = 0x1E3A78u;
            goto label_1e3a78;
        }
    }
    ctx->pc = 0x1E3A60u;
label_1e3a60:
    // 0x1e3a60: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1e3a60u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e3a64: 0x2405001b  addiu       $a1, $zero, 0x1B
    ctx->pc = 0x1e3a64u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 27));
    // 0x1e3a68: 0x8fc60008  lw          $a2, 0x8($fp)
    ctx->pc = 0x1e3a68u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e3a6c: 0xc076ad5  jal         func_1DAB54
    ctx->pc = 0x1E3A6Cu;
    SET_GPR_U32(ctx, 31, 0x1E3A74u);
    ctx->pc = 0x1DAB54u;
    if (runtime->hasFunction(0x1DAB54u)) {
        auto targetFn = runtime->lookupFunction(0x1DAB54u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3A74u; }
        if (ctx->pc != 0x1E3A74u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DAB54_0x1dab54(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3A74u; }
        if (ctx->pc != 0x1E3A74u) { return; }
    }
    ctx->pc = 0x1E3A74u;
label_1e3a74:
    // 0x1e3a74: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1e3a74u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1e3a78:
    // 0x1e3a78: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e3a78u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e3a7c: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1e3a7cu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1e3a80: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1e3a80u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1e3a84: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1e3a84u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1e3a88: 0x3e00008  jr          $ra
    ctx->pc = 0x1E3A88u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E1B3Cu: goto label_1e1b3c;
            case 0x1E1B60u: goto label_1e1b60;
            case 0x1E1B84u: goto label_1e1b84;
            case 0x1E1BA8u: goto label_1e1ba8;
            case 0x1E1BC8u: goto label_1e1bc8;
            case 0x1E1BE4u: goto label_1e1be4;
            case 0x1E1BE8u: goto label_1e1be8;
            case 0x1E1C44u: goto label_1e1c44;
            case 0x1E1C58u: goto label_1e1c58;
            case 0x1E1C7Cu: goto label_1e1c7c;
            case 0x1E1CD8u: goto label_1e1cd8;
            case 0x1E1CECu: goto label_1e1cec;
            case 0x1E1D14u: goto label_1e1d14;
            case 0x1E1D7Cu: goto label_1e1d7c;
            case 0x1E1D90u: goto label_1e1d90;
            case 0x1E1DD0u: goto label_1e1dd0;
            case 0x1E1DE0u: goto label_1e1de0;
            case 0x1E1E04u: goto label_1e1e04;
            case 0x1E1E14u: goto label_1e1e14;
            case 0x1E1E38u: goto label_1e1e38;
            case 0x1E1E4Cu: goto label_1e1e4c;
            case 0x1E1E5Cu: goto label_1e1e5c;
            case 0x1E1E84u: goto label_1e1e84;
            case 0x1E1EA0u: goto label_1e1ea0;
            case 0x1E1EB4u: goto label_1e1eb4;
            case 0x1E1ED0u: goto label_1e1ed0;
            case 0x1E1F48u: goto label_1e1f48;
            case 0x1E1F5Cu: goto label_1e1f5c;
            case 0x1E1F9Cu: goto label_1e1f9c;
            case 0x1E1FACu: goto label_1e1fac;
            case 0x1E1FD0u: goto label_1e1fd0;
            case 0x1E1FE0u: goto label_1e1fe0;
            case 0x1E2004u: goto label_1e2004;
            case 0x1E2018u: goto label_1e2018;
            case 0x1E202Cu: goto label_1e202c;
            case 0x1E2064u: goto label_1e2064;
            case 0x1E206Cu: goto label_1e206c;
            case 0x1E2088u: goto label_1e2088;
            case 0x1E20A0u: goto label_1e20a0;
            case 0x1E20D4u: goto label_1e20d4;
            case 0x1E20F8u: goto label_1e20f8;
            case 0x1E210Cu: goto label_1e210c;
            case 0x1E2128u: goto label_1e2128;
            case 0x1E2190u: goto label_1e2190;
            case 0x1E21A4u: goto label_1e21a4;
            case 0x1E21E4u: goto label_1e21e4;
            case 0x1E21F4u: goto label_1e21f4;
            case 0x1E2218u: goto label_1e2218;
            case 0x1E2228u: goto label_1e2228;
            case 0x1E224Cu: goto label_1e224c;
            case 0x1E2260u: goto label_1e2260;
            case 0x1E22D4u: goto label_1e22d4;
            case 0x1E22F0u: goto label_1e22f0;
            case 0x1E2304u: goto label_1e2304;
            case 0x1E2320u: goto label_1e2320;
            case 0x1E23A0u: goto label_1e23a0;
            case 0x1E23B4u: goto label_1e23b4;
            case 0x1E23F4u: goto label_1e23f4;
            case 0x1E2404u: goto label_1e2404;
            case 0x1E2428u: goto label_1e2428;
            case 0x1E2438u: goto label_1e2438;
            case 0x1E245Cu: goto label_1e245c;
            case 0x1E2470u: goto label_1e2470;
            case 0x1E2480u: goto label_1e2480;
            case 0x1E24F8u: goto label_1e24f8;
            case 0x1E2500u: goto label_1e2500;
            case 0x1E2508u: goto label_1e2508;
            case 0x1E25D0u: goto label_1e25d0;
            case 0x1E25ECu: goto label_1e25ec;
            case 0x1E2600u: goto label_1e2600;
            case 0x1E261Cu: goto label_1e261c;
            case 0x1E2684u: goto label_1e2684;
            case 0x1E2698u: goto label_1e2698;
            case 0x1E26D8u: goto label_1e26d8;
            case 0x1E26E8u: goto label_1e26e8;
            case 0x1E270Cu: goto label_1e270c;
            case 0x1E271Cu: goto label_1e271c;
            case 0x1E2740u: goto label_1e2740;
            case 0x1E2754u: goto label_1e2754;
            case 0x1E27C8u: goto label_1e27c8;
            case 0x1E27E4u: goto label_1e27e4;
            case 0x1E27F8u: goto label_1e27f8;
            case 0x1E2814u: goto label_1e2814;
            case 0x1E287Cu: goto label_1e287c;
            case 0x1E2890u: goto label_1e2890;
            case 0x1E28D0u: goto label_1e28d0;
            case 0x1E28E0u: goto label_1e28e0;
            case 0x1E2904u: goto label_1e2904;
            case 0x1E2914u: goto label_1e2914;
            case 0x1E2938u: goto label_1e2938;
            case 0x1E294Cu: goto label_1e294c;
            case 0x1E29C0u: goto label_1e29c0;
            case 0x1E29DCu: goto label_1e29dc;
            case 0x1E29F0u: goto label_1e29f0;
            case 0x1E2A0Cu: goto label_1e2a0c;
            case 0x1E2A78u: goto label_1e2a78;
            case 0x1E2A8Cu: goto label_1e2a8c;
            case 0x1E2ACCu: goto label_1e2acc;
            case 0x1E2ADCu: goto label_1e2adc;
            case 0x1E2B00u: goto label_1e2b00;
            case 0x1E2B10u: goto label_1e2b10;
            case 0x1E2B34u: goto label_1e2b34;
            case 0x1E2B48u: goto label_1e2b48;
            case 0x1E2B54u: goto label_1e2b54;
            case 0x1E2B90u: goto label_1e2b90;
            case 0x1E2B98u: goto label_1e2b98;
            case 0x1E2BC0u: goto label_1e2bc0;
            case 0x1E2BE4u: goto label_1e2be4;
            case 0x1E2BF8u: goto label_1e2bf8;
            case 0x1E2C14u: goto label_1e2c14;
            case 0x1E2C84u: goto label_1e2c84;
            case 0x1E2C98u: goto label_1e2c98;
            case 0x1E2CD8u: goto label_1e2cd8;
            case 0x1E2CE8u: goto label_1e2ce8;
            case 0x1E2D0Cu: goto label_1e2d0c;
            case 0x1E2D1Cu: goto label_1e2d1c;
            case 0x1E2D40u: goto label_1e2d40;
            case 0x1E2D54u: goto label_1e2d54;
            case 0x1E2E10u: goto label_1e2e10;
            case 0x1E2E18u: goto label_1e2e18;
            case 0x1E2E20u: goto label_1e2e20;
            case 0x1E2E48u: goto label_1e2e48;
            case 0x1E2E64u: goto label_1e2e64;
            case 0x1E2E78u: goto label_1e2e78;
            case 0x1E2E94u: goto label_1e2e94;
            case 0x1E2EF8u: goto label_1e2ef8;
            case 0x1E2F0Cu: goto label_1e2f0c;
            case 0x1E2F4Cu: goto label_1e2f4c;
            case 0x1E2F5Cu: goto label_1e2f5c;
            case 0x1E2F80u: goto label_1e2f80;
            case 0x1E2FA8u: goto label_1e2fa8;
            case 0x1E2FC4u: goto label_1e2fc4;
            case 0x1E2FD8u: goto label_1e2fd8;
            case 0x1E2FF4u: goto label_1e2ff4;
            case 0x1E3058u: goto label_1e3058;
            case 0x1E306Cu: goto label_1e306c;
            case 0x1E30ACu: goto label_1e30ac;
            case 0x1E30BCu: goto label_1e30bc;
            case 0x1E30E0u: goto label_1e30e0;
            case 0x1E3108u: goto label_1e3108;
            case 0x1E3124u: goto label_1e3124;
            case 0x1E3138u: goto label_1e3138;
            case 0x1E3154u: goto label_1e3154;
            case 0x1E31CCu: goto label_1e31cc;
            case 0x1E31E0u: goto label_1e31e0;
            case 0x1E3220u: goto label_1e3220;
            case 0x1E3238u: goto label_1e3238;
            case 0x1E325Cu: goto label_1e325c;
            case 0x1E3278u: goto label_1e3278;
            case 0x1E329Cu: goto label_1e329c;
            case 0x1E32B0u: goto label_1e32b0;
            case 0x1E3318u: goto label_1e3318;
            case 0x1E3388u: goto label_1e3388;
            case 0x1E33C4u: goto label_1e33c4;
            case 0x1E33E0u: goto label_1e33e0;
            case 0x1E33F4u: goto label_1e33f4;
            case 0x1E3410u: goto label_1e3410;
            case 0x1E347Cu: goto label_1e347c;
            case 0x1E3490u: goto label_1e3490;
            case 0x1E34D0u: goto label_1e34d0;
            case 0x1E34E0u: goto label_1e34e0;
            case 0x1E3504u: goto label_1e3504;
            case 0x1E3514u: goto label_1e3514;
            case 0x1E3538u: goto label_1e3538;
            case 0x1E354Cu: goto label_1e354c;
            case 0x1E360Cu: goto label_1e360c;
            case 0x1E3628u: goto label_1e3628;
            case 0x1E363Cu: goto label_1e363c;
            case 0x1E3658u: goto label_1e3658;
            case 0x1E36C4u: goto label_1e36c4;
            case 0x1E36D8u: goto label_1e36d8;
            case 0x1E3718u: goto label_1e3718;
            case 0x1E3728u: goto label_1e3728;
            case 0x1E374Cu: goto label_1e374c;
            case 0x1E375Cu: goto label_1e375c;
            case 0x1E3780u: goto label_1e3780;
            case 0x1E3794u: goto label_1e3794;
            case 0x1E3854u: goto label_1e3854;
            case 0x1E3870u: goto label_1e3870;
            case 0x1E3884u: goto label_1e3884;
            case 0x1E38A0u: goto label_1e38a0;
            case 0x1E3908u: goto label_1e3908;
            case 0x1E391Cu: goto label_1e391c;
            case 0x1E395Cu: goto label_1e395c;
            case 0x1E396Cu: goto label_1e396c;
            case 0x1E3990u: goto label_1e3990;
            case 0x1E39A0u: goto label_1e39a0;
            case 0x1E39C4u: goto label_1e39c4;
            case 0x1E39D8u: goto label_1e39d8;
            case 0x1E3A44u: goto label_1e3a44;
            case 0x1E3A60u: goto label_1e3a60;
            case 0x1E3A74u: goto label_1e3a74;
            case 0x1E3A78u: goto label_1e3a78;
            case 0x1E3ADCu: goto label_1e3adc;
            case 0x1E3AF0u: goto label_1e3af0;
            case 0x1E3B30u: goto label_1e3b30;
            case 0x1E3B40u: goto label_1e3b40;
            case 0x1E3B64u: goto label_1e3b64;
            case 0x1E3B84u: goto label_1e3b84;
            case 0x1E3BA0u: goto label_1e3ba0;
            case 0x1E3BB4u: goto label_1e3bb4;
            case 0x1E3BB8u: goto label_1e3bb8;
            case 0x1E3C1Cu: goto label_1e3c1c;
            case 0x1E3C30u: goto label_1e3c30;
            case 0x1E3C70u: goto label_1e3c70;
            case 0x1E3C80u: goto label_1e3c80;
            case 0x1E3CA4u: goto label_1e3ca4;
            case 0x1E3CC4u: goto label_1e3cc4;
            case 0x1E3CE8u: goto label_1e3ce8;
            case 0x1E3CFCu: goto label_1e3cfc;
            case 0x1E3D00u: goto label_1e3d00;
            case 0x1E3D68u: goto label_1e3d68;
            case 0x1E3D7Cu: goto label_1e3d7c;
            case 0x1E3DBCu: goto label_1e3dbc;
            case 0x1E3DCCu: goto label_1e3dcc;
            case 0x1E3DF0u: goto label_1e3df0;
            case 0x1E3E00u: goto label_1e3e00;
            case 0x1E3E24u: goto label_1e3e24;
            case 0x1E3E38u: goto label_1e3e38;
            case 0x1E3EA4u: goto label_1e3ea4;
            case 0x1E3EC0u: goto label_1e3ec0;
            case 0x1E3ED4u: goto label_1e3ed4;
            case 0x1E3ED8u: goto label_1e3ed8;
            case 0x1E3F40u: goto label_1e3f40;
            case 0x1E3F54u: goto label_1e3f54;
            case 0x1E3F94u: goto label_1e3f94;
            case 0x1E3FA4u: goto label_1e3fa4;
            case 0x1E3FC8u: goto label_1e3fc8;
            case 0x1E3FD8u: goto label_1e3fd8;
            case 0x1E3FFCu: goto label_1e3ffc;
            case 0x1E4010u: goto label_1e4010;
            case 0x1E407Cu: goto label_1e407c;
            case 0x1E4098u: goto label_1e4098;
            case 0x1E40ACu: goto label_1e40ac;
            case 0x1E40B0u: goto label_1e40b0;
            case 0x1E4118u: goto label_1e4118;
            case 0x1E412Cu: goto label_1e412c;
            case 0x1E416Cu: goto label_1e416c;
            case 0x1E417Cu: goto label_1e417c;
            case 0x1E41A0u: goto label_1e41a0;
            case 0x1E41B0u: goto label_1e41b0;
            case 0x1E41D4u: goto label_1e41d4;
            case 0x1E41E8u: goto label_1e41e8;
            case 0x1E4254u: goto label_1e4254;
            case 0x1E4270u: goto label_1e4270;
            case 0x1E4284u: goto label_1e4284;
            case 0x1E4288u: goto label_1e4288;
            case 0x1E42F0u: goto label_1e42f0;
            case 0x1E4304u: goto label_1e4304;
            case 0x1E4344u: goto label_1e4344;
            case 0x1E4358u: goto label_1e4358;
            case 0x1E437Cu: goto label_1e437c;
            case 0x1E4394u: goto label_1e4394;
            case 0x1E43B8u: goto label_1e43b8;
            case 0x1E43CCu: goto label_1e43cc;
            case 0x1E43E4u: goto label_1e43e4;
            case 0x1E4414u: goto label_1e4414;
            case 0x1E4430u: goto label_1e4430;
            case 0x1E4444u: goto label_1e4444;
            case 0x1E4460u: goto label_1e4460;
            case 0x1E44C8u: goto label_1e44c8;
            case 0x1E44DCu: goto label_1e44dc;
            case 0x1E451Cu: goto label_1e451c;
            case 0x1E452Cu: goto label_1e452c;
            case 0x1E4550u: goto label_1e4550;
            case 0x1E4560u: goto label_1e4560;
            case 0x1E4584u: goto label_1e4584;
            case 0x1E4598u: goto label_1e4598;
            case 0x1E460Cu: goto label_1e460c;
            case 0x1E4628u: goto label_1e4628;
            case 0x1E463Cu: goto label_1e463c;
            case 0x1E4658u: goto label_1e4658;
            case 0x1E46C8u: goto label_1e46c8;
            case 0x1E46DCu: goto label_1e46dc;
            case 0x1E471Cu: goto label_1e471c;
            case 0x1E472Cu: goto label_1e472c;
            case 0x1E4750u: goto label_1e4750;
            case 0x1E4764u: goto label_1e4764;
            case 0x1E4788u: goto label_1e4788;
            case 0x1E479Cu: goto label_1e479c;
            case 0x1E47B0u: goto label_1e47b0;
            case 0x1E47E0u: goto label_1e47e0;
            case 0x1E47FCu: goto label_1e47fc;
            case 0x1E4800u: goto label_1e4800;
            case 0x1E48A0u: goto label_1e48a0;
            case 0x1E48B4u: goto label_1e48b4;
            case 0x1E48F4u: goto label_1e48f4;
            case 0x1E4918u: goto label_1e4918;
            case 0x1E493Cu: goto label_1e493c;
            case 0x1E4974u: goto label_1e4974;
            case 0x1E4998u: goto label_1e4998;
            case 0x1E49ACu: goto label_1e49ac;
            case 0x1E4A08u: goto label_1e4a08;
            case 0x1E4A24u: goto label_1e4a24;
            case 0x1E4AACu: goto label_1e4aac;
            case 0x1E4AC0u: goto label_1e4ac0;
            case 0x1E4B00u: goto label_1e4b00;
            case 0x1E4B1Cu: goto label_1e4b1c;
            case 0x1E4B20u: goto label_1e4b20;
            case 0x1E4B94u: goto label_1e4b94;
            case 0x1E4BA8u: goto label_1e4ba8;
            case 0x1E4BE8u: goto label_1e4be8;
            case 0x1E4C10u: goto label_1e4c10;
            case 0x1E4C34u: goto label_1e4c34;
            case 0x1E4C64u: goto label_1e4c64;
            case 0x1E4C88u: goto label_1e4c88;
            case 0x1E4C9Cu: goto label_1e4c9c;
            case 0x1E4D08u: goto label_1e4d08;
            case 0x1E4D28u: goto label_1e4d28;
            case 0x1E4DE4u: goto label_1e4de4;
            case 0x1E4DF8u: goto label_1e4df8;
            case 0x1E4E3Cu: goto label_1e4e3c;
            case 0x1E4E58u: goto label_1e4e58;
            case 0x1E4E5Cu: goto label_1e4e5c;
            case 0x1E4EC4u: goto label_1e4ec4;
            case 0x1E4ED8u: goto label_1e4ed8;
            case 0x1E4F18u: goto label_1e4f18;
            case 0x1E4F28u: goto label_1e4f28;
            case 0x1E4F4Cu: goto label_1e4f4c;
            case 0x1E4F60u: goto label_1e4f60;
            case 0x1E4F84u: goto label_1e4f84;
            case 0x1E4F98u: goto label_1e4f98;
            case 0x1E4FACu: goto label_1e4fac;
            case 0x1E4FD0u: goto label_1e4fd0;
            case 0x1E4FECu: goto label_1e4fec;
            case 0x1E4FF0u: goto label_1e4ff0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E3A90u;
    // 0x1e3a90: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1e3a90u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1e3a94: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1e3a94u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1e3a98: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1e3a98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1e3a9c: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e3a9cu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e3aa0: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e3aa0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e3aa4: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e3aa4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e3aa8: 0xafc0000c  sw          $zero, 0xC($fp)
    ctx->pc = 0x1e3aa8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 0));
    // 0x1e3aac: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e3aacu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e3ab0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e3ab0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e3ab4: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E3AB4u;
    {
        const bool branch_taken_0x1e3ab4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e3ab4) {
            ctx->pc = 0x1E3ADCu;
            goto label_1e3adc;
        }
    }
    ctx->pc = 0x1E3ABCu;
    // 0x1e3abc: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e3abcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e3ac0: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e3ac0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e3ac4: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e3ac4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e3ac8: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e3ac8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e3acc: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e3accu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e3ad0: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e3ad0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e3ad4: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E3AD4u;
    {
        const bool branch_taken_0x1e3ad4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e3ad4) {
            ctx->pc = 0x1E3AF0u;
            goto label_1e3af0;
        }
    }
    ctx->pc = 0x1E3ADCu;
label_1e3adc:
    // 0x1e3adc: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e3adcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e3ae0: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e3ae0u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e3ae4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e3ae4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e3ae8: 0x10000033  b           . + 4 + (0x33 << 2)
    ctx->pc = 0x1E3AE8u;
    {
        const bool branch_taken_0x1e3ae8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3ae8) {
            ctx->pc = 0x1E3BB8u;
            goto label_1e3bb8;
        }
    }
    ctx->pc = 0x1E3AF0u;
label_1e3af0:
    // 0x1e3af0: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e3af0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e3af4: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e3af4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e3af8: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e3af8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e3afc: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e3afcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e3b00: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e3b00u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e3b04: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e3b04u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e3b08: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1e3b08u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1e3b0c: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e3b0cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e3b10: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e3b10u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e3b14: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E3B14u;
    {
        const bool branch_taken_0x1e3b14 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3b14) {
            ctx->pc = 0x1E3B30u;
            goto label_1e3b30;
        }
    }
    ctx->pc = 0x1E3B1Cu;
    // 0x1e3b1c: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e3b1cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e3b20: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e3b20u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e3b24: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e3b24u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e3b28: 0x10000023  b           . + 4 + (0x23 << 2)
    ctx->pc = 0x1E3B28u;
    {
        const bool branch_taken_0x1e3b28 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3b28) {
            ctx->pc = 0x1E3BB8u;
            goto label_1e3bb8;
        }
    }
    ctx->pc = 0x1E3B30u;
label_1e3b30:
    // 0x1e3b30: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1e3b30u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e3b34: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1e3b34u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e3b38: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E3B38u;
    SET_GPR_U32(ctx, 31, 0x1E3B40u);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3B40u; }
        if (ctx->pc != 0x1E3B40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3B40u; }
        if (ctx->pc != 0x1E3B40u) { return; }
    }
    ctx->pc = 0x1E3B40u;
label_1e3b40:
    // 0x1e3b40: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1e3b40u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1e3b44: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1e3b44u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e3b48: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E3B48u;
    {
        const bool branch_taken_0x1e3b48 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e3b48) {
            ctx->pc = 0x1E3B64u;
            goto label_1e3b64;
        }
    }
    ctx->pc = 0x1E3B50u;
    // 0x1e3b50: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e3b50u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e3b54: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e3b54u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e3b58: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e3b58u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e3b5c: 0x10000016  b           . + 4 + (0x16 << 2)
    ctx->pc = 0x1E3B5Cu;
    {
        const bool branch_taken_0x1e3b5c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3b5c) {
            ctx->pc = 0x1E3BB8u;
            goto label_1e3bb8;
        }
    }
    ctx->pc = 0x1E3B64u;
label_1e3b64:
    // 0x1e3b64: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1e3b64u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e3b68: 0x8fc50008  lw          $a1, 0x8($fp)
    ctx->pc = 0x1e3b68u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e3b6c: 0x3406b000  ori         $a2, $zero, 0xB000
    ctx->pc = 0x1e3b6cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)45056);
    // 0x1e3b70: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1e3b70u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e3b74: 0x2408000e  addiu       $t0, $zero, 0xE
    ctx->pc = 0x1e3b74u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
    // 0x1e3b78: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1e3b78u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e3b7c: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E3B7Cu;
    SET_GPR_U32(ctx, 31, 0x1E3B84u);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3B84u; }
        if (ctx->pc != 0x1E3B84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3B84u; }
        if (ctx->pc != 0x1E3B84u) { return; }
    }
    ctx->pc = 0x1E3B84u;
label_1e3b84:
    // 0x1e3b84: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E3B84u;
    {
        const bool branch_taken_0x1e3b84 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3b84) {
            ctx->pc = 0x1E3BA0u;
            goto label_1e3ba0;
        }
    }
    ctx->pc = 0x1E3B8Cu;
    // 0x1e3b8c: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e3b8cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e3b90: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e3b90u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e3b94: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e3b94u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e3b98: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1E3B98u;
    {
        const bool branch_taken_0x1e3b98 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3b98) {
            ctx->pc = 0x1E3BB8u;
            goto label_1e3bb8;
        }
    }
    ctx->pc = 0x1E3BA0u;
label_1e3ba0:
    // 0x1e3ba0: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1e3ba0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e3ba4: 0x2405001a  addiu       $a1, $zero, 0x1A
    ctx->pc = 0x1e3ba4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 26));
    // 0x1e3ba8: 0x8fc60004  lw          $a2, 0x4($fp)
    ctx->pc = 0x1e3ba8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e3bac: 0xc076ad5  jal         func_1DAB54
    ctx->pc = 0x1E3BACu;
    SET_GPR_U32(ctx, 31, 0x1E3BB4u);
    ctx->pc = 0x1DAB54u;
    if (runtime->hasFunction(0x1DAB54u)) {
        auto targetFn = runtime->lookupFunction(0x1DAB54u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3BB4u; }
        if (ctx->pc != 0x1E3BB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DAB54_0x1dab54(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3BB4u; }
        if (ctx->pc != 0x1E3BB4u) { return; }
    }
    ctx->pc = 0x1E3BB4u;
label_1e3bb4:
    // 0x1e3bb4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1e3bb4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1e3bb8:
    // 0x1e3bb8: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e3bb8u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e3bbc: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1e3bbcu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1e3bc0: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1e3bc0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1e3bc4: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1e3bc4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1e3bc8: 0x3e00008  jr          $ra
    ctx->pc = 0x1E3BC8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E1B3Cu: goto label_1e1b3c;
            case 0x1E1B60u: goto label_1e1b60;
            case 0x1E1B84u: goto label_1e1b84;
            case 0x1E1BA8u: goto label_1e1ba8;
            case 0x1E1BC8u: goto label_1e1bc8;
            case 0x1E1BE4u: goto label_1e1be4;
            case 0x1E1BE8u: goto label_1e1be8;
            case 0x1E1C44u: goto label_1e1c44;
            case 0x1E1C58u: goto label_1e1c58;
            case 0x1E1C7Cu: goto label_1e1c7c;
            case 0x1E1CD8u: goto label_1e1cd8;
            case 0x1E1CECu: goto label_1e1cec;
            case 0x1E1D14u: goto label_1e1d14;
            case 0x1E1D7Cu: goto label_1e1d7c;
            case 0x1E1D90u: goto label_1e1d90;
            case 0x1E1DD0u: goto label_1e1dd0;
            case 0x1E1DE0u: goto label_1e1de0;
            case 0x1E1E04u: goto label_1e1e04;
            case 0x1E1E14u: goto label_1e1e14;
            case 0x1E1E38u: goto label_1e1e38;
            case 0x1E1E4Cu: goto label_1e1e4c;
            case 0x1E1E5Cu: goto label_1e1e5c;
            case 0x1E1E84u: goto label_1e1e84;
            case 0x1E1EA0u: goto label_1e1ea0;
            case 0x1E1EB4u: goto label_1e1eb4;
            case 0x1E1ED0u: goto label_1e1ed0;
            case 0x1E1F48u: goto label_1e1f48;
            case 0x1E1F5Cu: goto label_1e1f5c;
            case 0x1E1F9Cu: goto label_1e1f9c;
            case 0x1E1FACu: goto label_1e1fac;
            case 0x1E1FD0u: goto label_1e1fd0;
            case 0x1E1FE0u: goto label_1e1fe0;
            case 0x1E2004u: goto label_1e2004;
            case 0x1E2018u: goto label_1e2018;
            case 0x1E202Cu: goto label_1e202c;
            case 0x1E2064u: goto label_1e2064;
            case 0x1E206Cu: goto label_1e206c;
            case 0x1E2088u: goto label_1e2088;
            case 0x1E20A0u: goto label_1e20a0;
            case 0x1E20D4u: goto label_1e20d4;
            case 0x1E20F8u: goto label_1e20f8;
            case 0x1E210Cu: goto label_1e210c;
            case 0x1E2128u: goto label_1e2128;
            case 0x1E2190u: goto label_1e2190;
            case 0x1E21A4u: goto label_1e21a4;
            case 0x1E21E4u: goto label_1e21e4;
            case 0x1E21F4u: goto label_1e21f4;
            case 0x1E2218u: goto label_1e2218;
            case 0x1E2228u: goto label_1e2228;
            case 0x1E224Cu: goto label_1e224c;
            case 0x1E2260u: goto label_1e2260;
            case 0x1E22D4u: goto label_1e22d4;
            case 0x1E22F0u: goto label_1e22f0;
            case 0x1E2304u: goto label_1e2304;
            case 0x1E2320u: goto label_1e2320;
            case 0x1E23A0u: goto label_1e23a0;
            case 0x1E23B4u: goto label_1e23b4;
            case 0x1E23F4u: goto label_1e23f4;
            case 0x1E2404u: goto label_1e2404;
            case 0x1E2428u: goto label_1e2428;
            case 0x1E2438u: goto label_1e2438;
            case 0x1E245Cu: goto label_1e245c;
            case 0x1E2470u: goto label_1e2470;
            case 0x1E2480u: goto label_1e2480;
            case 0x1E24F8u: goto label_1e24f8;
            case 0x1E2500u: goto label_1e2500;
            case 0x1E2508u: goto label_1e2508;
            case 0x1E25D0u: goto label_1e25d0;
            case 0x1E25ECu: goto label_1e25ec;
            case 0x1E2600u: goto label_1e2600;
            case 0x1E261Cu: goto label_1e261c;
            case 0x1E2684u: goto label_1e2684;
            case 0x1E2698u: goto label_1e2698;
            case 0x1E26D8u: goto label_1e26d8;
            case 0x1E26E8u: goto label_1e26e8;
            case 0x1E270Cu: goto label_1e270c;
            case 0x1E271Cu: goto label_1e271c;
            case 0x1E2740u: goto label_1e2740;
            case 0x1E2754u: goto label_1e2754;
            case 0x1E27C8u: goto label_1e27c8;
            case 0x1E27E4u: goto label_1e27e4;
            case 0x1E27F8u: goto label_1e27f8;
            case 0x1E2814u: goto label_1e2814;
            case 0x1E287Cu: goto label_1e287c;
            case 0x1E2890u: goto label_1e2890;
            case 0x1E28D0u: goto label_1e28d0;
            case 0x1E28E0u: goto label_1e28e0;
            case 0x1E2904u: goto label_1e2904;
            case 0x1E2914u: goto label_1e2914;
            case 0x1E2938u: goto label_1e2938;
            case 0x1E294Cu: goto label_1e294c;
            case 0x1E29C0u: goto label_1e29c0;
            case 0x1E29DCu: goto label_1e29dc;
            case 0x1E29F0u: goto label_1e29f0;
            case 0x1E2A0Cu: goto label_1e2a0c;
            case 0x1E2A78u: goto label_1e2a78;
            case 0x1E2A8Cu: goto label_1e2a8c;
            case 0x1E2ACCu: goto label_1e2acc;
            case 0x1E2ADCu: goto label_1e2adc;
            case 0x1E2B00u: goto label_1e2b00;
            case 0x1E2B10u: goto label_1e2b10;
            case 0x1E2B34u: goto label_1e2b34;
            case 0x1E2B48u: goto label_1e2b48;
            case 0x1E2B54u: goto label_1e2b54;
            case 0x1E2B90u: goto label_1e2b90;
            case 0x1E2B98u: goto label_1e2b98;
            case 0x1E2BC0u: goto label_1e2bc0;
            case 0x1E2BE4u: goto label_1e2be4;
            case 0x1E2BF8u: goto label_1e2bf8;
            case 0x1E2C14u: goto label_1e2c14;
            case 0x1E2C84u: goto label_1e2c84;
            case 0x1E2C98u: goto label_1e2c98;
            case 0x1E2CD8u: goto label_1e2cd8;
            case 0x1E2CE8u: goto label_1e2ce8;
            case 0x1E2D0Cu: goto label_1e2d0c;
            case 0x1E2D1Cu: goto label_1e2d1c;
            case 0x1E2D40u: goto label_1e2d40;
            case 0x1E2D54u: goto label_1e2d54;
            case 0x1E2E10u: goto label_1e2e10;
            case 0x1E2E18u: goto label_1e2e18;
            case 0x1E2E20u: goto label_1e2e20;
            case 0x1E2E48u: goto label_1e2e48;
            case 0x1E2E64u: goto label_1e2e64;
            case 0x1E2E78u: goto label_1e2e78;
            case 0x1E2E94u: goto label_1e2e94;
            case 0x1E2EF8u: goto label_1e2ef8;
            case 0x1E2F0Cu: goto label_1e2f0c;
            case 0x1E2F4Cu: goto label_1e2f4c;
            case 0x1E2F5Cu: goto label_1e2f5c;
            case 0x1E2F80u: goto label_1e2f80;
            case 0x1E2FA8u: goto label_1e2fa8;
            case 0x1E2FC4u: goto label_1e2fc4;
            case 0x1E2FD8u: goto label_1e2fd8;
            case 0x1E2FF4u: goto label_1e2ff4;
            case 0x1E3058u: goto label_1e3058;
            case 0x1E306Cu: goto label_1e306c;
            case 0x1E30ACu: goto label_1e30ac;
            case 0x1E30BCu: goto label_1e30bc;
            case 0x1E30E0u: goto label_1e30e0;
            case 0x1E3108u: goto label_1e3108;
            case 0x1E3124u: goto label_1e3124;
            case 0x1E3138u: goto label_1e3138;
            case 0x1E3154u: goto label_1e3154;
            case 0x1E31CCu: goto label_1e31cc;
            case 0x1E31E0u: goto label_1e31e0;
            case 0x1E3220u: goto label_1e3220;
            case 0x1E3238u: goto label_1e3238;
            case 0x1E325Cu: goto label_1e325c;
            case 0x1E3278u: goto label_1e3278;
            case 0x1E329Cu: goto label_1e329c;
            case 0x1E32B0u: goto label_1e32b0;
            case 0x1E3318u: goto label_1e3318;
            case 0x1E3388u: goto label_1e3388;
            case 0x1E33C4u: goto label_1e33c4;
            case 0x1E33E0u: goto label_1e33e0;
            case 0x1E33F4u: goto label_1e33f4;
            case 0x1E3410u: goto label_1e3410;
            case 0x1E347Cu: goto label_1e347c;
            case 0x1E3490u: goto label_1e3490;
            case 0x1E34D0u: goto label_1e34d0;
            case 0x1E34E0u: goto label_1e34e0;
            case 0x1E3504u: goto label_1e3504;
            case 0x1E3514u: goto label_1e3514;
            case 0x1E3538u: goto label_1e3538;
            case 0x1E354Cu: goto label_1e354c;
            case 0x1E360Cu: goto label_1e360c;
            case 0x1E3628u: goto label_1e3628;
            case 0x1E363Cu: goto label_1e363c;
            case 0x1E3658u: goto label_1e3658;
            case 0x1E36C4u: goto label_1e36c4;
            case 0x1E36D8u: goto label_1e36d8;
            case 0x1E3718u: goto label_1e3718;
            case 0x1E3728u: goto label_1e3728;
            case 0x1E374Cu: goto label_1e374c;
            case 0x1E375Cu: goto label_1e375c;
            case 0x1E3780u: goto label_1e3780;
            case 0x1E3794u: goto label_1e3794;
            case 0x1E3854u: goto label_1e3854;
            case 0x1E3870u: goto label_1e3870;
            case 0x1E3884u: goto label_1e3884;
            case 0x1E38A0u: goto label_1e38a0;
            case 0x1E3908u: goto label_1e3908;
            case 0x1E391Cu: goto label_1e391c;
            case 0x1E395Cu: goto label_1e395c;
            case 0x1E396Cu: goto label_1e396c;
            case 0x1E3990u: goto label_1e3990;
            case 0x1E39A0u: goto label_1e39a0;
            case 0x1E39C4u: goto label_1e39c4;
            case 0x1E39D8u: goto label_1e39d8;
            case 0x1E3A44u: goto label_1e3a44;
            case 0x1E3A60u: goto label_1e3a60;
            case 0x1E3A74u: goto label_1e3a74;
            case 0x1E3A78u: goto label_1e3a78;
            case 0x1E3ADCu: goto label_1e3adc;
            case 0x1E3AF0u: goto label_1e3af0;
            case 0x1E3B30u: goto label_1e3b30;
            case 0x1E3B40u: goto label_1e3b40;
            case 0x1E3B64u: goto label_1e3b64;
            case 0x1E3B84u: goto label_1e3b84;
            case 0x1E3BA0u: goto label_1e3ba0;
            case 0x1E3BB4u: goto label_1e3bb4;
            case 0x1E3BB8u: goto label_1e3bb8;
            case 0x1E3C1Cu: goto label_1e3c1c;
            case 0x1E3C30u: goto label_1e3c30;
            case 0x1E3C70u: goto label_1e3c70;
            case 0x1E3C80u: goto label_1e3c80;
            case 0x1E3CA4u: goto label_1e3ca4;
            case 0x1E3CC4u: goto label_1e3cc4;
            case 0x1E3CE8u: goto label_1e3ce8;
            case 0x1E3CFCu: goto label_1e3cfc;
            case 0x1E3D00u: goto label_1e3d00;
            case 0x1E3D68u: goto label_1e3d68;
            case 0x1E3D7Cu: goto label_1e3d7c;
            case 0x1E3DBCu: goto label_1e3dbc;
            case 0x1E3DCCu: goto label_1e3dcc;
            case 0x1E3DF0u: goto label_1e3df0;
            case 0x1E3E00u: goto label_1e3e00;
            case 0x1E3E24u: goto label_1e3e24;
            case 0x1E3E38u: goto label_1e3e38;
            case 0x1E3EA4u: goto label_1e3ea4;
            case 0x1E3EC0u: goto label_1e3ec0;
            case 0x1E3ED4u: goto label_1e3ed4;
            case 0x1E3ED8u: goto label_1e3ed8;
            case 0x1E3F40u: goto label_1e3f40;
            case 0x1E3F54u: goto label_1e3f54;
            case 0x1E3F94u: goto label_1e3f94;
            case 0x1E3FA4u: goto label_1e3fa4;
            case 0x1E3FC8u: goto label_1e3fc8;
            case 0x1E3FD8u: goto label_1e3fd8;
            case 0x1E3FFCu: goto label_1e3ffc;
            case 0x1E4010u: goto label_1e4010;
            case 0x1E407Cu: goto label_1e407c;
            case 0x1E4098u: goto label_1e4098;
            case 0x1E40ACu: goto label_1e40ac;
            case 0x1E40B0u: goto label_1e40b0;
            case 0x1E4118u: goto label_1e4118;
            case 0x1E412Cu: goto label_1e412c;
            case 0x1E416Cu: goto label_1e416c;
            case 0x1E417Cu: goto label_1e417c;
            case 0x1E41A0u: goto label_1e41a0;
            case 0x1E41B0u: goto label_1e41b0;
            case 0x1E41D4u: goto label_1e41d4;
            case 0x1E41E8u: goto label_1e41e8;
            case 0x1E4254u: goto label_1e4254;
            case 0x1E4270u: goto label_1e4270;
            case 0x1E4284u: goto label_1e4284;
            case 0x1E4288u: goto label_1e4288;
            case 0x1E42F0u: goto label_1e42f0;
            case 0x1E4304u: goto label_1e4304;
            case 0x1E4344u: goto label_1e4344;
            case 0x1E4358u: goto label_1e4358;
            case 0x1E437Cu: goto label_1e437c;
            case 0x1E4394u: goto label_1e4394;
            case 0x1E43B8u: goto label_1e43b8;
            case 0x1E43CCu: goto label_1e43cc;
            case 0x1E43E4u: goto label_1e43e4;
            case 0x1E4414u: goto label_1e4414;
            case 0x1E4430u: goto label_1e4430;
            case 0x1E4444u: goto label_1e4444;
            case 0x1E4460u: goto label_1e4460;
            case 0x1E44C8u: goto label_1e44c8;
            case 0x1E44DCu: goto label_1e44dc;
            case 0x1E451Cu: goto label_1e451c;
            case 0x1E452Cu: goto label_1e452c;
            case 0x1E4550u: goto label_1e4550;
            case 0x1E4560u: goto label_1e4560;
            case 0x1E4584u: goto label_1e4584;
            case 0x1E4598u: goto label_1e4598;
            case 0x1E460Cu: goto label_1e460c;
            case 0x1E4628u: goto label_1e4628;
            case 0x1E463Cu: goto label_1e463c;
            case 0x1E4658u: goto label_1e4658;
            case 0x1E46C8u: goto label_1e46c8;
            case 0x1E46DCu: goto label_1e46dc;
            case 0x1E471Cu: goto label_1e471c;
            case 0x1E472Cu: goto label_1e472c;
            case 0x1E4750u: goto label_1e4750;
            case 0x1E4764u: goto label_1e4764;
            case 0x1E4788u: goto label_1e4788;
            case 0x1E479Cu: goto label_1e479c;
            case 0x1E47B0u: goto label_1e47b0;
            case 0x1E47E0u: goto label_1e47e0;
            case 0x1E47FCu: goto label_1e47fc;
            case 0x1E4800u: goto label_1e4800;
            case 0x1E48A0u: goto label_1e48a0;
            case 0x1E48B4u: goto label_1e48b4;
            case 0x1E48F4u: goto label_1e48f4;
            case 0x1E4918u: goto label_1e4918;
            case 0x1E493Cu: goto label_1e493c;
            case 0x1E4974u: goto label_1e4974;
            case 0x1E4998u: goto label_1e4998;
            case 0x1E49ACu: goto label_1e49ac;
            case 0x1E4A08u: goto label_1e4a08;
            case 0x1E4A24u: goto label_1e4a24;
            case 0x1E4AACu: goto label_1e4aac;
            case 0x1E4AC0u: goto label_1e4ac0;
            case 0x1E4B00u: goto label_1e4b00;
            case 0x1E4B1Cu: goto label_1e4b1c;
            case 0x1E4B20u: goto label_1e4b20;
            case 0x1E4B94u: goto label_1e4b94;
            case 0x1E4BA8u: goto label_1e4ba8;
            case 0x1E4BE8u: goto label_1e4be8;
            case 0x1E4C10u: goto label_1e4c10;
            case 0x1E4C34u: goto label_1e4c34;
            case 0x1E4C64u: goto label_1e4c64;
            case 0x1E4C88u: goto label_1e4c88;
            case 0x1E4C9Cu: goto label_1e4c9c;
            case 0x1E4D08u: goto label_1e4d08;
            case 0x1E4D28u: goto label_1e4d28;
            case 0x1E4DE4u: goto label_1e4de4;
            case 0x1E4DF8u: goto label_1e4df8;
            case 0x1E4E3Cu: goto label_1e4e3c;
            case 0x1E4E58u: goto label_1e4e58;
            case 0x1E4E5Cu: goto label_1e4e5c;
            case 0x1E4EC4u: goto label_1e4ec4;
            case 0x1E4ED8u: goto label_1e4ed8;
            case 0x1E4F18u: goto label_1e4f18;
            case 0x1E4F28u: goto label_1e4f28;
            case 0x1E4F4Cu: goto label_1e4f4c;
            case 0x1E4F60u: goto label_1e4f60;
            case 0x1E4F84u: goto label_1e4f84;
            case 0x1E4F98u: goto label_1e4f98;
            case 0x1E4FACu: goto label_1e4fac;
            case 0x1E4FD0u: goto label_1e4fd0;
            case 0x1E4FECu: goto label_1e4fec;
            case 0x1E4FF0u: goto label_1e4ff0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E3BD0u;
    // 0x1e3bd0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1e3bd0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1e3bd4: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1e3bd4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1e3bd8: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1e3bd8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1e3bdc: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e3bdcu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e3be0: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e3be0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e3be4: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e3be4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e3be8: 0xafc0000c  sw          $zero, 0xC($fp)
    ctx->pc = 0x1e3be8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 0));
    // 0x1e3bec: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e3becu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e3bf0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e3bf0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e3bf4: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E3BF4u;
    {
        const bool branch_taken_0x1e3bf4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e3bf4) {
            ctx->pc = 0x1E3C1Cu;
            goto label_1e3c1c;
        }
    }
    ctx->pc = 0x1E3BFCu;
    // 0x1e3bfc: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e3bfcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e3c00: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e3c00u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e3c04: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e3c04u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e3c08: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e3c08u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e3c0c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e3c0cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e3c10: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e3c10u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e3c14: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E3C14u;
    {
        const bool branch_taken_0x1e3c14 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e3c14) {
            ctx->pc = 0x1E3C30u;
            goto label_1e3c30;
        }
    }
    ctx->pc = 0x1E3C1Cu;
label_1e3c1c:
    // 0x1e3c1c: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e3c1cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e3c20: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e3c20u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e3c24: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e3c24u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e3c28: 0x10000035  b           . + 4 + (0x35 << 2)
    ctx->pc = 0x1E3C28u;
    {
        const bool branch_taken_0x1e3c28 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3c28) {
            ctx->pc = 0x1E3D00u;
            goto label_1e3d00;
        }
    }
    ctx->pc = 0x1E3C30u;
label_1e3c30:
    // 0x1e3c30: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e3c30u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e3c34: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e3c34u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e3c38: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e3c38u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e3c3c: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e3c3cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e3c40: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e3c40u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e3c44: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e3c44u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e3c48: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1e3c48u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1e3c4c: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e3c4cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e3c50: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e3c50u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e3c54: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E3C54u;
    {
        const bool branch_taken_0x1e3c54 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3c54) {
            ctx->pc = 0x1E3C70u;
            goto label_1e3c70;
        }
    }
    ctx->pc = 0x1E3C5Cu;
    // 0x1e3c5c: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e3c5cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e3c60: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e3c60u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e3c64: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e3c64u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e3c68: 0x10000025  b           . + 4 + (0x25 << 2)
    ctx->pc = 0x1E3C68u;
    {
        const bool branch_taken_0x1e3c68 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3c68) {
            ctx->pc = 0x1E3D00u;
            goto label_1e3d00;
        }
    }
    ctx->pc = 0x1E3C70u;
label_1e3c70:
    // 0x1e3c70: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1e3c70u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e3c74: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1e3c74u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e3c78: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E3C78u;
    SET_GPR_U32(ctx, 31, 0x1E3C80u);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3C80u; }
        if (ctx->pc != 0x1E3C80u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3C80u; }
        if (ctx->pc != 0x1E3C80u) { return; }
    }
    ctx->pc = 0x1E3C80u;
label_1e3c80:
    // 0x1e3c80: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1e3c80u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1e3c84: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1e3c84u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e3c88: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E3C88u;
    {
        const bool branch_taken_0x1e3c88 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e3c88) {
            ctx->pc = 0x1E3CA4u;
            goto label_1e3ca4;
        }
    }
    ctx->pc = 0x1E3C90u;
    // 0x1e3c90: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e3c90u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e3c94: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e3c94u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e3c98: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e3c98u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e3c9c: 0x10000018  b           . + 4 + (0x18 << 2)
    ctx->pc = 0x1E3C9Cu;
    {
        const bool branch_taken_0x1e3c9c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3c9c) {
            ctx->pc = 0x1E3D00u;
            goto label_1e3d00;
        }
    }
    ctx->pc = 0x1E3CA4u;
label_1e3ca4:
    // 0x1e3ca4: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1e3ca4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e3ca8: 0x8fc50008  lw          $a1, 0x8($fp)
    ctx->pc = 0x1e3ca8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e3cac: 0x3406b000  ori         $a2, $zero, 0xB000
    ctx->pc = 0x1e3cacu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)45056);
    // 0x1e3cb0: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1e3cb0u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e3cb4: 0x24080047  addiu       $t0, $zero, 0x47
    ctx->pc = 0x1e3cb4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 71));
    // 0x1e3cb8: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1e3cb8u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e3cbc: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E3CBCu;
    SET_GPR_U32(ctx, 31, 0x1E3CC4u);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3CC4u; }
        if (ctx->pc != 0x1E3CC4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3CC4u; }
        if (ctx->pc != 0x1E3CC4u) { return; }
    }
    ctx->pc = 0x1E3CC4u;
label_1e3cc4:
    // 0x1e3cc4: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1e3cc4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1e3cc8: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e3cc8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e3ccc: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E3CCCu;
    {
        const bool branch_taken_0x1e3ccc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3ccc) {
            ctx->pc = 0x1E3CE8u;
            goto label_1e3ce8;
        }
    }
    ctx->pc = 0x1E3CD4u;
    // 0x1e3cd4: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e3cd4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e3cd8: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e3cd8u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e3cdc: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e3cdcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e3ce0: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1E3CE0u;
    {
        const bool branch_taken_0x1e3ce0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3ce0) {
            ctx->pc = 0x1E3D00u;
            goto label_1e3d00;
        }
    }
    ctx->pc = 0x1E3CE8u;
label_1e3ce8:
    // 0x1e3ce8: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1e3ce8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e3cec: 0x24050030  addiu       $a1, $zero, 0x30
    ctx->pc = 0x1e3cecu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 48));
    // 0x1e3cf0: 0x8fc60004  lw          $a2, 0x4($fp)
    ctx->pc = 0x1e3cf0u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e3cf4: 0xc076ad5  jal         func_1DAB54
    ctx->pc = 0x1E3CF4u;
    SET_GPR_U32(ctx, 31, 0x1E3CFCu);
    ctx->pc = 0x1DAB54u;
    if (runtime->hasFunction(0x1DAB54u)) {
        auto targetFn = runtime->lookupFunction(0x1DAB54u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3CFCu; }
        if (ctx->pc != 0x1E3CFCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DAB54_0x1dab54(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3CFCu; }
        if (ctx->pc != 0x1E3CFCu) { return; }
    }
    ctx->pc = 0x1E3CFCu;
label_1e3cfc:
    // 0x1e3cfc: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1e3cfcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1e3d00:
    // 0x1e3d00: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e3d00u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e3d04: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1e3d04u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1e3d08: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1e3d08u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1e3d0c: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1e3d0cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1e3d10: 0x3e00008  jr          $ra
    ctx->pc = 0x1E3D10u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E1B3Cu: goto label_1e1b3c;
            case 0x1E1B60u: goto label_1e1b60;
            case 0x1E1B84u: goto label_1e1b84;
            case 0x1E1BA8u: goto label_1e1ba8;
            case 0x1E1BC8u: goto label_1e1bc8;
            case 0x1E1BE4u: goto label_1e1be4;
            case 0x1E1BE8u: goto label_1e1be8;
            case 0x1E1C44u: goto label_1e1c44;
            case 0x1E1C58u: goto label_1e1c58;
            case 0x1E1C7Cu: goto label_1e1c7c;
            case 0x1E1CD8u: goto label_1e1cd8;
            case 0x1E1CECu: goto label_1e1cec;
            case 0x1E1D14u: goto label_1e1d14;
            case 0x1E1D7Cu: goto label_1e1d7c;
            case 0x1E1D90u: goto label_1e1d90;
            case 0x1E1DD0u: goto label_1e1dd0;
            case 0x1E1DE0u: goto label_1e1de0;
            case 0x1E1E04u: goto label_1e1e04;
            case 0x1E1E14u: goto label_1e1e14;
            case 0x1E1E38u: goto label_1e1e38;
            case 0x1E1E4Cu: goto label_1e1e4c;
            case 0x1E1E5Cu: goto label_1e1e5c;
            case 0x1E1E84u: goto label_1e1e84;
            case 0x1E1EA0u: goto label_1e1ea0;
            case 0x1E1EB4u: goto label_1e1eb4;
            case 0x1E1ED0u: goto label_1e1ed0;
            case 0x1E1F48u: goto label_1e1f48;
            case 0x1E1F5Cu: goto label_1e1f5c;
            case 0x1E1F9Cu: goto label_1e1f9c;
            case 0x1E1FACu: goto label_1e1fac;
            case 0x1E1FD0u: goto label_1e1fd0;
            case 0x1E1FE0u: goto label_1e1fe0;
            case 0x1E2004u: goto label_1e2004;
            case 0x1E2018u: goto label_1e2018;
            case 0x1E202Cu: goto label_1e202c;
            case 0x1E2064u: goto label_1e2064;
            case 0x1E206Cu: goto label_1e206c;
            case 0x1E2088u: goto label_1e2088;
            case 0x1E20A0u: goto label_1e20a0;
            case 0x1E20D4u: goto label_1e20d4;
            case 0x1E20F8u: goto label_1e20f8;
            case 0x1E210Cu: goto label_1e210c;
            case 0x1E2128u: goto label_1e2128;
            case 0x1E2190u: goto label_1e2190;
            case 0x1E21A4u: goto label_1e21a4;
            case 0x1E21E4u: goto label_1e21e4;
            case 0x1E21F4u: goto label_1e21f4;
            case 0x1E2218u: goto label_1e2218;
            case 0x1E2228u: goto label_1e2228;
            case 0x1E224Cu: goto label_1e224c;
            case 0x1E2260u: goto label_1e2260;
            case 0x1E22D4u: goto label_1e22d4;
            case 0x1E22F0u: goto label_1e22f0;
            case 0x1E2304u: goto label_1e2304;
            case 0x1E2320u: goto label_1e2320;
            case 0x1E23A0u: goto label_1e23a0;
            case 0x1E23B4u: goto label_1e23b4;
            case 0x1E23F4u: goto label_1e23f4;
            case 0x1E2404u: goto label_1e2404;
            case 0x1E2428u: goto label_1e2428;
            case 0x1E2438u: goto label_1e2438;
            case 0x1E245Cu: goto label_1e245c;
            case 0x1E2470u: goto label_1e2470;
            case 0x1E2480u: goto label_1e2480;
            case 0x1E24F8u: goto label_1e24f8;
            case 0x1E2500u: goto label_1e2500;
            case 0x1E2508u: goto label_1e2508;
            case 0x1E25D0u: goto label_1e25d0;
            case 0x1E25ECu: goto label_1e25ec;
            case 0x1E2600u: goto label_1e2600;
            case 0x1E261Cu: goto label_1e261c;
            case 0x1E2684u: goto label_1e2684;
            case 0x1E2698u: goto label_1e2698;
            case 0x1E26D8u: goto label_1e26d8;
            case 0x1E26E8u: goto label_1e26e8;
            case 0x1E270Cu: goto label_1e270c;
            case 0x1E271Cu: goto label_1e271c;
            case 0x1E2740u: goto label_1e2740;
            case 0x1E2754u: goto label_1e2754;
            case 0x1E27C8u: goto label_1e27c8;
            case 0x1E27E4u: goto label_1e27e4;
            case 0x1E27F8u: goto label_1e27f8;
            case 0x1E2814u: goto label_1e2814;
            case 0x1E287Cu: goto label_1e287c;
            case 0x1E2890u: goto label_1e2890;
            case 0x1E28D0u: goto label_1e28d0;
            case 0x1E28E0u: goto label_1e28e0;
            case 0x1E2904u: goto label_1e2904;
            case 0x1E2914u: goto label_1e2914;
            case 0x1E2938u: goto label_1e2938;
            case 0x1E294Cu: goto label_1e294c;
            case 0x1E29C0u: goto label_1e29c0;
            case 0x1E29DCu: goto label_1e29dc;
            case 0x1E29F0u: goto label_1e29f0;
            case 0x1E2A0Cu: goto label_1e2a0c;
            case 0x1E2A78u: goto label_1e2a78;
            case 0x1E2A8Cu: goto label_1e2a8c;
            case 0x1E2ACCu: goto label_1e2acc;
            case 0x1E2ADCu: goto label_1e2adc;
            case 0x1E2B00u: goto label_1e2b00;
            case 0x1E2B10u: goto label_1e2b10;
            case 0x1E2B34u: goto label_1e2b34;
            case 0x1E2B48u: goto label_1e2b48;
            case 0x1E2B54u: goto label_1e2b54;
            case 0x1E2B90u: goto label_1e2b90;
            case 0x1E2B98u: goto label_1e2b98;
            case 0x1E2BC0u: goto label_1e2bc0;
            case 0x1E2BE4u: goto label_1e2be4;
            case 0x1E2BF8u: goto label_1e2bf8;
            case 0x1E2C14u: goto label_1e2c14;
            case 0x1E2C84u: goto label_1e2c84;
            case 0x1E2C98u: goto label_1e2c98;
            case 0x1E2CD8u: goto label_1e2cd8;
            case 0x1E2CE8u: goto label_1e2ce8;
            case 0x1E2D0Cu: goto label_1e2d0c;
            case 0x1E2D1Cu: goto label_1e2d1c;
            case 0x1E2D40u: goto label_1e2d40;
            case 0x1E2D54u: goto label_1e2d54;
            case 0x1E2E10u: goto label_1e2e10;
            case 0x1E2E18u: goto label_1e2e18;
            case 0x1E2E20u: goto label_1e2e20;
            case 0x1E2E48u: goto label_1e2e48;
            case 0x1E2E64u: goto label_1e2e64;
            case 0x1E2E78u: goto label_1e2e78;
            case 0x1E2E94u: goto label_1e2e94;
            case 0x1E2EF8u: goto label_1e2ef8;
            case 0x1E2F0Cu: goto label_1e2f0c;
            case 0x1E2F4Cu: goto label_1e2f4c;
            case 0x1E2F5Cu: goto label_1e2f5c;
            case 0x1E2F80u: goto label_1e2f80;
            case 0x1E2FA8u: goto label_1e2fa8;
            case 0x1E2FC4u: goto label_1e2fc4;
            case 0x1E2FD8u: goto label_1e2fd8;
            case 0x1E2FF4u: goto label_1e2ff4;
            case 0x1E3058u: goto label_1e3058;
            case 0x1E306Cu: goto label_1e306c;
            case 0x1E30ACu: goto label_1e30ac;
            case 0x1E30BCu: goto label_1e30bc;
            case 0x1E30E0u: goto label_1e30e0;
            case 0x1E3108u: goto label_1e3108;
            case 0x1E3124u: goto label_1e3124;
            case 0x1E3138u: goto label_1e3138;
            case 0x1E3154u: goto label_1e3154;
            case 0x1E31CCu: goto label_1e31cc;
            case 0x1E31E0u: goto label_1e31e0;
            case 0x1E3220u: goto label_1e3220;
            case 0x1E3238u: goto label_1e3238;
            case 0x1E325Cu: goto label_1e325c;
            case 0x1E3278u: goto label_1e3278;
            case 0x1E329Cu: goto label_1e329c;
            case 0x1E32B0u: goto label_1e32b0;
            case 0x1E3318u: goto label_1e3318;
            case 0x1E3388u: goto label_1e3388;
            case 0x1E33C4u: goto label_1e33c4;
            case 0x1E33E0u: goto label_1e33e0;
            case 0x1E33F4u: goto label_1e33f4;
            case 0x1E3410u: goto label_1e3410;
            case 0x1E347Cu: goto label_1e347c;
            case 0x1E3490u: goto label_1e3490;
            case 0x1E34D0u: goto label_1e34d0;
            case 0x1E34E0u: goto label_1e34e0;
            case 0x1E3504u: goto label_1e3504;
            case 0x1E3514u: goto label_1e3514;
            case 0x1E3538u: goto label_1e3538;
            case 0x1E354Cu: goto label_1e354c;
            case 0x1E360Cu: goto label_1e360c;
            case 0x1E3628u: goto label_1e3628;
            case 0x1E363Cu: goto label_1e363c;
            case 0x1E3658u: goto label_1e3658;
            case 0x1E36C4u: goto label_1e36c4;
            case 0x1E36D8u: goto label_1e36d8;
            case 0x1E3718u: goto label_1e3718;
            case 0x1E3728u: goto label_1e3728;
            case 0x1E374Cu: goto label_1e374c;
            case 0x1E375Cu: goto label_1e375c;
            case 0x1E3780u: goto label_1e3780;
            case 0x1E3794u: goto label_1e3794;
            case 0x1E3854u: goto label_1e3854;
            case 0x1E3870u: goto label_1e3870;
            case 0x1E3884u: goto label_1e3884;
            case 0x1E38A0u: goto label_1e38a0;
            case 0x1E3908u: goto label_1e3908;
            case 0x1E391Cu: goto label_1e391c;
            case 0x1E395Cu: goto label_1e395c;
            case 0x1E396Cu: goto label_1e396c;
            case 0x1E3990u: goto label_1e3990;
            case 0x1E39A0u: goto label_1e39a0;
            case 0x1E39C4u: goto label_1e39c4;
            case 0x1E39D8u: goto label_1e39d8;
            case 0x1E3A44u: goto label_1e3a44;
            case 0x1E3A60u: goto label_1e3a60;
            case 0x1E3A74u: goto label_1e3a74;
            case 0x1E3A78u: goto label_1e3a78;
            case 0x1E3ADCu: goto label_1e3adc;
            case 0x1E3AF0u: goto label_1e3af0;
            case 0x1E3B30u: goto label_1e3b30;
            case 0x1E3B40u: goto label_1e3b40;
            case 0x1E3B64u: goto label_1e3b64;
            case 0x1E3B84u: goto label_1e3b84;
            case 0x1E3BA0u: goto label_1e3ba0;
            case 0x1E3BB4u: goto label_1e3bb4;
            case 0x1E3BB8u: goto label_1e3bb8;
            case 0x1E3C1Cu: goto label_1e3c1c;
            case 0x1E3C30u: goto label_1e3c30;
            case 0x1E3C70u: goto label_1e3c70;
            case 0x1E3C80u: goto label_1e3c80;
            case 0x1E3CA4u: goto label_1e3ca4;
            case 0x1E3CC4u: goto label_1e3cc4;
            case 0x1E3CE8u: goto label_1e3ce8;
            case 0x1E3CFCu: goto label_1e3cfc;
            case 0x1E3D00u: goto label_1e3d00;
            case 0x1E3D68u: goto label_1e3d68;
            case 0x1E3D7Cu: goto label_1e3d7c;
            case 0x1E3DBCu: goto label_1e3dbc;
            case 0x1E3DCCu: goto label_1e3dcc;
            case 0x1E3DF0u: goto label_1e3df0;
            case 0x1E3E00u: goto label_1e3e00;
            case 0x1E3E24u: goto label_1e3e24;
            case 0x1E3E38u: goto label_1e3e38;
            case 0x1E3EA4u: goto label_1e3ea4;
            case 0x1E3EC0u: goto label_1e3ec0;
            case 0x1E3ED4u: goto label_1e3ed4;
            case 0x1E3ED8u: goto label_1e3ed8;
            case 0x1E3F40u: goto label_1e3f40;
            case 0x1E3F54u: goto label_1e3f54;
            case 0x1E3F94u: goto label_1e3f94;
            case 0x1E3FA4u: goto label_1e3fa4;
            case 0x1E3FC8u: goto label_1e3fc8;
            case 0x1E3FD8u: goto label_1e3fd8;
            case 0x1E3FFCu: goto label_1e3ffc;
            case 0x1E4010u: goto label_1e4010;
            case 0x1E407Cu: goto label_1e407c;
            case 0x1E4098u: goto label_1e4098;
            case 0x1E40ACu: goto label_1e40ac;
            case 0x1E40B0u: goto label_1e40b0;
            case 0x1E4118u: goto label_1e4118;
            case 0x1E412Cu: goto label_1e412c;
            case 0x1E416Cu: goto label_1e416c;
            case 0x1E417Cu: goto label_1e417c;
            case 0x1E41A0u: goto label_1e41a0;
            case 0x1E41B0u: goto label_1e41b0;
            case 0x1E41D4u: goto label_1e41d4;
            case 0x1E41E8u: goto label_1e41e8;
            case 0x1E4254u: goto label_1e4254;
            case 0x1E4270u: goto label_1e4270;
            case 0x1E4284u: goto label_1e4284;
            case 0x1E4288u: goto label_1e4288;
            case 0x1E42F0u: goto label_1e42f0;
            case 0x1E4304u: goto label_1e4304;
            case 0x1E4344u: goto label_1e4344;
            case 0x1E4358u: goto label_1e4358;
            case 0x1E437Cu: goto label_1e437c;
            case 0x1E4394u: goto label_1e4394;
            case 0x1E43B8u: goto label_1e43b8;
            case 0x1E43CCu: goto label_1e43cc;
            case 0x1E43E4u: goto label_1e43e4;
            case 0x1E4414u: goto label_1e4414;
            case 0x1E4430u: goto label_1e4430;
            case 0x1E4444u: goto label_1e4444;
            case 0x1E4460u: goto label_1e4460;
            case 0x1E44C8u: goto label_1e44c8;
            case 0x1E44DCu: goto label_1e44dc;
            case 0x1E451Cu: goto label_1e451c;
            case 0x1E452Cu: goto label_1e452c;
            case 0x1E4550u: goto label_1e4550;
            case 0x1E4560u: goto label_1e4560;
            case 0x1E4584u: goto label_1e4584;
            case 0x1E4598u: goto label_1e4598;
            case 0x1E460Cu: goto label_1e460c;
            case 0x1E4628u: goto label_1e4628;
            case 0x1E463Cu: goto label_1e463c;
            case 0x1E4658u: goto label_1e4658;
            case 0x1E46C8u: goto label_1e46c8;
            case 0x1E46DCu: goto label_1e46dc;
            case 0x1E471Cu: goto label_1e471c;
            case 0x1E472Cu: goto label_1e472c;
            case 0x1E4750u: goto label_1e4750;
            case 0x1E4764u: goto label_1e4764;
            case 0x1E4788u: goto label_1e4788;
            case 0x1E479Cu: goto label_1e479c;
            case 0x1E47B0u: goto label_1e47b0;
            case 0x1E47E0u: goto label_1e47e0;
            case 0x1E47FCu: goto label_1e47fc;
            case 0x1E4800u: goto label_1e4800;
            case 0x1E48A0u: goto label_1e48a0;
            case 0x1E48B4u: goto label_1e48b4;
            case 0x1E48F4u: goto label_1e48f4;
            case 0x1E4918u: goto label_1e4918;
            case 0x1E493Cu: goto label_1e493c;
            case 0x1E4974u: goto label_1e4974;
            case 0x1E4998u: goto label_1e4998;
            case 0x1E49ACu: goto label_1e49ac;
            case 0x1E4A08u: goto label_1e4a08;
            case 0x1E4A24u: goto label_1e4a24;
            case 0x1E4AACu: goto label_1e4aac;
            case 0x1E4AC0u: goto label_1e4ac0;
            case 0x1E4B00u: goto label_1e4b00;
            case 0x1E4B1Cu: goto label_1e4b1c;
            case 0x1E4B20u: goto label_1e4b20;
            case 0x1E4B94u: goto label_1e4b94;
            case 0x1E4BA8u: goto label_1e4ba8;
            case 0x1E4BE8u: goto label_1e4be8;
            case 0x1E4C10u: goto label_1e4c10;
            case 0x1E4C34u: goto label_1e4c34;
            case 0x1E4C64u: goto label_1e4c64;
            case 0x1E4C88u: goto label_1e4c88;
            case 0x1E4C9Cu: goto label_1e4c9c;
            case 0x1E4D08u: goto label_1e4d08;
            case 0x1E4D28u: goto label_1e4d28;
            case 0x1E4DE4u: goto label_1e4de4;
            case 0x1E4DF8u: goto label_1e4df8;
            case 0x1E4E3Cu: goto label_1e4e3c;
            case 0x1E4E58u: goto label_1e4e58;
            case 0x1E4E5Cu: goto label_1e4e5c;
            case 0x1E4EC4u: goto label_1e4ec4;
            case 0x1E4ED8u: goto label_1e4ed8;
            case 0x1E4F18u: goto label_1e4f18;
            case 0x1E4F28u: goto label_1e4f28;
            case 0x1E4F4Cu: goto label_1e4f4c;
            case 0x1E4F60u: goto label_1e4f60;
            case 0x1E4F84u: goto label_1e4f84;
            case 0x1E4F98u: goto label_1e4f98;
            case 0x1E4FACu: goto label_1e4fac;
            case 0x1E4FD0u: goto label_1e4fd0;
            case 0x1E4FECu: goto label_1e4fec;
            case 0x1E4FF0u: goto label_1e4ff0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E3D18u;
    // 0x1e3d18: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1e3d18u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1e3d1c: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1e3d1cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1e3d20: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1e3d20u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1e3d24: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e3d24u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e3d28: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e3d28u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e3d2c: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e3d2cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e3d30: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e3d30u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e3d34: 0xafc00014  sw          $zero, 0x14($fp)
    ctx->pc = 0x1e3d34u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 0));
    // 0x1e3d38: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e3d38u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e3d3c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e3d3cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e3d40: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E3D40u;
    {
        const bool branch_taken_0x1e3d40 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e3d40) {
            ctx->pc = 0x1E3D68u;
            goto label_1e3d68;
        }
    }
    ctx->pc = 0x1E3D48u;
    // 0x1e3d48: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e3d48u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e3d4c: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e3d4cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e3d50: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e3d50u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e3d54: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e3d54u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e3d58: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e3d58u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e3d5c: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e3d5cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e3d60: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E3D60u;
    {
        const bool branch_taken_0x1e3d60 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e3d60) {
            ctx->pc = 0x1E3D7Cu;
            goto label_1e3d7c;
        }
    }
    ctx->pc = 0x1E3D68u;
label_1e3d68:
    // 0x1e3d68: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e3d68u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e3d6c: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e3d6cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e3d70: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e3d70u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e3d74: 0x10000058  b           . + 4 + (0x58 << 2)
    ctx->pc = 0x1E3D74u;
    {
        const bool branch_taken_0x1e3d74 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3d74) {
            ctx->pc = 0x1E3ED8u;
            goto label_1e3ed8;
        }
    }
    ctx->pc = 0x1E3D7Cu;
label_1e3d7c:
    // 0x1e3d7c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e3d7cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e3d80: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e3d80u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e3d84: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e3d84u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e3d88: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e3d88u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e3d8c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e3d8cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e3d90: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e3d90u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e3d94: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1e3d94u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1e3d98: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e3d98u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e3d9c: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e3d9cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e3da0: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E3DA0u;
    {
        const bool branch_taken_0x1e3da0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3da0) {
            ctx->pc = 0x1E3DBCu;
            goto label_1e3dbc;
        }
    }
    ctx->pc = 0x1E3DA8u;
    // 0x1e3da8: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e3da8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e3dac: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e3dacu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e3db0: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e3db0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e3db4: 0x10000048  b           . + 4 + (0x48 << 2)
    ctx->pc = 0x1E3DB4u;
    {
        const bool branch_taken_0x1e3db4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3db4) {
            ctx->pc = 0x1E3ED8u;
            goto label_1e3ed8;
        }
    }
    ctx->pc = 0x1E3DBCu;
label_1e3dbc:
    // 0x1e3dbc: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e3dbcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e3dc0: 0x24050004  addiu       $a1, $zero, 0x4
    ctx->pc = 0x1e3dc0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1e3dc4: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E3DC4u;
    SET_GPR_U32(ctx, 31, 0x1E3DCCu);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3DCCu; }
        if (ctx->pc != 0x1E3DCCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3DCCu; }
        if (ctx->pc != 0x1E3DCCu) { return; }
    }
    ctx->pc = 0x1E3DCCu;
label_1e3dcc:
    // 0x1e3dcc: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1e3dccu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1e3dd0: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e3dd0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e3dd4: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E3DD4u;
    {
        const bool branch_taken_0x1e3dd4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e3dd4) {
            ctx->pc = 0x1E3DF0u;
            goto label_1e3df0;
        }
    }
    ctx->pc = 0x1E3DDCu;
    // 0x1e3ddc: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e3ddcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e3de0: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e3de0u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e3de4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e3de4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e3de8: 0x1000003b  b           . + 4 + (0x3B << 2)
    ctx->pc = 0x1E3DE8u;
    {
        const bool branch_taken_0x1e3de8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3de8) {
            ctx->pc = 0x1E3ED8u;
            goto label_1e3ed8;
        }
    }
    ctx->pc = 0x1E3DF0u;
label_1e3df0:
    // 0x1e3df0: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1e3df0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e3df4: 0x24050004  addiu       $a1, $zero, 0x4
    ctx->pc = 0x1e3df4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1e3df8: 0xc07cc3c  jal         func_1F30F0
    ctx->pc = 0x1E3DF8u;
    SET_GPR_U32(ctx, 31, 0x1E3E00u);
    ctx->pc = 0x1F30F0u;
    if (runtime->hasFunction(0x1F30F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F30F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3E00u; }
        if (ctx->pc != 0x1E3E00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F30F0_0x1f30f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3E00u; }
        if (ctx->pc != 0x1E3E00u) { return; }
    }
    ctx->pc = 0x1E3E00u;
label_1e3e00:
    // 0x1e3e00: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1e3e00u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1e3e04: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e3e04u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e3e08: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1E3E08u;
    {
        const bool branch_taken_0x1e3e08 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e3e08) {
            ctx->pc = 0x1E3E38u;
            goto label_1e3e38;
        }
    }
    ctx->pc = 0x1E3E10u;
    // 0x1e3e10: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e3e10u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e3e14: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1e3e14u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1e3e18: 0x8fc5000c  lw          $a1, 0xC($fp)
    ctx->pc = 0x1e3e18u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e3e1c: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1E3E1Cu;
    SET_GPR_U32(ctx, 31, 0x1E3E24u);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3E24u; }
        if (ctx->pc != 0x1E3E24u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3E24u; }
        if (ctx->pc != 0x1E3E24u) { return; }
    }
    ctx->pc = 0x1E3E24u;
label_1e3e24:
    // 0x1e3e24: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e3e24u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e3e28: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e3e28u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e3e2c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e3e2cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e3e30: 0x10000029  b           . + 4 + (0x29 << 2)
    ctx->pc = 0x1E3E30u;
    {
        const bool branch_taken_0x1e3e30 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3e30) {
            ctx->pc = 0x1E3ED8u;
            goto label_1e3ed8;
        }
    }
    ctx->pc = 0x1E3E38u;
label_1e3e38:
    // 0x1e3e38: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e3e38u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e3e3c: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e3e3cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e3e40: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1e3e40u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1e3e44: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1e3e44u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1e3e48: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e3e48u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e3e4c: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1e3e4cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1e3e50: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1e3e50u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1e3e54: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1e3e54u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e3e58: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1e3e58u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e3e5c: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1e3e5cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1e3e60: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e3e60u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e3e64: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1e3e64u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1e3e68: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1e3e68u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e3e6c: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1e3e6cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e3e70: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1e3e70u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1e3e74: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e3e74u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e3e78: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1e3e78u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1e3e7c: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1e3e7cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e3e80: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x1e3e80u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x1e3e84: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e3e84u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e3e88: 0x8fc5000c  lw          $a1, 0xC($fp)
    ctx->pc = 0x1e3e88u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e3e8c: 0x3406b000  ori         $a2, $zero, 0xB000
    ctx->pc = 0x1e3e8cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)45056);
    // 0x1e3e90: 0x24070004  addiu       $a3, $zero, 0x4
    ctx->pc = 0x1e3e90u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1e3e94: 0x2408000a  addiu       $t0, $zero, 0xA
    ctx->pc = 0x1e3e94u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x1e3e98: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1e3e98u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e3e9c: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E3E9Cu;
    SET_GPR_U32(ctx, 31, 0x1E3EA4u);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3EA4u; }
        if (ctx->pc != 0x1E3EA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3EA4u; }
        if (ctx->pc != 0x1E3EA4u) { return; }
    }
    ctx->pc = 0x1E3EA4u;
label_1e3ea4:
    // 0x1e3ea4: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E3EA4u;
    {
        const bool branch_taken_0x1e3ea4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3ea4) {
            ctx->pc = 0x1E3EC0u;
            goto label_1e3ec0;
        }
    }
    ctx->pc = 0x1E3EACu;
    // 0x1e3eac: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e3eacu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e3eb0: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e3eb0u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e3eb4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e3eb4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e3eb8: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1E3EB8u;
    {
        const bool branch_taken_0x1e3eb8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3eb8) {
            ctx->pc = 0x1E3ED8u;
            goto label_1e3ed8;
        }
    }
    ctx->pc = 0x1E3EC0u;
label_1e3ec0:
    // 0x1e3ec0: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1e3ec0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e3ec4: 0x24050019  addiu       $a1, $zero, 0x19
    ctx->pc = 0x1e3ec4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 25));
    // 0x1e3ec8: 0x8fc60008  lw          $a2, 0x8($fp)
    ctx->pc = 0x1e3ec8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e3ecc: 0xc076ad5  jal         func_1DAB54
    ctx->pc = 0x1E3ECCu;
    SET_GPR_U32(ctx, 31, 0x1E3ED4u);
    ctx->pc = 0x1DAB54u;
    if (runtime->hasFunction(0x1DAB54u)) {
        auto targetFn = runtime->lookupFunction(0x1DAB54u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3ED4u; }
        if (ctx->pc != 0x1E3ED4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DAB54_0x1dab54(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3ED4u; }
        if (ctx->pc != 0x1E3ED4u) { return; }
    }
    ctx->pc = 0x1E3ED4u;
label_1e3ed4:
    // 0x1e3ed4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1e3ed4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1e3ed8:
    // 0x1e3ed8: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e3ed8u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e3edc: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1e3edcu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1e3ee0: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1e3ee0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1e3ee4: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1e3ee4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1e3ee8: 0x3e00008  jr          $ra
    ctx->pc = 0x1E3EE8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E1B3Cu: goto label_1e1b3c;
            case 0x1E1B60u: goto label_1e1b60;
            case 0x1E1B84u: goto label_1e1b84;
            case 0x1E1BA8u: goto label_1e1ba8;
            case 0x1E1BC8u: goto label_1e1bc8;
            case 0x1E1BE4u: goto label_1e1be4;
            case 0x1E1BE8u: goto label_1e1be8;
            case 0x1E1C44u: goto label_1e1c44;
            case 0x1E1C58u: goto label_1e1c58;
            case 0x1E1C7Cu: goto label_1e1c7c;
            case 0x1E1CD8u: goto label_1e1cd8;
            case 0x1E1CECu: goto label_1e1cec;
            case 0x1E1D14u: goto label_1e1d14;
            case 0x1E1D7Cu: goto label_1e1d7c;
            case 0x1E1D90u: goto label_1e1d90;
            case 0x1E1DD0u: goto label_1e1dd0;
            case 0x1E1DE0u: goto label_1e1de0;
            case 0x1E1E04u: goto label_1e1e04;
            case 0x1E1E14u: goto label_1e1e14;
            case 0x1E1E38u: goto label_1e1e38;
            case 0x1E1E4Cu: goto label_1e1e4c;
            case 0x1E1E5Cu: goto label_1e1e5c;
            case 0x1E1E84u: goto label_1e1e84;
            case 0x1E1EA0u: goto label_1e1ea0;
            case 0x1E1EB4u: goto label_1e1eb4;
            case 0x1E1ED0u: goto label_1e1ed0;
            case 0x1E1F48u: goto label_1e1f48;
            case 0x1E1F5Cu: goto label_1e1f5c;
            case 0x1E1F9Cu: goto label_1e1f9c;
            case 0x1E1FACu: goto label_1e1fac;
            case 0x1E1FD0u: goto label_1e1fd0;
            case 0x1E1FE0u: goto label_1e1fe0;
            case 0x1E2004u: goto label_1e2004;
            case 0x1E2018u: goto label_1e2018;
            case 0x1E202Cu: goto label_1e202c;
            case 0x1E2064u: goto label_1e2064;
            case 0x1E206Cu: goto label_1e206c;
            case 0x1E2088u: goto label_1e2088;
            case 0x1E20A0u: goto label_1e20a0;
            case 0x1E20D4u: goto label_1e20d4;
            case 0x1E20F8u: goto label_1e20f8;
            case 0x1E210Cu: goto label_1e210c;
            case 0x1E2128u: goto label_1e2128;
            case 0x1E2190u: goto label_1e2190;
            case 0x1E21A4u: goto label_1e21a4;
            case 0x1E21E4u: goto label_1e21e4;
            case 0x1E21F4u: goto label_1e21f4;
            case 0x1E2218u: goto label_1e2218;
            case 0x1E2228u: goto label_1e2228;
            case 0x1E224Cu: goto label_1e224c;
            case 0x1E2260u: goto label_1e2260;
            case 0x1E22D4u: goto label_1e22d4;
            case 0x1E22F0u: goto label_1e22f0;
            case 0x1E2304u: goto label_1e2304;
            case 0x1E2320u: goto label_1e2320;
            case 0x1E23A0u: goto label_1e23a0;
            case 0x1E23B4u: goto label_1e23b4;
            case 0x1E23F4u: goto label_1e23f4;
            case 0x1E2404u: goto label_1e2404;
            case 0x1E2428u: goto label_1e2428;
            case 0x1E2438u: goto label_1e2438;
            case 0x1E245Cu: goto label_1e245c;
            case 0x1E2470u: goto label_1e2470;
            case 0x1E2480u: goto label_1e2480;
            case 0x1E24F8u: goto label_1e24f8;
            case 0x1E2500u: goto label_1e2500;
            case 0x1E2508u: goto label_1e2508;
            case 0x1E25D0u: goto label_1e25d0;
            case 0x1E25ECu: goto label_1e25ec;
            case 0x1E2600u: goto label_1e2600;
            case 0x1E261Cu: goto label_1e261c;
            case 0x1E2684u: goto label_1e2684;
            case 0x1E2698u: goto label_1e2698;
            case 0x1E26D8u: goto label_1e26d8;
            case 0x1E26E8u: goto label_1e26e8;
            case 0x1E270Cu: goto label_1e270c;
            case 0x1E271Cu: goto label_1e271c;
            case 0x1E2740u: goto label_1e2740;
            case 0x1E2754u: goto label_1e2754;
            case 0x1E27C8u: goto label_1e27c8;
            case 0x1E27E4u: goto label_1e27e4;
            case 0x1E27F8u: goto label_1e27f8;
            case 0x1E2814u: goto label_1e2814;
            case 0x1E287Cu: goto label_1e287c;
            case 0x1E2890u: goto label_1e2890;
            case 0x1E28D0u: goto label_1e28d0;
            case 0x1E28E0u: goto label_1e28e0;
            case 0x1E2904u: goto label_1e2904;
            case 0x1E2914u: goto label_1e2914;
            case 0x1E2938u: goto label_1e2938;
            case 0x1E294Cu: goto label_1e294c;
            case 0x1E29C0u: goto label_1e29c0;
            case 0x1E29DCu: goto label_1e29dc;
            case 0x1E29F0u: goto label_1e29f0;
            case 0x1E2A0Cu: goto label_1e2a0c;
            case 0x1E2A78u: goto label_1e2a78;
            case 0x1E2A8Cu: goto label_1e2a8c;
            case 0x1E2ACCu: goto label_1e2acc;
            case 0x1E2ADCu: goto label_1e2adc;
            case 0x1E2B00u: goto label_1e2b00;
            case 0x1E2B10u: goto label_1e2b10;
            case 0x1E2B34u: goto label_1e2b34;
            case 0x1E2B48u: goto label_1e2b48;
            case 0x1E2B54u: goto label_1e2b54;
            case 0x1E2B90u: goto label_1e2b90;
            case 0x1E2B98u: goto label_1e2b98;
            case 0x1E2BC0u: goto label_1e2bc0;
            case 0x1E2BE4u: goto label_1e2be4;
            case 0x1E2BF8u: goto label_1e2bf8;
            case 0x1E2C14u: goto label_1e2c14;
            case 0x1E2C84u: goto label_1e2c84;
            case 0x1E2C98u: goto label_1e2c98;
            case 0x1E2CD8u: goto label_1e2cd8;
            case 0x1E2CE8u: goto label_1e2ce8;
            case 0x1E2D0Cu: goto label_1e2d0c;
            case 0x1E2D1Cu: goto label_1e2d1c;
            case 0x1E2D40u: goto label_1e2d40;
            case 0x1E2D54u: goto label_1e2d54;
            case 0x1E2E10u: goto label_1e2e10;
            case 0x1E2E18u: goto label_1e2e18;
            case 0x1E2E20u: goto label_1e2e20;
            case 0x1E2E48u: goto label_1e2e48;
            case 0x1E2E64u: goto label_1e2e64;
            case 0x1E2E78u: goto label_1e2e78;
            case 0x1E2E94u: goto label_1e2e94;
            case 0x1E2EF8u: goto label_1e2ef8;
            case 0x1E2F0Cu: goto label_1e2f0c;
            case 0x1E2F4Cu: goto label_1e2f4c;
            case 0x1E2F5Cu: goto label_1e2f5c;
            case 0x1E2F80u: goto label_1e2f80;
            case 0x1E2FA8u: goto label_1e2fa8;
            case 0x1E2FC4u: goto label_1e2fc4;
            case 0x1E2FD8u: goto label_1e2fd8;
            case 0x1E2FF4u: goto label_1e2ff4;
            case 0x1E3058u: goto label_1e3058;
            case 0x1E306Cu: goto label_1e306c;
            case 0x1E30ACu: goto label_1e30ac;
            case 0x1E30BCu: goto label_1e30bc;
            case 0x1E30E0u: goto label_1e30e0;
            case 0x1E3108u: goto label_1e3108;
            case 0x1E3124u: goto label_1e3124;
            case 0x1E3138u: goto label_1e3138;
            case 0x1E3154u: goto label_1e3154;
            case 0x1E31CCu: goto label_1e31cc;
            case 0x1E31E0u: goto label_1e31e0;
            case 0x1E3220u: goto label_1e3220;
            case 0x1E3238u: goto label_1e3238;
            case 0x1E325Cu: goto label_1e325c;
            case 0x1E3278u: goto label_1e3278;
            case 0x1E329Cu: goto label_1e329c;
            case 0x1E32B0u: goto label_1e32b0;
            case 0x1E3318u: goto label_1e3318;
            case 0x1E3388u: goto label_1e3388;
            case 0x1E33C4u: goto label_1e33c4;
            case 0x1E33E0u: goto label_1e33e0;
            case 0x1E33F4u: goto label_1e33f4;
            case 0x1E3410u: goto label_1e3410;
            case 0x1E347Cu: goto label_1e347c;
            case 0x1E3490u: goto label_1e3490;
            case 0x1E34D0u: goto label_1e34d0;
            case 0x1E34E0u: goto label_1e34e0;
            case 0x1E3504u: goto label_1e3504;
            case 0x1E3514u: goto label_1e3514;
            case 0x1E3538u: goto label_1e3538;
            case 0x1E354Cu: goto label_1e354c;
            case 0x1E360Cu: goto label_1e360c;
            case 0x1E3628u: goto label_1e3628;
            case 0x1E363Cu: goto label_1e363c;
            case 0x1E3658u: goto label_1e3658;
            case 0x1E36C4u: goto label_1e36c4;
            case 0x1E36D8u: goto label_1e36d8;
            case 0x1E3718u: goto label_1e3718;
            case 0x1E3728u: goto label_1e3728;
            case 0x1E374Cu: goto label_1e374c;
            case 0x1E375Cu: goto label_1e375c;
            case 0x1E3780u: goto label_1e3780;
            case 0x1E3794u: goto label_1e3794;
            case 0x1E3854u: goto label_1e3854;
            case 0x1E3870u: goto label_1e3870;
            case 0x1E3884u: goto label_1e3884;
            case 0x1E38A0u: goto label_1e38a0;
            case 0x1E3908u: goto label_1e3908;
            case 0x1E391Cu: goto label_1e391c;
            case 0x1E395Cu: goto label_1e395c;
            case 0x1E396Cu: goto label_1e396c;
            case 0x1E3990u: goto label_1e3990;
            case 0x1E39A0u: goto label_1e39a0;
            case 0x1E39C4u: goto label_1e39c4;
            case 0x1E39D8u: goto label_1e39d8;
            case 0x1E3A44u: goto label_1e3a44;
            case 0x1E3A60u: goto label_1e3a60;
            case 0x1E3A74u: goto label_1e3a74;
            case 0x1E3A78u: goto label_1e3a78;
            case 0x1E3ADCu: goto label_1e3adc;
            case 0x1E3AF0u: goto label_1e3af0;
            case 0x1E3B30u: goto label_1e3b30;
            case 0x1E3B40u: goto label_1e3b40;
            case 0x1E3B64u: goto label_1e3b64;
            case 0x1E3B84u: goto label_1e3b84;
            case 0x1E3BA0u: goto label_1e3ba0;
            case 0x1E3BB4u: goto label_1e3bb4;
            case 0x1E3BB8u: goto label_1e3bb8;
            case 0x1E3C1Cu: goto label_1e3c1c;
            case 0x1E3C30u: goto label_1e3c30;
            case 0x1E3C70u: goto label_1e3c70;
            case 0x1E3C80u: goto label_1e3c80;
            case 0x1E3CA4u: goto label_1e3ca4;
            case 0x1E3CC4u: goto label_1e3cc4;
            case 0x1E3CE8u: goto label_1e3ce8;
            case 0x1E3CFCu: goto label_1e3cfc;
            case 0x1E3D00u: goto label_1e3d00;
            case 0x1E3D68u: goto label_1e3d68;
            case 0x1E3D7Cu: goto label_1e3d7c;
            case 0x1E3DBCu: goto label_1e3dbc;
            case 0x1E3DCCu: goto label_1e3dcc;
            case 0x1E3DF0u: goto label_1e3df0;
            case 0x1E3E00u: goto label_1e3e00;
            case 0x1E3E24u: goto label_1e3e24;
            case 0x1E3E38u: goto label_1e3e38;
            case 0x1E3EA4u: goto label_1e3ea4;
            case 0x1E3EC0u: goto label_1e3ec0;
            case 0x1E3ED4u: goto label_1e3ed4;
            case 0x1E3ED8u: goto label_1e3ed8;
            case 0x1E3F40u: goto label_1e3f40;
            case 0x1E3F54u: goto label_1e3f54;
            case 0x1E3F94u: goto label_1e3f94;
            case 0x1E3FA4u: goto label_1e3fa4;
            case 0x1E3FC8u: goto label_1e3fc8;
            case 0x1E3FD8u: goto label_1e3fd8;
            case 0x1E3FFCu: goto label_1e3ffc;
            case 0x1E4010u: goto label_1e4010;
            case 0x1E407Cu: goto label_1e407c;
            case 0x1E4098u: goto label_1e4098;
            case 0x1E40ACu: goto label_1e40ac;
            case 0x1E40B0u: goto label_1e40b0;
            case 0x1E4118u: goto label_1e4118;
            case 0x1E412Cu: goto label_1e412c;
            case 0x1E416Cu: goto label_1e416c;
            case 0x1E417Cu: goto label_1e417c;
            case 0x1E41A0u: goto label_1e41a0;
            case 0x1E41B0u: goto label_1e41b0;
            case 0x1E41D4u: goto label_1e41d4;
            case 0x1E41E8u: goto label_1e41e8;
            case 0x1E4254u: goto label_1e4254;
            case 0x1E4270u: goto label_1e4270;
            case 0x1E4284u: goto label_1e4284;
            case 0x1E4288u: goto label_1e4288;
            case 0x1E42F0u: goto label_1e42f0;
            case 0x1E4304u: goto label_1e4304;
            case 0x1E4344u: goto label_1e4344;
            case 0x1E4358u: goto label_1e4358;
            case 0x1E437Cu: goto label_1e437c;
            case 0x1E4394u: goto label_1e4394;
            case 0x1E43B8u: goto label_1e43b8;
            case 0x1E43CCu: goto label_1e43cc;
            case 0x1E43E4u: goto label_1e43e4;
            case 0x1E4414u: goto label_1e4414;
            case 0x1E4430u: goto label_1e4430;
            case 0x1E4444u: goto label_1e4444;
            case 0x1E4460u: goto label_1e4460;
            case 0x1E44C8u: goto label_1e44c8;
            case 0x1E44DCu: goto label_1e44dc;
            case 0x1E451Cu: goto label_1e451c;
            case 0x1E452Cu: goto label_1e452c;
            case 0x1E4550u: goto label_1e4550;
            case 0x1E4560u: goto label_1e4560;
            case 0x1E4584u: goto label_1e4584;
            case 0x1E4598u: goto label_1e4598;
            case 0x1E460Cu: goto label_1e460c;
            case 0x1E4628u: goto label_1e4628;
            case 0x1E463Cu: goto label_1e463c;
            case 0x1E4658u: goto label_1e4658;
            case 0x1E46C8u: goto label_1e46c8;
            case 0x1E46DCu: goto label_1e46dc;
            case 0x1E471Cu: goto label_1e471c;
            case 0x1E472Cu: goto label_1e472c;
            case 0x1E4750u: goto label_1e4750;
            case 0x1E4764u: goto label_1e4764;
            case 0x1E4788u: goto label_1e4788;
            case 0x1E479Cu: goto label_1e479c;
            case 0x1E47B0u: goto label_1e47b0;
            case 0x1E47E0u: goto label_1e47e0;
            case 0x1E47FCu: goto label_1e47fc;
            case 0x1E4800u: goto label_1e4800;
            case 0x1E48A0u: goto label_1e48a0;
            case 0x1E48B4u: goto label_1e48b4;
            case 0x1E48F4u: goto label_1e48f4;
            case 0x1E4918u: goto label_1e4918;
            case 0x1E493Cu: goto label_1e493c;
            case 0x1E4974u: goto label_1e4974;
            case 0x1E4998u: goto label_1e4998;
            case 0x1E49ACu: goto label_1e49ac;
            case 0x1E4A08u: goto label_1e4a08;
            case 0x1E4A24u: goto label_1e4a24;
            case 0x1E4AACu: goto label_1e4aac;
            case 0x1E4AC0u: goto label_1e4ac0;
            case 0x1E4B00u: goto label_1e4b00;
            case 0x1E4B1Cu: goto label_1e4b1c;
            case 0x1E4B20u: goto label_1e4b20;
            case 0x1E4B94u: goto label_1e4b94;
            case 0x1E4BA8u: goto label_1e4ba8;
            case 0x1E4BE8u: goto label_1e4be8;
            case 0x1E4C10u: goto label_1e4c10;
            case 0x1E4C34u: goto label_1e4c34;
            case 0x1E4C64u: goto label_1e4c64;
            case 0x1E4C88u: goto label_1e4c88;
            case 0x1E4C9Cu: goto label_1e4c9c;
            case 0x1E4D08u: goto label_1e4d08;
            case 0x1E4D28u: goto label_1e4d28;
            case 0x1E4DE4u: goto label_1e4de4;
            case 0x1E4DF8u: goto label_1e4df8;
            case 0x1E4E3Cu: goto label_1e4e3c;
            case 0x1E4E58u: goto label_1e4e58;
            case 0x1E4E5Cu: goto label_1e4e5c;
            case 0x1E4EC4u: goto label_1e4ec4;
            case 0x1E4ED8u: goto label_1e4ed8;
            case 0x1E4F18u: goto label_1e4f18;
            case 0x1E4F28u: goto label_1e4f28;
            case 0x1E4F4Cu: goto label_1e4f4c;
            case 0x1E4F60u: goto label_1e4f60;
            case 0x1E4F84u: goto label_1e4f84;
            case 0x1E4F98u: goto label_1e4f98;
            case 0x1E4FACu: goto label_1e4fac;
            case 0x1E4FD0u: goto label_1e4fd0;
            case 0x1E4FECu: goto label_1e4fec;
            case 0x1E4FF0u: goto label_1e4ff0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E3EF0u;
    // 0x1e3ef0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1e3ef0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1e3ef4: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1e3ef4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1e3ef8: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1e3ef8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1e3efc: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e3efcu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e3f00: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e3f00u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e3f04: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e3f04u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e3f08: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e3f08u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e3f0c: 0xafc00014  sw          $zero, 0x14($fp)
    ctx->pc = 0x1e3f0cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 0));
    // 0x1e3f10: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e3f10u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e3f14: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e3f14u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e3f18: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E3F18u;
    {
        const bool branch_taken_0x1e3f18 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e3f18) {
            ctx->pc = 0x1E3F40u;
            goto label_1e3f40;
        }
    }
    ctx->pc = 0x1E3F20u;
    // 0x1e3f20: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e3f20u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e3f24: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e3f24u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e3f28: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e3f28u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e3f2c: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e3f2cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e3f30: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e3f30u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e3f34: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e3f34u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e3f38: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E3F38u;
    {
        const bool branch_taken_0x1e3f38 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e3f38) {
            ctx->pc = 0x1E3F54u;
            goto label_1e3f54;
        }
    }
    ctx->pc = 0x1E3F40u;
label_1e3f40:
    // 0x1e3f40: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e3f40u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e3f44: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e3f44u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e3f48: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e3f48u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e3f4c: 0x10000058  b           . + 4 + (0x58 << 2)
    ctx->pc = 0x1E3F4Cu;
    {
        const bool branch_taken_0x1e3f4c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3f4c) {
            ctx->pc = 0x1E40B0u;
            goto label_1e40b0;
        }
    }
    ctx->pc = 0x1E3F54u;
label_1e3f54:
    // 0x1e3f54: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e3f54u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e3f58: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e3f58u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e3f5c: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e3f5cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e3f60: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e3f60u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e3f64: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e3f64u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e3f68: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e3f68u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e3f6c: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1e3f6cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1e3f70: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e3f70u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e3f74: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e3f74u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e3f78: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E3F78u;
    {
        const bool branch_taken_0x1e3f78 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3f78) {
            ctx->pc = 0x1E3F94u;
            goto label_1e3f94;
        }
    }
    ctx->pc = 0x1E3F80u;
    // 0x1e3f80: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e3f80u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e3f84: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e3f84u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e3f88: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e3f88u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e3f8c: 0x10000048  b           . + 4 + (0x48 << 2)
    ctx->pc = 0x1E3F8Cu;
    {
        const bool branch_taken_0x1e3f8c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3f8c) {
            ctx->pc = 0x1E40B0u;
            goto label_1e40b0;
        }
    }
    ctx->pc = 0x1E3F94u;
label_1e3f94:
    // 0x1e3f94: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e3f94u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e3f98: 0x24050004  addiu       $a1, $zero, 0x4
    ctx->pc = 0x1e3f98u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1e3f9c: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E3F9Cu;
    SET_GPR_U32(ctx, 31, 0x1E3FA4u);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3FA4u; }
        if (ctx->pc != 0x1E3FA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3FA4u; }
        if (ctx->pc != 0x1E3FA4u) { return; }
    }
    ctx->pc = 0x1E3FA4u;
label_1e3fa4:
    // 0x1e3fa4: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1e3fa4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1e3fa8: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e3fa8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e3fac: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E3FACu;
    {
        const bool branch_taken_0x1e3fac = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e3fac) {
            ctx->pc = 0x1E3FC8u;
            goto label_1e3fc8;
        }
    }
    ctx->pc = 0x1E3FB4u;
    // 0x1e3fb4: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e3fb4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e3fb8: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e3fb8u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e3fbc: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e3fbcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e3fc0: 0x1000003b  b           . + 4 + (0x3B << 2)
    ctx->pc = 0x1E3FC0u;
    {
        const bool branch_taken_0x1e3fc0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3fc0) {
            ctx->pc = 0x1E40B0u;
            goto label_1e40b0;
        }
    }
    ctx->pc = 0x1E3FC8u;
label_1e3fc8:
    // 0x1e3fc8: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1e3fc8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e3fcc: 0x24050004  addiu       $a1, $zero, 0x4
    ctx->pc = 0x1e3fccu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1e3fd0: 0xc07cc3c  jal         func_1F30F0
    ctx->pc = 0x1E3FD0u;
    SET_GPR_U32(ctx, 31, 0x1E3FD8u);
    ctx->pc = 0x1F30F0u;
    if (runtime->hasFunction(0x1F30F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F30F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3FD8u; }
        if (ctx->pc != 0x1E3FD8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F30F0_0x1f30f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3FD8u; }
        if (ctx->pc != 0x1E3FD8u) { return; }
    }
    ctx->pc = 0x1E3FD8u;
label_1e3fd8:
    // 0x1e3fd8: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1e3fd8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1e3fdc: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e3fdcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e3fe0: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1E3FE0u;
    {
        const bool branch_taken_0x1e3fe0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e3fe0) {
            ctx->pc = 0x1E4010u;
            goto label_1e4010;
        }
    }
    ctx->pc = 0x1E3FE8u;
    // 0x1e3fe8: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e3fe8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e3fec: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1e3fecu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1e3ff0: 0x8fc5000c  lw          $a1, 0xC($fp)
    ctx->pc = 0x1e3ff0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e3ff4: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1E3FF4u;
    SET_GPR_U32(ctx, 31, 0x1E3FFCu);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3FFCu; }
        if (ctx->pc != 0x1E3FFCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3FFCu; }
        if (ctx->pc != 0x1E3FFCu) { return; }
    }
    ctx->pc = 0x1E3FFCu;
label_1e3ffc:
    // 0x1e3ffc: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e3ffcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e4000: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e4000u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e4004: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e4004u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e4008: 0x10000029  b           . + 4 + (0x29 << 2)
    ctx->pc = 0x1E4008u;
    {
        const bool branch_taken_0x1e4008 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4008) {
            ctx->pc = 0x1E40B0u;
            goto label_1e40b0;
        }
    }
    ctx->pc = 0x1E4010u;
label_1e4010:
    // 0x1e4010: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e4010u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e4014: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e4014u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e4018: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1e4018u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1e401c: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1e401cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1e4020: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e4020u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e4024: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1e4024u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1e4028: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1e4028u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1e402c: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1e402cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e4030: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1e4030u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e4034: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1e4034u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1e4038: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e4038u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e403c: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1e403cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1e4040: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1e4040u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e4044: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1e4044u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e4048: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1e4048u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1e404c: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e404cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e4050: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1e4050u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1e4054: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1e4054u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e4058: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x1e4058u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x1e405c: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e405cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e4060: 0x8fc5000c  lw          $a1, 0xC($fp)
    ctx->pc = 0x1e4060u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e4064: 0x3406a000  ori         $a2, $zero, 0xA000
    ctx->pc = 0x1e4064u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)40960);
    // 0x1e4068: 0x24070004  addiu       $a3, $zero, 0x4
    ctx->pc = 0x1e4068u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1e406c: 0x2408000a  addiu       $t0, $zero, 0xA
    ctx->pc = 0x1e406cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x1e4070: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1e4070u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e4074: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E4074u;
    SET_GPR_U32(ctx, 31, 0x1E407Cu);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E407Cu; }
        if (ctx->pc != 0x1E407Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E407Cu; }
        if (ctx->pc != 0x1E407Cu) { return; }
    }
    ctx->pc = 0x1E407Cu;
label_1e407c:
    // 0x1e407c: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E407Cu;
    {
        const bool branch_taken_0x1e407c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e407c) {
            ctx->pc = 0x1E4098u;
            goto label_1e4098;
        }
    }
    ctx->pc = 0x1E4084u;
    // 0x1e4084: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e4084u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e4088: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e4088u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e408c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e408cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e4090: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1E4090u;
    {
        const bool branch_taken_0x1e4090 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4090) {
            ctx->pc = 0x1E40B0u;
            goto label_1e40b0;
        }
    }
    ctx->pc = 0x1E4098u;
label_1e4098:
    // 0x1e4098: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1e4098u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e409c: 0x24050018  addiu       $a1, $zero, 0x18
    ctx->pc = 0x1e409cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 24));
    // 0x1e40a0: 0x8fc60008  lw          $a2, 0x8($fp)
    ctx->pc = 0x1e40a0u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e40a4: 0xc076ad5  jal         func_1DAB54
    ctx->pc = 0x1E40A4u;
    SET_GPR_U32(ctx, 31, 0x1E40ACu);
    ctx->pc = 0x1DAB54u;
    if (runtime->hasFunction(0x1DAB54u)) {
        auto targetFn = runtime->lookupFunction(0x1DAB54u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E40ACu; }
        if (ctx->pc != 0x1E40ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DAB54_0x1dab54(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E40ACu; }
        if (ctx->pc != 0x1E40ACu) { return; }
    }
    ctx->pc = 0x1E40ACu;
label_1e40ac:
    // 0x1e40ac: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1e40acu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1e40b0:
    // 0x1e40b0: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e40b0u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e40b4: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1e40b4u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1e40b8: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1e40b8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1e40bc: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1e40bcu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1e40c0: 0x3e00008  jr          $ra
    ctx->pc = 0x1E40C0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E1B3Cu: goto label_1e1b3c;
            case 0x1E1B60u: goto label_1e1b60;
            case 0x1E1B84u: goto label_1e1b84;
            case 0x1E1BA8u: goto label_1e1ba8;
            case 0x1E1BC8u: goto label_1e1bc8;
            case 0x1E1BE4u: goto label_1e1be4;
            case 0x1E1BE8u: goto label_1e1be8;
            case 0x1E1C44u: goto label_1e1c44;
            case 0x1E1C58u: goto label_1e1c58;
            case 0x1E1C7Cu: goto label_1e1c7c;
            case 0x1E1CD8u: goto label_1e1cd8;
            case 0x1E1CECu: goto label_1e1cec;
            case 0x1E1D14u: goto label_1e1d14;
            case 0x1E1D7Cu: goto label_1e1d7c;
            case 0x1E1D90u: goto label_1e1d90;
            case 0x1E1DD0u: goto label_1e1dd0;
            case 0x1E1DE0u: goto label_1e1de0;
            case 0x1E1E04u: goto label_1e1e04;
            case 0x1E1E14u: goto label_1e1e14;
            case 0x1E1E38u: goto label_1e1e38;
            case 0x1E1E4Cu: goto label_1e1e4c;
            case 0x1E1E5Cu: goto label_1e1e5c;
            case 0x1E1E84u: goto label_1e1e84;
            case 0x1E1EA0u: goto label_1e1ea0;
            case 0x1E1EB4u: goto label_1e1eb4;
            case 0x1E1ED0u: goto label_1e1ed0;
            case 0x1E1F48u: goto label_1e1f48;
            case 0x1E1F5Cu: goto label_1e1f5c;
            case 0x1E1F9Cu: goto label_1e1f9c;
            case 0x1E1FACu: goto label_1e1fac;
            case 0x1E1FD0u: goto label_1e1fd0;
            case 0x1E1FE0u: goto label_1e1fe0;
            case 0x1E2004u: goto label_1e2004;
            case 0x1E2018u: goto label_1e2018;
            case 0x1E202Cu: goto label_1e202c;
            case 0x1E2064u: goto label_1e2064;
            case 0x1E206Cu: goto label_1e206c;
            case 0x1E2088u: goto label_1e2088;
            case 0x1E20A0u: goto label_1e20a0;
            case 0x1E20D4u: goto label_1e20d4;
            case 0x1E20F8u: goto label_1e20f8;
            case 0x1E210Cu: goto label_1e210c;
            case 0x1E2128u: goto label_1e2128;
            case 0x1E2190u: goto label_1e2190;
            case 0x1E21A4u: goto label_1e21a4;
            case 0x1E21E4u: goto label_1e21e4;
            case 0x1E21F4u: goto label_1e21f4;
            case 0x1E2218u: goto label_1e2218;
            case 0x1E2228u: goto label_1e2228;
            case 0x1E224Cu: goto label_1e224c;
            case 0x1E2260u: goto label_1e2260;
            case 0x1E22D4u: goto label_1e22d4;
            case 0x1E22F0u: goto label_1e22f0;
            case 0x1E2304u: goto label_1e2304;
            case 0x1E2320u: goto label_1e2320;
            case 0x1E23A0u: goto label_1e23a0;
            case 0x1E23B4u: goto label_1e23b4;
            case 0x1E23F4u: goto label_1e23f4;
            case 0x1E2404u: goto label_1e2404;
            case 0x1E2428u: goto label_1e2428;
            case 0x1E2438u: goto label_1e2438;
            case 0x1E245Cu: goto label_1e245c;
            case 0x1E2470u: goto label_1e2470;
            case 0x1E2480u: goto label_1e2480;
            case 0x1E24F8u: goto label_1e24f8;
            case 0x1E2500u: goto label_1e2500;
            case 0x1E2508u: goto label_1e2508;
            case 0x1E25D0u: goto label_1e25d0;
            case 0x1E25ECu: goto label_1e25ec;
            case 0x1E2600u: goto label_1e2600;
            case 0x1E261Cu: goto label_1e261c;
            case 0x1E2684u: goto label_1e2684;
            case 0x1E2698u: goto label_1e2698;
            case 0x1E26D8u: goto label_1e26d8;
            case 0x1E26E8u: goto label_1e26e8;
            case 0x1E270Cu: goto label_1e270c;
            case 0x1E271Cu: goto label_1e271c;
            case 0x1E2740u: goto label_1e2740;
            case 0x1E2754u: goto label_1e2754;
            case 0x1E27C8u: goto label_1e27c8;
            case 0x1E27E4u: goto label_1e27e4;
            case 0x1E27F8u: goto label_1e27f8;
            case 0x1E2814u: goto label_1e2814;
            case 0x1E287Cu: goto label_1e287c;
            case 0x1E2890u: goto label_1e2890;
            case 0x1E28D0u: goto label_1e28d0;
            case 0x1E28E0u: goto label_1e28e0;
            case 0x1E2904u: goto label_1e2904;
            case 0x1E2914u: goto label_1e2914;
            case 0x1E2938u: goto label_1e2938;
            case 0x1E294Cu: goto label_1e294c;
            case 0x1E29C0u: goto label_1e29c0;
            case 0x1E29DCu: goto label_1e29dc;
            case 0x1E29F0u: goto label_1e29f0;
            case 0x1E2A0Cu: goto label_1e2a0c;
            case 0x1E2A78u: goto label_1e2a78;
            case 0x1E2A8Cu: goto label_1e2a8c;
            case 0x1E2ACCu: goto label_1e2acc;
            case 0x1E2ADCu: goto label_1e2adc;
            case 0x1E2B00u: goto label_1e2b00;
            case 0x1E2B10u: goto label_1e2b10;
            case 0x1E2B34u: goto label_1e2b34;
            case 0x1E2B48u: goto label_1e2b48;
            case 0x1E2B54u: goto label_1e2b54;
            case 0x1E2B90u: goto label_1e2b90;
            case 0x1E2B98u: goto label_1e2b98;
            case 0x1E2BC0u: goto label_1e2bc0;
            case 0x1E2BE4u: goto label_1e2be4;
            case 0x1E2BF8u: goto label_1e2bf8;
            case 0x1E2C14u: goto label_1e2c14;
            case 0x1E2C84u: goto label_1e2c84;
            case 0x1E2C98u: goto label_1e2c98;
            case 0x1E2CD8u: goto label_1e2cd8;
            case 0x1E2CE8u: goto label_1e2ce8;
            case 0x1E2D0Cu: goto label_1e2d0c;
            case 0x1E2D1Cu: goto label_1e2d1c;
            case 0x1E2D40u: goto label_1e2d40;
            case 0x1E2D54u: goto label_1e2d54;
            case 0x1E2E10u: goto label_1e2e10;
            case 0x1E2E18u: goto label_1e2e18;
            case 0x1E2E20u: goto label_1e2e20;
            case 0x1E2E48u: goto label_1e2e48;
            case 0x1E2E64u: goto label_1e2e64;
            case 0x1E2E78u: goto label_1e2e78;
            case 0x1E2E94u: goto label_1e2e94;
            case 0x1E2EF8u: goto label_1e2ef8;
            case 0x1E2F0Cu: goto label_1e2f0c;
            case 0x1E2F4Cu: goto label_1e2f4c;
            case 0x1E2F5Cu: goto label_1e2f5c;
            case 0x1E2F80u: goto label_1e2f80;
            case 0x1E2FA8u: goto label_1e2fa8;
            case 0x1E2FC4u: goto label_1e2fc4;
            case 0x1E2FD8u: goto label_1e2fd8;
            case 0x1E2FF4u: goto label_1e2ff4;
            case 0x1E3058u: goto label_1e3058;
            case 0x1E306Cu: goto label_1e306c;
            case 0x1E30ACu: goto label_1e30ac;
            case 0x1E30BCu: goto label_1e30bc;
            case 0x1E30E0u: goto label_1e30e0;
            case 0x1E3108u: goto label_1e3108;
            case 0x1E3124u: goto label_1e3124;
            case 0x1E3138u: goto label_1e3138;
            case 0x1E3154u: goto label_1e3154;
            case 0x1E31CCu: goto label_1e31cc;
            case 0x1E31E0u: goto label_1e31e0;
            case 0x1E3220u: goto label_1e3220;
            case 0x1E3238u: goto label_1e3238;
            case 0x1E325Cu: goto label_1e325c;
            case 0x1E3278u: goto label_1e3278;
            case 0x1E329Cu: goto label_1e329c;
            case 0x1E32B0u: goto label_1e32b0;
            case 0x1E3318u: goto label_1e3318;
            case 0x1E3388u: goto label_1e3388;
            case 0x1E33C4u: goto label_1e33c4;
            case 0x1E33E0u: goto label_1e33e0;
            case 0x1E33F4u: goto label_1e33f4;
            case 0x1E3410u: goto label_1e3410;
            case 0x1E347Cu: goto label_1e347c;
            case 0x1E3490u: goto label_1e3490;
            case 0x1E34D0u: goto label_1e34d0;
            case 0x1E34E0u: goto label_1e34e0;
            case 0x1E3504u: goto label_1e3504;
            case 0x1E3514u: goto label_1e3514;
            case 0x1E3538u: goto label_1e3538;
            case 0x1E354Cu: goto label_1e354c;
            case 0x1E360Cu: goto label_1e360c;
            case 0x1E3628u: goto label_1e3628;
            case 0x1E363Cu: goto label_1e363c;
            case 0x1E3658u: goto label_1e3658;
            case 0x1E36C4u: goto label_1e36c4;
            case 0x1E36D8u: goto label_1e36d8;
            case 0x1E3718u: goto label_1e3718;
            case 0x1E3728u: goto label_1e3728;
            case 0x1E374Cu: goto label_1e374c;
            case 0x1E375Cu: goto label_1e375c;
            case 0x1E3780u: goto label_1e3780;
            case 0x1E3794u: goto label_1e3794;
            case 0x1E3854u: goto label_1e3854;
            case 0x1E3870u: goto label_1e3870;
            case 0x1E3884u: goto label_1e3884;
            case 0x1E38A0u: goto label_1e38a0;
            case 0x1E3908u: goto label_1e3908;
            case 0x1E391Cu: goto label_1e391c;
            case 0x1E395Cu: goto label_1e395c;
            case 0x1E396Cu: goto label_1e396c;
            case 0x1E3990u: goto label_1e3990;
            case 0x1E39A0u: goto label_1e39a0;
            case 0x1E39C4u: goto label_1e39c4;
            case 0x1E39D8u: goto label_1e39d8;
            case 0x1E3A44u: goto label_1e3a44;
            case 0x1E3A60u: goto label_1e3a60;
            case 0x1E3A74u: goto label_1e3a74;
            case 0x1E3A78u: goto label_1e3a78;
            case 0x1E3ADCu: goto label_1e3adc;
            case 0x1E3AF0u: goto label_1e3af0;
            case 0x1E3B30u: goto label_1e3b30;
            case 0x1E3B40u: goto label_1e3b40;
            case 0x1E3B64u: goto label_1e3b64;
            case 0x1E3B84u: goto label_1e3b84;
            case 0x1E3BA0u: goto label_1e3ba0;
            case 0x1E3BB4u: goto label_1e3bb4;
            case 0x1E3BB8u: goto label_1e3bb8;
            case 0x1E3C1Cu: goto label_1e3c1c;
            case 0x1E3C30u: goto label_1e3c30;
            case 0x1E3C70u: goto label_1e3c70;
            case 0x1E3C80u: goto label_1e3c80;
            case 0x1E3CA4u: goto label_1e3ca4;
            case 0x1E3CC4u: goto label_1e3cc4;
            case 0x1E3CE8u: goto label_1e3ce8;
            case 0x1E3CFCu: goto label_1e3cfc;
            case 0x1E3D00u: goto label_1e3d00;
            case 0x1E3D68u: goto label_1e3d68;
            case 0x1E3D7Cu: goto label_1e3d7c;
            case 0x1E3DBCu: goto label_1e3dbc;
            case 0x1E3DCCu: goto label_1e3dcc;
            case 0x1E3DF0u: goto label_1e3df0;
            case 0x1E3E00u: goto label_1e3e00;
            case 0x1E3E24u: goto label_1e3e24;
            case 0x1E3E38u: goto label_1e3e38;
            case 0x1E3EA4u: goto label_1e3ea4;
            case 0x1E3EC0u: goto label_1e3ec0;
            case 0x1E3ED4u: goto label_1e3ed4;
            case 0x1E3ED8u: goto label_1e3ed8;
            case 0x1E3F40u: goto label_1e3f40;
            case 0x1E3F54u: goto label_1e3f54;
            case 0x1E3F94u: goto label_1e3f94;
            case 0x1E3FA4u: goto label_1e3fa4;
            case 0x1E3FC8u: goto label_1e3fc8;
            case 0x1E3FD8u: goto label_1e3fd8;
            case 0x1E3FFCu: goto label_1e3ffc;
            case 0x1E4010u: goto label_1e4010;
            case 0x1E407Cu: goto label_1e407c;
            case 0x1E4098u: goto label_1e4098;
            case 0x1E40ACu: goto label_1e40ac;
            case 0x1E40B0u: goto label_1e40b0;
            case 0x1E4118u: goto label_1e4118;
            case 0x1E412Cu: goto label_1e412c;
            case 0x1E416Cu: goto label_1e416c;
            case 0x1E417Cu: goto label_1e417c;
            case 0x1E41A0u: goto label_1e41a0;
            case 0x1E41B0u: goto label_1e41b0;
            case 0x1E41D4u: goto label_1e41d4;
            case 0x1E41E8u: goto label_1e41e8;
            case 0x1E4254u: goto label_1e4254;
            case 0x1E4270u: goto label_1e4270;
            case 0x1E4284u: goto label_1e4284;
            case 0x1E4288u: goto label_1e4288;
            case 0x1E42F0u: goto label_1e42f0;
            case 0x1E4304u: goto label_1e4304;
            case 0x1E4344u: goto label_1e4344;
            case 0x1E4358u: goto label_1e4358;
            case 0x1E437Cu: goto label_1e437c;
            case 0x1E4394u: goto label_1e4394;
            case 0x1E43B8u: goto label_1e43b8;
            case 0x1E43CCu: goto label_1e43cc;
            case 0x1E43E4u: goto label_1e43e4;
            case 0x1E4414u: goto label_1e4414;
            case 0x1E4430u: goto label_1e4430;
            case 0x1E4444u: goto label_1e4444;
            case 0x1E4460u: goto label_1e4460;
            case 0x1E44C8u: goto label_1e44c8;
            case 0x1E44DCu: goto label_1e44dc;
            case 0x1E451Cu: goto label_1e451c;
            case 0x1E452Cu: goto label_1e452c;
            case 0x1E4550u: goto label_1e4550;
            case 0x1E4560u: goto label_1e4560;
            case 0x1E4584u: goto label_1e4584;
            case 0x1E4598u: goto label_1e4598;
            case 0x1E460Cu: goto label_1e460c;
            case 0x1E4628u: goto label_1e4628;
            case 0x1E463Cu: goto label_1e463c;
            case 0x1E4658u: goto label_1e4658;
            case 0x1E46C8u: goto label_1e46c8;
            case 0x1E46DCu: goto label_1e46dc;
            case 0x1E471Cu: goto label_1e471c;
            case 0x1E472Cu: goto label_1e472c;
            case 0x1E4750u: goto label_1e4750;
            case 0x1E4764u: goto label_1e4764;
            case 0x1E4788u: goto label_1e4788;
            case 0x1E479Cu: goto label_1e479c;
            case 0x1E47B0u: goto label_1e47b0;
            case 0x1E47E0u: goto label_1e47e0;
            case 0x1E47FCu: goto label_1e47fc;
            case 0x1E4800u: goto label_1e4800;
            case 0x1E48A0u: goto label_1e48a0;
            case 0x1E48B4u: goto label_1e48b4;
            case 0x1E48F4u: goto label_1e48f4;
            case 0x1E4918u: goto label_1e4918;
            case 0x1E493Cu: goto label_1e493c;
            case 0x1E4974u: goto label_1e4974;
            case 0x1E4998u: goto label_1e4998;
            case 0x1E49ACu: goto label_1e49ac;
            case 0x1E4A08u: goto label_1e4a08;
            case 0x1E4A24u: goto label_1e4a24;
            case 0x1E4AACu: goto label_1e4aac;
            case 0x1E4AC0u: goto label_1e4ac0;
            case 0x1E4B00u: goto label_1e4b00;
            case 0x1E4B1Cu: goto label_1e4b1c;
            case 0x1E4B20u: goto label_1e4b20;
            case 0x1E4B94u: goto label_1e4b94;
            case 0x1E4BA8u: goto label_1e4ba8;
            case 0x1E4BE8u: goto label_1e4be8;
            case 0x1E4C10u: goto label_1e4c10;
            case 0x1E4C34u: goto label_1e4c34;
            case 0x1E4C64u: goto label_1e4c64;
            case 0x1E4C88u: goto label_1e4c88;
            case 0x1E4C9Cu: goto label_1e4c9c;
            case 0x1E4D08u: goto label_1e4d08;
            case 0x1E4D28u: goto label_1e4d28;
            case 0x1E4DE4u: goto label_1e4de4;
            case 0x1E4DF8u: goto label_1e4df8;
            case 0x1E4E3Cu: goto label_1e4e3c;
            case 0x1E4E58u: goto label_1e4e58;
            case 0x1E4E5Cu: goto label_1e4e5c;
            case 0x1E4EC4u: goto label_1e4ec4;
            case 0x1E4ED8u: goto label_1e4ed8;
            case 0x1E4F18u: goto label_1e4f18;
            case 0x1E4F28u: goto label_1e4f28;
            case 0x1E4F4Cu: goto label_1e4f4c;
            case 0x1E4F60u: goto label_1e4f60;
            case 0x1E4F84u: goto label_1e4f84;
            case 0x1E4F98u: goto label_1e4f98;
            case 0x1E4FACu: goto label_1e4fac;
            case 0x1E4FD0u: goto label_1e4fd0;
            case 0x1E4FECu: goto label_1e4fec;
            case 0x1E4FF0u: goto label_1e4ff0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E40C8u;
    // 0x1e40c8: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1e40c8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1e40cc: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1e40ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1e40d0: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1e40d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1e40d4: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e40d4u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e40d8: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e40d8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e40dc: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e40dcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e40e0: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e40e0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e40e4: 0xafc00014  sw          $zero, 0x14($fp)
    ctx->pc = 0x1e40e4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 0));
    // 0x1e40e8: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e40e8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e40ec: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e40ecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e40f0: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E40F0u;
    {
        const bool branch_taken_0x1e40f0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e40f0) {
            ctx->pc = 0x1E4118u;
            goto label_1e4118;
        }
    }
    ctx->pc = 0x1E40F8u;
    // 0x1e40f8: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e40f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e40fc: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e40fcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e4100: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e4100u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e4104: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e4104u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e4108: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e4108u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e410c: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e410cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e4110: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E4110u;
    {
        const bool branch_taken_0x1e4110 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e4110) {
            ctx->pc = 0x1E412Cu;
            goto label_1e412c;
        }
    }
    ctx->pc = 0x1E4118u;
label_1e4118:
    // 0x1e4118: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e4118u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e411c: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e411cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e4120: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e4120u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e4124: 0x10000058  b           . + 4 + (0x58 << 2)
    ctx->pc = 0x1E4124u;
    {
        const bool branch_taken_0x1e4124 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4124) {
            ctx->pc = 0x1E4288u;
            goto label_1e4288;
        }
    }
    ctx->pc = 0x1E412Cu;
label_1e412c:
    // 0x1e412c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e412cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e4130: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e4130u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e4134: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e4134u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e4138: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e4138u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e413c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e413cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e4140: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e4140u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e4144: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1e4144u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1e4148: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e4148u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e414c: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e414cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e4150: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E4150u;
    {
        const bool branch_taken_0x1e4150 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4150) {
            ctx->pc = 0x1E416Cu;
            goto label_1e416c;
        }
    }
    ctx->pc = 0x1E4158u;
    // 0x1e4158: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e4158u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e415c: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e415cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e4160: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e4160u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e4164: 0x10000048  b           . + 4 + (0x48 << 2)
    ctx->pc = 0x1E4164u;
    {
        const bool branch_taken_0x1e4164 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4164) {
            ctx->pc = 0x1E4288u;
            goto label_1e4288;
        }
    }
    ctx->pc = 0x1E416Cu;
label_1e416c:
    // 0x1e416c: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e416cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e4170: 0x24050004  addiu       $a1, $zero, 0x4
    ctx->pc = 0x1e4170u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1e4174: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E4174u;
    SET_GPR_U32(ctx, 31, 0x1E417Cu);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E417Cu; }
        if (ctx->pc != 0x1E417Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E417Cu; }
        if (ctx->pc != 0x1E417Cu) { return; }
    }
    ctx->pc = 0x1E417Cu;
label_1e417c:
    // 0x1e417c: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1e417cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1e4180: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e4180u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e4184: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E4184u;
    {
        const bool branch_taken_0x1e4184 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e4184) {
            ctx->pc = 0x1E41A0u;
            goto label_1e41a0;
        }
    }
    ctx->pc = 0x1E418Cu;
    // 0x1e418c: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e418cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e4190: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e4190u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e4194: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e4194u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e4198: 0x1000003b  b           . + 4 + (0x3B << 2)
    ctx->pc = 0x1E4198u;
    {
        const bool branch_taken_0x1e4198 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4198) {
            ctx->pc = 0x1E4288u;
            goto label_1e4288;
        }
    }
    ctx->pc = 0x1E41A0u;
label_1e41a0:
    // 0x1e41a0: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1e41a0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e41a4: 0x24050004  addiu       $a1, $zero, 0x4
    ctx->pc = 0x1e41a4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1e41a8: 0xc07cc3c  jal         func_1F30F0
    ctx->pc = 0x1E41A8u;
    SET_GPR_U32(ctx, 31, 0x1E41B0u);
    ctx->pc = 0x1F30F0u;
    if (runtime->hasFunction(0x1F30F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F30F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E41B0u; }
        if (ctx->pc != 0x1E41B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F30F0_0x1f30f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E41B0u; }
        if (ctx->pc != 0x1E41B0u) { return; }
    }
    ctx->pc = 0x1E41B0u;
label_1e41b0:
    // 0x1e41b0: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1e41b0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1e41b4: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e41b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e41b8: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1E41B8u;
    {
        const bool branch_taken_0x1e41b8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e41b8) {
            ctx->pc = 0x1E41E8u;
            goto label_1e41e8;
        }
    }
    ctx->pc = 0x1E41C0u;
    // 0x1e41c0: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e41c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e41c4: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1e41c4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1e41c8: 0x8fc5000c  lw          $a1, 0xC($fp)
    ctx->pc = 0x1e41c8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e41cc: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1E41CCu;
    SET_GPR_U32(ctx, 31, 0x1E41D4u);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E41D4u; }
        if (ctx->pc != 0x1E41D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E41D4u; }
        if (ctx->pc != 0x1E41D4u) { return; }
    }
    ctx->pc = 0x1E41D4u;
label_1e41d4:
    // 0x1e41d4: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e41d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e41d8: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e41d8u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e41dc: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e41dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e41e0: 0x10000029  b           . + 4 + (0x29 << 2)
    ctx->pc = 0x1E41E0u;
    {
        const bool branch_taken_0x1e41e0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e41e0) {
            ctx->pc = 0x1E4288u;
            goto label_1e4288;
        }
    }
    ctx->pc = 0x1E41E8u;
label_1e41e8:
    // 0x1e41e8: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e41e8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e41ec: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e41ecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e41f0: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1e41f0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1e41f4: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1e41f4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1e41f8: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e41f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e41fc: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1e41fcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1e4200: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1e4200u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1e4204: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1e4204u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e4208: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1e4208u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e420c: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1e420cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1e4210: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e4210u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e4214: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1e4214u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1e4218: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1e4218u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e421c: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1e421cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e4220: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1e4220u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1e4224: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e4224u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e4228: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1e4228u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1e422c: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1e422cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e4230: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x1e4230u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x1e4234: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e4234u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e4238: 0x8fc5000c  lw          $a1, 0xC($fp)
    ctx->pc = 0x1e4238u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e423c: 0x3406a000  ori         $a2, $zero, 0xA000
    ctx->pc = 0x1e423cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)40960);
    // 0x1e4240: 0x24070004  addiu       $a3, $zero, 0x4
    ctx->pc = 0x1e4240u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1e4244: 0x24080043  addiu       $t0, $zero, 0x43
    ctx->pc = 0x1e4244u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 67));
    // 0x1e4248: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1e4248u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e424c: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E424Cu;
    SET_GPR_U32(ctx, 31, 0x1E4254u);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4254u; }
        if (ctx->pc != 0x1E4254u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4254u; }
        if (ctx->pc != 0x1E4254u) { return; }
    }
    ctx->pc = 0x1E4254u;
label_1e4254:
    // 0x1e4254: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E4254u;
    {
        const bool branch_taken_0x1e4254 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4254) {
            ctx->pc = 0x1E4270u;
            goto label_1e4270;
        }
    }
    ctx->pc = 0x1E425Cu;
    // 0x1e425c: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e425cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e4260: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e4260u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e4264: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e4264u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e4268: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1E4268u;
    {
        const bool branch_taken_0x1e4268 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4268) {
            ctx->pc = 0x1E4288u;
            goto label_1e4288;
        }
    }
    ctx->pc = 0x1E4270u;
label_1e4270:
    // 0x1e4270: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1e4270u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e4274: 0x2405002e  addiu       $a1, $zero, 0x2E
    ctx->pc = 0x1e4274u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 46));
    // 0x1e4278: 0x8fc60008  lw          $a2, 0x8($fp)
    ctx->pc = 0x1e4278u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e427c: 0xc076ad5  jal         func_1DAB54
    ctx->pc = 0x1E427Cu;
    SET_GPR_U32(ctx, 31, 0x1E4284u);
    ctx->pc = 0x1DAB54u;
    if (runtime->hasFunction(0x1DAB54u)) {
        auto targetFn = runtime->lookupFunction(0x1DAB54u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4284u; }
        if (ctx->pc != 0x1E4284u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DAB54_0x1dab54(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4284u; }
        if (ctx->pc != 0x1E4284u) { return; }
    }
    ctx->pc = 0x1E4284u;
label_1e4284:
    // 0x1e4284: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1e4284u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1e4288:
    // 0x1e4288: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e4288u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e428c: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1e428cu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1e4290: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1e4290u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1e4294: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1e4294u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1e4298: 0x3e00008  jr          $ra
    ctx->pc = 0x1E4298u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E1B3Cu: goto label_1e1b3c;
            case 0x1E1B60u: goto label_1e1b60;
            case 0x1E1B84u: goto label_1e1b84;
            case 0x1E1BA8u: goto label_1e1ba8;
            case 0x1E1BC8u: goto label_1e1bc8;
            case 0x1E1BE4u: goto label_1e1be4;
            case 0x1E1BE8u: goto label_1e1be8;
            case 0x1E1C44u: goto label_1e1c44;
            case 0x1E1C58u: goto label_1e1c58;
            case 0x1E1C7Cu: goto label_1e1c7c;
            case 0x1E1CD8u: goto label_1e1cd8;
            case 0x1E1CECu: goto label_1e1cec;
            case 0x1E1D14u: goto label_1e1d14;
            case 0x1E1D7Cu: goto label_1e1d7c;
            case 0x1E1D90u: goto label_1e1d90;
            case 0x1E1DD0u: goto label_1e1dd0;
            case 0x1E1DE0u: goto label_1e1de0;
            case 0x1E1E04u: goto label_1e1e04;
            case 0x1E1E14u: goto label_1e1e14;
            case 0x1E1E38u: goto label_1e1e38;
            case 0x1E1E4Cu: goto label_1e1e4c;
            case 0x1E1E5Cu: goto label_1e1e5c;
            case 0x1E1E84u: goto label_1e1e84;
            case 0x1E1EA0u: goto label_1e1ea0;
            case 0x1E1EB4u: goto label_1e1eb4;
            case 0x1E1ED0u: goto label_1e1ed0;
            case 0x1E1F48u: goto label_1e1f48;
            case 0x1E1F5Cu: goto label_1e1f5c;
            case 0x1E1F9Cu: goto label_1e1f9c;
            case 0x1E1FACu: goto label_1e1fac;
            case 0x1E1FD0u: goto label_1e1fd0;
            case 0x1E1FE0u: goto label_1e1fe0;
            case 0x1E2004u: goto label_1e2004;
            case 0x1E2018u: goto label_1e2018;
            case 0x1E202Cu: goto label_1e202c;
            case 0x1E2064u: goto label_1e2064;
            case 0x1E206Cu: goto label_1e206c;
            case 0x1E2088u: goto label_1e2088;
            case 0x1E20A0u: goto label_1e20a0;
            case 0x1E20D4u: goto label_1e20d4;
            case 0x1E20F8u: goto label_1e20f8;
            case 0x1E210Cu: goto label_1e210c;
            case 0x1E2128u: goto label_1e2128;
            case 0x1E2190u: goto label_1e2190;
            case 0x1E21A4u: goto label_1e21a4;
            case 0x1E21E4u: goto label_1e21e4;
            case 0x1E21F4u: goto label_1e21f4;
            case 0x1E2218u: goto label_1e2218;
            case 0x1E2228u: goto label_1e2228;
            case 0x1E224Cu: goto label_1e224c;
            case 0x1E2260u: goto label_1e2260;
            case 0x1E22D4u: goto label_1e22d4;
            case 0x1E22F0u: goto label_1e22f0;
            case 0x1E2304u: goto label_1e2304;
            case 0x1E2320u: goto label_1e2320;
            case 0x1E23A0u: goto label_1e23a0;
            case 0x1E23B4u: goto label_1e23b4;
            case 0x1E23F4u: goto label_1e23f4;
            case 0x1E2404u: goto label_1e2404;
            case 0x1E2428u: goto label_1e2428;
            case 0x1E2438u: goto label_1e2438;
            case 0x1E245Cu: goto label_1e245c;
            case 0x1E2470u: goto label_1e2470;
            case 0x1E2480u: goto label_1e2480;
            case 0x1E24F8u: goto label_1e24f8;
            case 0x1E2500u: goto label_1e2500;
            case 0x1E2508u: goto label_1e2508;
            case 0x1E25D0u: goto label_1e25d0;
            case 0x1E25ECu: goto label_1e25ec;
            case 0x1E2600u: goto label_1e2600;
            case 0x1E261Cu: goto label_1e261c;
            case 0x1E2684u: goto label_1e2684;
            case 0x1E2698u: goto label_1e2698;
            case 0x1E26D8u: goto label_1e26d8;
            case 0x1E26E8u: goto label_1e26e8;
            case 0x1E270Cu: goto label_1e270c;
            case 0x1E271Cu: goto label_1e271c;
            case 0x1E2740u: goto label_1e2740;
            case 0x1E2754u: goto label_1e2754;
            case 0x1E27C8u: goto label_1e27c8;
            case 0x1E27E4u: goto label_1e27e4;
            case 0x1E27F8u: goto label_1e27f8;
            case 0x1E2814u: goto label_1e2814;
            case 0x1E287Cu: goto label_1e287c;
            case 0x1E2890u: goto label_1e2890;
            case 0x1E28D0u: goto label_1e28d0;
            case 0x1E28E0u: goto label_1e28e0;
            case 0x1E2904u: goto label_1e2904;
            case 0x1E2914u: goto label_1e2914;
            case 0x1E2938u: goto label_1e2938;
            case 0x1E294Cu: goto label_1e294c;
            case 0x1E29C0u: goto label_1e29c0;
            case 0x1E29DCu: goto label_1e29dc;
            case 0x1E29F0u: goto label_1e29f0;
            case 0x1E2A0Cu: goto label_1e2a0c;
            case 0x1E2A78u: goto label_1e2a78;
            case 0x1E2A8Cu: goto label_1e2a8c;
            case 0x1E2ACCu: goto label_1e2acc;
            case 0x1E2ADCu: goto label_1e2adc;
            case 0x1E2B00u: goto label_1e2b00;
            case 0x1E2B10u: goto label_1e2b10;
            case 0x1E2B34u: goto label_1e2b34;
            case 0x1E2B48u: goto label_1e2b48;
            case 0x1E2B54u: goto label_1e2b54;
            case 0x1E2B90u: goto label_1e2b90;
            case 0x1E2B98u: goto label_1e2b98;
            case 0x1E2BC0u: goto label_1e2bc0;
            case 0x1E2BE4u: goto label_1e2be4;
            case 0x1E2BF8u: goto label_1e2bf8;
            case 0x1E2C14u: goto label_1e2c14;
            case 0x1E2C84u: goto label_1e2c84;
            case 0x1E2C98u: goto label_1e2c98;
            case 0x1E2CD8u: goto label_1e2cd8;
            case 0x1E2CE8u: goto label_1e2ce8;
            case 0x1E2D0Cu: goto label_1e2d0c;
            case 0x1E2D1Cu: goto label_1e2d1c;
            case 0x1E2D40u: goto label_1e2d40;
            case 0x1E2D54u: goto label_1e2d54;
            case 0x1E2E10u: goto label_1e2e10;
            case 0x1E2E18u: goto label_1e2e18;
            case 0x1E2E20u: goto label_1e2e20;
            case 0x1E2E48u: goto label_1e2e48;
            case 0x1E2E64u: goto label_1e2e64;
            case 0x1E2E78u: goto label_1e2e78;
            case 0x1E2E94u: goto label_1e2e94;
            case 0x1E2EF8u: goto label_1e2ef8;
            case 0x1E2F0Cu: goto label_1e2f0c;
            case 0x1E2F4Cu: goto label_1e2f4c;
            case 0x1E2F5Cu: goto label_1e2f5c;
            case 0x1E2F80u: goto label_1e2f80;
            case 0x1E2FA8u: goto label_1e2fa8;
            case 0x1E2FC4u: goto label_1e2fc4;
            case 0x1E2FD8u: goto label_1e2fd8;
            case 0x1E2FF4u: goto label_1e2ff4;
            case 0x1E3058u: goto label_1e3058;
            case 0x1E306Cu: goto label_1e306c;
            case 0x1E30ACu: goto label_1e30ac;
            case 0x1E30BCu: goto label_1e30bc;
            case 0x1E30E0u: goto label_1e30e0;
            case 0x1E3108u: goto label_1e3108;
            case 0x1E3124u: goto label_1e3124;
            case 0x1E3138u: goto label_1e3138;
            case 0x1E3154u: goto label_1e3154;
            case 0x1E31CCu: goto label_1e31cc;
            case 0x1E31E0u: goto label_1e31e0;
            case 0x1E3220u: goto label_1e3220;
            case 0x1E3238u: goto label_1e3238;
            case 0x1E325Cu: goto label_1e325c;
            case 0x1E3278u: goto label_1e3278;
            case 0x1E329Cu: goto label_1e329c;
            case 0x1E32B0u: goto label_1e32b0;
            case 0x1E3318u: goto label_1e3318;
            case 0x1E3388u: goto label_1e3388;
            case 0x1E33C4u: goto label_1e33c4;
            case 0x1E33E0u: goto label_1e33e0;
            case 0x1E33F4u: goto label_1e33f4;
            case 0x1E3410u: goto label_1e3410;
            case 0x1E347Cu: goto label_1e347c;
            case 0x1E3490u: goto label_1e3490;
            case 0x1E34D0u: goto label_1e34d0;
            case 0x1E34E0u: goto label_1e34e0;
            case 0x1E3504u: goto label_1e3504;
            case 0x1E3514u: goto label_1e3514;
            case 0x1E3538u: goto label_1e3538;
            case 0x1E354Cu: goto label_1e354c;
            case 0x1E360Cu: goto label_1e360c;
            case 0x1E3628u: goto label_1e3628;
            case 0x1E363Cu: goto label_1e363c;
            case 0x1E3658u: goto label_1e3658;
            case 0x1E36C4u: goto label_1e36c4;
            case 0x1E36D8u: goto label_1e36d8;
            case 0x1E3718u: goto label_1e3718;
            case 0x1E3728u: goto label_1e3728;
            case 0x1E374Cu: goto label_1e374c;
            case 0x1E375Cu: goto label_1e375c;
            case 0x1E3780u: goto label_1e3780;
            case 0x1E3794u: goto label_1e3794;
            case 0x1E3854u: goto label_1e3854;
            case 0x1E3870u: goto label_1e3870;
            case 0x1E3884u: goto label_1e3884;
            case 0x1E38A0u: goto label_1e38a0;
            case 0x1E3908u: goto label_1e3908;
            case 0x1E391Cu: goto label_1e391c;
            case 0x1E395Cu: goto label_1e395c;
            case 0x1E396Cu: goto label_1e396c;
            case 0x1E3990u: goto label_1e3990;
            case 0x1E39A0u: goto label_1e39a0;
            case 0x1E39C4u: goto label_1e39c4;
            case 0x1E39D8u: goto label_1e39d8;
            case 0x1E3A44u: goto label_1e3a44;
            case 0x1E3A60u: goto label_1e3a60;
            case 0x1E3A74u: goto label_1e3a74;
            case 0x1E3A78u: goto label_1e3a78;
            case 0x1E3ADCu: goto label_1e3adc;
            case 0x1E3AF0u: goto label_1e3af0;
            case 0x1E3B30u: goto label_1e3b30;
            case 0x1E3B40u: goto label_1e3b40;
            case 0x1E3B64u: goto label_1e3b64;
            case 0x1E3B84u: goto label_1e3b84;
            case 0x1E3BA0u: goto label_1e3ba0;
            case 0x1E3BB4u: goto label_1e3bb4;
            case 0x1E3BB8u: goto label_1e3bb8;
            case 0x1E3C1Cu: goto label_1e3c1c;
            case 0x1E3C30u: goto label_1e3c30;
            case 0x1E3C70u: goto label_1e3c70;
            case 0x1E3C80u: goto label_1e3c80;
            case 0x1E3CA4u: goto label_1e3ca4;
            case 0x1E3CC4u: goto label_1e3cc4;
            case 0x1E3CE8u: goto label_1e3ce8;
            case 0x1E3CFCu: goto label_1e3cfc;
            case 0x1E3D00u: goto label_1e3d00;
            case 0x1E3D68u: goto label_1e3d68;
            case 0x1E3D7Cu: goto label_1e3d7c;
            case 0x1E3DBCu: goto label_1e3dbc;
            case 0x1E3DCCu: goto label_1e3dcc;
            case 0x1E3DF0u: goto label_1e3df0;
            case 0x1E3E00u: goto label_1e3e00;
            case 0x1E3E24u: goto label_1e3e24;
            case 0x1E3E38u: goto label_1e3e38;
            case 0x1E3EA4u: goto label_1e3ea4;
            case 0x1E3EC0u: goto label_1e3ec0;
            case 0x1E3ED4u: goto label_1e3ed4;
            case 0x1E3ED8u: goto label_1e3ed8;
            case 0x1E3F40u: goto label_1e3f40;
            case 0x1E3F54u: goto label_1e3f54;
            case 0x1E3F94u: goto label_1e3f94;
            case 0x1E3FA4u: goto label_1e3fa4;
            case 0x1E3FC8u: goto label_1e3fc8;
            case 0x1E3FD8u: goto label_1e3fd8;
            case 0x1E3FFCu: goto label_1e3ffc;
            case 0x1E4010u: goto label_1e4010;
            case 0x1E407Cu: goto label_1e407c;
            case 0x1E4098u: goto label_1e4098;
            case 0x1E40ACu: goto label_1e40ac;
            case 0x1E40B0u: goto label_1e40b0;
            case 0x1E4118u: goto label_1e4118;
            case 0x1E412Cu: goto label_1e412c;
            case 0x1E416Cu: goto label_1e416c;
            case 0x1E417Cu: goto label_1e417c;
            case 0x1E41A0u: goto label_1e41a0;
            case 0x1E41B0u: goto label_1e41b0;
            case 0x1E41D4u: goto label_1e41d4;
            case 0x1E41E8u: goto label_1e41e8;
            case 0x1E4254u: goto label_1e4254;
            case 0x1E4270u: goto label_1e4270;
            case 0x1E4284u: goto label_1e4284;
            case 0x1E4288u: goto label_1e4288;
            case 0x1E42F0u: goto label_1e42f0;
            case 0x1E4304u: goto label_1e4304;
            case 0x1E4344u: goto label_1e4344;
            case 0x1E4358u: goto label_1e4358;
            case 0x1E437Cu: goto label_1e437c;
            case 0x1E4394u: goto label_1e4394;
            case 0x1E43B8u: goto label_1e43b8;
            case 0x1E43CCu: goto label_1e43cc;
            case 0x1E43E4u: goto label_1e43e4;
            case 0x1E4414u: goto label_1e4414;
            case 0x1E4430u: goto label_1e4430;
            case 0x1E4444u: goto label_1e4444;
            case 0x1E4460u: goto label_1e4460;
            case 0x1E44C8u: goto label_1e44c8;
            case 0x1E44DCu: goto label_1e44dc;
            case 0x1E451Cu: goto label_1e451c;
            case 0x1E452Cu: goto label_1e452c;
            case 0x1E4550u: goto label_1e4550;
            case 0x1E4560u: goto label_1e4560;
            case 0x1E4584u: goto label_1e4584;
            case 0x1E4598u: goto label_1e4598;
            case 0x1E460Cu: goto label_1e460c;
            case 0x1E4628u: goto label_1e4628;
            case 0x1E463Cu: goto label_1e463c;
            case 0x1E4658u: goto label_1e4658;
            case 0x1E46C8u: goto label_1e46c8;
            case 0x1E46DCu: goto label_1e46dc;
            case 0x1E471Cu: goto label_1e471c;
            case 0x1E472Cu: goto label_1e472c;
            case 0x1E4750u: goto label_1e4750;
            case 0x1E4764u: goto label_1e4764;
            case 0x1E4788u: goto label_1e4788;
            case 0x1E479Cu: goto label_1e479c;
            case 0x1E47B0u: goto label_1e47b0;
            case 0x1E47E0u: goto label_1e47e0;
            case 0x1E47FCu: goto label_1e47fc;
            case 0x1E4800u: goto label_1e4800;
            case 0x1E48A0u: goto label_1e48a0;
            case 0x1E48B4u: goto label_1e48b4;
            case 0x1E48F4u: goto label_1e48f4;
            case 0x1E4918u: goto label_1e4918;
            case 0x1E493Cu: goto label_1e493c;
            case 0x1E4974u: goto label_1e4974;
            case 0x1E4998u: goto label_1e4998;
            case 0x1E49ACu: goto label_1e49ac;
            case 0x1E4A08u: goto label_1e4a08;
            case 0x1E4A24u: goto label_1e4a24;
            case 0x1E4AACu: goto label_1e4aac;
            case 0x1E4AC0u: goto label_1e4ac0;
            case 0x1E4B00u: goto label_1e4b00;
            case 0x1E4B1Cu: goto label_1e4b1c;
            case 0x1E4B20u: goto label_1e4b20;
            case 0x1E4B94u: goto label_1e4b94;
            case 0x1E4BA8u: goto label_1e4ba8;
            case 0x1E4BE8u: goto label_1e4be8;
            case 0x1E4C10u: goto label_1e4c10;
            case 0x1E4C34u: goto label_1e4c34;
            case 0x1E4C64u: goto label_1e4c64;
            case 0x1E4C88u: goto label_1e4c88;
            case 0x1E4C9Cu: goto label_1e4c9c;
            case 0x1E4D08u: goto label_1e4d08;
            case 0x1E4D28u: goto label_1e4d28;
            case 0x1E4DE4u: goto label_1e4de4;
            case 0x1E4DF8u: goto label_1e4df8;
            case 0x1E4E3Cu: goto label_1e4e3c;
            case 0x1E4E58u: goto label_1e4e58;
            case 0x1E4E5Cu: goto label_1e4e5c;
            case 0x1E4EC4u: goto label_1e4ec4;
            case 0x1E4ED8u: goto label_1e4ed8;
            case 0x1E4F18u: goto label_1e4f18;
            case 0x1E4F28u: goto label_1e4f28;
            case 0x1E4F4Cu: goto label_1e4f4c;
            case 0x1E4F60u: goto label_1e4f60;
            case 0x1E4F84u: goto label_1e4f84;
            case 0x1E4F98u: goto label_1e4f98;
            case 0x1E4FACu: goto label_1e4fac;
            case 0x1E4FD0u: goto label_1e4fd0;
            case 0x1E4FECu: goto label_1e4fec;
            case 0x1E4FF0u: goto label_1e4ff0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E42A0u;
    // 0x1e42a0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1e42a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1e42a4: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1e42a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1e42a8: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1e42a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1e42ac: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e42acu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e42b0: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e42b0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e42b4: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e42b4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e42b8: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e42b8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e42bc: 0xafc00014  sw          $zero, 0x14($fp)
    ctx->pc = 0x1e42bcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 0));
    // 0x1e42c0: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e42c0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e42c4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e42c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e42c8: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E42C8u;
    {
        const bool branch_taken_0x1e42c8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e42c8) {
            ctx->pc = 0x1E42F0u;
            goto label_1e42f0;
        }
    }
    ctx->pc = 0x1E42D0u;
    // 0x1e42d0: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e42d0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e42d4: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e42d4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e42d8: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e42d8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e42dc: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e42dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e42e0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e42e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e42e4: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e42e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e42e8: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E42E8u;
    {
        const bool branch_taken_0x1e42e8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e42e8) {
            ctx->pc = 0x1E4304u;
            goto label_1e4304;
        }
    }
    ctx->pc = 0x1E42F0u;
label_1e42f0:
    // 0x1e42f0: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e42f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e42f4: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e42f4u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e42f8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e42f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e42fc: 0x10000058  b           . + 4 + (0x58 << 2)
    ctx->pc = 0x1E42FCu;
    {
        const bool branch_taken_0x1e42fc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e42fc) {
            ctx->pc = 0x1E4460u;
            goto label_1e4460;
        }
    }
    ctx->pc = 0x1E4304u;
label_1e4304:
    // 0x1e4304: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e4304u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e4308: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e4308u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e430c: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e430cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e4310: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e4310u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e4314: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e4314u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e4318: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e4318u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e431c: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1e431cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1e4320: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e4320u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e4324: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e4324u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e4328: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E4328u;
    {
        const bool branch_taken_0x1e4328 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4328) {
            ctx->pc = 0x1E4344u;
            goto label_1e4344;
        }
    }
    ctx->pc = 0x1E4330u;
    // 0x1e4330: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e4330u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e4334: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e4334u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e4338: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e4338u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e433c: 0x10000048  b           . + 4 + (0x48 << 2)
    ctx->pc = 0x1E433Cu;
    {
        const bool branch_taken_0x1e433c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e433c) {
            ctx->pc = 0x1E4460u;
            goto label_1e4460;
        }
    }
    ctx->pc = 0x1E4344u;
label_1e4344:
    // 0x1e4344: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e4344u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e4348: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e4348u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e434c: 0x8c450064  lw          $a1, 0x64($v0)
    ctx->pc = 0x1e434cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 100)));
    // 0x1e4350: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E4350u;
    SET_GPR_U32(ctx, 31, 0x1E4358u);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4358u; }
        if (ctx->pc != 0x1E4358u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4358u; }
        if (ctx->pc != 0x1E4358u) { return; }
    }
    ctx->pc = 0x1E4358u;
label_1e4358:
    // 0x1e4358: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1e4358u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1e435c: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e435cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e4360: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E4360u;
    {
        const bool branch_taken_0x1e4360 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e4360) {
            ctx->pc = 0x1E437Cu;
            goto label_1e437c;
        }
    }
    ctx->pc = 0x1E4368u;
    // 0x1e4368: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e4368u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e436c: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e436cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e4370: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e4370u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e4374: 0x1000003a  b           . + 4 + (0x3A << 2)
    ctx->pc = 0x1E4374u;
    {
        const bool branch_taken_0x1e4374 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4374) {
            ctx->pc = 0x1E4460u;
            goto label_1e4460;
        }
    }
    ctx->pc = 0x1E437Cu;
label_1e437c:
    // 0x1e437c: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e437cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e4380: 0x94420064  lhu         $v0, 0x64($v0)
    ctx->pc = 0x1e4380u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 100)));
    // 0x1e4384: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1e4384u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e4388: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1e4388u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e438c: 0xc07cc3c  jal         func_1F30F0
    ctx->pc = 0x1E438Cu;
    SET_GPR_U32(ctx, 31, 0x1E4394u);
    ctx->pc = 0x1F30F0u;
    if (runtime->hasFunction(0x1F30F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F30F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4394u; }
        if (ctx->pc != 0x1E4394u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F30F0_0x1f30f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4394u; }
        if (ctx->pc != 0x1E4394u) { return; }
    }
    ctx->pc = 0x1E4394u;
label_1e4394:
    // 0x1e4394: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1e4394u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1e4398: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e4398u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e439c: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1E439Cu;
    {
        const bool branch_taken_0x1e439c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e439c) {
            ctx->pc = 0x1E43CCu;
            goto label_1e43cc;
        }
    }
    ctx->pc = 0x1E43A4u;
    // 0x1e43a4: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e43a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e43a8: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1e43a8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1e43ac: 0x8fc5000c  lw          $a1, 0xC($fp)
    ctx->pc = 0x1e43acu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e43b0: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1E43B0u;
    SET_GPR_U32(ctx, 31, 0x1E43B8u);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E43B8u; }
        if (ctx->pc != 0x1E43B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E43B8u; }
        if (ctx->pc != 0x1E43B8u) { return; }
    }
    ctx->pc = 0x1E43B8u;
label_1e43b8:
    // 0x1e43b8: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e43b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e43bc: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e43bcu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e43c0: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e43c0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e43c4: 0x10000026  b           . + 4 + (0x26 << 2)
    ctx->pc = 0x1E43C4u;
    {
        const bool branch_taken_0x1e43c4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e43c4) {
            ctx->pc = 0x1E4460u;
            goto label_1e4460;
        }
    }
    ctx->pc = 0x1E43CCu;
label_1e43cc:
    // 0x1e43cc: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e43ccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e43d0: 0x8fc40010  lw          $a0, 0x10($fp)
    ctx->pc = 0x1e43d0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e43d4: 0x8fc50004  lw          $a1, 0x4($fp)
    ctx->pc = 0x1e43d4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e43d8: 0x8c460064  lw          $a2, 0x64($v0)
    ctx->pc = 0x1e43d8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 100)));
    // 0x1e43dc: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1E43DCu;
    SET_GPR_U32(ctx, 31, 0x1E43E4u);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E43E4u; }
        if (ctx->pc != 0x1E43E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E43E4u; }
        if (ctx->pc != 0x1E43E4u) { return; }
    }
    ctx->pc = 0x1E43E4u;
label_1e43e4:
    // 0x1e43e4: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e43e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e43e8: 0x94430064  lhu         $v1, 0x64($v0)
    ctx->pc = 0x1e43e8u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 100)));
    // 0x1e43ec: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e43ecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e43f0: 0x9042061f  lbu         $v0, 0x61F($v0)
    ctx->pc = 0x1e43f0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 1567)));
    // 0x1e43f4: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e43f4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e43f8: 0x8fc5000c  lw          $a1, 0xC($fp)
    ctx->pc = 0x1e43f8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e43fc: 0x3406a000  ori         $a2, $zero, 0xA000
    ctx->pc = 0x1e43fcu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)40960);
    // 0x1e4400: 0x60382d  daddu       $a3, $v1, $zero
    ctx->pc = 0x1e4400u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e4404: 0x2408000c  addiu       $t0, $zero, 0xC
    ctx->pc = 0x1e4404u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
    // 0x1e4408: 0x40482d  daddu       $t1, $v0, $zero
    ctx->pc = 0x1e4408u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e440c: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E440Cu;
    SET_GPR_U32(ctx, 31, 0x1E4414u);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4414u; }
        if (ctx->pc != 0x1E4414u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4414u; }
        if (ctx->pc != 0x1E4414u) { return; }
    }
    ctx->pc = 0x1E4414u;
label_1e4414:
    // 0x1e4414: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E4414u;
    {
        const bool branch_taken_0x1e4414 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4414) {
            ctx->pc = 0x1E4430u;
            goto label_1e4430;
        }
    }
    ctx->pc = 0x1E441Cu;
    // 0x1e441c: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e441cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e4420: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e4420u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e4424: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e4424u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e4428: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1E4428u;
    {
        const bool branch_taken_0x1e4428 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4428) {
            ctx->pc = 0x1E4460u;
            goto label_1e4460;
        }
    }
    ctx->pc = 0x1E4430u;
label_1e4430:
    // 0x1e4430: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1e4430u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e4434: 0x24050026  addiu       $a1, $zero, 0x26
    ctx->pc = 0x1e4434u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 38));
    // 0x1e4438: 0x8fc60008  lw          $a2, 0x8($fp)
    ctx->pc = 0x1e4438u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e443c: 0xc076ad5  jal         func_1DAB54
    ctx->pc = 0x1E443Cu;
    SET_GPR_U32(ctx, 31, 0x1E4444u);
    ctx->pc = 0x1DAB54u;
    if (runtime->hasFunction(0x1DAB54u)) {
        auto targetFn = runtime->lookupFunction(0x1DAB54u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4444u; }
        if (ctx->pc != 0x1E4444u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DAB54_0x1dab54(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4444u; }
        if (ctx->pc != 0x1E4444u) { return; }
    }
    ctx->pc = 0x1E4444u;
label_1e4444:
    // 0x1e4444: 0x8fc30014  lw          $v1, 0x14($fp)
    ctx->pc = 0x1e4444u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e4448: 0x9064061f  lbu         $a0, 0x61F($v1)
    ctx->pc = 0x1e4448u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 1567)));
    // 0x1e444c: 0x24820001  addiu       $v0, $a0, 0x1
    ctx->pc = 0x1e444cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1e4450: 0xa062061f  sb          $v0, 0x61F($v1)
    ctx->pc = 0x1e4450u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 1567), (uint8_t)GPR_U32(ctx, 2));
    // 0x1e4454: 0x308200ff  andi        $v0, $a0, 0xFF
    ctx->pc = 0x1e4454u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x1e4458: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1e4458u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1e445c: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e445cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
label_1e4460:
    // 0x1e4460: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e4460u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e4464: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1e4464u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1e4468: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1e4468u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1e446c: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1e446cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1e4470: 0x3e00008  jr          $ra
    ctx->pc = 0x1E4470u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E1B3Cu: goto label_1e1b3c;
            case 0x1E1B60u: goto label_1e1b60;
            case 0x1E1B84u: goto label_1e1b84;
            case 0x1E1BA8u: goto label_1e1ba8;
            case 0x1E1BC8u: goto label_1e1bc8;
            case 0x1E1BE4u: goto label_1e1be4;
            case 0x1E1BE8u: goto label_1e1be8;
            case 0x1E1C44u: goto label_1e1c44;
            case 0x1E1C58u: goto label_1e1c58;
            case 0x1E1C7Cu: goto label_1e1c7c;
            case 0x1E1CD8u: goto label_1e1cd8;
            case 0x1E1CECu: goto label_1e1cec;
            case 0x1E1D14u: goto label_1e1d14;
            case 0x1E1D7Cu: goto label_1e1d7c;
            case 0x1E1D90u: goto label_1e1d90;
            case 0x1E1DD0u: goto label_1e1dd0;
            case 0x1E1DE0u: goto label_1e1de0;
            case 0x1E1E04u: goto label_1e1e04;
            case 0x1E1E14u: goto label_1e1e14;
            case 0x1E1E38u: goto label_1e1e38;
            case 0x1E1E4Cu: goto label_1e1e4c;
            case 0x1E1E5Cu: goto label_1e1e5c;
            case 0x1E1E84u: goto label_1e1e84;
            case 0x1E1EA0u: goto label_1e1ea0;
            case 0x1E1EB4u: goto label_1e1eb4;
            case 0x1E1ED0u: goto label_1e1ed0;
            case 0x1E1F48u: goto label_1e1f48;
            case 0x1E1F5Cu: goto label_1e1f5c;
            case 0x1E1F9Cu: goto label_1e1f9c;
            case 0x1E1FACu: goto label_1e1fac;
            case 0x1E1FD0u: goto label_1e1fd0;
            case 0x1E1FE0u: goto label_1e1fe0;
            case 0x1E2004u: goto label_1e2004;
            case 0x1E2018u: goto label_1e2018;
            case 0x1E202Cu: goto label_1e202c;
            case 0x1E2064u: goto label_1e2064;
            case 0x1E206Cu: goto label_1e206c;
            case 0x1E2088u: goto label_1e2088;
            case 0x1E20A0u: goto label_1e20a0;
            case 0x1E20D4u: goto label_1e20d4;
            case 0x1E20F8u: goto label_1e20f8;
            case 0x1E210Cu: goto label_1e210c;
            case 0x1E2128u: goto label_1e2128;
            case 0x1E2190u: goto label_1e2190;
            case 0x1E21A4u: goto label_1e21a4;
            case 0x1E21E4u: goto label_1e21e4;
            case 0x1E21F4u: goto label_1e21f4;
            case 0x1E2218u: goto label_1e2218;
            case 0x1E2228u: goto label_1e2228;
            case 0x1E224Cu: goto label_1e224c;
            case 0x1E2260u: goto label_1e2260;
            case 0x1E22D4u: goto label_1e22d4;
            case 0x1E22F0u: goto label_1e22f0;
            case 0x1E2304u: goto label_1e2304;
            case 0x1E2320u: goto label_1e2320;
            case 0x1E23A0u: goto label_1e23a0;
            case 0x1E23B4u: goto label_1e23b4;
            case 0x1E23F4u: goto label_1e23f4;
            case 0x1E2404u: goto label_1e2404;
            case 0x1E2428u: goto label_1e2428;
            case 0x1E2438u: goto label_1e2438;
            case 0x1E245Cu: goto label_1e245c;
            case 0x1E2470u: goto label_1e2470;
            case 0x1E2480u: goto label_1e2480;
            case 0x1E24F8u: goto label_1e24f8;
            case 0x1E2500u: goto label_1e2500;
            case 0x1E2508u: goto label_1e2508;
            case 0x1E25D0u: goto label_1e25d0;
            case 0x1E25ECu: goto label_1e25ec;
            case 0x1E2600u: goto label_1e2600;
            case 0x1E261Cu: goto label_1e261c;
            case 0x1E2684u: goto label_1e2684;
            case 0x1E2698u: goto label_1e2698;
            case 0x1E26D8u: goto label_1e26d8;
            case 0x1E26E8u: goto label_1e26e8;
            case 0x1E270Cu: goto label_1e270c;
            case 0x1E271Cu: goto label_1e271c;
            case 0x1E2740u: goto label_1e2740;
            case 0x1E2754u: goto label_1e2754;
            case 0x1E27C8u: goto label_1e27c8;
            case 0x1E27E4u: goto label_1e27e4;
            case 0x1E27F8u: goto label_1e27f8;
            case 0x1E2814u: goto label_1e2814;
            case 0x1E287Cu: goto label_1e287c;
            case 0x1E2890u: goto label_1e2890;
            case 0x1E28D0u: goto label_1e28d0;
            case 0x1E28E0u: goto label_1e28e0;
            case 0x1E2904u: goto label_1e2904;
            case 0x1E2914u: goto label_1e2914;
            case 0x1E2938u: goto label_1e2938;
            case 0x1E294Cu: goto label_1e294c;
            case 0x1E29C0u: goto label_1e29c0;
            case 0x1E29DCu: goto label_1e29dc;
            case 0x1E29F0u: goto label_1e29f0;
            case 0x1E2A0Cu: goto label_1e2a0c;
            case 0x1E2A78u: goto label_1e2a78;
            case 0x1E2A8Cu: goto label_1e2a8c;
            case 0x1E2ACCu: goto label_1e2acc;
            case 0x1E2ADCu: goto label_1e2adc;
            case 0x1E2B00u: goto label_1e2b00;
            case 0x1E2B10u: goto label_1e2b10;
            case 0x1E2B34u: goto label_1e2b34;
            case 0x1E2B48u: goto label_1e2b48;
            case 0x1E2B54u: goto label_1e2b54;
            case 0x1E2B90u: goto label_1e2b90;
            case 0x1E2B98u: goto label_1e2b98;
            case 0x1E2BC0u: goto label_1e2bc0;
            case 0x1E2BE4u: goto label_1e2be4;
            case 0x1E2BF8u: goto label_1e2bf8;
            case 0x1E2C14u: goto label_1e2c14;
            case 0x1E2C84u: goto label_1e2c84;
            case 0x1E2C98u: goto label_1e2c98;
            case 0x1E2CD8u: goto label_1e2cd8;
            case 0x1E2CE8u: goto label_1e2ce8;
            case 0x1E2D0Cu: goto label_1e2d0c;
            case 0x1E2D1Cu: goto label_1e2d1c;
            case 0x1E2D40u: goto label_1e2d40;
            case 0x1E2D54u: goto label_1e2d54;
            case 0x1E2E10u: goto label_1e2e10;
            case 0x1E2E18u: goto label_1e2e18;
            case 0x1E2E20u: goto label_1e2e20;
            case 0x1E2E48u: goto label_1e2e48;
            case 0x1E2E64u: goto label_1e2e64;
            case 0x1E2E78u: goto label_1e2e78;
            case 0x1E2E94u: goto label_1e2e94;
            case 0x1E2EF8u: goto label_1e2ef8;
            case 0x1E2F0Cu: goto label_1e2f0c;
            case 0x1E2F4Cu: goto label_1e2f4c;
            case 0x1E2F5Cu: goto label_1e2f5c;
            case 0x1E2F80u: goto label_1e2f80;
            case 0x1E2FA8u: goto label_1e2fa8;
            case 0x1E2FC4u: goto label_1e2fc4;
            case 0x1E2FD8u: goto label_1e2fd8;
            case 0x1E2FF4u: goto label_1e2ff4;
            case 0x1E3058u: goto label_1e3058;
            case 0x1E306Cu: goto label_1e306c;
            case 0x1E30ACu: goto label_1e30ac;
            case 0x1E30BCu: goto label_1e30bc;
            case 0x1E30E0u: goto label_1e30e0;
            case 0x1E3108u: goto label_1e3108;
            case 0x1E3124u: goto label_1e3124;
            case 0x1E3138u: goto label_1e3138;
            case 0x1E3154u: goto label_1e3154;
            case 0x1E31CCu: goto label_1e31cc;
            case 0x1E31E0u: goto label_1e31e0;
            case 0x1E3220u: goto label_1e3220;
            case 0x1E3238u: goto label_1e3238;
            case 0x1E325Cu: goto label_1e325c;
            case 0x1E3278u: goto label_1e3278;
            case 0x1E329Cu: goto label_1e329c;
            case 0x1E32B0u: goto label_1e32b0;
            case 0x1E3318u: goto label_1e3318;
            case 0x1E3388u: goto label_1e3388;
            case 0x1E33C4u: goto label_1e33c4;
            case 0x1E33E0u: goto label_1e33e0;
            case 0x1E33F4u: goto label_1e33f4;
            case 0x1E3410u: goto label_1e3410;
            case 0x1E347Cu: goto label_1e347c;
            case 0x1E3490u: goto label_1e3490;
            case 0x1E34D0u: goto label_1e34d0;
            case 0x1E34E0u: goto label_1e34e0;
            case 0x1E3504u: goto label_1e3504;
            case 0x1E3514u: goto label_1e3514;
            case 0x1E3538u: goto label_1e3538;
            case 0x1E354Cu: goto label_1e354c;
            case 0x1E360Cu: goto label_1e360c;
            case 0x1E3628u: goto label_1e3628;
            case 0x1E363Cu: goto label_1e363c;
            case 0x1E3658u: goto label_1e3658;
            case 0x1E36C4u: goto label_1e36c4;
            case 0x1E36D8u: goto label_1e36d8;
            case 0x1E3718u: goto label_1e3718;
            case 0x1E3728u: goto label_1e3728;
            case 0x1E374Cu: goto label_1e374c;
            case 0x1E375Cu: goto label_1e375c;
            case 0x1E3780u: goto label_1e3780;
            case 0x1E3794u: goto label_1e3794;
            case 0x1E3854u: goto label_1e3854;
            case 0x1E3870u: goto label_1e3870;
            case 0x1E3884u: goto label_1e3884;
            case 0x1E38A0u: goto label_1e38a0;
            case 0x1E3908u: goto label_1e3908;
            case 0x1E391Cu: goto label_1e391c;
            case 0x1E395Cu: goto label_1e395c;
            case 0x1E396Cu: goto label_1e396c;
            case 0x1E3990u: goto label_1e3990;
            case 0x1E39A0u: goto label_1e39a0;
            case 0x1E39C4u: goto label_1e39c4;
            case 0x1E39D8u: goto label_1e39d8;
            case 0x1E3A44u: goto label_1e3a44;
            case 0x1E3A60u: goto label_1e3a60;
            case 0x1E3A74u: goto label_1e3a74;
            case 0x1E3A78u: goto label_1e3a78;
            case 0x1E3ADCu: goto label_1e3adc;
            case 0x1E3AF0u: goto label_1e3af0;
            case 0x1E3B30u: goto label_1e3b30;
            case 0x1E3B40u: goto label_1e3b40;
            case 0x1E3B64u: goto label_1e3b64;
            case 0x1E3B84u: goto label_1e3b84;
            case 0x1E3BA0u: goto label_1e3ba0;
            case 0x1E3BB4u: goto label_1e3bb4;
            case 0x1E3BB8u: goto label_1e3bb8;
            case 0x1E3C1Cu: goto label_1e3c1c;
            case 0x1E3C30u: goto label_1e3c30;
            case 0x1E3C70u: goto label_1e3c70;
            case 0x1E3C80u: goto label_1e3c80;
            case 0x1E3CA4u: goto label_1e3ca4;
            case 0x1E3CC4u: goto label_1e3cc4;
            case 0x1E3CE8u: goto label_1e3ce8;
            case 0x1E3CFCu: goto label_1e3cfc;
            case 0x1E3D00u: goto label_1e3d00;
            case 0x1E3D68u: goto label_1e3d68;
            case 0x1E3D7Cu: goto label_1e3d7c;
            case 0x1E3DBCu: goto label_1e3dbc;
            case 0x1E3DCCu: goto label_1e3dcc;
            case 0x1E3DF0u: goto label_1e3df0;
            case 0x1E3E00u: goto label_1e3e00;
            case 0x1E3E24u: goto label_1e3e24;
            case 0x1E3E38u: goto label_1e3e38;
            case 0x1E3EA4u: goto label_1e3ea4;
            case 0x1E3EC0u: goto label_1e3ec0;
            case 0x1E3ED4u: goto label_1e3ed4;
            case 0x1E3ED8u: goto label_1e3ed8;
            case 0x1E3F40u: goto label_1e3f40;
            case 0x1E3F54u: goto label_1e3f54;
            case 0x1E3F94u: goto label_1e3f94;
            case 0x1E3FA4u: goto label_1e3fa4;
            case 0x1E3FC8u: goto label_1e3fc8;
            case 0x1E3FD8u: goto label_1e3fd8;
            case 0x1E3FFCu: goto label_1e3ffc;
            case 0x1E4010u: goto label_1e4010;
            case 0x1E407Cu: goto label_1e407c;
            case 0x1E4098u: goto label_1e4098;
            case 0x1E40ACu: goto label_1e40ac;
            case 0x1E40B0u: goto label_1e40b0;
            case 0x1E4118u: goto label_1e4118;
            case 0x1E412Cu: goto label_1e412c;
            case 0x1E416Cu: goto label_1e416c;
            case 0x1E417Cu: goto label_1e417c;
            case 0x1E41A0u: goto label_1e41a0;
            case 0x1E41B0u: goto label_1e41b0;
            case 0x1E41D4u: goto label_1e41d4;
            case 0x1E41E8u: goto label_1e41e8;
            case 0x1E4254u: goto label_1e4254;
            case 0x1E4270u: goto label_1e4270;
            case 0x1E4284u: goto label_1e4284;
            case 0x1E4288u: goto label_1e4288;
            case 0x1E42F0u: goto label_1e42f0;
            case 0x1E4304u: goto label_1e4304;
            case 0x1E4344u: goto label_1e4344;
            case 0x1E4358u: goto label_1e4358;
            case 0x1E437Cu: goto label_1e437c;
            case 0x1E4394u: goto label_1e4394;
            case 0x1E43B8u: goto label_1e43b8;
            case 0x1E43CCu: goto label_1e43cc;
            case 0x1E43E4u: goto label_1e43e4;
            case 0x1E4414u: goto label_1e4414;
            case 0x1E4430u: goto label_1e4430;
            case 0x1E4444u: goto label_1e4444;
            case 0x1E4460u: goto label_1e4460;
            case 0x1E44C8u: goto label_1e44c8;
            case 0x1E44DCu: goto label_1e44dc;
            case 0x1E451Cu: goto label_1e451c;
            case 0x1E452Cu: goto label_1e452c;
            case 0x1E4550u: goto label_1e4550;
            case 0x1E4560u: goto label_1e4560;
            case 0x1E4584u: goto label_1e4584;
            case 0x1E4598u: goto label_1e4598;
            case 0x1E460Cu: goto label_1e460c;
            case 0x1E4628u: goto label_1e4628;
            case 0x1E463Cu: goto label_1e463c;
            case 0x1E4658u: goto label_1e4658;
            case 0x1E46C8u: goto label_1e46c8;
            case 0x1E46DCu: goto label_1e46dc;
            case 0x1E471Cu: goto label_1e471c;
            case 0x1E472Cu: goto label_1e472c;
            case 0x1E4750u: goto label_1e4750;
            case 0x1E4764u: goto label_1e4764;
            case 0x1E4788u: goto label_1e4788;
            case 0x1E479Cu: goto label_1e479c;
            case 0x1E47B0u: goto label_1e47b0;
            case 0x1E47E0u: goto label_1e47e0;
            case 0x1E47FCu: goto label_1e47fc;
            case 0x1E4800u: goto label_1e4800;
            case 0x1E48A0u: goto label_1e48a0;
            case 0x1E48B4u: goto label_1e48b4;
            case 0x1E48F4u: goto label_1e48f4;
            case 0x1E4918u: goto label_1e4918;
            case 0x1E493Cu: goto label_1e493c;
            case 0x1E4974u: goto label_1e4974;
            case 0x1E4998u: goto label_1e4998;
            case 0x1E49ACu: goto label_1e49ac;
            case 0x1E4A08u: goto label_1e4a08;
            case 0x1E4A24u: goto label_1e4a24;
            case 0x1E4AACu: goto label_1e4aac;
            case 0x1E4AC0u: goto label_1e4ac0;
            case 0x1E4B00u: goto label_1e4b00;
            case 0x1E4B1Cu: goto label_1e4b1c;
            case 0x1E4B20u: goto label_1e4b20;
            case 0x1E4B94u: goto label_1e4b94;
            case 0x1E4BA8u: goto label_1e4ba8;
            case 0x1E4BE8u: goto label_1e4be8;
            case 0x1E4C10u: goto label_1e4c10;
            case 0x1E4C34u: goto label_1e4c34;
            case 0x1E4C64u: goto label_1e4c64;
            case 0x1E4C88u: goto label_1e4c88;
            case 0x1E4C9Cu: goto label_1e4c9c;
            case 0x1E4D08u: goto label_1e4d08;
            case 0x1E4D28u: goto label_1e4d28;
            case 0x1E4DE4u: goto label_1e4de4;
            case 0x1E4DF8u: goto label_1e4df8;
            case 0x1E4E3Cu: goto label_1e4e3c;
            case 0x1E4E58u: goto label_1e4e58;
            case 0x1E4E5Cu: goto label_1e4e5c;
            case 0x1E4EC4u: goto label_1e4ec4;
            case 0x1E4ED8u: goto label_1e4ed8;
            case 0x1E4F18u: goto label_1e4f18;
            case 0x1E4F28u: goto label_1e4f28;
            case 0x1E4F4Cu: goto label_1e4f4c;
            case 0x1E4F60u: goto label_1e4f60;
            case 0x1E4F84u: goto label_1e4f84;
            case 0x1E4F98u: goto label_1e4f98;
            case 0x1E4FACu: goto label_1e4fac;
            case 0x1E4FD0u: goto label_1e4fd0;
            case 0x1E4FECu: goto label_1e4fec;
            case 0x1E4FF0u: goto label_1e4ff0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E4478u;
    // 0x1e4478: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1e4478u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1e447c: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1e447cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1e4480: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1e4480u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1e4484: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e4484u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e4488: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e4488u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e448c: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e448cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e4490: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e4490u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e4494: 0xafc00014  sw          $zero, 0x14($fp)
    ctx->pc = 0x1e4494u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 0));
    // 0x1e4498: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e4498u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e449c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e449cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e44a0: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E44A0u;
    {
        const bool branch_taken_0x1e44a0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e44a0) {
            ctx->pc = 0x1E44C8u;
            goto label_1e44c8;
        }
    }
    ctx->pc = 0x1E44A8u;
    // 0x1e44a8: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e44a8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e44ac: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e44acu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e44b0: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e44b0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e44b4: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e44b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e44b8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e44b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e44bc: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e44bcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e44c0: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E44C0u;
    {
        const bool branch_taken_0x1e44c0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e44c0) {
            ctx->pc = 0x1E44DCu;
            goto label_1e44dc;
        }
    }
    ctx->pc = 0x1E44C8u;
label_1e44c8:
    // 0x1e44c8: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e44c8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e44cc: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e44ccu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e44d0: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e44d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e44d4: 0x10000060  b           . + 4 + (0x60 << 2)
    ctx->pc = 0x1E44D4u;
    {
        const bool branch_taken_0x1e44d4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e44d4) {
            ctx->pc = 0x1E4658u;
            goto label_1e4658;
        }
    }
    ctx->pc = 0x1E44DCu;
label_1e44dc:
    // 0x1e44dc: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e44dcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e44e0: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e44e0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e44e4: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e44e4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e44e8: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e44e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e44ec: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e44ecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e44f0: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e44f0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e44f4: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1e44f4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1e44f8: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e44f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e44fc: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e44fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e4500: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E4500u;
    {
        const bool branch_taken_0x1e4500 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4500) {
            ctx->pc = 0x1E451Cu;
            goto label_1e451c;
        }
    }
    ctx->pc = 0x1E4508u;
    // 0x1e4508: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e4508u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e450c: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e450cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e4510: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e4510u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e4514: 0x10000050  b           . + 4 + (0x50 << 2)
    ctx->pc = 0x1E4514u;
    {
        const bool branch_taken_0x1e4514 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4514) {
            ctx->pc = 0x1E4658u;
            goto label_1e4658;
        }
    }
    ctx->pc = 0x1E451Cu;
label_1e451c:
    // 0x1e451c: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e451cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e4520: 0x24050004  addiu       $a1, $zero, 0x4
    ctx->pc = 0x1e4520u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1e4524: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E4524u;
    SET_GPR_U32(ctx, 31, 0x1E452Cu);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E452Cu; }
        if (ctx->pc != 0x1E452Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E452Cu; }
        if (ctx->pc != 0x1E452Cu) { return; }
    }
    ctx->pc = 0x1E452Cu;
label_1e452c:
    // 0x1e452c: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1e452cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1e4530: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e4530u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e4534: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E4534u;
    {
        const bool branch_taken_0x1e4534 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e4534) {
            ctx->pc = 0x1E4550u;
            goto label_1e4550;
        }
    }
    ctx->pc = 0x1E453Cu;
    // 0x1e453c: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e453cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e4540: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e4540u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e4544: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e4544u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e4548: 0x10000043  b           . + 4 + (0x43 << 2)
    ctx->pc = 0x1E4548u;
    {
        const bool branch_taken_0x1e4548 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4548) {
            ctx->pc = 0x1E4658u;
            goto label_1e4658;
        }
    }
    ctx->pc = 0x1E4550u;
label_1e4550:
    // 0x1e4550: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1e4550u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e4554: 0x24050004  addiu       $a1, $zero, 0x4
    ctx->pc = 0x1e4554u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1e4558: 0xc07cc3c  jal         func_1F30F0
    ctx->pc = 0x1E4558u;
    SET_GPR_U32(ctx, 31, 0x1E4560u);
    ctx->pc = 0x1F30F0u;
    if (runtime->hasFunction(0x1F30F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F30F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4560u; }
        if (ctx->pc != 0x1E4560u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F30F0_0x1f30f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4560u; }
        if (ctx->pc != 0x1E4560u) { return; }
    }
    ctx->pc = 0x1E4560u;
label_1e4560:
    // 0x1e4560: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1e4560u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1e4564: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e4564u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e4568: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1E4568u;
    {
        const bool branch_taken_0x1e4568 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e4568) {
            ctx->pc = 0x1E4598u;
            goto label_1e4598;
        }
    }
    ctx->pc = 0x1E4570u;
    // 0x1e4570: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e4570u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e4574: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1e4574u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1e4578: 0x8fc5000c  lw          $a1, 0xC($fp)
    ctx->pc = 0x1e4578u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e457c: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1E457Cu;
    SET_GPR_U32(ctx, 31, 0x1E4584u);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4584u; }
        if (ctx->pc != 0x1E4584u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4584u; }
        if (ctx->pc != 0x1E4584u) { return; }
    }
    ctx->pc = 0x1E4584u;
label_1e4584:
    // 0x1e4584: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e4584u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e4588: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e4588u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e458c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e458cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e4590: 0x10000031  b           . + 4 + (0x31 << 2)
    ctx->pc = 0x1E4590u;
    {
        const bool branch_taken_0x1e4590 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4590) {
            ctx->pc = 0x1E4658u;
            goto label_1e4658;
        }
    }
    ctx->pc = 0x1E4598u;
label_1e4598:
    // 0x1e4598: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e4598u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e459c: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e459cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e45a0: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1e45a0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1e45a4: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1e45a4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1e45a8: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e45a8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e45ac: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1e45acu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1e45b0: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1e45b0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1e45b4: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1e45b4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e45b8: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1e45b8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e45bc: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1e45bcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1e45c0: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e45c0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e45c4: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1e45c4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1e45c8: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1e45c8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e45cc: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1e45ccu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e45d0: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1e45d0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1e45d4: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e45d4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e45d8: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1e45d8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1e45dc: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1e45dcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e45e0: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x1e45e0u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x1e45e4: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e45e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e45e8: 0x90420620  lbu         $v0, 0x620($v0)
    ctx->pc = 0x1e45e8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 1568)));
    // 0x1e45ec: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e45ecu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e45f0: 0x8fc5000c  lw          $a1, 0xC($fp)
    ctx->pc = 0x1e45f0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e45f4: 0x3406a000  ori         $a2, $zero, 0xA000
    ctx->pc = 0x1e45f4u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)40960);
    // 0x1e45f8: 0x24070004  addiu       $a3, $zero, 0x4
    ctx->pc = 0x1e45f8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1e45fc: 0x2408000d  addiu       $t0, $zero, 0xD
    ctx->pc = 0x1e45fcu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 13));
    // 0x1e4600: 0x40482d  daddu       $t1, $v0, $zero
    ctx->pc = 0x1e4600u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e4604: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E4604u;
    SET_GPR_U32(ctx, 31, 0x1E460Cu);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E460Cu; }
        if (ctx->pc != 0x1E460Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E460Cu; }
        if (ctx->pc != 0x1E460Cu) { return; }
    }
    ctx->pc = 0x1E460Cu;
label_1e460c:
    // 0x1e460c: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E460Cu;
    {
        const bool branch_taken_0x1e460c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e460c) {
            ctx->pc = 0x1E4628u;
            goto label_1e4628;
        }
    }
    ctx->pc = 0x1E4614u;
    // 0x1e4614: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e4614u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e4618: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e4618u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e461c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e461cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e4620: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1E4620u;
    {
        const bool branch_taken_0x1e4620 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4620) {
            ctx->pc = 0x1E4658u;
            goto label_1e4658;
        }
    }
    ctx->pc = 0x1E4628u;
label_1e4628:
    // 0x1e4628: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1e4628u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e462c: 0x24050027  addiu       $a1, $zero, 0x27
    ctx->pc = 0x1e462cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 39));
    // 0x1e4630: 0x8fc60008  lw          $a2, 0x8($fp)
    ctx->pc = 0x1e4630u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e4634: 0xc076ad5  jal         func_1DAB54
    ctx->pc = 0x1E4634u;
    SET_GPR_U32(ctx, 31, 0x1E463Cu);
    ctx->pc = 0x1DAB54u;
    if (runtime->hasFunction(0x1DAB54u)) {
        auto targetFn = runtime->lookupFunction(0x1DAB54u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E463Cu; }
        if (ctx->pc != 0x1E463Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DAB54_0x1dab54(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E463Cu; }
        if (ctx->pc != 0x1E463Cu) { return; }
    }
    ctx->pc = 0x1E463Cu;
label_1e463c:
    // 0x1e463c: 0x8fc30014  lw          $v1, 0x14($fp)
    ctx->pc = 0x1e463cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e4640: 0x90640620  lbu         $a0, 0x620($v1)
    ctx->pc = 0x1e4640u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 1568)));
    // 0x1e4644: 0x24820001  addiu       $v0, $a0, 0x1
    ctx->pc = 0x1e4644u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1e4648: 0xa0620620  sb          $v0, 0x620($v1)
    ctx->pc = 0x1e4648u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 1568), (uint8_t)GPR_U32(ctx, 2));
    // 0x1e464c: 0x308200ff  andi        $v0, $a0, 0xFF
    ctx->pc = 0x1e464cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x1e4650: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1e4650u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1e4654: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e4654u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
label_1e4658:
    // 0x1e4658: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e4658u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e465c: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1e465cu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1e4660: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1e4660u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1e4664: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1e4664u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1e4668: 0x3e00008  jr          $ra
    ctx->pc = 0x1E4668u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E1B3Cu: goto label_1e1b3c;
            case 0x1E1B60u: goto label_1e1b60;
            case 0x1E1B84u: goto label_1e1b84;
            case 0x1E1BA8u: goto label_1e1ba8;
            case 0x1E1BC8u: goto label_1e1bc8;
            case 0x1E1BE4u: goto label_1e1be4;
            case 0x1E1BE8u: goto label_1e1be8;
            case 0x1E1C44u: goto label_1e1c44;
            case 0x1E1C58u: goto label_1e1c58;
            case 0x1E1C7Cu: goto label_1e1c7c;
            case 0x1E1CD8u: goto label_1e1cd8;
            case 0x1E1CECu: goto label_1e1cec;
            case 0x1E1D14u: goto label_1e1d14;
            case 0x1E1D7Cu: goto label_1e1d7c;
            case 0x1E1D90u: goto label_1e1d90;
            case 0x1E1DD0u: goto label_1e1dd0;
            case 0x1E1DE0u: goto label_1e1de0;
            case 0x1E1E04u: goto label_1e1e04;
            case 0x1E1E14u: goto label_1e1e14;
            case 0x1E1E38u: goto label_1e1e38;
            case 0x1E1E4Cu: goto label_1e1e4c;
            case 0x1E1E5Cu: goto label_1e1e5c;
            case 0x1E1E84u: goto label_1e1e84;
            case 0x1E1EA0u: goto label_1e1ea0;
            case 0x1E1EB4u: goto label_1e1eb4;
            case 0x1E1ED0u: goto label_1e1ed0;
            case 0x1E1F48u: goto label_1e1f48;
            case 0x1E1F5Cu: goto label_1e1f5c;
            case 0x1E1F9Cu: goto label_1e1f9c;
            case 0x1E1FACu: goto label_1e1fac;
            case 0x1E1FD0u: goto label_1e1fd0;
            case 0x1E1FE0u: goto label_1e1fe0;
            case 0x1E2004u: goto label_1e2004;
            case 0x1E2018u: goto label_1e2018;
            case 0x1E202Cu: goto label_1e202c;
            case 0x1E2064u: goto label_1e2064;
            case 0x1E206Cu: goto label_1e206c;
            case 0x1E2088u: goto label_1e2088;
            case 0x1E20A0u: goto label_1e20a0;
            case 0x1E20D4u: goto label_1e20d4;
            case 0x1E20F8u: goto label_1e20f8;
            case 0x1E210Cu: goto label_1e210c;
            case 0x1E2128u: goto label_1e2128;
            case 0x1E2190u: goto label_1e2190;
            case 0x1E21A4u: goto label_1e21a4;
            case 0x1E21E4u: goto label_1e21e4;
            case 0x1E21F4u: goto label_1e21f4;
            case 0x1E2218u: goto label_1e2218;
            case 0x1E2228u: goto label_1e2228;
            case 0x1E224Cu: goto label_1e224c;
            case 0x1E2260u: goto label_1e2260;
            case 0x1E22D4u: goto label_1e22d4;
            case 0x1E22F0u: goto label_1e22f0;
            case 0x1E2304u: goto label_1e2304;
            case 0x1E2320u: goto label_1e2320;
            case 0x1E23A0u: goto label_1e23a0;
            case 0x1E23B4u: goto label_1e23b4;
            case 0x1E23F4u: goto label_1e23f4;
            case 0x1E2404u: goto label_1e2404;
            case 0x1E2428u: goto label_1e2428;
            case 0x1E2438u: goto label_1e2438;
            case 0x1E245Cu: goto label_1e245c;
            case 0x1E2470u: goto label_1e2470;
            case 0x1E2480u: goto label_1e2480;
            case 0x1E24F8u: goto label_1e24f8;
            case 0x1E2500u: goto label_1e2500;
            case 0x1E2508u: goto label_1e2508;
            case 0x1E25D0u: goto label_1e25d0;
            case 0x1E25ECu: goto label_1e25ec;
            case 0x1E2600u: goto label_1e2600;
            case 0x1E261Cu: goto label_1e261c;
            case 0x1E2684u: goto label_1e2684;
            case 0x1E2698u: goto label_1e2698;
            case 0x1E26D8u: goto label_1e26d8;
            case 0x1E26E8u: goto label_1e26e8;
            case 0x1E270Cu: goto label_1e270c;
            case 0x1E271Cu: goto label_1e271c;
            case 0x1E2740u: goto label_1e2740;
            case 0x1E2754u: goto label_1e2754;
            case 0x1E27C8u: goto label_1e27c8;
            case 0x1E27E4u: goto label_1e27e4;
            case 0x1E27F8u: goto label_1e27f8;
            case 0x1E2814u: goto label_1e2814;
            case 0x1E287Cu: goto label_1e287c;
            case 0x1E2890u: goto label_1e2890;
            case 0x1E28D0u: goto label_1e28d0;
            case 0x1E28E0u: goto label_1e28e0;
            case 0x1E2904u: goto label_1e2904;
            case 0x1E2914u: goto label_1e2914;
            case 0x1E2938u: goto label_1e2938;
            case 0x1E294Cu: goto label_1e294c;
            case 0x1E29C0u: goto label_1e29c0;
            case 0x1E29DCu: goto label_1e29dc;
            case 0x1E29F0u: goto label_1e29f0;
            case 0x1E2A0Cu: goto label_1e2a0c;
            case 0x1E2A78u: goto label_1e2a78;
            case 0x1E2A8Cu: goto label_1e2a8c;
            case 0x1E2ACCu: goto label_1e2acc;
            case 0x1E2ADCu: goto label_1e2adc;
            case 0x1E2B00u: goto label_1e2b00;
            case 0x1E2B10u: goto label_1e2b10;
            case 0x1E2B34u: goto label_1e2b34;
            case 0x1E2B48u: goto label_1e2b48;
            case 0x1E2B54u: goto label_1e2b54;
            case 0x1E2B90u: goto label_1e2b90;
            case 0x1E2B98u: goto label_1e2b98;
            case 0x1E2BC0u: goto label_1e2bc0;
            case 0x1E2BE4u: goto label_1e2be4;
            case 0x1E2BF8u: goto label_1e2bf8;
            case 0x1E2C14u: goto label_1e2c14;
            case 0x1E2C84u: goto label_1e2c84;
            case 0x1E2C98u: goto label_1e2c98;
            case 0x1E2CD8u: goto label_1e2cd8;
            case 0x1E2CE8u: goto label_1e2ce8;
            case 0x1E2D0Cu: goto label_1e2d0c;
            case 0x1E2D1Cu: goto label_1e2d1c;
            case 0x1E2D40u: goto label_1e2d40;
            case 0x1E2D54u: goto label_1e2d54;
            case 0x1E2E10u: goto label_1e2e10;
            case 0x1E2E18u: goto label_1e2e18;
            case 0x1E2E20u: goto label_1e2e20;
            case 0x1E2E48u: goto label_1e2e48;
            case 0x1E2E64u: goto label_1e2e64;
            case 0x1E2E78u: goto label_1e2e78;
            case 0x1E2E94u: goto label_1e2e94;
            case 0x1E2EF8u: goto label_1e2ef8;
            case 0x1E2F0Cu: goto label_1e2f0c;
            case 0x1E2F4Cu: goto label_1e2f4c;
            case 0x1E2F5Cu: goto label_1e2f5c;
            case 0x1E2F80u: goto label_1e2f80;
            case 0x1E2FA8u: goto label_1e2fa8;
            case 0x1E2FC4u: goto label_1e2fc4;
            case 0x1E2FD8u: goto label_1e2fd8;
            case 0x1E2FF4u: goto label_1e2ff4;
            case 0x1E3058u: goto label_1e3058;
            case 0x1E306Cu: goto label_1e306c;
            case 0x1E30ACu: goto label_1e30ac;
            case 0x1E30BCu: goto label_1e30bc;
            case 0x1E30E0u: goto label_1e30e0;
            case 0x1E3108u: goto label_1e3108;
            case 0x1E3124u: goto label_1e3124;
            case 0x1E3138u: goto label_1e3138;
            case 0x1E3154u: goto label_1e3154;
            case 0x1E31CCu: goto label_1e31cc;
            case 0x1E31E0u: goto label_1e31e0;
            case 0x1E3220u: goto label_1e3220;
            case 0x1E3238u: goto label_1e3238;
            case 0x1E325Cu: goto label_1e325c;
            case 0x1E3278u: goto label_1e3278;
            case 0x1E329Cu: goto label_1e329c;
            case 0x1E32B0u: goto label_1e32b0;
            case 0x1E3318u: goto label_1e3318;
            case 0x1E3388u: goto label_1e3388;
            case 0x1E33C4u: goto label_1e33c4;
            case 0x1E33E0u: goto label_1e33e0;
            case 0x1E33F4u: goto label_1e33f4;
            case 0x1E3410u: goto label_1e3410;
            case 0x1E347Cu: goto label_1e347c;
            case 0x1E3490u: goto label_1e3490;
            case 0x1E34D0u: goto label_1e34d0;
            case 0x1E34E0u: goto label_1e34e0;
            case 0x1E3504u: goto label_1e3504;
            case 0x1E3514u: goto label_1e3514;
            case 0x1E3538u: goto label_1e3538;
            case 0x1E354Cu: goto label_1e354c;
            case 0x1E360Cu: goto label_1e360c;
            case 0x1E3628u: goto label_1e3628;
            case 0x1E363Cu: goto label_1e363c;
            case 0x1E3658u: goto label_1e3658;
            case 0x1E36C4u: goto label_1e36c4;
            case 0x1E36D8u: goto label_1e36d8;
            case 0x1E3718u: goto label_1e3718;
            case 0x1E3728u: goto label_1e3728;
            case 0x1E374Cu: goto label_1e374c;
            case 0x1E375Cu: goto label_1e375c;
            case 0x1E3780u: goto label_1e3780;
            case 0x1E3794u: goto label_1e3794;
            case 0x1E3854u: goto label_1e3854;
            case 0x1E3870u: goto label_1e3870;
            case 0x1E3884u: goto label_1e3884;
            case 0x1E38A0u: goto label_1e38a0;
            case 0x1E3908u: goto label_1e3908;
            case 0x1E391Cu: goto label_1e391c;
            case 0x1E395Cu: goto label_1e395c;
            case 0x1E396Cu: goto label_1e396c;
            case 0x1E3990u: goto label_1e3990;
            case 0x1E39A0u: goto label_1e39a0;
            case 0x1E39C4u: goto label_1e39c4;
            case 0x1E39D8u: goto label_1e39d8;
            case 0x1E3A44u: goto label_1e3a44;
            case 0x1E3A60u: goto label_1e3a60;
            case 0x1E3A74u: goto label_1e3a74;
            case 0x1E3A78u: goto label_1e3a78;
            case 0x1E3ADCu: goto label_1e3adc;
            case 0x1E3AF0u: goto label_1e3af0;
            case 0x1E3B30u: goto label_1e3b30;
            case 0x1E3B40u: goto label_1e3b40;
            case 0x1E3B64u: goto label_1e3b64;
            case 0x1E3B84u: goto label_1e3b84;
            case 0x1E3BA0u: goto label_1e3ba0;
            case 0x1E3BB4u: goto label_1e3bb4;
            case 0x1E3BB8u: goto label_1e3bb8;
            case 0x1E3C1Cu: goto label_1e3c1c;
            case 0x1E3C30u: goto label_1e3c30;
            case 0x1E3C70u: goto label_1e3c70;
            case 0x1E3C80u: goto label_1e3c80;
            case 0x1E3CA4u: goto label_1e3ca4;
            case 0x1E3CC4u: goto label_1e3cc4;
            case 0x1E3CE8u: goto label_1e3ce8;
            case 0x1E3CFCu: goto label_1e3cfc;
            case 0x1E3D00u: goto label_1e3d00;
            case 0x1E3D68u: goto label_1e3d68;
            case 0x1E3D7Cu: goto label_1e3d7c;
            case 0x1E3DBCu: goto label_1e3dbc;
            case 0x1E3DCCu: goto label_1e3dcc;
            case 0x1E3DF0u: goto label_1e3df0;
            case 0x1E3E00u: goto label_1e3e00;
            case 0x1E3E24u: goto label_1e3e24;
            case 0x1E3E38u: goto label_1e3e38;
            case 0x1E3EA4u: goto label_1e3ea4;
            case 0x1E3EC0u: goto label_1e3ec0;
            case 0x1E3ED4u: goto label_1e3ed4;
            case 0x1E3ED8u: goto label_1e3ed8;
            case 0x1E3F40u: goto label_1e3f40;
            case 0x1E3F54u: goto label_1e3f54;
            case 0x1E3F94u: goto label_1e3f94;
            case 0x1E3FA4u: goto label_1e3fa4;
            case 0x1E3FC8u: goto label_1e3fc8;
            case 0x1E3FD8u: goto label_1e3fd8;
            case 0x1E3FFCu: goto label_1e3ffc;
            case 0x1E4010u: goto label_1e4010;
            case 0x1E407Cu: goto label_1e407c;
            case 0x1E4098u: goto label_1e4098;
            case 0x1E40ACu: goto label_1e40ac;
            case 0x1E40B0u: goto label_1e40b0;
            case 0x1E4118u: goto label_1e4118;
            case 0x1E412Cu: goto label_1e412c;
            case 0x1E416Cu: goto label_1e416c;
            case 0x1E417Cu: goto label_1e417c;
            case 0x1E41A0u: goto label_1e41a0;
            case 0x1E41B0u: goto label_1e41b0;
            case 0x1E41D4u: goto label_1e41d4;
            case 0x1E41E8u: goto label_1e41e8;
            case 0x1E4254u: goto label_1e4254;
            case 0x1E4270u: goto label_1e4270;
            case 0x1E4284u: goto label_1e4284;
            case 0x1E4288u: goto label_1e4288;
            case 0x1E42F0u: goto label_1e42f0;
            case 0x1E4304u: goto label_1e4304;
            case 0x1E4344u: goto label_1e4344;
            case 0x1E4358u: goto label_1e4358;
            case 0x1E437Cu: goto label_1e437c;
            case 0x1E4394u: goto label_1e4394;
            case 0x1E43B8u: goto label_1e43b8;
            case 0x1E43CCu: goto label_1e43cc;
            case 0x1E43E4u: goto label_1e43e4;
            case 0x1E4414u: goto label_1e4414;
            case 0x1E4430u: goto label_1e4430;
            case 0x1E4444u: goto label_1e4444;
            case 0x1E4460u: goto label_1e4460;
            case 0x1E44C8u: goto label_1e44c8;
            case 0x1E44DCu: goto label_1e44dc;
            case 0x1E451Cu: goto label_1e451c;
            case 0x1E452Cu: goto label_1e452c;
            case 0x1E4550u: goto label_1e4550;
            case 0x1E4560u: goto label_1e4560;
            case 0x1E4584u: goto label_1e4584;
            case 0x1E4598u: goto label_1e4598;
            case 0x1E460Cu: goto label_1e460c;
            case 0x1E4628u: goto label_1e4628;
            case 0x1E463Cu: goto label_1e463c;
            case 0x1E4658u: goto label_1e4658;
            case 0x1E46C8u: goto label_1e46c8;
            case 0x1E46DCu: goto label_1e46dc;
            case 0x1E471Cu: goto label_1e471c;
            case 0x1E472Cu: goto label_1e472c;
            case 0x1E4750u: goto label_1e4750;
            case 0x1E4764u: goto label_1e4764;
            case 0x1E4788u: goto label_1e4788;
            case 0x1E479Cu: goto label_1e479c;
            case 0x1E47B0u: goto label_1e47b0;
            case 0x1E47E0u: goto label_1e47e0;
            case 0x1E47FCu: goto label_1e47fc;
            case 0x1E4800u: goto label_1e4800;
            case 0x1E48A0u: goto label_1e48a0;
            case 0x1E48B4u: goto label_1e48b4;
            case 0x1E48F4u: goto label_1e48f4;
            case 0x1E4918u: goto label_1e4918;
            case 0x1E493Cu: goto label_1e493c;
            case 0x1E4974u: goto label_1e4974;
            case 0x1E4998u: goto label_1e4998;
            case 0x1E49ACu: goto label_1e49ac;
            case 0x1E4A08u: goto label_1e4a08;
            case 0x1E4A24u: goto label_1e4a24;
            case 0x1E4AACu: goto label_1e4aac;
            case 0x1E4AC0u: goto label_1e4ac0;
            case 0x1E4B00u: goto label_1e4b00;
            case 0x1E4B1Cu: goto label_1e4b1c;
            case 0x1E4B20u: goto label_1e4b20;
            case 0x1E4B94u: goto label_1e4b94;
            case 0x1E4BA8u: goto label_1e4ba8;
            case 0x1E4BE8u: goto label_1e4be8;
            case 0x1E4C10u: goto label_1e4c10;
            case 0x1E4C34u: goto label_1e4c34;
            case 0x1E4C64u: goto label_1e4c64;
            case 0x1E4C88u: goto label_1e4c88;
            case 0x1E4C9Cu: goto label_1e4c9c;
            case 0x1E4D08u: goto label_1e4d08;
            case 0x1E4D28u: goto label_1e4d28;
            case 0x1E4DE4u: goto label_1e4de4;
            case 0x1E4DF8u: goto label_1e4df8;
            case 0x1E4E3Cu: goto label_1e4e3c;
            case 0x1E4E58u: goto label_1e4e58;
            case 0x1E4E5Cu: goto label_1e4e5c;
            case 0x1E4EC4u: goto label_1e4ec4;
            case 0x1E4ED8u: goto label_1e4ed8;
            case 0x1E4F18u: goto label_1e4f18;
            case 0x1E4F28u: goto label_1e4f28;
            case 0x1E4F4Cu: goto label_1e4f4c;
            case 0x1E4F60u: goto label_1e4f60;
            case 0x1E4F84u: goto label_1e4f84;
            case 0x1E4F98u: goto label_1e4f98;
            case 0x1E4FACu: goto label_1e4fac;
            case 0x1E4FD0u: goto label_1e4fd0;
            case 0x1E4FECu: goto label_1e4fec;
            case 0x1E4FF0u: goto label_1e4ff0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E4670u;
    // 0x1e4670: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1e4670u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1e4674: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1e4674u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1e4678: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1e4678u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1e467c: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e467cu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e4680: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e4680u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e4684: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e4684u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e4688: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e4688u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e468c: 0xe0102d  daddu       $v0, $a3, $zero
    ctx->pc = 0x1e468cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e4690: 0xa7c2000c  sh          $v0, 0xC($fp)
    ctx->pc = 0x1e4690u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 12), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e4694: 0xafc00018  sw          $zero, 0x18($fp)
    ctx->pc = 0x1e4694u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 0));
    // 0x1e4698: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e4698u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e469c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e469cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e46a0: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E46A0u;
    {
        const bool branch_taken_0x1e46a0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e46a0) {
            ctx->pc = 0x1E46C8u;
            goto label_1e46c8;
        }
    }
    ctx->pc = 0x1E46A8u;
    // 0x1e46a8: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e46a8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e46ac: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e46acu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e46b0: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e46b0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e46b4: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e46b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e46b8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e46b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e46bc: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e46bcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e46c0: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E46C0u;
    {
        const bool branch_taken_0x1e46c0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e46c0) {
            ctx->pc = 0x1E46DCu;
            goto label_1e46dc;
        }
    }
    ctx->pc = 0x1E46C8u;
label_1e46c8:
    // 0x1e46c8: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e46c8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e46cc: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e46ccu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e46d0: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e46d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e46d4: 0x1000004a  b           . + 4 + (0x4A << 2)
    ctx->pc = 0x1E46D4u;
    {
        const bool branch_taken_0x1e46d4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e46d4) {
            ctx->pc = 0x1E4800u;
            goto label_1e4800;
        }
    }
    ctx->pc = 0x1E46DCu;
label_1e46dc:
    // 0x1e46dc: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e46dcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e46e0: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e46e0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e46e4: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e46e4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e46e8: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e46e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e46ec: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e46ecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e46f0: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e46f0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e46f4: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1e46f4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1e46f8: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e46f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e46fc: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e46fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e4700: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E4700u;
    {
        const bool branch_taken_0x1e4700 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4700) {
            ctx->pc = 0x1E471Cu;
            goto label_1e471c;
        }
    }
    ctx->pc = 0x1E4708u;
    // 0x1e4708: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e4708u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e470c: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e470cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e4710: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e4710u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e4714: 0x1000003a  b           . + 4 + (0x3A << 2)
    ctx->pc = 0x1E4714u;
    {
        const bool branch_taken_0x1e4714 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4714) {
            ctx->pc = 0x1E4800u;
            goto label_1e4800;
        }
    }
    ctx->pc = 0x1E471Cu;
label_1e471c:
    // 0x1e471c: 0x8fc40018  lw          $a0, 0x18($fp)
    ctx->pc = 0x1e471cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e4720: 0x8fc50008  lw          $a1, 0x8($fp)
    ctx->pc = 0x1e4720u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e4724: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E4724u;
    SET_GPR_U32(ctx, 31, 0x1E472Cu);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E472Cu; }
        if (ctx->pc != 0x1E472Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E472Cu; }
        if (ctx->pc != 0x1E472Cu) { return; }
    }
    ctx->pc = 0x1E472Cu;
label_1e472c:
    // 0x1e472c: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1e472cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1e4730: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e4730u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e4734: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E4734u;
    {
        const bool branch_taken_0x1e4734 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e4734) {
            ctx->pc = 0x1E4750u;
            goto label_1e4750;
        }
    }
    ctx->pc = 0x1E473Cu;
    // 0x1e473c: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e473cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e4740: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e4740u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e4744: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e4744u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e4748: 0x1000002d  b           . + 4 + (0x2D << 2)
    ctx->pc = 0x1E4748u;
    {
        const bool branch_taken_0x1e4748 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4748) {
            ctx->pc = 0x1E4800u;
            goto label_1e4800;
        }
    }
    ctx->pc = 0x1E4750u;
label_1e4750:
    // 0x1e4750: 0x97c20008  lhu         $v0, 0x8($fp)
    ctx->pc = 0x1e4750u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e4754: 0x8fc40010  lw          $a0, 0x10($fp)
    ctx->pc = 0x1e4754u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e4758: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1e4758u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e475c: 0xc07cc3c  jal         func_1F30F0
    ctx->pc = 0x1E475Cu;
    SET_GPR_U32(ctx, 31, 0x1E4764u);
    ctx->pc = 0x1F30F0u;
    if (runtime->hasFunction(0x1F30F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F30F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4764u; }
        if (ctx->pc != 0x1E4764u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F30F0_0x1f30f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4764u; }
        if (ctx->pc != 0x1E4764u) { return; }
    }
    ctx->pc = 0x1E4764u;
label_1e4764:
    // 0x1e4764: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1e4764u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1e4768: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e4768u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e476c: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1E476Cu;
    {
        const bool branch_taken_0x1e476c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e476c) {
            ctx->pc = 0x1E479Cu;
            goto label_1e479c;
        }
    }
    ctx->pc = 0x1E4774u;
    // 0x1e4774: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e4774u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e4778: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1e4778u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1e477c: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e477cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e4780: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1E4780u;
    SET_GPR_U32(ctx, 31, 0x1E4788u);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4788u; }
        if (ctx->pc != 0x1E4788u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4788u; }
        if (ctx->pc != 0x1E4788u) { return; }
    }
    ctx->pc = 0x1E4788u;
label_1e4788:
    // 0x1e4788: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e4788u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e478c: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e478cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e4790: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e4790u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e4794: 0x1000001a  b           . + 4 + (0x1A << 2)
    ctx->pc = 0x1E4794u;
    {
        const bool branch_taken_0x1e4794 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4794) {
            ctx->pc = 0x1E4800u;
            goto label_1e4800;
        }
    }
    ctx->pc = 0x1E479Cu;
label_1e479c:
    // 0x1e479c: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e479cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e47a0: 0x8fc50004  lw          $a1, 0x4($fp)
    ctx->pc = 0x1e47a0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e47a4: 0x8fc60008  lw          $a2, 0x8($fp)
    ctx->pc = 0x1e47a4u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e47a8: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1E47A8u;
    SET_GPR_U32(ctx, 31, 0x1E47B0u);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E47B0u; }
        if (ctx->pc != 0x1E47B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E47B0u; }
        if (ctx->pc != 0x1E47B0u) { return; }
    }
    ctx->pc = 0x1E47B0u;
label_1e47b0:
    // 0x1e47b0: 0x97c2000c  lhu         $v0, 0xC($fp)
    ctx->pc = 0x1e47b0u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e47b4: 0x3442a400  ori         $v0, $v0, 0xA400
    ctx->pc = 0x1e47b4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)41984);
    // 0x1e47b8: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1e47b8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1e47bc: 0x97c30008  lhu         $v1, 0x8($fp)
    ctx->pc = 0x1e47bcu;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e47c0: 0x8fc40018  lw          $a0, 0x18($fp)
    ctx->pc = 0x1e47c0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e47c4: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e47c4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e47c8: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x1e47c8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e47cc: 0x60382d  daddu       $a3, $v1, $zero
    ctx->pc = 0x1e47ccu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e47d0: 0x2408000f  addiu       $t0, $zero, 0xF
    ctx->pc = 0x1e47d0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
    // 0x1e47d4: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1e47d4u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e47d8: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E47D8u;
    SET_GPR_U32(ctx, 31, 0x1E47E0u);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E47E0u; }
        if (ctx->pc != 0x1E47E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E47E0u; }
        if (ctx->pc != 0x1E47E0u) { return; }
    }
    ctx->pc = 0x1E47E0u;
label_1e47e0:
    // 0x1e47e0: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E47E0u;
    {
        const bool branch_taken_0x1e47e0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e47e0) {
            ctx->pc = 0x1E47FCu;
            goto label_1e47fc;
        }
    }
    ctx->pc = 0x1E47E8u;
    // 0x1e47e8: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e47e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e47ec: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e47ecu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e47f0: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e47f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e47f4: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1E47F4u;
    {
        const bool branch_taken_0x1e47f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e47f4) {
            ctx->pc = 0x1E4800u;
            goto label_1e4800;
        }
    }
    ctx->pc = 0x1E47FCu;
label_1e47fc:
    // 0x1e47fc: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1e47fcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1e4800:
    // 0x1e4800: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e4800u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e4804: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1e4804u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1e4808: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1e4808u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1e480c: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1e480cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1e4810: 0x3e00008  jr          $ra
    ctx->pc = 0x1E4810u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E1B3Cu: goto label_1e1b3c;
            case 0x1E1B60u: goto label_1e1b60;
            case 0x1E1B84u: goto label_1e1b84;
            case 0x1E1BA8u: goto label_1e1ba8;
            case 0x1E1BC8u: goto label_1e1bc8;
            case 0x1E1BE4u: goto label_1e1be4;
            case 0x1E1BE8u: goto label_1e1be8;
            case 0x1E1C44u: goto label_1e1c44;
            case 0x1E1C58u: goto label_1e1c58;
            case 0x1E1C7Cu: goto label_1e1c7c;
            case 0x1E1CD8u: goto label_1e1cd8;
            case 0x1E1CECu: goto label_1e1cec;
            case 0x1E1D14u: goto label_1e1d14;
            case 0x1E1D7Cu: goto label_1e1d7c;
            case 0x1E1D90u: goto label_1e1d90;
            case 0x1E1DD0u: goto label_1e1dd0;
            case 0x1E1DE0u: goto label_1e1de0;
            case 0x1E1E04u: goto label_1e1e04;
            case 0x1E1E14u: goto label_1e1e14;
            case 0x1E1E38u: goto label_1e1e38;
            case 0x1E1E4Cu: goto label_1e1e4c;
            case 0x1E1E5Cu: goto label_1e1e5c;
            case 0x1E1E84u: goto label_1e1e84;
            case 0x1E1EA0u: goto label_1e1ea0;
            case 0x1E1EB4u: goto label_1e1eb4;
            case 0x1E1ED0u: goto label_1e1ed0;
            case 0x1E1F48u: goto label_1e1f48;
            case 0x1E1F5Cu: goto label_1e1f5c;
            case 0x1E1F9Cu: goto label_1e1f9c;
            case 0x1E1FACu: goto label_1e1fac;
            case 0x1E1FD0u: goto label_1e1fd0;
            case 0x1E1FE0u: goto label_1e1fe0;
            case 0x1E2004u: goto label_1e2004;
            case 0x1E2018u: goto label_1e2018;
            case 0x1E202Cu: goto label_1e202c;
            case 0x1E2064u: goto label_1e2064;
            case 0x1E206Cu: goto label_1e206c;
            case 0x1E2088u: goto label_1e2088;
            case 0x1E20A0u: goto label_1e20a0;
            case 0x1E20D4u: goto label_1e20d4;
            case 0x1E20F8u: goto label_1e20f8;
            case 0x1E210Cu: goto label_1e210c;
            case 0x1E2128u: goto label_1e2128;
            case 0x1E2190u: goto label_1e2190;
            case 0x1E21A4u: goto label_1e21a4;
            case 0x1E21E4u: goto label_1e21e4;
            case 0x1E21F4u: goto label_1e21f4;
            case 0x1E2218u: goto label_1e2218;
            case 0x1E2228u: goto label_1e2228;
            case 0x1E224Cu: goto label_1e224c;
            case 0x1E2260u: goto label_1e2260;
            case 0x1E22D4u: goto label_1e22d4;
            case 0x1E22F0u: goto label_1e22f0;
            case 0x1E2304u: goto label_1e2304;
            case 0x1E2320u: goto label_1e2320;
            case 0x1E23A0u: goto label_1e23a0;
            case 0x1E23B4u: goto label_1e23b4;
            case 0x1E23F4u: goto label_1e23f4;
            case 0x1E2404u: goto label_1e2404;
            case 0x1E2428u: goto label_1e2428;
            case 0x1E2438u: goto label_1e2438;
            case 0x1E245Cu: goto label_1e245c;
            case 0x1E2470u: goto label_1e2470;
            case 0x1E2480u: goto label_1e2480;
            case 0x1E24F8u: goto label_1e24f8;
            case 0x1E2500u: goto label_1e2500;
            case 0x1E2508u: goto label_1e2508;
            case 0x1E25D0u: goto label_1e25d0;
            case 0x1E25ECu: goto label_1e25ec;
            case 0x1E2600u: goto label_1e2600;
            case 0x1E261Cu: goto label_1e261c;
            case 0x1E2684u: goto label_1e2684;
            case 0x1E2698u: goto label_1e2698;
            case 0x1E26D8u: goto label_1e26d8;
            case 0x1E26E8u: goto label_1e26e8;
            case 0x1E270Cu: goto label_1e270c;
            case 0x1E271Cu: goto label_1e271c;
            case 0x1E2740u: goto label_1e2740;
            case 0x1E2754u: goto label_1e2754;
            case 0x1E27C8u: goto label_1e27c8;
            case 0x1E27E4u: goto label_1e27e4;
            case 0x1E27F8u: goto label_1e27f8;
            case 0x1E2814u: goto label_1e2814;
            case 0x1E287Cu: goto label_1e287c;
            case 0x1E2890u: goto label_1e2890;
            case 0x1E28D0u: goto label_1e28d0;
            case 0x1E28E0u: goto label_1e28e0;
            case 0x1E2904u: goto label_1e2904;
            case 0x1E2914u: goto label_1e2914;
            case 0x1E2938u: goto label_1e2938;
            case 0x1E294Cu: goto label_1e294c;
            case 0x1E29C0u: goto label_1e29c0;
            case 0x1E29DCu: goto label_1e29dc;
            case 0x1E29F0u: goto label_1e29f0;
            case 0x1E2A0Cu: goto label_1e2a0c;
            case 0x1E2A78u: goto label_1e2a78;
            case 0x1E2A8Cu: goto label_1e2a8c;
            case 0x1E2ACCu: goto label_1e2acc;
            case 0x1E2ADCu: goto label_1e2adc;
            case 0x1E2B00u: goto label_1e2b00;
            case 0x1E2B10u: goto label_1e2b10;
            case 0x1E2B34u: goto label_1e2b34;
            case 0x1E2B48u: goto label_1e2b48;
            case 0x1E2B54u: goto label_1e2b54;
            case 0x1E2B90u: goto label_1e2b90;
            case 0x1E2B98u: goto label_1e2b98;
            case 0x1E2BC0u: goto label_1e2bc0;
            case 0x1E2BE4u: goto label_1e2be4;
            case 0x1E2BF8u: goto label_1e2bf8;
            case 0x1E2C14u: goto label_1e2c14;
            case 0x1E2C84u: goto label_1e2c84;
            case 0x1E2C98u: goto label_1e2c98;
            case 0x1E2CD8u: goto label_1e2cd8;
            case 0x1E2CE8u: goto label_1e2ce8;
            case 0x1E2D0Cu: goto label_1e2d0c;
            case 0x1E2D1Cu: goto label_1e2d1c;
            case 0x1E2D40u: goto label_1e2d40;
            case 0x1E2D54u: goto label_1e2d54;
            case 0x1E2E10u: goto label_1e2e10;
            case 0x1E2E18u: goto label_1e2e18;
            case 0x1E2E20u: goto label_1e2e20;
            case 0x1E2E48u: goto label_1e2e48;
            case 0x1E2E64u: goto label_1e2e64;
            case 0x1E2E78u: goto label_1e2e78;
            case 0x1E2E94u: goto label_1e2e94;
            case 0x1E2EF8u: goto label_1e2ef8;
            case 0x1E2F0Cu: goto label_1e2f0c;
            case 0x1E2F4Cu: goto label_1e2f4c;
            case 0x1E2F5Cu: goto label_1e2f5c;
            case 0x1E2F80u: goto label_1e2f80;
            case 0x1E2FA8u: goto label_1e2fa8;
            case 0x1E2FC4u: goto label_1e2fc4;
            case 0x1E2FD8u: goto label_1e2fd8;
            case 0x1E2FF4u: goto label_1e2ff4;
            case 0x1E3058u: goto label_1e3058;
            case 0x1E306Cu: goto label_1e306c;
            case 0x1E30ACu: goto label_1e30ac;
            case 0x1E30BCu: goto label_1e30bc;
            case 0x1E30E0u: goto label_1e30e0;
            case 0x1E3108u: goto label_1e3108;
            case 0x1E3124u: goto label_1e3124;
            case 0x1E3138u: goto label_1e3138;
            case 0x1E3154u: goto label_1e3154;
            case 0x1E31CCu: goto label_1e31cc;
            case 0x1E31E0u: goto label_1e31e0;
            case 0x1E3220u: goto label_1e3220;
            case 0x1E3238u: goto label_1e3238;
            case 0x1E325Cu: goto label_1e325c;
            case 0x1E3278u: goto label_1e3278;
            case 0x1E329Cu: goto label_1e329c;
            case 0x1E32B0u: goto label_1e32b0;
            case 0x1E3318u: goto label_1e3318;
            case 0x1E3388u: goto label_1e3388;
            case 0x1E33C4u: goto label_1e33c4;
            case 0x1E33E0u: goto label_1e33e0;
            case 0x1E33F4u: goto label_1e33f4;
            case 0x1E3410u: goto label_1e3410;
            case 0x1E347Cu: goto label_1e347c;
            case 0x1E3490u: goto label_1e3490;
            case 0x1E34D0u: goto label_1e34d0;
            case 0x1E34E0u: goto label_1e34e0;
            case 0x1E3504u: goto label_1e3504;
            case 0x1E3514u: goto label_1e3514;
            case 0x1E3538u: goto label_1e3538;
            case 0x1E354Cu: goto label_1e354c;
            case 0x1E360Cu: goto label_1e360c;
            case 0x1E3628u: goto label_1e3628;
            case 0x1E363Cu: goto label_1e363c;
            case 0x1E3658u: goto label_1e3658;
            case 0x1E36C4u: goto label_1e36c4;
            case 0x1E36D8u: goto label_1e36d8;
            case 0x1E3718u: goto label_1e3718;
            case 0x1E3728u: goto label_1e3728;
            case 0x1E374Cu: goto label_1e374c;
            case 0x1E375Cu: goto label_1e375c;
            case 0x1E3780u: goto label_1e3780;
            case 0x1E3794u: goto label_1e3794;
            case 0x1E3854u: goto label_1e3854;
            case 0x1E3870u: goto label_1e3870;
            case 0x1E3884u: goto label_1e3884;
            case 0x1E38A0u: goto label_1e38a0;
            case 0x1E3908u: goto label_1e3908;
            case 0x1E391Cu: goto label_1e391c;
            case 0x1E395Cu: goto label_1e395c;
            case 0x1E396Cu: goto label_1e396c;
            case 0x1E3990u: goto label_1e3990;
            case 0x1E39A0u: goto label_1e39a0;
            case 0x1E39C4u: goto label_1e39c4;
            case 0x1E39D8u: goto label_1e39d8;
            case 0x1E3A44u: goto label_1e3a44;
            case 0x1E3A60u: goto label_1e3a60;
            case 0x1E3A74u: goto label_1e3a74;
            case 0x1E3A78u: goto label_1e3a78;
            case 0x1E3ADCu: goto label_1e3adc;
            case 0x1E3AF0u: goto label_1e3af0;
            case 0x1E3B30u: goto label_1e3b30;
            case 0x1E3B40u: goto label_1e3b40;
            case 0x1E3B64u: goto label_1e3b64;
            case 0x1E3B84u: goto label_1e3b84;
            case 0x1E3BA0u: goto label_1e3ba0;
            case 0x1E3BB4u: goto label_1e3bb4;
            case 0x1E3BB8u: goto label_1e3bb8;
            case 0x1E3C1Cu: goto label_1e3c1c;
            case 0x1E3C30u: goto label_1e3c30;
            case 0x1E3C70u: goto label_1e3c70;
            case 0x1E3C80u: goto label_1e3c80;
            case 0x1E3CA4u: goto label_1e3ca4;
            case 0x1E3CC4u: goto label_1e3cc4;
            case 0x1E3CE8u: goto label_1e3ce8;
            case 0x1E3CFCu: goto label_1e3cfc;
            case 0x1E3D00u: goto label_1e3d00;
            case 0x1E3D68u: goto label_1e3d68;
            case 0x1E3D7Cu: goto label_1e3d7c;
            case 0x1E3DBCu: goto label_1e3dbc;
            case 0x1E3DCCu: goto label_1e3dcc;
            case 0x1E3DF0u: goto label_1e3df0;
            case 0x1E3E00u: goto label_1e3e00;
            case 0x1E3E24u: goto label_1e3e24;
            case 0x1E3E38u: goto label_1e3e38;
            case 0x1E3EA4u: goto label_1e3ea4;
            case 0x1E3EC0u: goto label_1e3ec0;
            case 0x1E3ED4u: goto label_1e3ed4;
            case 0x1E3ED8u: goto label_1e3ed8;
            case 0x1E3F40u: goto label_1e3f40;
            case 0x1E3F54u: goto label_1e3f54;
            case 0x1E3F94u: goto label_1e3f94;
            case 0x1E3FA4u: goto label_1e3fa4;
            case 0x1E3FC8u: goto label_1e3fc8;
            case 0x1E3FD8u: goto label_1e3fd8;
            case 0x1E3FFCu: goto label_1e3ffc;
            case 0x1E4010u: goto label_1e4010;
            case 0x1E407Cu: goto label_1e407c;
            case 0x1E4098u: goto label_1e4098;
            case 0x1E40ACu: goto label_1e40ac;
            case 0x1E40B0u: goto label_1e40b0;
            case 0x1E4118u: goto label_1e4118;
            case 0x1E412Cu: goto label_1e412c;
            case 0x1E416Cu: goto label_1e416c;
            case 0x1E417Cu: goto label_1e417c;
            case 0x1E41A0u: goto label_1e41a0;
            case 0x1E41B0u: goto label_1e41b0;
            case 0x1E41D4u: goto label_1e41d4;
            case 0x1E41E8u: goto label_1e41e8;
            case 0x1E4254u: goto label_1e4254;
            case 0x1E4270u: goto label_1e4270;
            case 0x1E4284u: goto label_1e4284;
            case 0x1E4288u: goto label_1e4288;
            case 0x1E42F0u: goto label_1e42f0;
            case 0x1E4304u: goto label_1e4304;
            case 0x1E4344u: goto label_1e4344;
            case 0x1E4358u: goto label_1e4358;
            case 0x1E437Cu: goto label_1e437c;
            case 0x1E4394u: goto label_1e4394;
            case 0x1E43B8u: goto label_1e43b8;
            case 0x1E43CCu: goto label_1e43cc;
            case 0x1E43E4u: goto label_1e43e4;
            case 0x1E4414u: goto label_1e4414;
            case 0x1E4430u: goto label_1e4430;
            case 0x1E4444u: goto label_1e4444;
            case 0x1E4460u: goto label_1e4460;
            case 0x1E44C8u: goto label_1e44c8;
            case 0x1E44DCu: goto label_1e44dc;
            case 0x1E451Cu: goto label_1e451c;
            case 0x1E452Cu: goto label_1e452c;
            case 0x1E4550u: goto label_1e4550;
            case 0x1E4560u: goto label_1e4560;
            case 0x1E4584u: goto label_1e4584;
            case 0x1E4598u: goto label_1e4598;
            case 0x1E460Cu: goto label_1e460c;
            case 0x1E4628u: goto label_1e4628;
            case 0x1E463Cu: goto label_1e463c;
            case 0x1E4658u: goto label_1e4658;
            case 0x1E46C8u: goto label_1e46c8;
            case 0x1E46DCu: goto label_1e46dc;
            case 0x1E471Cu: goto label_1e471c;
            case 0x1E472Cu: goto label_1e472c;
            case 0x1E4750u: goto label_1e4750;
            case 0x1E4764u: goto label_1e4764;
            case 0x1E4788u: goto label_1e4788;
            case 0x1E479Cu: goto label_1e479c;
            case 0x1E47B0u: goto label_1e47b0;
            case 0x1E47E0u: goto label_1e47e0;
            case 0x1E47FCu: goto label_1e47fc;
            case 0x1E4800u: goto label_1e4800;
            case 0x1E48A0u: goto label_1e48a0;
            case 0x1E48B4u: goto label_1e48b4;
            case 0x1E48F4u: goto label_1e48f4;
            case 0x1E4918u: goto label_1e4918;
            case 0x1E493Cu: goto label_1e493c;
            case 0x1E4974u: goto label_1e4974;
            case 0x1E4998u: goto label_1e4998;
            case 0x1E49ACu: goto label_1e49ac;
            case 0x1E4A08u: goto label_1e4a08;
            case 0x1E4A24u: goto label_1e4a24;
            case 0x1E4AACu: goto label_1e4aac;
            case 0x1E4AC0u: goto label_1e4ac0;
            case 0x1E4B00u: goto label_1e4b00;
            case 0x1E4B1Cu: goto label_1e4b1c;
            case 0x1E4B20u: goto label_1e4b20;
            case 0x1E4B94u: goto label_1e4b94;
            case 0x1E4BA8u: goto label_1e4ba8;
            case 0x1E4BE8u: goto label_1e4be8;
            case 0x1E4C10u: goto label_1e4c10;
            case 0x1E4C34u: goto label_1e4c34;
            case 0x1E4C64u: goto label_1e4c64;
            case 0x1E4C88u: goto label_1e4c88;
            case 0x1E4C9Cu: goto label_1e4c9c;
            case 0x1E4D08u: goto label_1e4d08;
            case 0x1E4D28u: goto label_1e4d28;
            case 0x1E4DE4u: goto label_1e4de4;
            case 0x1E4DF8u: goto label_1e4df8;
            case 0x1E4E3Cu: goto label_1e4e3c;
            case 0x1E4E58u: goto label_1e4e58;
            case 0x1E4E5Cu: goto label_1e4e5c;
            case 0x1E4EC4u: goto label_1e4ec4;
            case 0x1E4ED8u: goto label_1e4ed8;
            case 0x1E4F18u: goto label_1e4f18;
            case 0x1E4F28u: goto label_1e4f28;
            case 0x1E4F4Cu: goto label_1e4f4c;
            case 0x1E4F60u: goto label_1e4f60;
            case 0x1E4F84u: goto label_1e4f84;
            case 0x1E4F98u: goto label_1e4f98;
            case 0x1E4FACu: goto label_1e4fac;
            case 0x1E4FD0u: goto label_1e4fd0;
            case 0x1E4FECu: goto label_1e4fec;
            case 0x1E4FF0u: goto label_1e4ff0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E4818u;
    // 0x1e4818: 0x27bdff80  addiu       $sp, $sp, -0x80
    ctx->pc = 0x1e4818u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x1e481c: 0xffbe0030  sd          $fp, 0x30($sp)
    ctx->pc = 0x1e481cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 30));
    // 0x1e4820: 0xffbf0038  sd          $ra, 0x38($sp)
    ctx->pc = 0x1e4820u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x1e4824: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e4824u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e4828: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e4828u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e482c: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e482cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e4830: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e4830u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e4834: 0xe0102d  daddu       $v0, $a3, $zero
    ctx->pc = 0x1e4834u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e4838: 0xffc90068  sd          $t1, 0x68($fp)
    ctx->pc = 0x1e4838u;
    WRITE64(ADD32(GPR_U32(ctx, 30), 104), GPR_U64(ctx, 9));
    // 0x1e483c: 0xffca0070  sd          $t2, 0x70($fp)
    ctx->pc = 0x1e483cu;
    WRITE64(ADD32(GPR_U32(ctx, 30), 112), GPR_U64(ctx, 10));
    // 0x1e4840: 0xffcb0078  sd          $t3, 0x78($fp)
    ctx->pc = 0x1e4840u;
    WRITE64(ADD32(GPR_U32(ctx, 30), 120), GPR_U64(ctx, 11));
    // 0x1e4844: 0xe7cc0048  swc1        $f12, 0x48($fp)
    ctx->pc = 0x1e4844u;
    { float f = ctx->f[12]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 30), 72), bits); }
    // 0x1e4848: 0xe7cd004c  swc1        $f13, 0x4C($fp)
    ctx->pc = 0x1e4848u;
    { float f = ctx->f[13]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 30), 76), bits); }
    // 0x1e484c: 0xe7ce0050  swc1        $f14, 0x50($fp)
    ctx->pc = 0x1e484cu;
    { float f = ctx->f[14]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 30), 80), bits); }
    // 0x1e4850: 0xe7cf0054  swc1        $f15, 0x54($fp)
    ctx->pc = 0x1e4850u;
    { float f = ctx->f[15]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 30), 84), bits); }
    // 0x1e4854: 0xe7d00058  swc1        $f16, 0x58($fp)
    ctx->pc = 0x1e4854u;
    { float f = ctx->f[16]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 30), 88), bits); }
    // 0x1e4858: 0xe7d1005c  swc1        $f17, 0x5C($fp)
    ctx->pc = 0x1e4858u;
    { float f = ctx->f[17]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 30), 92), bits); }
    // 0x1e485c: 0xe7d20060  swc1        $f18, 0x60($fp)
    ctx->pc = 0x1e485cu;
    { float f = ctx->f[18]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 30), 96), bits); }
    // 0x1e4860: 0xe7d30064  swc1        $f19, 0x64($fp)
    ctx->pc = 0x1e4860u;
    { float f = ctx->f[19]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 30), 100), bits); }
    // 0x1e4864: 0xafc80010  sw          $t0, 0x10($fp)
    ctx->pc = 0x1e4864u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 8));
    // 0x1e4868: 0xa7c2000c  sh          $v0, 0xC($fp)
    ctx->pc = 0x1e4868u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 12), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e486c: 0xafc00024  sw          $zero, 0x24($fp)
    ctx->pc = 0x1e486cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 0));
    // 0x1e4870: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e4870u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e4874: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e4874u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e4878: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E4878u;
    {
        const bool branch_taken_0x1e4878 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e4878) {
            ctx->pc = 0x1E48A0u;
            goto label_1e48a0;
        }
    }
    ctx->pc = 0x1E4880u;
    // 0x1e4880: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e4880u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e4884: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e4884u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e4888: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e4888u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e488c: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e488cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e4890: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e4890u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e4894: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e4894u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e4898: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E4898u;
    {
        const bool branch_taken_0x1e4898 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e4898) {
            ctx->pc = 0x1E48B4u;
            goto label_1e48b4;
        }
    }
    ctx->pc = 0x1E48A0u;
label_1e48a0:
    // 0x1e48a0: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e48a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e48a4: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e48a4u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e48a8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e48a8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e48ac: 0x1000009c  b           . + 4 + (0x9C << 2)
    ctx->pc = 0x1E48ACu;
    {
        const bool branch_taken_0x1e48ac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e48ac) {
            ctx->pc = 0x1E4B20u;
            goto label_1e4b20;
        }
    }
    ctx->pc = 0x1E48B4u;
label_1e48b4:
    // 0x1e48b4: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e48b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e48b8: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e48b8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e48bc: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e48bcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e48c0: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e48c0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e48c4: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e48c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e48c8: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e48c8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e48cc: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1e48ccu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1e48d0: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1e48d0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1e48d4: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e48d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e48d8: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E48D8u;
    {
        const bool branch_taken_0x1e48d8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e48d8) {
            ctx->pc = 0x1E48F4u;
            goto label_1e48f4;
        }
    }
    ctx->pc = 0x1E48E0u;
    // 0x1e48e0: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e48e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e48e4: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e48e4u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e48e8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e48e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e48ec: 0x1000008c  b           . + 4 + (0x8C << 2)
    ctx->pc = 0x1E48ECu;
    {
        const bool branch_taken_0x1e48ec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e48ec) {
            ctx->pc = 0x1E4B20u;
            goto label_1e4b20;
        }
    }
    ctx->pc = 0x1E48F4u;
label_1e48f4:
    // 0x1e48f4: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e48f4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e48f8: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e48f8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e48fc: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1e48fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e4900: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e4900u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e4904: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1e4904u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1e4908: 0x8fc40024  lw          $a0, 0x24($fp)
    ctx->pc = 0x1e4908u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1e490c: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1e490cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e4910: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E4910u;
    SET_GPR_U32(ctx, 31, 0x1E4918u);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4918u; }
        if (ctx->pc != 0x1E4918u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4918u; }
        if (ctx->pc != 0x1E4918u) { return; }
    }
    ctx->pc = 0x1E4918u;
label_1e4918:
    // 0x1e4918: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1e4918u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1e491c: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e491cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e4920: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E4920u;
    {
        const bool branch_taken_0x1e4920 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e4920) {
            ctx->pc = 0x1E493Cu;
            goto label_1e493c;
        }
    }
    ctx->pc = 0x1E4928u;
    // 0x1e4928: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e4928u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e492c: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e492cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e4930: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e4930u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e4934: 0x1000007a  b           . + 4 + (0x7A << 2)
    ctx->pc = 0x1E4934u;
    {
        const bool branch_taken_0x1e4934 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4934) {
            ctx->pc = 0x1E4B20u;
            goto label_1e4b20;
        }
    }
    ctx->pc = 0x1E493Cu;
label_1e493c:
    // 0x1e493c: 0x27c20080  addiu       $v0, $fp, 0x80
    ctx->pc = 0x1e493cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 128));
    // 0x1e4940: 0x2442ffe8  addiu       $v0, $v0, -0x18
    ctx->pc = 0x1e4940u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967272));
    // 0x1e4944: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1e4944u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1e4948: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e4948u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e494c: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1e494cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e4950: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e4950u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e4954: 0x97c20008  lhu         $v0, 0x8($fp)
    ctx->pc = 0x1e4954u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e4958: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e4958u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e495c: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1e495cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1e4960: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1e4960u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1e4964: 0x8fc40018  lw          $a0, 0x18($fp)
    ctx->pc = 0x1e4964u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e4968: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1e4968u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e496c: 0xc07cc3c  jal         func_1F30F0
    ctx->pc = 0x1E496Cu;
    SET_GPR_U32(ctx, 31, 0x1E4974u);
    ctx->pc = 0x1F30F0u;
    if (runtime->hasFunction(0x1F30F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F30F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4974u; }
        if (ctx->pc != 0x1E4974u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F30F0_0x1f30f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4974u; }
        if (ctx->pc != 0x1E4974u) { return; }
    }
    ctx->pc = 0x1E4974u;
label_1e4974:
    // 0x1e4974: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1e4974u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1e4978: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1e4978u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e497c: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1E497Cu;
    {
        const bool branch_taken_0x1e497c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e497c) {
            ctx->pc = 0x1E49ACu;
            goto label_1e49ac;
        }
    }
    ctx->pc = 0x1E4984u;
    // 0x1e4984: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1e4984u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1e4988: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1e4988u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1e498c: 0x8fc50018  lw          $a1, 0x18($fp)
    ctx->pc = 0x1e498cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e4990: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1E4990u;
    SET_GPR_U32(ctx, 31, 0x1E4998u);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4998u; }
        if (ctx->pc != 0x1E4998u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4998u; }
        if (ctx->pc != 0x1E4998u) { return; }
    }
    ctx->pc = 0x1E4998u;
label_1e4998:
    // 0x1e4998: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e4998u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e499c: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e499cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e49a0: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e49a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e49a4: 0x1000005e  b           . + 4 + (0x5E << 2)
    ctx->pc = 0x1E49A4u;
    {
        const bool branch_taken_0x1e49a4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e49a4) {
            ctx->pc = 0x1E4B20u;
            goto label_1e4b20;
        }
    }
    ctx->pc = 0x1E49ACu;
label_1e49ac:
    // 0x1e49ac: 0x27c6001c  addiu       $a2, $fp, 0x1C
    ctx->pc = 0x1e49acu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 30), 28));
    // 0x1e49b0: 0x8cc50000  lw          $a1, 0x0($a2)
    ctx->pc = 0x1e49b0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1e49b4: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e49b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e49b8: 0x304300ff  andi        $v1, $v0, 0xFF
    ctx->pc = 0x1e49b8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1e49bc: 0x31e00  sll         $v1, $v1, 24
    ctx->pc = 0x1e49bcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 24));
    // 0x1e49c0: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e49c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e49c4: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1e49c4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1e49c8: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1e49c8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1e49cc: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1e49ccu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e49d0: 0x8fc40010  lw          $a0, 0x10($fp)
    ctx->pc = 0x1e49d0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e49d4: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1e49d4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1e49d8: 0x821024  and         $v0, $a0, $v0
    ctx->pc = 0x1e49d8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & GPR_U64(ctx, 2));
    // 0x1e49dc: 0x21203  sra         $v0, $v0, 8
    ctx->pc = 0x1e49dcu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 8));
    // 0x1e49e0: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1e49e0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e49e4: 0x8fc40010  lw          $a0, 0x10($fp)
    ctx->pc = 0x1e49e4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e49e8: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1e49e8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1e49ec: 0x821024  and         $v0, $a0, $v0
    ctx->pc = 0x1e49ecu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & GPR_U64(ctx, 2));
    // 0x1e49f0: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1e49f0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1e49f4: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1e49f4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e49f8: 0xaca30000  sw          $v1, 0x0($a1)
    ctx->pc = 0x1e49f8u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 3));
    // 0x1e49fc: 0x24a50004  addiu       $a1, $a1, 0x4
    ctx->pc = 0x1e49fcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4));
    // 0x1e4a00: 0xacc50000  sw          $a1, 0x0($a2)
    ctx->pc = 0x1e4a00u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 5));
    // 0x1e4a04: 0xafc00028  sw          $zero, 0x28($fp)
    ctx->pc = 0x1e4a04u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 0));
label_1e4a08:
    // 0x1e4a08: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1e4a08u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1e4a0c: 0x8fc30010  lw          $v1, 0x10($fp)
    ctx->pc = 0x1e4a0cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e4a10: 0x43102a  slt         $v0, $v0, $v1
    ctx->pc = 0x1e4a10u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1e4a14: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1E4A14u;
    {
        const bool branch_taken_0x1e4a14 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e4a14) {
            ctx->pc = 0x1E4A24u;
            goto label_1e4a24;
        }
    }
    ctx->pc = 0x1E4A1Cu;
    // 0x1e4a1c: 0x10000023  b           . + 4 + (0x23 << 2)
    ctx->pc = 0x1E4A1Cu;
    {
        const bool branch_taken_0x1e4a1c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4a1c) {
            ctx->pc = 0x1E4AACu;
            goto label_1e4aac;
        }
    }
    ctx->pc = 0x1E4A24u;
label_1e4a24:
    // 0x1e4a24: 0x27c30014  addiu       $v1, $fp, 0x14
    ctx->pc = 0x1e4a24u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 30), 20));
    // 0x1e4a28: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x1e4a28u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1e4a2c: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1e4a2cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e4a30: 0x24420008  addiu       $v0, $v0, 0x8
    ctx->pc = 0x1e4a30u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x1e4a34: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1e4a34u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1e4a38: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1e4a38u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1e4a3c: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1e4a3cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1e4a40: 0x27c6001c  addiu       $a2, $fp, 0x1C
    ctx->pc = 0x1e4a40u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 30), 28));
    // 0x1e4a44: 0x8cc50000  lw          $a1, 0x0($a2)
    ctx->pc = 0x1e4a44u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1e4a48: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e4a48u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e4a4c: 0x304300ff  andi        $v1, $v0, 0xFF
    ctx->pc = 0x1e4a4cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1e4a50: 0x31e00  sll         $v1, $v1, 24
    ctx->pc = 0x1e4a50u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 24));
    // 0x1e4a54: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e4a54u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e4a58: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1e4a58u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1e4a5c: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1e4a5cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1e4a60: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1e4a60u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e4a64: 0x8fc40020  lw          $a0, 0x20($fp)
    ctx->pc = 0x1e4a64u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e4a68: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1e4a68u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1e4a6c: 0x821024  and         $v0, $a0, $v0
    ctx->pc = 0x1e4a6cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & GPR_U64(ctx, 2));
    // 0x1e4a70: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1e4a70u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1e4a74: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1e4a74u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e4a78: 0x8fc40020  lw          $a0, 0x20($fp)
    ctx->pc = 0x1e4a78u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e4a7c: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1e4a7cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1e4a80: 0x821024  and         $v0, $a0, $v0
    ctx->pc = 0x1e4a80u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & GPR_U64(ctx, 2));
    // 0x1e4a84: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1e4a84u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1e4a88: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1e4a88u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e4a8c: 0xaca30000  sw          $v1, 0x0($a1)
    ctx->pc = 0x1e4a8cu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 3));
    // 0x1e4a90: 0x24a50004  addiu       $a1, $a1, 0x4
    ctx->pc = 0x1e4a90u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4));
    // 0x1e4a94: 0xacc50000  sw          $a1, 0x0($a2)
    ctx->pc = 0x1e4a94u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 5));
    // 0x1e4a98: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1e4a98u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1e4a9c: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1e4a9cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1e4aa0: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1e4aa0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1e4aa4: 0x1000ffd8  b           . + 4 + (-0x28 << 2)
    ctx->pc = 0x1E4AA4u;
    {
        const bool branch_taken_0x1e4aa4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4aa4) {
            ctx->pc = 0x1E4A08u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1e4a08;
        }
    }
    ctx->pc = 0x1E4AACu;
label_1e4aac:
    // 0x1e4aac: 0x8fc4001c  lw          $a0, 0x1C($fp)
    ctx->pc = 0x1e4aacu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e4ab0: 0x8fc50004  lw          $a1, 0x4($fp)
    ctx->pc = 0x1e4ab0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e4ab4: 0x8fc60008  lw          $a2, 0x8($fp)
    ctx->pc = 0x1e4ab4u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e4ab8: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1E4AB8u;
    SET_GPR_U32(ctx, 31, 0x1E4AC0u);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4AC0u; }
        if (ctx->pc != 0x1E4AC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4AC0u; }
        if (ctx->pc != 0x1E4AC0u) { return; }
    }
    ctx->pc = 0x1E4AC0u;
label_1e4ac0:
    // 0x1e4ac0: 0x97c2000c  lhu         $v0, 0xC($fp)
    ctx->pc = 0x1e4ac0u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e4ac4: 0x3442a400  ori         $v0, $v0, 0xA400
    ctx->pc = 0x1e4ac4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)41984);
    // 0x1e4ac8: 0x3046ffff  andi        $a2, $v0, 0xFFFF
    ctx->pc = 0x1e4ac8u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1e4acc: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e4accu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e4ad0: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1e4ad0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e4ad4: 0x97c30008  lhu         $v1, 0x8($fp)
    ctx->pc = 0x1e4ad4u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e4ad8: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e4ad8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e4adc: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1e4adcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1e4ae0: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1e4ae0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1e4ae4: 0x8fc40024  lw          $a0, 0x24($fp)
    ctx->pc = 0x1e4ae4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1e4ae8: 0x8fc50018  lw          $a1, 0x18($fp)
    ctx->pc = 0x1e4ae8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e4aec: 0x40382d  daddu       $a3, $v0, $zero
    ctx->pc = 0x1e4aecu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e4af0: 0x24080010  addiu       $t0, $zero, 0x10
    ctx->pc = 0x1e4af0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1e4af4: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1e4af4u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e4af8: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E4AF8u;
    SET_GPR_U32(ctx, 31, 0x1E4B00u);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4B00u; }
        if (ctx->pc != 0x1E4B00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4B00u; }
        if (ctx->pc != 0x1E4B00u) { return; }
    }
    ctx->pc = 0x1E4B00u;
label_1e4b00:
    // 0x1e4b00: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E4B00u;
    {
        const bool branch_taken_0x1e4b00 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4b00) {
            ctx->pc = 0x1E4B1Cu;
            goto label_1e4b1c;
        }
    }
    ctx->pc = 0x1E4B08u;
    // 0x1e4b08: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e4b08u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e4b0c: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e4b0cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e4b10: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e4b10u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e4b14: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1E4B14u;
    {
        const bool branch_taken_0x1e4b14 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4b14) {
            ctx->pc = 0x1E4B20u;
            goto label_1e4b20;
        }
    }
    ctx->pc = 0x1E4B1Cu;
label_1e4b1c:
    // 0x1e4b1c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1e4b1cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1e4b20:
    // 0x1e4b20: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e4b20u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e4b24: 0xdfbe0030  ld          $fp, 0x30($sp)
    ctx->pc = 0x1e4b24u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1e4b28: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x1e4b28u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x1e4b2c: 0x27bd0080  addiu       $sp, $sp, 0x80
    ctx->pc = 0x1e4b2cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
    // 0x1e4b30: 0x3e00008  jr          $ra
    ctx->pc = 0x1E4B30u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E1B3Cu: goto label_1e1b3c;
            case 0x1E1B60u: goto label_1e1b60;
            case 0x1E1B84u: goto label_1e1b84;
            case 0x1E1BA8u: goto label_1e1ba8;
            case 0x1E1BC8u: goto label_1e1bc8;
            case 0x1E1BE4u: goto label_1e1be4;
            case 0x1E1BE8u: goto label_1e1be8;
            case 0x1E1C44u: goto label_1e1c44;
            case 0x1E1C58u: goto label_1e1c58;
            case 0x1E1C7Cu: goto label_1e1c7c;
            case 0x1E1CD8u: goto label_1e1cd8;
            case 0x1E1CECu: goto label_1e1cec;
            case 0x1E1D14u: goto label_1e1d14;
            case 0x1E1D7Cu: goto label_1e1d7c;
            case 0x1E1D90u: goto label_1e1d90;
            case 0x1E1DD0u: goto label_1e1dd0;
            case 0x1E1DE0u: goto label_1e1de0;
            case 0x1E1E04u: goto label_1e1e04;
            case 0x1E1E14u: goto label_1e1e14;
            case 0x1E1E38u: goto label_1e1e38;
            case 0x1E1E4Cu: goto label_1e1e4c;
            case 0x1E1E5Cu: goto label_1e1e5c;
            case 0x1E1E84u: goto label_1e1e84;
            case 0x1E1EA0u: goto label_1e1ea0;
            case 0x1E1EB4u: goto label_1e1eb4;
            case 0x1E1ED0u: goto label_1e1ed0;
            case 0x1E1F48u: goto label_1e1f48;
            case 0x1E1F5Cu: goto label_1e1f5c;
            case 0x1E1F9Cu: goto label_1e1f9c;
            case 0x1E1FACu: goto label_1e1fac;
            case 0x1E1FD0u: goto label_1e1fd0;
            case 0x1E1FE0u: goto label_1e1fe0;
            case 0x1E2004u: goto label_1e2004;
            case 0x1E2018u: goto label_1e2018;
            case 0x1E202Cu: goto label_1e202c;
            case 0x1E2064u: goto label_1e2064;
            case 0x1E206Cu: goto label_1e206c;
            case 0x1E2088u: goto label_1e2088;
            case 0x1E20A0u: goto label_1e20a0;
            case 0x1E20D4u: goto label_1e20d4;
            case 0x1E20F8u: goto label_1e20f8;
            case 0x1E210Cu: goto label_1e210c;
            case 0x1E2128u: goto label_1e2128;
            case 0x1E2190u: goto label_1e2190;
            case 0x1E21A4u: goto label_1e21a4;
            case 0x1E21E4u: goto label_1e21e4;
            case 0x1E21F4u: goto label_1e21f4;
            case 0x1E2218u: goto label_1e2218;
            case 0x1E2228u: goto label_1e2228;
            case 0x1E224Cu: goto label_1e224c;
            case 0x1E2260u: goto label_1e2260;
            case 0x1E22D4u: goto label_1e22d4;
            case 0x1E22F0u: goto label_1e22f0;
            case 0x1E2304u: goto label_1e2304;
            case 0x1E2320u: goto label_1e2320;
            case 0x1E23A0u: goto label_1e23a0;
            case 0x1E23B4u: goto label_1e23b4;
            case 0x1E23F4u: goto label_1e23f4;
            case 0x1E2404u: goto label_1e2404;
            case 0x1E2428u: goto label_1e2428;
            case 0x1E2438u: goto label_1e2438;
            case 0x1E245Cu: goto label_1e245c;
            case 0x1E2470u: goto label_1e2470;
            case 0x1E2480u: goto label_1e2480;
            case 0x1E24F8u: goto label_1e24f8;
            case 0x1E2500u: goto label_1e2500;
            case 0x1E2508u: goto label_1e2508;
            case 0x1E25D0u: goto label_1e25d0;
            case 0x1E25ECu: goto label_1e25ec;
            case 0x1E2600u: goto label_1e2600;
            case 0x1E261Cu: goto label_1e261c;
            case 0x1E2684u: goto label_1e2684;
            case 0x1E2698u: goto label_1e2698;
            case 0x1E26D8u: goto label_1e26d8;
            case 0x1E26E8u: goto label_1e26e8;
            case 0x1E270Cu: goto label_1e270c;
            case 0x1E271Cu: goto label_1e271c;
            case 0x1E2740u: goto label_1e2740;
            case 0x1E2754u: goto label_1e2754;
            case 0x1E27C8u: goto label_1e27c8;
            case 0x1E27E4u: goto label_1e27e4;
            case 0x1E27F8u: goto label_1e27f8;
            case 0x1E2814u: goto label_1e2814;
            case 0x1E287Cu: goto label_1e287c;
            case 0x1E2890u: goto label_1e2890;
            case 0x1E28D0u: goto label_1e28d0;
            case 0x1E28E0u: goto label_1e28e0;
            case 0x1E2904u: goto label_1e2904;
            case 0x1E2914u: goto label_1e2914;
            case 0x1E2938u: goto label_1e2938;
            case 0x1E294Cu: goto label_1e294c;
            case 0x1E29C0u: goto label_1e29c0;
            case 0x1E29DCu: goto label_1e29dc;
            case 0x1E29F0u: goto label_1e29f0;
            case 0x1E2A0Cu: goto label_1e2a0c;
            case 0x1E2A78u: goto label_1e2a78;
            case 0x1E2A8Cu: goto label_1e2a8c;
            case 0x1E2ACCu: goto label_1e2acc;
            case 0x1E2ADCu: goto label_1e2adc;
            case 0x1E2B00u: goto label_1e2b00;
            case 0x1E2B10u: goto label_1e2b10;
            case 0x1E2B34u: goto label_1e2b34;
            case 0x1E2B48u: goto label_1e2b48;
            case 0x1E2B54u: goto label_1e2b54;
            case 0x1E2B90u: goto label_1e2b90;
            case 0x1E2B98u: goto label_1e2b98;
            case 0x1E2BC0u: goto label_1e2bc0;
            case 0x1E2BE4u: goto label_1e2be4;
            case 0x1E2BF8u: goto label_1e2bf8;
            case 0x1E2C14u: goto label_1e2c14;
            case 0x1E2C84u: goto label_1e2c84;
            case 0x1E2C98u: goto label_1e2c98;
            case 0x1E2CD8u: goto label_1e2cd8;
            case 0x1E2CE8u: goto label_1e2ce8;
            case 0x1E2D0Cu: goto label_1e2d0c;
            case 0x1E2D1Cu: goto label_1e2d1c;
            case 0x1E2D40u: goto label_1e2d40;
            case 0x1E2D54u: goto label_1e2d54;
            case 0x1E2E10u: goto label_1e2e10;
            case 0x1E2E18u: goto label_1e2e18;
            case 0x1E2E20u: goto label_1e2e20;
            case 0x1E2E48u: goto label_1e2e48;
            case 0x1E2E64u: goto label_1e2e64;
            case 0x1E2E78u: goto label_1e2e78;
            case 0x1E2E94u: goto label_1e2e94;
            case 0x1E2EF8u: goto label_1e2ef8;
            case 0x1E2F0Cu: goto label_1e2f0c;
            case 0x1E2F4Cu: goto label_1e2f4c;
            case 0x1E2F5Cu: goto label_1e2f5c;
            case 0x1E2F80u: goto label_1e2f80;
            case 0x1E2FA8u: goto label_1e2fa8;
            case 0x1E2FC4u: goto label_1e2fc4;
            case 0x1E2FD8u: goto label_1e2fd8;
            case 0x1E2FF4u: goto label_1e2ff4;
            case 0x1E3058u: goto label_1e3058;
            case 0x1E306Cu: goto label_1e306c;
            case 0x1E30ACu: goto label_1e30ac;
            case 0x1E30BCu: goto label_1e30bc;
            case 0x1E30E0u: goto label_1e30e0;
            case 0x1E3108u: goto label_1e3108;
            case 0x1E3124u: goto label_1e3124;
            case 0x1E3138u: goto label_1e3138;
            case 0x1E3154u: goto label_1e3154;
            case 0x1E31CCu: goto label_1e31cc;
            case 0x1E31E0u: goto label_1e31e0;
            case 0x1E3220u: goto label_1e3220;
            case 0x1E3238u: goto label_1e3238;
            case 0x1E325Cu: goto label_1e325c;
            case 0x1E3278u: goto label_1e3278;
            case 0x1E329Cu: goto label_1e329c;
            case 0x1E32B0u: goto label_1e32b0;
            case 0x1E3318u: goto label_1e3318;
            case 0x1E3388u: goto label_1e3388;
            case 0x1E33C4u: goto label_1e33c4;
            case 0x1E33E0u: goto label_1e33e0;
            case 0x1E33F4u: goto label_1e33f4;
            case 0x1E3410u: goto label_1e3410;
            case 0x1E347Cu: goto label_1e347c;
            case 0x1E3490u: goto label_1e3490;
            case 0x1E34D0u: goto label_1e34d0;
            case 0x1E34E0u: goto label_1e34e0;
            case 0x1E3504u: goto label_1e3504;
            case 0x1E3514u: goto label_1e3514;
            case 0x1E3538u: goto label_1e3538;
            case 0x1E354Cu: goto label_1e354c;
            case 0x1E360Cu: goto label_1e360c;
            case 0x1E3628u: goto label_1e3628;
            case 0x1E363Cu: goto label_1e363c;
            case 0x1E3658u: goto label_1e3658;
            case 0x1E36C4u: goto label_1e36c4;
            case 0x1E36D8u: goto label_1e36d8;
            case 0x1E3718u: goto label_1e3718;
            case 0x1E3728u: goto label_1e3728;
            case 0x1E374Cu: goto label_1e374c;
            case 0x1E375Cu: goto label_1e375c;
            case 0x1E3780u: goto label_1e3780;
            case 0x1E3794u: goto label_1e3794;
            case 0x1E3854u: goto label_1e3854;
            case 0x1E3870u: goto label_1e3870;
            case 0x1E3884u: goto label_1e3884;
            case 0x1E38A0u: goto label_1e38a0;
            case 0x1E3908u: goto label_1e3908;
            case 0x1E391Cu: goto label_1e391c;
            case 0x1E395Cu: goto label_1e395c;
            case 0x1E396Cu: goto label_1e396c;
            case 0x1E3990u: goto label_1e3990;
            case 0x1E39A0u: goto label_1e39a0;
            case 0x1E39C4u: goto label_1e39c4;
            case 0x1E39D8u: goto label_1e39d8;
            case 0x1E3A44u: goto label_1e3a44;
            case 0x1E3A60u: goto label_1e3a60;
            case 0x1E3A74u: goto label_1e3a74;
            case 0x1E3A78u: goto label_1e3a78;
            case 0x1E3ADCu: goto label_1e3adc;
            case 0x1E3AF0u: goto label_1e3af0;
            case 0x1E3B30u: goto label_1e3b30;
            case 0x1E3B40u: goto label_1e3b40;
            case 0x1E3B64u: goto label_1e3b64;
            case 0x1E3B84u: goto label_1e3b84;
            case 0x1E3BA0u: goto label_1e3ba0;
            case 0x1E3BB4u: goto label_1e3bb4;
            case 0x1E3BB8u: goto label_1e3bb8;
            case 0x1E3C1Cu: goto label_1e3c1c;
            case 0x1E3C30u: goto label_1e3c30;
            case 0x1E3C70u: goto label_1e3c70;
            case 0x1E3C80u: goto label_1e3c80;
            case 0x1E3CA4u: goto label_1e3ca4;
            case 0x1E3CC4u: goto label_1e3cc4;
            case 0x1E3CE8u: goto label_1e3ce8;
            case 0x1E3CFCu: goto label_1e3cfc;
            case 0x1E3D00u: goto label_1e3d00;
            case 0x1E3D68u: goto label_1e3d68;
            case 0x1E3D7Cu: goto label_1e3d7c;
            case 0x1E3DBCu: goto label_1e3dbc;
            case 0x1E3DCCu: goto label_1e3dcc;
            case 0x1E3DF0u: goto label_1e3df0;
            case 0x1E3E00u: goto label_1e3e00;
            case 0x1E3E24u: goto label_1e3e24;
            case 0x1E3E38u: goto label_1e3e38;
            case 0x1E3EA4u: goto label_1e3ea4;
            case 0x1E3EC0u: goto label_1e3ec0;
            case 0x1E3ED4u: goto label_1e3ed4;
            case 0x1E3ED8u: goto label_1e3ed8;
            case 0x1E3F40u: goto label_1e3f40;
            case 0x1E3F54u: goto label_1e3f54;
            case 0x1E3F94u: goto label_1e3f94;
            case 0x1E3FA4u: goto label_1e3fa4;
            case 0x1E3FC8u: goto label_1e3fc8;
            case 0x1E3FD8u: goto label_1e3fd8;
            case 0x1E3FFCu: goto label_1e3ffc;
            case 0x1E4010u: goto label_1e4010;
            case 0x1E407Cu: goto label_1e407c;
            case 0x1E4098u: goto label_1e4098;
            case 0x1E40ACu: goto label_1e40ac;
            case 0x1E40B0u: goto label_1e40b0;
            case 0x1E4118u: goto label_1e4118;
            case 0x1E412Cu: goto label_1e412c;
            case 0x1E416Cu: goto label_1e416c;
            case 0x1E417Cu: goto label_1e417c;
            case 0x1E41A0u: goto label_1e41a0;
            case 0x1E41B0u: goto label_1e41b0;
            case 0x1E41D4u: goto label_1e41d4;
            case 0x1E41E8u: goto label_1e41e8;
            case 0x1E4254u: goto label_1e4254;
            case 0x1E4270u: goto label_1e4270;
            case 0x1E4284u: goto label_1e4284;
            case 0x1E4288u: goto label_1e4288;
            case 0x1E42F0u: goto label_1e42f0;
            case 0x1E4304u: goto label_1e4304;
            case 0x1E4344u: goto label_1e4344;
            case 0x1E4358u: goto label_1e4358;
            case 0x1E437Cu: goto label_1e437c;
            case 0x1E4394u: goto label_1e4394;
            case 0x1E43B8u: goto label_1e43b8;
            case 0x1E43CCu: goto label_1e43cc;
            case 0x1E43E4u: goto label_1e43e4;
            case 0x1E4414u: goto label_1e4414;
            case 0x1E4430u: goto label_1e4430;
            case 0x1E4444u: goto label_1e4444;
            case 0x1E4460u: goto label_1e4460;
            case 0x1E44C8u: goto label_1e44c8;
            case 0x1E44DCu: goto label_1e44dc;
            case 0x1E451Cu: goto label_1e451c;
            case 0x1E452Cu: goto label_1e452c;
            case 0x1E4550u: goto label_1e4550;
            case 0x1E4560u: goto label_1e4560;
            case 0x1E4584u: goto label_1e4584;
            case 0x1E4598u: goto label_1e4598;
            case 0x1E460Cu: goto label_1e460c;
            case 0x1E4628u: goto label_1e4628;
            case 0x1E463Cu: goto label_1e463c;
            case 0x1E4658u: goto label_1e4658;
            case 0x1E46C8u: goto label_1e46c8;
            case 0x1E46DCu: goto label_1e46dc;
            case 0x1E471Cu: goto label_1e471c;
            case 0x1E472Cu: goto label_1e472c;
            case 0x1E4750u: goto label_1e4750;
            case 0x1E4764u: goto label_1e4764;
            case 0x1E4788u: goto label_1e4788;
            case 0x1E479Cu: goto label_1e479c;
            case 0x1E47B0u: goto label_1e47b0;
            case 0x1E47E0u: goto label_1e47e0;
            case 0x1E47FCu: goto label_1e47fc;
            case 0x1E4800u: goto label_1e4800;
            case 0x1E48A0u: goto label_1e48a0;
            case 0x1E48B4u: goto label_1e48b4;
            case 0x1E48F4u: goto label_1e48f4;
            case 0x1E4918u: goto label_1e4918;
            case 0x1E493Cu: goto label_1e493c;
            case 0x1E4974u: goto label_1e4974;
            case 0x1E4998u: goto label_1e4998;
            case 0x1E49ACu: goto label_1e49ac;
            case 0x1E4A08u: goto label_1e4a08;
            case 0x1E4A24u: goto label_1e4a24;
            case 0x1E4AACu: goto label_1e4aac;
            case 0x1E4AC0u: goto label_1e4ac0;
            case 0x1E4B00u: goto label_1e4b00;
            case 0x1E4B1Cu: goto label_1e4b1c;
            case 0x1E4B20u: goto label_1e4b20;
            case 0x1E4B94u: goto label_1e4b94;
            case 0x1E4BA8u: goto label_1e4ba8;
            case 0x1E4BE8u: goto label_1e4be8;
            case 0x1E4C10u: goto label_1e4c10;
            case 0x1E4C34u: goto label_1e4c34;
            case 0x1E4C64u: goto label_1e4c64;
            case 0x1E4C88u: goto label_1e4c88;
            case 0x1E4C9Cu: goto label_1e4c9c;
            case 0x1E4D08u: goto label_1e4d08;
            case 0x1E4D28u: goto label_1e4d28;
            case 0x1E4DE4u: goto label_1e4de4;
            case 0x1E4DF8u: goto label_1e4df8;
            case 0x1E4E3Cu: goto label_1e4e3c;
            case 0x1E4E58u: goto label_1e4e58;
            case 0x1E4E5Cu: goto label_1e4e5c;
            case 0x1E4EC4u: goto label_1e4ec4;
            case 0x1E4ED8u: goto label_1e4ed8;
            case 0x1E4F18u: goto label_1e4f18;
            case 0x1E4F28u: goto label_1e4f28;
            case 0x1E4F4Cu: goto label_1e4f4c;
            case 0x1E4F60u: goto label_1e4f60;
            case 0x1E4F84u: goto label_1e4f84;
            case 0x1E4F98u: goto label_1e4f98;
            case 0x1E4FACu: goto label_1e4fac;
            case 0x1E4FD0u: goto label_1e4fd0;
            case 0x1E4FECu: goto label_1e4fec;
            case 0x1E4FF0u: goto label_1e4ff0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E4B38u;
    // 0x1e4b38: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1e4b38u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1e4b3c: 0xffbe0030  sd          $fp, 0x30($sp)
    ctx->pc = 0x1e4b3cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 30));
    // 0x1e4b40: 0xffbf0038  sd          $ra, 0x38($sp)
    ctx->pc = 0x1e4b40u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x1e4b44: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e4b44u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e4b48: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e4b48u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e4b4c: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e4b4cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e4b50: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e4b50u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e4b54: 0xe0102d  daddu       $v0, $a3, $zero
    ctx->pc = 0x1e4b54u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e4b58: 0xafc80010  sw          $t0, 0x10($fp)
    ctx->pc = 0x1e4b58u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 8));
    // 0x1e4b5c: 0xa7c2000c  sh          $v0, 0xC($fp)
    ctx->pc = 0x1e4b5cu;
    WRITE16(ADD32(GPR_U32(ctx, 30), 12), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e4b60: 0xafc0001c  sw          $zero, 0x1C($fp)
    ctx->pc = 0x1e4b60u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 0));
    // 0x1e4b64: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e4b64u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e4b68: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e4b68u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e4b6c: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E4B6Cu;
    {
        const bool branch_taken_0x1e4b6c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e4b6c) {
            ctx->pc = 0x1E4B94u;
            goto label_1e4b94;
        }
    }
    ctx->pc = 0x1E4B74u;
    // 0x1e4b74: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e4b74u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e4b78: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e4b78u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e4b7c: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e4b7cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e4b80: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e4b80u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e4b84: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e4b84u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e4b88: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e4b88u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e4b8c: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E4B8Cu;
    {
        const bool branch_taken_0x1e4b8c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e4b8c) {
            ctx->pc = 0x1E4BA8u;
            goto label_1e4ba8;
        }
    }
    ctx->pc = 0x1E4B94u;
label_1e4b94:
    // 0x1e4b94: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e4b94u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e4b98: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e4b98u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e4b9c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e4b9cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e4ba0: 0x100000ae  b           . + 4 + (0xAE << 2)
    ctx->pc = 0x1E4BA0u;
    {
        const bool branch_taken_0x1e4ba0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4ba0) {
            ctx->pc = 0x1E4E5Cu;
            goto label_1e4e5c;
        }
    }
    ctx->pc = 0x1E4BA8u;
label_1e4ba8:
    // 0x1e4ba8: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e4ba8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e4bac: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e4bacu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e4bb0: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e4bb0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e4bb4: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e4bb4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e4bb8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e4bb8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e4bbc: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e4bbcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e4bc0: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1e4bc0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1e4bc4: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1e4bc4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e4bc8: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e4bc8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e4bcc: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E4BCCu;
    {
        const bool branch_taken_0x1e4bcc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4bcc) {
            ctx->pc = 0x1E4BE8u;
            goto label_1e4be8;
        }
    }
    ctx->pc = 0x1E4BD4u;
    // 0x1e4bd4: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e4bd4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e4bd8: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e4bd8u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e4bdc: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e4bdcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e4be0: 0x1000009e  b           . + 4 + (0x9E << 2)
    ctx->pc = 0x1E4BE0u;
    {
        const bool branch_taken_0x1e4be0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4be0) {
            ctx->pc = 0x1E4E5Cu;
            goto label_1e4e5c;
        }
    }
    ctx->pc = 0x1E4BE8u;
label_1e4be8:
    // 0x1e4be8: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e4be8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e4bec: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e4becu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e4bf0: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e4bf0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e4bf4: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1e4bf4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e4bf8: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e4bf8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e4bfc: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1e4bfcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1e4c00: 0x8fc4001c  lw          $a0, 0x1C($fp)
    ctx->pc = 0x1e4c00u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e4c04: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1e4c04u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e4c08: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E4C08u;
    SET_GPR_U32(ctx, 31, 0x1E4C10u);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4C10u; }
        if (ctx->pc != 0x1E4C10u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4C10u; }
        if (ctx->pc != 0x1E4C10u) { return; }
    }
    ctx->pc = 0x1E4C10u;
label_1e4c10:
    // 0x1e4c10: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1e4c10u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1e4c14: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e4c14u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e4c18: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E4C18u;
    {
        const bool branch_taken_0x1e4c18 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e4c18) {
            ctx->pc = 0x1E4C34u;
            goto label_1e4c34;
        }
    }
    ctx->pc = 0x1E4C20u;
    // 0x1e4c20: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e4c20u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e4c24: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e4c24u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e4c28: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e4c28u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e4c2c: 0x1000008b  b           . + 4 + (0x8B << 2)
    ctx->pc = 0x1E4C2Cu;
    {
        const bool branch_taken_0x1e4c2c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4c2c) {
            ctx->pc = 0x1E4E5Cu;
            goto label_1e4e5c;
        }
    }
    ctx->pc = 0x1E4C34u;
label_1e4c34:
    // 0x1e4c34: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e4c34u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e4c38: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e4c38u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e4c3c: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1e4c3cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e4c40: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e4c40u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e4c44: 0x97c20008  lhu         $v0, 0x8($fp)
    ctx->pc = 0x1e4c44u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e4c48: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e4c48u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e4c4c: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1e4c4cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1e4c50: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1e4c50u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1e4c54: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e4c54u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e4c58: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1e4c58u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e4c5c: 0xc07cc3c  jal         func_1F30F0
    ctx->pc = 0x1E4C5Cu;
    SET_GPR_U32(ctx, 31, 0x1E4C64u);
    ctx->pc = 0x1F30F0u;
    if (runtime->hasFunction(0x1F30F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F30F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4C64u; }
        if (ctx->pc != 0x1E4C64u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F30F0_0x1f30f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4C64u; }
        if (ctx->pc != 0x1E4C64u) { return; }
    }
    ctx->pc = 0x1E4C64u;
label_1e4c64:
    // 0x1e4c64: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1e4c64u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1e4c68: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e4c68u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e4c6c: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1E4C6Cu;
    {
        const bool branch_taken_0x1e4c6c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e4c6c) {
            ctx->pc = 0x1E4C9Cu;
            goto label_1e4c9c;
        }
    }
    ctx->pc = 0x1E4C74u;
    // 0x1e4c74: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1e4c74u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e4c78: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1e4c78u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1e4c7c: 0x8fc50014  lw          $a1, 0x14($fp)
    ctx->pc = 0x1e4c7cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e4c80: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1E4C80u;
    SET_GPR_U32(ctx, 31, 0x1E4C88u);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4C88u; }
        if (ctx->pc != 0x1E4C88u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4C88u; }
        if (ctx->pc != 0x1E4C88u) { return; }
    }
    ctx->pc = 0x1E4C88u;
label_1e4c88:
    // 0x1e4c88: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e4c88u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e4c8c: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e4c8cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e4c90: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e4c90u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e4c94: 0x10000071  b           . + 4 + (0x71 << 2)
    ctx->pc = 0x1E4C94u;
    {
        const bool branch_taken_0x1e4c94 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4c94) {
            ctx->pc = 0x1E4E5Cu;
            goto label_1e4e5c;
        }
    }
    ctx->pc = 0x1E4C9Cu;
label_1e4c9c:
    // 0x1e4c9c: 0x27c60018  addiu       $a2, $fp, 0x18
    ctx->pc = 0x1e4c9cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 30), 24));
    // 0x1e4ca0: 0x8cc50000  lw          $a1, 0x0($a2)
    ctx->pc = 0x1e4ca0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1e4ca4: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e4ca4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e4ca8: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e4ca8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e4cac: 0x304300ff  andi        $v1, $v0, 0xFF
    ctx->pc = 0x1e4cacu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1e4cb0: 0x31e00  sll         $v1, $v1, 24
    ctx->pc = 0x1e4cb0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 24));
    // 0x1e4cb4: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e4cb4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e4cb8: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e4cb8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e4cbc: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1e4cbcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1e4cc0: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1e4cc0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1e4cc4: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1e4cc4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e4cc8: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e4cc8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e4ccc: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x1e4cccu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e4cd0: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1e4cd0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1e4cd4: 0x821024  and         $v0, $a0, $v0
    ctx->pc = 0x1e4cd4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & GPR_U64(ctx, 2));
    // 0x1e4cd8: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1e4cd8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1e4cdc: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1e4cdcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e4ce0: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e4ce0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e4ce4: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x1e4ce4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e4ce8: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1e4ce8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1e4cec: 0x821024  and         $v0, $a0, $v0
    ctx->pc = 0x1e4cecu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & GPR_U64(ctx, 2));
    // 0x1e4cf0: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1e4cf0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1e4cf4: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1e4cf4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e4cf8: 0xaca30000  sw          $v1, 0x0($a1)
    ctx->pc = 0x1e4cf8u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 3));
    // 0x1e4cfc: 0x24a50004  addiu       $a1, $a1, 0x4
    ctx->pc = 0x1e4cfcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4));
    // 0x1e4d00: 0xacc50000  sw          $a1, 0x0($a2)
    ctx->pc = 0x1e4d00u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 5));
    // 0x1e4d04: 0xafc00020  sw          $zero, 0x20($fp)
    ctx->pc = 0x1e4d04u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 0));
label_1e4d08:
    // 0x1e4d08: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e4d08u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e4d0c: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1e4d0cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e4d10: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e4d10u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e4d14: 0x62102a  slt         $v0, $v1, $v0
    ctx->pc = 0x1e4d14u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1e4d18: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1E4D18u;
    {
        const bool branch_taken_0x1e4d18 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e4d18) {
            ctx->pc = 0x1E4D28u;
            goto label_1e4d28;
        }
    }
    ctx->pc = 0x1E4D20u;
    // 0x1e4d20: 0x10000030  b           . + 4 + (0x30 << 2)
    ctx->pc = 0x1E4D20u;
    {
        const bool branch_taken_0x1e4d20 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4d20) {
            ctx->pc = 0x1E4DE4u;
            goto label_1e4de4;
        }
    }
    ctx->pc = 0x1E4D28u;
label_1e4d28:
    // 0x1e4d28: 0x27c70018  addiu       $a3, $fp, 0x18
    ctx->pc = 0x1e4d28u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 30), 24));
    // 0x1e4d2c: 0x8ce60000  lw          $a2, 0x0($a3)
    ctx->pc = 0x1e4d2cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x1e4d30: 0x8fc40010  lw          $a0, 0x10($fp)
    ctx->pc = 0x1e4d30u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e4d34: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e4d34u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e4d38: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e4d38u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e4d3c: 0x8c820004  lw          $v0, 0x4($a0)
    ctx->pc = 0x1e4d3cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1e4d40: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e4d40u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e4d44: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e4d44u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e4d48: 0x304400ff  andi        $a0, $v0, 0xFF
    ctx->pc = 0x1e4d48u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1e4d4c: 0x42600  sll         $a0, $a0, 24
    ctx->pc = 0x1e4d4cu;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 24));
    // 0x1e4d50: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e4d50u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e4d54: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e4d54u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e4d58: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e4d58u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e4d5c: 0x8ca20004  lw          $v0, 0x4($a1)
    ctx->pc = 0x1e4d5cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 4)));
    // 0x1e4d60: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e4d60u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e4d64: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e4d64u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e4d68: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1e4d68u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1e4d6c: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1e4d6cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1e4d70: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1e4d70u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e4d74: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e4d74u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e4d78: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e4d78u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e4d7c: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e4d7cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e4d80: 0x8ca20004  lw          $v0, 0x4($a1)
    ctx->pc = 0x1e4d80u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 4)));
    // 0x1e4d84: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e4d84u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e4d88: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1e4d88u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e4d8c: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1e4d8cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1e4d90: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e4d90u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e4d94: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1e4d94u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1e4d98: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1e4d98u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e4d9c: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e4d9cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e4da0: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e4da0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e4da4: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e4da4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e4da8: 0x8ca20004  lw          $v0, 0x4($a1)
    ctx->pc = 0x1e4da8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 4)));
    // 0x1e4dac: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e4dacu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e4db0: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1e4db0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e4db4: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1e4db4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1e4db8: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e4db8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e4dbc: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1e4dbcu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1e4dc0: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1e4dc0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e4dc4: 0xacc40000  sw          $a0, 0x0($a2)
    ctx->pc = 0x1e4dc4u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 4));
    // 0x1e4dc8: 0x24c60004  addiu       $a2, $a2, 0x4
    ctx->pc = 0x1e4dc8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4));
    // 0x1e4dcc: 0xace60000  sw          $a2, 0x0($a3)
    ctx->pc = 0x1e4dccu;
    WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 6));
    // 0x1e4dd0: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e4dd0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e4dd4: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1e4dd4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1e4dd8: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1e4dd8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1e4ddc: 0x1000ffca  b           . + 4 + (-0x36 << 2)
    ctx->pc = 0x1E4DDCu;
    {
        const bool branch_taken_0x1e4ddc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4ddc) {
            ctx->pc = 0x1E4D08u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1e4d08;
        }
    }
    ctx->pc = 0x1E4DE4u;
label_1e4de4:
    // 0x1e4de4: 0x8fc40018  lw          $a0, 0x18($fp)
    ctx->pc = 0x1e4de4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e4de8: 0x8fc50004  lw          $a1, 0x4($fp)
    ctx->pc = 0x1e4de8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e4dec: 0x8fc60008  lw          $a2, 0x8($fp)
    ctx->pc = 0x1e4decu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e4df0: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1E4DF0u;
    SET_GPR_U32(ctx, 31, 0x1E4DF8u);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4DF8u; }
        if (ctx->pc != 0x1E4DF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4DF8u; }
        if (ctx->pc != 0x1E4DF8u) { return; }
    }
    ctx->pc = 0x1E4DF8u;
label_1e4df8:
    // 0x1e4df8: 0x97c2000c  lhu         $v0, 0xC($fp)
    ctx->pc = 0x1e4df8u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e4dfc: 0x3442a400  ori         $v0, $v0, 0xA400
    ctx->pc = 0x1e4dfcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)41984);
    // 0x1e4e00: 0x3046ffff  andi        $a2, $v0, 0xFFFF
    ctx->pc = 0x1e4e00u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1e4e04: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e4e04u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e4e08: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e4e08u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e4e0c: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1e4e0cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e4e10: 0x97c30008  lhu         $v1, 0x8($fp)
    ctx->pc = 0x1e4e10u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e4e14: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e4e14u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e4e18: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1e4e18u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1e4e1c: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1e4e1cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1e4e20: 0x8fc4001c  lw          $a0, 0x1C($fp)
    ctx->pc = 0x1e4e20u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e4e24: 0x8fc50014  lw          $a1, 0x14($fp)
    ctx->pc = 0x1e4e24u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e4e28: 0x40382d  daddu       $a3, $v0, $zero
    ctx->pc = 0x1e4e28u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e4e2c: 0x24080010  addiu       $t0, $zero, 0x10
    ctx->pc = 0x1e4e2cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1e4e30: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1e4e30u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e4e34: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E4E34u;
    SET_GPR_U32(ctx, 31, 0x1E4E3Cu);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4E3Cu; }
        if (ctx->pc != 0x1E4E3Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4E3Cu; }
        if (ctx->pc != 0x1E4E3Cu) { return; }
    }
    ctx->pc = 0x1E4E3Cu;
label_1e4e3c:
    // 0x1e4e3c: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E4E3Cu;
    {
        const bool branch_taken_0x1e4e3c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4e3c) {
            ctx->pc = 0x1E4E58u;
            goto label_1e4e58;
        }
    }
    ctx->pc = 0x1E4E44u;
    // 0x1e4e44: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e4e44u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e4e48: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e4e48u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e4e4c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e4e4cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e4e50: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1E4E50u;
    {
        const bool branch_taken_0x1e4e50 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4e50) {
            ctx->pc = 0x1E4E5Cu;
            goto label_1e4e5c;
        }
    }
    ctx->pc = 0x1E4E58u;
label_1e4e58:
    // 0x1e4e58: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1e4e58u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1e4e5c:
    // 0x1e4e5c: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e4e5cu;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e4e60: 0xdfbe0030  ld          $fp, 0x30($sp)
    ctx->pc = 0x1e4e60u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1e4e64: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x1e4e64u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x1e4e68: 0x27bd0040  addiu       $sp, $sp, 0x40
    ctx->pc = 0x1e4e68u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x1e4e6c: 0x3e00008  jr          $ra
    ctx->pc = 0x1E4E6Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E1B3Cu: goto label_1e1b3c;
            case 0x1E1B60u: goto label_1e1b60;
            case 0x1E1B84u: goto label_1e1b84;
            case 0x1E1BA8u: goto label_1e1ba8;
            case 0x1E1BC8u: goto label_1e1bc8;
            case 0x1E1BE4u: goto label_1e1be4;
            case 0x1E1BE8u: goto label_1e1be8;
            case 0x1E1C44u: goto label_1e1c44;
            case 0x1E1C58u: goto label_1e1c58;
            case 0x1E1C7Cu: goto label_1e1c7c;
            case 0x1E1CD8u: goto label_1e1cd8;
            case 0x1E1CECu: goto label_1e1cec;
            case 0x1E1D14u: goto label_1e1d14;
            case 0x1E1D7Cu: goto label_1e1d7c;
            case 0x1E1D90u: goto label_1e1d90;
            case 0x1E1DD0u: goto label_1e1dd0;
            case 0x1E1DE0u: goto label_1e1de0;
            case 0x1E1E04u: goto label_1e1e04;
            case 0x1E1E14u: goto label_1e1e14;
            case 0x1E1E38u: goto label_1e1e38;
            case 0x1E1E4Cu: goto label_1e1e4c;
            case 0x1E1E5Cu: goto label_1e1e5c;
            case 0x1E1E84u: goto label_1e1e84;
            case 0x1E1EA0u: goto label_1e1ea0;
            case 0x1E1EB4u: goto label_1e1eb4;
            case 0x1E1ED0u: goto label_1e1ed0;
            case 0x1E1F48u: goto label_1e1f48;
            case 0x1E1F5Cu: goto label_1e1f5c;
            case 0x1E1F9Cu: goto label_1e1f9c;
            case 0x1E1FACu: goto label_1e1fac;
            case 0x1E1FD0u: goto label_1e1fd0;
            case 0x1E1FE0u: goto label_1e1fe0;
            case 0x1E2004u: goto label_1e2004;
            case 0x1E2018u: goto label_1e2018;
            case 0x1E202Cu: goto label_1e202c;
            case 0x1E2064u: goto label_1e2064;
            case 0x1E206Cu: goto label_1e206c;
            case 0x1E2088u: goto label_1e2088;
            case 0x1E20A0u: goto label_1e20a0;
            case 0x1E20D4u: goto label_1e20d4;
            case 0x1E20F8u: goto label_1e20f8;
            case 0x1E210Cu: goto label_1e210c;
            case 0x1E2128u: goto label_1e2128;
            case 0x1E2190u: goto label_1e2190;
            case 0x1E21A4u: goto label_1e21a4;
            case 0x1E21E4u: goto label_1e21e4;
            case 0x1E21F4u: goto label_1e21f4;
            case 0x1E2218u: goto label_1e2218;
            case 0x1E2228u: goto label_1e2228;
            case 0x1E224Cu: goto label_1e224c;
            case 0x1E2260u: goto label_1e2260;
            case 0x1E22D4u: goto label_1e22d4;
            case 0x1E22F0u: goto label_1e22f0;
            case 0x1E2304u: goto label_1e2304;
            case 0x1E2320u: goto label_1e2320;
            case 0x1E23A0u: goto label_1e23a0;
            case 0x1E23B4u: goto label_1e23b4;
            case 0x1E23F4u: goto label_1e23f4;
            case 0x1E2404u: goto label_1e2404;
            case 0x1E2428u: goto label_1e2428;
            case 0x1E2438u: goto label_1e2438;
            case 0x1E245Cu: goto label_1e245c;
            case 0x1E2470u: goto label_1e2470;
            case 0x1E2480u: goto label_1e2480;
            case 0x1E24F8u: goto label_1e24f8;
            case 0x1E2500u: goto label_1e2500;
            case 0x1E2508u: goto label_1e2508;
            case 0x1E25D0u: goto label_1e25d0;
            case 0x1E25ECu: goto label_1e25ec;
            case 0x1E2600u: goto label_1e2600;
            case 0x1E261Cu: goto label_1e261c;
            case 0x1E2684u: goto label_1e2684;
            case 0x1E2698u: goto label_1e2698;
            case 0x1E26D8u: goto label_1e26d8;
            case 0x1E26E8u: goto label_1e26e8;
            case 0x1E270Cu: goto label_1e270c;
            case 0x1E271Cu: goto label_1e271c;
            case 0x1E2740u: goto label_1e2740;
            case 0x1E2754u: goto label_1e2754;
            case 0x1E27C8u: goto label_1e27c8;
            case 0x1E27E4u: goto label_1e27e4;
            case 0x1E27F8u: goto label_1e27f8;
            case 0x1E2814u: goto label_1e2814;
            case 0x1E287Cu: goto label_1e287c;
            case 0x1E2890u: goto label_1e2890;
            case 0x1E28D0u: goto label_1e28d0;
            case 0x1E28E0u: goto label_1e28e0;
            case 0x1E2904u: goto label_1e2904;
            case 0x1E2914u: goto label_1e2914;
            case 0x1E2938u: goto label_1e2938;
            case 0x1E294Cu: goto label_1e294c;
            case 0x1E29C0u: goto label_1e29c0;
            case 0x1E29DCu: goto label_1e29dc;
            case 0x1E29F0u: goto label_1e29f0;
            case 0x1E2A0Cu: goto label_1e2a0c;
            case 0x1E2A78u: goto label_1e2a78;
            case 0x1E2A8Cu: goto label_1e2a8c;
            case 0x1E2ACCu: goto label_1e2acc;
            case 0x1E2ADCu: goto label_1e2adc;
            case 0x1E2B00u: goto label_1e2b00;
            case 0x1E2B10u: goto label_1e2b10;
            case 0x1E2B34u: goto label_1e2b34;
            case 0x1E2B48u: goto label_1e2b48;
            case 0x1E2B54u: goto label_1e2b54;
            case 0x1E2B90u: goto label_1e2b90;
            case 0x1E2B98u: goto label_1e2b98;
            case 0x1E2BC0u: goto label_1e2bc0;
            case 0x1E2BE4u: goto label_1e2be4;
            case 0x1E2BF8u: goto label_1e2bf8;
            case 0x1E2C14u: goto label_1e2c14;
            case 0x1E2C84u: goto label_1e2c84;
            case 0x1E2C98u: goto label_1e2c98;
            case 0x1E2CD8u: goto label_1e2cd8;
            case 0x1E2CE8u: goto label_1e2ce8;
            case 0x1E2D0Cu: goto label_1e2d0c;
            case 0x1E2D1Cu: goto label_1e2d1c;
            case 0x1E2D40u: goto label_1e2d40;
            case 0x1E2D54u: goto label_1e2d54;
            case 0x1E2E10u: goto label_1e2e10;
            case 0x1E2E18u: goto label_1e2e18;
            case 0x1E2E20u: goto label_1e2e20;
            case 0x1E2E48u: goto label_1e2e48;
            case 0x1E2E64u: goto label_1e2e64;
            case 0x1E2E78u: goto label_1e2e78;
            case 0x1E2E94u: goto label_1e2e94;
            case 0x1E2EF8u: goto label_1e2ef8;
            case 0x1E2F0Cu: goto label_1e2f0c;
            case 0x1E2F4Cu: goto label_1e2f4c;
            case 0x1E2F5Cu: goto label_1e2f5c;
            case 0x1E2F80u: goto label_1e2f80;
            case 0x1E2FA8u: goto label_1e2fa8;
            case 0x1E2FC4u: goto label_1e2fc4;
            case 0x1E2FD8u: goto label_1e2fd8;
            case 0x1E2FF4u: goto label_1e2ff4;
            case 0x1E3058u: goto label_1e3058;
            case 0x1E306Cu: goto label_1e306c;
            case 0x1E30ACu: goto label_1e30ac;
            case 0x1E30BCu: goto label_1e30bc;
            case 0x1E30E0u: goto label_1e30e0;
            case 0x1E3108u: goto label_1e3108;
            case 0x1E3124u: goto label_1e3124;
            case 0x1E3138u: goto label_1e3138;
            case 0x1E3154u: goto label_1e3154;
            case 0x1E31CCu: goto label_1e31cc;
            case 0x1E31E0u: goto label_1e31e0;
            case 0x1E3220u: goto label_1e3220;
            case 0x1E3238u: goto label_1e3238;
            case 0x1E325Cu: goto label_1e325c;
            case 0x1E3278u: goto label_1e3278;
            case 0x1E329Cu: goto label_1e329c;
            case 0x1E32B0u: goto label_1e32b0;
            case 0x1E3318u: goto label_1e3318;
            case 0x1E3388u: goto label_1e3388;
            case 0x1E33C4u: goto label_1e33c4;
            case 0x1E33E0u: goto label_1e33e0;
            case 0x1E33F4u: goto label_1e33f4;
            case 0x1E3410u: goto label_1e3410;
            case 0x1E347Cu: goto label_1e347c;
            case 0x1E3490u: goto label_1e3490;
            case 0x1E34D0u: goto label_1e34d0;
            case 0x1E34E0u: goto label_1e34e0;
            case 0x1E3504u: goto label_1e3504;
            case 0x1E3514u: goto label_1e3514;
            case 0x1E3538u: goto label_1e3538;
            case 0x1E354Cu: goto label_1e354c;
            case 0x1E360Cu: goto label_1e360c;
            case 0x1E3628u: goto label_1e3628;
            case 0x1E363Cu: goto label_1e363c;
            case 0x1E3658u: goto label_1e3658;
            case 0x1E36C4u: goto label_1e36c4;
            case 0x1E36D8u: goto label_1e36d8;
            case 0x1E3718u: goto label_1e3718;
            case 0x1E3728u: goto label_1e3728;
            case 0x1E374Cu: goto label_1e374c;
            case 0x1E375Cu: goto label_1e375c;
            case 0x1E3780u: goto label_1e3780;
            case 0x1E3794u: goto label_1e3794;
            case 0x1E3854u: goto label_1e3854;
            case 0x1E3870u: goto label_1e3870;
            case 0x1E3884u: goto label_1e3884;
            case 0x1E38A0u: goto label_1e38a0;
            case 0x1E3908u: goto label_1e3908;
            case 0x1E391Cu: goto label_1e391c;
            case 0x1E395Cu: goto label_1e395c;
            case 0x1E396Cu: goto label_1e396c;
            case 0x1E3990u: goto label_1e3990;
            case 0x1E39A0u: goto label_1e39a0;
            case 0x1E39C4u: goto label_1e39c4;
            case 0x1E39D8u: goto label_1e39d8;
            case 0x1E3A44u: goto label_1e3a44;
            case 0x1E3A60u: goto label_1e3a60;
            case 0x1E3A74u: goto label_1e3a74;
            case 0x1E3A78u: goto label_1e3a78;
            case 0x1E3ADCu: goto label_1e3adc;
            case 0x1E3AF0u: goto label_1e3af0;
            case 0x1E3B30u: goto label_1e3b30;
            case 0x1E3B40u: goto label_1e3b40;
            case 0x1E3B64u: goto label_1e3b64;
            case 0x1E3B84u: goto label_1e3b84;
            case 0x1E3BA0u: goto label_1e3ba0;
            case 0x1E3BB4u: goto label_1e3bb4;
            case 0x1E3BB8u: goto label_1e3bb8;
            case 0x1E3C1Cu: goto label_1e3c1c;
            case 0x1E3C30u: goto label_1e3c30;
            case 0x1E3C70u: goto label_1e3c70;
            case 0x1E3C80u: goto label_1e3c80;
            case 0x1E3CA4u: goto label_1e3ca4;
            case 0x1E3CC4u: goto label_1e3cc4;
            case 0x1E3CE8u: goto label_1e3ce8;
            case 0x1E3CFCu: goto label_1e3cfc;
            case 0x1E3D00u: goto label_1e3d00;
            case 0x1E3D68u: goto label_1e3d68;
            case 0x1E3D7Cu: goto label_1e3d7c;
            case 0x1E3DBCu: goto label_1e3dbc;
            case 0x1E3DCCu: goto label_1e3dcc;
            case 0x1E3DF0u: goto label_1e3df0;
            case 0x1E3E00u: goto label_1e3e00;
            case 0x1E3E24u: goto label_1e3e24;
            case 0x1E3E38u: goto label_1e3e38;
            case 0x1E3EA4u: goto label_1e3ea4;
            case 0x1E3EC0u: goto label_1e3ec0;
            case 0x1E3ED4u: goto label_1e3ed4;
            case 0x1E3ED8u: goto label_1e3ed8;
            case 0x1E3F40u: goto label_1e3f40;
            case 0x1E3F54u: goto label_1e3f54;
            case 0x1E3F94u: goto label_1e3f94;
            case 0x1E3FA4u: goto label_1e3fa4;
            case 0x1E3FC8u: goto label_1e3fc8;
            case 0x1E3FD8u: goto label_1e3fd8;
            case 0x1E3FFCu: goto label_1e3ffc;
            case 0x1E4010u: goto label_1e4010;
            case 0x1E407Cu: goto label_1e407c;
            case 0x1E4098u: goto label_1e4098;
            case 0x1E40ACu: goto label_1e40ac;
            case 0x1E40B0u: goto label_1e40b0;
            case 0x1E4118u: goto label_1e4118;
            case 0x1E412Cu: goto label_1e412c;
            case 0x1E416Cu: goto label_1e416c;
            case 0x1E417Cu: goto label_1e417c;
            case 0x1E41A0u: goto label_1e41a0;
            case 0x1E41B0u: goto label_1e41b0;
            case 0x1E41D4u: goto label_1e41d4;
            case 0x1E41E8u: goto label_1e41e8;
            case 0x1E4254u: goto label_1e4254;
            case 0x1E4270u: goto label_1e4270;
            case 0x1E4284u: goto label_1e4284;
            case 0x1E4288u: goto label_1e4288;
            case 0x1E42F0u: goto label_1e42f0;
            case 0x1E4304u: goto label_1e4304;
            case 0x1E4344u: goto label_1e4344;
            case 0x1E4358u: goto label_1e4358;
            case 0x1E437Cu: goto label_1e437c;
            case 0x1E4394u: goto label_1e4394;
            case 0x1E43B8u: goto label_1e43b8;
            case 0x1E43CCu: goto label_1e43cc;
            case 0x1E43E4u: goto label_1e43e4;
            case 0x1E4414u: goto label_1e4414;
            case 0x1E4430u: goto label_1e4430;
            case 0x1E4444u: goto label_1e4444;
            case 0x1E4460u: goto label_1e4460;
            case 0x1E44C8u: goto label_1e44c8;
            case 0x1E44DCu: goto label_1e44dc;
            case 0x1E451Cu: goto label_1e451c;
            case 0x1E452Cu: goto label_1e452c;
            case 0x1E4550u: goto label_1e4550;
            case 0x1E4560u: goto label_1e4560;
            case 0x1E4584u: goto label_1e4584;
            case 0x1E4598u: goto label_1e4598;
            case 0x1E460Cu: goto label_1e460c;
            case 0x1E4628u: goto label_1e4628;
            case 0x1E463Cu: goto label_1e463c;
            case 0x1E4658u: goto label_1e4658;
            case 0x1E46C8u: goto label_1e46c8;
            case 0x1E46DCu: goto label_1e46dc;
            case 0x1E471Cu: goto label_1e471c;
            case 0x1E472Cu: goto label_1e472c;
            case 0x1E4750u: goto label_1e4750;
            case 0x1E4764u: goto label_1e4764;
            case 0x1E4788u: goto label_1e4788;
            case 0x1E479Cu: goto label_1e479c;
            case 0x1E47B0u: goto label_1e47b0;
            case 0x1E47E0u: goto label_1e47e0;
            case 0x1E47FCu: goto label_1e47fc;
            case 0x1E4800u: goto label_1e4800;
            case 0x1E48A0u: goto label_1e48a0;
            case 0x1E48B4u: goto label_1e48b4;
            case 0x1E48F4u: goto label_1e48f4;
            case 0x1E4918u: goto label_1e4918;
            case 0x1E493Cu: goto label_1e493c;
            case 0x1E4974u: goto label_1e4974;
            case 0x1E4998u: goto label_1e4998;
            case 0x1E49ACu: goto label_1e49ac;
            case 0x1E4A08u: goto label_1e4a08;
            case 0x1E4A24u: goto label_1e4a24;
            case 0x1E4AACu: goto label_1e4aac;
            case 0x1E4AC0u: goto label_1e4ac0;
            case 0x1E4B00u: goto label_1e4b00;
            case 0x1E4B1Cu: goto label_1e4b1c;
            case 0x1E4B20u: goto label_1e4b20;
            case 0x1E4B94u: goto label_1e4b94;
            case 0x1E4BA8u: goto label_1e4ba8;
            case 0x1E4BE8u: goto label_1e4be8;
            case 0x1E4C10u: goto label_1e4c10;
            case 0x1E4C34u: goto label_1e4c34;
            case 0x1E4C64u: goto label_1e4c64;
            case 0x1E4C88u: goto label_1e4c88;
            case 0x1E4C9Cu: goto label_1e4c9c;
            case 0x1E4D08u: goto label_1e4d08;
            case 0x1E4D28u: goto label_1e4d28;
            case 0x1E4DE4u: goto label_1e4de4;
            case 0x1E4DF8u: goto label_1e4df8;
            case 0x1E4E3Cu: goto label_1e4e3c;
            case 0x1E4E58u: goto label_1e4e58;
            case 0x1E4E5Cu: goto label_1e4e5c;
            case 0x1E4EC4u: goto label_1e4ec4;
            case 0x1E4ED8u: goto label_1e4ed8;
            case 0x1E4F18u: goto label_1e4f18;
            case 0x1E4F28u: goto label_1e4f28;
            case 0x1E4F4Cu: goto label_1e4f4c;
            case 0x1E4F60u: goto label_1e4f60;
            case 0x1E4F84u: goto label_1e4f84;
            case 0x1E4F98u: goto label_1e4f98;
            case 0x1E4FACu: goto label_1e4fac;
            case 0x1E4FD0u: goto label_1e4fd0;
            case 0x1E4FECu: goto label_1e4fec;
            case 0x1E4FF0u: goto label_1e4ff0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E4E74u;
    // 0x1e4e74: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1e4e74u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1e4e78: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1e4e78u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1e4e7c: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1e4e7cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1e4e80: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e4e80u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e4e84: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e4e84u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e4e88: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e4e88u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e4e8c: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e4e8cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e4e90: 0xafc00014  sw          $zero, 0x14($fp)
    ctx->pc = 0x1e4e90u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 0));
    // 0x1e4e94: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e4e94u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e4e98: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e4e98u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e4e9c: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E4E9Cu;
    {
        const bool branch_taken_0x1e4e9c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e4e9c) {
            ctx->pc = 0x1E4EC4u;
            goto label_1e4ec4;
        }
    }
    ctx->pc = 0x1E4EA4u;
    // 0x1e4ea4: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e4ea4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e4ea8: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e4ea8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e4eac: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e4eacu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e4eb0: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e4eb0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e4eb4: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e4eb4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e4eb8: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e4eb8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e4ebc: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E4EBCu;
    {
        const bool branch_taken_0x1e4ebc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e4ebc) {
            ctx->pc = 0x1E4ED8u;
            goto label_1e4ed8;
        }
    }
    ctx->pc = 0x1E4EC4u;
label_1e4ec4:
    // 0x1e4ec4: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e4ec4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e4ec8: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e4ec8u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e4ecc: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e4eccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e4ed0: 0x10000047  b           . + 4 + (0x47 << 2)
    ctx->pc = 0x1E4ED0u;
    {
        const bool branch_taken_0x1e4ed0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4ed0) {
            ctx->pc = 0x1E4FF0u;
            goto label_1e4ff0;
        }
    }
    ctx->pc = 0x1E4ED8u;
label_1e4ed8:
    // 0x1e4ed8: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e4ed8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e4edc: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e4edcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e4ee0: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e4ee0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e4ee4: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e4ee4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e4ee8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e4ee8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e4eec: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e4eecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e4ef0: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1e4ef0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1e4ef4: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e4ef4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e4ef8: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e4ef8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e4efc: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E4EFCu;
    {
        const bool branch_taken_0x1e4efc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4efc) {
            ctx->pc = 0x1E4F18u;
            goto label_1e4f18;
        }
    }
    ctx->pc = 0x1E4F04u;
    // 0x1e4f04: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e4f04u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e4f08: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e4f08u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e4f0c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e4f0cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e4f10: 0x10000037  b           . + 4 + (0x37 << 2)
    ctx->pc = 0x1E4F10u;
    {
        const bool branch_taken_0x1e4f10 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4f10) {
            ctx->pc = 0x1E4FF0u;
            goto label_1e4ff0;
        }
    }
    ctx->pc = 0x1E4F18u;
label_1e4f18:
    // 0x1e4f18: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e4f18u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e4f1c: 0x8fc50008  lw          $a1, 0x8($fp)
    ctx->pc = 0x1e4f1cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e4f20: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E4F20u;
    SET_GPR_U32(ctx, 31, 0x1E4F28u);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4F28u; }
        if (ctx->pc != 0x1E4F28u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4F28u; }
        if (ctx->pc != 0x1E4F28u) { return; }
    }
    ctx->pc = 0x1E4F28u;
label_1e4f28:
    // 0x1e4f28: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1e4f28u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1e4f2c: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e4f2cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e4f30: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E4F30u;
    {
        const bool branch_taken_0x1e4f30 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e4f30) {
            ctx->pc = 0x1E4F4Cu;
            goto label_1e4f4c;
        }
    }
    ctx->pc = 0x1E4F38u;
    // 0x1e4f38: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e4f38u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e4f3c: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e4f3cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e4f40: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e4f40u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e4f44: 0x1000002a  b           . + 4 + (0x2A << 2)
    ctx->pc = 0x1E4F44u;
    {
        const bool branch_taken_0x1e4f44 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4f44) {
            ctx->pc = 0x1E4FF0u;
            goto label_1e4ff0;
        }
    }
    ctx->pc = 0x1E4F4Cu;
label_1e4f4c:
    // 0x1e4f4c: 0x97c20008  lhu         $v0, 0x8($fp)
    ctx->pc = 0x1e4f4cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e4f50: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1e4f50u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e4f54: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1e4f54u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e4f58: 0xc07cc3c  jal         func_1F30F0
    ctx->pc = 0x1E4F58u;
    SET_GPR_U32(ctx, 31, 0x1E4F60u);
    ctx->pc = 0x1F30F0u;
    if (runtime->hasFunction(0x1F30F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F30F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4F60u; }
        if (ctx->pc != 0x1E4F60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F30F0_0x1f30f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4F60u; }
        if (ctx->pc != 0x1E4F60u) { return; }
    }
    ctx->pc = 0x1E4F60u;
label_1e4f60:
    // 0x1e4f60: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1e4f60u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1e4f64: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e4f64u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e4f68: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1E4F68u;
    {
        const bool branch_taken_0x1e4f68 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e4f68) {
            ctx->pc = 0x1E4F98u;
            goto label_1e4f98;
        }
    }
    ctx->pc = 0x1E4F70u;
    // 0x1e4f70: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e4f70u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e4f74: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1e4f74u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1e4f78: 0x8fc5000c  lw          $a1, 0xC($fp)
    ctx->pc = 0x1e4f78u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e4f7c: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1E4F7Cu;
    SET_GPR_U32(ctx, 31, 0x1E4F84u);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4F84u; }
        if (ctx->pc != 0x1E4F84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4F84u; }
        if (ctx->pc != 0x1E4F84u) { return; }
    }
    ctx->pc = 0x1E4F84u;
label_1e4f84:
    // 0x1e4f84: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e4f84u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e4f88: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e4f88u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e4f8c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e4f8cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e4f90: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x1E4F90u;
    {
        const bool branch_taken_0x1e4f90 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4f90) {
            ctx->pc = 0x1E4FF0u;
            goto label_1e4ff0;
        }
    }
    ctx->pc = 0x1E4F98u;
label_1e4f98:
    // 0x1e4f98: 0x8fc40010  lw          $a0, 0x10($fp)
    ctx->pc = 0x1e4f98u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e4f9c: 0x8fc50004  lw          $a1, 0x4($fp)
    ctx->pc = 0x1e4f9cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e4fa0: 0x8fc60008  lw          $a2, 0x8($fp)
    ctx->pc = 0x1e4fa0u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e4fa4: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1E4FA4u;
    SET_GPR_U32(ctx, 31, 0x1E4FACu);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4FACu; }
        if (ctx->pc != 0x1E4FACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4FACu; }
        if (ctx->pc != 0x1E4FACu) { return; }
    }
    ctx->pc = 0x1E4FACu;
label_1e4fac:
    // 0x1e4fac: 0x97c20008  lhu         $v0, 0x8($fp)
    ctx->pc = 0x1e4facu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e4fb0: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e4fb0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e4fb4: 0x8fc5000c  lw          $a1, 0xC($fp)
    ctx->pc = 0x1e4fb4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e4fb8: 0x24062000  addiu       $a2, $zero, 0x2000
    ctx->pc = 0x1e4fb8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 8192));
    // 0x1e4fbc: 0x40382d  daddu       $a3, $v0, $zero
    ctx->pc = 0x1e4fbcu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e4fc0: 0x24080032  addiu       $t0, $zero, 0x32
    ctx->pc = 0x1e4fc0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 50));
    // 0x1e4fc4: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1e4fc4u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e4fc8: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E4FC8u;
    SET_GPR_U32(ctx, 31, 0x1E4FD0u);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4FD0u; }
        if (ctx->pc != 0x1E4FD0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4FD0u; }
        if (ctx->pc != 0x1E4FD0u) { return; }
    }
    ctx->pc = 0x1E4FD0u;
label_1e4fd0:
    // 0x1e4fd0: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E4FD0u;
    {
        const bool branch_taken_0x1e4fd0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4fd0) {
            ctx->pc = 0x1E4FECu;
            goto label_1e4fec;
        }
    }
    ctx->pc = 0x1E4FD8u;
    // 0x1e4fd8: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e4fd8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e4fdc: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e4fdcu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e4fe0: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e4fe0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e4fe4: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1E4FE4u;
    {
        const bool branch_taken_0x1e4fe4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4fe4) {
            ctx->pc = 0x1E4FF0u;
            goto label_1e4ff0;
        }
    }
    ctx->pc = 0x1E4FECu;
label_1e4fec:
    // 0x1e4fec: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1e4fecu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1e4ff0:
    // 0x1e4ff0: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e4ff0u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e4ff4: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1e4ff4u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1e4ff8: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1e4ff8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1e4ffc: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1e4ffcu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1e5000: 0x3e00008  jr          $ra
    ctx->pc = 0x1E5000u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E1B3Cu: goto label_1e1b3c;
            case 0x1E1B60u: goto label_1e1b60;
            case 0x1E1B84u: goto label_1e1b84;
            case 0x1E1BA8u: goto label_1e1ba8;
            case 0x1E1BC8u: goto label_1e1bc8;
            case 0x1E1BE4u: goto label_1e1be4;
            case 0x1E1BE8u: goto label_1e1be8;
            case 0x1E1C44u: goto label_1e1c44;
            case 0x1E1C58u: goto label_1e1c58;
            case 0x1E1C7Cu: goto label_1e1c7c;
            case 0x1E1CD8u: goto label_1e1cd8;
            case 0x1E1CECu: goto label_1e1cec;
            case 0x1E1D14u: goto label_1e1d14;
            case 0x1E1D7Cu: goto label_1e1d7c;
            case 0x1E1D90u: goto label_1e1d90;
            case 0x1E1DD0u: goto label_1e1dd0;
            case 0x1E1DE0u: goto label_1e1de0;
            case 0x1E1E04u: goto label_1e1e04;
            case 0x1E1E14u: goto label_1e1e14;
            case 0x1E1E38u: goto label_1e1e38;
            case 0x1E1E4Cu: goto label_1e1e4c;
            case 0x1E1E5Cu: goto label_1e1e5c;
            case 0x1E1E84u: goto label_1e1e84;
            case 0x1E1EA0u: goto label_1e1ea0;
            case 0x1E1EB4u: goto label_1e1eb4;
            case 0x1E1ED0u: goto label_1e1ed0;
            case 0x1E1F48u: goto label_1e1f48;
            case 0x1E1F5Cu: goto label_1e1f5c;
            case 0x1E1F9Cu: goto label_1e1f9c;
            case 0x1E1FACu: goto label_1e1fac;
            case 0x1E1FD0u: goto label_1e1fd0;
            case 0x1E1FE0u: goto label_1e1fe0;
            case 0x1E2004u: goto label_1e2004;
            case 0x1E2018u: goto label_1e2018;
            case 0x1E202Cu: goto label_1e202c;
            case 0x1E2064u: goto label_1e2064;
            case 0x1E206Cu: goto label_1e206c;
            case 0x1E2088u: goto label_1e2088;
            case 0x1E20A0u: goto label_1e20a0;
            case 0x1E20D4u: goto label_1e20d4;
            case 0x1E20F8u: goto label_1e20f8;
            case 0x1E210Cu: goto label_1e210c;
            case 0x1E2128u: goto label_1e2128;
            case 0x1E2190u: goto label_1e2190;
            case 0x1E21A4u: goto label_1e21a4;
            case 0x1E21E4u: goto label_1e21e4;
            case 0x1E21F4u: goto label_1e21f4;
            case 0x1E2218u: goto label_1e2218;
            case 0x1E2228u: goto label_1e2228;
            case 0x1E224Cu: goto label_1e224c;
            case 0x1E2260u: goto label_1e2260;
            case 0x1E22D4u: goto label_1e22d4;
            case 0x1E22F0u: goto label_1e22f0;
            case 0x1E2304u: goto label_1e2304;
            case 0x1E2320u: goto label_1e2320;
            case 0x1E23A0u: goto label_1e23a0;
            case 0x1E23B4u: goto label_1e23b4;
            case 0x1E23F4u: goto label_1e23f4;
            case 0x1E2404u: goto label_1e2404;
            case 0x1E2428u: goto label_1e2428;
            case 0x1E2438u: goto label_1e2438;
            case 0x1E245Cu: goto label_1e245c;
            case 0x1E2470u: goto label_1e2470;
            case 0x1E2480u: goto label_1e2480;
            case 0x1E24F8u: goto label_1e24f8;
            case 0x1E2500u: goto label_1e2500;
            case 0x1E2508u: goto label_1e2508;
            case 0x1E25D0u: goto label_1e25d0;
            case 0x1E25ECu: goto label_1e25ec;
            case 0x1E2600u: goto label_1e2600;
            case 0x1E261Cu: goto label_1e261c;
            case 0x1E2684u: goto label_1e2684;
            case 0x1E2698u: goto label_1e2698;
            case 0x1E26D8u: goto label_1e26d8;
            case 0x1E26E8u: goto label_1e26e8;
            case 0x1E270Cu: goto label_1e270c;
            case 0x1E271Cu: goto label_1e271c;
            case 0x1E2740u: goto label_1e2740;
            case 0x1E2754u: goto label_1e2754;
            case 0x1E27C8u: goto label_1e27c8;
            case 0x1E27E4u: goto label_1e27e4;
            case 0x1E27F8u: goto label_1e27f8;
            case 0x1E2814u: goto label_1e2814;
            case 0x1E287Cu: goto label_1e287c;
            case 0x1E2890u: goto label_1e2890;
            case 0x1E28D0u: goto label_1e28d0;
            case 0x1E28E0u: goto label_1e28e0;
            case 0x1E2904u: goto label_1e2904;
            case 0x1E2914u: goto label_1e2914;
            case 0x1E2938u: goto label_1e2938;
            case 0x1E294Cu: goto label_1e294c;
            case 0x1E29C0u: goto label_1e29c0;
            case 0x1E29DCu: goto label_1e29dc;
            case 0x1E29F0u: goto label_1e29f0;
            case 0x1E2A0Cu: goto label_1e2a0c;
            case 0x1E2A78u: goto label_1e2a78;
            case 0x1E2A8Cu: goto label_1e2a8c;
            case 0x1E2ACCu: goto label_1e2acc;
            case 0x1E2ADCu: goto label_1e2adc;
            case 0x1E2B00u: goto label_1e2b00;
            case 0x1E2B10u: goto label_1e2b10;
            case 0x1E2B34u: goto label_1e2b34;
            case 0x1E2B48u: goto label_1e2b48;
            case 0x1E2B54u: goto label_1e2b54;
            case 0x1E2B90u: goto label_1e2b90;
            case 0x1E2B98u: goto label_1e2b98;
            case 0x1E2BC0u: goto label_1e2bc0;
            case 0x1E2BE4u: goto label_1e2be4;
            case 0x1E2BF8u: goto label_1e2bf8;
            case 0x1E2C14u: goto label_1e2c14;
            case 0x1E2C84u: goto label_1e2c84;
            case 0x1E2C98u: goto label_1e2c98;
            case 0x1E2CD8u: goto label_1e2cd8;
            case 0x1E2CE8u: goto label_1e2ce8;
            case 0x1E2D0Cu: goto label_1e2d0c;
            case 0x1E2D1Cu: goto label_1e2d1c;
            case 0x1E2D40u: goto label_1e2d40;
            case 0x1E2D54u: goto label_1e2d54;
            case 0x1E2E10u: goto label_1e2e10;
            case 0x1E2E18u: goto label_1e2e18;
            case 0x1E2E20u: goto label_1e2e20;
            case 0x1E2E48u: goto label_1e2e48;
            case 0x1E2E64u: goto label_1e2e64;
            case 0x1E2E78u: goto label_1e2e78;
            case 0x1E2E94u: goto label_1e2e94;
            case 0x1E2EF8u: goto label_1e2ef8;
            case 0x1E2F0Cu: goto label_1e2f0c;
            case 0x1E2F4Cu: goto label_1e2f4c;
            case 0x1E2F5Cu: goto label_1e2f5c;
            case 0x1E2F80u: goto label_1e2f80;
            case 0x1E2FA8u: goto label_1e2fa8;
            case 0x1E2FC4u: goto label_1e2fc4;
            case 0x1E2FD8u: goto label_1e2fd8;
            case 0x1E2FF4u: goto label_1e2ff4;
            case 0x1E3058u: goto label_1e3058;
            case 0x1E306Cu: goto label_1e306c;
            case 0x1E30ACu: goto label_1e30ac;
            case 0x1E30BCu: goto label_1e30bc;
            case 0x1E30E0u: goto label_1e30e0;
            case 0x1E3108u: goto label_1e3108;
            case 0x1E3124u: goto label_1e3124;
            case 0x1E3138u: goto label_1e3138;
            case 0x1E3154u: goto label_1e3154;
            case 0x1E31CCu: goto label_1e31cc;
            case 0x1E31E0u: goto label_1e31e0;
            case 0x1E3220u: goto label_1e3220;
            case 0x1E3238u: goto label_1e3238;
            case 0x1E325Cu: goto label_1e325c;
            case 0x1E3278u: goto label_1e3278;
            case 0x1E329Cu: goto label_1e329c;
            case 0x1E32B0u: goto label_1e32b0;
            case 0x1E3318u: goto label_1e3318;
            case 0x1E3388u: goto label_1e3388;
            case 0x1E33C4u: goto label_1e33c4;
            case 0x1E33E0u: goto label_1e33e0;
            case 0x1E33F4u: goto label_1e33f4;
            case 0x1E3410u: goto label_1e3410;
            case 0x1E347Cu: goto label_1e347c;
            case 0x1E3490u: goto label_1e3490;
            case 0x1E34D0u: goto label_1e34d0;
            case 0x1E34E0u: goto label_1e34e0;
            case 0x1E3504u: goto label_1e3504;
            case 0x1E3514u: goto label_1e3514;
            case 0x1E3538u: goto label_1e3538;
            case 0x1E354Cu: goto label_1e354c;
            case 0x1E360Cu: goto label_1e360c;
            case 0x1E3628u: goto label_1e3628;
            case 0x1E363Cu: goto label_1e363c;
            case 0x1E3658u: goto label_1e3658;
            case 0x1E36C4u: goto label_1e36c4;
            case 0x1E36D8u: goto label_1e36d8;
            case 0x1E3718u: goto label_1e3718;
            case 0x1E3728u: goto label_1e3728;
            case 0x1E374Cu: goto label_1e374c;
            case 0x1E375Cu: goto label_1e375c;
            case 0x1E3780u: goto label_1e3780;
            case 0x1E3794u: goto label_1e3794;
            case 0x1E3854u: goto label_1e3854;
            case 0x1E3870u: goto label_1e3870;
            case 0x1E3884u: goto label_1e3884;
            case 0x1E38A0u: goto label_1e38a0;
            case 0x1E3908u: goto label_1e3908;
            case 0x1E391Cu: goto label_1e391c;
            case 0x1E395Cu: goto label_1e395c;
            case 0x1E396Cu: goto label_1e396c;
            case 0x1E3990u: goto label_1e3990;
            case 0x1E39A0u: goto label_1e39a0;
            case 0x1E39C4u: goto label_1e39c4;
            case 0x1E39D8u: goto label_1e39d8;
            case 0x1E3A44u: goto label_1e3a44;
            case 0x1E3A60u: goto label_1e3a60;
            case 0x1E3A74u: goto label_1e3a74;
            case 0x1E3A78u: goto label_1e3a78;
            case 0x1E3ADCu: goto label_1e3adc;
            case 0x1E3AF0u: goto label_1e3af0;
            case 0x1E3B30u: goto label_1e3b30;
            case 0x1E3B40u: goto label_1e3b40;
            case 0x1E3B64u: goto label_1e3b64;
            case 0x1E3B84u: goto label_1e3b84;
            case 0x1E3BA0u: goto label_1e3ba0;
            case 0x1E3BB4u: goto label_1e3bb4;
            case 0x1E3BB8u: goto label_1e3bb8;
            case 0x1E3C1Cu: goto label_1e3c1c;
            case 0x1E3C30u: goto label_1e3c30;
            case 0x1E3C70u: goto label_1e3c70;
            case 0x1E3C80u: goto label_1e3c80;
            case 0x1E3CA4u: goto label_1e3ca4;
            case 0x1E3CC4u: goto label_1e3cc4;
            case 0x1E3CE8u: goto label_1e3ce8;
            case 0x1E3CFCu: goto label_1e3cfc;
            case 0x1E3D00u: goto label_1e3d00;
            case 0x1E3D68u: goto label_1e3d68;
            case 0x1E3D7Cu: goto label_1e3d7c;
            case 0x1E3DBCu: goto label_1e3dbc;
            case 0x1E3DCCu: goto label_1e3dcc;
            case 0x1E3DF0u: goto label_1e3df0;
            case 0x1E3E00u: goto label_1e3e00;
            case 0x1E3E24u: goto label_1e3e24;
            case 0x1E3E38u: goto label_1e3e38;
            case 0x1E3EA4u: goto label_1e3ea4;
            case 0x1E3EC0u: goto label_1e3ec0;
            case 0x1E3ED4u: goto label_1e3ed4;
            case 0x1E3ED8u: goto label_1e3ed8;
            case 0x1E3F40u: goto label_1e3f40;
            case 0x1E3F54u: goto label_1e3f54;
            case 0x1E3F94u: goto label_1e3f94;
            case 0x1E3FA4u: goto label_1e3fa4;
            case 0x1E3FC8u: goto label_1e3fc8;
            case 0x1E3FD8u: goto label_1e3fd8;
            case 0x1E3FFCu: goto label_1e3ffc;
            case 0x1E4010u: goto label_1e4010;
            case 0x1E407Cu: goto label_1e407c;
            case 0x1E4098u: goto label_1e4098;
            case 0x1E40ACu: goto label_1e40ac;
            case 0x1E40B0u: goto label_1e40b0;
            case 0x1E4118u: goto label_1e4118;
            case 0x1E412Cu: goto label_1e412c;
            case 0x1E416Cu: goto label_1e416c;
            case 0x1E417Cu: goto label_1e417c;
            case 0x1E41A0u: goto label_1e41a0;
            case 0x1E41B0u: goto label_1e41b0;
            case 0x1E41D4u: goto label_1e41d4;
            case 0x1E41E8u: goto label_1e41e8;
            case 0x1E4254u: goto label_1e4254;
            case 0x1E4270u: goto label_1e4270;
            case 0x1E4284u: goto label_1e4284;
            case 0x1E4288u: goto label_1e4288;
            case 0x1E42F0u: goto label_1e42f0;
            case 0x1E4304u: goto label_1e4304;
            case 0x1E4344u: goto label_1e4344;
            case 0x1E4358u: goto label_1e4358;
            case 0x1E437Cu: goto label_1e437c;
            case 0x1E4394u: goto label_1e4394;
            case 0x1E43B8u: goto label_1e43b8;
            case 0x1E43CCu: goto label_1e43cc;
            case 0x1E43E4u: goto label_1e43e4;
            case 0x1E4414u: goto label_1e4414;
            case 0x1E4430u: goto label_1e4430;
            case 0x1E4444u: goto label_1e4444;
            case 0x1E4460u: goto label_1e4460;
            case 0x1E44C8u: goto label_1e44c8;
            case 0x1E44DCu: goto label_1e44dc;
            case 0x1E451Cu: goto label_1e451c;
            case 0x1E452Cu: goto label_1e452c;
            case 0x1E4550u: goto label_1e4550;
            case 0x1E4560u: goto label_1e4560;
            case 0x1E4584u: goto label_1e4584;
            case 0x1E4598u: goto label_1e4598;
            case 0x1E460Cu: goto label_1e460c;
            case 0x1E4628u: goto label_1e4628;
            case 0x1E463Cu: goto label_1e463c;
            case 0x1E4658u: goto label_1e4658;
            case 0x1E46C8u: goto label_1e46c8;
            case 0x1E46DCu: goto label_1e46dc;
            case 0x1E471Cu: goto label_1e471c;
            case 0x1E472Cu: goto label_1e472c;
            case 0x1E4750u: goto label_1e4750;
            case 0x1E4764u: goto label_1e4764;
            case 0x1E4788u: goto label_1e4788;
            case 0x1E479Cu: goto label_1e479c;
            case 0x1E47B0u: goto label_1e47b0;
            case 0x1E47E0u: goto label_1e47e0;
            case 0x1E47FCu: goto label_1e47fc;
            case 0x1E4800u: goto label_1e4800;
            case 0x1E48A0u: goto label_1e48a0;
            case 0x1E48B4u: goto label_1e48b4;
            case 0x1E48F4u: goto label_1e48f4;
            case 0x1E4918u: goto label_1e4918;
            case 0x1E493Cu: goto label_1e493c;
            case 0x1E4974u: goto label_1e4974;
            case 0x1E4998u: goto label_1e4998;
            case 0x1E49ACu: goto label_1e49ac;
            case 0x1E4A08u: goto label_1e4a08;
            case 0x1E4A24u: goto label_1e4a24;
            case 0x1E4AACu: goto label_1e4aac;
            case 0x1E4AC0u: goto label_1e4ac0;
            case 0x1E4B00u: goto label_1e4b00;
            case 0x1E4B1Cu: goto label_1e4b1c;
            case 0x1E4B20u: goto label_1e4b20;
            case 0x1E4B94u: goto label_1e4b94;
            case 0x1E4BA8u: goto label_1e4ba8;
            case 0x1E4BE8u: goto label_1e4be8;
            case 0x1E4C10u: goto label_1e4c10;
            case 0x1E4C34u: goto label_1e4c34;
            case 0x1E4C64u: goto label_1e4c64;
            case 0x1E4C88u: goto label_1e4c88;
            case 0x1E4C9Cu: goto label_1e4c9c;
            case 0x1E4D08u: goto label_1e4d08;
            case 0x1E4D28u: goto label_1e4d28;
            case 0x1E4DE4u: goto label_1e4de4;
            case 0x1E4DF8u: goto label_1e4df8;
            case 0x1E4E3Cu: goto label_1e4e3c;
            case 0x1E4E58u: goto label_1e4e58;
            case 0x1E4E5Cu: goto label_1e4e5c;
            case 0x1E4EC4u: goto label_1e4ec4;
            case 0x1E4ED8u: goto label_1e4ed8;
            case 0x1E4F18u: goto label_1e4f18;
            case 0x1E4F28u: goto label_1e4f28;
            case 0x1E4F4Cu: goto label_1e4f4c;
            case 0x1E4F60u: goto label_1e4f60;
            case 0x1E4F84u: goto label_1e4f84;
            case 0x1E4F98u: goto label_1e4f98;
            case 0x1E4FACu: goto label_1e4fac;
            case 0x1E4FD0u: goto label_1e4fd0;
            case 0x1E4FECu: goto label_1e4fec;
            case 0x1E4FF0u: goto label_1e4ff0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E5008u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
