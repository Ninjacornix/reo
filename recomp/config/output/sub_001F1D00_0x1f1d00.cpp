#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F1D00
// Address: 0x1f1d00 - 0x1f2028
void sub_001F1D00_0x1f1d00(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F1D00_0x1f1d00");
#endif

    switch (ctx->pc) {
        case 0x1f1d38u: goto label_1f1d38;
        case 0x1f1da8u: goto label_1f1da8;
        case 0x1f1db8u: goto label_1f1db8;
        case 0x1f1ddcu: goto label_1f1ddc;
        case 0x1f1e20u: goto label_1f1e20;
        case 0x1f1e80u: goto label_1f1e80;
        case 0x1f1ea4u: goto label_1f1ea4;
        case 0x1f1eecu: goto label_1f1eec;
        case 0x1f1f4cu: goto label_1f1f4c;
        case 0x1f1f70u: goto label_1f1f70;
        case 0x1f1fb8u: goto label_1f1fb8;
        default: break;
    }

    ctx->pc = 0x1f1d00u;

    // 0x1f1d00: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1f1d00u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1f1d04: 0xffbe0030  sd          $fp, 0x30($sp)
    ctx->pc = 0x1f1d04u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 30));
    // 0x1f1d08: 0xffbf0038  sd          $ra, 0x38($sp)
    ctx->pc = 0x1f1d08u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x1f1d0c: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1f1d0cu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f1d10: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1f1d10u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1f1d14: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x1f1d14u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f1d18: 0xc0182d  daddu       $v1, $a2, $zero
    ctx->pc = 0x1f1d18u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f1d1c: 0xe0202d  daddu       $a0, $a3, $zero
    ctx->pc = 0x1f1d1cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f1d20: 0xa7c20004  sh          $v0, 0x4($fp)
    ctx->pc = 0x1f1d20u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 4), (uint16_t)GPR_U32(ctx, 2));
    // 0x1f1d24: 0xa7c30006  sh          $v1, 0x6($fp)
    ctx->pc = 0x1f1d24u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 6), (uint16_t)GPR_U32(ctx, 3));
    // 0x1f1d28: 0xa7c40008  sh          $a0, 0x8($fp)
    ctx->pc = 0x1f1d28u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 8), (uint16_t)GPR_U32(ctx, 4));
    // 0x1f1d2c: 0x24040078  addiu       $a0, $zero, 0x78
    ctx->pc = 0x1f1d2cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 120));
    // 0x1f1d30: 0xc079f1f  jal         func_1E7C7C
    ctx->pc = 0x1F1D30u;
    SET_GPR_U32(ctx, 31, 0x1F1D38u);
    ctx->pc = 0x1E7C7Cu;
    if (runtime->hasFunction(0x1E7C7Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E7C7Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F1D38u; }
        if (ctx->pc != 0x1F1D38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E7C7C_0x1e7c7c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F1D38u; }
        if (ctx->pc != 0x1F1D38u) { return; }
    }
    ctx->pc = 0x1F1D38u;
label_1f1d38:
    // 0x1f1d38: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1f1d38u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1f1d3c: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1f1d3cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1f1d40: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1F1D40u;
    {
        const bool branch_taken_0x1f1d40 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1f1d40) {
            ctx->pc = 0x1F1D54u;
            goto label_1f1d54;
        }
    }
    ctx->pc = 0x1F1D48u;
    // 0x1f1d48: 0x2402e4a9  addiu       $v0, $zero, -0x1B57
    ctx->pc = 0x1f1d48u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294960297));
    // 0x1f1d4c: 0x100000b0  b           . + 4 + (0xB0 << 2)
    ctx->pc = 0x1F1D4Cu;
    {
        const bool branch_taken_0x1f1d4c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f1d4c) {
            ctx->pc = 0x1F2010u;
            goto label_1f2010;
        }
    }
    ctx->pc = 0x1F1D54u;
