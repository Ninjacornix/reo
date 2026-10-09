#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00103C78
// Address: 0x103c78 - 0x104ee0
void sub_00103C78_0x103c78(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00103C78_0x103c78");
#endif

    switch (ctx->pc) {
        case 0x103ce8u: goto label_103ce8;
        case 0x103da8u: goto label_103da8;
        case 0x103df0u: goto label_103df0;
        case 0x103ea4u: goto label_103ea4;
        case 0x103ec0u: goto label_103ec0;
        case 0x103f04u: goto label_103f04;
        case 0x103f18u: goto label_103f18;
        case 0x103f2cu: goto label_103f2c;
        case 0x103f38u: goto label_103f38;
        case 0x103f4cu: goto label_103f4c;
        case 0x103f5cu: goto label_103f5c;
        case 0x103f6cu: goto label_103f6c;
        case 0x103f7cu: goto label_103f7c;
        case 0x103f8cu: goto label_103f8c;
        case 0x103f9cu: goto label_103f9c;
        case 0x103fd0u: goto label_103fd0;
        case 0x104110u: goto label_104110;
        case 0x10413cu: goto label_10413c;
        case 0x1041acu: goto label_1041ac;
        case 0x1041c0u: goto label_1041c0;
        case 0x1041dcu: goto label_1041dc;
        case 0x1041fcu: goto label_1041fc;
        case 0x104230u: goto label_104230;
        case 0x104240u: goto label_104240;
        case 0x10425cu: goto label_10425c;
        case 0x10428cu: goto label_10428c;
        case 0x1042c4u: goto label_1042c4;
        case 0x1042d0u: goto label_1042d0;
        case 0x1042e0u: goto label_1042e0;
        case 0x1042f4u: goto label_1042f4;
        case 0x10433cu: goto label_10433c;
        case 0x104350u: goto label_104350;
        case 0x104368u: goto label_104368;
        case 0x104378u: goto label_104378;
        case 0x1043b0u: goto label_1043b0;
        case 0x1043c0u: goto label_1043c0;
        case 0x1043c8u: goto label_1043c8;
        case 0x1043dcu: goto label_1043dc;
        case 0x1043f0u: goto label_1043f0;
        case 0x104400u: goto label_104400;
        case 0x10440cu: goto label_10440c;
        case 0x10441cu: goto label_10441c;
        case 0x104438u: goto label_104438;
        case 0x104454u: goto label_104454;
        case 0x104464u: goto label_104464;
        case 0x1044a4u: goto label_1044a4;
        case 0x1044a8u: goto label_1044a8;
        case 0x1044b4u: goto label_1044b4;
        case 0x1044c0u: goto label_1044c0;
        case 0x1044d0u: goto label_1044d0;
        case 0x1044fcu: goto label_1044fc;
        case 0x10450cu: goto label_10450c;
        case 0x104528u: goto label_104528;
        case 0x104538u: goto label_104538;
        case 0x104548u: goto label_104548;
        case 0x104584u: goto label_104584;
        case 0x1045fcu: goto label_1045fc;
        case 0x10460cu: goto label_10460c;
        case 0x104620u: goto label_104620;
        case 0x104630u: goto label_104630;
        case 0x10463cu: goto label_10463c;
        case 0x104648u: goto label_104648;
        case 0x104658u: goto label_104658;
        case 0x104668u: goto label_104668;
        case 0x10468cu: goto label_10468c;
        case 0x1046a0u: goto label_1046a0;
        case 0x1046b8u: goto label_1046b8;
        case 0x1046d8u: goto label_1046d8;
        case 0x104728u: goto label_104728;
        case 0x10473cu: goto label_10473c;
        case 0x1047fcu: goto label_1047fc;
        case 0x104870u: goto label_104870;
        case 0x104884u: goto label_104884;
        case 0x104894u: goto label_104894;
        case 0x1048b8u: goto label_1048b8;
        case 0x1048ccu: goto label_1048cc;
        case 0x1048dcu: goto label_1048dc;
        case 0x1048f8u: goto label_1048f8;
        case 0x104964u: goto label_104964;
        case 0x1049fcu: goto label_1049fc;
        case 0x104a1cu: goto label_104a1c;
        case 0x104a34u: goto label_104a34;
        case 0x104a50u: goto label_104a50;
        case 0x104a74u: goto label_104a74;
        case 0x104ab8u: goto label_104ab8;
        case 0x104ac8u: goto label_104ac8;
        case 0x104b18u: goto label_104b18;
        case 0x104b34u: goto label_104b34;
        case 0x104b54u: goto label_104b54;
        case 0x104b64u: goto label_104b64;
        case 0x104b80u: goto label_104b80;
        case 0x104b94u: goto label_104b94;
        case 0x104bbcu: goto label_104bbc;
        case 0x104bd8u: goto label_104bd8;
        case 0x104bf0u: goto label_104bf0;
        case 0x104c04u: goto label_104c04;
        case 0x104c14u: goto label_104c14;
        case 0x104c28u: goto label_104c28;
        case 0x104c44u: goto label_104c44;
        case 0x104c54u: goto label_104c54;
        case 0x104cb8u: goto label_104cb8;
        case 0x104cc8u: goto label_104cc8;
        case 0x104d48u: goto label_104d48;
        case 0x104d5cu: goto label_104d5c;
        case 0x104d70u: goto label_104d70;
        case 0x104d98u: goto label_104d98;
        case 0x104da8u: goto label_104da8;
        case 0x104dd8u: goto label_104dd8;
        case 0x104e24u: goto label_104e24;
        case 0x104e50u: goto label_104e50;
        case 0x104e74u: goto label_104e74;
        case 0x104e80u: goto label_104e80;
        case 0x104e8cu: goto label_104e8c;
        default: break;
    }

    ctx->pc = 0x103c78u;

    // 0x103c78: 0x27bdff50  addiu       $sp, $sp, -0xB0
    ctx->pc = 0x103c78u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967120));
    // 0x103c7c: 0xffb00060  sd          $s0, 0x60($sp)
    ctx->pc = 0x103c7cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 16));
    // 0x103c80: 0x120802d  daddu       $s0, $t1, $zero
    ctx->pc = 0x103c80u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x103c84: 0xffb40080  sd          $s4, 0x80($sp)
    ctx->pc = 0x103c84u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 20));
    // 0x103c88: 0xa0a02d  daddu       $s4, $a1, $zero
    ctx->pc = 0x103c88u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x103c8c: 0xffb70098  sd          $s7, 0x98($sp)
    ctx->pc = 0x103c8cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 152), GPR_U64(ctx, 23));
    // 0x103c90: 0x80b82d  daddu       $s7, $a0, $zero
    ctx->pc = 0x103c90u;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x103c94: 0xffb10068  sd          $s1, 0x68($sp)
    ctx->pc = 0x103c94u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 104), GPR_U64(ctx, 17));
    // 0x103c98: 0xffb20070  sd          $s2, 0x70($sp)
    ctx->pc = 0x103c98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 18));
    // 0x103c9c: 0xffb30078  sd          $s3, 0x78($sp)
    ctx->pc = 0x103c9cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 120), GPR_U64(ctx, 19));
    // 0x103ca0: 0xffb50088  sd          $s5, 0x88($sp)
    ctx->pc = 0x103ca0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 136), GPR_U64(ctx, 21));
    // 0x103ca4: 0xffb60090  sd          $s6, 0x90($sp)
    ctx->pc = 0x103ca4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 22));
    // 0x103ca8: 0xffbe00a0  sd          $fp, 0xA0($sp)
    ctx->pc = 0x103ca8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 30));
    // 0x103cac: 0xffbf00a8  sd          $ra, 0xA8($sp)
    ctx->pc = 0x103cacu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 168), GPR_U64(ctx, 31));
    // 0x103cb0: 0xafa60008  sw          $a2, 0x8($sp)
    ctx->pc = 0x103cb0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 6));
    // 0x103cb4: 0x8eeb0040  lw          $t3, 0x40($s7)
    ctx->pc = 0x103cb4u;
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 23), 64)));
    // 0x103cb8: 0xafa7000c  sw          $a3, 0xC($sp)
    ctx->pc = 0x103cb8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 12), GPR_U32(ctx, 7));
    // 0x103cbc: 0xafa80010  sw          $t0, 0x10($sp)
    ctx->pc = 0x103cbcu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 8));
    // 0x103cc0: 0x1160000a  beqz        $t3, . + 4 + (0xA << 2)
    ctx->pc = 0x103CC0u;
    {
        const bool branch_taken_0x103cc0 = (GPR_U64(ctx, 11) == GPR_U64(ctx, 0));
        ctx->pc = 0x103CC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x103CC0u;
            // 0x103cc4: 0xafaa0014  sw          $t2, 0x14($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 10));
        ctx->in_delay_slot = false;
        if (branch_taken_0x103cc0) {
            ctx->pc = 0x103CECu;
            goto label_103cec;
        }
    }
    ctx->pc = 0x103CC8u;
    // 0x103cc8: 0x8ee60044  lw          $a2, 0x44($s7)
    ctx->pc = 0x103cc8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 23), 68)));
    // 0x103ccc: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x103cccu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x103cd0: 0x160282d  daddu       $a1, $t3, $zero
    ctx->pc = 0x103cd0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 11) + (uint64_t)GPR_U64(ctx, 0));
    // 0x103cd4: 0xad660004  sw          $a2, 0x4($t3)
    ctx->pc = 0x103cd4u;
    WRITE32(ADD32(GPR_U32(ctx, 11), 4), GPR_U32(ctx, 6));
    // 0x103cd8: 0x8ee20044  lw          $v0, 0x44($s7)
    ctx->pc = 0x103cd8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 23), 68)));
    // 0x103cdc: 0x431804  sllv        $v1, $v1, $v0
    ctx->pc = 0x103cdcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), GPR_U32(ctx, 2) & 0x1F));
    // 0x103ce0: 0xc041fa8  jal         func_107EA0
    ctx->pc = 0x103CE0u;
    SET_GPR_U32(ctx, 31, 0x103CE8u);
    ctx->pc = 0x103CE4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x103CE0u;
            // 0x103ce4: 0xad630008  sw          $v1, 0x8($t3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 11), 8), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107EA0u;
    if (runtime->hasFunction(0x107EA0u)) {
        auto targetFn = runtime->lookupFunction(0x107EA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x103CE8u; }
        if (ctx->pc != 0x103CE8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107EA0_0x107ea0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x103CE8u; }
        if (ctx->pc != 0x103CE8u) { return; }
    }
    ctx->pc = 0x103CE8u;
label_103ce8:
    // 0x103ce8: 0xaee00040  sw          $zero, 0x40($s7)
    ctx->pc = 0x103ce8u;
    WRITE32(ADD32(GPR_U32(ctx, 23), 64), GPR_U32(ctx, 0));
label_103cec:
    // 0x103cec: 0x14103e  dsrl32      $v0, $s4, 0
    ctx->pc = 0x103cecu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 20) >> (32 + 0));
    // 0x103cf0: 0x2203c  dsll32      $a0, $v0, 0
    ctx->pc = 0x103cf0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) << (32 + 0));
    // 0x103cf4: 0x4203f  dsra32      $a0, $a0, 0
    ctx->pc = 0x103cf4u;
    SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 0));
    // 0x103cf8: 0x483000c  bgezl       $a0, . + 4 + (0xC << 2)
    ctx->pc = 0x103CF8u;
    {
        const bool branch_taken_0x103cf8 = (GPR_S64(ctx, 4) >= 0);
        if (branch_taken_0x103cf8) {
            ctx->pc = 0x103CFCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x103CF8u;
            // 0x103cfc: 0xae000000  sw          $zero, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x103D2Cu;
            goto label_103d2c;
        }
    }
    ctx->pc = 0x103D00u;
    // 0x103d00: 0x3c027fff  lui         $v0, 0x7FFF
    ctx->pc = 0x103d00u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32767 << 16));
    // 0x103d04: 0x3c03ffff  lui         $v1, 0xFFFF
    ctx->pc = 0x103d04u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)65535 << 16));
    // 0x103d08: 0x3183e  dsrl32      $v1, $v1, 0
    ctx->pc = 0x103d08u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) >> (32 + 0));
    // 0x103d0c: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x103d0cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x103d10: 0x283a024  and         $s4, $s4, $v1
    ctx->pc = 0x103d10u;
    SET_GPR_U64(ctx, 20, GPR_U64(ctx, 20) & GPR_U64(ctx, 3));
    // 0x103d14: 0x821024  and         $v0, $a0, $v0
    ctx->pc = 0x103d14u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & GPR_U64(ctx, 2));
    // 0x103d18: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x103d18u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x103d1c: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x103d1cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x103d20: 0xae030000  sw          $v1, 0x0($s0)
    ctx->pc = 0x103d20u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 3));
    // 0x103d24: 0x282a025  or          $s4, $s4, $v0
    ctx->pc = 0x103d24u;
    SET_GPR_U64(ctx, 20, GPR_U64(ctx, 20) | GPR_U64(ctx, 2));
    // 0x103d28: 0x14103e  dsrl32      $v0, $s4, 0
    ctx->pc = 0x103d28u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 20) >> (32 + 0));
label_103d2c:
    // 0x103d2c: 0x2803c  dsll32      $s0, $v0, 0
    ctx->pc = 0x103d2cu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 2) << (32 + 0));
    // 0x103d30: 0x10803f  dsra32      $s0, $s0, 0
    ctx->pc = 0x103d30u;
    SET_GPR_S64(ctx, 16, GPR_S64(ctx, 16) >> (32 + 0));
    // 0x103d34: 0x3c037ff0  lui         $v1, 0x7FF0
    ctx->pc = 0x103d34u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32752 << 16));
    // 0x103d38: 0x2031024  and         $v0, $s0, $v1
    ctx->pc = 0x103d38u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & GPR_U64(ctx, 3));
    // 0x103d3c: 0x14430016  bne         $v0, $v1, . + 4 + (0x16 << 2)
    ctx->pc = 0x103D3Cu;
    {
        const bool branch_taken_0x103d3c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x103D40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x103D3Cu;
            // 0x103d40: 0x8fa40010  lw          $a0, 0x10($sp) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x103d3c) {
            ctx->pc = 0x103D98u;
            goto label_103d98;
        }
    }
    ctx->pc = 0x103D44u;
    // 0x103d44: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x103d44u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x103d48: 0x2133a  dsrl        $v0, $v0, 12
    ctx->pc = 0x103d48u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> 12);
    // 0x103d4c: 0x2403270f  addiu       $v1, $zero, 0x270F
    ctx->pc = 0x103d4cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 9999));
    // 0x103d50: 0x2821024  and         $v0, $s4, $v0
    ctx->pc = 0x103d50u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 20) & GPR_U64(ctx, 2));
    // 0x103d54: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x103D54u;
    {
        const bool branch_taken_0x103d54 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x103D58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x103D54u;
            // 0x103d58: 0xac830000  sw          $v1, 0x0($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x103d54) {
            ctx->pc = 0x103D68u;
            goto label_103d68;
        }
    }
    ctx->pc = 0x103D5Cu;
    // 0x103d5c: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x103d5cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x103d60: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x103D60u;
    {
        const bool branch_taken_0x103d60 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x103D64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x103D60u;
            // 0x103d64: 0x24557870  addiu       $s5, $v0, 0x7870 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 2), 30832));
        ctx->in_delay_slot = false;
        if (branch_taken_0x103d60) {
            ctx->pc = 0x103D70u;
            goto label_103d70;
        }
    }
    ctx->pc = 0x103D68u;
label_103d68:
    // 0x103d68: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x103d68u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x103d6c: 0x24557880  addiu       $s5, $v0, 0x7880
    ctx->pc = 0x103d6cu;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 2), 30848));
label_103d70:
    // 0x103d70: 0x8fa20014  lw          $v0, 0x14($sp)
    ctx->pc = 0x103d70u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x103d74: 0x10400018  beqz        $v0, . + 4 + (0x18 << 2)
    ctx->pc = 0x103D74u;
    {
        const bool branch_taken_0x103d74 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x103D78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x103D74u;
            // 0x103d78: 0x26a30008  addiu       $v1, $s5, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 21), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x103d74) {
            ctx->pc = 0x103DD8u;
            goto label_103dd8;
        }
    }
    ctx->pc = 0x103D7Cu;
    // 0x103d7c: 0x82a20003  lb          $v0, 0x3($s5)
    ctx->pc = 0x103d7cu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 21), 3)));
    // 0x103d80: 0x26a40003  addiu       $a0, $s5, 0x3
    ctx->pc = 0x103d80u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 21), 3));
    // 0x103d84: 0x82180a  movz        $v1, $a0, $v0
    ctx->pc = 0x103d84u;
    if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 3, GPR_VEC(ctx, 4));
    // 0x103d88: 0x8fa40014  lw          $a0, 0x14($sp)
    ctx->pc = 0x103d88u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x103d8c: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x103D8Cu;
    {
        const bool branch_taken_0x103d8c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x103D90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x103D8Cu;
            // 0x103d90: 0xac830000  sw          $v1, 0x0($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x103d8c) {
            ctx->pc = 0x103DD8u;
            goto label_103dd8;
        }
    }
    ctx->pc = 0x103D94u;
    // 0x103d94: 0x0  nop
    ctx->pc = 0x103d94u;
    // NOP
label_103d98:
    // 0x103d98: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x103d98u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x103d9c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x103d9cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x103da0: 0xc0448a6  jal         func_112298
    ctx->pc = 0x103DA0u;
    SET_GPR_U32(ctx, 31, 0x103DA8u);
    ctx->pc = 0x112298u;
    if (runtime->hasFunction(0x112298u)) {
        auto targetFn = runtime->lookupFunction(0x112298u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x103DA8u; }
        if (ctx->pc != 0x103DA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112298_0x112298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x103DA8u; }
        if (ctx->pc != 0x103DA8u) { return; }
    }
    ctx->pc = 0x103DA8u;
label_103da8:
    // 0x103da8: 0x1440000d  bnez        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x103DA8u;
    {
        const bool branch_taken_0x103da8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x103DACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x103DA8u;
            // 0x103dac: 0x2e0202d  daddu       $a0, $s7, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x103da8) {
            ctx->pc = 0x103DE0u;
            goto label_103de0;
        }
    }
    ctx->pc = 0x103DB0u;
    // 0x103db0: 0x8fa40010  lw          $a0, 0x10($sp)
    ctx->pc = 0x103db0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x103db4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x103db4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x103db8: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x103db8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x103dbc: 0xac820000  sw          $v0, 0x0($a0)
    ctx->pc = 0x103dbcu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 2));
    // 0x103dc0: 0x8fa20014  lw          $v0, 0x14($sp)
    ctx->pc = 0x103dc0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x103dc4: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x103DC4u;
    {
        const bool branch_taken_0x103dc4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x103DC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x103DC4u;
            // 0x103dc8: 0x24757888  addiu       $s5, $v1, 0x7888 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 3), 30856));
        ctx->in_delay_slot = false;
        if (branch_taken_0x103dc4) {
            ctx->pc = 0x103DD8u;
            goto label_103dd8;
        }
    }
    ctx->pc = 0x103DCCu;
    // 0x103dcc: 0x8fa30014  lw          $v1, 0x14($sp)
    ctx->pc = 0x103dccu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x103dd0: 0x26a20001  addiu       $v0, $s5, 0x1
    ctx->pc = 0x103dd0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 21), 1));
    // 0x103dd4: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x103dd4u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
label_103dd8:
    // 0x103dd8: 0x10000434  b           . + 4 + (0x434 << 2)
    ctx->pc = 0x103DD8u;
    {
        const bool branch_taken_0x103dd8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x103DDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x103DD8u;
            // 0x103ddc: 0x2a0102d  daddu       $v0, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x103dd8) {
            ctx->pc = 0x104EACu;
            goto label_104eac;
        }
    }
    ctx->pc = 0x103DE0u;
label_103de0:
    // 0x103de0: 0x280282d  daddu       $a1, $s4, $zero
    ctx->pc = 0x103de0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x103de4: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x103de4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x103de8: 0xc0422d2  jal         func_108B48
    ctx->pc = 0x103DE8u;
    SET_GPR_U32(ctx, 31, 0x103DF0u);
    ctx->pc = 0x103DECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x103DE8u;
            // 0x103dec: 0x27a70004  addiu       $a3, $sp, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x108B48u;
    if (runtime->hasFunction(0x108B48u)) {
        auto targetFn = runtime->lookupFunction(0x108B48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x103DF0u; }
        if (ctx->pc != 0x103DF0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00108B48_0x108b48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x103DF0u; }
        if (ctx->pc != 0x103DF0u) { return; }
    }
    ctx->pc = 0x103DF0u;
label_103df0:
    // 0x103df0: 0xafa20044  sw          $v0, 0x44($sp)
    ctx->pc = 0x103df0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 68), GPR_U32(ctx, 2));
    // 0x103df4: 0x101502  srl         $v0, $s0, 20
    ctx->pc = 0x103df4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), 20));
    // 0x103df8: 0x305307ff  andi        $s3, $v0, 0x7FF
    ctx->pc = 0x103df8u;
    SET_GPR_U64(ctx, 19, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)2047);
    // 0x103dfc: 0x12600014  beqz        $s3, . + 4 + (0x14 << 2)
    ctx->pc = 0x103DFCu;
    {
        const bool branch_taken_0x103dfc = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x103E00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x103DFCu;
            // 0x103e00: 0x3c02000f  lui         $v0, 0xF (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)15 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x103dfc) {
            ctx->pc = 0x103E50u;
            goto label_103e50;
        }
    }
    ctx->pc = 0x103E04u;
    // 0x103e04: 0x280b02d  daddu       $s6, $s4, $zero
    ctx->pc = 0x103e04u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x103e08: 0x16183f  dsra32      $v1, $s6, 0
    ctx->pc = 0x103e08u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 22) >> (32 + 0));
    // 0x103e0c: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x103e0cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x103e10: 0x621824  and         $v1, $v1, $v0
    ctx->pc = 0x103e10u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x103e14: 0x3c05ffff  lui         $a1, 0xFFFF
    ctx->pc = 0x103e14u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65535 << 16));
    // 0x103e18: 0x5283e  dsrl32      $a1, $a1, 0
    ctx->pc = 0x103e18u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) >> (32 + 0));
    // 0x103e1c: 0x3183c  dsll32      $v1, $v1, 0
    ctx->pc = 0x103e1cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x103e20: 0x2c5b024  and         $s6, $s6, $a1
    ctx->pc = 0x103e20u;
    SET_GPR_U64(ctx, 22, GPR_U64(ctx, 22) & GPR_U64(ctx, 5));
    // 0x103e24: 0x2c3b025  or          $s6, $s6, $v1
    ctx->pc = 0x103e24u;
    SET_GPR_U64(ctx, 22, GPR_U64(ctx, 22) | GPR_U64(ctx, 3));
    // 0x103e28: 0x3c043ff0  lui         $a0, 0x3FF0
    ctx->pc = 0x103e28u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)16368 << 16));
    // 0x103e2c: 0x16103f  dsra32      $v0, $s6, 0
    ctx->pc = 0x103e2cu;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 22) >> (32 + 0));
    // 0x103e30: 0x2c5b024  and         $s6, $s6, $a1
    ctx->pc = 0x103e30u;
    SET_GPR_U64(ctx, 22, GPR_U64(ctx, 22) & GPR_U64(ctx, 5));
    // 0x103e34: 0x441025  or          $v0, $v0, $a0
    ctx->pc = 0x103e34u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 4));
    // 0x103e38: 0x2673fc01  addiu       $s3, $s3, -0x3FF
    ctx->pc = 0x103e38u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294966273));
    // 0x103e3c: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x103e3cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x103e40: 0xafa00040  sw          $zero, 0x40($sp)
    ctx->pc = 0x103e40u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 64), GPR_U32(ctx, 0));
    // 0x103e44: 0x2c2b025  or          $s6, $s6, $v0
    ctx->pc = 0x103e44u;
    SET_GPR_U64(ctx, 22, GPR_U64(ctx, 22) | GPR_U64(ctx, 2));
    // 0x103e48: 0x10000029  b           . + 4 + (0x29 << 2)
    ctx->pc = 0x103E48u;
    {
        const bool branch_taken_0x103e48 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x103E4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x103E48u;
            // 0x103e4c: 0x8fb20004  lw          $s2, 0x4($sp) (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x103e48) {
            ctx->pc = 0x103EF0u;
            goto label_103ef0;
        }
    }
    ctx->pc = 0x103E50u;
label_103e50:
    // 0x103e50: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x103e50u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x103e54: 0x8fb20004  lw          $s2, 0x4($sp)
    ctx->pc = 0x103e54u;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x103e58: 0x2422021  addu        $a0, $s2, $v0
    ctx->pc = 0x103e58u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 2)));
    // 0x103e5c: 0x24930432  addiu       $s3, $a0, 0x432
    ctx->pc = 0x103e5cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 4), 1074));
    // 0x103e60: 0x2a620021  slti        $v0, $s3, 0x21
    ctx->pc = 0x103e60u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)33) ? 1 : 0);
    // 0x103e64: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x103E64u;
    {
        const bool branch_taken_0x103e64 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x103E68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x103E64u;
            // 0x103e68: 0x131023  negu        $v0, $s3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 19)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x103e64) {
            ctx->pc = 0x103E90u;
            goto label_103e90;
        }
    }
    ctx->pc = 0x103E6Cu;
    // 0x103e6c: 0x24840412  addiu       $a0, $a0, 0x412
    ctx->pc = 0x103e6cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1042));
    // 0x103e70: 0x131823  negu        $v1, $s3
    ctx->pc = 0x103e70u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 19)));
    // 0x103e74: 0x14103c  dsll32      $v0, $s4, 0
    ctx->pc = 0x103e74u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 20) << (32 + 0));
    // 0x103e78: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x103e78u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x103e7c: 0x701804  sllv        $v1, $s0, $v1
    ctx->pc = 0x103e7cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 3) & 0x1F));
    // 0x103e80: 0x821006  srlv        $v0, $v0, $a0
    ctx->pc = 0x103e80u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), GPR_U32(ctx, 4) & 0x1F));
    // 0x103e84: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x103E84u;
    {
        const bool branch_taken_0x103e84 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x103E88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x103E84u;
            // 0x103e88: 0x628025  or          $s0, $v1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x103e84) {
            ctx->pc = 0x103E9Cu;
            goto label_103e9c;
        }
    }
    ctx->pc = 0x103E8Cu;
    // 0x103e8c: 0x0  nop
    ctx->pc = 0x103e8cu;
    // NOP
label_103e90:
    // 0x103e90: 0x14183c  dsll32      $v1, $s4, 0
    ctx->pc = 0x103e90u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 20) << (32 + 0));
    // 0x103e94: 0x3183f  dsra32      $v1, $v1, 0
    ctx->pc = 0x103e94u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 0));
    // 0x103e98: 0x438004  sllv        $s0, $v1, $v0
    ctx->pc = 0x103e98u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 3), GPR_U32(ctx, 2) & 0x1F));
