#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A7690
// Address: 0x1a7690 - 0x1a7730
void sub_001A7690_0x1a7690(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A7690_0x1a7690");
#endif

    switch (ctx->pc) {
        case 0x1a76d0u: goto label_1a76d0;
        default: break;
    }

    ctx->pc = 0x1a7690u;

    // 0x1a7690: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1a7690u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1a7694: 0x3c02002b  lui         $v0, 0x2B
    ctx->pc = 0x1a7694u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)43 << 16));
    // 0x1a7698: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1a7698u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1a769c: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a769cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a76a0: 0x8c250a68  lw          $a1, 0xA68($at)
    ctx->pc = 0x1a76a0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2664)));
    // 0x1a76a4: 0x24420a80  addiu       $v0, $v0, 0xA80
    ctx->pc = 0x1a76a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2688));
    // 0x1a76a8: 0x51840  sll         $v1, $a1, 1
    ctx->pc = 0x1a76a8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
    // 0x1a76ac: 0x651821  addu        $v1, $v1, $a1
    ctx->pc = 0x1a76acu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x1a76b0: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1a76b0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1a76b4: 0x432821  addu        $a1, $v0, $v1
    ctx->pc = 0x1a76b4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1a76b8: 0x8ca20000  lw          $v0, 0x0($a1)
    ctx->pc = 0x1a76b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1a76bc: 0x4400006  bltz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1A76BCu;
    {
        const bool branch_taken_0x1a76bc = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x1A76C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A76BCu;
            // 0x1a76c0: 0x3083ffff  andi        $v1, $a0, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a76bc) {
            ctx->pc = 0x1A76D8u;
            goto label_1a76d8;
        }
    }
    ctx->pc = 0x1A76C4u;
    // 0x1a76c4: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1a76c4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1a76c8: 0xc0423b4  jal         func_108ED0
    ctx->pc = 0x1A76C8u;
    SET_GPR_U32(ctx, 31, 0x1A76D0u);
    ctx->pc = 0x1A76CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A76C8u;
            // 0x1a76cc: 0x24842150  addiu       $a0, $a0, 0x2150 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 8528));
        ctx->in_delay_slot = false;
    ctx->pc = 0x108ED0u;
    if (runtime->hasFunction(0x108ED0u)) {
        auto targetFn = runtime->lookupFunction(0x108ED0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A76D0u; }
        if (ctx->pc != 0x1A76D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00108ED0_0x108ed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A76D0u; }
        if (ctx->pc != 0x1A76D0u) { return; }
    }
    ctx->pc = 0x1A76D0u;
label_1a76d0:
    // 0x1a76d0: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x1A76D0u;
    {
        const bool branch_taken_0x1a76d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A76D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A76D0u;
            // 0x1a76d4: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a76d0) {
            ctx->pc = 0x1A771Cu;
            goto label_1a771c;
        }
    }
    ctx->pc = 0x1A76D8u;
label_1a76d8:
    // 0x1a76d8: 0x3c022900  lui         $v0, 0x2900
    ctx->pc = 0x1a76d8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)10496 << 16));
    // 0x1a76dc: 0x31a00  sll         $v1, $v1, 8
    ctx->pc = 0x1a76dcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
    // 0x1a76e0: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a76e0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a76e4: 0x31a3c  dsll32      $v1, $v1, 8
    ctx->pc = 0x1a76e4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 8));
    // 0x1a76e8: 0x31a3e  dsrl32      $v1, $v1, 8
    ctx->pc = 0x1a76e8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) >> (32 + 8));
    // 0x1a76ec: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1a76ecu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1a76f0: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x1a76f0u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x1a76f4: 0x8c220a68  lw          $v0, 0xA68($at)
    ctx->pc = 0x1a76f4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2664)));
    // 0x1a76f8: 0x24430001  addiu       $v1, $v0, 0x1
    ctx->pc = 0x1a76f8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1a76fc: 0x4610004  bgez        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1A76FCu;
    {
        const bool branch_taken_0x1a76fc = (GPR_S64(ctx, 3) >= 0);
        ctx->pc = 0x1A7700u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A76FCu;
            // 0x1a7700: 0x3062001f  andi        $v0, $v1, 0x1F (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)31);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a76fc) {
            ctx->pc = 0x1A7710u;
            goto label_1a7710;
        }
    }
    ctx->pc = 0x1A7704u;
    // 0x1a7704: 0x10400002  beqz        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1A7704u;
    {
        const bool branch_taken_0x1a7704 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a7704) {
            ctx->pc = 0x1A7710u;
            goto label_1a7710;
        }
    }
    ctx->pc = 0x1A770Cu;
    // 0x1a770c: 0x2442ffe0  addiu       $v0, $v0, -0x20
    ctx->pc = 0x1a770cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967264));
label_1a7710:
    // 0x1a7710: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a7710u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a7714: 0xac220a68  sw          $v0, 0xA68($at)
    ctx->pc = 0x1a7714u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 2664), GPR_U32(ctx, 2));
    // 0x1a7718: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1a7718u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1a771c:
    // 0x1a771c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1a771cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a7720: 0x3e00008  jr          $ra
    ctx->pc = 0x1A7720u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A7724u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7720u;
            // 0x1a7724: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A76D0u: goto label_1a76d0;
            case 0x1A76D8u: goto label_1a76d8;
            case 0x1A7710u: goto label_1a7710;
            case 0x1A771Cu: goto label_1a771c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A7728u;
    // 0x1a7728: 0x0  nop
    ctx->pc = 0x1a7728u;
    // NOP
    // 0x1a772c: 0x0  nop
    ctx->pc = 0x1a772cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
