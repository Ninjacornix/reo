#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B5010
// Address: 0x1b5010 - 0x1b52b0
void sub_001B5010_0x1b5010(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B5010_0x1b5010");
#endif

    switch (ctx->pc) {
        case 0x1b5054u: goto label_1b5054;
        case 0x1b5134u: goto label_1b5134;
        case 0x1b5178u: goto label_1b5178;
        case 0x1b517cu: goto label_1b517c;
        case 0x1b51fcu: goto label_1b51fc;
        case 0x1b5218u: goto label_1b5218;
        case 0x1b5224u: goto label_1b5224;
        case 0x1b5284u: goto label_1b5284;
        default: break;
    }

    ctx->pc = 0x1b5010u;

    // 0x1b5010: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x1b5010u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x1b5014: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x1b5014u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x1b5018: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1b5018u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1b501c: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1b501cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1b5020: 0x80a02d  daddu       $s4, $a0, $zero
    ctx->pc = 0x1b5020u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b5024: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1b5024u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1b5028: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x1b5028u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b502c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1b502cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1b5030: 0xe0902d  daddu       $s2, $a3, $zero
    ctx->pc = 0x1b5030u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b5034: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b5034u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b5038: 0x3c11002c  lui         $s1, 0x2C
    ctx->pc = 0x1b5038u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)44 << 16));
    // 0x1b503c: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x1b503cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b5040: 0x2631aaf0  addiu       $s1, $s1, -0x5510
    ctx->pc = 0x1b5040u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294945520));
    // 0x1b5044: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1b5044u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b5048: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1b5048u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b504c: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1B504Cu;
    SET_GPR_U32(ctx, 31, 0x1B5054u);
    ctx->pc = 0x1B5050u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B504Cu;
            // 0x1b5050: 0x240600a8  addiu       $a2, $zero, 0xA8 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 168));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B5054u; }
        if (ctx->pc != 0x1B5054u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B5054u; }
        if (ctx->pc != 0x1B5054u) { return; }
    }
    ctx->pc = 0x1B5054u;