label_1f1d54:
    // 0x1f1d54: 0x8fc30010  lw          $v1, 0x10($fp)
    ctx->pc = 0x1f1d54u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1f1d58: 0x240200ec  addiu       $v0, $zero, 0xEC
    ctx->pc = 0x1f1d58u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 236));
    // 0x1f1d5c: 0xa462005e  sh          $v0, 0x5E($v1)
    ctx->pc = 0x1f1d5cu;
    WRITE16(ADD32(GPR_U32(ctx, 3), 94), (uint16_t)GPR_U32(ctx, 2));
    // 0x1f1d60: 0x8fc30010  lw          $v1, 0x10($fp)
    ctx->pc = 0x1f1d60u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1f1d64: 0x2402022c  addiu       $v0, $zero, 0x22C
    ctx->pc = 0x1f1d64u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 556));
    // 0x1f1d68: 0xa4620064  sh          $v0, 0x64($v1)
    ctx->pc = 0x1f1d68u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 100), (uint16_t)GPR_U32(ctx, 2));
    // 0x1f1d6c: 0x8fc30010  lw          $v1, 0x10($fp)
    ctx->pc = 0x1f1d6cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1f1d70: 0x240203ac  addiu       $v0, $zero, 0x3AC
    ctx->pc = 0x1f1d70u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 940));
    // 0x1f1d74: 0xa462006a  sh          $v0, 0x6A($v1)
    ctx->pc = 0x1f1d74u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 106), (uint16_t)GPR_U32(ctx, 2));
    // 0x1f1d78: 0x8fc30010  lw          $v1, 0x10($fp)
    ctx->pc = 0x1f1d78u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1f1d7c: 0x24020006  addiu       $v0, $zero, 0x6
    ctx->pc = 0x1f1d7cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x1f1d80: 0xa4620070  sh          $v0, 0x70($v1)
    ctx->pc = 0x1f1d80u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 112), (uint16_t)GPR_U32(ctx, 2));
    // 0x1f1d84: 0x8fc30010  lw          $v1, 0x10($fp)
    ctx->pc = 0x1f1d84u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1f1d88: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1f1d88u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1f1d8c: 0xa4620072  sh          $v0, 0x72($v1)
    ctx->pc = 0x1f1d8cu;
    WRITE16(ADD32(GPR_U32(ctx, 3), 114), (uint16_t)GPR_U32(ctx, 2));
    // 0x1f1d90: 0x8fc30010  lw          $v1, 0x10($fp)
    ctx->pc = 0x1f1d90u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1f1d94: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1f1d94u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1f1d98: 0xa4620074  sh          $v0, 0x74($v1)
    ctx->pc = 0x1f1d98u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 116), (uint16_t)GPR_U32(ctx, 2));
    // 0x1f1d9c: 0x8fc40010  lw          $a0, 0x10($fp)
    ctx->pc = 0x1f1d9cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1f1da0: 0xc07cad6  jal         func_1F2B58
    ctx->pc = 0x1F1DA0u;
    SET_GPR_U32(ctx, 31, 0x1F1DA8u);
    ctx->pc = 0x1F2B58u;
    if (runtime->hasFunction(0x1F2B58u)) {
        auto targetFn = runtime->lookupFunction(0x1F2B58u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F1DA8u; }
        if (ctx->pc != 0x1F1DA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2B58_0x1f2b58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F1DA8u; }
        if (ctx->pc != 0x1F1DA8u) { return; }
    }
    ctx->pc = 0x1F1DA8u;
label_1f1da8:
    // 0x1f1da8: 0x8fc40010  lw          $a0, 0x10($fp)
    ctx->pc = 0x1f1da8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1f1dac: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1f1dacu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f1db0: 0xc07c417  jal         func_1F105C
    ctx->pc = 0x1F1DB0u;
    SET_GPR_U32(ctx, 31, 0x1F1DB8u);
    ctx->pc = 0x1F105Cu;
    if (runtime->hasFunction(0x1F105Cu)) {
        auto targetFn = runtime->lookupFunction(0x1F105Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F1DB8u; }
        if (ctx->pc != 0x1F1DB8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F105C_0x1f105c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F1DB8u; }
        if (ctx->pc != 0x1F1DB8u) { return; }
    }
    ctx->pc = 0x1F1DB8u;