label_103e9c:
    // 0x103e9c: 0xc0448ba  jal         func_1122E8
    ctx->pc = 0x103E9Cu;
    SET_GPR_U32(ctx, 31, 0x103EA4u);
    ctx->pc = 0x103EA0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x103E9Cu;
            // 0x103ea0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1122E8u;
    if (runtime->hasFunction(0x1122E8u)) {
        auto targetFn = runtime->lookupFunction(0x1122E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x103EA4u; }
        if (ctx->pc != 0x103EA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001122E8_0x1122e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x103EA4u; }
        if (ctx->pc != 0x103EA4u) { return; }
    }
    ctx->pc = 0x103EA4u;
label_103ea4:
    // 0x103ea4: 0x6010006  bgez        $s0, . + 4 + (0x6 << 2)
    ctx->pc = 0x103EA4u;
    {
        const bool branch_taken_0x103ea4 = (GPR_S64(ctx, 16) >= 0);
        if (branch_taken_0x103ea4) {
            ctx->pc = 0x103EC0u;
            goto label_103ec0;
        }
    }
    ctx->pc = 0x103EACu;
    // 0x103eac: 0x340583e0  ori         $a1, $zero, 0x83E0
    ctx->pc = 0x103eacu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)33760);
    // 0x103eb0: 0x52bfc  dsll32      $a1, $a1, 15
    ctx->pc = 0x103eb0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 15));
    // 0x103eb4: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x103eb4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x103eb8: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x103EB8u;
    SET_GPR_U32(ctx, 31, 0x103EC0u);
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x103EC0u; }
        if (ctx->pc != 0x103EC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x103EC0u; }
        if (ctx->pc != 0x103EC0u) { return; }
    }
    ctx->pc = 0x103EC0u;
label_103ec0:
    // 0x103ec0: 0x40b02d  daddu       $s6, $v0, $zero
    ctx->pc = 0x103ec0u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x103ec4: 0x3c02fe10  lui         $v0, 0xFE10
    ctx->pc = 0x103ec4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65040 << 16));
    // 0x103ec8: 0x16183f  dsra32      $v1, $s6, 0
    ctx->pc = 0x103ec8u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 22) >> (32 + 0));
    // 0x103ecc: 0x3c04ffff  lui         $a0, 0xFFFF
    ctx->pc = 0x103eccu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)65535 << 16));
    // 0x103ed0: 0x4203e  dsrl32      $a0, $a0, 0
    ctx->pc = 0x103ed0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) >> (32 + 0));
    // 0x103ed4: 0x2c4b024  and         $s6, $s6, $a0
    ctx->pc = 0x103ed4u;
    SET_GPR_U64(ctx, 22, GPR_U64(ctx, 22) & GPR_U64(ctx, 4));
    // 0x103ed8: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x103ed8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x103edc: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x103edcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x103ee0: 0xafa40040  sw          $a0, 0x40($sp)
    ctx->pc = 0x103ee0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 64), GPR_U32(ctx, 4));
    // 0x103ee4: 0x3183c  dsll32      $v1, $v1, 0
    ctx->pc = 0x103ee4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x103ee8: 0x2673fbcd  addiu       $s3, $s3, -0x433
    ctx->pc = 0x103ee8u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294966221));
    // 0x103eec: 0x2c3b025  or          $s6, $s6, $v1
    ctx->pc = 0x103eecu;
    SET_GPR_U64(ctx, 22, GPR_U64(ctx, 22) | GPR_U64(ctx, 3));
label_103ef0:
    // 0x103ef0: 0x3405ffe0  ori         $a1, $zero, 0xFFE0
    ctx->pc = 0x103ef0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65504);
    // 0x103ef4: 0x52bbc  dsll32      $a1, $a1, 14
    ctx->pc = 0x103ef4u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 14));
    // 0x103ef8: 0x2c0202d  daddu       $a0, $s6, $zero
    ctx->pc = 0x103ef8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x103efc: 0xc044752  jal         func_111D48
    ctx->pc = 0x103EFCu;
    SET_GPR_U32(ctx, 31, 0x103F04u);
    ctx->pc = 0x111D48u;
    if (runtime->hasFunction(0x111D48u)) {
        auto targetFn = runtime->lookupFunction(0x111D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x103F04u; }
        if (ctx->pc != 0x103F04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111D48_0x111d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x103F04u; }
        if (ctx->pc != 0x103F04u) { return; }
    }
    ctx->pc = 0x103F04u;
label_103f04:
    // 0x103f04: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x103f04u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x103f08: 0xdc257890  ld          $a1, 0x7890($at)
    ctx->pc = 0x103f08u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 1), 30864)));
    // 0x103f0c: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x103f0cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x103f10: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x103F10u;
    SET_GPR_U32(ctx, 31, 0x103F18u);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x103F18u; }
        if (ctx->pc != 0x103F18u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x103F18u; }
        if (ctx->pc != 0x103F18u) { return; }
    }
    ctx->pc = 0x103F18u;
label_103f18:
    // 0x103f18: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x103f18u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x103f1c: 0xdc257898  ld          $a1, 0x7898($at)
    ctx->pc = 0x103f1cu;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 1), 30872)));
    // 0x103f20: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x103f20u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x103f24: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x103F24u;
    SET_GPR_U32(ctx, 31, 0x103F2Cu);
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x103F2Cu; }
        if (ctx->pc != 0x103F2Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x103F2Cu; }
        if (ctx->pc != 0x103F2Cu) { return; }
    }
    ctx->pc = 0x103F2Cu;
label_103f2c:
    // 0x103f2c: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x103f2cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x103f30: 0xc0448ba  jal         func_1122E8
    ctx->pc = 0x103F30u;
    SET_GPR_U32(ctx, 31, 0x103F38u);
    ctx->pc = 0x103F34u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x103F30u;
            // 0x103f34: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1122E8u;
    if (runtime->hasFunction(0x1122E8u)) {
        auto targetFn = runtime->lookupFunction(0x1122E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x103F38u; }
        if (ctx->pc != 0x103F38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001122E8_0x1122e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x103F38u; }
        if (ctx->pc != 0x103F38u) { return; }
    }
    ctx->pc = 0x103F38u;
label_103f38:
    // 0x103f38: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x103f38u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x103f3c: 0xdc2578a0  ld          $a1, 0x78A0($at)
    ctx->pc = 0x103f3cu;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 1), 30880)));
    // 0x103f40: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x103f40u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x103f44: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x103F44u;
    SET_GPR_U32(ctx, 31, 0x103F4Cu);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x103F4Cu; }
        if (ctx->pc != 0x103F4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x103F4Cu; }
        if (ctx->pc != 0x103F4Cu) { return; }
    }
    ctx->pc = 0x103F4Cu;
label_103f4c:
    // 0x103f4c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x103f4cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x103f50: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x103f50u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x103f54: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x103F54u;
    SET_GPR_U32(ctx, 31, 0x103F5Cu);
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x103F5Cu; }
        if (ctx->pc != 0x103F5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x103F5Cu; }
        if (ctx->pc != 0x103F5Cu) { return; }
    }
    ctx->pc = 0x103F5Cu;
label_103f5c:
    // 0x103f5c: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x103f5cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x103f60: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x103f60u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x103f64: 0xc0448e8  jal         func_1123A0
    ctx->pc = 0x103F64u;
    SET_GPR_U32(ctx, 31, 0x103F6Cu);
    ctx->pc = 0x1123A0u;
    if (runtime->hasFunction(0x1123A0u)) {
        auto targetFn = runtime->lookupFunction(0x1123A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x103F6Cu; }
        if (ctx->pc != 0x103F6Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001123A0_0x1123a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x103F6Cu; }
        if (ctx->pc != 0x103F6Cu) { return; }
    }
    ctx->pc = 0x103F6Cu;
label_103f6c:
    // 0x103f6c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x103f6cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x103f70: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x103f70u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x103f74: 0xc0448a6  jal         func_112298
    ctx->pc = 0x103F74u;
    SET_GPR_U32(ctx, 31, 0x103F7Cu);
    ctx->pc = 0x103F78u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x103F74u;
            // 0x103f78: 0x40f02d  daddu       $fp, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x112298u;
    if (runtime->hasFunction(0x112298u)) {
        auto targetFn = runtime->lookupFunction(0x112298u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x103F7Cu; }
        if (ctx->pc != 0x103F7Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112298_0x112298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x103F7Cu; }
        if (ctx->pc != 0x103F7Cu) { return; }
    }
    ctx->pc = 0x103F7Cu;
label_103f7c:
    // 0x103f7c: 0x441000a  bgez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x103F7Cu;
    {
        const bool branch_taken_0x103f7c = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x103F80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x103F7Cu;
            // 0x103f80: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x103f7c) {
            ctx->pc = 0x103FA8u;
            goto label_103fa8;
        }
    }
    ctx->pc = 0x103F84u;
    // 0x103f84: 0xc0448ba  jal         func_1122E8
    ctx->pc = 0x103F84u;
    SET_GPR_U32(ctx, 31, 0x103F8Cu);
    ctx->pc = 0x103F88u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x103F84u;
            // 0x103f88: 0x3c0202d  daddu       $a0, $fp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1122E8u;
    if (runtime->hasFunction(0x1122E8u)) {
        auto targetFn = runtime->lookupFunction(0x1122E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x103F8Cu; }
        if (ctx->pc != 0x103F8Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001122E8_0x1122e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x103F8Cu; }
        if (ctx->pc != 0x103F8Cu) { return; }
    }
    ctx->pc = 0x103F8Cu;
label_103f8c:
    // 0x103f8c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x103f8cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x103f90: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x103f90u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x103f94: 0xc0448a6  jal         func_112298
    ctx->pc = 0x103F94u;
    SET_GPR_U32(ctx, 31, 0x103F9Cu);
    ctx->pc = 0x112298u;
    if (runtime->hasFunction(0x112298u)) {
        auto targetFn = runtime->lookupFunction(0x112298u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x103F9Cu; }
        if (ctx->pc != 0x103F9Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112298_0x112298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x103F9Cu; }
        if (ctx->pc != 0x103F9Cu) { return; }
    }
    ctx->pc = 0x103F9Cu;
label_103f9c:
    // 0x103f9c: 0x27c3ffff  addiu       $v1, $fp, -0x1
    ctx->pc = 0x103f9cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 30), 4294967295));
    // 0x103fa0: 0x62f00b  movn        $fp, $v1, $v0
    ctx->pc = 0x103fa0u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 30, GPR_VEC(ctx, 3));
    // 0x103fa4: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x103fa4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_103fa8:
    // 0x103fa8: 0x2fc20017  sltiu       $v0, $fp, 0x17
    ctx->pc = 0x103fa8u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 30) < (uint64_t)(int64_t)(int32_t)23) ? 1 : 0);
    // 0x103fac: 0x1040000b  beqz        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x103FACu;
    {
        const bool branch_taken_0x103fac = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x103FB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x103FACu;
            // 0x103fb0: 0xafa30030  sw          $v1, 0x30($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x103fac) {
            ctx->pc = 0x103FDCu;
            goto label_103fdc;
        }
    }
    ctx->pc = 0x103FB4u;
    // 0x103fb4: 0x1e10c0  sll         $v0, $fp, 3
    ctx->pc = 0x103fb4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 30), 3));
    // 0x103fb8: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x103fb8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x103fbc: 0x3c050023  lui         $a1, 0x23
    ctx->pc = 0x103fbcu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)35 << 16));
    // 0x103fc0: 0xa22821  addu        $a1, $a1, $v0
    ctx->pc = 0x103fc0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x103fc4: 0xdca57928  ld          $a1, 0x7928($a1)
    ctx->pc = 0x103fc4u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 5), 31016)));
    // 0x103fc8: 0xc0448a6  jal         func_112298
    ctx->pc = 0x103FC8u;
    SET_GPR_U32(ctx, 31, 0x103FD0u);
    ctx->pc = 0x103FCCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x103FC8u;
            // 0x103fcc: 0xafa00030  sw          $zero, 0x30($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x112298u;
    if (runtime->hasFunction(0x112298u)) {
        auto targetFn = runtime->lookupFunction(0x112298u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x103FD0u; }
        if (ctx->pc != 0x103FD0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112298_0x112298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x103FD0u; }
        if (ctx->pc != 0x103FD0u) { return; }
    }
    ctx->pc = 0x103FD0u;
label_103fd0:
    // 0x103fd0: 0x27c3ffff  addiu       $v1, $fp, -0x1
    ctx->pc = 0x103fd0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 30), 4294967295));
    // 0x103fd4: 0x28420000  slti        $v0, $v0, 0x0
    ctx->pc = 0x103fd4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x103fd8: 0x62f00b  movn        $fp, $v1, $v0
    ctx->pc = 0x103fd8u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 30, GPR_VEC(ctx, 3));
label_103fdc:
    // 0x103fdc: 0x2531023  subu        $v0, $s2, $s3
    ctx->pc = 0x103fdcu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 18), GPR_U32(ctx, 19)));
    // 0x103fe0: 0x2450ffff  addiu       $s0, $v0, -0x1
    ctx->pc = 0x103fe0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x103fe4: 0x6020004  bltzl       $s0, . + 4 + (0x4 << 2)
    ctx->pc = 0x103FE4u;
    {
        const bool branch_taken_0x103fe4 = (GPR_S64(ctx, 16) < 0);
        if (branch_taken_0x103fe4) {
            ctx->pc = 0x103FE8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x103FE4u;
            // 0x103fe8: 0x108023  negu        $s0, $s0 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 16)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x103FF8u;
            goto label_103ff8;
        }
    }
    ctx->pc = 0x103FECu;
    // 0x103fec: 0xafb00038  sw          $s0, 0x38($sp)
    ctx->pc = 0x103fecu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 16));
    // 0x103ff0: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x103FF0u;
    {
        const bool branch_taken_0x103ff0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x103FF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x103FF0u;
            // 0x103ff4: 0xafa00018  sw          $zero, 0x18($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x103ff0) {
            ctx->pc = 0x104000u;
            goto label_104000;
        }
    }
    ctx->pc = 0x103FF8u;
label_103ff8:
    // 0x103ff8: 0xafa00038  sw          $zero, 0x38($sp)
    ctx->pc = 0x103ff8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 0));
    // 0x103ffc: 0xafb00018  sw          $s0, 0x18($sp)
    ctx->pc = 0x103ffcu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
label_104000:
    // 0x104000: 0x7c00007  bltz        $fp, . + 4 + (0x7 << 2)
    ctx->pc = 0x104000u;
    {
        const bool branch_taken_0x104000 = (GPR_S64(ctx, 30) < 0);
        ctx->pc = 0x104004u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x104000u;
            // 0x104004: 0x8fa40038  lw          $a0, 0x38($sp) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x104000) {
            ctx->pc = 0x104020u;
            goto label_104020;
        }
    }
    ctx->pc = 0x104008u;
    // 0x104008: 0xafa0001c  sw          $zero, 0x1C($sp)
    ctx->pc = 0x104008u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 0));
    // 0x10400c: 0x9e2021  addu        $a0, $a0, $fp
    ctx->pc = 0x10400cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 30)));
    // 0x104010: 0xafbe003c  sw          $fp, 0x3C($sp)
    ctx->pc = 0x104010u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 60), GPR_U32(ctx, 30));
    // 0x104014: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x104014u;
    {
        const bool branch_taken_0x104014 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x104018u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x104014u;
            // 0x104018: 0xafa40038  sw          $a0, 0x38($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x104014) {
            ctx->pc = 0x104038u;
            goto label_104038;
        }
    }
    ctx->pc = 0x10401Cu;
    // 0x10401c: 0x0  nop
    ctx->pc = 0x10401cu;
    // NOP
label_104020:
    // 0x104020: 0x8fa20018  lw          $v0, 0x18($sp)
    ctx->pc = 0x104020u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x104024: 0x1e1823  negu        $v1, $fp
    ctx->pc = 0x104024u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 30)));
    // 0x104028: 0xafa3001c  sw          $v1, 0x1C($sp)
    ctx->pc = 0x104028u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 3));
    // 0x10402c: 0x5e1023  subu        $v0, $v0, $fp
    ctx->pc = 0x10402cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 30)));
    // 0x104030: 0xafa0003c  sw          $zero, 0x3C($sp)
    ctx->pc = 0x104030u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 60), GPR_U32(ctx, 0));
    // 0x104034: 0xafa20018  sw          $v0, 0x18($sp)
    ctx->pc = 0x104034u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 2));
label_104038:
    // 0x104038: 0x8fa40008  lw          $a0, 0x8($sp)
    ctx->pc = 0x104038u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x10403c: 0x24110001  addiu       $s1, $zero, 0x1
    ctx->pc = 0x10403cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x104040: 0x2c83000a  sltiu       $v1, $a0, 0xA
    ctx->pc = 0x104040u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)(int64_t)(int32_t)10) ? 1 : 0);
    // 0x104044: 0x3200a  movz        $a0, $zero, $v1
    ctx->pc = 0x104044u;
    if (GPR_U64(ctx, 3) == 0) SET_GPR_VEC(ctx, 4, GPR_VEC(ctx, 0));
    // 0x104048: 0x28820006  slti        $v0, $a0, 0x6
    ctx->pc = 0x104048u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)6) ? 1 : 0);
    // 0x10404c: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x10404Cu;
    {
        const bool branch_taken_0x10404c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x104050u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10404Cu;
            // 0x104050: 0xafa40008  sw          $a0, 0x8($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10404c) {
            ctx->pc = 0x104060u;
            goto label_104060;
        }
    }
    ctx->pc = 0x104054u;
    // 0x104054: 0x2484fffc  addiu       $a0, $a0, -0x4
    ctx->pc = 0x104054u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967292));
    // 0x104058: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x104058u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10405c: 0xafa40008  sw          $a0, 0x8($sp)
    ctx->pc = 0x10405cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 4));
label_104060:
    // 0x104060: 0x8fa30008  lw          $v1, 0x8($sp)
    ctx->pc = 0x104060u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x104064: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x104064u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x104068: 0xafa40034  sw          $a0, 0x34($sp)
    ctx->pc = 0x104068u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 4));
    // 0x10406c: 0x2c620006  sltiu       $v0, $v1, 0x6
    ctx->pc = 0x10406cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)6) ? 1 : 0);
    // 0x104070: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x104070u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x104074: 0xafa30028  sw          $v1, 0x28($sp)
    ctx->pc = 0x104074u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 3));
    // 0x104078: 0x10400020  beqz        $v0, . + 4 + (0x20 << 2)
    ctx->pc = 0x104078u;
    {
        const bool branch_taken_0x104078 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10407Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x104078u;
            // 0x10407c: 0xafa30020  sw          $v1, 0x20($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x104078) {
            ctx->pc = 0x1040FCu;
            goto label_1040fc;
        }
    }
    ctx->pc = 0x104080u;
    // 0x104080: 0x8fa40008  lw          $a0, 0x8($sp)
    ctx->pc = 0x104080u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x104084: 0x41080  sll         $v0, $a0, 2
    ctx->pc = 0x104084u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x104088: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x104088u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x10408c: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x10408cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x104090: 0x8c6378b0  lw          $v1, 0x78B0($v1)
    ctx->pc = 0x104090u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 30896)));
    // 0x104094: 0x600008  jr          $v1
    ctx->pc = 0x104094u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1040A0u: goto label_1040a0;
            case 0x1040B0u: goto label_1040b0;
            case 0x1040B4u: goto label_1040b4;
            case 0x1040D8u: goto label_1040d8;
            case 0x1040DCu: goto label_1040dc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x10409Cu;
    // 0x10409c: 0x0  nop
    ctx->pc = 0x10409cu;
    // NOP
label_1040a0:
    // 0x1040a0: 0x24130012  addiu       $s3, $zero, 0x12
    ctx->pc = 0x1040a0u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 18));
    // 0x1040a4: 0x10000015  b           . + 4 + (0x15 << 2)
    ctx->pc = 0x1040A4u;
    {
        const bool branch_taken_0x1040a4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1040A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1040A4u;
            // 0x1040a8: 0xafa0000c  sw          $zero, 0xC($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 12), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1040a4) {
            ctx->pc = 0x1040FCu;
            goto label_1040fc;
        }
    }
    ctx->pc = 0x1040ACu;
    // 0x1040ac: 0x0  nop
    ctx->pc = 0x1040acu;
    // NOP
label_1040b0:
    // 0x1040b0: 0xafa00034  sw          $zero, 0x34($sp)
    ctx->pc = 0x1040b0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 0));
label_1040b4:
    // 0x1040b4: 0x8fa3000c  lw          $v1, 0xC($sp)
    ctx->pc = 0x1040b4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 12)));
    // 0x1040b8: 0x24130001  addiu       $s3, $zero, 0x1
    ctx->pc = 0x1040b8u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1040bc: 0x3102a  slt         $v0, $zero, $v1
    ctx->pc = 0x1040bcu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 0) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1040c0: 0x62980b  movn        $s3, $v1, $v0
    ctx->pc = 0x1040c0u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 19, GPR_VEC(ctx, 3));
    // 0x1040c4: 0xafb3000c  sw          $s3, 0xC($sp)
    ctx->pc = 0x1040c4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 12), GPR_U32(ctx, 19));
    // 0x1040c8: 0xafb30028  sw          $s3, 0x28($sp)
    ctx->pc = 0x1040c8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 19));
    // 0x1040cc: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x1040CCu;
    {
        const bool branch_taken_0x1040cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1040D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1040CCu;
            // 0x1040d0: 0xafb30020  sw          $s3, 0x20($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 19));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1040cc) {
            ctx->pc = 0x1040FCu;
            goto label_1040fc;
        }
    }
    ctx->pc = 0x1040D4u;
    // 0x1040d4: 0x0  nop
    ctx->pc = 0x1040d4u;
    // NOP
label_1040d8:
    // 0x1040d8: 0xafa00034  sw          $zero, 0x34($sp)
    ctx->pc = 0x1040d8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 0));
label_1040dc:
    // 0x1040dc: 0x8fa4000c  lw          $a0, 0xC($sp)
    ctx->pc = 0x1040dcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 12)));
    // 0x1040e0: 0x9e1021  addu        $v0, $a0, $fp
    ctx->pc = 0x1040e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 30)));
    // 0x1040e4: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1040e4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1040e8: 0x24530001  addiu       $s3, $v0, 0x1
    ctx->pc = 0x1040e8u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1040ec: 0xafa20028  sw          $v0, 0x28($sp)
    ctx->pc = 0x1040ecu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 2));
    // 0x1040f0: 0x13182a  slt         $v1, $zero, $s3
    ctx->pc = 0x1040f0u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 0) < (int64_t)GPR_S64(ctx, 19)) ? 1 : 0);
    // 0x1040f4: 0xafb30020  sw          $s3, 0x20($sp)
    ctx->pc = 0x1040f4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 19));
    // 0x1040f8: 0x83980a  movz        $s3, $a0, $v1
    ctx->pc = 0x1040f8u;
    if (GPR_U64(ctx, 3) == 0) SET_GPR_VEC(ctx, 19, GPR_VEC(ctx, 4));
label_1040fc:
    // 0x1040fc: 0x2e620018  sltiu       $v0, $s3, 0x18
    ctx->pc = 0x1040fcu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 19) < (uint64_t)(int64_t)(int32_t)24) ? 1 : 0);
    // 0x104100: 0xaee00044  sw          $zero, 0x44($s7)
    ctx->pc = 0x104100u;
    WRITE32(ADD32(GPR_U32(ctx, 23), 68), GPR_U32(ctx, 0));
    // 0x104104: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x104104u;
    {
        const bool branch_taken_0x104104 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x104108u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x104104u;
            // 0x104108: 0x24100004  addiu       $s0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x104104) {
            ctx->pc = 0x104130u;
            goto label_104130;
        }
    }
    ctx->pc = 0x10410Cu;
    // 0x10410c: 0x182d  daddu       $v1, $zero, $zero
    ctx->pc = 0x10410cu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_104110:
    // 0x104110: 0x108040  sll         $s0, $s0, 1
    ctx->pc = 0x104110u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 1));
    // 0x104114: 0x26020014  addiu       $v0, $s0, 0x14
    ctx->pc = 0x104114u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 20));
    // 0x104118: 0x262102b  sltu        $v0, $s3, $v0
    ctx->pc = 0x104118u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 19) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x10411c: 0x0  nop
    ctx->pc = 0x10411cu;
    // NOP
    // 0x104120: 0x0  nop
    ctx->pc = 0x104120u;
    // NOP
    // 0x104124: 0x1040fffa  beqz        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x104124u;
    {
        const bool branch_taken_0x104124 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x104128u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x104124u;
            // 0x104128: 0x24630001  addiu       $v1, $v1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x104124) {
            ctx->pc = 0x104110u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_104110;
        }
    }
    ctx->pc = 0x10412Cu;
    // 0x10412c: 0xaee30044  sw          $v1, 0x44($s7)
    ctx->pc = 0x10412cu;
    WRITE32(ADD32(GPR_U32(ctx, 23), 68), GPR_U32(ctx, 3));
label_104130:
    // 0x104130: 0x8ee50044  lw          $a1, 0x44($s7)
    ctx->pc = 0x104130u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 23), 68)));
    // 0x104134: 0xc041f7e  jal         func_107DF8
    ctx->pc = 0x104134u;
    SET_GPR_U32(ctx, 31, 0x10413Cu);
    ctx->pc = 0x104138u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x104134u;
            // 0x104138: 0x2e0202d  daddu       $a0, $s7, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107DF8u;
    if (runtime->hasFunction(0x107DF8u)) {
        auto targetFn = runtime->lookupFunction(0x107DF8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10413Cu; }
        if (ctx->pc != 0x10413Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107DF8_0x107df8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10413Cu; }
        if (ctx->pc != 0x10413Cu) { return; }
    }
    ctx->pc = 0x10413Cu;
