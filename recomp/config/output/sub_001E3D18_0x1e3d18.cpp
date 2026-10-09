#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E3D18
// Address: 0x1e3d18 - 0x1e3ef0
void sub_001E3D18_0x1e3d18(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E3D18_0x1e3d18");
#endif

    switch (ctx->pc) {
        case 0x1e3dccu: goto label_1e3dcc;
        case 0x1e3e00u: goto label_1e3e00;
        case 0x1e3e24u: goto label_1e3e24;
        case 0x1e3ea4u: goto label_1e3ea4;
        case 0x1e3ed4u: goto label_1e3ed4;
        default: break;
    }

    ctx->pc = 0x1e3d18u;

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
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E3EF0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