label_1f1db8:
    // 0x1f1db8: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1f1db8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1f1dbc: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1f1dbcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1f1dc0: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1F1DC0u;
    {
        const bool branch_taken_0x1f1dc0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f1dc0) {
            ctx->pc = 0x1F1DD4u;
            goto label_1f1dd4;
        }
    }
    ctx->pc = 0x1F1DC8u;
    // 0x1f1dc8: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1f1dc8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1f1dcc: 0x10000090  b           . + 4 + (0x90 << 2)
    ctx->pc = 0x1F1DCCu;
    {
        const bool branch_taken_0x1f1dcc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f1dcc) {
            ctx->pc = 0x1F2010u;
            goto label_1f2010;
        }
    }
    ctx->pc = 0x1F1DD4u;
label_1f1dd4:
    // 0x1f1dd4: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1f1dd4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1f1dd8: 0xa440005c  sh          $zero, 0x5C($v0)
    ctx->pc = 0x1f1dd8u;
    WRITE16(ADD32(GPR_U32(ctx, 2), 92), (uint16_t)GPR_U32(ctx, 0));
label_1f1ddc:
    // 0x1f1ddc: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1f1ddcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1f1de0: 0x9443005c  lhu         $v1, 0x5C($v0)
    ctx->pc = 0x1f1de0u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 92)));
    // 0x1f1de4: 0x97c20004  lhu         $v0, 0x4($fp)
    ctx->pc = 0x1f1de4u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f1de8: 0x62102b  sltu        $v0, $v1, $v0
    ctx->pc = 0x1f1de8u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x1f1dec: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F1DECu;
    {
        const bool branch_taken_0x1f1dec = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1f1dec) {
            ctx->pc = 0x1F1DFCu;
            goto label_1f1dfc;
        }
    }
    ctx->pc = 0x1F1DF4u;
    // 0x1f1df4: 0x10000018  b           . + 4 + (0x18 << 2)
    ctx->pc = 0x1F1DF4u;
    {
        const bool branch_taken_0x1f1df4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f1df4) {
            ctx->pc = 0x1F1E58u;
            goto label_1f1e58;
        }
    }
    ctx->pc = 0x1F1DFCu;
label_1f1dfc:
    // 0x1f1dfc: 0x27c30014  addiu       $v1, $fp, 0x14
    ctx->pc = 0x1f1dfcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 30), 20));
    // 0x1f1e00: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1f1e00u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1f1e04: 0x9442005e  lhu         $v0, 0x5E($v0)
    ctx->pc = 0x1f1e04u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 94)));
    // 0x1f1e08: 0x8fc40010  lw          $a0, 0x10($fp)
    ctx->pc = 0x1f1e08u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1f1e0c: 0x60282d  daddu       $a1, $v1, $zero
    ctx->pc = 0x1f1e0cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f1e10: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x1f1e10u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f1e14: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1f1e14u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f1e18: 0xc07c644  jal         func_1F1910
    ctx->pc = 0x1F1E18u;
    SET_GPR_U32(ctx, 31, 0x1F1E20u);
    ctx->pc = 0x1F1910u;
    if (runtime->hasFunction(0x1F1910u)) {
        auto targetFn = runtime->lookupFunction(0x1F1910u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F1E20u; }
        if (ctx->pc != 0x1F1E20u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1910_0x1f1910(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F1E20u; }
        if (ctx->pc != 0x1F1E20u) { return; }
    }
    ctx->pc = 0x1F1E20u;
label_1f1e20:
    // 0x1f1e20: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1f1e20u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1f1e24: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1f1e24u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1f1e28: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1F1E28u;
    {
        const bool branch_taken_0x1f1e28 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f1e28) {
            ctx->pc = 0x1F1E3Cu;
            goto label_1f1e3c;
        }
    }
    ctx->pc = 0x1F1E30u;
    // 0x1f1e30: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1f1e30u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1f1e34: 0x10000076  b           . + 4 + (0x76 << 2)
    ctx->pc = 0x1F1E34u;
    {
        const bool branch_taken_0x1f1e34 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f1e34) {
            ctx->pc = 0x1F2010u;
            goto label_1f2010;
        }
    }
    ctx->pc = 0x1F1E3Cu;
