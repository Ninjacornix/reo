#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00130218
// Address: 0x130218 - 0x1302f8
void sub_00130218_0x130218(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00130218_0x130218");
#endif

    switch (ctx->pc) {
        case 0x130288u: goto label_130288;
        case 0x1302e0u: goto label_1302e0;
        default: break;
    }

    ctx->pc = 0x130218u;

    // 0x130218: 0x3c0d0022  lui         $t5, 0x22
    ctx->pc = 0x130218u;
    SET_GPR_S32(ctx, 13, (int32_t)((uint32_t)34 << 16));
    // 0x13021c: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13021cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x130220: 0x8da9a8a4  lw          $t1, -0x575C($t5)
    ctx->pc = 0x130220u;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 13), 4294944932)));
    // 0x130224: 0xa0502d  daddu       $t2, $a1, $zero
    ctx->pc = 0x130224u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x130228: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x130228u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13022c: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x13022cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x130230: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x130230u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x130234: 0x80602d  daddu       $t4, $a0, $zero
    ctx->pc = 0x130234u;
    SET_GPR_U64(ctx, 12, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x130238: 0xc0582d  daddu       $t3, $a2, $zero
    ctx->pc = 0x130238u;
    SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13023c: 0xe0402d  daddu       $t0, $a3, $zero
    ctx->pc = 0x13023cu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x130240: 0x1920001f  blez        $t1, . + 4 + (0x1F << 2)
    ctx->pc = 0x130240u;
    {
        const bool branch_taken_0x130240 = (GPR_S64(ctx, 9) <= 0);
        ctx->pc = 0x130244u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x130240u;
            // 0x130244: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x130240) {
            ctx->pc = 0x1302C0u;
            goto label_1302c0;
        }
    }
    ctx->pc = 0x130248u;
    // 0x130248: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x130248u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x13024c: 0x3c040022  lui         $a0, 0x22
    ctx->pc = 0x13024cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)34 << 16));
    // 0x130250: 0x2447a8a0  addiu       $a3, $v0, -0x5760
    ctx->pc = 0x130250u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 2), 4294944928));
    // 0x130254: 0x2484a8c0  addiu       $a0, $a0, -0x5740
    ctx->pc = 0x130254u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294944960));
    // 0x130258: 0x8ce30000  lw          $v1, 0x0($a3)
    ctx->pc = 0x130258u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x13025c: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x13025cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x130260: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x130260u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x130264: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x130264u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x130268: 0x431023  subu        $v0, $v0, $v1
    ctx->pc = 0x130268u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x13026c: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x13026cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x130270: 0x448021  addu        $s0, $v0, $a0
    ctx->pc = 0x130270u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x130274: 0x82030000  lb          $v1, 0x0($s0)
    ctx->pc = 0x130274u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x130278: 0x10600012  beqz        $v1, . + 4 + (0x12 << 2)
    ctx->pc = 0x130278u;
    {
        const bool branch_taken_0x130278 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x13027Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x130278u;
            // 0x13027c: 0x8da3a8a4  lw          $v1, -0x575C($t5) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 13), 4294944932)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x130278) {
            ctx->pc = 0x1302C4u;
            goto label_1302c4;
        }
    }
    ctx->pc = 0x130280u;
    // 0x130280: 0x120302d  daddu       $a2, $t1, $zero
    ctx->pc = 0x130280u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x130284: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x130284u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
label_130288:
    // 0x130288: 0xa6102a  slt         $v0, $a1, $a2
    ctx->pc = 0x130288u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 6)) ? 1 : 0);
    // 0x13028c: 0x1040000d  beqz        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x13028Cu;
    {
        const bool branch_taken_0x13028c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x130290u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13028Cu;
            // 0x130290: 0x8da3a8a4  lw          $v1, -0x575C($t5) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 13), 4294944932)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13028c) {
            ctx->pc = 0x1302C4u;
            goto label_1302c4;
        }
    }
    ctx->pc = 0x130294u;
    // 0x130294: 0x8ce20000  lw          $v0, 0x0($a3)
    ctx->pc = 0x130294u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x130298: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x130298u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x13029c: 0x21840  sll         $v1, $v0, 1
    ctx->pc = 0x13029cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1302a0: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x1302a0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1302a4: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x1302a4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x1302a8: 0x621823  subu        $v1, $v1, $v0
    ctx->pc = 0x1302a8u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1302ac: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1302acu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1302b0: 0x648021  addu        $s0, $v1, $a0
    ctx->pc = 0x1302b0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1302b4: 0x82020000  lb          $v0, 0x0($s0)
    ctx->pc = 0x1302b4u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1302b8: 0x5440fff3  bnel        $v0, $zero, . + 4 + (-0xD << 2)
    ctx->pc = 0x1302B8u;
    {
        const bool branch_taken_0x1302b8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1302b8) {
            ctx->pc = 0x1302BCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1302B8u;
            // 0x1302bc: 0x24a50001  addiu       $a1, $a1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x130288u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_130288;
        }
    }
    ctx->pc = 0x1302C0u;
label_1302c0:
    // 0x1302c0: 0x8da3a8a4  lw          $v1, -0x575C($t5)
    ctx->pc = 0x1302c0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 13), 4294944932)));
label_1302c4:
    // 0x1302c4: 0x10a30007  beq         $a1, $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x1302C4u;
    {
        const bool branch_taken_0x1302c4 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 3));
        ctx->pc = 0x1302C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1302C4u;
            // 0x1302c8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1302c4) {
            ctx->pc = 0x1302E4u;
            goto label_1302e4;
        }
    }
    ctx->pc = 0x1302CCu;
    // 0x1302cc: 0x180282d  daddu       $a1, $t4, $zero
    ctx->pc = 0x1302ccu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 12) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1302d0: 0x140302d  daddu       $a2, $t2, $zero
    ctx->pc = 0x1302d0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1302d4: 0x160382d  daddu       $a3, $t3, $zero
    ctx->pc = 0x1302d4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 11) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1302d8: 0xc04c042  jal         func_130108
    ctx->pc = 0x1302D8u;
    SET_GPR_U32(ctx, 31, 0x1302E0u);
    ctx->pc = 0x1302DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1302D8u;
            // 0x1302dc: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x130108u;
    if (runtime->hasFunction(0x130108u)) {
        auto targetFn = runtime->lookupFunction(0x130108u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1302E0u; }
        if (ctx->pc != 0x1302E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00130108_0x130108(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1302E0u; }
        if (ctx->pc != 0x1302E0u) { return; }
    }
    ctx->pc = 0x1302E0u;
label_1302e0:
    // 0x1302e0: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1302e0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_1302e4:
    // 0x1302e4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1302e4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1302e8: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x1302e8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1302ec: 0x3e00008  jr          $ra
    ctx->pc = 0x1302ECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1302F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1302ECu;
            // 0x1302f0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x130288u: goto label_130288;
            case 0x1302C0u: goto label_1302c0;
            case 0x1302C4u: goto label_1302c4;
            case 0x1302E0u: goto label_1302e0;
            case 0x1302E4u: goto label_1302e4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1302F4u;
    // 0x1302f4: 0x0  nop
    ctx->pc = 0x1302f4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
