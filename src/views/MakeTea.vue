<template>
    <h1>Making tea...</h1>
</template>

<script setup lang="ts">
import { ref } from 'vue';
import { useRouter } from 'vue-router';
import teaJson from '@/assets/tea.json'
import TeaPreview from '@/components/TeaPreview.vue';

const router = useRouter();

const redirectToTeaDetails = (teaSlug: string) => {
  router.push(`/tea/${teaSlug}`);
};

const teaData = ref(teaJson);
</script>