label_1f1e3c:
    // 0x1f1e3c: 0x8fc30010  lw          $v1, 0x10($fp)
    ctx->pc = 0x1f1e3cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1f1e40: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1f1e40u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1f1e44: 0x9442005c  lhu         $v0, 0x5C($v0)
    ctx->pc = 0x1f1e44u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 92)));
    // 0x1f1e48: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1f1e48u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1f1e4c: 0xa462005c  sh          $v0, 0x5C($v1)
    ctx->pc = 0x1f1e4cu;
    WRITE16(ADD32(GPR_U32(ctx, 3), 92), (uint16_t)GPR_U32(ctx, 2));
    // 0x1f1e50: 0x1000ffe2  b           . + 4 + (-0x1E << 2)
    ctx->pc = 0x1F1E50u;
    {
        const bool branch_taken_0x1f1e50 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f1e50) {
            ctx->pc = 0x1F1DDCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1f1ddc;
        }
    }
    ctx->pc = 0x1F1E58u;
label_1f1e58:
    // 0x1f1e58: 0x8fc30010  lw          $v1, 0x10($fp)
    ctx->pc = 0x1f1e58u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1f1e5c: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1f1e5cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1f1e60: 0x9442005c  lhu         $v0, 0x5C($v0)
    ctx->pc = 0x1f1e60u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 92)));
    // 0x1f1e64: 0xa4620060  sh          $v0, 0x60($v1)
    ctx->pc = 0x1f1e64u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 96), (uint16_t)GPR_U32(ctx, 2));
    // 0x1f1e68: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1f1e68u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1f1e6c: 0x24420014  addiu       $v0, $v0, 0x14
    ctx->pc = 0x1f1e6cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 20));
    // 0x1f1e70: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1f1e70u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f1e74: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1f1e74u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f1e78: 0xc07c417  jal         func_1F105C
    ctx->pc = 0x1F1E78u;
    SET_GPR_U32(ctx, 31, 0x1F1E80u);
    ctx->pc = 0x1F105Cu;
    if (runtime->hasFunction(0x1F105Cu)) {
        auto targetFn = runtime->lookupFunction(0x1F105Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F1E80u; }
        if (ctx->pc != 0x1F1E80u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F105C_0x1f105c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F1E80u; }
        if (ctx->pc != 0x1F1E80u) { return; }
    }
    ctx->pc = 0x1F1E80u;
label_1f1e80:
    // 0x1f1e80: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1f1e80u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1f1e84: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1f1e84u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1f1e88: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1F1E88u;
    {
        const bool branch_taken_0x1f1e88 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f1e88) {
            ctx->pc = 0x1F1E9Cu;
            goto label_1f1e9c;
        }
    }
    ctx->pc = 0x1F1E90u;
    // 0x1f1e90: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1f1e90u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1f1e94: 0x1000005e  b           . + 4 + (0x5E << 2)
    ctx->pc = 0x1F1E94u;
    {
        const bool branch_taken_0x1f1e94 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f1e94) {
            ctx->pc = 0x1F2010u;
            goto label_1f2010;
        }
    }
    ctx->pc = 0x1F1E9Cu;
label_1f1e9c:
    // 0x1f1e9c: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1f1e9cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1f1ea0: 0xa4400062  sh          $zero, 0x62($v0)
    ctx->pc = 0x1f1ea0u;
    WRITE16(ADD32(GPR_U32(ctx, 2), 98), (uint16_t)GPR_U32(ctx, 0));
label_1f1ea4:
    // 0x1f1ea4: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1f1ea4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1f1ea8: 0x94430062  lhu         $v1, 0x62($v0)
    ctx->pc = 0x1f1ea8u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 98)));
    // 0x1f1eac: 0x97c20006  lhu         $v0, 0x6($fp)
    ctx->pc = 0x1f1eacu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 6)));
    // 0x1f1eb0: 0x62102b  sltu        $v0, $v1, $v0
    ctx->pc = 0x1f1eb0u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x1f1eb4: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F1EB4u;
    {
        const bool branch_taken_0x1f1eb4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1f1eb4) {
            ctx->pc = 0x1F1EC4u;
            goto label_1f1ec4;
        }
    }
    ctx->pc = 0x1F1EBCu;
    // 0x1f1ebc: 0x10000019  b           . + 4 + (0x19 << 2)
    ctx->pc = 0x1F1EBCu;
    {
        const bool branch_taken_0x1f1ebc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f1ebc) {
            ctx->pc = 0x1F1F24u;
            goto label_1f1f24;
        }
    }
    ctx->pc = 0x1F1EC4u;