label_10413c:
    // 0x10413c: 0xafa20054  sw          $v0, 0x54($sp)
    ctx->pc = 0x10413cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 84), GPR_U32(ctx, 2));
    // 0x104140: 0x8fa30020  lw          $v1, 0x20($sp)
    ctx->pc = 0x104140u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x104144: 0x8fa40054  lw          $a0, 0x54($sp)
    ctx->pc = 0x104144u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 84)));
    // 0x104148: 0x2c62000f  sltiu       $v0, $v1, 0xF
    ctx->pc = 0x104148u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)15) ? 1 : 0);
    // 0x10414c: 0xaee40040  sw          $a0, 0x40($s7)
    ctx->pc = 0x10414cu;
    WRITE32(ADD32(GPR_U32(ctx, 23), 64), GPR_U32(ctx, 4));
    // 0x104150: 0x10400113  beqz        $v0, . + 4 + (0x113 << 2)
    ctx->pc = 0x104150u;
    {
        const bool branch_taken_0x104150 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x104154u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x104150u;
            // 0x104154: 0x8fb50054  lw          $s5, 0x54($sp) (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 84)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x104150) {
            ctx->pc = 0x1045A0u;
            goto label_1045a0;
        }
    }
    ctx->pc = 0x104158u;
    // 0x104158: 0x52200112  beql        $s1, $zero, . + 4 + (0x112 << 2)
    ctx->pc = 0x104158u;
    {
        const bool branch_taken_0x104158 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        if (branch_taken_0x104158) {
            ctx->pc = 0x10415Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x104158u;
            // 0x10415c: 0x8fa30000  lw          $v1, 0x0($sp) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1045A4u;
            goto label_1045a4;
        }
    }
    ctx->pc = 0x104160u;
    // 0x104160: 0x280b02d  daddu       $s6, $s4, $zero
    ctx->pc = 0x104160u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x104164: 0xafbe002c  sw          $fp, 0x2C($sp)
    ctx->pc = 0x104164u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 30));
    // 0x104168: 0xafa30024  sw          $v1, 0x24($sp)
    ctx->pc = 0x104168u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 3));
    // 0x10416c: 0x1bc00026  blez        $fp, . + 4 + (0x26 << 2)
    ctx->pc = 0x10416Cu;
    {
        const bool branch_taken_0x10416c = (GPR_S64(ctx, 30) <= 0);
        ctx->pc = 0x104170u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10416Cu;
            // 0x104170: 0x24130002  addiu       $s3, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10416c) {
            ctx->pc = 0x104208u;
            goto label_104208;
        }
    }
    ctx->pc = 0x104174u;
    // 0x104174: 0x33c2000f  andi        $v0, $fp, 0xF
    ctx->pc = 0x104174u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 30) & (uint64_t)(uint16_t)15);
    // 0x104178: 0x1e8103  sra         $s0, $fp, 4
    ctx->pc = 0x104178u;
    SET_GPR_S32(ctx, 16, SRA32(GPR_S32(ctx, 30), 4));
    // 0x10417c: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x10417cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x104180: 0x32030010  andi        $v1, $s0, 0x10
    ctx->pc = 0x104180u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)16);
    // 0x104184: 0x3c110023  lui         $s1, 0x23
    ctx->pc = 0x104184u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)35 << 16));
    // 0x104188: 0x2228821  addu        $s1, $s1, $v0
    ctx->pc = 0x104188u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 2)));
    // 0x10418c: 0xde317928  ld          $s1, 0x7928($s1)
    ctx->pc = 0x10418cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 17), 31016)));
    // 0x104190: 0x10600007  beqz        $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x104190u;
    {
        const bool branch_taken_0x104190 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x104194u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x104190u;
            // 0x104194: 0x3c020023  lui         $v0, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x104190) {
            ctx->pc = 0x1041B0u;
            goto label_1041b0;
        }
    }
    ctx->pc = 0x104198u;
    // 0x104198: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x104198u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10419c: 0xdc457a10  ld          $a1, 0x7A10($v0)
    ctx->pc = 0x10419cu;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 2), 31248)));
    // 0x1041a0: 0x3210000f  andi        $s0, $s0, 0xF
    ctx->pc = 0x1041a0u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)15);
    // 0x1041a4: 0xc04480e  jal         func_112038
    ctx->pc = 0x1041A4u;
    SET_GPR_U32(ctx, 31, 0x1041ACu);
    ctx->pc = 0x1041A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1041A4u;
            // 0x1041a8: 0x24130003  addiu       $s3, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x112038u;
    if (runtime->hasFunction(0x112038u)) {
        auto targetFn = runtime->lookupFunction(0x112038u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1041ACu; }
        if (ctx->pc != 0x1041ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112038_0x112038(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1041ACu; }
        if (ctx->pc != 0x1041ACu) { return; }
    }
    ctx->pc = 0x1041ACu;
label_1041ac:
    // 0x1041ac: 0x40a02d  daddu       $s4, $v0, $zero
    ctx->pc = 0x1041acu;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_1041b0:
    // 0x1041b0: 0x1200000e  beqz        $s0, . + 4 + (0xE << 2)
    ctx->pc = 0x1041B0u;
    {
        const bool branch_taken_0x1041b0 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x1041B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1041B0u;
            // 0x1041b4: 0x3c020023  lui         $v0, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1041b0) {
            ctx->pc = 0x1041ECu;
            goto label_1041ec;
        }
    }
    ctx->pc = 0x1041B8u;
    // 0x1041b8: 0x245279f0  addiu       $s2, $v0, 0x79F0
    ctx->pc = 0x1041b8u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 2), 31216));
    // 0x1041bc: 0x0  nop
    ctx->pc = 0x1041bcu;
    // NOP
label_1041c0:
    // 0x1041c0: 0x32020001  andi        $v0, $s0, 0x1
    ctx->pc = 0x1041c0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)1);
    // 0x1041c4: 0x50400007  beql        $v0, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x1041C4u;
    {
        const bool branch_taken_0x1041c4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1041c4) {
            ctx->pc = 0x1041C8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1041C4u;
            // 0x1041c8: 0x108043  sra         $s0, $s0, 1 (Delay Slot)
        SET_GPR_S32(ctx, 16, SRA32(GPR_S32(ctx, 16), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1041E4u;
            goto label_1041e4;
        }
    }
    ctx->pc = 0x1041CCu;
    // 0x1041cc: 0xde450000  ld          $a1, 0x0($s2)
    ctx->pc = 0x1041ccu;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x1041d0: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1041d0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1041d4: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x1041D4u;
    SET_GPR_U32(ctx, 31, 0x1041DCu);
    ctx->pc = 0x1041D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1041D4u;
            // 0x1041d8: 0x26730001  addiu       $s3, $s3, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1041DCu; }
        if (ctx->pc != 0x1041DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1041DCu; }
        if (ctx->pc != 0x1041DCu) { return; }
    }
    ctx->pc = 0x1041DCu;
label_1041dc:
    // 0x1041dc: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x1041dcu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1041e0: 0x108043  sra         $s0, $s0, 1
    ctx->pc = 0x1041e0u;
    SET_GPR_S32(ctx, 16, SRA32(GPR_S32(ctx, 16), 1));
label_1041e4:
    // 0x1041e4: 0x1600fff6  bnez        $s0, . + 4 + (-0xA << 2)
    ctx->pc = 0x1041E4u;
    {
        const bool branch_taken_0x1041e4 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x1041E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1041E4u;
            // 0x1041e8: 0x26520008  addiu       $s2, $s2, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1041e4) {
            ctx->pc = 0x1041C0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1041c0;
        }
    }
    ctx->pc = 0x1041ECu;
label_1041ec:
    // 0x1041ec: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x1041ecu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1041f0: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1041f0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1041f4: 0xc04480e  jal         func_112038
    ctx->pc = 0x1041F4u;
    SET_GPR_U32(ctx, 31, 0x1041FCu);
    ctx->pc = 0x112038u;
    if (runtime->hasFunction(0x112038u)) {
        auto targetFn = runtime->lookupFunction(0x112038u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1041FCu; }
        if (ctx->pc != 0x1041FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112038_0x112038(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1041FCu; }
        if (ctx->pc != 0x1041FCu) { return; }
    }
    ctx->pc = 0x1041FCu;
label_1041fc:
    // 0x1041fc: 0x1000001b  b           . + 4 + (0x1B << 2)
    ctx->pc = 0x1041FCu;
    {
        const bool branch_taken_0x1041fc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x104200u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1041FCu;
            // 0x104200: 0x40a02d  daddu       $s4, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1041fc) {
            ctx->pc = 0x10426Cu;
            goto label_10426c;
        }
    }
    ctx->pc = 0x104204u;
    // 0x104204: 0x0  nop
    ctx->pc = 0x104204u;
    // NOP
label_104208:
    // 0x104208: 0x1e8823  negu        $s1, $fp
    ctx->pc = 0x104208u;
    SET_GPR_S32(ctx, 17, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 30)));
    // 0x10420c: 0x12200017  beqz        $s1, . + 4 + (0x17 << 2)
    ctx->pc = 0x10420Cu;
    {
        const bool branch_taken_0x10420c = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x104210u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10420Cu;
            // 0x104210: 0x3222000f  andi        $v0, $s1, 0xF (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)15);
        ctx->in_delay_slot = false;
        if (branch_taken_0x10420c) {
            ctx->pc = 0x10426Cu;
            goto label_10426c;
        }
    }
    ctx->pc = 0x104214u;
    // 0x104214: 0x280282d  daddu       $a1, $s4, $zero
    ctx->pc = 0x104214u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x104218: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x104218u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x10421c: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x10421cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x104220: 0x822021  addu        $a0, $a0, $v0
    ctx->pc = 0x104220u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x104224: 0xdc847928  ld          $a0, 0x7928($a0)
    ctx->pc = 0x104224u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 4), 31016)));
    // 0x104228: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x104228u;
    SET_GPR_U32(ctx, 31, 0x104230u);
    ctx->pc = 0x10422Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x104228u;
            // 0x10422c: 0x118103  sra         $s0, $s1, 4 (Delay Slot)
        SET_GPR_S32(ctx, 16, SRA32(GPR_S32(ctx, 17), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104230u; }
        if (ctx->pc != 0x104230u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104230u; }
        if (ctx->pc != 0x104230u) { return; }
    }
    ctx->pc = 0x104230u;
label_104230:
    // 0x104230: 0x1200000e  beqz        $s0, . + 4 + (0xE << 2)
    ctx->pc = 0x104230u;
    {
        const bool branch_taken_0x104230 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x104234u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x104230u;
            // 0x104234: 0x40a02d  daddu       $s4, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x104230) {
            ctx->pc = 0x10426Cu;
            goto label_10426c;
        }
    }
    ctx->pc = 0x104238u;
    // 0x104238: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x104238u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x10423c: 0x245179f0  addiu       $s1, $v0, 0x79F0
    ctx->pc = 0x10423cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), 31216));
label_104240:
    // 0x104240: 0x32020001  andi        $v0, $s0, 0x1
    ctx->pc = 0x104240u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)1);
    // 0x104244: 0x50400007  beql        $v0, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x104244u;
    {
        const bool branch_taken_0x104244 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x104244) {
            ctx->pc = 0x104248u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x104244u;
            // 0x104248: 0x108043  sra         $s0, $s0, 1 (Delay Slot)
        SET_GPR_S32(ctx, 16, SRA32(GPR_S32(ctx, 16), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x104264u;
            goto label_104264;
        }
    }
    ctx->pc = 0x10424Cu;
    // 0x10424c: 0xde240000  ld          $a0, 0x0($s1)
    ctx->pc = 0x10424cu;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x104250: 0x280282d  daddu       $a1, $s4, $zero
    ctx->pc = 0x104250u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x104254: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x104254u;
    SET_GPR_U32(ctx, 31, 0x10425Cu);
    ctx->pc = 0x104258u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x104254u;
            // 0x104258: 0x26730001  addiu       $s3, $s3, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10425Cu; }
        if (ctx->pc != 0x10425Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10425Cu; }
        if (ctx->pc != 0x10425Cu) { return; }
    }
    ctx->pc = 0x10425Cu;
label_10425c:
    // 0x10425c: 0x40a02d  daddu       $s4, $v0, $zero
    ctx->pc = 0x10425cu;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x104260: 0x108043  sra         $s0, $s0, 1
    ctx->pc = 0x104260u;
    SET_GPR_S32(ctx, 16, SRA32(GPR_S32(ctx, 16), 1));
label_104264:
    // 0x104264: 0x1600fff6  bnez        $s0, . + 4 + (-0xA << 2)
    ctx->pc = 0x104264u;
    {
        const bool branch_taken_0x104264 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x104268u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x104264u;
            // 0x104268: 0x26310008  addiu       $s1, $s1, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x104264) {
            ctx->pc = 0x104240u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_104240;
        }
    }
    ctx->pc = 0x10426Cu;
label_10426c:
    // 0x10426c: 0x8fa20030  lw          $v0, 0x30($sp)
    ctx->pc = 0x10426cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x104270: 0x10400015  beqz        $v0, . + 4 + (0x15 << 2)
    ctx->pc = 0x104270u;
    {
        const bool branch_taken_0x104270 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x104270) {
            ctx->pc = 0x1042C8u;
            goto label_1042c8;
        }
    }
    ctx->pc = 0x104278u;
    // 0x104278: 0x3405ffc0  ori         $a1, $zero, 0xFFC0
    ctx->pc = 0x104278u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65472);
    // 0x10427c: 0x52bbc  dsll32      $a1, $a1, 14
    ctx->pc = 0x10427cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 14));
    // 0x104280: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x104280u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x104284: 0xc0448a6  jal         func_112298
    ctx->pc = 0x104284u;
    SET_GPR_U32(ctx, 31, 0x10428Cu);
    ctx->pc = 0x112298u;
    if (runtime->hasFunction(0x112298u)) {
        auto targetFn = runtime->lookupFunction(0x112298u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10428Cu; }
        if (ctx->pc != 0x10428Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112298_0x112298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10428Cu; }
        if (ctx->pc != 0x10428Cu) { return; }
    }
    ctx->pc = 0x10428Cu;
label_10428c:
    // 0x10428c: 0x441000e  bgez        $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x10428Cu;
    {
        const bool branch_taken_0x10428c = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x104290u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10428Cu;
            // 0x104290: 0x8fa30020  lw          $v1, 0x20($sp) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10428c) {
            ctx->pc = 0x1042C8u;
            goto label_1042c8;
        }
    }
    ctx->pc = 0x104294u;
    // 0x104294: 0x1860000c  blez        $v1, . + 4 + (0xC << 2)
    ctx->pc = 0x104294u;
    {
        const bool branch_taken_0x104294 = (GPR_S64(ctx, 3) <= 0);
        ctx->pc = 0x104298u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x104294u;
            // 0x104298: 0x8fa40028  lw          $a0, 0x28($sp) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x104294) {
            ctx->pc = 0x1042C8u;
            goto label_1042c8;
        }
    }
    ctx->pc = 0x10429Cu;
    // 0x10429c: 0x188000bc  blez        $a0, . + 4 + (0xBC << 2)
    ctx->pc = 0x10429Cu;
    {
        const bool branch_taken_0x10429c = (GPR_S64(ctx, 4) <= 0);
        ctx->pc = 0x1042A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10429Cu;
            // 0x1042a0: 0x8fa20024  lw          $v0, 0x24($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10429c) {
            ctx->pc = 0x104590u;
            goto label_104590;
        }
    }
    ctx->pc = 0x1042A4u;
    // 0x1042a4: 0x8fa20028  lw          $v0, 0x28($sp)
    ctx->pc = 0x1042a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1042a8: 0x280282d  daddu       $a1, $s4, $zero
    ctx->pc = 0x1042a8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1042ac: 0x34048048  ori         $a0, $zero, 0x8048
    ctx->pc = 0x1042acu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32840);
    // 0x1042b0: 0x423fc  dsll32      $a0, $a0, 15
    ctx->pc = 0x1042b0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << (32 + 15));
    // 0x1042b4: 0x27deffff  addiu       $fp, $fp, -0x1
    ctx->pc = 0x1042b4u;
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 30), 4294967295));
    // 0x1042b8: 0xafa20020  sw          $v0, 0x20($sp)
    ctx->pc = 0x1042b8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 2));
    // 0x1042bc: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x1042BCu;
    SET_GPR_U32(ctx, 31, 0x1042C4u);
    ctx->pc = 0x1042C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1042BCu;
            // 0x1042c0: 0x26730001  addiu       $s3, $s3, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1042C4u; }
        if (ctx->pc != 0x1042C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1042C4u; }
        if (ctx->pc != 0x1042C4u) { return; }
    }
    ctx->pc = 0x1042C4u;
label_1042c4:
    // 0x1042c4: 0x40a02d  daddu       $s4, $v0, $zero
    ctx->pc = 0x1042c4u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_1042c8:
    // 0x1042c8: 0xc0448ba  jal         func_1122E8
    ctx->pc = 0x1042C8u;
    SET_GPR_U32(ctx, 31, 0x1042D0u);
    ctx->pc = 0x1042CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1042C8u;
            // 0x1042cc: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1122E8u;
    if (runtime->hasFunction(0x1122E8u)) {
        auto targetFn = runtime->lookupFunction(0x1122E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1042D0u; }
        if (ctx->pc != 0x1042D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001122E8_0x1122e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1042D0u; }
        if (ctx->pc != 0x1042D0u) { return; }
    }
    ctx->pc = 0x1042D0u;
label_1042d0:
    // 0x1042d0: 0x280282d  daddu       $a1, $s4, $zero
    ctx->pc = 0x1042d0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1042d4: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1042d4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1042d8: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x1042D8u;
    SET_GPR_U32(ctx, 31, 0x1042E0u);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1042E0u; }
        if (ctx->pc != 0x1042E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1042E0u; }
        if (ctx->pc != 0x1042E0u) { return; }
    }
    ctx->pc = 0x1042E0u;
label_1042e0:
    // 0x1042e0: 0x34058038  ori         $a1, $zero, 0x8038
    ctx->pc = 0x1042e0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32824);
    // 0x1042e4: 0x52bfc  dsll32      $a1, $a1, 15
    ctx->pc = 0x1042e4u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 15));
    // 0x1042e8: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1042e8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1042ec: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x1042ECu;
    SET_GPR_U32(ctx, 31, 0x1042F4u);
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1042F4u; }
        if (ctx->pc != 0x1042F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1042F4u; }
        if (ctx->pc != 0x1042F4u) { return; }
    }
    ctx->pc = 0x1042F4u;
label_1042f4:
    // 0x1042f4: 0x3c04ffff  lui         $a0, 0xFFFF
    ctx->pc = 0x1042f4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)65535 << 16));
    // 0x1042f8: 0x4203e  dsrl32      $a0, $a0, 0
    ctx->pc = 0x1042f8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) >> (32 + 0));
    // 0x1042fc: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x1042fcu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x104300: 0x3c02fcc0  lui         $v0, 0xFCC0
    ctx->pc = 0x104300u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)64704 << 16));
    // 0x104304: 0x12183f  dsra32      $v1, $s2, 0
    ctx->pc = 0x104304u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 18) >> (32 + 0));
    // 0x104308: 0x2449024  and         $s2, $s2, $a0
    ctx->pc = 0x104308u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) & GPR_U64(ctx, 4));
    // 0x10430c: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x10430cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x104310: 0x3183c  dsll32      $v1, $v1, 0
    ctx->pc = 0x104310u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x104314: 0x2439025  or          $s2, $s2, $v1
    ctx->pc = 0x104314u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 3));
    // 0x104318: 0x8fa30020  lw          $v1, 0x20($sp)
    ctx->pc = 0x104318u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x10431c: 0x1460001a  bnez        $v1, . + 4 + (0x1A << 2)
    ctx->pc = 0x10431Cu;
    {
        const bool branch_taken_0x10431c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x104320u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10431Cu;
            // 0x104320: 0x8fa40034  lw          $a0, 0x34($sp) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10431c) {
            ctx->pc = 0x104388u;
            goto label_104388;
        }
    }
    ctx->pc = 0x104324u;
    // 0x104324: 0x34058028  ori         $a1, $zero, 0x8028
    ctx->pc = 0x104324u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32808);
    // 0x104328: 0x52bfc  dsll32      $a1, $a1, 15
    ctx->pc = 0x104328u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 15));
    // 0x10432c: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x10432cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x104330: 0xafa0004c  sw          $zero, 0x4C($sp)
    ctx->pc = 0x104330u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 76), GPR_U32(ctx, 0));
    // 0x104334: 0xc044752  jal         func_111D48
    ctx->pc = 0x104334u;
    SET_GPR_U32(ctx, 31, 0x10433Cu);
    ctx->pc = 0x104338u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x104334u;
            // 0x104338: 0xafa00050  sw          $zero, 0x50($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 80), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111D48u;
    if (runtime->hasFunction(0x111D48u)) {
        auto targetFn = runtime->lookupFunction(0x111D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10433Cu; }
        if (ctx->pc != 0x10433Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111D48_0x111d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10433Cu; }
        if (ctx->pc != 0x10433Cu) { return; }
    }
    ctx->pc = 0x10433Cu;
label_10433c:
    // 0x10433c: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x10433cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x104340: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x104340u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x104344: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x104344u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x104348: 0xc0448a6  jal         func_112298
    ctx->pc = 0x104348u;
    SET_GPR_U32(ctx, 31, 0x104350u);
    ctx->pc = 0x112298u;
    if (runtime->hasFunction(0x112298u)) {
        auto targetFn = runtime->lookupFunction(0x112298u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104350u; }
        if (ctx->pc != 0x104350u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112298_0x112298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104350u; }
        if (ctx->pc != 0x104350u) { return; }
    }
    ctx->pc = 0x104350u;
label_104350:
    // 0x104350: 0x1c4001e3  bgtz        $v0, . + 4 + (0x1E3 << 2)
    ctx->pc = 0x104350u;
    {
        const bool branch_taken_0x104350 = (GPR_S64(ctx, 2) > 0);
        ctx->pc = 0x104354u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x104350u;
            // 0x104354: 0x8fa30054  lw          $v1, 0x54($sp) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 84)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x104350) {
            ctx->pc = 0x104AE0u;
            goto label_104ae0;
        }
    }
    ctx->pc = 0x104358u;
    // 0x104358: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x104358u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10435c: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x10435cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x104360: 0xc044752  jal         func_111D48
    ctx->pc = 0x104360u;
    SET_GPR_U32(ctx, 31, 0x104368u);
    ctx->pc = 0x111D48u;
    if (runtime->hasFunction(0x111D48u)) {
        auto targetFn = runtime->lookupFunction(0x111D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104368u; }
        if (ctx->pc != 0x104368u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111D48_0x111d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104368u; }
        if (ctx->pc != 0x104368u) { return; }
    }
    ctx->pc = 0x104368u;
label_104368:
    // 0x104368: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x104368u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10436c: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x10436cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x104370: 0xc0448a6  jal         func_112298
    ctx->pc = 0x104370u;
    SET_GPR_U32(ctx, 31, 0x104378u);
    ctx->pc = 0x112298u;
    if (runtime->hasFunction(0x112298u)) {
        auto targetFn = runtime->lookupFunction(0x112298u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104378u; }
        if (ctx->pc != 0x104378u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112298_0x112298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104378u; }
        if (ctx->pc != 0x104378u) { return; }
    }
    ctx->pc = 0x104378u;
label_104378:
    // 0x104378: 0x44001d5  bltz        $v0, . + 4 + (0x1D5 << 2)
    ctx->pc = 0x104378u;
    {
        const bool branch_taken_0x104378 = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x10437Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x104378u;
            // 0x10437c: 0x8fa20024  lw          $v0, 0x24($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x104378) {
            ctx->pc = 0x104AD0u;
            goto label_104ad0;
        }
    }
    ctx->pc = 0x104380u;
    // 0x104380: 0x10000083  b           . + 4 + (0x83 << 2)
    ctx->pc = 0x104380u;
    {
        const bool branch_taken_0x104380 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x104380) {
            ctx->pc = 0x104590u;
            goto label_104590;
        }
    }
    ctx->pc = 0x104388u;
label_104388:
    // 0x104388: 0x1080003f  beqz        $a0, . + 4 + (0x3F << 2)
    ctx->pc = 0x104388u;
    {
        const bool branch_taken_0x104388 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x10438Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x104388u;
            // 0x10438c: 0x8fa30020  lw          $v1, 0x20($sp) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x104388) {
            ctx->pc = 0x104488u;
            goto label_104488;
        }
    }
    ctx->pc = 0x104390u;
    // 0x104390: 0x3404ff80  ori         $a0, $zero, 0xFF80
    ctx->pc = 0x104390u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65408);
    // 0x104394: 0x423bc  dsll32      $a0, $a0, 14
    ctx->pc = 0x104394u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << (32 + 14));
    // 0x104398: 0x310c0  sll         $v0, $v1, 3
    ctx->pc = 0x104398u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x10439c: 0x3c050023  lui         $a1, 0x23
    ctx->pc = 0x10439cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)35 << 16));
    // 0x1043a0: 0xa22821  addu        $a1, $a1, $v0
    ctx->pc = 0x1043a0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x1043a4: 0xdca57920  ld          $a1, 0x7920($a1)
    ctx->pc = 0x1043a4u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 5), 31008)));
    // 0x1043a8: 0xc04480e  jal         func_112038
    ctx->pc = 0x1043A8u;
    SET_GPR_U32(ctx, 31, 0x1043B0u);
    ctx->pc = 0x1043ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1043A8u;
            // 0x1043ac: 0x982d  daddu       $s3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x112038u;
    if (runtime->hasFunction(0x112038u)) {
        auto targetFn = runtime->lookupFunction(0x112038u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1043B0u; }
        if (ctx->pc != 0x1043B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112038_0x112038(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1043B0u; }
        if (ctx->pc != 0x1043B0u) { return; }
    }
    ctx->pc = 0x1043B0u;
label_1043b0:
    // 0x1043b0: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x1043b0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1043b4: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1043b4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1043b8: 0xc044752  jal         func_111D48
    ctx->pc = 0x1043B8u;
    SET_GPR_U32(ctx, 31, 0x1043C0u);
    ctx->pc = 0x111D48u;
    if (runtime->hasFunction(0x111D48u)) {
        auto targetFn = runtime->lookupFunction(0x111D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1043C0u; }
        if (ctx->pc != 0x1043C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111D48_0x111d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1043C0u; }
        if (ctx->pc != 0x1043C0u) { return; }
    }
    ctx->pc = 0x1043C0u;
label_1043c0:
    // 0x1043c0: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x1043C0u;
    {
        const bool branch_taken_0x1043c0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1043C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1043C0u;
            // 0x1043c4: 0x40902d  daddu       $s2, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1043c0) {
            ctx->pc = 0x1043F4u;
            goto label_1043f4;
        }
    }
    ctx->pc = 0x1043C8u;
label_1043c8:
    // 0x1043c8: 0x34048048  ori         $a0, $zero, 0x8048
    ctx->pc = 0x1043c8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32840);
    // 0x1043cc: 0x423fc  dsll32      $a0, $a0, 15
    ctx->pc = 0x1043ccu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << (32 + 15));
    // 0x1043d0: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x1043d0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1043d4: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x1043D4u;
    SET_GPR_U32(ctx, 31, 0x1043DCu);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1043DCu; }
        if (ctx->pc != 0x1043DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1043DCu; }
        if (ctx->pc != 0x1043DCu) { return; }
    }
    ctx->pc = 0x1043DCu;
label_1043dc:
    // 0x1043dc: 0x34048048  ori         $a0, $zero, 0x8048
    ctx->pc = 0x1043dcu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32840);
    // 0x1043e0: 0x423fc  dsll32      $a0, $a0, 15
    ctx->pc = 0x1043e0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << (32 + 15));
    // 0x1043e4: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1043e4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1043e8: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x1043E8u;
    SET_GPR_U32(ctx, 31, 0x1043F0u);
    ctx->pc = 0x1043ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1043E8u;
            // 0x1043ec: 0x40902d  daddu       $s2, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1043F0u; }
        if (ctx->pc != 0x1043F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1043F0u; }
        if (ctx->pc != 0x1043F0u) { return; }
    }
    ctx->pc = 0x1043F0u;