label_1b5054:
    // 0x1b5054: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1b5054u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1b5058: 0x3c020004  lui         $v0, 0x4
    ctx->pc = 0x1b5058u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4 << 16));
    // 0x1b505c: 0xac34aaf4  sw          $s4, -0x550C($at)
    ctx->pc = 0x1b505cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294945524), GPR_U32(ctx, 20));
    // 0x1b5060: 0x34428170  ori         $v0, $v0, 0x8170
    ctx->pc = 0x1b5060u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)33136);
    // 0x1b5064: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1b5064u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1b5068: 0x2407ffc0  addiu       $a3, $zero, -0x40
    ctx->pc = 0x1b5068u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967232));
    // 0x1b506c: 0xac20aaf0  sw          $zero, -0x5510($at)
    ctx->pc = 0x1b506cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294945520), GPR_U32(ctx, 0));
    // 0x1b5070: 0x182d  daddu       $v1, $zero, $zero
    ctx->pc = 0x1b5070u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b5074: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1b5074u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1b5078: 0xac22ab8c  sw          $v0, -0x5474($at)
    ctx->pc = 0x1b5078u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294945676), GPR_U32(ctx, 2));
    // 0x1b507c: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1b507cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1b5080: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1b5080u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1b5084: 0xac20ab94  sw          $zero, -0x546C($at)
    ctx->pc = 0x1b5084u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294945684), GPR_U32(ctx, 0));
    // 0x1b5088: 0x24424590  addiu       $v0, $v0, 0x4590
    ctx->pc = 0x1b5088u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 17808));
    // 0x1b508c: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1b508cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1b5090: 0xac20ab90  sw          $zero, -0x5470($at)
    ctx->pc = 0x1b5090u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294945680), GPR_U32(ctx, 0));
    // 0x1b5094: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1b5094u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1b5098: 0x8c25aaf4  lw          $a1, -0x550C($at)
    ctx->pc = 0x1b5098u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294945524)));
    // 0x1b509c: 0x52040  sll         $a0, $a1, 1
    ctx->pc = 0x1b509cu;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
    // 0x1b50a0: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1b50a0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1b50a4: 0x852021  addu        $a0, $a0, $a1
    ctx->pc = 0x1b50a4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
    // 0x1b50a8: 0x42080  sll         $a0, $a0, 2
    ctx->pc = 0x1b50a8u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1b50ac: 0x852021  addu        $a0, $a0, $a1
    ctx->pc = 0x1b50acu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
    // 0x1b50b0: 0x42080  sll         $a0, $a0, 2
    ctx->pc = 0x1b50b0u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1b50b4: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x1b50b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1b50b8: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x1b50b8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1b50bc: 0xac24aaf8  sw          $a0, -0x5508($at)
    ctx->pc = 0x1b50bcu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294945528), GPR_U32(ctx, 4));
    // 0x1b50c0: 0x8c440004  lw          $a0, 0x4($v0)
    ctx->pc = 0x1b50c0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1b50c4: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1b50c4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1b50c8: 0xac24aafc  sw          $a0, -0x5504($at)
    ctx->pc = 0x1b50c8u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294945532), GPR_U32(ctx, 4));
    // 0x1b50cc: 0x8c440008  lw          $a0, 0x8($v0)
    ctx->pc = 0x1b50ccu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1b50d0: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1b50d0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1b50d4: 0xac24ab00  sw          $a0, -0x5500($at)
    ctx->pc = 0x1b50d4u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294945536), GPR_U32(ctx, 4));
    // 0x1b50d8: 0x8c44000c  lw          $a0, 0xC($v0)
    ctx->pc = 0x1b50d8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 12)));
    // 0x1b50dc: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1b50dcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1b50e0: 0xac24ab04  sw          $a0, -0x54FC($at)
    ctx->pc = 0x1b50e0u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294945540), GPR_U32(ctx, 4));
    // 0x1b50e4: 0x8c440010  lw          $a0, 0x10($v0)
    ctx->pc = 0x1b50e4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x1b50e8: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1b50e8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1b50ec: 0xac24ab08  sw          $a0, -0x54F8($at)
    ctx->pc = 0x1b50ecu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294945544), GPR_U32(ctx, 4));
    // 0x1b50f0: 0x8c44001c  lw          $a0, 0x1C($v0)
    ctx->pc = 0x1b50f0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 28)));
    // 0x1b50f4: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1b50f4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1b50f8: 0xac24ab0c  sw          $a0, -0x54F4($at)
    ctx->pc = 0x1b50f8u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294945548), GPR_U32(ctx, 4));
    // 0x1b50fc: 0x8c440020  lw          $a0, 0x20($v0)
    ctx->pc = 0x1b50fcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 32)));
    // 0x1b5100: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1b5100u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1b5104: 0xac24ab10  sw          $a0, -0x54F0($at)
    ctx->pc = 0x1b5104u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294945552), GPR_U32(ctx, 4));
    // 0x1b5108: 0x8c440018  lw          $a0, 0x18($v0)
    ctx->pc = 0x1b5108u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 24)));
    // 0x1b510c: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1b510cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1b5110: 0xac24ab14  sw          $a0, -0x54EC($at)
    ctx->pc = 0x1b5110u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294945556), GPR_U32(ctx, 4));
    // 0x1b5114: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1b5114u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1b5118: 0xac30ab50  sw          $s0, -0x54B0($at)
    ctx->pc = 0x1b5118u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294945616), GPR_U32(ctx, 16));
    // 0x1b511c: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1b511cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1b5120: 0xac33ab18  sw          $s3, -0x54E8($at)
    ctx->pc = 0x1b5120u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294945560), GPR_U32(ctx, 19));
    // 0x1b5124: 0x8c440024  lw          $a0, 0x24($v0)
    ctx->pc = 0x1b5124u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 36)));
    // 0x1b5128: 0x2642021  addu        $a0, $s3, $a0
    ctx->pc = 0x1b5128u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 4)));
    // 0x1b512c: 0x2484003f  addiu       $a0, $a0, 0x3F
    ctx->pc = 0x1b512cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 63));
    // 0x1b5130: 0x879824  and         $s3, $a0, $a3
    ctx->pc = 0x1b5130u;
    SET_GPR_U64(ctx, 19, GPR_U64(ctx, 4) & GPR_U64(ctx, 7));