label_1f1ec4:
    // 0x1f1ec4: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1f1ec4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1f1ec8: 0x24430014  addiu       $v1, $v0, 0x14
    ctx->pc = 0x1f1ec8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 20));
    // 0x1f1ecc: 0x27c50014  addiu       $a1, $fp, 0x14
    ctx->pc = 0x1f1eccu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 30), 20));
    // 0x1f1ed0: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1f1ed0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1f1ed4: 0x94420064  lhu         $v0, 0x64($v0)
    ctx->pc = 0x1f1ed4u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 100)));
    // 0x1f1ed8: 0x60202d  daddu       $a0, $v1, $zero
    ctx->pc = 0x1f1ed8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f1edc: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x1f1edcu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f1ee0: 0x24070001  addiu       $a3, $zero, 0x1
    ctx->pc = 0x1f1ee0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1f1ee4: 0xc07c644  jal         func_1F1910
    ctx->pc = 0x1F1EE4u;
    SET_GPR_U32(ctx, 31, 0x1F1EECu);
    ctx->pc = 0x1F1910u;
    if (runtime->hasFunction(0x1F1910u)) {
        auto targetFn = runtime->lookupFunction(0x1F1910u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F1EECu; }
        if (ctx->pc != 0x1F1EECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1910_0x1f1910(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F1EECu; }
        if (ctx->pc != 0x1F1EECu) { return; }
    }
    ctx->pc = 0x1F1EECu;
label_1f1eec:
    // 0x1f1eec: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1f1eecu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1f1ef0: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1f1ef0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1f1ef4: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1F1EF4u;
    {
        const bool branch_taken_0x1f1ef4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f1ef4) {
            ctx->pc = 0x1F1F08u;
            goto label_1f1f08;
        }
    }
    ctx->pc = 0x1F1EFCu;
    // 0x1f1efc: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1f1efcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1f1f00: 0x10000043  b           . + 4 + (0x43 << 2)
    ctx->pc = 0x1F1F00u;
    {
        const bool branch_taken_0x1f1f00 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f1f00) {
            ctx->pc = 0x1F2010u;
            goto label_1f2010;
        }
    }
    ctx->pc = 0x1F1F08u;
label_1f1f08:
    // 0x1f1f08: 0x8fc30010  lw          $v1, 0x10($fp)
    ctx->pc = 0x1f1f08u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1f1f0c: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1f1f0cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1f1f10: 0x94420062  lhu         $v0, 0x62($v0)
    ctx->pc = 0x1f1f10u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 98)));
    // 0x1f1f14: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1f1f14u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1f1f18: 0xa4620062  sh          $v0, 0x62($v1)
    ctx->pc = 0x1f1f18u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 98), (uint16_t)GPR_U32(ctx, 2));
    // 0x1f1f1c: 0x1000ffe1  b           . + 4 + (-0x1F << 2)
    ctx->pc = 0x1F1F1Cu;
    {
        const bool branch_taken_0x1f1f1c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f1f1c) {
            ctx->pc = 0x1F1EA4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1f1ea4;
        }
    }
    ctx->pc = 0x1F1F24u;
label_1f1f24:
    // 0x1f1f24: 0x8fc30010  lw          $v1, 0x10($fp)
    ctx->pc = 0x1f1f24u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1f1f28: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1f1f28u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1f1f2c: 0x94420062  lhu         $v0, 0x62($v0)
    ctx->pc = 0x1f1f2cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 98)));
    // 0x1f1f30: 0xa4620066  sh          $v0, 0x66($v1)
    ctx->pc = 0x1f1f30u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 102), (uint16_t)GPR_U32(ctx, 2));
    // 0x1f1f34: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1f1f34u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1f1f38: 0x24420028  addiu       $v0, $v0, 0x28
    ctx->pc = 0x1f1f38u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 40));
    // 0x1f1f3c: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1f1f3cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f1f40: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1f1f40u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f1f44: 0xc07c417  jal         func_1F105C
    ctx->pc = 0x1F1F44u;
    SET_GPR_U32(ctx, 31, 0x1F1F4Cu);
    ctx->pc = 0x1F105Cu;
    if (runtime->hasFunction(0x1F105Cu)) {
        auto targetFn = runtime->lookupFunction(0x1F105Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F1F4Cu; }
        if (ctx->pc != 0x1F1F4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F105C_0x1f105c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F1F4Cu; }
        if (ctx->pc != 0x1F1F4Cu) { return; }
    }
    ctx->pc = 0x1F1F4Cu;
