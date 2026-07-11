#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_0019CE40
// Address: 0x19ce40 - 0x19d040
void sub_0019CE40_0x19ce40(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x19ce40u;

    // 0x19ce40: 0x27bdff60
    ctx->pc = 0x19ce40u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967136));
    // 0x19ce44: 0xffbf0090
    ctx->pc = 0x19ce44u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 31));
    // 0x19ce48: 0x7fb60080
    ctx->pc = 0x19ce48u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 128), GPR_VEC(ctx, 22));
    // 0x19ce4c: 0x7fb50070
    ctx->pc = 0x19ce4cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 112), GPR_VEC(ctx, 21));
    // 0x19ce50: 0x7fb40060
    ctx->pc = 0x19ce50u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 96), GPR_VEC(ctx, 20));
    // 0x19ce54: 0x80a82d
    ctx->pc = 0x19ce54u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19ce58: 0x7fb30050
    ctx->pc = 0x19ce58u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 19));
    // 0x19ce5c: 0x7fb20040
    ctx->pc = 0x19ce5cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 18));
    // 0x19ce60: 0x7fb10030
    ctx->pc = 0x19ce60u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 17));
    // 0x19ce64: 0x7fb00020
    ctx->pc = 0x19ce64u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 16));
    // 0x19ce68: 0xc063728
    ctx->pc = 0x19CE68u;
    SET_GPR_U32(ctx, 31, 0x19CE70u);
    ctx->pc = 0x19CE6Cu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 4), 36)));
    ctx->pc = 0x18DCA0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DCA0_0x18dca0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19CE70u; }
    }
    if (ctx->pc != 0x19CE70u) { return; }
    ctx->pc = 0x19CE70u;
    // 0x19ce70: 0x86b2001a
    ctx->pc = 0x19ce70u;
    SET_GPR_S32(ctx, 18, (int16_t)READ16(ADD32(GPR_U32(ctx, 21), 26)));
    // 0x19ce74: 0x40a02d
    ctx->pc = 0x19ce74u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19ce78: 0x86b1001c
    ctx->pc = 0x19ce78u;
    SET_GPR_S32(ctx, 17, (int16_t)READ16(ADD32(GPR_U32(ctx, 21), 28)));
    // 0x19ce7c: 0x10000060
    ctx->pc = 0x19CE7Cu;
    {
        const bool branch_taken_0x19ce7c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x19CE80u;
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x19ce7c) {
            ctx->pc = 0x19D000u;
            goto label_19d000;
        }
    }
    ctx->pc = 0x19CE84u;