label_1043f0:
    // 0x1043f0: 0x40a02d  daddu       $s4, $v0, $zero
    ctx->pc = 0x1043f0u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_1043f4:
    // 0x1043f4: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x1043f4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1043f8: 0xc0448e8  jal         func_1123A0
    ctx->pc = 0x1043F8u;
    SET_GPR_U32(ctx, 31, 0x104400u);
    ctx->pc = 0x1123A0u;
    if (runtime->hasFunction(0x1123A0u)) {
        auto targetFn = runtime->lookupFunction(0x1123A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104400u; }
        if (ctx->pc != 0x104400u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001123A0_0x1123a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104400u; }
        if (ctx->pc != 0x104400u) { return; }
    }
    ctx->pc = 0x104400u;
label_104400:
    // 0x104400: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x104400u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x104404: 0xc0448ba  jal         func_1122E8
    ctx->pc = 0x104404u;
    SET_GPR_U32(ctx, 31, 0x10440Cu);
    ctx->pc = 0x104408u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x104404u;
            // 0x104408: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1122E8u;
    if (runtime->hasFunction(0x1122E8u)) {
        auto targetFn = runtime->lookupFunction(0x1122E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10440Cu; }
        if (ctx->pc != 0x10440Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001122E8_0x1122e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10440Cu; }
        if (ctx->pc != 0x10440Cu) { return; }
    }
    ctx->pc = 0x10440Cu;
label_10440c:
    // 0x10440c: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x10440cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x104410: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x104410u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x104414: 0xc044752  jal         func_111D48
    ctx->pc = 0x104414u;
    SET_GPR_U32(ctx, 31, 0x10441Cu);
    ctx->pc = 0x111D48u;
    if (runtime->hasFunction(0x111D48u)) {
        auto targetFn = runtime->lookupFunction(0x111D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10441Cu; }
        if (ctx->pc != 0x10441Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111D48_0x111d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10441Cu; }
        if (ctx->pc != 0x10441Cu) { return; }
    }
    ctx->pc = 0x10441Cu;
label_10441c:
    // 0x10441c: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x10441cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x104420: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x104420u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x104424: 0x26020030  addiu       $v0, $s0, 0x30
    ctx->pc = 0x104424u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 48));
    // 0x104428: 0xa2a20000  sb          $v0, 0x0($s5)
    ctx->pc = 0x104428u;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x10442c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x10442cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x104430: 0xc0448a6  jal         func_112298
    ctx->pc = 0x104430u;
    SET_GPR_U32(ctx, 31, 0x104438u);
    ctx->pc = 0x104434u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x104430u;
            // 0x104434: 0x26b50001  addiu       $s5, $s5, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x112298u;
    if (runtime->hasFunction(0x112298u)) {
        auto targetFn = runtime->lookupFunction(0x112298u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104438u; }
        if (ctx->pc != 0x104438u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112298_0x112298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104438u; }
        if (ctx->pc != 0x104438u) { return; }
    }
    ctx->pc = 0x104438u;
label_104438:
    // 0x104438: 0x4400292  bltz        $v0, . + 4 + (0x292 << 2)
    ctx->pc = 0x104438u;
    {
        const bool branch_taken_0x104438 = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x10443Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x104438u;
            // 0x10443c: 0x8fa50044  lw          $a1, 0x44($sp) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 68)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x104438) {
            ctx->pc = 0x104E84u;
            goto label_104e84;
        }
    }
    ctx->pc = 0x104440u;
    // 0x104440: 0x3404ffc0  ori         $a0, $zero, 0xFFC0
    ctx->pc = 0x104440u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65472);
    // 0x104444: 0x423bc  dsll32      $a0, $a0, 14
    ctx->pc = 0x104444u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << (32 + 14));
    // 0x104448: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x104448u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10444c: 0xc044752  jal         func_111D48
    ctx->pc = 0x10444Cu;
    SET_GPR_U32(ctx, 31, 0x104454u);
    ctx->pc = 0x111D48u;
    if (runtime->hasFunction(0x111D48u)) {
        auto targetFn = runtime->lookupFunction(0x111D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104454u; }
        if (ctx->pc != 0x104454u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111D48_0x111d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104454u; }
        if (ctx->pc != 0x104454u) { return; }
    }
    ctx->pc = 0x104454u;
label_104454:
    // 0x104454: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x104454u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x104458: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x104458u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10445c: 0xc0448a6  jal         func_112298
    ctx->pc = 0x10445Cu;
    SET_GPR_U32(ctx, 31, 0x104464u);
    ctx->pc = 0x112298u;
    if (runtime->hasFunction(0x112298u)) {
        auto targetFn = runtime->lookupFunction(0x112298u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104464u; }
        if (ctx->pc != 0x104464u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112298_0x112298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104464u; }
        if (ctx->pc != 0x104464u) { return; }
    }
    ctx->pc = 0x104464u;
label_104464:
    // 0x104464: 0x4400099  bltz        $v0, . + 4 + (0x99 << 2)
    ctx->pc = 0x104464u;
    {
        const bool branch_taken_0x104464 = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x104468u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x104464u;
            // 0x104468: 0x24030039  addiu       $v1, $zero, 0x39 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 57));
        ctx->in_delay_slot = false;
        if (branch_taken_0x104464) {
            ctx->pc = 0x1046CCu;
            goto label_1046cc;
        }
    }
    ctx->pc = 0x10446Cu;
    // 0x10446c: 0x8fa40020  lw          $a0, 0x20($sp)
    ctx->pc = 0x10446cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x104470: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x104470u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
    // 0x104474: 0x264102a  slt         $v0, $s3, $a0
    ctx->pc = 0x104474u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)GPR_S64(ctx, 4)) ? 1 : 0);
    // 0x104478: 0x1440ffd3  bnez        $v0, . + 4 + (-0x2D << 2)
    ctx->pc = 0x104478u;
    {
        const bool branch_taken_0x104478 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10447Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x104478u;
            // 0x10447c: 0x8fa20024  lw          $v0, 0x24($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x104478) {
            ctx->pc = 0x1043C8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1043c8;
        }
    }
    ctx->pc = 0x104480u;
    // 0x104480: 0x10000043  b           . + 4 + (0x43 << 2)
    ctx->pc = 0x104480u;
    {
        const bool branch_taken_0x104480 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x104480) {
            ctx->pc = 0x104590u;
            goto label_104590;
        }
    }
    ctx->pc = 0x104488u;
label_104488:
    // 0x104488: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x104488u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10448c: 0x310c0  sll         $v0, $v1, 3
    ctx->pc = 0x10448cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x104490: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x104490u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x104494: 0x822021  addu        $a0, $a0, $v0
    ctx->pc = 0x104494u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x104498: 0xdc847920  ld          $a0, 0x7920($a0)
    ctx->pc = 0x104498u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 4), 31008)));
    // 0x10449c: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x10449Cu;
    SET_GPR_U32(ctx, 31, 0x1044A4u);
    ctx->pc = 0x1044A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10449Cu;
            // 0x1044a0: 0x24130001  addiu       $s3, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1044A4u; }
        if (ctx->pc != 0x1044A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1044A4u; }
        if (ctx->pc != 0x1044A4u) { return; }
    }
    ctx->pc = 0x1044A4u;
label_1044a4:
    // 0x1044a4: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x1044a4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_1044a8:
    // 0x1044a8: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x1044a8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1044ac: 0xc0448e8  jal         func_1123A0
    ctx->pc = 0x1044ACu;
    SET_GPR_U32(ctx, 31, 0x1044B4u);
    ctx->pc = 0x1123A0u;
    if (runtime->hasFunction(0x1123A0u)) {
        auto targetFn = runtime->lookupFunction(0x1123A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1044B4u; }
        if (ctx->pc != 0x1044B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001123A0_0x1123a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1044B4u; }
        if (ctx->pc != 0x1044B4u) { return; }
    }
    ctx->pc = 0x1044B4u;
label_1044b4:
    // 0x1044b4: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1044b4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1044b8: 0xc0448ba  jal         func_1122E8
    ctx->pc = 0x1044B8u;
    SET_GPR_U32(ctx, 31, 0x1044C0u);
    ctx->pc = 0x1044BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1044B8u;
            // 0x1044bc: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1122E8u;
    if (runtime->hasFunction(0x1122E8u)) {
        auto targetFn = runtime->lookupFunction(0x1122E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1044C0u; }
        if (ctx->pc != 0x1044C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001122E8_0x1122e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1044C0u; }
        if (ctx->pc != 0x1044C0u) { return; }
    }
    ctx->pc = 0x1044C0u;
label_1044c0:
    // 0x1044c0: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x1044c0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1044c4: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1044c4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1044c8: 0xc044752  jal         func_111D48
    ctx->pc = 0x1044C8u;
    SET_GPR_U32(ctx, 31, 0x1044D0u);
    ctx->pc = 0x111D48u;
    if (runtime->hasFunction(0x111D48u)) {
        auto targetFn = runtime->lookupFunction(0x111D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1044D0u; }
        if (ctx->pc != 0x1044D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111D48_0x111d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1044D0u; }
        if (ctx->pc != 0x1044D0u) { return; }
    }
    ctx->pc = 0x1044D0u;
label_1044d0:
    // 0x1044d0: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x1044d0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1044d4: 0x26020030  addiu       $v0, $s0, 0x30
    ctx->pc = 0x1044d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 48));
    // 0x1044d8: 0xa2a20000  sb          $v0, 0x0($s5)
    ctx->pc = 0x1044d8u;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1044dc: 0x8fa40020  lw          $a0, 0x20($sp)
    ctx->pc = 0x1044dcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1044e0: 0x16640023  bne         $s3, $a0, . + 4 + (0x23 << 2)
    ctx->pc = 0x1044E0u;
    {
        const bool branch_taken_0x1044e0 = (GPR_U64(ctx, 19) != GPR_U64(ctx, 4));
        ctx->pc = 0x1044E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1044E0u;
            // 0x1044e4: 0x26b50001  addiu       $s5, $s5, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1044e0) {
            ctx->pc = 0x104570u;
            goto label_104570;
        }
    }
    ctx->pc = 0x1044E8u;
    // 0x1044e8: 0x3404ff80  ori         $a0, $zero, 0xFF80
    ctx->pc = 0x1044e8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65408);
    // 0x1044ec: 0x423bc  dsll32      $a0, $a0, 14
    ctx->pc = 0x1044ecu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << (32 + 14));
    // 0x1044f0: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x1044f0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1044f4: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x1044F4u;
    SET_GPR_U32(ctx, 31, 0x1044FCu);
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1044FCu; }
        if (ctx->pc != 0x1044FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1044FCu; }
        if (ctx->pc != 0x1044FCu) { return; }
    }
    ctx->pc = 0x1044FCu;
label_1044fc:
    // 0x1044fc: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1044fcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x104500: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x104500u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x104504: 0xc0448a6  jal         func_112298
    ctx->pc = 0x104504u;
    SET_GPR_U32(ctx, 31, 0x10450Cu);
    ctx->pc = 0x112298u;
    if (runtime->hasFunction(0x112298u)) {
        auto targetFn = runtime->lookupFunction(0x112298u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10450Cu; }
        if (ctx->pc != 0x10450Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112298_0x112298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10450Cu; }
        if (ctx->pc != 0x10450Cu) { return; }
    }
    ctx->pc = 0x10450Cu;
label_10450c:
    // 0x10450c: 0x1c40006f  bgtz        $v0, . + 4 + (0x6F << 2)
    ctx->pc = 0x10450Cu;
    {
        const bool branch_taken_0x10450c = (GPR_S64(ctx, 2) > 0);
        ctx->pc = 0x104510u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10450Cu;
            // 0x104510: 0x24030039  addiu       $v1, $zero, 0x39 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 57));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10450c) {
            ctx->pc = 0x1046CCu;
            goto label_1046cc;
        }
    }
    ctx->pc = 0x104514u;
    // 0x104514: 0x3404ff80  ori         $a0, $zero, 0xFF80
    ctx->pc = 0x104514u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65408);
    // 0x104518: 0x423bc  dsll32      $a0, $a0, 14
    ctx->pc = 0x104518u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << (32 + 14));
    // 0x10451c: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x10451cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x104520: 0xc044752  jal         func_111D48
    ctx->pc = 0x104520u;
    SET_GPR_U32(ctx, 31, 0x104528u);
    ctx->pc = 0x111D48u;
    if (runtime->hasFunction(0x111D48u)) {
        auto targetFn = runtime->lookupFunction(0x111D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104528u; }
        if (ctx->pc != 0x104528u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111D48_0x111d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104528u; }
        if (ctx->pc != 0x104528u) { return; }
    }
    ctx->pc = 0x104528u;
label_104528:
    // 0x104528: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x104528u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10452c: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x10452cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x104530: 0xc0448a6  jal         func_112298
    ctx->pc = 0x104530u;
    SET_GPR_U32(ctx, 31, 0x104538u);
    ctx->pc = 0x112298u;
    if (runtime->hasFunction(0x112298u)) {
        auto targetFn = runtime->lookupFunction(0x112298u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104538u; }
        if (ctx->pc != 0x104538u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112298_0x112298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104538u; }
        if (ctx->pc != 0x104538u) { return; }
    }
    ctx->pc = 0x104538u;
label_104538:
    // 0x104538: 0x4410015  bgez        $v0, . + 4 + (0x15 << 2)
    ctx->pc = 0x104538u;
    {
        const bool branch_taken_0x104538 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x10453Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x104538u;
            // 0x10453c: 0x8fa20024  lw          $v0, 0x24($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x104538) {
            ctx->pc = 0x104590u;
            goto label_104590;
        }
    }
    ctx->pc = 0x104540u;
    // 0x104540: 0x24030030  addiu       $v1, $zero, 0x30
    ctx->pc = 0x104540u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 48));
    // 0x104544: 0x26b5ffff  addiu       $s5, $s5, -0x1
    ctx->pc = 0x104544u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), 4294967295));
label_104548:
    // 0x104548: 0x82a20000  lb          $v0, 0x0($s5)
    ctx->pc = 0x104548u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 21), 0)));
    // 0x10454c: 0x0  nop
    ctx->pc = 0x10454cu;
    // NOP
    // 0x104550: 0x0  nop
    ctx->pc = 0x104550u;
    // NOP
    // 0x104554: 0x0  nop
    ctx->pc = 0x104554u;
    // NOP
    // 0x104558: 0x0  nop
    ctx->pc = 0x104558u;
    // NOP
    // 0x10455c: 0x5043fffa  beql        $v0, $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x10455Cu;
    {
        const bool branch_taken_0x10455c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x10455c) {
            ctx->pc = 0x104560u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10455Cu;
            // 0x104560: 0x26b5ffff  addiu       $s5, $s5, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), 4294967295));
        ctx->in_delay_slot = false;
            ctx->pc = 0x104548u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_104548;
        }
    }
    ctx->pc = 0x104564u;
    // 0x104564: 0x10000246  b           . + 4 + (0x246 << 2)
    ctx->pc = 0x104564u;
    {
        const bool branch_taken_0x104564 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x104568u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x104564u;
            // 0x104568: 0x26b50001  addiu       $s5, $s5, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x104564) {
            ctx->pc = 0x104E80u;
            goto label_104e80;
        }
    }
    ctx->pc = 0x10456Cu;
    // 0x10456c: 0x0  nop
    ctx->pc = 0x10456cu;
    // NOP
label_104570:
    // 0x104570: 0x34048048  ori         $a0, $zero, 0x8048
    ctx->pc = 0x104570u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32840);
    // 0x104574: 0x423fc  dsll32      $a0, $a0, 15
    ctx->pc = 0x104574u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << (32 + 15));
    // 0x104578: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x104578u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10457c: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x10457Cu;
    SET_GPR_U32(ctx, 31, 0x104584u);
    ctx->pc = 0x104580u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10457Cu;
            // 0x104580: 0x26730001  addiu       $s3, $s3, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104584u; }
        if (ctx->pc != 0x104584u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104584u; }
        if (ctx->pc != 0x104584u) { return; }
    }
    ctx->pc = 0x104584u;
label_104584:
    // 0x104584: 0x1000ffc8  b           . + 4 + (-0x38 << 2)
    ctx->pc = 0x104584u;
    {
        const bool branch_taken_0x104584 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x104588u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x104584u;
            // 0x104588: 0x40a02d  daddu       $s4, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x104584) {
            ctx->pc = 0x1044A8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1044a8;
        }
    }
    ctx->pc = 0x10458Cu;
    // 0x10458c: 0x0  nop
    ctx->pc = 0x10458cu;
    // NOP
label_104590:
    // 0x104590: 0x2c0a02d  daddu       $s4, $s6, $zero
    ctx->pc = 0x104590u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x104594: 0x8fbe002c  lw          $fp, 0x2C($sp)
    ctx->pc = 0x104594u;
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x104598: 0xafa20020  sw          $v0, 0x20($sp)
    ctx->pc = 0x104598u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 2));
    // 0x10459c: 0x8fb50054  lw          $s5, 0x54($sp)
    ctx->pc = 0x10459cu;
    SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 84)));
label_1045a0:
    // 0x1045a0: 0x8fa30000  lw          $v1, 0x0($sp)
    ctx->pc = 0x1045a0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
label_1045a4:
    // 0x1045a4: 0x460006a  bltz        $v1, . + 4 + (0x6A << 2)
    ctx->pc = 0x1045A4u;
    {
        const bool branch_taken_0x1045a4 = (GPR_S64(ctx, 3) < 0);
        ctx->pc = 0x1045A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1045A4u;
            // 0x1045a8: 0x2bc2000f  slti        $v0, $fp, 0xF (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 30) < (int64_t)(int32_t)15) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1045a4) {
            ctx->pc = 0x104750u;
            goto label_104750;
        }
    }
    ctx->pc = 0x1045ACu;
    // 0x1045ac: 0x10400069  beqz        $v0, . + 4 + (0x69 << 2)
    ctx->pc = 0x1045ACu;
    {
        const bool branch_taken_0x1045ac = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1045B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1045ACu;
            // 0x1045b0: 0x8fa20008  lw          $v0, 0x8($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1045ac) {
            ctx->pc = 0x104754u;
            goto label_104754;
        }
    }
    ctx->pc = 0x1045B4u;
    // 0x1045b4: 0x8fa3000c  lw          $v1, 0xC($sp)
    ctx->pc = 0x1045b4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 12)));
    // 0x1045b8: 0x1e10c0  sll         $v0, $fp, 3
    ctx->pc = 0x1045b8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 30), 3));
    // 0x1045bc: 0x3c110023  lui         $s1, 0x23
    ctx->pc = 0x1045bcu;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)35 << 16));
    // 0x1045c0: 0x2228821  addu        $s1, $s1, $v0
    ctx->pc = 0x1045c0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 2)));
    // 0x1045c4: 0xde317928  ld          $s1, 0x7928($s1)
    ctx->pc = 0x1045c4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 17), 31016)));
    // 0x1045c8: 0x4610015  bgez        $v1, . + 4 + (0x15 << 2)
    ctx->pc = 0x1045C8u;
    {
        const bool branch_taken_0x1045c8 = (GPR_S64(ctx, 3) >= 0);
        ctx->pc = 0x1045CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1045C8u;
            // 0x1045cc: 0x24130001  addiu       $s3, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1045c8) {
            ctx->pc = 0x104620u;
            goto label_104620;
        }
    }
    ctx->pc = 0x1045D0u;
    // 0x1045d0: 0x8fa40020  lw          $a0, 0x20($sp)
    ctx->pc = 0x1045d0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1045d4: 0x1c800012  bgtz        $a0, . + 4 + (0x12 << 2)
    ctx->pc = 0x1045D4u;
    {
        const bool branch_taken_0x1045d4 = (GPR_S64(ctx, 4) > 0);
        if (branch_taken_0x1045d4) {
            ctx->pc = 0x104620u;
            goto label_104620;
        }
    }
    ctx->pc = 0x1045DCu;
    // 0x1045dc: 0xafa0004c  sw          $zero, 0x4C($sp)
    ctx->pc = 0x1045dcu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 76), GPR_U32(ctx, 0));
    // 0x1045e0: 0x480013b  bltz        $a0, . + 4 + (0x13B << 2)
    ctx->pc = 0x1045E0u;
    {
        const bool branch_taken_0x1045e0 = (GPR_S64(ctx, 4) < 0);
        ctx->pc = 0x1045E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1045E0u;
            // 0x1045e4: 0xafa00050  sw          $zero, 0x50($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 80), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1045e0) {
            ctx->pc = 0x104AD0u;
            goto label_104ad0;
        }
    }
    ctx->pc = 0x1045E8u;
    // 0x1045e8: 0x34058028  ori         $a1, $zero, 0x8028
    ctx->pc = 0x1045e8u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32808);
    // 0x1045ec: 0x52bfc  dsll32      $a1, $a1, 15
    ctx->pc = 0x1045ecu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 15));
    // 0x1045f0: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1045f0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1045f4: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x1045F4u;
    SET_GPR_U32(ctx, 31, 0x1045FCu);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1045FCu; }
        if (ctx->pc != 0x1045FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1045FCu; }
        if (ctx->pc != 0x1045FCu) { return; }
    }
    ctx->pc = 0x1045FCu;
label_1045fc:
    // 0x1045fc: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x1045fcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x104600: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x104600u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x104604: 0xc0448a6  jal         func_112298
    ctx->pc = 0x104604u;
    SET_GPR_U32(ctx, 31, 0x10460Cu);
    ctx->pc = 0x112298u;
    if (runtime->hasFunction(0x112298u)) {
        auto targetFn = runtime->lookupFunction(0x112298u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10460Cu; }
        if (ctx->pc != 0x10460Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112298_0x112298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10460Cu; }
        if (ctx->pc != 0x10460Cu) { return; }
    }
    ctx->pc = 0x10460Cu;
label_10460c:
    // 0x10460c: 0x18400131  blez        $v0, . + 4 + (0x131 << 2)
    ctx->pc = 0x10460Cu;
    {
        const bool branch_taken_0x10460c = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x104610u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10460Cu;
            // 0x104610: 0x8fa2000c  lw          $v0, 0xC($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 12)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10460c) {
            ctx->pc = 0x104AD4u;
            goto label_104ad4;
        }
    }
    ctx->pc = 0x104614u;
    // 0x104614: 0x10000132  b           . + 4 + (0x132 << 2)
    ctx->pc = 0x104614u;
    {
        const bool branch_taken_0x104614 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x104618u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x104614u;
            // 0x104618: 0x8fa30054  lw          $v1, 0x54($sp) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 84)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x104614) {
            ctx->pc = 0x104AE0u;
            goto label_104ae0;
        }
    }
    ctx->pc = 0x10461Cu;
    // 0x10461c: 0x0  nop
    ctx->pc = 0x10461cu;
    // NOP
label_104620:
    // 0x104620: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x104620u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x104624: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x104624u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x104628: 0xc04480e  jal         func_112038
    ctx->pc = 0x104628u;
    SET_GPR_U32(ctx, 31, 0x104630u);
    ctx->pc = 0x112038u;
    if (runtime->hasFunction(0x112038u)) {
        auto targetFn = runtime->lookupFunction(0x112038u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104630u; }
        if (ctx->pc != 0x104630u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112038_0x112038(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104630u; }
        if (ctx->pc != 0x104630u) { return; }
    }
    ctx->pc = 0x104630u;
label_104630:
    // 0x104630: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x104630u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x104634: 0xc0448e8  jal         func_1123A0
    ctx->pc = 0x104634u;
    SET_GPR_U32(ctx, 31, 0x10463Cu);
    ctx->pc = 0x1123A0u;
    if (runtime->hasFunction(0x1123A0u)) {
        auto targetFn = runtime->lookupFunction(0x1123A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10463Cu; }
        if (ctx->pc != 0x10463Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001123A0_0x1123a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10463Cu; }
        if (ctx->pc != 0x10463Cu) { return; }
    }
    ctx->pc = 0x10463Cu;
label_10463c:
    // 0x10463c: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x10463cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x104640: 0xc0448ba  jal         func_1122E8
    ctx->pc = 0x104640u;
    SET_GPR_U32(ctx, 31, 0x104648u);
    ctx->pc = 0x104644u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x104640u;
            // 0x104644: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1122E8u;
    if (runtime->hasFunction(0x1122E8u)) {
        auto targetFn = runtime->lookupFunction(0x1122E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104648u; }
        if (ctx->pc != 0x104648u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001122E8_0x1122e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104648u; }
        if (ctx->pc != 0x104648u) { return; }
    }
    ctx->pc = 0x104648u;
label_104648:
    // 0x104648: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x104648u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10464c: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x10464cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x104650: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x104650u;
    SET_GPR_U32(ctx, 31, 0x104658u);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104658u; }
        if (ctx->pc != 0x104658u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104658u; }
        if (ctx->pc != 0x104658u) { return; }
    }
    ctx->pc = 0x104658u;
label_104658:
    // 0x104658: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x104658u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10465c: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x10465cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x104660: 0xc044752  jal         func_111D48
    ctx->pc = 0x104660u;
    SET_GPR_U32(ctx, 31, 0x104668u);
    ctx->pc = 0x111D48u;
    if (runtime->hasFunction(0x111D48u)) {
        auto targetFn = runtime->lookupFunction(0x111D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104668u; }
        if (ctx->pc != 0x104668u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111D48_0x111d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104668u; }
        if (ctx->pc != 0x104668u) { return; }
    }
    ctx->pc = 0x104668u;
label_104668:
    // 0x104668: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x104668u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10466c: 0x26020030  addiu       $v0, $s0, 0x30
    ctx->pc = 0x10466cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 48));
    // 0x104670: 0xa2a20000  sb          $v0, 0x0($s5)
    ctx->pc = 0x104670u;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x104674: 0x8fa20020  lw          $v0, 0x20($sp)
    ctx->pc = 0x104674u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x104678: 0x16620027  bne         $s3, $v0, . + 4 + (0x27 << 2)
    ctx->pc = 0x104678u;
    {
        const bool branch_taken_0x104678 = (GPR_U64(ctx, 19) != GPR_U64(ctx, 2));
        ctx->pc = 0x10467Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x104678u;
            // 0x10467c: 0x26b50001  addiu       $s5, $s5, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x104678) {
            ctx->pc = 0x104718u;
            goto label_104718;
        }
    }
    ctx->pc = 0x104680u;
    // 0x104680: 0xa0202d  daddu       $a0, $a1, $zero
    ctx->pc = 0x104680u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x104684: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x104684u;
    SET_GPR_U32(ctx, 31, 0x10468Cu);
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10468Cu; }
        if (ctx->pc != 0x10468Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10468Cu; }
        if (ctx->pc != 0x10468Cu) { return; }
    }
    ctx->pc = 0x10468Cu;
label_10468c:
    // 0x10468c: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x10468cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x104690: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x104690u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x104694: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x104694u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x104698: 0xc0448a6  jal         func_112298
    ctx->pc = 0x104698u;
    SET_GPR_U32(ctx, 31, 0x1046A0u);
    ctx->pc = 0x112298u;
    if (runtime->hasFunction(0x112298u)) {
        auto targetFn = runtime->lookupFunction(0x112298u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1046A0u; }
        if (ctx->pc != 0x1046A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112298_0x112298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1046A0u; }
        if (ctx->pc != 0x1046A0u) { return; }
    }
    ctx->pc = 0x1046A0u;
