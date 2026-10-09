#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00112F08
// Address: 0x112f08 - 0x113010
void sub_00112F08_0x112f08(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00112F08_0x112f08");
#endif

    ctx->pc = 0x112f08u;

    // 0x112f08: 0x73c00  sll         $a3, $a3, 16
    ctx->pc = 0x112f08u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 16));
    // 0x112f0c: 0x94c00  sll         $t1, $t1, 16
    ctx->pc = 0x112f0cu;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 16));
    // 0x112f10: 0x73c03  sra         $a3, $a3, 16
    ctx->pc = 0x112f10u;
    SET_GPR_S32(ctx, 7, SRA32(GPR_S32(ctx, 7), 16));
    // 0x112f14: 0x94c03  sra         $t1, $t1, 16
    ctx->pc = 0x112f14u;
    SET_GPR_S32(ctx, 9, SRA32(GPR_S32(ctx, 9), 16));
    // 0x112f18: 0xe94821  addu        $t1, $a3, $t1
    ctx->pc = 0x112f18u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 9)));
    // 0x112f1c: 0x63400  sll         $a2, $a2, 16
    ctx->pc = 0x112f1cu;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 16));
    // 0x112f20: 0x84400  sll         $t0, $t0, 16
    ctx->pc = 0x112f20u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 16));
    // 0x112f24: 0x93ac0000  lbu         $t4, 0x0($sp)
    ctx->pc = 0x112f24u;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x112f28: 0x63403  sra         $a2, $a2, 16
    ctx->pc = 0x112f28u;
    SET_GPR_S32(ctx, 6, SRA32(GPR_S32(ctx, 6), 16));
    // 0x112f2c: 0x84403  sra         $t0, $t0, 16
    ctx->pc = 0x112f2cu;
    SET_GPR_S32(ctx, 8, SRA32(GPR_S32(ctx, 8), 16));
    // 0x112f30: 0x94900  sll         $t1, $t1, 4
    ctx->pc = 0x112f30u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 4));
    // 0x112f34: 0x73900  sll         $a3, $a3, 4
    ctx->pc = 0x112f34u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 4));
    // 0x112f38: 0x9fa30010  lwu         $v1, 0x10($sp)
    ctx->pc = 0x112f38u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x112f3c: 0xc84021  addu        $t0, $a2, $t0
    ctx->pc = 0x112f3cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x112f40: 0x316b00ff  andi        $t3, $t3, 0xFF
    ctx->pc = 0x112f40u;
    SET_GPR_U64(ctx, 11, GPR_U64(ctx, 11) & (uint64_t)(uint16_t)255);
    // 0x112f44: 0x93ad0008  lbu         $t5, 0x8($sp)
    ctx->pc = 0x112f44u;
    SET_GPR_U32(ctx, 13, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x112f48: 0xb5a38  dsll        $t3, $t3, 8
    ctx->pc = 0x112f48u;
    SET_GPR_U64(ctx, 11, GPR_U64(ctx, 11) << 8);
    // 0x112f4c: 0x3402fe00  ori         $v0, $zero, 0xFE00
    ctx->pc = 0x112f4cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65024);
    // 0x112f50: 0x213bc  dsll32      $v0, $v0, 14
    ctx->pc = 0x112f50u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 14));
    // 0x112f54: 0x84100  sll         $t0, $t0, 4
    ctx->pc = 0x112f54u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 4));
    // 0x112f58: 0x63100  sll         $a2, $a2, 4
    ctx->pc = 0x112f58u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 4));
    // 0x112f5c: 0x314a00ff  andi        $t2, $t2, 0xFF
    ctx->pc = 0x112f5cu;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 10) & (uint64_t)(uint16_t)255);
    // 0x112f60: 0xc6438  dsll        $t4, $t4, 16
    ctx->pc = 0x112f60u;
    SET_GPR_U64(ctx, 12, GPR_U64(ctx, 12) << 16);
    // 0x112f64: 0x73c38  dsll        $a3, $a3, 16
    ctx->pc = 0x112f64u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) << 16);
    // 0x112f68: 0x94c38  dsll        $t1, $t1, 16
    ctx->pc = 0x112f68u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) << 16);
    // 0x112f6c: 0x3183c  dsll32      $v1, $v1, 0
    ctx->pc = 0x112f6cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x112f70: 0x1425025  or          $t2, $t2, $v0
    ctx->pc = 0x112f70u;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 10) | GPR_U64(ctx, 2));
    // 0x112f74: 0x18b6025  or          $t4, $t4, $t3
    ctx->pc = 0x112f74u;
    SET_GPR_U64(ctx, 12, GPR_U64(ctx, 12) | GPR_U64(ctx, 11));
    // 0x112f78: 0xc73825  or          $a3, $a2, $a3
    ctx->pc = 0x112f78u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 6) | GPR_U64(ctx, 7));
    // 0x112f7c: 0x1094825  or          $t1, $t0, $t1
    ctx->pc = 0x112f7cu;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 8) | GPR_U64(ctx, 9));
    // 0x112f80: 0x52c00  sll         $a1, $a1, 16
    ctx->pc = 0x112f80u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 16));
    // 0x112f84: 0x80302d  daddu       $a2, $a0, $zero
    ctx->pc = 0x112f84u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x112f88: 0x1234825  or          $t1, $t1, $v1
    ctx->pc = 0x112f88u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) | GPR_U64(ctx, 3));
    // 0x112f8c: 0xe33825  or          $a3, $a3, $v1
    ctx->pc = 0x112f8cu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 3));
    // 0x112f90: 0x14c5025  or          $t2, $t2, $t4
    ctx->pc = 0x112f90u;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 10) | GPR_U64(ctx, 12));
    // 0x112f94: 0xd6e38  dsll        $t5, $t5, 24
    ctx->pc = 0x112f94u;
    SET_GPR_U64(ctx, 13, GPR_U64(ctx, 13) << 24);
    // 0x112f98: 0x54403  sra         $t0, $a1, 16
    ctx->pc = 0x112f98u;
    SET_GPR_S32(ctx, 8, SRA32(GPR_S32(ctx, 5), 16));
    // 0x112f9c: 0x24040047  addiu       $a0, $zero, 0x47
    ctx->pc = 0x112f9cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 71));
    // 0x112fa0: 0x24050005  addiu       $a1, $zero, 0x5
    ctx->pc = 0x112fa0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x112fa4: 0x14d5025  or          $t2, $t2, $t5
    ctx->pc = 0x112fa4u;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 10) | GPR_U64(ctx, 13));
    // 0x112fa8: 0x3c0b0003  lui         $t3, 0x3
    ctx->pc = 0x112fa8u;
    SET_GPR_S32(ctx, 11, (int32_t)((uint32_t)3 << 16));
    // 0x112fac: 0x24020006  addiu       $v0, $zero, 0x6
    ctx->pc = 0x112facu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x112fb0: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x112fb0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x112fb4: 0xfcc20010  sd          $v0, 0x10($a2)
    ctx->pc = 0x112fb4u;
    WRITE64(ADD32(GPR_U32(ctx, 6), 16), GPR_U64(ctx, 2));
    // 0x112fb8: 0xfcc30028  sd          $v1, 0x28($a2)
    ctx->pc = 0x112fb8u;
    WRITE64(ADD32(GPR_U32(ctx, 6), 40), GPR_U64(ctx, 3));
    // 0x112fbc: 0xfcca0020  sd          $t2, 0x20($a2)
    ctx->pc = 0x112fbcu;
    WRITE64(ADD32(GPR_U32(ctx, 6), 32), GPR_U64(ctx, 10));
    // 0x112fc0: 0xfcc70030  sd          $a3, 0x30($a2)
    ctx->pc = 0x112fc0u;
    WRITE64(ADD32(GPR_U32(ctx, 6), 48), GPR_U64(ctx, 7));
    // 0x112fc4: 0xfcc50048  sd          $a1, 0x48($a2)
    ctx->pc = 0x112fc4u;
    WRITE64(ADD32(GPR_U32(ctx, 6), 72), GPR_U64(ctx, 5));
    // 0x112fc8: 0xfcc90040  sd          $t1, 0x40($a2)
    ctx->pc = 0x112fc8u;
    WRITE64(ADD32(GPR_U32(ctx, 6), 64), GPR_U64(ctx, 9));
    // 0x112fcc: 0xfcc40058  sd          $a0, 0x58($a2)
    ctx->pc = 0x112fccu;
    WRITE64(ADD32(GPR_U32(ctx, 6), 88), GPR_U64(ctx, 4));
    // 0x112fd0: 0xfcc40008  sd          $a0, 0x8($a2)
    ctx->pc = 0x112fd0u;
    WRITE64(ADD32(GPR_U32(ctx, 6), 8), GPR_U64(ctx, 4));
    // 0x112fd4: 0xfccb0000  sd          $t3, 0x0($a2)
    ctx->pc = 0x112fd4u;
    WRITE64(ADD32(GPR_U32(ctx, 6), 0), GPR_U64(ctx, 11));
    // 0x112fd8: 0xfcc00018  sd          $zero, 0x18($a2)
    ctx->pc = 0x112fd8u;
    WRITE64(ADD32(GPR_U32(ctx, 6), 24), GPR_U64(ctx, 0));
    // 0x112fdc: 0x11000007  beqz        $t0, . + 4 + (0x7 << 2)
    ctx->pc = 0x112FDCu;
    {
        const bool branch_taken_0x112fdc = (GPR_U64(ctx, 8) == GPR_U64(ctx, 0));
        ctx->pc = 0x112FE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x112FDCu;
            // 0x112fe0: 0xfcc50038  sd          $a1, 0x38($a2) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 6), 56), GPR_U64(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x112fdc) {
            ctx->pc = 0x112FFCu;
            goto label_112ffc;
        }
    }
    ctx->pc = 0x112FE4u;
    // 0x112fe4: 0x31020003  andi        $v0, $t0, 0x3
    ctx->pc = 0x112fe4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 8) & (uint64_t)(uint16_t)3);
    // 0x112fe8: 0x3c030001  lui         $v1, 0x1
    ctx->pc = 0x112fe8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)1 << 16));
    // 0x112fec: 0x21478  dsll        $v0, $v0, 17
    ctx->pc = 0x112fecu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 17);
    // 0x112ff0: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x112ff0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x112ff4: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x112FF4u;
    {
        const bool branch_taken_0x112ff4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x112FF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x112FF4u;
            // 0x112ff8: 0xfcc20050  sd          $v0, 0x50($a2) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 6), 80), GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x112ff4) {
            ctx->pc = 0x113000u;
            goto label_113000;
        }
    }
    ctx->pc = 0x112FFCu;
label_112ffc:
    // 0x112ffc: 0xfccb0050  sd          $t3, 0x50($a2)
    ctx->pc = 0x112ffcu;
    WRITE64(ADD32(GPR_U32(ctx, 6), 80), GPR_U64(ctx, 11));
label_113000:
    // 0x113000: 0xf  sync
    ctx->pc = 0x113000u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x113004: 0x3e00008  jr          $ra
    ctx->pc = 0x113004u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x113008u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x113004u;
            // 0x113008: 0x24020006  addiu       $v0, $zero, 0x6 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x112FFCu: goto label_112ffc;
            case 0x113000u: goto label_113000;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11300Cu;
    // 0x11300c: 0x0  nop
    ctx->pc = 0x11300cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
