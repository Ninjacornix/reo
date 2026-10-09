#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E5008
// Address: 0x1e5008 - 0x1e7298
void sub_001E5008_0x1e5008(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E5008_0x1e5008");
#endif

    switch (ctx->pc) {
        case 0x1e50c4u: goto label_1e50c4;
        case 0x1e50fcu: goto label_1e50fc;
        case 0x1e5120u: goto label_1e5120;
        case 0x1e5148u: goto label_1e5148;
        case 0x1e5178u: goto label_1e5178;
        case 0x1e52b0u: goto label_1e52b0;
        case 0x1e530cu: goto label_1e530c;
        case 0x1e536cu: goto label_1e536c;
        case 0x1e5424u: goto label_1e5424;
        case 0x1e5464u: goto label_1e5464;
        case 0x1e5574u: goto label_1e5574;
        case 0x1e55c8u: goto label_1e55c8;
        case 0x1e55ecu: goto label_1e55ec;
        case 0x1e566cu: goto label_1e566c;
        case 0x1e575cu: goto label_1e575c;
        case 0x1e57a0u: goto label_1e57a0;
        case 0x1e5884u: goto label_1e5884;
        case 0x1e58c8u: goto label_1e58c8;
        case 0x1e59acu: goto label_1e59ac;
        case 0x1e59f0u: goto label_1e59f0;
        case 0x1e5ae4u: goto label_1e5ae4;
        case 0x1e5b1cu: goto label_1e5b1c;
        case 0x1e5b40u: goto label_1e5b40;
        case 0x1e5b68u: goto label_1e5b68;
        case 0x1e5b98u: goto label_1e5b98;
        case 0x1e5c90u: goto label_1e5c90;
        case 0x1e5cc8u: goto label_1e5cc8;
        case 0x1e5cecu: goto label_1e5cec;
        case 0x1e5d14u: goto label_1e5d14;
        case 0x1e5d48u: goto label_1e5d48;
        case 0x1e5d78u: goto label_1e5d78;
        case 0x1e5e68u: goto label_1e5e68;
        case 0x1e5e9cu: goto label_1e5e9c;
        case 0x1e5eb4u: goto label_1e5eb4;
        case 0x1e5f6cu: goto label_1e5f6c;
        case 0x1e5f9cu: goto label_1e5f9c;
        case 0x1e6068u: goto label_1e6068;
        case 0x1e6094u: goto label_1e6094;
        case 0x1e60ccu: goto label_1e60cc;
        case 0x1e60f0u: goto label_1e60f0;
        case 0x1e6118u: goto label_1e6118;
        case 0x1e613cu: goto label_1e613c;
        case 0x1e616cu: goto label_1e616c;
        case 0x1e623cu: goto label_1e623c;
        case 0x1e630cu: goto label_1e630c;
        case 0x1e63dcu: goto label_1e63dc;
        case 0x1e64c4u: goto label_1e64c4;
        case 0x1e64fcu: goto label_1e64fc;
        case 0x1e6520u: goto label_1e6520;
        case 0x1e6548u: goto label_1e6548;
        case 0x1e656cu: goto label_1e656c;
        case 0x1e6674u: goto label_1e6674;
        case 0x1e66acu: goto label_1e66ac;
        case 0x1e66d0u: goto label_1e66d0;
        case 0x1e66fcu: goto label_1e66fc;
        case 0x1e6718u: goto label_1e6718;
        case 0x1e6744u: goto label_1e6744;
        case 0x1e6834u: goto label_1e6834;
        case 0x1e6868u: goto label_1e6868;
        case 0x1e688cu: goto label_1e688c;
        case 0x1e68acu: goto label_1e68ac;
        case 0x1e68bcu: goto label_1e68bc;
        case 0x1e69d0u: goto label_1e69d0;
        case 0x1e69f4u: goto label_1e69f4;
        case 0x1e6a30u: goto label_1e6a30;
        case 0x1e6a4cu: goto label_1e6a4c;
        case 0x1e6af4u: goto label_1e6af4;
        case 0x1e6b24u: goto label_1e6b24;
        case 0x1e6b6cu: goto label_1e6b6c;
        case 0x1e6b88u: goto label_1e6b88;
        case 0x1e6bccu: goto label_1e6bcc;
        case 0x1e6be8u: goto label_1e6be8;
        case 0x1e6c30u: goto label_1e6c30;
        case 0x1e6c4cu: goto label_1e6c4c;
        case 0x1e6c84u: goto label_1e6c84;
        case 0x1e6cb4u: goto label_1e6cb4;
        case 0x1e6cecu: goto label_1e6cec;
        case 0x1e6dc0u: goto label_1e6dc0;
        case 0x1e6df4u: goto label_1e6df4;
        case 0x1e6e18u: goto label_1e6e18;
        case 0x1e6e38u: goto label_1e6e38;
        case 0x1e6e48u: goto label_1e6e48;
        case 0x1e6f5cu: goto label_1e6f5c;
        case 0x1e6f80u: goto label_1e6f80;
        case 0x1e6fbcu: goto label_1e6fbc;
        case 0x1e6fd8u: goto label_1e6fd8;
        case 0x1e7080u: goto label_1e7080;
        case 0x1e70b0u: goto label_1e70b0;
        case 0x1e70f8u: goto label_1e70f8;
        case 0x1e7114u: goto label_1e7114;
        case 0x1e7158u: goto label_1e7158;
        case 0x1e7174u: goto label_1e7174;
        case 0x1e71bcu: goto label_1e71bc;
        case 0x1e71d8u: goto label_1e71d8;
        case 0x1e7210u: goto label_1e7210;
        case 0x1e7240u: goto label_1e7240;
        case 0x1e7278u: goto label_1e7278;
        default: break;
    }

    ctx->pc = 0x1e5008u;

    // 0x1e5008: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1e5008u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1e500c: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1e500cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1e5010: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1e5010u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1e5014: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e5014u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e5018: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e5018u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e501c: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x1e501cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e5020: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e5020u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e5024: 0xafc7000c  sw          $a3, 0xC($fp)
    ctx->pc = 0x1e5024u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 7));
    // 0x1e5028: 0xa7c20004  sh          $v0, 0x4($fp)
    ctx->pc = 0x1e5028u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 4), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e502c: 0xafc00018  sw          $zero, 0x18($fp)
    ctx->pc = 0x1e502cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 0));
    // 0x1e5030: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e5030u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e5034: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e5034u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e5038: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E5038u;
    {
        const bool branch_taken_0x1e5038 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e5038) {
            ctx->pc = 0x1E5060u;
            goto label_1e5060;
        }
    }
    ctx->pc = 0x1E5040u;
    // 0x1e5040: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e5040u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e5044: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e5044u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e5048: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e5048u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e504c: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e504cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e5050: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e5050u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e5054: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e5054u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e5058: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E5058u;
    {
        const bool branch_taken_0x1e5058 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e5058) {
            ctx->pc = 0x1E5074u;
            goto label_1e5074;
        }
    }
    ctx->pc = 0x1E5060u;
label_1e5060:
    // 0x1e5060: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e5060u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e5064: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e5064u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e5068: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e5068u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e506c: 0x1000004a  b           . + 4 + (0x4A << 2)
    ctx->pc = 0x1E506Cu;
    {
        const bool branch_taken_0x1e506c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e506c) {
            ctx->pc = 0x1E5198u;
            goto label_1e5198;
        }
    }
    ctx->pc = 0x1E5074u;
label_1e5074:
    // 0x1e5074: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e5074u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e5078: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e5078u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e507c: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e507cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e5080: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e5080u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e5084: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e5084u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e5088: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e5088u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e508c: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1e508cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1e5090: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e5090u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e5094: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e5094u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e5098: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E5098u;
    {
        const bool branch_taken_0x1e5098 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5098) {
            ctx->pc = 0x1E50B4u;
            goto label_1e50b4;
        }
    }
    ctx->pc = 0x1E50A0u;
    // 0x1e50a0: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e50a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e50a4: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e50a4u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e50a8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e50a8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e50ac: 0x1000003a  b           . + 4 + (0x3A << 2)
    ctx->pc = 0x1E50ACu;
    {
        const bool branch_taken_0x1e50ac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e50ac) {
            ctx->pc = 0x1E5198u;
            goto label_1e5198;
        }
    }
    ctx->pc = 0x1E50B4u;
label_1e50b4:
    // 0x1e50b4: 0x8fc40018  lw          $a0, 0x18($fp)
    ctx->pc = 0x1e50b4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e50b8: 0x8fc5000c  lw          $a1, 0xC($fp)
    ctx->pc = 0x1e50b8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e50bc: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E50BCu;
    SET_GPR_U32(ctx, 31, 0x1E50C4u);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E50C4u; }
        if (ctx->pc != 0x1E50C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E50C4u; }
        if (ctx->pc != 0x1E50C4u) { return; }
    }
    ctx->pc = 0x1E50C4u;
label_1e50c4:
    // 0x1e50c4: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1e50c4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1e50c8: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e50c8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e50cc: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E50CCu;
    {
        const bool branch_taken_0x1e50cc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e50cc) {
            ctx->pc = 0x1E50E8u;
            goto label_1e50e8;
        }
    }
    ctx->pc = 0x1E50D4u;
    // 0x1e50d4: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e50d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e50d8: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e50d8u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e50dc: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e50dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e50e0: 0x1000002d  b           . + 4 + (0x2D << 2)
    ctx->pc = 0x1E50E0u;
    {
        const bool branch_taken_0x1e50e0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e50e0) {
            ctx->pc = 0x1E5198u;
            goto label_1e5198;
        }
    }
    ctx->pc = 0x1E50E8u;
label_1e50e8:
    // 0x1e50e8: 0x97c2000c  lhu         $v0, 0xC($fp)
    ctx->pc = 0x1e50e8u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e50ec: 0x8fc40010  lw          $a0, 0x10($fp)
    ctx->pc = 0x1e50ecu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e50f0: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1e50f0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e50f4: 0xc07cc3c  jal         func_1F30F0
    ctx->pc = 0x1E50F4u;
    SET_GPR_U32(ctx, 31, 0x1E50FCu);
    ctx->pc = 0x1F30F0u;
    if (runtime->hasFunction(0x1F30F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F30F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E50FCu; }
        if (ctx->pc != 0x1E50FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F30F0_0x1f30f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E50FCu; }
        if (ctx->pc != 0x1E50FCu) { return; }
    }
    ctx->pc = 0x1E50FCu;
label_1e50fc:
    // 0x1e50fc: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1e50fcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1e5100: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e5100u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e5104: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1E5104u;
    {
        const bool branch_taken_0x1e5104 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e5104) {
            ctx->pc = 0x1E5134u;
            goto label_1e5134;
        }
    }
    ctx->pc = 0x1E510Cu;
    // 0x1e510c: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e510cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e5110: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1e5110u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1e5114: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e5114u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e5118: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1E5118u;
    SET_GPR_U32(ctx, 31, 0x1E5120u);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5120u; }
        if (ctx->pc != 0x1E5120u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5120u; }
        if (ctx->pc != 0x1E5120u) { return; }
    }
    ctx->pc = 0x1E5120u;
label_1e5120:
    // 0x1e5120: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e5120u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e5124: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e5124u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e5128: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e5128u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e512c: 0x1000001a  b           . + 4 + (0x1A << 2)
    ctx->pc = 0x1E512Cu;
    {
        const bool branch_taken_0x1e512c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e512c) {
            ctx->pc = 0x1E5198u;
            goto label_1e5198;
        }
    }
    ctx->pc = 0x1E5134u;
label_1e5134:
    // 0x1e5134: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e5134u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e5138: 0x8fc50008  lw          $a1, 0x8($fp)
    ctx->pc = 0x1e5138u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e513c: 0x8fc6000c  lw          $a2, 0xC($fp)
    ctx->pc = 0x1e513cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e5140: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1E5140u;
    SET_GPR_U32(ctx, 31, 0x1E5148u);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5148u; }
        if (ctx->pc != 0x1E5148u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5148u; }
        if (ctx->pc != 0x1E5148u) { return; }
    }
    ctx->pc = 0x1E5148u;
label_1e5148:
    // 0x1e5148: 0x97c20004  lhu         $v0, 0x4($fp)
    ctx->pc = 0x1e5148u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e514c: 0x34422000  ori         $v0, $v0, 0x2000
    ctx->pc = 0x1e514cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)8192);
    // 0x1e5150: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1e5150u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1e5154: 0x97c3000c  lhu         $v1, 0xC($fp)
    ctx->pc = 0x1e5154u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e5158: 0x8fc40018  lw          $a0, 0x18($fp)
    ctx->pc = 0x1e5158u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e515c: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e515cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e5160: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x1e5160u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e5164: 0x60382d  daddu       $a3, $v1, $zero
    ctx->pc = 0x1e5164u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e5168: 0x2408000f  addiu       $t0, $zero, 0xF
    ctx->pc = 0x1e5168u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
    // 0x1e516c: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1e516cu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e5170: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E5170u;
    SET_GPR_U32(ctx, 31, 0x1E5178u);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5178u; }
        if (ctx->pc != 0x1E5178u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5178u; }
        if (ctx->pc != 0x1E5178u) { return; }
    }
    ctx->pc = 0x1E5178u;
label_1e5178:
    // 0x1e5178: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E5178u;
    {
        const bool branch_taken_0x1e5178 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5178) {
            ctx->pc = 0x1E5194u;
            goto label_1e5194;
        }
    }
    ctx->pc = 0x1E5180u;
    // 0x1e5180: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e5180u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e5184: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e5184u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e5188: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e5188u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e518c: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1E518Cu;
    {
        const bool branch_taken_0x1e518c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e518c) {
            ctx->pc = 0x1E5198u;
            goto label_1e5198;
        }
    }
    ctx->pc = 0x1E5194u;
label_1e5194:
    // 0x1e5194: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1e5194u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1e5198:
    // 0x1e5198: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e5198u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e519c: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1e519cu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1e51a0: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1e51a0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1e51a4: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1e51a4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1e51a8: 0x3e00008  jr          $ra
    ctx->pc = 0x1E51A8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E5060u: goto label_1e5060;
            case 0x1E5074u: goto label_1e5074;
            case 0x1E50B4u: goto label_1e50b4;
            case 0x1E50C4u: goto label_1e50c4;
            case 0x1E50E8u: goto label_1e50e8;
            case 0x1E50FCu: goto label_1e50fc;
            case 0x1E5120u: goto label_1e5120;
            case 0x1E5134u: goto label_1e5134;
            case 0x1E5148u: goto label_1e5148;
            case 0x1E5178u: goto label_1e5178;
            case 0x1E5194u: goto label_1e5194;
            case 0x1E5198u: goto label_1e5198;
            case 0x1E5238u: goto label_1e5238;
            case 0x1E524Cu: goto label_1e524c;
            case 0x1E528Cu: goto label_1e528c;
            case 0x1E52B0u: goto label_1e52b0;
            case 0x1E52D4u: goto label_1e52d4;
            case 0x1E530Cu: goto label_1e530c;
            case 0x1E536Cu: goto label_1e536c;
            case 0x1E5388u: goto label_1e5388;
            case 0x1E5410u: goto label_1e5410;
            case 0x1E5424u: goto label_1e5424;
            case 0x1E5464u: goto label_1e5464;
            case 0x1E5480u: goto label_1e5480;
            case 0x1E5484u: goto label_1e5484;
            case 0x1E54F8u: goto label_1e54f8;
            case 0x1E550Cu: goto label_1e550c;
            case 0x1E554Cu: goto label_1e554c;
            case 0x1E5574u: goto label_1e5574;
            case 0x1E5598u: goto label_1e5598;
            case 0x1E55C8u: goto label_1e55c8;
            case 0x1E55ECu: goto label_1e55ec;
            case 0x1E5600u: goto label_1e5600;
            case 0x1E566Cu: goto label_1e566c;
            case 0x1E568Cu: goto label_1e568c;
            case 0x1E5748u: goto label_1e5748;
            case 0x1E575Cu: goto label_1e575c;
            case 0x1E57A0u: goto label_1e57a0;
            case 0x1E57BCu: goto label_1e57bc;
            case 0x1E57C0u: goto label_1e57c0;
            case 0x1E5820u: goto label_1e5820;
            case 0x1E5834u: goto label_1e5834;
            case 0x1E5874u: goto label_1e5874;
            case 0x1E5884u: goto label_1e5884;
            case 0x1E58A8u: goto label_1e58a8;
            case 0x1E58C8u: goto label_1e58c8;
            case 0x1E58E4u: goto label_1e58e4;
            case 0x1E58E8u: goto label_1e58e8;
            case 0x1E5948u: goto label_1e5948;
            case 0x1E595Cu: goto label_1e595c;
            case 0x1E599Cu: goto label_1e599c;
            case 0x1E59ACu: goto label_1e59ac;
            case 0x1E59D0u: goto label_1e59d0;
            case 0x1E59F0u: goto label_1e59f0;
            case 0x1E5A0Cu: goto label_1e5a0c;
            case 0x1E5A10u: goto label_1e5a10;
            case 0x1E5A80u: goto label_1e5a80;
            case 0x1E5A94u: goto label_1e5a94;
            case 0x1E5AD4u: goto label_1e5ad4;
            case 0x1E5AE4u: goto label_1e5ae4;
            case 0x1E5B08u: goto label_1e5b08;
            case 0x1E5B1Cu: goto label_1e5b1c;
            case 0x1E5B40u: goto label_1e5b40;
            case 0x1E5B54u: goto label_1e5b54;
            case 0x1E5B68u: goto label_1e5b68;
            case 0x1E5B98u: goto label_1e5b98;
            case 0x1E5BB4u: goto label_1e5bb4;
            case 0x1E5BB8u: goto label_1e5bb8;
            case 0x1E5C2Cu: goto label_1e5c2c;
            case 0x1E5C40u: goto label_1e5c40;
            case 0x1E5C80u: goto label_1e5c80;
            case 0x1E5C90u: goto label_1e5c90;
            case 0x1E5CB4u: goto label_1e5cb4;
            case 0x1E5CC8u: goto label_1e5cc8;
            case 0x1E5CECu: goto label_1e5cec;
            case 0x1E5D00u: goto label_1e5d00;
            case 0x1E5D14u: goto label_1e5d14;
            case 0x1E5D48u: goto label_1e5d48;
            case 0x1E5D64u: goto label_1e5d64;
            case 0x1E5D78u: goto label_1e5d78;
            case 0x1E5D94u: goto label_1e5d94;
            case 0x1E5E04u: goto label_1e5e04;
            case 0x1E5E18u: goto label_1e5e18;
            case 0x1E5E58u: goto label_1e5e58;
            case 0x1E5E68u: goto label_1e5e68;
            case 0x1E5E8Cu: goto label_1e5e8c;
            case 0x1E5E9Cu: goto label_1e5e9c;
            case 0x1E5EB4u: goto label_1e5eb4;
            case 0x1E5F6Cu: goto label_1e5f6c;
            case 0x1E5F88u: goto label_1e5f88;
            case 0x1E5F9Cu: goto label_1e5f9c;
            case 0x1E5FA0u: goto label_1e5fa0;
            case 0x1E6008u: goto label_1e6008;
            case 0x1E601Cu: goto label_1e601c;
            case 0x1E605Cu: goto label_1e605c;
            case 0x1E6068u: goto label_1e6068;
            case 0x1E6084u: goto label_1e6084;
            case 0x1E6094u: goto label_1e6094;
            case 0x1E60B8u: goto label_1e60b8;
            case 0x1E60CCu: goto label_1e60cc;
            case 0x1E60F0u: goto label_1e60f0;
            case 0x1E6104u: goto label_1e6104;
            case 0x1E6118u: goto label_1e6118;
            case 0x1E613Cu: goto label_1e613c;
            case 0x1E6158u: goto label_1e6158;
            case 0x1E616Cu: goto label_1e616c;
            case 0x1E6170u: goto label_1e6170;
            case 0x1E61D4u: goto label_1e61d4;
            case 0x1E61E8u: goto label_1e61e8;
            case 0x1E6228u: goto label_1e6228;
            case 0x1E623Cu: goto label_1e623c;
            case 0x1E6240u: goto label_1e6240;
            case 0x1E62A4u: goto label_1e62a4;
            case 0x1E62B8u: goto label_1e62b8;
            case 0x1E62F8u: goto label_1e62f8;
            case 0x1E630Cu: goto label_1e630c;
            case 0x1E6310u: goto label_1e6310;
            case 0x1E6374u: goto label_1e6374;
            case 0x1E6388u: goto label_1e6388;
            case 0x1E63C8u: goto label_1e63c8;
            case 0x1E63DCu: goto label_1e63dc;
            case 0x1E63E0u: goto label_1e63e0;
            case 0x1E6448u: goto label_1e6448;
            case 0x1E645Cu: goto label_1e645c;
            case 0x1E649Cu: goto label_1e649c;
            case 0x1E64B4u: goto label_1e64b4;
            case 0x1E64C4u: goto label_1e64c4;
            case 0x1E64E8u: goto label_1e64e8;
            case 0x1E64FCu: goto label_1e64fc;
            case 0x1E6520u: goto label_1e6520;
            case 0x1E6534u: goto label_1e6534;
            case 0x1E6548u: goto label_1e6548;
            case 0x1E656Cu: goto label_1e656c;
            case 0x1E6588u: goto label_1e6588;
            case 0x1E658Cu: goto label_1e658c;
            case 0x1E65F8u: goto label_1e65f8;
            case 0x1E660Cu: goto label_1e660c;
            case 0x1E664Cu: goto label_1e664c;
            case 0x1E6664u: goto label_1e6664;
            case 0x1E6674u: goto label_1e6674;
            case 0x1E6698u: goto label_1e6698;
            case 0x1E66ACu: goto label_1e66ac;
            case 0x1E66D0u: goto label_1e66d0;
            case 0x1E66E4u: goto label_1e66e4;
            case 0x1E66FCu: goto label_1e66fc;
            case 0x1E6718u: goto label_1e6718;
            case 0x1E6744u: goto label_1e6744;
            case 0x1E6760u: goto label_1e6760;
            case 0x1E6764u: goto label_1e6764;
            case 0x1E67D0u: goto label_1e67d0;
            case 0x1E67E4u: goto label_1e67e4;
            case 0x1E6824u: goto label_1e6824;
            case 0x1E6834u: goto label_1e6834;
            case 0x1E6858u: goto label_1e6858;
            case 0x1E6868u: goto label_1e6868;
            case 0x1E688Cu: goto label_1e688c;
            case 0x1E68A0u: goto label_1e68a0;
            case 0x1E68ACu: goto label_1e68ac;
            case 0x1E68BCu: goto label_1e68bc;
            case 0x1E68D4u: goto label_1e68d4;
            case 0x1E6904u: goto label_1e6904;
            case 0x1E6970u: goto label_1e6970;
            case 0x1E6988u: goto label_1e6988;
            case 0x1E699Cu: goto label_1e699c;
            case 0x1E69B0u: goto label_1e69b0;
            case 0x1E69BCu: goto label_1e69bc;
            case 0x1E69D0u: goto label_1e69d0;
            case 0x1E69F4u: goto label_1e69f4;
            case 0x1E6A08u: goto label_1e6a08;
            case 0x1E6A30u: goto label_1e6a30;
            case 0x1E6A4Cu: goto label_1e6a4c;
            case 0x1E6AC8u: goto label_1e6ac8;
            case 0x1E6AE0u: goto label_1e6ae0;
            case 0x1E6AF4u: goto label_1e6af4;
            case 0x1E6B24u: goto label_1e6b24;
            case 0x1E6B38u: goto label_1e6b38;
            case 0x1E6B6Cu: goto label_1e6b6c;
            case 0x1E6B88u: goto label_1e6b88;
            case 0x1E6BCCu: goto label_1e6bcc;
            case 0x1E6BE8u: goto label_1e6be8;
            case 0x1E6BFCu: goto label_1e6bfc;
            case 0x1E6C30u: goto label_1e6c30;
            case 0x1E6C4Cu: goto label_1e6c4c;
            case 0x1E6C58u: goto label_1e6c58;
            case 0x1E6C6Cu: goto label_1e6c6c;
            case 0x1E6C84u: goto label_1e6c84;
            case 0x1E6CB4u: goto label_1e6cb4;
            case 0x1E6CD8u: goto label_1e6cd8;
            case 0x1E6CECu: goto label_1e6cec;
            case 0x1E6CF0u: goto label_1e6cf0;
            case 0x1E6D5Cu: goto label_1e6d5c;
            case 0x1E6D70u: goto label_1e6d70;
            case 0x1E6DB0u: goto label_1e6db0;
            case 0x1E6DC0u: goto label_1e6dc0;
            case 0x1E6DE4u: goto label_1e6de4;
            case 0x1E6DF4u: goto label_1e6df4;
            case 0x1E6E18u: goto label_1e6e18;
            case 0x1E6E2Cu: goto label_1e6e2c;
            case 0x1E6E38u: goto label_1e6e38;
            case 0x1E6E48u: goto label_1e6e48;
            case 0x1E6E60u: goto label_1e6e60;
            case 0x1E6E90u: goto label_1e6e90;
            case 0x1E6EFCu: goto label_1e6efc;
            case 0x1E6F14u: goto label_1e6f14;
            case 0x1E6F28u: goto label_1e6f28;
            case 0x1E6F3Cu: goto label_1e6f3c;
            case 0x1E6F48u: goto label_1e6f48;
            case 0x1E6F5Cu: goto label_1e6f5c;
            case 0x1E6F80u: goto label_1e6f80;
            case 0x1E6F94u: goto label_1e6f94;
            case 0x1E6FBCu: goto label_1e6fbc;
            case 0x1E6FD8u: goto label_1e6fd8;
            case 0x1E7054u: goto label_1e7054;
            case 0x1E706Cu: goto label_1e706c;
            case 0x1E7080u: goto label_1e7080;
            case 0x1E70B0u: goto label_1e70b0;
            case 0x1E70C4u: goto label_1e70c4;
            case 0x1E70F8u: goto label_1e70f8;
            case 0x1E7114u: goto label_1e7114;
            case 0x1E7158u: goto label_1e7158;
            case 0x1E7174u: goto label_1e7174;
            case 0x1E7188u: goto label_1e7188;
            case 0x1E71BCu: goto label_1e71bc;
            case 0x1E71D8u: goto label_1e71d8;
            case 0x1E71E4u: goto label_1e71e4;
            case 0x1E71F8u: goto label_1e71f8;
            case 0x1E7210u: goto label_1e7210;
            case 0x1E7240u: goto label_1e7240;
            case 0x1E7264u: goto label_1e7264;
            case 0x1E7278u: goto label_1e7278;
            case 0x1E727Cu: goto label_1e727c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E51B0u;
    // 0x1e51b0: 0x27bdff80  addiu       $sp, $sp, -0x80
    ctx->pc = 0x1e51b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x1e51b4: 0xffbe0030  sd          $fp, 0x30($sp)
    ctx->pc = 0x1e51b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 30));
    // 0x1e51b8: 0xffbf0038  sd          $ra, 0x38($sp)
    ctx->pc = 0x1e51b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x1e51bc: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e51bcu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e51c0: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e51c0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e51c4: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x1e51c4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e51c8: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e51c8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e51cc: 0xafc7000c  sw          $a3, 0xC($fp)
    ctx->pc = 0x1e51ccu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 7));
    // 0x1e51d0: 0xffc90068  sd          $t1, 0x68($fp)
    ctx->pc = 0x1e51d0u;
    WRITE64(ADD32(GPR_U32(ctx, 30), 104), GPR_U64(ctx, 9));
    // 0x1e51d4: 0xffca0070  sd          $t2, 0x70($fp)
    ctx->pc = 0x1e51d4u;
    WRITE64(ADD32(GPR_U32(ctx, 30), 112), GPR_U64(ctx, 10));
    // 0x1e51d8: 0xffcb0078  sd          $t3, 0x78($fp)
    ctx->pc = 0x1e51d8u;
    WRITE64(ADD32(GPR_U32(ctx, 30), 120), GPR_U64(ctx, 11));
    // 0x1e51dc: 0xe7cc0048  swc1        $f12, 0x48($fp)
    ctx->pc = 0x1e51dcu;
    { float f = ctx->f[12]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 30), 72), bits); }
    // 0x1e51e0: 0xe7cd004c  swc1        $f13, 0x4C($fp)
    ctx->pc = 0x1e51e0u;
    { float f = ctx->f[13]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 30), 76), bits); }
    // 0x1e51e4: 0xe7ce0050  swc1        $f14, 0x50($fp)
    ctx->pc = 0x1e51e4u;
    { float f = ctx->f[14]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 30), 80), bits); }
    // 0x1e51e8: 0xe7cf0054  swc1        $f15, 0x54($fp)
    ctx->pc = 0x1e51e8u;
    { float f = ctx->f[15]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 30), 84), bits); }
    // 0x1e51ec: 0xe7d00058  swc1        $f16, 0x58($fp)
    ctx->pc = 0x1e51ecu;
    { float f = ctx->f[16]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 30), 88), bits); }
    // 0x1e51f0: 0xe7d1005c  swc1        $f17, 0x5C($fp)
    ctx->pc = 0x1e51f0u;
    { float f = ctx->f[17]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 30), 92), bits); }
    // 0x1e51f4: 0xe7d20060  swc1        $f18, 0x60($fp)
    ctx->pc = 0x1e51f4u;
    { float f = ctx->f[18]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 30), 96), bits); }
    // 0x1e51f8: 0xe7d30064  swc1        $f19, 0x64($fp)
    ctx->pc = 0x1e51f8u;
    { float f = ctx->f[19]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 30), 100), bits); }
    // 0x1e51fc: 0xafc80010  sw          $t0, 0x10($fp)
    ctx->pc = 0x1e51fcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 8));
    // 0x1e5200: 0xa7c20004  sh          $v0, 0x4($fp)
    ctx->pc = 0x1e5200u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 4), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e5204: 0xafc00024  sw          $zero, 0x24($fp)
    ctx->pc = 0x1e5204u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 0));
    // 0x1e5208: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e5208u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e520c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e520cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e5210: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E5210u;
    {
        const bool branch_taken_0x1e5210 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e5210) {
            ctx->pc = 0x1E5238u;
            goto label_1e5238;
        }
    }
    ctx->pc = 0x1E5218u;
    // 0x1e5218: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e5218u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e521c: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e521cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e5220: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e5220u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e5224: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e5224u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e5228: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e5228u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e522c: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e522cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e5230: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E5230u;
    {
        const bool branch_taken_0x1e5230 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e5230) {
            ctx->pc = 0x1E524Cu;
            goto label_1e524c;
        }
    }
    ctx->pc = 0x1E5238u;
label_1e5238:
    // 0x1e5238: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e5238u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e523c: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e523cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e5240: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e5240u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e5244: 0x1000008f  b           . + 4 + (0x8F << 2)
    ctx->pc = 0x1E5244u;
    {
        const bool branch_taken_0x1e5244 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5244) {
            ctx->pc = 0x1E5484u;
            goto label_1e5484;
        }
    }
    ctx->pc = 0x1E524Cu;
label_1e524c:
    // 0x1e524c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e524cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e5250: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e5250u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e5254: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e5254u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e5258: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e5258u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e525c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e525cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e5260: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e5260u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e5264: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1e5264u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1e5268: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1e5268u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1e526c: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e526cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e5270: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E5270u;
    {
        const bool branch_taken_0x1e5270 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5270) {
            ctx->pc = 0x1E528Cu;
            goto label_1e528c;
        }
    }
    ctx->pc = 0x1E5278u;
    // 0x1e5278: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e5278u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e527c: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e527cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e5280: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e5280u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e5284: 0x1000007f  b           . + 4 + (0x7F << 2)
    ctx->pc = 0x1E5284u;
    {
        const bool branch_taken_0x1e5284 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5284) {
            ctx->pc = 0x1E5484u;
            goto label_1e5484;
        }
    }
    ctx->pc = 0x1E528Cu;
label_1e528c:
    // 0x1e528c: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e528cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e5290: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e5290u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e5294: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e5294u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e5298: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e5298u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e529c: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1e529cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1e52a0: 0x8fc40024  lw          $a0, 0x24($fp)
    ctx->pc = 0x1e52a0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1e52a4: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1e52a4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e52a8: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E52A8u;
    SET_GPR_U32(ctx, 31, 0x1E52B0u);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E52B0u; }
        if (ctx->pc != 0x1E52B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E52B0u; }
        if (ctx->pc != 0x1E52B0u) { return; }
    }
    ctx->pc = 0x1E52B0u;
label_1e52b0:
    // 0x1e52b0: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1e52b0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1e52b4: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e52b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e52b8: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E52B8u;
    {
        const bool branch_taken_0x1e52b8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e52b8) {
            ctx->pc = 0x1E52D4u;
            goto label_1e52d4;
        }
    }
    ctx->pc = 0x1E52C0u;
    // 0x1e52c0: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e52c0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e52c4: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e52c4u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e52c8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e52c8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e52cc: 0x1000006d  b           . + 4 + (0x6D << 2)
    ctx->pc = 0x1E52CCu;
    {
        const bool branch_taken_0x1e52cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e52cc) {
            ctx->pc = 0x1E5484u;
            goto label_1e5484;
        }
    }
    ctx->pc = 0x1E52D4u;
label_1e52d4:
    // 0x1e52d4: 0x27c20080  addiu       $v0, $fp, 0x80
    ctx->pc = 0x1e52d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 128));
    // 0x1e52d8: 0x2442ffe8  addiu       $v0, $v0, -0x18
    ctx->pc = 0x1e52d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967272));
    // 0x1e52dc: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1e52dcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1e52e0: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e52e0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e52e4: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1e52e4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e52e8: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e52e8u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e52ec: 0x97c2000c  lhu         $v0, 0xC($fp)
    ctx->pc = 0x1e52ecu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e52f0: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e52f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e52f4: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1e52f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1e52f8: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1e52f8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1e52fc: 0x8fc40018  lw          $a0, 0x18($fp)
    ctx->pc = 0x1e52fcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e5300: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1e5300u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e5304: 0xc07cc3c  jal         func_1F30F0
    ctx->pc = 0x1E5304u;
    SET_GPR_U32(ctx, 31, 0x1E530Cu);
    ctx->pc = 0x1F30F0u;
    if (runtime->hasFunction(0x1F30F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F30F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E530Cu; }
        if (ctx->pc != 0x1E530Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F30F0_0x1f30f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E530Cu; }
        if (ctx->pc != 0x1E530Cu) { return; }
    }
    ctx->pc = 0x1E530Cu;
label_1e530c:
    // 0x1e530c: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1e530cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1e5310: 0x27c6001c  addiu       $a2, $fp, 0x1C
    ctx->pc = 0x1e5310u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 30), 28));
    // 0x1e5314: 0x8cc50000  lw          $a1, 0x0($a2)
    ctx->pc = 0x1e5314u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1e5318: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e5318u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e531c: 0x304300ff  andi        $v1, $v0, 0xFF
    ctx->pc = 0x1e531cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1e5320: 0x31e00  sll         $v1, $v1, 24
    ctx->pc = 0x1e5320u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 24));
    // 0x1e5324: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e5324u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e5328: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1e5328u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1e532c: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1e532cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1e5330: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1e5330u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e5334: 0x8fc40010  lw          $a0, 0x10($fp)
    ctx->pc = 0x1e5334u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e5338: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1e5338u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1e533c: 0x821024  and         $v0, $a0, $v0
    ctx->pc = 0x1e533cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & GPR_U64(ctx, 2));
    // 0x1e5340: 0x21203  sra         $v0, $v0, 8
    ctx->pc = 0x1e5340u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 8));
    // 0x1e5344: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1e5344u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e5348: 0x8fc40010  lw          $a0, 0x10($fp)
    ctx->pc = 0x1e5348u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e534c: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1e534cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1e5350: 0x821024  and         $v0, $a0, $v0
    ctx->pc = 0x1e5350u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & GPR_U64(ctx, 2));
    // 0x1e5354: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1e5354u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1e5358: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1e5358u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e535c: 0xaca30000  sw          $v1, 0x0($a1)
    ctx->pc = 0x1e535cu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 3));
    // 0x1e5360: 0x24a50004  addiu       $a1, $a1, 0x4
    ctx->pc = 0x1e5360u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4));
    // 0x1e5364: 0xacc50000  sw          $a1, 0x0($a2)
    ctx->pc = 0x1e5364u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 5));
    // 0x1e5368: 0xafc00028  sw          $zero, 0x28($fp)
    ctx->pc = 0x1e5368u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 0));
label_1e536c:
    // 0x1e536c: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1e536cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1e5370: 0x8fc30010  lw          $v1, 0x10($fp)
    ctx->pc = 0x1e5370u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e5374: 0x43102a  slt         $v0, $v0, $v1
    ctx->pc = 0x1e5374u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1e5378: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1E5378u;
    {
        const bool branch_taken_0x1e5378 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e5378) {
            ctx->pc = 0x1E5388u;
            goto label_1e5388;
        }
    }
    ctx->pc = 0x1E5380u;
    // 0x1e5380: 0x10000023  b           . + 4 + (0x23 << 2)
    ctx->pc = 0x1E5380u;
    {
        const bool branch_taken_0x1e5380 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5380) {
            ctx->pc = 0x1E5410u;
            goto label_1e5410;
        }
    }
    ctx->pc = 0x1E5388u;
label_1e5388:
    // 0x1e5388: 0x27c30014  addiu       $v1, $fp, 0x14
    ctx->pc = 0x1e5388u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 30), 20));
    // 0x1e538c: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x1e538cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1e5390: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1e5390u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e5394: 0x24420008  addiu       $v0, $v0, 0x8
    ctx->pc = 0x1e5394u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x1e5398: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1e5398u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1e539c: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1e539cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1e53a0: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1e53a0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1e53a4: 0x27c6001c  addiu       $a2, $fp, 0x1C
    ctx->pc = 0x1e53a4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 30), 28));
    // 0x1e53a8: 0x8cc50000  lw          $a1, 0x0($a2)
    ctx->pc = 0x1e53a8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1e53ac: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e53acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e53b0: 0x304300ff  andi        $v1, $v0, 0xFF
    ctx->pc = 0x1e53b0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1e53b4: 0x31e00  sll         $v1, $v1, 24
    ctx->pc = 0x1e53b4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 24));
    // 0x1e53b8: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e53b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e53bc: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1e53bcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1e53c0: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1e53c0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1e53c4: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1e53c4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e53c8: 0x8fc40020  lw          $a0, 0x20($fp)
    ctx->pc = 0x1e53c8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e53cc: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1e53ccu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1e53d0: 0x821024  and         $v0, $a0, $v0
    ctx->pc = 0x1e53d0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & GPR_U64(ctx, 2));
    // 0x1e53d4: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1e53d4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1e53d8: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1e53d8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e53dc: 0x8fc40020  lw          $a0, 0x20($fp)
    ctx->pc = 0x1e53dcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e53e0: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1e53e0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1e53e4: 0x821024  and         $v0, $a0, $v0
    ctx->pc = 0x1e53e4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & GPR_U64(ctx, 2));
    // 0x1e53e8: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1e53e8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1e53ec: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1e53ecu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e53f0: 0xaca30000  sw          $v1, 0x0($a1)
    ctx->pc = 0x1e53f0u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 3));
    // 0x1e53f4: 0x24a50004  addiu       $a1, $a1, 0x4
    ctx->pc = 0x1e53f4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4));
    // 0x1e53f8: 0xacc50000  sw          $a1, 0x0($a2)
    ctx->pc = 0x1e53f8u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 5));
    // 0x1e53fc: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1e53fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1e5400: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1e5400u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1e5404: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1e5404u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1e5408: 0x1000ffd8  b           . + 4 + (-0x28 << 2)
    ctx->pc = 0x1E5408u;
    {
        const bool branch_taken_0x1e5408 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5408) {
            ctx->pc = 0x1E536Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1e536c;
        }
    }
    ctx->pc = 0x1E5410u;
label_1e5410:
    // 0x1e5410: 0x8fc4001c  lw          $a0, 0x1C($fp)
    ctx->pc = 0x1e5410u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e5414: 0x8fc50008  lw          $a1, 0x8($fp)
    ctx->pc = 0x1e5414u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e5418: 0x8fc6000c  lw          $a2, 0xC($fp)
    ctx->pc = 0x1e5418u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e541c: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1E541Cu;
    SET_GPR_U32(ctx, 31, 0x1E5424u);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5424u; }
        if (ctx->pc != 0x1E5424u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5424u; }
        if (ctx->pc != 0x1E5424u) { return; }
    }
    ctx->pc = 0x1E5424u;
label_1e5424:
    // 0x1e5424: 0x97c20004  lhu         $v0, 0x4($fp)
    ctx->pc = 0x1e5424u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e5428: 0x34422000  ori         $v0, $v0, 0x2000
    ctx->pc = 0x1e5428u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)8192);
    // 0x1e542c: 0x3046ffff  andi        $a2, $v0, 0xFFFF
    ctx->pc = 0x1e542cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1e5430: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e5430u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e5434: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1e5434u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e5438: 0x97c3000c  lhu         $v1, 0xC($fp)
    ctx->pc = 0x1e5438u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e543c: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e543cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e5440: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1e5440u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1e5444: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1e5444u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1e5448: 0x8fc40024  lw          $a0, 0x24($fp)
    ctx->pc = 0x1e5448u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1e544c: 0x8fc50018  lw          $a1, 0x18($fp)
    ctx->pc = 0x1e544cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e5450: 0x40382d  daddu       $a3, $v0, $zero
    ctx->pc = 0x1e5450u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e5454: 0x24080010  addiu       $t0, $zero, 0x10
    ctx->pc = 0x1e5454u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1e5458: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1e5458u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e545c: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E545Cu;
    SET_GPR_U32(ctx, 31, 0x1E5464u);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5464u; }
        if (ctx->pc != 0x1E5464u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5464u; }
        if (ctx->pc != 0x1E5464u) { return; }
    }
    ctx->pc = 0x1E5464u;
label_1e5464:
    // 0x1e5464: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E5464u;
    {
        const bool branch_taken_0x1e5464 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5464) {
            ctx->pc = 0x1E5480u;
            goto label_1e5480;
        }
    }
    ctx->pc = 0x1E546Cu;
    // 0x1e546c: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e546cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e5470: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e5470u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e5474: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e5474u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e5478: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1E5478u;
    {
        const bool branch_taken_0x1e5478 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5478) {
            ctx->pc = 0x1E5484u;
            goto label_1e5484;
        }
    }
    ctx->pc = 0x1E5480u;
label_1e5480:
    // 0x1e5480: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1e5480u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1e5484:
    // 0x1e5484: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e5484u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e5488: 0xdfbe0030  ld          $fp, 0x30($sp)
    ctx->pc = 0x1e5488u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1e548c: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x1e548cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x1e5490: 0x27bd0080  addiu       $sp, $sp, 0x80
    ctx->pc = 0x1e5490u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
    // 0x1e5494: 0x3e00008  jr          $ra
    ctx->pc = 0x1E5494u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E5060u: goto label_1e5060;
            case 0x1E5074u: goto label_1e5074;
            case 0x1E50B4u: goto label_1e50b4;
            case 0x1E50C4u: goto label_1e50c4;
            case 0x1E50E8u: goto label_1e50e8;
            case 0x1E50FCu: goto label_1e50fc;
            case 0x1E5120u: goto label_1e5120;
            case 0x1E5134u: goto label_1e5134;
            case 0x1E5148u: goto label_1e5148;
            case 0x1E5178u: goto label_1e5178;
            case 0x1E5194u: goto label_1e5194;
            case 0x1E5198u: goto label_1e5198;
            case 0x1E5238u: goto label_1e5238;
            case 0x1E524Cu: goto label_1e524c;
            case 0x1E528Cu: goto label_1e528c;
            case 0x1E52B0u: goto label_1e52b0;
            case 0x1E52D4u: goto label_1e52d4;
            case 0x1E530Cu: goto label_1e530c;
            case 0x1E536Cu: goto label_1e536c;
            case 0x1E5388u: goto label_1e5388;
            case 0x1E5410u: goto label_1e5410;
            case 0x1E5424u: goto label_1e5424;
            case 0x1E5464u: goto label_1e5464;
            case 0x1E5480u: goto label_1e5480;
            case 0x1E5484u: goto label_1e5484;
            case 0x1E54F8u: goto label_1e54f8;
            case 0x1E550Cu: goto label_1e550c;
            case 0x1E554Cu: goto label_1e554c;
            case 0x1E5574u: goto label_1e5574;
            case 0x1E5598u: goto label_1e5598;
            case 0x1E55C8u: goto label_1e55c8;
            case 0x1E55ECu: goto label_1e55ec;
            case 0x1E5600u: goto label_1e5600;
            case 0x1E566Cu: goto label_1e566c;
            case 0x1E568Cu: goto label_1e568c;
            case 0x1E5748u: goto label_1e5748;
            case 0x1E575Cu: goto label_1e575c;
            case 0x1E57A0u: goto label_1e57a0;
            case 0x1E57BCu: goto label_1e57bc;
            case 0x1E57C0u: goto label_1e57c0;
            case 0x1E5820u: goto label_1e5820;
            case 0x1E5834u: goto label_1e5834;
            case 0x1E5874u: goto label_1e5874;
            case 0x1E5884u: goto label_1e5884;
            case 0x1E58A8u: goto label_1e58a8;
            case 0x1E58C8u: goto label_1e58c8;
            case 0x1E58E4u: goto label_1e58e4;
            case 0x1E58E8u: goto label_1e58e8;
            case 0x1E5948u: goto label_1e5948;
            case 0x1E595Cu: goto label_1e595c;
            case 0x1E599Cu: goto label_1e599c;
            case 0x1E59ACu: goto label_1e59ac;
            case 0x1E59D0u: goto label_1e59d0;
            case 0x1E59F0u: goto label_1e59f0;
            case 0x1E5A0Cu: goto label_1e5a0c;
            case 0x1E5A10u: goto label_1e5a10;
            case 0x1E5A80u: goto label_1e5a80;
            case 0x1E5A94u: goto label_1e5a94;
            case 0x1E5AD4u: goto label_1e5ad4;
            case 0x1E5AE4u: goto label_1e5ae4;
            case 0x1E5B08u: goto label_1e5b08;
            case 0x1E5B1Cu: goto label_1e5b1c;
            case 0x1E5B40u: goto label_1e5b40;
            case 0x1E5B54u: goto label_1e5b54;
            case 0x1E5B68u: goto label_1e5b68;
            case 0x1E5B98u: goto label_1e5b98;
            case 0x1E5BB4u: goto label_1e5bb4;
            case 0x1E5BB8u: goto label_1e5bb8;
            case 0x1E5C2Cu: goto label_1e5c2c;
            case 0x1E5C40u: goto label_1e5c40;
            case 0x1E5C80u: goto label_1e5c80;
            case 0x1E5C90u: goto label_1e5c90;
            case 0x1E5CB4u: goto label_1e5cb4;
            case 0x1E5CC8u: goto label_1e5cc8;
            case 0x1E5CECu: goto label_1e5cec;
            case 0x1E5D00u: goto label_1e5d00;
            case 0x1E5D14u: goto label_1e5d14;
            case 0x1E5D48u: goto label_1e5d48;
            case 0x1E5D64u: goto label_1e5d64;
            case 0x1E5D78u: goto label_1e5d78;
            case 0x1E5D94u: goto label_1e5d94;
            case 0x1E5E04u: goto label_1e5e04;
            case 0x1E5E18u: goto label_1e5e18;
            case 0x1E5E58u: goto label_1e5e58;
            case 0x1E5E68u: goto label_1e5e68;
            case 0x1E5E8Cu: goto label_1e5e8c;
            case 0x1E5E9Cu: goto label_1e5e9c;
            case 0x1E5EB4u: goto label_1e5eb4;
            case 0x1E5F6Cu: goto label_1e5f6c;
            case 0x1E5F88u: goto label_1e5f88;
            case 0x1E5F9Cu: goto label_1e5f9c;
            case 0x1E5FA0u: goto label_1e5fa0;
            case 0x1E6008u: goto label_1e6008;
            case 0x1E601Cu: goto label_1e601c;
            case 0x1E605Cu: goto label_1e605c;
            case 0x1E6068u: goto label_1e6068;
            case 0x1E6084u: goto label_1e6084;
            case 0x1E6094u: goto label_1e6094;
            case 0x1E60B8u: goto label_1e60b8;
            case 0x1E60CCu: goto label_1e60cc;
            case 0x1E60F0u: goto label_1e60f0;
            case 0x1E6104u: goto label_1e6104;
            case 0x1E6118u: goto label_1e6118;
            case 0x1E613Cu: goto label_1e613c;
            case 0x1E6158u: goto label_1e6158;
            case 0x1E616Cu: goto label_1e616c;
            case 0x1E6170u: goto label_1e6170;
            case 0x1E61D4u: goto label_1e61d4;
            case 0x1E61E8u: goto label_1e61e8;
            case 0x1E6228u: goto label_1e6228;
            case 0x1E623Cu: goto label_1e623c;
            case 0x1E6240u: goto label_1e6240;
            case 0x1E62A4u: goto label_1e62a4;
            case 0x1E62B8u: goto label_1e62b8;
            case 0x1E62F8u: goto label_1e62f8;
            case 0x1E630Cu: goto label_1e630c;
            case 0x1E6310u: goto label_1e6310;
            case 0x1E6374u: goto label_1e6374;
            case 0x1E6388u: goto label_1e6388;
            case 0x1E63C8u: goto label_1e63c8;
            case 0x1E63DCu: goto label_1e63dc;
            case 0x1E63E0u: goto label_1e63e0;
            case 0x1E6448u: goto label_1e6448;
            case 0x1E645Cu: goto label_1e645c;
            case 0x1E649Cu: goto label_1e649c;
            case 0x1E64B4u: goto label_1e64b4;
            case 0x1E64C4u: goto label_1e64c4;
            case 0x1E64E8u: goto label_1e64e8;
            case 0x1E64FCu: goto label_1e64fc;
            case 0x1E6520u: goto label_1e6520;
            case 0x1E6534u: goto label_1e6534;
            case 0x1E6548u: goto label_1e6548;
            case 0x1E656Cu: goto label_1e656c;
            case 0x1E6588u: goto label_1e6588;
            case 0x1E658Cu: goto label_1e658c;
            case 0x1E65F8u: goto label_1e65f8;
            case 0x1E660Cu: goto label_1e660c;
            case 0x1E664Cu: goto label_1e664c;
            case 0x1E6664u: goto label_1e6664;
            case 0x1E6674u: goto label_1e6674;
            case 0x1E6698u: goto label_1e6698;
            case 0x1E66ACu: goto label_1e66ac;
            case 0x1E66D0u: goto label_1e66d0;
            case 0x1E66E4u: goto label_1e66e4;
            case 0x1E66FCu: goto label_1e66fc;
            case 0x1E6718u: goto label_1e6718;
            case 0x1E6744u: goto label_1e6744;
            case 0x1E6760u: goto label_1e6760;
            case 0x1E6764u: goto label_1e6764;
            case 0x1E67D0u: goto label_1e67d0;
            case 0x1E67E4u: goto label_1e67e4;
            case 0x1E6824u: goto label_1e6824;
            case 0x1E6834u: goto label_1e6834;
            case 0x1E6858u: goto label_1e6858;
            case 0x1E6868u: goto label_1e6868;
            case 0x1E688Cu: goto label_1e688c;
            case 0x1E68A0u: goto label_1e68a0;
            case 0x1E68ACu: goto label_1e68ac;
            case 0x1E68BCu: goto label_1e68bc;
            case 0x1E68D4u: goto label_1e68d4;
            case 0x1E6904u: goto label_1e6904;
            case 0x1E6970u: goto label_1e6970;
            case 0x1E6988u: goto label_1e6988;
            case 0x1E699Cu: goto label_1e699c;
            case 0x1E69B0u: goto label_1e69b0;
            case 0x1E69BCu: goto label_1e69bc;
            case 0x1E69D0u: goto label_1e69d0;
            case 0x1E69F4u: goto label_1e69f4;
            case 0x1E6A08u: goto label_1e6a08;
            case 0x1E6A30u: goto label_1e6a30;
            case 0x1E6A4Cu: goto label_1e6a4c;
            case 0x1E6AC8u: goto label_1e6ac8;
            case 0x1E6AE0u: goto label_1e6ae0;
            case 0x1E6AF4u: goto label_1e6af4;
            case 0x1E6B24u: goto label_1e6b24;
            case 0x1E6B38u: goto label_1e6b38;
            case 0x1E6B6Cu: goto label_1e6b6c;
            case 0x1E6B88u: goto label_1e6b88;
            case 0x1E6BCCu: goto label_1e6bcc;
            case 0x1E6BE8u: goto label_1e6be8;
            case 0x1E6BFCu: goto label_1e6bfc;
            case 0x1E6C30u: goto label_1e6c30;
            case 0x1E6C4Cu: goto label_1e6c4c;
            case 0x1E6C58u: goto label_1e6c58;
            case 0x1E6C6Cu: goto label_1e6c6c;
            case 0x1E6C84u: goto label_1e6c84;
            case 0x1E6CB4u: goto label_1e6cb4;
            case 0x1E6CD8u: goto label_1e6cd8;
            case 0x1E6CECu: goto label_1e6cec;
            case 0x1E6CF0u: goto label_1e6cf0;
            case 0x1E6D5Cu: goto label_1e6d5c;
            case 0x1E6D70u: goto label_1e6d70;
            case 0x1E6DB0u: goto label_1e6db0;
            case 0x1E6DC0u: goto label_1e6dc0;
            case 0x1E6DE4u: goto label_1e6de4;
            case 0x1E6DF4u: goto label_1e6df4;
            case 0x1E6E18u: goto label_1e6e18;
            case 0x1E6E2Cu: goto label_1e6e2c;
            case 0x1E6E38u: goto label_1e6e38;
            case 0x1E6E48u: goto label_1e6e48;
            case 0x1E6E60u: goto label_1e6e60;
            case 0x1E6E90u: goto label_1e6e90;
            case 0x1E6EFCu: goto label_1e6efc;
            case 0x1E6F14u: goto label_1e6f14;
            case 0x1E6F28u: goto label_1e6f28;
            case 0x1E6F3Cu: goto label_1e6f3c;
            case 0x1E6F48u: goto label_1e6f48;
            case 0x1E6F5Cu: goto label_1e6f5c;
            case 0x1E6F80u: goto label_1e6f80;
            case 0x1E6F94u: goto label_1e6f94;
            case 0x1E6FBCu: goto label_1e6fbc;
            case 0x1E6FD8u: goto label_1e6fd8;
            case 0x1E7054u: goto label_1e7054;
            case 0x1E706Cu: goto label_1e706c;
            case 0x1E7080u: goto label_1e7080;
            case 0x1E70B0u: goto label_1e70b0;
            case 0x1E70C4u: goto label_1e70c4;
            case 0x1E70F8u: goto label_1e70f8;
            case 0x1E7114u: goto label_1e7114;
            case 0x1E7158u: goto label_1e7158;
            case 0x1E7174u: goto label_1e7174;
            case 0x1E7188u: goto label_1e7188;
            case 0x1E71BCu: goto label_1e71bc;
            case 0x1E71D8u: goto label_1e71d8;
            case 0x1E71E4u: goto label_1e71e4;
            case 0x1E71F8u: goto label_1e71f8;
            case 0x1E7210u: goto label_1e7210;
            case 0x1E7240u: goto label_1e7240;
            case 0x1E7264u: goto label_1e7264;
            case 0x1E7278u: goto label_1e7278;
            case 0x1E727Cu: goto label_1e727c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E549Cu;
    // 0x1e549c: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1e549cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1e54a0: 0xffbe0030  sd          $fp, 0x30($sp)
    ctx->pc = 0x1e54a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 30));
    // 0x1e54a4: 0xffbf0038  sd          $ra, 0x38($sp)
    ctx->pc = 0x1e54a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x1e54a8: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e54a8u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e54ac: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e54acu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e54b0: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x1e54b0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e54b4: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e54b4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e54b8: 0xafc7000c  sw          $a3, 0xC($fp)
    ctx->pc = 0x1e54b8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 7));
    // 0x1e54bc: 0xafc80010  sw          $t0, 0x10($fp)
    ctx->pc = 0x1e54bcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 8));
    // 0x1e54c0: 0xa7c20004  sh          $v0, 0x4($fp)
    ctx->pc = 0x1e54c0u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 4), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e54c4: 0xafc0001c  sw          $zero, 0x1C($fp)
    ctx->pc = 0x1e54c4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 0));
    // 0x1e54c8: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e54c8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e54cc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e54ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e54d0: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E54D0u;
    {
        const bool branch_taken_0x1e54d0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e54d0) {
            ctx->pc = 0x1E54F8u;
            goto label_1e54f8;
        }
    }
    ctx->pc = 0x1E54D8u;
    // 0x1e54d8: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e54d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e54dc: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e54dcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e54e0: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e54e0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e54e4: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e54e4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e54e8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e54e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e54ec: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e54ecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e54f0: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E54F0u;
    {
        const bool branch_taken_0x1e54f0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e54f0) {
            ctx->pc = 0x1E550Cu;
            goto label_1e550c;
        }
    }
    ctx->pc = 0x1E54F8u;
label_1e54f8:
    // 0x1e54f8: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e54f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e54fc: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e54fcu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e5500: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e5500u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e5504: 0x100000ae  b           . + 4 + (0xAE << 2)
    ctx->pc = 0x1E5504u;
    {
        const bool branch_taken_0x1e5504 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5504) {
            ctx->pc = 0x1E57C0u;
            goto label_1e57c0;
        }
    }
    ctx->pc = 0x1E550Cu;
label_1e550c:
    // 0x1e550c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e550cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e5510: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e5510u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e5514: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e5514u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e5518: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e5518u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e551c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e551cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e5520: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e5520u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e5524: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1e5524u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1e5528: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1e5528u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e552c: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e552cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e5530: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E5530u;
    {
        const bool branch_taken_0x1e5530 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5530) {
            ctx->pc = 0x1E554Cu;
            goto label_1e554c;
        }
    }
    ctx->pc = 0x1E5538u;
    // 0x1e5538: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e5538u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e553c: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e553cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e5540: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e5540u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e5544: 0x1000009e  b           . + 4 + (0x9E << 2)
    ctx->pc = 0x1E5544u;
    {
        const bool branch_taken_0x1e5544 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5544) {
            ctx->pc = 0x1E57C0u;
            goto label_1e57c0;
        }
    }
    ctx->pc = 0x1E554Cu;
label_1e554c:
    // 0x1e554c: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e554cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e5550: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e5550u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e5554: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e5554u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e5558: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e5558u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e555c: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e555cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e5560: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1e5560u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1e5564: 0x8fc4001c  lw          $a0, 0x1C($fp)
    ctx->pc = 0x1e5564u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e5568: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1e5568u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e556c: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E556Cu;
    SET_GPR_U32(ctx, 31, 0x1E5574u);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5574u; }
        if (ctx->pc != 0x1E5574u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5574u; }
        if (ctx->pc != 0x1E5574u) { return; }
    }
    ctx->pc = 0x1E5574u;
label_1e5574:
    // 0x1e5574: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1e5574u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1e5578: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e5578u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e557c: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E557Cu;
    {
        const bool branch_taken_0x1e557c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e557c) {
            ctx->pc = 0x1E5598u;
            goto label_1e5598;
        }
    }
    ctx->pc = 0x1E5584u;
    // 0x1e5584: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e5584u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e5588: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e5588u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e558c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e558cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e5590: 0x1000008b  b           . + 4 + (0x8B << 2)
    ctx->pc = 0x1E5590u;
    {
        const bool branch_taken_0x1e5590 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5590) {
            ctx->pc = 0x1E57C0u;
            goto label_1e57c0;
        }
    }
    ctx->pc = 0x1E5598u;
label_1e5598:
    // 0x1e5598: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e5598u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e559c: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e559cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e55a0: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1e55a0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e55a4: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e55a4u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e55a8: 0x97c2000c  lhu         $v0, 0xC($fp)
    ctx->pc = 0x1e55a8u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e55ac: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e55acu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e55b0: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1e55b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1e55b4: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1e55b4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1e55b8: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e55b8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e55bc: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1e55bcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e55c0: 0xc07cc3c  jal         func_1F30F0
    ctx->pc = 0x1E55C0u;
    SET_GPR_U32(ctx, 31, 0x1E55C8u);
    ctx->pc = 0x1F30F0u;
    if (runtime->hasFunction(0x1F30F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F30F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E55C8u; }
        if (ctx->pc != 0x1E55C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F30F0_0x1f30f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E55C8u; }
        if (ctx->pc != 0x1E55C8u) { return; }
    }
    ctx->pc = 0x1E55C8u;
label_1e55c8:
    // 0x1e55c8: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1e55c8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1e55cc: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e55ccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e55d0: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1E55D0u;
    {
        const bool branch_taken_0x1e55d0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e55d0) {
            ctx->pc = 0x1E5600u;
            goto label_1e5600;
        }
    }
    ctx->pc = 0x1E55D8u;
    // 0x1e55d8: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1e55d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e55dc: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1e55dcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1e55e0: 0x8fc50014  lw          $a1, 0x14($fp)
    ctx->pc = 0x1e55e0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e55e4: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1E55E4u;
    SET_GPR_U32(ctx, 31, 0x1E55ECu);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E55ECu; }
        if (ctx->pc != 0x1E55ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E55ECu; }
        if (ctx->pc != 0x1E55ECu) { return; }
    }
    ctx->pc = 0x1E55ECu;
label_1e55ec:
    // 0x1e55ec: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e55ecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e55f0: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e55f0u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e55f4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e55f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e55f8: 0x10000071  b           . + 4 + (0x71 << 2)
    ctx->pc = 0x1E55F8u;
    {
        const bool branch_taken_0x1e55f8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e55f8) {
            ctx->pc = 0x1E57C0u;
            goto label_1e57c0;
        }
    }
    ctx->pc = 0x1E5600u;
label_1e5600:
    // 0x1e5600: 0x27c60018  addiu       $a2, $fp, 0x18
    ctx->pc = 0x1e5600u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 30), 24));
    // 0x1e5604: 0x8cc50000  lw          $a1, 0x0($a2)
    ctx->pc = 0x1e5604u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1e5608: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e5608u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e560c: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e560cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e5610: 0x304300ff  andi        $v1, $v0, 0xFF
    ctx->pc = 0x1e5610u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1e5614: 0x31e00  sll         $v1, $v1, 24
    ctx->pc = 0x1e5614u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 24));
    // 0x1e5618: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e5618u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e561c: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e561cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e5620: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1e5620u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1e5624: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1e5624u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1e5628: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1e5628u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e562c: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e562cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e5630: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x1e5630u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e5634: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1e5634u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1e5638: 0x821024  and         $v0, $a0, $v0
    ctx->pc = 0x1e5638u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & GPR_U64(ctx, 2));
    // 0x1e563c: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1e563cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1e5640: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1e5640u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e5644: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e5644u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e5648: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x1e5648u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e564c: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1e564cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1e5650: 0x821024  and         $v0, $a0, $v0
    ctx->pc = 0x1e5650u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & GPR_U64(ctx, 2));
    // 0x1e5654: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1e5654u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1e5658: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1e5658u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e565c: 0xaca30000  sw          $v1, 0x0($a1)
    ctx->pc = 0x1e565cu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 3));
    // 0x1e5660: 0x24a50004  addiu       $a1, $a1, 0x4
    ctx->pc = 0x1e5660u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4));
    // 0x1e5664: 0xacc50000  sw          $a1, 0x0($a2)
    ctx->pc = 0x1e5664u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 5));
    // 0x1e5668: 0xafc00020  sw          $zero, 0x20($fp)
    ctx->pc = 0x1e5668u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 0));
label_1e566c:
    // 0x1e566c: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e566cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e5670: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1e5670u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e5674: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e5674u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e5678: 0x62102a  slt         $v0, $v1, $v0
    ctx->pc = 0x1e5678u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1e567c: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1E567Cu;
    {
        const bool branch_taken_0x1e567c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e567c) {
            ctx->pc = 0x1E568Cu;
            goto label_1e568c;
        }
    }
    ctx->pc = 0x1E5684u;
    // 0x1e5684: 0x10000030  b           . + 4 + (0x30 << 2)
    ctx->pc = 0x1E5684u;
    {
        const bool branch_taken_0x1e5684 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5684) {
            ctx->pc = 0x1E5748u;
            goto label_1e5748;
        }
    }
    ctx->pc = 0x1E568Cu;
label_1e568c:
    // 0x1e568c: 0x27c70018  addiu       $a3, $fp, 0x18
    ctx->pc = 0x1e568cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 30), 24));
    // 0x1e5690: 0x8ce60000  lw          $a2, 0x0($a3)
    ctx->pc = 0x1e5690u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x1e5694: 0x8fc40010  lw          $a0, 0x10($fp)
    ctx->pc = 0x1e5694u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e5698: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e5698u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e569c: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e569cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e56a0: 0x8c820004  lw          $v0, 0x4($a0)
    ctx->pc = 0x1e56a0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1e56a4: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e56a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e56a8: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e56a8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e56ac: 0x304400ff  andi        $a0, $v0, 0xFF
    ctx->pc = 0x1e56acu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1e56b0: 0x42600  sll         $a0, $a0, 24
    ctx->pc = 0x1e56b0u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 24));
    // 0x1e56b4: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e56b4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e56b8: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e56b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e56bc: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e56bcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e56c0: 0x8ca20004  lw          $v0, 0x4($a1)
    ctx->pc = 0x1e56c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 4)));
    // 0x1e56c4: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e56c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e56c8: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e56c8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e56cc: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1e56ccu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1e56d0: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1e56d0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1e56d4: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1e56d4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e56d8: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e56d8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e56dc: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e56dcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e56e0: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e56e0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e56e4: 0x8ca20004  lw          $v0, 0x4($a1)
    ctx->pc = 0x1e56e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 4)));
    // 0x1e56e8: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e56e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e56ec: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1e56ecu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e56f0: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1e56f0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1e56f4: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e56f4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e56f8: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1e56f8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1e56fc: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1e56fcu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e5700: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e5700u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e5704: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e5704u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e5708: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e5708u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e570c: 0x8ca20004  lw          $v0, 0x4($a1)
    ctx->pc = 0x1e570cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 4)));
    // 0x1e5710: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e5710u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e5714: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1e5714u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e5718: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1e5718u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1e571c: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e571cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e5720: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1e5720u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1e5724: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1e5724u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e5728: 0xacc40000  sw          $a0, 0x0($a2)
    ctx->pc = 0x1e5728u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 4));
    // 0x1e572c: 0x24c60004  addiu       $a2, $a2, 0x4
    ctx->pc = 0x1e572cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4));
    // 0x1e5730: 0xace60000  sw          $a2, 0x0($a3)
    ctx->pc = 0x1e5730u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 6));
    // 0x1e5734: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e5734u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e5738: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1e5738u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1e573c: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1e573cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1e5740: 0x1000ffca  b           . + 4 + (-0x36 << 2)
    ctx->pc = 0x1E5740u;
    {
        const bool branch_taken_0x1e5740 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5740) {
            ctx->pc = 0x1E566Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1e566c;
        }
    }
    ctx->pc = 0x1E5748u;
label_1e5748:
    // 0x1e5748: 0x8fc40018  lw          $a0, 0x18($fp)
    ctx->pc = 0x1e5748u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e574c: 0x8fc50008  lw          $a1, 0x8($fp)
    ctx->pc = 0x1e574cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e5750: 0x8fc6000c  lw          $a2, 0xC($fp)
    ctx->pc = 0x1e5750u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e5754: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1E5754u;
    SET_GPR_U32(ctx, 31, 0x1E575Cu);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E575Cu; }
        if (ctx->pc != 0x1E575Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E575Cu; }
        if (ctx->pc != 0x1E575Cu) { return; }
    }
    ctx->pc = 0x1E575Cu;
label_1e575c:
    // 0x1e575c: 0x97c20004  lhu         $v0, 0x4($fp)
    ctx->pc = 0x1e575cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e5760: 0x34422000  ori         $v0, $v0, 0x2000
    ctx->pc = 0x1e5760u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)8192);
    // 0x1e5764: 0x3046ffff  andi        $a2, $v0, 0xFFFF
    ctx->pc = 0x1e5764u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1e5768: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e5768u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e576c: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e576cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e5770: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1e5770u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e5774: 0x97c3000c  lhu         $v1, 0xC($fp)
    ctx->pc = 0x1e5774u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e5778: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e5778u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e577c: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1e577cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1e5780: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1e5780u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1e5784: 0x8fc4001c  lw          $a0, 0x1C($fp)
    ctx->pc = 0x1e5784u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e5788: 0x8fc50014  lw          $a1, 0x14($fp)
    ctx->pc = 0x1e5788u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e578c: 0x40382d  daddu       $a3, $v0, $zero
    ctx->pc = 0x1e578cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e5790: 0x24080010  addiu       $t0, $zero, 0x10
    ctx->pc = 0x1e5790u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1e5794: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1e5794u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e5798: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E5798u;
    SET_GPR_U32(ctx, 31, 0x1E57A0u);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E57A0u; }
        if (ctx->pc != 0x1E57A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E57A0u; }
        if (ctx->pc != 0x1E57A0u) { return; }
    }
    ctx->pc = 0x1E57A0u;
label_1e57a0:
    // 0x1e57a0: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E57A0u;
    {
        const bool branch_taken_0x1e57a0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e57a0) {
            ctx->pc = 0x1E57BCu;
            goto label_1e57bc;
        }
    }
    ctx->pc = 0x1E57A8u;
    // 0x1e57a8: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e57a8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e57ac: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e57acu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e57b0: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e57b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e57b4: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1E57B4u;
    {
        const bool branch_taken_0x1e57b4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e57b4) {
            ctx->pc = 0x1E57C0u;
            goto label_1e57c0;
        }
    }
    ctx->pc = 0x1E57BCu;
label_1e57bc:
    // 0x1e57bc: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1e57bcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1e57c0:
    // 0x1e57c0: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e57c0u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e57c4: 0xdfbe0030  ld          $fp, 0x30($sp)
    ctx->pc = 0x1e57c4u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1e57c8: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x1e57c8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x1e57cc: 0x27bd0040  addiu       $sp, $sp, 0x40
    ctx->pc = 0x1e57ccu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x1e57d0: 0x3e00008  jr          $ra
    ctx->pc = 0x1E57D0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E5060u: goto label_1e5060;
            case 0x1E5074u: goto label_1e5074;
            case 0x1E50B4u: goto label_1e50b4;
            case 0x1E50C4u: goto label_1e50c4;
            case 0x1E50E8u: goto label_1e50e8;
            case 0x1E50FCu: goto label_1e50fc;
            case 0x1E5120u: goto label_1e5120;
            case 0x1E5134u: goto label_1e5134;
            case 0x1E5148u: goto label_1e5148;
            case 0x1E5178u: goto label_1e5178;
            case 0x1E5194u: goto label_1e5194;
            case 0x1E5198u: goto label_1e5198;
            case 0x1E5238u: goto label_1e5238;
            case 0x1E524Cu: goto label_1e524c;
            case 0x1E528Cu: goto label_1e528c;
            case 0x1E52B0u: goto label_1e52b0;
            case 0x1E52D4u: goto label_1e52d4;
            case 0x1E530Cu: goto label_1e530c;
            case 0x1E536Cu: goto label_1e536c;
            case 0x1E5388u: goto label_1e5388;
            case 0x1E5410u: goto label_1e5410;
            case 0x1E5424u: goto label_1e5424;
            case 0x1E5464u: goto label_1e5464;
            case 0x1E5480u: goto label_1e5480;
            case 0x1E5484u: goto label_1e5484;
            case 0x1E54F8u: goto label_1e54f8;
            case 0x1E550Cu: goto label_1e550c;
            case 0x1E554Cu: goto label_1e554c;
            case 0x1E5574u: goto label_1e5574;
            case 0x1E5598u: goto label_1e5598;
            case 0x1E55C8u: goto label_1e55c8;
            case 0x1E55ECu: goto label_1e55ec;
            case 0x1E5600u: goto label_1e5600;
            case 0x1E566Cu: goto label_1e566c;
            case 0x1E568Cu: goto label_1e568c;
            case 0x1E5748u: goto label_1e5748;
            case 0x1E575Cu: goto label_1e575c;
            case 0x1E57A0u: goto label_1e57a0;
            case 0x1E57BCu: goto label_1e57bc;
            case 0x1E57C0u: goto label_1e57c0;
            case 0x1E5820u: goto label_1e5820;
            case 0x1E5834u: goto label_1e5834;
            case 0x1E5874u: goto label_1e5874;
            case 0x1E5884u: goto label_1e5884;
            case 0x1E58A8u: goto label_1e58a8;
            case 0x1E58C8u: goto label_1e58c8;
            case 0x1E58E4u: goto label_1e58e4;
            case 0x1E58E8u: goto label_1e58e8;
            case 0x1E5948u: goto label_1e5948;
            case 0x1E595Cu: goto label_1e595c;
            case 0x1E599Cu: goto label_1e599c;
            case 0x1E59ACu: goto label_1e59ac;
            case 0x1E59D0u: goto label_1e59d0;
            case 0x1E59F0u: goto label_1e59f0;
            case 0x1E5A0Cu: goto label_1e5a0c;
            case 0x1E5A10u: goto label_1e5a10;
            case 0x1E5A80u: goto label_1e5a80;
            case 0x1E5A94u: goto label_1e5a94;
            case 0x1E5AD4u: goto label_1e5ad4;
            case 0x1E5AE4u: goto label_1e5ae4;
            case 0x1E5B08u: goto label_1e5b08;
            case 0x1E5B1Cu: goto label_1e5b1c;
            case 0x1E5B40u: goto label_1e5b40;
            case 0x1E5B54u: goto label_1e5b54;
            case 0x1E5B68u: goto label_1e5b68;
            case 0x1E5B98u: goto label_1e5b98;
            case 0x1E5BB4u: goto label_1e5bb4;
            case 0x1E5BB8u: goto label_1e5bb8;
            case 0x1E5C2Cu: goto label_1e5c2c;
            case 0x1E5C40u: goto label_1e5c40;
            case 0x1E5C80u: goto label_1e5c80;
            case 0x1E5C90u: goto label_1e5c90;
            case 0x1E5CB4u: goto label_1e5cb4;
            case 0x1E5CC8u: goto label_1e5cc8;
            case 0x1E5CECu: goto label_1e5cec;
            case 0x1E5D00u: goto label_1e5d00;
            case 0x1E5D14u: goto label_1e5d14;
            case 0x1E5D48u: goto label_1e5d48;
            case 0x1E5D64u: goto label_1e5d64;
            case 0x1E5D78u: goto label_1e5d78;
            case 0x1E5D94u: goto label_1e5d94;
            case 0x1E5E04u: goto label_1e5e04;
            case 0x1E5E18u: goto label_1e5e18;
            case 0x1E5E58u: goto label_1e5e58;
            case 0x1E5E68u: goto label_1e5e68;
            case 0x1E5E8Cu: goto label_1e5e8c;
            case 0x1E5E9Cu: goto label_1e5e9c;
            case 0x1E5EB4u: goto label_1e5eb4;
            case 0x1E5F6Cu: goto label_1e5f6c;
            case 0x1E5F88u: goto label_1e5f88;
            case 0x1E5F9Cu: goto label_1e5f9c;
            case 0x1E5FA0u: goto label_1e5fa0;
            case 0x1E6008u: goto label_1e6008;
            case 0x1E601Cu: goto label_1e601c;
            case 0x1E605Cu: goto label_1e605c;
            case 0x1E6068u: goto label_1e6068;
            case 0x1E6084u: goto label_1e6084;
            case 0x1E6094u: goto label_1e6094;
            case 0x1E60B8u: goto label_1e60b8;
            case 0x1E60CCu: goto label_1e60cc;
            case 0x1E60F0u: goto label_1e60f0;
            case 0x1E6104u: goto label_1e6104;
            case 0x1E6118u: goto label_1e6118;
            case 0x1E613Cu: goto label_1e613c;
            case 0x1E6158u: goto label_1e6158;
            case 0x1E616Cu: goto label_1e616c;
            case 0x1E6170u: goto label_1e6170;
            case 0x1E61D4u: goto label_1e61d4;
            case 0x1E61E8u: goto label_1e61e8;
            case 0x1E6228u: goto label_1e6228;
            case 0x1E623Cu: goto label_1e623c;
            case 0x1E6240u: goto label_1e6240;
            case 0x1E62A4u: goto label_1e62a4;
            case 0x1E62B8u: goto label_1e62b8;
            case 0x1E62F8u: goto label_1e62f8;
            case 0x1E630Cu: goto label_1e630c;
            case 0x1E6310u: goto label_1e6310;
            case 0x1E6374u: goto label_1e6374;
            case 0x1E6388u: goto label_1e6388;
            case 0x1E63C8u: goto label_1e63c8;
            case 0x1E63DCu: goto label_1e63dc;
            case 0x1E63E0u: goto label_1e63e0;
            case 0x1E6448u: goto label_1e6448;
            case 0x1E645Cu: goto label_1e645c;
            case 0x1E649Cu: goto label_1e649c;
            case 0x1E64B4u: goto label_1e64b4;
            case 0x1E64C4u: goto label_1e64c4;
            case 0x1E64E8u: goto label_1e64e8;
            case 0x1E64FCu: goto label_1e64fc;
            case 0x1E6520u: goto label_1e6520;
            case 0x1E6534u: goto label_1e6534;
            case 0x1E6548u: goto label_1e6548;
            case 0x1E656Cu: goto label_1e656c;
            case 0x1E6588u: goto label_1e6588;
            case 0x1E658Cu: goto label_1e658c;
            case 0x1E65F8u: goto label_1e65f8;
            case 0x1E660Cu: goto label_1e660c;
            case 0x1E664Cu: goto label_1e664c;
            case 0x1E6664u: goto label_1e6664;
            case 0x1E6674u: goto label_1e6674;
            case 0x1E6698u: goto label_1e6698;
            case 0x1E66ACu: goto label_1e66ac;
            case 0x1E66D0u: goto label_1e66d0;
            case 0x1E66E4u: goto label_1e66e4;
            case 0x1E66FCu: goto label_1e66fc;
            case 0x1E6718u: goto label_1e6718;
            case 0x1E6744u: goto label_1e6744;
            case 0x1E6760u: goto label_1e6760;
            case 0x1E6764u: goto label_1e6764;
            case 0x1E67D0u: goto label_1e67d0;
            case 0x1E67E4u: goto label_1e67e4;
            case 0x1E6824u: goto label_1e6824;
            case 0x1E6834u: goto label_1e6834;
            case 0x1E6858u: goto label_1e6858;
            case 0x1E6868u: goto label_1e6868;
            case 0x1E688Cu: goto label_1e688c;
            case 0x1E68A0u: goto label_1e68a0;
            case 0x1E68ACu: goto label_1e68ac;
            case 0x1E68BCu: goto label_1e68bc;
            case 0x1E68D4u: goto label_1e68d4;
            case 0x1E6904u: goto label_1e6904;
            case 0x1E6970u: goto label_1e6970;
            case 0x1E6988u: goto label_1e6988;
            case 0x1E699Cu: goto label_1e699c;
            case 0x1E69B0u: goto label_1e69b0;
            case 0x1E69BCu: goto label_1e69bc;
            case 0x1E69D0u: goto label_1e69d0;
            case 0x1E69F4u: goto label_1e69f4;
            case 0x1E6A08u: goto label_1e6a08;
            case 0x1E6A30u: goto label_1e6a30;
            case 0x1E6A4Cu: goto label_1e6a4c;
            case 0x1E6AC8u: goto label_1e6ac8;
            case 0x1E6AE0u: goto label_1e6ae0;
            case 0x1E6AF4u: goto label_1e6af4;
            case 0x1E6B24u: goto label_1e6b24;
            case 0x1E6B38u: goto label_1e6b38;
            case 0x1E6B6Cu: goto label_1e6b6c;
            case 0x1E6B88u: goto label_1e6b88;
            case 0x1E6BCCu: goto label_1e6bcc;
            case 0x1E6BE8u: goto label_1e6be8;
            case 0x1E6BFCu: goto label_1e6bfc;
            case 0x1E6C30u: goto label_1e6c30;
            case 0x1E6C4Cu: goto label_1e6c4c;
            case 0x1E6C58u: goto label_1e6c58;
            case 0x1E6C6Cu: goto label_1e6c6c;
            case 0x1E6C84u: goto label_1e6c84;
            case 0x1E6CB4u: goto label_1e6cb4;
            case 0x1E6CD8u: goto label_1e6cd8;
            case 0x1E6CECu: goto label_1e6cec;
            case 0x1E6CF0u: goto label_1e6cf0;
            case 0x1E6D5Cu: goto label_1e6d5c;
            case 0x1E6D70u: goto label_1e6d70;
            case 0x1E6DB0u: goto label_1e6db0;
            case 0x1E6DC0u: goto label_1e6dc0;
            case 0x1E6DE4u: goto label_1e6de4;
            case 0x1E6DF4u: goto label_1e6df4;
            case 0x1E6E18u: goto label_1e6e18;
            case 0x1E6E2Cu: goto label_1e6e2c;
            case 0x1E6E38u: goto label_1e6e38;
            case 0x1E6E48u: goto label_1e6e48;
            case 0x1E6E60u: goto label_1e6e60;
            case 0x1E6E90u: goto label_1e6e90;
            case 0x1E6EFCu: goto label_1e6efc;
            case 0x1E6F14u: goto label_1e6f14;
            case 0x1E6F28u: goto label_1e6f28;
            case 0x1E6F3Cu: goto label_1e6f3c;
            case 0x1E6F48u: goto label_1e6f48;
            case 0x1E6F5Cu: goto label_1e6f5c;
            case 0x1E6F80u: goto label_1e6f80;
            case 0x1E6F94u: goto label_1e6f94;
            case 0x1E6FBCu: goto label_1e6fbc;
            case 0x1E6FD8u: goto label_1e6fd8;
            case 0x1E7054u: goto label_1e7054;
            case 0x1E706Cu: goto label_1e706c;
            case 0x1E7080u: goto label_1e7080;
            case 0x1E70B0u: goto label_1e70b0;
            case 0x1E70C4u: goto label_1e70c4;
            case 0x1E70F8u: goto label_1e70f8;
            case 0x1E7114u: goto label_1e7114;
            case 0x1E7158u: goto label_1e7158;
            case 0x1E7174u: goto label_1e7174;
            case 0x1E7188u: goto label_1e7188;
            case 0x1E71BCu: goto label_1e71bc;
            case 0x1E71D8u: goto label_1e71d8;
            case 0x1E71E4u: goto label_1e71e4;
            case 0x1E71F8u: goto label_1e71f8;
            case 0x1E7210u: goto label_1e7210;
            case 0x1E7240u: goto label_1e7240;
            case 0x1E7264u: goto label_1e7264;
            case 0x1E7278u: goto label_1e7278;
            case 0x1E727Cu: goto label_1e727c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E57D8u;
    // 0x1e57d8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1e57d8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1e57dc: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1e57dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1e57e0: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1e57e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1e57e4: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e57e4u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e57e8: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e57e8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e57ec: 0xafc00008  sw          $zero, 0x8($fp)
    ctx->pc = 0x1e57ecu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 0));
    // 0x1e57f0: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e57f0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e57f4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e57f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e57f8: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E57F8u;
    {
        const bool branch_taken_0x1e57f8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e57f8) {
            ctx->pc = 0x1E5820u;
            goto label_1e5820;
        }
    }
    ctx->pc = 0x1E5800u;
    // 0x1e5800: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e5800u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e5804: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e5804u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e5808: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e5808u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e580c: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e580cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e5810: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e5810u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e5814: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e5814u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e5818: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E5818u;
    {
        const bool branch_taken_0x1e5818 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e5818) {
            ctx->pc = 0x1E5834u;
            goto label_1e5834;
        }
    }
    ctx->pc = 0x1E5820u;
label_1e5820:
    // 0x1e5820: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e5820u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e5824: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e5824u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e5828: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e5828u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e582c: 0x1000002e  b           . + 4 + (0x2E << 2)
    ctx->pc = 0x1E582Cu;
    {
        const bool branch_taken_0x1e582c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e582c) {
            ctx->pc = 0x1E58E8u;
            goto label_1e58e8;
        }
    }
    ctx->pc = 0x1E5834u;
label_1e5834:
    // 0x1e5834: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e5834u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e5838: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e5838u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e583c: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e583cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e5840: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e5840u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e5844: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e5844u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e5848: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e5848u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e584c: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1e584cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1e5850: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1e5850u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e5854: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e5854u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e5858: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E5858u;
    {
        const bool branch_taken_0x1e5858 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5858) {
            ctx->pc = 0x1E5874u;
            goto label_1e5874;
        }
    }
    ctx->pc = 0x1E5860u;
    // 0x1e5860: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e5860u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e5864: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e5864u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e5868: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e5868u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e586c: 0x1000001e  b           . + 4 + (0x1E << 2)
    ctx->pc = 0x1E586Cu;
    {
        const bool branch_taken_0x1e586c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e586c) {
            ctx->pc = 0x1E58E8u;
            goto label_1e58e8;
        }
    }
    ctx->pc = 0x1E5874u;
label_1e5874:
    // 0x1e5874: 0x8fc40008  lw          $a0, 0x8($fp)
    ctx->pc = 0x1e5874u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e5878: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1e5878u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e587c: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E587Cu;
    SET_GPR_U32(ctx, 31, 0x1E5884u);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5884u; }
        if (ctx->pc != 0x1E5884u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5884u; }
        if (ctx->pc != 0x1E5884u) { return; }
    }
    ctx->pc = 0x1E5884u;
label_1e5884:
    // 0x1e5884: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1e5884u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
    // 0x1e5888: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e5888u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e588c: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E588Cu;
    {
        const bool branch_taken_0x1e588c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e588c) {
            ctx->pc = 0x1E58A8u;
            goto label_1e58a8;
        }
    }
    ctx->pc = 0x1E5894u;
    // 0x1e5894: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e5894u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e5898: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e5898u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e589c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e589cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e58a0: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x1E58A0u;
    {
        const bool branch_taken_0x1e58a0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e58a0) {
            ctx->pc = 0x1E58E8u;
            goto label_1e58e8;
        }
    }
    ctx->pc = 0x1E58A8u;
label_1e58a8:
    // 0x1e58a8: 0x8fc40008  lw          $a0, 0x8($fp)
    ctx->pc = 0x1e58a8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e58ac: 0x8fc50004  lw          $a1, 0x4($fp)
    ctx->pc = 0x1e58acu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e58b0: 0x24062000  addiu       $a2, $zero, 0x2000
    ctx->pc = 0x1e58b0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 8192));
    // 0x1e58b4: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1e58b4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e58b8: 0x24080012  addiu       $t0, $zero, 0x12
    ctx->pc = 0x1e58b8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 18));
    // 0x1e58bc: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1e58bcu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e58c0: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E58C0u;
    SET_GPR_U32(ctx, 31, 0x1E58C8u);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E58C8u; }
        if (ctx->pc != 0x1E58C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E58C8u; }
        if (ctx->pc != 0x1E58C8u) { return; }
    }
    ctx->pc = 0x1E58C8u;
label_1e58c8:
    // 0x1e58c8: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E58C8u;
    {
        const bool branch_taken_0x1e58c8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e58c8) {
            ctx->pc = 0x1E58E4u;
            goto label_1e58e4;
        }
    }
    ctx->pc = 0x1E58D0u;
    // 0x1e58d0: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e58d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e58d4: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e58d4u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e58d8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e58d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e58dc: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1E58DCu;
    {
        const bool branch_taken_0x1e58dc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e58dc) {
            ctx->pc = 0x1E58E8u;
            goto label_1e58e8;
        }
    }
    ctx->pc = 0x1E58E4u;
label_1e58e4:
    // 0x1e58e4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1e58e4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1e58e8:
    // 0x1e58e8: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e58e8u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e58ec: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1e58ecu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1e58f0: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1e58f0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1e58f4: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1e58f4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1e58f8: 0x3e00008  jr          $ra
    ctx->pc = 0x1E58F8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E5060u: goto label_1e5060;
            case 0x1E5074u: goto label_1e5074;
            case 0x1E50B4u: goto label_1e50b4;
            case 0x1E50C4u: goto label_1e50c4;
            case 0x1E50E8u: goto label_1e50e8;
            case 0x1E50FCu: goto label_1e50fc;
            case 0x1E5120u: goto label_1e5120;
            case 0x1E5134u: goto label_1e5134;
            case 0x1E5148u: goto label_1e5148;
            case 0x1E5178u: goto label_1e5178;
            case 0x1E5194u: goto label_1e5194;
            case 0x1E5198u: goto label_1e5198;
            case 0x1E5238u: goto label_1e5238;
            case 0x1E524Cu: goto label_1e524c;
            case 0x1E528Cu: goto label_1e528c;
            case 0x1E52B0u: goto label_1e52b0;
            case 0x1E52D4u: goto label_1e52d4;
            case 0x1E530Cu: goto label_1e530c;
            case 0x1E536Cu: goto label_1e536c;
            case 0x1E5388u: goto label_1e5388;
            case 0x1E5410u: goto label_1e5410;
            case 0x1E5424u: goto label_1e5424;
            case 0x1E5464u: goto label_1e5464;
            case 0x1E5480u: goto label_1e5480;
            case 0x1E5484u: goto label_1e5484;
            case 0x1E54F8u: goto label_1e54f8;
            case 0x1E550Cu: goto label_1e550c;
            case 0x1E554Cu: goto label_1e554c;
            case 0x1E5574u: goto label_1e5574;
            case 0x1E5598u: goto label_1e5598;
            case 0x1E55C8u: goto label_1e55c8;
            case 0x1E55ECu: goto label_1e55ec;
            case 0x1E5600u: goto label_1e5600;
            case 0x1E566Cu: goto label_1e566c;
            case 0x1E568Cu: goto label_1e568c;
            case 0x1E5748u: goto label_1e5748;
            case 0x1E575Cu: goto label_1e575c;
            case 0x1E57A0u: goto label_1e57a0;
            case 0x1E57BCu: goto label_1e57bc;
            case 0x1E57C0u: goto label_1e57c0;
            case 0x1E5820u: goto label_1e5820;
            case 0x1E5834u: goto label_1e5834;
            case 0x1E5874u: goto label_1e5874;
            case 0x1E5884u: goto label_1e5884;
            case 0x1E58A8u: goto label_1e58a8;
            case 0x1E58C8u: goto label_1e58c8;
            case 0x1E58E4u: goto label_1e58e4;
            case 0x1E58E8u: goto label_1e58e8;
            case 0x1E5948u: goto label_1e5948;
            case 0x1E595Cu: goto label_1e595c;
            case 0x1E599Cu: goto label_1e599c;
            case 0x1E59ACu: goto label_1e59ac;
            case 0x1E59D0u: goto label_1e59d0;
            case 0x1E59F0u: goto label_1e59f0;
            case 0x1E5A0Cu: goto label_1e5a0c;
            case 0x1E5A10u: goto label_1e5a10;
            case 0x1E5A80u: goto label_1e5a80;
            case 0x1E5A94u: goto label_1e5a94;
            case 0x1E5AD4u: goto label_1e5ad4;
            case 0x1E5AE4u: goto label_1e5ae4;
            case 0x1E5B08u: goto label_1e5b08;
            case 0x1E5B1Cu: goto label_1e5b1c;
            case 0x1E5B40u: goto label_1e5b40;
            case 0x1E5B54u: goto label_1e5b54;
            case 0x1E5B68u: goto label_1e5b68;
            case 0x1E5B98u: goto label_1e5b98;
            case 0x1E5BB4u: goto label_1e5bb4;
            case 0x1E5BB8u: goto label_1e5bb8;
            case 0x1E5C2Cu: goto label_1e5c2c;
            case 0x1E5C40u: goto label_1e5c40;
            case 0x1E5C80u: goto label_1e5c80;
            case 0x1E5C90u: goto label_1e5c90;
            case 0x1E5CB4u: goto label_1e5cb4;
            case 0x1E5CC8u: goto label_1e5cc8;
            case 0x1E5CECu: goto label_1e5cec;
            case 0x1E5D00u: goto label_1e5d00;
            case 0x1E5D14u: goto label_1e5d14;
            case 0x1E5D48u: goto label_1e5d48;
            case 0x1E5D64u: goto label_1e5d64;
            case 0x1E5D78u: goto label_1e5d78;
            case 0x1E5D94u: goto label_1e5d94;
            case 0x1E5E04u: goto label_1e5e04;
            case 0x1E5E18u: goto label_1e5e18;
            case 0x1E5E58u: goto label_1e5e58;
            case 0x1E5E68u: goto label_1e5e68;
            case 0x1E5E8Cu: goto label_1e5e8c;
            case 0x1E5E9Cu: goto label_1e5e9c;
            case 0x1E5EB4u: goto label_1e5eb4;
            case 0x1E5F6Cu: goto label_1e5f6c;
            case 0x1E5F88u: goto label_1e5f88;
            case 0x1E5F9Cu: goto label_1e5f9c;
            case 0x1E5FA0u: goto label_1e5fa0;
            case 0x1E6008u: goto label_1e6008;
            case 0x1E601Cu: goto label_1e601c;
            case 0x1E605Cu: goto label_1e605c;
            case 0x1E6068u: goto label_1e6068;
            case 0x1E6084u: goto label_1e6084;
            case 0x1E6094u: goto label_1e6094;
            case 0x1E60B8u: goto label_1e60b8;
            case 0x1E60CCu: goto label_1e60cc;
            case 0x1E60F0u: goto label_1e60f0;
            case 0x1E6104u: goto label_1e6104;
            case 0x1E6118u: goto label_1e6118;
            case 0x1E613Cu: goto label_1e613c;
            case 0x1E6158u: goto label_1e6158;
            case 0x1E616Cu: goto label_1e616c;
            case 0x1E6170u: goto label_1e6170;
            case 0x1E61D4u: goto label_1e61d4;
            case 0x1E61E8u: goto label_1e61e8;
            case 0x1E6228u: goto label_1e6228;
            case 0x1E623Cu: goto label_1e623c;
            case 0x1E6240u: goto label_1e6240;
            case 0x1E62A4u: goto label_1e62a4;
            case 0x1E62B8u: goto label_1e62b8;
            case 0x1E62F8u: goto label_1e62f8;
            case 0x1E630Cu: goto label_1e630c;
            case 0x1E6310u: goto label_1e6310;
            case 0x1E6374u: goto label_1e6374;
            case 0x1E6388u: goto label_1e6388;
            case 0x1E63C8u: goto label_1e63c8;
            case 0x1E63DCu: goto label_1e63dc;
            case 0x1E63E0u: goto label_1e63e0;
            case 0x1E6448u: goto label_1e6448;
            case 0x1E645Cu: goto label_1e645c;
            case 0x1E649Cu: goto label_1e649c;
            case 0x1E64B4u: goto label_1e64b4;
            case 0x1E64C4u: goto label_1e64c4;
            case 0x1E64E8u: goto label_1e64e8;
            case 0x1E64FCu: goto label_1e64fc;
            case 0x1E6520u: goto label_1e6520;
            case 0x1E6534u: goto label_1e6534;
            case 0x1E6548u: goto label_1e6548;
            case 0x1E656Cu: goto label_1e656c;
            case 0x1E6588u: goto label_1e6588;
            case 0x1E658Cu: goto label_1e658c;
            case 0x1E65F8u: goto label_1e65f8;
            case 0x1E660Cu: goto label_1e660c;
            case 0x1E664Cu: goto label_1e664c;
            case 0x1E6664u: goto label_1e6664;
            case 0x1E6674u: goto label_1e6674;
            case 0x1E6698u: goto label_1e6698;
            case 0x1E66ACu: goto label_1e66ac;
            case 0x1E66D0u: goto label_1e66d0;
            case 0x1E66E4u: goto label_1e66e4;
            case 0x1E66FCu: goto label_1e66fc;
            case 0x1E6718u: goto label_1e6718;
            case 0x1E6744u: goto label_1e6744;
            case 0x1E6760u: goto label_1e6760;
            case 0x1E6764u: goto label_1e6764;
            case 0x1E67D0u: goto label_1e67d0;
            case 0x1E67E4u: goto label_1e67e4;
            case 0x1E6824u: goto label_1e6824;
            case 0x1E6834u: goto label_1e6834;
            case 0x1E6858u: goto label_1e6858;
            case 0x1E6868u: goto label_1e6868;
            case 0x1E688Cu: goto label_1e688c;
            case 0x1E68A0u: goto label_1e68a0;
            case 0x1E68ACu: goto label_1e68ac;
            case 0x1E68BCu: goto label_1e68bc;
            case 0x1E68D4u: goto label_1e68d4;
            case 0x1E6904u: goto label_1e6904;
            case 0x1E6970u: goto label_1e6970;
            case 0x1E6988u: goto label_1e6988;
            case 0x1E699Cu: goto label_1e699c;
            case 0x1E69B0u: goto label_1e69b0;
            case 0x1E69BCu: goto label_1e69bc;
            case 0x1E69D0u: goto label_1e69d0;
            case 0x1E69F4u: goto label_1e69f4;
            case 0x1E6A08u: goto label_1e6a08;
            case 0x1E6A30u: goto label_1e6a30;
            case 0x1E6A4Cu: goto label_1e6a4c;
            case 0x1E6AC8u: goto label_1e6ac8;
            case 0x1E6AE0u: goto label_1e6ae0;
            case 0x1E6AF4u: goto label_1e6af4;
            case 0x1E6B24u: goto label_1e6b24;
            case 0x1E6B38u: goto label_1e6b38;
            case 0x1E6B6Cu: goto label_1e6b6c;
            case 0x1E6B88u: goto label_1e6b88;
            case 0x1E6BCCu: goto label_1e6bcc;
            case 0x1E6BE8u: goto label_1e6be8;
            case 0x1E6BFCu: goto label_1e6bfc;
            case 0x1E6C30u: goto label_1e6c30;
            case 0x1E6C4Cu: goto label_1e6c4c;
            case 0x1E6C58u: goto label_1e6c58;
            case 0x1E6C6Cu: goto label_1e6c6c;
            case 0x1E6C84u: goto label_1e6c84;
            case 0x1E6CB4u: goto label_1e6cb4;
            case 0x1E6CD8u: goto label_1e6cd8;
            case 0x1E6CECu: goto label_1e6cec;
            case 0x1E6CF0u: goto label_1e6cf0;
            case 0x1E6D5Cu: goto label_1e6d5c;
            case 0x1E6D70u: goto label_1e6d70;
            case 0x1E6DB0u: goto label_1e6db0;
            case 0x1E6DC0u: goto label_1e6dc0;
            case 0x1E6DE4u: goto label_1e6de4;
            case 0x1E6DF4u: goto label_1e6df4;
            case 0x1E6E18u: goto label_1e6e18;
            case 0x1E6E2Cu: goto label_1e6e2c;
            case 0x1E6E38u: goto label_1e6e38;
            case 0x1E6E48u: goto label_1e6e48;
            case 0x1E6E60u: goto label_1e6e60;
            case 0x1E6E90u: goto label_1e6e90;
            case 0x1E6EFCu: goto label_1e6efc;
            case 0x1E6F14u: goto label_1e6f14;
            case 0x1E6F28u: goto label_1e6f28;
            case 0x1E6F3Cu: goto label_1e6f3c;
            case 0x1E6F48u: goto label_1e6f48;
            case 0x1E6F5Cu: goto label_1e6f5c;
            case 0x1E6F80u: goto label_1e6f80;
            case 0x1E6F94u: goto label_1e6f94;
            case 0x1E6FBCu: goto label_1e6fbc;
            case 0x1E6FD8u: goto label_1e6fd8;
            case 0x1E7054u: goto label_1e7054;
            case 0x1E706Cu: goto label_1e706c;
            case 0x1E7080u: goto label_1e7080;
            case 0x1E70B0u: goto label_1e70b0;
            case 0x1E70C4u: goto label_1e70c4;
            case 0x1E70F8u: goto label_1e70f8;
            case 0x1E7114u: goto label_1e7114;
            case 0x1E7158u: goto label_1e7158;
            case 0x1E7174u: goto label_1e7174;
            case 0x1E7188u: goto label_1e7188;
            case 0x1E71BCu: goto label_1e71bc;
            case 0x1E71D8u: goto label_1e71d8;
            case 0x1E71E4u: goto label_1e71e4;
            case 0x1E71F8u: goto label_1e71f8;
            case 0x1E7210u: goto label_1e7210;
            case 0x1E7240u: goto label_1e7240;
            case 0x1E7264u: goto label_1e7264;
            case 0x1E7278u: goto label_1e7278;
            case 0x1E727Cu: goto label_1e727c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E5900u;
    // 0x1e5900: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1e5900u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1e5904: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1e5904u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1e5908: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1e5908u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1e590c: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e590cu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e5910: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e5910u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e5914: 0xafc00008  sw          $zero, 0x8($fp)
    ctx->pc = 0x1e5914u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 0));
    // 0x1e5918: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e5918u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e591c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e591cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e5920: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E5920u;
    {
        const bool branch_taken_0x1e5920 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e5920) {
            ctx->pc = 0x1E5948u;
            goto label_1e5948;
        }
    }
    ctx->pc = 0x1E5928u;
    // 0x1e5928: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e5928u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e592c: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e592cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e5930: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e5930u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e5934: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e5934u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e5938: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e5938u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e593c: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e593cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e5940: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E5940u;
    {
        const bool branch_taken_0x1e5940 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e5940) {
            ctx->pc = 0x1E595Cu;
            goto label_1e595c;
        }
    }
    ctx->pc = 0x1E5948u;
label_1e5948:
    // 0x1e5948: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e5948u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e594c: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e594cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e5950: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e5950u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e5954: 0x1000002e  b           . + 4 + (0x2E << 2)
    ctx->pc = 0x1E5954u;
    {
        const bool branch_taken_0x1e5954 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5954) {
            ctx->pc = 0x1E5A10u;
            goto label_1e5a10;
        }
    }
    ctx->pc = 0x1E595Cu;
label_1e595c:
    // 0x1e595c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e595cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e5960: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e5960u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e5964: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e5964u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e5968: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e5968u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e596c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e596cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e5970: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e5970u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e5974: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1e5974u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1e5978: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1e5978u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e597c: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e597cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e5980: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E5980u;
    {
        const bool branch_taken_0x1e5980 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5980) {
            ctx->pc = 0x1E599Cu;
            goto label_1e599c;
        }
    }
    ctx->pc = 0x1E5988u;
    // 0x1e5988: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e5988u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e598c: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e598cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e5990: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e5990u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e5994: 0x1000001e  b           . + 4 + (0x1E << 2)
    ctx->pc = 0x1E5994u;
    {
        const bool branch_taken_0x1e5994 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5994) {
            ctx->pc = 0x1E5A10u;
            goto label_1e5a10;
        }
    }
    ctx->pc = 0x1E599Cu;
label_1e599c:
    // 0x1e599c: 0x8fc40008  lw          $a0, 0x8($fp)
    ctx->pc = 0x1e599cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e59a0: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1e59a0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e59a4: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E59A4u;
    SET_GPR_U32(ctx, 31, 0x1E59ACu);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E59ACu; }
        if (ctx->pc != 0x1E59ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E59ACu; }
        if (ctx->pc != 0x1E59ACu) { return; }
    }
    ctx->pc = 0x1E59ACu;
label_1e59ac:
    // 0x1e59ac: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1e59acu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
    // 0x1e59b0: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e59b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e59b4: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E59B4u;
    {
        const bool branch_taken_0x1e59b4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e59b4) {
            ctx->pc = 0x1E59D0u;
            goto label_1e59d0;
        }
    }
    ctx->pc = 0x1E59BCu;
    // 0x1e59bc: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e59bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e59c0: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e59c0u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e59c4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e59c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e59c8: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x1E59C8u;
    {
        const bool branch_taken_0x1e59c8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e59c8) {
            ctx->pc = 0x1E5A10u;
            goto label_1e5a10;
        }
    }
    ctx->pc = 0x1E59D0u;
label_1e59d0:
    // 0x1e59d0: 0x8fc40008  lw          $a0, 0x8($fp)
    ctx->pc = 0x1e59d0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e59d4: 0x8fc50004  lw          $a1, 0x4($fp)
    ctx->pc = 0x1e59d4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e59d8: 0x24062000  addiu       $a2, $zero, 0x2000
    ctx->pc = 0x1e59d8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 8192));
    // 0x1e59dc: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1e59dcu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e59e0: 0x24080013  addiu       $t0, $zero, 0x13
    ctx->pc = 0x1e59e0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 19));
    // 0x1e59e4: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1e59e4u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e59e8: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E59E8u;
    SET_GPR_U32(ctx, 31, 0x1E59F0u);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E59F0u; }
        if (ctx->pc != 0x1E59F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E59F0u; }
        if (ctx->pc != 0x1E59F0u) { return; }
    }
    ctx->pc = 0x1E59F0u;
label_1e59f0:
    // 0x1e59f0: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E59F0u;
    {
        const bool branch_taken_0x1e59f0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e59f0) {
            ctx->pc = 0x1E5A0Cu;
            goto label_1e5a0c;
        }
    }
    ctx->pc = 0x1E59F8u;
    // 0x1e59f8: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e59f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e59fc: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e59fcu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e5a00: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e5a00u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e5a04: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1E5A04u;
    {
        const bool branch_taken_0x1e5a04 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5a04) {
            ctx->pc = 0x1E5A10u;
            goto label_1e5a10;
        }
    }
    ctx->pc = 0x1E5A0Cu;
label_1e5a0c:
    // 0x1e5a0c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1e5a0cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1e5a10:
    // 0x1e5a10: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e5a10u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e5a14: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1e5a14u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1e5a18: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1e5a18u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1e5a1c: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1e5a1cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1e5a20: 0x3e00008  jr          $ra
    ctx->pc = 0x1E5A20u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E5060u: goto label_1e5060;
            case 0x1E5074u: goto label_1e5074;
            case 0x1E50B4u: goto label_1e50b4;
            case 0x1E50C4u: goto label_1e50c4;
            case 0x1E50E8u: goto label_1e50e8;
            case 0x1E50FCu: goto label_1e50fc;
            case 0x1E5120u: goto label_1e5120;
            case 0x1E5134u: goto label_1e5134;
            case 0x1E5148u: goto label_1e5148;
            case 0x1E5178u: goto label_1e5178;
            case 0x1E5194u: goto label_1e5194;
            case 0x1E5198u: goto label_1e5198;
            case 0x1E5238u: goto label_1e5238;
            case 0x1E524Cu: goto label_1e524c;
            case 0x1E528Cu: goto label_1e528c;
            case 0x1E52B0u: goto label_1e52b0;
            case 0x1E52D4u: goto label_1e52d4;
            case 0x1E530Cu: goto label_1e530c;
            case 0x1E536Cu: goto label_1e536c;
            case 0x1E5388u: goto label_1e5388;
            case 0x1E5410u: goto label_1e5410;
            case 0x1E5424u: goto label_1e5424;
            case 0x1E5464u: goto label_1e5464;
            case 0x1E5480u: goto label_1e5480;
            case 0x1E5484u: goto label_1e5484;
            case 0x1E54F8u: goto label_1e54f8;
            case 0x1E550Cu: goto label_1e550c;
            case 0x1E554Cu: goto label_1e554c;
            case 0x1E5574u: goto label_1e5574;
            case 0x1E5598u: goto label_1e5598;
            case 0x1E55C8u: goto label_1e55c8;
            case 0x1E55ECu: goto label_1e55ec;
            case 0x1E5600u: goto label_1e5600;
            case 0x1E566Cu: goto label_1e566c;
            case 0x1E568Cu: goto label_1e568c;
            case 0x1E5748u: goto label_1e5748;
            case 0x1E575Cu: goto label_1e575c;
            case 0x1E57A0u: goto label_1e57a0;
            case 0x1E57BCu: goto label_1e57bc;
            case 0x1E57C0u: goto label_1e57c0;
            case 0x1E5820u: goto label_1e5820;
            case 0x1E5834u: goto label_1e5834;
            case 0x1E5874u: goto label_1e5874;
            case 0x1E5884u: goto label_1e5884;
            case 0x1E58A8u: goto label_1e58a8;
            case 0x1E58C8u: goto label_1e58c8;
            case 0x1E58E4u: goto label_1e58e4;
            case 0x1E58E8u: goto label_1e58e8;
            case 0x1E5948u: goto label_1e5948;
            case 0x1E595Cu: goto label_1e595c;
            case 0x1E599Cu: goto label_1e599c;
            case 0x1E59ACu: goto label_1e59ac;
            case 0x1E59D0u: goto label_1e59d0;
            case 0x1E59F0u: goto label_1e59f0;
            case 0x1E5A0Cu: goto label_1e5a0c;
            case 0x1E5A10u: goto label_1e5a10;
            case 0x1E5A80u: goto label_1e5a80;
            case 0x1E5A94u: goto label_1e5a94;
            case 0x1E5AD4u: goto label_1e5ad4;
            case 0x1E5AE4u: goto label_1e5ae4;
            case 0x1E5B08u: goto label_1e5b08;
            case 0x1E5B1Cu: goto label_1e5b1c;
            case 0x1E5B40u: goto label_1e5b40;
            case 0x1E5B54u: goto label_1e5b54;
            case 0x1E5B68u: goto label_1e5b68;
            case 0x1E5B98u: goto label_1e5b98;
            case 0x1E5BB4u: goto label_1e5bb4;
            case 0x1E5BB8u: goto label_1e5bb8;
            case 0x1E5C2Cu: goto label_1e5c2c;
            case 0x1E5C40u: goto label_1e5c40;
            case 0x1E5C80u: goto label_1e5c80;
            case 0x1E5C90u: goto label_1e5c90;
            case 0x1E5CB4u: goto label_1e5cb4;
            case 0x1E5CC8u: goto label_1e5cc8;
            case 0x1E5CECu: goto label_1e5cec;
            case 0x1E5D00u: goto label_1e5d00;
            case 0x1E5D14u: goto label_1e5d14;
            case 0x1E5D48u: goto label_1e5d48;
            case 0x1E5D64u: goto label_1e5d64;
            case 0x1E5D78u: goto label_1e5d78;
            case 0x1E5D94u: goto label_1e5d94;
            case 0x1E5E04u: goto label_1e5e04;
            case 0x1E5E18u: goto label_1e5e18;
            case 0x1E5E58u: goto label_1e5e58;
            case 0x1E5E68u: goto label_1e5e68;
            case 0x1E5E8Cu: goto label_1e5e8c;
            case 0x1E5E9Cu: goto label_1e5e9c;
            case 0x1E5EB4u: goto label_1e5eb4;
            case 0x1E5F6Cu: goto label_1e5f6c;
            case 0x1E5F88u: goto label_1e5f88;
            case 0x1E5F9Cu: goto label_1e5f9c;
            case 0x1E5FA0u: goto label_1e5fa0;
            case 0x1E6008u: goto label_1e6008;
            case 0x1E601Cu: goto label_1e601c;
            case 0x1E605Cu: goto label_1e605c;
            case 0x1E6068u: goto label_1e6068;
            case 0x1E6084u: goto label_1e6084;
            case 0x1E6094u: goto label_1e6094;
            case 0x1E60B8u: goto label_1e60b8;
            case 0x1E60CCu: goto label_1e60cc;
            case 0x1E60F0u: goto label_1e60f0;
            case 0x1E6104u: goto label_1e6104;
            case 0x1E6118u: goto label_1e6118;
            case 0x1E613Cu: goto label_1e613c;
            case 0x1E6158u: goto label_1e6158;
            case 0x1E616Cu: goto label_1e616c;
            case 0x1E6170u: goto label_1e6170;
            case 0x1E61D4u: goto label_1e61d4;
            case 0x1E61E8u: goto label_1e61e8;
            case 0x1E6228u: goto label_1e6228;
            case 0x1E623Cu: goto label_1e623c;
            case 0x1E6240u: goto label_1e6240;
            case 0x1E62A4u: goto label_1e62a4;
            case 0x1E62B8u: goto label_1e62b8;
            case 0x1E62F8u: goto label_1e62f8;
            case 0x1E630Cu: goto label_1e630c;
            case 0x1E6310u: goto label_1e6310;
            case 0x1E6374u: goto label_1e6374;
            case 0x1E6388u: goto label_1e6388;
            case 0x1E63C8u: goto label_1e63c8;
            case 0x1E63DCu: goto label_1e63dc;
            case 0x1E63E0u: goto label_1e63e0;
            case 0x1E6448u: goto label_1e6448;
            case 0x1E645Cu: goto label_1e645c;
            case 0x1E649Cu: goto label_1e649c;
            case 0x1E64B4u: goto label_1e64b4;
            case 0x1E64C4u: goto label_1e64c4;
            case 0x1E64E8u: goto label_1e64e8;
            case 0x1E64FCu: goto label_1e64fc;
            case 0x1E6520u: goto label_1e6520;
            case 0x1E6534u: goto label_1e6534;
            case 0x1E6548u: goto label_1e6548;
            case 0x1E656Cu: goto label_1e656c;
            case 0x1E6588u: goto label_1e6588;
            case 0x1E658Cu: goto label_1e658c;
            case 0x1E65F8u: goto label_1e65f8;
            case 0x1E660Cu: goto label_1e660c;
            case 0x1E664Cu: goto label_1e664c;
            case 0x1E6664u: goto label_1e6664;
            case 0x1E6674u: goto label_1e6674;
            case 0x1E6698u: goto label_1e6698;
            case 0x1E66ACu: goto label_1e66ac;
            case 0x1E66D0u: goto label_1e66d0;
            case 0x1E66E4u: goto label_1e66e4;
            case 0x1E66FCu: goto label_1e66fc;
            case 0x1E6718u: goto label_1e6718;
            case 0x1E6744u: goto label_1e6744;
            case 0x1E6760u: goto label_1e6760;
            case 0x1E6764u: goto label_1e6764;
            case 0x1E67D0u: goto label_1e67d0;
            case 0x1E67E4u: goto label_1e67e4;
            case 0x1E6824u: goto label_1e6824;
            case 0x1E6834u: goto label_1e6834;
            case 0x1E6858u: goto label_1e6858;
            case 0x1E6868u: goto label_1e6868;
            case 0x1E688Cu: goto label_1e688c;
            case 0x1E68A0u: goto label_1e68a0;
            case 0x1E68ACu: goto label_1e68ac;
            case 0x1E68BCu: goto label_1e68bc;
            case 0x1E68D4u: goto label_1e68d4;
            case 0x1E6904u: goto label_1e6904;
            case 0x1E6970u: goto label_1e6970;
            case 0x1E6988u: goto label_1e6988;
            case 0x1E699Cu: goto label_1e699c;
            case 0x1E69B0u: goto label_1e69b0;
            case 0x1E69BCu: goto label_1e69bc;
            case 0x1E69D0u: goto label_1e69d0;
            case 0x1E69F4u: goto label_1e69f4;
            case 0x1E6A08u: goto label_1e6a08;
            case 0x1E6A30u: goto label_1e6a30;
            case 0x1E6A4Cu: goto label_1e6a4c;
            case 0x1E6AC8u: goto label_1e6ac8;
            case 0x1E6AE0u: goto label_1e6ae0;
            case 0x1E6AF4u: goto label_1e6af4;
            case 0x1E6B24u: goto label_1e6b24;
            case 0x1E6B38u: goto label_1e6b38;
            case 0x1E6B6Cu: goto label_1e6b6c;
            case 0x1E6B88u: goto label_1e6b88;
            case 0x1E6BCCu: goto label_1e6bcc;
            case 0x1E6BE8u: goto label_1e6be8;
            case 0x1E6BFCu: goto label_1e6bfc;
            case 0x1E6C30u: goto label_1e6c30;
            case 0x1E6C4Cu: goto label_1e6c4c;
            case 0x1E6C58u: goto label_1e6c58;
            case 0x1E6C6Cu: goto label_1e6c6c;
            case 0x1E6C84u: goto label_1e6c84;
            case 0x1E6CB4u: goto label_1e6cb4;
            case 0x1E6CD8u: goto label_1e6cd8;
            case 0x1E6CECu: goto label_1e6cec;
            case 0x1E6CF0u: goto label_1e6cf0;
            case 0x1E6D5Cu: goto label_1e6d5c;
            case 0x1E6D70u: goto label_1e6d70;
            case 0x1E6DB0u: goto label_1e6db0;
            case 0x1E6DC0u: goto label_1e6dc0;
            case 0x1E6DE4u: goto label_1e6de4;
            case 0x1E6DF4u: goto label_1e6df4;
            case 0x1E6E18u: goto label_1e6e18;
            case 0x1E6E2Cu: goto label_1e6e2c;
            case 0x1E6E38u: goto label_1e6e38;
            case 0x1E6E48u: goto label_1e6e48;
            case 0x1E6E60u: goto label_1e6e60;
            case 0x1E6E90u: goto label_1e6e90;
            case 0x1E6EFCu: goto label_1e6efc;
            case 0x1E6F14u: goto label_1e6f14;
            case 0x1E6F28u: goto label_1e6f28;
            case 0x1E6F3Cu: goto label_1e6f3c;
            case 0x1E6F48u: goto label_1e6f48;
            case 0x1E6F5Cu: goto label_1e6f5c;
            case 0x1E6F80u: goto label_1e6f80;
            case 0x1E6F94u: goto label_1e6f94;
            case 0x1E6FBCu: goto label_1e6fbc;
            case 0x1E6FD8u: goto label_1e6fd8;
            case 0x1E7054u: goto label_1e7054;
            case 0x1E706Cu: goto label_1e706c;
            case 0x1E7080u: goto label_1e7080;
            case 0x1E70B0u: goto label_1e70b0;
            case 0x1E70C4u: goto label_1e70c4;
            case 0x1E70F8u: goto label_1e70f8;
            case 0x1E7114u: goto label_1e7114;
            case 0x1E7158u: goto label_1e7158;
            case 0x1E7174u: goto label_1e7174;
            case 0x1E7188u: goto label_1e7188;
            case 0x1E71BCu: goto label_1e71bc;
            case 0x1E71D8u: goto label_1e71d8;
            case 0x1E71E4u: goto label_1e71e4;
            case 0x1E71F8u: goto label_1e71f8;
            case 0x1E7210u: goto label_1e7210;
            case 0x1E7240u: goto label_1e7240;
            case 0x1E7264u: goto label_1e7264;
            case 0x1E7278u: goto label_1e7278;
            case 0x1E727Cu: goto label_1e727c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E5A28u;
    // 0x1e5a28: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1e5a28u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1e5a2c: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1e5a2cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1e5a30: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1e5a30u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1e5a34: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e5a34u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e5a38: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e5a38u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e5a3c: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x1e5a3cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e5a40: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e5a40u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e5a44: 0xafc7000c  sw          $a3, 0xC($fp)
    ctx->pc = 0x1e5a44u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 7));
    // 0x1e5a48: 0xa7c20004  sh          $v0, 0x4($fp)
    ctx->pc = 0x1e5a48u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 4), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e5a4c: 0xafc00018  sw          $zero, 0x18($fp)
    ctx->pc = 0x1e5a4cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 0));
    // 0x1e5a50: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e5a50u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e5a54: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e5a54u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e5a58: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E5A58u;
    {
        const bool branch_taken_0x1e5a58 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e5a58) {
            ctx->pc = 0x1E5A80u;
            goto label_1e5a80;
        }
    }
    ctx->pc = 0x1E5A60u;
    // 0x1e5a60: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e5a60u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e5a64: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e5a64u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e5a68: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e5a68u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e5a6c: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e5a6cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e5a70: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e5a70u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e5a74: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e5a74u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e5a78: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E5A78u;
    {
        const bool branch_taken_0x1e5a78 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e5a78) {
            ctx->pc = 0x1E5A94u;
            goto label_1e5a94;
        }
    }
    ctx->pc = 0x1E5A80u;
label_1e5a80:
    // 0x1e5a80: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e5a80u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e5a84: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e5a84u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e5a88: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e5a88u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e5a8c: 0x1000004a  b           . + 4 + (0x4A << 2)
    ctx->pc = 0x1E5A8Cu;
    {
        const bool branch_taken_0x1e5a8c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5a8c) {
            ctx->pc = 0x1E5BB8u;
            goto label_1e5bb8;
        }
    }
    ctx->pc = 0x1E5A94u;
label_1e5a94:
    // 0x1e5a94: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e5a94u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e5a98: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e5a98u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e5a9c: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e5a9cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e5aa0: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e5aa0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e5aa4: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e5aa4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e5aa8: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e5aa8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e5aac: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1e5aacu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1e5ab0: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e5ab0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e5ab4: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e5ab4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e5ab8: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E5AB8u;
    {
        const bool branch_taken_0x1e5ab8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5ab8) {
            ctx->pc = 0x1E5AD4u;
            goto label_1e5ad4;
        }
    }
    ctx->pc = 0x1E5AC0u;
    // 0x1e5ac0: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e5ac0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e5ac4: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e5ac4u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e5ac8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e5ac8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e5acc: 0x1000003a  b           . + 4 + (0x3A << 2)
    ctx->pc = 0x1E5ACCu;
    {
        const bool branch_taken_0x1e5acc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5acc) {
            ctx->pc = 0x1E5BB8u;
            goto label_1e5bb8;
        }
    }
    ctx->pc = 0x1E5AD4u;
label_1e5ad4:
    // 0x1e5ad4: 0x8fc40018  lw          $a0, 0x18($fp)
    ctx->pc = 0x1e5ad4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e5ad8: 0x8fc5000c  lw          $a1, 0xC($fp)
    ctx->pc = 0x1e5ad8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e5adc: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E5ADCu;
    SET_GPR_U32(ctx, 31, 0x1E5AE4u);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5AE4u; }
        if (ctx->pc != 0x1E5AE4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5AE4u; }
        if (ctx->pc != 0x1E5AE4u) { return; }
    }
    ctx->pc = 0x1E5AE4u;
label_1e5ae4:
    // 0x1e5ae4: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1e5ae4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1e5ae8: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e5ae8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e5aec: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E5AECu;
    {
        const bool branch_taken_0x1e5aec = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e5aec) {
            ctx->pc = 0x1E5B08u;
            goto label_1e5b08;
        }
    }
    ctx->pc = 0x1E5AF4u;
    // 0x1e5af4: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e5af4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e5af8: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e5af8u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e5afc: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e5afcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e5b00: 0x1000002d  b           . + 4 + (0x2D << 2)
    ctx->pc = 0x1E5B00u;
    {
        const bool branch_taken_0x1e5b00 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5b00) {
            ctx->pc = 0x1E5BB8u;
            goto label_1e5bb8;
        }
    }
    ctx->pc = 0x1E5B08u;
label_1e5b08:
    // 0x1e5b08: 0x97c2000c  lhu         $v0, 0xC($fp)
    ctx->pc = 0x1e5b08u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e5b0c: 0x8fc40010  lw          $a0, 0x10($fp)
    ctx->pc = 0x1e5b0cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e5b10: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1e5b10u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e5b14: 0xc07cc3c  jal         func_1F30F0
    ctx->pc = 0x1E5B14u;
    SET_GPR_U32(ctx, 31, 0x1E5B1Cu);
    ctx->pc = 0x1F30F0u;
    if (runtime->hasFunction(0x1F30F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F30F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5B1Cu; }
        if (ctx->pc != 0x1E5B1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F30F0_0x1f30f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5B1Cu; }
        if (ctx->pc != 0x1E5B1Cu) { return; }
    }
    ctx->pc = 0x1E5B1Cu;
label_1e5b1c:
    // 0x1e5b1c: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1e5b1cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1e5b20: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e5b20u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e5b24: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1E5B24u;
    {
        const bool branch_taken_0x1e5b24 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e5b24) {
            ctx->pc = 0x1E5B54u;
            goto label_1e5b54;
        }
    }
    ctx->pc = 0x1E5B2Cu;
    // 0x1e5b2c: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e5b2cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e5b30: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1e5b30u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1e5b34: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e5b34u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e5b38: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1E5B38u;
    SET_GPR_U32(ctx, 31, 0x1E5B40u);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5B40u; }
        if (ctx->pc != 0x1E5B40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5B40u; }
        if (ctx->pc != 0x1E5B40u) { return; }
    }
    ctx->pc = 0x1E5B40u;
label_1e5b40:
    // 0x1e5b40: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e5b40u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e5b44: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e5b44u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e5b48: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e5b48u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e5b4c: 0x1000001a  b           . + 4 + (0x1A << 2)
    ctx->pc = 0x1E5B4Cu;
    {
        const bool branch_taken_0x1e5b4c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5b4c) {
            ctx->pc = 0x1E5BB8u;
            goto label_1e5bb8;
        }
    }
    ctx->pc = 0x1E5B54u;
label_1e5b54:
    // 0x1e5b54: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e5b54u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e5b58: 0x8fc50008  lw          $a1, 0x8($fp)
    ctx->pc = 0x1e5b58u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e5b5c: 0x8fc6000c  lw          $a2, 0xC($fp)
    ctx->pc = 0x1e5b5cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e5b60: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1E5B60u;
    SET_GPR_U32(ctx, 31, 0x1E5B68u);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5B68u; }
        if (ctx->pc != 0x1E5B68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5B68u; }
        if (ctx->pc != 0x1E5B68u) { return; }
    }
    ctx->pc = 0x1E5B68u;
label_1e5b68:
    // 0x1e5b68: 0x97c20004  lhu         $v0, 0x4($fp)
    ctx->pc = 0x1e5b68u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e5b6c: 0x34422000  ori         $v0, $v0, 0x2000
    ctx->pc = 0x1e5b6cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)8192);
    // 0x1e5b70: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1e5b70u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1e5b74: 0x97c3000c  lhu         $v1, 0xC($fp)
    ctx->pc = 0x1e5b74u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e5b78: 0x8fc40018  lw          $a0, 0x18($fp)
    ctx->pc = 0x1e5b78u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e5b7c: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e5b7cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e5b80: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x1e5b80u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e5b84: 0x60382d  daddu       $a3, $v1, $zero
    ctx->pc = 0x1e5b84u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e5b88: 0x24080011  addiu       $t0, $zero, 0x11
    ctx->pc = 0x1e5b88u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 17));
    // 0x1e5b8c: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1e5b8cu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e5b90: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E5B90u;
    SET_GPR_U32(ctx, 31, 0x1E5B98u);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5B98u; }
        if (ctx->pc != 0x1E5B98u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5B98u; }
        if (ctx->pc != 0x1E5B98u) { return; }
    }
    ctx->pc = 0x1E5B98u;
label_1e5b98:
    // 0x1e5b98: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E5B98u;
    {
        const bool branch_taken_0x1e5b98 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5b98) {
            ctx->pc = 0x1E5BB4u;
            goto label_1e5bb4;
        }
    }
    ctx->pc = 0x1E5BA0u;
    // 0x1e5ba0: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e5ba0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e5ba4: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e5ba4u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e5ba8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e5ba8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e5bac: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1E5BACu;
    {
        const bool branch_taken_0x1e5bac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5bac) {
            ctx->pc = 0x1E5BB8u;
            goto label_1e5bb8;
        }
    }
    ctx->pc = 0x1E5BB4u;
label_1e5bb4:
    // 0x1e5bb4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1e5bb4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1e5bb8:
    // 0x1e5bb8: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e5bb8u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e5bbc: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1e5bbcu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1e5bc0: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1e5bc0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1e5bc4: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1e5bc4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1e5bc8: 0x3e00008  jr          $ra
    ctx->pc = 0x1E5BC8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E5060u: goto label_1e5060;
            case 0x1E5074u: goto label_1e5074;
            case 0x1E50B4u: goto label_1e50b4;
            case 0x1E50C4u: goto label_1e50c4;
            case 0x1E50E8u: goto label_1e50e8;
            case 0x1E50FCu: goto label_1e50fc;
            case 0x1E5120u: goto label_1e5120;
            case 0x1E5134u: goto label_1e5134;
            case 0x1E5148u: goto label_1e5148;
            case 0x1E5178u: goto label_1e5178;
            case 0x1E5194u: goto label_1e5194;
            case 0x1E5198u: goto label_1e5198;
            case 0x1E5238u: goto label_1e5238;
            case 0x1E524Cu: goto label_1e524c;
            case 0x1E528Cu: goto label_1e528c;
            case 0x1E52B0u: goto label_1e52b0;
            case 0x1E52D4u: goto label_1e52d4;
            case 0x1E530Cu: goto label_1e530c;
            case 0x1E536Cu: goto label_1e536c;
            case 0x1E5388u: goto label_1e5388;
            case 0x1E5410u: goto label_1e5410;
            case 0x1E5424u: goto label_1e5424;
            case 0x1E5464u: goto label_1e5464;
            case 0x1E5480u: goto label_1e5480;
            case 0x1E5484u: goto label_1e5484;
            case 0x1E54F8u: goto label_1e54f8;
            case 0x1E550Cu: goto label_1e550c;
            case 0x1E554Cu: goto label_1e554c;
            case 0x1E5574u: goto label_1e5574;
            case 0x1E5598u: goto label_1e5598;
            case 0x1E55C8u: goto label_1e55c8;
            case 0x1E55ECu: goto label_1e55ec;
            case 0x1E5600u: goto label_1e5600;
            case 0x1E566Cu: goto label_1e566c;
            case 0x1E568Cu: goto label_1e568c;
            case 0x1E5748u: goto label_1e5748;
            case 0x1E575Cu: goto label_1e575c;
            case 0x1E57A0u: goto label_1e57a0;
            case 0x1E57BCu: goto label_1e57bc;
            case 0x1E57C0u: goto label_1e57c0;
            case 0x1E5820u: goto label_1e5820;
            case 0x1E5834u: goto label_1e5834;
            case 0x1E5874u: goto label_1e5874;
            case 0x1E5884u: goto label_1e5884;
            case 0x1E58A8u: goto label_1e58a8;
            case 0x1E58C8u: goto label_1e58c8;
            case 0x1E58E4u: goto label_1e58e4;
            case 0x1E58E8u: goto label_1e58e8;
            case 0x1E5948u: goto label_1e5948;
            case 0x1E595Cu: goto label_1e595c;
            case 0x1E599Cu: goto label_1e599c;
            case 0x1E59ACu: goto label_1e59ac;
            case 0x1E59D0u: goto label_1e59d0;
            case 0x1E59F0u: goto label_1e59f0;
            case 0x1E5A0Cu: goto label_1e5a0c;
            case 0x1E5A10u: goto label_1e5a10;
            case 0x1E5A80u: goto label_1e5a80;
            case 0x1E5A94u: goto label_1e5a94;
            case 0x1E5AD4u: goto label_1e5ad4;
            case 0x1E5AE4u: goto label_1e5ae4;
            case 0x1E5B08u: goto label_1e5b08;
            case 0x1E5B1Cu: goto label_1e5b1c;
            case 0x1E5B40u: goto label_1e5b40;
            case 0x1E5B54u: goto label_1e5b54;
            case 0x1E5B68u: goto label_1e5b68;
            case 0x1E5B98u: goto label_1e5b98;
            case 0x1E5BB4u: goto label_1e5bb4;
            case 0x1E5BB8u: goto label_1e5bb8;
            case 0x1E5C2Cu: goto label_1e5c2c;
            case 0x1E5C40u: goto label_1e5c40;
            case 0x1E5C80u: goto label_1e5c80;
            case 0x1E5C90u: goto label_1e5c90;
            case 0x1E5CB4u: goto label_1e5cb4;
            case 0x1E5CC8u: goto label_1e5cc8;
            case 0x1E5CECu: goto label_1e5cec;
            case 0x1E5D00u: goto label_1e5d00;
            case 0x1E5D14u: goto label_1e5d14;
            case 0x1E5D48u: goto label_1e5d48;
            case 0x1E5D64u: goto label_1e5d64;
            case 0x1E5D78u: goto label_1e5d78;
            case 0x1E5D94u: goto label_1e5d94;
            case 0x1E5E04u: goto label_1e5e04;
            case 0x1E5E18u: goto label_1e5e18;
            case 0x1E5E58u: goto label_1e5e58;
            case 0x1E5E68u: goto label_1e5e68;
            case 0x1E5E8Cu: goto label_1e5e8c;
            case 0x1E5E9Cu: goto label_1e5e9c;
            case 0x1E5EB4u: goto label_1e5eb4;
            case 0x1E5F6Cu: goto label_1e5f6c;
            case 0x1E5F88u: goto label_1e5f88;
            case 0x1E5F9Cu: goto label_1e5f9c;
            case 0x1E5FA0u: goto label_1e5fa0;
            case 0x1E6008u: goto label_1e6008;
            case 0x1E601Cu: goto label_1e601c;
            case 0x1E605Cu: goto label_1e605c;
            case 0x1E6068u: goto label_1e6068;
            case 0x1E6084u: goto label_1e6084;
            case 0x1E6094u: goto label_1e6094;
            case 0x1E60B8u: goto label_1e60b8;
            case 0x1E60CCu: goto label_1e60cc;
            case 0x1E60F0u: goto label_1e60f0;
            case 0x1E6104u: goto label_1e6104;
            case 0x1E6118u: goto label_1e6118;
            case 0x1E613Cu: goto label_1e613c;
            case 0x1E6158u: goto label_1e6158;
            case 0x1E616Cu: goto label_1e616c;
            case 0x1E6170u: goto label_1e6170;
            case 0x1E61D4u: goto label_1e61d4;
            case 0x1E61E8u: goto label_1e61e8;
            case 0x1E6228u: goto label_1e6228;
            case 0x1E623Cu: goto label_1e623c;
            case 0x1E6240u: goto label_1e6240;
            case 0x1E62A4u: goto label_1e62a4;
            case 0x1E62B8u: goto label_1e62b8;
            case 0x1E62F8u: goto label_1e62f8;
            case 0x1E630Cu: goto label_1e630c;
            case 0x1E6310u: goto label_1e6310;
            case 0x1E6374u: goto label_1e6374;
            case 0x1E6388u: goto label_1e6388;
            case 0x1E63C8u: goto label_1e63c8;
            case 0x1E63DCu: goto label_1e63dc;
            case 0x1E63E0u: goto label_1e63e0;
            case 0x1E6448u: goto label_1e6448;
            case 0x1E645Cu: goto label_1e645c;
            case 0x1E649Cu: goto label_1e649c;
            case 0x1E64B4u: goto label_1e64b4;
            case 0x1E64C4u: goto label_1e64c4;
            case 0x1E64E8u: goto label_1e64e8;
            case 0x1E64FCu: goto label_1e64fc;
            case 0x1E6520u: goto label_1e6520;
            case 0x1E6534u: goto label_1e6534;
            case 0x1E6548u: goto label_1e6548;
            case 0x1E656Cu: goto label_1e656c;
            case 0x1E6588u: goto label_1e6588;
            case 0x1E658Cu: goto label_1e658c;
            case 0x1E65F8u: goto label_1e65f8;
            case 0x1E660Cu: goto label_1e660c;
            case 0x1E664Cu: goto label_1e664c;
            case 0x1E6664u: goto label_1e6664;
            case 0x1E6674u: goto label_1e6674;
            case 0x1E6698u: goto label_1e6698;
            case 0x1E66ACu: goto label_1e66ac;
            case 0x1E66D0u: goto label_1e66d0;
            case 0x1E66E4u: goto label_1e66e4;
            case 0x1E66FCu: goto label_1e66fc;
            case 0x1E6718u: goto label_1e6718;
            case 0x1E6744u: goto label_1e6744;
            case 0x1E6760u: goto label_1e6760;
            case 0x1E6764u: goto label_1e6764;
            case 0x1E67D0u: goto label_1e67d0;
            case 0x1E67E4u: goto label_1e67e4;
            case 0x1E6824u: goto label_1e6824;
            case 0x1E6834u: goto label_1e6834;
            case 0x1E6858u: goto label_1e6858;
            case 0x1E6868u: goto label_1e6868;
            case 0x1E688Cu: goto label_1e688c;
            case 0x1E68A0u: goto label_1e68a0;
            case 0x1E68ACu: goto label_1e68ac;
            case 0x1E68BCu: goto label_1e68bc;
            case 0x1E68D4u: goto label_1e68d4;
            case 0x1E6904u: goto label_1e6904;
            case 0x1E6970u: goto label_1e6970;
            case 0x1E6988u: goto label_1e6988;
            case 0x1E699Cu: goto label_1e699c;
            case 0x1E69B0u: goto label_1e69b0;
            case 0x1E69BCu: goto label_1e69bc;
            case 0x1E69D0u: goto label_1e69d0;
            case 0x1E69F4u: goto label_1e69f4;
            case 0x1E6A08u: goto label_1e6a08;
            case 0x1E6A30u: goto label_1e6a30;
            case 0x1E6A4Cu: goto label_1e6a4c;
            case 0x1E6AC8u: goto label_1e6ac8;
            case 0x1E6AE0u: goto label_1e6ae0;
            case 0x1E6AF4u: goto label_1e6af4;
            case 0x1E6B24u: goto label_1e6b24;
            case 0x1E6B38u: goto label_1e6b38;
            case 0x1E6B6Cu: goto label_1e6b6c;
            case 0x1E6B88u: goto label_1e6b88;
            case 0x1E6BCCu: goto label_1e6bcc;
            case 0x1E6BE8u: goto label_1e6be8;
            case 0x1E6BFCu: goto label_1e6bfc;
            case 0x1E6C30u: goto label_1e6c30;
            case 0x1E6C4Cu: goto label_1e6c4c;
            case 0x1E6C58u: goto label_1e6c58;
            case 0x1E6C6Cu: goto label_1e6c6c;
            case 0x1E6C84u: goto label_1e6c84;
            case 0x1E6CB4u: goto label_1e6cb4;
            case 0x1E6CD8u: goto label_1e6cd8;
            case 0x1E6CECu: goto label_1e6cec;
            case 0x1E6CF0u: goto label_1e6cf0;
            case 0x1E6D5Cu: goto label_1e6d5c;
            case 0x1E6D70u: goto label_1e6d70;
            case 0x1E6DB0u: goto label_1e6db0;
            case 0x1E6DC0u: goto label_1e6dc0;
            case 0x1E6DE4u: goto label_1e6de4;
            case 0x1E6DF4u: goto label_1e6df4;
            case 0x1E6E18u: goto label_1e6e18;
            case 0x1E6E2Cu: goto label_1e6e2c;
            case 0x1E6E38u: goto label_1e6e38;
            case 0x1E6E48u: goto label_1e6e48;
            case 0x1E6E60u: goto label_1e6e60;
            case 0x1E6E90u: goto label_1e6e90;
            case 0x1E6EFCu: goto label_1e6efc;
            case 0x1E6F14u: goto label_1e6f14;
            case 0x1E6F28u: goto label_1e6f28;
            case 0x1E6F3Cu: goto label_1e6f3c;
            case 0x1E6F48u: goto label_1e6f48;
            case 0x1E6F5Cu: goto label_1e6f5c;
            case 0x1E6F80u: goto label_1e6f80;
            case 0x1E6F94u: goto label_1e6f94;
            case 0x1E6FBCu: goto label_1e6fbc;
            case 0x1E6FD8u: goto label_1e6fd8;
            case 0x1E7054u: goto label_1e7054;
            case 0x1E706Cu: goto label_1e706c;
            case 0x1E7080u: goto label_1e7080;
            case 0x1E70B0u: goto label_1e70b0;
            case 0x1E70C4u: goto label_1e70c4;
            case 0x1E70F8u: goto label_1e70f8;
            case 0x1E7114u: goto label_1e7114;
            case 0x1E7158u: goto label_1e7158;
            case 0x1E7174u: goto label_1e7174;
            case 0x1E7188u: goto label_1e7188;
            case 0x1E71BCu: goto label_1e71bc;
            case 0x1E71D8u: goto label_1e71d8;
            case 0x1E71E4u: goto label_1e71e4;
            case 0x1E71F8u: goto label_1e71f8;
            case 0x1E7210u: goto label_1e7210;
            case 0x1E7240u: goto label_1e7240;
            case 0x1E7264u: goto label_1e7264;
            case 0x1E7278u: goto label_1e7278;
            case 0x1E727Cu: goto label_1e727c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E5BD0u;
    // 0x1e5bd0: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1e5bd0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1e5bd4: 0xffbe0030  sd          $fp, 0x30($sp)
    ctx->pc = 0x1e5bd4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 30));
    // 0x1e5bd8: 0xffbf0038  sd          $ra, 0x38($sp)
    ctx->pc = 0x1e5bd8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x1e5bdc: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e5bdcu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e5be0: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e5be0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e5be4: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x1e5be4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e5be8: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e5be8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e5bec: 0xafc7000c  sw          $a3, 0xC($fp)
    ctx->pc = 0x1e5becu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 7));
    // 0x1e5bf0: 0xafc80010  sw          $t0, 0x10($fp)
    ctx->pc = 0x1e5bf0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 8));
    // 0x1e5bf4: 0xa7c20004  sh          $v0, 0x4($fp)
    ctx->pc = 0x1e5bf4u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 4), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e5bf8: 0xafc0001c  sw          $zero, 0x1C($fp)
    ctx->pc = 0x1e5bf8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 0));
    // 0x1e5bfc: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e5bfcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e5c00: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e5c00u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e5c04: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E5C04u;
    {
        const bool branch_taken_0x1e5c04 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e5c04) {
            ctx->pc = 0x1E5C2Cu;
            goto label_1e5c2c;
        }
    }
    ctx->pc = 0x1E5C0Cu;
    // 0x1e5c0c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e5c0cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e5c10: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e5c10u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e5c14: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e5c14u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e5c18: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e5c18u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e5c1c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e5c1cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e5c20: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e5c20u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e5c24: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E5C24u;
    {
        const bool branch_taken_0x1e5c24 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e5c24) {
            ctx->pc = 0x1E5C40u;
            goto label_1e5c40;
        }
    }
    ctx->pc = 0x1E5C2Cu;
label_1e5c2c:
    // 0x1e5c2c: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e5c2cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e5c30: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e5c30u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e5c34: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e5c34u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e5c38: 0x10000056  b           . + 4 + (0x56 << 2)
    ctx->pc = 0x1E5C38u;
    {
        const bool branch_taken_0x1e5c38 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5c38) {
            ctx->pc = 0x1E5D94u;
            goto label_1e5d94;
        }
    }
    ctx->pc = 0x1E5C40u;
label_1e5c40:
    // 0x1e5c40: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e5c40u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e5c44: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e5c44u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e5c48: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e5c48u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e5c4c: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e5c4cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e5c50: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e5c50u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e5c54: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e5c54u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e5c58: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1e5c58u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1e5c5c: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1e5c5cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e5c60: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e5c60u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e5c64: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E5C64u;
    {
        const bool branch_taken_0x1e5c64 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5c64) {
            ctx->pc = 0x1E5C80u;
            goto label_1e5c80;
        }
    }
    ctx->pc = 0x1E5C6Cu;
    // 0x1e5c6c: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e5c6cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e5c70: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e5c70u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e5c74: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e5c74u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e5c78: 0x10000046  b           . + 4 + (0x46 << 2)
    ctx->pc = 0x1E5C78u;
    {
        const bool branch_taken_0x1e5c78 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5c78) {
            ctx->pc = 0x1E5D94u;
            goto label_1e5d94;
        }
    }
    ctx->pc = 0x1E5C80u;
label_1e5c80:
    // 0x1e5c80: 0x8fc4001c  lw          $a0, 0x1C($fp)
    ctx->pc = 0x1e5c80u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e5c84: 0x8fc5000c  lw          $a1, 0xC($fp)
    ctx->pc = 0x1e5c84u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e5c88: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E5C88u;
    SET_GPR_U32(ctx, 31, 0x1E5C90u);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5C90u; }
        if (ctx->pc != 0x1E5C90u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5C90u; }
        if (ctx->pc != 0x1E5C90u) { return; }
    }
    ctx->pc = 0x1E5C90u;
label_1e5c90:
    // 0x1e5c90: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1e5c90u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1e5c94: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e5c94u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e5c98: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E5C98u;
    {
        const bool branch_taken_0x1e5c98 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e5c98) {
            ctx->pc = 0x1E5CB4u;
            goto label_1e5cb4;
        }
    }
    ctx->pc = 0x1E5CA0u;
    // 0x1e5ca0: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e5ca0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e5ca4: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e5ca4u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e5ca8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e5ca8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e5cac: 0x10000039  b           . + 4 + (0x39 << 2)
    ctx->pc = 0x1E5CACu;
    {
        const bool branch_taken_0x1e5cac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5cac) {
            ctx->pc = 0x1E5D94u;
            goto label_1e5d94;
        }
    }
    ctx->pc = 0x1E5CB4u;
label_1e5cb4:
    // 0x1e5cb4: 0x97c2000c  lhu         $v0, 0xC($fp)
    ctx->pc = 0x1e5cb4u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e5cb8: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e5cb8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e5cbc: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1e5cbcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e5cc0: 0xc07cc3c  jal         func_1F30F0
    ctx->pc = 0x1E5CC0u;
    SET_GPR_U32(ctx, 31, 0x1E5CC8u);
    ctx->pc = 0x1F30F0u;
    if (runtime->hasFunction(0x1F30F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F30F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5CC8u; }
        if (ctx->pc != 0x1E5CC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F30F0_0x1f30f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5CC8u; }
        if (ctx->pc != 0x1E5CC8u) { return; }
    }
    ctx->pc = 0x1E5CC8u;
label_1e5cc8:
    // 0x1e5cc8: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1e5cc8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1e5ccc: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e5cccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e5cd0: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1E5CD0u;
    {
        const bool branch_taken_0x1e5cd0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e5cd0) {
            ctx->pc = 0x1E5D00u;
            goto label_1e5d00;
        }
    }
    ctx->pc = 0x1E5CD8u;
    // 0x1e5cd8: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1e5cd8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e5cdc: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1e5cdcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1e5ce0: 0x8fc50014  lw          $a1, 0x14($fp)
    ctx->pc = 0x1e5ce0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e5ce4: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1E5CE4u;
    SET_GPR_U32(ctx, 31, 0x1E5CECu);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5CECu; }
        if (ctx->pc != 0x1E5CECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5CECu; }
        if (ctx->pc != 0x1E5CECu) { return; }
    }
    ctx->pc = 0x1E5CECu;
label_1e5cec:
    // 0x1e5cec: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e5cecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e5cf0: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e5cf0u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e5cf4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e5cf4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e5cf8: 0x10000026  b           . + 4 + (0x26 << 2)
    ctx->pc = 0x1E5CF8u;
    {
        const bool branch_taken_0x1e5cf8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5cf8) {
            ctx->pc = 0x1E5D94u;
            goto label_1e5d94;
        }
    }
    ctx->pc = 0x1E5D00u;
label_1e5d00:
    // 0x1e5d00: 0x8fc40018  lw          $a0, 0x18($fp)
    ctx->pc = 0x1e5d00u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e5d04: 0x8fc50008  lw          $a1, 0x8($fp)
    ctx->pc = 0x1e5d04u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e5d08: 0x8fc6000c  lw          $a2, 0xC($fp)
    ctx->pc = 0x1e5d08u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e5d0c: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1E5D0Cu;
    SET_GPR_U32(ctx, 31, 0x1E5D14u);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5D14u; }
        if (ctx->pc != 0x1E5D14u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5D14u; }
        if (ctx->pc != 0x1E5D14u) { return; }
    }
    ctx->pc = 0x1E5D14u;
label_1e5d14:
    // 0x1e5d14: 0x97c20004  lhu         $v0, 0x4($fp)
    ctx->pc = 0x1e5d14u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e5d18: 0x34422000  ori         $v0, $v0, 0x2000
    ctx->pc = 0x1e5d18u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)8192);
    // 0x1e5d1c: 0x3043ffff  andi        $v1, $v0, 0xFFFF
    ctx->pc = 0x1e5d1cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1e5d20: 0x97c7000c  lhu         $a3, 0xC($fp)
    ctx->pc = 0x1e5d20u;
    SET_GPR_U32(ctx, 7, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e5d24: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1e5d24u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e5d28: 0x90420621  lbu         $v0, 0x621($v0)
    ctx->pc = 0x1e5d28u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 1569)));
    // 0x1e5d2c: 0x8fc4001c  lw          $a0, 0x1C($fp)
    ctx->pc = 0x1e5d2cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e5d30: 0x8fc50014  lw          $a1, 0x14($fp)
    ctx->pc = 0x1e5d30u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e5d34: 0x60302d  daddu       $a2, $v1, $zero
    ctx->pc = 0x1e5d34u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e5d38: 0x24080014  addiu       $t0, $zero, 0x14
    ctx->pc = 0x1e5d38u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
    // 0x1e5d3c: 0x40482d  daddu       $t1, $v0, $zero
    ctx->pc = 0x1e5d3cu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e5d40: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E5D40u;
    SET_GPR_U32(ctx, 31, 0x1E5D48u);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5D48u; }
        if (ctx->pc != 0x1E5D48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5D48u; }
        if (ctx->pc != 0x1E5D48u) { return; }
    }
    ctx->pc = 0x1E5D48u;
label_1e5d48:
    // 0x1e5d48: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E5D48u;
    {
        const bool branch_taken_0x1e5d48 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5d48) {
            ctx->pc = 0x1E5D64u;
            goto label_1e5d64;
        }
    }
    ctx->pc = 0x1E5D50u;
    // 0x1e5d50: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e5d50u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e5d54: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e5d54u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e5d58: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e5d58u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e5d5c: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1E5D5Cu;
    {
        const bool branch_taken_0x1e5d5c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5d5c) {
            ctx->pc = 0x1E5D94u;
            goto label_1e5d94;
        }
    }
    ctx->pc = 0x1E5D64u;
label_1e5d64:
    // 0x1e5d64: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1e5d64u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e5d68: 0x24050028  addiu       $a1, $zero, 0x28
    ctx->pc = 0x1e5d68u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 40));
    // 0x1e5d6c: 0x8fc60010  lw          $a2, 0x10($fp)
    ctx->pc = 0x1e5d6cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e5d70: 0xc076ad5  jal         func_1DAB54
    ctx->pc = 0x1E5D70u;
    SET_GPR_U32(ctx, 31, 0x1E5D78u);
    ctx->pc = 0x1DAB54u;
    if (runtime->hasFunction(0x1DAB54u)) {
        auto targetFn = runtime->lookupFunction(0x1DAB54u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5D78u; }
        if (ctx->pc != 0x1E5D78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DAB54_0x1dab54(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5D78u; }
        if (ctx->pc != 0x1E5D78u) { return; }
    }
    ctx->pc = 0x1E5D78u;
label_1e5d78:
    // 0x1e5d78: 0x8fc3001c  lw          $v1, 0x1C($fp)
    ctx->pc = 0x1e5d78u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e5d7c: 0x90640621  lbu         $a0, 0x621($v1)
    ctx->pc = 0x1e5d7cu;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 1569)));
    // 0x1e5d80: 0x24820001  addiu       $v0, $a0, 0x1
    ctx->pc = 0x1e5d80u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1e5d84: 0xa0620621  sb          $v0, 0x621($v1)
    ctx->pc = 0x1e5d84u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 1569), (uint8_t)GPR_U32(ctx, 2));
    // 0x1e5d88: 0x308200ff  andi        $v0, $a0, 0xFF
    ctx->pc = 0x1e5d88u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x1e5d8c: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1e5d8cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1e5d90: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e5d90u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
label_1e5d94:
    // 0x1e5d94: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e5d94u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e5d98: 0xdfbe0030  ld          $fp, 0x30($sp)
    ctx->pc = 0x1e5d98u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1e5d9c: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x1e5d9cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x1e5da0: 0x27bd0040  addiu       $sp, $sp, 0x40
    ctx->pc = 0x1e5da0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x1e5da4: 0x3e00008  jr          $ra
    ctx->pc = 0x1E5DA4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E5060u: goto label_1e5060;
            case 0x1E5074u: goto label_1e5074;
            case 0x1E50B4u: goto label_1e50b4;
            case 0x1E50C4u: goto label_1e50c4;
            case 0x1E50E8u: goto label_1e50e8;
            case 0x1E50FCu: goto label_1e50fc;
            case 0x1E5120u: goto label_1e5120;
            case 0x1E5134u: goto label_1e5134;
            case 0x1E5148u: goto label_1e5148;
            case 0x1E5178u: goto label_1e5178;
            case 0x1E5194u: goto label_1e5194;
            case 0x1E5198u: goto label_1e5198;
            case 0x1E5238u: goto label_1e5238;
            case 0x1E524Cu: goto label_1e524c;
            case 0x1E528Cu: goto label_1e528c;
            case 0x1E52B0u: goto label_1e52b0;
            case 0x1E52D4u: goto label_1e52d4;
            case 0x1E530Cu: goto label_1e530c;
            case 0x1E536Cu: goto label_1e536c;
            case 0x1E5388u: goto label_1e5388;
            case 0x1E5410u: goto label_1e5410;
            case 0x1E5424u: goto label_1e5424;
            case 0x1E5464u: goto label_1e5464;
            case 0x1E5480u: goto label_1e5480;
            case 0x1E5484u: goto label_1e5484;
            case 0x1E54F8u: goto label_1e54f8;
            case 0x1E550Cu: goto label_1e550c;
            case 0x1E554Cu: goto label_1e554c;
            case 0x1E5574u: goto label_1e5574;
            case 0x1E5598u: goto label_1e5598;
            case 0x1E55C8u: goto label_1e55c8;
            case 0x1E55ECu: goto label_1e55ec;
            case 0x1E5600u: goto label_1e5600;
            case 0x1E566Cu: goto label_1e566c;
            case 0x1E568Cu: goto label_1e568c;
            case 0x1E5748u: goto label_1e5748;
            case 0x1E575Cu: goto label_1e575c;
            case 0x1E57A0u: goto label_1e57a0;
            case 0x1E57BCu: goto label_1e57bc;
            case 0x1E57C0u: goto label_1e57c0;
            case 0x1E5820u: goto label_1e5820;
            case 0x1E5834u: goto label_1e5834;
            case 0x1E5874u: goto label_1e5874;
            case 0x1E5884u: goto label_1e5884;
            case 0x1E58A8u: goto label_1e58a8;
            case 0x1E58C8u: goto label_1e58c8;
            case 0x1E58E4u: goto label_1e58e4;
            case 0x1E58E8u: goto label_1e58e8;
            case 0x1E5948u: goto label_1e5948;
            case 0x1E595Cu: goto label_1e595c;
            case 0x1E599Cu: goto label_1e599c;
            case 0x1E59ACu: goto label_1e59ac;
            case 0x1E59D0u: goto label_1e59d0;
            case 0x1E59F0u: goto label_1e59f0;
            case 0x1E5A0Cu: goto label_1e5a0c;
            case 0x1E5A10u: goto label_1e5a10;
            case 0x1E5A80u: goto label_1e5a80;
            case 0x1E5A94u: goto label_1e5a94;
            case 0x1E5AD4u: goto label_1e5ad4;
            case 0x1E5AE4u: goto label_1e5ae4;
            case 0x1E5B08u: goto label_1e5b08;
            case 0x1E5B1Cu: goto label_1e5b1c;
            case 0x1E5B40u: goto label_1e5b40;
            case 0x1E5B54u: goto label_1e5b54;
            case 0x1E5B68u: goto label_1e5b68;
            case 0x1E5B98u: goto label_1e5b98;
            case 0x1E5BB4u: goto label_1e5bb4;
            case 0x1E5BB8u: goto label_1e5bb8;
            case 0x1E5C2Cu: goto label_1e5c2c;
            case 0x1E5C40u: goto label_1e5c40;
            case 0x1E5C80u: goto label_1e5c80;
            case 0x1E5C90u: goto label_1e5c90;
            case 0x1E5CB4u: goto label_1e5cb4;
            case 0x1E5CC8u: goto label_1e5cc8;
            case 0x1E5CECu: goto label_1e5cec;
            case 0x1E5D00u: goto label_1e5d00;
            case 0x1E5D14u: goto label_1e5d14;
            case 0x1E5D48u: goto label_1e5d48;
            case 0x1E5D64u: goto label_1e5d64;
            case 0x1E5D78u: goto label_1e5d78;
            case 0x1E5D94u: goto label_1e5d94;
            case 0x1E5E04u: goto label_1e5e04;
            case 0x1E5E18u: goto label_1e5e18;
            case 0x1E5E58u: goto label_1e5e58;
            case 0x1E5E68u: goto label_1e5e68;
            case 0x1E5E8Cu: goto label_1e5e8c;
            case 0x1E5E9Cu: goto label_1e5e9c;
            case 0x1E5EB4u: goto label_1e5eb4;
            case 0x1E5F6Cu: goto label_1e5f6c;
            case 0x1E5F88u: goto label_1e5f88;
            case 0x1E5F9Cu: goto label_1e5f9c;
            case 0x1E5FA0u: goto label_1e5fa0;
            case 0x1E6008u: goto label_1e6008;
            case 0x1E601Cu: goto label_1e601c;
            case 0x1E605Cu: goto label_1e605c;
            case 0x1E6068u: goto label_1e6068;
            case 0x1E6084u: goto label_1e6084;
            case 0x1E6094u: goto label_1e6094;
            case 0x1E60B8u: goto label_1e60b8;
            case 0x1E60CCu: goto label_1e60cc;
            case 0x1E60F0u: goto label_1e60f0;
            case 0x1E6104u: goto label_1e6104;
            case 0x1E6118u: goto label_1e6118;
            case 0x1E613Cu: goto label_1e613c;
            case 0x1E6158u: goto label_1e6158;
            case 0x1E616Cu: goto label_1e616c;
            case 0x1E6170u: goto label_1e6170;
            case 0x1E61D4u: goto label_1e61d4;
            case 0x1E61E8u: goto label_1e61e8;
            case 0x1E6228u: goto label_1e6228;
            case 0x1E623Cu: goto label_1e623c;
            case 0x1E6240u: goto label_1e6240;
            case 0x1E62A4u: goto label_1e62a4;
            case 0x1E62B8u: goto label_1e62b8;
            case 0x1E62F8u: goto label_1e62f8;
            case 0x1E630Cu: goto label_1e630c;
            case 0x1E6310u: goto label_1e6310;
            case 0x1E6374u: goto label_1e6374;
            case 0x1E6388u: goto label_1e6388;
            case 0x1E63C8u: goto label_1e63c8;
            case 0x1E63DCu: goto label_1e63dc;
            case 0x1E63E0u: goto label_1e63e0;
            case 0x1E6448u: goto label_1e6448;
            case 0x1E645Cu: goto label_1e645c;
            case 0x1E649Cu: goto label_1e649c;
            case 0x1E64B4u: goto label_1e64b4;
            case 0x1E64C4u: goto label_1e64c4;
            case 0x1E64E8u: goto label_1e64e8;
            case 0x1E64FCu: goto label_1e64fc;
            case 0x1E6520u: goto label_1e6520;
            case 0x1E6534u: goto label_1e6534;
            case 0x1E6548u: goto label_1e6548;
            case 0x1E656Cu: goto label_1e656c;
            case 0x1E6588u: goto label_1e6588;
            case 0x1E658Cu: goto label_1e658c;
            case 0x1E65F8u: goto label_1e65f8;
            case 0x1E660Cu: goto label_1e660c;
            case 0x1E664Cu: goto label_1e664c;
            case 0x1E6664u: goto label_1e6664;
            case 0x1E6674u: goto label_1e6674;
            case 0x1E6698u: goto label_1e6698;
            case 0x1E66ACu: goto label_1e66ac;
            case 0x1E66D0u: goto label_1e66d0;
            case 0x1E66E4u: goto label_1e66e4;
            case 0x1E66FCu: goto label_1e66fc;
            case 0x1E6718u: goto label_1e6718;
            case 0x1E6744u: goto label_1e6744;
            case 0x1E6760u: goto label_1e6760;
            case 0x1E6764u: goto label_1e6764;
            case 0x1E67D0u: goto label_1e67d0;
            case 0x1E67E4u: goto label_1e67e4;
            case 0x1E6824u: goto label_1e6824;
            case 0x1E6834u: goto label_1e6834;
            case 0x1E6858u: goto label_1e6858;
            case 0x1E6868u: goto label_1e6868;
            case 0x1E688Cu: goto label_1e688c;
            case 0x1E68A0u: goto label_1e68a0;
            case 0x1E68ACu: goto label_1e68ac;
            case 0x1E68BCu: goto label_1e68bc;
            case 0x1E68D4u: goto label_1e68d4;
            case 0x1E6904u: goto label_1e6904;
            case 0x1E6970u: goto label_1e6970;
            case 0x1E6988u: goto label_1e6988;
            case 0x1E699Cu: goto label_1e699c;
            case 0x1E69B0u: goto label_1e69b0;
            case 0x1E69BCu: goto label_1e69bc;
            case 0x1E69D0u: goto label_1e69d0;
            case 0x1E69F4u: goto label_1e69f4;
            case 0x1E6A08u: goto label_1e6a08;
            case 0x1E6A30u: goto label_1e6a30;
            case 0x1E6A4Cu: goto label_1e6a4c;
            case 0x1E6AC8u: goto label_1e6ac8;
            case 0x1E6AE0u: goto label_1e6ae0;
            case 0x1E6AF4u: goto label_1e6af4;
            case 0x1E6B24u: goto label_1e6b24;
            case 0x1E6B38u: goto label_1e6b38;
            case 0x1E6B6Cu: goto label_1e6b6c;
            case 0x1E6B88u: goto label_1e6b88;
            case 0x1E6BCCu: goto label_1e6bcc;
            case 0x1E6BE8u: goto label_1e6be8;
            case 0x1E6BFCu: goto label_1e6bfc;
            case 0x1E6C30u: goto label_1e6c30;
            case 0x1E6C4Cu: goto label_1e6c4c;
            case 0x1E6C58u: goto label_1e6c58;
            case 0x1E6C6Cu: goto label_1e6c6c;
            case 0x1E6C84u: goto label_1e6c84;
            case 0x1E6CB4u: goto label_1e6cb4;
            case 0x1E6CD8u: goto label_1e6cd8;
            case 0x1E6CECu: goto label_1e6cec;
            case 0x1E6CF0u: goto label_1e6cf0;
            case 0x1E6D5Cu: goto label_1e6d5c;
            case 0x1E6D70u: goto label_1e6d70;
            case 0x1E6DB0u: goto label_1e6db0;
            case 0x1E6DC0u: goto label_1e6dc0;
            case 0x1E6DE4u: goto label_1e6de4;
            case 0x1E6DF4u: goto label_1e6df4;
            case 0x1E6E18u: goto label_1e6e18;
            case 0x1E6E2Cu: goto label_1e6e2c;
            case 0x1E6E38u: goto label_1e6e38;
            case 0x1E6E48u: goto label_1e6e48;
            case 0x1E6E60u: goto label_1e6e60;
            case 0x1E6E90u: goto label_1e6e90;
            case 0x1E6EFCu: goto label_1e6efc;
            case 0x1E6F14u: goto label_1e6f14;
            case 0x1E6F28u: goto label_1e6f28;
            case 0x1E6F3Cu: goto label_1e6f3c;
            case 0x1E6F48u: goto label_1e6f48;
            case 0x1E6F5Cu: goto label_1e6f5c;
            case 0x1E6F80u: goto label_1e6f80;
            case 0x1E6F94u: goto label_1e6f94;
            case 0x1E6FBCu: goto label_1e6fbc;
            case 0x1E6FD8u: goto label_1e6fd8;
            case 0x1E7054u: goto label_1e7054;
            case 0x1E706Cu: goto label_1e706c;
            case 0x1E7080u: goto label_1e7080;
            case 0x1E70B0u: goto label_1e70b0;
            case 0x1E70C4u: goto label_1e70c4;
            case 0x1E70F8u: goto label_1e70f8;
            case 0x1E7114u: goto label_1e7114;
            case 0x1E7158u: goto label_1e7158;
            case 0x1E7174u: goto label_1e7174;
            case 0x1E7188u: goto label_1e7188;
            case 0x1E71BCu: goto label_1e71bc;
            case 0x1E71D8u: goto label_1e71d8;
            case 0x1E71E4u: goto label_1e71e4;
            case 0x1E71F8u: goto label_1e71f8;
            case 0x1E7210u: goto label_1e7210;
            case 0x1E7240u: goto label_1e7240;
            case 0x1E7264u: goto label_1e7264;
            case 0x1E7278u: goto label_1e7278;
            case 0x1E727Cu: goto label_1e727c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E5DACu;
    // 0x1e5dac: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1e5dacu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1e5db0: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1e5db0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1e5db4: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1e5db4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1e5db8: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e5db8u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e5dbc: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e5dbcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e5dc0: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e5dc0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e5dc4: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e5dc4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e5dc8: 0xafc7000c  sw          $a3, 0xC($fp)
    ctx->pc = 0x1e5dc8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 7));
    // 0x1e5dcc: 0xafc80010  sw          $t0, 0x10($fp)
    ctx->pc = 0x1e5dccu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 8));
    // 0x1e5dd0: 0xafc0001c  sw          $zero, 0x1C($fp)
    ctx->pc = 0x1e5dd0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 0));
    // 0x1e5dd4: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e5dd4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e5dd8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e5dd8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e5ddc: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E5DDCu;
    {
        const bool branch_taken_0x1e5ddc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e5ddc) {
            ctx->pc = 0x1E5E04u;
            goto label_1e5e04;
        }
    }
    ctx->pc = 0x1E5DE4u;
    // 0x1e5de4: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e5de4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e5de8: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e5de8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e5dec: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e5decu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e5df0: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e5df0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e5df4: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e5df4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e5df8: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e5df8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e5dfc: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E5DFCu;
    {
        const bool branch_taken_0x1e5dfc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e5dfc) {
            ctx->pc = 0x1E5E18u;
            goto label_1e5e18;
        }
    }
    ctx->pc = 0x1E5E04u;
label_1e5e04:
    // 0x1e5e04: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e5e04u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e5e08: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e5e08u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e5e0c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e5e0cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e5e10: 0x10000063  b           . + 4 + (0x63 << 2)
    ctx->pc = 0x1E5E10u;
    {
        const bool branch_taken_0x1e5e10 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5e10) {
            ctx->pc = 0x1E5FA0u;
            goto label_1e5fa0;
        }
    }
    ctx->pc = 0x1E5E18u;
label_1e5e18:
    // 0x1e5e18: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e5e18u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e5e1c: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e5e1cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e5e20: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e5e20u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e5e24: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e5e24u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e5e28: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e5e28u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e5e2c: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e5e2cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e5e30: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1e5e30u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1e5e34: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1e5e34u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e5e38: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e5e38u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e5e3c: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E5E3Cu;
    {
        const bool branch_taken_0x1e5e3c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5e3c) {
            ctx->pc = 0x1E5E58u;
            goto label_1e5e58;
        }
    }
    ctx->pc = 0x1E5E44u;
    // 0x1e5e44: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e5e44u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e5e48: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e5e48u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e5e4c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e5e4cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e5e50: 0x10000053  b           . + 4 + (0x53 << 2)
    ctx->pc = 0x1E5E50u;
    {
        const bool branch_taken_0x1e5e50 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5e50) {
            ctx->pc = 0x1E5FA0u;
            goto label_1e5fa0;
        }
    }
    ctx->pc = 0x1E5E58u;
label_1e5e58:
    // 0x1e5e58: 0x8fc4001c  lw          $a0, 0x1C($fp)
    ctx->pc = 0x1e5e58u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e5e5c: 0x24050018  addiu       $a1, $zero, 0x18
    ctx->pc = 0x1e5e5cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 24));
    // 0x1e5e60: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E5E60u;
    SET_GPR_U32(ctx, 31, 0x1E5E68u);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5E68u; }
        if (ctx->pc != 0x1E5E68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5E68u; }
        if (ctx->pc != 0x1E5E68u) { return; }
    }
    ctx->pc = 0x1E5E68u;
label_1e5e68:
    // 0x1e5e68: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1e5e68u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1e5e6c: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e5e6cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e5e70: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E5E70u;
    {
        const bool branch_taken_0x1e5e70 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e5e70) {
            ctx->pc = 0x1E5E8Cu;
            goto label_1e5e8c;
        }
    }
    ctx->pc = 0x1E5E78u;
    // 0x1e5e78: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e5e78u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e5e7c: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e5e7cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e5e80: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e5e80u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e5e84: 0x10000046  b           . + 4 + (0x46 << 2)
    ctx->pc = 0x1E5E84u;
    {
        const bool branch_taken_0x1e5e84 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5e84) {
            ctx->pc = 0x1E5FA0u;
            goto label_1e5fa0;
        }
    }
    ctx->pc = 0x1E5E8Cu;
label_1e5e8c:
    // 0x1e5e8c: 0x8fc40018  lw          $a0, 0x18($fp)
    ctx->pc = 0x1e5e8cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e5e90: 0x24050018  addiu       $a1, $zero, 0x18
    ctx->pc = 0x1e5e90u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 24));
    // 0x1e5e94: 0xc07cc3c  jal         func_1F30F0
    ctx->pc = 0x1E5E94u;
    SET_GPR_U32(ctx, 31, 0x1E5E9Cu);
    ctx->pc = 0x1F30F0u;
    if (runtime->hasFunction(0x1F30F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F30F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5E9Cu; }
        if (ctx->pc != 0x1E5E9Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F30F0_0x1f30f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5E9Cu; }
        if (ctx->pc != 0x1E5E9Cu) { return; }
    }
    ctx->pc = 0x1E5E9Cu;
label_1e5e9c:
    // 0x1e5e9c: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1e5e9cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1e5ea0: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e5ea0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e5ea4: 0x8fc50004  lw          $a1, 0x4($fp)
    ctx->pc = 0x1e5ea4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e5ea8: 0x24060010  addiu       $a2, $zero, 0x10
    ctx->pc = 0x1e5ea8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1e5eac: 0xc042d7e  jal         func_10B5F8
    ctx->pc = 0x1E5EACu;
    SET_GPR_U32(ctx, 31, 0x1E5EB4u);
    ctx->pc = 0x10B5F8u;
    if (runtime->hasFunction(0x10B5F8u)) {
        auto targetFn = runtime->lookupFunction(0x10B5F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5EB4u; }
        if (ctx->pc != 0x1E5EB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B5F8_0x10b5f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5EB4u; }
        if (ctx->pc != 0x1E5EB4u) { return; }
    }
    ctx->pc = 0x1E5EB4u;
label_1e5eb4:
    // 0x1e5eb4: 0x8fc50014  lw          $a1, 0x14($fp)
    ctx->pc = 0x1e5eb4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e5eb8: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1e5eb8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e5ebc: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1e5ebcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1e5ec0: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1e5ec0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1e5ec4: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1e5ec4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e5ec8: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1e5ec8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1e5ecc: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1e5eccu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1e5ed0: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1e5ed0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e5ed4: 0x8fc30008  lw          $v1, 0x8($fp)
    ctx->pc = 0x1e5ed4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e5ed8: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1e5ed8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1e5edc: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e5edcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e5ee0: 0x21203  sra         $v0, $v0, 8
    ctx->pc = 0x1e5ee0u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 8));
    // 0x1e5ee4: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1e5ee4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e5ee8: 0x8fc30008  lw          $v1, 0x8($fp)
    ctx->pc = 0x1e5ee8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e5eec: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1e5eecu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1e5ef0: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e5ef0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e5ef4: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1e5ef4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1e5ef8: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1e5ef8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e5efc: 0xaca20010  sw          $v0, 0x10($a1)
    ctx->pc = 0x1e5efcu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 16), GPR_U32(ctx, 2));
    // 0x1e5f00: 0x8fc50014  lw          $a1, 0x14($fp)
    ctx->pc = 0x1e5f00u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e5f04: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e5f04u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e5f08: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1e5f08u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1e5f0c: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1e5f0cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1e5f10: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e5f10u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e5f14: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1e5f14u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1e5f18: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1e5f18u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1e5f1c: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1e5f1cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e5f20: 0x8fc3000c  lw          $v1, 0xC($fp)
    ctx->pc = 0x1e5f20u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e5f24: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1e5f24u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1e5f28: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e5f28u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e5f2c: 0x21203  sra         $v0, $v0, 8
    ctx->pc = 0x1e5f2cu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 8));
    // 0x1e5f30: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1e5f30u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e5f34: 0x8fc3000c  lw          $v1, 0xC($fp)
    ctx->pc = 0x1e5f34u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e5f38: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1e5f38u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1e5f3c: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e5f3cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e5f40: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1e5f40u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1e5f44: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1e5f44u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e5f48: 0xaca20014  sw          $v0, 0x14($a1)
    ctx->pc = 0x1e5f48u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 20), GPR_U32(ctx, 2));
    // 0x1e5f4c: 0x8fc4001c  lw          $a0, 0x1C($fp)
    ctx->pc = 0x1e5f4cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e5f50: 0x8fc50018  lw          $a1, 0x18($fp)
    ctx->pc = 0x1e5f50u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e5f54: 0x3406b000  ori         $a2, $zero, 0xB000
    ctx->pc = 0x1e5f54u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)45056);
    // 0x1e5f58: 0x24070018  addiu       $a3, $zero, 0x18
    ctx->pc = 0x1e5f58u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 24));
    // 0x1e5f5c: 0x24080025  addiu       $t0, $zero, 0x25
    ctx->pc = 0x1e5f5cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 37));
    // 0x1e5f60: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1e5f60u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e5f64: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E5F64u;
    SET_GPR_U32(ctx, 31, 0x1E5F6Cu);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5F6Cu; }
        if (ctx->pc != 0x1E5F6Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5F6Cu; }
        if (ctx->pc != 0x1E5F6Cu) { return; }
    }
    ctx->pc = 0x1E5F6Cu;
label_1e5f6c:
    // 0x1e5f6c: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E5F6Cu;
    {
        const bool branch_taken_0x1e5f6c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5f6c) {
            ctx->pc = 0x1E5F88u;
            goto label_1e5f88;
        }
    }
    ctx->pc = 0x1E5F74u;
    // 0x1e5f74: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e5f74u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e5f78: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e5f78u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e5f7c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e5f7cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e5f80: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1E5F80u;
    {
        const bool branch_taken_0x1e5f80 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5f80) {
            ctx->pc = 0x1E5FA0u;
            goto label_1e5fa0;
        }
    }
    ctx->pc = 0x1E5F88u;
label_1e5f88:
    // 0x1e5f88: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1e5f88u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e5f8c: 0x24050029  addiu       $a1, $zero, 0x29
    ctx->pc = 0x1e5f8cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 41));
    // 0x1e5f90: 0x8fc60010  lw          $a2, 0x10($fp)
    ctx->pc = 0x1e5f90u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e5f94: 0xc076ad5  jal         func_1DAB54
    ctx->pc = 0x1E5F94u;
    SET_GPR_U32(ctx, 31, 0x1E5F9Cu);
    ctx->pc = 0x1DAB54u;
    if (runtime->hasFunction(0x1DAB54u)) {
        auto targetFn = runtime->lookupFunction(0x1DAB54u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5F9Cu; }
        if (ctx->pc != 0x1E5F9Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DAB54_0x1dab54(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5F9Cu; }
        if (ctx->pc != 0x1E5F9Cu) { return; }
    }
    ctx->pc = 0x1E5F9Cu;
label_1e5f9c:
    // 0x1e5f9c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1e5f9cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1e5fa0:
    // 0x1e5fa0: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e5fa0u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e5fa4: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1e5fa4u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1e5fa8: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1e5fa8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1e5fac: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1e5facu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1e5fb0: 0x3e00008  jr          $ra
    ctx->pc = 0x1E5FB0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E5060u: goto label_1e5060;
            case 0x1E5074u: goto label_1e5074;
            case 0x1E50B4u: goto label_1e50b4;
            case 0x1E50C4u: goto label_1e50c4;
            case 0x1E50E8u: goto label_1e50e8;
            case 0x1E50FCu: goto label_1e50fc;
            case 0x1E5120u: goto label_1e5120;
            case 0x1E5134u: goto label_1e5134;
            case 0x1E5148u: goto label_1e5148;
            case 0x1E5178u: goto label_1e5178;
            case 0x1E5194u: goto label_1e5194;
            case 0x1E5198u: goto label_1e5198;
            case 0x1E5238u: goto label_1e5238;
            case 0x1E524Cu: goto label_1e524c;
            case 0x1E528Cu: goto label_1e528c;
            case 0x1E52B0u: goto label_1e52b0;
            case 0x1E52D4u: goto label_1e52d4;
            case 0x1E530Cu: goto label_1e530c;
            case 0x1E536Cu: goto label_1e536c;
            case 0x1E5388u: goto label_1e5388;
            case 0x1E5410u: goto label_1e5410;
            case 0x1E5424u: goto label_1e5424;
            case 0x1E5464u: goto label_1e5464;
            case 0x1E5480u: goto label_1e5480;
            case 0x1E5484u: goto label_1e5484;
            case 0x1E54F8u: goto label_1e54f8;
            case 0x1E550Cu: goto label_1e550c;
            case 0x1E554Cu: goto label_1e554c;
            case 0x1E5574u: goto label_1e5574;
            case 0x1E5598u: goto label_1e5598;
            case 0x1E55C8u: goto label_1e55c8;
            case 0x1E55ECu: goto label_1e55ec;
            case 0x1E5600u: goto label_1e5600;
            case 0x1E566Cu: goto label_1e566c;
            case 0x1E568Cu: goto label_1e568c;
            case 0x1E5748u: goto label_1e5748;
            case 0x1E575Cu: goto label_1e575c;
            case 0x1E57A0u: goto label_1e57a0;
            case 0x1E57BCu: goto label_1e57bc;
            case 0x1E57C0u: goto label_1e57c0;
            case 0x1E5820u: goto label_1e5820;
            case 0x1E5834u: goto label_1e5834;
            case 0x1E5874u: goto label_1e5874;
            case 0x1E5884u: goto label_1e5884;
            case 0x1E58A8u: goto label_1e58a8;
            case 0x1E58C8u: goto label_1e58c8;
            case 0x1E58E4u: goto label_1e58e4;
            case 0x1E58E8u: goto label_1e58e8;
            case 0x1E5948u: goto label_1e5948;
            case 0x1E595Cu: goto label_1e595c;
            case 0x1E599Cu: goto label_1e599c;
            case 0x1E59ACu: goto label_1e59ac;
            case 0x1E59D0u: goto label_1e59d0;
            case 0x1E59F0u: goto label_1e59f0;
            case 0x1E5A0Cu: goto label_1e5a0c;
            case 0x1E5A10u: goto label_1e5a10;
            case 0x1E5A80u: goto label_1e5a80;
            case 0x1E5A94u: goto label_1e5a94;
            case 0x1E5AD4u: goto label_1e5ad4;
            case 0x1E5AE4u: goto label_1e5ae4;
            case 0x1E5B08u: goto label_1e5b08;
            case 0x1E5B1Cu: goto label_1e5b1c;
            case 0x1E5B40u: goto label_1e5b40;
            case 0x1E5B54u: goto label_1e5b54;
            case 0x1E5B68u: goto label_1e5b68;
            case 0x1E5B98u: goto label_1e5b98;
            case 0x1E5BB4u: goto label_1e5bb4;
            case 0x1E5BB8u: goto label_1e5bb8;
            case 0x1E5C2Cu: goto label_1e5c2c;
            case 0x1E5C40u: goto label_1e5c40;
            case 0x1E5C80u: goto label_1e5c80;
            case 0x1E5C90u: goto label_1e5c90;
            case 0x1E5CB4u: goto label_1e5cb4;
            case 0x1E5CC8u: goto label_1e5cc8;
            case 0x1E5CECu: goto label_1e5cec;
            case 0x1E5D00u: goto label_1e5d00;
            case 0x1E5D14u: goto label_1e5d14;
            case 0x1E5D48u: goto label_1e5d48;
            case 0x1E5D64u: goto label_1e5d64;
            case 0x1E5D78u: goto label_1e5d78;
            case 0x1E5D94u: goto label_1e5d94;
            case 0x1E5E04u: goto label_1e5e04;
            case 0x1E5E18u: goto label_1e5e18;
            case 0x1E5E58u: goto label_1e5e58;
            case 0x1E5E68u: goto label_1e5e68;
            case 0x1E5E8Cu: goto label_1e5e8c;
            case 0x1E5E9Cu: goto label_1e5e9c;
            case 0x1E5EB4u: goto label_1e5eb4;
            case 0x1E5F6Cu: goto label_1e5f6c;
            case 0x1E5F88u: goto label_1e5f88;
            case 0x1E5F9Cu: goto label_1e5f9c;
            case 0x1E5FA0u: goto label_1e5fa0;
            case 0x1E6008u: goto label_1e6008;
            case 0x1E601Cu: goto label_1e601c;
            case 0x1E605Cu: goto label_1e605c;
            case 0x1E6068u: goto label_1e6068;
            case 0x1E6084u: goto label_1e6084;
            case 0x1E6094u: goto label_1e6094;
            case 0x1E60B8u: goto label_1e60b8;
            case 0x1E60CCu: goto label_1e60cc;
            case 0x1E60F0u: goto label_1e60f0;
            case 0x1E6104u: goto label_1e6104;
            case 0x1E6118u: goto label_1e6118;
            case 0x1E613Cu: goto label_1e613c;
            case 0x1E6158u: goto label_1e6158;
            case 0x1E616Cu: goto label_1e616c;
            case 0x1E6170u: goto label_1e6170;
            case 0x1E61D4u: goto label_1e61d4;
            case 0x1E61E8u: goto label_1e61e8;
            case 0x1E6228u: goto label_1e6228;
            case 0x1E623Cu: goto label_1e623c;
            case 0x1E6240u: goto label_1e6240;
            case 0x1E62A4u: goto label_1e62a4;
            case 0x1E62B8u: goto label_1e62b8;
            case 0x1E62F8u: goto label_1e62f8;
            case 0x1E630Cu: goto label_1e630c;
            case 0x1E6310u: goto label_1e6310;
            case 0x1E6374u: goto label_1e6374;
            case 0x1E6388u: goto label_1e6388;
            case 0x1E63C8u: goto label_1e63c8;
            case 0x1E63DCu: goto label_1e63dc;
            case 0x1E63E0u: goto label_1e63e0;
            case 0x1E6448u: goto label_1e6448;
            case 0x1E645Cu: goto label_1e645c;
            case 0x1E649Cu: goto label_1e649c;
            case 0x1E64B4u: goto label_1e64b4;
            case 0x1E64C4u: goto label_1e64c4;
            case 0x1E64E8u: goto label_1e64e8;
            case 0x1E64FCu: goto label_1e64fc;
            case 0x1E6520u: goto label_1e6520;
            case 0x1E6534u: goto label_1e6534;
            case 0x1E6548u: goto label_1e6548;
            case 0x1E656Cu: goto label_1e656c;
            case 0x1E6588u: goto label_1e6588;
            case 0x1E658Cu: goto label_1e658c;
            case 0x1E65F8u: goto label_1e65f8;
            case 0x1E660Cu: goto label_1e660c;
            case 0x1E664Cu: goto label_1e664c;
            case 0x1E6664u: goto label_1e6664;
            case 0x1E6674u: goto label_1e6674;
            case 0x1E6698u: goto label_1e6698;
            case 0x1E66ACu: goto label_1e66ac;
            case 0x1E66D0u: goto label_1e66d0;
            case 0x1E66E4u: goto label_1e66e4;
            case 0x1E66FCu: goto label_1e66fc;
            case 0x1E6718u: goto label_1e6718;
            case 0x1E6744u: goto label_1e6744;
            case 0x1E6760u: goto label_1e6760;
            case 0x1E6764u: goto label_1e6764;
            case 0x1E67D0u: goto label_1e67d0;
            case 0x1E67E4u: goto label_1e67e4;
            case 0x1E6824u: goto label_1e6824;
            case 0x1E6834u: goto label_1e6834;
            case 0x1E6858u: goto label_1e6858;
            case 0x1E6868u: goto label_1e6868;
            case 0x1E688Cu: goto label_1e688c;
            case 0x1E68A0u: goto label_1e68a0;
            case 0x1E68ACu: goto label_1e68ac;
            case 0x1E68BCu: goto label_1e68bc;
            case 0x1E68D4u: goto label_1e68d4;
            case 0x1E6904u: goto label_1e6904;
            case 0x1E6970u: goto label_1e6970;
            case 0x1E6988u: goto label_1e6988;
            case 0x1E699Cu: goto label_1e699c;
            case 0x1E69B0u: goto label_1e69b0;
            case 0x1E69BCu: goto label_1e69bc;
            case 0x1E69D0u: goto label_1e69d0;
            case 0x1E69F4u: goto label_1e69f4;
            case 0x1E6A08u: goto label_1e6a08;
            case 0x1E6A30u: goto label_1e6a30;
            case 0x1E6A4Cu: goto label_1e6a4c;
            case 0x1E6AC8u: goto label_1e6ac8;
            case 0x1E6AE0u: goto label_1e6ae0;
            case 0x1E6AF4u: goto label_1e6af4;
            case 0x1E6B24u: goto label_1e6b24;
            case 0x1E6B38u: goto label_1e6b38;
            case 0x1E6B6Cu: goto label_1e6b6c;
            case 0x1E6B88u: goto label_1e6b88;
            case 0x1E6BCCu: goto label_1e6bcc;
            case 0x1E6BE8u: goto label_1e6be8;
            case 0x1E6BFCu: goto label_1e6bfc;
            case 0x1E6C30u: goto label_1e6c30;
            case 0x1E6C4Cu: goto label_1e6c4c;
            case 0x1E6C58u: goto label_1e6c58;
            case 0x1E6C6Cu: goto label_1e6c6c;
            case 0x1E6C84u: goto label_1e6c84;
            case 0x1E6CB4u: goto label_1e6cb4;
            case 0x1E6CD8u: goto label_1e6cd8;
            case 0x1E6CECu: goto label_1e6cec;
            case 0x1E6CF0u: goto label_1e6cf0;
            case 0x1E6D5Cu: goto label_1e6d5c;
            case 0x1E6D70u: goto label_1e6d70;
            case 0x1E6DB0u: goto label_1e6db0;
            case 0x1E6DC0u: goto label_1e6dc0;
            case 0x1E6DE4u: goto label_1e6de4;
            case 0x1E6DF4u: goto label_1e6df4;
            case 0x1E6E18u: goto label_1e6e18;
            case 0x1E6E2Cu: goto label_1e6e2c;
            case 0x1E6E38u: goto label_1e6e38;
            case 0x1E6E48u: goto label_1e6e48;
            case 0x1E6E60u: goto label_1e6e60;
            case 0x1E6E90u: goto label_1e6e90;
            case 0x1E6EFCu: goto label_1e6efc;
            case 0x1E6F14u: goto label_1e6f14;
            case 0x1E6F28u: goto label_1e6f28;
            case 0x1E6F3Cu: goto label_1e6f3c;
            case 0x1E6F48u: goto label_1e6f48;
            case 0x1E6F5Cu: goto label_1e6f5c;
            case 0x1E6F80u: goto label_1e6f80;
            case 0x1E6F94u: goto label_1e6f94;
            case 0x1E6FBCu: goto label_1e6fbc;
            case 0x1E6FD8u: goto label_1e6fd8;
            case 0x1E7054u: goto label_1e7054;
            case 0x1E706Cu: goto label_1e706c;
            case 0x1E7080u: goto label_1e7080;
            case 0x1E70B0u: goto label_1e70b0;
            case 0x1E70C4u: goto label_1e70c4;
            case 0x1E70F8u: goto label_1e70f8;
            case 0x1E7114u: goto label_1e7114;
            case 0x1E7158u: goto label_1e7158;
            case 0x1E7174u: goto label_1e7174;
            case 0x1E7188u: goto label_1e7188;
            case 0x1E71BCu: goto label_1e71bc;
            case 0x1E71D8u: goto label_1e71d8;
            case 0x1E71E4u: goto label_1e71e4;
            case 0x1E71F8u: goto label_1e71f8;
            case 0x1E7210u: goto label_1e7210;
            case 0x1E7240u: goto label_1e7240;
            case 0x1E7264u: goto label_1e7264;
            case 0x1E7278u: goto label_1e7278;
            case 0x1E727Cu: goto label_1e727c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E5FB8u;
    // 0x1e5fb8: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1e5fb8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1e5fbc: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1e5fbcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1e5fc0: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1e5fc0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1e5fc4: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e5fc4u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e5fc8: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e5fc8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e5fcc: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e5fccu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e5fd0: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e5fd0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e5fd4: 0xafc00014  sw          $zero, 0x14($fp)
    ctx->pc = 0x1e5fd4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 0));
    // 0x1e5fd8: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e5fd8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e5fdc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e5fdcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e5fe0: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E5FE0u;
    {
        const bool branch_taken_0x1e5fe0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e5fe0) {
            ctx->pc = 0x1E6008u;
            goto label_1e6008;
        }
    }
    ctx->pc = 0x1E5FE8u;
    // 0x1e5fe8: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e5fe8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e5fec: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e5fecu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e5ff0: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e5ff0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e5ff4: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e5ff4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e5ff8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e5ff8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e5ffc: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e5ffcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e6000: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E6000u;
    {
        const bool branch_taken_0x1e6000 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e6000) {
            ctx->pc = 0x1E601Cu;
            goto label_1e601c;
        }
    }
    ctx->pc = 0x1E6008u;
label_1e6008:
    // 0x1e6008: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e6008u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e600c: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e600cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e6010: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e6010u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e6014: 0x10000056  b           . + 4 + (0x56 << 2)
    ctx->pc = 0x1E6014u;
    {
        const bool branch_taken_0x1e6014 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6014) {
            ctx->pc = 0x1E6170u;
            goto label_1e6170;
        }
    }
    ctx->pc = 0x1E601Cu;
label_1e601c:
    // 0x1e601c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e601cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e6020: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e6020u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e6024: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e6024u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e6028: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e6028u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e602c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e602cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e6030: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e6030u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e6034: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1e6034u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1e6038: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e6038u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e603c: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e603cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e6040: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E6040u;
    {
        const bool branch_taken_0x1e6040 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6040) {
            ctx->pc = 0x1E605Cu;
            goto label_1e605c;
        }
    }
    ctx->pc = 0x1E6048u;
    // 0x1e6048: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e6048u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e604c: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e604cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e6050: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e6050u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e6054: 0x10000046  b           . + 4 + (0x46 << 2)
    ctx->pc = 0x1E6054u;
    {
        const bool branch_taken_0x1e6054 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6054) {
            ctx->pc = 0x1E6170u;
            goto label_1e6170;
        }
    }
    ctx->pc = 0x1E605Cu;
label_1e605c:
    // 0x1e605c: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1e605cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e6060: 0xc042c56  jal         func_10B158
    ctx->pc = 0x1E6060u;
    SET_GPR_U32(ctx, 31, 0x1E6068u);
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6068u; }
        if (ctx->pc != 0x1E6068u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6068u; }
        if (ctx->pc != 0x1E6068u) { return; }
    }
    ctx->pc = 0x1E6068u;
label_1e6068:
    // 0x1e6068: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1e6068u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1e606c: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e606cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e6070: 0x2c420369  sltiu       $v0, $v0, 0x369
    ctx->pc = 0x1e6070u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)873) ? 1 : 0);
    // 0x1e6074: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1E6074u;
    {
        const bool branch_taken_0x1e6074 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e6074) {
            ctx->pc = 0x1E6084u;
            goto label_1e6084;
        }
    }
    ctx->pc = 0x1E607Cu;
    // 0x1e607c: 0x24020368  addiu       $v0, $zero, 0x368
    ctx->pc = 0x1e607cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 872));
    // 0x1e6080: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1e6080u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
label_1e6084:
    // 0x1e6084: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e6084u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e6088: 0x8fc50018  lw          $a1, 0x18($fp)
    ctx->pc = 0x1e6088u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e608c: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E608Cu;
    SET_GPR_U32(ctx, 31, 0x1E6094u);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6094u; }
        if (ctx->pc != 0x1E6094u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6094u; }
        if (ctx->pc != 0x1E6094u) { return; }
    }
    ctx->pc = 0x1E6094u;
label_1e6094:
    // 0x1e6094: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1e6094u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1e6098: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e6098u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e609c: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E609Cu;
    {
        const bool branch_taken_0x1e609c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e609c) {
            ctx->pc = 0x1E60B8u;
            goto label_1e60b8;
        }
    }
    ctx->pc = 0x1E60A4u;
    // 0x1e60a4: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e60a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e60a8: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e60a8u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e60ac: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e60acu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e60b0: 0x1000002f  b           . + 4 + (0x2F << 2)
    ctx->pc = 0x1E60B0u;
    {
        const bool branch_taken_0x1e60b0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e60b0) {
            ctx->pc = 0x1E6170u;
            goto label_1e6170;
        }
    }
    ctx->pc = 0x1E60B8u;
label_1e60b8:
    // 0x1e60b8: 0x97c20018  lhu         $v0, 0x18($fp)
    ctx->pc = 0x1e60b8u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e60bc: 0x8fc40010  lw          $a0, 0x10($fp)
    ctx->pc = 0x1e60bcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e60c0: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1e60c0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e60c4: 0xc07cc3c  jal         func_1F30F0
    ctx->pc = 0x1E60C4u;
    SET_GPR_U32(ctx, 31, 0x1E60CCu);
    ctx->pc = 0x1F30F0u;
    if (runtime->hasFunction(0x1F30F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F30F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E60CCu; }
        if (ctx->pc != 0x1E60CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F30F0_0x1f30f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E60CCu; }
        if (ctx->pc != 0x1E60CCu) { return; }
    }
    ctx->pc = 0x1E60CCu;
label_1e60cc:
    // 0x1e60cc: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1e60ccu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1e60d0: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e60d0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e60d4: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1E60D4u;
    {
        const bool branch_taken_0x1e60d4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e60d4) {
            ctx->pc = 0x1E6104u;
            goto label_1e6104;
        }
    }
    ctx->pc = 0x1E60DCu;
    // 0x1e60dc: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e60dcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e60e0: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1e60e0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1e60e4: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e60e4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e60e8: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1E60E8u;
    SET_GPR_U32(ctx, 31, 0x1E60F0u);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E60F0u; }
        if (ctx->pc != 0x1E60F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E60F0u; }
        if (ctx->pc != 0x1E60F0u) { return; }
    }
    ctx->pc = 0x1E60F0u;
label_1e60f0:
    // 0x1e60f0: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e60f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e60f4: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e60f4u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e60f8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e60f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e60fc: 0x1000001c  b           . + 4 + (0x1C << 2)
    ctx->pc = 0x1E60FCu;
    {
        const bool branch_taken_0x1e60fc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e60fc) {
            ctx->pc = 0x1E6170u;
            goto label_1e6170;
        }
    }
    ctx->pc = 0x1E6104u;
label_1e6104:
    // 0x1e6104: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1e6104u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e6108: 0x8fc50004  lw          $a1, 0x4($fp)
    ctx->pc = 0x1e6108u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e610c: 0x8fc60018  lw          $a2, 0x18($fp)
    ctx->pc = 0x1e610cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e6110: 0xc042d7e  jal         func_10B5F8
    ctx->pc = 0x1E6110u;
    SET_GPR_U32(ctx, 31, 0x1E6118u);
    ctx->pc = 0x10B5F8u;
    if (runtime->hasFunction(0x10B5F8u)) {
        auto targetFn = runtime->lookupFunction(0x10B5F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6118u; }
        if (ctx->pc != 0x1E6118u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B5F8_0x10b5f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6118u; }
        if (ctx->pc != 0x1E6118u) { return; }
    }
    ctx->pc = 0x1E6118u;
label_1e6118:
    // 0x1e6118: 0x97c20018  lhu         $v0, 0x18($fp)
    ctx->pc = 0x1e6118u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e611c: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e611cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e6120: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e6120u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e6124: 0x3406b000  ori         $a2, $zero, 0xB000
    ctx->pc = 0x1e6124u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)45056);
    // 0x1e6128: 0x40382d  daddu       $a3, $v0, $zero
    ctx->pc = 0x1e6128u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e612c: 0x24080034  addiu       $t0, $zero, 0x34
    ctx->pc = 0x1e612cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 52));
    // 0x1e6130: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1e6130u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e6134: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E6134u;
    SET_GPR_U32(ctx, 31, 0x1E613Cu);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E613Cu; }
        if (ctx->pc != 0x1E613Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E613Cu; }
        if (ctx->pc != 0x1E613Cu) { return; }
    }
    ctx->pc = 0x1E613Cu;
label_1e613c:
    // 0x1e613c: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E613Cu;
    {
        const bool branch_taken_0x1e613c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e613c) {
            ctx->pc = 0x1E6158u;
            goto label_1e6158;
        }
    }
    ctx->pc = 0x1E6144u;
    // 0x1e6144: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e6144u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e6148: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e6148u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e614c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e614cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e6150: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1E6150u;
    {
        const bool branch_taken_0x1e6150 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6150) {
            ctx->pc = 0x1E6170u;
            goto label_1e6170;
        }
    }
    ctx->pc = 0x1E6158u;
label_1e6158:
    // 0x1e6158: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1e6158u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e615c: 0x2405002a  addiu       $a1, $zero, 0x2A
    ctx->pc = 0x1e615cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 42));
    // 0x1e6160: 0x8fc60008  lw          $a2, 0x8($fp)
    ctx->pc = 0x1e6160u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e6164: 0xc076ad5  jal         func_1DAB54
    ctx->pc = 0x1E6164u;
    SET_GPR_U32(ctx, 31, 0x1E616Cu);
    ctx->pc = 0x1DAB54u;
    if (runtime->hasFunction(0x1DAB54u)) {
        auto targetFn = runtime->lookupFunction(0x1DAB54u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E616Cu; }
        if (ctx->pc != 0x1E616Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DAB54_0x1dab54(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E616Cu; }
        if (ctx->pc != 0x1E616Cu) { return; }
    }
    ctx->pc = 0x1E616Cu;
label_1e616c:
    // 0x1e616c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1e616cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1e6170:
    // 0x1e6170: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e6170u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e6174: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1e6174u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1e6178: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1e6178u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1e617c: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1e617cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1e6180: 0x3e00008  jr          $ra
    ctx->pc = 0x1E6180u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E5060u: goto label_1e5060;
            case 0x1E5074u: goto label_1e5074;
            case 0x1E50B4u: goto label_1e50b4;
            case 0x1E50C4u: goto label_1e50c4;
            case 0x1E50E8u: goto label_1e50e8;
            case 0x1E50FCu: goto label_1e50fc;
            case 0x1E5120u: goto label_1e5120;
            case 0x1E5134u: goto label_1e5134;
            case 0x1E5148u: goto label_1e5148;
            case 0x1E5178u: goto label_1e5178;
            case 0x1E5194u: goto label_1e5194;
            case 0x1E5198u: goto label_1e5198;
            case 0x1E5238u: goto label_1e5238;
            case 0x1E524Cu: goto label_1e524c;
            case 0x1E528Cu: goto label_1e528c;
            case 0x1E52B0u: goto label_1e52b0;
            case 0x1E52D4u: goto label_1e52d4;
            case 0x1E530Cu: goto label_1e530c;
            case 0x1E536Cu: goto label_1e536c;
            case 0x1E5388u: goto label_1e5388;
            case 0x1E5410u: goto label_1e5410;
            case 0x1E5424u: goto label_1e5424;
            case 0x1E5464u: goto label_1e5464;
            case 0x1E5480u: goto label_1e5480;
            case 0x1E5484u: goto label_1e5484;
            case 0x1E54F8u: goto label_1e54f8;
            case 0x1E550Cu: goto label_1e550c;
            case 0x1E554Cu: goto label_1e554c;
            case 0x1E5574u: goto label_1e5574;
            case 0x1E5598u: goto label_1e5598;
            case 0x1E55C8u: goto label_1e55c8;
            case 0x1E55ECu: goto label_1e55ec;
            case 0x1E5600u: goto label_1e5600;
            case 0x1E566Cu: goto label_1e566c;
            case 0x1E568Cu: goto label_1e568c;
            case 0x1E5748u: goto label_1e5748;
            case 0x1E575Cu: goto label_1e575c;
            case 0x1E57A0u: goto label_1e57a0;
            case 0x1E57BCu: goto label_1e57bc;
            case 0x1E57C0u: goto label_1e57c0;
            case 0x1E5820u: goto label_1e5820;
            case 0x1E5834u: goto label_1e5834;
            case 0x1E5874u: goto label_1e5874;
            case 0x1E5884u: goto label_1e5884;
            case 0x1E58A8u: goto label_1e58a8;
            case 0x1E58C8u: goto label_1e58c8;
            case 0x1E58E4u: goto label_1e58e4;
            case 0x1E58E8u: goto label_1e58e8;
            case 0x1E5948u: goto label_1e5948;
            case 0x1E595Cu: goto label_1e595c;
            case 0x1E599Cu: goto label_1e599c;
            case 0x1E59ACu: goto label_1e59ac;
            case 0x1E59D0u: goto label_1e59d0;
            case 0x1E59F0u: goto label_1e59f0;
            case 0x1E5A0Cu: goto label_1e5a0c;
            case 0x1E5A10u: goto label_1e5a10;
            case 0x1E5A80u: goto label_1e5a80;
            case 0x1E5A94u: goto label_1e5a94;
            case 0x1E5AD4u: goto label_1e5ad4;
            case 0x1E5AE4u: goto label_1e5ae4;
            case 0x1E5B08u: goto label_1e5b08;
            case 0x1E5B1Cu: goto label_1e5b1c;
            case 0x1E5B40u: goto label_1e5b40;
            case 0x1E5B54u: goto label_1e5b54;
            case 0x1E5B68u: goto label_1e5b68;
            case 0x1E5B98u: goto label_1e5b98;
            case 0x1E5BB4u: goto label_1e5bb4;
            case 0x1E5BB8u: goto label_1e5bb8;
            case 0x1E5C2Cu: goto label_1e5c2c;
            case 0x1E5C40u: goto label_1e5c40;
            case 0x1E5C80u: goto label_1e5c80;
            case 0x1E5C90u: goto label_1e5c90;
            case 0x1E5CB4u: goto label_1e5cb4;
            case 0x1E5CC8u: goto label_1e5cc8;
            case 0x1E5CECu: goto label_1e5cec;
            case 0x1E5D00u: goto label_1e5d00;
            case 0x1E5D14u: goto label_1e5d14;
            case 0x1E5D48u: goto label_1e5d48;
            case 0x1E5D64u: goto label_1e5d64;
            case 0x1E5D78u: goto label_1e5d78;
            case 0x1E5D94u: goto label_1e5d94;
            case 0x1E5E04u: goto label_1e5e04;
            case 0x1E5E18u: goto label_1e5e18;
            case 0x1E5E58u: goto label_1e5e58;
            case 0x1E5E68u: goto label_1e5e68;
            case 0x1E5E8Cu: goto label_1e5e8c;
            case 0x1E5E9Cu: goto label_1e5e9c;
            case 0x1E5EB4u: goto label_1e5eb4;
            case 0x1E5F6Cu: goto label_1e5f6c;
            case 0x1E5F88u: goto label_1e5f88;
            case 0x1E5F9Cu: goto label_1e5f9c;
            case 0x1E5FA0u: goto label_1e5fa0;
            case 0x1E6008u: goto label_1e6008;
            case 0x1E601Cu: goto label_1e601c;
            case 0x1E605Cu: goto label_1e605c;
            case 0x1E6068u: goto label_1e6068;
            case 0x1E6084u: goto label_1e6084;
            case 0x1E6094u: goto label_1e6094;
            case 0x1E60B8u: goto label_1e60b8;
            case 0x1E60CCu: goto label_1e60cc;
            case 0x1E60F0u: goto label_1e60f0;
            case 0x1E6104u: goto label_1e6104;
            case 0x1E6118u: goto label_1e6118;
            case 0x1E613Cu: goto label_1e613c;
            case 0x1E6158u: goto label_1e6158;
            case 0x1E616Cu: goto label_1e616c;
            case 0x1E6170u: goto label_1e6170;
            case 0x1E61D4u: goto label_1e61d4;
            case 0x1E61E8u: goto label_1e61e8;
            case 0x1E6228u: goto label_1e6228;
            case 0x1E623Cu: goto label_1e623c;
            case 0x1E6240u: goto label_1e6240;
            case 0x1E62A4u: goto label_1e62a4;
            case 0x1E62B8u: goto label_1e62b8;
            case 0x1E62F8u: goto label_1e62f8;
            case 0x1E630Cu: goto label_1e630c;
            case 0x1E6310u: goto label_1e6310;
            case 0x1E6374u: goto label_1e6374;
            case 0x1E6388u: goto label_1e6388;
            case 0x1E63C8u: goto label_1e63c8;
            case 0x1E63DCu: goto label_1e63dc;
            case 0x1E63E0u: goto label_1e63e0;
            case 0x1E6448u: goto label_1e6448;
            case 0x1E645Cu: goto label_1e645c;
            case 0x1E649Cu: goto label_1e649c;
            case 0x1E64B4u: goto label_1e64b4;
            case 0x1E64C4u: goto label_1e64c4;
            case 0x1E64E8u: goto label_1e64e8;
            case 0x1E64FCu: goto label_1e64fc;
            case 0x1E6520u: goto label_1e6520;
            case 0x1E6534u: goto label_1e6534;
            case 0x1E6548u: goto label_1e6548;
            case 0x1E656Cu: goto label_1e656c;
            case 0x1E6588u: goto label_1e6588;
            case 0x1E658Cu: goto label_1e658c;
            case 0x1E65F8u: goto label_1e65f8;
            case 0x1E660Cu: goto label_1e660c;
            case 0x1E664Cu: goto label_1e664c;
            case 0x1E6664u: goto label_1e6664;
            case 0x1E6674u: goto label_1e6674;
            case 0x1E6698u: goto label_1e6698;
            case 0x1E66ACu: goto label_1e66ac;
            case 0x1E66D0u: goto label_1e66d0;
            case 0x1E66E4u: goto label_1e66e4;
            case 0x1E66FCu: goto label_1e66fc;
            case 0x1E6718u: goto label_1e6718;
            case 0x1E6744u: goto label_1e6744;
            case 0x1E6760u: goto label_1e6760;
            case 0x1E6764u: goto label_1e6764;
            case 0x1E67D0u: goto label_1e67d0;
            case 0x1E67E4u: goto label_1e67e4;
            case 0x1E6824u: goto label_1e6824;
            case 0x1E6834u: goto label_1e6834;
            case 0x1E6858u: goto label_1e6858;
            case 0x1E6868u: goto label_1e6868;
            case 0x1E688Cu: goto label_1e688c;
            case 0x1E68A0u: goto label_1e68a0;
            case 0x1E68ACu: goto label_1e68ac;
            case 0x1E68BCu: goto label_1e68bc;
            case 0x1E68D4u: goto label_1e68d4;
            case 0x1E6904u: goto label_1e6904;
            case 0x1E6970u: goto label_1e6970;
            case 0x1E6988u: goto label_1e6988;
            case 0x1E699Cu: goto label_1e699c;
            case 0x1E69B0u: goto label_1e69b0;
            case 0x1E69BCu: goto label_1e69bc;
            case 0x1E69D0u: goto label_1e69d0;
            case 0x1E69F4u: goto label_1e69f4;
            case 0x1E6A08u: goto label_1e6a08;
            case 0x1E6A30u: goto label_1e6a30;
            case 0x1E6A4Cu: goto label_1e6a4c;
            case 0x1E6AC8u: goto label_1e6ac8;
            case 0x1E6AE0u: goto label_1e6ae0;
            case 0x1E6AF4u: goto label_1e6af4;
            case 0x1E6B24u: goto label_1e6b24;
            case 0x1E6B38u: goto label_1e6b38;
            case 0x1E6B6Cu: goto label_1e6b6c;
            case 0x1E6B88u: goto label_1e6b88;
            case 0x1E6BCCu: goto label_1e6bcc;
            case 0x1E6BE8u: goto label_1e6be8;
            case 0x1E6BFCu: goto label_1e6bfc;
            case 0x1E6C30u: goto label_1e6c30;
            case 0x1E6C4Cu: goto label_1e6c4c;
            case 0x1E6C58u: goto label_1e6c58;
            case 0x1E6C6Cu: goto label_1e6c6c;
            case 0x1E6C84u: goto label_1e6c84;
            case 0x1E6CB4u: goto label_1e6cb4;
            case 0x1E6CD8u: goto label_1e6cd8;
            case 0x1E6CECu: goto label_1e6cec;
            case 0x1E6CF0u: goto label_1e6cf0;
            case 0x1E6D5Cu: goto label_1e6d5c;
            case 0x1E6D70u: goto label_1e6d70;
            case 0x1E6DB0u: goto label_1e6db0;
            case 0x1E6DC0u: goto label_1e6dc0;
            case 0x1E6DE4u: goto label_1e6de4;
            case 0x1E6DF4u: goto label_1e6df4;
            case 0x1E6E18u: goto label_1e6e18;
            case 0x1E6E2Cu: goto label_1e6e2c;
            case 0x1E6E38u: goto label_1e6e38;
            case 0x1E6E48u: goto label_1e6e48;
            case 0x1E6E60u: goto label_1e6e60;
            case 0x1E6E90u: goto label_1e6e90;
            case 0x1E6EFCu: goto label_1e6efc;
            case 0x1E6F14u: goto label_1e6f14;
            case 0x1E6F28u: goto label_1e6f28;
            case 0x1E6F3Cu: goto label_1e6f3c;
            case 0x1E6F48u: goto label_1e6f48;
            case 0x1E6F5Cu: goto label_1e6f5c;
            case 0x1E6F80u: goto label_1e6f80;
            case 0x1E6F94u: goto label_1e6f94;
            case 0x1E6FBCu: goto label_1e6fbc;
            case 0x1E6FD8u: goto label_1e6fd8;
            case 0x1E7054u: goto label_1e7054;
            case 0x1E706Cu: goto label_1e706c;
            case 0x1E7080u: goto label_1e7080;
            case 0x1E70B0u: goto label_1e70b0;
            case 0x1E70C4u: goto label_1e70c4;
            case 0x1E70F8u: goto label_1e70f8;
            case 0x1E7114u: goto label_1e7114;
            case 0x1E7158u: goto label_1e7158;
            case 0x1E7174u: goto label_1e7174;
            case 0x1E7188u: goto label_1e7188;
            case 0x1E71BCu: goto label_1e71bc;
            case 0x1E71D8u: goto label_1e71d8;
            case 0x1E71E4u: goto label_1e71e4;
            case 0x1E71F8u: goto label_1e71f8;
            case 0x1E7210u: goto label_1e7210;
            case 0x1E7240u: goto label_1e7240;
            case 0x1E7264u: goto label_1e7264;
            case 0x1E7278u: goto label_1e7278;
            case 0x1E727Cu: goto label_1e727c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E6188u;
    // 0x1e6188: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1e6188u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1e618c: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1e618cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1e6190: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1e6190u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1e6194: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e6194u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e6198: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e6198u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e619c: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e619cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e61a0: 0xafc00008  sw          $zero, 0x8($fp)
    ctx->pc = 0x1e61a0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 0));
    // 0x1e61a4: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e61a4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e61a8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e61a8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e61ac: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E61ACu;
    {
        const bool branch_taken_0x1e61ac = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e61ac) {
            ctx->pc = 0x1E61D4u;
            goto label_1e61d4;
        }
    }
    ctx->pc = 0x1E61B4u;
    // 0x1e61b4: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e61b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e61b8: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e61b8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e61bc: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e61bcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e61c0: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e61c0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e61c4: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e61c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e61c8: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e61c8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e61cc: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E61CCu;
    {
        const bool branch_taken_0x1e61cc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e61cc) {
            ctx->pc = 0x1E61E8u;
            goto label_1e61e8;
        }
    }
    ctx->pc = 0x1E61D4u;
label_1e61d4:
    // 0x1e61d4: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e61d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e61d8: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e61d8u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e61dc: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e61dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e61e0: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x1E61E0u;
    {
        const bool branch_taken_0x1e61e0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e61e0) {
            ctx->pc = 0x1E6240u;
            goto label_1e6240;
        }
    }
    ctx->pc = 0x1E61E8u;
label_1e61e8:
    // 0x1e61e8: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e61e8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e61ec: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e61ecu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e61f0: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e61f0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e61f4: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e61f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e61f8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e61f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e61fc: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e61fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e6200: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1e6200u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1e6204: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1e6204u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e6208: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e6208u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e620c: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E620Cu;
    {
        const bool branch_taken_0x1e620c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e620c) {
            ctx->pc = 0x1E6228u;
            goto label_1e6228;
        }
    }
    ctx->pc = 0x1E6214u;
    // 0x1e6214: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e6214u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e6218: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e6218u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e621c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e621cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e6220: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1E6220u;
    {
        const bool branch_taken_0x1e6220 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6220) {
            ctx->pc = 0x1E6240u;
            goto label_1e6240;
        }
    }
    ctx->pc = 0x1E6228u;
label_1e6228:
    // 0x1e6228: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1e6228u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e622c: 0x2405002b  addiu       $a1, $zero, 0x2B
    ctx->pc = 0x1e622cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 43));
    // 0x1e6230: 0x8fc60004  lw          $a2, 0x4($fp)
    ctx->pc = 0x1e6230u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e6234: 0xc076ad5  jal         func_1DAB54
    ctx->pc = 0x1E6234u;
    SET_GPR_U32(ctx, 31, 0x1E623Cu);
    ctx->pc = 0x1DAB54u;
    if (runtime->hasFunction(0x1DAB54u)) {
        auto targetFn = runtime->lookupFunction(0x1DAB54u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E623Cu; }
        if (ctx->pc != 0x1E623Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DAB54_0x1dab54(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E623Cu; }
        if (ctx->pc != 0x1E623Cu) { return; }
    }
    ctx->pc = 0x1E623Cu;
label_1e623c:
    // 0x1e623c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1e623cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1e6240:
    // 0x1e6240: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e6240u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e6244: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1e6244u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1e6248: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1e6248u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1e624c: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1e624cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1e6250: 0x3e00008  jr          $ra
    ctx->pc = 0x1E6250u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E5060u: goto label_1e5060;
            case 0x1E5074u: goto label_1e5074;
            case 0x1E50B4u: goto label_1e50b4;
            case 0x1E50C4u: goto label_1e50c4;
            case 0x1E50E8u: goto label_1e50e8;
            case 0x1E50FCu: goto label_1e50fc;
            case 0x1E5120u: goto label_1e5120;
            case 0x1E5134u: goto label_1e5134;
            case 0x1E5148u: goto label_1e5148;
            case 0x1E5178u: goto label_1e5178;
            case 0x1E5194u: goto label_1e5194;
            case 0x1E5198u: goto label_1e5198;
            case 0x1E5238u: goto label_1e5238;
            case 0x1E524Cu: goto label_1e524c;
            case 0x1E528Cu: goto label_1e528c;
            case 0x1E52B0u: goto label_1e52b0;
            case 0x1E52D4u: goto label_1e52d4;
            case 0x1E530Cu: goto label_1e530c;
            case 0x1E536Cu: goto label_1e536c;
            case 0x1E5388u: goto label_1e5388;
            case 0x1E5410u: goto label_1e5410;
            case 0x1E5424u: goto label_1e5424;
            case 0x1E5464u: goto label_1e5464;
            case 0x1E5480u: goto label_1e5480;
            case 0x1E5484u: goto label_1e5484;
            case 0x1E54F8u: goto label_1e54f8;
            case 0x1E550Cu: goto label_1e550c;
            case 0x1E554Cu: goto label_1e554c;
            case 0x1E5574u: goto label_1e5574;
            case 0x1E5598u: goto label_1e5598;
            case 0x1E55C8u: goto label_1e55c8;
            case 0x1E55ECu: goto label_1e55ec;
            case 0x1E5600u: goto label_1e5600;
            case 0x1E566Cu: goto label_1e566c;
            case 0x1E568Cu: goto label_1e568c;
            case 0x1E5748u: goto label_1e5748;
            case 0x1E575Cu: goto label_1e575c;
            case 0x1E57A0u: goto label_1e57a0;
            case 0x1E57BCu: goto label_1e57bc;
            case 0x1E57C0u: goto label_1e57c0;
            case 0x1E5820u: goto label_1e5820;
            case 0x1E5834u: goto label_1e5834;
            case 0x1E5874u: goto label_1e5874;
            case 0x1E5884u: goto label_1e5884;
            case 0x1E58A8u: goto label_1e58a8;
            case 0x1E58C8u: goto label_1e58c8;
            case 0x1E58E4u: goto label_1e58e4;
            case 0x1E58E8u: goto label_1e58e8;
            case 0x1E5948u: goto label_1e5948;
            case 0x1E595Cu: goto label_1e595c;
            case 0x1E599Cu: goto label_1e599c;
            case 0x1E59ACu: goto label_1e59ac;
            case 0x1E59D0u: goto label_1e59d0;
            case 0x1E59F0u: goto label_1e59f0;
            case 0x1E5A0Cu: goto label_1e5a0c;
            case 0x1E5A10u: goto label_1e5a10;
            case 0x1E5A80u: goto label_1e5a80;
            case 0x1E5A94u: goto label_1e5a94;
            case 0x1E5AD4u: goto label_1e5ad4;
            case 0x1E5AE4u: goto label_1e5ae4;
            case 0x1E5B08u: goto label_1e5b08;
            case 0x1E5B1Cu: goto label_1e5b1c;
            case 0x1E5B40u: goto label_1e5b40;
            case 0x1E5B54u: goto label_1e5b54;
            case 0x1E5B68u: goto label_1e5b68;
            case 0x1E5B98u: goto label_1e5b98;
            case 0x1E5BB4u: goto label_1e5bb4;
            case 0x1E5BB8u: goto label_1e5bb8;
            case 0x1E5C2Cu: goto label_1e5c2c;
            case 0x1E5C40u: goto label_1e5c40;
            case 0x1E5C80u: goto label_1e5c80;
            case 0x1E5C90u: goto label_1e5c90;
            case 0x1E5CB4u: goto label_1e5cb4;
            case 0x1E5CC8u: goto label_1e5cc8;
            case 0x1E5CECu: goto label_1e5cec;
            case 0x1E5D00u: goto label_1e5d00;
            case 0x1E5D14u: goto label_1e5d14;
            case 0x1E5D48u: goto label_1e5d48;
            case 0x1E5D64u: goto label_1e5d64;
            case 0x1E5D78u: goto label_1e5d78;
            case 0x1E5D94u: goto label_1e5d94;
            case 0x1E5E04u: goto label_1e5e04;
            case 0x1E5E18u: goto label_1e5e18;
            case 0x1E5E58u: goto label_1e5e58;
            case 0x1E5E68u: goto label_1e5e68;
            case 0x1E5E8Cu: goto label_1e5e8c;
            case 0x1E5E9Cu: goto label_1e5e9c;
            case 0x1E5EB4u: goto label_1e5eb4;
            case 0x1E5F6Cu: goto label_1e5f6c;
            case 0x1E5F88u: goto label_1e5f88;
            case 0x1E5F9Cu: goto label_1e5f9c;
            case 0x1E5FA0u: goto label_1e5fa0;
            case 0x1E6008u: goto label_1e6008;
            case 0x1E601Cu: goto label_1e601c;
            case 0x1E605Cu: goto label_1e605c;
            case 0x1E6068u: goto label_1e6068;
            case 0x1E6084u: goto label_1e6084;
            case 0x1E6094u: goto label_1e6094;
            case 0x1E60B8u: goto label_1e60b8;
            case 0x1E60CCu: goto label_1e60cc;
            case 0x1E60F0u: goto label_1e60f0;
            case 0x1E6104u: goto label_1e6104;
            case 0x1E6118u: goto label_1e6118;
            case 0x1E613Cu: goto label_1e613c;
            case 0x1E6158u: goto label_1e6158;
            case 0x1E616Cu: goto label_1e616c;
            case 0x1E6170u: goto label_1e6170;
            case 0x1E61D4u: goto label_1e61d4;
            case 0x1E61E8u: goto label_1e61e8;
            case 0x1E6228u: goto label_1e6228;
            case 0x1E623Cu: goto label_1e623c;
            case 0x1E6240u: goto label_1e6240;
            case 0x1E62A4u: goto label_1e62a4;
            case 0x1E62B8u: goto label_1e62b8;
            case 0x1E62F8u: goto label_1e62f8;
            case 0x1E630Cu: goto label_1e630c;
            case 0x1E6310u: goto label_1e6310;
            case 0x1E6374u: goto label_1e6374;
            case 0x1E6388u: goto label_1e6388;
            case 0x1E63C8u: goto label_1e63c8;
            case 0x1E63DCu: goto label_1e63dc;
            case 0x1E63E0u: goto label_1e63e0;
            case 0x1E6448u: goto label_1e6448;
            case 0x1E645Cu: goto label_1e645c;
            case 0x1E649Cu: goto label_1e649c;
            case 0x1E64B4u: goto label_1e64b4;
            case 0x1E64C4u: goto label_1e64c4;
            case 0x1E64E8u: goto label_1e64e8;
            case 0x1E64FCu: goto label_1e64fc;
            case 0x1E6520u: goto label_1e6520;
            case 0x1E6534u: goto label_1e6534;
            case 0x1E6548u: goto label_1e6548;
            case 0x1E656Cu: goto label_1e656c;
            case 0x1E6588u: goto label_1e6588;
            case 0x1E658Cu: goto label_1e658c;
            case 0x1E65F8u: goto label_1e65f8;
            case 0x1E660Cu: goto label_1e660c;
            case 0x1E664Cu: goto label_1e664c;
            case 0x1E6664u: goto label_1e6664;
            case 0x1E6674u: goto label_1e6674;
            case 0x1E6698u: goto label_1e6698;
            case 0x1E66ACu: goto label_1e66ac;
            case 0x1E66D0u: goto label_1e66d0;
            case 0x1E66E4u: goto label_1e66e4;
            case 0x1E66FCu: goto label_1e66fc;
            case 0x1E6718u: goto label_1e6718;
            case 0x1E6744u: goto label_1e6744;
            case 0x1E6760u: goto label_1e6760;
            case 0x1E6764u: goto label_1e6764;
            case 0x1E67D0u: goto label_1e67d0;
            case 0x1E67E4u: goto label_1e67e4;
            case 0x1E6824u: goto label_1e6824;
            case 0x1E6834u: goto label_1e6834;
            case 0x1E6858u: goto label_1e6858;
            case 0x1E6868u: goto label_1e6868;
            case 0x1E688Cu: goto label_1e688c;
            case 0x1E68A0u: goto label_1e68a0;
            case 0x1E68ACu: goto label_1e68ac;
            case 0x1E68BCu: goto label_1e68bc;
            case 0x1E68D4u: goto label_1e68d4;
            case 0x1E6904u: goto label_1e6904;
            case 0x1E6970u: goto label_1e6970;
            case 0x1E6988u: goto label_1e6988;
            case 0x1E699Cu: goto label_1e699c;
            case 0x1E69B0u: goto label_1e69b0;
            case 0x1E69BCu: goto label_1e69bc;
            case 0x1E69D0u: goto label_1e69d0;
            case 0x1E69F4u: goto label_1e69f4;
            case 0x1E6A08u: goto label_1e6a08;
            case 0x1E6A30u: goto label_1e6a30;
            case 0x1E6A4Cu: goto label_1e6a4c;
            case 0x1E6AC8u: goto label_1e6ac8;
            case 0x1E6AE0u: goto label_1e6ae0;
            case 0x1E6AF4u: goto label_1e6af4;
            case 0x1E6B24u: goto label_1e6b24;
            case 0x1E6B38u: goto label_1e6b38;
            case 0x1E6B6Cu: goto label_1e6b6c;
            case 0x1E6B88u: goto label_1e6b88;
            case 0x1E6BCCu: goto label_1e6bcc;
            case 0x1E6BE8u: goto label_1e6be8;
            case 0x1E6BFCu: goto label_1e6bfc;
            case 0x1E6C30u: goto label_1e6c30;
            case 0x1E6C4Cu: goto label_1e6c4c;
            case 0x1E6C58u: goto label_1e6c58;
            case 0x1E6C6Cu: goto label_1e6c6c;
            case 0x1E6C84u: goto label_1e6c84;
            case 0x1E6CB4u: goto label_1e6cb4;
            case 0x1E6CD8u: goto label_1e6cd8;
            case 0x1E6CECu: goto label_1e6cec;
            case 0x1E6CF0u: goto label_1e6cf0;
            case 0x1E6D5Cu: goto label_1e6d5c;
            case 0x1E6D70u: goto label_1e6d70;
            case 0x1E6DB0u: goto label_1e6db0;
            case 0x1E6DC0u: goto label_1e6dc0;
            case 0x1E6DE4u: goto label_1e6de4;
            case 0x1E6DF4u: goto label_1e6df4;
            case 0x1E6E18u: goto label_1e6e18;
            case 0x1E6E2Cu: goto label_1e6e2c;
            case 0x1E6E38u: goto label_1e6e38;
            case 0x1E6E48u: goto label_1e6e48;
            case 0x1E6E60u: goto label_1e6e60;
            case 0x1E6E90u: goto label_1e6e90;
            case 0x1E6EFCu: goto label_1e6efc;
            case 0x1E6F14u: goto label_1e6f14;
            case 0x1E6F28u: goto label_1e6f28;
            case 0x1E6F3Cu: goto label_1e6f3c;
            case 0x1E6F48u: goto label_1e6f48;
            case 0x1E6F5Cu: goto label_1e6f5c;
            case 0x1E6F80u: goto label_1e6f80;
            case 0x1E6F94u: goto label_1e6f94;
            case 0x1E6FBCu: goto label_1e6fbc;
            case 0x1E6FD8u: goto label_1e6fd8;
            case 0x1E7054u: goto label_1e7054;
            case 0x1E706Cu: goto label_1e706c;
            case 0x1E7080u: goto label_1e7080;
            case 0x1E70B0u: goto label_1e70b0;
            case 0x1E70C4u: goto label_1e70c4;
            case 0x1E70F8u: goto label_1e70f8;
            case 0x1E7114u: goto label_1e7114;
            case 0x1E7158u: goto label_1e7158;
            case 0x1E7174u: goto label_1e7174;
            case 0x1E7188u: goto label_1e7188;
            case 0x1E71BCu: goto label_1e71bc;
            case 0x1E71D8u: goto label_1e71d8;
            case 0x1E71E4u: goto label_1e71e4;
            case 0x1E71F8u: goto label_1e71f8;
            case 0x1E7210u: goto label_1e7210;
            case 0x1E7240u: goto label_1e7240;
            case 0x1E7264u: goto label_1e7264;
            case 0x1E7278u: goto label_1e7278;
            case 0x1E727Cu: goto label_1e727c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E6258u;
    // 0x1e6258: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1e6258u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1e625c: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1e625cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1e6260: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1e6260u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1e6264: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e6264u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e6268: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e6268u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e626c: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e626cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e6270: 0xafc00008  sw          $zero, 0x8($fp)
    ctx->pc = 0x1e6270u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 0));
    // 0x1e6274: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e6274u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e6278: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e6278u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e627c: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E627Cu;
    {
        const bool branch_taken_0x1e627c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e627c) {
            ctx->pc = 0x1E62A4u;
            goto label_1e62a4;
        }
    }
    ctx->pc = 0x1E6284u;
    // 0x1e6284: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e6284u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e6288: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e6288u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e628c: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e628cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e6290: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e6290u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e6294: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e6294u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e6298: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e6298u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e629c: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E629Cu;
    {
        const bool branch_taken_0x1e629c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e629c) {
            ctx->pc = 0x1E62B8u;
            goto label_1e62b8;
        }
    }
    ctx->pc = 0x1E62A4u;
label_1e62a4:
    // 0x1e62a4: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e62a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e62a8: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e62a8u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e62ac: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e62acu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e62b0: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x1E62B0u;
    {
        const bool branch_taken_0x1e62b0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e62b0) {
            ctx->pc = 0x1E6310u;
            goto label_1e6310;
        }
    }
    ctx->pc = 0x1E62B8u;
label_1e62b8:
    // 0x1e62b8: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e62b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e62bc: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e62bcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e62c0: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e62c0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e62c4: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e62c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e62c8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e62c8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e62cc: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e62ccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e62d0: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1e62d0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1e62d4: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1e62d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e62d8: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e62d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e62dc: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E62DCu;
    {
        const bool branch_taken_0x1e62dc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e62dc) {
            ctx->pc = 0x1E62F8u;
            goto label_1e62f8;
        }
    }
    ctx->pc = 0x1E62E4u;
    // 0x1e62e4: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e62e4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e62e8: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e62e8u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e62ec: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e62ecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e62f0: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1E62F0u;
    {
        const bool branch_taken_0x1e62f0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e62f0) {
            ctx->pc = 0x1E6310u;
            goto label_1e6310;
        }
    }
    ctx->pc = 0x1E62F8u;
label_1e62f8:
    // 0x1e62f8: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1e62f8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e62fc: 0x2405002c  addiu       $a1, $zero, 0x2C
    ctx->pc = 0x1e62fcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 44));
    // 0x1e6300: 0x8fc60004  lw          $a2, 0x4($fp)
    ctx->pc = 0x1e6300u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e6304: 0xc076ad5  jal         func_1DAB54
    ctx->pc = 0x1E6304u;
    SET_GPR_U32(ctx, 31, 0x1E630Cu);
    ctx->pc = 0x1DAB54u;
    if (runtime->hasFunction(0x1DAB54u)) {
        auto targetFn = runtime->lookupFunction(0x1DAB54u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E630Cu; }
        if (ctx->pc != 0x1E630Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DAB54_0x1dab54(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E630Cu; }
        if (ctx->pc != 0x1E630Cu) { return; }
    }
    ctx->pc = 0x1E630Cu;
label_1e630c:
    // 0x1e630c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1e630cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1e6310:
    // 0x1e6310: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e6310u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e6314: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1e6314u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1e6318: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1e6318u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1e631c: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1e631cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1e6320: 0x3e00008  jr          $ra
    ctx->pc = 0x1E6320u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E5060u: goto label_1e5060;
            case 0x1E5074u: goto label_1e5074;
            case 0x1E50B4u: goto label_1e50b4;
            case 0x1E50C4u: goto label_1e50c4;
            case 0x1E50E8u: goto label_1e50e8;
            case 0x1E50FCu: goto label_1e50fc;
            case 0x1E5120u: goto label_1e5120;
            case 0x1E5134u: goto label_1e5134;
            case 0x1E5148u: goto label_1e5148;
            case 0x1E5178u: goto label_1e5178;
            case 0x1E5194u: goto label_1e5194;
            case 0x1E5198u: goto label_1e5198;
            case 0x1E5238u: goto label_1e5238;
            case 0x1E524Cu: goto label_1e524c;
            case 0x1E528Cu: goto label_1e528c;
            case 0x1E52B0u: goto label_1e52b0;
            case 0x1E52D4u: goto label_1e52d4;
            case 0x1E530Cu: goto label_1e530c;
            case 0x1E536Cu: goto label_1e536c;
            case 0x1E5388u: goto label_1e5388;
            case 0x1E5410u: goto label_1e5410;
            case 0x1E5424u: goto label_1e5424;
            case 0x1E5464u: goto label_1e5464;
            case 0x1E5480u: goto label_1e5480;
            case 0x1E5484u: goto label_1e5484;
            case 0x1E54F8u: goto label_1e54f8;
            case 0x1E550Cu: goto label_1e550c;
            case 0x1E554Cu: goto label_1e554c;
            case 0x1E5574u: goto label_1e5574;
            case 0x1E5598u: goto label_1e5598;
            case 0x1E55C8u: goto label_1e55c8;
            case 0x1E55ECu: goto label_1e55ec;
            case 0x1E5600u: goto label_1e5600;
            case 0x1E566Cu: goto label_1e566c;
            case 0x1E568Cu: goto label_1e568c;
            case 0x1E5748u: goto label_1e5748;
            case 0x1E575Cu: goto label_1e575c;
            case 0x1E57A0u: goto label_1e57a0;
            case 0x1E57BCu: goto label_1e57bc;
            case 0x1E57C0u: goto label_1e57c0;
            case 0x1E5820u: goto label_1e5820;
            case 0x1E5834u: goto label_1e5834;
            case 0x1E5874u: goto label_1e5874;
            case 0x1E5884u: goto label_1e5884;
            case 0x1E58A8u: goto label_1e58a8;
            case 0x1E58C8u: goto label_1e58c8;
            case 0x1E58E4u: goto label_1e58e4;
            case 0x1E58E8u: goto label_1e58e8;
            case 0x1E5948u: goto label_1e5948;
            case 0x1E595Cu: goto label_1e595c;
            case 0x1E599Cu: goto label_1e599c;
            case 0x1E59ACu: goto label_1e59ac;
            case 0x1E59D0u: goto label_1e59d0;
            case 0x1E59F0u: goto label_1e59f0;
            case 0x1E5A0Cu: goto label_1e5a0c;
            case 0x1E5A10u: goto label_1e5a10;
            case 0x1E5A80u: goto label_1e5a80;
            case 0x1E5A94u: goto label_1e5a94;
            case 0x1E5AD4u: goto label_1e5ad4;
            case 0x1E5AE4u: goto label_1e5ae4;
            case 0x1E5B08u: goto label_1e5b08;
            case 0x1E5B1Cu: goto label_1e5b1c;
            case 0x1E5B40u: goto label_1e5b40;
            case 0x1E5B54u: goto label_1e5b54;
            case 0x1E5B68u: goto label_1e5b68;
            case 0x1E5B98u: goto label_1e5b98;
            case 0x1E5BB4u: goto label_1e5bb4;
            case 0x1E5BB8u: goto label_1e5bb8;
            case 0x1E5C2Cu: goto label_1e5c2c;
            case 0x1E5C40u: goto label_1e5c40;
            case 0x1E5C80u: goto label_1e5c80;
            case 0x1E5C90u: goto label_1e5c90;
            case 0x1E5CB4u: goto label_1e5cb4;
            case 0x1E5CC8u: goto label_1e5cc8;
            case 0x1E5CECu: goto label_1e5cec;
            case 0x1E5D00u: goto label_1e5d00;
            case 0x1E5D14u: goto label_1e5d14;
            case 0x1E5D48u: goto label_1e5d48;
            case 0x1E5D64u: goto label_1e5d64;
            case 0x1E5D78u: goto label_1e5d78;
            case 0x1E5D94u: goto label_1e5d94;
            case 0x1E5E04u: goto label_1e5e04;
            case 0x1E5E18u: goto label_1e5e18;
            case 0x1E5E58u: goto label_1e5e58;
            case 0x1E5E68u: goto label_1e5e68;
            case 0x1E5E8Cu: goto label_1e5e8c;
            case 0x1E5E9Cu: goto label_1e5e9c;
            case 0x1E5EB4u: goto label_1e5eb4;
            case 0x1E5F6Cu: goto label_1e5f6c;
            case 0x1E5F88u: goto label_1e5f88;
            case 0x1E5F9Cu: goto label_1e5f9c;
            case 0x1E5FA0u: goto label_1e5fa0;
            case 0x1E6008u: goto label_1e6008;
            case 0x1E601Cu: goto label_1e601c;
            case 0x1E605Cu: goto label_1e605c;
            case 0x1E6068u: goto label_1e6068;
            case 0x1E6084u: goto label_1e6084;
            case 0x1E6094u: goto label_1e6094;
            case 0x1E60B8u: goto label_1e60b8;
            case 0x1E60CCu: goto label_1e60cc;
            case 0x1E60F0u: goto label_1e60f0;
            case 0x1E6104u: goto label_1e6104;
            case 0x1E6118u: goto label_1e6118;
            case 0x1E613Cu: goto label_1e613c;
            case 0x1E6158u: goto label_1e6158;
            case 0x1E616Cu: goto label_1e616c;
            case 0x1E6170u: goto label_1e6170;
            case 0x1E61D4u: goto label_1e61d4;
            case 0x1E61E8u: goto label_1e61e8;
            case 0x1E6228u: goto label_1e6228;
            case 0x1E623Cu: goto label_1e623c;
            case 0x1E6240u: goto label_1e6240;
            case 0x1E62A4u: goto label_1e62a4;
            case 0x1E62B8u: goto label_1e62b8;
            case 0x1E62F8u: goto label_1e62f8;
            case 0x1E630Cu: goto label_1e630c;
            case 0x1E6310u: goto label_1e6310;
            case 0x1E6374u: goto label_1e6374;
            case 0x1E6388u: goto label_1e6388;
            case 0x1E63C8u: goto label_1e63c8;
            case 0x1E63DCu: goto label_1e63dc;
            case 0x1E63E0u: goto label_1e63e0;
            case 0x1E6448u: goto label_1e6448;
            case 0x1E645Cu: goto label_1e645c;
            case 0x1E649Cu: goto label_1e649c;
            case 0x1E64B4u: goto label_1e64b4;
            case 0x1E64C4u: goto label_1e64c4;
            case 0x1E64E8u: goto label_1e64e8;
            case 0x1E64FCu: goto label_1e64fc;
            case 0x1E6520u: goto label_1e6520;
            case 0x1E6534u: goto label_1e6534;
            case 0x1E6548u: goto label_1e6548;
            case 0x1E656Cu: goto label_1e656c;
            case 0x1E6588u: goto label_1e6588;
            case 0x1E658Cu: goto label_1e658c;
            case 0x1E65F8u: goto label_1e65f8;
            case 0x1E660Cu: goto label_1e660c;
            case 0x1E664Cu: goto label_1e664c;
            case 0x1E6664u: goto label_1e6664;
            case 0x1E6674u: goto label_1e6674;
            case 0x1E6698u: goto label_1e6698;
            case 0x1E66ACu: goto label_1e66ac;
            case 0x1E66D0u: goto label_1e66d0;
            case 0x1E66E4u: goto label_1e66e4;
            case 0x1E66FCu: goto label_1e66fc;
            case 0x1E6718u: goto label_1e6718;
            case 0x1E6744u: goto label_1e6744;
            case 0x1E6760u: goto label_1e6760;
            case 0x1E6764u: goto label_1e6764;
            case 0x1E67D0u: goto label_1e67d0;
            case 0x1E67E4u: goto label_1e67e4;
            case 0x1E6824u: goto label_1e6824;
            case 0x1E6834u: goto label_1e6834;
            case 0x1E6858u: goto label_1e6858;
            case 0x1E6868u: goto label_1e6868;
            case 0x1E688Cu: goto label_1e688c;
            case 0x1E68A0u: goto label_1e68a0;
            case 0x1E68ACu: goto label_1e68ac;
            case 0x1E68BCu: goto label_1e68bc;
            case 0x1E68D4u: goto label_1e68d4;
            case 0x1E6904u: goto label_1e6904;
            case 0x1E6970u: goto label_1e6970;
            case 0x1E6988u: goto label_1e6988;
            case 0x1E699Cu: goto label_1e699c;
            case 0x1E69B0u: goto label_1e69b0;
            case 0x1E69BCu: goto label_1e69bc;
            case 0x1E69D0u: goto label_1e69d0;
            case 0x1E69F4u: goto label_1e69f4;
            case 0x1E6A08u: goto label_1e6a08;
            case 0x1E6A30u: goto label_1e6a30;
            case 0x1E6A4Cu: goto label_1e6a4c;
            case 0x1E6AC8u: goto label_1e6ac8;
            case 0x1E6AE0u: goto label_1e6ae0;
            case 0x1E6AF4u: goto label_1e6af4;
            case 0x1E6B24u: goto label_1e6b24;
            case 0x1E6B38u: goto label_1e6b38;
            case 0x1E6B6Cu: goto label_1e6b6c;
            case 0x1E6B88u: goto label_1e6b88;
            case 0x1E6BCCu: goto label_1e6bcc;
            case 0x1E6BE8u: goto label_1e6be8;
            case 0x1E6BFCu: goto label_1e6bfc;
            case 0x1E6C30u: goto label_1e6c30;
            case 0x1E6C4Cu: goto label_1e6c4c;
            case 0x1E6C58u: goto label_1e6c58;
            case 0x1E6C6Cu: goto label_1e6c6c;
            case 0x1E6C84u: goto label_1e6c84;
            case 0x1E6CB4u: goto label_1e6cb4;
            case 0x1E6CD8u: goto label_1e6cd8;
            case 0x1E6CECu: goto label_1e6cec;
            case 0x1E6CF0u: goto label_1e6cf0;
            case 0x1E6D5Cu: goto label_1e6d5c;
            case 0x1E6D70u: goto label_1e6d70;
            case 0x1E6DB0u: goto label_1e6db0;
            case 0x1E6DC0u: goto label_1e6dc0;
            case 0x1E6DE4u: goto label_1e6de4;
            case 0x1E6DF4u: goto label_1e6df4;
            case 0x1E6E18u: goto label_1e6e18;
            case 0x1E6E2Cu: goto label_1e6e2c;
            case 0x1E6E38u: goto label_1e6e38;
            case 0x1E6E48u: goto label_1e6e48;
            case 0x1E6E60u: goto label_1e6e60;
            case 0x1E6E90u: goto label_1e6e90;
            case 0x1E6EFCu: goto label_1e6efc;
            case 0x1E6F14u: goto label_1e6f14;
            case 0x1E6F28u: goto label_1e6f28;
            case 0x1E6F3Cu: goto label_1e6f3c;
            case 0x1E6F48u: goto label_1e6f48;
            case 0x1E6F5Cu: goto label_1e6f5c;
            case 0x1E6F80u: goto label_1e6f80;
            case 0x1E6F94u: goto label_1e6f94;
            case 0x1E6FBCu: goto label_1e6fbc;
            case 0x1E6FD8u: goto label_1e6fd8;
            case 0x1E7054u: goto label_1e7054;
            case 0x1E706Cu: goto label_1e706c;
            case 0x1E7080u: goto label_1e7080;
            case 0x1E70B0u: goto label_1e70b0;
            case 0x1E70C4u: goto label_1e70c4;
            case 0x1E70F8u: goto label_1e70f8;
            case 0x1E7114u: goto label_1e7114;
            case 0x1E7158u: goto label_1e7158;
            case 0x1E7174u: goto label_1e7174;
            case 0x1E7188u: goto label_1e7188;
            case 0x1E71BCu: goto label_1e71bc;
            case 0x1E71D8u: goto label_1e71d8;
            case 0x1E71E4u: goto label_1e71e4;
            case 0x1E71F8u: goto label_1e71f8;
            case 0x1E7210u: goto label_1e7210;
            case 0x1E7240u: goto label_1e7240;
            case 0x1E7264u: goto label_1e7264;
            case 0x1E7278u: goto label_1e7278;
            case 0x1E727Cu: goto label_1e727c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E6328u;
    // 0x1e6328: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1e6328u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1e632c: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1e632cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1e6330: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1e6330u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1e6334: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e6334u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e6338: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e6338u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e633c: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e633cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e6340: 0xafc00008  sw          $zero, 0x8($fp)
    ctx->pc = 0x1e6340u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 0));
    // 0x1e6344: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e6344u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e6348: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e6348u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e634c: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E634Cu;
    {
        const bool branch_taken_0x1e634c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e634c) {
            ctx->pc = 0x1E6374u;
            goto label_1e6374;
        }
    }
    ctx->pc = 0x1E6354u;
    // 0x1e6354: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e6354u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e6358: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e6358u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e635c: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e635cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e6360: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e6360u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e6364: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e6364u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e6368: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e6368u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e636c: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E636Cu;
    {
        const bool branch_taken_0x1e636c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e636c) {
            ctx->pc = 0x1E6388u;
            goto label_1e6388;
        }
    }
    ctx->pc = 0x1E6374u;
label_1e6374:
    // 0x1e6374: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e6374u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e6378: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e6378u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e637c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e637cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e6380: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x1E6380u;
    {
        const bool branch_taken_0x1e6380 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6380) {
            ctx->pc = 0x1E63E0u;
            goto label_1e63e0;
        }
    }
    ctx->pc = 0x1E6388u;
label_1e6388:
    // 0x1e6388: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e6388u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e638c: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e638cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e6390: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e6390u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e6394: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e6394u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e6398: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e6398u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e639c: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e639cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e63a0: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1e63a0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1e63a4: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1e63a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e63a8: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e63a8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e63ac: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E63ACu;
    {
        const bool branch_taken_0x1e63ac = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e63ac) {
            ctx->pc = 0x1E63C8u;
            goto label_1e63c8;
        }
    }
    ctx->pc = 0x1E63B4u;
    // 0x1e63b4: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e63b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e63b8: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e63b8u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e63bc: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e63bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e63c0: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1E63C0u;
    {
        const bool branch_taken_0x1e63c0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e63c0) {
            ctx->pc = 0x1E63E0u;
            goto label_1e63e0;
        }
    }
    ctx->pc = 0x1E63C8u;
label_1e63c8:
    // 0x1e63c8: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1e63c8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e63cc: 0x2405002d  addiu       $a1, $zero, 0x2D
    ctx->pc = 0x1e63ccu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 45));
    // 0x1e63d0: 0x8fc60004  lw          $a2, 0x4($fp)
    ctx->pc = 0x1e63d0u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e63d4: 0xc076ad5  jal         func_1DAB54
    ctx->pc = 0x1E63D4u;
    SET_GPR_U32(ctx, 31, 0x1E63DCu);
    ctx->pc = 0x1DAB54u;
    if (runtime->hasFunction(0x1DAB54u)) {
        auto targetFn = runtime->lookupFunction(0x1DAB54u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E63DCu; }
        if (ctx->pc != 0x1E63DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DAB54_0x1dab54(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E63DCu; }
        if (ctx->pc != 0x1E63DCu) { return; }
    }
    ctx->pc = 0x1E63DCu;
label_1e63dc:
    // 0x1e63dc: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1e63dcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1e63e0:
    // 0x1e63e0: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e63e0u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e63e4: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1e63e4u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1e63e8: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1e63e8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1e63ec: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1e63ecu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1e63f0: 0x3e00008  jr          $ra
    ctx->pc = 0x1E63F0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E5060u: goto label_1e5060;
            case 0x1E5074u: goto label_1e5074;
            case 0x1E50B4u: goto label_1e50b4;
            case 0x1E50C4u: goto label_1e50c4;
            case 0x1E50E8u: goto label_1e50e8;
            case 0x1E50FCu: goto label_1e50fc;
            case 0x1E5120u: goto label_1e5120;
            case 0x1E5134u: goto label_1e5134;
            case 0x1E5148u: goto label_1e5148;
            case 0x1E5178u: goto label_1e5178;
            case 0x1E5194u: goto label_1e5194;
            case 0x1E5198u: goto label_1e5198;
            case 0x1E5238u: goto label_1e5238;
            case 0x1E524Cu: goto label_1e524c;
            case 0x1E528Cu: goto label_1e528c;
            case 0x1E52B0u: goto label_1e52b0;
            case 0x1E52D4u: goto label_1e52d4;
            case 0x1E530Cu: goto label_1e530c;
            case 0x1E536Cu: goto label_1e536c;
            case 0x1E5388u: goto label_1e5388;
            case 0x1E5410u: goto label_1e5410;
            case 0x1E5424u: goto label_1e5424;
            case 0x1E5464u: goto label_1e5464;
            case 0x1E5480u: goto label_1e5480;
            case 0x1E5484u: goto label_1e5484;
            case 0x1E54F8u: goto label_1e54f8;
            case 0x1E550Cu: goto label_1e550c;
            case 0x1E554Cu: goto label_1e554c;
            case 0x1E5574u: goto label_1e5574;
            case 0x1E5598u: goto label_1e5598;
            case 0x1E55C8u: goto label_1e55c8;
            case 0x1E55ECu: goto label_1e55ec;
            case 0x1E5600u: goto label_1e5600;
            case 0x1E566Cu: goto label_1e566c;
            case 0x1E568Cu: goto label_1e568c;
            case 0x1E5748u: goto label_1e5748;
            case 0x1E575Cu: goto label_1e575c;
            case 0x1E57A0u: goto label_1e57a0;
            case 0x1E57BCu: goto label_1e57bc;
            case 0x1E57C0u: goto label_1e57c0;
            case 0x1E5820u: goto label_1e5820;
            case 0x1E5834u: goto label_1e5834;
            case 0x1E5874u: goto label_1e5874;
            case 0x1E5884u: goto label_1e5884;
            case 0x1E58A8u: goto label_1e58a8;
            case 0x1E58C8u: goto label_1e58c8;
            case 0x1E58E4u: goto label_1e58e4;
            case 0x1E58E8u: goto label_1e58e8;
            case 0x1E5948u: goto label_1e5948;
            case 0x1E595Cu: goto label_1e595c;
            case 0x1E599Cu: goto label_1e599c;
            case 0x1E59ACu: goto label_1e59ac;
            case 0x1E59D0u: goto label_1e59d0;
            case 0x1E59F0u: goto label_1e59f0;
            case 0x1E5A0Cu: goto label_1e5a0c;
            case 0x1E5A10u: goto label_1e5a10;
            case 0x1E5A80u: goto label_1e5a80;
            case 0x1E5A94u: goto label_1e5a94;
            case 0x1E5AD4u: goto label_1e5ad4;
            case 0x1E5AE4u: goto label_1e5ae4;
            case 0x1E5B08u: goto label_1e5b08;
            case 0x1E5B1Cu: goto label_1e5b1c;
            case 0x1E5B40u: goto label_1e5b40;
            case 0x1E5B54u: goto label_1e5b54;
            case 0x1E5B68u: goto label_1e5b68;
            case 0x1E5B98u: goto label_1e5b98;
            case 0x1E5BB4u: goto label_1e5bb4;
            case 0x1E5BB8u: goto label_1e5bb8;
            case 0x1E5C2Cu: goto label_1e5c2c;
            case 0x1E5C40u: goto label_1e5c40;
            case 0x1E5C80u: goto label_1e5c80;
            case 0x1E5C90u: goto label_1e5c90;
            case 0x1E5CB4u: goto label_1e5cb4;
            case 0x1E5CC8u: goto label_1e5cc8;
            case 0x1E5CECu: goto label_1e5cec;
            case 0x1E5D00u: goto label_1e5d00;
            case 0x1E5D14u: goto label_1e5d14;
            case 0x1E5D48u: goto label_1e5d48;
            case 0x1E5D64u: goto label_1e5d64;
            case 0x1E5D78u: goto label_1e5d78;
            case 0x1E5D94u: goto label_1e5d94;
            case 0x1E5E04u: goto label_1e5e04;
            case 0x1E5E18u: goto label_1e5e18;
            case 0x1E5E58u: goto label_1e5e58;
            case 0x1E5E68u: goto label_1e5e68;
            case 0x1E5E8Cu: goto label_1e5e8c;
            case 0x1E5E9Cu: goto label_1e5e9c;
            case 0x1E5EB4u: goto label_1e5eb4;
            case 0x1E5F6Cu: goto label_1e5f6c;
            case 0x1E5F88u: goto label_1e5f88;
            case 0x1E5F9Cu: goto label_1e5f9c;
            case 0x1E5FA0u: goto label_1e5fa0;
            case 0x1E6008u: goto label_1e6008;
            case 0x1E601Cu: goto label_1e601c;
            case 0x1E605Cu: goto label_1e605c;
            case 0x1E6068u: goto label_1e6068;
            case 0x1E6084u: goto label_1e6084;
            case 0x1E6094u: goto label_1e6094;
            case 0x1E60B8u: goto label_1e60b8;
            case 0x1E60CCu: goto label_1e60cc;
            case 0x1E60F0u: goto label_1e60f0;
            case 0x1E6104u: goto label_1e6104;
            case 0x1E6118u: goto label_1e6118;
            case 0x1E613Cu: goto label_1e613c;
            case 0x1E6158u: goto label_1e6158;
            case 0x1E616Cu: goto label_1e616c;
            case 0x1E6170u: goto label_1e6170;
            case 0x1E61D4u: goto label_1e61d4;
            case 0x1E61E8u: goto label_1e61e8;
            case 0x1E6228u: goto label_1e6228;
            case 0x1E623Cu: goto label_1e623c;
            case 0x1E6240u: goto label_1e6240;
            case 0x1E62A4u: goto label_1e62a4;
            case 0x1E62B8u: goto label_1e62b8;
            case 0x1E62F8u: goto label_1e62f8;
            case 0x1E630Cu: goto label_1e630c;
            case 0x1E6310u: goto label_1e6310;
            case 0x1E6374u: goto label_1e6374;
            case 0x1E6388u: goto label_1e6388;
            case 0x1E63C8u: goto label_1e63c8;
            case 0x1E63DCu: goto label_1e63dc;
            case 0x1E63E0u: goto label_1e63e0;
            case 0x1E6448u: goto label_1e6448;
            case 0x1E645Cu: goto label_1e645c;
            case 0x1E649Cu: goto label_1e649c;
            case 0x1E64B4u: goto label_1e64b4;
            case 0x1E64C4u: goto label_1e64c4;
            case 0x1E64E8u: goto label_1e64e8;
            case 0x1E64FCu: goto label_1e64fc;
            case 0x1E6520u: goto label_1e6520;
            case 0x1E6534u: goto label_1e6534;
            case 0x1E6548u: goto label_1e6548;
            case 0x1E656Cu: goto label_1e656c;
            case 0x1E6588u: goto label_1e6588;
            case 0x1E658Cu: goto label_1e658c;
            case 0x1E65F8u: goto label_1e65f8;
            case 0x1E660Cu: goto label_1e660c;
            case 0x1E664Cu: goto label_1e664c;
            case 0x1E6664u: goto label_1e6664;
            case 0x1E6674u: goto label_1e6674;
            case 0x1E6698u: goto label_1e6698;
            case 0x1E66ACu: goto label_1e66ac;
            case 0x1E66D0u: goto label_1e66d0;
            case 0x1E66E4u: goto label_1e66e4;
            case 0x1E66FCu: goto label_1e66fc;
            case 0x1E6718u: goto label_1e6718;
            case 0x1E6744u: goto label_1e6744;
            case 0x1E6760u: goto label_1e6760;
            case 0x1E6764u: goto label_1e6764;
            case 0x1E67D0u: goto label_1e67d0;
            case 0x1E67E4u: goto label_1e67e4;
            case 0x1E6824u: goto label_1e6824;
            case 0x1E6834u: goto label_1e6834;
            case 0x1E6858u: goto label_1e6858;
            case 0x1E6868u: goto label_1e6868;
            case 0x1E688Cu: goto label_1e688c;
            case 0x1E68A0u: goto label_1e68a0;
            case 0x1E68ACu: goto label_1e68ac;
            case 0x1E68BCu: goto label_1e68bc;
            case 0x1E68D4u: goto label_1e68d4;
            case 0x1E6904u: goto label_1e6904;
            case 0x1E6970u: goto label_1e6970;
            case 0x1E6988u: goto label_1e6988;
            case 0x1E699Cu: goto label_1e699c;
            case 0x1E69B0u: goto label_1e69b0;
            case 0x1E69BCu: goto label_1e69bc;
            case 0x1E69D0u: goto label_1e69d0;
            case 0x1E69F4u: goto label_1e69f4;
            case 0x1E6A08u: goto label_1e6a08;
            case 0x1E6A30u: goto label_1e6a30;
            case 0x1E6A4Cu: goto label_1e6a4c;
            case 0x1E6AC8u: goto label_1e6ac8;
            case 0x1E6AE0u: goto label_1e6ae0;
            case 0x1E6AF4u: goto label_1e6af4;
            case 0x1E6B24u: goto label_1e6b24;
            case 0x1E6B38u: goto label_1e6b38;
            case 0x1E6B6Cu: goto label_1e6b6c;
            case 0x1E6B88u: goto label_1e6b88;
            case 0x1E6BCCu: goto label_1e6bcc;
            case 0x1E6BE8u: goto label_1e6be8;
            case 0x1E6BFCu: goto label_1e6bfc;
            case 0x1E6C30u: goto label_1e6c30;
            case 0x1E6C4Cu: goto label_1e6c4c;
            case 0x1E6C58u: goto label_1e6c58;
            case 0x1E6C6Cu: goto label_1e6c6c;
            case 0x1E6C84u: goto label_1e6c84;
            case 0x1E6CB4u: goto label_1e6cb4;
            case 0x1E6CD8u: goto label_1e6cd8;
            case 0x1E6CECu: goto label_1e6cec;
            case 0x1E6CF0u: goto label_1e6cf0;
            case 0x1E6D5Cu: goto label_1e6d5c;
            case 0x1E6D70u: goto label_1e6d70;
            case 0x1E6DB0u: goto label_1e6db0;
            case 0x1E6DC0u: goto label_1e6dc0;
            case 0x1E6DE4u: goto label_1e6de4;
            case 0x1E6DF4u: goto label_1e6df4;
            case 0x1E6E18u: goto label_1e6e18;
            case 0x1E6E2Cu: goto label_1e6e2c;
            case 0x1E6E38u: goto label_1e6e38;
            case 0x1E6E48u: goto label_1e6e48;
            case 0x1E6E60u: goto label_1e6e60;
            case 0x1E6E90u: goto label_1e6e90;
            case 0x1E6EFCu: goto label_1e6efc;
            case 0x1E6F14u: goto label_1e6f14;
            case 0x1E6F28u: goto label_1e6f28;
            case 0x1E6F3Cu: goto label_1e6f3c;
            case 0x1E6F48u: goto label_1e6f48;
            case 0x1E6F5Cu: goto label_1e6f5c;
            case 0x1E6F80u: goto label_1e6f80;
            case 0x1E6F94u: goto label_1e6f94;
            case 0x1E6FBCu: goto label_1e6fbc;
            case 0x1E6FD8u: goto label_1e6fd8;
            case 0x1E7054u: goto label_1e7054;
            case 0x1E706Cu: goto label_1e706c;
            case 0x1E7080u: goto label_1e7080;
            case 0x1E70B0u: goto label_1e70b0;
            case 0x1E70C4u: goto label_1e70c4;
            case 0x1E70F8u: goto label_1e70f8;
            case 0x1E7114u: goto label_1e7114;
            case 0x1E7158u: goto label_1e7158;
            case 0x1E7174u: goto label_1e7174;
            case 0x1E7188u: goto label_1e7188;
            case 0x1E71BCu: goto label_1e71bc;
            case 0x1E71D8u: goto label_1e71d8;
            case 0x1E71E4u: goto label_1e71e4;
            case 0x1E71F8u: goto label_1e71f8;
            case 0x1E7210u: goto label_1e7210;
            case 0x1E7240u: goto label_1e7240;
            case 0x1E7264u: goto label_1e7264;
            case 0x1E7278u: goto label_1e7278;
            case 0x1E727Cu: goto label_1e727c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E63F8u;
    // 0x1e63f8: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1e63f8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1e63fc: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1e63fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1e6400: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1e6400u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1e6404: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e6404u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e6408: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e6408u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e640c: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e640cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e6410: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e6410u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e6414: 0xafc00014  sw          $zero, 0x14($fp)
    ctx->pc = 0x1e6414u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 0));
    // 0x1e6418: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e6418u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e641c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e641cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e6420: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E6420u;
    {
        const bool branch_taken_0x1e6420 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e6420) {
            ctx->pc = 0x1E6448u;
            goto label_1e6448;
        }
    }
    ctx->pc = 0x1E6428u;
    // 0x1e6428: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e6428u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e642c: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e642cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e6430: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e6430u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e6434: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e6434u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e6438: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e6438u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e643c: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e643cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e6440: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E6440u;
    {
        const bool branch_taken_0x1e6440 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e6440) {
            ctx->pc = 0x1E645Cu;
            goto label_1e645c;
        }
    }
    ctx->pc = 0x1E6448u;
label_1e6448:
    // 0x1e6448: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e6448u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e644c: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e644cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e6450: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e6450u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e6454: 0x1000004d  b           . + 4 + (0x4D << 2)
    ctx->pc = 0x1E6454u;
    {
        const bool branch_taken_0x1e6454 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6454) {
            ctx->pc = 0x1E658Cu;
            goto label_1e658c;
        }
    }
    ctx->pc = 0x1E645Cu;
label_1e645c:
    // 0x1e645c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e645cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e6460: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e6460u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e6464: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e6464u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e6468: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e6468u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e646c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e646cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e6470: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e6470u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e6474: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1e6474u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1e6478: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e6478u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e647c: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e647cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e6480: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E6480u;
    {
        const bool branch_taken_0x1e6480 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6480) {
            ctx->pc = 0x1E649Cu;
            goto label_1e649c;
        }
    }
    ctx->pc = 0x1E6488u;
    // 0x1e6488: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e6488u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e648c: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e648cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e6490: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e6490u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e6494: 0x1000003d  b           . + 4 + (0x3D << 2)
    ctx->pc = 0x1E6494u;
    {
        const bool branch_taken_0x1e6494 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6494) {
            ctx->pc = 0x1E658Cu;
            goto label_1e658c;
        }
    }
    ctx->pc = 0x1E649Cu;
label_1e649c:
    // 0x1e649c: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1e649cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e64a0: 0x2c42036c  sltiu       $v0, $v0, 0x36C
    ctx->pc = 0x1e64a0u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)876) ? 1 : 0);
    // 0x1e64a4: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1E64A4u;
    {
        const bool branch_taken_0x1e64a4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e64a4) {
            ctx->pc = 0x1E64B4u;
            goto label_1e64b4;
        }
    }
    ctx->pc = 0x1E64ACu;
    // 0x1e64ac: 0x2402036c  addiu       $v0, $zero, 0x36C
    ctx->pc = 0x1e64acu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 876));
    // 0x1e64b0: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1e64b0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
label_1e64b4:
    // 0x1e64b4: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e64b4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e64b8: 0x8fc50008  lw          $a1, 0x8($fp)
    ctx->pc = 0x1e64b8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e64bc: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E64BCu;
    SET_GPR_U32(ctx, 31, 0x1E64C4u);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E64C4u; }
        if (ctx->pc != 0x1E64C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E64C4u; }
        if (ctx->pc != 0x1E64C4u) { return; }
    }
    ctx->pc = 0x1E64C4u;
label_1e64c4:
    // 0x1e64c4: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1e64c4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1e64c8: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e64c8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e64cc: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E64CCu;
    {
        const bool branch_taken_0x1e64cc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e64cc) {
            ctx->pc = 0x1E64E8u;
            goto label_1e64e8;
        }
    }
    ctx->pc = 0x1E64D4u;
    // 0x1e64d4: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e64d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e64d8: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e64d8u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e64dc: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e64dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e64e0: 0x1000002a  b           . + 4 + (0x2A << 2)
    ctx->pc = 0x1E64E0u;
    {
        const bool branch_taken_0x1e64e0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e64e0) {
            ctx->pc = 0x1E658Cu;
            goto label_1e658c;
        }
    }
    ctx->pc = 0x1E64E8u;
label_1e64e8:
    // 0x1e64e8: 0x97c20008  lhu         $v0, 0x8($fp)
    ctx->pc = 0x1e64e8u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e64ec: 0x8fc40010  lw          $a0, 0x10($fp)
    ctx->pc = 0x1e64ecu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e64f0: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1e64f0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e64f4: 0xc07cc3c  jal         func_1F30F0
    ctx->pc = 0x1E64F4u;
    SET_GPR_U32(ctx, 31, 0x1E64FCu);
    ctx->pc = 0x1F30F0u;
    if (runtime->hasFunction(0x1F30F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F30F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E64FCu; }
        if (ctx->pc != 0x1E64FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F30F0_0x1f30f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E64FCu; }
        if (ctx->pc != 0x1E64FCu) { return; }
    }
    ctx->pc = 0x1E64FCu;
label_1e64fc:
    // 0x1e64fc: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1e64fcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1e6500: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e6500u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e6504: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1E6504u;
    {
        const bool branch_taken_0x1e6504 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e6504) {
            ctx->pc = 0x1E6534u;
            goto label_1e6534;
        }
    }
    ctx->pc = 0x1E650Cu;
    // 0x1e650c: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e650cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e6510: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1e6510u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1e6514: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e6514u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e6518: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1E6518u;
    SET_GPR_U32(ctx, 31, 0x1E6520u);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6520u; }
        if (ctx->pc != 0x1E6520u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6520u; }
        if (ctx->pc != 0x1E6520u) { return; }
    }
    ctx->pc = 0x1E6520u;
label_1e6520:
    // 0x1e6520: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e6520u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e6524: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e6524u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e6528: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e6528u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e652c: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x1E652Cu;
    {
        const bool branch_taken_0x1e652c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e652c) {
            ctx->pc = 0x1E658Cu;
            goto label_1e658c;
        }
    }
    ctx->pc = 0x1E6534u;
label_1e6534:
    // 0x1e6534: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1e6534u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e6538: 0x8fc50004  lw          $a1, 0x4($fp)
    ctx->pc = 0x1e6538u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e653c: 0x8fc60008  lw          $a2, 0x8($fp)
    ctx->pc = 0x1e653cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e6540: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1E6540u;
    SET_GPR_U32(ctx, 31, 0x1E6548u);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6548u; }
        if (ctx->pc != 0x1E6548u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6548u; }
        if (ctx->pc != 0x1E6548u) { return; }
    }
    ctx->pc = 0x1E6548u;
label_1e6548:
    // 0x1e6548: 0x97c20008  lhu         $v0, 0x8($fp)
    ctx->pc = 0x1e6548u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e654c: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e654cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e6550: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e6550u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e6554: 0x3406b000  ori         $a2, $zero, 0xB000
    ctx->pc = 0x1e6554u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)45056);
    // 0x1e6558: 0x40382d  daddu       $a3, $v0, $zero
    ctx->pc = 0x1e6558u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e655c: 0x2408003e  addiu       $t0, $zero, 0x3E
    ctx->pc = 0x1e655cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 62));
    // 0x1e6560: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1e6560u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e6564: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E6564u;
    SET_GPR_U32(ctx, 31, 0x1E656Cu);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E656Cu; }
        if (ctx->pc != 0x1E656Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E656Cu; }
        if (ctx->pc != 0x1E656Cu) { return; }
    }
    ctx->pc = 0x1E656Cu;
label_1e656c:
    // 0x1e656c: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E656Cu;
    {
        const bool branch_taken_0x1e656c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e656c) {
            ctx->pc = 0x1E6588u;
            goto label_1e6588;
        }
    }
    ctx->pc = 0x1E6574u;
    // 0x1e6574: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e6574u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e6578: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e6578u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e657c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e657cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e6580: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1E6580u;
    {
        const bool branch_taken_0x1e6580 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6580) {
            ctx->pc = 0x1E658Cu;
            goto label_1e658c;
        }
    }
    ctx->pc = 0x1E6588u;
label_1e6588:
    // 0x1e6588: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1e6588u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1e658c:
    // 0x1e658c: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e658cu;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e6590: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1e6590u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1e6594: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1e6594u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1e6598: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1e6598u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1e659c: 0x3e00008  jr          $ra
    ctx->pc = 0x1E659Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E5060u: goto label_1e5060;
            case 0x1E5074u: goto label_1e5074;
            case 0x1E50B4u: goto label_1e50b4;
            case 0x1E50C4u: goto label_1e50c4;
            case 0x1E50E8u: goto label_1e50e8;
            case 0x1E50FCu: goto label_1e50fc;
            case 0x1E5120u: goto label_1e5120;
            case 0x1E5134u: goto label_1e5134;
            case 0x1E5148u: goto label_1e5148;
            case 0x1E5178u: goto label_1e5178;
            case 0x1E5194u: goto label_1e5194;
            case 0x1E5198u: goto label_1e5198;
            case 0x1E5238u: goto label_1e5238;
            case 0x1E524Cu: goto label_1e524c;
            case 0x1E528Cu: goto label_1e528c;
            case 0x1E52B0u: goto label_1e52b0;
            case 0x1E52D4u: goto label_1e52d4;
            case 0x1E530Cu: goto label_1e530c;
            case 0x1E536Cu: goto label_1e536c;
            case 0x1E5388u: goto label_1e5388;
            case 0x1E5410u: goto label_1e5410;
            case 0x1E5424u: goto label_1e5424;
            case 0x1E5464u: goto label_1e5464;
            case 0x1E5480u: goto label_1e5480;
            case 0x1E5484u: goto label_1e5484;
            case 0x1E54F8u: goto label_1e54f8;
            case 0x1E550Cu: goto label_1e550c;
            case 0x1E554Cu: goto label_1e554c;
            case 0x1E5574u: goto label_1e5574;
            case 0x1E5598u: goto label_1e5598;
            case 0x1E55C8u: goto label_1e55c8;
            case 0x1E55ECu: goto label_1e55ec;
            case 0x1E5600u: goto label_1e5600;
            case 0x1E566Cu: goto label_1e566c;
            case 0x1E568Cu: goto label_1e568c;
            case 0x1E5748u: goto label_1e5748;
            case 0x1E575Cu: goto label_1e575c;
            case 0x1E57A0u: goto label_1e57a0;
            case 0x1E57BCu: goto label_1e57bc;
            case 0x1E57C0u: goto label_1e57c0;
            case 0x1E5820u: goto label_1e5820;
            case 0x1E5834u: goto label_1e5834;
            case 0x1E5874u: goto label_1e5874;
            case 0x1E5884u: goto label_1e5884;
            case 0x1E58A8u: goto label_1e58a8;
            case 0x1E58C8u: goto label_1e58c8;
            case 0x1E58E4u: goto label_1e58e4;
            case 0x1E58E8u: goto label_1e58e8;
            case 0x1E5948u: goto label_1e5948;
            case 0x1E595Cu: goto label_1e595c;
            case 0x1E599Cu: goto label_1e599c;
            case 0x1E59ACu: goto label_1e59ac;
            case 0x1E59D0u: goto label_1e59d0;
            case 0x1E59F0u: goto label_1e59f0;
            case 0x1E5A0Cu: goto label_1e5a0c;
            case 0x1E5A10u: goto label_1e5a10;
            case 0x1E5A80u: goto label_1e5a80;
            case 0x1E5A94u: goto label_1e5a94;
            case 0x1E5AD4u: goto label_1e5ad4;
            case 0x1E5AE4u: goto label_1e5ae4;
            case 0x1E5B08u: goto label_1e5b08;
            case 0x1E5B1Cu: goto label_1e5b1c;
            case 0x1E5B40u: goto label_1e5b40;
            case 0x1E5B54u: goto label_1e5b54;
            case 0x1E5B68u: goto label_1e5b68;
            case 0x1E5B98u: goto label_1e5b98;
            case 0x1E5BB4u: goto label_1e5bb4;
            case 0x1E5BB8u: goto label_1e5bb8;
            case 0x1E5C2Cu: goto label_1e5c2c;
            case 0x1E5C40u: goto label_1e5c40;
            case 0x1E5C80u: goto label_1e5c80;
            case 0x1E5C90u: goto label_1e5c90;
            case 0x1E5CB4u: goto label_1e5cb4;
            case 0x1E5CC8u: goto label_1e5cc8;
            case 0x1E5CECu: goto label_1e5cec;
            case 0x1E5D00u: goto label_1e5d00;
            case 0x1E5D14u: goto label_1e5d14;
            case 0x1E5D48u: goto label_1e5d48;
            case 0x1E5D64u: goto label_1e5d64;
            case 0x1E5D78u: goto label_1e5d78;
            case 0x1E5D94u: goto label_1e5d94;
            case 0x1E5E04u: goto label_1e5e04;
            case 0x1E5E18u: goto label_1e5e18;
            case 0x1E5E58u: goto label_1e5e58;
            case 0x1E5E68u: goto label_1e5e68;
            case 0x1E5E8Cu: goto label_1e5e8c;
            case 0x1E5E9Cu: goto label_1e5e9c;
            case 0x1E5EB4u: goto label_1e5eb4;
            case 0x1E5F6Cu: goto label_1e5f6c;
            case 0x1E5F88u: goto label_1e5f88;
            case 0x1E5F9Cu: goto label_1e5f9c;
            case 0x1E5FA0u: goto label_1e5fa0;
            case 0x1E6008u: goto label_1e6008;
            case 0x1E601Cu: goto label_1e601c;
            case 0x1E605Cu: goto label_1e605c;
            case 0x1E6068u: goto label_1e6068;
            case 0x1E6084u: goto label_1e6084;
            case 0x1E6094u: goto label_1e6094;
            case 0x1E60B8u: goto label_1e60b8;
            case 0x1E60CCu: goto label_1e60cc;
            case 0x1E60F0u: goto label_1e60f0;
            case 0x1E6104u: goto label_1e6104;
            case 0x1E6118u: goto label_1e6118;
            case 0x1E613Cu: goto label_1e613c;
            case 0x1E6158u: goto label_1e6158;
            case 0x1E616Cu: goto label_1e616c;
            case 0x1E6170u: goto label_1e6170;
            case 0x1E61D4u: goto label_1e61d4;
            case 0x1E61E8u: goto label_1e61e8;
            case 0x1E6228u: goto label_1e6228;
            case 0x1E623Cu: goto label_1e623c;
            case 0x1E6240u: goto label_1e6240;
            case 0x1E62A4u: goto label_1e62a4;
            case 0x1E62B8u: goto label_1e62b8;
            case 0x1E62F8u: goto label_1e62f8;
            case 0x1E630Cu: goto label_1e630c;
            case 0x1E6310u: goto label_1e6310;
            case 0x1E6374u: goto label_1e6374;
            case 0x1E6388u: goto label_1e6388;
            case 0x1E63C8u: goto label_1e63c8;
            case 0x1E63DCu: goto label_1e63dc;
            case 0x1E63E0u: goto label_1e63e0;
            case 0x1E6448u: goto label_1e6448;
            case 0x1E645Cu: goto label_1e645c;
            case 0x1E649Cu: goto label_1e649c;
            case 0x1E64B4u: goto label_1e64b4;
            case 0x1E64C4u: goto label_1e64c4;
            case 0x1E64E8u: goto label_1e64e8;
            case 0x1E64FCu: goto label_1e64fc;
            case 0x1E6520u: goto label_1e6520;
            case 0x1E6534u: goto label_1e6534;
            case 0x1E6548u: goto label_1e6548;
            case 0x1E656Cu: goto label_1e656c;
            case 0x1E6588u: goto label_1e6588;
            case 0x1E658Cu: goto label_1e658c;
            case 0x1E65F8u: goto label_1e65f8;
            case 0x1E660Cu: goto label_1e660c;
            case 0x1E664Cu: goto label_1e664c;
            case 0x1E6664u: goto label_1e6664;
            case 0x1E6674u: goto label_1e6674;
            case 0x1E6698u: goto label_1e6698;
            case 0x1E66ACu: goto label_1e66ac;
            case 0x1E66D0u: goto label_1e66d0;
            case 0x1E66E4u: goto label_1e66e4;
            case 0x1E66FCu: goto label_1e66fc;
            case 0x1E6718u: goto label_1e6718;
            case 0x1E6744u: goto label_1e6744;
            case 0x1E6760u: goto label_1e6760;
            case 0x1E6764u: goto label_1e6764;
            case 0x1E67D0u: goto label_1e67d0;
            case 0x1E67E4u: goto label_1e67e4;
            case 0x1E6824u: goto label_1e6824;
            case 0x1E6834u: goto label_1e6834;
            case 0x1E6858u: goto label_1e6858;
            case 0x1E6868u: goto label_1e6868;
            case 0x1E688Cu: goto label_1e688c;
            case 0x1E68A0u: goto label_1e68a0;
            case 0x1E68ACu: goto label_1e68ac;
            case 0x1E68BCu: goto label_1e68bc;
            case 0x1E68D4u: goto label_1e68d4;
            case 0x1E6904u: goto label_1e6904;
            case 0x1E6970u: goto label_1e6970;
            case 0x1E6988u: goto label_1e6988;
            case 0x1E699Cu: goto label_1e699c;
            case 0x1E69B0u: goto label_1e69b0;
            case 0x1E69BCu: goto label_1e69bc;
            case 0x1E69D0u: goto label_1e69d0;
            case 0x1E69F4u: goto label_1e69f4;
            case 0x1E6A08u: goto label_1e6a08;
            case 0x1E6A30u: goto label_1e6a30;
            case 0x1E6A4Cu: goto label_1e6a4c;
            case 0x1E6AC8u: goto label_1e6ac8;
            case 0x1E6AE0u: goto label_1e6ae0;
            case 0x1E6AF4u: goto label_1e6af4;
            case 0x1E6B24u: goto label_1e6b24;
            case 0x1E6B38u: goto label_1e6b38;
            case 0x1E6B6Cu: goto label_1e6b6c;
            case 0x1E6B88u: goto label_1e6b88;
            case 0x1E6BCCu: goto label_1e6bcc;
            case 0x1E6BE8u: goto label_1e6be8;
            case 0x1E6BFCu: goto label_1e6bfc;
            case 0x1E6C30u: goto label_1e6c30;
            case 0x1E6C4Cu: goto label_1e6c4c;
            case 0x1E6C58u: goto label_1e6c58;
            case 0x1E6C6Cu: goto label_1e6c6c;
            case 0x1E6C84u: goto label_1e6c84;
            case 0x1E6CB4u: goto label_1e6cb4;
            case 0x1E6CD8u: goto label_1e6cd8;
            case 0x1E6CECu: goto label_1e6cec;
            case 0x1E6CF0u: goto label_1e6cf0;
            case 0x1E6D5Cu: goto label_1e6d5c;
            case 0x1E6D70u: goto label_1e6d70;
            case 0x1E6DB0u: goto label_1e6db0;
            case 0x1E6DC0u: goto label_1e6dc0;
            case 0x1E6DE4u: goto label_1e6de4;
            case 0x1E6DF4u: goto label_1e6df4;
            case 0x1E6E18u: goto label_1e6e18;
            case 0x1E6E2Cu: goto label_1e6e2c;
            case 0x1E6E38u: goto label_1e6e38;
            case 0x1E6E48u: goto label_1e6e48;
            case 0x1E6E60u: goto label_1e6e60;
            case 0x1E6E90u: goto label_1e6e90;
            case 0x1E6EFCu: goto label_1e6efc;
            case 0x1E6F14u: goto label_1e6f14;
            case 0x1E6F28u: goto label_1e6f28;
            case 0x1E6F3Cu: goto label_1e6f3c;
            case 0x1E6F48u: goto label_1e6f48;
            case 0x1E6F5Cu: goto label_1e6f5c;
            case 0x1E6F80u: goto label_1e6f80;
            case 0x1E6F94u: goto label_1e6f94;
            case 0x1E6FBCu: goto label_1e6fbc;
            case 0x1E6FD8u: goto label_1e6fd8;
            case 0x1E7054u: goto label_1e7054;
            case 0x1E706Cu: goto label_1e706c;
            case 0x1E7080u: goto label_1e7080;
            case 0x1E70B0u: goto label_1e70b0;
            case 0x1E70C4u: goto label_1e70c4;
            case 0x1E70F8u: goto label_1e70f8;
            case 0x1E7114u: goto label_1e7114;
            case 0x1E7158u: goto label_1e7158;
            case 0x1E7174u: goto label_1e7174;
            case 0x1E7188u: goto label_1e7188;
            case 0x1E71BCu: goto label_1e71bc;
            case 0x1E71D8u: goto label_1e71d8;
            case 0x1E71E4u: goto label_1e71e4;
            case 0x1E71F8u: goto label_1e71f8;
            case 0x1E7210u: goto label_1e7210;
            case 0x1E7240u: goto label_1e7240;
            case 0x1E7264u: goto label_1e7264;
            case 0x1E7278u: goto label_1e7278;
            case 0x1E727Cu: goto label_1e727c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E65A4u;
    // 0x1e65a4: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1e65a4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1e65a8: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1e65a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1e65ac: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1e65acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1e65b0: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e65b0u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e65b4: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e65b4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e65b8: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e65b8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e65bc: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e65bcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e65c0: 0xafc7000c  sw          $a3, 0xC($fp)
    ctx->pc = 0x1e65c0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 7));
    // 0x1e65c4: 0xafc00018  sw          $zero, 0x18($fp)
    ctx->pc = 0x1e65c4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 0));
    // 0x1e65c8: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e65c8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e65cc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e65ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e65d0: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E65D0u;
    {
        const bool branch_taken_0x1e65d0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e65d0) {
            ctx->pc = 0x1E65F8u;
            goto label_1e65f8;
        }
    }
    ctx->pc = 0x1E65D8u;
    // 0x1e65d8: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e65d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e65dc: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e65dcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e65e0: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e65e0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e65e4: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e65e4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e65e8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e65e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e65ec: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e65ecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e65f0: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E65F0u;
    {
        const bool branch_taken_0x1e65f0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e65f0) {
            ctx->pc = 0x1E660Cu;
            goto label_1e660c;
        }
    }
    ctx->pc = 0x1E65F8u;
label_1e65f8:
    // 0x1e65f8: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e65f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e65fc: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e65fcu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e6600: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e6600u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e6604: 0x10000057  b           . + 4 + (0x57 << 2)
    ctx->pc = 0x1E6604u;
    {
        const bool branch_taken_0x1e6604 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6604) {
            ctx->pc = 0x1E6764u;
            goto label_1e6764;
        }
    }
    ctx->pc = 0x1E660Cu;
label_1e660c:
    // 0x1e660c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e660cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e6610: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e6610u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e6614: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e6614u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e6618: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e6618u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e661c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e661cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e6620: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e6620u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e6624: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1e6624u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1e6628: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e6628u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e662c: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e662cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e6630: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E6630u;
    {
        const bool branch_taken_0x1e6630 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6630) {
            ctx->pc = 0x1E664Cu;
            goto label_1e664c;
        }
    }
    ctx->pc = 0x1E6638u;
    // 0x1e6638: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e6638u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e663c: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e663cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e6640: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e6640u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e6644: 0x10000047  b           . + 4 + (0x47 << 2)
    ctx->pc = 0x1E6644u;
    {
        const bool branch_taken_0x1e6644 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6644) {
            ctx->pc = 0x1E6764u;
            goto label_1e6764;
        }
    }
    ctx->pc = 0x1E664Cu;
label_1e664c:
    // 0x1e664c: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e664cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e6650: 0x2c420368  sltiu       $v0, $v0, 0x368
    ctx->pc = 0x1e6650u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)872) ? 1 : 0);
    // 0x1e6654: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1E6654u;
    {
        const bool branch_taken_0x1e6654 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e6654) {
            ctx->pc = 0x1E6664u;
            goto label_1e6664;
        }
    }
    ctx->pc = 0x1E665Cu;
    // 0x1e665c: 0x24020368  addiu       $v0, $zero, 0x368
    ctx->pc = 0x1e665cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 872));
    // 0x1e6660: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1e6660u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
label_1e6664:
    // 0x1e6664: 0x8fc40018  lw          $a0, 0x18($fp)
    ctx->pc = 0x1e6664u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e6668: 0x8fc5000c  lw          $a1, 0xC($fp)
    ctx->pc = 0x1e6668u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e666c: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E666Cu;
    SET_GPR_U32(ctx, 31, 0x1E6674u);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6674u; }
        if (ctx->pc != 0x1E6674u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6674u; }
        if (ctx->pc != 0x1E6674u) { return; }
    }
    ctx->pc = 0x1E6674u;
label_1e6674:
    // 0x1e6674: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1e6674u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1e6678: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e6678u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e667c: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E667Cu;
    {
        const bool branch_taken_0x1e667c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e667c) {
            ctx->pc = 0x1E6698u;
            goto label_1e6698;
        }
    }
    ctx->pc = 0x1E6684u;
    // 0x1e6684: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e6684u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e6688: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e6688u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e668c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e668cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e6690: 0x10000034  b           . + 4 + (0x34 << 2)
    ctx->pc = 0x1E6690u;
    {
        const bool branch_taken_0x1e6690 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6690) {
            ctx->pc = 0x1E6764u;
            goto label_1e6764;
        }
    }
    ctx->pc = 0x1E6698u;
label_1e6698:
    // 0x1e6698: 0x97c2000c  lhu         $v0, 0xC($fp)
    ctx->pc = 0x1e6698u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e669c: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e669cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e66a0: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1e66a0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e66a4: 0xc07cc3c  jal         func_1F30F0
    ctx->pc = 0x1E66A4u;
    SET_GPR_U32(ctx, 31, 0x1E66ACu);
    ctx->pc = 0x1F30F0u;
    if (runtime->hasFunction(0x1F30F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F30F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E66ACu; }
        if (ctx->pc != 0x1E66ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F30F0_0x1f30f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E66ACu; }
        if (ctx->pc != 0x1E66ACu) { return; }
    }
    ctx->pc = 0x1E66ACu;
label_1e66ac:
    // 0x1e66ac: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1e66acu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1e66b0: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e66b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e66b4: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1E66B4u;
    {
        const bool branch_taken_0x1e66b4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e66b4) {
            ctx->pc = 0x1E66E4u;
            goto label_1e66e4;
        }
    }
    ctx->pc = 0x1E66BCu;
    // 0x1e66bc: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e66bcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e66c0: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1e66c0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1e66c4: 0x8fc50014  lw          $a1, 0x14($fp)
    ctx->pc = 0x1e66c4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e66c8: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1E66C8u;
    SET_GPR_U32(ctx, 31, 0x1E66D0u);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E66D0u; }
        if (ctx->pc != 0x1E66D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E66D0u; }
        if (ctx->pc != 0x1E66D0u) { return; }
    }
    ctx->pc = 0x1E66D0u;
label_1e66d0:
    // 0x1e66d0: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e66d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e66d4: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e66d4u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e66d8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e66d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e66dc: 0x10000021  b           . + 4 + (0x21 << 2)
    ctx->pc = 0x1E66DCu;
    {
        const bool branch_taken_0x1e66dc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e66dc) {
            ctx->pc = 0x1E6764u;
            goto label_1e6764;
        }
    }
    ctx->pc = 0x1E66E4u;
label_1e66e4:
    // 0x1e66e4: 0x27c20004  addiu       $v0, $fp, 0x4
    ctx->pc = 0x1e66e4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 4));
    // 0x1e66e8: 0x8fc40010  lw          $a0, 0x10($fp)
    ctx->pc = 0x1e66e8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e66ec: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1e66ecu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e66f0: 0x24060004  addiu       $a2, $zero, 0x4
    ctx->pc = 0x1e66f0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1e66f4: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1E66F4u;
    SET_GPR_U32(ctx, 31, 0x1E66FCu);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E66FCu; }
        if (ctx->pc != 0x1E66FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E66FCu; }
        if (ctx->pc != 0x1E66FCu) { return; }
    }
    ctx->pc = 0x1E66FCu;
label_1e66fc:
    // 0x1e66fc: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e66fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e6700: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1e6700u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1e6704: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1e6704u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e6708: 0x8fc50008  lw          $a1, 0x8($fp)
    ctx->pc = 0x1e6708u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e670c: 0x8fc6000c  lw          $a2, 0xC($fp)
    ctx->pc = 0x1e670cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e6710: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1E6710u;
    SET_GPR_U32(ctx, 31, 0x1E6718u);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6718u; }
        if (ctx->pc != 0x1E6718u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6718u; }
        if (ctx->pc != 0x1E6718u) { return; }
    }
    ctx->pc = 0x1E6718u;
label_1e6718:
    // 0x1e6718: 0x97c2000c  lhu         $v0, 0xC($fp)
    ctx->pc = 0x1e6718u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e671c: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1e671cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1e6720: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1e6720u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1e6724: 0x8fc40018  lw          $a0, 0x18($fp)
    ctx->pc = 0x1e6724u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e6728: 0x8fc50014  lw          $a1, 0x14($fp)
    ctx->pc = 0x1e6728u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e672c: 0x3406b000  ori         $a2, $zero, 0xB000
    ctx->pc = 0x1e672cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)45056);
    // 0x1e6730: 0x40382d  daddu       $a3, $v0, $zero
    ctx->pc = 0x1e6730u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e6734: 0x2408003f  addiu       $t0, $zero, 0x3F
    ctx->pc = 0x1e6734u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 63));
    // 0x1e6738: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1e6738u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e673c: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E673Cu;
    SET_GPR_U32(ctx, 31, 0x1E6744u);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6744u; }
        if (ctx->pc != 0x1E6744u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6744u; }
        if (ctx->pc != 0x1E6744u) { return; }
    }
    ctx->pc = 0x1E6744u;
label_1e6744:
    // 0x1e6744: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E6744u;
    {
        const bool branch_taken_0x1e6744 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6744) {
            ctx->pc = 0x1E6760u;
            goto label_1e6760;
        }
    }
    ctx->pc = 0x1E674Cu;
    // 0x1e674c: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e674cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e6750: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e6750u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e6754: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e6754u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e6758: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1E6758u;
    {
        const bool branch_taken_0x1e6758 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6758) {
            ctx->pc = 0x1E6764u;
            goto label_1e6764;
        }
    }
    ctx->pc = 0x1E6760u;
label_1e6760:
    // 0x1e6760: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1e6760u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1e6764:
    // 0x1e6764: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e6764u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e6768: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1e6768u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1e676c: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1e676cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1e6770: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1e6770u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1e6774: 0x3e00008  jr          $ra
    ctx->pc = 0x1E6774u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E5060u: goto label_1e5060;
            case 0x1E5074u: goto label_1e5074;
            case 0x1E50B4u: goto label_1e50b4;
            case 0x1E50C4u: goto label_1e50c4;
            case 0x1E50E8u: goto label_1e50e8;
            case 0x1E50FCu: goto label_1e50fc;
            case 0x1E5120u: goto label_1e5120;
            case 0x1E5134u: goto label_1e5134;
            case 0x1E5148u: goto label_1e5148;
            case 0x1E5178u: goto label_1e5178;
            case 0x1E5194u: goto label_1e5194;
            case 0x1E5198u: goto label_1e5198;
            case 0x1E5238u: goto label_1e5238;
            case 0x1E524Cu: goto label_1e524c;
            case 0x1E528Cu: goto label_1e528c;
            case 0x1E52B0u: goto label_1e52b0;
            case 0x1E52D4u: goto label_1e52d4;
            case 0x1E530Cu: goto label_1e530c;
            case 0x1E536Cu: goto label_1e536c;
            case 0x1E5388u: goto label_1e5388;
            case 0x1E5410u: goto label_1e5410;
            case 0x1E5424u: goto label_1e5424;
            case 0x1E5464u: goto label_1e5464;
            case 0x1E5480u: goto label_1e5480;
            case 0x1E5484u: goto label_1e5484;
            case 0x1E54F8u: goto label_1e54f8;
            case 0x1E550Cu: goto label_1e550c;
            case 0x1E554Cu: goto label_1e554c;
            case 0x1E5574u: goto label_1e5574;
            case 0x1E5598u: goto label_1e5598;
            case 0x1E55C8u: goto label_1e55c8;
            case 0x1E55ECu: goto label_1e55ec;
            case 0x1E5600u: goto label_1e5600;
            case 0x1E566Cu: goto label_1e566c;
            case 0x1E568Cu: goto label_1e568c;
            case 0x1E5748u: goto label_1e5748;
            case 0x1E575Cu: goto label_1e575c;
            case 0x1E57A0u: goto label_1e57a0;
            case 0x1E57BCu: goto label_1e57bc;
            case 0x1E57C0u: goto label_1e57c0;
            case 0x1E5820u: goto label_1e5820;
            case 0x1E5834u: goto label_1e5834;
            case 0x1E5874u: goto label_1e5874;
            case 0x1E5884u: goto label_1e5884;
            case 0x1E58A8u: goto label_1e58a8;
            case 0x1E58C8u: goto label_1e58c8;
            case 0x1E58E4u: goto label_1e58e4;
            case 0x1E58E8u: goto label_1e58e8;
            case 0x1E5948u: goto label_1e5948;
            case 0x1E595Cu: goto label_1e595c;
            case 0x1E599Cu: goto label_1e599c;
            case 0x1E59ACu: goto label_1e59ac;
            case 0x1E59D0u: goto label_1e59d0;
            case 0x1E59F0u: goto label_1e59f0;
            case 0x1E5A0Cu: goto label_1e5a0c;
            case 0x1E5A10u: goto label_1e5a10;
            case 0x1E5A80u: goto label_1e5a80;
            case 0x1E5A94u: goto label_1e5a94;
            case 0x1E5AD4u: goto label_1e5ad4;
            case 0x1E5AE4u: goto label_1e5ae4;
            case 0x1E5B08u: goto label_1e5b08;
            case 0x1E5B1Cu: goto label_1e5b1c;
            case 0x1E5B40u: goto label_1e5b40;
            case 0x1E5B54u: goto label_1e5b54;
            case 0x1E5B68u: goto label_1e5b68;
            case 0x1E5B98u: goto label_1e5b98;
            case 0x1E5BB4u: goto label_1e5bb4;
            case 0x1E5BB8u: goto label_1e5bb8;
            case 0x1E5C2Cu: goto label_1e5c2c;
            case 0x1E5C40u: goto label_1e5c40;
            case 0x1E5C80u: goto label_1e5c80;
            case 0x1E5C90u: goto label_1e5c90;
            case 0x1E5CB4u: goto label_1e5cb4;
            case 0x1E5CC8u: goto label_1e5cc8;
            case 0x1E5CECu: goto label_1e5cec;
            case 0x1E5D00u: goto label_1e5d00;
            case 0x1E5D14u: goto label_1e5d14;
            case 0x1E5D48u: goto label_1e5d48;
            case 0x1E5D64u: goto label_1e5d64;
            case 0x1E5D78u: goto label_1e5d78;
            case 0x1E5D94u: goto label_1e5d94;
            case 0x1E5E04u: goto label_1e5e04;
            case 0x1E5E18u: goto label_1e5e18;
            case 0x1E5E58u: goto label_1e5e58;
            case 0x1E5E68u: goto label_1e5e68;
            case 0x1E5E8Cu: goto label_1e5e8c;
            case 0x1E5E9Cu: goto label_1e5e9c;
            case 0x1E5EB4u: goto label_1e5eb4;
            case 0x1E5F6Cu: goto label_1e5f6c;
            case 0x1E5F88u: goto label_1e5f88;
            case 0x1E5F9Cu: goto label_1e5f9c;
            case 0x1E5FA0u: goto label_1e5fa0;
            case 0x1E6008u: goto label_1e6008;
            case 0x1E601Cu: goto label_1e601c;
            case 0x1E605Cu: goto label_1e605c;
            case 0x1E6068u: goto label_1e6068;
            case 0x1E6084u: goto label_1e6084;
            case 0x1E6094u: goto label_1e6094;
            case 0x1E60B8u: goto label_1e60b8;
            case 0x1E60CCu: goto label_1e60cc;
            case 0x1E60F0u: goto label_1e60f0;
            case 0x1E6104u: goto label_1e6104;
            case 0x1E6118u: goto label_1e6118;
            case 0x1E613Cu: goto label_1e613c;
            case 0x1E6158u: goto label_1e6158;
            case 0x1E616Cu: goto label_1e616c;
            case 0x1E6170u: goto label_1e6170;
            case 0x1E61D4u: goto label_1e61d4;
            case 0x1E61E8u: goto label_1e61e8;
            case 0x1E6228u: goto label_1e6228;
            case 0x1E623Cu: goto label_1e623c;
            case 0x1E6240u: goto label_1e6240;
            case 0x1E62A4u: goto label_1e62a4;
            case 0x1E62B8u: goto label_1e62b8;
            case 0x1E62F8u: goto label_1e62f8;
            case 0x1E630Cu: goto label_1e630c;
            case 0x1E6310u: goto label_1e6310;
            case 0x1E6374u: goto label_1e6374;
            case 0x1E6388u: goto label_1e6388;
            case 0x1E63C8u: goto label_1e63c8;
            case 0x1E63DCu: goto label_1e63dc;
            case 0x1E63E0u: goto label_1e63e0;
            case 0x1E6448u: goto label_1e6448;
            case 0x1E645Cu: goto label_1e645c;
            case 0x1E649Cu: goto label_1e649c;
            case 0x1E64B4u: goto label_1e64b4;
            case 0x1E64C4u: goto label_1e64c4;
            case 0x1E64E8u: goto label_1e64e8;
            case 0x1E64FCu: goto label_1e64fc;
            case 0x1E6520u: goto label_1e6520;
            case 0x1E6534u: goto label_1e6534;
            case 0x1E6548u: goto label_1e6548;
            case 0x1E656Cu: goto label_1e656c;
            case 0x1E6588u: goto label_1e6588;
            case 0x1E658Cu: goto label_1e658c;
            case 0x1E65F8u: goto label_1e65f8;
            case 0x1E660Cu: goto label_1e660c;
            case 0x1E664Cu: goto label_1e664c;
            case 0x1E6664u: goto label_1e6664;
            case 0x1E6674u: goto label_1e6674;
            case 0x1E6698u: goto label_1e6698;
            case 0x1E66ACu: goto label_1e66ac;
            case 0x1E66D0u: goto label_1e66d0;
            case 0x1E66E4u: goto label_1e66e4;
            case 0x1E66FCu: goto label_1e66fc;
            case 0x1E6718u: goto label_1e6718;
            case 0x1E6744u: goto label_1e6744;
            case 0x1E6760u: goto label_1e6760;
            case 0x1E6764u: goto label_1e6764;
            case 0x1E67D0u: goto label_1e67d0;
            case 0x1E67E4u: goto label_1e67e4;
            case 0x1E6824u: goto label_1e6824;
            case 0x1E6834u: goto label_1e6834;
            case 0x1E6858u: goto label_1e6858;
            case 0x1E6868u: goto label_1e6868;
            case 0x1E688Cu: goto label_1e688c;
            case 0x1E68A0u: goto label_1e68a0;
            case 0x1E68ACu: goto label_1e68ac;
            case 0x1E68BCu: goto label_1e68bc;
            case 0x1E68D4u: goto label_1e68d4;
            case 0x1E6904u: goto label_1e6904;
            case 0x1E6970u: goto label_1e6970;
            case 0x1E6988u: goto label_1e6988;
            case 0x1E699Cu: goto label_1e699c;
            case 0x1E69B0u: goto label_1e69b0;
            case 0x1E69BCu: goto label_1e69bc;
            case 0x1E69D0u: goto label_1e69d0;
            case 0x1E69F4u: goto label_1e69f4;
            case 0x1E6A08u: goto label_1e6a08;
            case 0x1E6A30u: goto label_1e6a30;
            case 0x1E6A4Cu: goto label_1e6a4c;
            case 0x1E6AC8u: goto label_1e6ac8;
            case 0x1E6AE0u: goto label_1e6ae0;
            case 0x1E6AF4u: goto label_1e6af4;
            case 0x1E6B24u: goto label_1e6b24;
            case 0x1E6B38u: goto label_1e6b38;
            case 0x1E6B6Cu: goto label_1e6b6c;
            case 0x1E6B88u: goto label_1e6b88;
            case 0x1E6BCCu: goto label_1e6bcc;
            case 0x1E6BE8u: goto label_1e6be8;
            case 0x1E6BFCu: goto label_1e6bfc;
            case 0x1E6C30u: goto label_1e6c30;
            case 0x1E6C4Cu: goto label_1e6c4c;
            case 0x1E6C58u: goto label_1e6c58;
            case 0x1E6C6Cu: goto label_1e6c6c;
            case 0x1E6C84u: goto label_1e6c84;
            case 0x1E6CB4u: goto label_1e6cb4;
            case 0x1E6CD8u: goto label_1e6cd8;
            case 0x1E6CECu: goto label_1e6cec;
            case 0x1E6CF0u: goto label_1e6cf0;
            case 0x1E6D5Cu: goto label_1e6d5c;
            case 0x1E6D70u: goto label_1e6d70;
            case 0x1E6DB0u: goto label_1e6db0;
            case 0x1E6DC0u: goto label_1e6dc0;
            case 0x1E6DE4u: goto label_1e6de4;
            case 0x1E6DF4u: goto label_1e6df4;
            case 0x1E6E18u: goto label_1e6e18;
            case 0x1E6E2Cu: goto label_1e6e2c;
            case 0x1E6E38u: goto label_1e6e38;
            case 0x1E6E48u: goto label_1e6e48;
            case 0x1E6E60u: goto label_1e6e60;
            case 0x1E6E90u: goto label_1e6e90;
            case 0x1E6EFCu: goto label_1e6efc;
            case 0x1E6F14u: goto label_1e6f14;
            case 0x1E6F28u: goto label_1e6f28;
            case 0x1E6F3Cu: goto label_1e6f3c;
            case 0x1E6F48u: goto label_1e6f48;
            case 0x1E6F5Cu: goto label_1e6f5c;
            case 0x1E6F80u: goto label_1e6f80;
            case 0x1E6F94u: goto label_1e6f94;
            case 0x1E6FBCu: goto label_1e6fbc;
            case 0x1E6FD8u: goto label_1e6fd8;
            case 0x1E7054u: goto label_1e7054;
            case 0x1E706Cu: goto label_1e706c;
            case 0x1E7080u: goto label_1e7080;
            case 0x1E70B0u: goto label_1e70b0;
            case 0x1E70C4u: goto label_1e70c4;
            case 0x1E70F8u: goto label_1e70f8;
            case 0x1E7114u: goto label_1e7114;
            case 0x1E7158u: goto label_1e7158;
            case 0x1E7174u: goto label_1e7174;
            case 0x1E7188u: goto label_1e7188;
            case 0x1E71BCu: goto label_1e71bc;
            case 0x1E71D8u: goto label_1e71d8;
            case 0x1E71E4u: goto label_1e71e4;
            case 0x1E71F8u: goto label_1e71f8;
            case 0x1E7210u: goto label_1e7210;
            case 0x1E7240u: goto label_1e7240;
            case 0x1E7264u: goto label_1e7264;
            case 0x1E7278u: goto label_1e7278;
            case 0x1E727Cu: goto label_1e727c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E677Cu;
    // 0x1e677c: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1e677cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1e6780: 0xffbe0040  sd          $fp, 0x40($sp)
    ctx->pc = 0x1e6780u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 30));
    // 0x1e6784: 0xffbf0048  sd          $ra, 0x48($sp)
    ctx->pc = 0x1e6784u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 31));
    // 0x1e6788: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e6788u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e678c: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e678cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e6790: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e6790u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e6794: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e6794u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e6798: 0xafc7000c  sw          $a3, 0xC($fp)
    ctx->pc = 0x1e6798u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 7));
    // 0x1e679c: 0xafc00014  sw          $zero, 0x14($fp)
    ctx->pc = 0x1e679cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 0));
    // 0x1e67a0: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e67a0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e67a4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e67a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e67a8: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E67A8u;
    {
        const bool branch_taken_0x1e67a8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e67a8) {
            ctx->pc = 0x1E67D0u;
            goto label_1e67d0;
        }
    }
    ctx->pc = 0x1E67B0u;
    // 0x1e67b0: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e67b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e67b4: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e67b4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e67b8: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e67b8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e67bc: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e67bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e67c0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e67c0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e67c4: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e67c4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e67c8: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E67C8u;
    {
        const bool branch_taken_0x1e67c8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e67c8) {
            ctx->pc = 0x1E67E4u;
            goto label_1e67e4;
        }
    }
    ctx->pc = 0x1E67D0u;
label_1e67d0:
    // 0x1e67d0: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e67d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e67d4: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e67d4u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e67d8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e67d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e67dc: 0x10000144  b           . + 4 + (0x144 << 2)
    ctx->pc = 0x1E67DCu;
    {
        const bool branch_taken_0x1e67dc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e67dc) {
            ctx->pc = 0x1E6CF0u;
            goto label_1e6cf0;
        }
    }
    ctx->pc = 0x1E67E4u;
label_1e67e4:
    // 0x1e67e4: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e67e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e67e8: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e67e8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e67ec: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e67ecu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e67f0: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e67f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e67f4: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e67f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e67f8: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e67f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e67fc: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1e67fcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1e6800: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e6800u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e6804: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e6804u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e6808: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E6808u;
    {
        const bool branch_taken_0x1e6808 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6808) {
            ctx->pc = 0x1E6824u;
            goto label_1e6824;
        }
    }
    ctx->pc = 0x1E6810u;
    // 0x1e6810: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e6810u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e6814: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e6814u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e6818: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e6818u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e681c: 0x10000134  b           . + 4 + (0x134 << 2)
    ctx->pc = 0x1E681Cu;
    {
        const bool branch_taken_0x1e681c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e681c) {
            ctx->pc = 0x1E6CF0u;
            goto label_1e6cf0;
        }
    }
    ctx->pc = 0x1E6824u;
label_1e6824:
    // 0x1e6824: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e6824u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e6828: 0x240502a8  addiu       $a1, $zero, 0x2A8
    ctx->pc = 0x1e6828u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 680));
    // 0x1e682c: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E682Cu;
    SET_GPR_U32(ctx, 31, 0x1E6834u);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6834u; }
        if (ctx->pc != 0x1E6834u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6834u; }
        if (ctx->pc != 0x1E6834u) { return; }
    }
    ctx->pc = 0x1E6834u;
label_1e6834:
    // 0x1e6834: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1e6834u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1e6838: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e6838u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e683c: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E683Cu;
    {
        const bool branch_taken_0x1e683c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e683c) {
            ctx->pc = 0x1E6858u;
            goto label_1e6858;
        }
    }
    ctx->pc = 0x1E6844u;
    // 0x1e6844: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e6844u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e6848: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e6848u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e684c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e684cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e6850: 0x10000127  b           . + 4 + (0x127 << 2)
    ctx->pc = 0x1E6850u;
    {
        const bool branch_taken_0x1e6850 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6850) {
            ctx->pc = 0x1E6CF0u;
            goto label_1e6cf0;
        }
    }
    ctx->pc = 0x1E6858u;
label_1e6858:
    // 0x1e6858: 0x8fc40010  lw          $a0, 0x10($fp)
    ctx->pc = 0x1e6858u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e685c: 0x24050008  addiu       $a1, $zero, 0x8
    ctx->pc = 0x1e685cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1e6860: 0xc07cc3c  jal         func_1F30F0
    ctx->pc = 0x1E6860u;
    SET_GPR_U32(ctx, 31, 0x1E6868u);
    ctx->pc = 0x1F30F0u;
    if (runtime->hasFunction(0x1F30F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F30F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6868u; }
        if (ctx->pc != 0x1E6868u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F30F0_0x1f30f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6868u; }
        if (ctx->pc != 0x1E6868u) { return; }
    }
    ctx->pc = 0x1E6868u;
label_1e6868:
    // 0x1e6868: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1e6868u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1e686c: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1e686cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e6870: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1E6870u;
    {
        const bool branch_taken_0x1e6870 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e6870) {
            ctx->pc = 0x1E68A0u;
            goto label_1e68a0;
        }
    }
    ctx->pc = 0x1E6878u;
    // 0x1e6878: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e6878u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e687c: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1e687cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1e6880: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e6880u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e6884: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1E6884u;
    SET_GPR_U32(ctx, 31, 0x1E688Cu);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E688Cu; }
        if (ctx->pc != 0x1E688Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E688Cu; }
        if (ctx->pc != 0x1E688Cu) { return; }
    }
    ctx->pc = 0x1E688Cu;
label_1e688c:
    // 0x1e688c: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e688cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e6890: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e6890u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e6894: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e6894u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e6898: 0x10000115  b           . + 4 + (0x115 << 2)
    ctx->pc = 0x1E6898u;
    {
        const bool branch_taken_0x1e6898 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6898) {
            ctx->pc = 0x1E6CF0u;
            goto label_1e6cf0;
        }
    }
    ctx->pc = 0x1E68A0u;
label_1e68a0:
    // 0x1e68a0: 0x8fc40008  lw          $a0, 0x8($fp)
    ctx->pc = 0x1e68a0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e68a4: 0xc07a04d  jal         func_1E8134
    ctx->pc = 0x1E68A4u;
    SET_GPR_U32(ctx, 31, 0x1E68ACu);
    ctx->pc = 0x1E8134u;
    if (runtime->hasFunction(0x1E8134u)) {
        auto targetFn = runtime->lookupFunction(0x1E8134u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E68ACu; }
        if (ctx->pc != 0x1E68ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E8134_0x1e8134(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E68ACu; }
        if (ctx->pc != 0x1E68ACu) { return; }
    }
    ctx->pc = 0x1E68ACu;
label_1e68ac:
    // 0x1e68ac: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e68acu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e68b0: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1e68b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e68b4: 0xac430000  sw          $v1, 0x0($v0)
    ctx->pc = 0x1e68b4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x1e68b8: 0xafc00030  sw          $zero, 0x30($fp)
    ctx->pc = 0x1e68b8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 0));
label_1e68bc:
    // 0x1e68bc: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1e68bcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1e68c0: 0x28420020  slti        $v0, $v0, 0x20
    ctx->pc = 0x1e68c0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x1e68c4: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1E68C4u;
    {
        const bool branch_taken_0x1e68c4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e68c4) {
            ctx->pc = 0x1E68D4u;
            goto label_1e68d4;
        }
    }
    ctx->pc = 0x1E68CCu;
    // 0x1e68cc: 0x100000e7  b           . + 4 + (0xE7 << 2)
    ctx->pc = 0x1E68CCu;
    {
        const bool branch_taken_0x1e68cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e68cc) {
            ctx->pc = 0x1E6C6Cu;
            goto label_1e6c6c;
        }
    }
    ctx->pc = 0x1E68D4u;
label_1e68d4:
    // 0x1e68d4: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1e68d4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1e68d8: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1e68d8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e68dc: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x1e68dcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1e68e0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e68e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e68e4: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e68e4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e68e8: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e68e8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e68ec: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e68ecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e68f0: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e68f0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e68f4: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1E68F4u;
    {
        const bool branch_taken_0x1e68f4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e68f4) {
            ctx->pc = 0x1E6904u;
            goto label_1e6904;
        }
    }
    ctx->pc = 0x1E68FCu;
    // 0x1e68fc: 0x100000db  b           . + 4 + (0xDB << 2)
    ctx->pc = 0x1E68FCu;
    {
        const bool branch_taken_0x1e68fc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e68fc) {
            ctx->pc = 0x1E6C6Cu;
            goto label_1e6c6c;
        }
    }
    ctx->pc = 0x1E6904u;
label_1e6904:
    // 0x1e6904: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1e6904u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1e6908: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1e6908u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e690c: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x1e690cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1e6910: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e6910u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e6914: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e6914u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e6918: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e6918u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e691c: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e691cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e6920: 0x8c420004  lw          $v0, 0x4($v0)
    ctx->pc = 0x1e6920u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1e6924: 0x21142  srl         $v0, $v0, 5
    ctx->pc = 0x1e6924u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 5));
    // 0x1e6928: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1e6928u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1e692c: 0x24020005  addiu       $v0, $zero, 0x5
    ctx->pc = 0x1e692cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1e6930: 0xafc20034  sw          $v0, 0x34($fp)
    ctx->pc = 0x1e6930u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 2));
    // 0x1e6934: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1e6934u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1e6938: 0xafc20038  sw          $v0, 0x38($fp)
    ctx->pc = 0x1e6938u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 2));
    // 0x1e693c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e693cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e6940: 0x8fc30038  lw          $v1, 0x38($fp)
    ctx->pc = 0x1e6940u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1e6944: 0x10620015  beq         $v1, $v0, . + 4 + (0x15 << 2)
    ctx->pc = 0x1E6944u;
    {
        const bool branch_taken_0x1e6944 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1e6944) {
            ctx->pc = 0x1E699Cu;
            goto label_1e699c;
        }
    }
    ctx->pc = 0x1E694Cu;
    // 0x1e694c: 0x8fc30038  lw          $v1, 0x38($fp)
    ctx->pc = 0x1e694cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1e6950: 0x28620002  slti        $v0, $v1, 0x2
    ctx->pc = 0x1e6950u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x1e6954: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E6954u;
    {
        const bool branch_taken_0x1e6954 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6954) {
            ctx->pc = 0x1E6970u;
            goto label_1e6970;
        }
    }
    ctx->pc = 0x1E695Cu;
    // 0x1e695c: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1e695cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1e6960: 0x10400013  beqz        $v0, . + 4 + (0x13 << 2)
    ctx->pc = 0x1E6960u;
    {
        const bool branch_taken_0x1e6960 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6960) {
            ctx->pc = 0x1E69B0u;
            goto label_1e69b0;
        }
    }
    ctx->pc = 0x1E6968u;
    // 0x1e6968: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x1E6968u;
    {
        const bool branch_taken_0x1e6968 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6968) {
            ctx->pc = 0x1E69B0u;
            goto label_1e69b0;
        }
    }
    ctx->pc = 0x1E6970u;
label_1e6970:
    // 0x1e6970: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1e6970u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1e6974: 0x8fc30038  lw          $v1, 0x38($fp)
    ctx->pc = 0x1e6974u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1e6978: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1E6978u;
    {
        const bool branch_taken_0x1e6978 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1e6978) {
            ctx->pc = 0x1E6988u;
            goto label_1e6988;
        }
    }
    ctx->pc = 0x1E6980u;
    // 0x1e6980: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x1E6980u;
    {
        const bool branch_taken_0x1e6980 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6980) {
            ctx->pc = 0x1E69B0u;
            goto label_1e69b0;
        }
    }
    ctx->pc = 0x1E6988u;
label_1e6988:
    // 0x1e6988: 0x8fc20034  lw          $v0, 0x34($fp)
    ctx->pc = 0x1e6988u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1e698c: 0x24420010  addiu       $v0, $v0, 0x10
    ctx->pc = 0x1e698cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 16));
    // 0x1e6990: 0xafc20034  sw          $v0, 0x34($fp)
    ctx->pc = 0x1e6990u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 2));
    // 0x1e6994: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1E6994u;
    {
        const bool branch_taken_0x1e6994 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6994) {
            ctx->pc = 0x1E69BCu;
            goto label_1e69bc;
        }
    }
    ctx->pc = 0x1E699Cu;
label_1e699c:
    // 0x1e699c: 0x8fc20034  lw          $v0, 0x34($fp)
    ctx->pc = 0x1e699cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1e69a0: 0x24420008  addiu       $v0, $v0, 0x8
    ctx->pc = 0x1e69a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x1e69a4: 0xafc20034  sw          $v0, 0x34($fp)
    ctx->pc = 0x1e69a4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 2));
    // 0x1e69a8: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1E69A8u;
    {
        const bool branch_taken_0x1e69a8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e69a8) {
            ctx->pc = 0x1E69BCu;
            goto label_1e69bc;
        }
    }
    ctx->pc = 0x1E69B0u;
label_1e69b0:
    // 0x1e69b0: 0x8fc20034  lw          $v0, 0x34($fp)
    ctx->pc = 0x1e69b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1e69b4: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1e69b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1e69b8: 0xafc20034  sw          $v0, 0x34($fp)
    ctx->pc = 0x1e69b8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 2));
label_1e69bc:
    // 0x1e69bc: 0x97c20034  lhu         $v0, 0x34($fp)
    ctx->pc = 0x1e69bcu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1e69c0: 0x8fc40010  lw          $a0, 0x10($fp)
    ctx->pc = 0x1e69c0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e69c4: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1e69c4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e69c8: 0xc07cc3c  jal         func_1F30F0
    ctx->pc = 0x1E69C8u;
    SET_GPR_U32(ctx, 31, 0x1E69D0u);
    ctx->pc = 0x1F30F0u;
    if (runtime->hasFunction(0x1F30F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F30F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E69D0u; }
        if (ctx->pc != 0x1E69D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F30F0_0x1f30f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E69D0u; }
        if (ctx->pc != 0x1E69D0u) { return; }
    }
    ctx->pc = 0x1E69D0u;
label_1e69d0:
    // 0x1e69d0: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1e69d0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1e69d4: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e69d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e69d8: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1E69D8u;
    {
        const bool branch_taken_0x1e69d8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e69d8) {
            ctx->pc = 0x1E6A08u;
            goto label_1e6a08;
        }
    }
    ctx->pc = 0x1E69E0u;
    // 0x1e69e0: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e69e0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e69e4: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1e69e4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1e69e8: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e69e8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e69ec: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1E69ECu;
    SET_GPR_U32(ctx, 31, 0x1E69F4u);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E69F4u; }
        if (ctx->pc != 0x1E69F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E69F4u; }
        if (ctx->pc != 0x1E69F4u) { return; }
    }
    ctx->pc = 0x1E69F4u;
label_1e69f4:
    // 0x1e69f4: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e69f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e69f8: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e69f8u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e69fc: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e69fcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e6a00: 0x100000bb  b           . + 4 + (0xBB << 2)
    ctx->pc = 0x1E6A00u;
    {
        const bool branch_taken_0x1e6a00 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6a00) {
            ctx->pc = 0x1E6CF0u;
            goto label_1e6cf0;
        }
    }
    ctx->pc = 0x1E6A08u;
label_1e6a08:
    // 0x1e6a08: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1e6a08u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1e6a0c: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1e6a0cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e6a10: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x1e6a10u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1e6a14: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e6a14u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e6a18: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e6a18u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e6a1c: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e6a1cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e6a20: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e6a20u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e6a24: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x1e6a24u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e6a28: 0xc07a04d  jal         func_1E8134
    ctx->pc = 0x1E6A28u;
    SET_GPR_U32(ctx, 31, 0x1E6A30u);
    ctx->pc = 0x1E8134u;
    if (runtime->hasFunction(0x1E8134u)) {
        auto targetFn = runtime->lookupFunction(0x1E8134u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6A30u; }
        if (ctx->pc != 0x1E6A30u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E8134_0x1e8134(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6A30u; }
        if (ctx->pc != 0x1E6A30u) { return; }
    }
    ctx->pc = 0x1E6A30u;
label_1e6a30:
    // 0x1e6a30: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1e6a30u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1e6a34: 0x27c20024  addiu       $v0, $fp, 0x24
    ctx->pc = 0x1e6a34u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 36));
    // 0x1e6a38: 0x8fc40020  lw          $a0, 0x20($fp)
    ctx->pc = 0x1e6a38u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e6a3c: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1e6a3cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e6a40: 0x24060004  addiu       $a2, $zero, 0x4
    ctx->pc = 0x1e6a40u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1e6a44: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1E6A44u;
    SET_GPR_U32(ctx, 31, 0x1E6A4Cu);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6A4Cu; }
        if (ctx->pc != 0x1E6A4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6A4Cu; }
        if (ctx->pc != 0x1E6A4Cu) { return; }
    }
    ctx->pc = 0x1E6A4Cu;
label_1e6a4c:
    // 0x1e6a4c: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e6a4cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e6a50: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1e6a50u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1e6a54: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1e6a54u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1e6a58: 0x27c50020  addiu       $a1, $fp, 0x20
    ctx->pc = 0x1e6a58u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 30), 32));
    // 0x1e6a5c: 0x8ca40000  lw          $a0, 0x0($a1)
    ctx->pc = 0x1e6a5cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1e6a60: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1e6a60u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1e6a64: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1e6a64u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e6a68: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x1e6a68u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1e6a6c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e6a6cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e6a70: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e6a70u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e6a74: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e6a74u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e6a78: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e6a78u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e6a7c: 0x90420004  lbu         $v0, 0x4($v0)
    ctx->pc = 0x1e6a7cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1e6a80: 0xa0820000  sb          $v0, 0x0($a0)
    ctx->pc = 0x1e6a80u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1e6a84: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x1e6a84u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1e6a88: 0xaca40000  sw          $a0, 0x0($a1)
    ctx->pc = 0x1e6a88u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 4));
    // 0x1e6a8c: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1e6a8cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1e6a90: 0xafc2003c  sw          $v0, 0x3C($fp)
    ctx->pc = 0x1e6a90u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 2));
    // 0x1e6a94: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e6a94u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e6a98: 0x8fc3003c  lw          $v1, 0x3C($fp)
    ctx->pc = 0x1e6a98u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1e6a9c: 0x10620026  beq         $v1, $v0, . + 4 + (0x26 << 2)
    ctx->pc = 0x1E6A9Cu;
    {
        const bool branch_taken_0x1e6a9c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1e6a9c) {
            ctx->pc = 0x1E6B38u;
            goto label_1e6b38;
        }
    }
    ctx->pc = 0x1E6AA4u;
    // 0x1e6aa4: 0x8fc3003c  lw          $v1, 0x3C($fp)
    ctx->pc = 0x1e6aa4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1e6aa8: 0x28620002  slti        $v0, $v1, 0x2
    ctx->pc = 0x1e6aa8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x1e6aac: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E6AACu;
    {
        const bool branch_taken_0x1e6aac = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6aac) {
            ctx->pc = 0x1E6AC8u;
            goto label_1e6ac8;
        }
    }
    ctx->pc = 0x1E6AB4u;
    // 0x1e6ab4: 0x8fc2003c  lw          $v0, 0x3C($fp)
    ctx->pc = 0x1e6ab4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1e6ab8: 0x10400050  beqz        $v0, . + 4 + (0x50 << 2)
    ctx->pc = 0x1E6AB8u;
    {
        const bool branch_taken_0x1e6ab8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6ab8) {
            ctx->pc = 0x1E6BFCu;
            goto label_1e6bfc;
        }
    }
    ctx->pc = 0x1E6AC0u;
    // 0x1e6ac0: 0x1000004e  b           . + 4 + (0x4E << 2)
    ctx->pc = 0x1E6AC0u;
    {
        const bool branch_taken_0x1e6ac0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6ac0) {
            ctx->pc = 0x1E6BFCu;
            goto label_1e6bfc;
        }
    }
    ctx->pc = 0x1E6AC8u;
label_1e6ac8:
    // 0x1e6ac8: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1e6ac8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1e6acc: 0x8fc3003c  lw          $v1, 0x3C($fp)
    ctx->pc = 0x1e6accu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1e6ad0: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1E6AD0u;
    {
        const bool branch_taken_0x1e6ad0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1e6ad0) {
            ctx->pc = 0x1E6AE0u;
            goto label_1e6ae0;
        }
    }
    ctx->pc = 0x1E6AD8u;
    // 0x1e6ad8: 0x10000048  b           . + 4 + (0x48 << 2)
    ctx->pc = 0x1E6AD8u;
    {
        const bool branch_taken_0x1e6ad8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6ad8) {
            ctx->pc = 0x1E6BFCu;
            goto label_1e6bfc;
        }
    }
    ctx->pc = 0x1E6AE0u;
label_1e6ae0:
    // 0x1e6ae0: 0x8fc40020  lw          $a0, 0x20($fp)
    ctx->pc = 0x1e6ae0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e6ae4: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1e6ae4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e6ae8: 0x24060010  addiu       $a2, $zero, 0x10
    ctx->pc = 0x1e6ae8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1e6aec: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1E6AECu;
    SET_GPR_U32(ctx, 31, 0x1E6AF4u);
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6AF4u; }
        if (ctx->pc != 0x1E6AF4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6AF4u; }
        if (ctx->pc != 0x1E6AF4u) { return; }
    }
    ctx->pc = 0x1E6AF4u;
label_1e6af4:
    // 0x1e6af4: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1e6af4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1e6af8: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1e6af8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e6afc: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x1e6afcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1e6b00: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e6b00u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e6b04: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e6b04u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e6b08: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e6b08u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e6b0c: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e6b0cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e6b10: 0x8fc40020  lw          $a0, 0x20($fp)
    ctx->pc = 0x1e6b10u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e6b14: 0x8c450008  lw          $a1, 0x8($v0)
    ctx->pc = 0x1e6b14u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1e6b18: 0x24060010  addiu       $a2, $zero, 0x10
    ctx->pc = 0x1e6b18u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1e6b1c: 0xc042d7e  jal         func_10B5F8
    ctx->pc = 0x1E6B1Cu;
    SET_GPR_U32(ctx, 31, 0x1E6B24u);
    ctx->pc = 0x10B5F8u;
    if (runtime->hasFunction(0x10B5F8u)) {
        auto targetFn = runtime->lookupFunction(0x10B5F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6B24u; }
        if (ctx->pc != 0x1E6B24u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B5F8_0x10b5f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6B24u; }
        if (ctx->pc != 0x1E6B24u) { return; }
    }
    ctx->pc = 0x1E6B24u;
label_1e6b24:
    // 0x1e6b24: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e6b24u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e6b28: 0x24420010  addiu       $v0, $v0, 0x10
    ctx->pc = 0x1e6b28u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 16));
    // 0x1e6b2c: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1e6b2cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1e6b30: 0x10000049  b           . + 4 + (0x49 << 2)
    ctx->pc = 0x1E6B30u;
    {
        const bool branch_taken_0x1e6b30 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6b30) {
            ctx->pc = 0x1E6C58u;
            goto label_1e6c58;
        }
    }
    ctx->pc = 0x1E6B38u;
label_1e6b38:
    // 0x1e6b38: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1e6b38u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1e6b3c: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1e6b3cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e6b40: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x1e6b40u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1e6b44: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e6b44u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e6b48: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e6b48u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e6b4c: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e6b4cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e6b50: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e6b50u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e6b54: 0x8c420008  lw          $v0, 0x8($v0)
    ctx->pc = 0x1e6b54u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1e6b58: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e6b58u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e6b5c: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1e6b5cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1e6b60: 0x8fc40028  lw          $a0, 0x28($fp)
    ctx->pc = 0x1e6b60u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1e6b64: 0xc07a04d  jal         func_1E8134
    ctx->pc = 0x1E6B64u;
    SET_GPR_U32(ctx, 31, 0x1E6B6Cu);
    ctx->pc = 0x1E8134u;
    if (runtime->hasFunction(0x1E8134u)) {
        auto targetFn = runtime->lookupFunction(0x1E8134u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6B6Cu; }
        if (ctx->pc != 0x1E6B6Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E8134_0x1e8134(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6B6Cu; }
        if (ctx->pc != 0x1E6B6Cu) { return; }
    }
    ctx->pc = 0x1E6B6Cu;
label_1e6b6c:
    // 0x1e6b6c: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1e6b6cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1e6b70: 0x27c20028  addiu       $v0, $fp, 0x28
    ctx->pc = 0x1e6b70u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0x1e6b74: 0x8fc40020  lw          $a0, 0x20($fp)
    ctx->pc = 0x1e6b74u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e6b78: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1e6b78u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e6b7c: 0x24060004  addiu       $a2, $zero, 0x4
    ctx->pc = 0x1e6b7cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1e6b80: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1E6B80u;
    SET_GPR_U32(ctx, 31, 0x1E6B88u);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6B88u; }
        if (ctx->pc != 0x1E6B88u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6B88u; }
        if (ctx->pc != 0x1E6B88u) { return; }
    }
    ctx->pc = 0x1E6B88u;
label_1e6b88:
    // 0x1e6b88: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e6b88u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e6b8c: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1e6b8cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1e6b90: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1e6b90u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1e6b94: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1e6b94u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1e6b98: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1e6b98u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e6b9c: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x1e6b9cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1e6ba0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e6ba0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e6ba4: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e6ba4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e6ba8: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e6ba8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e6bac: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e6bacu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e6bb0: 0x8c420008  lw          $v0, 0x8($v0)
    ctx->pc = 0x1e6bb0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1e6bb4: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1e6bb4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1e6bb8: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e6bb8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e6bbc: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1e6bbcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1e6bc0: 0x8fc40028  lw          $a0, 0x28($fp)
    ctx->pc = 0x1e6bc0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1e6bc4: 0xc07a04d  jal         func_1E8134
    ctx->pc = 0x1E6BC4u;
    SET_GPR_U32(ctx, 31, 0x1E6BCCu);
    ctx->pc = 0x1E8134u;
    if (runtime->hasFunction(0x1E8134u)) {
        auto targetFn = runtime->lookupFunction(0x1E8134u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6BCCu; }
        if (ctx->pc != 0x1E6BCCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E8134_0x1e8134(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6BCCu; }
        if (ctx->pc != 0x1E6BCCu) { return; }
    }
    ctx->pc = 0x1E6BCCu;
label_1e6bcc:
    // 0x1e6bcc: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1e6bccu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1e6bd0: 0x27c20028  addiu       $v0, $fp, 0x28
    ctx->pc = 0x1e6bd0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0x1e6bd4: 0x8fc40020  lw          $a0, 0x20($fp)
    ctx->pc = 0x1e6bd4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e6bd8: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1e6bd8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e6bdc: 0x24060004  addiu       $a2, $zero, 0x4
    ctx->pc = 0x1e6bdcu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1e6be0: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1E6BE0u;
    SET_GPR_U32(ctx, 31, 0x1E6BE8u);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6BE8u; }
        if (ctx->pc != 0x1E6BE8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6BE8u; }
        if (ctx->pc != 0x1E6BE8u) { return; }
    }
    ctx->pc = 0x1E6BE8u;
label_1e6be8:
    // 0x1e6be8: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e6be8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e6bec: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1e6becu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1e6bf0: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1e6bf0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1e6bf4: 0x10000018  b           . + 4 + (0x18 << 2)
    ctx->pc = 0x1E6BF4u;
    {
        const bool branch_taken_0x1e6bf4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6bf4) {
            ctx->pc = 0x1E6C58u;
            goto label_1e6c58;
        }
    }
    ctx->pc = 0x1E6BFCu;
label_1e6bfc:
    // 0x1e6bfc: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1e6bfcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1e6c00: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1e6c00u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e6c04: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x1e6c04u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1e6c08: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e6c08u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e6c0c: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e6c0cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e6c10: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e6c10u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e6c14: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e6c14u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e6c18: 0x8c420008  lw          $v0, 0x8($v0)
    ctx->pc = 0x1e6c18u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1e6c1c: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e6c1cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e6c20: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1e6c20u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1e6c24: 0x8fc40028  lw          $a0, 0x28($fp)
    ctx->pc = 0x1e6c24u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1e6c28: 0xc07a04d  jal         func_1E8134
    ctx->pc = 0x1E6C28u;
    SET_GPR_U32(ctx, 31, 0x1E6C30u);
    ctx->pc = 0x1E8134u;
    if (runtime->hasFunction(0x1E8134u)) {
        auto targetFn = runtime->lookupFunction(0x1E8134u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6C30u; }
        if (ctx->pc != 0x1E6C30u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E8134_0x1e8134(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6C30u; }
        if (ctx->pc != 0x1E6C30u) { return; }
    }
    ctx->pc = 0x1E6C30u;
label_1e6c30:
    // 0x1e6c30: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1e6c30u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1e6c34: 0x27c20028  addiu       $v0, $fp, 0x28
    ctx->pc = 0x1e6c34u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0x1e6c38: 0x8fc40020  lw          $a0, 0x20($fp)
    ctx->pc = 0x1e6c38u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e6c3c: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1e6c3cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e6c40: 0x24060004  addiu       $a2, $zero, 0x4
    ctx->pc = 0x1e6c40u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1e6c44: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1E6C44u;
    SET_GPR_U32(ctx, 31, 0x1E6C4Cu);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6C4Cu; }
        if (ctx->pc != 0x1E6C4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6C4Cu; }
        if (ctx->pc != 0x1E6C4Cu) { return; }
    }
    ctx->pc = 0x1E6C4Cu;
label_1e6c4c:
    // 0x1e6c4c: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e6c4cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e6c50: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1e6c50u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1e6c54: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1e6c54u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
label_1e6c58:
    // 0x1e6c58: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1e6c58u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1e6c5c: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1e6c5cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1e6c60: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1e6c60u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1e6c64: 0x1000ff15  b           . + 4 + (-0xEB << 2)
    ctx->pc = 0x1E6C64u;
    {
        const bool branch_taken_0x1e6c64 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6c64) {
            ctx->pc = 0x1E68BCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1e68bc;
        }
    }
    ctx->pc = 0x1E6C6Cu;
label_1e6c6c:
    // 0x1e6c6c: 0x8fc3001c  lw          $v1, 0x1C($fp)
    ctx->pc = 0x1e6c6cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e6c70: 0x93c20030  lbu         $v0, 0x30($fp)
    ctx->pc = 0x1e6c70u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1e6c74: 0xa0620004  sb          $v0, 0x4($v1)
    ctx->pc = 0x1e6c74u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 4), (uint8_t)GPR_U32(ctx, 2));
    // 0x1e6c78: 0x8fc40010  lw          $a0, 0x10($fp)
    ctx->pc = 0x1e6c78u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e6c7c: 0xc07c6b6  jal         func_1F1AD8
    ctx->pc = 0x1E6C7Cu;
    SET_GPR_U32(ctx, 31, 0x1E6C84u);
    ctx->pc = 0x1F1AD8u;
    if (runtime->hasFunction(0x1F1AD8u)) {
        auto targetFn = runtime->lookupFunction(0x1F1AD8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6C84u; }
        if (ctx->pc != 0x1E6C84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1AD8_0x1f1ad8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6C84u; }
        if (ctx->pc != 0x1E6C84u) { return; }
    }
    ctx->pc = 0x1E6C84u;
label_1e6c84:
    // 0x1e6c84: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e6c84u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e6c88: 0x3402fff0  ori         $v0, $zero, 0xFFF0
    ctx->pc = 0x1e6c88u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65520);
    // 0x1e6c8c: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e6c8cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e6c90: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1e6c90u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1e6c94: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e6c94u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e6c98: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e6c98u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e6c9c: 0x3406b000  ori         $a2, $zero, 0xB000
    ctx->pc = 0x1e6c9cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)45056);
    // 0x1e6ca0: 0x40382d  daddu       $a3, $v0, $zero
    ctx->pc = 0x1e6ca0u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e6ca4: 0x24080048  addiu       $t0, $zero, 0x48
    ctx->pc = 0x1e6ca4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 72));
    // 0x1e6ca8: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1e6ca8u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e6cac: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E6CACu;
    SET_GPR_U32(ctx, 31, 0x1E6CB4u);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6CB4u; }
        if (ctx->pc != 0x1E6CB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6CB4u; }
        if (ctx->pc != 0x1E6CB4u) { return; }
    }
    ctx->pc = 0x1E6CB4u;
label_1e6cb4:
    // 0x1e6cb4: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1e6cb4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1e6cb8: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e6cb8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e6cbc: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E6CBCu;
    {
        const bool branch_taken_0x1e6cbc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6cbc) {
            ctx->pc = 0x1E6CD8u;
            goto label_1e6cd8;
        }
    }
    ctx->pc = 0x1E6CC4u;
    // 0x1e6cc4: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e6cc4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e6cc8: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e6cc8u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e6ccc: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e6cccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e6cd0: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1E6CD0u;
    {
        const bool branch_taken_0x1e6cd0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6cd0) {
            ctx->pc = 0x1E6CF0u;
            goto label_1e6cf0;
        }
    }
    ctx->pc = 0x1E6CD8u;
label_1e6cd8:
    // 0x1e6cd8: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1e6cd8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e6cdc: 0x24050031  addiu       $a1, $zero, 0x31
    ctx->pc = 0x1e6cdcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 49));
    // 0x1e6ce0: 0x8fc6000c  lw          $a2, 0xC($fp)
    ctx->pc = 0x1e6ce0u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e6ce4: 0xc076ad5  jal         func_1DAB54
    ctx->pc = 0x1E6CE4u;
    SET_GPR_U32(ctx, 31, 0x1E6CECu);
    ctx->pc = 0x1DAB54u;
    if (runtime->hasFunction(0x1DAB54u)) {
        auto targetFn = runtime->lookupFunction(0x1DAB54u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6CECu; }
        if (ctx->pc != 0x1E6CECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DAB54_0x1dab54(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6CECu; }
        if (ctx->pc != 0x1E6CECu) { return; }
    }
    ctx->pc = 0x1E6CECu;
label_1e6cec:
    // 0x1e6cec: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1e6cecu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1e6cf0:
    // 0x1e6cf0: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e6cf0u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e6cf4: 0xdfbe0040  ld          $fp, 0x40($sp)
    ctx->pc = 0x1e6cf4u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1e6cf8: 0xdfbf0048  ld          $ra, 0x48($sp)
    ctx->pc = 0x1e6cf8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x1e6cfc: 0x27bd0050  addiu       $sp, $sp, 0x50
    ctx->pc = 0x1e6cfcu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
    // 0x1e6d00: 0x3e00008  jr          $ra
    ctx->pc = 0x1E6D00u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E5060u: goto label_1e5060;
            case 0x1E5074u: goto label_1e5074;
            case 0x1E50B4u: goto label_1e50b4;
            case 0x1E50C4u: goto label_1e50c4;
            case 0x1E50E8u: goto label_1e50e8;
            case 0x1E50FCu: goto label_1e50fc;
            case 0x1E5120u: goto label_1e5120;
            case 0x1E5134u: goto label_1e5134;
            case 0x1E5148u: goto label_1e5148;
            case 0x1E5178u: goto label_1e5178;
            case 0x1E5194u: goto label_1e5194;
            case 0x1E5198u: goto label_1e5198;
            case 0x1E5238u: goto label_1e5238;
            case 0x1E524Cu: goto label_1e524c;
            case 0x1E528Cu: goto label_1e528c;
            case 0x1E52B0u: goto label_1e52b0;
            case 0x1E52D4u: goto label_1e52d4;
            case 0x1E530Cu: goto label_1e530c;
            case 0x1E536Cu: goto label_1e536c;
            case 0x1E5388u: goto label_1e5388;
            case 0x1E5410u: goto label_1e5410;
            case 0x1E5424u: goto label_1e5424;
            case 0x1E5464u: goto label_1e5464;
            case 0x1E5480u: goto label_1e5480;
            case 0x1E5484u: goto label_1e5484;
            case 0x1E54F8u: goto label_1e54f8;
            case 0x1E550Cu: goto label_1e550c;
            case 0x1E554Cu: goto label_1e554c;
            case 0x1E5574u: goto label_1e5574;
            case 0x1E5598u: goto label_1e5598;
            case 0x1E55C8u: goto label_1e55c8;
            case 0x1E55ECu: goto label_1e55ec;
            case 0x1E5600u: goto label_1e5600;
            case 0x1E566Cu: goto label_1e566c;
            case 0x1E568Cu: goto label_1e568c;
            case 0x1E5748u: goto label_1e5748;
            case 0x1E575Cu: goto label_1e575c;
            case 0x1E57A0u: goto label_1e57a0;
            case 0x1E57BCu: goto label_1e57bc;
            case 0x1E57C0u: goto label_1e57c0;
            case 0x1E5820u: goto label_1e5820;
            case 0x1E5834u: goto label_1e5834;
            case 0x1E5874u: goto label_1e5874;
            case 0x1E5884u: goto label_1e5884;
            case 0x1E58A8u: goto label_1e58a8;
            case 0x1E58C8u: goto label_1e58c8;
            case 0x1E58E4u: goto label_1e58e4;
            case 0x1E58E8u: goto label_1e58e8;
            case 0x1E5948u: goto label_1e5948;
            case 0x1E595Cu: goto label_1e595c;
            case 0x1E599Cu: goto label_1e599c;
            case 0x1E59ACu: goto label_1e59ac;
            case 0x1E59D0u: goto label_1e59d0;
            case 0x1E59F0u: goto label_1e59f0;
            case 0x1E5A0Cu: goto label_1e5a0c;
            case 0x1E5A10u: goto label_1e5a10;
            case 0x1E5A80u: goto label_1e5a80;
            case 0x1E5A94u: goto label_1e5a94;
            case 0x1E5AD4u: goto label_1e5ad4;
            case 0x1E5AE4u: goto label_1e5ae4;
            case 0x1E5B08u: goto label_1e5b08;
            case 0x1E5B1Cu: goto label_1e5b1c;
            case 0x1E5B40u: goto label_1e5b40;
            case 0x1E5B54u: goto label_1e5b54;
            case 0x1E5B68u: goto label_1e5b68;
            case 0x1E5B98u: goto label_1e5b98;
            case 0x1E5BB4u: goto label_1e5bb4;
            case 0x1E5BB8u: goto label_1e5bb8;
            case 0x1E5C2Cu: goto label_1e5c2c;
            case 0x1E5C40u: goto label_1e5c40;
            case 0x1E5C80u: goto label_1e5c80;
            case 0x1E5C90u: goto label_1e5c90;
            case 0x1E5CB4u: goto label_1e5cb4;
            case 0x1E5CC8u: goto label_1e5cc8;
            case 0x1E5CECu: goto label_1e5cec;
            case 0x1E5D00u: goto label_1e5d00;
            case 0x1E5D14u: goto label_1e5d14;
            case 0x1E5D48u: goto label_1e5d48;
            case 0x1E5D64u: goto label_1e5d64;
            case 0x1E5D78u: goto label_1e5d78;
            case 0x1E5D94u: goto label_1e5d94;
            case 0x1E5E04u: goto label_1e5e04;
            case 0x1E5E18u: goto label_1e5e18;
            case 0x1E5E58u: goto label_1e5e58;
            case 0x1E5E68u: goto label_1e5e68;
            case 0x1E5E8Cu: goto label_1e5e8c;
            case 0x1E5E9Cu: goto label_1e5e9c;
            case 0x1E5EB4u: goto label_1e5eb4;
            case 0x1E5F6Cu: goto label_1e5f6c;
            case 0x1E5F88u: goto label_1e5f88;
            case 0x1E5F9Cu: goto label_1e5f9c;
            case 0x1E5FA0u: goto label_1e5fa0;
            case 0x1E6008u: goto label_1e6008;
            case 0x1E601Cu: goto label_1e601c;
            case 0x1E605Cu: goto label_1e605c;
            case 0x1E6068u: goto label_1e6068;
            case 0x1E6084u: goto label_1e6084;
            case 0x1E6094u: goto label_1e6094;
            case 0x1E60B8u: goto label_1e60b8;
            case 0x1E60CCu: goto label_1e60cc;
            case 0x1E60F0u: goto label_1e60f0;
            case 0x1E6104u: goto label_1e6104;
            case 0x1E6118u: goto label_1e6118;
            case 0x1E613Cu: goto label_1e613c;
            case 0x1E6158u: goto label_1e6158;
            case 0x1E616Cu: goto label_1e616c;
            case 0x1E6170u: goto label_1e6170;
            case 0x1E61D4u: goto label_1e61d4;
            case 0x1E61E8u: goto label_1e61e8;
            case 0x1E6228u: goto label_1e6228;
            case 0x1E623Cu: goto label_1e623c;
            case 0x1E6240u: goto label_1e6240;
            case 0x1E62A4u: goto label_1e62a4;
            case 0x1E62B8u: goto label_1e62b8;
            case 0x1E62F8u: goto label_1e62f8;
            case 0x1E630Cu: goto label_1e630c;
            case 0x1E6310u: goto label_1e6310;
            case 0x1E6374u: goto label_1e6374;
            case 0x1E6388u: goto label_1e6388;
            case 0x1E63C8u: goto label_1e63c8;
            case 0x1E63DCu: goto label_1e63dc;
            case 0x1E63E0u: goto label_1e63e0;
            case 0x1E6448u: goto label_1e6448;
            case 0x1E645Cu: goto label_1e645c;
            case 0x1E649Cu: goto label_1e649c;
            case 0x1E64B4u: goto label_1e64b4;
            case 0x1E64C4u: goto label_1e64c4;
            case 0x1E64E8u: goto label_1e64e8;
            case 0x1E64FCu: goto label_1e64fc;
            case 0x1E6520u: goto label_1e6520;
            case 0x1E6534u: goto label_1e6534;
            case 0x1E6548u: goto label_1e6548;
            case 0x1E656Cu: goto label_1e656c;
            case 0x1E6588u: goto label_1e6588;
            case 0x1E658Cu: goto label_1e658c;
            case 0x1E65F8u: goto label_1e65f8;
            case 0x1E660Cu: goto label_1e660c;
            case 0x1E664Cu: goto label_1e664c;
            case 0x1E6664u: goto label_1e6664;
            case 0x1E6674u: goto label_1e6674;
            case 0x1E6698u: goto label_1e6698;
            case 0x1E66ACu: goto label_1e66ac;
            case 0x1E66D0u: goto label_1e66d0;
            case 0x1E66E4u: goto label_1e66e4;
            case 0x1E66FCu: goto label_1e66fc;
            case 0x1E6718u: goto label_1e6718;
            case 0x1E6744u: goto label_1e6744;
            case 0x1E6760u: goto label_1e6760;
            case 0x1E6764u: goto label_1e6764;
            case 0x1E67D0u: goto label_1e67d0;
            case 0x1E67E4u: goto label_1e67e4;
            case 0x1E6824u: goto label_1e6824;
            case 0x1E6834u: goto label_1e6834;
            case 0x1E6858u: goto label_1e6858;
            case 0x1E6868u: goto label_1e6868;
            case 0x1E688Cu: goto label_1e688c;
            case 0x1E68A0u: goto label_1e68a0;
            case 0x1E68ACu: goto label_1e68ac;
            case 0x1E68BCu: goto label_1e68bc;
            case 0x1E68D4u: goto label_1e68d4;
            case 0x1E6904u: goto label_1e6904;
            case 0x1E6970u: goto label_1e6970;
            case 0x1E6988u: goto label_1e6988;
            case 0x1E699Cu: goto label_1e699c;
            case 0x1E69B0u: goto label_1e69b0;
            case 0x1E69BCu: goto label_1e69bc;
            case 0x1E69D0u: goto label_1e69d0;
            case 0x1E69F4u: goto label_1e69f4;
            case 0x1E6A08u: goto label_1e6a08;
            case 0x1E6A30u: goto label_1e6a30;
            case 0x1E6A4Cu: goto label_1e6a4c;
            case 0x1E6AC8u: goto label_1e6ac8;
            case 0x1E6AE0u: goto label_1e6ae0;
            case 0x1E6AF4u: goto label_1e6af4;
            case 0x1E6B24u: goto label_1e6b24;
            case 0x1E6B38u: goto label_1e6b38;
            case 0x1E6B6Cu: goto label_1e6b6c;
            case 0x1E6B88u: goto label_1e6b88;
            case 0x1E6BCCu: goto label_1e6bcc;
            case 0x1E6BE8u: goto label_1e6be8;
            case 0x1E6BFCu: goto label_1e6bfc;
            case 0x1E6C30u: goto label_1e6c30;
            case 0x1E6C4Cu: goto label_1e6c4c;
            case 0x1E6C58u: goto label_1e6c58;
            case 0x1E6C6Cu: goto label_1e6c6c;
            case 0x1E6C84u: goto label_1e6c84;
            case 0x1E6CB4u: goto label_1e6cb4;
            case 0x1E6CD8u: goto label_1e6cd8;
            case 0x1E6CECu: goto label_1e6cec;
            case 0x1E6CF0u: goto label_1e6cf0;
            case 0x1E6D5Cu: goto label_1e6d5c;
            case 0x1E6D70u: goto label_1e6d70;
            case 0x1E6DB0u: goto label_1e6db0;
            case 0x1E6DC0u: goto label_1e6dc0;
            case 0x1E6DE4u: goto label_1e6de4;
            case 0x1E6DF4u: goto label_1e6df4;
            case 0x1E6E18u: goto label_1e6e18;
            case 0x1E6E2Cu: goto label_1e6e2c;
            case 0x1E6E38u: goto label_1e6e38;
            case 0x1E6E48u: goto label_1e6e48;
            case 0x1E6E60u: goto label_1e6e60;
            case 0x1E6E90u: goto label_1e6e90;
            case 0x1E6EFCu: goto label_1e6efc;
            case 0x1E6F14u: goto label_1e6f14;
            case 0x1E6F28u: goto label_1e6f28;
            case 0x1E6F3Cu: goto label_1e6f3c;
            case 0x1E6F48u: goto label_1e6f48;
            case 0x1E6F5Cu: goto label_1e6f5c;
            case 0x1E6F80u: goto label_1e6f80;
            case 0x1E6F94u: goto label_1e6f94;
            case 0x1E6FBCu: goto label_1e6fbc;
            case 0x1E6FD8u: goto label_1e6fd8;
            case 0x1E7054u: goto label_1e7054;
            case 0x1E706Cu: goto label_1e706c;
            case 0x1E7080u: goto label_1e7080;
            case 0x1E70B0u: goto label_1e70b0;
            case 0x1E70C4u: goto label_1e70c4;
            case 0x1E70F8u: goto label_1e70f8;
            case 0x1E7114u: goto label_1e7114;
            case 0x1E7158u: goto label_1e7158;
            case 0x1E7174u: goto label_1e7174;
            case 0x1E7188u: goto label_1e7188;
            case 0x1E71BCu: goto label_1e71bc;
            case 0x1E71D8u: goto label_1e71d8;
            case 0x1E71E4u: goto label_1e71e4;
            case 0x1E71F8u: goto label_1e71f8;
            case 0x1E7210u: goto label_1e7210;
            case 0x1E7240u: goto label_1e7240;
            case 0x1E7264u: goto label_1e7264;
            case 0x1E7278u: goto label_1e7278;
            case 0x1E727Cu: goto label_1e727c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E6D08u;
    // 0x1e6d08: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1e6d08u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1e6d0c: 0xffbe0040  sd          $fp, 0x40($sp)
    ctx->pc = 0x1e6d0cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 30));
    // 0x1e6d10: 0xffbf0048  sd          $ra, 0x48($sp)
    ctx->pc = 0x1e6d10u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 31));
    // 0x1e6d14: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e6d14u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e6d18: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e6d18u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e6d1c: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e6d1cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e6d20: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e6d20u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e6d24: 0xafc7000c  sw          $a3, 0xC($fp)
    ctx->pc = 0x1e6d24u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 7));
    // 0x1e6d28: 0xafc00014  sw          $zero, 0x14($fp)
    ctx->pc = 0x1e6d28u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 0));
    // 0x1e6d2c: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e6d2cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e6d30: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e6d30u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e6d34: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E6D34u;
    {
        const bool branch_taken_0x1e6d34 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e6d34) {
            ctx->pc = 0x1E6D5Cu;
            goto label_1e6d5c;
        }
    }
    ctx->pc = 0x1E6D3Cu;
    // 0x1e6d3c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e6d3cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e6d40: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e6d40u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e6d44: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e6d44u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e6d48: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e6d48u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e6d4c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e6d4cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e6d50: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e6d50u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e6d54: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E6D54u;
    {
        const bool branch_taken_0x1e6d54 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e6d54) {
            ctx->pc = 0x1E6D70u;
            goto label_1e6d70;
        }
    }
    ctx->pc = 0x1E6D5Cu;
label_1e6d5c:
    // 0x1e6d5c: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e6d5cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e6d60: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e6d60u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e6d64: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e6d64u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e6d68: 0x10000144  b           . + 4 + (0x144 << 2)
    ctx->pc = 0x1E6D68u;
    {
        const bool branch_taken_0x1e6d68 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6d68) {
            ctx->pc = 0x1E727Cu;
            goto label_1e727c;
        }
    }
    ctx->pc = 0x1E6D70u;
label_1e6d70:
    // 0x1e6d70: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e6d70u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e6d74: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e6d74u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e6d78: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e6d78u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e6d7c: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e6d7cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e6d80: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e6d80u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e6d84: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e6d84u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e6d88: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1e6d88u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1e6d8c: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e6d8cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e6d90: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e6d90u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e6d94: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E6D94u;
    {
        const bool branch_taken_0x1e6d94 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6d94) {
            ctx->pc = 0x1E6DB0u;
            goto label_1e6db0;
        }
    }
    ctx->pc = 0x1E6D9Cu;
    // 0x1e6d9c: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e6d9cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e6da0: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e6da0u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e6da4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e6da4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e6da8: 0x10000134  b           . + 4 + (0x134 << 2)
    ctx->pc = 0x1E6DA8u;
    {
        const bool branch_taken_0x1e6da8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6da8) {
            ctx->pc = 0x1E727Cu;
            goto label_1e727c;
        }
    }
    ctx->pc = 0x1E6DB0u;
label_1e6db0:
    // 0x1e6db0: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e6db0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e6db4: 0x240502a8  addiu       $a1, $zero, 0x2A8
    ctx->pc = 0x1e6db4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 680));
    // 0x1e6db8: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E6DB8u;
    SET_GPR_U32(ctx, 31, 0x1E6DC0u);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6DC0u; }
        if (ctx->pc != 0x1E6DC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6DC0u; }
        if (ctx->pc != 0x1E6DC0u) { return; }
    }
    ctx->pc = 0x1E6DC0u;
label_1e6dc0:
    // 0x1e6dc0: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1e6dc0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1e6dc4: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e6dc4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e6dc8: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E6DC8u;
    {
        const bool branch_taken_0x1e6dc8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e6dc8) {
            ctx->pc = 0x1E6DE4u;
            goto label_1e6de4;
        }
    }
    ctx->pc = 0x1E6DD0u;
    // 0x1e6dd0: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e6dd0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e6dd4: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e6dd4u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e6dd8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e6dd8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e6ddc: 0x10000127  b           . + 4 + (0x127 << 2)
    ctx->pc = 0x1E6DDCu;
    {
        const bool branch_taken_0x1e6ddc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6ddc) {
            ctx->pc = 0x1E727Cu;
            goto label_1e727c;
        }
    }
    ctx->pc = 0x1E6DE4u;
label_1e6de4:
    // 0x1e6de4: 0x8fc40010  lw          $a0, 0x10($fp)
    ctx->pc = 0x1e6de4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e6de8: 0x24050008  addiu       $a1, $zero, 0x8
    ctx->pc = 0x1e6de8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1e6dec: 0xc07cc3c  jal         func_1F30F0
    ctx->pc = 0x1E6DECu;
    SET_GPR_U32(ctx, 31, 0x1E6DF4u);
    ctx->pc = 0x1F30F0u;
    if (runtime->hasFunction(0x1F30F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F30F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6DF4u; }
        if (ctx->pc != 0x1E6DF4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F30F0_0x1f30f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6DF4u; }
        if (ctx->pc != 0x1E6DF4u) { return; }
    }
    ctx->pc = 0x1E6DF4u;
label_1e6df4:
    // 0x1e6df4: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1e6df4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1e6df8: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1e6df8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e6dfc: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1E6DFCu;
    {
        const bool branch_taken_0x1e6dfc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e6dfc) {
            ctx->pc = 0x1E6E2Cu;
            goto label_1e6e2c;
        }
    }
    ctx->pc = 0x1E6E04u;
    // 0x1e6e04: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e6e04u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e6e08: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1e6e08u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1e6e0c: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e6e0cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e6e10: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1E6E10u;
    SET_GPR_U32(ctx, 31, 0x1E6E18u);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6E18u; }
        if (ctx->pc != 0x1E6E18u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6E18u; }
        if (ctx->pc != 0x1E6E18u) { return; }
    }
    ctx->pc = 0x1E6E18u;
label_1e6e18:
    // 0x1e6e18: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e6e18u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e6e1c: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e6e1cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e6e20: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e6e20u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e6e24: 0x10000115  b           . + 4 + (0x115 << 2)
    ctx->pc = 0x1E6E24u;
    {
        const bool branch_taken_0x1e6e24 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6e24) {
            ctx->pc = 0x1E727Cu;
            goto label_1e727c;
        }
    }
    ctx->pc = 0x1E6E2Cu;
label_1e6e2c:
    // 0x1e6e2c: 0x8fc40008  lw          $a0, 0x8($fp)
    ctx->pc = 0x1e6e2cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e6e30: 0xc07a04d  jal         func_1E8134
    ctx->pc = 0x1E6E30u;
    SET_GPR_U32(ctx, 31, 0x1E6E38u);
    ctx->pc = 0x1E8134u;
    if (runtime->hasFunction(0x1E8134u)) {
        auto targetFn = runtime->lookupFunction(0x1E8134u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6E38u; }
        if (ctx->pc != 0x1E6E38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E8134_0x1e8134(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6E38u; }
        if (ctx->pc != 0x1E6E38u) { return; }
    }
    ctx->pc = 0x1E6E38u;
label_1e6e38:
    // 0x1e6e38: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e6e38u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e6e3c: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1e6e3cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e6e40: 0xac430000  sw          $v1, 0x0($v0)
    ctx->pc = 0x1e6e40u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x1e6e44: 0xafc00030  sw          $zero, 0x30($fp)
    ctx->pc = 0x1e6e44u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 0));
label_1e6e48:
    // 0x1e6e48: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1e6e48u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1e6e4c: 0x28420020  slti        $v0, $v0, 0x20
    ctx->pc = 0x1e6e4cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x1e6e50: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1E6E50u;
    {
        const bool branch_taken_0x1e6e50 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e6e50) {
            ctx->pc = 0x1E6E60u;
            goto label_1e6e60;
        }
    }
    ctx->pc = 0x1E6E58u;
    // 0x1e6e58: 0x100000e7  b           . + 4 + (0xE7 << 2)
    ctx->pc = 0x1E6E58u;
    {
        const bool branch_taken_0x1e6e58 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6e58) {
            ctx->pc = 0x1E71F8u;
            goto label_1e71f8;
        }
    }
    ctx->pc = 0x1E6E60u;
label_1e6e60:
    // 0x1e6e60: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1e6e60u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1e6e64: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1e6e64u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e6e68: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x1e6e68u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1e6e6c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e6e6cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e6e70: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e6e70u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e6e74: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e6e74u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e6e78: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e6e78u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e6e7c: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e6e7cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e6e80: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1E6E80u;
    {
        const bool branch_taken_0x1e6e80 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e6e80) {
            ctx->pc = 0x1E6E90u;
            goto label_1e6e90;
        }
    }
    ctx->pc = 0x1E6E88u;
    // 0x1e6e88: 0x100000db  b           . + 4 + (0xDB << 2)
    ctx->pc = 0x1E6E88u;
    {
        const bool branch_taken_0x1e6e88 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6e88) {
            ctx->pc = 0x1E71F8u;
            goto label_1e71f8;
        }
    }
    ctx->pc = 0x1E6E90u;
label_1e6e90:
    // 0x1e6e90: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1e6e90u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1e6e94: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1e6e94u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e6e98: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x1e6e98u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1e6e9c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e6e9cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e6ea0: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e6ea0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e6ea4: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e6ea4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e6ea8: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e6ea8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e6eac: 0x8c420004  lw          $v0, 0x4($v0)
    ctx->pc = 0x1e6eacu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1e6eb0: 0x21142  srl         $v0, $v0, 5
    ctx->pc = 0x1e6eb0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 5));
    // 0x1e6eb4: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1e6eb4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1e6eb8: 0x24020005  addiu       $v0, $zero, 0x5
    ctx->pc = 0x1e6eb8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1e6ebc: 0xafc20034  sw          $v0, 0x34($fp)
    ctx->pc = 0x1e6ebcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 2));
    // 0x1e6ec0: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1e6ec0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1e6ec4: 0xafc20038  sw          $v0, 0x38($fp)
    ctx->pc = 0x1e6ec4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 2));
    // 0x1e6ec8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e6ec8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e6ecc: 0x8fc30038  lw          $v1, 0x38($fp)
    ctx->pc = 0x1e6eccu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1e6ed0: 0x10620015  beq         $v1, $v0, . + 4 + (0x15 << 2)
    ctx->pc = 0x1E6ED0u;
    {
        const bool branch_taken_0x1e6ed0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1e6ed0) {
            ctx->pc = 0x1E6F28u;
            goto label_1e6f28;
        }
    }
    ctx->pc = 0x1E6ED8u;
    // 0x1e6ed8: 0x8fc30038  lw          $v1, 0x38($fp)
    ctx->pc = 0x1e6ed8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1e6edc: 0x28620002  slti        $v0, $v1, 0x2
    ctx->pc = 0x1e6edcu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x1e6ee0: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E6EE0u;
    {
        const bool branch_taken_0x1e6ee0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6ee0) {
            ctx->pc = 0x1E6EFCu;
            goto label_1e6efc;
        }
    }
    ctx->pc = 0x1E6EE8u;
    // 0x1e6ee8: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1e6ee8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1e6eec: 0x10400013  beqz        $v0, . + 4 + (0x13 << 2)
    ctx->pc = 0x1E6EECu;
    {
        const bool branch_taken_0x1e6eec = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6eec) {
            ctx->pc = 0x1E6F3Cu;
            goto label_1e6f3c;
        }
    }
    ctx->pc = 0x1E6EF4u;
    // 0x1e6ef4: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x1E6EF4u;
    {
        const bool branch_taken_0x1e6ef4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6ef4) {
            ctx->pc = 0x1E6F3Cu;
            goto label_1e6f3c;
        }
    }
    ctx->pc = 0x1E6EFCu;
label_1e6efc:
    // 0x1e6efc: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1e6efcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1e6f00: 0x8fc30038  lw          $v1, 0x38($fp)
    ctx->pc = 0x1e6f00u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1e6f04: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1E6F04u;
    {
        const bool branch_taken_0x1e6f04 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1e6f04) {
            ctx->pc = 0x1E6F14u;
            goto label_1e6f14;
        }
    }
    ctx->pc = 0x1E6F0Cu;
    // 0x1e6f0c: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x1E6F0Cu;
    {
        const bool branch_taken_0x1e6f0c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6f0c) {
            ctx->pc = 0x1E6F3Cu;
            goto label_1e6f3c;
        }
    }
    ctx->pc = 0x1E6F14u;
label_1e6f14:
    // 0x1e6f14: 0x8fc20034  lw          $v0, 0x34($fp)
    ctx->pc = 0x1e6f14u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1e6f18: 0x24420010  addiu       $v0, $v0, 0x10
    ctx->pc = 0x1e6f18u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 16));
    // 0x1e6f1c: 0xafc20034  sw          $v0, 0x34($fp)
    ctx->pc = 0x1e6f1cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 2));
    // 0x1e6f20: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1E6F20u;
    {
        const bool branch_taken_0x1e6f20 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6f20) {
            ctx->pc = 0x1E6F48u;
            goto label_1e6f48;
        }
    }
    ctx->pc = 0x1E6F28u;
label_1e6f28:
    // 0x1e6f28: 0x8fc20034  lw          $v0, 0x34($fp)
    ctx->pc = 0x1e6f28u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1e6f2c: 0x24420008  addiu       $v0, $v0, 0x8
    ctx->pc = 0x1e6f2cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x1e6f30: 0xafc20034  sw          $v0, 0x34($fp)
    ctx->pc = 0x1e6f30u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 2));
    // 0x1e6f34: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1E6F34u;
    {
        const bool branch_taken_0x1e6f34 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6f34) {
            ctx->pc = 0x1E6F48u;
            goto label_1e6f48;
        }
    }
    ctx->pc = 0x1E6F3Cu;
label_1e6f3c:
    // 0x1e6f3c: 0x8fc20034  lw          $v0, 0x34($fp)
    ctx->pc = 0x1e6f3cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1e6f40: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1e6f40u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1e6f44: 0xafc20034  sw          $v0, 0x34($fp)
    ctx->pc = 0x1e6f44u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 2));
label_1e6f48:
    // 0x1e6f48: 0x97c20034  lhu         $v0, 0x34($fp)
    ctx->pc = 0x1e6f48u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1e6f4c: 0x8fc40010  lw          $a0, 0x10($fp)
    ctx->pc = 0x1e6f4cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e6f50: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1e6f50u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e6f54: 0xc07cc3c  jal         func_1F30F0
    ctx->pc = 0x1E6F54u;
    SET_GPR_U32(ctx, 31, 0x1E6F5Cu);
    ctx->pc = 0x1F30F0u;
    if (runtime->hasFunction(0x1F30F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F30F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6F5Cu; }
        if (ctx->pc != 0x1E6F5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F30F0_0x1f30f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6F5Cu; }
        if (ctx->pc != 0x1E6F5Cu) { return; }
    }
    ctx->pc = 0x1E6F5Cu;
label_1e6f5c:
    // 0x1e6f5c: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1e6f5cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1e6f60: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e6f60u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e6f64: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1E6F64u;
    {
        const bool branch_taken_0x1e6f64 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e6f64) {
            ctx->pc = 0x1E6F94u;
            goto label_1e6f94;
        }
    }
    ctx->pc = 0x1E6F6Cu;
    // 0x1e6f6c: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e6f6cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e6f70: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1e6f70u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1e6f74: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e6f74u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e6f78: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1E6F78u;
    SET_GPR_U32(ctx, 31, 0x1E6F80u);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6F80u; }
        if (ctx->pc != 0x1E6F80u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6F80u; }
        if (ctx->pc != 0x1E6F80u) { return; }
    }
    ctx->pc = 0x1E6F80u;
label_1e6f80:
    // 0x1e6f80: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e6f80u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e6f84: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e6f84u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e6f88: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e6f88u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e6f8c: 0x100000bb  b           . + 4 + (0xBB << 2)
    ctx->pc = 0x1E6F8Cu;
    {
        const bool branch_taken_0x1e6f8c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6f8c) {
            ctx->pc = 0x1E727Cu;
            goto label_1e727c;
        }
    }
    ctx->pc = 0x1E6F94u;
label_1e6f94:
    // 0x1e6f94: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1e6f94u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1e6f98: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1e6f98u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e6f9c: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x1e6f9cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1e6fa0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e6fa0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e6fa4: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e6fa4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e6fa8: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e6fa8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e6fac: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e6facu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e6fb0: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x1e6fb0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e6fb4: 0xc07a04d  jal         func_1E8134
    ctx->pc = 0x1E6FB4u;
    SET_GPR_U32(ctx, 31, 0x1E6FBCu);
    ctx->pc = 0x1E8134u;
    if (runtime->hasFunction(0x1E8134u)) {
        auto targetFn = runtime->lookupFunction(0x1E8134u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6FBCu; }
        if (ctx->pc != 0x1E6FBCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E8134_0x1e8134(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6FBCu; }
        if (ctx->pc != 0x1E6FBCu) { return; }
    }
    ctx->pc = 0x1E6FBCu;
label_1e6fbc:
    // 0x1e6fbc: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1e6fbcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1e6fc0: 0x27c20024  addiu       $v0, $fp, 0x24
    ctx->pc = 0x1e6fc0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 36));
    // 0x1e6fc4: 0x8fc40020  lw          $a0, 0x20($fp)
    ctx->pc = 0x1e6fc4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e6fc8: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1e6fc8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e6fcc: 0x24060004  addiu       $a2, $zero, 0x4
    ctx->pc = 0x1e6fccu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1e6fd0: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1E6FD0u;
    SET_GPR_U32(ctx, 31, 0x1E6FD8u);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6FD8u; }
        if (ctx->pc != 0x1E6FD8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6FD8u; }
        if (ctx->pc != 0x1E6FD8u) { return; }
    }
    ctx->pc = 0x1E6FD8u;
label_1e6fd8:
    // 0x1e6fd8: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e6fd8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e6fdc: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1e6fdcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1e6fe0: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1e6fe0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1e6fe4: 0x27c50020  addiu       $a1, $fp, 0x20
    ctx->pc = 0x1e6fe4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 30), 32));
    // 0x1e6fe8: 0x8ca40000  lw          $a0, 0x0($a1)
    ctx->pc = 0x1e6fe8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1e6fec: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1e6fecu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1e6ff0: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1e6ff0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e6ff4: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x1e6ff4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1e6ff8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e6ff8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e6ffc: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e6ffcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e7000: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e7000u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e7004: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e7004u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e7008: 0x90420004  lbu         $v0, 0x4($v0)
    ctx->pc = 0x1e7008u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1e700c: 0xa0820000  sb          $v0, 0x0($a0)
    ctx->pc = 0x1e700cu;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1e7010: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x1e7010u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1e7014: 0xaca40000  sw          $a0, 0x0($a1)
    ctx->pc = 0x1e7014u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 4));
    // 0x1e7018: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1e7018u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1e701c: 0xafc2003c  sw          $v0, 0x3C($fp)
    ctx->pc = 0x1e701cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 2));
    // 0x1e7020: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e7020u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e7024: 0x8fc3003c  lw          $v1, 0x3C($fp)
    ctx->pc = 0x1e7024u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1e7028: 0x10620026  beq         $v1, $v0, . + 4 + (0x26 << 2)
    ctx->pc = 0x1E7028u;
    {
        const bool branch_taken_0x1e7028 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1e7028) {
            ctx->pc = 0x1E70C4u;
            goto label_1e70c4;
        }
    }
    ctx->pc = 0x1E7030u;
    // 0x1e7030: 0x8fc3003c  lw          $v1, 0x3C($fp)
    ctx->pc = 0x1e7030u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1e7034: 0x28620002  slti        $v0, $v1, 0x2
    ctx->pc = 0x1e7034u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x1e7038: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E7038u;
    {
        const bool branch_taken_0x1e7038 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e7038) {
            ctx->pc = 0x1E7054u;
            goto label_1e7054;
        }
    }
    ctx->pc = 0x1E7040u;
    // 0x1e7040: 0x8fc2003c  lw          $v0, 0x3C($fp)
    ctx->pc = 0x1e7040u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1e7044: 0x10400050  beqz        $v0, . + 4 + (0x50 << 2)
    ctx->pc = 0x1E7044u;
    {
        const bool branch_taken_0x1e7044 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e7044) {
            ctx->pc = 0x1E7188u;
            goto label_1e7188;
        }
    }
    ctx->pc = 0x1E704Cu;
    // 0x1e704c: 0x1000004e  b           . + 4 + (0x4E << 2)
    ctx->pc = 0x1E704Cu;
    {
        const bool branch_taken_0x1e704c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e704c) {
            ctx->pc = 0x1E7188u;
            goto label_1e7188;
        }
    }
    ctx->pc = 0x1E7054u;
label_1e7054:
    // 0x1e7054: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1e7054u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1e7058: 0x8fc3003c  lw          $v1, 0x3C($fp)
    ctx->pc = 0x1e7058u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1e705c: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1E705Cu;
    {
        const bool branch_taken_0x1e705c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1e705c) {
            ctx->pc = 0x1E706Cu;
            goto label_1e706c;
        }
    }
    ctx->pc = 0x1E7064u;
    // 0x1e7064: 0x10000048  b           . + 4 + (0x48 << 2)
    ctx->pc = 0x1E7064u;
    {
        const bool branch_taken_0x1e7064 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e7064) {
            ctx->pc = 0x1E7188u;
            goto label_1e7188;
        }
    }
    ctx->pc = 0x1E706Cu;
label_1e706c:
    // 0x1e706c: 0x8fc40020  lw          $a0, 0x20($fp)
    ctx->pc = 0x1e706cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e7070: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1e7070u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e7074: 0x24060010  addiu       $a2, $zero, 0x10
    ctx->pc = 0x1e7074u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1e7078: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1E7078u;
    SET_GPR_U32(ctx, 31, 0x1E7080u);
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7080u; }
        if (ctx->pc != 0x1E7080u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7080u; }
        if (ctx->pc != 0x1E7080u) { return; }
    }
    ctx->pc = 0x1E7080u;
label_1e7080:
    // 0x1e7080: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1e7080u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1e7084: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1e7084u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e7088: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x1e7088u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1e708c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e708cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e7090: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e7090u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e7094: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e7094u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e7098: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e7098u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e709c: 0x8fc40020  lw          $a0, 0x20($fp)
    ctx->pc = 0x1e709cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e70a0: 0x8c450008  lw          $a1, 0x8($v0)
    ctx->pc = 0x1e70a0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1e70a4: 0x24060010  addiu       $a2, $zero, 0x10
    ctx->pc = 0x1e70a4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1e70a8: 0xc042d7e  jal         func_10B5F8
    ctx->pc = 0x1E70A8u;
    SET_GPR_U32(ctx, 31, 0x1E70B0u);
    ctx->pc = 0x10B5F8u;
    if (runtime->hasFunction(0x10B5F8u)) {
        auto targetFn = runtime->lookupFunction(0x10B5F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E70B0u; }
        if (ctx->pc != 0x1E70B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B5F8_0x10b5f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E70B0u; }
        if (ctx->pc != 0x1E70B0u) { return; }
    }
    ctx->pc = 0x1E70B0u;
label_1e70b0:
    // 0x1e70b0: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e70b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e70b4: 0x24420010  addiu       $v0, $v0, 0x10
    ctx->pc = 0x1e70b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 16));
    // 0x1e70b8: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1e70b8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1e70bc: 0x10000049  b           . + 4 + (0x49 << 2)
    ctx->pc = 0x1E70BCu;
    {
        const bool branch_taken_0x1e70bc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e70bc) {
            ctx->pc = 0x1E71E4u;
            goto label_1e71e4;
        }
    }
    ctx->pc = 0x1E70C4u;
label_1e70c4:
    // 0x1e70c4: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1e70c4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1e70c8: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1e70c8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e70cc: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x1e70ccu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1e70d0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e70d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e70d4: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e70d4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e70d8: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e70d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e70dc: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e70dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e70e0: 0x8c420008  lw          $v0, 0x8($v0)
    ctx->pc = 0x1e70e0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1e70e4: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e70e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e70e8: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1e70e8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1e70ec: 0x8fc40028  lw          $a0, 0x28($fp)
    ctx->pc = 0x1e70ecu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1e70f0: 0xc07a04d  jal         func_1E8134
    ctx->pc = 0x1E70F0u;
    SET_GPR_U32(ctx, 31, 0x1E70F8u);
    ctx->pc = 0x1E8134u;
    if (runtime->hasFunction(0x1E8134u)) {
        auto targetFn = runtime->lookupFunction(0x1E8134u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E70F8u; }
        if (ctx->pc != 0x1E70F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E8134_0x1e8134(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E70F8u; }
        if (ctx->pc != 0x1E70F8u) { return; }
    }
    ctx->pc = 0x1E70F8u;
label_1e70f8:
    // 0x1e70f8: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1e70f8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1e70fc: 0x27c20028  addiu       $v0, $fp, 0x28
    ctx->pc = 0x1e70fcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0x1e7100: 0x8fc40020  lw          $a0, 0x20($fp)
    ctx->pc = 0x1e7100u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e7104: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1e7104u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e7108: 0x24060004  addiu       $a2, $zero, 0x4
    ctx->pc = 0x1e7108u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1e710c: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1E710Cu;
    SET_GPR_U32(ctx, 31, 0x1E7114u);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7114u; }
        if (ctx->pc != 0x1E7114u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7114u; }
        if (ctx->pc != 0x1E7114u) { return; }
    }
    ctx->pc = 0x1E7114u;
label_1e7114:
    // 0x1e7114: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e7114u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e7118: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1e7118u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1e711c: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1e711cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1e7120: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1e7120u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1e7124: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1e7124u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e7128: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x1e7128u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1e712c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e712cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e7130: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e7130u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e7134: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e7134u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e7138: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e7138u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e713c: 0x8c420008  lw          $v0, 0x8($v0)
    ctx->pc = 0x1e713cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1e7140: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1e7140u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1e7144: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e7144u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e7148: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1e7148u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1e714c: 0x8fc40028  lw          $a0, 0x28($fp)
    ctx->pc = 0x1e714cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1e7150: 0xc07a04d  jal         func_1E8134
    ctx->pc = 0x1E7150u;
    SET_GPR_U32(ctx, 31, 0x1E7158u);
    ctx->pc = 0x1E8134u;
    if (runtime->hasFunction(0x1E8134u)) {
        auto targetFn = runtime->lookupFunction(0x1E8134u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7158u; }
        if (ctx->pc != 0x1E7158u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E8134_0x1e8134(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7158u; }
        if (ctx->pc != 0x1E7158u) { return; }
    }
    ctx->pc = 0x1E7158u;
label_1e7158:
    // 0x1e7158: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1e7158u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1e715c: 0x27c20028  addiu       $v0, $fp, 0x28
    ctx->pc = 0x1e715cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0x1e7160: 0x8fc40020  lw          $a0, 0x20($fp)
    ctx->pc = 0x1e7160u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e7164: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1e7164u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e7168: 0x24060004  addiu       $a2, $zero, 0x4
    ctx->pc = 0x1e7168u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1e716c: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1E716Cu;
    SET_GPR_U32(ctx, 31, 0x1E7174u);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7174u; }
        if (ctx->pc != 0x1E7174u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7174u; }
        if (ctx->pc != 0x1E7174u) { return; }
    }
    ctx->pc = 0x1E7174u;
label_1e7174:
    // 0x1e7174: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e7174u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e7178: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1e7178u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1e717c: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1e717cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1e7180: 0x10000018  b           . + 4 + (0x18 << 2)
    ctx->pc = 0x1E7180u;
    {
        const bool branch_taken_0x1e7180 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e7180) {
            ctx->pc = 0x1E71E4u;
            goto label_1e71e4;
        }
    }
    ctx->pc = 0x1E7188u;
label_1e7188:
    // 0x1e7188: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1e7188u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1e718c: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1e718cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e7190: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x1e7190u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1e7194: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e7194u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e7198: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e7198u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e719c: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e719cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e71a0: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e71a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e71a4: 0x8c420008  lw          $v0, 0x8($v0)
    ctx->pc = 0x1e71a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1e71a8: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e71a8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e71ac: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1e71acu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1e71b0: 0x8fc40028  lw          $a0, 0x28($fp)
    ctx->pc = 0x1e71b0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1e71b4: 0xc07a04d  jal         func_1E8134
    ctx->pc = 0x1E71B4u;
    SET_GPR_U32(ctx, 31, 0x1E71BCu);
    ctx->pc = 0x1E8134u;
    if (runtime->hasFunction(0x1E8134u)) {
        auto targetFn = runtime->lookupFunction(0x1E8134u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E71BCu; }
        if (ctx->pc != 0x1E71BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E8134_0x1e8134(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E71BCu; }
        if (ctx->pc != 0x1E71BCu) { return; }
    }
    ctx->pc = 0x1E71BCu;
label_1e71bc:
    // 0x1e71bc: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1e71bcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1e71c0: 0x27c20028  addiu       $v0, $fp, 0x28
    ctx->pc = 0x1e71c0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0x1e71c4: 0x8fc40020  lw          $a0, 0x20($fp)
    ctx->pc = 0x1e71c4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e71c8: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1e71c8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e71cc: 0x24060004  addiu       $a2, $zero, 0x4
    ctx->pc = 0x1e71ccu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1e71d0: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1E71D0u;
    SET_GPR_U32(ctx, 31, 0x1E71D8u);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E71D8u; }
        if (ctx->pc != 0x1E71D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E71D8u; }
        if (ctx->pc != 0x1E71D8u) { return; }
    }
    ctx->pc = 0x1E71D8u;
label_1e71d8:
    // 0x1e71d8: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e71d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e71dc: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1e71dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1e71e0: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1e71e0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
label_1e71e4:
    // 0x1e71e4: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1e71e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1e71e8: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1e71e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1e71ec: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1e71ecu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1e71f0: 0x1000ff15  b           . + 4 + (-0xEB << 2)
    ctx->pc = 0x1E71F0u;
    {
        const bool branch_taken_0x1e71f0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e71f0) {
            ctx->pc = 0x1E6E48u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1e6e48;
        }
    }
    ctx->pc = 0x1E71F8u;
label_1e71f8:
    // 0x1e71f8: 0x8fc3001c  lw          $v1, 0x1C($fp)
    ctx->pc = 0x1e71f8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e71fc: 0x93c20030  lbu         $v0, 0x30($fp)
    ctx->pc = 0x1e71fcu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1e7200: 0xa0620004  sb          $v0, 0x4($v1)
    ctx->pc = 0x1e7200u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 4), (uint8_t)GPR_U32(ctx, 2));
    // 0x1e7204: 0x8fc40010  lw          $a0, 0x10($fp)
    ctx->pc = 0x1e7204u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e7208: 0xc07c6b6  jal         func_1F1AD8
    ctx->pc = 0x1E7208u;
    SET_GPR_U32(ctx, 31, 0x1E7210u);
    ctx->pc = 0x1F1AD8u;
    if (runtime->hasFunction(0x1F1AD8u)) {
        auto targetFn = runtime->lookupFunction(0x1F1AD8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7210u; }
        if (ctx->pc != 0x1E7210u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1AD8_0x1f1ad8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7210u; }
        if (ctx->pc != 0x1E7210u) { return; }
    }
    ctx->pc = 0x1E7210u;
label_1e7210:
    // 0x1e7210: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e7210u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e7214: 0x3402fff0  ori         $v0, $zero, 0xFFF0
    ctx->pc = 0x1e7214u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65520);
    // 0x1e7218: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e7218u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e721c: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1e721cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1e7220: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e7220u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e7224: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e7224u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e7228: 0x3406b000  ori         $a2, $zero, 0xB000
    ctx->pc = 0x1e7228u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)45056);
    // 0x1e722c: 0x40382d  daddu       $a3, $v0, $zero
    ctx->pc = 0x1e722cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e7230: 0x24080049  addiu       $t0, $zero, 0x49
    ctx->pc = 0x1e7230u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 73));
    // 0x1e7234: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1e7234u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e7238: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E7238u;
    SET_GPR_U32(ctx, 31, 0x1E7240u);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7240u; }
        if (ctx->pc != 0x1E7240u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7240u; }
        if (ctx->pc != 0x1E7240u) { return; }
    }
    ctx->pc = 0x1E7240u;
label_1e7240:
    // 0x1e7240: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1e7240u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1e7244: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e7244u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e7248: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E7248u;
    {
        const bool branch_taken_0x1e7248 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e7248) {
            ctx->pc = 0x1E7264u;
            goto label_1e7264;
        }
    }
    ctx->pc = 0x1E7250u;
    // 0x1e7250: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e7250u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e7254: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e7254u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e7258: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e7258u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e725c: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1E725Cu;
    {
        const bool branch_taken_0x1e725c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e725c) {
            ctx->pc = 0x1E727Cu;
            goto label_1e727c;
        }
    }
    ctx->pc = 0x1E7264u;
label_1e7264:
    // 0x1e7264: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1e7264u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e7268: 0x24050032  addiu       $a1, $zero, 0x32
    ctx->pc = 0x1e7268u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 50));
    // 0x1e726c: 0x8fc6000c  lw          $a2, 0xC($fp)
    ctx->pc = 0x1e726cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e7270: 0xc076ad5  jal         func_1DAB54
    ctx->pc = 0x1E7270u;
    SET_GPR_U32(ctx, 31, 0x1E7278u);
    ctx->pc = 0x1DAB54u;
    if (runtime->hasFunction(0x1DAB54u)) {
        auto targetFn = runtime->lookupFunction(0x1DAB54u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7278u; }
        if (ctx->pc != 0x1E7278u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DAB54_0x1dab54(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7278u; }
        if (ctx->pc != 0x1E7278u) { return; }
    }
    ctx->pc = 0x1E7278u;
label_1e7278:
    // 0x1e7278: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1e7278u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1e727c:
    // 0x1e727c: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e727cu;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e7280: 0xdfbe0040  ld          $fp, 0x40($sp)
    ctx->pc = 0x1e7280u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1e7284: 0xdfbf0048  ld          $ra, 0x48($sp)
    ctx->pc = 0x1e7284u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x1e7288: 0x27bd0050  addiu       $sp, $sp, 0x50
    ctx->pc = 0x1e7288u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
    // 0x1e728c: 0x3e00008  jr          $ra
    ctx->pc = 0x1E728Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E5060u: goto label_1e5060;
            case 0x1E5074u: goto label_1e5074;
            case 0x1E50B4u: goto label_1e50b4;
            case 0x1E50C4u: goto label_1e50c4;
            case 0x1E50E8u: goto label_1e50e8;
            case 0x1E50FCu: goto label_1e50fc;
            case 0x1E5120u: goto label_1e5120;
            case 0x1E5134u: goto label_1e5134;
            case 0x1E5148u: goto label_1e5148;
            case 0x1E5178u: goto label_1e5178;
            case 0x1E5194u: goto label_1e5194;
            case 0x1E5198u: goto label_1e5198;
            case 0x1E5238u: goto label_1e5238;
            case 0x1E524Cu: goto label_1e524c;
            case 0x1E528Cu: goto label_1e528c;
            case 0x1E52B0u: goto label_1e52b0;
            case 0x1E52D4u: goto label_1e52d4;
            case 0x1E530Cu: goto label_1e530c;
            case 0x1E536Cu: goto label_1e536c;
            case 0x1E5388u: goto label_1e5388;
            case 0x1E5410u: goto label_1e5410;
            case 0x1E5424u: goto label_1e5424;
            case 0x1E5464u: goto label_1e5464;
            case 0x1E5480u: goto label_1e5480;
            case 0x1E5484u: goto label_1e5484;
            case 0x1E54F8u: goto label_1e54f8;
            case 0x1E550Cu: goto label_1e550c;
            case 0x1E554Cu: goto label_1e554c;
            case 0x1E5574u: goto label_1e5574;
            case 0x1E5598u: goto label_1e5598;
            case 0x1E55C8u: goto label_1e55c8;
            case 0x1E55ECu: goto label_1e55ec;
            case 0x1E5600u: goto label_1e5600;
            case 0x1E566Cu: goto label_1e566c;
            case 0x1E568Cu: goto label_1e568c;
            case 0x1E5748u: goto label_1e5748;
            case 0x1E575Cu: goto label_1e575c;
            case 0x1E57A0u: goto label_1e57a0;
            case 0x1E57BCu: goto label_1e57bc;
            case 0x1E57C0u: goto label_1e57c0;
            case 0x1E5820u: goto label_1e5820;
            case 0x1E5834u: goto label_1e5834;
            case 0x1E5874u: goto label_1e5874;
            case 0x1E5884u: goto label_1e5884;
            case 0x1E58A8u: goto label_1e58a8;
            case 0x1E58C8u: goto label_1e58c8;
            case 0x1E58E4u: goto label_1e58e4;
            case 0x1E58E8u: goto label_1e58e8;
            case 0x1E5948u: goto label_1e5948;
            case 0x1E595Cu: goto label_1e595c;
            case 0x1E599Cu: goto label_1e599c;
            case 0x1E59ACu: goto label_1e59ac;
            case 0x1E59D0u: goto label_1e59d0;
            case 0x1E59F0u: goto label_1e59f0;
            case 0x1E5A0Cu: goto label_1e5a0c;
            case 0x1E5A10u: goto label_1e5a10;
            case 0x1E5A80u: goto label_1e5a80;
            case 0x1E5A94u: goto label_1e5a94;
            case 0x1E5AD4u: goto label_1e5ad4;
            case 0x1E5AE4u: goto label_1e5ae4;
            case 0x1E5B08u: goto label_1e5b08;
            case 0x1E5B1Cu: goto label_1e5b1c;
            case 0x1E5B40u: goto label_1e5b40;
            case 0x1E5B54u: goto label_1e5b54;
            case 0x1E5B68u: goto label_1e5b68;
            case 0x1E5B98u: goto label_1e5b98;
            case 0x1E5BB4u: goto label_1e5bb4;
            case 0x1E5BB8u: goto label_1e5bb8;
            case 0x1E5C2Cu: goto label_1e5c2c;
            case 0x1E5C40u: goto label_1e5c40;
            case 0x1E5C80u: goto label_1e5c80;
            case 0x1E5C90u: goto label_1e5c90;
            case 0x1E5CB4u: goto label_1e5cb4;
            case 0x1E5CC8u: goto label_1e5cc8;
            case 0x1E5CECu: goto label_1e5cec;
            case 0x1E5D00u: goto label_1e5d00;
            case 0x1E5D14u: goto label_1e5d14;
            case 0x1E5D48u: goto label_1e5d48;
            case 0x1E5D64u: goto label_1e5d64;
            case 0x1E5D78u: goto label_1e5d78;
            case 0x1E5D94u: goto label_1e5d94;
            case 0x1E5E04u: goto label_1e5e04;
            case 0x1E5E18u: goto label_1e5e18;
            case 0x1E5E58u: goto label_1e5e58;
            case 0x1E5E68u: goto label_1e5e68;
            case 0x1E5E8Cu: goto label_1e5e8c;
            case 0x1E5E9Cu: goto label_1e5e9c;
            case 0x1E5EB4u: goto label_1e5eb4;
            case 0x1E5F6Cu: goto label_1e5f6c;
            case 0x1E5F88u: goto label_1e5f88;
            case 0x1E5F9Cu: goto label_1e5f9c;
            case 0x1E5FA0u: goto label_1e5fa0;
            case 0x1E6008u: goto label_1e6008;
            case 0x1E601Cu: goto label_1e601c;
            case 0x1E605Cu: goto label_1e605c;
            case 0x1E6068u: goto label_1e6068;
            case 0x1E6084u: goto label_1e6084;
            case 0x1E6094u: goto label_1e6094;
            case 0x1E60B8u: goto label_1e60b8;
            case 0x1E60CCu: goto label_1e60cc;
            case 0x1E60F0u: goto label_1e60f0;
            case 0x1E6104u: goto label_1e6104;
            case 0x1E6118u: goto label_1e6118;
            case 0x1E613Cu: goto label_1e613c;
            case 0x1E6158u: goto label_1e6158;
            case 0x1E616Cu: goto label_1e616c;
            case 0x1E6170u: goto label_1e6170;
            case 0x1E61D4u: goto label_1e61d4;
            case 0x1E61E8u: goto label_1e61e8;
            case 0x1E6228u: goto label_1e6228;
            case 0x1E623Cu: goto label_1e623c;
            case 0x1E6240u: goto label_1e6240;
            case 0x1E62A4u: goto label_1e62a4;
            case 0x1E62B8u: goto label_1e62b8;
            case 0x1E62F8u: goto label_1e62f8;
            case 0x1E630Cu: goto label_1e630c;
            case 0x1E6310u: goto label_1e6310;
            case 0x1E6374u: goto label_1e6374;
            case 0x1E6388u: goto label_1e6388;
            case 0x1E63C8u: goto label_1e63c8;
            case 0x1E63DCu: goto label_1e63dc;
            case 0x1E63E0u: goto label_1e63e0;
            case 0x1E6448u: goto label_1e6448;
            case 0x1E645Cu: goto label_1e645c;
            case 0x1E649Cu: goto label_1e649c;
            case 0x1E64B4u: goto label_1e64b4;
            case 0x1E64C4u: goto label_1e64c4;
            case 0x1E64E8u: goto label_1e64e8;
            case 0x1E64FCu: goto label_1e64fc;
            case 0x1E6520u: goto label_1e6520;
            case 0x1E6534u: goto label_1e6534;
            case 0x1E6548u: goto label_1e6548;
            case 0x1E656Cu: goto label_1e656c;
            case 0x1E6588u: goto label_1e6588;
            case 0x1E658Cu: goto label_1e658c;
            case 0x1E65F8u: goto label_1e65f8;
            case 0x1E660Cu: goto label_1e660c;
            case 0x1E664Cu: goto label_1e664c;
            case 0x1E6664u: goto label_1e6664;
            case 0x1E6674u: goto label_1e6674;
            case 0x1E6698u: goto label_1e6698;
            case 0x1E66ACu: goto label_1e66ac;
            case 0x1E66D0u: goto label_1e66d0;
            case 0x1E66E4u: goto label_1e66e4;
            case 0x1E66FCu: goto label_1e66fc;
            case 0x1E6718u: goto label_1e6718;
            case 0x1E6744u: goto label_1e6744;
            case 0x1E6760u: goto label_1e6760;
            case 0x1E6764u: goto label_1e6764;
            case 0x1E67D0u: goto label_1e67d0;
            case 0x1E67E4u: goto label_1e67e4;
            case 0x1E6824u: goto label_1e6824;
            case 0x1E6834u: goto label_1e6834;
            case 0x1E6858u: goto label_1e6858;
            case 0x1E6868u: goto label_1e6868;
            case 0x1E688Cu: goto label_1e688c;
            case 0x1E68A0u: goto label_1e68a0;
            case 0x1E68ACu: goto label_1e68ac;
            case 0x1E68BCu: goto label_1e68bc;
            case 0x1E68D4u: goto label_1e68d4;
            case 0x1E6904u: goto label_1e6904;
            case 0x1E6970u: goto label_1e6970;
            case 0x1E6988u: goto label_1e6988;
            case 0x1E699Cu: goto label_1e699c;
            case 0x1E69B0u: goto label_1e69b0;
            case 0x1E69BCu: goto label_1e69bc;
            case 0x1E69D0u: goto label_1e69d0;
            case 0x1E69F4u: goto label_1e69f4;
            case 0x1E6A08u: goto label_1e6a08;
            case 0x1E6A30u: goto label_1e6a30;
            case 0x1E6A4Cu: goto label_1e6a4c;
            case 0x1E6AC8u: goto label_1e6ac8;
            case 0x1E6AE0u: goto label_1e6ae0;
            case 0x1E6AF4u: goto label_1e6af4;
            case 0x1E6B24u: goto label_1e6b24;
            case 0x1E6B38u: goto label_1e6b38;
            case 0x1E6B6Cu: goto label_1e6b6c;
            case 0x1E6B88u: goto label_1e6b88;
            case 0x1E6BCCu: goto label_1e6bcc;
            case 0x1E6BE8u: goto label_1e6be8;
            case 0x1E6BFCu: goto label_1e6bfc;
            case 0x1E6C30u: goto label_1e6c30;
            case 0x1E6C4Cu: goto label_1e6c4c;
            case 0x1E6C58u: goto label_1e6c58;
            case 0x1E6C6Cu: goto label_1e6c6c;
            case 0x1E6C84u: goto label_1e6c84;
            case 0x1E6CB4u: goto label_1e6cb4;
            case 0x1E6CD8u: goto label_1e6cd8;
            case 0x1E6CECu: goto label_1e6cec;
            case 0x1E6CF0u: goto label_1e6cf0;
            case 0x1E6D5Cu: goto label_1e6d5c;
            case 0x1E6D70u: goto label_1e6d70;
            case 0x1E6DB0u: goto label_1e6db0;
            case 0x1E6DC0u: goto label_1e6dc0;
            case 0x1E6DE4u: goto label_1e6de4;
            case 0x1E6DF4u: goto label_1e6df4;
            case 0x1E6E18u: goto label_1e6e18;
            case 0x1E6E2Cu: goto label_1e6e2c;
            case 0x1E6E38u: goto label_1e6e38;
            case 0x1E6E48u: goto label_1e6e48;
            case 0x1E6E60u: goto label_1e6e60;
            case 0x1E6E90u: goto label_1e6e90;
            case 0x1E6EFCu: goto label_1e6efc;
            case 0x1E6F14u: goto label_1e6f14;
            case 0x1E6F28u: goto label_1e6f28;
            case 0x1E6F3Cu: goto label_1e6f3c;
            case 0x1E6F48u: goto label_1e6f48;
            case 0x1E6F5Cu: goto label_1e6f5c;
            case 0x1E6F80u: goto label_1e6f80;
            case 0x1E6F94u: goto label_1e6f94;
            case 0x1E6FBCu: goto label_1e6fbc;
            case 0x1E6FD8u: goto label_1e6fd8;
            case 0x1E7054u: goto label_1e7054;
            case 0x1E706Cu: goto label_1e706c;
            case 0x1E7080u: goto label_1e7080;
            case 0x1E70B0u: goto label_1e70b0;
            case 0x1E70C4u: goto label_1e70c4;
            case 0x1E70F8u: goto label_1e70f8;
            case 0x1E7114u: goto label_1e7114;
            case 0x1E7158u: goto label_1e7158;
            case 0x1E7174u: goto label_1e7174;
            case 0x1E7188u: goto label_1e7188;
            case 0x1E71BCu: goto label_1e71bc;
            case 0x1E71D8u: goto label_1e71d8;
            case 0x1E71E4u: goto label_1e71e4;
            case 0x1E71F8u: goto label_1e71f8;
            case 0x1E7210u: goto label_1e7210;
            case 0x1E7240u: goto label_1e7240;
            case 0x1E7264u: goto label_1e7264;
            case 0x1E7278u: goto label_1e7278;
            case 0x1E727Cu: goto label_1e727c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E7294u;
    // 0x1e7294: 0x0  nop
    ctx->pc = 0x1e7294u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