label_1046a0:
    // 0x1046a0: 0x1c40000a  bgtz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1046A0u;
    {
        const bool branch_taken_0x1046a0 = (GPR_S64(ctx, 2) > 0);
        ctx->pc = 0x1046A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1046A0u;
            // 0x1046a4: 0x24030039  addiu       $v1, $zero, 0x39 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 57));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1046a0) {
            ctx->pc = 0x1046CCu;
            goto label_1046cc;
        }
    }
    ctx->pc = 0x1046A8u;
    // 0x1046a8: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1046a8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1046ac: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1046acu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1046b0: 0xc0448a6  jal         func_112298
    ctx->pc = 0x1046B0u;
    SET_GPR_U32(ctx, 31, 0x1046B8u);
    ctx->pc = 0x112298u;
    if (runtime->hasFunction(0x112298u)) {
        auto targetFn = runtime->lookupFunction(0x112298u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1046B8u; }
        if (ctx->pc != 0x1046B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112298_0x112298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1046B8u; }
        if (ctx->pc != 0x1046B8u) { return; }
    }
    ctx->pc = 0x1046B8u;
label_1046b8:
    // 0x1046b8: 0x144001f2  bnez        $v0, . + 4 + (0x1F2 << 2)
    ctx->pc = 0x1046B8u;
    {
        const bool branch_taken_0x1046b8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1046BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1046B8u;
            // 0x1046bc: 0x8fa50044  lw          $a1, 0x44($sp) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 68)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1046b8) {
            ctx->pc = 0x104E84u;
            goto label_104e84;
        }
    }
    ctx->pc = 0x1046C0u;
    // 0x1046c0: 0x32020001  andi        $v0, $s0, 0x1
    ctx->pc = 0x1046c0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)1);
    // 0x1046c4: 0x104001ef  beqz        $v0, . + 4 + (0x1EF << 2)
    ctx->pc = 0x1046C4u;
    {
        const bool branch_taken_0x1046c4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1046C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1046C4u;
            // 0x1046c8: 0x24030039  addiu       $v1, $zero, 0x39 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 57));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1046c4) {
            ctx->pc = 0x104E84u;
            goto label_104e84;
        }
    }
    ctx->pc = 0x1046CCu;
label_1046cc:
    // 0x1046cc: 0x24050030  addiu       $a1, $zero, 0x30
    ctx->pc = 0x1046ccu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 48));
    // 0x1046d0: 0x26b5ffff  addiu       $s5, $s5, -0x1
    ctx->pc = 0x1046d0u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), 4294967295));
    // 0x1046d4: 0x0  nop
    ctx->pc = 0x1046d4u;
    // NOP
label_1046d8:
    // 0x1046d8: 0x82a20000  lb          $v0, 0x0($s5)
    ctx->pc = 0x1046d8u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 21), 0)));
    // 0x1046dc: 0x1443000a  bne         $v0, $v1, . + 4 + (0xA << 2)
    ctx->pc = 0x1046DCu;
    {
        const bool branch_taken_0x1046dc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x1046E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1046DCu;
            // 0x1046e0: 0x92a40000  lbu         $a0, 0x0($s5) (Delay Slot)
        SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 21), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1046dc) {
            ctx->pc = 0x104708u;
            goto label_104708;
        }
    }
    ctx->pc = 0x1046E4u;
    // 0x1046e4: 0x8fa40054  lw          $a0, 0x54($sp)
    ctx->pc = 0x1046e4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 84)));
    // 0x1046e8: 0x0  nop
    ctx->pc = 0x1046e8u;
    // NOP
    // 0x1046ec: 0x0  nop
    ctx->pc = 0x1046ecu;
    // NOP
    // 0x1046f0: 0x0  nop
    ctx->pc = 0x1046f0u;
    // NOP
    // 0x1046f4: 0x56a4fff8  bnel        $s5, $a0, . + 4 + (-0x8 << 2)
    ctx->pc = 0x1046F4u;
    {
        const bool branch_taken_0x1046f4 = (GPR_U64(ctx, 21) != GPR_U64(ctx, 4));
        if (branch_taken_0x1046f4) {
            ctx->pc = 0x1046F8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1046F4u;
            // 0x1046f8: 0x26b5ffff  addiu       $s5, $s5, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), 4294967295));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1046D8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1046d8;
        }
    }
    ctx->pc = 0x1046FCu;
    // 0x1046fc: 0xa0850000  sb          $a1, 0x0($a0)
    ctx->pc = 0x1046fcu;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0x104700: 0xa0202d  daddu       $a0, $a1, $zero
    ctx->pc = 0x104700u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x104704: 0x27de0001  addiu       $fp, $fp, 0x1
    ctx->pc = 0x104704u;
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 30), 1));
label_104708:
    // 0x104708: 0x24820001  addiu       $v0, $a0, 0x1
    ctx->pc = 0x104708u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x10470c: 0xa2a20000  sb          $v0, 0x0($s5)
    ctx->pc = 0x10470cu;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x104710: 0x100001db  b           . + 4 + (0x1DB << 2)
    ctx->pc = 0x104710u;
    {
        const bool branch_taken_0x104710 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x104714u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x104710u;
            // 0x104714: 0x26b50001  addiu       $s5, $s5, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x104710) {
            ctx->pc = 0x104E80u;
            goto label_104e80;
        }
    }
    ctx->pc = 0x104718u;
label_104718:
    // 0x104718: 0x34048048  ori         $a0, $zero, 0x8048
    ctx->pc = 0x104718u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32840);
    // 0x10471c: 0x423fc  dsll32      $a0, $a0, 15
    ctx->pc = 0x10471cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << (32 + 15));
    // 0x104720: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x104720u;
    SET_GPR_U32(ctx, 31, 0x104728u);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104728u; }
        if (ctx->pc != 0x104728u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104728u; }
        if (ctx->pc != 0x104728u) { return; }
    }
    ctx->pc = 0x104728u;
label_104728:
    // 0x104728: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x104728u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10472c: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x10472cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x104730: 0x40a02d  daddu       $s4, $v0, $zero
    ctx->pc = 0x104730u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x104734: 0xc0448a6  jal         func_112298
    ctx->pc = 0x104734u;
    SET_GPR_U32(ctx, 31, 0x10473Cu);
    ctx->pc = 0x112298u;
    if (runtime->hasFunction(0x112298u)) {
        auto targetFn = runtime->lookupFunction(0x112298u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10473Cu; }
        if (ctx->pc != 0x10473Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112298_0x112298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10473Cu; }
        if (ctx->pc != 0x10473Cu) { return; }
    }
    ctx->pc = 0x10473Cu;
label_10473c:
    // 0x10473c: 0x104001d0  beqz        $v0, . + 4 + (0x1D0 << 2)
    ctx->pc = 0x10473Cu;
    {
        const bool branch_taken_0x10473c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x104740u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10473Cu;
            // 0x104740: 0x26730001  addiu       $s3, $s3, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10473c) {
            ctx->pc = 0x104E80u;
            goto label_104e80;
        }
    }
    ctx->pc = 0x104744u;
    // 0x104744: 0x1000ffb6  b           . + 4 + (-0x4A << 2)
    ctx->pc = 0x104744u;
    {
        const bool branch_taken_0x104744 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x104744) {
            ctx->pc = 0x104620u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_104620;
        }
    }
    ctx->pc = 0x10474Cu;
    // 0x10474c: 0x0  nop
    ctx->pc = 0x10474cu;
    // NOP
label_104750:
    // 0x104750: 0x8fa20008  lw          $v0, 0x8($sp)
    ctx->pc = 0x104750u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
label_104754:
    // 0x104754: 0x8fa40034  lw          $a0, 0x34($sp)
    ctx->pc = 0x104754u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0x104758: 0x8fb10018  lw          $s1, 0x18($sp)
    ctx->pc = 0x104758u;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x10475c: 0x28560002  slti        $s6, $v0, 0x2
    ctx->pc = 0x10475cu;
    SET_GPR_U64(ctx, 22, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x104760: 0x8fb2001c  lw          $s2, 0x1C($sp)
    ctx->pc = 0x104760u;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x104764: 0xafa00048  sw          $zero, 0x48($sp)
    ctx->pc = 0x104764u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 72), GPR_U32(ctx, 0));
    // 0x104768: 0x10800028  beqz        $a0, . + 4 + (0x28 << 2)
    ctx->pc = 0x104768u;
    {
        const bool branch_taken_0x104768 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x10476Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x104768u;
            // 0x10476c: 0xafa0004c  sw          $zero, 0x4C($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 76), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x104768) {
            ctx->pc = 0x10480Cu;
            goto label_10480c;
        }
    }
    ctx->pc = 0x104770u;
    // 0x104770: 0x52c00009  beql        $s6, $zero, . + 4 + (0x9 << 2)
    ctx->pc = 0x104770u;
    {
        const bool branch_taken_0x104770 = (GPR_U64(ctx, 22) == GPR_U64(ctx, 0));
        if (branch_taken_0x104770) {
            ctx->pc = 0x104774u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x104770u;
            // 0x104774: 0x8fa30020  lw          $v1, 0x20($sp) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x104798u;
            goto label_104798;
        }
    }
    ctx->pc = 0x104778u;
    // 0x104778: 0x8fa20040  lw          $v0, 0x40($sp)
    ctx->pc = 0x104778u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x10477c: 0x14400019  bnez        $v0, . + 4 + (0x19 << 2)
    ctx->pc = 0x10477Cu;
    {
        const bool branch_taken_0x10477c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x104780u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10477Cu;
            // 0x104780: 0x24730433  addiu       $s3, $v1, 0x433 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 3), 1075));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10477c) {
            ctx->pc = 0x1047E4u;
            goto label_1047e4;
        }
    }
    ctx->pc = 0x104784u;
    // 0x104784: 0x8fa30004  lw          $v1, 0x4($sp)
    ctx->pc = 0x104784u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x104788: 0x24020036  addiu       $v0, $zero, 0x36
    ctx->pc = 0x104788u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 54));
    // 0x10478c: 0x10000015  b           . + 4 + (0x15 << 2)
    ctx->pc = 0x10478Cu;
    {
        const bool branch_taken_0x10478c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x104790u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10478Cu;
            // 0x104790: 0x439823  subu        $s3, $v0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10478c) {
            ctx->pc = 0x1047E4u;
            goto label_1047e4;
        }
    }
    ctx->pc = 0x104794u;
    // 0x104794: 0x0  nop
    ctx->pc = 0x104794u;
    // NOP
label_104798:
    // 0x104798: 0x8fa4001c  lw          $a0, 0x1C($sp)
    ctx->pc = 0x104798u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x10479c: 0x2470ffff  addiu       $s0, $v1, -0x1
    ctx->pc = 0x10479cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x1047a0: 0x90102a  slt         $v0, $a0, $s0
    ctx->pc = 0x1047a0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)GPR_S64(ctx, 16)) ? 1 : 0);
    // 0x1047a4: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1047A4u;
    {
        const bool branch_taken_0x1047a4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1047A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1047A4u;
            // 0x1047a8: 0x909023  subu        $s2, $a0, $s0 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1047a4) {
            ctx->pc = 0x1047CCu;
            goto label_1047cc;
        }
    }
    ctx->pc = 0x1047ACu;
    // 0x1047ac: 0x8fa2001c  lw          $v0, 0x1C($sp)
    ctx->pc = 0x1047acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x1047b0: 0x902d  daddu       $s2, $zero, $zero
    ctx->pc = 0x1047b0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1047b4: 0x8fa3003c  lw          $v1, 0x3C($sp)
    ctx->pc = 0x1047b4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 60)));
    // 0x1047b8: 0x2028023  subu        $s0, $s0, $v0
    ctx->pc = 0x1047b8u;
    SET_GPR_S32(ctx, 16, (int32_t)SUB32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x1047bc: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x1047bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1047c0: 0x701821  addu        $v1, $v1, $s0
    ctx->pc = 0x1047c0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x1047c4: 0xafa2001c  sw          $v0, 0x1C($sp)
    ctx->pc = 0x1047c4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 2));
    // 0x1047c8: 0xafa3003c  sw          $v1, 0x3C($sp)
    ctx->pc = 0x1047c8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 60), GPR_U32(ctx, 3));
label_1047cc:
    // 0x1047cc: 0x8fb30020  lw          $s3, 0x20($sp)
    ctx->pc = 0x1047ccu;
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1047d0: 0x6610005  bgez        $s3, . + 4 + (0x5 << 2)
    ctx->pc = 0x1047D0u;
    {
        const bool branch_taken_0x1047d0 = (GPR_S64(ctx, 19) >= 0);
        ctx->pc = 0x1047D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1047D0u;
            // 0x1047d4: 0x8fa20038  lw          $v0, 0x38($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1047d0) {
            ctx->pc = 0x1047E8u;
            goto label_1047e8;
        }
    }
    ctx->pc = 0x1047D8u;
    // 0x1047d8: 0x8fa40018  lw          $a0, 0x18($sp)
    ctx->pc = 0x1047d8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1047dc: 0x938823  subu        $s1, $a0, $s3
    ctx->pc = 0x1047dcu;
    SET_GPR_S32(ctx, 17, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 19)));
    // 0x1047e0: 0x982d  daddu       $s3, $zero, $zero
    ctx->pc = 0x1047e0u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1047e4:
    // 0x1047e4: 0x8fa20038  lw          $v0, 0x38($sp)
    ctx->pc = 0x1047e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
label_1047e8:
    // 0x1047e8: 0x2e0202d  daddu       $a0, $s7, $zero
    ctx->pc = 0x1047e8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1047ec: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1047ecu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1047f0: 0x531021  addu        $v0, $v0, $s3
    ctx->pc = 0x1047f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x1047f4: 0xc042092  jal         func_108248
    ctx->pc = 0x1047F4u;
    SET_GPR_U32(ctx, 31, 0x1047FCu);
    ctx->pc = 0x1047F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1047F4u;
            // 0x1047f8: 0xafa20038  sw          $v0, 0x38($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x108248u;
    if (runtime->hasFunction(0x108248u)) {
        auto targetFn = runtime->lookupFunction(0x108248u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1047FCu; }
        if (ctx->pc != 0x1047FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00108248_0x108248(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1047FCu; }
        if (ctx->pc != 0x1047FCu) { return; }
    }
    ctx->pc = 0x1047FCu;
label_1047fc:
    // 0x1047fc: 0x8fa30018  lw          $v1, 0x18($sp)
    ctx->pc = 0x1047fcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x104800: 0xafa2004c  sw          $v0, 0x4C($sp)
    ctx->pc = 0x104800u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 76), GPR_U32(ctx, 2));
    // 0x104804: 0x731821  addu        $v1, $v1, $s3
    ctx->pc = 0x104804u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 19)));
    // 0x104808: 0xafa30018  sw          $v1, 0x18($sp)
    ctx->pc = 0x104808u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 3));
label_10480c:
    // 0x10480c: 0x1a20000d  blez        $s1, . + 4 + (0xD << 2)
    ctx->pc = 0x10480Cu;
    {
        const bool branch_taken_0x10480c = (GPR_S64(ctx, 17) <= 0);
        ctx->pc = 0x104810u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10480Cu;
            // 0x104810: 0x8fa3001c  lw          $v1, 0x1C($sp) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10480c) {
            ctx->pc = 0x104844u;
            goto label_104844;
        }
    }
    ctx->pc = 0x104814u;
    // 0x104814: 0x8fa40038  lw          $a0, 0x38($sp)
    ctx->pc = 0x104814u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x104818: 0x1880000a  blez        $a0, . + 4 + (0xA << 2)
    ctx->pc = 0x104818u;
    {
        const bool branch_taken_0x104818 = (GPR_S64(ctx, 4) <= 0);
        ctx->pc = 0x10481Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x104818u;
            // 0x10481c: 0x80982d  daddu       $s3, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x104818) {
            ctx->pc = 0x104844u;
            goto label_104844;
        }
    }
    ctx->pc = 0x104820u;
    // 0x104820: 0x233102a  slt         $v0, $s1, $s3
    ctx->pc = 0x104820u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)GPR_S64(ctx, 19)) ? 1 : 0);
    // 0x104824: 0x222980b  movn        $s3, $s1, $v0
    ctx->pc = 0x104824u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 19, GPR_VEC(ctx, 17));
    // 0x104828: 0x8fa20018  lw          $v0, 0x18($sp)
    ctx->pc = 0x104828u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x10482c: 0x932023  subu        $a0, $a0, $s3
    ctx->pc = 0x10482cu;
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 19)));
    // 0x104830: 0x2338823  subu        $s1, $s1, $s3
    ctx->pc = 0x104830u;
    SET_GPR_S32(ctx, 17, (int32_t)SUB32(GPR_U32(ctx, 17), GPR_U32(ctx, 19)));
    // 0x104834: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x104834u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x104838: 0xafa40038  sw          $a0, 0x38($sp)
    ctx->pc = 0x104838u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 4));
    // 0x10483c: 0xafa20018  sw          $v0, 0x18($sp)
    ctx->pc = 0x10483cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 2));
    // 0x104840: 0x8fa3001c  lw          $v1, 0x1C($sp)
    ctx->pc = 0x104840u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
label_104844:
    // 0x104844: 0x18600023  blez        $v1, . + 4 + (0x23 << 2)
    ctx->pc = 0x104844u;
    {
        const bool branch_taken_0x104844 = (GPR_S64(ctx, 3) <= 0);
        ctx->pc = 0x104848u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x104844u;
            // 0x104848: 0x2e0202d  daddu       $a0, $s7, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x104844) {
            ctx->pc = 0x1048D4u;
            goto label_1048d4;
        }
    }
    ctx->pc = 0x10484Cu;
    // 0x10484c: 0x8fa40034  lw          $a0, 0x34($sp)
    ctx->pc = 0x10484cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0x104850: 0x1080001b  beqz        $a0, . + 4 + (0x1B << 2)
    ctx->pc = 0x104850u;
    {
        const bool branch_taken_0x104850 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x104854u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x104850u;
            // 0x104854: 0x8fa50044  lw          $a1, 0x44($sp) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 68)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x104850) {
            ctx->pc = 0x1048C0u;
            goto label_1048c0;
        }
    }
    ctx->pc = 0x104858u;
    // 0x104858: 0x1a400010  blez        $s2, . + 4 + (0x10 << 2)
    ctx->pc = 0x104858u;
    {
        const bool branch_taken_0x104858 = (GPR_S64(ctx, 18) <= 0);
        ctx->pc = 0x10485Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x104858u;
            // 0x10485c: 0x8fa2001c  lw          $v0, 0x1C($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x104858) {
            ctx->pc = 0x10489Cu;
            goto label_10489c;
        }
    }
    ctx->pc = 0x104860u;
    // 0x104860: 0x8fa5004c  lw          $a1, 0x4C($sp)
    ctx->pc = 0x104860u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 76)));
    // 0x104864: 0x2e0202d  daddu       $a0, $s7, $zero
    ctx->pc = 0x104864u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x104868: 0xc042124  jal         func_108490
    ctx->pc = 0x104868u;
    SET_GPR_U32(ctx, 31, 0x104870u);
    ctx->pc = 0x10486Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x104868u;
            // 0x10486c: 0x240302d  daddu       $a2, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x108490u;
    if (runtime->hasFunction(0x108490u)) {
        auto targetFn = runtime->lookupFunction(0x108490u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104870u; }
        if (ctx->pc != 0x104870u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00108490_0x108490(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104870u; }
        if (ctx->pc != 0x104870u) { return; }
    }
    ctx->pc = 0x104870u;
label_104870:
    // 0x104870: 0x2e0202d  daddu       $a0, $s7, $zero
    ctx->pc = 0x104870u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x104874: 0x8fa60044  lw          $a2, 0x44($sp)
    ctx->pc = 0x104874u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 68)));
    // 0x104878: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x104878u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10487c: 0xc0420a0  jal         func_108280
    ctx->pc = 0x10487Cu;
    SET_GPR_U32(ctx, 31, 0x104884u);
    ctx->pc = 0x104880u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10487Cu;
            // 0x104880: 0xafa2004c  sw          $v0, 0x4C($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 76), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x108280u;
    if (runtime->hasFunction(0x108280u)) {
        auto targetFn = runtime->lookupFunction(0x108280u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104884u; }
        if (ctx->pc != 0x104884u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00108280_0x108280(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104884u; }
        if (ctx->pc != 0x104884u) { return; }
    }
    ctx->pc = 0x104884u;
label_104884:
    // 0x104884: 0x2e0202d  daddu       $a0, $s7, $zero
    ctx->pc = 0x104884u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x104888: 0x8fa50044  lw          $a1, 0x44($sp)
    ctx->pc = 0x104888u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 68)));
    // 0x10488c: 0xc041fa8  jal         func_107EA0
    ctx->pc = 0x10488Cu;
    SET_GPR_U32(ctx, 31, 0x104894u);
    ctx->pc = 0x104890u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10488Cu;
            // 0x104890: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107EA0u;
    if (runtime->hasFunction(0x107EA0u)) {
        auto targetFn = runtime->lookupFunction(0x107EA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104894u; }
        if (ctx->pc != 0x104894u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107EA0_0x107ea0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104894u; }
        if (ctx->pc != 0x104894u) { return; }
    }
    ctx->pc = 0x104894u;
label_104894:
    // 0x104894: 0xafb00044  sw          $s0, 0x44($sp)
    ctx->pc = 0x104894u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 68), GPR_U32(ctx, 16));
    // 0x104898: 0x8fa2001c  lw          $v0, 0x1C($sp)
    ctx->pc = 0x104898u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
label_10489c:
    // 0x10489c: 0x528023  subu        $s0, $v0, $s2
    ctx->pc = 0x10489cu;
    SET_GPR_S32(ctx, 16, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 18)));
    // 0x1048a0: 0x5200000c  beql        $s0, $zero, . + 4 + (0xC << 2)
    ctx->pc = 0x1048A0u;
    {
        const bool branch_taken_0x1048a0 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        if (branch_taken_0x1048a0) {
            ctx->pc = 0x1048A4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1048A0u;
            // 0x1048a4: 0x2e0202d  daddu       $a0, $s7, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1048D4u;
            goto label_1048d4;
        }
    }
    ctx->pc = 0x1048A8u;
    // 0x1048a8: 0x8fa50044  lw          $a1, 0x44($sp)
    ctx->pc = 0x1048a8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 68)));
    // 0x1048ac: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x1048acu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1048b0: 0xc042124  jal         func_108490
    ctx->pc = 0x1048B0u;
    SET_GPR_U32(ctx, 31, 0x1048B8u);
    ctx->pc = 0x1048B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1048B0u;
            // 0x1048b4: 0x2e0202d  daddu       $a0, $s7, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x108490u;
    if (runtime->hasFunction(0x108490u)) {
        auto targetFn = runtime->lookupFunction(0x108490u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1048B8u; }
        if (ctx->pc != 0x1048B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00108490_0x108490(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1048B8u; }
        if (ctx->pc != 0x1048B8u) { return; }
    }
    ctx->pc = 0x1048B8u;
label_1048b8:
    // 0x1048b8: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1048B8u;
    {
        const bool branch_taken_0x1048b8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1048BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1048B8u;
            // 0x1048bc: 0xafa20044  sw          $v0, 0x44($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 68), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1048b8) {
            ctx->pc = 0x1048D0u;
            goto label_1048d0;
        }
    }
    ctx->pc = 0x1048C0u;
label_1048c0:
    // 0x1048c0: 0x2e0202d  daddu       $a0, $s7, $zero
    ctx->pc = 0x1048c0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1048c4: 0xc042124  jal         func_108490
    ctx->pc = 0x1048C4u;
    SET_GPR_U32(ctx, 31, 0x1048CCu);
    ctx->pc = 0x1048C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1048C4u;
            // 0x1048c8: 0x8fa6001c  lw          $a2, 0x1C($sp) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x108490u;
    if (runtime->hasFunction(0x108490u)) {
        auto targetFn = runtime->lookupFunction(0x108490u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1048CCu; }
        if (ctx->pc != 0x1048CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00108490_0x108490(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1048CCu; }
        if (ctx->pc != 0x1048CCu) { return; }
    }
    ctx->pc = 0x1048CCu;
label_1048cc:
    // 0x1048cc: 0xafa20044  sw          $v0, 0x44($sp)
    ctx->pc = 0x1048ccu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 68), GPR_U32(ctx, 2));
label_1048d0:
    // 0x1048d0: 0x2e0202d  daddu       $a0, $s7, $zero
    ctx->pc = 0x1048d0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
label_1048d4:
    // 0x1048d4: 0xc042092  jal         func_108248
    ctx->pc = 0x1048D4u;
    SET_GPR_U32(ctx, 31, 0x1048DCu);
    ctx->pc = 0x1048D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1048D4u;
            // 0x1048d8: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x108248u;
    if (runtime->hasFunction(0x108248u)) {
        auto targetFn = runtime->lookupFunction(0x108248u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1048DCu; }
        if (ctx->pc != 0x1048DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00108248_0x108248(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1048DCu; }
        if (ctx->pc != 0x1048DCu) { return; }
    }
    ctx->pc = 0x1048DCu;
label_1048dc:
    // 0x1048dc: 0x8fa3003c  lw          $v1, 0x3C($sp)
    ctx->pc = 0x1048dcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 60)));
    // 0x1048e0: 0x18600006  blez        $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x1048E0u;
    {
        const bool branch_taken_0x1048e0 = (GPR_S64(ctx, 3) <= 0);
        ctx->pc = 0x1048E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1048E0u;
            // 0x1048e4: 0xafa20050  sw          $v0, 0x50($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 80), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1048e0) {
            ctx->pc = 0x1048FCu;
            goto label_1048fc;
        }
    }
    ctx->pc = 0x1048E8u;
    // 0x1048e8: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1048e8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1048ec: 0x2e0202d  daddu       $a0, $s7, $zero
    ctx->pc = 0x1048ecu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1048f0: 0xc042124  jal         func_108490
    ctx->pc = 0x1048F0u;
    SET_GPR_U32(ctx, 31, 0x1048F8u);
    ctx->pc = 0x1048F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1048F0u;
            // 0x1048f4: 0x60302d  daddu       $a2, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x108490u;
    if (runtime->hasFunction(0x108490u)) {
        auto targetFn = runtime->lookupFunction(0x108490u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1048F8u; }
        if (ctx->pc != 0x1048F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00108490_0x108490(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1048F8u; }
        if (ctx->pc != 0x1048F8u) { return; }
    }
    ctx->pc = 0x1048F8u;
label_1048f8:
    // 0x1048f8: 0xafa20050  sw          $v0, 0x50($sp)
    ctx->pc = 0x1048f8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 80), GPR_U32(ctx, 2));