label_1b5134:
    // 0x1b5134: 0x32080  sll         $a0, $v1, 2
    ctx->pc = 0x1b5134u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1b5138: 0x2242021  addu        $a0, $s1, $a0
    ctx->pc = 0x1b5138u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 4)));
    // 0x1b513c: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1b513cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1b5140: 0xac93002c  sw          $s3, 0x2C($a0)
    ctx->pc = 0x1b5140u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 44), GPR_U32(ctx, 19));
    // 0x1b5144: 0x8e260018  lw          $a2, 0x18($s1)
    ctx->pc = 0x1b5144u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 24)));
    // 0x1b5148: 0x28640002  slti        $a0, $v1, 0x2
    ctx->pc = 0x1b5148u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x1b514c: 0x8e250060  lw          $a1, 0x60($s1)
    ctx->pc = 0x1b514cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 96)));
    // 0x1b5150: 0xc52818  mult        $a1, $a2, $a1
    ctx->pc = 0x1b5150u;
    { int64_t result = (int64_t)GPR_S32(ctx, 6) * (int64_t)GPR_S32(ctx, 5); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 5, (int32_t)result); }
    // 0x1b5154: 0x2652821  addu        $a1, $s3, $a1
    ctx->pc = 0x1b5154u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 5)));
    // 0x1b5158: 0x24a5003f  addiu       $a1, $a1, 0x3F
    ctx->pc = 0x1b5158u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 63));
    // 0x1b515c: 0x1480fff5  bnez        $a0, . + 4 + (-0xB << 2)
    ctx->pc = 0x1B515Cu;
    {
        const bool branch_taken_0x1b515c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B5160u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B515Cu;
            // 0x1b5160: 0xa79824  and         $s3, $a1, $a3 (Delay Slot)
        SET_GPR_U64(ctx, 19, GPR_U64(ctx, 5) & GPR_U64(ctx, 7));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b515c) {
            ctx->pc = 0x1B5134u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b5134;
        }
    }
    ctx->pc = 0x1B5164u;
    // 0x1b5164: 0xae330034  sw          $s3, 0x34($s1)
    ctx->pc = 0x1b5164u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 52), GPR_U32(ctx, 19));
    // 0x1b5168: 0x8c460014  lw          $a2, 0x14($v0)
    ctx->pc = 0x1b5168u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 20)));
    // 0x1b516c: 0x8e270034  lw          $a3, 0x34($s1)
    ctx->pc = 0x1b516cu;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 52)));
    // 0x1b5170: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x1B5170u;
    {
        const bool branch_taken_0x1b5170 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B5174u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5170u;
            // 0x1b5174: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b5170) {
            ctx->pc = 0x1B51ACu;
            goto label_1b51ac;
        }
    }
    ctx->pc = 0x1B5178u;
