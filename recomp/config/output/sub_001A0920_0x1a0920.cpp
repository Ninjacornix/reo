#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A0920
// Address: 0x1a0920 - 0x1a0ad0
void sub_001A0920_0x1a0920(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A0920_0x1a0920");
#endif

    switch (ctx->pc) {
        case 0x1a0a84u: goto label_1a0a84;
        case 0x1a0a9cu: goto label_1a0a9c;
        case 0x1a0ab8u: goto label_1a0ab8;
        default: break;
    }

    ctx->pc = 0x1a0920u;

    // 0x1a0920: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1a0920u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1a0924: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1a0924u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1a0928: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1a0928u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1a092c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a092cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a0930: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1a0930u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1a0934: 0x2483c  dsll32      $t1, $v0, 0
    ctx->pc = 0x1a0934u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1a0938: 0x8c2cfed0  lw          $t4, -0x130($at)
    ctx->pc = 0x1a0938u;
    SET_GPR_S32(ctx, 12, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966992)));
    // 0x1a093c: 0x24040140  addiu       $a0, $zero, 0x140
    ctx->pc = 0x1a093cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 320));
    // 0x1a0940: 0x24050010  addiu       $a1, $zero, 0x10
    ctx->pc = 0x1a0940u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1a0944: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a0944u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a0948: 0x2587ffff  addiu       $a3, $t4, -0x1
    ctx->pc = 0x1a0948u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 12), 4294967295));
    // 0x1a094c: 0x8c2bfed8  lw          $t3, -0x128($at)
    ctx->pc = 0x1a094cu;
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294967000)));
    // 0x1a0950: 0x7383c  dsll32      $a3, $a3, 0
    ctx->pc = 0x1a0950u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) << (32 + 0));
    // 0x1a0954: 0x7383f  dsra32      $a3, $a3, 0
    ctx->pc = 0x1a0954u;
    SET_GPR_S64(ctx, 7, GPR_S64(ctx, 7) >> (32 + 0));
    // 0x1a0958: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a0958u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a095c: 0x2568ffff  addiu       $t0, $t3, -0x1
    ctx->pc = 0x1a095cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 11), 4294967295));
    // 0x1a0960: 0x8c22fd50  lw          $v0, -0x2B0($at)
    ctx->pc = 0x1a0960u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966608)));
    // 0x1a0964: 0x8503c  dsll32      $t2, $t0, 0
    ctx->pc = 0x1a0964u;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 8) << (32 + 0));
    // 0x1a0968: 0xa503f  dsra32      $t2, $t2, 0
    ctx->pc = 0x1a0968u;
    SET_GPR_S64(ctx, 10, GPR_S64(ctx, 10) >> (32 + 0));
    // 0x1a096c: 0x7443c  dsll32      $t0, $a3, 16
    ctx->pc = 0x1a096cu;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 7) << (32 + 16));
    // 0x1a0970: 0xa5438  dsll        $t2, $t2, 16
    ctx->pc = 0x1a0970u;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 10) << 16);
    // 0x1a0974: 0x1485025  or          $t2, $t2, $t0
    ctx->pc = 0x1a0974u;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 10) | GPR_U64(ctx, 8));
    // 0x1a0978: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a0978u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a097c: 0x8c2efd58  lw          $t6, -0x2A8($at)
    ctx->pc = 0x1a097cu;
    SET_GPR_S32(ctx, 14, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966616)));
    // 0x1a0980: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a0980u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a0984: 0xe4100  sll         $t0, $t6, 4
    ctx->pc = 0x1a0984u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 14), 4));
    // 0x1a0988: 0x8c2dfd54  lw          $t5, -0x2AC($at)
    ctx->pc = 0x1a0988u;
    SET_GPR_S32(ctx, 13, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966612)));
    // 0x1a098c: 0x84438  dsll        $t0, $t0, 16
    ctx->pc = 0x1a098cu;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) << 16);
    // 0x1a0990: 0x1cc3821  addu        $a3, $t6, $t4
    ctx->pc = 0x1a0990u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 14), GPR_U32(ctx, 12)));
    // 0x1a0994: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a0994u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a0998: 0xdc26fdf0  ld          $a2, -0x210($at)
    ctx->pc = 0x1a0998u;
    SET_GPR_U64(ctx, 6, READ64(ADD32(GPR_U32(ctx, 1), 4294966768)));
    // 0x1a099c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a099cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a09a0: 0xdc23fe08  ld          $v1, -0x1F8($at)
    ctx->pc = 0x1a09a0u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 1), 4294966792)));
    // 0x1a09a4: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a09a4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a09a8: 0xfc2af760  sd          $t2, -0x8A0($at)
    ctx->pc = 0x1a09a8u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965088), GPR_U64(ctx, 10));
    // 0x1a09ac: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a09acu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a09b0: 0xfc26f7c0  sd          $a2, -0x840($at)
    ctx->pc = 0x1a09b0u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965184), GPR_U64(ctx, 6));
    // 0x1a09b4: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a09b4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a09b8: 0x1ab3021  addu        $a2, $t5, $t3
    ctx->pc = 0x1a09b8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 13), GPR_U32(ctx, 11)));
    // 0x1a09bc: 0xfc23f7d0  sd          $v1, -0x830($at)
    ctx->pc = 0x1a09bcu;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965200), GPR_U64(ctx, 3));
    // 0x1a09c0: 0x63100  sll         $a2, $a2, 4
    ctx->pc = 0x1a09c0u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 4));
    // 0x1a09c4: 0xd1900  sll         $v1, $t5, 4
    ctx->pc = 0x1a09c4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 13), 4));
    // 0x1a09c8: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a09c8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a09cc: 0x681825  or          $v1, $v1, $t0
    ctx->pc = 0x1a09ccu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 8));
    // 0x1a09d0: 0xfc23f7a0  sd          $v1, -0x860($at)
    ctx->pc = 0x1a09d0u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965152), GPR_U64(ctx, 3));
    // 0x1a09d4: 0x71900  sll         $v1, $a3, 4
    ctx->pc = 0x1a09d4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 7), 4));
    // 0x1a09d8: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a09d8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a09dc: 0x31c38  dsll        $v1, $v1, 16
    ctx->pc = 0x1a09dcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << 16);
    // 0x1a09e0: 0x23c02  srl         $a3, $v0, 16
    ctx->pc = 0x1a09e0u;
    SET_GPR_S32(ctx, 7, (int32_t)SRL32(GPR_U32(ctx, 2), 16));
    // 0x1a09e4: 0xc31825  or          $v1, $a2, $v1
    ctx->pc = 0x1a09e4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 6) | GPR_U64(ctx, 3));
    // 0x1a09e8: 0x30e700ff  andi        $a3, $a3, 0xFF
    ctx->pc = 0x1a09e8u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) & (uint64_t)(uint16_t)255);
    // 0x1a09ec: 0xfc23f7b0  sd          $v1, -0x850($at)
    ctx->pc = 0x1a09ecu;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965168), GPR_U64(ctx, 3));
    // 0x1a09f0: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a09f0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a09f4: 0x21a02  srl         $v1, $v0, 8
    ctx->pc = 0x1a09f4u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1a09f8: 0xdc28fdd0  ld          $t0, -0x230($at)
    ctx->pc = 0x1a09f8u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 1), 4294966736)));
    // 0x1a09fc: 0x306600ff  andi        $a2, $v1, 0xFF
    ctx->pc = 0x1a09fcu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)255);
    // 0x1a0a00: 0x304300ff  andi        $v1, $v0, 0xFF
    ctx->pc = 0x1a0a00u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1a0a04: 0x63238  dsll        $a2, $a2, 8
    ctx->pc = 0x1a0a04u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) << 8);
    // 0x1a0a08: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1a0a08u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1a0a0c: 0xe63025  or          $a2, $a3, $a2
    ctx->pc = 0x1a0a0cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 7) | GPR_U64(ctx, 6));
    // 0x1a0a10: 0x31c38  dsll        $v1, $v1, 16
    ctx->pc = 0x1a0a10u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << 16);
    // 0x1a0a14: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1a0a14u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1a0a18: 0x661825  or          $v1, $v1, $a2
    ctx->pc = 0x1a0a18u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 6));
    // 0x1a0a1c: 0x21638  dsll        $v0, $v0, 24
    ctx->pc = 0x1a0a1cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 24);
    // 0x1a0a20: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1a0a20u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1a0a24: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a0a24u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a0a28: 0x491025  or          $v0, $v0, $t1
    ctx->pc = 0x1a0a28u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 9));
    // 0x1a0a2c: 0xdc27fdd8  ld          $a3, -0x228($at)
    ctx->pc = 0x1a0a2cu;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 1), 4294966744)));
    // 0x1a0a30: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a0a30u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a0a34: 0xdc26fde0  ld          $a2, -0x220($at)
    ctx->pc = 0x1a0a34u;
    SET_GPR_U64(ctx, 6, READ64(ADD32(GPR_U32(ctx, 1), 4294966752)));
    // 0x1a0a38: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a0a38u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a0a3c: 0xfc22f790  sd          $v0, -0x870($at)
    ctx->pc = 0x1a0a3cu;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965136), GPR_U64(ctx, 2));
    // 0x1a0a40: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a0a40u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a0a44: 0xdc23fde8  ld          $v1, -0x218($at)
    ctx->pc = 0x1a0a44u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 1), 4294966760)));
    // 0x1a0a48: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x1a0a48u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x1a0a4c: 0x9c224190  lwu         $v0, 0x4190($at)
    ctx->pc = 0x1a0a4cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 1), 16784)));
    // 0x1a0a50: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a0a50u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a0a54: 0xfc28f7e0  sd          $t0, -0x820($at)
    ctx->pc = 0x1a0a54u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965216), GPR_U64(ctx, 8));
    // 0x1a0a58: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a0a58u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a0a5c: 0xfc27f7f0  sd          $a3, -0x810($at)
    ctx->pc = 0x1a0a5cu;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965232), GPR_U64(ctx, 7));
    // 0x1a0a60: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a0a60u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a0a64: 0xfc26f800  sd          $a2, -0x800($at)
    ctx->pc = 0x1a0a64u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965248), GPR_U64(ctx, 6));
    // 0x1a0a68: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a0a68u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a0a6c: 0xfc23f810  sd          $v1, -0x7F0($at)
    ctx->pc = 0x1a0a6cu;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965264), GPR_U64(ctx, 3));
    // 0x1a0a70: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a0a70u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a0a74: 0xfc22f820  sd          $v0, -0x7E0($at)
    ctx->pc = 0x1a0a74u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965280), GPR_U64(ctx, 2));
    // 0x1a0a78: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a0a78u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a0a7c: 0xc063774  jal         func_18DDD0
    ctx->pc = 0x1A0A7Cu;
    SET_GPR_U32(ctx, 31, 0x1A0A84u);
    ctx->pc = 0x1A0A80u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A0A7Cu;
            // 0x1a0a80: 0xfc22f830  sd          $v0, -0x7D0($at) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 1), 4294965296), GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DDD0u;
    if (runtime->hasFunction(0x18DDD0u)) {
        auto targetFn = runtime->lookupFunction(0x18DDD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A0A84u; }
        if (ctx->pc != 0x1A0A84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A0A84u; }
        if (ctx->pc != 0x1A0A84u) { return; }
    }
    ctx->pc = 0x1A0A84u;