label_1f1f4c:
    // 0x1f1f4c: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1f1f4cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1f1f50: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1f1f50u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1f1f54: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1F1F54u;
    {
        const bool branch_taken_0x1f1f54 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f1f54) {
            ctx->pc = 0x1F1F68u;
            goto label_1f1f68;
        }
    }
    ctx->pc = 0x1F1F5Cu;
    // 0x1f1f5c: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1f1f5cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1f1f60: 0x1000002b  b           . + 4 + (0x2B << 2)
    ctx->pc = 0x1F1F60u;
    {
        const bool branch_taken_0x1f1f60 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f1f60) {
            ctx->pc = 0x1F2010u;
            goto label_1f2010;
        }
    }
    ctx->pc = 0x1F1F68u;
label_1f1f68:
    // 0x1f1f68: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1f1f68u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1f1f6c: 0xa4400068  sh          $zero, 0x68($v0)
    ctx->pc = 0x1f1f6cu;
    WRITE16(ADD32(GPR_U32(ctx, 2), 104), (uint16_t)GPR_U32(ctx, 0));
label_1f1f70:
    // 0x1f1f70: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1f1f70u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1f1f74: 0x94430068  lhu         $v1, 0x68($v0)
    ctx->pc = 0x1f1f74u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 104)));
    // 0x1f1f78: 0x97c20008  lhu         $v0, 0x8($fp)
    ctx->pc = 0x1f1f78u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1f1f7c: 0x62102b  sltu        $v0, $v1, $v0
    ctx->pc = 0x1f1f7cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x1f1f80: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F1F80u;
    {
        const bool branch_taken_0x1f1f80 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1f1f80) {
            ctx->pc = 0x1F1F90u;
            goto label_1f1f90;
        }
    }
    ctx->pc = 0x1F1F88u;
    // 0x1f1f88: 0x10000019  b           . + 4 + (0x19 << 2)
    ctx->pc = 0x1F1F88u;
    {
        const bool branch_taken_0x1f1f88 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f1f88) {
            ctx->pc = 0x1F1FF0u;
            goto label_1f1ff0;
        }
    }
    ctx->pc = 0x1F1F90u;
label_1f1f90:
    // 0x1f1f90: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1f1f90u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1f1f94: 0x24430028  addiu       $v1, $v0, 0x28
    ctx->pc = 0x1f1f94u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 40));
    // 0x1f1f98: 0x27c50014  addiu       $a1, $fp, 0x14
    ctx->pc = 0x1f1f98u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 30), 20));
    // 0x1f1f9c: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1f1f9cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1f1fa0: 0x9442006a  lhu         $v0, 0x6A($v0)
    ctx->pc = 0x1f1fa0u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 106)));
    // 0x1f1fa4: 0x60202d  daddu       $a0, $v1, $zero
    ctx->pc = 0x1f1fa4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f1fa8: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x1f1fa8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f1fac: 0x24070002  addiu       $a3, $zero, 0x2
    ctx->pc = 0x1f1facu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1f1fb0: 0xc07c644  jal         func_1F1910
    ctx->pc = 0x1F1FB0u;
    SET_GPR_U32(ctx, 31, 0x1F1FB8u);
    ctx->pc = 0x1F1910u;
    if (runtime->hasFunction(0x1F1910u)) {
        auto targetFn = runtime->lookupFunction(0x1F1910u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F1FB8u; }
        if (ctx->pc != 0x1F1FB8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1910_0x1f1910(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F1FB8u; }
        if (ctx->pc != 0x1F1FB8u) { return; }
    }
    ctx->pc = 0x1F1FB8u;
label_1f1fb8:
    // 0x1f1fb8: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1f1fb8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1f1fbc: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1f1fbcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1f1fc0: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1F1FC0u;
    {
        const bool branch_taken_0x1f1fc0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f1fc0) {
            ctx->pc = 0x1F1FD4u;
            goto label_1f1fd4;
        }
    }
    ctx->pc = 0x1F1FC8u;
    // 0x1f1fc8: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1f1fc8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1f1fcc: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x1F1FCCu;
    {
        const bool branch_taken_0x1f1fcc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f1fcc) {
            ctx->pc = 0x1F2010u;
            goto label_1f2010;
        }
    }
    ctx->pc = 0x1F1FD4u;
