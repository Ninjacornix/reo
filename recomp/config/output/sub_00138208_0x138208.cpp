#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00138208
// Address: 0x138208 - 0x1382f0
void sub_00138208_0x138208(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00138208_0x138208");
#endif

    switch (ctx->pc) {
        case 0x138278u: goto label_138278;
        case 0x1382e0u: goto label_1382e0;
        default: break;
    }

    ctx->pc = 0x138208u;

    // 0x138208: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x138208u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x13820c: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x13820cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x138210: 0x2463bbf4  addiu       $v1, $v1, -0x440C
    ctx->pc = 0x138210u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294949876));
    // 0x138214: 0x2442bbf0  addiu       $v0, $v0, -0x4410
    ctx->pc = 0x138214u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294949872));
    // 0x138218: 0x8c650000  lw          $a1, 0x0($v1)
    ctx->pc = 0x138218u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x13821c: 0xac450000  sw          $a1, 0x0($v0)
    ctx->pc = 0x13821cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 5));
    // 0x138220: 0x3e00008  jr          $ra
    ctx->pc = 0x138220u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x138224u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x138220u;
            // 0x138224: 0xac640000  sw          $a0, 0x0($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x138268u: goto label_138268;
            case 0x138278u: goto label_138278;
            case 0x1382D0u: goto label_1382d0;
            case 0x1382E0u: goto label_1382e0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x138228u;
    // 0x138228: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x138228u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x13822c: 0x2463bbf4  addiu       $v1, $v1, -0x440C
    ctx->pc = 0x13822cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294949876));
    // 0x138230: 0x3e00008  jr          $ra
    ctx->pc = 0x138230u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x138234u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x138230u;
            // 0x138234: 0x8c620000  lw          $v0, 0x0($v1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x138268u: goto label_138268;
            case 0x138278u: goto label_138278;
            case 0x1382D0u: goto label_1382d0;
            case 0x1382E0u: goto label_1382e0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x138238u;
    // 0x138238: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x138238u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13823c: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x13823cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x138240: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x138240u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x138244: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x138244u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x138248: 0x14830007  bne         $a0, $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x138248u;
    {
        const bool branch_taken_0x138248 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 3));
        ctx->pc = 0x13824Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x138248u;
            // 0x13824c: 0xac44bbf8  sw          $a0, -0x4408($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 4294949880), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x138248) {
            ctx->pc = 0x138268u;
            goto label_138268;
        }
    }
    ctx->pc = 0x138250u;
    // 0x138250: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x138250u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x138254: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x138254u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x138258: 0x2484c6c8  addiu       $a0, $a0, -0x3938
    ctx->pc = 0x138258u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294952648));
    // 0x13825c: 0x8045a12  j           func_116848
    ctx->pc = 0x13825Cu;
    ctx->pc = 0x138260u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13825Cu;
            // 0x138260: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00116848_0x116848(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x138264u;
    // 0x138264: 0x0  nop
    ctx->pc = 0x138264u;
    // NOP
label_138268:
    // 0x138268: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x138268u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13826c: 0x3e00008  jr          $ra
    ctx->pc = 0x13826Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x138270u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13826Cu;
            // 0x138270: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x138268u: goto label_138268;
            case 0x138278u: goto label_138278;
            case 0x1382D0u: goto label_1382d0;
            case 0x1382E0u: goto label_1382e0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x138274u;
    // 0x138274: 0x0  nop
    ctx->pc = 0x138274u;
    // NOP
label_138278:
    // 0x138278: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x138278u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x13827c: 0x3e00008  jr          $ra
    ctx->pc = 0x13827Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x138280u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13827Cu;
            // 0x138280: 0x8c62bbf8  lw          $v0, -0x4408($v1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294949880)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x138268u: goto label_138268;
            case 0x138278u: goto label_138278;
            case 0x1382D0u: goto label_1382d0;
            case 0x1382E0u: goto label_1382e0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x138284u;
    // 0x138284: 0x0  nop
    ctx->pc = 0x138284u;
    // NOP
    // 0x138288: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x138288u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x13828c: 0x41600  sll         $v0, $a0, 24
    ctx->pc = 0x13828cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 24));
    // 0x138290: 0x2463bbcc  addiu       $v1, $v1, -0x4434
    ctx->pc = 0x138290u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294949836));
    // 0x138294: 0x21603  sra         $v0, $v0, 24
    ctx->pc = 0x138294u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 24));
    // 0x138298: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x138298u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13829c: 0x3c060022  lui         $a2, 0x22
    ctx->pc = 0x13829cu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)34 << 16));
    // 0x1382a0: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1382a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1382a4: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1382a4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1382a8: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1382a8u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1382ac: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x1382acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1382b0: 0x14850007  bne         $a0, $a1, . + 4 + (0x7 << 2)
    ctx->pc = 0x1382B0u;
    {
        const bool branch_taken_0x1382b0 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 5));
        ctx->pc = 0x1382B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1382B0u;
            // 0x1382b4: 0xacc2bbfc  sw          $v0, -0x4404($a2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 6), 4294949884), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1382b0) {
            ctx->pc = 0x1382D0u;
            goto label_1382d0;
        }
    }
    ctx->pc = 0x1382B8u;
    // 0x1382b8: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1382b8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1382bc: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1382bcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1382c0: 0x2484c6e8  addiu       $a0, $a0, -0x3918
    ctx->pc = 0x1382c0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294952680));
    // 0x1382c4: 0x8045a12  j           func_116848
    ctx->pc = 0x1382C4u;
    ctx->pc = 0x1382C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1382C4u;
            // 0x1382c8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00116848_0x116848(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1382CCu;
    // 0x1382cc: 0x0  nop
    ctx->pc = 0x1382ccu;
    // NOP
label_1382d0:
    // 0x1382d0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1382d0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1382d4: 0x3e00008  jr          $ra
    ctx->pc = 0x1382D4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1382D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1382D4u;
            // 0x1382d8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x138268u: goto label_138268;
            case 0x138278u: goto label_138278;
            case 0x1382D0u: goto label_1382d0;
            case 0x1382E0u: goto label_1382e0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1382DCu;
    // 0x1382dc: 0x0  nop
    ctx->pc = 0x1382dcu;
    // NOP
label_1382e0:
    // 0x1382e0: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x1382e0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x1382e4: 0x3e00008  jr          $ra
    ctx->pc = 0x1382E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1382E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1382E4u;
            // 0x1382e8: 0x8c62bbfc  lw          $v0, -0x4404($v1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294949884)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x138268u: goto label_138268;
            case 0x138278u: goto label_138278;
            case 0x1382D0u: goto label_1382d0;
            case 0x1382E0u: goto label_1382e0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1382ECu;
    // 0x1382ec: 0x0  nop
    ctx->pc = 0x1382ecu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