label_1048fc:
    // 0x1048fc: 0x12c00011  beqz        $s6, . + 4 + (0x11 << 2)
    ctx->pc = 0x1048FCu;
    {
        const bool branch_taken_0x1048fc = (GPR_U64(ctx, 22) == GPR_U64(ctx, 0));
        ctx->pc = 0x104900u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1048FCu;
            // 0x104900: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1048fc) {
            ctx->pc = 0x104944u;
            goto label_104944;
        }
    }
    ctx->pc = 0x104904u;
    // 0x104904: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x104904u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x104908: 0x2133a  dsrl        $v0, $v0, 12
    ctx->pc = 0x104908u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> 12);
    // 0x10490c: 0x2821024  and         $v0, $s4, $v0
    ctx->pc = 0x10490cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 20) & GPR_U64(ctx, 2));
    // 0x104910: 0x1440000d  bnez        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x104910u;
    {
        const bool branch_taken_0x104910 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x104914u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x104910u;
            // 0x104914: 0x8fa3003c  lw          $v1, 0x3C($sp) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 60)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x104910) {
            ctx->pc = 0x104948u;
            goto label_104948;
        }
    }
    ctx->pc = 0x104918u;
    // 0x104918: 0x14103f  dsra32      $v0, $s4, 0
    ctx->pc = 0x104918u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 20) >> (32 + 0));
    // 0x10491c: 0x3c037ff0  lui         $v1, 0x7FF0
    ctx->pc = 0x10491cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32752 << 16));
    // 0x104920: 0x431024  and         $v0, $v0, $v1
    ctx->pc = 0x104920u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x104924: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x104924u;
    {
        const bool branch_taken_0x104924 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x104928u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x104924u;
            // 0x104928: 0x8fa40018  lw          $a0, 0x18($sp) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x104924) {
            ctx->pc = 0x104944u;
            goto label_104944;
        }
    }
    ctx->pc = 0x10492Cu;
    // 0x10492c: 0x24100001  addiu       $s0, $zero, 0x1
    ctx->pc = 0x10492cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x104930: 0x8fa20038  lw          $v0, 0x38($sp)
    ctx->pc = 0x104930u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x104934: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x104934u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x104938: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x104938u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x10493c: 0xafa40018  sw          $a0, 0x18($sp)
    ctx->pc = 0x10493cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 4));
    // 0x104940: 0xafa20038  sw          $v0, 0x38($sp)
    ctx->pc = 0x104940u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 2));
label_104944:
    // 0x104944: 0x8fa3003c  lw          $v1, 0x3C($sp)
    ctx->pc = 0x104944u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 60)));
label_104948:
    // 0x104948: 0x10600009  beqz        $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x104948u;
    {
        const bool branch_taken_0x104948 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x10494Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x104948u;
            // 0x10494c: 0x8fa40050  lw          $a0, 0x50($sp) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 80)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x104948) {
            ctx->pc = 0x104970u;
            goto label_104970;
        }
    }
    ctx->pc = 0x104950u;
    // 0x104950: 0x8c820010  lw          $v0, 0x10($a0)
    ctx->pc = 0x104950u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x104954: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x104954u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x104958: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x104958u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x10495c: 0xc042042  jal         func_108108
    ctx->pc = 0x10495Cu;
    SET_GPR_U32(ctx, 31, 0x104964u);
    ctx->pc = 0x104960u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10495Cu;
            // 0x104960: 0x8c440010  lw          $a0, 0x10($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x108108u;
    if (runtime->hasFunction(0x108108u)) {
        auto targetFn = runtime->lookupFunction(0x108108u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104964u; }
        if (ctx->pc != 0x104964u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00108108_0x108108(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104964u; }
        if (ctx->pc != 0x104964u) { return; }
    }
    ctx->pc = 0x104964u;
label_104964:
    // 0x104964: 0x8fa30038  lw          $v1, 0x38($sp)
    ctx->pc = 0x104964u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x104968: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x104968u;
    {
        const bool branch_taken_0x104968 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10496Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x104968u;
            // 0x10496c: 0x621023  subu        $v0, $v1, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x104968) {
            ctx->pc = 0x104978u;
            goto label_104978;
        }
    }
    ctx->pc = 0x104970u;
label_104970:
    // 0x104970: 0x8fa40038  lw          $a0, 0x38($sp)
    ctx->pc = 0x104970u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x104974: 0x24820001  addiu       $v0, $a0, 0x1
    ctx->pc = 0x104974u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
label_104978:
    // 0x104978: 0x3053001f  andi        $s3, $v0, 0x1F
    ctx->pc = 0x104978u;
    SET_GPR_U64(ctx, 19, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)31);
    // 0x10497c: 0x12600002  beqz        $s3, . + 4 + (0x2 << 2)
    ctx->pc = 0x10497Cu;
    {
        const bool branch_taken_0x10497c = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x104980u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10497Cu;
            // 0x104980: 0x24020020  addiu       $v0, $zero, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10497c) {
            ctx->pc = 0x104988u;
            goto label_104988;
        }
    }
    ctx->pc = 0x104984u;
    // 0x104984: 0x539823  subu        $s3, $v0, $s3
    ctx->pc = 0x104984u;
    SET_GPR_S32(ctx, 19, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
label_104988:
    // 0x104988: 0x2a620005  slti        $v0, $s3, 0x5
    ctx->pc = 0x104988u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)5) ? 1 : 0);
    // 0x10498c: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x10498Cu;
    {
        const bool branch_taken_0x10498c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x104990u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10498Cu;
            // 0x104990: 0x2a620004  slti        $v0, $s3, 0x4 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)4) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x10498c) {
            ctx->pc = 0x1049B8u;
            goto label_1049b8;
        }
    }
    ctx->pc = 0x104994u;
    // 0x104994: 0x8fa20038  lw          $v0, 0x38($sp)
    ctx->pc = 0x104994u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x104998: 0x2673fffc  addiu       $s3, $s3, -0x4
    ctx->pc = 0x104998u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967292));
    // 0x10499c: 0x8fa30018  lw          $v1, 0x18($sp)
    ctx->pc = 0x10499cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1049a0: 0x2338821  addu        $s1, $s1, $s3
    ctx->pc = 0x1049a0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 19)));
    // 0x1049a4: 0x531021  addu        $v0, $v0, $s3
    ctx->pc = 0x1049a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x1049a8: 0x731821  addu        $v1, $v1, $s3
    ctx->pc = 0x1049a8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 19)));
    // 0x1049ac: 0xafa20038  sw          $v0, 0x38($sp)
    ctx->pc = 0x1049acu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 2));
    // 0x1049b0: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x1049B0u;
    {
        const bool branch_taken_0x1049b0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1049B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1049B0u;
            // 0x1049b4: 0xafa30018  sw          $v1, 0x18($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1049b0) {
            ctx->pc = 0x1049E0u;
            goto label_1049e0;
        }
    }
    ctx->pc = 0x1049B8u;
label_1049b8:
    // 0x1049b8: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1049B8u;
    {
        const bool branch_taken_0x1049b8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1049BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1049B8u;
            // 0x1049bc: 0x8fa30018  lw          $v1, 0x18($sp) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1049b8) {
            ctx->pc = 0x1049E4u;
            goto label_1049e4;
        }
    }
    ctx->pc = 0x1049C0u;
    // 0x1049c0: 0x8fa40038  lw          $a0, 0x38($sp)
    ctx->pc = 0x1049c0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x1049c4: 0x2673001c  addiu       $s3, $s3, 0x1C
    ctx->pc = 0x1049c4u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 28));
    // 0x1049c8: 0x8fa20018  lw          $v0, 0x18($sp)
    ctx->pc = 0x1049c8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1049cc: 0x2338821  addu        $s1, $s1, $s3
    ctx->pc = 0x1049ccu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 19)));
    // 0x1049d0: 0x932021  addu        $a0, $a0, $s3
    ctx->pc = 0x1049d0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 19)));
    // 0x1049d4: 0x531021  addu        $v0, $v0, $s3
    ctx->pc = 0x1049d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x1049d8: 0xafa40038  sw          $a0, 0x38($sp)
    ctx->pc = 0x1049d8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 4));
    // 0x1049dc: 0xafa20018  sw          $v0, 0x18($sp)
    ctx->pc = 0x1049dcu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 2));
label_1049e0:
    // 0x1049e0: 0x8fa30018  lw          $v1, 0x18($sp)
    ctx->pc = 0x1049e0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
label_1049e4:
    // 0x1049e4: 0x58600007  blezl       $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x1049E4u;
    {
        const bool branch_taken_0x1049e4 = (GPR_S64(ctx, 3) <= 0);
        if (branch_taken_0x1049e4) {
            ctx->pc = 0x1049E8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1049E4u;
            // 0x1049e8: 0x8fa40038  lw          $a0, 0x38($sp) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x104A04u;
            goto label_104a04;
        }
    }
    ctx->pc = 0x1049ECu;
    // 0x1049ec: 0x8fa50044  lw          $a1, 0x44($sp)
    ctx->pc = 0x1049ecu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 68)));
    // 0x1049f0: 0x60302d  daddu       $a2, $v1, $zero
    ctx->pc = 0x1049f0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1049f4: 0xc042164  jal         func_108590
    ctx->pc = 0x1049F4u;
    SET_GPR_U32(ctx, 31, 0x1049FCu);
    ctx->pc = 0x1049F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1049F4u;
            // 0x1049f8: 0x2e0202d  daddu       $a0, $s7, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x108590u;
    if (runtime->hasFunction(0x108590u)) {
        auto targetFn = runtime->lookupFunction(0x108590u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1049FCu; }
        if (ctx->pc != 0x1049FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00108590_0x108590(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1049FCu; }
        if (ctx->pc != 0x1049FCu) { return; }
    }
    ctx->pc = 0x1049FCu;
label_1049fc:
    // 0x1049fc: 0xafa20044  sw          $v0, 0x44($sp)
    ctx->pc = 0x1049fcu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 68), GPR_U32(ctx, 2));
    // 0x104a00: 0x8fa40038  lw          $a0, 0x38($sp)
    ctx->pc = 0x104a00u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
label_104a04:
    // 0x104a04: 0x18800007  blez        $a0, . + 4 + (0x7 << 2)
    ctx->pc = 0x104A04u;
    {
        const bool branch_taken_0x104a04 = (GPR_S64(ctx, 4) <= 0);
        ctx->pc = 0x104A08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x104A04u;
            // 0x104a08: 0x8fa20030  lw          $v0, 0x30($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x104a04) {
            ctx->pc = 0x104A24u;
            goto label_104a24;
        }
    }
    ctx->pc = 0x104A0Cu;
    // 0x104a0c: 0x8fa50050  lw          $a1, 0x50($sp)
    ctx->pc = 0x104a0cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x104a10: 0x80302d  daddu       $a2, $a0, $zero
    ctx->pc = 0x104a10u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x104a14: 0xc042164  jal         func_108590
    ctx->pc = 0x104A14u;
    SET_GPR_U32(ctx, 31, 0x104A1Cu);
    ctx->pc = 0x104A18u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x104A14u;
            // 0x104a18: 0x2e0202d  daddu       $a0, $s7, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x108590u;
    if (runtime->hasFunction(0x108590u)) {
        auto targetFn = runtime->lookupFunction(0x108590u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104A1Cu; }
        if (ctx->pc != 0x104A1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00108590_0x108590(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104A1Cu; }
        if (ctx->pc != 0x104A1Cu) { return; }
    }
    ctx->pc = 0x104A1Cu;
label_104a1c:
    // 0x104a1c: 0xafa20050  sw          $v0, 0x50($sp)
    ctx->pc = 0x104a1cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 80), GPR_U32(ctx, 2));
    // 0x104a20: 0x8fa20030  lw          $v0, 0x30($sp)
    ctx->pc = 0x104a20u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
label_104a24:
    // 0x104a24: 0x10400016  beqz        $v0, . + 4 + (0x16 << 2)
    ctx->pc = 0x104A24u;
    {
        const bool branch_taken_0x104a24 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x104A28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x104A24u;
            // 0x104a28: 0x8fa40044  lw          $a0, 0x44($sp) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 68)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x104a24) {
            ctx->pc = 0x104A80u;
            goto label_104a80;
        }
    }
    ctx->pc = 0x104A2Cu;
    // 0x104a2c: 0xc0421ba  jal         func_1086E8
    ctx->pc = 0x104A2Cu;
    SET_GPR_U32(ctx, 31, 0x104A34u);
    ctx->pc = 0x104A30u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x104A2Cu;
            // 0x104a30: 0x8fa50050  lw          $a1, 0x50($sp) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 80)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1086E8u;
    if (runtime->hasFunction(0x1086E8u)) {
        auto targetFn = runtime->lookupFunction(0x1086E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104A34u; }
        if (ctx->pc != 0x104A34u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001086E8_0x1086e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104A34u; }
        if (ctx->pc != 0x104A34u) { return; }
    }
    ctx->pc = 0x104A34u;
label_104a34:
    // 0x104a34: 0x4430013  bgezl       $v0, . + 4 + (0x13 << 2)
    ctx->pc = 0x104A34u;
    {
        const bool branch_taken_0x104a34 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x104a34) {
            ctx->pc = 0x104A38u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x104A34u;
            // 0x104a38: 0x8fa20020  lw          $v0, 0x20($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x104A84u;
            goto label_104a84;
        }
    }
    ctx->pc = 0x104A3Cu;
    // 0x104a3c: 0x8fa50044  lw          $a1, 0x44($sp)
    ctx->pc = 0x104a3cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 68)));
    // 0x104a40: 0x2e0202d  daddu       $a0, $s7, $zero
    ctx->pc = 0x104a40u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x104a44: 0x2406000a  addiu       $a2, $zero, 0xA
    ctx->pc = 0x104a44u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x104a48: 0xc041fb4  jal         func_107ED0
    ctx->pc = 0x104A48u;
    SET_GPR_U32(ctx, 31, 0x104A50u);
    ctx->pc = 0x104A4Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x104A48u;
            // 0x104a4c: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107ED0u;
    if (runtime->hasFunction(0x107ED0u)) {
        auto targetFn = runtime->lookupFunction(0x107ED0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104A50u; }
        if (ctx->pc != 0x104A50u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107ED0_0x107ed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104A50u; }
        if (ctx->pc != 0x104A50u) { return; }
    }
    ctx->pc = 0x104A50u;
label_104a50:
    // 0x104a50: 0x27deffff  addiu       $fp, $fp, -0x1
    ctx->pc = 0x104a50u;
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 30), 4294967295));
    // 0x104a54: 0x8fa30034  lw          $v1, 0x34($sp)
    ctx->pc = 0x104a54u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0x104a58: 0x10600007  beqz        $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x104A58u;
    {
        const bool branch_taken_0x104a58 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x104A5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x104A58u;
            // 0x104a5c: 0xafa20044  sw          $v0, 0x44($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 68), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x104a58) {
            ctx->pc = 0x104A78u;
            goto label_104a78;
        }
    }
    ctx->pc = 0x104A60u;
    // 0x104a60: 0x8fa5004c  lw          $a1, 0x4C($sp)
    ctx->pc = 0x104a60u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 76)));
    // 0x104a64: 0x2e0202d  daddu       $a0, $s7, $zero
    ctx->pc = 0x104a64u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x104a68: 0x2406000a  addiu       $a2, $zero, 0xA
    ctx->pc = 0x104a68u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x104a6c: 0xc041fb4  jal         func_107ED0
    ctx->pc = 0x104A6Cu;
    SET_GPR_U32(ctx, 31, 0x104A74u);
    ctx->pc = 0x104A70u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x104A6Cu;
            // 0x104a70: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107ED0u;
    if (runtime->hasFunction(0x107ED0u)) {
        auto targetFn = runtime->lookupFunction(0x107ED0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104A74u; }
        if (ctx->pc != 0x104A74u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107ED0_0x107ed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104A74u; }
        if (ctx->pc != 0x104A74u) { return; }
    }
    ctx->pc = 0x104A74u;
label_104a74:
    // 0x104a74: 0xafa2004c  sw          $v0, 0x4C($sp)
    ctx->pc = 0x104a74u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 76), GPR_U32(ctx, 2));
label_104a78:
    // 0x104a78: 0x8fa40028  lw          $a0, 0x28($sp)
    ctx->pc = 0x104a78u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x104a7c: 0xafa40020  sw          $a0, 0x20($sp)
    ctx->pc = 0x104a7cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 4));
label_104a80:
    // 0x104a80: 0x8fa20020  lw          $v0, 0x20($sp)
    ctx->pc = 0x104a80u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
label_104a84:
    // 0x104a84: 0x1c40001c  bgtz        $v0, . + 4 + (0x1C << 2)
    ctx->pc = 0x104A84u;
    {
        const bool branch_taken_0x104a84 = (GPR_S64(ctx, 2) > 0);
        ctx->pc = 0x104A88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x104A84u;
            // 0x104a88: 0x8fa40034  lw          $a0, 0x34($sp) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x104a84) {
            ctx->pc = 0x104AF8u;
            goto label_104af8;
        }
    }
    ctx->pc = 0x104A8Cu;
    // 0x104a8c: 0x8fa30008  lw          $v1, 0x8($sp)
    ctx->pc = 0x104a8cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x104a90: 0x28620003  slti        $v0, $v1, 0x3
    ctx->pc = 0x104a90u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)3) ? 1 : 0);
    // 0x104a94: 0x14400018  bnez        $v0, . + 4 + (0x18 << 2)
    ctx->pc = 0x104A94u;
    {
        const bool branch_taken_0x104a94 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x104a94) {
            ctx->pc = 0x104AF8u;
            goto label_104af8;
        }
    }
    ctx->pc = 0x104A9Cu;
    // 0x104a9c: 0x8fa40020  lw          $a0, 0x20($sp)
    ctx->pc = 0x104a9cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x104aa0: 0x480000b  bltz        $a0, . + 4 + (0xB << 2)
    ctx->pc = 0x104AA0u;
    {
        const bool branch_taken_0x104aa0 = (GPR_S64(ctx, 4) < 0);
        ctx->pc = 0x104AA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x104AA0u;
            // 0x104aa4: 0x8fa50050  lw          $a1, 0x50($sp) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 80)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x104aa0) {
            ctx->pc = 0x104AD0u;
            goto label_104ad0;
        }
    }
    ctx->pc = 0x104AA8u;
    // 0x104aa8: 0x2e0202d  daddu       $a0, $s7, $zero
    ctx->pc = 0x104aa8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x104aac: 0x24060005  addiu       $a2, $zero, 0x5
    ctx->pc = 0x104aacu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x104ab0: 0xc041fb4  jal         func_107ED0
    ctx->pc = 0x104AB0u;
    SET_GPR_U32(ctx, 31, 0x104AB8u);
    ctx->pc = 0x104AB4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x104AB0u;
            // 0x104ab4: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107ED0u;
    if (runtime->hasFunction(0x107ED0u)) {
        auto targetFn = runtime->lookupFunction(0x107ED0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104AB8u; }
        if (ctx->pc != 0x104AB8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107ED0_0x107ed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104AB8u; }
        if (ctx->pc != 0x104AB8u) { return; }
    }
    ctx->pc = 0x104AB8u;
label_104ab8:
    // 0x104ab8: 0x8fa40044  lw          $a0, 0x44($sp)
    ctx->pc = 0x104ab8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 68)));
    // 0x104abc: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x104abcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x104ac0: 0xc0421ba  jal         func_1086E8
    ctx->pc = 0x104AC0u;
    SET_GPR_U32(ctx, 31, 0x104AC8u);
    ctx->pc = 0x104AC4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x104AC0u;
            // 0x104ac4: 0xafa20050  sw          $v0, 0x50($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 80), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1086E8u;
    if (runtime->hasFunction(0x1086E8u)) {
        auto targetFn = runtime->lookupFunction(0x1086E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104AC8u; }
        if (ctx->pc != 0x104AC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001086E8_0x1086e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104AC8u; }
        if (ctx->pc != 0x104AC8u) { return; }
    }
    ctx->pc = 0x104AC8u;
label_104ac8:
    // 0x104ac8: 0x5c400005  bgtzl       $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x104AC8u;
    {
        const bool branch_taken_0x104ac8 = (GPR_S64(ctx, 2) > 0);
        if (branch_taken_0x104ac8) {
            ctx->pc = 0x104ACCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x104AC8u;
            // 0x104acc: 0x8fa30054  lw          $v1, 0x54($sp) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 84)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x104AE0u;
            goto label_104ae0;
        }
    }
    ctx->pc = 0x104AD0u;
label_104ad0:
    // 0x104ad0: 0x8fa2000c  lw          $v0, 0xC($sp)
    ctx->pc = 0x104ad0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 12)));
label_104ad4:
    // 0x104ad4: 0x100000db  b           . + 4 + (0xDB << 2)
    ctx->pc = 0x104AD4u;
    {
        const bool branch_taken_0x104ad4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x104AD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x104AD4u;
            // 0x104ad8: 0x2f027  nor         $fp, $zero, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 30, ~(GPR_U64(ctx, 0) | GPR_U64(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x104ad4) {
            ctx->pc = 0x104E44u;
            goto label_104e44;
        }
    }
    ctx->pc = 0x104ADCu;
    // 0x104adc: 0x0  nop
    ctx->pc = 0x104adcu;
    // NOP
label_104ae0:
    // 0x104ae0: 0x24020031  addiu       $v0, $zero, 0x31
    ctx->pc = 0x104ae0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 49));
    // 0x104ae4: 0x27de0001  addiu       $fp, $fp, 0x1
    ctx->pc = 0x104ae4u;
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 30), 1));
    // 0x104ae8: 0x24750001  addiu       $s5, $v1, 0x1
    ctx->pc = 0x104ae8u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x104aec: 0x100000d5  b           . + 4 + (0xD5 << 2)
    ctx->pc = 0x104AECu;
    {
        const bool branch_taken_0x104aec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x104AF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x104AECu;
            // 0x104af0: 0xa0620000  sb          $v0, 0x0($v1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x104aec) {
            ctx->pc = 0x104E44u;
            goto label_104e44;
        }
    }
    ctx->pc = 0x104AF4u;
    // 0x104af4: 0x0  nop
    ctx->pc = 0x104af4u;
    // NOP
label_104af8:
    // 0x104af8: 0x1080009a  beqz        $a0, . + 4 + (0x9A << 2)
    ctx->pc = 0x104AF8u;
    {
        const bool branch_taken_0x104af8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x104AFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x104AF8u;
            // 0x104afc: 0x24130001  addiu       $s3, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x104af8) {
            ctx->pc = 0x104D64u;
            goto label_104d64;
        }
    }
    ctx->pc = 0x104B00u;
    // 0x104b00: 0x1a200007  blez        $s1, . + 4 + (0x7 << 2)
    ctx->pc = 0x104B00u;
    {
        const bool branch_taken_0x104b00 = (GPR_S64(ctx, 17) <= 0);
        ctx->pc = 0x104B04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x104B00u;
            // 0x104b04: 0x8fa2004c  lw          $v0, 0x4C($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 76)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x104b00) {
            ctx->pc = 0x104B20u;
            goto label_104b20;
        }
    }
    ctx->pc = 0x104B08u;
    // 0x104b08: 0x8fa5004c  lw          $a1, 0x4C($sp)
    ctx->pc = 0x104b08u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 76)));
    // 0x104b0c: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x104b0cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x104b10: 0xc042164  jal         func_108590
    ctx->pc = 0x104B10u;
    SET_GPR_U32(ctx, 31, 0x104B18u);
    ctx->pc = 0x104B14u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x104B10u;
            // 0x104b14: 0x2e0202d  daddu       $a0, $s7, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x108590u;
    if (runtime->hasFunction(0x108590u)) {
        auto targetFn = runtime->lookupFunction(0x108590u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104B18u; }
        if (ctx->pc != 0x104B18u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00108590_0x108590(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104B18u; }
        if (ctx->pc != 0x104B18u) { return; }
    }
    ctx->pc = 0x104B18u;
label_104b18:
    // 0x104b18: 0xafa2004c  sw          $v0, 0x4C($sp)
    ctx->pc = 0x104b18u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 76), GPR_U32(ctx, 2));
    // 0x104b1c: 0x8fa2004c  lw          $v0, 0x4C($sp)
    ctx->pc = 0x104b1cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 76)));
label_104b20:
    // 0x104b20: 0x12000011  beqz        $s0, . + 4 + (0x11 << 2)
    ctx->pc = 0x104B20u;
    {
        const bool branch_taken_0x104b20 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x104B24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x104B20u;
            // 0x104b24: 0xafa20048  sw          $v0, 0x48($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 72), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x104b20) {
            ctx->pc = 0x104B68u;
            goto label_104b68;
        }
    }
    ctx->pc = 0x104B28u;
    // 0x104b28: 0x8c450004  lw          $a1, 0x4($v0)
    ctx->pc = 0x104b28u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x104b2c: 0xc041f7e  jal         func_107DF8
    ctx->pc = 0x104B2Cu;
    SET_GPR_U32(ctx, 31, 0x104B34u);
    ctx->pc = 0x104B30u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x104B2Cu;
            // 0x104b30: 0x2e0202d  daddu       $a0, $s7, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107DF8u;
    if (runtime->hasFunction(0x107DF8u)) {
        auto targetFn = runtime->lookupFunction(0x107DF8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104B34u; }
        if (ctx->pc != 0x104B34u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107DF8_0x107df8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104B34u; }
        if (ctx->pc != 0x104B34u) { return; }
    }
    ctx->pc = 0x104B34u;
label_104b34:
    // 0x104b34: 0x8fa30048  lw          $v1, 0x48($sp)
    ctx->pc = 0x104b34u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x104b38: 0x2444000c  addiu       $a0, $v0, 0xC
    ctx->pc = 0x104b38u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 12));
    // 0x104b3c: 0xafa2004c  sw          $v0, 0x4C($sp)
    ctx->pc = 0x104b3cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 76), GPR_U32(ctx, 2));
    // 0x104b40: 0x2465000c  addiu       $a1, $v1, 0xC
    ctx->pc = 0x104b40u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), 12));
    // 0x104b44: 0x8c660010  lw          $a2, 0x10($v1)
    ctx->pc = 0x104b44u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 16)));
    // 0x104b48: 0x63080  sll         $a2, $a2, 2
    ctx->pc = 0x104b48u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 2));
    // 0x104b4c: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x104B4Cu;
    SET_GPR_U32(ctx, 31, 0x104B54u);
    ctx->pc = 0x104B50u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x104B4Cu;
            // 0x104b50: 0x24c60008  addiu       $a2, $a2, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104B54u; }
        if (ctx->pc != 0x104B54u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104B54u; }
        if (ctx->pc != 0x104B54u) { return; }
    }
    ctx->pc = 0x104B54u;