label_19ce84:
    // 0x19ce84: 0x8ea30020
    ctx->pc = 0x19ce84u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 21), 32)));
    // 0x19ce88: 0x10600017
    ctx->pc = 0x19CE88u;
    {
        const bool branch_taken_0x19ce88 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 0));
        ctx->pc = 0x19CE8Cu;
        { int64_t result = (int64_t)GPR_S32(ctx, 18) * (int64_t)GPR_S32(ctx, 17); ctx->lo = (uint32_t)result; ctx->hi = (uint32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)(uint32_t)result); }
        if (branch_taken_0x19ce88) {
            ctx->pc = 0x19CEE8u;
            goto label_19cee8;
        }
    }
    ctx->pc = 0x19CE90u;
    // 0x19ce90: 0x24020001
    ctx->pc = 0x19ce90u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
    // 0x19ce94: 0x10620012
    ctx->pc = 0x19CE94u;
    {
        const bool branch_taken_0x19ce94 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 2));
        ctx->pc = 0x19CE98u;
        { int64_t result = (int64_t)GPR_S32(ctx, 18) * (int64_t)GPR_S32(ctx, 17); ctx->lo = (uint32_t)result; ctx->hi = (uint32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)(uint32_t)result); }
        if (branch_taken_0x19ce94) {
            ctx->pc = 0x19CEE0u;
            goto label_19cee0;
        }
    }
    ctx->pc = 0x19CE9Cu;
    // 0x19ce9c: 0x24020002
    ctx->pc = 0x19ce9cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 2));
    // 0x19cea0: 0x1062000d
    ctx->pc = 0x19CEA0u;
    {
        const bool branch_taken_0x19cea0 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 2));
        ctx->pc = 0x19CEA4u;
        { int64_t result = (int64_t)GPR_S32(ctx, 18) * (int64_t)GPR_S32(ctx, 17); ctx->lo = (uint32_t)result; ctx->hi = (uint32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)(uint32_t)result); }
        if (branch_taken_0x19cea0) {
            ctx->pc = 0x19CED8u;
            goto label_19ced8;
        }
    }
    ctx->pc = 0x19CEA8u;
    // 0x19cea8: 0x24020013
    ctx->pc = 0x19cea8u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 19));
    // 0x19ceac: 0x10620008
    ctx->pc = 0x19CEACu;
    {
        const bool branch_taken_0x19ceac = (GPR_U32(ctx, 3) == GPR_U32(ctx, 2));
        ctx->pc = 0x19CEB0u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 20));
        if (branch_taken_0x19ceac) {
            ctx->pc = 0x19CED0u;
            goto label_19ced0;
        }
    }
    ctx->pc = 0x19CEB4u;
    // 0x19ceb4: 0x10620003
    ctx->pc = 0x19CEB4u;
    {
        const bool branch_taken_0x19ceb4 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 2));
        if (branch_taken_0x19ceb4) {
            ctx->pc = 0x19CEC4u;
            goto label_19cec4;
        }
    }
    ctx->pc = 0x19CEBCu;
    // 0x19cebc: 0x1000000c
    ctx->pc = 0x19CEBCu;
    {
        const bool branch_taken_0x19cebc = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x19CEC0u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x19cebc) {
            ctx->pc = 0x19CEF0u;
            goto label_19cef0;
        }
    }
    ctx->pc = 0x19CEC4u;
label_19cec4:
    // 0x19cec4: 0x2511018
    ctx->pc = 0x19cec4u;
    { int64_t result = (int64_t)GPR_S32(ctx, 18) * (int64_t)GPR_S32(ctx, 17); ctx->lo = (uint32_t)result; ctx->hi = (uint32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)(uint32_t)result); }
    // 0x19cec8: 0x10000008
    ctx->pc = 0x19CEC8u;
    {
        const bool branch_taken_0x19cec8 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x19CECCu;
        SET_GPR_S32(ctx, 16, SRA32(GPR_S32(ctx, 2), 1));
        if (branch_taken_0x19cec8) {
            ctx->pc = 0x19CEECu;
            goto label_19ceec;
        }
    }
    ctx->pc = 0x19CED0u;
label_19ced0:
    // 0x19ced0: 0x10000006
    ctx->pc = 0x19CED0u;
    {
        const bool branch_taken_0x19ced0 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x19CED4u;
        { int64_t result = (int64_t)GPR_S32(ctx, 18) * (int64_t)GPR_S32(ctx, 17); ctx->lo = (uint32_t)result; ctx->hi = (uint32_t)(result >> 32); SET_GPR_S32(ctx, 16, (int32_t)(uint32_t)result); }
        if (branch_taken_0x19ced0) {
            ctx->pc = 0x19CEECu;
            goto label_19ceec;
        }
    }
    ctx->pc = 0x19CED8u;
label_19ced8:
    // 0x19ced8: 0x10000004
    ctx->pc = 0x19CED8u;
    {
        const bool branch_taken_0x19ced8 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x19CEDCu;
        SET_GPR_U32(ctx, 16, SLL32(GPR_U32(ctx, 2), 1));
        if (branch_taken_0x19ced8) {
            ctx->pc = 0x19CEECu;
            goto label_19ceec;
        }
    }
    ctx->pc = 0x19CEE0u;
label_19cee0:
    // 0x19cee0: 0x10000002
    ctx->pc = 0x19CEE0u;
    {
        const bool branch_taken_0x19cee0 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x19CEE4u;
        SET_GPR_U32(ctx, 16, SLL32(GPR_U32(ctx, 2), 2));
        if (branch_taken_0x19cee0) {
            ctx->pc = 0x19CEECu;
            goto label_19ceec;
        }
    }
    ctx->pc = 0x19CEE8u;