label_1a0a84:
    // 0x1a0a84: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1a0a84u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a0a88: 0x3c04002a  lui         $a0, 0x2A
    ctx->pc = 0x1a0a88u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)42 << 16));
    // 0x1a0a8c: 0x2484f730  addiu       $a0, $a0, -0x8D0
    ctx->pc = 0x1a0a8cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294965040));
    // 0x1a0a90: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1a0a90u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a0a94: 0xc0626c2  jal         func_189B08
    ctx->pc = 0x1A0A94u;
    SET_GPR_U32(ctx, 31, 0x1A0A9Cu);
    ctx->pc = 0x1A0A98u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A0A94u;
            // 0x1a0a98: 0x24060014  addiu       $a2, $zero, 0x14 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
        ctx->in_delay_slot = false;
    ctx->pc = 0x189B08u;
    if (runtime->hasFunction(0x189B08u)) {
        auto targetFn = runtime->lookupFunction(0x189B08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A0A9Cu; }
        if (ctx->pc != 0x1A0A9Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00189B08_0x189b08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A0A9Cu; }
        if (ctx->pc != 0x1A0A9Cu) { return; }
    }
    ctx->pc = 0x1A0A9Cu;
label_1a0a9c:
    // 0x1a0a9c: 0x10293c  dsll32      $a1, $s0, 4
    ctx->pc = 0x1a0a9cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 16) << (32 + 4));
    // 0x1a0aa0: 0x3c07002a  lui         $a3, 0x2A
    ctx->pc = 0x1a0aa0u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)42 << 16));
    // 0x1a0aa4: 0x5293e  dsrl32      $a1, $a1, 4
    ctx->pc = 0x1a0aa4u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) >> (32 + 4));
    // 0x1a0aa8: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x1a0aa8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a0aac: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1a0aacu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a0ab0: 0xc0633ec  jal         func_18CFB0
    ctx->pc = 0x1A0AB0u;
    SET_GPR_U32(ctx, 31, 0x1A0AB8u);
    ctx->pc = 0x1A0AB4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A0AB0u;
            // 0x1a0ab4: 0x24e7f6f0  addiu       $a3, $a3, -0x910 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294964976));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18CFB0u;
    if (runtime->hasFunction(0x18CFB0u)) {
        auto targetFn = runtime->lookupFunction(0x18CFB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A0AB8u; }
        if (ctx->pc != 0x1A0AB8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018CFB0_0x18cfb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A0AB8u; }
        if (ctx->pc != 0x1A0AB8u) { return; }
    }
    ctx->pc = 0x1A0AB8u;
label_1a0ab8:
    // 0x1a0ab8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1a0ab8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1a0abc: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1a0abcu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a0ac0: 0x3e00008  jr          $ra
    ctx->pc = 0x1A0AC0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A0AC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A0AC0u;
            // 0x1a0ac4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A0A84u: goto label_1a0a84;
            case 0x1A0A9Cu: goto label_1a0a9c;
            case 0x1A0AB8u: goto label_1a0ab8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A0AC8u;
    // 0x1a0ac8: 0x0  nop
    ctx->pc = 0x1a0ac8u;
    // NOP
    // 0x1a0acc: 0x0  nop
    ctx->pc = 0x1a0accu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