label_104b54:
    // 0x104b54: 0x2e0202d  daddu       $a0, $s7, $zero
    ctx->pc = 0x104b54u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x104b58: 0x8fa5004c  lw          $a1, 0x4C($sp)
    ctx->pc = 0x104b58u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 76)));
    // 0x104b5c: 0xc042164  jal         func_108590
    ctx->pc = 0x104B5Cu;
    SET_GPR_U32(ctx, 31, 0x104B64u);
    ctx->pc = 0x104B60u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x104B5Cu;
            // 0x104b60: 0x24060001  addiu       $a2, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x108590u;
    if (runtime->hasFunction(0x108590u)) {
        auto targetFn = runtime->lookupFunction(0x108590u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104B64u; }
        if (ctx->pc != 0x104B64u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00108590_0x108590(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104B64u; }
        if (ctx->pc != 0x104B64u) { return; }
    }
    ctx->pc = 0x104B64u;
label_104b64:
    // 0x104b64: 0xafa2004c  sw          $v0, 0x4C($sp)
    ctx->pc = 0x104b64u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 76), GPR_U32(ctx, 2));
label_104b68:
    // 0x104b68: 0x14103c  dsll32      $v0, $s4, 0
    ctx->pc = 0x104b68u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 20) << (32 + 0));
    // 0x104b6c: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x104b6cu;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x104b70: 0x24130001  addiu       $s3, $zero, 0x1
    ctx->pc = 0x104b70u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x104b74: 0x10000020  b           . + 4 + (0x20 << 2)
    ctx->pc = 0x104B74u;
    {
        const bool branch_taken_0x104b74 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x104B78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x104B74u;
            // 0x104b78: 0x30560001  andi        $s6, $v0, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 22, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
        ctx->in_delay_slot = false;
        if (branch_taken_0x104b74) {
            ctx->pc = 0x104BF8u;
            goto label_104bf8;
        }
    }
    ctx->pc = 0x104B7Cu;
    // 0x104b7c: 0x0  nop
    ctx->pc = 0x104b7cu;
    // NOP
label_104b80:
    // 0x104b80: 0x8fa50044  lw          $a1, 0x44($sp)
    ctx->pc = 0x104b80u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 68)));
    // 0x104b84: 0x2e0202d  daddu       $a0, $s7, $zero
    ctx->pc = 0x104b84u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x104b88: 0x2406000a  addiu       $a2, $zero, 0xA
    ctx->pc = 0x104b88u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x104b8c: 0xc041fb4  jal         func_107ED0
    ctx->pc = 0x104B8Cu;
    SET_GPR_U32(ctx, 31, 0x104B94u);
    ctx->pc = 0x104B90u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x104B8Cu;
            // 0x104b90: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107ED0u;
    if (runtime->hasFunction(0x107ED0u)) {
        auto targetFn = runtime->lookupFunction(0x107ED0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104B94u; }
        if (ctx->pc != 0x104B94u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107ED0_0x107ed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104B94u; }
        if (ctx->pc != 0x104B94u) { return; }
    }
    ctx->pc = 0x104B94u;
label_104b94:
    // 0x104b94: 0xafa20044  sw          $v0, 0x44($sp)
    ctx->pc = 0x104b94u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 68), GPR_U32(ctx, 2));
    // 0x104b98: 0x8fa40048  lw          $a0, 0x48($sp)
    ctx->pc = 0x104b98u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x104b9c: 0x8fa2004c  lw          $v0, 0x4C($sp)
    ctx->pc = 0x104b9cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 76)));
    // 0x104ba0: 0x14820009  bne         $a0, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x104BA0u;
    {
        const bool branch_taken_0x104ba0 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 2));
        ctx->pc = 0x104BA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x104BA0u;
            // 0x104ba4: 0x8fa50048  lw          $a1, 0x48($sp) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 72)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x104ba0) {
            ctx->pc = 0x104BC8u;
            goto label_104bc8;
        }
    }
    ctx->pc = 0x104BA8u;
    // 0x104ba8: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x104ba8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x104bac: 0x2e0202d  daddu       $a0, $s7, $zero
    ctx->pc = 0x104bacu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x104bb0: 0x2406000a  addiu       $a2, $zero, 0xA
    ctx->pc = 0x104bb0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x104bb4: 0xc041fb4  jal         func_107ED0
    ctx->pc = 0x104BB4u;
    SET_GPR_U32(ctx, 31, 0x104BBCu);
    ctx->pc = 0x104BB8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x104BB4u;
            // 0x104bb8: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107ED0u;
    if (runtime->hasFunction(0x107ED0u)) {
        auto targetFn = runtime->lookupFunction(0x107ED0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104BBCu; }
        if (ctx->pc != 0x104BBCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107ED0_0x107ed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104BBCu; }
        if (ctx->pc != 0x104BBCu) { return; }
    }
    ctx->pc = 0x104BBCu;
label_104bbc:
    // 0x104bbc: 0xafa2004c  sw          $v0, 0x4C($sp)
    ctx->pc = 0x104bbcu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 76), GPR_U32(ctx, 2));
    // 0x104bc0: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x104BC0u;
    {
        const bool branch_taken_0x104bc0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x104BC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x104BC0u;
            // 0x104bc4: 0xafa20048  sw          $v0, 0x48($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 72), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x104bc0) {
            ctx->pc = 0x104BF4u;
            goto label_104bf4;
        }
    }
    ctx->pc = 0x104BC8u;
label_104bc8:
    // 0x104bc8: 0x2406000a  addiu       $a2, $zero, 0xA
    ctx->pc = 0x104bc8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x104bcc: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x104bccu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x104bd0: 0xc041fb4  jal         func_107ED0
    ctx->pc = 0x104BD0u;
    SET_GPR_U32(ctx, 31, 0x104BD8u);
    ctx->pc = 0x104BD4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x104BD0u;
            // 0x104bd4: 0x2e0202d  daddu       $a0, $s7, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107ED0u;
    if (runtime->hasFunction(0x107ED0u)) {
        auto targetFn = runtime->lookupFunction(0x107ED0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104BD8u; }
        if (ctx->pc != 0x104BD8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107ED0_0x107ed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104BD8u; }
        if (ctx->pc != 0x104BD8u) { return; }
    }
    ctx->pc = 0x104BD8u;
label_104bd8:
    // 0x104bd8: 0x2e0202d  daddu       $a0, $s7, $zero
    ctx->pc = 0x104bd8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x104bdc: 0x8fa5004c  lw          $a1, 0x4C($sp)
    ctx->pc = 0x104bdcu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 76)));
    // 0x104be0: 0x2406000a  addiu       $a2, $zero, 0xA
    ctx->pc = 0x104be0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x104be4: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x104be4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x104be8: 0xc041fb4  jal         func_107ED0
    ctx->pc = 0x104BE8u;
    SET_GPR_U32(ctx, 31, 0x104BF0u);
    ctx->pc = 0x104BECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x104BE8u;
            // 0x104bec: 0xafa20048  sw          $v0, 0x48($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 72), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107ED0u;
    if (runtime->hasFunction(0x107ED0u)) {
        auto targetFn = runtime->lookupFunction(0x107ED0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104BF0u; }
        if (ctx->pc != 0x104BF0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107ED0_0x107ed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104BF0u; }
        if (ctx->pc != 0x104BF0u) { return; }
    }
    ctx->pc = 0x104BF0u;
label_104bf0:
    // 0x104bf0: 0xafa2004c  sw          $v0, 0x4C($sp)
    ctx->pc = 0x104bf0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 76), GPR_U32(ctx, 2));
label_104bf4:
    // 0x104bf4: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x104bf4u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
label_104bf8:
    // 0x104bf8: 0x8fa40044  lw          $a0, 0x44($sp)
    ctx->pc = 0x104bf8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 68)));
    // 0x104bfc: 0xc040e92  jal         func_103A48
    ctx->pc = 0x104BFCu;
    SET_GPR_U32(ctx, 31, 0x104C04u);
    ctx->pc = 0x104C00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x104BFCu;
            // 0x104c00: 0x8fa50050  lw          $a1, 0x50($sp) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 80)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x103A48u;
    if (runtime->hasFunction(0x103A48u)) {
        auto targetFn = runtime->lookupFunction(0x103A48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104C04u; }
        if (ctx->pc != 0x104C04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00103A48_0x103a48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104C04u; }
        if (ctx->pc != 0x104C04u) { return; }
    }
    ctx->pc = 0x104C04u;
label_104c04:
    // 0x104c04: 0x8fa40044  lw          $a0, 0x44($sp)
    ctx->pc = 0x104c04u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 68)));
    // 0x104c08: 0x24540030  addiu       $s4, $v0, 0x30
    ctx->pc = 0x104c08u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 2), 48));
    // 0x104c0c: 0xc0421ba  jal         func_1086E8
    ctx->pc = 0x104C0Cu;
    SET_GPR_U32(ctx, 31, 0x104C14u);
    ctx->pc = 0x104C10u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x104C0Cu;
            // 0x104c10: 0x8fa50048  lw          $a1, 0x48($sp) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 72)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1086E8u;
    if (runtime->hasFunction(0x1086E8u)) {
        auto targetFn = runtime->lookupFunction(0x1086E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104C14u; }
        if (ctx->pc != 0x104C14u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001086E8_0x1086e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104C14u; }
        if (ctx->pc != 0x104C14u) { return; }
    }
    ctx->pc = 0x104C14u;
label_104c14:
    // 0x104c14: 0x2e0202d  daddu       $a0, $s7, $zero
    ctx->pc = 0x104c14u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x104c18: 0x8fa50050  lw          $a1, 0x50($sp)
    ctx->pc = 0x104c18u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x104c1c: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x104c1cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x104c20: 0xc0421d4  jal         func_108750
    ctx->pc = 0x104C20u;
    SET_GPR_U32(ctx, 31, 0x104C28u);
    ctx->pc = 0x104C24u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x104C20u;
            // 0x104c24: 0x8fa6004c  lw          $a2, 0x4C($sp) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 76)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x108750u;
    if (runtime->hasFunction(0x108750u)) {
        auto targetFn = runtime->lookupFunction(0x108750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104C28u; }
        if (ctx->pc != 0x104C28u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00108750_0x108750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104C28u; }
        if (ctx->pc != 0x104C28u) { return; }
    }
    ctx->pc = 0x104C28u;
label_104c28:
    // 0x104c28: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x104c28u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x104c2c: 0x8e42000c  lw          $v0, 0xC($s2)
    ctx->pc = 0x104c2cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 12)));
    // 0x104c30: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x104C30u;
    {
        const bool branch_taken_0x104c30 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x104C34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x104C30u;
            // 0x104c34: 0x24110001  addiu       $s1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x104c30) {
            ctx->pc = 0x104C48u;
            goto label_104c48;
        }
    }
    ctx->pc = 0x104C38u;
    // 0x104c38: 0x8fa40044  lw          $a0, 0x44($sp)
    ctx->pc = 0x104c38u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 68)));
    // 0x104c3c: 0xc0421ba  jal         func_1086E8
    ctx->pc = 0x104C3Cu;
    SET_GPR_U32(ctx, 31, 0x104C44u);
    ctx->pc = 0x104C40u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x104C3Cu;
            // 0x104c40: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1086E8u;
    if (runtime->hasFunction(0x1086E8u)) {
        auto targetFn = runtime->lookupFunction(0x1086E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104C44u; }
        if (ctx->pc != 0x104C44u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001086E8_0x1086e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104C44u; }
        if (ctx->pc != 0x104C44u) { return; }
    }
    ctx->pc = 0x104C44u;
label_104c44:
    // 0x104c44: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x104c44u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_104c48:
    // 0x104c48: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x104c48u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x104c4c: 0xc041fa8  jal         func_107EA0
    ctx->pc = 0x104C4Cu;
    SET_GPR_U32(ctx, 31, 0x104C54u);
    ctx->pc = 0x104C50u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x104C4Cu;
            // 0x104c50: 0x2e0202d  daddu       $a0, $s7, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107EA0u;
    if (runtime->hasFunction(0x107EA0u)) {
        auto targetFn = runtime->lookupFunction(0x107EA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104C54u; }
        if (ctx->pc != 0x104C54u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107EA0_0x107ea0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104C54u; }
        if (ctx->pc != 0x104C54u) { return; }
    }
    ctx->pc = 0x104C54u;
label_104c54:
    // 0x104c54: 0x1620000a  bnez        $s1, . + 4 + (0xA << 2)
    ctx->pc = 0x104C54u;
    {
        const bool branch_taken_0x104c54 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        ctx->pc = 0x104C58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x104C54u;
            // 0x104c58: 0x8fa30008  lw          $v1, 0x8($sp) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x104c54) {
            ctx->pc = 0x104C80u;
            goto label_104c80;
        }
    }
    ctx->pc = 0x104C5Cu;
    // 0x104c5c: 0x14600008  bnez        $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x104C5Cu;
    {
        const bool branch_taken_0x104c5c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x104c5c) {
            ctx->pc = 0x104C80u;
            goto label_104c80;
        }
    }
    ctx->pc = 0x104C64u;
    // 0x104c64: 0x16c00006  bnez        $s6, . + 4 + (0x6 << 2)
    ctx->pc = 0x104C64u;
    {
        const bool branch_taken_0x104c64 = (GPR_U64(ctx, 22) != GPR_U64(ctx, 0));
        ctx->pc = 0x104C68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x104C64u;
            // 0x104c68: 0x24040039  addiu       $a0, $zero, 0x39 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 57));
        ctx->in_delay_slot = false;
        if (branch_taken_0x104c64) {
            ctx->pc = 0x104C80u;
            goto label_104c80;
        }
    }
    ctx->pc = 0x104C6Cu;
    // 0x104c6c: 0x12840029  beq         $s4, $a0, . + 4 + (0x29 << 2)
    ctx->pc = 0x104C6Cu;
    {
        const bool branch_taken_0x104c6c = (GPR_U64(ctx, 20) == GPR_U64(ctx, 4));
        ctx->pc = 0x104C70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x104C6Cu;
            // 0x104c70: 0x230102a  slt         $v0, $s1, $s0 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)GPR_S64(ctx, 16)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x104c6c) {
            ctx->pc = 0x104D14u;
            goto label_104d14;
        }
    }
    ctx->pc = 0x104C74u;
    // 0x104c74: 0x282a021  addu        $s4, $s4, $v0
    ctx->pc = 0x104c74u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 2)));
    // 0x104c78: 0x10000071  b           . + 4 + (0x71 << 2)
    ctx->pc = 0x104C78u;
    {
        const bool branch_taken_0x104c78 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x104C7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x104C78u;
            // 0x104c7c: 0xa2b40000  sb          $s4, 0x0($s5) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 20));
        ctx->in_delay_slot = false;
        if (branch_taken_0x104c78) {
            ctx->pc = 0x104E40u;
            goto label_104e40;
        }
    }
    ctx->pc = 0x104C80u;
label_104c80:
    // 0x104c80: 0x6000007  bltz        $s0, . + 4 + (0x7 << 2)
    ctx->pc = 0x104C80u;
    {
        const bool branch_taken_0x104c80 = (GPR_S64(ctx, 16) < 0);
        if (branch_taken_0x104c80) {
            ctx->pc = 0x104CA0u;
            goto label_104ca0;
        }
    }
    ctx->pc = 0x104C88u;
    // 0x104c88: 0x1600001d  bnez        $s0, . + 4 + (0x1D << 2)
    ctx->pc = 0x104C88u;
    {
        const bool branch_taken_0x104c88 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x104C8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x104C88u;
            // 0x104c8c: 0x8fa20008  lw          $v0, 0x8($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x104c88) {
            ctx->pc = 0x104D00u;
            goto label_104d00;
        }
    }
    ctx->pc = 0x104C90u;
    // 0x104c90: 0x1440001b  bnez        $v0, . + 4 + (0x1B << 2)
    ctx->pc = 0x104C90u;
    {
        const bool branch_taken_0x104c90 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x104c90) {
            ctx->pc = 0x104D00u;
            goto label_104d00;
        }
    }
    ctx->pc = 0x104C98u;
    // 0x104c98: 0x16c00019  bnez        $s6, . + 4 + (0x19 << 2)
    ctx->pc = 0x104C98u;
    {
        const bool branch_taken_0x104c98 = (GPR_U64(ctx, 22) != GPR_U64(ctx, 0));
        if (branch_taken_0x104c98) {
            ctx->pc = 0x104D00u;
            goto label_104d00;
        }
    }
    ctx->pc = 0x104CA0u;
label_104ca0:
    // 0x104ca0: 0x5a200067  blezl       $s1, . + 4 + (0x67 << 2)
    ctx->pc = 0x104CA0u;
    {
        const bool branch_taken_0x104ca0 = (GPR_S64(ctx, 17) <= 0);
        if (branch_taken_0x104ca0) {
            ctx->pc = 0x104CA4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x104CA0u;
            // 0x104ca4: 0xa2b40000  sb          $s4, 0x0($s5) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 20));
        ctx->in_delay_slot = false;
            ctx->pc = 0x104E40u;
            goto label_104e40;
        }
    }
    ctx->pc = 0x104CA8u;
    // 0x104ca8: 0x8fa50044  lw          $a1, 0x44($sp)
    ctx->pc = 0x104ca8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 68)));
    // 0x104cac: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x104cacu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x104cb0: 0xc042164  jal         func_108590
    ctx->pc = 0x104CB0u;
    SET_GPR_U32(ctx, 31, 0x104CB8u);
    ctx->pc = 0x104CB4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x104CB0u;
            // 0x104cb4: 0x2e0202d  daddu       $a0, $s7, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x108590u;
    if (runtime->hasFunction(0x108590u)) {
        auto targetFn = runtime->lookupFunction(0x108590u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104CB8u; }
        if (ctx->pc != 0x104CB8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00108590_0x108590(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104CB8u; }
        if (ctx->pc != 0x104CB8u) { return; }
    }
    ctx->pc = 0x104CB8u;
label_104cb8:
    // 0x104cb8: 0x8fa50050  lw          $a1, 0x50($sp)
    ctx->pc = 0x104cb8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x104cbc: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x104cbcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x104cc0: 0xc0421ba  jal         func_1086E8
    ctx->pc = 0x104CC0u;
    SET_GPR_U32(ctx, 31, 0x104CC8u);
    ctx->pc = 0x104CC4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x104CC0u;
            // 0x104cc4: 0xafa20044  sw          $v0, 0x44($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 68), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1086E8u;
    if (runtime->hasFunction(0x1086E8u)) {
        auto targetFn = runtime->lookupFunction(0x1086E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104CC8u; }
        if (ctx->pc != 0x104CC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001086E8_0x1086e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104CC8u; }
        if (ctx->pc != 0x104CC8u) { return; }
    }
    ctx->pc = 0x104CC8u;
label_104cc8:
    // 0x104cc8: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x104cc8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x104ccc: 0x5e200007  bgtzl       $s1, . + 4 + (0x7 << 2)
    ctx->pc = 0x104CCCu;
    {
        const bool branch_taken_0x104ccc = (GPR_S64(ctx, 17) > 0);
        if (branch_taken_0x104ccc) {
            ctx->pc = 0x104CD0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x104CCCu;
            // 0x104cd0: 0x26940001  addiu       $s4, $s4, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x104CECu;
            goto label_104cec;
        }
    }
    ctx->pc = 0x104CD4u;
    // 0x104cd4: 0x5620005a  bnel        $s1, $zero, . + 4 + (0x5A << 2)
    ctx->pc = 0x104CD4u;
    {
        const bool branch_taken_0x104cd4 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        if (branch_taken_0x104cd4) {
            ctx->pc = 0x104CD8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x104CD4u;
            // 0x104cd8: 0xa2b40000  sb          $s4, 0x0($s5) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 20));
        ctx->in_delay_slot = false;
            ctx->pc = 0x104E40u;
            goto label_104e40;
        }
    }
    ctx->pc = 0x104CDCu;
    // 0x104cdc: 0x32820001  andi        $v0, $s4, 0x1
    ctx->pc = 0x104cdcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 20) & (uint64_t)(uint16_t)1);
    // 0x104ce0: 0x50400057  beql        $v0, $zero, . + 4 + (0x57 << 2)
    ctx->pc = 0x104CE0u;
    {
        const bool branch_taken_0x104ce0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x104ce0) {
            ctx->pc = 0x104CE4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x104CE0u;
            // 0x104ce4: 0xa2b40000  sb          $s4, 0x0($s5) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 20));
        ctx->in_delay_slot = false;
            ctx->pc = 0x104E40u;
            goto label_104e40;
        }
    }
    ctx->pc = 0x104CE8u;
    // 0x104ce8: 0x26940001  addiu       $s4, $s4, 0x1
    ctx->pc = 0x104ce8u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 1));
label_104cec:
    // 0x104cec: 0x2402003a  addiu       $v0, $zero, 0x3A
    ctx->pc = 0x104cecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 58));
    // 0x104cf0: 0x52820009  beql        $s4, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x104CF0u;
    {
        const bool branch_taken_0x104cf0 = (GPR_U64(ctx, 20) == GPR_U64(ctx, 2));
        if (branch_taken_0x104cf0) {
            ctx->pc = 0x104CF4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x104CF0u;
            // 0x104cf4: 0x24040039  addiu       $a0, $zero, 0x39 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 57));
        ctx->in_delay_slot = false;
            ctx->pc = 0x104D18u;
            goto label_104d18;
        }
    }
    ctx->pc = 0x104CF8u;
    // 0x104cf8: 0x10000051  b           . + 4 + (0x51 << 2)
    ctx->pc = 0x104CF8u;
    {
        const bool branch_taken_0x104cf8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x104CFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x104CF8u;
            // 0x104cfc: 0xa2b40000  sb          $s4, 0x0($s5) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 20));
        ctx->in_delay_slot = false;
        if (branch_taken_0x104cf8) {
            ctx->pc = 0x104E40u;
            goto label_104e40;
        }
    }
    ctx->pc = 0x104D00u;
label_104d00:
    // 0x104d00: 0x5a20000b  blezl       $s1, . + 4 + (0xB << 2)
    ctx->pc = 0x104D00u;
    {
        const bool branch_taken_0x104d00 = (GPR_S64(ctx, 17) <= 0);
        if (branch_taken_0x104d00) {
            ctx->pc = 0x104D04u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x104D00u;
            // 0x104d04: 0xa2b40000  sb          $s4, 0x0($s5) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 20));
        ctx->in_delay_slot = false;
            ctx->pc = 0x104D30u;
            goto label_104d30;
        }
    }
    ctx->pc = 0x104D08u;
    // 0x104d08: 0x24030039  addiu       $v1, $zero, 0x39
    ctx->pc = 0x104d08u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 57));
    // 0x104d0c: 0x16830006  bne         $s4, $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x104D0Cu;
    {
        const bool branch_taken_0x104d0c = (GPR_U64(ctx, 20) != GPR_U64(ctx, 3));
        ctx->pc = 0x104D10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x104D0Cu;
            // 0x104d10: 0x26820001  addiu       $v0, $s4, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 20), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x104d0c) {
            ctx->pc = 0x104D28u;
            goto label_104d28;
        }
    }
    ctx->pc = 0x104D14u;
label_104d14:
    // 0x104d14: 0x24040039  addiu       $a0, $zero, 0x39
    ctx->pc = 0x104d14u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 57));
label_104d18:
    // 0x104d18: 0xa2a40000  sb          $a0, 0x0($s5)
    ctx->pc = 0x104d18u;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x104d1c: 0x1000002a  b           . + 4 + (0x2A << 2)
    ctx->pc = 0x104D1Cu;
    {
        const bool branch_taken_0x104d1c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x104D20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x104D1Cu;
            // 0x104d20: 0x26b50001  addiu       $s5, $s5, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x104d1c) {
            ctx->pc = 0x104DC8u;
            goto label_104dc8;
        }
    }
    ctx->pc = 0x104D24u;
    // 0x104d24: 0x0  nop
    ctx->pc = 0x104d24u;
    // NOP
label_104d28:
    // 0x104d28: 0x10000045  b           . + 4 + (0x45 << 2)
    ctx->pc = 0x104D28u;
    {
        const bool branch_taken_0x104d28 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x104D2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x104D28u;
            // 0x104d2c: 0xa2a20000  sb          $v0, 0x0($s5) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x104d28) {
            ctx->pc = 0x104E40u;
            goto label_104e40;
        }
    }
    ctx->pc = 0x104D30u;
label_104d30:
    // 0x104d30: 0x8fa20020  lw          $v0, 0x20($sp)
    ctx->pc = 0x104d30u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x104d34: 0x1662ff92  bne         $s3, $v0, . + 4 + (-0x6E << 2)
    ctx->pc = 0x104D34u;
    {
        const bool branch_taken_0x104d34 = (GPR_U64(ctx, 19) != GPR_U64(ctx, 2));
        ctx->pc = 0x104D38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x104D34u;
            // 0x104d38: 0x26b50001  addiu       $s5, $s5, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x104d34) {
            ctx->pc = 0x104B80u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_104b80;
        }
    }
    ctx->pc = 0x104D3Cu;
    // 0x104d3c: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x104D3Cu;
    {
        const bool branch_taken_0x104d3c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x104D40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x104D3Cu;
            // 0x104d40: 0x8fa50044  lw          $a1, 0x44($sp) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 68)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x104d3c) {
            ctx->pc = 0x104D8Cu;
            goto label_104d8c;
        }
    }
    ctx->pc = 0x104D44u;
    // 0x104d44: 0x0  nop
    ctx->pc = 0x104d44u;
    // NOP
label_104d48:
    // 0x104d48: 0x8fa50044  lw          $a1, 0x44($sp)
    ctx->pc = 0x104d48u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 68)));
    // 0x104d4c: 0x2e0202d  daddu       $a0, $s7, $zero
    ctx->pc = 0x104d4cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x104d50: 0x2406000a  addiu       $a2, $zero, 0xA
    ctx->pc = 0x104d50u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x104d54: 0xc041fb4  jal         func_107ED0
    ctx->pc = 0x104D54u;
    SET_GPR_U32(ctx, 31, 0x104D5Cu);
    ctx->pc = 0x104D58u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x104D54u;
            // 0x104d58: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107ED0u;
    if (runtime->hasFunction(0x107ED0u)) {
        auto targetFn = runtime->lookupFunction(0x107ED0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104D5Cu; }
        if (ctx->pc != 0x104D5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107ED0_0x107ed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104D5Cu; }
        if (ctx->pc != 0x104D5Cu) { return; }
    }
    ctx->pc = 0x104D5Cu;
label_104d5c:
    // 0x104d5c: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x104d5cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
    // 0x104d60: 0xafa20044  sw          $v0, 0x44($sp)
    ctx->pc = 0x104d60u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 68), GPR_U32(ctx, 2));
label_104d64:
    // 0x104d64: 0x8fa40044  lw          $a0, 0x44($sp)
    ctx->pc = 0x104d64u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 68)));
    // 0x104d68: 0xc040e92  jal         func_103A48
    ctx->pc = 0x104D68u;
    SET_GPR_U32(ctx, 31, 0x104D70u);
    ctx->pc = 0x104D6Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x104D68u;
            // 0x104d6c: 0x8fa50050  lw          $a1, 0x50($sp) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 80)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x103A48u;
    if (runtime->hasFunction(0x103A48u)) {
        auto targetFn = runtime->lookupFunction(0x103A48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104D70u; }
        if (ctx->pc != 0x104D70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00103A48_0x103a48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104D70u; }
        if (ctx->pc != 0x104D70u) { return; }
    }
    ctx->pc = 0x104D70u;