label_19cee8:
    // 0x19cee8: 0x28080
    ctx->pc = 0x19cee8u;
    SET_GPR_U32(ctx, 16, SLL32(GPR_U32(ctx, 2), 2));
label_19ceec:
    // 0x19ceec: 0x200202d
    ctx->pc = 0x19ceecu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_19cef0:
    // 0x19cef0: 0xc06321c
    ctx->pc = 0x19CEF0u;
    SET_GPR_U32(ctx, 31, 0x19CEF8u);
    ctx->pc = 0x18C870u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018C870_0x18c870(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19CEF8u; }
    }
    if (ctx->pc != 0x19CEF8u) { return; }
    ctx->pc = 0x19CEF8u;
    // 0x19cef8: 0x40202d
    ctx->pc = 0x19cef8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19cefc: 0xc063774
    ctx->pc = 0x19CEFCu;
    SET_GPR_U32(ctx, 31, 0x19CF04u);
    ctx->pc = 0x19CF00u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 16));
    ctx->pc = 0x18DDD0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19CF04u; }
    }
    if (ctx->pc != 0x19CF04u) { return; }
    ctx->pc = 0x19CF04u;
    // 0x19cf04: 0x40b02d
    ctx->pc = 0x19cf04u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19cf08: 0x2a0202d
    ctx->pc = 0x19cf08u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19cf0c: 0xc067410
    ctx->pc = 0x19CF0Cu;
    SET_GPR_U32(ctx, 31, 0x19CF14u);
    ctx->pc = 0x19CF10u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x19D040u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0019D040_0x19d040(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19CF14u; }
    }
    if (ctx->pc != 0x19CF14u) { return; }
    ctx->pc = 0x19CF14u;
    // 0x19cf14: 0x82a30036
    ctx->pc = 0x19cf14u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 21), 54)));
    // 0x19cf18: 0x14600018
    ctx->pc = 0x19CF18u;
    {
        const bool branch_taken_0x19cf18 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 0));
        ctx->pc = 0x19CF1Cu;
        SET_GPR_U64(ctx, 8, GPR_U64(ctx, 2) << (32 + 16));
        if (branch_taken_0x19cf18) {
            ctx->pc = 0x19CF7Cu;
            goto label_19cf7c;
        }
    }
    ctx->pc = 0x19CF20u;
    // 0x19cf20: 0x111c3c
    ctx->pc = 0x19cf20u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 17) << (32 + 16));
    // 0x19cf24: 0x12143c
    ctx->pc = 0x19cf24u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 18) << (32 + 16));
    // 0x19cf28: 0xffa00000
    ctx->pc = 0x19cf28u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 0));
    // 0x19cf2c: 0x2143f
    ctx->pc = 0x19cf2cu;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x19cf30: 0x31c3f
    ctx->pc = 0x19cf30u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 16));
    // 0x19cf34: 0xffa20008
    ctx->pc = 0x19cf34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 2));
    // 0x19cf38: 0x8443f
    ctx->pc = 0x19cf38u;
    SET_GPR_S64(ctx, 8, GPR_S64(ctx, 8) >> (32 + 16));
    // 0x19cf3c: 0x121183
    ctx->pc = 0x19cf3cu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 18), 6));
    // 0x19cf40: 0x6410003
    ctx->pc = 0x19CF40u;
    {
        const bool branch_taken_0x19cf40 = (GPR_S32(ctx, 18) >= 0);
        ctx->pc = 0x19CF44u;
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 3));
        if (branch_taken_0x19cf40) {
            ctx->pc = 0x19CF50u;
            goto label_19cf50;
        }
    }
    ctx->pc = 0x19CF48u;
    // 0x19cf48: 0x2642003f
    ctx->pc = 0x19cf48u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 18), 63));
    // 0x19cf4c: 0x21183
    ctx->pc = 0x19cf4cu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 6));