label_1b5178:
    // 0x1b5178: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1b5178u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1b517c:
    // 0x1b517c: 0x90c30000  lbu         $v1, 0x0($a2)
    ctx->pc = 0x1b517cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1b5180: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x1b5180u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x1b5184: 0x28a20010  slti        $v0, $a1, 0x10
    ctx->pc = 0x1b5184u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x1b5188: 0xa0e30003  sb          $v1, 0x3($a3)
    ctx->pc = 0x1b5188u;
    WRITE8(ADD32(GPR_U32(ctx, 7), 3), (uint8_t)GPR_U32(ctx, 3));
    // 0x1b518c: 0x90c30001  lbu         $v1, 0x1($a2)
    ctx->pc = 0x1b518cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 1)));
    // 0x1b5190: 0xa0e30002  sb          $v1, 0x2($a3)
    ctx->pc = 0x1b5190u;
    WRITE8(ADD32(GPR_U32(ctx, 7), 2), (uint8_t)GPR_U32(ctx, 3));
    // 0x1b5194: 0x24c60002  addiu       $a2, $a2, 0x2
    ctx->pc = 0x1b5194u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 2));
    // 0x1b5198: 0xa0e30001  sb          $v1, 0x1($a3)
    ctx->pc = 0x1b5198u;
    WRITE8(ADD32(GPR_U32(ctx, 7), 1), (uint8_t)GPR_U32(ctx, 3));
    // 0x1b519c: 0xa0e30000  sb          $v1, 0x0($a3)
    ctx->pc = 0x1b519cu;
    WRITE8(ADD32(GPR_U32(ctx, 7), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1b51a0: 0x1440fff6  bnez        $v0, . + 4 + (-0xA << 2)
    ctx->pc = 0x1B51A0u;
    {
        const bool branch_taken_0x1b51a0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B51A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B51A0u;
            // 0x1b51a4: 0x24e70004  addiu       $a3, $a3, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b51a0) {
            ctx->pc = 0x1B517Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b517c;
        }
    }
    ctx->pc = 0x1B51A8u;
    // 0x1b51a8: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x1b51a8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
label_1b51ac:
    // 0x1b51ac: 0x8e250024  lw          $a1, 0x24($s1)
    ctx->pc = 0x1b51acu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 36)));
    // 0x1b51b0: 0x85102b  sltu        $v0, $a0, $a1
    ctx->pc = 0x1b51b0u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)GPR_U64(ctx, 5)) ? 1 : 0);
    // 0x1b51b4: 0x1440fff0  bnez        $v0, . + 4 + (-0x10 << 2)
    ctx->pc = 0x1B51B4u;
    {
        const bool branch_taken_0x1b51b4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B51B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B51B4u;
            // 0x1b51b8: 0x510c0  sll         $v0, $a1, 3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b51b4) {
            ctx->pc = 0x1B5178u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b5178;
        }
    }
    ctx->pc = 0x1B51BCu;
    // 0x1b51bc: 0x51980  sll         $v1, $a1, 6
    ctx->pc = 0x1b51bcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 5), 6));
    // 0x1b51c0: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x1b51c0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x1b51c4: 0x2639821  addu        $s3, $s3, $v1
    ctx->pc = 0x1b51c4u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 3)));
    // 0x1b51c8: 0x8e250060  lw          $a1, 0x60($s1)
    ctx->pc = 0x1b51c8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 96)));
    // 0x1b51cc: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x1b51ccu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x1b51d0: 0x2446008f  addiu       $a2, $v0, 0x8F
    ctx->pc = 0x1b51d0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), 143));
    // 0x1b51d4: 0x2403ffc0  addiu       $v1, $zero, -0x40
    ctx->pc = 0x1b51d4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967232));
    // 0x1b51d8: 0x26420002  addiu       $v0, $s2, 0x2
    ctx->pc = 0x1b51d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), 2));
    // 0x1b51dc: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x1b51dcu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b51e0: 0xae320054  sw          $s2, 0x54($s1)
    ctx->pc = 0x1b51e0u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 84), GPR_U32(ctx, 18));
    // 0x1b51e4: 0x520c0  sll         $a0, $a1, 3
    ctx->pc = 0x1b51e4u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x1b51e8: 0x852021  addu        $a0, $a0, $a1
    ctx->pc = 0x1b51e8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
    // 0x1b51ec: 0xae220058  sw          $v0, 0x58($s1)
    ctx->pc = 0x1b51ecu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 88), GPR_U32(ctx, 2));
    // 0x1b51f0: 0x41140  sll         $v0, $a0, 5
    ctx->pc = 0x1b51f0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 5));
    // 0x1b51f4: 0xc21021  addu        $v0, $a2, $v0
    ctx->pc = 0x1b51f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
    // 0x1b51f8: 0x43a024  and         $s4, $v0, $v1
    ctx->pc = 0x1b51f8u;
    SET_GPR_U64(ctx, 20, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
label_1b51fc:
    // 0x1b51fc: 0x101080  sll         $v0, $s0, 2
    ctx->pc = 0x1b51fcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x1b5200: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x1b5200u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b5204: 0x2229021  addu        $s2, $s1, $v0
    ctx->pc = 0x1b5204u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 2)));
    // 0x1b5208: 0xae530038  sw          $s3, 0x38($s2)
    ctx->pc = 0x1b5208u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 56), GPR_U32(ctx, 19));
    // 0x1b520c: 0x8e25000c  lw          $a1, 0xC($s1)
    ctx->pc = 0x1b520cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
    // 0x1b5210: 0xc06dba4  jal         func_1B6E90
    ctx->pc = 0x1B5210u;
    SET_GPR_U32(ctx, 31, 0x1B5218u);
    ctx->pc = 0x1B5214u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5210u;
            // 0x1b5214: 0x2749821  addu        $s3, $s3, $s4 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 20)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B6E90u;
    if (runtime->hasFunction(0x1B6E90u)) {
        auto targetFn = runtime->lookupFunction(0x1B6E90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B5218u; }
        if (ctx->pc != 0x1B5218u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B6E90_0x1b6e90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B5218u; }
        if (ctx->pc != 0x1B5218u) { return; }
    }
    ctx->pc = 0x1B5218u;