label_104d70:
    // 0x104d70: 0x8fa40020  lw          $a0, 0x20($sp)
    ctx->pc = 0x104d70u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x104d74: 0x24540030  addiu       $s4, $v0, 0x30
    ctx->pc = 0x104d74u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 2), 48));
    // 0x104d78: 0xa2b40000  sb          $s4, 0x0($s5)
    ctx->pc = 0x104d78u;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 20));
    // 0x104d7c: 0x264182a  slt         $v1, $s3, $a0
    ctx->pc = 0x104d7cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 19) < (int64_t)GPR_S64(ctx, 4)) ? 1 : 0);
    // 0x104d80: 0x1460fff1  bnez        $v1, . + 4 + (-0xF << 2)
    ctx->pc = 0x104D80u;
    {
        const bool branch_taken_0x104d80 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x104D84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x104D80u;
            // 0x104d84: 0x26b50001  addiu       $s5, $s5, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x104d80) {
            ctx->pc = 0x104D48u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_104d48;
        }
    }
    ctx->pc = 0x104D88u;
    // 0x104d88: 0x8fa50044  lw          $a1, 0x44($sp)
    ctx->pc = 0x104d88u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 68)));
label_104d8c:
    // 0x104d8c: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x104d8cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x104d90: 0xc042164  jal         func_108590
    ctx->pc = 0x104D90u;
    SET_GPR_U32(ctx, 31, 0x104D98u);
    ctx->pc = 0x104D94u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x104D90u;
            // 0x104d94: 0x2e0202d  daddu       $a0, $s7, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x108590u;
    if (runtime->hasFunction(0x108590u)) {
        auto targetFn = runtime->lookupFunction(0x108590u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104D98u; }
        if (ctx->pc != 0x104D98u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00108590_0x108590(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104D98u; }
        if (ctx->pc != 0x104D98u) { return; }
    }
    ctx->pc = 0x104D98u;
label_104d98:
    // 0x104d98: 0x8fa50050  lw          $a1, 0x50($sp)
    ctx->pc = 0x104d98u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x104d9c: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x104d9cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x104da0: 0xc0421ba  jal         func_1086E8
    ctx->pc = 0x104DA0u;
    SET_GPR_U32(ctx, 31, 0x104DA8u);
    ctx->pc = 0x104DA4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x104DA0u;
            // 0x104da4: 0xafa20044  sw          $v0, 0x44($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 68), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1086E8u;
    if (runtime->hasFunction(0x1086E8u)) {
        auto targetFn = runtime->lookupFunction(0x1086E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104DA8u; }
        if (ctx->pc != 0x104DA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001086E8_0x1086e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104DA8u; }
        if (ctx->pc != 0x104DA8u) { return; }
    }
    ctx->pc = 0x104DA8u;
label_104da8:
    // 0x104da8: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x104da8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x104dac: 0x5e000007  bgtzl       $s0, . + 4 + (0x7 << 2)
    ctx->pc = 0x104DACu;
    {
        const bool branch_taken_0x104dac = (GPR_S64(ctx, 16) > 0);
        if (branch_taken_0x104dac) {
            ctx->pc = 0x104DB0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x104DACu;
            // 0x104db0: 0x26b5ffff  addiu       $s5, $s5, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), 4294967295));
        ctx->in_delay_slot = false;
            ctx->pc = 0x104DCCu;
            goto label_104dcc;
        }
    }
    ctx->pc = 0x104DB4u;
    // 0x104db4: 0x1600001a  bnez        $s0, . + 4 + (0x1A << 2)
    ctx->pc = 0x104DB4u;
    {
        const bool branch_taken_0x104db4 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x104DB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x104DB4u;
            // 0x104db8: 0x24030030  addiu       $v1, $zero, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 48));
        ctx->in_delay_slot = false;
        if (branch_taken_0x104db4) {
            ctx->pc = 0x104E20u;
            goto label_104e20;
        }
    }
    ctx->pc = 0x104DBCu;
    // 0x104dbc: 0x32820001  andi        $v0, $s4, 0x1
    ctx->pc = 0x104dbcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 20) & (uint64_t)(uint16_t)1);
    // 0x104dc0: 0x50400018  beql        $v0, $zero, . + 4 + (0x18 << 2)
    ctx->pc = 0x104DC0u;
    {
        const bool branch_taken_0x104dc0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x104dc0) {
            ctx->pc = 0x104DC4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x104DC0u;
            // 0x104dc4: 0x26b5ffff  addiu       $s5, $s5, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), 4294967295));
        ctx->in_delay_slot = false;
            ctx->pc = 0x104E24u;
            goto label_104e24;
        }
    }
    ctx->pc = 0x104DC8u;
label_104dc8:
    // 0x104dc8: 0x26b5ffff  addiu       $s5, $s5, -0x1
    ctx->pc = 0x104dc8u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), 4294967295));
label_104dcc:
    // 0x104dcc: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x104DCCu;
    {
        const bool branch_taken_0x104dcc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x104DD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x104DCCu;
            // 0x104dd0: 0x24030039  addiu       $v1, $zero, 0x39 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 57));
        ctx->in_delay_slot = false;
        if (branch_taken_0x104dcc) {
            ctx->pc = 0x104DE8u;
            goto label_104de8;
        }
    }
    ctx->pc = 0x104DD4u;
    // 0x104dd4: 0x0  nop
    ctx->pc = 0x104dd4u;
    // NOP
label_104dd8:
    // 0x104dd8: 0x8fa20054  lw          $v0, 0x54($sp)
    ctx->pc = 0x104dd8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 84)));
    // 0x104ddc: 0x52a2000a  beql        $s5, $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x104DDCu;
    {
        const bool branch_taken_0x104ddc = (GPR_U64(ctx, 21) == GPR_U64(ctx, 2));
        if (branch_taken_0x104ddc) {
            ctx->pc = 0x104DE0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x104DDCu;
            // 0x104de0: 0x8fa30054  lw          $v1, 0x54($sp) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 84)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x104E08u;
            goto label_104e08;
        }
    }
    ctx->pc = 0x104DE4u;
    // 0x104de4: 0x26b5ffff  addiu       $s5, $s5, -0x1
    ctx->pc = 0x104de4u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), 4294967295));
label_104de8:
    // 0x104de8: 0x82a20000  lb          $v0, 0x0($s5)
    ctx->pc = 0x104de8u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 21), 0)));
    // 0x104dec: 0x0  nop
    ctx->pc = 0x104decu;
    // NOP
    // 0x104df0: 0x0  nop
    ctx->pc = 0x104df0u;
    // NOP
    // 0x104df4: 0x1043fff8  beq         $v0, $v1, . + 4 + (-0x8 << 2)
    ctx->pc = 0x104DF4u;
    {
        const bool branch_taken_0x104df4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x104DF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x104DF4u;
            // 0x104df8: 0x92a40000  lbu         $a0, 0x0($s5) (Delay Slot)
        SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 21), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x104df4) {
            ctx->pc = 0x104DD8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_104dd8;
        }
    }
    ctx->pc = 0x104DFCu;
    // 0x104dfc: 0x24820001  addiu       $v0, $a0, 0x1
    ctx->pc = 0x104dfcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x104e00: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x104E00u;
    {
        const bool branch_taken_0x104e00 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x104E04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x104E00u;
            // 0x104e04: 0xa2a20000  sb          $v0, 0x0($s5) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x104e00) {
            ctx->pc = 0x104E40u;
            goto label_104e40;
        }
    }
    ctx->pc = 0x104E08u;
label_104e08:
    // 0x104e08: 0x24020031  addiu       $v0, $zero, 0x31
    ctx->pc = 0x104e08u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 49));
    // 0x104e0c: 0x27de0001  addiu       $fp, $fp, 0x1
    ctx->pc = 0x104e0cu;
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 30), 1));
    // 0x104e10: 0xa0620000  sb          $v0, 0x0($v1)
    ctx->pc = 0x104e10u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x104e14: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x104E14u;
    {
        const bool branch_taken_0x104e14 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x104E18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x104E14u;
            // 0x104e18: 0x24750001  addiu       $s5, $v1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x104e14) {
            ctx->pc = 0x104E44u;
            goto label_104e44;
        }
    }
    ctx->pc = 0x104E1Cu;
    // 0x104e1c: 0x0  nop
    ctx->pc = 0x104e1cu;
    // NOP
label_104e20:
    // 0x104e20: 0x26b5ffff  addiu       $s5, $s5, -0x1
    ctx->pc = 0x104e20u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), 4294967295));
label_104e24:
    // 0x104e24: 0x82a20000  lb          $v0, 0x0($s5)
    ctx->pc = 0x104e24u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 21), 0)));
    // 0x104e28: 0x0  nop
    ctx->pc = 0x104e28u;
    // NOP
    // 0x104e2c: 0x0  nop
    ctx->pc = 0x104e2cu;
    // NOP
    // 0x104e30: 0x0  nop
    ctx->pc = 0x104e30u;
    // NOP
    // 0x104e34: 0x0  nop
    ctx->pc = 0x104e34u;
    // NOP
    // 0x104e38: 0x5043fffa  beql        $v0, $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x104E38u;
    {
        const bool branch_taken_0x104e38 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x104e38) {
            ctx->pc = 0x104E3Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x104E38u;
            // 0x104e3c: 0x26b5ffff  addiu       $s5, $s5, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), 4294967295));
        ctx->in_delay_slot = false;
            ctx->pc = 0x104E24u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_104e24;
        }
    }
    ctx->pc = 0x104E40u;
label_104e40:
    // 0x104e40: 0x26b50001  addiu       $s5, $s5, 0x1
    ctx->pc = 0x104e40u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), 1));
label_104e44:
    // 0x104e44: 0x8fa50050  lw          $a1, 0x50($sp)
    ctx->pc = 0x104e44u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x104e48: 0xc041fa8  jal         func_107EA0
    ctx->pc = 0x104E48u;
    SET_GPR_U32(ctx, 31, 0x104E50u);
    ctx->pc = 0x104E4Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x104E48u;
            // 0x104e4c: 0x2e0202d  daddu       $a0, $s7, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107EA0u;
    if (runtime->hasFunction(0x107EA0u)) {
        auto targetFn = runtime->lookupFunction(0x107EA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104E50u; }
        if (ctx->pc != 0x104E50u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107EA0_0x107ea0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104E50u; }
        if (ctx->pc != 0x104E50u) { return; }
    }
    ctx->pc = 0x104E50u;
label_104e50:
    // 0x104e50: 0x8fa4004c  lw          $a0, 0x4C($sp)
    ctx->pc = 0x104e50u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 76)));
    // 0x104e54: 0x1080000a  beqz        $a0, . + 4 + (0xA << 2)
    ctx->pc = 0x104E54u;
    {
        const bool branch_taken_0x104e54 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x104E58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x104E54u;
            // 0x104e58: 0x8fa20048  lw          $v0, 0x48($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 72)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x104e54) {
            ctx->pc = 0x104E80u;
            goto label_104e80;
        }
    }
    ctx->pc = 0x104E5Cu;
    // 0x104e5c: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x104E5Cu;
    {
        const bool branch_taken_0x104e5c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x104E60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x104E5Cu;
            // 0x104e60: 0x8fa5004c  lw          $a1, 0x4C($sp) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 76)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x104e5c) {
            ctx->pc = 0x104E78u;
            goto label_104e78;
        }
    }
    ctx->pc = 0x104E64u;
    // 0x104e64: 0x10440003  beq         $v0, $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x104E64u;
    {
        const bool branch_taken_0x104e64 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 4));
        ctx->pc = 0x104E68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x104E64u;
            // 0x104e68: 0x40282d  daddu       $a1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x104e64) {
            ctx->pc = 0x104E74u;
            goto label_104e74;
        }
    }
    ctx->pc = 0x104E6Cu;
    // 0x104e6c: 0xc041fa8  jal         func_107EA0
    ctx->pc = 0x104E6Cu;
    SET_GPR_U32(ctx, 31, 0x104E74u);
    ctx->pc = 0x104E70u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x104E6Cu;
            // 0x104e70: 0x2e0202d  daddu       $a0, $s7, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107EA0u;
    if (runtime->hasFunction(0x107EA0u)) {
        auto targetFn = runtime->lookupFunction(0x107EA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104E74u; }
        if (ctx->pc != 0x104E74u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107EA0_0x107ea0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104E74u; }
        if (ctx->pc != 0x104E74u) { return; }
    }
    ctx->pc = 0x104E74u;
label_104e74:
    // 0x104e74: 0x8fa5004c  lw          $a1, 0x4C($sp)
    ctx->pc = 0x104e74u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 76)));
label_104e78:
    // 0x104e78: 0xc041fa8  jal         func_107EA0
    ctx->pc = 0x104E78u;
    SET_GPR_U32(ctx, 31, 0x104E80u);
    ctx->pc = 0x104E7Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x104E78u;
            // 0x104e7c: 0x2e0202d  daddu       $a0, $s7, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107EA0u;
    if (runtime->hasFunction(0x107EA0u)) {
        auto targetFn = runtime->lookupFunction(0x107EA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104E80u; }
        if (ctx->pc != 0x104E80u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107EA0_0x107ea0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104E80u; }
        if (ctx->pc != 0x104E80u) { return; }
    }
    ctx->pc = 0x104E80u;
label_104e80:
    // 0x104e80: 0x8fa50044  lw          $a1, 0x44($sp)
    ctx->pc = 0x104e80u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 68)));
label_104e84:
    // 0x104e84: 0xc041fa8  jal         func_107EA0
    ctx->pc = 0x104E84u;
    SET_GPR_U32(ctx, 31, 0x104E8Cu);
    ctx->pc = 0x104E88u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x104E84u;
            // 0x104e88: 0x2e0202d  daddu       $a0, $s7, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107EA0u;
    if (runtime->hasFunction(0x107EA0u)) {
        auto targetFn = runtime->lookupFunction(0x107EA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104E8Cu; }
        if (ctx->pc != 0x104E8Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107EA0_0x107ea0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x104E8Cu; }
        if (ctx->pc != 0x104E8Cu) { return; }
    }
    ctx->pc = 0x104E8Cu;
label_104e8c:
    // 0x104e8c: 0xa2a00000  sb          $zero, 0x0($s5)
    ctx->pc = 0x104e8cu;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x104e90: 0x27c20001  addiu       $v0, $fp, 0x1
    ctx->pc = 0x104e90u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 1));
    // 0x104e94: 0x8fa30010  lw          $v1, 0x10($sp)
    ctx->pc = 0x104e94u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x104e98: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x104e98u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x104e9c: 0x8fa40014  lw          $a0, 0x14($sp)
    ctx->pc = 0x104e9cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x104ea0: 0x54800001  bnel        $a0, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x104EA0u;
    {
        const bool branch_taken_0x104ea0 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        if (branch_taken_0x104ea0) {
            ctx->pc = 0x104EA4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x104EA0u;
            // 0x104ea4: 0xac950000  sw          $s5, 0x0($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 21));
        ctx->in_delay_slot = false;
            ctx->pc = 0x104EA8u;
            goto label_104ea8;
        }
    }
    ctx->pc = 0x104EA8u;
label_104ea8:
    // 0x104ea8: 0x8fa20054  lw          $v0, 0x54($sp)
    ctx->pc = 0x104ea8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 84)));
label_104eac:
    // 0x104eac: 0xdfb00060  ld          $s0, 0x60($sp)
    ctx->pc = 0x104eacu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x104eb0: 0xdfb10068  ld          $s1, 0x68($sp)
    ctx->pc = 0x104eb0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 104)));
    // 0x104eb4: 0xdfb20070  ld          $s2, 0x70($sp)
    ctx->pc = 0x104eb4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x104eb8: 0xdfb30078  ld          $s3, 0x78($sp)
    ctx->pc = 0x104eb8u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 120)));
    // 0x104ebc: 0xdfb40080  ld          $s4, 0x80($sp)
    ctx->pc = 0x104ebcu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x104ec0: 0xdfb50088  ld          $s5, 0x88($sp)
    ctx->pc = 0x104ec0u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 136)));
    // 0x104ec4: 0xdfb60090  ld          $s6, 0x90($sp)
    ctx->pc = 0x104ec4u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x104ec8: 0xdfb70098  ld          $s7, 0x98($sp)
    ctx->pc = 0x104ec8u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 152)));
    // 0x104ecc: 0xdfbe00a0  ld          $fp, 0xA0($sp)
    ctx->pc = 0x104eccu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x104ed0: 0xdfbf00a8  ld          $ra, 0xA8($sp)
    ctx->pc = 0x104ed0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 168)));
    // 0x104ed4: 0x3e00008  jr          $ra
    ctx->pc = 0x104ED4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x104ED8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x104ED4u;
            // 0x104ed8: 0x27bd00b0  addiu       $sp, $sp, 0xB0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 176));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x103CE8u: goto label_103ce8;
            case 0x103CECu: goto label_103cec;
            case 0x103D2Cu: goto label_103d2c;
            case 0x103D68u: goto label_103d68;
            case 0x103D70u: goto label_103d70;
            case 0x103D98u: goto label_103d98;
            case 0x103DA8u: goto label_103da8;
            case 0x103DD8u: goto label_103dd8;
            case 0x103DE0u: goto label_103de0;
            case 0x103DF0u: goto label_103df0;
            case 0x103E50u: goto label_103e50;
            case 0x103E90u: goto label_103e90;
            case 0x103E9Cu: goto label_103e9c;
            case 0x103EA4u: goto label_103ea4;
            case 0x103EC0u: goto label_103ec0;
            case 0x103EF0u: goto label_103ef0;
            case 0x103F04u: goto label_103f04;
            case 0x103F18u: goto label_103f18;
            case 0x103F2Cu: goto label_103f2c;
            case 0x103F38u: goto label_103f38;
            case 0x103F4Cu: goto label_103f4c;
            case 0x103F5Cu: goto label_103f5c;
            case 0x103F6Cu: goto label_103f6c;
            case 0x103F7Cu: goto label_103f7c;
            case 0x103F8Cu: goto label_103f8c;
            case 0x103F9Cu: goto label_103f9c;
            case 0x103FA8u: goto label_103fa8;
            case 0x103FD0u: goto label_103fd0;
            case 0x103FDCu: goto label_103fdc;
            case 0x103FF8u: goto label_103ff8;
            case 0x104000u: goto label_104000;
            case 0x104020u: goto label_104020;
            case 0x104038u: goto label_104038;
            case 0x104060u: goto label_104060;
            case 0x1040A0u: goto label_1040a0;
            case 0x1040B0u: goto label_1040b0;
            case 0x1040B4u: goto label_1040b4;
            case 0x1040D8u: goto label_1040d8;
            case 0x1040DCu: goto label_1040dc;
            case 0x1040FCu: goto label_1040fc;
            case 0x104110u: goto label_104110;
            case 0x104130u: goto label_104130;
            case 0x10413Cu: goto label_10413c;
            case 0x1041ACu: goto label_1041ac;
            case 0x1041B0u: goto label_1041b0;
            case 0x1041C0u: goto label_1041c0;
            case 0x1041DCu: goto label_1041dc;
            case 0x1041E4u: goto label_1041e4;
            case 0x1041ECu: goto label_1041ec;
            case 0x1041FCu: goto label_1041fc;
            case 0x104208u: goto label_104208;
            case 0x104230u: goto label_104230;
            case 0x104240u: goto label_104240;
            case 0x10425Cu: goto label_10425c;
            case 0x104264u: goto label_104264;
            case 0x10426Cu: goto label_10426c;
            case 0x10428Cu: goto label_10428c;
            case 0x1042C4u: goto label_1042c4;
            case 0x1042C8u: goto label_1042c8;
            case 0x1042D0u: goto label_1042d0;
            case 0x1042E0u: goto label_1042e0;
            case 0x1042F4u: goto label_1042f4;
            case 0x10433Cu: goto label_10433c;
            case 0x104350u: goto label_104350;
            case 0x104368u: goto label_104368;
            case 0x104378u: goto label_104378;
            case 0x104388u: goto label_104388;
            case 0x1043B0u: goto label_1043b0;
            case 0x1043C0u: goto label_1043c0;
            case 0x1043C8u: goto label_1043c8;
            case 0x1043DCu: goto label_1043dc;
            case 0x1043F0u: goto label_1043f0;
            case 0x1043F4u: goto label_1043f4;
            case 0x104400u: goto label_104400;
            case 0x10440Cu: goto label_10440c;
            case 0x10441Cu: goto label_10441c;
            case 0x104438u: goto label_104438;
            case 0x104454u: goto label_104454;
            case 0x104464u: goto label_104464;
            case 0x104488u: goto label_104488;
            case 0x1044A4u: goto label_1044a4;
            case 0x1044A8u: goto label_1044a8;
            case 0x1044B4u: goto label_1044b4;
            case 0x1044C0u: goto label_1044c0;
            case 0x1044D0u: goto label_1044d0;
            case 0x1044FCu: goto label_1044fc;
            case 0x10450Cu: goto label_10450c;
            case 0x104528u: goto label_104528;
            case 0x104538u: goto label_104538;
            case 0x104548u: goto label_104548;
            case 0x104570u: goto label_104570;
            case 0x104584u: goto label_104584;
            case 0x104590u: goto label_104590;
            case 0x1045A0u: goto label_1045a0;
            case 0x1045A4u: goto label_1045a4;
            case 0x1045FCu: goto label_1045fc;
            case 0x10460Cu: goto label_10460c;
            case 0x104620u: goto label_104620;
            case 0x104630u: goto label_104630;
            case 0x10463Cu: goto label_10463c;
            case 0x104648u: goto label_104648;
            case 0x104658u: goto label_104658;
            case 0x104668u: goto label_104668;
            case 0x10468Cu: goto label_10468c;
            case 0x1046A0u: goto label_1046a0;
            case 0x1046B8u: goto label_1046b8;
            case 0x1046CCu: goto label_1046cc;
            case 0x1046D8u: goto label_1046d8;
            case 0x104708u: goto label_104708;
            case 0x104718u: goto label_104718;
            case 0x104728u: goto label_104728;
            case 0x10473Cu: goto label_10473c;
            case 0x104750u: goto label_104750;
            case 0x104754u: goto label_104754;
            case 0x104798u: goto label_104798;
            case 0x1047CCu: goto label_1047cc;
            case 0x1047E4u: goto label_1047e4;
            case 0x1047E8u: goto label_1047e8;
            case 0x1047FCu: goto label_1047fc;
            case 0x10480Cu: goto label_10480c;
            case 0x104844u: goto label_104844;
            case 0x104870u: goto label_104870;
            case 0x104884u: goto label_104884;
            case 0x104894u: goto label_104894;
            case 0x10489Cu: goto label_10489c;
            case 0x1048B8u: goto label_1048b8;
            case 0x1048C0u: goto label_1048c0;
            case 0x1048CCu: goto label_1048cc;
            case 0x1048D0u: goto label_1048d0;
            case 0x1048D4u: goto label_1048d4;
            case 0x1048DCu: goto label_1048dc;
            case 0x1048F8u: goto label_1048f8;
            case 0x1048FCu: goto label_1048fc;
            case 0x104944u: goto label_104944;
            case 0x104948u: goto label_104948;
            case 0x104964u: goto label_104964;
            case 0x104970u: goto label_104970;
            case 0x104978u: goto label_104978;
            case 0x104988u: goto label_104988;
            case 0x1049B8u: goto label_1049b8;
            case 0x1049E0u: goto label_1049e0;
            case 0x1049E4u: goto label_1049e4;
            case 0x1049FCu: goto label_1049fc;
            case 0x104A04u: goto label_104a04;
            case 0x104A1Cu: goto label_104a1c;
            case 0x104A24u: goto label_104a24;
            case 0x104A34u: goto label_104a34;
            case 0x104A50u: goto label_104a50;
            case 0x104A74u: goto label_104a74;
            case 0x104A78u: goto label_104a78;
            case 0x104A80u: goto label_104a80;
            case 0x104A84u: goto label_104a84;
            case 0x104AB8u: goto label_104ab8;
            case 0x104AC8u: goto label_104ac8;
            case 0x104AD0u: goto label_104ad0;
            case 0x104AD4u: goto label_104ad4;
            case 0x104AE0u: goto label_104ae0;
            case 0x104AF8u: goto label_104af8;
            case 0x104B18u: goto label_104b18;
            case 0x104B20u: goto label_104b20;
            case 0x104B34u: goto label_104b34;
            case 0x104B54u: goto label_104b54;
            case 0x104B64u: goto label_104b64;
            case 0x104B68u: goto label_104b68;
            case 0x104B80u: goto label_104b80;
            case 0x104B94u: goto label_104b94;
            case 0x104BBCu: goto label_104bbc;
            case 0x104BC8u: goto label_104bc8;
            case 0x104BD8u: goto label_104bd8;
            case 0x104BF0u: goto label_104bf0;
            case 0x104BF4u: goto label_104bf4;
            case 0x104BF8u: goto label_104bf8;
            case 0x104C04u: goto label_104c04;
            case 0x104C14u: goto label_104c14;
            case 0x104C28u: goto label_104c28;
            case 0x104C44u: goto label_104c44;
            case 0x104C48u: goto label_104c48;
            case 0x104C54u: goto label_104c54;
            case 0x104C80u: goto label_104c80;
            case 0x104CA0u: goto label_104ca0;
            case 0x104CB8u: goto label_104cb8;
            case 0x104CC8u: goto label_104cc8;
            case 0x104CECu: goto label_104cec;
            case 0x104D00u: goto label_104d00;
            case 0x104D14u: goto label_104d14;
            case 0x104D18u: goto label_104d18;
            case 0x104D28u: goto label_104d28;
            case 0x104D30u: goto label_104d30;
            case 0x104D48u: goto label_104d48;
            case 0x104D5Cu: goto label_104d5c;
            case 0x104D64u: goto label_104d64;
            case 0x104D70u: goto label_104d70;
            case 0x104D8Cu: goto label_104d8c;
            case 0x104D98u: goto label_104d98;
            case 0x104DA8u: goto label_104da8;
            case 0x104DC8u: goto label_104dc8;
            case 0x104DCCu: goto label_104dcc;
            case 0x104DD8u: goto label_104dd8;
            case 0x104DE8u: goto label_104de8;
            case 0x104E08u: goto label_104e08;
            case 0x104E20u: goto label_104e20;
            case 0x104E24u: goto label_104e24;
            case 0x104E40u: goto label_104e40;
            case 0x104E44u: goto label_104e44;
            case 0x104E50u: goto label_104e50;
            case 0x104E74u: goto label_104e74;
            case 0x104E78u: goto label_104e78;
            case 0x104E80u: goto label_104e80;
            case 0x104E84u: goto label_104e84;
            case 0x104E8Cu: goto label_104e8c;
            case 0x104EA8u: goto label_104ea8;
            case 0x104EACu: goto label_104eac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x104EDCu;
    // 0x104edc: 0x0  nop
    ctx->pc = 0x104edcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
