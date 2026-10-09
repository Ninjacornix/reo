#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00112B98
// Address: 0x112b98 - 0x112c58
void sub_00112B98_0x112b98(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00112B98_0x112b98");
#endif

    switch (ctx->pc) {
        case 0x112bacu: goto label_112bac;
        default: break;
    }

    ctx->pc = 0x112b98u;

    // 0x112b98: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x112b98u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x112b9c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x112b9cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x112ba0: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x112ba0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x112ba4: 0xc0449be  jal         func_1126F8
    ctx->pc = 0x112BA4u;
    SET_GPR_U32(ctx, 31, 0x112BACu);
    ctx->pc = 0x112BA8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x112BA4u;
            // 0x112ba8: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1126F8u;
    if (runtime->hasFunction(0x1126F8u)) {
        auto targetFn = runtime->lookupFunction(0x1126F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x112BACu; }
        if (ctx->pc != 0x112BACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001126F8_0x1126f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x112BACu; }
        if (ctx->pc != 0x112BACu) { return; }
    }
    ctx->pc = 0x112BACu;
label_112bac:
    // 0x112bac: 0x84430006  lh          $v1, 0x6($v0)
    ctx->pc = 0x112bacu;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 2), 6)));
    // 0x112bb0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x112bb0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x112bb4: 0x14620011  bne         $v1, $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x112BB4u;
    {
        const bool branch_taken_0x112bb4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x112BB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x112BB4u;
            // 0x112bb8: 0xde040000  ld          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x112bb4) {
            ctx->pc = 0x112BFCu;
            goto label_112bfc;
        }
    }
    ctx->pc = 0x112BBCu;
    // 0x112bbc: 0x3c021200  lui         $v0, 0x1200
    ctx->pc = 0x112bbcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4608 << 16));
    // 0x112bc0: 0x3c031200  lui         $v1, 0x1200
    ctx->pc = 0x112bc0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4608 << 16));
    // 0x112bc4: 0x3c061200  lui         $a2, 0x1200
    ctx->pc = 0x112bc4u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)4608 << 16));
    // 0x112bc8: 0xfc440000  sd          $a0, 0x0($v0)
    ctx->pc = 0x112bc8u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 0), GPR_U64(ctx, 4));
    // 0x112bcc: 0x34630070  ori         $v1, $v1, 0x70
    ctx->pc = 0x112bccu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)112);
    // 0x112bd0: 0x34c60080  ori         $a2, $a2, 0x80
    ctx->pc = 0x112bd0u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)128);
    // 0x112bd4: 0x3c041200  lui         $a0, 0x1200
    ctx->pc = 0x112bd4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)4608 << 16));
    // 0x112bd8: 0xde050010  ld          $a1, 0x10($s0)
    ctx->pc = 0x112bd8u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x112bdc: 0x348400c0  ori         $a0, $a0, 0xC0
    ctx->pc = 0x112bdcu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)192);
    // 0x112be0: 0xfc650000  sd          $a1, 0x0($v1)
    ctx->pc = 0x112be0u;
    WRITE64(ADD32(GPR_U32(ctx, 3), 0), GPR_U64(ctx, 5));
    // 0x112be4: 0xde020018  ld          $v0, 0x18($s0)
    ctx->pc = 0x112be4u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 16), 24)));
    // 0x112be8: 0xfcc20000  sd          $v0, 0x0($a2)
    ctx->pc = 0x112be8u;
    WRITE64(ADD32(GPR_U32(ctx, 6), 0), GPR_U64(ctx, 2));
    // 0x112bec: 0xde030020  ld          $v1, 0x20($s0)
    ctx->pc = 0x112becu;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x112bf0: 0xfc830000  sd          $v1, 0x0($a0)
    ctx->pc = 0x112bf0u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 0), GPR_U64(ctx, 3));
    // 0x112bf4: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x112BF4u;
    {
        const bool branch_taken_0x112bf4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x112BF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x112BF4u;
            // 0x112bf8: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x112bf4) {
            ctx->pc = 0x112C48u;
            goto label_112c48;
        }
    }
    ctx->pc = 0x112BFCu;
label_112bfc:
    // 0x112bfc: 0x3c031200  lui         $v1, 0x1200
    ctx->pc = 0x112bfcu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4608 << 16));
    // 0x112c00: 0x3c021200  lui         $v0, 0x1200
    ctx->pc = 0x112c00u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4608 << 16));
    // 0x112c04: 0x3c061200  lui         $a2, 0x1200
    ctx->pc = 0x112c04u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)4608 << 16));
    // 0x112c08: 0xfc640000  sd          $a0, 0x0($v1)
    ctx->pc = 0x112c08u;
    WRITE64(ADD32(GPR_U32(ctx, 3), 0), GPR_U64(ctx, 4));
    // 0x112c0c: 0x34420020  ori         $v0, $v0, 0x20
    ctx->pc = 0x112c0cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32);
    // 0x112c10: 0x34c60090  ori         $a2, $a2, 0x90
    ctx->pc = 0x112c10u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)144);
    // 0x112c14: 0x3c051200  lui         $a1, 0x1200
    ctx->pc = 0x112c14u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)4608 << 16));
    // 0x112c18: 0xde030008  ld          $v1, 0x8($s0)
    ctx->pc = 0x112c18u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x112c1c: 0x34a500a0  ori         $a1, $a1, 0xA0
    ctx->pc = 0x112c1cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)160);
    // 0x112c20: 0x3c041200  lui         $a0, 0x1200
    ctx->pc = 0x112c20u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)4608 << 16));
    // 0x112c24: 0xfc430000  sd          $v1, 0x0($v0)
    ctx->pc = 0x112c24u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 0), GPR_U64(ctx, 3));
    // 0x112c28: 0x348400e0  ori         $a0, $a0, 0xE0
    ctx->pc = 0x112c28u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)224);
    // 0x112c2c: 0xde020010  ld          $v0, 0x10($s0)
    ctx->pc = 0x112c2cu;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x112c30: 0xfcc20000  sd          $v0, 0x0($a2)
    ctx->pc = 0x112c30u;
    WRITE64(ADD32(GPR_U32(ctx, 6), 0), GPR_U64(ctx, 2));
    // 0x112c34: 0xde030018  ld          $v1, 0x18($s0)
    ctx->pc = 0x112c34u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 16), 24)));
    // 0x112c38: 0xfca30000  sd          $v1, 0x0($a1)
    ctx->pc = 0x112c38u;
    WRITE64(ADD32(GPR_U32(ctx, 5), 0), GPR_U64(ctx, 3));
    // 0x112c3c: 0xde020020  ld          $v0, 0x20($s0)
    ctx->pc = 0x112c3cu;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x112c40: 0xfc820000  sd          $v0, 0x0($a0)
    ctx->pc = 0x112c40u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 0), GPR_U64(ctx, 2));
    // 0x112c44: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x112c44u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_112c48:
    // 0x112c48: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x112c48u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x112c4c: 0x3e00008  jr          $ra
    ctx->pc = 0x112C4Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x112C50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x112C4Cu;
            // 0x112c50: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x112BACu: goto label_112bac;
            case 0x112BFCu: goto label_112bfc;
            case 0x112C48u: goto label_112c48;
            default: break;
        }
        return;
    }
    ctx->pc = 0x112C54u;
    // 0x112c54: 0x0  nop
    ctx->pc = 0x112c54u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
