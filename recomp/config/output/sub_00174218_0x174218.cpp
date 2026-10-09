#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00174218
// Address: 0x174218 - 0x1742a8
void sub_00174218_0x174218(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00174218_0x174218");
#endif

    switch (ctx->pc) {
        case 0x174268u: goto label_174268;
        default: break;
    }

    ctx->pc = 0x174218u;

    // 0x174218: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x174218u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17421c: 0xc0382d  daddu       $a3, $a2, $zero
    ctx->pc = 0x17421cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x174220: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x174220u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x174224: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x174224u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x174228: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x174228u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x17422c: 0x518c0  sll         $v1, $a1, 3
    ctx->pc = 0x17422cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x174230: 0x651823  subu        $v1, $v1, $a1
    ctx->pc = 0x174230u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x174234: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x174234u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x174238: 0x8ce60000  lw          $a2, 0x0($a3)
    ctx->pc = 0x174238u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x17423c: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x17423cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x174240: 0x4c00014  bltz        $a2, . + 4 + (0x14 << 2)
    ctx->pc = 0x174240u;
    {
        const bool branch_taken_0x174240 = (GPR_S64(ctx, 6) < 0);
        ctx->pc = 0x174244u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x174240u;
            // 0x174244: 0x651821  addu        $v1, $v1, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x174240) {
            ctx->pc = 0x174294u;
            goto label_174294;
        }
    }
    ctx->pc = 0x174248u;
    // 0x174248: 0x32080  sll         $a0, $v1, 2
    ctx->pc = 0x174248u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x17424c: 0x2042021  addu        $a0, $s0, $a0
    ctx->pc = 0x17424cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 4)));
    // 0x174250: 0x24841178  addiu       $a0, $a0, 0x1178
    ctx->pc = 0x174250u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4472));
    // 0x174254: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x174254u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x174258: 0x5060000f  beql        $v1, $zero, . + 4 + (0xF << 2)
    ctx->pc = 0x174258u;
    {
        const bool branch_taken_0x174258 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x174258) {
            ctx->pc = 0x17425Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x174258u;
            // 0x17425c: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x174298u;
            goto label_174298;
        }
    }
    ctx->pc = 0x174260u;
    // 0x174260: 0xc05d0aa  jal         func_1742A8
    ctx->pc = 0x174260u;
    SET_GPR_U32(ctx, 31, 0x174268u);
    ctx->pc = 0x174264u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x174260u;
            // 0x174264: 0xe0282d  daddu       $a1, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1742A8u;
    if (runtime->hasFunction(0x1742A8u)) {
        auto targetFn = runtime->lookupFunction(0x1742A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x174268u; }
        if (ctx->pc != 0x174268u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001742A8_0x1742a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x174268u; }
        if (ctx->pc != 0x174268u) { return; }
    }
    ctx->pc = 0x174268u;
label_174268:
    // 0x174268: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x174268u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17426c: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x17426cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x174270: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x174270u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x174274: 0x14430006  bne         $v0, $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x174274u;
    {
        const bool branch_taken_0x174274 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x174278u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x174274u;
            // 0x174278: 0x34a50421  ori         $a1, $a1, 0x421 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)1057);
        ctx->in_delay_slot = false;
        if (branch_taken_0x174274) {
            ctx->pc = 0x174290u;
            goto label_174290;
        }
    }
    ctx->pc = 0x17427Cu;
    // 0x17427c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17427cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x174280: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x174280u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x174284: 0x805a704  j           func_169C10
    ctx->pc = 0x174284u;
    ctx->pc = 0x174288u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x174284u;
            // 0x174288: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17428Cu;
    // 0x17428c: 0x0  nop
    ctx->pc = 0x17428cu;
    // NOP
label_174290:
    // 0x174290: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x174290u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_174294:
    // 0x174294: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x174294u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_174298:
    // 0x174298: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x174298u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17429c: 0x3e00008  jr          $ra
    ctx->pc = 0x17429Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1742A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17429Cu;
            // 0x1742a0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x174268u: goto label_174268;
            case 0x174290u: goto label_174290;
            case 0x174294u: goto label_174294;
            case 0x174298u: goto label_174298;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1742A4u;
    // 0x1742a4: 0x0  nop
    ctx->pc = 0x1742a4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