label_1b5218:
    // 0x1b5218: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1b5218u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b521c: 0xc06dc54  jal         func_1B7150
    ctx->pc = 0x1B521Cu;
    SET_GPR_U32(ctx, 31, 0x1B5224u);
    ctx->pc = 0x1B5220u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B521Cu;
            // 0x1b5220: 0x40282d  daddu       $a1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B7150u;
    if (runtime->hasFunction(0x1B7150u)) {
        auto targetFn = runtime->lookupFunction(0x1B7150u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B5224u; }
        if (ctx->pc != 0x1B5224u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B7150_0x1b7150(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B5224u; }
        if (ctx->pc != 0x1B5224u) { return; }
    }
    ctx->pc = 0x1B5224u;
label_1b5224:
    // 0x1b5224: 0xae420040  sw          $v0, 0x40($s2)
    ctx->pc = 0x1b5224u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 64), GPR_U32(ctx, 2));
    // 0x1b5228: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1b5228u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1b522c: 0x2a020002  slti        $v0, $s0, 0x2
    ctx->pc = 0x1b522cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x1b5230: 0x1440fff2  bnez        $v0, . + 4 + (-0xE << 2)
    ctx->pc = 0x1B5230u;
    {
        const bool branch_taken_0x1b5230 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b5230) {
            ctx->pc = 0x1B51FCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b51fc;
        }
    }
    ctx->pc = 0x1B5238u;
    // 0x1b5238: 0xae200048  sw          $zero, 0x48($s1)
    ctx->pc = 0x1b5238u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 72), GPR_U32(ctx, 0));
    // 0x1b523c: 0x3c028080  lui         $v0, 0x8080
    ctx->pc = 0x1b523cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32896 << 16));
    // 0x1b5240: 0x8e250040  lw          $a1, 0x40($s1)
    ctx->pc = 0x1b5240u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 64)));
    // 0x1b5244: 0x2403fffe  addiu       $v1, $zero, -0x2
    ctx->pc = 0x1b5244u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
    // 0x1b5248: 0x34428080  ori         $v0, $v0, 0x8080
    ctx->pc = 0x1b5248u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32896);
    // 0x1b524c: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1b524cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b5250: 0xae25004c  sw          $a1, 0x4C($s1)
    ctx->pc = 0x1b5250u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 76), GPR_U32(ctx, 5));
    // 0x1b5254: 0x8e250028  lw          $a1, 0x28($s1)
    ctx->pc = 0x1b5254u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 40)));
    // 0x1b5258: 0x2652823  subu        $a1, $s3, $a1
    ctx->pc = 0x1b5258u;
    SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 19), GPR_U32(ctx, 5)));
    // 0x1b525c: 0xae25005c  sw          $a1, 0x5C($s1)
    ctx->pc = 0x1b525cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 92), GPR_U32(ctx, 5));
    // 0x1b5260: 0x8e25000c  lw          $a1, 0xC($s1)
    ctx->pc = 0x1b5260u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
    // 0x1b5264: 0xae25006c  sw          $a1, 0x6C($s1)
    ctx->pc = 0x1b5264u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 108), GPR_U32(ctx, 5));
    // 0x1b5268: 0xae200070  sw          $zero, 0x70($s1)
    ctx->pc = 0x1b5268u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 112), GPR_U32(ctx, 0));
    // 0x1b526c: 0xae200074  sw          $zero, 0x74($s1)
    ctx->pc = 0x1b526cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 116), GPR_U32(ctx, 0));
    // 0x1b5270: 0xae230078  sw          $v1, 0x78($s1)
    ctx->pc = 0x1b5270u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 120), GPR_U32(ctx, 3));
    // 0x1b5274: 0xae20007c  sw          $zero, 0x7C($s1)
    ctx->pc = 0x1b5274u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 124), GPR_U32(ctx, 0));
    // 0x1b5278: 0xae220080  sw          $v0, 0x80($s1)
    ctx->pc = 0x1b5278u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 128), GPR_U32(ctx, 2));
    // 0x1b527c: 0xc06d59c  jal         func_1B5670
    ctx->pc = 0x1B527Cu;
    SET_GPR_U32(ctx, 31, 0x1B5284u);
    ctx->pc = 0x1B5280u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B527Cu;
            // 0x1b5280: 0xae200088  sw          $zero, 0x88($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 136), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B5670u;
    if (runtime->hasFunction(0x1B5670u)) {
        auto targetFn = runtime->lookupFunction(0x1B5670u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B5284u; }
        if (ctx->pc != 0x1B5284u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B5670_0x1b5670(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B5284u; }
        if (ctx->pc != 0x1B5284u) { return; }
    }
    ctx->pc = 0x1B5284u;
label_1b5284:
    // 0x1b5284: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x1b5284u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1b5288: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1b5288u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1b528c: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1b528cu;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1b5290: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1b5290u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1b5294: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1b5294u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b5298: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b5298u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b529c: 0x3e00008  jr          $ra
    ctx->pc = 0x1B529Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B52A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B529Cu;
            // 0x1b52a0: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B5054u: goto label_1b5054;
            case 0x1B5134u: goto label_1b5134;
            case 0x1B5178u: goto label_1b5178;
            case 0x1B517Cu: goto label_1b517c;
            case 0x1B51ACu: goto label_1b51ac;
            case 0x1B51FCu: goto label_1b51fc;
            case 0x1B5218u: goto label_1b5218;
            case 0x1B5224u: goto label_1b5224;
            case 0x1B5284u: goto label_1b5284;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B52A4u;
    // 0x1b52a4: 0x0  nop
    ctx->pc = 0x1b52a4u;
    // NOP
    // 0x1b52a8: 0x0  nop
    ctx->pc = 0x1b52a8u;
    // NOP
    // 0x1b52ac: 0x0  nop
    ctx->pc = 0x1b52acu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