label_1f1fd4:
    // 0x1f1fd4: 0x8fc30010  lw          $v1, 0x10($fp)
    ctx->pc = 0x1f1fd4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1f1fd8: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1f1fd8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1f1fdc: 0x94420068  lhu         $v0, 0x68($v0)
    ctx->pc = 0x1f1fdcu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 104)));
    // 0x1f1fe0: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1f1fe0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1f1fe4: 0xa4620068  sh          $v0, 0x68($v1)
    ctx->pc = 0x1f1fe4u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 104), (uint16_t)GPR_U32(ctx, 2));
    // 0x1f1fe8: 0x1000ffe1  b           . + 4 + (-0x1F << 2)
    ctx->pc = 0x1F1FE8u;
    {
        const bool branch_taken_0x1f1fe8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f1fe8) {
            ctx->pc = 0x1F1F70u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1f1f70;
        }
    }
    ctx->pc = 0x1F1FF0u;
label_1f1ff0:
    // 0x1f1ff0: 0x8fc30010  lw          $v1, 0x10($fp)
    ctx->pc = 0x1f1ff0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1f1ff4: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1f1ff4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1f1ff8: 0x94420068  lhu         $v0, 0x68($v0)
    ctx->pc = 0x1f1ff8u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 104)));
    // 0x1f1ffc: 0xa462006c  sh          $v0, 0x6C($v1)
    ctx->pc = 0x1f1ffcu;
    WRITE16(ADD32(GPR_U32(ctx, 3), 108), (uint16_t)GPR_U32(ctx, 2));
    // 0x1f2000: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1f2000u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f2004: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1f2004u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1f2008: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1f2008u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1f200c: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1f200cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
label_1f2010:
    // 0x1f2010: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1f2010u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f2014: 0xdfbe0030  ld          $fp, 0x30($sp)
    ctx->pc = 0x1f2014u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1f2018: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x1f2018u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x1f201c: 0x27bd0040  addiu       $sp, $sp, 0x40
    ctx->pc = 0x1f201cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x1f2020: 0x3e00008  jr          $ra
    ctx->pc = 0x1F2020u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F1D38u: goto label_1f1d38;
            case 0x1F1D54u: goto label_1f1d54;
            case 0x1F1DA8u: goto label_1f1da8;
            case 0x1F1DB8u: goto label_1f1db8;
            case 0x1F1DD4u: goto label_1f1dd4;
            case 0x1F1DDCu: goto label_1f1ddc;
            case 0x1F1DFCu: goto label_1f1dfc;
            case 0x1F1E20u: goto label_1f1e20;
            case 0x1F1E3Cu: goto label_1f1e3c;
            case 0x1F1E58u: goto label_1f1e58;
            case 0x1F1E80u: goto label_1f1e80;
            case 0x1F1E9Cu: goto label_1f1e9c;
            case 0x1F1EA4u: goto label_1f1ea4;
            case 0x1F1EC4u: goto label_1f1ec4;
            case 0x1F1EECu: goto label_1f1eec;
            case 0x1F1F08u: goto label_1f1f08;
            case 0x1F1F24u: goto label_1f1f24;
            case 0x1F1F4Cu: goto label_1f1f4c;
            case 0x1F1F68u: goto label_1f1f68;
            case 0x1F1F70u: goto label_1f1f70;
            case 0x1F1F90u: goto label_1f1f90;
            case 0x1F1FB8u: goto label_1f1fb8;
            case 0x1F1FD4u: goto label_1f1fd4;
            case 0x1F1FF0u: goto label_1f1ff0;
            case 0x1F2010u: goto label_1f2010;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F2028u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