label_19cf50:
    // 0x19cf50: 0x86aa0020
    ctx->pc = 0x19cf50u;
    SET_GPR_S32(ctx, 10, (int16_t)READ16(ADD32(GPR_U32(ctx, 21), 32)));
    // 0x19cf54: 0x24c3c
    ctx->pc = 0x19cf54u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 2) << (32 + 16));
    // 0x19cf58: 0x94c3f
    ctx->pc = 0x19cf58u;
    SET_GPR_S64(ctx, 9, GPR_S64(ctx, 9) >> (32 + 16));
    // 0x19cf5c: 0x2c0202d
    ctx->pc = 0x19cf5cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19cf60: 0x24050001
    ctx->pc = 0x19cf60u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 1));
    // 0x19cf64: 0x280302d
    ctx->pc = 0x19cf64u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19cf68: 0x200382d
    ctx->pc = 0x19cf68u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19cf6c: 0xc063230
    ctx->pc = 0x19CF6Cu;
    SET_GPR_U32(ctx, 31, 0x19CF74u);
    ctx->pc = 0x19CF70u;
    SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x18C8C0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018C8C0_0x18c8c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19CF74u; }
    }
    if (ctx->pc != 0x19CF74u) { return; }
    ctx->pc = 0x19CF74u;
    // 0x19cf74: 0x10000016
    ctx->pc = 0x19CF74u;
    {
        const bool branch_taken_0x19cf74 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x19CF78u;
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 22) << (32 + 4));
        if (branch_taken_0x19cf74) {
            ctx->pc = 0x19CFD0u;
            goto label_19cfd0;
        }
    }
    ctx->pc = 0x19CF7Cu;
label_19cf7c:
    // 0x19cf7c: 0x86a40028
    ctx->pc = 0x19cf7cu;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 21), 40)));
    // 0x19cf80: 0x2443c
    ctx->pc = 0x19cf80u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 2) << (32 + 16));
    // 0x19cf84: 0x8443f
    ctx->pc = 0x19cf84u;
    SET_GPR_S64(ctx, 8, GPR_S64(ctx, 8) >> (32 + 16));
    // 0x19cf88: 0xffa00000
    ctx->pc = 0x19cf88u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 0));
    // 0x19cf8c: 0x41183
    ctx->pc = 0x19cf8cu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 4), 6));
    // 0x19cf90: 0xffa40008
    ctx->pc = 0x19cf90u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 4));
    // 0x19cf94: 0x86a3002a
    ctx->pc = 0x19cf94u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 21), 42)));
    // 0x19cf98: 0x4810003
    ctx->pc = 0x19CF98u;
    {
        const bool branch_taken_0x19cf98 = (GPR_S32(ctx, 4) >= 0);
        ctx->pc = 0x19CF9Cu;
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 3));
        if (branch_taken_0x19cf98) {
            ctx->pc = 0x19CFA8u;
            goto label_19cfa8;
        }
    }
    ctx->pc = 0x19CFA0u;
    // 0x19cfa0: 0x2482003f
    ctx->pc = 0x19cfa0u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 4), 63));
    // 0x19cfa4: 0x21183
    ctx->pc = 0x19cfa4u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 6));
label_19cfa8:
    // 0x19cfa8: 0x24c3c
    ctx->pc = 0x19cfa8u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 2) << (32 + 16));
    // 0x19cfac: 0x2c0202d
    ctx->pc = 0x19cfacu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19cfb0: 0x94c3f
    ctx->pc = 0x19cfb0u;
    SET_GPR_S64(ctx, 9, GPR_S64(ctx, 9) >> (32 + 16));
    // 0x19cfb4: 0x24050001
    ctx->pc = 0x19cfb4u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 1));
    // 0x19cfb8: 0x280302d
    ctx->pc = 0x19cfb8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19cfbc: 0x200382d
    ctx->pc = 0x19cfbcu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19cfc0: 0x502d
    ctx->pc = 0x19cfc0u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19cfc4: 0xc063230
    ctx->pc = 0x19CFC4u;
    SET_GPR_U32(ctx, 31, 0x19CFCCu);
    ctx->pc = 0x19CFC8u;
    SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x18C8C0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018C8C0_0x18c8c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19CFCCu; }
    }
    if (ctx->pc != 0x19CFCCu) { return; }
    ctx->pc = 0x19CFCCu;
    // 0x19cfcc: 0x16213c
    ctx->pc = 0x19cfccu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 22) << (32 + 4));
label_19cfd0:
    // 0x19cfd0: 0x3c07002a
    ctx->pc = 0x19cfd0u;
    SET_GPR_U32(ctx, 7, ((uint32_t)42 << 16));
    // 0x19cfd4: 0x4213e
    ctx->pc = 0x19cfd4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) >> (32 + 4));
    // 0x19cfd8: 0x3c031000
    ctx->pc = 0x19cfd8u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x19cfdc: 0x832825
    ctx->pc = 0x19cfdcu;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x19cfe0: 0x40302d
    ctx->pc = 0x19cfe0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19cfe4: 0x202d
    ctx->pc = 0x19cfe4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19cfe8: 0xc0633ec
    ctx->pc = 0x19CFE8u;
    SET_GPR_U32(ctx, 31, 0x19CFF0u);
    ctx->pc = 0x19CFECu;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 7), 4294964976));
    ctx->pc = 0x18CFB0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018CFB0_0x18cfb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19CFF0u; }
    }
    if (ctx->pc != 0x19CFF0u) { return; }
    ctx->pc = 0x19CFF0u;
    // 0x19cff0: 0x129043
    ctx->pc = 0x19cff0u;
    SET_GPR_S32(ctx, 18, SRA32(GPR_S32(ctx, 18), 1));
    // 0x19cff4: 0x118843
    ctx->pc = 0x19cff4u;
    SET_GPR_S32(ctx, 17, SRA32(GPR_S32(ctx, 17), 1));
    // 0x19cff8: 0x290a021
    ctx->pc = 0x19cff8u;
    SET_GPR_U32(ctx, 20, ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 16)));
    // 0x19cffc: 0x26730001
    ctx->pc = 0x19cffcu;
    SET_GPR_S32(ctx, 19, ADD32(GPR_U32(ctx, 19), 1));
label_19d000:
    // 0x19d000: 0x8ea30030
    ctx->pc = 0x19d000u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 21), 48)));
    // 0x19d004: 0x263182b
    ctx->pc = 0x19d004u;
    SET_GPR_U32(ctx, 3, SLTU32(GPR_U32(ctx, 19), GPR_U32(ctx, 3)));
    // 0x19d008: 0x1460ff9e
    ctx->pc = 0x19D008u;
    {
        const bool branch_taken_0x19d008 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 0));
        if (branch_taken_0x19d008) {
            ctx->pc = 0x19CE84u;
            goto label_19ce84;
        }
    }
    ctx->pc = 0x19D010u;
    // 0x19d010: 0xdfbf0090
    ctx->pc = 0x19d010u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x19d014: 0x7bb60080
    ctx->pc = 0x19d014u;
    SET_GPR_VEC(ctx, 22, READ128(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x19d018: 0x7bb50070
    ctx->pc = 0x19d018u;
    SET_GPR_VEC(ctx, 21, READ128(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x19d01c: 0x7bb40060
    ctx->pc = 0x19d01cu;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x19d020: 0x7bb30050
    ctx->pc = 0x19d020u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x19d024: 0x7bb20040
    ctx->pc = 0x19d024u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x19d028: 0x7bb10030
    ctx->pc = 0x19d028u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x19d02c: 0x7bb00020
    ctx->pc = 0x19d02cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x19d030: 0x3e00008
    ctx->pc = 0x19D030u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19D034u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 160));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x19CE84u: goto label_19ce84;
            case 0x19CEC4u: goto label_19cec4;
            case 0x19CED0u: goto label_19ced0;
            case 0x19CED8u: goto label_19ced8;
            case 0x19CEE0u: goto label_19cee0;
            case 0x19CEE8u: goto label_19cee8;
            case 0x19CEECu: goto label_19ceec;
            case 0x19CEF0u: goto label_19cef0;
            case 0x19CF50u: goto label_19cf50;
            case 0x19CF7Cu: goto label_19cf7c;
            case 0x19CFA8u: goto label_19cfa8;
            case 0x19CFD0u: goto label_19cfd0;
            case 0x19D000u: goto label_19d000;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19D038u;
    // 0x19d038: 0x0
    ctx->pc = 0x19d038u;
    // NOP
    // 0x19d03c: 0x0
    ctx->pc = 0x19d03cu;
    // NOP
}
